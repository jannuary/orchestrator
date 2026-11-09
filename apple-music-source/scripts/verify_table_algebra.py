"""Controls for encoded MixColumns detection, using specification/invented data."""
import argparse
import json
from pathlib import Path
import random
import sys

from analyze_table_algebra import analyze,apply,FORWARD,INVERSE


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,required=True);args=p.parse_args()
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.crypto.aes import _SBOX,_gmul
    rng=random.Random(0x32a19)
    encoder=[1<<i for i in range(32)]
    for _ in range(256):
        a,b=rng.sample(range(32),2);encoder[a]^=encoder[b]
    def arrays(matrix,independent_encoder=False):
        tables=[]
        for final in (False,True):
            for column in range(4):
                shift=rng.randrange(256);delta=rng.getrandbits(32);words=[]
                for x in range(256):
                    value=_SBOX[x^shift]
                    word=value<<(8*column) if final else sum(_gmul(value,matrix[j][column])<<(8*j) for j in range(4))
                    words.append((word if final and independent_encoder else apply(encoder,word))^delta)
                tables.append(b''.join(word.to_bytes(4,'little') for word in words))
        return tables
    rows=[]
    for name,matrix in (('AES-forward-MixColumns',FORWARD),('AES-inverse-MixColumns',INVERSE)):
        result=analyze(arrays(matrix),range(4),range(4,8))
        assert result['common_GF256_matrix_field'] and name in result['MixColumns_equivalence_families']
        rows.append(dict(control=name,status='pass',common_field=True,families=result['MixColumns_equivalence_families']))
    generic=tuple(tuple(rng.randrange(1,256) for _ in range(4)) for _ in range(4))
    result=analyze(arrays(generic),range(4),range(4,8))
    assert result['common_GF256_matrix_field'] and not result['MixColumns_equivalence_families']
    rows.append(dict(control='invented non-AES field mixing',status='pass',common_field=True,families=[]))
    result=analyze(arrays(FORWARD,True),range(4),range(4,8))
    assert not result.get('MixColumns_equivalence_families')
    rows.append(dict(control='incompatible final-word encoding',status='pass',families=[]))
    report=dict(status='pass',controls=rows,scope='specification-generated and invented data only; no target arrays or inferred matrices written')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
