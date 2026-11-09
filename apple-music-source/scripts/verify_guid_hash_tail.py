"""Compare the whole reconstructed hash tail with original instruction spans.

Inputs are invented independent scalar, fold and output states. Only equality,
coverage and artifact identity leave RAM. No network or native private material.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import random
import sys
from typing import Final

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'src'))
from apple_music_source.auth._guid_hash_tail import (
    SCALAR_FRAME_OFFSETS, apply_hash_header, assemble_hash_tail,
)
from scan_auth_substitutions import TARGETS
from verify_fill_dispatch import segment_read

HEADER_START: Final[int] = 0x2f807a
HEADER_END: Final[int] = 0x2f837f
MIXER_START: Final[int] = 0x2f8510
MIXER_END: Final[int] = 0x2f8593
FRAME: Final[int] = 0x90010800
OUTPUT: Final[int] = 0x90020000
SIZE_POINTER: Final[int] = 0x90030000
HASH_SIZE: Final[int] = 20
SIZE_ENCODING: Final[int] = 0x3005ed45
STATE_WIRE_XOR: Final[int] = 0x47
FOLD_LOOPS: Final[tuple[tuple[int, ...], ...]] = (
    (0x2f83c0, 0x2f83f0, 0x1d0, 0x77049158, 0x150, 64),
    (0x2f8430, 0x2f8460, 0x198, 0x78492303, 0xb0, 64),
    (0x2f84a0, 0x2f84cc, 0x1a8, 0x4a9e4e14, 0x340, 328),
)


def prove_hash_header(machine: object, image: bytes) -> dict[str, object]:
    from capstone import Cs, CS_ARCH_X86, CS_MODE_64
    from unicorn import UC_HOOK_CODE
    from unicorn import x86_const as registers
    from types import FunctionType
    from trace_lookup_dataflow import LookupTrace

    decoder = Cs(CS_ARCH_X86, CS_MODE_64)
    decoder.detail = True
    instructions = {instruction.address: instruction for instruction in decoder.disasm(segment_read(image, HEADER_START, HEADER_END - HEADER_START), HEADER_START)}
    machine.mem_write(FRAME - 0x400, bytes(0x400))
    machine.mem_write(OUTPUT, bytes(HASH_SIZE))
    for name, value in (('rbp', FRAME), ('r9', OUTPUT), ('r12', SIZE_POINTER), ('r11', 0)):
        machine.reg_write(getattr(registers, 'UC_X86_REG_' + name.upper()), value)
    trace = LookupTrace(machine, [], [], [])
    symbolic_inputs: list[list[object]] = []
    for role, addresses in (
        ('scalar', tuple(FRAME - offset for offset in SCALAR_FRAME_OFFSETS)),
        ('state', tuple(OUTPUT + offset for offset in range(HASH_SIZE))),
    ):
        variables: list[object] = []
        for number, address in enumerate(addresses):
            variable = trace.z.BitVec(f'{role}_{number}', 8)
            trace.variable_names[str(variable)] = len(trace.variables)
            trace.variables.append(variable)
            trace.values.append(0)
            trace.memory[address] = variable
            variables.append(variable)
        symbolic_inputs.append(variables)

    def step(current: object, counter: int, size: int, user: object) -> None:
        instruction = instructions[counter]
        if instruction.mnemonic != 'div':
            trace.step(current, counter, size)
            return
        divisor = trace.read(current, instruction, instruction.operands[0])
        low, high = trace.reg(current, 'eax'), trace.reg(current, 'edx')
        if trace.dependencies(divisor) | trace.dependencies(low) | trace.dependencies(high):
            raise ValueError('hash-header division unexpectedly depends on scalar/state bytes')
        quotient, remainder = divmod((trace.concrete(high) << 32) | trace.concrete(low), trace.concrete(divisor))
        trace.put_reg(current, 'eax', trace.literal(quotient, 32))
        trace.put_reg(current, 'edx', trace.literal(remainder, 32))

    hook = machine.hook_add(UC_HOOK_CODE, step)
    machine.emu_start(HEADER_START, HEADER_END, count=512)
    machine.hook_del(hook)
    if not trace.active or trace.errors:
        raise RuntimeError('symbolic original hash header did not complete')
    symbolic_source = FunctionType(
        apply_hash_header.__code__,
        dict(apply_hash_header.__globals__, bytearray=list, bytes=list),
    )
    expected = symbolic_source(symbolic_inputs[1], symbolic_inputs[0])
    solver = trace.z.Solver()
    solver.set(timeout=10000)
    solver.add(trace.z.Or(*(trace.memory[OUTPUT + index] != value for index, value in enumerate(expected))))
    verdict = str(solver.check())
    if verdict != 'unsat':
        raise ValueError('universal source hash-header equivalence was not proved')
    return dict(verdict=verdict, independent_scalar_bytes=len(SCALAR_FRAME_OFFSETS), independent_initial_bytes=HASH_SIZE, output_bytes=HASH_SIZE)


def main() -> None:
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_64
    from unicorn import x86_const as registers

    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--known-answers', type=Path)
    arguments = parser.parse_args()
    filename, expected_digest = TARGETS['corefp']
    image = (arguments.checkout / 'rootfs/system/lib64' / filename).read_bytes()
    if hashlib.sha256(image).hexdigest() != expected_digest:
        raise ValueError('original artifact identity mismatch')
    machine = Uc(UC_ARCH_X86, UC_MODE_64)
    machine.mem_map(0x2f8000, 4096)
    machine.mem_write(0x2f8000, segment_read(image, 0x2f8000, 4096))
    for address in (FRAME & ~4095, OUTPUT, SIZE_POINTER):
        machine.mem_map(address, 4096)
    machine.mem_write(SIZE_POINTER, (HASH_SIZE ^ SIZE_ENCODING).to_bytes(4, 'little'))
    universal_header_proof = prove_hash_header(machine, image)
    generator = random.Random(0x817293)
    suffix = generator.randbytes(32)

    def set_register(name: str, value: int) -> None:
        machine.reg_write(getattr(registers, 'UC_X86_REG_' + name.upper()), value)

    def header(scalars: bytes, initial: bytes) -> bytes:
        machine.mem_write(FRAME - 0x400, bytes(0x400))
        for offset, value in zip(SCALAR_FRAME_OFFSETS, scalars, strict=True):
            machine.mem_write(FRAME - offset, bytes([value]))
        machine.mem_write(OUTPUT, initial + suffix)
        for name, value in (('rbp', FRAME), ('r9', OUTPUT), ('r12', SIZE_POINTER), ('r11', 0)):
            set_register(name, value)
        machine.emu_start(HEADER_START, HEADER_END, count=512)
        actual = bytes(machine.mem_read(OUTPUT, HASH_SIZE + len(suffix)))
        if actual != apply_hash_header(initial, scalars) + suffix:
            raise ValueError('source header differs from complete original header or suffix')
        return actual[:HASH_SIZE]

    header_cases = 0
    for scalar_position in range(len(SCALAR_FRAME_OFFSETS)):
        baseline = bytearray(generator.randbytes(len(SCALAR_FRAME_OFFSETS)))
        for value in range(256):
            baseline[scalar_position] = value
            header(bytes(baseline), generator.randbytes(HASH_SIZE))
            header_cases += 1
    vectors: list[dict[str, object]] = []
    full_cases = 0
    fold_iterations = 0
    mixer_iterations = 0
    for _ in range(16):
        scalars = generator.randbytes(len(SCALAR_FRAME_OFFSETS))
        materials = tuple(generator.randbytes(length) for length in (64, 64, 328))
        header(scalars, bytes([0xc5]) * HASH_SIZE)
        for loop, material in zip(FOLD_LOOPS, materials, strict=True):
            begin, end, counter_offset, counter_base, material_offset, _ = loop
            machine.mem_write(FRAME - material_offset, bytes(value ^ STATE_WIRE_XOR for value in material))
            for index in range(len(material)):
                for name, value in (
                    ('rbp', FRAME), ('r12', SIZE_POINTER), ('r13', OUTPUT),
                    ('r8', SIZE_ENCODING), ('r9', FRAME - material_offset),
                    ('rsi', FRAME - material_offset), ('r10', FRAME - material_offset), ('rcx', SIZE_ENCODING),
                ):
                    set_register(name, value)
                machine.mem_write(FRAME - counter_offset, (counter_base + index).to_bytes(8, 'little'))
                machine.emu_start(begin, end, count=64)
                fold_iterations += 1
        for index in range(256):
            for name, value in (('rbp', FRAME), ('r12', SIZE_POINTER), ('r13', OUTPUT)):
                set_register(name, value)
            machine.mem_write(FRAME - 0x70, (0x4b4ae83 + index).to_bytes(4, 'little'))
            machine.emu_start(MIXER_START, MIXER_END, count=128)
            mixer_iterations += 1
        if bytes(machine.mem_read(OUTPUT, HASH_SIZE + len(suffix))) != assemble_hash_tail(scalars, *materials) + suffix:
            raise ValueError('source complete hash tail differs from original execution')
        if len(vectors) < 3:
            vectors.append(dict(scalars=scalars.hex(),folds=[material.hex() for material in materials],output=bytes(machine.mem_read(OUTPUT,HASH_SIZE)).hex()))
        full_cases += 1
    report = dict(
        status='whole source hash tail matches original instructions',
        universal_header_proof=universal_header_proof,
        artifact_sha256=expected_digest, complete_header_cases=header_cases,
        whole_hash_tail_cases=full_cases, original_fold_iterations=fold_iterations,
        original_mixer_iterations=mixer_iterations, entire_output_and_suffix_compared=True,
        network_requests=0, private_material_written=False,
        scope='header, folds and final mixer; middle-state origins and full GUID/auth remain incomplete',
    )
    if arguments.known_answers is not None:
        arguments.known_answers.write_text(json.dumps(dict(scope='public invented-state known answers from pinned original hash-tail instructions',artifact_sha256=expected_digest,cases=vectors),indent=2)+'\n')
    arguments.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report))


if __name__ == '__main__':
    main()
