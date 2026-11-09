"""Compare generated source middle/record execution with pinned native code.

Real static protocol inputs and invented-state controls remain in RAM. The
source phase denies vendor-file reads, dynamic loading and network activity.
"""
from __future__ import annotations

import argparse
import ast
from dataclasses import dataclass, field
import hashlib
import importlib.util
import json
from pathlib import Path
import random
import sys
from typing import Any, Final

from replay_guid_record_middle import (
    GuidMiddleOracle, MiddleState, MiddleLayout, FORWARD_LAYOUT, HASH_LAYOUT, INVENTED_ANDROID_IDENTIFIERS,
    HASH_WIRE_XOR, FORWARD_WIRE_XOR, MIDDLE_START_ADDRESS, MIDDLE_END_ADDRESS,
    MAXIMUM_INSTRUCTIONS, EXPANDED_STATE_FRAME_OFFSET, LOOKUP_START_ADDRESS,
    LOOKUP_BYTE_COUNT,
)
from emit_guid_middle_source import readonly_seed_locations
from apple_music_source.auth._guid_input_expansion import expand328
from apple_music_source.auth._guid_record_size import record_size

ALLOWED_SOURCE_CALLS: Final[frozenset[str]] = frozenset(('tuple', 'map', 'len', 'bytes', 'bytearray', 'ValueError'))
SYNTHETIC_CASE_COUNT: Final[int] = 12
PUBLIC_CONTROL_SEED: Final[int] = 0x717546
SYNTHETIC_INPUT_LENGTHS: Final[tuple[int, ...]] = (8, 16, 32, 80)
EXPANDED_STATE_BYTES: Final[int] = 328
INITIAL_STATE_BYTES: Final[int] = 64
LOOKUP_PARAMETER_BYTES: Final[int] = 64
READONLY_SEED_BYTES: Final[int] = 48


@dataclass(frozen=True, repr=False)
class SourceCase:
    expanded_input: bytes = field(repr=False)
    initial_input: bytes = field(repr=False)
    readonly_input: bytes = field(repr=False)
    substitution_input: bytes = field(repr=False)
    record_length: int
    expected_state: MiddleState = field(repr=False)
    protocol_parameters: bool


def inspect_source_model(source_path: Path) -> str:
    source_bytes = source_path.read_bytes()
    tree = ast.parse(source_bytes, filename=str(source_path))
    for node in ast.walk(tree):
        if isinstance(node, (ast.Import, ast.ImportFrom, ast.Attribute, ast.With, ast.AsyncWith)):
            raise ValueError('generated source has an external runtime operation')
        if isinstance(node, ast.Call) and (not isinstance(node.func, ast.Name) or node.func.id not in ALLOWED_SOURCE_CALLS):
            raise ValueError('generated source calls an unexpected function')
    return hashlib.sha256(source_bytes).hexdigest()


def collect_native_cases(checkout: Path, layout: MiddleLayout) -> tuple[list[SourceCase], str]:
    cases: list[SourceCase] = []
    generator = random.Random(PUBLIC_CONTROL_SEED)
    with GuidMiddleOracle(checkout, layout) as oracle:
        seed_locations = readonly_seed_locations(oracle)
        readonly = b''.join(bytes(oracle.unicorn.mem_read(address, length)) for address, length in seed_locations)
        substitution = bytes(oracle.unicorn.mem_read(layout.lookup_address, LOOKUP_BYTE_COUNT))
        protocol_inputs = INVENTED_ANDROID_IDENTIFIERS if layout.name == 'forward' else tuple(bytes((index * 13 + length) & 255 for index in range(length)) for length in (80, 112, 147, 200))
        for android_identifier in protocol_inputs:
            state = oracle.derive_state(android_identifier)
            expanded = bytes(value ^ HASH_WIRE_XOR ^ layout.wire_xor for value in expand328(bytes(value ^ HASH_WIRE_XOR ^ layout.input_wire_xor for value in android_identifier)))
            cases.append(SourceCase(expanded, oracle.initial_second_fold, readonly, substitution, record_size(android_identifier) if layout.name == 'forward' else 20, state, True))
        for case_number in range(SYNTHETIC_CASE_COUNT):
            input_lengths = SYNTHETIC_INPUT_LENGTHS if layout.name == 'forward' else (60, 80, 147, 200)
            input_length = input_lengths[case_number % len(input_lengths)]
            android_identifier = generator.randbytes(input_length)
            expanded = generator.randbytes(EXPANDED_STATE_BYTES)
            initial = generator.randbytes(INITIAL_STATE_BYTES)
            readonly = generator.randbytes(sum(length for _, length in seed_locations))
            substitution = generator.randbytes(LOOKUP_PARAMETER_BYTES)
            oracle.initial_second_fold = initial
            oracle.prepare_state(android_identifier)
            oracle.unicorn.mem_write(oracle.frame_address - EXPANDED_STATE_FRAME_OFFSET, expanded)
            readonly_offset = 0
            for address, length in seed_locations:
                oracle.unicorn.mem_write(address, readonly[readonly_offset:readonly_offset + length])
                readonly_offset += length
            oracle.unicorn.mem_write(layout.lookup_address, substitution)
            oracle.unicorn.emu_start(layout.start_address, layout.end_address, count=MAXIMUM_INSTRUCTIONS)
            cases.append(SourceCase(expanded, initial, readonly, substitution, record_size(android_identifier) if layout.name == 'forward' else 20, oracle.capture_state(), False))
        artifact_digest = oracle.artifact_digest
    return cases, artifact_digest


def install_source_guard(checkout: Path) -> None:
    vendor_root = (checkout / 'rootfs').resolve()

    def guard(event: str, arguments: tuple[Any, ...]) -> None:
        if event in ('ctypes.dlopen', 'socket.__new__', 'subprocess.Popen'):
            raise RuntimeError('source phase attempted an external runtime operation')
        if event != 'open' or not arguments or not isinstance(arguments[0], (str, bytes)):
            return
        opened_path = Path(arguments[0].decode() if isinstance(arguments[0], bytes) else arguments[0]).resolve()
        if opened_path == vendor_root or vendor_root in opened_path.parents:
            raise RuntimeError('source phase attempted a vendor-file read')

    sys.addaudithook(guard)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout', type=Path)
    parser.add_argument('--model', type=Path)
    parser.add_argument('--kind', choices=('forward', 'hash'), default='forward')
    parser.add_argument('--output', type=Path, required=True)
    arguments = parser.parse_args()
    checkout = arguments.checkout.resolve()
    layout = HASH_LAYOUT if arguments.kind == 'hash' else FORWARD_LAYOUT
    model_path = arguments.model or Path(__file__).with_name('guid_hash_middle_source_model.py' if layout.name == 'hash' else 'guid_middle_source_model.py')
    source_digest = inspect_source_model(model_path)
    specification = importlib.util.spec_from_file_location('source_guid_middle', model_path)
    if specification is None or specification.loader is None:
        raise RuntimeError('source middle model is unavailable')
    model = importlib.util.module_from_spec(specification)
    specification.loader.exec_module(model)
    cases, artifact_digest = collect_native_cases(checkout, layout)
    install_source_guard(checkout)
    protocol_cases = 0
    synthetic_cases = 0
    changed_zero_lookup_controls = 0
    def finish_state(state: MiddleState, length: int) -> bytes:
        if layout.name == 'forward':
            return state.build_clear_record(length)
        from apple_music_source.auth._guid_hash_tail import assemble_hash_tail
        return assemble_hash_tail(state.scalar_bytes, *(bytes(value ^ layout.wire_xor for value in block) for block in (state.first_fold_bytes, state.second_fold_bytes, state.expanded_fold_bytes)))

    for case in cases:
        observed = MiddleState(*model.generate_middle_state(case.expanded_input, case.initial_input, case.readonly_input, case.substitution_input))
        if observed != case.expected_state:
            raise ValueError('source middle state differs from original execution')
        if finish_state(observed, case.record_length) != finish_state(case.expected_state, case.record_length):
            raise ValueError('source record differs from original execution')
        if case.protocol_parameters:
            protocol_cases += 1
            zeroed = MiddleState(*model.generate_middle_state(case.expanded_input, case.initial_input, case.readonly_input, bytes(LOOKUP_PARAMETER_BYTES)))
            changed_zero_lookup_controls += finish_state(zeroed, case.record_length) != finish_state(observed, case.record_length)
        else:
            synthetic_cases += 1
    if changed_zero_lookup_controls != protocol_cases:
        raise ValueError('lookup dependency controls did not alter every protocol record')
    report = dict(status='source middle and complete tail match original execution',kind=layout.name,protocol_parameter_profiles=protocol_cases,arbitrary_parameter_profiles=synthetic_cases,zero_lookup_controls_changed_records=changed_zero_lookup_controls,artifact_sha256=artifact_digest,source_sha256=source_digest,vendor_reads_during_source_execution=False,instruction_execution_during_source_phase=False,dynamic_loading_during_source_execution=False,network_requests=0,private_material_written=False,scope='parametric developer source model; static initial/seed/substitution parameter generation and full GUID/auth remain unfinished')
    arguments.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report))


if __name__ == '__main__':
    main()
