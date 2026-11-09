"""Bounded native GUID field stages, without image or lookup dependencies.

CoreFP SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
Mixer body: 0x2f8510..0x2f85c7 (256 iterations on an observed 20-byte state).
Byte transform: 0x5e2151..0x5e2176 (multiply by -0x59, then add 0x12).

These stages do not derive their initial state, construct complete GUID fields,
or implement a native authentication provider. There are no fitted tables.
"""


def _state(value):
    if not isinstance(value,(bytes,bytearray,memoryview)):
        raise ValueError('GUID mixer state must contain 20 bytes')
    state=bytearray(value)
    if len(state)!=20:
        raise ValueError('GUID mixer state must contain 20 bytes')
    return state


def _rotate(value,amount):
    return ((value<<amount)|(value>>(8-amount)))&255


def _apply(state,index):
    at=index%20
    # Native EAX arithmetic wraps before unsigned DIV, including early
    # negative offsets. Python's signed modulo would produce different taps.
    state[at]^=(_rotate(state[((20+index-7)&0xffffffff)%20],1)
                ^_rotate(state[((20+index-37)&0xffffffff)%20],6)
                ^_rotate(state[((20+index-177)&0xffffffff)%20],5))


def mix20(value: bytes) -> bytes:
    """Apply the recovered 256-update cyclic mixer to a 20-byte state."""
    state=_state(value)
    for index in range(256):_apply(state,index)
    return bytes(state)


def unmix20(value: bytes) -> bytes:
    """Invert mix20; all three taps differ from the cell updated in each step."""
    state=_state(value)
    for index in range(255,-1,-1):_apply(state,index)
    return bytes(state)


def encode_bytes(value: bytes) -> bytes:
    """Apply the observed byte transform, without deriving its input buffer."""
    if not isinstance(value,(bytes,bytearray,memoryview)):
        raise ValueError('field input must be bytes-like')
    return bytes((167*byte+18)&255 for byte in bytes(value))
