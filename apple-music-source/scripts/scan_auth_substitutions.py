"""Classify pinned native-auth readonly words, keeping all maps/data in RAM.

Developer oracle only. An aligned candidate or inversion-family match is not
proof of live use, authentication semantics, or a replacement implementation.
"""
import argparse
import ctypes as C
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys
import tempfile

from probe_substitution_equivalence import SEARCH, investigate
from scan_substitution_tables import SCAN


TARGETS = {
    'coreadi': ('libCoreADI.so', 'b5b971cea0bbe828bdcfaf219fd91fc1e37cf8daee84001ef917d0b1c2b985ed'),
    'corefp': ('libCoreFP.so', 'cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175'),
    'storeservices': ('libstoreservicescore.so', '6238261363d7943f1a0a27116b52544831f3e295e8533a634641fe5b09d92c7e'),
}


def readonly_segments(image, alignment=16):
    assert alignment in (4, 16)
    assert image[:6] == b'\x7fELF\x02\x01'
    phoff = struct.unpack_from('<Q', image, 32)[0]
    phsize, phcount = struct.unpack_from('<HH', image, 54)
    assert phsize >= 56 and phoff + phsize * phcount <= len(image)
    result = []
    for index in range(phcount):
        kind, flags, offset, address, _, size, _, _ = struct.unpack_from('<IIQQQQQQ', image, phoff + index * phsize)
        if kind != 1 or flags & 3 or not flags & 4:
            continue
        assert offset + size <= len(image)
        start = (-address) % alignment
        result.append((address + start, image[offset + start:offset + size]))
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout', type=Path)
    parser.add_argument('--target', choices=TARGETS, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--limit', type=int, default=0, help='Zero attempts all aligned candidates')
    parser.add_argument('--alignment', type=int, choices=(4,16), default=16, help='Candidate base alignment; four includes minimally aligned uint32 arrays')
    args = parser.parse_args()
    assert args.limit >= 0
    name, digest = TARGETS[args.target]
    image = (args.checkout / 'rootfs/system/lib64' / name).read_bytes()
    assert hashlib.sha256(image).hexdigest() == digest
    segments = readonly_segments(image,args.alignment)
    sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'src'))
    from apple_music_source.crypto.aes import _gpow
    inverse = (C.c_uint8 * 256)(*(_gpow(x, 254) if x else 0 for x in range(256)))
    rows = []
    with tempfile.TemporaryDirectory(prefix='ams-auth-substitution-scan-') as temporary:
        source, library = Path(temporary) / 'scan.c', Path(temporary) / 'scan.so'
        assert SCAN.count('start+=16')==1
        source.write_text(SEARCH + SCAN.replace('start+=16','start+='+str(args.alignment)))
        subprocess.run(['cc', '-std=c99', '-O3', '-shared', '-fPIC', str(source), '-o', str(library)], check=True, capture_output=True)
        native = C.CDLL(str(library))
        scan, search = native.scan_candidates, native.equivalent
        scan.argtypes = [C.POINTER(C.c_uint8), C.c_size_t, C.POINTER(C.c_uint32), C.c_size_t]
        scan.restype = C.c_int
        search.argtypes = [C.POINTER(C.c_uint8), C.POINTER(C.c_uint8), C.POINTER(C.c_uint64), C.POINTER(C.c_uint8), C.POINTER(C.c_uint8)]
        search.restype = C.c_int
        candidates = []
        for address, data in segments:
            buffer = (C.c_uint8 * len(data)).from_buffer_copy(data)
            offsets = (C.c_uint32 * (len(data) // 16 + 1))()
            count = scan(buffer, len(data), offsets, len(offsets))
            assert count >= 0
            candidates.extend((address + offset, data[offset:offset + 1024]) for offset in offsets[:count])
        selected = candidates[:args.limit] if args.limit else candidates
        for address, data in selected:
            words = [int.from_bytes(data[offset:offset + 4], 'little') for offset in range(0, 1024, 4)]
            rows.append(dict(elf_virtual_address=hex(address), **investigate(words, search, inverse)))
    report = dict(status='bounded native-auth readonly substitution classification', target=args.target,
        artifact_sha256=digest, readonly_bytes=sum(len(data) for _, data in segments),
        readonly_segments=[dict(elf_virtual_address=hex(address), bytes=len(data)) for address, data in segments],
        alignment=args.alignment, window_bytes=1024, candidate_windows=len(candidates), attempted_windows=len(rows),
        exact_inversion_family_windows=sum(row.get('affine_equivalent_to_gf256_inversion', False) for row in rows),
        rows=rows,
        scope='aligned readonly affine-rank-eight word windows only; no reachability, live use, native-auth implementation or source-owned parameter claim; all data/maps RAM-only')
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({key: value for key, value in report.items() if key != 'rows'}))


if __name__ == '__main__':
    main()
