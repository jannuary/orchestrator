"""Independent byte/guard checks for decoded source control references.

The original ELF is only the offline oracle. It is not linked, shipped or read
by the model. No raw words, image bytes or state fingerprints enter reports.
"""
import argparse
import ctypes as C
import json
from pathlib import Path
import subprocess
import tempfile

from generate_control_refs import cells
from probe_control_data import Classifier
from verify_fill_dispatch import segment_read


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('checkout',type=Path);p.add_argument('inventory',type=Path);p.add_argument('--output',type=Path,required=True)
    args=p.parse_args();root=args.checkout.resolve();inventory=json.loads(args.inventory.read_text())
    entries=cells(root,inventory);classifier=Classifier(root,include_pristine_rw=True)
    native=Path(__file__).resolve().parents[1]/'src/apple_music_source/_native'
    known={address+i for address in entries for i in range(4)};reads=rejected=0
    with tempfile.TemporaryDirectory(prefix='ams-control-verify-') as temp:
        library=Path(temp)/'control.so'
        subprocess.run(['cc','-std=c99','-O2','-Wall','-Wextra','-Werror','-shared','-fPIC',
                        str(native/'control_refs.c'),'-o',str(library)],check=True)
        read=C.CDLL(str(library)).ams_control_refs_read
        read.argtypes=[C.c_uint64,C.c_uint,C.POINTER(C.c_uint64)];read.restype=C.c_int
        for address in sorted(known):
            for width in range(1,9):
                out=C.c_uint64(0xdecafbad12345678)
                if all(address+i in known for i in range(width)):
                    expected=classifier.pristine_read(address,width);assert expected is not None
                    assert read(address,width,C.byref(out))==1 and out.value==expected
                    reads+=1
                else:
                    assert read(address,width,C.byref(out))==0 and out.value==0xdecafbad12345678
                    rejected+=1
        for address,width in ((0,1),(2**64-1,8),(0,0),(min(known),9)):
            out=C.c_uint64(0xdecafbad12345678)
            assert read(address,width,C.byref(out))==0 and out.value==0xdecafbad12345678
            rejected+=1
        assert read(min(known),1,None)==0;rejected+=1
    report=dict(status='pass',cells=len(entries),bytes=len(known),read_comparisons=reads,
                rejection_preservation_checks=rejected,
                relation='all admitted 1..8-byte reads equal pinned pristine oracle data; gaps, width, null and overflow reject without output writes',
                provenance='decoded source-control destinations, instruction-derived bases and named imports; no raw image-word initializer',
                scope='observed reference cells only; no full image closure or successful standalone crypto/auth proof')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
