"""Check experimental zero-bank rejection guards against the source oracle."""
import argparse
import ctypes
import json
import os
from pathlib import Path
import subprocess
import tempfile

from probe_registry_lifetime import SHIM


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    root = args.checkout.resolve()
    library = root/'build/spc-payload/libwrapper_spc_native.so'
    original = ctypes.CDLL(str(library))
    os.environ['AMS_NATIVE'] = str(library)
    os.environ['AMS_ZERO_FOLD'] = '1'
    os.environ['AMS_ZERO_PAIR'] = '1'
    with tempfile.TemporaryDirectory(prefix='ams-registry-guards-') as temporary:
        t = Path(temporary)
        # Disable only this isolated check's coverage destructor: no runtime
        # fixture runs here and its counters would be misleading.
        marker='__attribute__((destructor))static void done(void){'
        assert SHIM.count(marker) == 1
        (t/'shim.c').write_text(SHIM.replace(marker,'static void unused_report(void){'))
        subprocess.run(['cc','-std=c99','-O2','-shared','-fPIC','-I'+str(root/'crypto/keygen_experimental'),str(t/'shim.c'),'-ldl','-o',str(t/'guards.so')],check=True,capture_output=True)
        candidate = ctypes.CDLL(str(t/'guards.so'))
        fold = [lib.wrapper_kg_integrity_fold for lib in (original, candidate)]
        pair = [lib.wrapper_kg_ckc_integrity_pair for lib in (original, candidate)]
        for f in fold:
            f.argtypes = [ctypes.c_uint64,ctypes.c_uint32,ctypes.POINTER(ctypes.c_int)]
            f.restype = ctypes.c_uint32
        for f in pair:
            f.argtypes = [ctypes.c_uint64,ctypes.c_uint64,ctypes.POINTER(ctypes.c_uint8)]
            f.restype = ctypes.c_int
        first,last = 0x100dc000,0x10664000
        fold_rejections = 0
        for base in (0,first-1,first+1,first+4095,last-1,last+1,(1<<64)-1):
            for value in (0,0x12345678,0xffffffff):
                a,b = ctypes.c_int(99),ctypes.c_int(99)
                assert fold[0](base,value,ctypes.byref(a)) == fold[1](base,value,ctypes.byref(b)) == 0
                assert a.value == b.value == 0
                fold_rejections += 1
        end = 0x1066c008
        relations = [(0,0),(first-1,first+1),(first,first+1),(first,first),
                     (first,first-32766),(end-1,end+1),(end,end+2),
                     (first+32766,first-1),((1<<64)-1,1)]
        pair_rejections = 0
        for a,b in relations:
            old,new = ctypes.c_uint8(0xa5),ctypes.c_uint8(0xa5)
            assert pair[0](a,b,ctypes.byref(old)) == pair[1](a,b,ctypes.byref(new)) == 0
            assert old.value == new.value == 0xa5
            pair_rejections += 1
        assert pair[0](first,first+2,None) == pair[1](first,first+2,None) == 0
        pair_rejections += 1
        accepted = 0
        for a,b in ((first,first+2),(first+32766,first),(end-3,end-1)):
            old,new = ctypes.c_uint8(0xa5),ctypes.c_uint8(0xa5)
            assert pair[0](a,b,ctypes.byref(old)) == pair[1](a,b,ctypes.byref(new)) == 1
            assert new.value == 0
            accepted += 1
        report = dict(status='pass',fold_rejection_cases=fold_rejections,
                      pair_rejection_output_preservation_cases=pair_rejections,
                      pair_acceptance_cases=accepted,
                      scope='experimental guards only; output equivalence for valid integrity lookups is neither expected nor claimed')
        args.output.write_text(json.dumps(report,indent=2)+'\n')
        print(json.dumps(report))


if __name__ == '__main__':
    main()
