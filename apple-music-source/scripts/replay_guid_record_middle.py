"""Replay the pinned middle span as a developer oracle, never package runtime.

Native instructions and readonly bytes stay in RAM. The surrounding record
size, expansion and tail use recovered source arithmetic. Output reports expose
only equality flags, PCs and bit-dependency metadata on invented device inputs.
"""
from __future__ import annotations

import argparse
from dataclasses import dataclass, field
import hashlib
import json
from pathlib import Path
import sys
from typing import Any, Final

PACKAGE_SOURCE_DIRECTORY: Final[Path] = Path(__file__).resolve().parents[1] / 'src'
sys.path.insert(0, str(PACKAGE_SOURCE_DIRECTORY))

from guid_record_tail_model import SCALAR_FRAME_OFFSETS, assemble_record_tail
from scan_auth_substitutions import TARGETS
from verify_fill_dispatch import segment_read

MIDDLE_START_ADDRESS: Final[int] = 0x2f8d76
MIDDLE_END_ADDRESS: Final[int] = 0x2fa884
LOOKUP_START_ADDRESS: Final[int] = 0x175fe0
LOOKUP_BYTE_COUNT: Final[int] = 64
INITIAL_STATE_SOURCE_ADDRESS: Final[int] = 0x142980
INITIAL_STATE_BYTE_COUNT: Final[int] = 64
PAGE_BYTE_COUNT: Final[int] = 4096
INVENTED_STACK_BASE: Final[int] = 0x90010000
INVENTED_FRAME_DISPLACEMENT: Final[int] = 0x800
FRAME_CLEAR_BYTE_COUNT: Final[int] = 0x400
EXPANDED_STATE_FRAME_OFFSET: Final[int] = 0x340
FIRST_FOLD_FRAME_OFFSET: Final[int] = 0x150
SECOND_FOLD_FRAME_OFFSET: Final[int] = 0xb0
SECOND_FOLD_POINTER_FRAME_OFFSET: Final[int] = 0x3a0
FOLD_BYTE_COUNT: Final[int] = 64
EXPANDED_STATE_BYTE_COUNT: Final[int] = 328
HASH_WIRE_XOR: Final[int] = 0x47
FORWARD_WIRE_XOR: Final[int] = 0x54
MAXIMUM_INSTRUCTIONS: Final[int] = 4096
BYTE_BIT_COUNT: Final[int] = 8
GPR_NAMES: Final[tuple[str, ...]] = (
    'rax', 'rbx', 'rcx', 'rdx', 'rsi', 'rdi', 'rbp', 'rsp',
    'r8', 'r9', 'r10', 'r11', 'r12', 'r13', 'r14', 'r15',
)
INVENTED_ANDROID_IDENTIFIERS: Final[tuple[bytes, ...]] = (
    b'0123456789abcdef', b'fedcba9876543210',
    b'0011223344556677', b'ffeeddccbbaa9988',
)


@dataclass(frozen=True)
class MiddleLayout:
    name: str
    start_address: int
    end_address: int
    lookup_address: int
    initial_state_address: int
    second_fold_pointer_offset: int
    scalar_offsets: tuple[int, ...]
    wire_xor: int
    input_wire_xor: int


FORWARD_LAYOUT: Final[MiddleLayout] = MiddleLayout(
    'forward', MIDDLE_START_ADDRESS, MIDDLE_END_ADDRESS, LOOKUP_START_ADDRESS,
    INITIAL_STATE_SOURCE_ADDRESS, SECOND_FOLD_POINTER_FRAME_OFFSET,
    SCALAR_FRAME_OFFSETS, FORWARD_WIRE_XOR, 0,
)
HASH_SCALAR_FRAME_OFFSETS: Final[tuple[int, ...]] = tuple(range(0x3e, 0x33, -1)) + (0x2a,)
HASH_LAYOUT: Final[MiddleLayout] = MiddleLayout(
    'hash', 0x2f6793, 0x2f7fd2, 0x26d800, 0x170890, 0x1c0,
    HASH_SCALAR_FRAME_OFFSETS, HASH_WIRE_XOR, HASH_WIRE_XOR,
)


@dataclass(frozen=True)
class MiddleState:
    scalar_bytes: bytes = field(repr=False)
    first_fold_bytes: bytes = field(repr=False)
    second_fold_bytes: bytes = field(repr=False)
    expanded_fold_bytes: bytes = field(repr=False)

    def build_clear_record(self, record_length: int) -> bytes:
        return assemble_record_tail(
            record_length, self.scalar_bytes,
            bytes(value ^ FORWARD_WIRE_XOR for value in self.first_fold_bytes),
            bytes(value ^ FORWARD_WIRE_XOR for value in self.second_fold_bytes),
            bytes(value ^ FORWARD_WIRE_XOR for value in self.expanded_fold_bytes),
        )


class GuidMiddleOracle:
    def __init__(self, checkout: Path, layout: MiddleLayout = FORWARD_LAYOUT) -> None:
        from capstone import Cs, CS_ARCH_X86, CS_MODE_64, CS_OP_MEM
        from unicorn import Uc, UC_ARCH_X86, UC_MODE_64, UC_HOOK_CODE, UC_HOOK_MEM_READ
        from unicorn import x86_const

        self.layout = layout
        self.register_ids = x86_const
        self.unicorn = Uc(UC_ARCH_X86, UC_MODE_64)
        self.mapped_pages: set[int] = set()
        self.frame_address = INVENTED_STACK_BASE + INVENTED_FRAME_DISPLACEMENT
        filename, expected_digest = TARGETS['corefp']
        self.image = (checkout / 'rootfs/system/lib64' / filename).read_bytes()
        if hashlib.sha256(self.image).hexdigest() != expected_digest:
            raise ValueError('CoreFP developer oracle does not match the pinned artifact')
        self.artifact_digest = expected_digest
        machine_code = segment_read(self.image, layout.start_address, layout.end_address - layout.start_address)
        self.map_bytes(layout.start_address, machine_code)
        decoder = Cs(CS_ARCH_X86, CS_MODE_64)
        decoder.detail = True
        self.instructions = {instruction.address: instruction for instruction in decoder.disasm(machine_code, layout.start_address)}
        if sum(instruction.size for instruction in self.instructions.values()) != len(machine_code):
            raise ValueError('middle span is not completely decoded')
        for instruction in self.instructions.values():
            if instruction.mnemonic != 'movaps':
                continue
            for operand in instruction.operands:
                if operand.type != CS_OP_MEM or instruction.reg_name(operand.mem.base) != 'rip':
                    continue
                address = instruction.address + instruction.size + operand.mem.disp
                self.map_bytes(address, segment_read(self.image, address, operand.size))
        self.map_bytes(layout.lookup_address, segment_read(self.image, layout.lookup_address, LOOKUP_BYTE_COUNT))
        self.map_bytes(INVENTED_STACK_BASE, bytes(PAGE_BYTE_COUNT))
        self.initial_second_fold = segment_read(self.image, layout.initial_state_address, INITIAL_STATE_BYTE_COUNT)
        self.lookup_reads: list[tuple[int, int]] = []
        self.selected_read: int | None = None
        self.selected_bit_mask = 0
        self.pending_register_flip: tuple[int, int] | None = None
        self.hooks = [
            self.unicorn.hook_add(UC_HOOK_MEM_READ, self.observe_lookup_read, begin=layout.lookup_address, end=layout.lookup_address + LOOKUP_BYTE_COUNT - 1),
            self.unicorn.hook_add(UC_HOOK_CODE, self.apply_pending_flip),
        ]

    def map_bytes(self, address: int, data: bytes) -> None:
        first_page = address // PAGE_BYTE_COUNT * PAGE_BYTE_COUNT
        final_page = (address + len(data) - 1) // PAGE_BYTE_COUNT * PAGE_BYTE_COUNT
        for page_address in range(first_page, final_page + PAGE_BYTE_COUNT, PAGE_BYTE_COUNT):
            if page_address not in self.mapped_pages:
                self.unicorn.mem_map(page_address, PAGE_BYTE_COUNT)
                self.mapped_pages.add(page_address)
        self.unicorn.mem_write(address, data)

    def observe_lookup_read(self, machine: Any, access: int, address: int, size: int, value: int, user_data: Any) -> None:
        program_counter = machine.reg_read(self.register_ids.UC_X86_REG_RIP)
        instruction = self.instructions[program_counter]
        if size != 1 or instruction.mnemonic not in ('mov', 'movzx'):
            raise ValueError('lookup read is not a supported byte load')
        read_number = len(self.lookup_reads)
        self.lookup_reads.append((program_counter, address - self.layout.lookup_address))
        if read_number != self.selected_read:
            return
        register_name = instruction.reg_name(instruction.operands[0].reg)
        destination_register = getattr(self.register_ids, 'UC_X86_REG_' + register_name.upper())
        self.pending_register_flip = (destination_register, self.selected_bit_mask)

    def apply_pending_flip(self, machine: Any, address: int, size: int, user_data: Any) -> None:
        if self.pending_register_flip is None:
            return
        register_id, bit_mask = self.pending_register_flip
        self.pending_register_flip = None
        machine.reg_write(register_id, machine.reg_read(register_id) ^ bit_mask)

    def prepare_state(self, android_identifier: bytes, selected_read: int | None = None, selected_bit: int = 0) -> None:
        from apple_music_source.auth._guid_input_expansion import expand328
        from apple_music_source.auth._guid_record_size import record_size

        if self.layout.name == 'forward':
            record_size(android_identifier)
        elif not 60 <= len(android_identifier) <= 200:
            raise ValueError('hash record length is outside the selected native bounds')
        expanded_wire_state = bytes(
            value ^ HASH_WIRE_XOR ^ self.layout.wire_xor
            for value in expand328(bytes(value ^ HASH_WIRE_XOR ^ self.layout.input_wire_xor for value in android_identifier))
        )
        self.unicorn.mem_write(self.frame_address - FRAME_CLEAR_BYTE_COUNT, bytes(FRAME_CLEAR_BYTE_COUNT))
        self.unicorn.mem_write(self.frame_address - EXPANDED_STATE_FRAME_OFFSET, expanded_wire_state)
        self.unicorn.mem_write(self.frame_address - SECOND_FOLD_FRAME_OFFSET, self.initial_second_fold)
        self.unicorn.mem_write(
            self.frame_address - self.layout.second_fold_pointer_offset,
            (self.frame_address - SECOND_FOLD_FRAME_OFFSET).to_bytes(BYTE_BIT_COUNT, 'little'),
        )
        for register_name in GPR_NAMES:
            self.unicorn.reg_write(getattr(self.register_ids, 'UC_X86_REG_' + register_name.upper()), 0)
        self.unicorn.reg_write(self.register_ids.UC_X86_REG_RBP, self.frame_address)
        self.unicorn.reg_write(self.register_ids.UC_X86_REG_RSP, self.frame_address - FRAME_CLEAR_BYTE_COUNT)
        self.unicorn.reg_write(self.register_ids.UC_X86_REG_EFLAGS, 2)
        self.lookup_reads = []
        self.selected_read = selected_read
        self.selected_bit_mask = 1 << selected_bit
        self.pending_register_flip = None

    def derive_state(self, android_identifier: bytes, selected_read: int | None = None, selected_bit: int = 0) -> MiddleState:
        self.prepare_state(android_identifier, selected_read, selected_bit)
        self.unicorn.emu_start(self.layout.start_address, self.layout.end_address, count=MAXIMUM_INSTRUCTIONS)
        if self.unicorn.reg_read(self.register_ids.UC_X86_REG_RIP) != self.layout.end_address:
            raise RuntimeError('middle span did not reach its end')
        return self.capture_state()

    def capture_state(self) -> MiddleState:
        return MiddleState(
            bytes(self.unicorn.mem_read(self.frame_address - offset, 1)[0] for offset in self.layout.scalar_offsets),
            bytes(self.unicorn.mem_read(self.frame_address - FIRST_FOLD_FRAME_OFFSET, FOLD_BYTE_COUNT)),
            bytes(self.unicorn.mem_read(self.frame_address - SECOND_FOLD_FRAME_OFFSET, FOLD_BYTE_COUNT)),
            bytes(self.unicorn.mem_read(self.frame_address - EXPANDED_STATE_FRAME_OFFSET, EXPANDED_STATE_BYTE_COUNT)),
        )

    def close(self) -> None:
        for hook in self.hooks:
            self.unicorn.hook_del(hook)
        self.hooks = []

    def __enter__(self) -> GuidMiddleOracle:
        return self

    def __exit__(self, exception_type: Any, exception: Any, traceback: Any) -> None:
        self.close()


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--bit-controls', action='store_true')
    arguments = parser.parse_args()
    from apple_music_source.auth._guid_record_size import record_size

    profiles: list[dict[str, Any]] = []
    with GuidMiddleOracle(arguments.checkout.resolve()) as oracle:
        for profile_number, android_identifier in enumerate(INVENTED_ANDROID_IDENTIFIERS):
            baseline_state = oracle.derive_state(android_identifier)
            baseline_reads = list(oracle.lookup_reads)
            baseline_record = baseline_state.build_clear_record(record_size(android_identifier))
            controls: list[dict[str, Any]] = []
            if arguments.bit_controls:
                for read_number, (program_counter, _) in enumerate(baseline_reads):
                    changed_state_bits: list[int] = []
                    changed_record_bits: list[int] = []
                    changed_lookup_sequence_bits: list[int] = []
                    for bit_number in range(BYTE_BIT_COUNT):
                        observed_state = oracle.derive_state(android_identifier, read_number, bit_number)
                        observed_record = observed_state.build_clear_record(record_size(android_identifier))
                        if observed_state != baseline_state:
                            changed_state_bits.append(bit_number)
                        if observed_record != baseline_record:
                            changed_record_bits.append(bit_number)
                        if oracle.lookup_reads != baseline_reads:
                            changed_lookup_sequence_bits.append(bit_number)
                    controls.append(dict(read_number=read_number,source_PC=hex(program_counter),changed_state_bits=changed_state_bits,changed_record_bits=changed_record_bits,changed_lookup_sequence_bits=changed_lookup_sequence_bits))
            profiles.append(dict(profile=profile_number,lookup_reads=len(baseline_reads),record_bytes=len(baseline_record),controls=controls))
        report = dict(status='original GUID middle span replayed',artifact_sha256=oracle.artifact_digest,instructions=len(oracle.instructions),profiles=profiles,network_requests=0,private_material_written=False,scope='developer original-instruction oracle and observed bit controls only; native integration and source reconstruction remain separate')
    arguments.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({key:value for key,value in report.items() if key!='profiles'}))


if __name__ == '__main__':
    main()
