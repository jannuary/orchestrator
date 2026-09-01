"""Media (master-variant) playlist loading using the `m3u8` library.

Reproduces the behaviour of the Go runv4 path: the URL returned by
``lite-server /m3u8`` is a *media* playlist.  All its segments share one
file URI, each separated by ``#EXT-X-BYTERANGE``; the first segment's key
URI (``skd://...``) is what we pass to ``/key``.
"""

from __future__ import annotations

import urllib.parse
import urllib.request
from dataclasses import dataclass
from typing import Optional

import m3u8


class PlaylistError(Exception):
    pass


@dataclass
class MediaSegment:
    uri: str
    byterange: Optional[tuple]  # (length, offset) or None
    duration: float
    key_uri: Optional[str] = None  # FairPlay skd:// key in effect for this segment


@dataclass
class MediaPlaylist:
    base_uri: str
    segments: list
    key_uri: Optional[str]

    @property
    def file_uri(self) -> str:
        """Resolve the shared media file URI for the first segment."""
        if not self.segments:
            raise PlaylistError("playlist has no segments")
        return urllib.parse.urljoin(self.base_uri, self.segments[0].uri)

    @property
    def is_byterange(self) -> bool:
        return all(s.byterange is not None for s in self.segments)


def _parse_byterange(s: str) -> Optional[tuple]:
    if not s:
        return None
    # forms: "length@offset" or "length"
    length_s, _, offset_s = s.partition("@")
    length = int(length_s)
    offset = int(offset_s) if offset_s else None
    return length, offset


def _filter_key_lines(text: str) -> str:
    """Drop ``#EXT-X-KEY`` lines that do not target the FairPlay key
    delivery (replicates Go ``filterResponse``).

    Apple Music playlists carry multiple keys (PlayReady / Widevine /
    FairPlay); only the one with ``streamingkeydelivery`` is the ``skd://``
    key we pass to lite-server ``/key``.
    """
    out = []
    for line in text.splitlines():
        if line.startswith("#EXT-X-KEY:") and "streamingkeydelivery" not in line:
            continue
        out.append(line)
    return "\n".join(out) + "\n"


def _alac_sample_rate(playlist) -> Optional[int]:
    """Sample rate encoded in a variant's AUDIO group id (``audio-alac-<sr>-<bd>``)."""
    audio = getattr(playlist.stream_info, "audio", None) or ""
    parts = audio.split("-")
    if len(parts) < 3:
        return None
    try:
        return int(parts[-2])
    except ValueError:
        return None


_QUALITIES = ("alac", "64", "128", "256")


def _variant_kbps(v) -> Optional[int]:
    """Bitrate tier (kbps) encoded in a variant's URI filename.

    Apple names AAC variants ``..._gr<kbps>_mp4a-...m3u8``.  Falls back to the
    AUDIO group id (``audio-stereo-<kbps>`` / ``audio-HE-stereo-<kbps>``).
    """
    name = getattr(v, "uri", "") or ""
    for part in name.split("_"):
        if part.startswith("gr") and part[2:].isdigit():
            return int(part[2:])
    audio = getattr(v.stream_info, "audio", None) or ""
    parts = audio.split("-")
    if len(parts) >= 3:
        try:
            return int(parts[-2])
        except ValueError:
            pass
    return None


def valid_qualities() -> tuple:
    return _QUALITIES


def select_alac_media_url(master_url: str, alac_max: int = 192000) -> str:
    """Resolve a master playlist to its best ALAC media playlist URL.

    This is a thin wrapper over :func:`select_media_url` passing
    ``quality="alac"``.  If the URL already points at a media playlist, it is
    returned unchanged.
    """
    return select_media_url(master_url, "alac", alac_max=alac_max)


def select_media_url(master_url: str, quality: str = "alac",
                     alac_max: int = 192000) -> str:
    """Resolve a master playlist to the media playlist for ``quality``.

    ``quality`` selects a variant by its *tier label* rather than its
    advertised bandwidth:

    * ``"alac"`` (default) -> the best ALAC variant (highest sample rate <=
      ``alac_max``), mirroring the original behaviour.
    * a kbps string (``"64"``, ``"128"``, ``"256"``) -> the AAC variant whose
      tier label matches that bitrate.

    If ``master_url`` already points at a media playlist (not a variant
    master), it is returned unchanged.
    """
    if quality == "":
        quality = "alac"
    if quality != "alac" and quality not in _QUALITIES:
        raise PlaylistError(
            f"unknown quality {quality!r}; expected one of {list(_QUALITIES)}")
    try:
        with urllib.request.urlopen(master_url, timeout=60) as resp:
            text = resp.read().decode("utf-8", errors="replace")
    except urllib.error.URLError as e:
        raise PlaylistError(f"failed to fetch master playlist {master_url}: {e}") from e
    obj = m3u8.M3U8(text, base_uri=master_url)
    if not obj.is_variant:
        return master_url
    variants = list(obj.playlists)
    if not variants:
        raise PlaylistError("master playlist has no variants")

    if quality == "alac":
        candidates = []
        for v in variants:
            codecs = getattr(v.stream_info, "codecs", None) or ""
            if codecs != "alac":
                continue
            rate = _alac_sample_rate(v)
            if rate is None or rate > alac_max:
                continue
            candidates.append(v)
        if not candidates:
            raise PlaylistError("master playlist has no suitable ALAC variant")
        candidates.sort(key=lambda v: v.stream_info.average_bandwidth
                        or v.stream_info.bandwidth or 0, reverse=True)
        return urllib.parse.urljoin(master_url, candidates[0].uri)

    target = int(quality)
    for v in variants:
        if _variant_kbps(v) == target:
            return urllib.parse.urljoin(master_url, v.uri)
    raise PlaylistError(
        f"master playlist has no {target} kbps audio variant")


def load_media_playlist_text(text: str, base_uri: str) -> MediaPlaylist:
    obj = m3u8.M3U8(_filter_key_lines(text), base_uri=base_uri)
    if obj.is_variant:
        raise PlaylistError("expected a media playlist, got a master playlist")
    segs = obj.segments
    if not segs:
        raise PlaylistError("playlist has no segments")
    key_uri = None
    first_key = getattr(segs[0], "key", None)
    if first_key is not None and getattr(first_key, "uri", None):
        key_uri = first_key.uri
    media = []
    for s in segs:
        if s is None:
            continue
        skey = getattr(s, "key", None)
        skey_uri = getattr(skey, "uri", None) if skey is not None else None
        media.append(MediaSegment(
            uri=s.uri,
            byterange=_parse_byterange(str(getattr(s, "byterange", "") or "")),
            duration=getattr(s, "duration", 0.0),
            key_uri=skey_uri,
        ))
    obj_uri = getattr(obj, "uri", None) or ""
    base = obj_uri if obj_uri and not base_uri else (base_uri or obj_uri)
    return MediaPlaylist(base_uri=base or "", segments=media, key_uri=key_uri)


def load_media_playlist(url: str) -> MediaPlaylist:
    try:
        with urllib.request.urlopen(url, timeout=60) as resp:
            text = resp.read().decode("utf-8", errors="replace")
    except urllib.error.URLError as e:
        raise PlaylistError(f"failed to fetch playlist {url}: {e}") from e
    return load_media_playlist_text(text, base_uri=url)
