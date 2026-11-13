"""CoreADI backend that delegates to a local anisette-v3-server instance.

anisette-v3-server (Dadoum/anisette-v3-server) runs the real
libstoreservicescore.so through an in-process bionic ELF loader and exposes
anisette headers over HTTP. We decode its X-Apple-I-MD and X-Apple-I-MD-M
fields back into OTP bytes so the rest of this package keeps composing
headers the same way as with a native CoreADI implementation.

The simplest deployment uses the project's Docker image:

    podman run -d --rm --name anisette -p 6969:6969 \\
        docker.io/dadoum/anisette-v3-server

The server defaults to http://127.0.0.1:6969; point the Python side there with
AMS_OMNISETTE_URL or the constructor argument. GET / on the server returns the
anonymous anisette headers for the server's shared provisioning state, which
is what this backend consumes.
"""
from __future__ import annotations

import base64
import binascii
import json
import os
from typing import Mapping
from urllib import error as urllib_error
from urllib import request as urllib_request
from urllib.parse import urlsplit

from .adi_protocol import OTP, ProvisioningSession, SynchronizationResult


DEFAULT_OMNISETTE_URL = 'http://127.0.0.1:6969'
OMNISETTE_URL_ENV = 'AMS_OMNISETTE_URL'
GET_HEADERS_PATH = '/'
MIN_HEADER_BYTES = 1
MAX_HEADER_BYTES = 65536
MAX_RESPONSE_BYTES = 256 * 1024
HTTP_OK = 200
ANONYMOUS_ACCOUNT = -1


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


class OmnisetteCoreADI:
    """A CoreADI backend that pulls anisette headers from omnisette-server.

    Only the OTP/MID path is supported; provisioning is handled inside
    omnisette and never exposed through this backend.
    """

    def __init__(self, url: str | None = None, *,
                 timeout: float = 15.0,
                 opener: urllib_request.OpenerDirector | None = None):
        self._base_url = _validated_base_url(
            url or os.environ.get(OMNISETTE_URL_ENV, DEFAULT_OMNISETTE_URL)
        )
        if timeout <= 0:
            raise ValueError('timeout must be positive')
        self._timeout = float(timeout)
        self._opener = opener or urllib_request.build_opener()

    @property
    def base_url(self) -> str:
        return self._base_url

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
        request = urllib_request.Request(
            self._base_url + GET_HEADERS_PATH,
            headers={'Accept': 'application/json'},
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
                f'cannot reach omnisette at {self._base_url}: {error.reason}'
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
