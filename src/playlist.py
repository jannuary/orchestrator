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


_QUALITIES = ("hires", "alac", "256", "128", "64")

#: Sample rates above this are treated as hi-res lossless (88.2/96/176.4/192k);
#: 44.1k/48k are standard lossless.  Mirrors the Apple Music lossless split.
_ALAC_HIRES_RATE = 48000


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


def _fetch_variants(master_url: str):
    """Return the master's variant list, or ``None`` if already a media playlist."""
    try:
        with urllib.request.urlopen(master_url, timeout=60) as resp:
            text = resp.read().decode("utf-8", errors="replace")
    except urllib.error.URLError as e:
        raise PlaylistError(f"failed to fetch master playlist {master_url}: {e}") from e
    obj = m3u8.M3U8(text, base_uri=master_url)
    if not obj.is_variant:
        return None
    return list(obj.playlists)


def _best_bandwidth(variants):
    return sorted(
        variants,
        key=lambda v: v.stream_info.average_bandwidth
        or v.stream_info.bandwidth or 0,
        reverse=True)


def _match_quality(variants, quality: str, alac_max: int):
    """Return the variant for a single quality tier, or ``None`` if absent.

    ``"hires"`` selects a hi-res (``> 48 kHz``) ALAC variant, ``"alac"`` a
    standard (``<= 48 kHz``) ALAC variant, and the numeric tiers their AAC
    counterpart by kbps label.
    """
    if quality in ("hires", "alac"):
        cands = []
        for v in variants:
            codecs = getattr(v.stream_info, "codecs", None) or ""
            if codecs != "alac":
                continue
            rate = _alac_sample_rate(v)
            if rate is None or rate > alac_max:
                continue
            if quality == "hires" and rate <= _ALAC_HIRES_RATE:
                continue
            if quality == "alac" and rate > _ALAC_HIRES_RATE:
                continue
            cands.append(v)
        if not cands:
            return None
        return _best_bandwidth(cands)[0]
    target = int(quality)
    for v in variants:
        if _variant_kbps(v) == target:
            return v
    return None


def select_alac_media_url(master_url: str, alac_max: int = 192000) -> str:
    """Resolve a master playlist to its best ALAC media playlist URL.

    Pure ALAC selection (never falls back to AAC): prefers the hi-res ALAC
    variant, else standard lossless, highest bandwidth.  If the URL already
    points at a media playlist, it is returned unchanged.
    """
    variants = _fetch_variants(master_url)
    if variants is None:
        return master_url
    for q in ("hires", "alac"):
        v = _match_quality(variants, q, alac_max)
        if v is not None:
            return urllib.parse.urljoin(master_url, v.uri)
    raise PlaylistError("master playlist has no suitable ALAC variant")


def select_media_url(master_url: str, quality: str,
                     alac_max: int = 192000) -> str:
    """Resolve a master playlist to the media playlist for ``quality``.

    ``quality`` is a tier label: ``"hires"`` (hi-res ALAC), ``"alac"``
    (standard lossless), or an AAC kbps tier (``"64"``/``"128"``/``"256"``).
    If that exact tier is not present, fall back to the *next* tier in the
    priority chain ``hires -> alac -> 256 -> 128 -> 64``; if nothing matches
    it raises :class:`PlaylistError`.  An empty ``quality`` is an error.

    If ``master_url`` already points at a media playlist (not a variant
    master), it is returned unchanged.
    """
    if quality == "":
        raise PlaylistError(
            f"quality is required; expected one of {list(_QUALITIES)}")
    if quality not in _QUALITIES:
        raise PlaylistError(
            f"unknown quality {quality!r}; expected one of {list(_QUALITIES)}")
    variants = _fetch_variants(master_url)
    if variants is None:
        return master_url
    if not variants:
        raise PlaylistError("master playlist has no variants")

    start = _QUALITIES.index(quality)
    for q in _QUALITIES[start:]:
        v = _match_quality(variants, q, alac_max)
        if v is not None:
            return urllib.parse.urljoin(master_url, v.uri)
    raise PlaylistError(
        f"master playlist has no audio variant for quality {quality!r} "
        f"(tried {' -> '.join(_QUALITIES[start:])})")


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
