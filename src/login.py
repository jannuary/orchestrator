"""Two-phase account login for the HTTP service.

The first request runs one login attempt.  When Apple answers with a
two-factor challenge the attempt is parked (client, credentials and Apple's
response headers kept in memory) and the caller is told to repost with a code.
The repost submits the code on the parked attempt, so the session that Apple
created for the first attempt is the one that is completed.
"""

from __future__ import annotations

import os
import plistlib
import secrets
import shutil
import threading
import time
import uuid
from dataclasses import dataclass
from pathlib import Path
from typing import Callable, Optional

from .source_package import ensure_importable

ensure_importable()

from apple_music_source.auth import (
    AdiProvisioning,
    DeviceIdentity,
    HttpsTransport,
    OmnisetteCoreADI,
    ProvisionCoreADI,
    SourceLoginClient,
    SourceLoginOutcome,
    load_bag,
)

BAG_URL = "https://init.itunes.apple.com/bag.xml?ix=6&locale=en-US"
SOURCE_USER_AGENT = "Music/5.0.2 Android/10 model/Pixel 8 build/7663314 (dt:66)"
SOURCE_CLIENT_INFO = "<Pixel 8> <Android;10;7663314> <com.apple.Music/5.0.2>"
DEFAULT_STOREFRONT = "143441-1,32 t:music31"
REQUEST_TIMEOUT_SECONDS = 45.0
PARK_TIMEOUT_SECONDS = 300.0


class LoginError(RuntimeError):
    pass


def describe_rejection(outcome: SourceLoginOutcome) -> str:
    classification = outcome.login.classification
    description = "Apple rejected the credentials"
    customer_message = classification.customer_message.strip()
    if customer_message:
        description += f": {customer_message}"
    codes = [
        f"{name} {value}"
        for name, value in (
            ("failureType", classification.failure_type),
            ("errorCode", classification.error_code),
            ("responseType", classification.response_type),
            ("statusType", classification.status_type),
        )
        if value is not None
    ]
    if codes:
        description += f" ({', '.join(codes)})"
    try:
        parsed = getattr(outcome.login, 'parsed', None)
        fields = getattr(parsed, 'fields', None) if parsed is not None else None
        if isinstance(fields, dict):
            summary = ', '.join(f"{k}={fields[k]!r}" for k in sorted(fields)
                                if k not in ('password', 'appleId', 'spd', 'adsid', 'ServiceIdentifier'))
            description += f" [response: {summary[:600]}]"
    except Exception:
        pass
    return description


@dataclass(frozen=True)
class LoginResult:
    session_saved: bool
    verification_required: bool
    storefront: str


def load_source_bag(transport: HttpsTransport, bag_file: Optional[Path]):
    if bag_file is not None and bag_file.is_file():
        return load_bag(bag_file)
    response = transport.get(
        BAG_URL,
        {
            "User-Agent": SOURCE_USER_AGENT,
            "Content-Type": "application/x-apple-plist",
        },
        timeout=REQUEST_TIMEOUT_SECONDS,
    )
    if response.status != 200:
        raise LoginError(f"URL bag request failed with HTTP {response.status}")
    if bag_file is not None:
        bag_file.write_bytes(response.body)
    return plistlib.loads(response.body)


class LoginManager:
    def __init__(
        self,
        *,
        session_directory: Path,
        device_state: Path,
        storefront: str = DEFAULT_STOREFRONT,
        bag_file: Optional[Path] = None,
        on_session_saved: Optional[Callable[[Path], str]] = None,
        anisette_url: Optional[str] = None,
    ):
        self._session_directory = Path(session_directory)
        self._device_state = Path(device_state)
        self._storefront = storefront
        self._bag_file = None if bag_file is None else Path(bag_file)
        self._on_session_saved = on_session_saved
        self._anisette_url = anisette_url
        self._lock = threading.Lock()
        self._parked_client: Optional[SourceLoginClient] = None
        self._parked_at = 0.0
        self._local_backend: Optional[ProvisionCoreADI] = None

    def authenticate(
        self, username: str, password: str, code: Optional[str] = None
    ) -> LoginResult:
        with self._lock:
            self._expire_parked()
            if not code and self._parked_client is not None:
                return LoginResult(False, True, "")
            if code and self._parked_client is not None:
                return self._continue_login(username, password, code)
            self._close_parked()
            return self._begin_login(username, password, code)

    def close(self) -> None:
        with self._lock:
            self._close_parked()
            if self._local_backend is not None:
                self._local_backend.close()
                self._local_backend = None

    def _begin_login(
        self, username: str, password: str, code: Optional[str]
    ) -> LoginResult:
        transport = HttpsTransport()
        bag = load_source_bag(transport, self._bag_file)
        machine_data: Optional[object] = None
        if self._anisette_url is not None:
            machine_data = (
                OmnisetteCoreADI.discover() if self._anisette_url == 'discover'
                else OmnisetteCoreADI(self._anisette_url)
            )
        else:
            machine_data = self._ensure_local_provisioning(transport)
        client = SourceLoginClient(
            device_state=self._device_state,
            destination=self._staging_directory(),
            bag=bag,
            transport=transport,
            storefront=self._storefront,
            machine_data=machine_data,
        )
        return self._run(client, username, password, code)

    def _ensure_local_provisioning(self, transport: HttpsTransport):
        """Return a long-lived ProvisionCoreADI bound to this device-state dir.

        The backend is created once per LoginManager and reused for every
        login, matching the way anisette-v3-server pins a single ADI instance
        per process; libstoreservicescore keeps in-process state a fresh
        instance cannot pick back up from adi.pb alone.

        Missing device identifiers are generated once and persisted alongside
        adi.pb. The full SPIM->CPIM->PTM/TK exchange against Apple runs only
        when adi.pb does not yet exist; later logins reuse the stored state.
        """
        if self._local_backend is not None:
            return self._local_backend
        self._device_state.mkdir(parents=True, exist_ok=True)
        adi_pb = self._device_state / 'adi.pb'
        android_id_path = self._device_state / 'ANDROID_ID'
        local_uuid_path = self._device_state / 'LOCAL_USER_UUID'
        device_uuid_path = self._device_state / 'DEVICE_IDENTIFIER'
        if android_id_path.is_file():
            identifier = android_id_path.read_bytes().strip().decode('ascii')
        else:
            identifier = secrets.token_hex(8)
            android_id_path.write_bytes(identifier.encode('ascii'))
            os.chmod(android_id_path, 0o600)
        if local_uuid_path.is_file():
            local_uuid = local_uuid_path.read_text().strip()
        else:
            local_uuid = secrets.token_hex(32).upper()
            local_uuid_path.write_text(local_uuid)
            os.chmod(local_uuid_path, 0o600)
        if device_uuid_path.is_file():
            device_identifier = device_uuid_path.read_text().strip()
        else:
            device_identifier = str(uuid.uuid4()).upper()
            device_uuid_path.write_text(device_identifier)
            os.chmod(device_uuid_path, 0o600)
        backend = ProvisionCoreADI(
            provisioning_path=self._device_state,
            identifier=identifier,
        )
        if not adi_pb.is_file() or adi_pb.stat().st_size == 0:
            device = DeviceIdentity(
                device_identifier=device_identifier,
                local_user_uuid=local_uuid,
                client_info=SOURCE_CLIENT_INFO,
            )
            AdiProvisioning(
                backend=backend, transport=transport, device=device,
                user_agent=SOURCE_USER_AGENT,
            ).provision()
        self._local_backend = backend
        return backend

    def _continue_login(
        self, username: str, password: str, code: str
    ) -> LoginResult:
        client = self._take_parked()
        return self._run(client, username, password, code)

    def _run(
        self,
        client: SourceLoginClient,
        username: str,
        password: str,
        code: Optional[str],
    ) -> LoginResult:
        try:
            outcome = client.authenticate(
                username=username,
                password=password,
                verification_code=code,
                acquire_web_tokens=True,
            )
        except BaseException:
            client.close()
            raise
        return self._settle(client, outcome)

    def _settle(
        self, client: SourceLoginClient, outcome: SourceLoginOutcome
    ) -> LoginResult:
        if outcome.session_saved:
            destination = Path(client.destination)
            client.close()
            return LoginResult(True, False, self._publish(destination))
        if outcome.verification_required:
            self._park(client)
            return LoginResult(False, True, "")
        client.close()
        raise LoginError(describe_rejection(outcome))

    def _staging_directory(self) -> Path:
        parent = self._session_directory.parent
        parent.mkdir(parents=True, exist_ok=True)
        return parent / f".{self._session_directory.name}.login-{time.time_ns()}"

    def _publish(self, staging: Path) -> str:
        session_directory = self._session_directory
        if session_directory.exists():
            previous = session_directory.with_name(
                f".{session_directory.name}.previous-{time.time_ns()}"
            )
            session_directory.rename(previous)
        staging.rename(session_directory)
        self._remove_previous_sessions()
        if self._on_session_saved is None:
            return ""
        return self._on_session_saved(session_directory)

    def _remove_previous_sessions(self) -> None:
        pattern = f".{self._session_directory.name}.previous-*"
        for previous in self._session_directory.parent.glob(pattern):
            if previous.is_dir():
                shutil.rmtree(previous)

    def _park(self, client: SourceLoginClient) -> None:
        self._close_parked()
        self._parked_client = client
        self._parked_at = time.monotonic()

    def _take_parked(self) -> SourceLoginClient:
        client = self._parked_client
        self._parked_client = None
        return client

    def _expire_parked(self) -> None:
        if self._parked_client is None:
            return
        if time.monotonic() - self._parked_at < PARK_TIMEOUT_SECONDS:
            return
        self._close_parked()

    def _close_parked(self) -> None:
        client = self._parked_client
        self._parked_client = None
        if client is not None:
            client.close()
