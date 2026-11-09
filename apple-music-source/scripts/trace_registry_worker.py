"""Bounded lifetime-worker research on invented shared state.

Original ELF only as a developer oracle. Sleep/gettimeofday use an explicit
single-thread test scheduler; non-null lock/import effects remain unsupported.
This is not a valid acquired context, worker constructor or expiry proof.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import sys

from verify_integrity_codec import HASH


def trace(elf, references, seconds=1700000005, observe_pc=None, counter=0, observed=0,
          selector_value=0, seed_words=None, baseline=0, timestamp=1700000000):
    from unicorn import Uc, UcError, UC_ARCH_X86, UC_MODE_64, UC_HOOK_CODE, UC_HOOK_MEM_INVALID, UC_HOOK_MEM_READ, UC_HOOK_MEM_WRITE
    from unicorn import x86_const as r
    assert hashlib.sha256(Path(elf).read_bytes()).hexdigest() == HASH
    sys.path.insert(0, str(Path(__file__).resolve().parents[3] / 'tools/crypto/keygen_experimental'))
    from elf_loader import load
    mu = Uc(UC_ARCH_X86, UC_MODE_64)
    mu.mem_map(0x900000, 0x10000); mu.mem_map(0x1000000, 0x100000); mu.mem_map(0x3000000, 0x100000)
    stubs = {}; load(mu, elf, 0, stubs, {}, 0x900000)
    def put(at, value, width=8): mu.mem_write(at, (value % (1 << (width * 8))).to_bytes(width, 'little'))
    put(0x691850, 0x3000000 + 0x1424a573); put(0x3000000, 0x3001000)
    put(0x3001020, references + 0x5fd2b496, 4)
    # Explicit invented seed-table and shared counter mappings. Without these,
    # the base-zero ELF mapping would admit a null seed/pool pointer.
    seed=0x12345678
    put(0x695d90,0x3004000);put(0x695db0,selector_value,4);put(0x3004000,seed)
    for offset,word in (seed_words or {}).items():put(0x3004000+offset,word)
    counter_seed=int.from_bytes(mu.mem_read(0x3004000+(selector_value&0xb4eda7e8),8),'little')&((1<<63)-1)
    time_seed=int.from_bytes(mu.mem_read(0x3004000+(selector_value&0x3cfb8018),8),'little')&((1<<63)-1)
    put(0x3001008,0x3012000);put(0x3012000,counter_seed^0x47ef675e13e3af4a^counter)
    put(0x3001028,counter_seed^0x47ef675e13e3af4a^observed)
    put(0x3001010,counter_seed^0x47ef675e13e3af4a^baseline)
    put(0x3001038,time_seed^0x25da2183ec893e97^timestamp)
    put(0x3001030,1)
    put(0x10f0000, 0x90ff00); mu.reg_write(r.UC_X86_REG_RSP, 0x10f0000)
    events = []; faults = []; recent = []; fields = []; sleeps = [0]; steps = [0]
    def returned(value):
        sp = mu.reg_read(r.UC_X86_REG_RSP)
        mu.reg_write(r.UC_X86_REG_RIP, int.from_bytes(mu.mem_read(sp, 8), 'little'))
        mu.reg_write(r.UC_X86_REG_RSP, sp + 8); mu.reg_write(r.UC_X86_REG_RAX, value)
    def code(_mu, at, _size, _user):
        steps[0] += 1; recent.append(hex(at)); del recent[:-12]
        if observe_pc: observe_pc(mu, at)
        if at == 0xdc7c9:
            events.append(dict(event='worker_return_boundary')); mu.emu_stop(); return
        if at in stubs:
            name = stubs[at]; arg = mu.reg_read(r.UC_X86_REG_RDI)
            events.append(dict(event='import', name=name, argument=hex(arg)))
            if name == 'sleep' and arg == 5:
                sleeps[0] += 1
                if sleeps[0] == 1: returned(0)
                else: mu.emu_stop()
            elif name == 'gettimeofday' and 0x1000000 <= arg <= 0x10ffff0 and mu.reg_read(r.UC_X86_REG_RSI) == 0:
                put(arg, seconds); put(arg + 8, 0); returned(0)
            else: mu.emu_stop()
    def access(_mu, kind, at, width, _value, _user):
        if at < 0x40:
            faults.append(dict(pc=hex(mu.reg_read(r.UC_X86_REG_RIP)),address=hex(at),width=width,reason='low application pointer'))
            mu.emu_stop()
        if 0x3001000 <= at < 0x3001100:
            fields.append(dict(pc=hex(mu.reg_read(r.UC_X86_REG_RIP)),access=kind,offset=at-0x3001000,width=width))
    def invalid(_mu, kind, at, width, _value, _user):
        faults.append(dict(pc=hex(mu.reg_read(r.UC_X86_REG_RIP)),access=kind,address=hex(at),width=width)); return False
    mu.hook_add(UC_HOOK_CODE, code); mu.hook_add(UC_HOOK_MEM_INVALID, invalid)
    mu.hook_add(UC_HOOK_MEM_READ | UC_HOOK_MEM_WRITE, access)
    error = None
    try: mu.emu_start(0xdc000, 0, count=200000)
    except UcError as e: error = e.errno
    return dict(references=references, steps=steps[0], events=events, faults=faults,
                selector_after=int.from_bytes(mu.mem_read(0x695db0,4),'little'),
                logical_counter_after=int.from_bytes(mu.mem_read(0x3012000,8),'little')^counter_seed^0x47ef675e13e3af4a,
                references_after=(int.from_bytes(mu.mem_read(0x3001020,4),'little')-0x5fd2b496)&0xffffffff,
                timestamp_after=int.from_bytes(mu.mem_read(0x3001038,8),'little')^time_seed^0x25da2183ec893e97,
                observed_after=int.from_bytes(mu.mem_read(0x3001028,8),'little')^counter_seed^0x47ef675e13e3af4a,
                thread_after=int.from_bytes(mu.mem_read(0x3001030,8),'little'),
                error=error, shared_accesses=fields, recent_pcs=recent)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('core_elf', type=Path); parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    cases = [trace(args.core_elf, refs) for refs in (0, 1, 2)]
    assert all(not c['error'] and not c['faults'] for c in cases), cases
    report = dict(status='research only', oracle_sha256=HASH, cases=cases,
                  scope='invented shared object; original worker entry through one controlled five-second wake; null locks; original encoded timer fields not reconstructed; no valid constructor, concurrent scheduler or expiry proof')
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps(dict(status=report['status'], cases=len(cases), endpoints=[c['events'][-1] for c in cases])))


if __name__ == '__main__': main()
