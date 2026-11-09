"""AES-128 CBC with caller-provided IV, plaintext and ciphertext XOR masks.

This is the byte transform identified in two reconstructed kernel
paths. The caller must supply the key and masks; this module does not recover
the missing source parameter initializer or acquire a session/content key.
It uses the specification-generated AES S-box, with no target-derived tables.
"""
from .aes import AES, AESError, _check_bytes


def _xor(left: bytes, right: bytes) -> bytes:
    return bytes(a ^ b for a, b in zip(left, right))


class MaskedCBC:
    """A caller-keyed transform with logical ciphertext feedback.

    The initial chain is ``iv XOR iv_mask``. Encryption applies ordinary CBC
    after XORing ``plaintext_mask`` into each input block, then XORs
    ``output_mask`` into each returned block. Feedback uses the ciphertext
    before this output mask. Decryption removes both block masks in reverse
    order. The optional plaintext mask defaults to zero. No padding is applied.

    Parameters are copied and excluded from the object's representation.
    This models byte results, not native packets, faults, budgets or aliases.
    """

    __slots__ = ("_cipher", "_iv_mask", "_output_mask", "_plaintext_mask")
    block_size = 16

    def __init__(self, key: bytes, iv_mask: bytes, output_mask: bytes, *, plaintext_mask: bytes = bytes(16)):
        key = _check_bytes(key, "key", 16)
        self._iv_mask = _check_bytes(iv_mask, "iv_mask", 16)
        self._output_mask = _check_bytes(output_mask, "output_mask", 16)
        self._plaintext_mask = _check_bytes(plaintext_mask, "plaintext_mask", 16)
        self._cipher = AES(key)

    def _input(self, data, iv, name):
        data = _check_bytes(data, name)
        iv = _check_bytes(iv, "iv", 16)
        if len(data) % 16:
            raise AESError(f"{name} length must be a multiple of 16 bytes")
        return data, _xor(iv, self._iv_mask)

    def encrypt(self, plaintext: bytes, iv: bytes) -> bytes:
        """Return masked ciphertext for a whole block-aligned message."""
        data, chain = self._input(plaintext, iv, "plaintext")
        output = bytearray()
        for start in range(0, len(data), 16):
            block = _xor(data[start:start + 16], self._plaintext_mask)
            chain = self._cipher.encrypt_block(_xor(block, chain))
            output.extend(_xor(chain, self._output_mask))
        return bytes(output)

    def decrypt(self, ciphertext: bytes, iv: bytes) -> bytes:
        """Invert :meth:`encrypt` without removing or validating padding."""
        data, chain = self._input(ciphertext, iv, "ciphertext")
        output = bytearray()
        for start in range(0, len(data), 16):
            block = _xor(data[start:start + 16], self._output_mask)
            output.extend(_xor(_xor(self._cipher.decrypt_block(block), chain), self._plaintext_mask))
            chain = block
        return bytes(output)
