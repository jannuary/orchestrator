"""Recovered, source-only portions of the Android Apple Music login protocol.

This module does not sign requests, provision a device, perform network login,
parse arbitrary protocol actions, or fabricate authentication tokens. Fields and
numeric response classifications follow the pinned libstoreservicescore.so;
see build/re/auth-reimplementation/login-findings.md for evidence boundaries.
"""
from dataclasses import dataclass, field
import plistlib
from typing import Mapping, Optional

METHOD = 'POST'
CONTENT_TYPE = 'application/x-apple-plist'
AUTHENTICATE_BAG_KEY = 'authenticateAccount'


def _string(value: str, label: str) -> str:
    if not isinstance(value, str) or '\0' in value:
        raise ValueError(label + ' must be a string without NUL')
    return value


def build_authenticate_body(*, username: str, password: str, guid: str = '', attempt: int = 0) -> bytes:
    """Return the final XML plist bytes to sign and transmit unchanged.

    Dict/value semantics are recovered. Python's XML whitespace/order need not
    equal CoreFoundation's; no byte-identical vendor XML claim is made. A signer
    must sign these exact bytes instead of reserializing the dictionary later.
    """
    username = _string(username, 'username')
    password = _string(password, 'password')
    guid = _string(guid, 'guid')
    if isinstance(attempt, bool) or not isinstance(attempt, int) or not -(1 << 31) <= attempt < (1 << 31):
        raise ValueError('attempt must be a signed 32-bit integer')
    payload = {'attempt': str(attempt)}
    if password:
        payload['password'] = password
    if username:
        payload['appleId'] = username
    # These are strings, including createSession. Do not turn them into booleans.
    payload.update(rmp='0', createSession='true', why='signIn')
    if guid:
        payload['guid'] = guid
    return plistlib.dumps(payload, fmt=plistlib.FMT_XML, sort_keys=False)


@dataclass(frozen=True)
class PreparedAuthenticate:
    """One serialized request body, immutable after construction and signing."""
    body: bytes = field(repr=False)
    content_type: str = CONTENT_TYPE
    method: str = METHOD

    @classmethod
    def create(cls, **credentials):
        return cls(build_authenticate_body(**credentials))


def append_verification_code(password: str, code: str) -> str:
    """Explicit caller-driven 2FA resubmission; never appends or retries itself."""
    _string(password, 'password')
    if not isinstance(code, str) or len(code) != 6 or not code.isascii() or not code.isdecimal():
        raise ValueError('verification code must contain six ASCII digits')
    return password + code


@dataclass(frozen=True)
class AuthenticateClassification:
    # Preserve numeric SDK classifications: their UI meaning is not all recovered.
    response_type: int
    status_type: int
    failure_type: Optional[int]
    error_code: Optional[int]
    customer_message: str = field(repr=False)


def _optional_integer(fields: Mapping, name: str) -> Optional[int]:
    """Read a numeric protocol field, treating unknown encodings as absent."""
    value = fields.get(name)
    if value is None:
        return None
    if isinstance(value, bool):
        return None
    if isinstance(value, int):
        return value
    if isinstance(value, str):
        text = value.lstrip('+-')
        if text and text.isascii() and text.isdecimal() and value.count('+') + value.count('-') <= 1:
            return int(value)
    return None


def classify_authenticate_response(fields: Optional[Mapping], *, has_created_account: bool = False) -> AuthenticateClassification:
    """Reproduce the recovered numeric classification for supported field types.

    has_created_account must come from a separately verified create-account
    protocol action, not the mere presence of a dsPersonId-looking field.
    This function does not assert that receiving status zero means login success.
    """
    response_type = 6 if has_created_account else 4
    if fields is None:
        return AuthenticateClassification(response_type, 0, None, None, '')
    if not isinstance(fields, Mapping):
        raise ValueError('protocol response must be a dictionary')
    failure = _optional_integer(fields, 'failureType')
    error = _optional_integer(fields, 'errorCode')
    if failure == -5000:
        response_type = 1 if error == -22947 else 0
    elif failure in (-128, 9008, 9009):
        response_type = {-128: 5, 9008: 2, 9009: 3}[failure]
    status = _optional_integer(fields, 'status')
    status_type = {-128: 5, 9008: 2, 9009: 3}.get(status, 6)
    message = fields.get('customerMessage', '')
    if not isinstance(message, str):
        raise ValueError('customerMessage must be a string')
    return AuthenticateClassification(response_type, status_type, failure, error, message)
