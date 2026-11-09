"""Source-reconstructed anonymous CoreADI machine data."""

from __future__ import annotations

import ctypes
from pathlib import Path

from .adi_protocol import OTP, ProvisioningSession


_LIBRARY = Path(__file__).resolve().parents[1] / "_native" / "libcoreadi_source.so"
_MAX_PROVISION_SIZE = 1024 * 1024
_MAX_ANDROID_ID_SIZE = 4096
_MAX_PROOF_SIZE = 4096
_MAX_SPIM_SIZE = 1024 * 1024
_UINT64_MODULUS = 1 << 64

_Entropy = ctypes.CFUNCTYPE(
    ctypes.c_int,
    ctypes.c_void_p,
    ctypes.POINTER(ctypes.c_ubyte),
    ctypes.c_size_t,
)
_Time = ctypes.CFUNCTYPE(
    ctypes.c_int,
    ctypes.c_void_p,
    ctypes.POINTER(ctypes.c_int64),
    ctypes.POINTER(ctypes.c_int64),
)


class _Request(ctypes.Structure):
    _fields_ = [
        ("provision", ctypes.c_void_p),
        ("provision_size", ctypes.c_size_t),
        ("android_id", ctypes.c_void_p),
        ("android_id_size", ctypes.c_size_t),
        ("entropy", _Entropy),
        ("time", _Time),
        ("user", ctypes.c_void_p),
    ]


class _Result(ctypes.Structure):
    _fields_ = [
        ("status", ctypes.c_int32),
        ("pc", ctypes.c_uint64),
        ("fault_address", ctypes.c_uint64),
        ("steps", ctypes.c_uint64),
        ("fault_size", ctypes.c_uint),
        ("mid_size", ctypes.c_size_t),
        ("otp_size", ctypes.c_size_t),
    ]


class _ProvisioningResult(ctypes.Structure):
    _fields_ = [
        ("status", ctypes.c_int32),
        ("pc", ctypes.c_uint64),
        ("fault_address", ctypes.c_uint64),
        ("steps", ctypes.c_uint64),
        ("fault_size", ctypes.c_uint),
        ("session", ctypes.c_uint32),
        ("cpim_size", ctypes.c_size_t),
    ]


class SourceCoreADI:
    """Generate anonymous OTP or invoke the source-backed provisioning start."""

    def __init__(self, provision: bytes | None, android_id: bytes, *, library: Path | None = None):
        if provision is not None and (
            not isinstance(provision, bytes)
            or not 0 < len(provision) <= _MAX_PROVISION_SIZE
        ):
            raise ValueError("provisioning state must contain 1..1048576 bytes")
        if not isinstance(android_id, bytes) or not 0 < len(android_id) <= _MAX_ANDROID_ID_SIZE:
            raise ValueError("Android identifier must contain 1..4096 bytes")
        self._provision = provision
        self._android_id = android_id
        self._library = library or _LIBRARY

    def otp(self, account: int = -1) -> OTP:
        if self._provision is None:
            raise NotImplementedError("OTP generation requires existing provisioning state")
        if account not in (-1, (1 << 64) - 1):
            raise NotImplementedError("source CoreADI supports anonymous machine data only")
        library = ctypes.CDLL(str(self._library.resolve()))
        generate = library.wrapper_adi_otp
        generate.argtypes = [
            ctypes.POINTER(_Request),
            ctypes.c_void_p,
            ctypes.c_size_t,
            ctypes.c_void_p,
            ctypes.c_size_t,
            ctypes.POINTER(_Result),
        ]
        generate.restype = ctypes.c_int
        provision = ctypes.create_string_buffer(self._provision, len(self._provision))
        android_id = ctypes.create_string_buffer(self._android_id, len(self._android_id))
        mid = ctypes.create_string_buffer(_MAX_PROOF_SIZE)
        otp = ctypes.create_string_buffer(_MAX_PROOF_SIZE)
        request = _Request(
            ctypes.cast(provision, ctypes.c_void_p),
            len(self._provision),
            ctypes.cast(android_id, ctypes.c_void_p),
            len(self._android_id),
            _Entropy(),
            _Time(),
            None,
        )
        result = _Result()
        try:
            status = generate(
                ctypes.byref(request),
                mid,
                len(mid),
                otp,
                len(otp),
                ctypes.byref(result),
            )
            if status:
                raise RuntimeError(
                    "source CoreADI failed "
                    f"(api={status}, backend={result.status}, pc=0x{result.pc:x})"
                )
            if not 0 < result.mid_size <= len(mid) or not 0 < result.otp_size <= len(otp):
                raise RuntimeError("source CoreADI returned invalid machine data")
            return OTP(
                otp=bytes(otp[:result.otp_size]),
                mid=bytes(mid[:result.mid_size]),
            )
        finally:
            ctypes.memset(mid, 0, len(mid))
            ctypes.memset(otp, 0, len(otp))
            ctypes.memset(provision, 0, len(provision))

    def start_provisioning(
        self,
        ds_id: int,
        spim: bytes,
    ) -> ProvisioningSession:
        if isinstance(ds_id, bool) or not isinstance(ds_id, int):
            raise ValueError("ds_id must be an integer")
        if ds_id < -(1 << 63) or ds_id >= _UINT64_MODULUS:
            raise ValueError("ds_id is outside the CoreADI range")
        if not isinstance(spim, bytes) or not 0 < len(spim) <= _MAX_SPIM_SIZE:
            raise ValueError("SPIM must contain 1..1048576 bytes")

        library = ctypes.CDLL(str(self._library.resolve()))
        start = library.wrapper_adi_provision_start
        start.argtypes = [
            ctypes.POINTER(_Request),
            ctypes.c_uint64,
            ctypes.c_void_p,
            ctypes.c_size_t,
            ctypes.c_void_p,
            ctypes.c_size_t,
            ctypes.POINTER(_ProvisioningResult),
        ]
        start.restype = ctypes.c_int
        android_id = ctypes.create_string_buffer(self._android_id, len(self._android_id))
        spim_buffer = ctypes.create_string_buffer(spim, len(spim))
        cpim = ctypes.create_string_buffer(_MAX_PROVISION_SIZE)
        request = _Request(
            None,
            0,
            ctypes.cast(android_id, ctypes.c_void_p),
            len(self._android_id),
            _Entropy(),
            _Time(),
            None,
        )
        result = _ProvisioningResult()
        try:
            api_status = start(
                ctypes.byref(request),
                ds_id % _UINT64_MODULUS,
                ctypes.cast(spim_buffer, ctypes.c_void_p),
                len(spim),
                cpim,
                len(cpim),
                ctypes.byref(result),
            )
            if api_status:
                raise RuntimeError(
                    "source CoreADI provisioning start failed "
                    f"(api={api_status}, pc=0x{result.pc:x})"
                )
            if result.status:
                raise RuntimeError(
                    "source CoreADI rejected provisioning SPIM "
                    f"(backend={result.status}, pc=0x{result.pc:x})"
                )
            if not 0 < result.cpim_size <= len(cpim):
                raise RuntimeError("source CoreADI returned invalid CPIM data")
            return ProvisioningSession(
                cpim=bytes(cpim[:result.cpim_size]),
                session=result.session,
            )
        finally:
            ctypes.memset(cpim, 0, len(cpim))
            ctypes.memset(spim_buffer, 0, len(spim_buffer))

