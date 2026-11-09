"""Recovered cookie and ping actions in native authentication response plists.

Cookie formatting follows SetCookiesProtocolAction::_httpCookieHeader at ELF
0x1b8e30. Ping keys accept a URL string or URL array, as ProtocolParser::_setActions
does; the transport owns their bounded, best-effort execution. Secret cookie
headers and server URLs are excluded from repr and diagnostics.
"""
from dataclasses import dataclass, field
import re
from typing import Mapping

PING_KEYS = ('ping', 'pings', 'pingUrls', 'duAnonymousPings')
SUPPORTED_ACTIONS = frozenset(('cookies',) + PING_KEYS)
MAX_COOKIES = 512
MAX_PINGS = 32
_TOKEN = re.compile(r"[!#$%&'*+.^_`|~0-9A-Za-z-]+\Z", re.ASCII)


def cookie_header(name, properties):
    """Translate one native protocol cookie to its HTTP Set-Cookie equivalent."""
    if not isinstance(name, str) or not _TOKEN.fullmatch(name):
        raise ValueError('invalid protocol cookie name')
    if not isinstance(properties, Mapping):
        raise ValueError('protocol cookie attributes must be a dictionary')
    value = properties.get('value', '')
    value = value if isinstance(value, str) else ''
    if any(c in value for c in '\r\n\0;'):
        raise ValueError('invalid protocol cookie value')
    parts = [name + '=' + value]
    for key, value in properties.items():
        # The native helper filters CFString/CFString pairs before formatting.
        if not isinstance(key, str) or not isinstance(value, str) or key == 'value':
            continue
        if not _TOKEN.fullmatch(key) or any(c in value for c in '\r\n\0;'):
            raise ValueError('invalid protocol cookie attribute')
        if key.lower() == 'ishttponly':
            parts.append('HttpOnly')
        elif key.lower() == 'issecure':
            parts.append('secure')
        else:
            parts.append(key + '=' + value)
    return '; '.join(parts)


@dataclass(frozen=True)
class CookieAction:
    header: str = field(repr=False)
    domain: str = field(default='', repr=False)


@dataclass(frozen=True)
class ProtocolActions:
    handled: tuple[str, ...]
    cookies: tuple[CookieAction, ...] = field(repr=False)
    pings: tuple[str, ...] = field(repr=False)


@dataclass(frozen=True)
class ActionEffects:
    handled: tuple[str, ...]
    cookies_applied: int = 0
    pings_attempted: int = 0
    pings_failed: int = 0
    pings_skipped: int = 0


def parse_protocol_actions(fields):
    handled, cookies, pings = [], [], []
    if 'cookies' in fields:
        value = fields['cookies']
        if value is None or value == []:
            value = {}
        if not isinstance(value, Mapping) or len(value) > MAX_COOKIES:
            raise ValueError('unsupported protocol cookie collection')
        for name, properties in value.items():
            # SetCookiesProtocolAction ignores non-string/non-dictionary entries.
            if not isinstance(name, str) or not isinstance(properties, Mapping):
                continue
            header = cookie_header(name, properties)
            domain = next((v.strip() for k, v in properties.items()
                           if isinstance(k, str) and k.lower() == 'domain' and isinstance(v, str)), '')
            cookies.append(CookieAction(header, domain))
        handled.append('cookies')
    for key in PING_KEYS:
        if key not in fields:
            continue
        value = fields[key]
        if value is None:
            value = []
        if isinstance(value, str):
            value = [value]
        if not isinstance(value, (list, tuple)):
            raise ValueError('unsupported protocol ping collection')
        if len(value) > MAX_PINGS or len(pings) + len(value) > MAX_PINGS:
            raise ValueError('too many protocol pings')
        pings.extend(url for url in value if isinstance(url, str) and url)
        handled.append(key)
    return ProtocolActions(tuple(handled), tuple(cookies), tuple(pings))
