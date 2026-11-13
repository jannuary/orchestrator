"""CoreADI backend that pulls anisette headers from an anisette v1 HTTP server.

Any `anisette-v3-server`-compatible host works, self-hosted or public. The
SideStore community maintains a shared pool at
`https://servers.sidestore.io/servers.json`; `OmnisetteCoreADI.discover()`
picks a reachable V1 entry from it so apple-music-source has no FairPlay/ADI
code of its own at runtime.

The server's `GET /` returns anonymous anisette headers (X-Apple-I-MD and
X-Apple-I-MD-M among them); this backend decodes the two base64 fields and
produces an OTP the rest of the package can compose login headers from.
"""
from __future__ import annotations

import base64
import binascii
import json
import os
from typing import Iterable, Mapping, Sequence
from urllib import error as urllib_error
from urllib import request as urllib_request
from urllib.parse import urlsplit

from .adi_protocol import OTP, ProvisioningSession, SynchronizationResult


SIDESTORE_DIRECTORY_URL = 'https://servers.sidestore.io/servers.json'
OMNISETTE_URL_ENV = 'AMS_OMNISETTE_URL'
GET_HEADERS_PATH = '/'
CLIENT_USER_AGENT = 'apple-music-source/0.1'
MIN_HEADER_BYTES = 1
MAX_HEADER_BYTES = 65536
MAX_RESPONSE_BYTES = 256 * 1024
MAX_DIRECTORY_BYTES = 128 * 1024
HTTP_OK = 200
ANONYMOUS_ACCOUNT = -1
V1_ANISETTE_KIND = 0
DEFAULT_DISCOVERY_TIMEOUT = 10.0


def _validated_base_url(url: str) -> str:
    if not isinstance(url, str) or not url:
        raise ValueError('omnisette URL must be a non-empty string')
    parsed = urlsplit(url)
    if parsed.scheme not in ('http', 'https') or not parsed.hostname:
        raise ValueError('omnisette URL must be an absolute http(s) URL')
    if parsed.username or parsed.password or parsed.fragment:
        raise ValueError('omnisette URL must not embed credentials or a fragment')
    return url.rstrip('/')


def _decoded(value: object, label: str) -> bytes:
    if not isinstance(value, str) or not value:
        raise ValueError(f'omnisette response is missing {label}')
    try:
        decoded = base64.b64decode(value, validate=True)
    except (binascii.Error, ValueError) as error:
        raise ValueError(f'omnisette {label} is not valid base64') from error
    if not MIN_HEADER_BYTES <= len(decoded) <= MAX_HEADER_BYTES:
        raise ValueError(f'omnisette {label} has an invalid length')
    return decoded


class OmnisetteUnavailable(RuntimeError):
    """The configured omnisette-server did not return a usable response."""


def fetch_sidestore_servers(*, timeout: float = DEFAULT_DISCOVERY_TIMEOUT,
                            directory_url: str = SIDESTORE_DIRECTORY_URL,
                            opener: urllib_request.OpenerDirector | None = None,
                            ) -> list[str]:
    """Return the V1 anisette URLs from SideStore's public directory."""
    opener = opener or urllib_request.build_opener()
    request = urllib_request.Request(
        directory_url,
        headers={'Accept': 'application/json', 'User-Agent': CLIENT_USER_AGENT},
        method='GET')
    try:
        with opener.open(request, timeout=timeout) as response:
            if response.status != HTTP_OK:
                raise OmnisetteUnavailable(
                    f'server directory returned HTTP {response.status}')
            body = response.read(MAX_DIRECTORY_BYTES + 1)
    except urllib_error.URLError as error:
        raise OmnisetteUnavailable(
            f'cannot reach {directory_url}: {error.reason}') from error
    if len(body) > MAX_DIRECTORY_BYTES:
        raise OmnisetteUnavailable('server directory response is too large')
    try:
        document = json.loads(body.decode('utf-8'))
    except (UnicodeDecodeError, json.JSONDecodeError) as error:
        raise OmnisetteUnavailable('server directory is not JSON') from error
    entries = document.get('servers') if isinstance(document, Mapping) else None
    if not isinstance(entries, Sequence):
        raise OmnisetteUnavailable('server directory is missing servers')
    urls: list[str] = []
    for entry in entries:
        if not isinstance(entry, Mapping):
            continue
        if entry.get('kind') != V1_ANISETTE_KIND:
            continue
        address = entry.get('address')
        if not isinstance(address, str):
            continue
        try:
            urls.append(_validated_base_url(address))
        except ValueError:
            continue
    if not urls:
        raise OmnisetteUnavailable('server directory lists no V1 servers')
    return urls


class OmnisetteCoreADI:
    """A CoreADI backend that pulls anisette headers from a V1 anisette server.

    Only the OTP/MID path is supported; provisioning is handled inside
    omnisette and never exposed through this backend.
    """

    def __init__(self, url: str | None = None, *,
                 fallback_urls: Iterable[str] = (),
                 timeout: float = 15.0,
                 opener: urllib_request.OpenerDirector | None = None):
        environment_url = os.environ.get(OMNISETTE_URL_ENV)
        selected = url or environment_url
        if timeout <= 0:
            raise ValueError('timeout must be positive')
        self._timeout = float(timeout)
        self._opener = opener or urllib_request.build_opener()
        if selected is None:
            candidates = list(fallback_urls)
            if not candidates:
                candidates = fetch_sidestore_servers(
                    timeout=self._timeout, opener=self._opener)
            selected = candidates[0]
            self._fallbacks = [_validated_base_url(u) for u in candidates[1:]]
        else:
            self._fallbacks = [_validated_base_url(u) for u in fallback_urls]
        self._base_url = _validated_base_url(selected)

    @classmethod
    def discover(cls, *, timeout: float = DEFAULT_DISCOVERY_TIMEOUT,
                 opener: urllib_request.OpenerDirector | None = None,
                 ) -> 'OmnisetteCoreADI':
        """Create a backend from the current SideStore server directory."""
        servers = fetch_sidestore_servers(timeout=timeout, opener=opener)
        return cls(servers[0], fallback_urls=servers[1:],
                   timeout=timeout, opener=opener)

    @property
    def base_url(self) -> str:
        return self._base_url

    @property
    def fallback_urls(self) -> tuple[str, ...]:
        return tuple(self._fallbacks)

    def is_provisioned(self, ds_id: int) -> bool:
        if isinstance(ds_id, bool) or not isinstance(ds_id, int):
            raise ValueError('ds_id must be an integer')
        return True

    def request_otp(self, ds_id: int) -> OTP:
        if ds_id != ANONYMOUS_ACCOUNT:
            raise NotImplementedError(
                'omnisette CoreADI supports the anonymous account only')
        return self.otp(account=ds_id)

    def otp(self, account: int = ANONYMOUS_ACCOUNT) -> OTP:
        if account != ANONYMOUS_ACCOUNT:
            raise NotImplementedError(
                'omnisette CoreADI supports the anonymous account only')
        payload = self._fetch_headers()
        return OTP(
            otp=_decoded(payload.get('X-Apple-I-MD'), 'X-Apple-I-MD'),
            mid=_decoded(payload.get('X-Apple-I-MD-M'), 'X-Apple-I-MD-M'),
        )

    def start_provisioning(self, ds_id: int, spim: bytes) -> ProvisioningSession:
        raise NotImplementedError(
            'omnisette drives provisioning internally; use the server API')

    def end_provisioning(self, session: int, ptm: bytes, tk: bytes) -> None:
        raise NotImplementedError(
            'omnisette drives provisioning internally; use the server API')

    def destroy_session(self, session: int) -> None:
        raise NotImplementedError(
            'omnisette drives provisioning internally; use the server API')

    def synchronize(self, ds_id: int, sim: bytes) -> SynchronizationResult:
        raise NotImplementedError('omnisette does not expose synchronization')

    def _fetch_headers(self) -> Mapping[str, object]:
        attempts = [self._base_url, *self._fallbacks]
        last_error: Exception | None = None
        for url in attempts:
            try:
                return self._fetch_once(url)
            except OmnisetteUnavailable as error:
                last_error = error
        raise last_error or OmnisetteUnavailable('no anisette server was usable')

    def _fetch_once(self, url: str) -> Mapping[str, object]:
        request = urllib_request.Request(
            url + GET_HEADERS_PATH,
            headers={'Accept': 'application/json', 'User-Agent': CLIENT_USER_AGENT},
            method='GET',
        )
        try:
            with self._opener.open(request, timeout=self._timeout) as response:
                if response.status != HTTP_OK:
                    raise OmnisetteUnavailable(
                        f'omnisette returned HTTP {response.status}')
                body = response.read(MAX_RESPONSE_BYTES + 1)
        except urllib_error.URLError as error:
            raise OmnisetteUnavailable(
                f'cannot reach omnisette at {url}: {error.reason}'
            ) from error
        if len(body) > MAX_RESPONSE_BYTES:
            raise OmnisetteUnavailable('omnisette response is too large')
        try:
            document = json.loads(body.decode('utf-8'))
        except (UnicodeDecodeError, json.JSONDecodeError) as error:
            raise OmnisetteUnavailable(
                'omnisette response is not JSON') from error
        if not isinstance(document, Mapping):
            raise OmnisetteUnavailable(
                'omnisette response is not a JSON object')
        return document
