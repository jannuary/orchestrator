"""Client for the external "wrapper-lite" (lite-server) HTTP API.

Mirrors the endpoints the Go downloader consumes:

* ``GET /m3u8?adamId=<id>``            -> JSON ``{code,msg,data:{m3u8}}``
* ``GET /key?adamId=<id>&uri=<skd://>`` -> JSON ``{code,msg,data:{ctx,state,rcx,rax,rdx,r9,rbp}}``

The ``/key`` response is handed straight to the ``temari`` white-box library
via ``Temari.from_json`` (it expects exactly that shape).
"""

from __future__ import annotations

import json
import urllib.parse
import urllib.request
from dataclasses import dataclass, field
from typing import Optional


class LiteError(Exception):
    pass


@dataclass
class Envelope:
    code: int
    msg: str
    data: dict = field(default_factory=dict)


def _get_json(base: str, path: str) -> Envelope:
    url = base.rstrip("/") + path
    try:
        with urllib.request.urlopen(url, timeout=60) as resp:
            body = resp.read()
    except urllib.error.HTTPError as e:
        raise LiteError(f"lite-server {path} returned {e.code} {e.reason}") from e
    except urllib.error.URLError as e:
        raise LiteError(f"lite-server unreachable: {e}") from e
    try:
        obj = json.loads(body)
    except ValueError as e:
        raise LiteError(f"lite-server {path} returned non-JSON: {e}") from e
    return Envelope(code=obj.get("code"), msg=obj.get("msg"), data=obj.get("data") or {})


class LiteClient:
    def __init__(self, base_url: str):
        self.base = base_url.rstrip("/")
        if not self.base.startswith("http"):
            raise ValueError("lite-server base URL must start with http(s)")

    def m3u8_url(self, adam_id: str) -> str:
        """Return the media-playlist URL for a track ('' when no hires asset)."""
        env = _get_json(self.base, "/m3u8?adamId=" + urllib.parse.quote(adam_id))
        if env.code != 0:
            raise LiteError(f"lite-server /m3u8 returned code={env.code} msg={env.msg}")
        return env.data.get("m3u8") or ""

    def key_template(self, adam_id: str, uri: str) -> dict:
        """Return the raw template dict from /key (fields consumed by temari)."""
        q = urllib.parse.urlencode({"adamId": adam_id, "uri": uri})
        env = _get_json(self.base, "/key?" + q)
        if env.code != 0:
            raise LiteError(f"lite-server /key returned code={env.code} msg={env.msg}")
        return env.data
