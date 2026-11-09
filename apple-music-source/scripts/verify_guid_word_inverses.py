"""Invented controls for complete source-form/matrix inverse proofs."""
import argparse
import json
from pathlib import Path
import random
import struct
import subprocess
import tempfile

from invert_guid_word_encodings import recover


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();import z3 as z
    with tempfile.TemporaryDirectory(prefix='ams-guid-inverse-controls-') as directory:
        directory=Path(directory);source=directory/'program.s';object_=directory/'program.o';binary=directory/'program.bin'
        source.write_text('.intel_syntax noprefix\n.text\nadd eax,17\nrol eax,5\nret\n')
        subprocess.run(['cc','-c',str(source),'-o',str(object_)],check=True,capture_output=True)
        subprocess.run(['objcopy','-O','binary','--only-section=.text',str(object_),str(binary)],check=True,capture_output=True)
        code=binary.read_bytes();base=0x1000000;image=bytearray(0x2000);image[:6]=b'\x7fELF\x02\x01'
        struct.pack_into('<Q',image,32,64);struct.pack_into('<HH',image,54,56,1)
        struct.pack_into('<IIQQQQQQ',image,64,1,5,0x1000,base,0,len(code),4096,4096)
        image[0x1000:0x1000+len(code)]=code
        words=[z.BitVec('test_word_'+str(index),32) for index in range(5)]
        contributions=[words[0],words[1]^z.LShR(words[1],3),
                       z.RotateLeft(words[2]+17,5)^z.RotateLeft(z.BitVecVal(17,32),5),
                       (z.RotateLeft(words[3],5)+17)^17,words[4]*3]
        analysis=dict(z=z,words=words,contributions=contributions,begin=base,end=base+len(code))
        inverses={};proofs=recover(analysis,bytes(image),lambda index,encoded,expr:inverses.update({index:(encoded,expr)}))
        assert set(inverses)=={0,1,2,3}
        assert proofs['words'][4]['status']=='no proved inverse in source-derived form family'
        absent=recover(dict(analysis,words=[words[4]],contributions=[words[4]*3]),bytes(image),allow_multiplication=True)
        assert absent['words'][0]['status']=='no proved inverse in source-derived form family'
        rng=random.Random(0x514237);checks=0
        for index,(encoded,inverse) in inverses.items():
            trials=list(range(256))+[0x7fffffff,0x80000000,0xffffffff]+[rng.getrandbits(32) for _ in range(128)]
            for value in trials:
                forward=z.simplify(z.substitute(contributions[index],(words[index],z.BitVecVal(value,32)))).as_long()
                assert z.simplify(z.substitute(inverse,(encoded,z.BitVecVal(forward,32)))).as_long()==value
                reverse=z.simplify(z.substitute(inverse,(encoded,z.BitVecVal(value,32)))).as_long()
                assert z.simplify(z.substitute(contributions[index],(words[index],z.BitVecVal(reverse,32)))).as_long()==value
                checks+=2
        source.write_text('.intel_syntax noprefix\n.text\nimul eax,eax,3\nadd eax,17\nrol eax,5\nret\n')
        subprocess.run(['cc','-c',str(source),'-o',str(object_)],check=True,capture_output=True)
        subprocess.run(['objcopy','-O','binary','--only-section=.text',str(object_),str(binary)],check=True,capture_output=True)
        code=binary.read_bytes();struct.pack_into('<IIQQQQQQ',image,64,1,5,0x1000,base,0,len(code),4096,4096)
        image[0x1000:0x1000+len(code)]=code
        extended=dict(z=z,words=words[:2],contributions=[words[0]*3,words[1]*6],begin=base,end=base+len(code))
        extra={};extra_report=recover(extended,bytes(image),lambda index,encoded,expr:extra.update({index:(encoded,expr)}),allow_multiplication=True)
        assert set(extra)=={0} and extra_report['words'][0]['source_odd_multiply_supported']
        assert extra_report['words'][1]['status']=='no proved inverse in source-derived form family'
        encoded,inverse=extra[0]
        for value in trials:
            forward=(value*3)&0xffffffff
            assert z.simplify(z.substitute(inverse,(encoded,z.BitVecVal(forward,32)))).as_long()==value
            backward=z.simplify(z.substitute(inverse,(encoded,z.BitVecVal(value,32)))).as_long()
            assert (backward*3)&0xffffffff==value;checks+=2
    report=dict(status='pass',proved_inverses=5,unsupported_nonlinear_form_rejected_by_default=True,
                source_odd_multiply_optin_supported=True,unlisted_multiplier_rejected=True,even_nonbijective_multiplier_rejected=True,two_direction_numeric_checks=checks,
                proof_methods=[row['inverse_proof'] for row in proofs['words'][:4]],
                scope='invented word functions and source-immediate candidates; no target data, keys, offsets or matrices emitted')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
