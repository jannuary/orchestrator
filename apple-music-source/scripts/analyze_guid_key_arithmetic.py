"""Prove first-transition index projections using source word contributions.

All lookup words remain unconstrained 32-bit symbols. The surrounding captured
path is fixed; this does not prove caller reachability or generate parameters.
"""
from collections import Counter
from functools import reduce


def analyze(trace,details,reference,timeout_ms=1500,all_rounds=False,encoded_callback=None):
    z=trace.z;outcomes=Counter();proofs=0
    if len(details['layers'])<2:return dict(status='insufficient layers',private_bytes_written=False)
    model=details['model'];records=[]
    transitions=range(1,len(details['layers'])) if all_rounds else range(1,2)
    for level in transitions:
      first={event['variable']:event for event in details['layers'][level-1]}
      for event in details['layers'][level]:
        group=event['dependencies']
        if len(group)!=4 or not group<=first.keys():
            return dict(status='unsupported first-transition parents',private_bytes_written=False)
        pieces=[]
        for variable in group:
            ordinal=first[variable]['ordinal']
            pieces.append(z.substitute(reference['contributions'][ordinal],
                         (reference['words'][ordinal],trace.word_expressions[variable])))
        combined=reduce(lambda a,b:a^b,pieces)
        physical=model['input_positions'][event['ordinal']]
        projected=z.Extract(physical*8+7,physical*8,combined)
        delta=z.simplify(event['expression']^projected)
        origin=z.simplify(z.substitute(delta,*[(variable,z.BitVecVal(0,variable.size())) for variable in trace.variables]))
        if not z.is_bv_value(origin):
            return dict(status='nonconstant projection origin',projection_proofs=proofs,private_bytes_written=False)
        solver=z.Solver();solver.set(timeout=timeout_ms);solver.add(delta!=origin)
        verdict=str(solver.check());outcomes[verdict]+=1
        if verdict=='unknown':
            exact=z.Then('simplify','propagate-values','solve-eqs','simplify','bit-blast','aig','sat').solver()
            exact.set(timeout=10000);exact.add(delta!=origin)
            verdict=str(exact.check());outcomes['aig_'+verdict]+=1
        if verdict!='unsat':
            return dict(status='source projection not proved',projection_proofs=proofs,
                        solver_outcomes=dict(outcomes),unproved_projection_pc=hex(event['pc']) if 'pc' in event else None,
                        private_bytes_written=False)
        proofs+=1
        records.append((level,event['ordinal'],tuple(sorted(group)),origin.as_long()))
    if encoded_callback is not None:encoded_callback(records)
    return dict(status='all-observed-transition source index XOR projections proved' if all_rounds else 'first-transition source index XOR projections proved',projection_proofs=proofs,
                complete_transitions=len(transitions),
                solver_outcomes=dict(outcomes),private_bytes_written=False,
                scope='all source lookup-word symbols unconstrained, captured surrounding path fixed; source contributions and table-derived row labels, no lookup values used in solver, no initializer or native-auth claim')
