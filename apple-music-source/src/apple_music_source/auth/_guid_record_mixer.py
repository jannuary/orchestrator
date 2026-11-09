"""Source arithmetic for the variable-length GUID initializer record mixer.

CoreFP SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
Original update body: 0x2fb6b0..0x2fb879, repeated 256 times.
The native wire cells use XOR 0x47; this function operates on clear bytes.
It uses ordinary cyclic taps. The separate final 20-byte field mixer has
different native index arithmetic and must not be substituted here.

The caller's preceding record generation remains unfinished. No lookup bank,
image bytes or fitted parameters are used by this stage.
"""


def _rotate(value, amount):
    return ((value << amount) | (value >> (8 - amount))) & 255


def mix_record(value: bytes) -> bytes:
    """Apply 256 native cyclic updates to a nonempty clear byte record.

    Lengths through 2**31 keep the native 32-bit index sums from overflowing.
    Tap reads all precede each store, including when a tap aliases that store.
    """
    if not isinstance(value, (bytes, bytearray, memoryview)):
        raise ValueError('GUID record must be bytes-like')
    state = bytearray(value)
    length = len(state)
    if not 1 <= length <= 0x80000000:
        raise ValueError('GUID record needs a nonempty bounded length')
    for index in range(256):
        at = index % length
        state[at] ^= (
            _rotate(state[(at - 7) % length], 1)
            ^ _rotate(state[(at - 37) % length], 6)
            ^ _rotate(state[(at - 177) % length], 5)
        )
    return bytes(state)
