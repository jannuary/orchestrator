"""Logical worker entry/wake differential; test scheduler, original ELF.

Independent representation seeds, null locks, invented counter/clock/ref states.
No real acquired context, concurrent scheduler or registry-expiry claim.
"""
import argparse
import ctypes as C
import hashlib
import json
from pathlib import Path
import random
import subprocess
import tempfile

from trace_registry_worker import trace
from verify_integrity_codec import HASH
from verify_registry_shared_release import Shared


class Worker(C.Structure):
    _fields_ = [('wake_counter', C.c_uint64), ('active', C.c_uint)]


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('core_elf',type=Path);p.add_argument('--output',type=Path,required=True)
    args=p.parse_args();assert hashlib.sha256(args.core_elf.read_bytes()).hexdigest()==HASH
    rng=random.Random(37);u64=(1<<64)-1;stops=sleeps=0
    native=Path(__file__).resolve().parents[1]/'src/apple_music_source/_native/registry.c'
    with tempfile.TemporaryDirectory(prefix='ams-worker-') as tmp:
        so=Path(tmp)/'registry.so'
        subprocess.run(['cc','-std=c99','-Wall','-Wextra','-Werror','-shared','-fPIC','-O2',str(native),'-o',str(so)],check=True)
        lib=C.CDLL(str(so))
        lib.ams_registry_worker_begin.argtypes=[C.POINTER(Worker),C.POINTER(Shared)]
        lib.ams_registry_worker_wake.argtypes=[C.POINTER(Worker),C.POINTER(Shared),C.c_uint64]
        for case in range(256):
            counter,wake,baseline=[rng.choice([0,u64,rng.getrandbits(64)]) for _ in range(3)]
            timestamp=rng.choice([0,u64,rng.getrandbits(64)])
            now=rng.choice([0,u64,timestamp,(timestamp+1)&u64,rng.getrandbits(64)])
            refs=rng.choice([0,1,2,0xffffffff])
            result=trace(args.core_elf,refs,counter=counter,observed=wake,baseline=baseline,timestamp=timestamp,seconds=now,
                         selector_value=0xf8,seed_words={k:rng.getrandbits(64) for k in (0xc0,0x18,0xe8,0x10)})
            assert not result['faults'] and not result['error'],(case,result)
            state=Shared(refs,timestamp,baseline,counter);worker=Worker(wake,0)
            assert lib.ams_registry_worker_begin(C.byref(worker),C.byref(state))==1
            status=lib.ams_registry_worker_wake(C.byref(worker),C.byref(state),now)
            actual=(state.references,state.timestamp,state.counter,worker.wake_counter,worker.active)
            expected=(result['references_after'],result['timestamp_after'],result['logical_counter_after'],
                      result['observed_after'],int(result['thread_after']!=0))
            assert actual==expected,(case,actual,expected)
            assert result['selector_after']==0xf8
            if worker.active:
                assert status==1 and result['events'][-1]['name']=='sleep';sleeps+=1
            else:
                assert status==0 and result['events'][-1]['event']=='worker_return_boundary';stops+=1
    report=dict(status='pass',oracle_sha256=HASH,comparisons=256,stops=stops,sleeps=sleeps,
                relation='logical references, timestamp, counter, wake counter and active/return/sleep boundaries with independent representation seeds and uint64/uint32 limits',
                scope='caller-held locks; explicit test sleep/clock; one wake on invented objects; no full encoded representation, real scheduler/concurrency, record expiry or successful crypto/auth proof')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
