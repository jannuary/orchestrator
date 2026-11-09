"""Commit one verified login session to a new private native-format store.

No password or verification code is accepted by this API. Token and cookie
values are server-issued secrets. A failed/partial login must never call commit.
"""
import dataclasses
import json
import os
from pathlib import Path
import shutil
import sqlite3
import tempfile
from typing import Optional

from .native_session import APPLE_EPOCH


@dataclasses.dataclass(frozen=True)
class SessionAccount:
    """Server-issued account fields from a verified create-account response."""
    dsid: int
    account_id: str = dataclasses.field(repr=False)
    token: str = dataclasses.field(repr=False)
    storefront: str = ''
    credit: str = ''
    first_name: str = ''
    last_name: str = ''


@dataclasses.dataclass(frozen=True)
class SessionCookie:
    """One server-issued cookie to persist for the native session."""
    domain: str
    name: str
    value: str = dataclasses.field(repr=False)
    path: str = '/'
    secure: bool = True
    domain_specified: bool = False
    discard: bool = False
    expires: Optional[float] = None
    version: int = 1


def _sqlite(path):
    fd = os.open(path, os.O_WRONLY | os.O_CREAT | os.O_EXCL, 0o600)
    os.close(fd)
    return sqlite3.connect(path)


def commit_session(destination, account, cookies, *, guid, device_seed, provision=None, android_id=None):
    destination = Path(destination).absolute()
    if destination.exists():
        raise FileExistsError('session destination already exists')
    if not 0 < account.dsid < (1 << 63) or not account.account_id or not account.token:
        raise ValueError('verified account identifier, DSID and token are required')
    if not isinstance(guid, str) or not guid or not isinstance(device_seed, bytes) or not device_seed:
        raise ValueError('matching device identity is required')
    device_files = {}
    if provision is not None or android_id is not None:
        if not isinstance(provision, bytes) or not provision or not isinstance(android_id, bytes) or not android_id:
            raise ValueError('matching provisioning state and Android identifier are required')
        device_files = {'adi.pb': provision, 'ANDROID_ID': android_id}
    staging = Path(tempfile.mkdtemp(prefix='.login-', dir=destination.parent))
    try:
        database = staging / 'mpl_db'
        database.mkdir(mode=0o700)
        db = _sqlite(database / 'accounts.sqlitedb')
        try:
            with db:
                db.execute('CREATE TABLE account(active INTEGER DEFAULT 0, creditString TEXT, dsid INTEGER PRIMARY KEY, firstName TEXT, id TEXT, im_can_subscribe INTEGER DEFAULT -1, im_subscribed INTEGER DEFAULT -1, im_supported INTEGER DEFAULT -1, lastName TEXT, storeFront TEXT, accountFlags TEXT)')
                db.execute('INSERT INTO account(active,creditString,dsid,firstName,id,lastName,storeFront) VALUES(1,?,?,?,?,?,?)',
                    (account.credit, account.dsid, account.first_name, account.account_id, account.last_name, account.storefront))
        finally:
            db.close()
        db = _sqlite(database / 'kvs.sqlitedb')
        try:
            with db:
                db.execute('CREATE TABLE value(key TEXT PRIMARY KEY, value TEXT)')
                db.executemany('INSERT INTO value VALUES(?,?)', [('Account.XToken:' + account.account_id, account.token), ('StoreFrontIdentifier', account.storefront)])
        finally:
            db.close()
        db = _sqlite(database / 'cookies.sqlitedb')
        try:
            with db:
                db.execute('CREATE TABLE cookies(discard INTEGER DEFAULT 0, domain TEXT NOT NULL, expire_time REAL, name TEXT NOT NULL, path TEXT NOT NULL, secure INTEGER, user INTEGER DEFAULT 0, value TEXT NOT NULL, version INTEGER DEFAULT 1, PRIMARY KEY(name,domain,path))')
                for cookie in cookies:
                    # Retain host-only domains without a leading dot, domain
                    # cookies with one. The source sender preserves this scope.
                    domain = cookie.domain
                    if cookie.domain_specified and not domain.startswith('.'):
                        domain = '.' + domain
                    expiry = cookie.expires - APPLE_EPOCH if cookie.expires is not None else None
                    db.execute('INSERT OR REPLACE INTO cookies VALUES(?,?,?,?,?,?,?,?,?)',
                        (int(cookie.discard), domain, expiry, cookie.name, cookie.path or '/', int(cookie.secure), account.dsid, cookie.value, cookie.version))
        finally:
            db.close()
        for name, data in dict({'device.json': json.dumps({'guid': guid}).encode(), 'DEVICE_SEED': device_seed}, **device_files).items():
            fd = os.open(staging / name, os.O_WRONLY | os.O_CREAT | os.O_EXCL, 0o600)
            with os.fdopen(fd, 'wb') as out:
                out.write(data)
        # Atomic publication to a new path; an existing session is never replaced.
        # Reserve a destination directory before replacing only that empty marker.
        destination.mkdir(mode=0o700)
        try:
            os.replace(staging, destination)
        except BaseException:
            destination.rmdir()
            raise
    finally:
        if staging.exists():
            shutil.rmtree(staging)
