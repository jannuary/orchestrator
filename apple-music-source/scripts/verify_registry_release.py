"""Original-ELF differential for the canonical unowned-reset suboperation.

Invented decoded records and generations only. Owned records with external
buffers stop before their unrecovered cleanup. No complete teardown/session/key
parity is claimed.
"""
import argparse
import ctypes as C
import hashlib
import json
from pathlib import Path
import random
import subprocess
import tempfile

from trace_registry_release import trace
from verify_integrity_codec import HASH


class Registry(C.Structure):
    _fields_=[('generation',C.c_uint32*1024)]


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('core_elf',type=Path)
    p.add_argument('--output',type=Path,required=True)
    a=p.parse_args();image=a.core_elf.read_bytes()
    assert hashlib.sha256(image).hexdigest()==HASH
    native=Path(__file__).resolve().parents[1]/'src/apple_music_source/_native'
    rng=random.Random(0x3f0cc7)
    counts=dict(record_kind_cases=0,null_record_cases=0,free_slot_cases=0,owned_cleanup_boundaries=0,
                inline_cleanup_cases=0,unsupported_ownership_cases=0)
    with tempfile.TemporaryDirectory(prefix='ams-release-') as temporary:
        library=Path(temporary)/'registry.so'
        subprocess.run(['cc','-std=c99','-O2','-Wall','-Wextra','-Werror','-shared','-fPIC',str(native/'registry.c'),'-o',str(library)],check=True)
        lib=C.CDLL(str(library))
        release=lib.ams_registry_release_unowned
        release.argtypes=[C.POINTER(Registry),C.c_size_t,C.c_void_p,C.c_size_t]
        release.restype=C.c_int
        inline=lib.ams_registry_release_inline
        inline.argtypes=release.argtypes+[C.c_uint64]
        inline.restype=C.c_int
        for kind in range(256):
            payload=bytearray(rng.randbytes(336));payload[244]=kind
            original=trace(image,1023,True,kind=kind,payload=payload,seed=rng.getrandbits(32))
            assert not original['error'] and not original['faults']
            registry=Registry();registry.generation[1023]=2047
            storage=C.create_string_buffer(bytes(payload))
            before=bytes(registry)
            status=release(C.byref(registry),1023,storage,336)
            assert storage.raw[:336]==bytes(payload)
            if kind==15:
                assert status==2 and bytes(registry)==before and not original['tag_cleared']
                assert original['decoded_record_observed']
                assert original['events'][-1]['event']=='owned_record_cleanup_required'
                counts['owned_cleanup_boundaries']+=1
            else:
                assert status==0 and not registry.generation[1023]
                assert original['tag_cleared'] and original['decoded_changed_offsets']==[]
                assert original['reencoded_pointer_consistent']
            counts['record_kind_cases']+=1
        for case in range(256):
            payload=bytearray(rng.randbytes(336));payload[244]=15
            for offset in (0xb8,0xc8,0x110,0x130):payload[offset:offset+8]=bytes(8)
            payload[0x12c]=case if case!=3 else 2
            frame=0x1008000+(case%128)*16
            captured=[]
            original=trace(image,1023,True,kind=15,payload=payload,seed=rng.getrandbits(32),
                           stop_owned=False,cleanup_return_state=8,frame_address=frame,
                           observe_record=captured.append)
            assert not original['error'] and not original['faults'],(case,original['faults'],original['recent_pcs'])
            assert original['events'][-1]['return_pc']=='0x3f0cb7',original['events'][-1]
            assert original['tag_cleared'] and original['reencoded_pointer_consistent']
            registry=Registry();registry.generation[1023]=2047
            storage=C.create_string_buffer(bytes(payload))
            assert inline(C.byref(registry),1023,storage,336,frame-0x3048)==0
            assert not registry.generation[1023]
            assert storage.raw[:336]==captured[0],case
            counts['inline_cleanup_cases']+=1
        for offset in (0xb8,0xc8,0x110,0x130,0x12c):
            payload=bytearray(336);payload[244]=15
            payload[offset]=3 if offset==0x12c else 1
            registry=Registry();registry.generation[1023]=2047
            storage=C.create_string_buffer(bytes(payload));before=bytes(registry),storage.raw
            assert inline(C.byref(registry),1023,storage,336,0x1005fb8)==2
            assert (bytes(registry),storage.raw)==before
            counts['unsupported_ownership_cases']+=1
        for slot in (0,1,511,1023):
            original=trace(image,slot,True,null_record=True)
            registry=Registry();registry.generation[slot]=slot+1024
            assert release(C.byref(registry),slot,None,0)==0
            assert original['tag_cleared'] and not original['decoded_record_observed']
            assert not any(registry.generation)
            counts['null_record_cases']+=1
            original=trace(image,slot,False)
            before=bytes(registry)
            # A free slot must not inspect an invalid non-null record pointer.
            assert release(C.byref(registry),slot,C.c_void_p(1),0)==1
            assert bytes(registry)==before and not original['decoded_record_observed']
            counts['free_slot_cases']+=1
    report=dict(status='pass',oracle_sha256=HASH,
                comparisons=counts['record_kind_cases']+counts['null_record_cases']+counts['free_slot_cases']+counts['inline_cleanup_cases'],**counts,
                relation='free slot skip; non-owned/null generation clear; owned records without external buffers compare every logical byte after inline cleanup across 128 aligned scratch addresses; unsupported ownership preserves storage',
                scope='bounded canonical reset suboperation; no external-buffer cleanup, final helper, complete register/flag/alias/fault/instruction-budget or session proof')
    a.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
