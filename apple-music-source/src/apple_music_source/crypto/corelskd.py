"""Python bindings for the source-reconstructed CoreLSKD block transform.

The native C source shipped in ``_native`` is a source-level translation of the
fixed CoreLSKD interval used by the original Android client.  It executes no
original machine code, loads no vendor library, and contains no opaque lookup
tables.  The caller still supplies the ``ctx``, ``state``, ``rax`` and ``rcx``
values from an existing ``/key`` response; this module does not acquire keys.

The wheel build compiles the C source into ``_native/libcorelskd_r1.so``.
There is deliberately no fallback to a checkout, an emulator, or a proprietary
library.
"""

from __future__ import annotations

import ctypes
import os
from enum import IntEnum
from pathlib import Path

__all__ = [
    "CoreLSKD",
    "CoreLSKDError",
    "CoreLSKDStatus",
    "NativeLibraryUnavailable",
    "default_library_path",
    "load_library",
    "initial_iv",
]

CTX_SIZE = 0x8000
STATE_SIZE = 0x2100
LIBRARY_NAME = "libcorelskd_r1.so"


def initial_iv(ctx: bytes, state: bytes) -> bytes:
    """Decode this build's initial CBC chain for independent AES decryption.

    The encoding must be a permutation. This validates the chain encoding,
    not the key schedule; use extract_key to validate/extract that separately.
    No caller memory is modified.
    """
    ctx = _bytes(ctx, "ctx", exact=CTX_SIZE)
    state = _bytes(state, "state", minimum=STATE_SIZE)
    inverse = {value: index for index, value in enumerate(ctx[0x4180:0x4280])}
    if len(inverse) != 256:
        raise ValueError("initial IV encoding is not bijective")
    chain = (0x178, 0x190, 0x118, 0x3e0, 0x160, 0x188, 0xe0, 0x120,
             0x100, 0xd0, 0xf8, 0x108, 0xf0, 0xe8, 0x410, 0xc0)
    return bytes(inverse[state[0x2000 - offset] ^ ctx[0x38ed]] for offset in chain)


class NativeLibraryUnavailable(RuntimeError):
    """The package-owned native library has not been built or installed."""


class CoreLSKDStatus(IntEnum):
    OK = 0
    INVALID = 1
    READ_FAULT = 2
    WRITE_FAULT = 3
    STEP_LIMIT = 4


class CoreLSKDError(RuntimeError):
    """A CoreLSKD call failed closed."""

    def __init__(self, operation: str, status: int):
        self.operation = operation
        self.status = int(status)
        try:
            label = CoreLSKDStatus(self.status).name
        except ValueError:
            label = "UNKNOWN"
        super().__init__(f"CoreLSKD {operation} failed: {label} ({self.status})")


def default_library_path() -> Path:
    """Return the installed package path, or an explicit environment override."""
    override = os.environ.get("APPLE_MUSIC_SOURCE_CORELSKD_LIB")
    if override:
        return Path(override).expanduser()
    return Path(__file__).resolve().parent.parent / "_native" / LIBRARY_NAME


def load_library(path: str | os.PathLike | None = None) -> ctypes.CDLL:
    """Load the package-owned CoreLSKD library.

    ``path`` is useful for tests and for a caller that built the source itself.
    A missing file raises :class:`NativeLibraryUnavailable`; it never searches
    the wrapper checkout or the system for a replacement library.
    """
    library = Path(path) if path is not None else default_library_path()
    if not library.is_file():
        raise NativeLibraryUnavailable(
            f"CoreLSKD native library is not available at {library}. "
            "Install a wheel built from this package or run the package build "
            "backend; no vendor or checkout fallback is used."
        )
    try:
        return ctypes.CDLL(str(library))
    except OSError as error:
        raise NativeLibraryUnavailable(
            f"CoreLSKD native library could not be loaded from {library}: {error}"
        ) from error


def _bytes(value, name: str, *, exact: int | None = None, minimum: int | None = None) -> bytes:
    if not isinstance(value, (bytes, bytearray, memoryview)):
        raise TypeError(f"{name} must be bytes-like")
    data = bytes(value)
    if exact is not None and len(data) != exact:
        raise ValueError(f"{name} must contain exactly {exact} bytes")
    if minimum is not None and len(data) < minimum:
        raise ValueError(f"{name} must contain at least {minimum} bytes")
    return data


def _index(value, name: str) -> int:
    if isinstance(value, bool) or not isinstance(value, int) or not 0 <= value <= 255:
        raise ValueError(f"{name} must be an integer in 0..255")
    return value


class CoreLSKD:
    """Call the source-reconstructed block/CBC/key-extraction entry points."""

    def __init__(self, library: str | os.PathLike | ctypes.CDLL | None = None):
        self._library = load_library(library) if not isinstance(library, ctypes.CDLL) else library
        self._block = self._library.corelskd_r1_block
        self._block.argtypes = [
            ctypes.c_void_p,
            ctypes.c_void_p,
            ctypes.c_size_t,
            ctypes.c_uint64,
            ctypes.c_uint64,
            ctypes.c_void_p,
            ctypes.c_void_p,
        ]
        self._block.restype = ctypes.c_int
        self._cbc = self._library.corelskd_r1_cbc
        self._cbc.argtypes = [
            ctypes.c_void_p,
            ctypes.c_void_p,
            ctypes.c_size_t,
            ctypes.c_uint64,
            ctypes.c_uint64,
            ctypes.c_void_p,
            ctypes.c_void_p,
            ctypes.c_void_p,
            ctypes.c_size_t,
        ]
        self._cbc.restype = ctypes.c_int
        self._extract = self._library.corelskd_r1_extract_key
        self._extract.argtypes = [
            ctypes.c_void_p,
            ctypes.c_void_p,
            ctypes.c_size_t,
            ctypes.c_uint64,
            ctypes.c_uint64,
            ctypes.c_void_p,
        ]
        self._extract.restype = ctypes.c_int

    @property
    def library(self) -> ctypes.CDLL:
        return self._library

    def block(
        self,
        ctx: bytes,
        state: bytes,
        rax: int,
        rcx: int,
        input_block: bytes,
    ) -> bytes:
        """Transform one 16-byte block using a captured CoreLSKD key context."""
        ctx = _bytes(ctx, "ctx", exact=CTX_SIZE)
        state = _bytes(state, "state", minimum=STATE_SIZE)
        rax = _index(rax, "rax")
        rcx = _index(rcx, "rcx")
        data = _bytes(input_block, "input_block", exact=16)
        context = ctypes.create_string_buffer(ctx, len(ctx))
        stack = ctypes.create_string_buffer(state, len(state))
        source = ctypes.create_string_buffer(data, len(data))
        output = ctypes.create_string_buffer(16)
        status = self._block(context, stack, len(state), rax, rcx, source, output)
        if status:
            raise CoreLSKDError("block", status)
        return output.raw

    def cbc(
        self,
        ctx: bytes,
        state: bytes,
        rax: int,
        rcx: int,
        iv: bytes | None,
        data: bytes,
    ) -> bytes:
        """Decrypt complete CBC blocks with a captured CoreLSKD key context.

        ``iv=None`` uses the chaining state encoded in the capture.  No padding
        is added or removed, matching the native entry point.  ``data`` must be
        a nonempty multiple of 16 bytes.
        """
        ctx = _bytes(ctx, "ctx", exact=CTX_SIZE)
        state = _bytes(state, "state", minimum=STATE_SIZE)
        rax = _index(rax, "rax")
        rcx = _index(rcx, "rcx")
        data = _bytes(data, "data")
        if not data or len(data) % 16:
            raise ValueError("data must be a nonempty multiple of 16 bytes")
        if iv is not None:
            iv = _bytes(iv, "iv", exact=16)
        context = ctypes.create_string_buffer(ctx, len(ctx))
        stack = ctypes.create_string_buffer(state, len(state))
        source = ctypes.create_string_buffer(data, len(data))
        output = ctypes.create_string_buffer(len(data))
        iv_buffer = ctypes.create_string_buffer(iv, 16) if iv is not None else None
        status = self._cbc(
            context,
            stack,
            len(state),
            rax,
            rcx,
            ctypes.cast(iv_buffer, ctypes.c_void_p) if iv_buffer is not None else None,
            source,
            output,
            len(data),
        )
        if status:
            raise CoreLSKDError("cbc", status)
        return output.raw

    def extract_key(self, ctx: bytes, state: bytes, rax: int, rcx: int) -> bytes:
        """Recover the ordinary 16-byte AES-128 content key.

        The native routine derives the key from the captured tables and the
        captured chaining state.  It writes a key only when all 16 positions
        agree, otherwise it fails closed.
        """
        ctx = _bytes(ctx, "ctx", exact=CTX_SIZE)
        state = _bytes(state, "state", minimum=STATE_SIZE)
        rax = _index(rax, "rax")
        rcx = _index(rcx, "rcx")
        context = ctypes.create_string_buffer(ctx, len(ctx))
        stack = ctypes.create_string_buffer(state, len(state))
        key = ctypes.create_string_buffer(16)
        status = self._extract(context, stack, len(state), rax, rcx, key)
        if status:
            raise CoreLSKDError("extract_key", status)
        return key.raw


_default: CoreLSKD | None = None


def _get_default() -> CoreLSKD:
    global _default
    if _default is None:
        _default = CoreLSKD()
    return _default


def block(ctx: bytes, state: bytes, rax: int, rcx: int, input_block: bytes) -> bytes:
    """Module-level convenience wrapper around :class:`CoreLSKD`."""
    return _get_default().block(ctx, state, rax, rcx, input_block)


def cbc(
    ctx: bytes,
    state: bytes,
    rax: int,
    rcx: int,
    iv: bytes | None,
    data: bytes,
) -> bytes:
    """Module-level convenience wrapper around :class:`CoreLSKD`."""
    return _get_default().cbc(ctx, state, rax, rcx, iv, data)


def extract_key(ctx: bytes, state: bytes, rax: int, rcx: int) -> bytes:
    """Module-level convenience wrapper around :class:`CoreLSKD`."""
    return _get_default().extract_key(ctx, state, rax, rcx)
