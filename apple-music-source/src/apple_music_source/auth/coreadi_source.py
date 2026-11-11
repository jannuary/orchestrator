"""Source-reconstructed anonymous CoreADI machine data."""

from __future__ import annotations

import ctypes
import threading
from pathlib import Path

from .adi_protocol import OTP, ProvisioningSession


_LIBRARY = Path(__file__).resolve().parents[1] / "_native" / "libcoreadi_source.so"
_MAX_PROVISION_SIZE = 1024 * 1024
_MAX_ANDROID_ID_SIZE = 4096
_MAX_PROOF_SIZE = 4096
_MAX_SPIM_SIZE = 1024 * 1024
_MAX_PTM_SIZE = 1024 * 1024
_MAX_TK_SIZE = 1024 * 1024
_UINT64_MODULUS = 1 << 64
_UINT32_MAX = (1 << 32) - 1

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


class _ProvisioningFinishResult(ctypes.Structure):
    _fields_ = [
        ("status", ctypes.c_int32),
        ("pc", ctypes.c_uint64),
        ("fault_address", ctypes.c_uint64),
        ("steps", ctypes.c_uint64),
        ("fault_size", ctypes.c_uint),
        ("provision_size", ctypes.c_size_t),
    ]


def _bind_library(library_path: Path) -> ctypes.CDLL:
    library = ctypes.CDLL(str(library_path.resolve()))

    library.wrapper_adi_otp.argtypes = [
        ctypes.POINTER(_Request),
        ctypes.c_void_p, ctypes.c_size_t,
        ctypes.c_void_p, ctypes.c_size_t,
        ctypes.POINTER(_Result),
    ]
    library.wrapper_adi_otp.restype = ctypes.c_int

    library.wrapper_adi_provision_start.argtypes = [
        ctypes.POINTER(_Request), ctypes.c_uint64,
        ctypes.c_void_p, ctypes.c_size_t,
        ctypes.c_void_p, ctypes.c_size_t,
        ctypes.POINTER(_ProvisioningResult),
    ]
    library.wrapper_adi_provision_start.restype = ctypes.c_int

    library.wrapper_adi_provision_open.argtypes = [
        ctypes.POINTER(_Request), ctypes.c_uint64,
        ctypes.c_void_p, ctypes.c_size_t,
        ctypes.c_void_p, ctypes.c_size_t,
        ctypes.POINTER(_ProvisioningResult),
    ]
    library.wrapper_adi_provision_open.restype = ctypes.c_void_p

    library.wrapper_adi_provision_finish.argtypes = [
        ctypes.c_void_p,
        ctypes.c_void_p, ctypes.c_size_t,
        ctypes.c_void_p, ctypes.c_size_t,
        ctypes.c_void_p, ctypes.c_size_t,
        ctypes.POINTER(_ProvisioningFinishResult),
    ]
    library.wrapper_adi_provision_finish.restype = ctypes.c_int

    library.wrapper_adi_provision_abort.argtypes = [ctypes.c_void_p]
    library.wrapper_adi_provision_abort.restype = None

    return library


class SourceCoreADI:
    """Generate anonymous OTP and drive fresh CoreADI provisioning."""

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
        self._library_path = library or _LIBRARY
        self._library = _bind_library(self._library_path)
        self._open_handles_lock = threading.Lock()
        self._open_handles: dict[int, int] = {}

    @property
    def provisioning_state(self) -> bytes | None:
        return self._provision

    def is_provisioned(self, ds_id: int) -> bool:
        if isinstance(ds_id, bool) or not isinstance(ds_id, int):
            raise ValueError("ds_id must be an integer")
        return self._provision is not None

    def request_otp(self, ds_id: int) -> OTP:
        if ds_id not in (-1, _UINT64_MODULUS - 1):
            raise NotImplementedError("source CoreADI supports anonymous machine data only")
        return self.otp(account=ds_id)

    def otp(self, account: int = -1) -> OTP:
        if self._provision is None:
            raise NotImplementedError("OTP generation requires existing provisioning state")
        if account not in (-1, _UINT64_MODULUS - 1):
            raise NotImplementedError("source CoreADI supports anonymous machine data only")
        generate = self._library.wrapper_adi_otp
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
                mid, len(mid),
                otp, len(otp),
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

        android_id = ctypes.create_string_buffer(self._android_id, len(self._android_id))
        spim_buffer = ctypes.create_string_buffer(spim, len(spim))
        cpim = ctypes.create_string_buffer(_MAX_PROVISION_SIZE)
        request = _Request(
            None, 0,
            ctypes.cast(android_id, ctypes.c_void_p),
            len(self._android_id),
            _Entropy(), _Time(), None,
        )
        result = _ProvisioningResult()
        handle_address = self._library.wrapper_adi_provision_open(
            ctypes.byref(request),
            ds_id % _UINT64_MODULUS,
            ctypes.cast(spim_buffer, ctypes.c_void_p),
            len(spim),
            cpim, len(cpim),
            ctypes.byref(result),
        )
        try:
            if not handle_address:
                raise RuntimeError(
                    "source CoreADI provisioning open failed "
                    f"(backend={result.status}, pc=0x{result.pc:x})"
                )
            if not 0 < result.cpim_size <= len(cpim):
                self._library.wrapper_adi_provision_abort(handle_address)
                raise RuntimeError("source CoreADI returned invalid CPIM data")
            session_value = int(result.session)
            cpim_bytes = bytes(cpim[: result.cpim_size])
            with self._open_handles_lock:
                if session_value in self._open_handles:
                    self._library.wrapper_adi_provision_abort(handle_address)
                    raise RuntimeError("source CoreADI reused an open session identifier")
                self._open_handles[session_value] = handle_address
            return ProvisioningSession(cpim=cpim_bytes, session=session_value)
        finally:
            ctypes.memset(cpim, 0, len(cpim))
            ctypes.memset(spim_buffer, 0, len(spim_buffer))

    def end_provisioning(self, session: int, ptm: bytes, tk: bytes) -> None:
        if isinstance(session, bool) or not isinstance(session, int) or not 0 <= session <= _UINT32_MAX:
            raise ValueError("session must be a uint32")
        if not isinstance(ptm, bytes) or not 0 < len(ptm) <= _MAX_PTM_SIZE:
            raise ValueError("PTM must contain 1..1048576 bytes")
        if not isinstance(tk, bytes) or not 0 < len(tk) <= _MAX_TK_SIZE:
            raise ValueError("TK must contain 1..1048576 bytes")
        with self._open_handles_lock:
            handle_address = self._open_handles.pop(session, None)
        if handle_address is None:
            raise RuntimeError("session is not open for finish")
        ptm_buffer = ctypes.create_string_buffer(ptm, len(ptm))
        tk_buffer = ctypes.create_string_buffer(tk, len(tk))
        provision_out = ctypes.create_string_buffer(_MAX_PROVISION_SIZE)
        result = _ProvisioningFinishResult()
        try:
            status = self._library.wrapper_adi_provision_finish(
                handle_address,
                ctypes.cast(ptm_buffer, ctypes.c_void_p), len(ptm),
                ctypes.cast(tk_buffer, ctypes.c_void_p), len(tk),
                provision_out, len(provision_out),
                ctypes.byref(result),
            )
            if status:
                raise RuntimeError(
                    "source CoreADI provisioning finish failed "
                    f"(api={status}, backend={result.status}, pc=0x{result.pc:x})"
                )
            if not 0 < result.provision_size <= len(provision_out):
                raise RuntimeError("source CoreADI returned invalid adi.pb")
            self._provision = bytes(provision_out[: result.provision_size])
        finally:
            ctypes.memset(ptm_buffer, 0, len(ptm_buffer))
            ctypes.memset(tk_buffer, 0, len(tk_buffer))
            ctypes.memset(provision_out, 0, len(provision_out))

    def destroy_session(self, session: int) -> None:
        if isinstance(session, bool) or not isinstance(session, int) or not 0 <= session <= _UINT32_MAX:
            raise ValueError("session must be a uint32")
        with self._open_handles_lock:
            handle_address = self._open_handles.pop(session, None)
        if handle_address is None:
            return
        self._library.wrapper_adi_provision_abort(handle_address)

    def __del__(self) -> None:
        try:
            lock = self._open_handles_lock
            handles = self._open_handles
            library = self._library
        except AttributeError:
            return
        with lock:
            drained = list(handles.values())
            handles.clear()
        for handle_address in drained:
            library.wrapper_adi_provision_abort(handle_address)
