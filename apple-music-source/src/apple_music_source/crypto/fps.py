from __future__ import annotations

import ctypes
import os
from pathlib import Path
from typing import Callable

__all__ = ["SourceSession", "SourceSessionError", "default_fps_library_path"]

LIBRARY_NAME = "libapple_music_fps_source.so"
OUTPUT_CAPACITY = 0x100000

Entropy = ctypes.CFUNCTYPE(ctypes.c_int, ctypes.c_void_p, ctypes.POINTER(ctypes.c_ubyte), ctypes.c_size_t)
Clock = ctypes.CFUNCTYPE(ctypes.c_uint64, ctypes.c_void_p)
Time = ctypes.CFUNCTYPE(ctypes.c_int, ctypes.c_void_p, ctypes.POINTER(ctypes.c_int64), ctypes.POINTER(ctypes.c_int64))


class Request(ctypes.Structure):
    _fields_ = [
        ("account", ctypes.c_uint64),
        ("certificate", ctypes.c_void_p),
        ("certificate_size", ctypes.c_size_t),
        ("content", ctypes.c_void_p),
        ("content_size", ctypes.c_size_t),
        ("device_seed", ctypes.c_void_p),
        ("device_seed_size", ctypes.c_size_t),
        ("entropy", Entropy),
        ("clock", Clock),
        ("time", Time),
        ("user", ctypes.c_void_p),
    ]


class Result(ctypes.Structure):
    _fields_ = [
        ("status", ctypes.c_uint32),
        ("pc", ctypes.c_uint64),
        ("fault_address", ctypes.c_uint64),
        ("source_steps", ctypes.c_uint64),
        ("clock_calls", ctypes.c_uint64),
        ("output_size", ctypes.c_size_t),
        ("fault_size", ctypes.c_uint),
    ]


class SourceSessionError(RuntimeError):
    def __init__(self, api_status: int, result: Result):
        self.api_status = api_status
        self.result = result
        super().__init__(
            f"source FPS session failed: api={api_status} core={result.status} "
            f"pc=0x{result.pc:x} fault=0x{result.fault_address:x}"
        )


def default_fps_library_path() -> Path:
    override = os.environ.get("APPLE_MUSIC_SOURCE_FPS_LIB")
    if override:
        return Path(override).expanduser()
    return Path(__file__).resolve().parents[1] / "_native" / LIBRARY_NAME


class SourceSession:
    def __init__(
        self,
        account: int,
        certificate: bytes,
        content: bytes,
        device_seed: bytes,
        *,
        library: str | os.PathLike[str] | None = None,
        entropy: Callable | None = None,
        clock: Callable | None = None,
        time: Callable | None = None,
        format_version: int,
    ) -> None:
        for name, value in (
            ("certificate", certificate),
            ("content", content),
            ("device_seed", device_seed),
        ):
            if not isinstance(value, (bytes, bytearray, memoryview)) or not value:
                raise ValueError(f"{name} must be nonempty bytes-like data")
        if isinstance(account, bool) or not isinstance(account, int) or not 0 <= account <= 0xFFFFFFFFFFFFFFFF:
            raise ValueError("account must be an unsigned 64-bit integer")
        if isinstance(format_version, bool) or not isinstance(format_version, int) or not 0 <= format_version <= 0xFFFFFFFF:
            raise ValueError("format_version must be an unsigned 32-bit integer")
        library_path = Path(library) if library is not None else default_fps_library_path()
        if not library_path.is_file():
            raise FileNotFoundError(f"source FPS library is unavailable at {library_path}")
        self._library = ctypes.CDLL(str(library_path))
        self._handle = ctypes.c_void_p()
        self._buffers = [
            ctypes.create_string_buffer(bytes(data), len(data))
            for data in (certificate, content, device_seed)
        ]
        self._callbacks = (
            Entropy(entropy) if entropy else Entropy(),
            Clock(clock) if clock else Clock(),
            Time(time) if time else Time(),
        )
        self._request = Request(
            account,
            ctypes.cast(self._buffers[0], ctypes.c_void_p), len(certificate),
            ctypes.cast(self._buffers[1], ctypes.c_void_p), len(content),
            ctypes.cast(self._buffers[2], ctypes.c_void_p), len(device_seed),
            *self._callbacks, None,
        )
        self._result = Result()
        create = self._library.wrapper_kg_spc_generate_fps_session
        create.argtypes = [ctypes.POINTER(Request), ctypes.c_uint32, ctypes.c_void_p, ctypes.c_size_t, ctypes.POINTER(Result), ctypes.POINTER(ctypes.c_void_p)]
        create.restype = ctypes.c_int
        self._library.wrapper_kg_spc_session_free.argtypes = [ctypes.c_void_p]
        self._library.wrapper_kg_spc_session_free.restype = None
        output = ctypes.create_string_buffer(OUTPUT_CAPACITY)
        status = create(
            ctypes.byref(self._request), format_version, output, len(output),
            ctypes.byref(self._result), ctypes.byref(self._handle),
        )
        if status:
            self.close()
            raise SourceSessionError(status, self._result)
        self.spc = bytes(output[:self._result.output_size])

    def _require_open(self) -> None:
        if not self._handle.value:
            raise ValueError("source session is closed")

    def _process(
        self,
        operation: str,
        ckc: bytes,
        output_capacity: int = OUTPUT_CAPACITY,
    ) -> bytes | int:
        self._require_open()
        if not isinstance(ckc, (bytes, bytearray, memoryview)) or not ckc or len(ckc) > 4096:
            raise ValueError("ckc must contain 1..4096 bytes")
        data = ctypes.create_string_buffer(bytes(ckc), len(ckc))
        result = Result()
        if operation == "context":
            output = ctypes.c_uint64()
            function = self._library.wrapper_kg_spc_session_ckc_context
            function.argtypes = [
                ctypes.c_void_p, ctypes.c_void_p, ctypes.c_size_t,
                ctypes.POINTER(ctypes.c_uint64), ctypes.POINTER(Result),
            ]
            function.restype = ctypes.c_int
            status = function(self._handle, data, len(ckc), ctypes.byref(output), ctypes.byref(result))
            if status:
                raise SourceSessionError(status, result)
            return output.value
        output = ctypes.create_string_buffer(output_capacity)
        function = self._library.wrapper_kg_spc_session_ckc_persistent
        function.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_size_t, ctypes.c_void_p, ctypes.c_size_t, ctypes.POINTER(Result)]
        function.restype = ctypes.c_int
        status = function(self._handle, data, len(ckc), output, len(output), ctypes.byref(result))
        if status:
            raise SourceSessionError(status, result)
        return bytes(output[:result.output_size])

    def exchange_descriptor(self) -> bytes:
        self._require_open()
        output = ctypes.create_string_buffer(16)
        function = self._library.wrapper_kg_spc_session_exchange
        function.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
        function.restype = ctypes.c_int
        if function(self._handle, output):
            raise ValueError("source exchange descriptor is unavailable")
        return output.raw

    def persistent_response(self, ckc: bytes) -> bytes:
        result = self._process("persistent", ckc)
        if not isinstance(result, bytes):
            raise RuntimeError("persistent CKC operation returned an invalid result")
        return result

    def context(self, ckc: bytes) -> int:
        result = self._process("context", ckc)
        if not isinstance(result, int):
            raise RuntimeError("context CKC operation returned an invalid result")
        return result

    def finalize_context(self, context: int) -> None:
        self._require_open()
        if isinstance(context, bool) or not isinstance(context, int) or not 0 <= context <= 0xFFFFFFFFFFFFFFFF:
            raise ValueError("context must be an unsigned 64-bit integer")
        function = self._library.wrapper_kg_spc_session_context_finalize
        function.argtypes = [ctypes.c_void_p, ctypes.c_uint64, ctypes.POINTER(Result)]
        function.restype = ctypes.c_int
        result = Result()
        status = function(self._handle, context, ctypes.byref(result))
        if status:
            raise SourceSessionError(status, result)

    def decrypt(self, context: int, data: bytes, mode: int = 5) -> bytes:
        self._require_open()
        if not isinstance(data, (bytes, bytearray, memoryview)) or not 0 < len(data) <= 4096:
            raise ValueError("data must contain 1..4096 bytes")
        if isinstance(mode, bool) or not isinstance(mode, int) or not 0 <= mode <= 0xFFFFFFFF:
            raise ValueError("mode must be an unsigned 32-bit integer")
        request = ctypes.create_string_buffer(bytes(data), len(data))
        output = ctypes.create_string_buffer(len(data))
        result = Result()
        function = self._library.wrapper_kg_spc_session_context_decrypt
        function.argtypes = [ctypes.c_void_p, ctypes.c_uint64, ctypes.c_uint32, ctypes.c_void_p, ctypes.c_size_t, ctypes.c_void_p, ctypes.c_size_t, ctypes.POINTER(Result)]
        function.restype = ctypes.c_int
        status = function(self._handle, context, mode, request, len(data), output, len(output), ctypes.byref(result))
        if status:
            raise SourceSessionError(status, result)
        return bytes(output[:result.output_size])

    def close(self) -> None:
        handle = getattr(self, "_handle", None)
        if handle is not None and handle.value:
            self._library.wrapper_kg_spc_session_free(handle)
            handle.value = None
            self.spc = b""

    def __enter__(self):
        return self

    def __exit__(self, *_: object) -> None:
        self.close()

    def __del__(self) -> None:
        self.close()
