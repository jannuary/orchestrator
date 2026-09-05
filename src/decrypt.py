"""fMP4 (SAMPLE-AES / "cbcs") decryption pipeline using the Temari library.

This replicates the Go ``runv4`` path for Apple Music ALAC ("hi-res lossless"):

1. Parse the init segment into a ``moov`` box tree; read per-track decryption
   info (``sinf/schm/schi/tenc``), the default sample values (``mvex/trex``),
   and strip the ``seig``/``seam`` sbgp/sgpd boxes.  Deduplicate the twin
   ``alac`` sample entries in ``stsd``.
2. Parse each fragment (``moof`` + ``mdat``).  Locate every sample's data in
   the ``mdat`` payload (via tfhd/trun + moof start offset).
3. Decrypt each sample's protected bytes with the Temari white-box (built from
   the lite-server ``/key`` template), in place.
4. Rebuild each ``moof`` with encryption boxes (senc/saiz/saio/seig/sgpd/pssh)
   removed and ``trun.data_offset`` adjusted, then emit the init + fragments.

The external ``temari`` package must be importable (``pip install temari``).
"""

from __future__ import annotations

import struct
from dataclasses import dataclass, field
from typing import Dict, List, Optional

from . import mp4box as b
from .mp4box import ContainerBox, LeafBox

from temari import Temari


class DecryptError(Exception):
    pass


# trun / tfhd / senc flags
TRUN_DATA_OFFSET = 0x000001
TRUN_FIRST_SAMPLE_FLAGS = 0x000004
TRUN_SAMPLE_DURATION = 0x000100
TRUN_SAMPLE_SIZE = 0x000200
TRUN_SAMPLE_FLAGS = 0x000400
TRUN_SAMPLE_CTO = 0x000800
TFHD_BASE_DATA_OFFSET = 0x000001
TFHD_SAMPLE_DESCRIPTION_INDEX = 0x000002
TFHD_DEFAULT_BASE_IS_MOOF = 0x020000
SENC_SUBSAMPLE = 0x000002


@dataclass
class Tenc:
    default_crypt_byte_block: int = 0
    default_skip_byte_block: int = 0
    default_iv_size: int = 0


@dataclass
class TrackInfo:
    track_id: int
    scheme: Optional[str] = None
    tenc: Optional[Tenc] = None
    trex_default_size: int = 0
    trex_default_duration: int = 0
    encrypted: bool = True


@dataclass
class TrunInfo:
    flags: int
    data_offset: int = 0
    sizes: List[int] = field(default_factory=list)
    durations: List[int] = field(default_factory=list)


@dataclass
class TrafInfo:
    track_id: int
    tfhd_flags: int
    base_data_offset: int = 0
    truns: List[TrunInfo] = field(default_factory=list)
    senc_subsamples: Optional[list] = None


@dataclass
class MoofInfo:
    start_pos: int
    tree: List[object]
    trafs: List[TrafInfo] = field(default_factory=list)


@dataclass
class Fragment:
    moof_start: int
    moof_info: MoofInfo
    moof: ContainerBox  # parsed moof box tree (children may be mutated)
    pre_mdat: List[object]  # boxes between moof and mdat (emsg/prft), in order
    mdat_header_size: int  # 8 or 16 (from the source stream)
    mdat_payload_start: int
    mdat: memoryview


# ---------------------------------------------------------------------------
# ISO BMFF scalar helpers
# ---------------------------------------------------------------------------

def _top_boxes(data: bytes):
    """Yield (typ, size, hdr, start) for top-level boxes of a byte buffer."""
    pos = 0
    end = len(data)
    while pos + 8 <= end:
        size = struct.unpack_from(">I", data, pos)[0]
        typ = data[pos + 4:pos + 8].decode("latin1")
        hdr = 8
        if size == 1:
            size = struct.unpack_from(">Q", data, pos + 8)[0]
            hdr = 16
        elif size == 0:
            size = end - pos
        yield typ, size, hdr, pos
        pos += size


def _find_track_id(trak: ContainerBox) -> Optional[int]:
    tkhd = b.find_child(trak.children, "tkhd")
    if tkhd is None or not isinstance(tkhd, LeafBox):
        return None
    payload = tkhd.payload
    if not payload:
        return None
    version = payload[0]
    # FullBox(version+flags=4) + creation(4|8) + modification(4|8) + track_ID
    off = 12 if version == 0 else 20
    if len(payload) < off + 4:
        return None
    return struct.unpack_from(">I", payload, off)[0]


def _find_scheme(stsd_entry: ContainerBox) -> Optional[str]:
    """Walk a sample entry to sinf/schm and return scheme type (e.g. 'cbcs')."""
    sinf = b.find_child(stsd_entry.children, "sinf")
    if sinf is None or not isinstance(sinf, ContainerBox):
        return None
    schm = b.find_child(sinf.children, "schm")
    if schm is None or not isinstance(schm, LeafBox):
        return None
    payload = schm.payload
    if len(payload) < 8:
        return None
    return payload[4:8].decode("latin1")


def _find_tenc(stsd_entry: ContainerBox) -> Optional[Tenc]:
    sinf = b.find_child(stsd_entry.children, "sinf")
    if sinf is None or not isinstance(sinf, ContainerBox):
        return None
    schi = b.find_child(sinf.children, "schi")
    if schi is None or not isinstance(schi, ContainerBox):
        return None
    tenc = b.find_child(schi.children, "tenc")
    if tenc is None or not isinstance(tenc, LeafBox):
        return None
    payload = tenc.payload
    if len(payload) < 6:
        return None
    # payload: version(1) flags(3) reserved(1) default_crypt_byte_block(1)
    #          default_skip_byte_block(1) default_isProtected(1) ...
    return Tenc(
        default_crypt_byte_block=payload[4],
        default_skip_byte_block=payload[5],
        default_iv_size=payload[7] if len(payload) > 7 else 0,
    )


# Sub-boxes that appear inside an audio sample entry ('alac'/'enca'/'mp4a'/
# 'fLaC'/...).  These hold a codec box plus, when encrypted, a 'sinf' box that
# itself contains 'frma'/'schm'/'schi'/'tenc'.  They are not general MP4
# containers, so they are kept out of the global CONTAINER_TYPES.
_AUDIO_ENTRY_TYPES = {"alac", "enca", "encv", "fLaC", "mp4a", "ac-3",
                      "ec-3", "Opus", "vorb", "flac", "sowt", "lpcm"}


def _parse_entry_children(body: bytes) -> List[object]:
    """Parse the sub-boxes of an audio sample entry body.

    ``body`` starts right after the sample entry's box header (i.e. after the
    8-byte box size+type).  Sub-boxes like ``alac`` (the codec magic cookie)
    are leaves; ``sinf`` is a container holding ``frma``/``schm``/``schi``.
    """
    boxes = []
    pos = 0
    end = len(body)
    while pos + 8 <= end:
        size = struct.unpack_from(">I", body, pos)[0]
        typ = body[pos + 4:pos + 8].decode("latin1")
        hdr = 8
        if size == 1:
            size = struct.unpack_from(">Q", body, pos + 8)[0]
            hdr = 16
        elif size == 0:
            size = end - pos
        if size < hdr or pos + size > end:
            break
        sub = body[pos + hdr:pos + size]
        if typ in ("sinf", "schi"):
            node = ContainerBox(typ=typ, header_size=hdr, size=size)
            node.children = _parse_entry_children(sub)
            boxes.append(node)
        else:
            boxes.append(LeafBox(typ=typ, header_size=hdr, size=size,
                                 payload=sub))
        pos += size
    return boxes


def _parse_stsd_sample_entries(stsd: object) -> List[ContainerBox]:
    """Parse the sample entries of an ``stsd`` leaf into box trees.

    stsd is a FullBox (version+flags+entry_count) followed by audio sample
    entries.  Each entry starts with a type (e.g. 'alac'/'enca'), followed by a
    fixed 28-byte audio sample entry header, then sub-boxes.  The entry is
    returned as a ContainerBox whose ``fixed_header`` attribute holds the byte
    segment before the first sub-box, so it can be re-encoded faithfully.
    """
    if not isinstance(stsd, LeafBox):
        return []
    payload = stsd.payload
    if len(payload) < 8:
        return []
    body = payload[8:]  # skip version(1)+flags(3)+entry_count(4)
    entries = []
    pos = 0
    end = len(body)
    while pos + 8 <= end:
        size = struct.unpack_from(">I", body, pos)[0]
        typ = body[pos + 4:pos + 8].decode("latin1")
        if size == 0:
            size = end - pos
        if size < 8 or pos + size > end or typ not in _AUDIO_ENTRY_TYPES:
            break
        entry_body = body[pos + 8:pos + size]
        # audio sample entry fixed header: 8 (reserved+data_ref) + 20 (codec)
        fixed = entry_body[:28]
        children = _parse_entry_children(entry_body[28:])
        node = ContainerBox(typ=typ, header_size=8, size=size)
        node.fixed_header = fixed
        node.children = children
        entries.append(node)
        pos += size
    return entries


def _sample_entries(stsd: object) -> List[ContainerBox]:
    return _parse_stsd_sample_entries(stsd)


class InitInfo:
    """Decoded init segment: box tree + per-track decryption info."""

    def __init__(self, data: bytes):
        self.data = data
        self.tree = b.parse_boxes(data)
        self.tracks: Dict[int, TrackInfo] = {}
        moov = b.find_child(self.tree, "moov")
        if moov is None or not isinstance(moov, ContainerBox):
            raise DecryptError("init segment has no moov box")
        self.moov = moov
        mvex = b.find_child(moov.children, "mvex")
        trex_defaults: Dict[int, tuple] = {}
        if mvex is not None and isinstance(mvex, ContainerBox):
            for trex in b.find_children(mvex.children, "trex"):
                payload = trex.payload if isinstance(trex, LeafBox) else None
                if payload and len(payload) >= 16:
                    # payload = version(1)+flags(3)+track_ID(4) [offset 0]
                    #   + default_sample_description_index(4) [offset 4]
                    #   + default_sample_duration(4) [offset 8]
                    #   + default_sample_size(4) [offset 12]
                    track_id = struct.unpack_from(">I", payload, 0)[0]
                    default_size = struct.unpack_from(">I", payload, 12)[0]
                    default_duration = struct.unpack_from(">I", payload, 8)[0]
                    trex_defaults[track_id] = (default_size, default_duration)
        for trak in b.find_children(moov.children, "trak"):
            if not isinstance(trak, ContainerBox):
                continue
            track_id = _find_track_id(trak)
            if track_id is None:
                continue
            mdia = b.find_child(trak.children, "mdia")
            if mdia is None or not isinstance(mdia, ContainerBox):
                continue
            minf = b.find_child(mdia.children, "minf")
            if minf is None or not isinstance(minf, ContainerBox):
                continue
            stbl = b.find_child(minf.children, "stbl")
            if stbl is None or not isinstance(stbl, ContainerBox):
                continue
            stsd = b.find_child(stbl.children, "stsd")
            info = TrackInfo(track_id=track_id)
            if trex_defaults.get(track_id):
                ds, dd = trex_defaults[track_id]
                info.trex_default_size = ds
                info.trex_default_duration = dd
            if stsd is not None:  # stsd may be a LeafBox in our parser
                scheme = None
                tenc = None
                for entry in _sample_entries(stsd):
                    s = _find_scheme(entry)
                    if s:
                        scheme = s
                        tenc = _find_tenc(entry)
                        break
                if scheme is None:
                    info.encrypted = False
                else:
                    info.scheme = scheme
                    info.tenc = tenc
            self.tracks[track_id] = info


def _filter_sbgp_sgpd(children: List[object]) -> List[object]:
    kept = []
    for child in children:
        if isinstance(child, LeafBox) and child.typ in ("sbgp", "sgpd"):
            payload = child.payload
            if len(payload) >= 4:
                group_type = payload[4:8].decode("latin1")
                if group_type in ("seig", "seam"):
                    continue
        kept.append(child)
    return kept


def _encode_sample_entry(node: ContainerBox) -> bytes:
    """Encode an audio sample entry (fixed header + sub-boxes) as a box."""
    body = getattr(node, "fixed_header", b"") + b"".join(
        b.encode_tree(c) for c in node.children)
    return struct.pack(">I", 8 + len(body)) + node.typ.encode("latin1") + body


def _frma_format(sinf: ContainerBox) -> Optional[str]:
    frma = b.find_child(sinf.children, "frma")
    if frma is not None and isinstance(frma, LeafBox) and len(frma.payload) >= 4:
        return frma.payload[:4].decode("latin1")
    return None


def _enca_to_plain(entry: ContainerBox) -> str:
    """Convert an 'enca'/'encv' sample entry in place to its plain codec type:
    remove the 'sinf' box and rename the entry to sinf.frma.data_format."""
    sinf = b.find_child(entry.children, "sinf")
    fmt = None
    if sinf is not None and isinstance(sinf, ContainerBox):
        fmt = _frma_format(sinf)
    entry.children = [c for c in entry.children
                      if not (isinstance(c, (LeafBox, ContainerBox)) and c.typ == "sinf")]
    if fmt:
        entry.typ = fmt
    return fmt or ""


def _patch_stsd(stbl: ContainerBox, stsd: object, kept_entries: List[object]) -> None:
    """Rebuild an stsd leaf with an updated entry_count and kept entries.

    stsd is a FullBox: version(1)+flags(3)+entry_count(4) followed by sample
    entries.  Only the kept sample entries (re-encoded from the parsed trees)
    are written, so the leftover entry_count matches the kept set."""
    if not isinstance(stsd, LeafBox):
        return
    header = stsd.payload[:4] + struct.pack(">I", len(kept_entries))
    content = header + b"".join(_encode_sample_entry(c) for c in kept_entries)
    new_leaf = LeafBox(typ="stsd", header_size=stsd.header_size,
                       size=stsd.header_size + len(content), payload=content)
    stbl.children = [new_leaf if c is stsd else c for c in stbl.children]


def sanitize_init(init: InitInfo) -> None:
    """Remove encryption metadata from the init segment.

    Mirrors mp4ff ``TransformInit``/``DecryptInit`` + runv4 ``sanitizeInit``:
    strip seig/seam sbgp/sgpd, convert encrypted ``enca``/``encv`` sample
    entries to their plain codec type (removing the ``sinf`` box), then dedup
    the twin identical sample entries (stsd.SampleCount reduced to 1).  This
    mutates the init tree in place.
    """
    for trak in b.find_children(init.moov.children, "trak"):
        if not isinstance(trak, ContainerBox):
            continue
        mdia = b.find_child(trak.children, "mdia")
        if not isinstance(mdia, ContainerBox):
            continue
        minf = b.find_child(mdia.children, "minf")
        if not isinstance(minf, ContainerBox):
            continue
        stbl = b.find_child(minf.children, "stbl")
        if not isinstance(stbl, ContainerBox):
            continue
        stbl.children = _filter_sbgp_sgpd(stbl.children)
        stsd = b.find_child(stbl.children, "stsd")
        entries = _sample_entries(stsd)
        if not entries:
            continue
        # convert encrypted entries (enca/encv) to plain codec entries
        for e in entries:
            if e.typ in ("enca", "encv"):
                _enca_to_plain(e)
        # dedup twin identical entries (e.g. two 'alac')
        if len(entries) >= 2 and entries[0].typ == entries[1].typ:
            entries = entries[:1]
        _patch_stsd(stbl, stsd, entries)


# ---------------------------------------------------------------------------
# Fragment (moof + mdat) parsing
# ---------------------------------------------------------------------------

def _parse_senc_subsamples(box: LeafBox, sample_count: int, iv_size: int):
    """Return a per-sample list of subsample patterns, or None if the senc box
    is absent (caller handles).  ``iv_size`` is the track's per-sample IV size
    (from ``tenc``); 0 for constant-IV streams.

    Returns a list aligned to sample_count; each element is a list of
    (bytes_of_clear, bytes_of_protected) tuples."""
    payload = box.payload
    if len(payload) < 8:
        return [[] for _ in range(sample_count)]
    ver = payload[0]
    flags = int.from_bytes(payload[1:4], "big")
    count = int.from_bytes(payload[4:8], "big")
    have_subsample = bool(flags & SENC_SUBSAMPLE)

    def walk(iv_bytes):
        pos = 8
        out = []
        for _ in range(count):
            if have_subsample:
                if iv_bytes and pos + iv_bytes <= len(payload):
                    pos += iv_bytes
                if pos + 2 > len(payload):
                    break
                nsub = int.from_bytes(payload[pos:pos + 2], "big")
                pos += 2
                pats = []
                broken = False
                for _ in range(nsub):
                    if pos + 6 > len(payload):
                        broken = True
                        break
                    clear = int.from_bytes(payload[pos:pos + 2], "big")
                    prot = int.from_bytes(payload[pos + 2:pos + 6], "big")
                    pos += 6
                    pats.append((clear, prot))
                if broken:
                    pos = -1
                    break
                out.append(pats)
            else:
                if iv_bytes and pos + iv_bytes <= len(payload):
                    pos += iv_bytes
                out.append([])
        return out, pos

    # Constant-IV senc boxes omit a per-sample IV altogether.  Try the supplied
    # iv_size first; if it doesn't consume the box cleanly, fall back to no IV.
    candidates = [iv_size] if iv_size else [0, 16]
    best = None
    for iv in candidates:
        parsed, consumed = walk(iv)
        if consumed == len(payload) and len(parsed) == count:
            best = parsed
            break
    parsed = best if best is not None else walk(0)[0]
    out = parsed[:sample_count]
    while len(out) < sample_count:
        out.append([])
    return out


def _parse_trun(box: LeafBox, default_size, default_duration):
    """Decode a trun box into (flags, data_offset, sizes, durations)."""
    payload = box.payload
    ver = payload[0]
    flags = int.from_bytes(payload[1:4], "big")
    sample_count = int.from_bytes(payload[4:8], "big")
    pos = 8
    data_offset = 0
    if flags & TRUN_DATA_OFFSET:
        data_offset = int.from_bytes(payload[pos:pos + 4], "big", signed=True)
        pos += 4
    if flags & TRUN_FIRST_SAMPLE_FLAGS:
        pos += 4
    sizes = []
    durations = []
    for _ in range(sample_count):
        if flags & TRUN_SAMPLE_DURATION:
            durations.append(int.from_bytes(payload[pos:pos + 4], "big"))
            pos += 4
        if flags & TRUN_SAMPLE_SIZE:
            sizes.append(int.from_bytes(payload[pos:pos + 4], "big"))
            pos += 4
        if flags & TRUN_SAMPLE_FLAGS:
            pos += 4
        if flags & TRUN_SAMPLE_CTO:
            pos += 4 if ver == 0 else 8
    if not sizes:
        sizes = [default_size] * sample_count
    if not durations:
        durations = [default_duration] * sample_count
    return TrunInfo(flags=flags, data_offset=data_offset,
                    sizes=sizes, durations=durations)


def _parse_moof(box: ContainerBox, moof_start: int) -> MoofInfo:
    info = MoofInfo(start_pos=moof_start, tree=[box])
    for traf in b.find_children(box.children, "traf"):
        if not isinstance(traf, ContainerBox):
            continue
        tfhd = b.find_child(traf.children, "tfhd")
        tfhd_flags = 0
        track_id = 0
        base_data_offset = 0
        if tfhd is not None and isinstance(tfhd, LeafBox):
            payload = tfhd.payload
            if len(payload) >= 8:
                tfhd_flags = int.from_bytes(payload[1:4], "big")
                track_id = int.from_bytes(payload[4:8], "big")
                pos = 8
                if tfhd_flags & TFHD_BASE_DATA_OFFSET:
                    base_data_offset = int.from_bytes(payload[pos:pos + 8], "big")
                    pos += 8
        tinfo = TrafInfo(track_id=track_id, tfhd_flags=tfhd_flags,
                         base_data_offset=base_data_offset)
        senc = b.find_child(traf.children, "senc")
        tinfo.senc_subsamples = None
        if senc is not None and isinstance(senc, LeafBox):
            n_samples = 0
            for trun in b.find_children(traf.children, "trun"):
                if isinstance(trun, LeafBox) and len(trun.payload) >= 8:
                    n_samples += int.from_bytes(trun.payload[4:8], "big")
            tinfo.senc_subsamples = _parse_senc_subsamples(senc, n_samples, 16)
        for trun in b.find_children(traf.children, "trun"):
            if isinstance(trun, LeafBox):
                tinfo.truns.append(_parse_trun(trun, 0, 0))
        info.trafs.append(tinfo)
    return info


def split_fragments(data: bytes):
    """Split an fMP4 byte stream into (init_bytes, [Fragment, ...]).

    Mirrors the Go ``ReadNextFragment`` loop: a fragment begins at a ``moof``,
    accumulates ``moof``/``emsg``/``prft`` boxes, and stops at the first
    ``mdat``.  Any other box types found mid-stream are ignored.  The init
    segment is the contiguous run of boxes before the first ``moof``.
    """
    if isinstance(data, bytes):
        data = bytearray(data)  # mdat payload is decrypted in place (writable)
    boxes = list(_top_boxes(data))
    if not boxes:
        raise DecryptError("empty fMP4 stream")
    init_end = 0
    for typ, size, hdr, start in boxes:
        if typ == "moof":
            init_end = start
            break
    else:
        init_end = len(data)
    init_bytes = data[:init_end]
    frags = []
    i = 0
    while i < len(boxes):
        typ, size, hdr, start = boxes[i]
        if typ == "moof":
            # collect pre-mdat boxes (moof + emsg/prft/etc) until an mdat
            pre = [typ]
            j = i + 1
            while j < len(boxes) and boxes[j][0] != "mdat":
                pre.append(boxes[j][0])
                j += 1
            if j >= len(boxes):
                break  # dangling moof with no mdat
            mtyp, msize, mhdr, mstart = boxes[j]
            payload_start = mstart + mhdr
            mdat = memoryview(data)[payload_start:payload_start + (msize - mhdr)]
            moof_tree = b.parse_boxes(data, start, start + size)
            moof_box = b.find_child(moof_tree, "moof")
            if moof_box is None:
                raise DecryptError("moof box not cached")
            info = _parse_moof(moof_box, start)
            frags.append(Fragment(
                moof_start=start, moof_info=info, moof=moof_box,
                pre_mdat=pre,
                mdat_header_size=mhdr, mdat_payload_start=payload_start,
                mdat=mdat))
            i = j + 1
        else:
            i += 1
    return init_bytes, frags


# ---------------------------------------------------------------------------
# Sample extraction + decryption
# ---------------------------------------------------------------------------

def _sample_offsets(tinfo: TrafInfo, moof_start: int, mdat_payload_start: int):
    """Compute (offset_in_mdat, size) for every sample of a traf.

    Mirrors mp4ff ``GetFullSamples``: base starts at the moof start position,
    is overridden by tfhd base_data_offset when present, then has each trun's
    data_offset added; sample offsets accumulate their sizes sequentially.
    """
    out = []
    for trun in tinfo.truns:
        base = moof_start
        if tinfo.tfhd_flags & TFHD_BASE_DATA_OFFSET:
            base = tinfo.base_data_offset
        elif tinfo.tfhd_flags & TFHD_DEFAULT_BASE_IS_MOOF:
            base = moof_start
        if trun.flags & TRUN_DATA_OFFSET:
            base += trun.data_offset
        offset_in_mdat = base - mdat_payload_start
        for size in trun.sizes:
            out.append((offset_in_mdat, size))
            offset_in_mdat += size
    return out


def decrypt_fragment(frag: Fragment, init: InitInfo, temari: Temari) -> None:
    """Decrypt a fragment's samples in place (mutates the mdat payload).

    Box removal and ``trun.data_offset`` rewriting happen later, during
    reassembly, exactly as the Go ``DecryptFragment`` does for the cipher step.
    ``temari`` must be freshly initialised from the template that matches this
    fragment's key (see the key-rotation notes on :func:`decrypt_track`).
    """
    for tinfo in frag.moof_info.trafs:
        track = init.tracks.get(tinfo.track_id)
        if track is None:
            raise DecryptError(f"no init track info for track {tinfo.track_id}")
        if not track.encrypted:
            continue
        if track.scheme != "cbcs":
            raise DecryptError(f"unsupported scheme {track.scheme}")
        if tinfo.senc_subsamples is None:
            raise DecryptError(f"no senc box in traf for track {tinfo.track_id}")
        offsets = _sample_offsets(tinfo, frag.moof_info.start_pos,
                                  frag.mdat_payload_start)
        subsamples = tinfo.senc_subsamples
        tenc = track.tenc or Tenc()
        for idx, (off, size) in enumerate(offsets):
            region = frag.mdat[off:off + size]
            pats = subsamples[idx] if idx < len(subsamples) else []
            _decrypt_sample_inplace(region, pats, tenc, temari)


def _decrypt_sample_inplace(region, pats, tenc, temari: Temari):
    if not pats:
        plain = temari.decrypt(bytes(region))
        region[:] = plain
        return
    pos = 0
    for clear, prot in pats:
        pos += clear
        if prot > 0:
            sub = region[pos:pos + prot]
            sub[:] = temari.decrypt(bytes(sub))
            pos += prot


# ---------------------------------------------------------------------------
# Reassembly
# ---------------------------------------------------------------------------

def _strip_encryption_boxes(moof_box: ContainerBox) -> None:
    """Remove encryption boxes (senc/saiz/saio, seig/seam sbgp/sgpd, pssh)
    from a parsed moof tree, in place (mp4ff ``RemoveEncryptionBoxes`` +
    ``MoofBox.RemovePsshs``)."""
    for traf in b.find_children(moof_box.children, "traf"):
        kept = []
        for child in traf.children:
            if isinstance(child, LeafBox) and child.typ in ("senc", "saiz", "saio"):
                continue
            if isinstance(child, LeafBox) and child.typ in ("sbgp", "sgpd"):
                gp = child.payload[4:8].decode("latin1") if len(child.payload) >= 8 else ""
                if gp in ("seig", "seam"):
                    continue
            kept.append(child)
        traf.children = kept
    moof_box.children = [
        c for c in moof_box.children
        if not (isinstance(c, LeafBox) and c.typ == "pssh")
    ]


def _trun_sample_payload_total(trun: LeafBox) -> int:
    """Sum of the per-sample sizes declared by a trun (used to chain trun
    data_offsets within a fragment, as mp4ff ``SetTrunDataOffsets`` does)."""
    payload = trun.payload
    flags = int.from_bytes(payload[1:4], "big")
    n = int.from_bytes(payload[4:8], "big")
    pos = 8
    if flags & TRUN_DATA_OFFSET:
        pos += 4
    if flags & TRUN_FIRST_SAMPLE_FLAGS:
        pos += 4
    total = 0
    for _ in range(n):
        if flags & TRUN_SAMPLE_DURATION:
            pos += 4
        if flags & TRUN_SAMPLE_SIZE:
            total += int.from_bytes(payload[pos:pos + 4], "big")
            pos += 4
        if flags & TRUN_SAMPLE_FLAGS:
            pos += 4
        if flags & TRUN_SAMPLE_CTO:
            pos += 4
    return total


def _set_trun_data_offset_value(trun: LeafBox, value: int) -> None:
    """Ensure a trun has a ``data_offset`` field and set it (in place)."""
    payload = trun.payload
    flags = int.from_bytes(payload[1:4], "big")
    pos = 8
    if flags & TRUN_DATA_OFFSET:
        trun.payload = (payload[:pos] + struct.pack(">i", value)
                        + payload[pos + 4:])
    else:
        # insert a data_offset field right after sample_count and set the flag
        trun.payload = (payload[:1] + ((flags | TRUN_DATA_OFFSET) & 0xffffff).to_bytes(3, "big")
                        + payload[4:8] + struct.pack(">i", value) + payload[8:])


def _set_trun_data_offsets(moof: ContainerBox, mdat_header_size: int) -> None:
    """Recompute each trun's data_offset like mp4ff ``SetTrunDataOffsets``.

    The first data offset is the (re-encoded) moof size plus the mdat header
    size; subsequent truns chain off the previous one's sample data size.

    Because a missing data_offset field is fixed-width (4 bytes), we make it
    present before measuring the moof so the recomputed size is stable.
    """
    truns = []
    for traf in b.find_children(moof.children, "traf"):
        for trun in b.find_children(traf.children, "trun"):
            if isinstance(trun, LeafBox):
                _set_trun_data_offset_value(trun, 0)  # ensure field present
                truns.append(trun)
    data_offset = _box_size(moof) + mdat_header_size
    for trun in truns:
        _set_trun_data_offset_value(trun, data_offset)
        data_offset += _trun_sample_payload_total(trun)


def _fix_tfhd_sample_description(moof: ContainerBox, new_index: int = 1) -> None:
    """Point every traf's ``tfhd`` sample_description_index at the deduped sd.

    The source fragments reference the *second* twin ``alac`` sample entry
    (index 2), but :func:`sanitize_init` deduplicates the twin entries down to
    a single one.  Unless the index is patched to 1, demuxers such as ffmpeg
    fail to resolve the sample entry for fragments that carry an explicit index
    and silently drop all of their samples (symptom: only the first fragment
    decodes)."""
    for traf in b.find_children(moof.children, "traf"):
        tfhd = b.find_child(traf.children, "tfhd")
        if not isinstance(tfhd, LeafBox):
            continue
        payload = tfhd.payload
        if len(payload) < 8:
            continue
        flags = int.from_bytes(payload[1:4], "big")
        if not (flags & TFHD_SAMPLE_DESCRIPTION_INDEX):
            continue
        pos = 8
        if flags & TFHD_BASE_DATA_OFFSET:
            pos += 8
        # sample_description_index is the 4 bytes at pos
        cur = int.from_bytes(payload[pos:pos + 4], "big")
        if cur == new_index:
            continue
        # Patch the value in place (2 -> 1).  The field must stay present and
        # the flag set: removing the field or clearing the flag would shift all
        # subsequent optional fields (default_sample_duration/size) by 4 bytes,
        # corrupting them and breaking per-sample timing for every demuxer.
        tfhd.payload = (payload[:pos] + struct.pack(">I", new_index)
                        + payload[pos + 4:])


def _encode_moof_without_encryption(frag: Fragment) -> bytes:
    """Rebuild a moof with encryption boxes removed and trun.data_offset
    recomputed (matching mp4ff ``Fragment.Encode`` -> ``SetTrunDataOffsets``)."""
    _strip_encryption_boxes(frag.moof)
    _fix_tfhd_sample_description(frag.moof)
    _set_trun_data_offsets(frag.moof, frag.mdat_header_size)
    return b.encode_tree(frag.moof)


def _encode_mdat(frag: Fragment) -> bytes:
    """Write the (decrypted) mdat, preserving the original header size."""
    data = memoryview(frag.mdat).tobytes()
    if frag.mdat_header_size == 16:
        return (struct.pack(">I", 1) + b"mdat"
                + struct.pack(">Q", 16 + len(data)) + data)
    return struct.pack(">I", 8 + len(data)) + b"mdat" + data


def reassemble(init: InitInfo, fragments: List[Fragment], source: bytes) -> bytes:
    """Reassemble a decrypted fMP4 into a standard non-fragmented MP4.

    Produces a single ``moov`` (with populated ``stsz``/``stts``/``stsc``/``stco``
    sample tables) followed by a single ``mdat`` containing all decrypted sample
    data.  This format is compatible with ffmpeg, QuickTime, and most players.
    """
    # Collect all sample sizes from fragments
    all_sizes: List[int] = []
    for frag in fragments:
        for tinfo in frag.moof_info.trafs:
            for trun in tinfo.truns:
                all_sizes.extend(trun.sizes)

    # Build a single mdat payload by concatenating all sample data in order
    mdat_payload = bytearray()
    for frag in fragments:
        tinfo = frag.moof_info.trafs[0]
        offs = _sample_offsets(tinfo, frag.moof_info.start_pos,
                               frag.mdat_payload_start)
        for o, s in offs:
            mdat_payload += memoryview(frag.mdat).tobytes()[o:o + s]

    # Each ALAC frame encodes its sample count; derive stts durations from it
    durations = _alac_frame_samples(mdat_payload, all_sizes)

    # Populate sample tables in the init's moov/stbl
    _patch_sample_tables(init, all_sizes, durations)

    # Rebuild init with populated sample tables; mdat follows
    init_bytes = _encode_init(init)
    # Patch stco with the mdat payload offset (= len(init) + 8-byte mdat header)
    _patch_stco_offset(init, len(init_bytes) + 8)
    init_bytes = _encode_init(init)  # re-encode with correct stco

    mdat_size = 8 + len(mdat_payload)
    mdat = struct.pack(">I", mdat_size) + b"mdat" + bytes(mdat_payload)
    return bytes(init_bytes) + mdat


def _alac_frame_samples(payload: bytes, sizes: List[int]) -> List[int]:
    """Extract each ALAC frame's sample count from its frame header.

    Mirrors FFmpeg's ``alac_decode_frame`` bit parsing: the first 3 bits are
    the element type, followed by a 4-bit instance tag, 12 unused bits, a
    ``has_size`` flag, 2-bit extra_bits and a 1-bit compression flag.  When
    ``has_size`` is set the sample count is a following 32-bit field; otherwise
    it defaults to ``max_samples_per_frame`` (4096) from the codec config.
    """
    counts = []
    pos = 0
    for size in sizes:
        if size < 4:
            counts.append(4096)
            pos += size
            continue
        data = payload[pos:pos + size]
        pos += size
        counts.append(_frame_sample_count(data))
    return counts


def _frame_sample_count(data: bytes) -> int:
    bitpos = 0

    def get(n: int) -> int:
        nonlocal bitpos
        v = 0
        for _ in range(n):
            byte = data[bitpos // 8]
            v = (v << 1) | ((byte >> (7 - (bitpos % 8))) & 1)
            bitpos += 1
        return v

    get(3)   # element type
    get(4)   # element instance tag
    get(12)  # unused header bits
    has_size = get(1)
    get(2)   # extra bits
    get(1)   # compression flag
    if has_size:
        return get(32)
    return 4096  # max_samples_per_frame default


def _patch_sample_tables(init: InitInfo, sizes: List[int],
                         durations: List[int]) -> None:
    """Populate stsz / stts / stsc / stco boxes inside the moov's stbl.

    These boxes are empty in the raw init segment (fMP4 pattern).  We rebuild
    them with the actual sample counts from all fragments so that ffmpeg and
    other demuxers can compute the track duration and index the samples.
    """
    for trak in b.find_children(init.moov.children, "trak"):
        if not isinstance(trak, ContainerBox):
            continue
        mdia = b.find_child(trak.children, "mdia")
        if not isinstance(mdia, ContainerBox):
            continue
        minf = b.find_child(mdia.children, "minf")
        if not isinstance(minf, ContainerBox):
            continue
        stbl = b.find_child(minf.children, "stbl")
        if not isinstance(stbl, ContainerBox):
            continue

        # Capture the media timescale from mdhd for the mvhd conversion
        track_timescale = 0
        mdhd_ts = b.find_child(mdia.children, "mdhd")
        if isinstance(mdhd_ts, LeafBox) and len(mdhd_ts.payload) >= 16:
            ver = mdhd_ts.payload[0]
            ts_off = 20 if ver == 1 else 12
            if len(mdhd_ts.payload) >= ts_off + 4:
                track_timescale = int.from_bytes(
                    mdhd_ts.payload[ts_off:ts_off + 4], "big")

        # Build stts: collapse consecutive same-duration samples (FullBox:
        # version+flags(4) + entry_count(4) + entries(8 each))
        stts_entries = _build_stts(durations)
        stts_payload = b"\x00\x00\x00\x00" + struct.pack(">I", len(stts_entries))
        for count, dur in stts_entries:
            stts_payload += struct.pack(">II", count, dur)
        stts_leaf = LeafBox(typ="stts", header_size=8,
                            size=8 + len(stts_payload),
                            payload=stts_payload)

        # Build stsc: all samples in one chunk (version+flags + entry_count + 12/entry)
        stsc_payload = b"\x00\x00\x00\x00" + struct.pack(">I", 1)
        stsc_payload += struct.pack(">III", 1, len(sizes), 1)  # chunk 1, N samples, sdidx 1
        stsc_leaf = LeafBox(typ="stsc", header_size=8,
                            size=8 + len(stsc_payload),
                            payload=stsc_payload)

        # Build stsz (version+flags + sample_size + sample_count + sizes)
        stsz_payload = b"\x00\x00\x00\x00" + struct.pack(">I", 0)  # default_size=0
        stsz_payload += struct.pack(">I", len(sizes))
        for s in sizes:
            stsz_payload += struct.pack(">I", s)
        stsz_leaf = LeafBox(typ="stsz", header_size=8,
                            size=8 + len(stsz_payload),
                            payload=stsz_payload)

        # Build stco (version+flags + entry_count + offsets)
        stco_payload = b"\x00\x00\x00\x00" + struct.pack(">I", 1)
        stco_payload += struct.pack(">I", 0)  # placeholder offset, patched later
        stco_leaf = LeafBox(typ="stco", header_size=8,
                            size=8 + len(stco_payload),
                            payload=stco_payload)

        # Replace stts/stsc/stsz/stco in stbl
        new_children = []
        for child in stbl.children:
            if isinstance(child, LeafBox) and child.typ in ("stts", "stsc", "stsz", "stco"):
                continue
            new_children.append(child)
        new_children.extend([stts_leaf, stsc_leaf, stsz_leaf, stco_leaf])
        stbl.children = new_children

        # Set the track media duration (mdhd duration = total samples)
        mdhd = b.find_child(mdia.children, "mdhd")
        if isinstance(mdhd, LeafBox) and len(mdhd.payload) >= 20:
            total = sum(durations)
            payload = mdhd.payload
            ver = payload[0]
            # ver 0: duration at [16:20]; ver 1: duration at [24:32]
            off = 24 if ver == 1 else 16
            width = 8 if ver == 1 else 4
            if len(payload) >= off + width:
                mdhd.payload = (payload[:off] + total.to_bytes(width, "big")
                                + payload[off + width:])

    _patch_mvhd_duration(init, sum(durations), track_timescale or 48000)


def _media_timescale(init: InitInfo, track_id: Optional[int] = None) -> int:
    """Return the media timescale (from mdhd) for a track, defaulting to
    48000 if it cannot be determined."""
    for trak in b.find_children(init.moov.children, "trak"):
        if not isinstance(trak, ContainerBox):
            continue
        if track_id is not None and _find_track_id(trak) != track_id:
            continue
        mdia = b.find_child(trak.children, "mdia")
        if not isinstance(mdia, ContainerBox):
            continue
        mdhd = b.find_child(mdia.children, "mdhd")
        if isinstance(mdhd, LeafBox) and len(mdhd.payload) >= 16:
            ver = mdhd.payload[0]
            ts_off = 20 if ver == 1 else 12
            if len(mdhd.payload) >= ts_off + 4:
                return int.from_bytes(mdhd.payload[ts_off:ts_off + 4], "big")
    return 48000


def _set_mdhd_duration(init: InitInfo, media_samples: int) -> None:
    """Set each track's ``mdhd`` duration to the total media samples."""
    for trak in b.find_children(init.moov.children, "trak"):
        if not isinstance(trak, ContainerBox):
            continue
        mdia = b.find_child(trak.children, "mdia")
        if not isinstance(mdia, ContainerBox):
            continue
        mdhd = b.find_child(mdia.children, "mdhd")
        if not isinstance(mdhd, LeafBox) or len(mdhd.payload) < 20:
            continue
        payload = mdhd.payload
        ver = payload[0]
        off = 24 if ver == 1 else 16
        width = 8 if ver == 1 else 4
        if len(payload) >= off + width:
            mdhd.payload = (payload[:off]
                            + media_samples.to_bytes(width, "big")
                            + payload[off + width:])


def _patch_fragment_duration(init: InitInfo, media_samples: int) -> None:
    """Set ``mdhd`` + ``mvhd`` durations so players (ffmpeg) report and
    decode the full track length.

    Fragmented streams normally leave these at 0, but ffmpeg's mov demuxer
    uses them to know the movie length and otherwise stops decoding after the
    first fragment.  ``media_samples`` is the total across all fragments,
    expressed in the media timescale."""
    _set_mdhd_duration(init, media_samples)
    _patch_mvhd_duration(init, media_samples, _media_timescale(init))


def _patch_mvhd_duration(init: InitInfo, media_samples: int,
                         media_timescale: int) -> None:
    """Set the moov movie duration from the media track's total samples.

    ``mvhd`` duration is expressed in the movie timescale; convert from the
    media timescale so players/reporters show the true duration."""
    mvhd = b.find_child(init.moov.children, "mvhd")
    if not isinstance(mvhd, LeafBox) or len(mvhd.payload) < 20:
        return
    payload = mvhd.payload
    ver = payload[0]
    if ver == 1:
        # version 1: creation(8) ... timescale starts at offset 20
        if len(payload) < 32:
            return
        movie_timescale = int.from_bytes(payload[20:24], "big")
        if movie_timescale:
            duration = int(media_samples / media_timescale * movie_timescale)
            mvhd.payload = (payload[:24] + struct.pack(">Q", duration)
                            + payload[32:])
    else:
        # version 0: creation(4) modification(4) timescale(4) duration(4)
        if len(payload) < 24:
            return
        movie_timescale = int.from_bytes(payload[12:16], "big")
        if movie_timescale:
            duration = int(media_samples / media_timescale * movie_timescale)
            mvhd.payload = payload[:16] + struct.pack(">I", duration) + payload[20:]


def _patch_stco_offset(init: InitInfo, mdat_payload_offset: int) -> None:
    """Set the stco chunk offset to the mdat payload start position."""
    for trak in b.find_children(init.moov.children, "trak"):
        if not isinstance(trak, ContainerBox):
            continue
        mdia = b.find_child(trak.children, "mdia")
        if not isinstance(mdia, ContainerBox):
            continue
        minf = b.find_child(mdia.children, "minf")
        if not isinstance(minf, ContainerBox):
            continue
        stbl = b.find_child(minf.children, "stbl")
        if not isinstance(stbl, ContainerBox):
            continue
        stco = b.find_child(stbl.children, "stco")
        if stco is None or not isinstance(stco, LeafBox):
            continue
        payload = stco.payload
        # stco is a FullBox: version+flags(4) + entry_count(4) + offset(4)
        if len(payload) >= 12:
            stco.payload = payload[:8] + struct.pack(">I", mdat_payload_offset) + payload[12:]


def _build_stts(durations: List[int]) -> List[tuple]:
    """Build stts entries by collapsing consecutive same-duration samples."""
    if not durations or all(d == 0 for d in durations):
        return []
    entries = []
    cur_dur = durations[0]
    cur_count = 1
    for d in durations[1:]:
        if d == cur_dur:
            cur_count += 1
        else:
            entries.append((cur_count, cur_dur))
            cur_dur = d
            cur_count = 1
    entries.append((cur_count, cur_dur))
    return entries


def _original_box(source: bytes, frag: Fragment, typ: str) -> bytes:
    """Slice the original on-disk bytes of a pre-mdat box type within frag."""
    pos = frag.moof_start
    moof_size = struct.unpack_from(">I", source, pos)[0]
    pos += moof_size
    end = frag.mdat_payload_start
    while pos + 8 <= end:
        size = struct.unpack_from(">I", source, pos)[0]
        t = source[pos + 4:pos + 8].decode("latin1")
        if t == typ:
            return bytes(source[pos:pos + size])
        pos += size
    return b""


def _encode_init(init: InitInfo) -> bytes:
    return b"".join(b.encode_tree(c) for c in init.tree)


def _box_size(node) -> int:
    if isinstance(node, LeafBox):
        return node.header_size + len(node.payload)
    if isinstance(node, ContainerBox):
        return 8 + sum(_box_size(c) for c in node.children)
    return 0


def decrypt_track(encrypted_bytes: bytes, key_jsons) -> bytes:
    """Decrypt a full encrypted fMP4 track given the lite-server ``/key`` JSON.

    ``key_jsons`` may be:

    * a ``str``/``bytes`` JSON document, or the raw dict from
      ``LiteClient.key_template`` -- used for *every* fragment (the common
      single-key case), or
    * a sequence of such values, one per fragment, letting a track with key
      rotation (multiple ``#EXT-X-KEY`` URIs) decrypt each fragment with its own
      template.  The caller derives this from the media playlist's per-segment
      keys; each fragment is a fresh Temari built from the matching template.

    Each fragment is decrypted with a fresh Temari handle built from its own
    template, because a template's internal state advances while decrypting and
    fragments may carry different keys.
    """
    import json as _json

    def _normalise(k):
        if isinstance(k, dict):
            return _json.dumps(k)
        if isinstance(k, (bytes, bytearray)):
            return bytes(k).decode("utf-8")
        return k

    if isinstance(key_jsons, (str, bytes, bytearray, dict)):
        key_jsons = [_normalise(key_jsons)]
    else:
        key_jsons = [_normalise(k) for k in key_jsons]

    init_bytes, fragments = split_fragments(encrypted_bytes)
    if not fragments:
        raise DecryptError("no fragments (moof+mdat) found in stream")
    if len(key_jsons) == 1:
        key_jsons = key_jsons * len(fragments)
    if len(key_jsons) != len(fragments):
        raise DecryptError(
            f"expected {len(fragments)} key templates, got {len(key_jsons)}")
    init = InitInfo(init_bytes)
    sanitize_init(init)
    for frag, kjson in zip(fragments, key_jsons):
        with Temari.from_json(kjson) as temari:
            decrypt_fragment(frag, init, temari)
    return reassemble(init, fragments, encrypted_bytes)


def _fragment_media_samples(fragments: List[Fragment]) -> int:
    """Total media samples across all fragments, expressed in the media
    timescale.

    Computed from the decode times without decrypting: the track's total
    duration is the last fragment's ``tfdt`` base decode time plus that
    fragment's summed sample durations.  Falls back to the plain sum of every
    trun's sample durations if no ``tfdt`` is present."""
    last = fragments[-1]
    for tinfo in last.moof_info.trafs:
        # last fragment's tfdt (baseMediaDecodeTime) from the moof tree
        tfdt_leaf = None
        for traf in b.find_children(last.moof.children, "traf"):
            tfdt = b.find_child(traf.children, "tfdt")
            if isinstance(tfdt, LeafBox) and len(tfdt.payload) >= 8:
                tfdt_leaf = tfdt
                break
        if tfdt_leaf is not None:
            payload = tfdt_leaf.payload
            ver = payload[0]
            base = (int.from_bytes(payload[4:12], "big")
                    if ver == 1 else int.from_bytes(payload[4:8], "big"))
            last_dur = sum(d for trun in tinfo.truns for d in trun.durations)
            return base + last_dur
    return sum(d for frag in fragments
               for tinfo in frag.moof_info.trafs
               for trun in tinfo.truns for d in trun.durations)


def decrypt_track_streaming(encrypted_bytes, key_jsons):
    """Streaming variant of :func:`decrypt_track`.

    Yields ``bytes`` chunks that together form an fMP4 stream (init segment
    followed by ``moof``+``mdat`` pairs).  Unlike :func:`decrypt_track` this
    never reassembles into a single-mdat MP4, so each fragment is emitted as
    soon as it is decrypted — keeping peak memory to roughly one fragment
    rather than the full output.

    The init ``moov`` is emitted with its ``mdhd``/``mvhd`` durations set to
    the total across all fragments: without this, demuxers such as ffmpeg stop
    decoding after the first fragment, truncating the track to a single
    fragment's length.

    Callers must send HTTP ``Transfer-Encoding: chunked`` (or equivalent)
    because the total ``Content-Length`` is not known up front.
    """
    import json as _json

    def _normalise(k):
        if isinstance(k, dict):
            return _json.dumps(k)
        if isinstance(k, (bytes, bytearray)):
            return bytes(k).decode("utf-8")
        return k

    if isinstance(key_jsons, (str, bytes, bytearray, dict)):
        key_jsons = [_normalise(key_jsons)]
    else:
        key_jsons = [_normalise(k) for k in key_jsons]

    init_bytes, fragments = split_fragments(encrypted_bytes)
    if not fragments:
        raise DecryptError("no fragments (moof+mdat) found in stream")
    if len(key_jsons) == 1:
        key_jsons = key_jsons * len(fragments)
    if len(key_jsons) != len(fragments):
        raise DecryptError(
            f"expected {len(fragments)} key templates, got {len(key_jsons)}")

    init = InitInfo(init_bytes)
    sanitize_init(init)
    _patch_fragment_duration(init, _fragment_media_samples(fragments))
    yield b"".join(b.encode_tree(c) for c in init.tree)

    for frag, kjson in zip(fragments, key_jsons):
        with Temari.from_json(kjson) as temari:
            decrypt_fragment(frag, init, temari)
        yield _encode_moof_without_encryption(frag)
        yield _encode_mdat(frag)
