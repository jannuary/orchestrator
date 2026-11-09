"""Native GUID input expansion stage, reconstructed as byte arithmetic.

CoreFP SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
Source: 0x2f65b0..0x2f6788. The native input is repeated into 328 bytes, then
mixed for four passes with three cyclic taps. The native cells encode their
working byte by XOR with 0x47; removing that encoding exposes the arithmetic.
No binary/table data or fitted constants are used. This is a bounded stage;
its caller's input selection and validation remain unreconstructed.
"""


def _rotate(value,amount):
    return ((value<<amount)|(value>>(8-amount)))&255


def expand328(value: bytes) -> bytes:
    """Produce the native 328-byte mixed buffer from a nonempty byte string."""
    if not isinstance(value,(bytes,bytearray,memoryview)):
        raise ValueError('GUID expansion input must be bytes-like')
    value=bytes(value)
    if not value or len(value)>0xffffffff:
        raise ValueError('GUID expansion needs a nonempty 32-bit length')
    state=bytearray(value[index%len(value)]^0x47 for index in range(328))
    for index in range(4*328):
        at=index%328
        state[at]=((state[at]^_rotate(state[(index-13)%328],3))
                   +_rotate(state[(index-57)%328],5)
                   -_rotate(state[(index-155)%328],7))&255
    return bytes(byte^0x47 for byte in state)
