"""Bounded TLS transport for native login and provisioning.

Redirects are returned to the protocol state machine rather than followed.
Cookies stay in an in-memory jar until a verified login is committed. Bodies and
headers are never logged. No vendor library or optional Python package is used.
"""
import copy
import gzip
import http.client
import http.cookiejar
import io
import os
import ssl
import time
import urllib.request
from pathlib import Path
from urllib.parse import urlsplit

from .login_client import HttpResult
from .protocol_actions import ActionEffects, parse_protocol_actions

MAX_BODY = 4 * 1024 * 1024
APPLE_ROOT_CA_FILE = Path(__file__).resolve().parent / 'AppleIncRootCertificate.pem'
APPLE_ROOT_CA_ENV = 'APPLE_MUSIC_SOURCE_CA_BUNDLE'


def _default_apple_ssl_context():
    context = ssl.create_default_context()
    extra = os.environ.get(APPLE_ROOT_CA_ENV)
    if extra:
        context.load_verify_locations(cafile=extra)
    if APPLE_ROOT_CA_FILE.is_file():
        context.load_verify_locations(cafile=str(APPLE_ROOT_CA_FILE))
    return context


def apple_https_url(url):
    if not isinstance(url, str) or any(c in url for c in '\r\n\x00'):
        raise ValueError('invalid service URL')
    parsed = urlsplit(url)
    host = (parsed.hostname or '').lower()
    if parsed.scheme != 'https' or parsed.username or parsed.password or parsed.fragment or parsed.port not in (None, 443):
        raise ValueError('authentication requires an HTTPS service URL')
    if not any(host == domain or host.endswith('.' + domain) for domain in ('apple.com', 'mzstatic.com')):
        raise ValueError('unexpected authentication service host')
    return parsed


class _CookieResponse:
    def __init__(self, headers):
        self._headers = headers

    def info(self):
        return self._headers


class HttpsTransport:
    def __init__(self, *, cookie_jar=None, ssl_context=None, max_body=MAX_BODY):
        self.cookies = cookie_jar if cookie_jar is not None else http.cookiejar.CookieJar()
        self.context = ssl_context if ssl_context is not None else _default_apple_ssl_context()
        if self.context.verify_mode != ssl.CERT_REQUIRED or not self.context.check_hostname:
            raise ValueError('authentication requires certificate and hostname verification')
        if not isinstance(max_body, int) or isinstance(max_body, bool) or not 0 < max_body <= MAX_BODY:
            raise ValueError('invalid response size bound')
        self.max_body = max_body

    def get(self, url, headers=(), *, timeout=45):
        return self.request('GET', url, b'', dict(headers), timeout=timeout)

    def post(self, url, body, headers, *, timeout=45):
        return self.request('POST', url, body, dict(headers), timeout=timeout)

    def accept_headers(self, url, headers):
        apple_https_url(url)
        from email.message import Message
        message = Message()
        for name, value in headers:
            if not isinstance(name, str) or not isinstance(value, str) or any(c in name + value for c in '\r\n\x00'):
                raise ValueError('invalid protocol response header')
            message.add_header(name, value)
        request = urllib.request.Request(url)
        self.cookies.extract_cookies(_CookieResponse(message), request)

    def handle_login_actions(self, url, fields, *, user_agent=''):
        """Apply protocol cookies and perform optional pings before persistence.

        The native SDK queues pings independently of the login result. Here they
        are best-effort with a shared time budget; failed/unsafe destinations do
        not turn a valid account response into authentication failure. Cookies
        are validated as a batch, including explicit Apple sibling-domain scope.
        """
        apple_https_url(url)
        actions = parse_protocol_actions(fields)
        from email.message import Message
        staged = http.cookiejar.CookieJar(policy=self.cookies._policy)
        for cookie in self.cookies:
            staged.set_cookie(copy.copy(cookie))
        origins = []
        for cookie in actions.cookies:
            origin = url
            if cookie.domain:
                host = cookie.domain.lstrip('.')
                parsed = apple_https_url('https://' + host + '/')
                if parsed.hostname != host.lower() or parsed.path != '/' or parsed.query:
                    raise ValueError('invalid protocol cookie domain')
                origin = 'https://' + host + '/'
            origins.append(origin)
        # Validate every domain before changing any session cookies.
        for cookie, origin in zip(actions.cookies, origins):
            message = Message()
            message.add_header('Set-Cookie', cookie.header)
            staged.extract_cookies(_CookieResponse(message), urllib.request.Request(origin))
        if actions.cookies:
            self.cookies.clear()
            for cookie in staged:
                self.cookies.set_cookie(cookie)
        attempted = failed = skipped = 0
        deadline = time.monotonic() + 10
        for ping in actions.pings:
            try:
                apple_https_url(ping)
            except ValueError:
                skipped += 1
                continue
            remaining = deadline - time.monotonic()
            if remaining <= 0:
                skipped += 1
                continue
            attempted += 1
            try:
                # Do not forward the password body, x-token or crypto headers.
                headers = {'User-Agent': user_agent} if user_agent else {}
                response = self.get(ping, headers, timeout=min(3, remaining))
                failed += not 200 <= response.status < 300
            except (OSError, ValueError, http.client.HTTPException):
                failed += 1
        return ActionEffects(actions.handled, len(actions.cookies), attempted, failed, skipped)

    def request(self, method, url, body, headers, *, timeout=45):
        parsed = apple_https_url(url)
        if method not in ('GET', 'POST') or not isinstance(body, bytes):
            raise ValueError('unsupported authentication request')
        if len(body) > MAX_BODY or timeout <= 0:
            raise ValueError('invalid authentication request bounds')
        clean = {}
        for key, value in headers.items():
            if not isinstance(key, str) or not isinstance(value, str) or not key or any(c in key + value for c in '\r\n\x00'):
                raise ValueError('invalid authentication header')
            if key.lower() not in ('host', 'content-length', 'connection', 'transfer-encoding', 'proxy-authorization'):
                clean[key] = value
        # The jar selects domain/path/secure/expiry scope for this exact URL.
        request = urllib.request.Request(url, data=body if method == 'POST' else None, headers=clean, method=method)
        self.cookies.add_cookie_header(request)
        outgoing = dict(request.header_items())
        outgoing['Accept-Encoding'] = 'gzip'
        path = parsed.path or '/'
        if parsed.query:
            path += '?' + parsed.query
        connection = http.client.HTTPSConnection(parsed.hostname, timeout=timeout, context=self.context)
        try:
            connection.request(method, path, body=body if method == 'POST' else None, headers=outgoing)
            response = connection.getresponse()
            raw = response.read(self.max_body + 1)
            if len(raw) > self.max_body:
                raise ValueError('authentication response too large')
            encoding = response.getheader('Content-Encoding', '').strip().lower()
            if encoding == 'gzip':
                with gzip.GzipFile(fileobj=io.BytesIO(raw)) as compressed:
                    raw = compressed.read(self.max_body + 1)
                if len(raw) > self.max_body:
                    raise ValueError('decompressed authentication response too large')
            elif encoding not in ('', 'identity'):
                raise ValueError('unsupported authentication response encoding')
            self.cookies.extract_cookies(_CookieResponse(response.headers), request)
            return HttpResult(response.status, raw, tuple(response.getheaders()))
        finally:
            connection.close()
