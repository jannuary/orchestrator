"""Compare installed-source word codecs with original instruction prefixes.

All original data and result values remain in RAM. Reports contain counts only.
"""
import argparse
import ctypes as C
import hashlib
import json
from pathlib import Path
import random
import subprocess
import tempfile

from recover_guid_word_consumers import candidates,verify_original
from scan_auth_substitutions import TARGETS
from verify_fill_dispatch import segment_read


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout',type=Path)
    parser.add_argument('--verified-decoders',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args()
    native=Path(__file__).resolve().parents[1]/'src/apple_music_source/_native'
    report=json.loads(args.verified_decoders.read_text());rows=[]
    with tempfile.TemporaryDirectory(prefix='ams-owned-auth-word-check-') as directory:
        library=Path(directory)/'word.so'
        subprocess.run(['cc','-std=c99','-O2','-Wall','-Wextra','-Werror','-shared','-fPIC',str(native/'auth_word_codecs.c'),'-o',str(library)],check=True,capture_output=True)
        decode=C.CDLL(str(library)).ams_auth_word_decode
        decode.argtypes=[C.c_uint,C.c_uint32,C.POINTER(C.c_uint32)];decode.restype=C.c_int
        kind=0;rng=random.Random(0x431585)
        for module in report['modules']:
            filename,digest=TARGETS[module['target']]
            image=(args.checkout/'rootfs/system/lib64'/filename).read_bytes()
            assert hashlib.sha256(image).hexdigest()==module['artifact_sha256']==digest
            for table in module['tables']:
                if table['status']!='verified source word decoder':continue
                candidate=next(item for item in candidates(image,int(table['source_load'],16))
                    if item['end']==int(table['source_decoder_end'],16) and item['output_register']==table['source_output_register'])
                data=segment_read(image,int(table['elf_virtual_address'],16),1024)
                words=[int.from_bytes(data[j:j+4],'little') for j in range(0,1024,4)]
                original=verify_original(image,words,candidate)
                z=candidate['z'];word=candidate['word'];expression=candidate['expression']
                trials=words+[0,1,0x7fffffff,0x80000000,0xffffffff]+[rng.getrandbits(32) for _ in range(1024)]
                for value in trials:
                    output=C.c_uint32()
                    assert decode(kind,value,C.byref(output))==1
                    expected=z.simplify(z.substitute(expression,(word,z.BitVecVal(value,32)))).as_long()
                    assert output.value==expected
                rows.append(dict(decoder=kind,target=module['target'],source_load=table['source_load'],
                    original_instruction_comparisons=original,owned_C_expression_comparisons=len(trials)))
                kind+=1
        assert kind==5
        for bad in (5,6,0xffffffff):
            output=C.c_uint32(0x12345678)
            assert decode(bad,0,C.byref(output))==0 and output.value==0x12345678
        assert all(decode(index,0,None)==0 for index in range(5))
    result=dict(status='pass',decoders=rows,invalid_ID_and_null_output_fail_closed=True,
        scope='owned C vs independently executed original prefixes and source expressions; original words/results stay RAM-only; no complete cipher, key acquisition or native-auth claim')
    args.output.write_text(json.dumps(result,indent=2)+'\n')
    print(json.dumps(dict(status='pass',decoders=len(rows),original_instruction_comparisons=sum(row['original_instruction_comparisons'] for row in rows),
        owned_C_expression_comparisons=sum(row['owned_C_expression_comparisons'] for row in rows))))


if __name__=='__main__':main()
