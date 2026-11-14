"""Recovered native login response actions for the pinned StoreServices build.

The create-account action is inferred from accountInfo, not status zero or an
assumed actions array. This parser does not execute redirects, reset devices,
provision anisette, accept dialogs, or persist credentials. Callers must handle
those effects explicitly. Unsupported recognized action keys remain visible.

Evidence: build/re/auth-reimplementation/actions-parser-evidence.json,
actions-create-account.asm, actions-dialog.asm, and action-parser-findings.md.
"""
from dataclasses import dataclass, field
import re
import string
from typing import Mapping, Optional

from .login_protocol import AuthenticateClassification, classify_authenticate_response


@dataclass(frozen=True)
class CreatedAccount:
    dsid: int
    account_id: str = field(repr=False)
    token: str = field(repr=False)
    storefront: str = ''
    credit: str = field(default='', repr=False)
    first_name: str = field(default='', repr=False)
    last_name: str = field(default='', repr=False)

    @property
    def credentials_ready(self):
        # Apple's modern native-auth path carries the session in Set-Cookie
        # (amp, mz_at0-<dsid>, X-Dsid, ...) and omits xToken/passwordToken
        # entirely; the token slot stays empty for those sessions. A nonzero
        # DSID and non-empty Apple-ID account name are the stable signal.
        return (0 < self.dsid < (1 << 63) and bool(self.account_id)
                and not any(c in self.account_id + self.token for c in '\r\n\0'))


@dataclass(frozen=True)
class LoginActions:
    account: Optional[CreatedAccount]
    classification: AuthenticateClassification
    requires_verification_code: bool
    authenticate_requested: bool
    redirect_url: Optional[str] = field(default=None, repr=False)
    reset_requested: bool = False
    unhandled_actions: tuple[str, ...] = ()
    effective_headers: tuple[tuple[str, str], ...] = field(default=(), repr=False)

    @property
    def has_created_account(self):
        return self.account is not None

    @property
    def can_persist_account(self):
        # ``reset_requested`` reflects the SDK's action.kind == Reset /
        # SetUserAndReset directive, which only instructs the client to
        # discard previously-cached state before adopting the new user.
        # For a fresh login it is a no-op; it does not reject the account.
        return (self.account is not None and self.account.credentials_ready
                and self.classification.response_type == 6
                and not self.authenticate_requested
                and self.redirect_url is None and not self.unhandled_actions)


def _first_string(document, *keys):
    for key in keys:
        value = document.get(key)
        if isinstance(value, str) and value:
            return value
    return ''


def _integer(document, key):
    value = document.get(key)
    if value is None:
        return 0
    # CoreFoundation also coerces booleans/floats and strtoull prefixes. Those
    # malformed identity encodings are deliberately not admitted here.
    if isinstance(value, bool):
        raise ValueError('account identifier must use an integer or decimal string')
    if isinstance(value, str):
        if not re.fullmatch(r'[+-]?[0-9]+', value):
            raise ValueError('account identifier must use an integer or decimal string')
        value = int(value)
    if not isinstance(value, int) or not -(1 << 63) <= value < (1 << 64):
        raise ValueError('account identifier outside supported integer range')
    return value - (1 << 64) if value >= (1 << 63) else value


def _headers(fields, supplied):
    items = supplied.items() if isinstance(supplied, Mapping) else supplied
    result = []
    for name, value in items:
        if not isinstance(name, str) or not isinstance(value, str):
            raise ValueError('response headers must contain string pairs')
        if any(c in name + value for c in '\r\n\0'):
            raise ValueError('response header contains an invalid character')
        result.append((name, value))
    present = {name.lower() for name, _ in result}
    embedded = fields.get('headers')
    if isinstance(embedded, Mapping):
        for name, value in embedded.items():
            if isinstance(name, str) and isinstance(value, str) and name.lower() not in present:
                if any(c in name + value for c in '\r\n\0'):
                    raise ValueError('embedded response header contains an invalid character')
                result.append((name, value))
                present.add(name.lower())
    return tuple(result)


def _storefront(headers):
    for name, value in headers:
        if name.lower() == 'x-set-apple-store-front':
            # TrimNonAlphaNumericString removes non-alphanumeric ends, preserving
            # separators inside the storefront/version string.
            valid = string.ascii_letters + string.digits
            begin, end = 0, len(value)
            while begin < end and value[begin] not in valid:
                begin += 1
            while end > begin and value[end - 1] not in valid:
                end -= 1
            return value[begin:end]
    return ''


def _account(fields, headers):
    nested = None
    if 'accountInfo' in fields:
        info = fields['accountInfo']
    else:
        value = fields.get('set-current-user')
        nested = value if isinstance(value, Mapping) else None
        info = nested.get('accountInfo') if nested is not None else None
    if not isinstance(info, Mapping):
        return None
    dsid = _integer(info, 'dsPersonId') or _integer(fields, 'dsPersonId')
    if not dsid and nested is not None:
        dsid = _integer(nested, 'dsPersonId')
    if not dsid:
        download_queue = fields.get('download-queue-info')
        if isinstance(download_queue, Mapping):
            dsid = _integer(download_queue, 'dsid') or _integer(download_queue, 'dsPersonId')
    if not dsid:
        account_dict = fields.get('account')
        if isinstance(account_dict, Mapping):
            dsid = _integer(account_dict, 'dsid') or _integer(account_dict, 'dsPersonId')
    token = _first_string(fields, 'xToken', 'passwordToken')
    credit = _first_string(info, 'creditDisplay')
    if nested is not None:
        token = token or _first_string(nested, 'xToken', 'passwordToken')
        credit = credit or _first_string(nested, 'creditDisplay')
    account_id = _first_string(info, 'appleId', 'accountName')
    if not dsid or not account_id:
        return None
    address = info.get('address')
    address = address if isinstance(address, Mapping) else {}
    return CreatedAccount(dsid, account_id, token,
                          _storefront(headers), credit,
                          _first_string(address, 'firstName'), _first_string(address, 'lastName'))


def parse_login_actions(fields, headers=()):
    """Parse supported native response actions, without carrying out their effects.

    Header input is a mapping or ordered sequence of pairs. A nonzero DSID and
    nonempty account name gate the SDK account action; credentials_ready is a separate,
    stricter condition. HTTP success must also be verified by the caller.
    """
    if fields is None:
        return LoginActions(None, classify_authenticate_response(None), False, False)
    if not isinstance(fields, Mapping):
        raise ValueError('login protocol response must be a dictionary')
    effective_headers = _headers(fields, headers)
    account = _account(fields, effective_headers)
    classification = classify_authenticate_response(fields, has_created_account=account is not None)
    redirect = None
    reset = False
    unknown = []
    action = fields.get('action')
    if action is not None:
        if not isinstance(action, Mapping) or not isinstance(action.get('kind'), str):
            unknown.append('action')
        else:
            kind = action['kind'].lower()
            if kind == 'goto':
                target = action.get('url')
                if isinstance(target, str) and target and not any(c in target for c in '\r\n\0'):
                    redirect = target
                else:
                    unknown.append('action.Goto')
            elif kind in ('reset', 'setuserandreset'):
                reset = True
            elif kind == 'setuse':
                # SetUse asks the client to adopt the just-authenticated account
                # as the current iTunes user. We have no previous session to
                # switch away from, so committing the response is the only
                # side effect required.
                pass
            else:
                unknown.append('action.kind')
    dialog = fields.get('dialog')
    if isinstance(dialog, Mapping):
        # Unlike CFStringCompare(...,caseInsensitive) for action kinds, this
        # dialog branch compares exactly the 13 bytes "authorization".
        authenticate_requested = dialog.get('kind') == 'authorization'
        if not authenticate_requested:
            unknown.append('dialog')
    else:
        failure = classification.failure_type
        authenticate_requested = failure in (1001, 1003, 1004, 2034)
        if dialog is not None:
            unknown.append('dialog')
        if failure in (5002, 5105):
            unknown.append('failure-dialog')
    requires_code = classification.response_type == 1
    # Source credentialHandler obtains this exact flag from responseType==1.
    # It does not follow from a generic authorization dialog alone.
    for key in ('set-auth-token', 'invalidate-url-bags', 'DelayedGoto',
                'ping', 'pings', 'pingUrls', 'duAnonymousPings', 'cookies'):
        if key in fields:
            unknown.append(key)
    return LoginActions(account, classification, requires_code, authenticate_requested,
                        redirect, reset, tuple(unknown), effective_headers)
