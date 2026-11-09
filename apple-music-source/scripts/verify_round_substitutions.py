"""Specification/invented controls for shared nonlinear round encodings."""
import argparse
import json
from pathlib import Path
import random
import sys

from analyze_table_algebra import Basis,apply,FORWARD,INVERSE
from analyze_round_substitutions import analyze


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,required=True);args=p.parse_args()
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.crypto.aes import _SBOX,_INV_SBOX,_gmul
    rng=random.Random(0x491322)
    def encoders():
        result=[]
        for _ in range(4):
            columns=[1<<j for j in range(8)]
            for _ in range(64):
                a,b=rng.sample(range(8),2);columns[a]^=columns[b]
            result.append(tuple(columns))
        return result
    def tables(matrix,box,incompatible=False):
        output=encoders();input_=encoders() if incompatible else output;arrays=[]
        for final in (False,True):
            for column in range(4):
                back=Basis(input_[column]);shift=rng.randrange(256);delta=rng.getrandbits(32);words=[]
                for x in range(256):
                    y=box[back.coordinates(x)^shift]
                    values=[y if j==column else 0 for j in range(4)] if final else [_gmul(y,matrix[j][column]) for j in range(4)]
                    words.append(sum(apply(output[j],value)<<(8*j) for j,value in enumerate(values))^delta)
                arrays.append(b''.join(word.to_bytes(4,'little') for word in words))
        return arrays
    rows=[]
    for name,matrix,box,substitution in (('forward',FORWARD,_SBOX,'AES-S-box'),('inverse',INVERSE,_INV_SBOX,'AES-inverse-S-box')):
        result=analyze(tables(matrix,box),range(4));assert result['full_substitution_candidates']>0
        assert any(family['substitution']==substitution for family in result['coherent_families'])
        rows.append(dict(control=name,status='pass',candidates=result['full_substitution_candidates'],families=result['coherent_families']))
    result=analyze(tables(FORWARD,_SBOX,True),range(4));assert result['full_substitution_candidates']==0
    rows.append(dict(control='incompatible nonlinear input encoding',status='pass',candidates=0))
    report=dict(status='pass',controls=rows,scope='specification-generated/invented arrays only; inferred encodings and translations stay RAM-only')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
