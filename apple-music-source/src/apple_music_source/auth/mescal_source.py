"""Source-reconstructed Mescal SAP and request-signature provider."""

from __future__ import annotations

import ctypes
from pathlib import Path


_LIBRARY = Path(__file__).resolve().parents[1] / "_native" / "libmescal_source.so"
_MAX_INPUT_SIZE = 0x80000
_MAX_OUTPUT_SIZE = 0x100000

_Entropy = ctypes.CFUNCTYPE(
    ctypes.c_int,
    ctypes.c_void_p,
    ctypes.POINTER(ctypes.c_ubyte),
    ctypes.c_size_t,
)
_Clock = ctypes.CFUNCTYPE(ctypes.c_uint64, ctypes.c_void_p)
_Time = ctypes.CFUNCTYPE(
    ctypes.c_int,
    ctypes.c_void_p,
    ctypes.POINTER(ctypes.c_int64),
    ctypes.POINTER(ctypes.c_int64),
)


class _Options(ctypes.Structure):
    _fields_ = [
        ("entropy", _Entropy),
        ("clock", _Clock),
        ("time", _Time),
        ("user", ctypes.c_void_p),
    ]


class _Result(ctypes.Structure):
    _fields_ = [
        ("status", ctypes.c_uint32),
        ("pc", ctypes.c_uint64),
        ("fault_address", ctypes.c_uint64),
        ("steps", ctypes.c_uint64),
        ("fault_size", ctypes.c_uint),
    ]


class SourceMescalError(RuntimeError):
    def __init__(self, operation: str, status: int, result: _Result):
        self.status = status
        self.result = result
        super().__init__(
            f"{operation} failed: source={status}, backend={result.status}, "
            f"pc=0x{result.pc:x}, fault=0x{result.fault_address:x}/{result.fault_size}"
        )


class SourceMescal:
    """Own a Mescal session for SAP setup and request signing."""

    def __init__(
        self,
        device_id: bytes,
        *,
        mode: int = 200,
        library: Path | None = None,
    ):
        if not isinstance(device_id, bytes) or not 1 <= len(device_id) <= 20:
            raise ValueError("device identifier must contain 1..20 bytes")
        if mode not in (200, 210):
            raise ValueError("unsupported SAP mode")
        self.mode = mode
        self._library = ctypes.CDLL(str((library or _LIBRARY).resolve()))
        self._handle = ctypes.c_void_p()
        self._options = _Options(_Entropy(), _Clock(), _Time(), None)
        create = self._library.wrapper_mescal_create
        create.argtypes = [
            ctypes.c_void_p,
            ctypes.c_size_t,
            ctypes.POINTER(_Options),
            ctypes.POINTER(ctypes.c_void_p),
            ctypes.POINTER(_Result),
        ]
        create.restype = ctypes.c_int
        exchange = self._library.wrapper_mescal_exchange
        exchange.argtypes = [
            ctypes.c_void_p,
            ctypes.c_uint,
            ctypes.c_void_p,
            ctypes.c_size_t,
            ctypes.c_void_p,
            ctypes.c_size_t,
            ctypes.POINTER(ctypes.c_size_t),
            ctypes.POINTER(ctypes.c_uint),
            ctypes.POINTER(_Result),
        ]
        exchange.restype = ctypes.c_int
        sign = self._library.wrapper_mescal_sign
        sign.argtypes = [
            ctypes.c_void_p,
            ctypes.c_void_p,
            ctypes.c_size_t,
            ctypes.c_void_p,
            ctypes.c_size_t,
            ctypes.POINTER(ctypes.c_size_t),
            ctypes.POINTER(_Result),
        ]
        sign.restype = ctypes.c_int
        self._library.wrapper_mescal_free.argtypes = [ctypes.c_void_p]
        self._library.wrapper_mescal_free.restype = None
        source = ctypes.create_string_buffer(device_id, len(device_id))
        result = _Result()
        status = create(
            source,
            len(device_id),
            ctypes.byref(self._options),
            ctypes.byref(self._handle),
            ctypes.byref(result),
        )
        if status:
            raise SourceMescalError("initialize", status, result)

    @staticmethod
    def guid_descriptor(
        android_id: bytes,
        mac_address: bytes,
        *,
        serial: bytes = b"",
        library: Path | None = None,
    ) -> bytes:
        if not isinstance(android_id, bytes) or not 0 < len(android_id) <= 4096:
            raise ValueError("Android identifier must contain 1..4096 bytes")
        if not isinstance(mac_address, bytes) or len(mac_address) != 6:
            raise ValueError("MAC address must contain six bytes")
        if not isinstance(serial, bytes) or len(serial) > 91 or b"\0" in serial:
            raise ValueError("serial must contain at most 91 non-NUL bytes")
        library_handle = ctypes.CDLL(str((library or _LIBRARY).resolve()))
        derive = library_handle.wrapper_mescal_guid_fields
        derive.argtypes = [
            ctypes.c_void_p,
            ctypes.c_size_t,
            ctypes.c_void_p,
            ctypes.c_size_t,
            ctypes.c_void_p,
            ctypes.c_void_p,
            ctypes.c_size_t,
            ctypes.POINTER(_Options),
            ctypes.POINTER(_Result),
        ]
        derive.restype = ctypes.c_int
        android = ctypes.create_string_buffer(android_id, len(android_id))
        serial_buffer = ctypes.create_string_buffer(serial)
        mac = ctypes.create_string_buffer(mac_address, len(mac_address))
        output = ctypes.create_string_buffer(56)
        result = _Result()
        status = derive(
            android,
            len(android_id),
            serial_buffer,
            len(serial),
            mac,
            output,
            len(output),
            None,
            ctypes.byref(result),
        )
        if status:
            raise SourceMescalError("GUID fields", status, result)
        return output.raw

    def exchange(self, data: bytes) -> tuple[int, bytes]:
        if not self._handle.value:
            raise ValueError("Mescal session is closed")
        if not isinstance(data, bytes) or not 0 < len(data) <= _MAX_INPUT_SIZE:
            raise ValueError("SAP input must contain 1..524288 bytes")
        source = ctypes.create_string_buffer(data, len(data))
        output = ctypes.create_string_buffer(_MAX_OUTPUT_SIZE)
        size = ctypes.c_size_t()
        phase = ctypes.c_uint()
        result = _Result()
        status = self._library.wrapper_mescal_exchange(
            self._handle,
            self.mode,
            source,
            len(data),
            output,
            len(output),
            ctypes.byref(size),
            ctypes.byref(phase),
            ctypes.byref(result),
        )
        if status:
            raise SourceMescalError("exchange", status, result)
        return phase.value, bytes(output[:size.value])

    def sign(self, body: bytes) -> bytes:
        if not self._handle.value:
            raise ValueError("Mescal session is closed")
        if not isinstance(body, bytes) or not 0 < len(body) <= _MAX_INPUT_SIZE:
            raise ValueError("signing input must contain 1..524288 bytes")
        source = ctypes.create_string_buffer(body, len(body))
        output = ctypes.create_string_buffer(_MAX_OUTPUT_SIZE)
        size = ctypes.c_size_t()
        result = _Result()
        status = self._library.wrapper_mescal_sign(
            self._handle,
            source,
            len(body),
            output,
            len(output),
            ctypes.byref(size),
            ctypes.byref(result),
        )
        if status:
            raise SourceMescalError("sign", status, result)
        return bytes(output[:size.value])

    def close(self) -> None:
        if self._handle.value:
            self._library.wrapper_mescal_free(self._handle)
            self._handle.value = None

    def __enter__(self) -> SourceMescal:
        return self

    def __exit__(self, *_args) -> None:
        self.close()

    def __del__(self) -> None:
        self.close()
