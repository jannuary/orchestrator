"""Exercise exact source projections with invented word expressions."""
import argparse
import json
from pathlib import Path
from types import SimpleNamespace

from analyze_guid_key_arithmetic import analyze


def main():
    import z3 as z
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();words=[z.BitVec('word_'+str(i),32) for i in range(4)]
    contributions=[z.RotateLeft(word+z.BitVecVal(17+index,32),index*3) for index,word in enumerate(words)]
    variables=[z.BitVec('loaded_'+str(i),32) for i in range(16)]
    first=[dict(variable=i,ordinal=i%4) for i in range(16)];second=[]
    for column in range(4):
        combined=z.BitVecVal(0,32);parents=set(range(column*4,column*4+4))
        for variable in parents:combined^=z.substitute(contributions[variable%4],(words[variable%4],variables[variable]))
        for row in range(4):
            second.append(dict(variable=16+len(second),ordinal=row,dependencies=parents,
                               expression=z.Extract(row*8+7,row*8,combined)^z.BitVecVal(column*4+row+1,8)))
    trace=SimpleNamespace(z=z,variables=variables,word_expressions=dict(enumerate(variables)))
    details=dict(layers=[first,second],model=dict(input_positions=(0,1,2,3)))
    reference=dict(words=words,contributions=contributions)
    positive=analyze(trace,details,reference);assert positive['projection_proofs']==16
    bad=[dict(event) for event in second];bad[0]['expression']=second[0]['expression']+(z.Extract(7,0,variables[0])&1)
    negative=analyze(trace,dict(details,layers=[first,bad]),reference)
    assert negative['status']=='source projection not proved' and negative['solver_outcomes']=={'sat':1}
    foreign=[dict(event) for event in second];foreign[0]['expression']^=z.BitVec('unknown_incoming',8)
    assert analyze(trace,dict(details,layers=[first,foreign]),reference)['status']=='nonconstant projection origin'
    report=dict(status='pass',positive=positive,wrong_projection_rejected=True,unknown_origin_rejected=True,
                scope='invented source expressions and unconstrained word32 inputs only')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(status='pass',projection_proofs=16)))


if __name__=='__main__':main()
