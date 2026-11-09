"""Reconstructed arithmetic after the first GUID field's middle calculation.

Header constants are immediate operands in CoreFP 0x2f807a..0x2f837f.
The three folds consume clear 64-, 64- and 328-byte states. Their native
cells have XOR-0x47 encoding, removed by the caller. Initial hash fill 0xc5
is already clear. This stage does not supply the unresolved state generator.
"""
from typing import Final

from ._guid_field_stages import mix20

SCALAR_FRAME_OFFSETS: Final[tuple[int, ...]] = tuple(range(0x3e, 0x33, -1)) + (0x2a,)
FOLD_STATE_LENGTHS: Final[tuple[int, ...]] = (64, 64, 328)
HASH_STATE_LENGTH: Final[int] = 20
INITIAL_HASH_FILL: Final[int] = 0xc5
BYTE_MASK: Final[int] = 0xff
HEADER_FIRST_INCREMENT: Final[int] = 0x7b
HEADER_FINAL_SCALAR_XOR: Final[int] = 0x96
HEADER_FINAL_DOUBLE_MASK: Final[int] = 0xf8
HEADER_FINAL_DOUBLE_XOR: Final[int] = 0xd0
HEADER_FINAL_SCALAR_INCREMENT: Final[int] = 0x84


def apply_hash_header(state: bytes, scalar_bytes: bytes) -> bytes:
    if len(state) != HASH_STATE_LENGTH or len(scalar_bytes) != len(SCALAR_FRAME_OFFSETS):
        raise ValueError('GUID hash header needs its 20-byte state and 12 scalar bytes')
    scalar_3e, scalar_3d, scalar_3c, scalar_3b, scalar_3a, scalar_39, scalar_38, scalar_37, scalar_36, scalar_35, scalar_34, scalar_2a = scalar_bytes
    increments = (
        scalar_34 + scalar_35 + scalar_3d + scalar_3e + HEADER_FIRST_INCREMENT,
        0xc2, scalar_3c, 0xd0, 0x14, 0x30, 0xa2, 0x8b,
        scalar_2a + 0x7a, scalar_39 + 0xd7, 0xba, scalar_36,
        0xd3, 0x19, 0xf9, 0x94, 0xfc, 0x43, 0xf4, 0x5f,
        0x86, 0x59, 0x6e, 0xaa, 0xee, scalar_3b + 0x91, 0x6f, 0x61,
        scalar_37 + scalar_38 + 0x3f, 0x2a,
        (scalar_3a ^ HEADER_FINAL_SCALAR_XOR)
        + (((scalar_3a * 2) & HEADER_FINAL_DOUBLE_MASK) ^ HEADER_FINAL_DOUBLE_XOR)
        + HEADER_FINAL_SCALAR_INCREMENT,
        0x68,
    )
    result = bytearray(state)
    for update_number, increment in enumerate(increments):
        position = update_number % HASH_STATE_LENGTH
        result[position] = (result[position] + increment) & BYTE_MASK
    return bytes(result)


def assemble_hash_tail(
    scalar_bytes: bytes,
    first_fold_state: bytes,
    second_fold_state: bytes,
    expanded_fold_state: bytes,
) -> bytes:
    fold_states = first_fold_state, second_fold_state, expanded_fold_state
    if tuple(map(len, fold_states)) != FOLD_STATE_LENGTHS:
        raise ValueError('GUID hash tail has incomplete fold states')
    state = bytearray(apply_hash_header(bytes([INITIAL_HASH_FILL]) * HASH_STATE_LENGTH, scalar_bytes))
    for fold_state in fold_states:
        for source_position, value in enumerate(fold_state):
            state[source_position % HASH_STATE_LENGTH] ^= value
    return mix20(state)
