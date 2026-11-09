"""Source CoreADI login client for Apple's fast native authentication route."""

from __future__ import annotations

from dataclasses import dataclass
from datetime import datetime, timezone
from pathlib import Path
import base64
from hashlib import sha1
from typing import Mapping

from .adi_protocol import AKD_USER_AGENT, DeviceIdentity, build_anisette_headers
from .coreadi_source import SourceCoreADI
from .http_transport import HttpsTransport
from .login_client import AdjustedRequest, LoginClient, LoginResult
from .login_protocol import AUTHENTICATE_BAG_KEY, PreparedAuthenticate
from .mescal_source import SourceMescal
from .sap import establish_signer
from .source_login import SourceLoginOutcome

_FAST_AUTH_URL = 'https://auth.itunes.apple.com/auth/v1/native/fast/'
_MAX_GUID_LENGTH = 256
_DEFAULT_STORE_FRONT = '143480-2,31'


@dataclass(frozen=True)
class FastLoginProfile:
    device: DeviceIdentity
    guid: str
    user_agent: str = AKD_USER_AGENT
    locale: str = 'en_US'
    timezone: str = 'UTC'
    store_front: str = _DEFAULT_STORE_FRONT

    def __post_init__(self) -> None:
        if not isinstance(self.device, DeviceIdentity):
            raise TypeError('fast login requires an explicit anisette device identity')
        if not isinstance(self.guid, str) or not 1 <= len(self.guid) <= _MAX_GUID_LENGTH:
            raise ValueError('fast login GUID must contain 1..256 characters')
        for name, value in (
            ('guid', self.guid),
            ('user agent', self.user_agent),
            ('locale', self.locale),
            ('timezone', self.timezone),
            ('store front', self.store_front),
        ):
            if not isinstance(value, str) or any(
                character in value for character in '\r\n\0'
            ):
                raise ValueError(f'{name} must not contain CR, LF, or NUL')
        if not self.user_agent or not self.locale or not self.timezone or not self.store_front:
            raise ValueError('user agent, locale, timezone, and store front are required')


class _FastAuthAdjuster:
    def __init__(
        self,
        machine_data: SourceCoreADI,
        profile: FastLoginProfile,
        signer: SourceMescal,
    ) -> None:
        self._machine_data = machine_data
        self._profile = profile
        self._signer = signer

    def adjust(self, request: PreparedAuthenticate) -> AdjustedRequest:
        proof = self._machine_data.otp(-1)
        headers = build_anisette_headers(proof, self._profile.device)
        encoded_mid = base64.b64encode(proof.mid).decode('ascii')
        encoded_otp = base64.b64encode(proof.otp).decode('ascii')
        signature = base64.b64encode(self._signer.sign(request.body)).decode('ascii')
        headers.update({
            'Accept': '*/*',
            'Content-Type': request.content_type,
            'User-Agent': self._profile.user_agent,
            'Accept-Language': self._profile.locale.replace('_', '-') + ',*;q=0.5',
            'X-Apple-AMD': encoded_mid,
            'X-Apple-AMD-M': encoded_otp,
            'X-Apple-ActionSignature': signature,
            'X-Apple-I-Client-Time': datetime.now(timezone.utc).isoformat(
                timespec='seconds'
            ).replace('+00:00', 'Z'),
            'X-Apple-I-TimeZone': self._profile.timezone,
            'X-Apple-I-Locale': self._profile.locale,
            'X-Apple-Locale': self._profile.locale,
            'X-Apple-Store-Front': self._profile.store_front,
            'Accept-Language': self._profile.locale.replace('_', '-') + ',*;q=0.5',
        })
        return AdjustedRequest(request.body, headers)


class SourceFastLoginClient:
    """Authenticate through the fast native route with source CoreADI data.

    The device directory must contain matching ``adi.pb`` and ``ANDROID_ID``
    files. An explicit GUID and anisette device identity are also required.
    """

    def __init__(
        self,
        *,
        device_state: Path,
        destination: Path,
        profile: FastLoginProfile,
        transport: HttpsTransport,
        sap_setup_bag: Mapping[str, object],
    ) -> None:
        self.device_state = Path(device_state)
        self.destination = Path(destination)
        if self.destination.exists():
            raise FileExistsError('login destination already exists')
        if not self.destination.parent.is_dir():
            raise FileNotFoundError('login destination parent directory does not exist')
        if not isinstance(profile, FastLoginProfile):
            raise TypeError('profile must be a FastLoginProfile')
        if not isinstance(transport, HttpsTransport):
            raise TypeError('source fast login requires the verified HttpsTransport')
        if not isinstance(sap_setup_bag, Mapping):
            raise TypeError('source fast login requires the SAP setup URL bag')
        self._transport = transport
        self._profile = profile
        self._signer: SourceMescal | None = None
        self._provision = (self.device_state / 'adi.pb').read_bytes()
        self._android_id = (self.device_state / 'ANDROID_ID').read_bytes().strip()
        if not 0 < len(self._provision) <= 1024 * 1024:
            raise ValueError('provisioning state must contain 1..1048576 bytes')
        if not 0 < len(self._android_id) <= 4096:
            raise ValueError('Android identifier must contain 1..4096 bytes')
        machine_data = SourceCoreADI(self._provision, self._android_id)
        mode_value = sap_setup_bag.get('sign-sap-version')
        mode = int(mode_value) if isinstance(mode_value, str) and mode_value.isdecimal() else mode_value
        if isinstance(mode, bool) or not isinstance(mode, int) or mode not in (200, 210):
            raise ValueError('SAP setup bag has an unsupported version')
        signer = SourceMescal(sha1(self._android_id).digest(), mode=mode)
        try:
            establish_signer(
                signer,
                sap_setup_bag,
                transport,
                user_agent=profile.user_agent,
            )
        except BaseException:
            signer.close()
            raise
        self._signer = signer
        bag: Mapping[str, str] = {AUTHENTICATE_BAG_KEY: _FAST_AUTH_URL}
        self._client = LoginClient(
            bag,
            transport=transport,
            adjuster=_FastAuthAdjuster(machine_data, profile, signer),
        )
        self._session_saved = False

    def authenticate(
        self,
        *,
        username: str,
        password: str,
        verification_code: str | None = None,
    ) -> SourceLoginOutcome:
        self._require_unsaved_session()
        if verification_code is None:
            result = self._client.authenticate(
                username=username,
                password=password,
                guid=self._profile.guid,
                attempt=1,
            )
        else:
            result = self._client.authenticate_with_verification_code(
                username=username,
                password=password,
                code=verification_code,
                guid=self._profile.guid,
                attempt=2,
            )
        return self._finish(result)

    def submit_verification_code(
        self,
        *,
        username: str,
        password: str,
        code: str,
    ) -> SourceLoginOutcome:
        self._require_unsaved_session()
        result = self._client.authenticate_with_verification_code(
            username=username,
            password=password,
            code=code,
            guid=self._profile.guid,
            attempt=2,
        )
        return self._finish(result)

    def _finish(self, result: LoginResult) -> SourceLoginOutcome:
        if not result.created_account:
            return SourceLoginOutcome(result, False)
        result.commit(
            self.destination,
            cookies=self._transport.cookies,
            guid=self._profile.guid,
            device_seed=self._android_id,
            provision=self._provision,
            android_id=self._android_id,
        )
        self._session_saved = True
        return SourceLoginOutcome(result, True)

    def _require_unsaved_session(self) -> None:
        if self._session_saved:
            raise RuntimeError('this login client already saved a session')

    def close(self) -> None:
        if self._signer is not None:
            self._signer.close()
            self._signer = None

    def __enter__(self) -> SourceFastLoginClient:
        return self

    def __exit__(self, *_args) -> None:
        self.close()

    def __del__(self) -> None:
        self.close()
