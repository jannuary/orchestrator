"""Minimal ISO BMFF (MP4 / fragmented MP4) parser and re-serialiser.

This is a focused implementation covering the subset of boxes that the
Apple Music ALAC/CBCS (SAMPLE-AES, white-box / "cbcs" scheme) decryption
pipeline needs.  It deliberately mirrors the semantics of the `mp4ff`
library used by the Go runv4 path rather than being a general media
container library.

Box model
---------
A box is decoded as either a ``ContainerBox`` (holds child boxes, used for
moov/trak/mdia/minf/stbl/traf/moof/sinf/schi/... ) or a ``LeafBox``
(opaque raw payload for everything else).  We keep enough parse-time
information to re-encode the container tree so that encryption-related
boxes can be stripped and ``trun.data_offset`` values can be rewritten,
while all opaque leaf payloads round-trip unmodified.
"""

from __future__ import annotations

import struct
from dataclasses import dataclass, field
from typing import List, Optional


class BoxError(Exception):
    pass


CONTAINER_TYPES = {
    "moov", "trak", "mdia", "minf", "stbl", "edts", "dinf", "udta",
    "moof", "traf", "mvex", "schi", "sinf", "wave", "iprp", "iref", "mfra",
}


@dataclass
class LeafBox:
    typ: str
    header_size: int
    size: int
    payload: bytes


@dataclass
class ContainerBox:
    typ: str
    header_size: int
    size: int
    children: List[object] = field(default_factory=list)


def _nxt(data: bytes, pos: int, end: int) -> Optional[tuple]:
    if pos + 8 > end:
        return None
    size = struct.unpack_from(">I", data, pos)[0]
    typ = data[pos + 4:pos + 8].decode("latin1")
    hdr = 8
    if size == 1:
        if pos + 16 > end:
            return None
        size = struct.unpack_from(">Q", data, pos + 8)[0]
        hdr = 16
    elif size == 0:
        size = end - pos
    if size < hdr or pos + size > end:
        raise BoxError(f"bad box size {size} for '{typ}' at 0x{pos:x}")
    return typ, size, hdr


def _parse(data: bytes, pos: int, end: int, boxes: List[object]) -> None:
    while pos < end:
        nxt = _nxt(data, pos, end)
        if nxt is None:
            break
        typ, size, hdr = nxt
        body_off = pos + hdr
        body_end = pos + size
        if typ in CONTAINER_TYPES:
            child = ContainerBox(typ=typ, header_size=hdr, size=size)
            _parse(data, body_off, body_end, child.children)
            boxes.append(child)
        else:
            boxes.append(LeafBox(typ=typ, header_size=hdr, size=size,
                                 payload=bytes(data[body_off:body_end])))
        pos = body_end


def parse_boxes(data: bytes, pos: int = 0, end: Optional[int] = None) -> List[object]:
    if end is None:
        end = len(data)
    boxes: List[object] = []
    _parse(data, pos, end, boxes)
    return boxes


def find_child(boxes: List[object], typ: str) -> Optional[object]:
    for b in boxes:
        if isinstance(b, (LeafBox, ContainerBox)) and b.typ == typ:
            return b
    return None


def find_children(boxes: List[object], typ: str) -> List[object]:
    return [b for b in boxes if isinstance(b, (LeafBox, ContainerBox)) and b.typ == typ]


def encode_tree(node: object) -> bytes:
    if isinstance(node, LeafBox):
        content = node.payload
        if node.header_size == 16:
            return (struct.pack(">I", 1) + node.typ.encode("latin1")
                    + struct.pack(">Q", 16 + len(content)) + content)
        size = node.header_size + len(content)
        return struct.pack(">I", size) + node.typ.encode("latin1") + content
    if isinstance(node, ContainerBox):
        content = b"".join(encode_tree(c) for c in node.children)
        size = 8 + len(content)
        return struct.pack(">I", size) + node.typ.encode("latin1") + content
    return b""
