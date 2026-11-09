"""Original-ELF comparison of owned buffers using an explicit test allocator.

Records and allocations are invented. Original helper dispatch executes; only
the imported void free is replaced by a lifetime-tracking allocator. Bytes stay
mapped after release solely to compare overwrite effects in RAM.
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


class Registry(C.Structure):
    _fields_ = [('generation', C.c_uint32 * 1024)]


class Buffer(C.Structure):
    _fields_ = [('address', C.c_uint64), ('data', C.c_void_p), ('size', C.c_size_t)]


Free = C.CFUNCTYPE(None, C.c_void_p, C.c_uint64)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('core_elf', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    image = args.core_elf.read_bytes()
    assert hashlib.sha256(image).hexdigest() == HASH
    native = Path(__file__).resolve().parents[1] / 'src/apple_music_source/_native'
    rng = random.Random(0x1b7617)
    lengths = [0, 1, 2, 7, 8, 15, 16, 17, 31, 32, 63, 64, 65, 127, 128, 129, 255, 256]
    count = frees = overwritten = 0
    with tempfile.TemporaryDirectory(prefix='ams-owned-') as temporary:
        library = Path(temporary) / 'registry.so'
        subprocess.run(['cc', '-std=c99', '-O2', '-Wall', '-Wextra', '-Werror',
                        '-shared', '-fPIC', str(native / 'registry.c'), '-o', str(library)], check=True)
        release = C.CDLL(str(library)).ams_registry_release_buffers
        release.argtypes = [C.POINTER(Registry), C.c_size_t, C.c_void_p, C.c_size_t,
                            C.c_uint64, C.POINTER(Buffer), Free, C.c_void_p]
        for mask in range(16):
            for length in lengths:
                payload = bytearray(rng.randbytes(336)); payload[244] = 15; payload[0x12c] = 2
                addresses = [0x3010000 + i * 0x400 for i in range(4)]
                heap = {}; views = (Buffer * 4)(); storage = {}
                for i, offset in enumerate((0x110, 0xb8, 0xc8, 0x130)):
                    present = bool(mask & (1 << i))
                    struct.pack_into('<Q', payload, offset, addresses[i] if present else 0)
                    if present:
                        data = rng.randbytes(320)
                        heap[addresses[i]] = data
                        storage[addresses[i]] = C.create_string_buffer(data)
                        views[i] = Buffer(addresses[i], C.cast(storage[addresses[i]], C.c_void_p), len(data))
                struct.pack_into('<I', payload, 0xd0, (0x193931bf + length) & 0xffffffff)
                frame = 0x1008000 + (count % 128) * 16
                records = []; heaps = []
                original = trace(image, 1023, True, kind=15, payload=payload,
                                 seed=rng.getrandbits(32), stop_owned=False,
                                 cleanup_return_state=8, frame_address=frame,
                                 execute_helpers=True, heap_blocks=heap,
                                 observe_record=records.append, observe_heap=heaps.append)
                assert not original['faults'] and not original['error'], original
                assert original['events'][-1]['event'] == 'final_helper_returned', original
                registry = Registry(); registry.generation[1023] = 2047
                record = C.create_string_buffer(bytes(payload)); calls = []
                @Free
                def free(_opaque, address):
                    calls.append(address)
                assert release(C.byref(registry), 1023, record, 336, frame - 0x3048,
                               views, free, None) == 0
                assert record.raw[:336] == records[0], (mask, length)
                assert registry.generation[1023] == 0 and original['tag_cleared']
                assert original['reencoded_pointer_consistent']
                assert calls == original['allocator_frees'] == [a for a in addresses if a in heap]
                for address, data in heap.items():
                    assert storage[address].raw[:len(data)] == heaps[0][address], (mask, length, address)
                count += 1; frees += len(calls)
                if mask & 4: overwritten += length
    report = dict(status='pass', oracle_sha256=HASH, comparisons=count,
                  allocator_releases=frees, requested_overwrite_bytes=overwritten,
                  presence_combinations=16, lengths=lengths,
                  relation='all logical record bytes, every mapped buffer byte, generation clear, encoded pointer consistency, allocator release order',
                  scope='synthetic records; original helper dispatch with explicit test free allocator; null final unlock helper executes; mode-3 shared state, non-null locking, worker expiry, instruction budgets and successful crypto/auth unproved')
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report))


if __name__ == '__main__':
    main()
