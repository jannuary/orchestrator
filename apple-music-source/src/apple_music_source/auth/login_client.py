"""Source-only orchestration for one fresh native login attempt.

The recoverable pieces are wired together here: URL-bag resolution, request body
construction, response parsing/classification and guarded session publication.
Cryptographic adjustment is supplied through an explicit `RequestAdjuster`;
the standalone CLI supplies the reconstructed CoreADI/Mescal providers. The
default raises rather than sending an unsigned request or loading an SDK.
Recovered cookie and ping actions are executed by a capable transport before
their unsupported markers are cleared and session publication is allowed.

The immutable request body temporarily contains credentials and is hidden from
repr. Credentials and server tokens are never logged or written to disk by this
module. Callers supply credentials and release results after use.
"""
from dataclasses import dataclass, field, replace
from pathlib import Path
import plistlib
import time
from typing import Mapping, Optional, Protocol
from urllib.parse import urlsplit

from .login_protocol import (AUTHENTICATE_BAG_KEY, AuthenticateClassification,
                            PreparedAuthenticate, append_verification_code,
                            classify_authenticate_response)
from .session_store import SessionAccount, SessionCookie, commit_session
from .login_actions import parse_login_actions
from .protocol_actions import SUPPORTED_ACTIONS


# ---------------------------------------------------------------------------
# URL bag
# ---------------------------------------------------------------------------

def load_bag(path) -> Mapping:
    """Load a URL bag plist from disk. Read-only; no network fallback."""
    with open(path, 'rb') as stream:
        bag = plistlib.load(stream)
    if not isinstance(bag, Mapping):
        raise ValueError('URL bag must be a plist dictionary')
    return bag


def resolve_bag_url(bag: Mapping, key: str = AUTHENTICATE_BAG_KEY) -> str:
    """Return one non-empty http(s) URL from the bag.

    A dotted path is accepted for nested bags; the pinned public bag stores
    `authenticateAccount` at the top level.
    """
    if not isinstance(bag, Mapping):
        raise ValueError('URL bag must be a dictionary')
    value = bag
    for part in key.split('.'):
        if not isinstance(value, Mapping) or part not in value:
            raise KeyError('URL bag key not found: ' + key)
        value = value[part]
    if not isinstance(value, str) or not value or '\0' in value:
        raise ValueError('URL bag value must be a non-empty string: ' + key)
    parsed = urlsplit(value)
    if parsed.scheme not in ('http', 'https') or not parsed.hostname:
        raise ValueError('URL bag value must be an absolute http(s) URL: ' + key)
    if parsed.username or parsed.password:
        raise ValueError('URL bag value must not embed credentials: ' + key)
    return value


# ---------------------------------------------------------------------------
# Transport and cryptographic boundary
# ---------------------------------------------------------------------------

@dataclass(frozen=True)
class HttpResult:
    status: int
    body: bytes = field(repr=False)
    headers: tuple = field(default=(), repr=False)

    def __post_init__(self):
        if isinstance(self.status, bool) or not isinstance(self.status, int):
            raise ValueError('HTTP status must be an integer')
        if not isinstance(self.body, bytes):
            raise ValueError('HTTP body must be bytes')
        for key, value in self.headers:
            if not isinstance(key, str) or not isinstance(value, str):
                raise ValueError('HTTP headers must be strings')


class Transport(Protocol):
    """Minimal injectable HTTP boundary so login can be tested offline."""

    def post(self, url: str, body: bytes, headers: Mapping[str, str], *,
             timeout: float) -> HttpResult:
        ...


@dataclass(frozen=True)
class AdjustedRequest:
    """Final bytes and headers after device/signing adjustment."""
    body: bytes = field(repr=False)
    headers: Mapping[str, str] = field(default_factory=dict, repr=False)

    def __post_init__(self):
        if not isinstance(self.body, bytes):
            raise ValueError('adjusted body must be bytes')
        for name, value in self.headers.items():
            if not isinstance(name, str) or not isinstance(value, str):
                raise ValueError('adjusted headers must be strings')
            if '\r' in name or '\n' in name or '\r' in value or '\n' in value:
                raise ValueError('adjusted headers must not contain CR/LF')


class RequestAdjuster(Protocol):
    """Adds CoreADI machine data and any Mescal signature to a prepared body."""

    def adjust(self, request: PreparedAuthenticate) -> AdjustedRequest:
        ...


class UnimplementedAdjuster:
    """Require callers to supply their device-backed crypto implementation."""

    def adjust(self, request: PreparedAuthenticate) -> AdjustedRequest:
        raise NotImplementedError(
            'native login needs CoreADI machine-data headers and Mescal request '
            'signatures. Supply an explicit '
            'RequestAdjuster; no unsigned fallback is provided.')


# ---------------------------------------------------------------------------
# Response parsing
# ---------------------------------------------------------------------------

@dataclass(frozen=True)
class ParsedResponse:
    fields: Optional[Mapping]
    has_created_account: bool = False
    actions: object = field(default=None, repr=False)


class ResponseParser(Protocol):
    def parse(self, body: bytes, headers=()) -> ParsedResponse:
        ...


class PlistResponseParser:
    """Parse the recovered native account and challenge actions from a plist."""

    def parse(self, body: bytes, headers=()) -> ParsedResponse:
        if not isinstance(body, bytes):
            raise ValueError('response body must be bytes')
        if not body:
            return ParsedResponse(None, False, parse_login_actions(None, headers))
        try:
            value = plistlib.loads(body)
        except Exception as error:
            raise ValueError('login response is not a valid plist') from error
        if not isinstance(value, Mapping):
            raise ValueError('login response must be a plist dictionary')
        actions = parse_login_actions(value, headers)
        return ParsedResponse(value, actions.has_created_account, actions)


# ---------------------------------------------------------------------------
# Login attempt
# ---------------------------------------------------------------------------

DEFAULT_TIMEOUT = 45.0
_MAX_AUTHENTICATE_ATTEMPTS = 3
_AUTHENTICATE_RETRY_DELAY_SECONDS = 0.25


def _is_retryable_authenticate_response(response: HttpResult) -> bool:
    status = response.status
    if status in (204, 404) or 500 <= status <= 599:
        return True
    if not 300 <= status <= 399:
        return False
    return not any(name.lower() == 'location' for name, _ in response.headers)


@dataclass(frozen=True)
class LoginResult:
    url: str = field(repr=False)
    request: PreparedAuthenticate = field(repr=False)
    response: HttpResult = field(repr=False)
    parsed: ParsedResponse = field(repr=False)
    classification: AuthenticateClassification
    action_effects: object = field(default=None, repr=False)

    @property
    def created_account(self) -> bool:
        actions = self.parsed.actions
        return (200 <= self.response.status < 300 and actions is not None
                and actions.can_persist_account)

    @property
    def account(self):
        return self.parsed.actions.account if self.parsed.actions is not None else None

    @property
    def requires_verification_code(self):
        return self.classification.response_type == 1

    def commit(self, destination, account: Optional[SessionAccount] = None,
               cookies=(), *, guid: str, device_seed: bytes, provision=None, android_id=None) -> None:
        """Publish a session only for a verified create-account response."""
        if not self.created_account:
            raise ValueError('login response did not create an account; refusing to commit')
        verified = self.account
        if account is not None:
            names = ('dsid', 'account_id', 'token', 'storefront', 'credit', 'first_name', 'last_name')
            if any(getattr(account, name) != getattr(verified, name) for name in names):
                raise ValueError('account does not match the verified login response')
        commit_session(destination, verified, cookies, guid=guid,
                       device_seed=device_seed, provision=provision, android_id=android_id)


class LoginClient:
    """One login endpoint, resolved from the bag, with injectable boundaries."""

    def __init__(self, bag: Mapping, *, transport: Transport,
                 adjuster: Optional[RequestAdjuster] = None,
                 parser: Optional[ResponseParser] = None,
                 timeout: float = DEFAULT_TIMEOUT):
        self.url = resolve_bag_url(bag)
        self._transport = transport
        self._adjuster = adjuster if adjuster is not None else UnimplementedAdjuster()
        self._parser = parser if parser is not None else PlistResponseParser()
        if timeout <= 0:
            raise ValueError('timeout must be positive')
        self._timeout = float(timeout)

    def authenticate(self, *, username: str, password: str,
                     guid: str = '', attempt: int = 0) -> LoginResult:
        """Send one attempt. The caller decides whether/when to retry."""
        prepared = PreparedAuthenticate.create(
            username=username, password=password, guid=guid, attempt=attempt)
        return self._send(prepared)

    def authenticate_with_verification_code(
            self, *, username: str, password: str, code: str,
            guid: str = '', attempt: int = 0) -> LoginResult:
        """Explicit 2FA resubmission; never auto-triggered by a challenge."""
        password = append_verification_code(password, code)
        return self.authenticate(username=username, password=password,
                                 guid=guid, attempt=attempt)

    def _send(self, prepared: PreparedAuthenticate) -> LoginResult:
        adjusted = self._adjuster.adjust(prepared)
        if adjusted.body != prepared.body:
            raise ValueError('request adjuster changed the serialized authentication body')
        response = None
        for attempt_index in range(_MAX_AUTHENTICATE_ATTEMPTS):
            response = self._transport.post(
                self.url,
                adjusted.body,
                dict(adjusted.headers),
                timeout=self._timeout,
            )
            if not isinstance(response, HttpResult):
                raise TypeError('transport must return HttpResult')
            if not _is_retryable_authenticate_response(response):
                break
            if attempt_index + 1 < _MAX_AUTHENTICATE_ATTEMPTS:
                time.sleep(_AUTHENTICATE_RETRY_DELAY_SECONDS)
        if response is None:
            raise RuntimeError('authentication request produced no response')
        try:
            parsed = self._parser.parse(response.body, response.headers)
        except ValueError:
            if 200 <= response.status < 300:
                raise
            parsed = ParsedResponse(None, False, parse_login_actions(None, response.headers))
        if parsed.actions is not None and parsed.actions.account is not None and not parsed.actions.account.storefront:
            # A successful response need not repeat X-Set-Apple-Store-Front.
            # Retain the storefront actually used for this login; otherwise
            # persistence silently drops it and subsequent FPS requests fail.
            storefront = next((value for key, value in adjusted.headers.items()
                               if key.lower() == 'x-apple-store-front'), '')
            if storefront:
                account = replace(parsed.actions.account, storefront=storefront)
                parsed = replace(parsed, actions=replace(parsed.actions, account=account))
        if parsed.actions is not None and hasattr(self._transport, 'accept_headers'):
            present = {key.lower() for key, value in response.headers}
            additional = tuple((key, value) for key, value in parsed.actions.effective_headers if key.lower() not in present)
            if additional:
                self._transport.accept_headers(self.url, additional)
        effects = None
        if parsed.actions is not None and parsed.fields is not None and hasattr(self._transport, 'handle_login_actions'):
            user_agent = next((value for key, value in adjusted.headers.items() if key.lower() == 'user-agent'), '')
            effects = self._transport.handle_login_actions(self.url, parsed.fields, user_agent=user_agent)
            handled = SUPPORTED_ACTIONS.intersection(effects.handled)
            actions = replace(parsed.actions, unhandled_actions=tuple(
                key for key in parsed.actions.unhandled_actions if key not in handled))
            parsed = replace(parsed, actions=actions)
        classification = classify_authenticate_response(
            parsed.fields, has_created_account=parsed.has_created_account)
        return LoginResult(self.url, prepared, response, parsed, classification, effects)
