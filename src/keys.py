"""Sample-key material captured from one FairPlay source session."""

from __future__ import annotations

from dataclasses import dataclass
from functools import cached_property

from .aes import aes_backend

from .source_package import ensure_importable

ensure_importable()

from apple_music_source.crypto import corelskd

BLOCK_SIZE = 16


@dataclass(frozen=True)
class KeyMaterial:
    """The CoreLSKD context, chaining state and registers for one key URI."""

    key_uri: str
    context: bytes
    state: bytes
    rax: int
    rcx: int

    def content_key(self) -> bytes:
        return corelskd.extract_key(self.context, self.state, self.rax, self.rcx)

    @cached_property
    def _aes_parameters(self) -> tuple[bytes, bytes] | None:
        backend = aes_backend()
        if backend is None:
            return None
        key = self.content_key()
        zero_block = bytes(BLOCK_SIZE)
        native_plaintext = corelskd.cbc(
            self.context, self.state, self.rax, self.rcx, None, zero_block)
        unchained_plaintext = backend.decrypt(key, zero_block, zero_block)
        iv = bytes(native ^ unchained for native, unchained
                   in zip(native_plaintext, unchained_plaintext))
        return key, iv

    def decrypt_sample(self, sample: bytes) -> bytes:
        block_length = len(sample) - len(sample) % BLOCK_SIZE
        if block_length == 0:
            return bytes(sample)
        parameters = self._aes_parameters
        if parameters is not None:
            key, iv = parameters
            plain = aes_backend().decrypt(key, iv, bytes(sample[:block_length]))
            return plain + bytes(sample[block_length:])
        plain = corelskd.cbc(
            self.context,
            self.state,
            self.rax,
            self.rcx,
            None,
            bytes(sample[:block_length]),
        )
        return plain + bytes(sample[block_length:])
