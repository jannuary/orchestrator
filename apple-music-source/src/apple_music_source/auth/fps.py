"""Build and post Apple catalog and live-radio FPS requests.

The caller supplies an SPC, a caller-owned authenticated header map, and an
explicit transport. SourceSession in :mod:`apple_music_source.crypto.fps`
generates the matching SPC and retains source state for the CKC exchange.
"""

from __future__ import annotations

import base64
import json
from dataclasses import dataclass, field
from typing import Mapping, Protocol

from .login_client import HttpResult

__all__ = ["FpsRequest", "FpsRequestError", "FpsResponse", "post_fps_request", "build_fps_request"]

_ENDPOINT_HOST = "play.itunes.apple.com"
_ENDPOINT_PATH = "/WebObjects/MZPlay.woa/music/fps"
CATALOG_FPS_URL = "https://" + _ENDPOINT_HOST + _ENDPOINT_PATH
RADIO_FPS_URL = "https://linear.tv.apple.com/v1/radio/streaming-key-delivery"
_MAX_RESPONSE_SIZE = 4 * 1024 * 1024
_EXCLUDED_HEADERS = {
    "host",
    "content-length",
    "content-type",
    "accept-encoding",
    "connection",
    "transfer-encoding",
    "proxy-authorization",
}


class _FpsTransport(Protocol):
    def post(self, url: str, body: bytes, headers: Mapping[str, str], *, timeout: float) -> HttpResult:
        ...


class FpsRequestError(ValueError):
    """Invalid FPS metadata, SPC, or header input."""


@dataclass(frozen=True)
class FpsResponse:
    http_status: int
    fps_status: int | None
    ckc: bytes = field(repr=False)

    @property
    def successful(self) -> bool:
        return self.http_status == 200 and self.fps_status == 0 and bool(self.ckc)


@dataclass(frozen=True)
class FpsRequest:
    body: bytes = field(repr=False)
    headers: Mapping[str, str] = field(repr=False)
    url: str = CATALOG_FPS_URL

    def __post_init__(self):
        if self.url not in (CATALOG_FPS_URL, RADIO_FPS_URL):
            raise FpsRequestError("unsupported FPS service URL")
        if not isinstance(self.body, bytes) or not self.body:
            raise FpsRequestError("FPS body must be nonempty bytes")
        if not isinstance(self.headers, Mapping):
            raise FpsRequestError("FPS headers must be a mapping")


def _safe(value, label: str) -> str:
    if not isinstance(value, str) or not value or any(c in value for c in "\r\n\0"):
        raise FpsRequestError(f"{label} must be a nonempty string without CR/LF/NUL")
    return value


def build_fps_request(
    *,
    metadata: Mapping,
    spc: bytes,
    headers: Mapping[str, str],
) -> FpsRequest:
    """Build one catalog or live-radio FPS request from caller-owned inputs.

    Required metadata keys are ``adamId``, ``keyUri`` and ``guid``.  The header
    map must contain either native account authentication (``cookie``,
    ``x-dsid``, ``x-token``, ``user-agent`` and an ``x-apple-store-front``) or a
    developer/Music-user-token pair (``authorization``,
    ``x-apple-music-user-token`` and ``user-agent``). Live radio requires
    the developer/Music-user-token pair. Values are never logged.
    """
    if not isinstance(metadata, Mapping):
        raise FpsRequestError("metadata must be a mapping")
    if not isinstance(spc, (bytes, bytearray, memoryview)):
        raise FpsRequestError("spc must be bytes-like")
    spc = bytes(spc)
    if not spc:
        raise FpsRequestError("spc must not be empty")
    adam_id = _safe(metadata.get("adamId"), "adamId")
    key_uri = _safe(metadata.get("keyUri"), "keyUri")
    guid = _safe(metadata.get("guid"), "guid")
    if not adam_id.isdigit():
        raise FpsRequestError("adamId must be decimal digits")
    is_radio = key_uri.startswith("skd://linear/")
    if not is_radio and not key_uri.startswith("skd://itunes.apple.com/"):
        raise FpsRequestError("keyUri must be a catalog or live-radio skd:// URI")
    challenge = base64.b64encode(spc).decode("ascii")
    body = {"guid": guid, "adamId": adam_id, "keyUri": key_uri, "spc": challenge}
    if is_radio:
        body = {"challenge": challenge, "uri": key_uri,
                "key-system": "com.apple.fps", "event": "beats1"}
    if "offline" in metadata and not is_radio:
        if not isinstance(metadata["offline"], bool):
            raise FpsRequestError("offline must be boolean")
        body["offline"] = metadata["offline"]
    if not isinstance(headers, Mapping):
        raise FpsRequestError("headers must be a mapping")
    clean: dict[str, str] = {}
    for key, value in headers.items():
        if not isinstance(key, str) or not isinstance(value, str):
            raise FpsRequestError("headers must map strings to strings")
        if not key or key.startswith(":") or any(c in key + value for c in "\r\n\0"):
            raise FpsRequestError("invalid header")
        lowered = key.lower()
        if lowered in _EXCLUDED_HEADERS:
            continue
        clean[lowered] = value
    native_auth = all(clean.get(key) for key in ("cookie", "x-dsid", "x-token", "user-agent"))
    if native_auth and not clean.get("x-apple-store-front"):
        raise FpsRequestError("native FPS authentication requires x-apple-store-front")
    web_auth = all(clean.get(key) for key in ("authorization", "x-apple-music-user-token", "user-agent"))
    if is_radio and not web_auth:
        raise FpsRequestError("live radio requires developer/user-token headers")
    if not (native_auth or web_auth):
        raise FpsRequestError("supply native account headers or developer/user-token headers")
    clean.update({
        "content-type": "application/json",
        "accept-encoding": "gzip",
        "accept": "*/*",
    })
    return FpsRequest(json.dumps(body, separators=(",", ":")).encode(), clean,
                      RADIO_FPS_URL if is_radio else CATALOG_FPS_URL)


def post_fps_request(request: FpsRequest, *, transport: _FpsTransport, timeout: float = 45.0) -> FpsResponse:
    """Post one built request to its validated Apple FPS endpoint.

    The caller owns account credentials and the transport.
    Response bodies and CKCs are excluded from object representations.
    """
    if not isinstance(request, FpsRequest):
        raise TypeError("request must be FpsRequest")
    if not callable(getattr(transport, "post", None)):
        raise TypeError("transport must provide post")
    if isinstance(timeout, bool) or not isinstance(timeout, (int, float)) or timeout <= 0:
        raise ValueError("timeout must be positive")
    response = transport.post(
        request.url,
        request.body,
        request.headers,
        timeout=timeout,
    )
    body = response.body
    if not isinstance(body, bytes) or len(body) > _MAX_RESPONSE_SIZE:
        raise FpsRequestError("FPS response exceeds the size limit")
    try:
        payload = json.loads(body)
    except (UnicodeDecodeError, json.JSONDecodeError) as error:
        raise FpsRequestError("FPS response is not valid JSON") from error
    if not isinstance(payload, dict):
        raise FpsRequestError("FPS response must be a JSON object")
    status = payload.get("status")
    if isinstance(status, bool) or (status is not None and not isinstance(status, int)):
        raise FpsRequestError("FPS response status must be an integer")
    encoded_ckc = payload.get("license", "") if request.url == RADIO_FPS_URL else payload.get("ckc", "")
    if not isinstance(encoded_ckc, str):
        raise FpsRequestError("FPS response CKC must be base64 text")
    try:
        ckc = base64.b64decode(encoded_ckc, validate=True) if encoded_ckc else b""
    except (ValueError, base64.binascii.Error) as error:
        raise FpsRequestError("FPS response CKC is not valid base64") from error
    return FpsResponse(response.status, status, ckc)
