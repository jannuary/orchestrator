"""Standalone Apple Music source client.

Owns everything the orchestrator previously asked the wrapper's lite-server
for: account tokens, the enhanced-HLS master playlist, and one FairPlay key
capture per ``#EXT-X-KEY`` URI.
"""

from __future__ import annotations

import ctypes
import json
import threading
import urllib.request
from pathlib import Path

from .keys import KeyMaterial
from .source_package import (
    R1_PROBE_LIBRARY,
    SourceUnavailable,
    ensure_importable,
    require_libraries,
)

ensure_importable()

from apple_music_source.auth import (
    HttpsTransport,
    NativeSession,
    build_fps_request,
    post_fps_request,
)
from apple_music_source.crypto import SourceSession, SourceSessionError

CATALOG_HOST = "https://amp-api.music.apple.com"
FPS_URL = "https://play.itunes.apple.com/WebObjects/MZPlay.woa/music/fps"
SOURCE_USER_AGENT = "Music/5.0.2 Android/10 model/Pixel 8 build/7663314 (dt:66)"
BROWSER_USER_AGENT = (
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 "
    "(KHTML, like Gecko) Chrome/120.0 Safari/537.36"
)
MUSIC_WEB_ORIGIN = "https://music.apple.com/"
FPS_SESSION_FORMAT_VERSION = 1
CAPTURE_CONTEXT_BYTES = 0x8000
CAPTURE_STATE_BYTES = 0x2100
CAPTURE_PLAINTEXT_BYTES = 64
REQUEST_TIMEOUT_SECONDS = 45.0


class SourceError(RuntimeError):
    pass


class SourceClient:
    def __init__(self, session_directory: Path, certificate_file: Path):
        require_libraries()
        self._session_directory = Path(session_directory)
        self._certificate = Path(certificate_file).read_bytes()
        self._native_session = NativeSession.load(self._session_directory)
        self._tokens = json.loads(
            (self._session_directory / "token_cache.json").read_text()
        )
        self._device = json.loads((self._session_directory / "device.json").read_text())
        self._device_seed = (self._session_directory / "DEVICE_SEED").read_bytes()
        self._transport = HttpsTransport()
        self._probe = _load_r1_probe()
        self._lock = threading.Lock()
        self._keys: dict[tuple[str, str], KeyMaterial] = {}

    @property
    def storefront(self) -> str:
        return self._tokens["storefront_id"]

    @property
    def dev_token(self) -> str:
        return self._tokens["dev_token"]

    @property
    def music_token(self) -> str:
        return self._tokens["music_token"]

    def master_playlist_url(self, adam_id: str) -> str:
        catalog_url = (
            f"{CATALOG_HOST}/v1/catalog/{self.storefront}"
            f"/songs/{adam_id}?extend=extendedAssetUrls"
        )
        request = urllib.request.Request(
            catalog_url,
            headers={
                "Authorization": "Bearer " + self._tokens["dev_token"],
                "User-Agent": BROWSER_USER_AGENT,
                "Origin": MUSIC_WEB_ORIGIN.rstrip("/"),
                "Referer": MUSIC_WEB_ORIGIN,
            },
        )
        with urllib.request.urlopen(
            request, timeout=REQUEST_TIMEOUT_SECONDS
        ) as response:
            catalog = json.load(response)
        songs = catalog.get("data") or []
        if not songs:
            raise SourceError(f"catalog has no song {adam_id}")
        assets = songs[0].get("attributes", {}).get("extendedAssetUrls", {})
        return assets.get("enhancedHls") or ""

    def key_material(self, adam_id: str, key_uri: str) -> KeyMaterial:
        cache_key = (adam_id, key_uri)
        with self._lock:
            cached = self._keys.get(cache_key)
            if cached is not None:
                return cached
            material = self._acquire_key(adam_id, key_uri)
            self._keys[cache_key] = material
            return material

    def _acquire_key(self, adam_id: str, key_uri: str) -> KeyMaterial:
        headers = self._native_session.headers(FPS_URL, SOURCE_USER_AGENT)
        metadata = {
            "guid": self._device["guid"],
            "adamId": adam_id,
            "keyUri": key_uri,
        }
        with SourceSession(
            0,
            self._certificate,
            key_uri.encode(),
            self._device_seed,
            format_version=FPS_SESSION_FORMAT_VERSION,
        ) as source:
            request = build_fps_request(
                metadata=metadata, spc=source.spc, headers=headers
            )
            response = post_fps_request(
                request, transport=self._transport, timeout=REQUEST_TIMEOUT_SECONDS
            )
            if not response.successful:
                raise SourceError(
                    f"FPS rejected {key_uri}: HTTP {response.http_status}, "
                    f"status {response.fps_status}"
                )
            _advance_persistent_state(source, response.ckc)
            context = source.context(response.ckc)
            source.finalize_context(context)
            self._probe.wrapper_kg_r1_probe_arm()
            source.decrypt(context, bytes(CAPTURE_PLAINTEXT_BYTES), mode=5)
            context_bytes, state_bytes, rax, rcx = self._capture()
        return KeyMaterial(key_uri, context_bytes, state_bytes, rax, rcx)

    def _capture(self) -> tuple[bytes, bytes, int, int]:
        context_buffer = ctypes.create_string_buffer(CAPTURE_CONTEXT_BYTES)
        state_buffer = ctypes.create_string_buffer(CAPTURE_STATE_BYTES)
        rax = ctypes.c_uint64()
        rcx = ctypes.c_uint64()
        status = self._probe.wrapper_kg_r1_probe_copy(
            context_buffer, state_buffer, ctypes.byref(rax), ctypes.byref(rcx)
        )
        if status != 1:
            raise SourceError(f"source runtime did not reach the key entry point ({status})")
        return context_buffer.raw, state_buffer.raw, rax.value, rcx.value


def _advance_persistent_state(source: SourceSession, ckc: bytes) -> None:
    # The source CKC state machine requires the persistent pass before the
    # context pass even when it rejects this catalog license.
    try:
        source.persistent_response(ckc)
    except SourceSessionError:
        pass


def _load_r1_probe():
    probe = ctypes.CDLL(str(R1_PROBE_LIBRARY), mode=ctypes.RTLD_GLOBAL)
    probe.wrapper_kg_r1_probe_arm.argtypes = []
    probe.wrapper_kg_r1_probe_arm.restype = None
    probe.wrapper_kg_r1_probe_copy.argtypes = [
        ctypes.c_void_p,
        ctypes.c_void_p,
        ctypes.POINTER(ctypes.c_uint64),
        ctypes.POINTER(ctypes.c_uint64),
    ]
    probe.wrapper_kg_r1_probe_copy.restype = ctypes.c_int
    return probe
