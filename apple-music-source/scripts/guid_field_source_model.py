"""Complete first-GUID arithmetic with unresolved parameters supplied explicitly.

This developer model contains no image data, native runtime or instruction
execution. Its six fixed state/lookup inputs have not been semantically
recovered and therefore are deliberately absent from the runtime package.
"""
from __future__ import annotations

from dataclasses import dataclass, field

from apple_music_source.auth._guid_hash_tail import assemble_hash_tail
from apple_music_source.auth._guid_input_expansion import expand328
from apple_music_source.auth._guid_record_size import record_size
from guid_middle_source_model import generate_middle_state as generate_record_middle
from guid_hash_middle_source_model import generate_middle_state as generate_hash_middle
from guid_record_tail_model import assemble_record_tail

RECORD_WIRE_XOR: int = 0x47
FORWARD_WIRE_XOR: int = 0x54
FIRST_FIELD_LENGTH: int = 18


@dataclass(frozen=True, repr=False)
class MiddleParameters:
    initial_fold: bytes = field(repr=False)
    readonly_seed: bytes = field(repr=False)
    substitution: bytes = field(repr=False)


def derive_first_guid_field(
    android_identifier: bytes,
    record_parameters: MiddleParameters,
    hash_parameters: MiddleParameters,
) -> bytes:
    length = record_size(android_identifier)
    expanded = bytes(
        value ^ RECORD_WIRE_XOR ^ FORWARD_WIRE_XOR
        for value in expand328(bytes(value ^ RECORD_WIRE_XOR for value in android_identifier))
    )
    record_scalars, *record_blocks = generate_record_middle(
        expanded, record_parameters.initial_fold,
        record_parameters.readonly_seed, record_parameters.substitution,
    )
    record = assemble_record_tail(
        length, record_scalars,
        *(bytes(value ^ FORWARD_WIRE_XOR for value in block) for block in record_blocks),
    )
    hash_input = bytes(value ^ RECORD_WIRE_XOR for value in record)
    hash_scalars, *hash_blocks = generate_hash_middle(
        expand328(hash_input), hash_parameters.initial_fold,
        hash_parameters.readonly_seed, hash_parameters.substitution,
    )
    result = assemble_hash_tail(
        hash_scalars,
        *(bytes(value ^ RECORD_WIRE_XOR for value in block) for block in hash_blocks),
    )
    return result[:FIRST_FIELD_LENGTH]
