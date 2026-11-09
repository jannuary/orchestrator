"""Prove canonical lookup indices equal normalized four-word byte projections.

Dataflow groups only propose candidates. Sample assignments only reject them.
Replacement requires syntactic identity or an UNSAT proof over every symbolic
domain coordinate. No sampled equality or unresolved solver result authorizes it.
"""
from collections import Counter,defaultdict
from functools import reduce


class Projector:
    def __init__(self,positions,timeout_ms=1500,bit_timeout_ms=0):
        self.positions=positions;self.timeout_ms=timeout_ms;self.bit_timeout_ms=bit_timeout_ms;self.outcomes=Counter()

    def prove_bits(self,z,index,candidate):
        verdicts=[]
        for bit in range(index.size()):
            solver=z.Then('simplify','propagate-values','solve-eqs','simplify','bit-blast','aig','sat').solver()
            solver.set(timeout=self.bit_timeout_ms)
            solver.add(z.Extract(bit,bit,index)!=z.Extract(bit,bit,candidate))
            verdict=str(solver.check());self.outcomes['bit_'+verdict]+=1;verdicts.append(verdict)
            if verdict=='sat':return 'sat'
        return 'unsat' if all(verdict=='unsat' for verdict in verdicts) else 'unknown' 

    def __call__(self,trace,index,ordinal):
        if ordinal>=len(self.positions):return index
        z=trace.z;dependencies=trace.dependencies(index)
        if len(dependencies)<4:return index
        depth={};levels=defaultdict(set);groups=set()
        for event in trace.events:
            if event['ordinal'] not in trace.regular:continue
            parents=event['dependencies']
            if any(parent not in depth for parent in parents):continue
            level=1+max(depth[parent] for parent in parents) if parents else 0
            depth[event['variable']]=level;levels[level].add(event['variable'])
            if len(parents)==4 and parents<=dependencies:groups.add(tuple(sorted(parents)))
        for variables in levels.values():
            selected=variables&dependencies
            if len(selected)==4:groups.add(tuple(sorted(selected)))
        if not groups:
            self.outcomes['no_four_word_candidate']+=1;return index
        assignments=[(variable,z.BitVecVal(0,variable.size())) for variable in trace.variables]
        origin=z.simplify(z.substitute(index,*assignments))
        if not z.is_bv_value(origin):self.outcomes['unknown_origin']+=1;return index
        for group in sorted(groups,key=lambda values:max(values),reverse=True):
            if any(variable not in trace.word_expressions for variable in group):continue
            word=reduce(lambda left,right:left^right,(trace.word_expressions[variable] for variable in group))
            byte=self.positions[ordinal];projection=z.Extract(byte*8+7,byte*8,word)
            projected_origin=z.simplify(z.substitute(projection,*assignments))
            if not z.is_bv_value(projected_origin):continue
            candidate=z.simplify(projection^origin^projected_origin)
            if z.eq(candidate,index):self.outcomes['syntactic_identity']+=1;return candidate
            plausible=True
            for trial in range(2):
                samples=[(variable,z.BitVecVal((position+3)*0x35+trial*0x79,variable.size()))
                         for position,variable in enumerate(trace.variables)]
                difference=z.simplify(z.substitute(index^candidate,*samples))
                if not z.is_bv_value(difference) or difference.as_long():plausible=False;break
            if not plausible:self.outcomes['filter_rejected']+=1;continue
            solver=z.Solver();solver.set(timeout=self.timeout_ms);solver.add(index!=candidate)
            verdict=str(solver.check());self.outcomes[verdict]+=1
            if verdict=='unknown':
                exact=z.Then('simplify','propagate-values','solve-eqs','simplify','bit-blast','aig','sat').solver()
                exact.set(timeout=8000);exact.add(index!=candidate);verdict=str(exact.check());self.outcomes['aig_'+verdict]+=1
            if verdict=='unknown' and self.bit_timeout_ms:
                verdict=self.prove_bits(z,index,candidate);self.outcomes['split_'+verdict]+=1
            if verdict=='unsat':return candidate
        return index
