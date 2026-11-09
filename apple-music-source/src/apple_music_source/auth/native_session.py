"""Source-only native account header construction from an existing session.

This imports persisted server credentials; it does not log in, mint passwordToken,
or implement the FairPlay anisette primitive. No SDK is loaded. Keep returned
header maps private.
"""
from contextlib import contextmanager
from dataclasses import dataclass, field
from pathlib import Path
import http.cookiejar
import sqlite3
import time
from urllib.parse import urlsplit

APPLE_EPOCH = 978307200

@dataclass(frozen=True)
class NativeSession:
    dsid: int
    storefront: str
    account_id: str = field(repr=False)
    token: str = field(repr=False)
    database: Path = field(repr=False)

    @classmethod
    def load(cls, base_dir):
        database = Path(base_dir) / 'mpl_db'
        with _read_db(database / 'accounts.sqlitedb') as db:
            rows = db.execute('SELECT dsid, storeFront, id FROM account WHERE active != 0').fetchall()
        if len(rows) != 1:
            raise ValueError('exactly one active native account is required')
        dsid, storefront, account_id = rows[0]
        if not isinstance(dsid, int) or dsid <= 0 or not account_id:
            raise ValueError('invalid native account')
        with _read_db(database / 'kvs.sqlitedb') as db:
            row = db.execute('SELECT value FROM value WHERE key = ?', ('Account.XToken:' + account_id,)).fetchone()
        if not row or not row[0]:
            raise ValueError('native passwordToken unavailable; login is required')
        return cls(dsid, storefront or '', account_id, row[0], database)

    def cookie_jar(self):
        """Restore this account's scoped cookies without exposing a header map.

        The transport subsequently selects cookies for each HTTPS service URL.
        Native database expiry values use Apple's epoch; CookieJar uses Unix.
        """
        jar = http.cookiejar.CookieJar()
        with _read_db(self.database / 'cookies.sqlitedb') as db:
            rows = db.execute('SELECT domain, path, name, value, expire_time, secure, user FROM cookies').fetchall()
        for domain, path, name, value, expiry, secure, user in rows:
            if user not in (-1, 0, self.dsid):
                continue
            for text in (domain, path or '/', name, value):
                _safe(text)
            jar.set_cookie(http.cookiejar.Cookie(
                version=0, name=name, value=value, port=None, port_specified=False,
                domain=domain, domain_specified=domain.startswith('.'),
                domain_initial_dot=domain.startswith('.'), path=path or '/',
                path_specified=True, secure=bool(secure),
                expires=int(expiry + APPLE_EPOCH) if expiry is not None else None,
                discard=expiry is None, comment=None, comment_url=None, rest={}))
        return jar

    def headers(self, url, user_agent, *, now=None):
        parsed = urlsplit(url)
        host = (parsed.hostname or '').lower()
        if parsed.scheme != 'https' or host != 'play.itunes.apple.com':
            raise ValueError('native session headers are restricted to the catalog host over HTTPS')
        now = time.time() if now is None else now
        path = parsed.path or '/'
        cookies = []
        with _read_db(self.database / 'cookies.sqlitedb') as db:
            # A deterministic RFC cookie ordering; the SDK's unordered map order
            # is not significant to the HTTP cookie semantics.
            rows = db.execute('SELECT domain, path, name, value, expire_time, secure, user FROM cookies').fetchall()
        for domain, cookie_path, name, value, expiry, secure, user in rows:
            if user not in (-1, 0, self.dsid):
                continue
            domain = domain.lower()
            if domain.startswith('.'):
                suffix = domain[1:]
                if host != suffix and not host.endswith('.' + suffix):
                    continue
            elif host != domain:
                continue
            cookie_path = cookie_path or '/'
            if path != cookie_path and not (path.startswith(cookie_path) and (cookie_path.endswith('/') or path[len(cookie_path):].startswith('/'))):
                continue
            if expiry is not None and expiry > 0 and expiry + APPLE_EPOCH <= now:
                continue
            _safe(name); _safe(value)
            cookies.append((cookie_path, name, value))
        headers = {'x-dsid': str(self.dsid), 'x-token': self.token,
                   'user-agent': user_agent, 'accept-language': 'en-US'}
        if self.storefront:
            headers['x-apple-store-front'] = self.storefront
        if cookies:
            headers['cookie'] = '; '.join(name + '=' + value for path, name, value in sorted(cookies, key=lambda c: (-len(c[0]), c[1])))
        for value in headers.values():
            _safe(value)
        return headers

@contextmanager
def _read_db(path):
    # Read-only connections; SQLite retains responsibility for a consistent view
    # within each database. Use a quiescent snapshot for a multi-file session.
    connection = sqlite3.connect(path.resolve().as_uri() + '?mode=ro', uri=True)
    try:
        yield connection
    finally:
        connection.close()

def _safe(value):
    if not isinstance(value, str) or any(c in value for c in '\r\n\x00'):
        raise ValueError('invalid session header')
