"""Source arithmetic for the reconstructed GUID record tail.

The native initial record fill 0x72 uses XOR-0x47 storage encoding, giving
the clear fill 0x35. Header increments and masks are instruction operands
proved in guid-record-header-arithmetic.json, rather than captured data.
Input-state generation is unfinished; this remains a developer model.
"""

from typing import Final

from apple_music_source.auth._guid_record_mixer import mix_record

SCALAR_FRAME_OFFSETS: Final[tuple[int, ...]] = (207, 206, 205, 204, 203, 202, 201, 200, 199, 184, 76, 72, 71, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 42)
MINIMUM_NATIVE_RECORD_SIZE: Final[int] = 80
MAXIMUM_NATIVE_RECORD_SIZE: Final[int] = 200
EXPECTED_FOLD_STATE_SIZES: Final[tuple[int, ...]] = (64, 64, 328)
INITIAL_CLEAR_RECORD_FILL: Final[int] = 0x35
BYTE_VALUE_MASK: Final[int] = 0xff
SCALAR_SHAPING_BASE: Final[int] = 42
SCALAR_SHAPING_FACTOR: Final[int] = 2
SCALAR_SHAPING_MASK: Final[int] = 238
SCALAR_SHAPING_INCREMENT: Final[int] = 44
HEADER_BYTE_0_FIXED_INCREMENT: Final[int] = 131
HEADER_BYTE_2_FIXED_INCREMENT: Final[int] = 55
HEADER_BYTE_3_FIXED_INCREMENT: Final[int] = 20
HEADER_BYTE_5_SCALAR_XOR_MASK: Final[int] = 29
HEADER_BYTE_6_SCALAR_XOR_MASK: Final[int] = 84
HEADER_BYTE_8_FIXED_INCREMENT: Final[int] = 129
HEADER_BYTE_9_FIXED_INCREMENT: Final[int] = 91
HEADER_BYTE_10_FIXED_INCREMENT: Final[int] = 108
HEADER_BYTE_11_FIXED_INCREMENT: Final[int] = 184
HEADER_BYTE_12_SCALAR_XOR_MASK: Final[int] = 44
HEADER_BYTE_13_FIXED_INCREMENT: Final[int] = 168
HEADER_BYTE_14_FIXED_INCREMENT: Final[int] = 133
HEADER_BYTE_15_FIXED_INCREMENT: Final[int] = 146
HEADER_BYTE_16_FIXED_INCREMENT: Final[int] = 34
HEADER_BYTE_17_FIXED_INCREMENT: Final[int] = 228
HEADER_BYTE_19_FIXED_INCREMENT: Final[int] = 148
HEADER_BYTE_20_FIXED_INCREMENT: Final[int] = 4
HEADER_BYTE_22_FIXED_INCREMENT: Final[int] = 31
HEADER_BYTE_23_SCALAR_XOR_MASK: Final[int] = 118
HEADER_BYTE_23_FIXED_INCREMENT: Final[int] = 128
HEADER_BYTE_24_FIXED_INCREMENT: Final[int] = 113
HEADER_BYTE_25_SCALAR_XOR_MASK: Final[int] = 78
HEADER_BYTE_26_FIXED_INCREMENT: Final[int] = 254
HEADER_BYTE_27_FIXED_INCREMENT: Final[int] = 24
HEADER_BYTE_28_FIXED_INCREMENT: Final[int] = 208
HEADER_BYTE_29_FIXED_INCREMENT: Final[int] = 62
HEADER_BYTE_30_FIXED_INCREMENT: Final[int] = 193
HEADER_BYTE_31_SCALAR_XOR_MASK: Final[int] = 42
HEADER_BYTE_31_FIXED_INCREMENT: Final[int] = 128


def assemble_record_tail(
    record_size: int,
    intermediate_scalar_bytes: bytes,
    first_fold_state: bytes,
    second_fold_state: bytes,
    expanded_fold_state: bytes,
) -> bytes:
    if not MINIMUM_NATIVE_RECORD_SIZE <= record_size <= MAXIMUM_NATIVE_RECORD_SIZE:
        raise ValueError('record size is outside the native bounds')
    if len(intermediate_scalar_bytes) != len(SCALAR_FRAME_OFFSETS):
        raise ValueError('record tail needs every intermediate scalar byte')
    fold_states = (first_fold_state, second_fold_state, expanded_fold_state)
    if tuple(map(len, fold_states)) != EXPECTED_FOLD_STATE_SIZES:
        raise ValueError('record tail has incomplete fold states')
    (
        scalar_frame_cf,
        scalar_frame_ce,
        scalar_frame_cd,
        scalar_frame_cc,
        scalar_frame_cb,
        scalar_frame_ca,
        scalar_frame_c9,
        scalar_frame_c8,
        scalar_frame_c7,
        scalar_frame_b8,
        scalar_frame_4c,
        scalar_frame_48,
        scalar_frame_47,
        scalar_frame_3f,
        scalar_frame_3e,
        scalar_frame_3d,
        scalar_frame_3c,
        scalar_frame_3b,
        scalar_frame_3a,
        scalar_frame_39,
        scalar_frame_38,
        scalar_frame_37,
        scalar_frame_36,
        scalar_frame_35,
        scalar_frame_34,
        scalar_frame_2a,
    ) = intermediate_scalar_bytes
    header_increments: tuple[int, ...] = (
        HEADER_BYTE_0_FIXED_INCREMENT,
        scalar_frame_3b,
        HEADER_BYTE_2_FIXED_INCREMENT,
        HEADER_BYTE_3_FIXED_INCREMENT,
        scalar_frame_36,
        (scalar_frame_3f ^ HEADER_BYTE_5_SCALAR_XOR_MASK),
        (scalar_frame_38 ^ HEADER_BYTE_6_SCALAR_XOR_MASK),
        scalar_frame_3c,
        scalar_frame_3e + scalar_frame_3d + HEADER_BYTE_8_FIXED_INCREMENT,
        scalar_frame_cc + HEADER_BYTE_9_FIXED_INCREMENT,
        HEADER_BYTE_10_FIXED_INCREMENT,
        HEADER_BYTE_11_FIXED_INCREMENT,
        (scalar_frame_cd ^ HEADER_BYTE_12_SCALAR_XOR_MASK),
        HEADER_BYTE_13_FIXED_INCREMENT,
        HEADER_BYTE_14_FIXED_INCREMENT,
        scalar_frame_cb + scalar_frame_ca + HEADER_BYTE_15_FIXED_INCREMENT,
        HEADER_BYTE_16_FIXED_INCREMENT,
        HEADER_BYTE_17_FIXED_INCREMENT,
        scalar_frame_b8 + ((SCALAR_SHAPING_BASE - SCALAR_SHAPING_FACTOR * scalar_frame_b8) & SCALAR_SHAPING_MASK) + SCALAR_SHAPING_INCREMENT,
        scalar_frame_c9 + scalar_frame_c8 + scalar_frame_34 - scalar_frame_35 + HEADER_BYTE_19_FIXED_INCREMENT,
        scalar_frame_3a + scalar_frame_39 + HEADER_BYTE_20_FIXED_INCREMENT,
        scalar_frame_48,
        HEADER_BYTE_22_FIXED_INCREMENT,
        (scalar_frame_47 ^ HEADER_BYTE_23_SCALAR_XOR_MASK) + HEADER_BYTE_23_FIXED_INCREMENT,
        HEADER_BYTE_24_FIXED_INCREMENT,
        (scalar_frame_c7 ^ HEADER_BYTE_25_SCALAR_XOR_MASK),
        HEADER_BYTE_26_FIXED_INCREMENT,
        HEADER_BYTE_27_FIXED_INCREMENT,
        HEADER_BYTE_28_FIXED_INCREMENT,
        scalar_frame_cf + scalar_frame_ce + HEADER_BYTE_29_FIXED_INCREMENT,
        scalar_frame_2a - scalar_frame_37 + HEADER_BYTE_30_FIXED_INCREMENT,
        (scalar_frame_4c ^ HEADER_BYTE_31_SCALAR_XOR_MASK) + HEADER_BYTE_31_FIXED_INCREMENT,
    )
    record_state = bytearray([INITIAL_CLEAR_RECORD_FILL]) * record_size
    for record_offset, header_increment in enumerate(header_increments):
        record_state[record_offset] = (record_state[record_offset] + header_increment) & BYTE_VALUE_MASK
    for fold_state in fold_states:
        for state_offset, state_byte in enumerate(fold_state):
            record_state[state_offset % record_size] ^= state_byte
    return mix_record(record_state)
