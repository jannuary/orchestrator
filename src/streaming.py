from __future__ import annotations

import struct
import urllib.parse
import urllib.request
from collections import OrderedDict
from concurrent.futures import ThreadPoolExecutor
from dataclasses import dataclass
from typing import Callable, Sequence

from . import mp4box
from .decrypt import (DecryptError, DecryptedTrack, Fragment, _encode_mdat,
                      _parse_moof, decrypt_fragment)
from .keys import KeyMaterial
from .playlist import MediaPlaylist

METADATA_WORKERS = 6
FRAGMENT_CACHE_SIZE = 2
BOX_HEADER_SIZE = 8
EXTENDED_BOX_HEADER_SIZE = 16
REQUEST_TIMEOUT_SECONDS = 45
METADATA_PREFIX_BYTES = 16 * 1024


@dataclass(frozen=True)
class MediaRange:
    url: str
    start: int
    length: int

    def read(self, offset: int, length: int) -> bytes:
        if offset < 0 or length <= 0 or offset + length > self.length:
            raise DecryptError("media read outside the advertised byte range")
        start = self.start + offset
        end = start + length - 1
        request = urllib.request.Request(self.url, headers={
            "Range": f"bytes={start}-{end}",
            "Accept-Encoding": "identity",
            "User-Agent": "amdlitepy/0.1",
        })
        with urllib.request.urlopen(request, timeout=REQUEST_TIMEOUT_SECONDS) as response:
            content_range = response.headers.get("Content-Range", "")
            if response.status != 206 or not content_range.startswith(f"bytes {start}-{end}/"):
                raise DecryptError("media server did not honor the requested byte range")
            data = response.read(length + 1)
        if len(data) != length:
            raise DecryptError("media server returned an incomplete byte range")
        return data


def read_fragment_metadata(media_range: MediaRange) -> tuple[Fragment, int]:
    prefix = media_range.read(0, min(METADATA_PREFIX_BYTES, media_range.length))

    def read_metadata(offset: int, length: int) -> bytes:
        if offset + length <= len(prefix):
            return prefix[offset:offset + length]
        return media_range.read(offset, length)

    offset = 0
    moof = None
    info = None
    preceding_boxes: list[str] = []
    while offset + BOX_HEADER_SIZE <= media_range.length:
        header_length = min(EXTENDED_BOX_HEADER_SIZE, media_range.length - offset)
        header = read_metadata(offset, header_length)
        size, box_type = struct.unpack_from(">I4s", header)
        header_size = BOX_HEADER_SIZE
        if size == 1:
            size = struct.unpack_from(">Q", header, BOX_HEADER_SIZE)[0]
            header_size = EXTENDED_BOX_HEADER_SIZE
        if size == 0:
            size = media_range.length - offset
        if size < header_size or offset + size > media_range.length:
            raise DecryptError("invalid media fragment box size")
        if box_type == b"moof":
            data = read_metadata(offset, size)
            moof = mp4box.find_child(mp4box.parse_boxes(data), "moof")
            if not isinstance(moof, mp4box.ContainerBox):
                raise DecryptError("media fragment has no moof")
            info = _parse_moof(moof, media_range.start + offset)
        if box_type == b"mdat":
            if moof is None or info is None:
                raise DecryptError("media payload precedes its fragment metadata")
            return Fragment(info.start_pos, info, moof, preceding_boxes,
                            header_size, media_range.start + offset + header_size,
                            memoryview(bytearray())), size - header_size
        preceding_boxes.append(box_type.decode("latin1"))
        offset += size
    raise DecryptError("media segment has no audio payload")


class StreamingTrack(DecryptedTrack):
    def __init__(self, playlist: MediaPlaylist, load_keys: Callable[[], Sequence[KeyMaterial]]):
        ranges: list[MediaRange] = []
        previous_end = 0
        previous_url = ""
        for segment in playlist.segments:
            if segment.byterange is None:
                raise DecryptError("streaming requires a byte-range media playlist")
            length, offset = segment.byterange
            url = urllib.parse.urljoin(playlist.base_uri, segment.uri)
            if offset is None and previous_url and url != previous_url:
                raise DecryptError("implicit byte range changed media files")
            start = previous_end if offset is None else offset
            ranges.append(MediaRange(url, start, length))
            previous_end = start + length
            previous_url = url
        if not ranges or ranges[0].start <= 0:
            raise DecryptError("media playlist has no initialization segment")
        initialization_range = MediaRange(ranges[0].url, 0, ranges[0].start)
        with ThreadPoolExecutor(max_workers=METADATA_WORKERS) as executor:
            keys = executor.submit(load_keys)
            initialization = executor.submit(initialization_range.read, 0, initialization_range.length)
            metadata = list(executor.map(read_fragment_metadata, ranges))
            init_bytes = initialization.result()
        self.durations = [segment.duration for segment in playlist.segments]
        self._ranges = ranges
        self._payload_sizes = [size for fragment, size in metadata]
        self._cached_payloads: OrderedDict[int, bytes] = OrderedDict()
        self._initialize(init_bytes, [fragment for fragment, size in metadata],
                         keys.result(), self._payload_sizes)

    def _mdat(self, index: int) -> bytes:
        with self._lock:
            if index in self._cached_payloads:
                self._cached_payloads.move_to_end(index)
                return self._cached_payloads[index]
            fragment = self._fragments[index]
            media_range = self._ranges[index]
            payload_offset = fragment.mdat_payload_start - media_range.start
            encrypted = media_range.read(payload_offset, self._payload_sizes[index])
            fragment.mdat = memoryview(bytearray(encrypted))
            try:
                decrypt_fragment(fragment, self._init, self._keys[index])
                decrypted = _encode_mdat(fragment)
            finally:
                fragment.mdat = memoryview(bytearray())
            self._cached_payloads[index] = decrypted
            while len(self._cached_payloads) > FRAGMENT_CACHE_SIZE:
                self._cached_payloads.popitem(last=False)
            return decrypted

    def segment(self, index: int) -> bytes:
        if index < 0 or index >= len(self._fragments):
            raise IndexError("media segment outside track")
        return self._parts[1 + index * 2][2] + self._mdat(index)

    def initialization(self) -> bytes:
        return self._parts[0][2]
