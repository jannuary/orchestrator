"""Original-ELF differential for canonical shared-mode record release.

Invented objects, independent representation seeds, bounded allocator, explicit
test clock, null locks. Compares logical effects, not concurrency or acquisition.
"""
import argparse
import ctypes as C
import hashlib
import json
from pathlib import Path
import random
import struct
import subprocess
import tempfile

from trace_registry_release import trace
from verify_integrity_codec import HASH
from verify_registry_owned_buffers import Registry, Buffer, Free


class Shared(C.Structure):
    _fields_ = [('references', C.c_uint32), ('timestamp', C.c_uint64),
                ('baseline', C.c_uint64), ('counter', C.c_uint64)]


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('core_elf', type=Path); p.add_argument('--output', type=Path, required=True)
    args = p.parse_args(); image = args.core_elf.read_bytes()
    assert hashlib.sha256(image).hexdigest() == HASH
    native = Path(__file__).resolve().parents[1] / 'src/apple_music_source/_native'
    rng = random.Random(0x24b568); u64 = (1 << 64) - 1
    counts = dict(shared_cases=0, absent_shared_cases=0, clock_failure_cases=0, allocator_releases=0)
    with tempfile.TemporaryDirectory(prefix='ams-shared-') as temp:
        library = Path(temp) / 'registry.so'
        subprocess.run(['cc', '-std=c99', '-O2', '-Wall', '-Wextra', '-Werror', '-shared', '-fPIC',
                        str(native / 'registry.c'), '-o', str(library)], check=True)
        release = C.CDLL(str(library)).ams_registry_release_shared
        release.argtypes = [C.POINTER(Registry), C.c_size_t, C.c_void_p, C.c_size_t, C.c_uint64,
                            C.POINTER(Buffer), Free, C.c_void_p, C.POINTER(Shared), C.c_uint64]
        for case in range(328):
            absent = 256 <= case < 320; clock_failure = case >= 320; mask = case % 16
            seeds = [rng.getrandbits(64) for _ in range(3)]
            time_key = (seeds[1] & (u64 >> 1)) ^ 0x25da2183ec893e97
            counter_key = (seeds[2] & (u64 >> 1)) ^ 0x47ef675e13e3af4a
            now = rng.choice([0, 1, u64 >> 1, 1 << 63, u64, rng.getrandbits(64)])
            if clock_failure: now = 0
            last = rng.choice([0, now, (now - 1) & u64, (now + 1) & u64, rng.getrandbits(64)])
            baseline = rng.choice([0, u64, rng.getrandbits(64)])
            current = rng.choice([baseline, (baseline - 1) & u64, (baseline + 1) & u64, rng.getrandbits(64)])
            refs = rng.choice([0, 1, 2, 255, 256, 65536, 0xffffffff])
            canonical = Shared(refs, last, baseline, current)
            shared = bytearray(rng.randbytes(256))
            struct.pack_into('<Q', shared, 0, 0); struct.pack_into('<Q', shared, 24, 0)
            struct.pack_into('<Q', shared, 8, 0x301e000)
            struct.pack_into('<Q', shared, 16, counter_key ^ baseline)
            struct.pack_into('<I', shared, 32, (0x5fd2b496 + refs) & 0xffffffff)
            struct.pack_into('<Q', shared, 56, time_key ^ last)
            payload = bytearray(rng.randbytes(336)); payload[244] = 15; payload[300] = 3
            heap = {}; storage = {}; views = (Buffer * 4)()
            for i, offset in enumerate((0x110, 0xb8, 0xc8, 0x130)):
                address = 0x3010000 + i * 0x400 if mask & (1 << i) else 0
                struct.pack_into('<Q', payload, offset, address)
                if address:
                    data = rng.randbytes(128); heap[address] = data
                    storage[address] = C.create_string_buffer(data)
                    views[i] = Buffer(address, C.cast(storage[address], C.c_void_p), len(data))
            struct.pack_into('<I', payload, 208, 0x193931bf + case % 129)
            if not absent: heap[0x301e000] = (counter_key ^ current).to_bytes(8, 'little')
            records = []; heaps = []; states = []
            frame = 0x1008000 + case % 128 * 16
            original = trace(image, 1023, True, kind=15, payload=payload,
                             seed=rng.getrandbits(32), stop_owned=False, cleanup_return_state=8,
                             execute_helpers=True, heap_blocks=heap, frame_address=frame,
                             shared_state=b'' if absent else shared, clock_sample=(now if now < 1 << 63 else now - (1 << 64), 0),
                             clock_status=-1 if clock_failure else 0,
                             selector_value=0xf8, seed_words={0xc0: seeds[0], 0x18: seeds[1], 0xe8: seeds[2]},
                             observe_record=records.append, observe_heap=heaps.append, observe_shared=states.append)
            assert not original['error'] and not original['faults'], (case, original)
            assert original['events'][-1]['event'] == 'final_helper_returned', (case, original)
            registry = Registry(); registry.generation[1023] = 2047
            record = C.create_string_buffer(bytes(payload)); calls = []
            @Free
            def free(_opaque, address): calls.append(address)
            assert release(C.byref(registry), 1023, record, 336, frame - 0x3048,
                           views, free, None, None if absent else C.byref(canonical), now) == 0
            assert record.raw[:336] == records[0], case
            assert not registry.generation[1023] and original['tag_cleared']
            assert original['reencoded_pointer_consistent']
            assert calls == original['allocator_frees'] == list(storage)
            for address, data in storage.items():
                assert data.raw[:128] == heaps[0][address], (case, address)
            if not absent:
                expected_shared = bytearray(shared)
                struct.pack_into('<I', expected_shared, 32, (canonical.references + 0x5fd2b496) & 0xffffffff)
                struct.pack_into('<Q', expected_shared, 56, canonical.timestamp ^ time_key)
                assert bytes(expected_shared) == states[0], case
                assert canonical.counter ^ counter_key == int.from_bytes(heaps[0][0x301e000], 'little'), case
                assert canonical.baseline == baseline
            counts['absent_shared_cases' if absent else 'shared_cases'] += 1
            counts['clock_failure_cases'] += int(clock_failure)
            counts['allocator_releases'] += len(calls)
    report = dict(status='pass', oracle_sha256=HASH, **counts,
                  relation='all logical record/buffer/shared bytes, references, timestamp, counter, generation and release order; independent 64-bit representation seeds; absent object; unsigned wrap/backward/equal/initial clocks',
                  scope='bounded decoded release with caller-held locks; original dispatch, explicit test free allocator/clock and null lock helpers; no concurrency/worker expiry, constructor validity, complete instruction state or successful crypto/auth proof')
    args.output.write_text(json.dumps(report, indent=2) + '\n'); print(json.dumps(report))


if __name__ == '__main__': main()
