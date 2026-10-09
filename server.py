"""HTTP service that decrypts an Apple Music ALAC track given an ``adamId``.

Usage::

    python3 server.py [--host 127.0.0.1] [--port 8123] [--lite http://127.0.0.1:8080]

Endpoints
---------
``GET /decrypt/<adamId>``
    Resolve the track's media playlist via the lite-server ``/m3u8`` endpoint,
    fetch the (encrypted, ALAC/SAMPLE-AES) asset, decrypt it with the Temari
    white-box (template from lite-server ``/key``), and stream it back as an
    ``.m4a``.  Single ``Range: bytes=...`` requests are honoured with a
    ``206 Partial Content`` response, so players can seek.

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
import logging
import re
import sys
import threading
import time
import urllib.parse
import urllib.request
from collections import OrderedDict
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer

from src import (DecryptedTrack, LiteClient, LiteError, PlaylistError,
                 load_media_playlist, select_media_url, valid_qualities)

DEFAULT_LITE = "http://127.0.0.1:8080"

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

log = logging.getLogger("orchestrator")


def fetch_bytes(url: str, timeout: float = 120.0) -> bytes:
    req = urllib.request.Request(url, headers={"User-Agent": "amdlitepy/0.1"})
    with urllib.request.urlopen(req, timeout=timeout) as resp:
        return resp.read()


def load_track(lite: LiteClient, adam_id: str, quality: str = "alac") -> DecryptedTrack:
    """Fetch a track's encrypted asset and key templates.

    ``quality`` selects the encoding: ``"hires"``/``"alac"`` for lossless, or
    an AAC kbps tier (``"256"``/``"128"``/``"64"``).  If the exact tier is
    absent the next tier in the chain ``hires -> alac -> 256 -> 128 -> 64``
    is used.  Fragments are decrypted later, as they are read.
    """
    m3u8_url = lite.m3u8_url(adam_id)
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
    templates = {uri: lite.key_template(
                     PRESHARE_ADAMID if uri == PREFETCH_KEY else adam_id, uri)
                 for uri in dict.fromkeys(key_uris)}

    asset = fetch_bytes(pl.file_uri)
    return DecryptedTrack(asset, [templates[u] for u in key_uris])


def decrypt_adamid(lite: LiteClient, adam_id: str, quality: str = "alac"):
    """Fetch and decrypt a track, yielding ``bytes`` chunks.

    The first chunk is the fMP4 init segment; subsequent chunks are
    ``moof``+``mdat`` pairs emitted as each fragment is decrypted.
    """
    yield from load_track(lite, adam_id, quality).iter_range()


class TrackCache:
    """Small LRU of :class:`DecryptedTrack`, so range requests for the same
    track (one per seek) reuse it instead of downloading the asset again.
    Concurrent requests for the same track wait for a single load."""

    def __init__(self, lite: LiteClient, size: int = TRACK_CACHE_SIZE):
        self._lite = lite
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
                track = load_track(self._lite, adam_id, quality)
            finally:
                with self._lock:
                    self._loading.pop(key, None)
            with self._lock:
                self._tracks[key] = track
                while len(self._tracks) > self._size:
                    self._tracks.popitem(last=False)
            return track


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


def make_handler(lite: LiteClient):
    cache = TrackCache(lite)

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


def make_server(lite_url: str = DEFAULT_LITE, host: str = "127.0.0.1",
                port: int = 8123, verbose: bool = False) -> ThreadingHTTPServer:
    """Build a configured server instance for programmatic use.

    Start it with ``httpd.serve_forever()`` (optionally in a thread) and stop
    it with ``httpd.shutdown()``.
    """
    logging.basicConfig(level=logging.DEBUG if verbose else logging.INFO,
                        format="%(asctime)s %(levelname)s %(message)s")
    lite = LiteClient(lite_url)
    return ThreadingHTTPServer((host, port), make_handler(lite))


def serve(lite_url: str = DEFAULT_LITE, host: str = "127.0.0.1",
          port: int = 8123, verbose: bool = False) -> None:
    """Run the orchestrator server in the foreground (Ctrl-C to stop)."""
    httpd = make_server(lite_url, host, port, verbose)
    print(f"listening on http://{host}:{port} (lite={lite_url})",
          file=sys.stderr, flush=True)
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        pass


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description="Apple Music ALAC decryption service")
    ap.add_argument("--host", default="127.0.0.1")
    ap.add_argument("--port", type=int, default=8123)
    ap.add_argument("--lite", default=DEFAULT_LITE,
                    help="wrapper-lite server base URL")
    ap.add_argument("--verbose", action="store_true",
                    help="log per-chunk streaming progress")
    args = ap.parse_args(argv)

    serve(lite_url=args.lite, host=args.host, port=args.port, verbose=args.verbose)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
