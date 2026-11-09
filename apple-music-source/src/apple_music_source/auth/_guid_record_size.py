"""Source-owned size calculation for the Android-ID GUID input record.

CoreFP SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
Source: 0x2f8605..0x2f87c8 and 0x2f8b89..0x2f8ba8.
The selected native transform accepts an 8..80-byte input. Its accumulator
starts at 5 and subtracts repeated input bytes modulo 121 for length+355
iterations; adding 80 gives the output record length. This computes the size
only, not the record contents or a complete GUID/authentication provider.
"""


def record_size(value: bytes) -> int:
    """Return the selected native transform's record size (80..200 bytes)."""
    if not isinstance(value, (bytes, bytearray, memoryview)):
        raise ValueError('GUID record source must be bytes-like')
    value = bytes(value)
    if not 8 <= len(value) <= 80:
        raise ValueError('GUID record source must contain 8..80 bytes')
    repetitions, tail = divmod(len(value) + 355, len(value))
    residue = (5 - repetitions * sum(value) - sum(value[:tail])) % 121
    return 80 + residue
