"""In-process CoreADI backend over the vendored Dadoum/Provision loader.

Builds on the shared library `ams_provision` emitted by
`src/apple_music_source/_native/auth/provision_loader`. That shim loads Apple's
`libstoreservicescore.so` plus the transitive bionic/Apple dependencies from
the project's `vendor/` directory through Provision's in-process ELF loader,
and exposes a small C ABI the Python side binds via ctypes.

This is the first-party replacement for the old source-emulator backend: full
start/finish provisioning, OTP, and session destruction all run against the
real FairPlay code without any external daemon.
"""
from __future__ import annotations

import ctypes
import ctypes.util
import threading
from pathlib import Path

from .adi_protocol import OTP, ProvisioningSession


_DEFAULT_LIBRARY_NAME = 'libams_provision.so'
_DEFAULT_LIBRARY_PATH = (
    Path(__file__).resolve().parents[1]
    / '_native' / 'auth' / 'provision_loader' / 'build' / _DEFAULT_LIBRARY_NAME
)
_DEFAULT_VENDOR_PATH = Path(__file__).resolve().parents[2].parent / 'vendor'
_MAX_BUFFER = 1024 * 1024
_UINT32_MAX = (1 << 32) - 1
_UINT64_MODULUS = 1 << 64
_ANONYMOUS_ACCOUNT = -1
_PRODUCTION_DS_ID = -2


class _AmsOtpResult(ctypes.Structure):
    _fields_ = [
        ('otp_length', ctypes.c_size_t),
        ('mid_length', ctypes.c_size_t),
    ]


class _AmsStartResult(ctypes.Structure):
    _fields_ = [
        ('cpim_length', ctypes.c_size_t),
        ('session', ctypes.c_uint32),
    ]


def _bind_library(path: Path) -> ctypes.CDLL:
    library = ctypes.CDLL(str(path.resolve()))

    library.ams_provision_adi_create.argtypes = [ctypes.c_char_p]
    library.ams_provision_adi_create.restype = ctypes.c_void_p

    library.ams_provision_adi_destroy.argtypes = [ctypes.c_void_p]
    library.ams_provision_adi_destroy.restype = None

    library.ams_provision_adi_set_provisioning_path.argtypes = [
        ctypes.c_void_p, ctypes.c_char_p]
    library.ams_provision_adi_set_provisioning_path.restype = ctypes.c_int

    library.ams_provision_adi_set_identifier.argtypes = [
        ctypes.c_void_p, ctypes.c_char_p]
    library.ams_provision_adi_set_identifier.restype = ctypes.c_int

    library.ams_provision_adi_is_provisioned.argtypes = [
        ctypes.c_void_p, ctypes.c_int64, ctypes.POINTER(ctypes.c_int)]
    library.ams_provision_adi_is_provisioned.restype = ctypes.c_int

    library.ams_provision_adi_request_otp.argtypes = [
        ctypes.c_void_p, ctypes.c_int64,
        ctypes.c_char_p, ctypes.c_size_t,
        ctypes.c_char_p, ctypes.c_size_t,
        ctypes.POINTER(_AmsOtpResult),
    ]
    library.ams_provision_adi_request_otp.restype = ctypes.c_int

    library.ams_provision_adi_start_provisioning.argtypes = [
        ctypes.c_void_p, ctypes.c_int64,
        ctypes.c_char_p, ctypes.c_size_t,
        ctypes.c_char_p, ctypes.c_size_t,
        ctypes.POINTER(_AmsStartResult),
    ]
    library.ams_provision_adi_start_provisioning.restype = ctypes.c_int

    library.ams_provision_adi_end_provisioning.argtypes = [
        ctypes.c_void_p, ctypes.c_uint32,
        ctypes.c_char_p, ctypes.c_size_t,
        ctypes.c_char_p, ctypes.c_size_t,
    ]
    library.ams_provision_adi_end_provisioning.restype = ctypes.c_int

    library.ams_provision_adi_destroy_session.argtypes = [
        ctypes.c_void_p, ctypes.c_uint32]
    library.ams_provision_adi_destroy_session.restype = ctypes.c_int

    library.ams_provision_last_error.argtypes = []
    library.ams_provision_last_error.restype = ctypes.c_char_p
    return library


class ProvisionError(RuntimeError):
    """A call into the vendored Provision loader failed."""

    def __init__(self, code: int, detail: str):
        super().__init__(f'{detail} (code={code})')
        self.code = code


def _check(library: ctypes.CDLL, code: int, operation: str) -> None:
    if code == 0:
        return
    message = library.ams_provision_last_error()
    detail = message.decode('utf-8', errors='replace') if message else operation
    raise ProvisionError(code, f'{operation}: {detail}')


class ProvisionCoreADI:
    """CoreADI backend using the vendored Dadoum/Provision bionic ELF loader."""

    def __init__(self, vendor_path: Path | str | None = None,
                 provisioning_path: Path | str | None = None,
                 identifier: str | None = None,
                 *, library_path: Path | None = None):
        self._library = _bind_library(library_path or _DEFAULT_LIBRARY_PATH)
        resolved_vendor = Path(vendor_path or _DEFAULT_VENDOR_PATH).resolve()
        if not (resolved_vendor / 'libstoreservicescore.so').exists():
            raise FileNotFoundError(
                f'libstoreservicescore.so not found under {resolved_vendor}')
        self._lock = threading.Lock()
        handle = self._library.ams_provision_adi_create(
            str(resolved_vendor).encode('utf-8'))
        if not handle:
            detail = (self._library.ams_provision_last_error() or b'').decode(
                'utf-8', errors='replace') or 'unknown error'
            raise ProvisionError(-1, f'ADI create failed: {detail}')
        self._handle = ctypes.c_void_p(handle)
        if provisioning_path is not None:
            self.set_provisioning_path(provisioning_path)
        if identifier is not None:
            self.set_identifier(identifier)

    def close(self) -> None:
        with self._lock:
            if self._handle:
                self._library.ams_provision_adi_destroy(self._handle)
                self._handle = ctypes.c_void_p(0)

    def __del__(self) -> None:
        try:
            self.close()
        except Exception:
            pass

    def set_provisioning_path(self, path: Path | str) -> None:
        encoded = str(path).encode('utf-8')
        with self._lock:
            status = self._library.ams_provision_adi_set_provisioning_path(
                self._handle, encoded)
        _check(self._library, status, 'ADI set_provisioning_path')

    def set_identifier(self, identifier: str) -> None:
        if not isinstance(identifier, str) or len(identifier) != 16:
            raise ValueError('identifier must be a 16-character string')
        with self._lock:
            status = self._library.ams_provision_adi_set_identifier(
                self._handle, identifier.encode('ascii'))
        _check(self._library, status, 'ADI set_identifier')

    def is_provisioned(self, ds_id: int) -> bool:
        if isinstance(ds_id, bool) or not isinstance(ds_id, int):
            raise ValueError('ds_id must be an integer')
        out = ctypes.c_int(0)
        with self._lock:
            status = self._library.ams_provision_adi_is_provisioned(
                self._handle, ctypes.c_int64(ds_id), ctypes.byref(out))
        _check(self._library, status, 'ADI is_provisioned')
        return bool(out.value)

    def request_otp(self, ds_id: int) -> OTP:
        return self.otp(account=ds_id)

    def otp(self, account: int = _ANONYMOUS_ACCOUNT) -> OTP:
        if isinstance(account, bool) or not isinstance(account, int):
            raise ValueError('account must be an integer')
        # Apple provisions anonymous machine data under the production
        # ds_id; callers that ask for the legacy UINT64_MAX alias get the
        # same OTP they would pick up through the production channel.
        effective_account = _PRODUCTION_DS_ID if account == _ANONYMOUS_ACCOUNT else account
        otp_buffer = ctypes.create_string_buffer(_MAX_BUFFER)
        mid_buffer = ctypes.create_string_buffer(_MAX_BUFFER)
        result = _AmsOtpResult()
        with self._lock:
            status = self._library.ams_provision_adi_request_otp(
                self._handle, ctypes.c_int64(effective_account),
                otp_buffer, _MAX_BUFFER,
                mid_buffer, _MAX_BUFFER,
                ctypes.byref(result))
        _check(self._library, status, 'ADI request_otp')
        return OTP(
            otp=bytes(otp_buffer[:result.otp_length]),
            mid=bytes(mid_buffer[:result.mid_length]),
        )

    def start_provisioning(self, ds_id: int, spim: bytes) -> ProvisioningSession:
        if isinstance(ds_id, bool) or not isinstance(ds_id, int):
            raise ValueError('ds_id must be an integer')
        if not isinstance(spim, bytes) or not 0 < len(spim) <= _MAX_BUFFER:
            raise ValueError('SPIM must be non-empty bytes below the buffer cap')
        cpim_buffer = ctypes.create_string_buffer(_MAX_BUFFER)
        result = _AmsStartResult()
        with self._lock:
            status = self._library.ams_provision_adi_start_provisioning(
                self._handle, ctypes.c_int64(ds_id),
                spim, len(spim),
                cpim_buffer, _MAX_BUFFER,
                ctypes.byref(result))
        _check(self._library, status, 'ADI start_provisioning')
        return ProvisioningSession(
            cpim=bytes(cpim_buffer[:result.cpim_length]),
            session=int(result.session),
        )

    def end_provisioning(self, session: int, ptm: bytes, tk: bytes) -> None:
        if isinstance(session, bool) or not isinstance(session, int) or not 0 <= session <= _UINT32_MAX:
            raise ValueError('session must be a uint32')
        if not isinstance(ptm, bytes) or not 0 < len(ptm) <= _MAX_BUFFER:
            raise ValueError('PTM must be non-empty bytes below the buffer cap')
        if not isinstance(tk, bytes) or not 0 < len(tk) <= _MAX_BUFFER:
            raise ValueError('TK must be non-empty bytes below the buffer cap')
        with self._lock:
            status = self._library.ams_provision_adi_end_provisioning(
                self._handle, ctypes.c_uint32(session),
                ptm, len(ptm), tk, len(tk))
        _check(self._library, status, 'ADI end_provisioning')

    def destroy_session(self, session: int) -> None:
        if isinstance(session, bool) or not isinstance(session, int) or not 0 <= session <= _UINT32_MAX:
            raise ValueError('session must be a uint32')
        with self._lock:
            status = self._library.ams_provision_adi_destroy_session(
                self._handle, ctypes.c_uint32(session))
        _check(self._library, status, 'ADI destroy_session')
