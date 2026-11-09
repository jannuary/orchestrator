"""Offline differential verification of a recovered finite data model.

Explicit digest-checked original artifact is an oracle ONLY. This script is not
called by package tests, builds, or runtime. Requires developer-only Unicorn.
Reports contain metadata only. No account, exchange, hardware, or network input.
"""
import argparse
import ctypes
import hashlib
import json
from pathlib import Path
import random
import struct
import subprocess
import tempfile

APP_HASH = '0a575431868e40ddb29e9e0bac7a4993d6e05971b45403cabe358c081b54a36e'
BEGIN, END = 0x525a00, 0x525a5c


def segment_read(raw, address, length):
    off = struct.unpack_from('<Q', raw, 32)[0]
    step, count = struct.unpack_from('<HH', raw, 54)
    for i in range(count):
        kind, _, offset, va, _, size, _, _ = struct.unpack_from(
            '<IIQQQQQQ', raw, off + i * step)
        if kind == 1 and va <= address and address + length <= va + size:
            return raw[offset + address - va:offset + address - va + length]
    raise ValueError('oracle range outside file-backed PT_LOAD')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('app_elf', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    raw = args.app_elf.read_bytes()
    if hashlib.sha256(raw).hexdigest() != APP_HASH:
        raise ValueError('oracle artifact digest mismatch')
    native = Path(__file__).resolve().parents[1] / 'src/apple_music_source/_native'
    with tempfile.TemporaryDirectory(prefix='ams-fill-oracle-') as t:
        libpath = Path(t) / 'model.so'
        subprocess.run(['cc', '-std=c99', '-O2', '-Wall', '-Wextra', '-Werror',
                        '-shared', '-fPIC', str(native / 'fill_dispatch.c'),
                        '-o', str(libpath)], check=True)
        lib = ctypes.CDLL(str(libpath))
        read = lib.ams_fill_dispatch_read
        read.argtypes = [ctypes.c_uint64, ctypes.c_uint,
                         ctypes.POINTER(ctypes.c_uint64)]
        read.restype = ctypes.c_int
        reconstructed = bytearray()
        for address in range(BEGIN, END):
            out = ctypes.c_uint64()
            assert read(address, 1, ctypes.byref(out)) == 1
            reconstructed.append(out.value)
        original = segment_read(raw, BEGIN, END - BEGIN)
        assert reconstructed == original
        reads = 0
        for address in range(BEGIN, END):
            for width in range(1, min(8, END - address) + 1):
                out = ctypes.c_uint64()
                assert read(address, width, ctypes.byref(out)) == 1
                assert out.value == int.from_bytes(
                    original[address - BEGIN:address - BEGIN + width], 'little')
                reads += 1

    from unicorn import Uc, UcError, UC_ARCH_X86, UC_MODE_64, UC_HOOK_MEM_INVALID
    from unicorn import x86_const as reg
    registers = [getattr(reg, 'UC_X86_REG_' + name) for name in (
        'RAX', 'RBX', 'RCX', 'RDX', 'RSI', 'RDI', 'RBP', 'RSP', 'R8', 'R9',
        'R10', 'R11', 'R12', 'R13', 'R14', 'R15', 'RFLAGS', 'RIP')]
    code = segment_read(raw, 0x42ced0, 0x12b)
    rng = random.Random(0xF111)

    def execute(table, destination, size, value, budget):
        mu = Uc(UC_ARCH_X86, UC_MODE_64)
        for at, n in ((0x42c000, 0x2000), (0x525000, 0x1000),
                      (0x2000000, 0x2000), (0x3000000, 0x4000), (0x900000, 0x1000)):
            mu.mem_map(at, n)
        mu.mem_write(0x42ced0, code)
        mu.mem_write(BEGIN, bytes(table))
        mu.mem_write(0x3000000, b'\xa5' * 0x4000)
        for i, r in enumerate(registers[:-2]):
            mu.reg_write(r, (0x102030405060708 * (i + 1)) & (2**64 - 1))
        sp = 0x2001000
        mu.reg_write(reg.UC_X86_REG_RSP, sp)
        mu.mem_write(sp, struct.pack('<Q', 0x900000))
        mu.reg_write(reg.UC_X86_REG_RDI, destination)
        mu.reg_write(reg.UC_X86_REG_RSI, value)
        mu.reg_write(reg.UC_X86_REG_RDX, size)
        mu.reg_write(reg.UC_X86_REG_RFLAGS, 0x202)
        faults = []
        def fault(_mu, access, address, width, _value, _user):
            faults.append((access, address, width))
            return False
        mu.hook_add(UC_HOOK_MEM_INVALID, fault)
        status = None
        try:
            mu.emu_start(0x42ced0, 0x900000, count=budget)
        except UcError as error:
            status = error.errno
        return (tuple(mu.reg_read(r) for r in registers),
                bytes(mu.mem_read(0x3000000, 0x4000)),
                bytes(mu.mem_read(0x2000000, 0x2000)),
                bytes(mu.mem_read(0x525000, 0x1000)),
                bytes(mu.mem_read(0x42c000, 0x2000)), tuple(faults), status)

    cases = [(0x3000100 + alignment, size, rng.getrandbits(64), 100000)
             for alignment in range(8)
             for size in (*range(0, 18), 63, 64, 65, 127, 128, 129, 511, 512, 513, 4096)]
    cases += [(0x3000000 + rng.randrange(256), rng.randrange(8193),
               rng.getrandbits(64), 100000) for _ in range(128)]
    cases += [(0x3003ff0 + alignment, 32, 0x78, 100000)
              for alignment in range(8)]
    cases += [(0x3000103, 512, 0x9876, budget)
              for budget in (1, 2, 7, 15, 20, 40, 60, 100, 200)]
    # Writes alias source-model tables or the stack: preserve writable memory
    # semantics, rather than installing an immutable oracle override.
    cases += [(BEGIN + offset, 16, 0x55, 100000) for offset in (0, 28, 60)]
    cases += [(0x2000ff0, 8, 0x33, 100000)]
    for case in cases:
        assert execute(original, *case) == execute(reconstructed, *case), (
            'execution mismatch', cases.index(case))
    # Also independently establish that completed ordinary cases perform fill.
    for case in cases[:224]:
        result = execute(reconstructed, *case)
        destination, size, value, _ = case
        expected = bytearray(b'\xa5' * 0x4000)
        expected[destination - 0x3000000:destination - 0x3000000 + size] = bytes([value & 255]) * size
        assert result[0][-1] == 0x900000 and result[1] == expected
    report = {'status': 'pass', 'oracle_sha256': APP_HASH,
              'model_bytes': END - BEGIN, 'finite_destinations': 23,
              'differential_reads': reads, 'execution_pairs': len(cases),
              'fault_pairs': 8, 'budget_pairs': 9, 'alias_pairs': 4,
              'original_tables_in_replacement': False,
              'scope': 'byte-fill control data only; no crypto/auth completeness'}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(report))


if __name__ == '__main__':
    main()
