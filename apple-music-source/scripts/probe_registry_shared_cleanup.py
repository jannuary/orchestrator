"""Synthetic mode-3 shared-state research; no package completion claim.

Uses an explicit deterministic test clock and null locks. A mapped counter cell
prevents a null application pointer from resolving into the base-zero ELF.
Timer/rate-limit fields are invented, not a validated constructor fixture.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

from trace_registry_release import trace
from verify_integrity_codec import HASH


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('core_elf', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args(); image = args.core_elf.read_bytes()
    assert hashlib.sha256(image).hexdigest() == HASH
    seed = 0x12345678 ^ 0x678086cb
    clock_key = seed ^ 0x25da2183ec893e97
    record = bytearray(336); record[244] = 15; record[300] = 3
    cases = []
    for refs in (0, 1, 2, 255, 256, 65536, 0xffffffff):
        for timestamp in (0, 12344, 12345, 12346):
            shared = bytearray(256)
            struct.pack_into('<I', shared, 32, (0x5fd2b496 + refs) & 0xffffffff)
            struct.pack_into('<Q', shared, 56, clock_key ^ timestamp)
            struct.pack_into('<Q', shared, 8, 0x301e000)
            cell = (seed ^ 0x47ef675e13e3af4a).to_bytes(8, 'little')
            after = []
            result = trace(image, 1023, True, kind=15, payload=record,
                           stop_owned=False, cleanup_return_state=8,
                           execute_helpers=True, shared_state=shared,
                           observe_shared=after.append, clock_sample=(12345, 0),
                           heap_blocks={0x301e000: cell})
            assert not result['error'] and not result['faults']
            assert result['events'][-1]['event'] == 'final_helper_returned'
            decoded_refs = (struct.unpack_from('<I', after[0], 32)[0] - 0x5fd2b496) & 0xffffffff
            assert decoded_refs == (refs - 1 if refs else 0)
            decoded_timestamp = struct.unpack_from('<Q', after[0], 56)[0] ^ clock_key
            assert decoded_timestamp == (12345 if timestamp == 0 else timestamp)
            cases.append(dict(references=refs, timestamp=timestamp, reference_relation=True,
                              timestamp_relation=True, generation_cleared=result['tag_cleared']))
    # Negative control: a missing pool pointer must not read the mapped ELF header.
    struct.pack_into('<Q', shared, 8, 0)
    result = trace(image, 1023, True, kind=15, payload=record,
                   stop_owned=False, cleanup_return_state=8, execute_helpers=True,
                   shared_state=shared, clock_sample=(12345, 0))
    assert any(f.get('reason') == 'null/low application data pointer' for f in result['faults'])
    report = dict(status='research only', oracle_sha256=HASH, cases=cases,
                  null_pool_negative_control=True,
                  scope='invented shared timer/rate-limit fields and deterministic test clock; null locks only; native mode-3 API remains guarded; no constructor, synchronization, expiry, successful crypto/auth or full shared-state equivalence proof')
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(dict(status=report['status'], cases=len(cases), null_pool_negative_control=True, scope=report['scope'])))


if __name__ == '__main__':
    main()
