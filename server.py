"""HTTP service that decrypts an Apple Music ALAC track given an ``adamId``.

Usage::

    python3 server.py [--host 127.0.0.1] [--port 8123] [--lite http://127.0.0.1:8080]

Endpoints
---------
``GET /decrypt/<adamId>``
    Resolve the track's media playlist via the lite-server ``/m3u8`` endpoint,
    fetch the (encrypted, ALAC/SAMPLE-AES) asset, decrypt it with the Temari
    white-box (template from lite-server ``/key``), and stream it back as an
    ``.m4a``.

``GET /healthz``
    Simple liveness probe.

The flow mirrors the Go ``runv4`` downloader: the whole asset (init segment +
fragments) is fetched, then decrypted and re-serialised in place.

The response is streamed (chunked transfer) so the client starts receiving
bytes as soon as the init segment is ready, without waiting for all fragments
to be decrypted.
"""

from __future__ import annotations

import argparse
import logging
import sys
import time
import urllib.parse
import urllib.request
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer

from src import (LiteClient, LiteError, PlaylistError,
                 decrypt_track_streaming, load_media_playlist,
                 select_media_url, valid_qualities)

DEFAULT_LITE = "http://127.0.0.1:8080"

log = logging.getLogger("orchestrator")


def fetch_bytes(url: str, timeout: float = 120.0) -> bytes:
    req = urllib.request.Request(url, headers={"User-Agent": "amdlitepy/0.1"})
    with urllib.request.urlopen(req, timeout=timeout) as resp:
        return resp.read()


def decrypt_adamid(lite: LiteClient, adam_id: str, quality: str = "alac"):
    """Fetch and decrypt a track, yielding ``bytes`` chunks.

    The first chunk is the fMP4 init segment; subsequent chunks are
    ``moof``+``mdat`` pairs emitted as each fragment is decrypted.
    ``quality`` selects the encoding: ``"hires"``/``"alac"`` for lossless, or
    an AAC kbps tier (``"256"``/``"128"``/``"64"``).  If the exact tier is
    absent the next tier in the chain ``hires -> alac -> 256 -> 128 -> 64``
    is used.
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
    templates = {uri: lite.key_template(adam_id, uri)
                 for uri in dict.fromkeys(key_uris)}

    asset = fetch_bytes(pl.file_uri)
    yield from decrypt_track_streaming(asset, [templates[u] for u in key_uris])


def make_handler(lite: LiteClient):
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
                chunks = decrypt_adamid(lite, adam_id, quality)
                filename = f"{adam_id}.m4a"
                self.send_response(200)
                self.send_header("Content-Type", "audio/mp4")
                self.send_header("Content-Disposition",
                                 f'attachment; filename="{filename}"')
                self.send_header("Transfer-Encoding", "chunked")
                self.end_headers()

                for idx, chunk in enumerate(chunks):
                    start = time.monotonic()
                    size_hex = format(len(chunk), "x").encode("ascii")
                    self.wfile.write(size_hex + b"\r\n" + chunk + b"\r\n")
                    self.wfile.flush()
                    log.debug("adamId=%s chunk=%d bytes=%d write_ms=%d",
                              adam_id, idx, len(chunk),
                              int((time.monotonic() - start) * 1000))
                self.wfile.write(b"0\r\n\r\n")
                self.wfile.flush()
                log.info("adamId=%s streamed %d chunks", adam_id, idx + 1)
            except BaseException as e:  # catch BrokenPipeError after headers
                import traceback
                log.error("adamId=%s failed after headers: %s\n%s",
                          adam_id, e, traceback.format_exc())
                try:
                    self._send_error_json(500, f"decryption pipeline failed: {e}")
                except BaseException:
                    pass

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
