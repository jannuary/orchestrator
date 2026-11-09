"""HTTP service that decrypts an Apple Music ALAC track given an ``adamId``.

Usage::

    python3 server.py --session /path/to/session [--host 127.0.0.1] [--port 8123]

The session directory holds the account databases, device identity and web
tokens produced by ``scripts/source_login.py`` or by a successful
``POST /login``. When it does not exist yet the server starts unauthenticated
and ``/login`` creates it; ``--device-state`` names the directory holding the
``adi.pb`` / ``ANDROID_ID`` pair the login needs. The ``--certificate`` path
may be overridden; it defaults to the vendored FairPlay certificate.

Endpoints
---------
``POST /login``
    Two-phase account login. Send ``X-Apple-User`` and ``X-Apple-Password``;
    when Apple asks for a two-factor code the response is ``401`` with
    ``{"status": "2fa_required"}``, and reposting the same headers plus
    ``X-Apple-2FA-Code`` completes the login. On success the session is
    written to ``--session`` and this server starts serving from it.

``GET /decrypt/<adamId>?quality=alac``
    Resolve the track's enhanced-HLS media playlist, fetch the (encrypted,
    ALAC/SAMPLE-AES) asset, capture the FairPlay key for its ``#EXT-X-KEY``
    URI, decrypt it, and stream it back as an ``.m4a``.  Single
    ``Range: bytes=...`` requests are honoured with a ``206 Partial Content``
    response, so players can seek.

``GET /healthz``
    Simple liveness probe.

The flow mirrors the Go ``runv4`` downloader: the whole asset (init segment +
fragments) is fetched, then decrypted and re-serialised in place.

The decrypted size is known before anything is decrypted (see
:class:`src.DecryptedTrack`), so responses carry a ``Content-Length`` and the
client still starts receiving bytes as soon as the init segment is ready:
fragments are decrypted as the response reaches them.  Recently used tracks
stay cached, so a seek does not download the asset again.
"""

from __future__ import annotations

import argparse
import json
import logging
import os
import re
import sys
import threading
import time
import urllib.parse
import urllib.request
from collections import OrderedDict
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path

from src import (DecryptedTrack, SourceClient, load_media_playlist,
                 select_media_url, valid_qualities)
from src.login import DEFAULT_STOREFRONT, LoginError, LoginManager

DEFAULT_CERTIFICATE = Path(__file__).resolve().parent / "certs" / "fps-certificate.bin"
SESSION_ENVIRONMENT_VARIABLE = "APPLE_MUSIC_SOURCE_SESSION"

#: FairPlay key URI Apple uses for the shared context template; when a
#: segment carries it the key request must use adamId "0" (preshare), not
#: the track's adamId (mirrors the Go runv2/reference downloader).
PREFETCH_KEY = "skd://itunes.apple.com/P000000000/s1/e1"
PRESHARE_ADAMID = "0"

#: How many decrypted tracks to keep for later range requests: enough for
#: the playing track plus a preloaded next one.
TRACK_CACHE_SIZE = 3

#: Bytes per write when sending a response body.
WRITE_CHUNK = 256 * 1024

LOGIN_HEADER_USER = "X-Apple-User"
LOGIN_HEADER_PASSWORD = "X-Apple-Password"
LOGIN_HEADER_CODE = "X-Apple-2FA-Code"

log = logging.getLogger("orchestrator")


class NotLoggedIn(RuntimeError):
    pass


def fetch_bytes(url: str, timeout: float = 120.0) -> bytes:
    req = urllib.request.Request(url, headers={"User-Agent": "amdlitepy/0.1"})
    with urllib.request.urlopen(req, timeout=timeout) as resp:
        return resp.read()


def load_track(source: SourceClient, adam_id: str, quality: str = "alac") -> DecryptedTrack:
    """Fetch a track's encrypted asset and key captures.

    ``quality`` selects the encoding: ``"hires"``/``"alac"`` for lossless, or
    an AAC kbps tier (``"256"``/``"128"``/``"64"``).  If the exact tier is
    absent the next tier in the chain ``hires -> alac -> 256 -> 128 -> 64``
    is used.  Fragments are decrypted later, as they are read.
    """
    m3u8_url = source.master_playlist_url(adam_id)
    if not m3u8_url:
        raise ValueError(f"adamId {adam_id} has no hi-res asset")

    media_url = select_media_url(m3u8_url, quality)
    pl = load_media_playlist(media_url)

    if not pl.file_uri:
        raise ValueError("media playlist has no segment file URI")

    key_uris: list = []
    for seg in pl.segments:
        uri = seg.key_uri or pl.key_uri
        if not uri:
            raise ValueError("media playlist has no #EXT-X-KEY URI")
        key_uris.append(uri)
    key_materials = {uri: source.key_material(
                         PRESHARE_ADAMID if uri == PREFETCH_KEY else adam_id, uri)
                     for uri in dict.fromkeys(key_uris)}

    asset = fetch_bytes(pl.file_uri)
    return DecryptedTrack(asset, [key_materials[u] for u in key_uris])


def decrypt_adamid(source: SourceClient, adam_id: str, quality: str = "alac"):
    """Fetch and decrypt a track, yielding ``bytes`` chunks.

    The first chunk is the fMP4 init segment; subsequent chunks are
    ``moof``+``mdat`` pairs emitted as each fragment is decrypted.
    """
    yield from load_track(source, adam_id, quality).iter_range()


class TrackCache:
    """Small LRU of :class:`DecryptedTrack`, so range requests for the same
    track (one per seek) reuse it instead of downloading the asset again.
    Concurrent requests for the same track wait for a single load."""

    def __init__(self, source: SourceClient, size: int = TRACK_CACHE_SIZE):
        self._source = source
        self._size = size
        self._tracks: "OrderedDict[tuple, DecryptedTrack]" = OrderedDict()
        self._loading: dict = {}
        self._lock = threading.Lock()

    def get(self, adam_id: str, quality: str) -> DecryptedTrack:
        key = (adam_id, quality)
        with self._lock:
            if key in self._tracks:
                self._tracks.move_to_end(key)
                return self._tracks[key]
            load_lock = self._loading.setdefault(key, threading.Lock())
        with load_lock:
            with self._lock:
                if key in self._tracks:
                    return self._tracks[key]
            try:
                track = load_track(self._source, adam_id, quality)
            finally:
                with self._lock:
                    self._loading.pop(key, None)
            with self._lock:
                self._tracks[key] = track
                while len(self._tracks) > self._size:
                    self._tracks.popitem(last=False)
            return track


class SourceStore:
    """The session the service currently serves from.

    ``adopt`` is called by the login manager once a login has been published
    to the session directory; until then requests are answered with 503 and
    only ``/login`` can make the service useful.
    """

    def __init__(self, session_directory, certificate_file):
        self._session_directory = Path(session_directory)
        self._certificate_file = Path(certificate_file)
        self._lock = threading.Lock()
        self._cache = None

    def load_from_disk(self) -> None:
        if (self._session_directory / "token_cache.json").is_file():
            self.adopt(self._session_directory)

    def adopt(self, session_directory) -> str:
        source = SourceClient(Path(session_directory), self._certificate_file)
        with self._lock:
            self._cache = TrackCache(source)
        return source.storefront

    def cache(self) -> TrackCache:
        with self._lock:
            if self._cache is None:
                raise NotLoggedIn("no session; POST /login first")
            return self._cache


class RangeNotSatisfiable(ValueError):
    pass


def parse_range(header, size: int):
    """Parse a ``Range`` header into an inclusive ``(start, end)`` pair.

    Returns ``None`` when the whole body should be sent: no header, a unit
    other than bytes, a malformed value, or several ranges (which are
    allowed to be answered with the full body).  Raises
    :class:`RangeNotSatisfiable` when the range lies outside the body.
    """
    if not header:
        return None
    m = re.fullmatch(r"\s*bytes\s*=\s*(\d*)\s*-\s*(\d*)\s*", header)
    if not m or not (m.group(1) or m.group(2)):
        return None
    first, last = m.group(1), m.group(2)
    if not first:  # suffix range: the last N bytes
        length = int(last)
        if length == 0 or size == 0:
            raise RangeNotSatisfiable(header)
        return max(size - length, 0), size - 1
    start = int(first)
    end = int(last) if last else size - 1
    if start >= size or end < start:
        raise RangeNotSatisfiable(header)
    return start, min(end, size - 1)


def make_handler(store: SourceStore, login_manager: LoginManager):
    class Handler(BaseHTTPRequestHandler):
        protocol_version = "HTTP/1.1"
        server_version = "amdlitepy/0.1"

        def _send_error_json(self, code: int, message: str) -> None:
            body = ('{"error": %s}' % _json_quote(message)).encode("utf-8")
            self.send_response(code)
            self.send_header("Content-Type", "application/json")
            self.send_header("Content-Length", str(len(body)))
            self.end_headers()
            self.wfile.write(body)

        def _send_json(self, code: int, payload: dict) -> None:
            body = json.dumps(payload).encode("utf-8")
            self.send_response(code)
            self.send_header("Content-Type", "application/json")
            self.send_header("Content-Length", str(len(body)))
            self.end_headers()
            self.wfile.write(body)

        def do_POST(self) -> None:
            parsed = urllib.parse.urlsplit(self.path)
            if parsed.path.rstrip("/") == "/login":
                self._handle_login()
                return
            self._send_error_json(404, "not found")

        def _handle_login(self) -> None:
            username = self.headers.get(LOGIN_HEADER_USER, "")
            password = self.headers.get(LOGIN_HEADER_PASSWORD, "")
            code = self.headers.get(LOGIN_HEADER_CODE, "") or None
            if not username or not password:
                self._send_error_json(
                    400, "missing X-Apple-User or X-Apple-Password header")
                return
            try:
                result = login_manager.authenticate(username, password, code)
            except LoginError as error:
                log.warning("login failed: %s", error)
                self._send_json(
                    401,
                    {"status": "credential_error", "error": str(error)},
                )
                return
            except Exception as error:
                log.exception("login failed")
                self._send_json(
                    502, {"status": "login_error", "error": str(error)})
                return
            if result.verification_required:
                self._send_json(
                    401,
                    {
                        "status": "2fa_required",
                        "error": "2FA required, repost with "
                                 "X-Apple-2FA-Code header",
                    },
                )
                return
            self._send_json(
                200,
                {
                    "status": "logged_in",
                    "storefront": result.storefront,
                    "session_saved": result.session_saved,
                },
            )

        def do_GET(self) -> None:
            parsed = urllib.parse.urlsplit(self.path)
            path = parsed.path.rstrip("/")
            query = urllib.parse.parse_qs(parsed.query)
            quality = (query.get("quality") or [""])[0]

            if path == "/healthz":
                self.send_response(200)
                self.send_header("Content-Type", "text/plain")
                body = b"ok"
                self.send_header("Content-Length", str(len(body)))
                self.end_headers()
                self.wfile.write(body)
                return

            prefix = "/decrypt/"
            if path.startswith(prefix):
                adam_id = urllib.parse.unquote(path[len(prefix):])
                if not adam_id:
                    self._send_error_json(400, "missing adamId")
                    return
                self._handle_decrypt(adam_id, quality)
                return

            self._send_error_json(404, "not found")

        def _handle_decrypt(self, adam_id: str, quality: str = "") -> None:
            if quality == "":
                self._send_error_json(
                    400, "quality is required; "
                         f"expected one of {list(valid_qualities())}")
                return
            if quality not in valid_qualities():
                self._send_error_json(
                    400, f"unknown quality {quality!r}; "
                         f"expected one of {list(valid_qualities())}")
                return
            try:
                cache = store.cache()
            except NotLoggedIn as e:
                self._send_error_json(503, str(e))
                return
            try:
                track = cache.get(adam_id, quality)
            except Exception as e:
                log.exception("adamId=%s could not be loaded", adam_id)
                self._send_error_json(500, f"decryption pipeline failed: {e}")
                return

            try:
                byte_range = parse_range(self.headers.get("Range"), track.size)
            except RangeNotSatisfiable:
                self.send_response(416)
                self.send_header("Content-Range", f"bytes */{track.size}")
                self.send_header("Content-Length", "0")
                self.end_headers()
                return
            start, end = byte_range or (0, track.size - 1)

            self.send_response(206 if byte_range else 200)
            self.send_header("Content-Type", "audio/mp4")
            self.send_header("Content-Disposition",
                             f'attachment; filename="{adam_id}.m4a"')
            self.send_header("Accept-Ranges", "bytes")
            self.send_header("Content-Length", str(end - start + 1))
            if byte_range:
                self.send_header("Content-Range",
                                 f"bytes {start}-{end}/{track.size}")
            self.end_headers()

            sent = 0
            began = time.monotonic()
            try:
                for chunk in track.iter_range(start, end):
                    view = memoryview(chunk)
                    for pos in range(0, len(view), WRITE_CHUNK):
                        self.wfile.write(view[pos:pos + WRITE_CHUNK])
                        sent += min(WRITE_CHUNK, len(view) - pos)
                self.wfile.flush()
                log.info("adamId=%s sent bytes %d-%d/%d in %d ms", adam_id,
                         start, end, track.size,
                         int((time.monotonic() - began) * 1000))
            except (BrokenPipeError, ConnectionResetError):
                # Players drop the connection when they seek or skip.
                log.debug("adamId=%s client closed the connection after %d bytes",
                          adam_id, sent)
                self.close_connection = True
            except Exception:
                # Headers are already sent, so all we can do is close.
                log.exception("adamId=%s failed after %d bytes", adam_id, sent)
                self.close_connection = True

        def log_message(self, fmt, *args):  # noqa: A003
            sys.stderr.write("[%s] %s\n" % (self.log_date_time_string(),
                                            fmt % args))

    return Handler


def _json_quote(s: str) -> str:
    return '"' + s.replace("\\", "\\\\").replace('"', '\\"') + '"'


def make_server(session_directory, certificate_file=DEFAULT_CERTIFICATE,
                host: str = "127.0.0.1", port: int = 8123,
                verbose: bool = False, device_state=None,
                storefront: str = DEFAULT_STOREFRONT,
                bag_file=None) -> ThreadingHTTPServer:
    """Build a configured server instance for programmatic use.

    Start it with ``httpd.serve_forever()`` (optionally in a thread) and stop
    it with ``httpd.shutdown()``.  The session directory is created by a
    successful ``POST /login``; when it already holds tokens it is used
    immediately.
    """
    logging.basicConfig(level=logging.DEBUG if verbose else logging.INFO,
                        format="%(asctime)s %(levelname)s %(message)s")
    session = Path(session_directory)
    store = SourceStore(session, Path(certificate_file))
    store.load_from_disk()
    login_manager = LoginManager(
        session_directory=session,
        device_state=Path(device_state) if device_state else session,
        storefront=storefront,
        bag_file=Path(bag_file) if bag_file else None,
        on_session_saved=store.adopt,
    )
    httpd = ThreadingHTTPServer((host, port), make_handler(store, login_manager))
    httpd.login_manager = login_manager
    return httpd


def serve(session_directory, certificate_file=DEFAULT_CERTIFICATE,
          host: str = "127.0.0.1", port: int = 8123,
          verbose: bool = False, device_state=None,
          storefront: str = DEFAULT_STOREFRONT,
          bag_file=None) -> None:
    """Run the orchestrator server in the foreground (Ctrl-C to stop)."""
    httpd = make_server(session_directory, certificate_file, host, port,
                        verbose, device_state, storefront, bag_file)
    print(f"listening on http://{host}:{port}", file=sys.stderr, flush=True)
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        pass
    finally:
        httpd.login_manager.close()
        httpd.server_close()


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description="Apple Music ALAC decryption service")
    ap.add_argument("--host", default="127.0.0.1")
    ap.add_argument("--port", type=int, default=8123)
    ap.add_argument("--session", default=os.environ.get(SESSION_ENVIRONMENT_VARIABLE),
                    help="source session directory (or APPLE_MUSIC_SOURCE_SESSION); "
                         "created by POST /login when it does not exist yet")
    ap.add_argument("--device-state",
                    help="device identity directory (adi.pb, ANDROID_ID) used "
                         "by POST /login; defaults to --session")
    ap.add_argument("--storefront", default=DEFAULT_STOREFRONT,
                    help="storefront used for a new login")
    ap.add_argument("--bag", dest="bag_file",
                    help="URL bag file to read, or to cache a fetched bag into")
    ap.add_argument("--certificate", default=str(DEFAULT_CERTIFICATE),
                    help="FairPlay certificate used for SPC generation")
    ap.add_argument("--verbose", action="store_true",
                    help="log per-chunk streaming progress")
    args = ap.parse_args(argv)
    if not args.session:
        ap.error("--session or APPLE_MUSIC_SOURCE_SESSION is required")

    serve(session_directory=args.session, certificate_file=args.certificate,
          host=args.host, port=args.port, verbose=args.verbose,
          device_state=args.device_state, storefront=args.storefront,
          bag_file=args.bag_file)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
