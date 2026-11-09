"""Differential canonical generation registry against the pinned original ELF.

Invented generation arrays only. The oracle executes the occupied-slot and full
paths absent from native_generated. Comparisons are at semantic probe/operation
boundaries, NOT complete x86 state, arbitrary aliases, faults or step budgets.
No record codec, bank or successful crypto session is replaced by this test.
"""
import argparse
import ctypes as C
import hashlib
import json
from pathlib import Path
import random
import struct
import subprocess
import sys
import tempfile

sys.path.insert(0, str(Path(__file__).resolve().parent))
from verify_integrity_codec import HASH

N = 1024
MASK = 0xffffffff
TAG = 0x69cad980


class Registry(C.Structure):
    _fields_ = [('generation', C.c_uint32 * N)]


class Search(C.Structure):
    _fields_ = [(n, C.c_uint32) for n in ('candidate', 'probes', 'slot', 'handle', 'status')]


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('core_elf', type=Path)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    raw = a.core_elf.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == HASH
    from unicorn import Uc, UC_ARCH_X86, UC_MODE_64, UC_HOOK_CODE
    from unicorn import x86_const as x
    mu = Uc(UC_ARCH_X86, UC_MODE_64)
    mu.mem_map(0, 0x700000)
    mu.mem_write(0, raw)
    mu.mem_map(0x1000000, 0x10000)
    mu.mem_map(0x3000000, 0x1000)
    frame, tags = 0x1009000, 0x3000000
    regs = [getattr(x, 'UC_X86_REG_' + n) for n in
            'RAX RBX RCX RDX RSI RDI RBP RSP R8 R9 R10 R11 R12 R13 R14 R15'.split()]
    visited, stop_after = [0], [None]

    def head(_mu, _pc, _size, _user):
        if stop_after[0] is not None and visited[0] == stop_after[0]:
            mu.emu_stop()
        else:
            visited[0] += 1

    # Install before translating any blocks. Repeated add/remove can leave
    # already translated Unicorn blocks without the newly added head hook.
    mu.hook_add(UC_HOOK_CODE, head, begin=0x1f7300, end=0x1f7300)

    def prepare(gens):
        for r in regs:
            mu.reg_write(r, 0)
        mu.reg_write(x.UC_X86_REG_EFLAGS, 0x202)
        mu.reg_write(x.UC_X86_REG_RBP, frame)
        mu.reg_write(x.UC_X86_REG_RSP, frame - 0x6000)
        mu.mem_write(tags, struct.pack('<1024I', *((g + TAG) & MASK for g in gens)))
        mu.mem_write(frame - 0x1158, struct.pack('<Q', tags))

    def generations():
        return [(g - TAG) & MASK for g in struct.unpack('<1024I', mu.mem_read(tags, 4096))]

    def allocate(gens, candidate, quota=None):
        prepare(gens)
        mu.reg_write(x.UC_X86_REG_RCX, candidate)
        mu.reg_write(x.UC_X86_REG_RDX, tags)
        mu.reg_write(x.UC_X86_REG_R12, 0x7350)
        mu.reg_write(x.UC_X86_REG_R15, 8)
        mu.reg_write(x.UC_X86_REG_R14, 0x7d85d950)
        mu.reg_write(x.UC_X86_REG_R9, 0x1f7300)
        mu.reg_write(x.UC_X86_REG_R8, 0x1f736a)
        mu.mem_write(frame - 0x196c, struct.pack('<I', candidate))
        mu.mem_write(frame - 0x2078, struct.pack('<I', 0xfaceb00c))
        visited[0], stop_after[0] = 0, quota
        mu.emu_start(0x1f7300, 0x2079d4, count=100000)
        pc = mu.reg_read(x.UC_X86_REG_RIP)
        assert pc in (0x1f7300, 0x2079d4)
        occupied = mu.reg_read(x.UC_X86_REG_R14) - 0x7d85d950
        counter = int.from_bytes(mu.mem_read(frame - 0x196c, 4), 'little')
        handle = int.from_bytes(mu.mem_read(frame - 0x2078, 4), 'little')
        status = 1 if pc == 0x1f7300 else 2 if occupied == N else 0
        probes = occupied if status else occupied + 1
        return status, counter, handle, probes, generations()

    native = Path(__file__).resolve().parents[1] / 'src/apple_music_source/_native'
    rng = random.Random(0xa110ca7e)
    with tempfile.TemporaryDirectory(prefix='ams-registry-allocator-') as temporary:
        libpath = Path(temporary) / 'registry.so'
        subprocess.run(['cc', '-std=c99', '-O2', '-Wall', '-Wextra', '-Werror',
                        '-shared', '-fPIC', str(native / 'registry.c'), '-o', str(libpath)], check=True)
        lib = C.CDLL(str(libpath))
        lib.ams_registry_search_begin.argtypes = [C.POINTER(Search), C.c_uint32]
        lib.ams_registry_reserve.argtypes = [C.POINTER(Registry), C.POINTER(Search), C.c_size_t]
        lib.ams_registry_tag_matches.argtypes = [C.POINTER(Registry), C.c_uint32]
        allocations = resumptions = validations = 0

        def check(gens, candidate, quotas=(N,)):
            nonlocal allocations, resumptions
            registry, search = Registry(), Search()
            registry.generation[:] = gens
            lib.ams_registry_search_begin(C.byref(search), candidate)
            total = 0
            for quota in quotas:
                status = lib.ams_registry_reserve(C.byref(registry), C.byref(search), quota)
                total += quota
                expected = allocate(gens, candidate, min(total, N) if status == 1 else None)
                assert (status, search.candidate, search.probes, list(registry.generation)) == (
                    expected[0], expected[1], expected[3], expected[4]), (
                        'invented scalar case', candidate, quota, total, status,
                        search.candidate, search.probes, expected[:4])
                if status == 0:
                    assert search.handle == expected[2]
                    assert search.slot == (search.candidate & 1023)
                else:
                    assert expected[2] == 0xfaceb00c
                allocations += 1
                if len(quotas) > 1:
                    resumptions += 1
                if status != 1:
                    break
            return registry, search

        # Every possible collision-chain length, including an exhausted table.
        for occupied in range(N + 1):
            gens = [0] * N
            candidate = rng.getrandbits(32)
            for i in range(occupied):
                gens[(candidate + i) & 1023] = rng.randrange(1, 1 << 32)
            check(gens, candidate)
        for seed in (0, 1, 0xfffffc00, 0xfffffffe, MASK):
            gens = [1] * N
            gens[(seed + 7) & 1023] = 0
            check(gens, seed, (0, 1, 2, 3, 1, 1))
            check([1] * N, seed, (0, 1, 511, 511, 1))

        # Generation wrap THROUGH zero is observable and is not "fixed" here.
        gens = [1] * N
        gens[0] = 0
        registry, search = check(gens, MASK)
        assert search.candidate == 0 and registry.generation[0] == 0
        assert lib.ams_registry_tag_matches(C.byref(registry), search.handle) == 1

        # Independent original pre-codec checks for every slot, with matching
        # generation, stale-generation negative control and original free tags.
        for slot in range(N):
            for mode in ('match', 'stale', 'free'):
                generation = (rng.getrandbits(22) << 10) | slot
                gens = [0] * N
                gens[slot] = generation if mode == 'match' else (generation + 1024) & MASK if mode == 'stale' else 0
                if mode == 'free':
                    generation = slot
                handle = generation ^ 0x51dc9294
                registry = Registry()
                registry.generation[:] = gens
                prepare(gens)
                mu.reg_write(x.UC_X86_REG_R14, handle)
                mu.reg_write(x.UC_X86_REG_R8, frame - 0x2000)
                mu.emu_start(0x3ee473, 0x3ee4e5, count=1000)
                assert mu.reg_read(x.UC_X86_REG_RIP) == 0x3ee4e5
                expected = mu.reg_read(x.UC_X86_REG_RDX) == 0xe982a16
                assert expected == bool(lib.ams_registry_tag_matches(C.byref(registry), handle))
                assert int.from_bytes(mu.mem_read(frame - 0x2000, 4), 'little') == slot ^ 0x3a6ea582
                validations += 1
    report = dict(artifact_sha256=HASH, allocation_comparisons=allocations,
                  probe_boundary_comparisons=resumptions, tag_validation_comparisons=validations,
                  all_collision_lengths=1025, wraps_through_zero=True,
                  original_allocation_interval='0x1f7300..0x2079d4',
                  original_tag_interval='0x3ee473..0x3ee4e5',
                  relation='original tag = canonical generation + 0x69cad980 modulo 2^32',
                  missing_generated_paths=['0x1f736a..0x1f73ce'],
                  scope='invented disjoint generation arrays; logical state and outputs at probe/operation boundaries; no complete register/flag/fault/alias/instruction-budget equivalence; no record lifetime or session proof')
    a.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report))


if __name__ == '__main__':
    main()
