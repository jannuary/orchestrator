"""Reject sampled-only projection equivalence using invented affine domains."""
import argparse
import json
from pathlib import Path

from prove_guid_index_projections import Projector
from trace_lookup_dataflow import LookupTrace


def main():
    import z3 as z
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    trace=LookupTrace(None,[],range(4),[]);variables=[z.BitVec('invented_domain_'+str(index),8) for index in range(9)]
    trace.variables=variables;trace.values=[0]*len(variables);trace.variable_names={str(variable):index for index,variable in enumerate(variables)}
    trace.word_expressions={index:z.ZeroExt(24,variable)*0x01010101 for index,variable in enumerate(variables)}
    trace.events=[dict(variable=index,ordinal=index%4,dependencies=set()) for index in range(8)]
    trace.events.append(dict(variable=8,ordinal=0,dependencies={4,5,6,7}))
    true=variables[4]^variables[5]^variables[6]^variables[7]^23
    noise=(variables[0]+variables[1]-((variables[0]&variables[1])<<1))^variables[0]^variables[1]
    index=true^noise;projector=Projector((3,0,1,2));normalized=projector(trace,index,0)
    assert trace.dependencies(normalized)==frozenset((4,5,6,7)) and projector.outcomes['unsat']==1
    negative=Projector((3,0,1,2));wrong=index^z.If(variables[0]==254,z.BitVecVal(1,8),z.BitVecVal(0,8))
    # The rare branch misses both invented filter assignments and zero origin.
    assert z.eq(negative(trace,wrong,0),wrong) and negative.outcomes['sat']>=1
    unknown=Projector((3,0,1,2));foreign=index^z.BitVec('unmodeled_foreign_byte',8)
    assert z.eq(unknown(trace,foreign,0),foreign) and unknown.outcomes['unknown_origin']==1
    split=Projector((3,0,1,2),bit_timeout_ms=1500)
    assert split.prove_bits(z,index,true)=='unsat' and split.outcomes['bit_unsat']==8
    assert split.prove_bits(z,wrong,true)=='sat'
    report=dict(status='pass',split_bit_controls=dict(split.outcomes),positive_UNSAT=dict(projector.outcomes),sampling_resistant_negative=dict(negative.outcomes),
                unknown_origin_rejected=True,scope='invented affine word domains and source-shaped expressions; no target values or encodings emitted')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
