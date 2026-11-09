"""Small, dependency-free AES (128/192/256) with CBC mode.

This is an independent, portable implementation written from the AES
specification.  It contains no target-derived tables: the S-box is generated
from GF(2**8) inversion and the standard affine transform at import time.

CBC here is ordinary AES-CBC.  It is useful once a caller has recovered the
plain 16-byte content key from a CoreLSKD capture (see
``apple_music_source.crypto.corelskd``).  It does not implement Apple's
obfuscated CoreLSKD block transform and does not remove padding unless asked.
"""

from __future__ import annotations

import hmac

__all__ = [
    "AES",
    "AESError",
    "aes_cbc_decrypt",
    "aes_cbc_encrypt",
    "decrypt_block",
    "encrypt_block",
    "pkcs7_pad",
    "pkcs7_unpad",
]


class AESError(ValueError):
    """Invalid AES key, IV, block, or padding input."""


def _xtime(value: int) -> int:
    value <<= 1
    return (value ^ 0x11B) if value & 0x100 else value


def _gmul(a: int, b: int) -> int:
    result = 0
    for _ in range(8):
        if b & 1:
            result ^= a
        a = _xtime(a)
        b >>= 1
    return result


def _gpow(value: int, exponent: int) -> int:
    result = 1
    while exponent:
        if exponent & 1:
            result = _gmul(result, value)
        value = _gmul(value, value)
        exponent >>= 1
    return result


def _rotl8(value: int, count: int) -> int:
    return ((value << count) | (value >> (8 - count))) & 0xFF


def _build_sbox() -> bytes:
    values = []
    for value in range(256):
        inverse = 0 if value == 0 else _gpow(value, 254)
        transformed = (
            inverse
            ^ _rotl8(inverse, 1)
            ^ _rotl8(inverse, 2)
            ^ _rotl8(inverse, 3)
            ^ _rotl8(inverse, 4)
            ^ 0x63
        )
        values.append(transformed)
    return bytes(values)


_SBOX = _build_sbox()
_INV_SBOX = bytes(_SBOX.index(value) for value in range(256))
_RCON = [0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36]


def _check_bytes(value, name: str, length: int | None = None) -> bytes:
    if not isinstance(value, (bytes, bytearray, memoryview)):
        raise AESError(f"{name} must be bytes-like")
    data = bytes(value)
    if length is not None and len(data) != length:
        raise AESError(f"{name} must contain exactly {length} bytes")
    return data


class AES:
    """AES block cipher for one caller-supplied key."""

    block_size = 16

    def __init__(self, key: bytes):
        key = _check_bytes(key, "key")
        if len(key) not in (16, 24, 32):
            raise AESError("AES key must contain 16, 24, or 32 bytes")
        self.key = key
        self.rounds = {16: 10, 24: 12, 32: 14}[len(key)]
        self._round_keys = self._expand(key)

    def _expand(self, key: bytes) -> list[list[int]]:
        nk = len(key) // 4
        words = [list(key[4 * index : 4 * index + 4]) for index in range(nk)]
        for index in range(nk, 4 * (self.rounds + 1)):
            temp = words[index - 1][:]
            if index % nk == 0:
                temp = temp[1:] + temp[:1]
                temp = [_SBOX[value] for value in temp]
                temp[0] ^= _RCON[index // nk]
            elif nk > 6 and index % nk == 4:
                temp = [_SBOX[value] for value in temp]
            words.append([words[index - nk][offset] ^ temp[offset] for offset in range(4)])
        return [sum(words[4 * rnd : 4 * rnd + 4], []) for rnd in range(self.rounds + 1)]

    @staticmethod
    def _add_round_key(state: list[int], round_key: list[int]) -> None:
        for index in range(16):
            state[index] ^= round_key[index]

    @staticmethod
    def _sub_bytes(state: list[int], box: bytes) -> None:
        for index in range(16):
            state[index] = box[state[index]]

    @staticmethod
    def _shift_rows(state: list[int]) -> None:
        for row in range(1, 4):
            values = [state[4 * column + row] for column in range(4)]
            values = values[row:] + values[:row]
            for column in range(4):
                state[4 * column + row] = values[column]

    @staticmethod
    def _inv_shift_rows(state: list[int]) -> None:
        for row in range(1, 4):
            values = [state[4 * column + row] for column in range(4)]
            values = values[-row:] + values[:-row]
            for column in range(4):
                state[4 * column + row] = values[column]

    @staticmethod
    def _mix_columns(state: list[int]) -> None:
        for column in range(4):
            offset = 4 * column
            a0, a1, a2, a3 = state[offset : offset + 4]
            state[offset] = _gmul(a0, 2) ^ _gmul(a1, 3) ^ a2 ^ a3
            state[offset + 1] = a0 ^ _gmul(a1, 2) ^ _gmul(a2, 3) ^ a3
            state[offset + 2] = a0 ^ a1 ^ _gmul(a2, 2) ^ _gmul(a3, 3)
            state[offset + 3] = _gmul(a0, 3) ^ a1 ^ a2 ^ _gmul(a3, 2)

    @staticmethod
    def _inv_mix_columns(state: list[int]) -> None:
        for column in range(4):
            offset = 4 * column
            a0, a1, a2, a3 = state[offset : offset + 4]
            state[offset] = _gmul(a0, 14) ^ _gmul(a1, 11) ^ _gmul(a2, 13) ^ _gmul(a3, 9)
            state[offset + 1] = _gmul(a0, 9) ^ _gmul(a1, 14) ^ _gmul(a2, 11) ^ _gmul(a3, 13)
            state[offset + 2] = _gmul(a0, 13) ^ _gmul(a1, 9) ^ _gmul(a2, 14) ^ _gmul(a3, 11)
            state[offset + 3] = _gmul(a0, 11) ^ _gmul(a1, 13) ^ _gmul(a2, 9) ^ _gmul(a3, 14)

    def encrypt_block(self, block: bytes) -> bytes:
        state = list(_check_bytes(block, "block", 16))
        self._add_round_key(state, self._round_keys[0])
        for rnd in range(1, self.rounds):
            self._sub_bytes(state, _SBOX)
            self._shift_rows(state)
            self._mix_columns(state)
            self._add_round_key(state, self._round_keys[rnd])
        self._sub_bytes(state, _SBOX)
        self._shift_rows(state)
        self._add_round_key(state, self._round_keys[self.rounds])
        return bytes(state)

    def decrypt_block(self, block: bytes) -> bytes:
        state = list(_check_bytes(block, "block", 16))
        self._add_round_key(state, self._round_keys[self.rounds])
        for rnd in range(self.rounds - 1, 0, -1):
            self._inv_shift_rows(state)
            self._sub_bytes(state, _INV_SBOX)
            self._add_round_key(state, self._round_keys[rnd])
            self._inv_mix_columns(state)
        self._inv_shift_rows(state)
        self._sub_bytes(state, _INV_SBOX)
        self._add_round_key(state, self._round_keys[0])
        return bytes(state)


def _check_iv(iv: bytes) -> bytes:
    return _check_bytes(iv, "iv", 16)


def encrypt_block(key: bytes, block: bytes) -> bytes:
    """Encrypt one 16-byte block with AES-128/192/256."""
    return AES(key).encrypt_block(block)


def decrypt_block(key: bytes, block: bytes) -> bytes:
    """Decrypt one 16-byte block with AES-128/192/256."""
    return AES(key).decrypt_block(block)


def pkcs7_pad(data: bytes, block_size: int = 16) -> bytes:
    data = _check_bytes(data, "data")
    if block_size != 16:
        raise AESError("AES padding requires a 16-byte block size")
    count = block_size - (len(data) % block_size)
    return data + bytes([count]) * count


def pkcs7_unpad(data: bytes, block_size: int = 16) -> bytes:
    data = _check_bytes(data, "data")
    if block_size != 16 or not data or len(data) % block_size:
        raise AESError("padded data must be a nonempty multiple of 16 bytes")
    count = data[-1]
    if not 1 <= count <= block_size or not hmac.compare_digest(
        data[-count:], bytes([count]) * count
    ):
        raise AESError("invalid PKCS#7 padding")
    return data[:-count]


def aes_cbc_encrypt(key: bytes, iv: bytes, plaintext: bytes, *, pad: bool = True) -> bytes:
    """Encrypt with AES-CBC.  PKCS#7 padding is applied by default."""
    iv = _check_iv(iv)
    plaintext = _check_bytes(plaintext, "plaintext")
    if pad:
        plaintext = pkcs7_pad(plaintext)
    elif not plaintext or len(plaintext) % 16:
        raise AESError("unpadded plaintext must be a nonempty multiple of 16 bytes")
    cipher = AES(key)
    previous = iv
    output = bytearray()
    for offset in range(0, len(plaintext), 16):
        block = bytes(a ^ b for a, b in zip(plaintext[offset : offset + 16], previous))
        previous = cipher.encrypt_block(block)
        output.extend(previous)
    return bytes(output)


def aes_cbc_decrypt(
    key: bytes, iv: bytes, ciphertext: bytes, *, unpad: bool = False
) -> bytes:
    """Decrypt with AES-CBC.  Padding is left intact unless ``unpad`` is true."""
    iv = _check_iv(iv)
    ciphertext = _check_bytes(ciphertext, "ciphertext")
    if not ciphertext or len(ciphertext) % 16:
        raise AESError("ciphertext must be a nonempty multiple of 16 bytes")
    cipher = AES(key)
    previous = iv
    output = bytearray()
    for offset in range(0, len(ciphertext), 16):
        block = ciphertext[offset : offset + 16]
        plain = cipher.decrypt_block(block)
        output.extend(a ^ b for a, b in zip(plain, previous))
        previous = block
    return pkcs7_unpad(bytes(output)) if unpad else bytes(output)
