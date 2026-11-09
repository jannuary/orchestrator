"""Sample-key material captured from one FairPlay source session."""

from __future__ import annotations

from dataclasses import dataclass

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

    def decrypt_sample(self, sample: bytes) -> bytes:
        block_length = len(sample) - len(sample) % BLOCK_SIZE
        if block_length == 0:
            return bytes(sample)
        plain = corelskd.cbc(
            self.context,
            self.state,
            self.rax,
            self.rcx,
            None,
            bytes(sample[:block_length]),
        )
        return plain + bytes(sample[block_length:])
