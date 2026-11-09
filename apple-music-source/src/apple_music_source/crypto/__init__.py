"""Cryptographic primitives implemented in this package.

The public surface includes:

* :mod:`apple_music_source.crypto.aes` - portable AES-128/192/256 and CBC,
  generated from the AES specification without target-derived tables.
* :mod:`apple_music_source.crypto.corelskd` - the source-reconstructed
  CoreLSKD block transform, CBC chaining, and content-key extraction from a
  caller-supplied captured key context.
* :mod:`apple_music_source.crypto.fps` - source SPC generation and matching
  FPS-session CKC operations.

SPC envelopes, dispatcher argument vectors and recovered compatibility helpers
are available through SPCV2 and CryptoPrimitives. initial_iv decodes the CBC
chain from a caller context for independent AES.

Online CKC-to-content-key processing is not verified. Nothing here executes an
original SDK image or falls back to a vendor library.
"""

from .aes import (
    AES,
    AESError,
    aes_cbc_decrypt,
    aes_cbc_encrypt,
    decrypt_block,
    encrypt_block,
    pkcs7_pad,
    pkcs7_unpad,
)
from .corelskd import (
    CoreLSKD,
    CoreLSKDError,
    CoreLSKDStatus,
    NativeLibraryUnavailable,
    block,
    cbc,
    default_library_path,
    extract_key,
    initial_iv,
    load_library,
)
from .protocol import SPCV2, CryptoPrimitives, DispatchPacket, decode_dispatch_status
from .masked_cbc import MaskedCBC
from .fps import SourceSession, SourceSessionError, default_fps_library_path

__all__ = [
    "SPCV2",
    "SourceSession",
    "SourceSessionError",
    "CryptoPrimitives",
    "DispatchPacket",
    "decode_dispatch_status",
    "AES",
    "AESError",
    "MaskedCBC",
    "CoreLSKD",
    "CoreLSKDError",
    "CoreLSKDStatus",
    "NativeLibraryUnavailable",
    "aes_cbc_decrypt",
    "aes_cbc_encrypt",
    "block",
    "cbc",
    "decrypt_block",
    "default_fps_library_path",
    "default_library_path",
    "encrypt_block",
    "extract_key",
    "initial_iv",
    "load_library",
    "pkcs7_pad",
    "pkcs7_unpad",
]
