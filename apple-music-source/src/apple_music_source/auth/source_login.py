"""Fresh account login using package-owned CoreADI and Mescal providers."""

from __future__ import annotations

from dataclasses import dataclass, field
from hashlib import sha1
from pathlib import Path
from typing import Mapping

from .coreadi_source import SourceCoreADI
from .device_identity import derive_android_guid_fields, format_android_guid, local_hardware_mac
from .http_transport import HttpsTransport
from .login_client import LoginClient, LoginResult
from .mescal_source import SourceMescal
from .native_adjuster import NativeRequestAdjuster
from .sap import establish_signer
from .token_client import TokenClient, WebTokens, verify_amp_tokens

_USER_AGENT = 'Music/5.0.2 Android/10 model/Pixel 8 build/7663314 (dt:66)'
_DEFAULT_STOREFRONT = '143480-2,31'


@dataclass(frozen=True)
class SourceLoginOutcome:
    login: LoginResult = field(repr=False)
    session_saved: bool
    web_tokens: WebTokens | None = field(default=None, repr=False)
    token_verification: Mapping[str, object] | None = field(default=None, repr=False)

    @property
    def verification_required(self) -> bool:
        return self.login.requires_verification_code and not self.session_saved


class SourceLoginClient:
    """Own the source authentication providers for one login and 2FA flow.

    The device directory must already contain matching ``adi.pb`` and
    ``ANDROID_ID`` files. The client creates only a new destination session.
    """

    def __init__(
        self,
        *,
        device_state: Path,
        destination: Path,
        bag: Mapping[str, object],
        transport: HttpsTransport,
        storefront: str = _DEFAULT_STOREFRONT,
        mac_address: bytes | None = None,
        sap_device_id: bytes | None = None,
        user_agent: str = _USER_AGENT,
    ):
        self.device_state = Path(device_state)
        self.destination = Path(destination)
        if self.destination.exists():
            raise FileExistsError('login destination already exists')
        if not self.destination.parent.is_dir():
            raise FileNotFoundError('login destination parent directory does not exist')
        if not isinstance(bag, Mapping):
            raise TypeError('URL bag must be a mapping')
        if not isinstance(transport, HttpsTransport):
            raise TypeError('source login requires the verified HttpsTransport')
        self._transport = transport
        self._provision = (self.device_state / 'adi.pb').read_bytes()
        self._android_id = (self.device_state / 'ANDROID_ID').read_bytes().strip()
        self._mac_address = mac_address if mac_address is not None else local_hardware_mac()
        self._sap_device_id = sap_device_id if sap_device_id is not None else sha1(self._android_id).digest()
        if not 0 < len(self._provision) <= 1024 * 1024:
            raise ValueError('provisioning state must contain 1..1048576 bytes')
        if not 0 < len(self._android_id) <= 4096:
            raise ValueError('Android identifier must contain 1..4096 bytes')
        if not isinstance(self._sap_device_id, bytes) or not 1 <= len(self._sap_device_id) <= 20:
            raise ValueError('SAP device identifier must contain 1..20 bytes')
        if not isinstance(storefront, str) or not storefront or any(c in storefront for c in '\r\n\0'):
            raise ValueError('a valid storefront is required')
        if not isinstance(user_agent, str) or not user_agent or any(c in user_agent for c in '\r\n\0'):
            raise ValueError('a valid user agent is required')
        mode_value = bag.get('sign-sap-version')
        mode = int(mode_value) if isinstance(mode_value, str) and mode_value.isdecimal() else mode_value
        if isinstance(mode, bool) or not isinstance(mode, int) or mode not in (200, 210):
            raise ValueError('URL bag has an unsupported SAP version')
        self._guid_fields = derive_android_guid_fields(self._android_id, self._mac_address)
        self.guid = format_android_guid(self._android_id, self._guid_fields)
        self.machine_data = SourceCoreADI(self._provision, self._android_id)
        self._signer = SourceMescal(self._sap_device_id, mode=mode)
        self._session_saved = False
        try:
            establish_signer(self._signer, bag, transport, user_agent=user_agent)
        except BaseException:
            self._signer.close()
            raise
        adjuster = NativeRequestAdjuster(
            machine_data=self.machine_data,
            signer=self._signer,
            user_agent=user_agent,
            storefront=storefront,
        )
        self._client = LoginClient(bag, transport=transport, adjuster=adjuster)
        self._bag = bag
        self._storefront = storefront
        self._user_agent = user_agent

    def authenticate(
        self,
        *,
        username: str,
        password: str,
        verification_code: str | None = None,
        acquire_web_tokens: bool = False,
        attempt: int = 0,
    ) -> SourceLoginOutcome:
        self._require_unsaved_session()
        result = self._client.authenticate_with_verification_code(
            username=username,
            password=password,
            code=verification_code,
            guid=self.guid,
            attempt=attempt,
        ) if verification_code is not None else self._client.authenticate(
            username=username,
            password=password,
            guid=self.guid,
            attempt=attempt,
        )
        return self._finish(result, acquire_web_tokens)

    def submit_verification_code(
        self,
        *,
        username: str,
        password: str,
        code: str,
        acquire_web_tokens: bool = False,
        attempt: int = 1,
    ) -> SourceLoginOutcome:
        self._require_unsaved_session()
        result = self._client.authenticate_with_verification_code(
            username=username,
            password=password,
            code=code,
            guid=self.guid,
            attempt=attempt,
        )
        return self._finish(result, acquire_web_tokens)

    def _finish(self, result: LoginResult, acquire_web_tokens: bool) -> SourceLoginOutcome:
        if not result.created_account:
            return SourceLoginOutcome(result, False)
        result.commit(
            self.destination,
            cookies=self._transport.cookies,
            guid=self.guid,
            device_seed=self._android_id,
            provision=self._provision,
            android_id=self._android_id,
        )
        self._session_saved = True
        if not acquire_web_tokens:
            return SourceLoginOutcome(result, True)
        tokens = TokenClient(
            session=result.account,
            guid=self.guid,
            bag=self._bag,
            transport=self._transport,
            machine_data=self.machine_data,
            signer=self._signer,
            storefront=self._storefront,
            user_agent=self._user_agent,
        ).acquire()
        verified_tokens, verification = verify_amp_tokens(
            self._transport,
            tokens,
            user_agent=self._user_agent,
        )
        verified_tokens.save(self.destination)
        return SourceLoginOutcome(result, True, verified_tokens, verification)

    def _require_unsaved_session(self) -> None:
        if self._session_saved:
            raise RuntimeError('this login client already saved a session')

    def close(self) -> None:
        self._signer.close()

    def __enter__(self) -> SourceLoginClient:
        return self

    def __exit__(self, *_args) -> None:
        self.close()

    def __del__(self) -> None:
        if hasattr(self, '_signer'):
            self._signer.close()
