"""Source implementation of Apple's ADI provisioning protocol (anisette v3).

Recovered from the pinned StoreServices flow and cross-checked against two
independent public analyses:

- `ionescu007/Blackwood-4NT` documents the ADI command structure, the
  provisioning operations, and the GSA status codes 433/434.
- `Dadoum/Provision` and `SideStore/apple-private-apis` document the exact
  `libstoreservicescore.so` export set and the GSA provisioning exchange.

What this module implements in source:

- URL-bag lookup (`GsService2/lookup`) and the `midStartProvisioning` /
  `midFinishProvisioning` exchange;
- SPIM/CPIM/PTM/TK handling and session teardown;
- `X-Apple-I-MD*` header assembly from an OTP result.

What it does **not** implement: the FairPlay OTP/MID primitive itself
(`startProvisioning`'s SPIM->CPIM transform, PTM/TK verification and
`requestOTP`). That is the CoreADI/FairPlay DRM boundary. `CoreADI` below is an
explicit protocol; `UnimplementedCoreADI` raises instead of inventing output.
The public analyses above stop at the same boundary on purpose, and every
known open-source anisette stack still ships the proprietary library.

No password, OTP, MID, PTM, TK or CPIM value is logged or placed in a repr.
"""
from dataclasses import dataclass, field
import base64
import binascii
import plistlib
import time
from typing import Mapping, Optional, Protocol
from urllib.parse import urlsplit

LOOKUP_URL = 'https://gsa.apple.com/grandslam/GsService2/lookup'
CLIENT_INFO = ('<MacBookPro13,2> <macOS;13.1;22C65> '
               '<com.apple.AuthKit/1 (com.apple.dt.Xcode/3594.4.19)>')
AKD_USER_AGENT = 'akd/1.0 CFNetwork/808.1.4'
CONTENT_TYPE = 'application/x-apple-plist'
ROUTING_INFO = '17106176'
DS_ID_PRODUCTION = -2
MAX_PROVISIONING_SESSION = (1 << 32) - 1


def _b64decode(value, label):
    if not isinstance(value, str) or not value:
        raise ValueError(label + ' must be a base64 string')
    try:
        return base64.b64decode(value, validate=True)
    except (binascii.Error, ValueError) as error:
        raise ValueError(label + ' must be valid base64') from error


def _plist_response(body):
    if not isinstance(body, bytes):
        raise ValueError('response body must be bytes')
    try:
        value = plistlib.loads(body)
    except Exception as error:
        raise ValueError('provisioning response is not a plist') from error
    if not isinstance(value, Mapping):
        raise ValueError('provisioning response must be a plist dictionary')
    return value


def check_status(document, *, require_response=True):
    """Return `Response` from a GSA plist, raising on a nonzero `Status.ec`.

    A URL-bag lookup has `urls` at the top level and no `Response`; pass
    `require_response=False` for that document.
    """
    if not isinstance(document, Mapping):
        raise ValueError('provisioning document must be a dictionary')
    status = document.get('Status')
    if status is None and not require_response:
        return {}
    if not isinstance(status, Mapping):
        raise ValueError('provisioning response is missing Status')
    code = status.get('ec')
    if isinstance(code, str) and code.isdecimal():
        code = int(code)
    if isinstance(code, bool) or not isinstance(code, int):
        raise ValueError('Status.ec must be an integer')
    if code != 0:
        message = status.get('em', '')
        if not isinstance(message, str):
            message = ''
        raise ProvisioningError(code, message)
    response = document.get('Response')
    if not require_response:
        return response if isinstance(response, Mapping) else {}
    if not isinstance(response, Mapping):
        raise ValueError('provisioning response is missing Response')
    return response


def _routing_info(value):
    """Normalize `X-Apple-I-MD-RINFO`, which arrives as a plist string or int."""
    if isinstance(value, bool):
        raise ValueError('routing information must be an integer')
    if isinstance(value, int):
        value = str(value)
    if not isinstance(value, str) or not value.isascii() or not value.isdecimal():
        raise ValueError('routing information must be an ASCII decimal string')
    if int(value) > 0xFFFFFFFF:
        raise ValueError('routing information is out of range')
    return value


class ProvisioningError(RuntimeError):
    def __init__(self, code, message=''):
        super().__init__('provisioning failed with status %d' % code)
        self.code = code
        self.message = message


# ---------------------------------------------------------------------------
# Cryptographic boundary
# ---------------------------------------------------------------------------

@dataclass(frozen=True)
class OTP:
    otp: bytes = field(repr=False)
    mid: bytes = field(repr=False)

    def __post_init__(self) -> None:
        if not isinstance(self.otp, bytes) or not self.otp:
            raise ValueError('otp must be non-empty bytes')
        if not isinstance(self.mid, bytes) or not self.mid:
            raise ValueError('mid must be non-empty bytes')


@dataclass(frozen=True)
class ProvisioningSession:
    cpim: bytes = field(repr=False)
    session: int

    def __post_init__(self) -> None:
        if not isinstance(self.cpim, bytes) or not self.cpim:
            raise ValueError('cpim must be non-empty bytes')
        if isinstance(self.session, bool) or not isinstance(self.session, int):
            raise ValueError('session must be an integer')
        if self.session < 0:
            raise ValueError('session must not be negative')
        if self.session > MAX_PROVISIONING_SESSION:
            raise ValueError('session exceeds the CoreADI session range')


@dataclass(frozen=True)
class SynchronizationResult:
    synchronization_resume_metadata: bytes = field(repr=False)
    machine_identifier: bytes = field(repr=False)

    def __post_init__(self) -> None:
        if not isinstance(self.synchronization_resume_metadata, bytes):
            raise ValueError('synchronization_resume_metadata must be bytes')
        if not isinstance(self.machine_identifier, bytes):
            raise ValueError('machine_identifier must be bytes')


class CoreADI(Protocol):
    """The FairPlay operations StoreServices exposes; none are reconstructed."""

    def is_provisioned(self, ds_id: int) -> bool:
        ...

    def start_provisioning(self, ds_id: int, spim: bytes) -> ProvisioningSession:
        ...

    def end_provisioning(self, session: int, ptm: bytes, tk: bytes) -> None:
        ...

    def destroy_session(self, session: int) -> None:
        ...

    def request_otp(self, ds_id: int) -> OTP:
        ...

    def synchronize(self, ds_id: int, sim: bytes) -> SynchronizationResult:
        ...


class UnimplementedCoreADI:
    """Explicit boundary: the FairPlay OTP/MID primitive is unreconstructed."""

    _REASON = ('ADI machine data requires the FairPlay OTP/MID primitive '
               '(SPIM->CPIM, PTM/TK verification, requestOTP). It is not '
               'reconstructed; supply an explicit CoreADI implementation.')

    def is_provisioned(self, ds_id):
        raise NotImplementedError(self._REASON)

    def start_provisioning(self, ds_id, spim):
        raise NotImplementedError(self._REASON)

    def end_provisioning(self, session, ptm, tk):
        raise NotImplementedError(self._REASON)

    def destroy_session(self, session):
        raise NotImplementedError(self._REASON)

    def request_otp(self, ds_id):
        raise NotImplementedError(self._REASON)

    def synchronize(self, ds_id, sim):
        raise NotImplementedError(self._REASON)


class NotProvisioned(RuntimeError):
    """The backend reports no cached provisioning for this environment."""


# ---------------------------------------------------------------------------
# Transport
# ---------------------------------------------------------------------------

@dataclass(frozen=True)
class HttpResponse:
    status: int
    body: bytes = field(repr=False)

    def __post_init__(self):
        if isinstance(self.status, bool) or not isinstance(self.status, int):
            raise ValueError('HTTP status must be an integer')
        if not isinstance(self.body, bytes):
            raise ValueError('HTTP body must be bytes')


class Transport(Protocol):
    def get(self, url: str, headers: Mapping[str, str], *,
            timeout: float) -> HttpResponse:
        ...

    def post(self, url: str, body: bytes, headers: Mapping[str, str], *,
             timeout: float) -> HttpResponse:
        ...


# ---------------------------------------------------------------------------
# Device identity and header assembly
# ---------------------------------------------------------------------------

@dataclass(frozen=True)
class DeviceIdentity:
    device_identifier: str
    local_user_uuid: str
    serial_number: str = '0'
    client_info: str = CLIENT_INFO

    def __post_init__(self):
        for name in ('device_identifier', 'local_user_uuid', 'serial_number',
                     'client_info'):
            value = getattr(self, name)
            if not isinstance(value, str) or not value or '\0' in value:
                raise ValueError(name + ' must be a non-empty string')
            if '\r' in value or '\n' in value:
                raise ValueError(name + ' must not contain CR/LF')


def build_anisette_headers(otp: OTP, device: DeviceIdentity,
                           routing_info: str = ROUTING_INFO) -> dict:
    """Return the native anisette headers for one request.

    Header values are server/device secrets; the caller must keep them private.
    """
    if not isinstance(otp, OTP):
        raise ValueError('otp must be an OTP')
    if not isinstance(device, DeviceIdentity):
        raise ValueError('device must be a DeviceIdentity')
    if not isinstance(routing_info, str) or not routing_info.isascii() \
            or not routing_info.isdecimal():
        raise ValueError('routing_info must be an ASCII decimal string')
    return {
        'X-Apple-I-MD': base64.b64encode(otp.otp).decode('ascii'),
        'X-Apple-I-MD-M': base64.b64encode(otp.mid).decode('ascii'),
        'X-Apple-I-MD-RINFO': routing_info,
        'X-Apple-I-MD-LU': device.local_user_uuid,
        'X-Apple-I-SRL-NO': device.serial_number,
        'X-Mme-Client-Info': device.client_info,
        'X-Mme-Device-Id': device.device_identifier,
    }


# ---------------------------------------------------------------------------
# Provisioning orchestration
# ---------------------------------------------------------------------------

def _require_url(value, label):
    if not isinstance(value, str) or not value:
        raise ValueError(label + ' must be a URL')
    parsed = urlsplit(value)
    if parsed.scheme not in ('http', 'https') or not parsed.hostname:
        raise ValueError(label + ' must be an absolute http(s) URL')
    if parsed.username or parsed.password:
        raise ValueError(label + ' must not embed credentials')
    return value


def _empty_provisioning_body(values: Optional[Mapping] = None) -> bytes:
    request = dict(values or {})
    return plistlib.dumps({'Header': {}, 'Request': request},
                          fmt=plistlib.FMT_XML, sort_keys=False)


class AdiProvisioning:
    """The GSA provisioning exchange around an injectable CoreADI backend."""

    def __init__(self, backend: CoreADI, transport: Transport,
                 device: DeviceIdentity, *, ds_id: int = DS_ID_PRODUCTION,
                 timeout: float = 45.0, clock=time.time):
        if isinstance(ds_id, bool) or not isinstance(ds_id, int):
            raise ValueError('ds_id must be an integer')
        if timeout <= 0:
            raise ValueError('timeout must be positive')
        self._backend = backend
        self._transport = transport
        self._device = device
        self._ds_id = ds_id
        self._timeout = float(timeout)
        self._clock = clock
        self._urls = None
        self._routing_info = None

    # -- request plumbing ---------------------------------------------------

    def _headers(self, *, with_time=False):
        headers = {
            'User-Agent': AKD_USER_AGENT,
            'Content-Type': CONTENT_TYPE,
            'X-Mme-Client-Info': self._device.client_info,
            'X-Mme-Device-Id': self._device.device_identifier,
            'X-Apple-I-MD-LU': self._device.local_user_uuid,
            'X-Apple-I-SRL-NO': self._device.serial_number,
        }
        if with_time:
            now = time.gmtime(self._clock())
            headers['X-Apple-I-Client-Time'] = time.strftime(
                '%Y-%m-%dT%H:%M:%SZ', now)
        return headers

    def lookup(self) -> Mapping:
        response = self._transport.get(LOOKUP_URL, self._headers(),
                                       timeout=self._timeout)
        if response.status != 200:
            raise ProvisioningError(response.status, 'URL bag lookup failed')
        document = _plist_response(response.body)
        check_status(document, require_response=False)
        urls = document.get('urls')
        if not isinstance(urls, Mapping):
            raise ValueError('URL bag lookup is missing urls')
        result = {
            'start': _require_url(urls.get('midStartProvisioning'),
                                  'midStartProvisioning'),
            'finish': _require_url(urls.get('midFinishProvisioning'),
                                   'midFinishProvisioning'),
        }
        self._urls = result
        return result

    def provision(self) -> None:
        """Run lookup -> start -> finish -> end. Never leaves a live session."""
        self._require_provisioning_backend()
        urls = self._urls or self.lookup()
        start_document = self._post(urls['start'], _empty_provisioning_body())
        spim = _b64decode(check_status(start_document).get('spim'), 'spim')

        session = self._backend.start_provisioning(self._ds_id, spim)
        try:
            finish_document = self._post(
                urls['finish'],
                _empty_provisioning_body({'cpim': base64.b64encode(
                    session.cpim).decode('ascii')}))
            response = check_status(finish_document)
            ptm = _b64decode(response.get('ptm'), 'ptm')
            tk = _b64decode(response.get('tk'), 'tk')
            routing = response.get('X-Apple-I-MD-RINFO')
            if routing is not None:
                self._routing_info = _routing_info(routing)
            self._backend.end_provisioning(session.session, ptm, tk)
        except BaseException:
            self._backend.destroy_session(session.session)
            raise

    def _require_provisioning_backend(self) -> None:
        required_methods = ('start_provisioning', 'end_provisioning', 'destroy_session')
        if isinstance(self._backend, UnimplementedCoreADI) or any(
                not callable(getattr(self._backend, method, None))
                for method in required_methods):
            raise NotImplementedError(UnimplementedCoreADI._REASON)

    def _post(self, url, body):
        response = self._transport.post(url, body,
                                        self._headers(with_time=True),
                                        timeout=self._timeout)
        if response.status != 200:
            raise ProvisioningError(response.status, 'provisioning POST failed')
        return _plist_response(response.body)

    # -- machine data -------------------------------------------------------

    def headers(self) -> dict:
        """Return anisette headers for a provisioned backend."""
        if not self._backend.is_provisioned(self._ds_id):
            raise NotProvisioned('ADI backend is not provisioned')
        return build_anisette_headers(
            self._backend.request_otp(self._ds_id), self._device,
            routing_info=self._routing_info or ROUTING_INFO)

    def synchronize(self, sim: bytes) -> SynchronizationResult:
        """Resynchronise after GSA status 434. Caller supplies the new SIM."""
        if not isinstance(sim, bytes) or not sim:
            raise ValueError('sim must be non-empty bytes')
        return self._backend.synchronize(self._ds_id, sim)
