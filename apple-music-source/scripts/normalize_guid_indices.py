"""Prove index projections against prior four-word column hypotheses.

Only proved identities replace expressions. Original words and byte-plane
models remain in RAM. No array/crypto values or hypothesis constants emitted.
"""
from collections import Counter
from functools import reduce
from analyze_table_algebra import apply


class IndexNormalizer:
    def __init__(self,timeout_ms=15000):self.timeout_ms=timeout_ms;self.outcomes=Counter()

    def __call__(self,trace,index,ordinal):
        z=trace.z;n=trace.regular_reads
        if ordinal>=4 or n<16:return index
        regular=[event for event in trace.events if event['ordinal']<4]
        previous=regular[16*(n//16-1):16*(n//16)]
        if len(previous)!=16:return index
        ordinals={event['variable']:event['ordinal'] for event in regular}
        upstream=trace.dependencies(index)
        if any(variable not in trace.domain_constraints for variable in upstream):
            self.outcomes['unsupported_domain']+=1;return index
        for start in range(0,16,4):
            group=previous[start:start+4]
            variables=[event['variable'] for event in group]
            if {event['ordinal'] for event in group}!={0,1,2,3}:continue
            combined=reduce(lambda a,b:a^b,(trace.word_expressions[variable] for variable in variables))
            for byte in range(4):
                projected=z.Extract(8*byte+7,8*byte,combined)
                constant=trace.concrete(index^projected)
                candidate=z.simplify(projected^z.BitVecVal(constant,8))
                all_variables=upstream|set(variables);plausible=True
                for trial in range(2):
                    assignments=[]
                    for variable in sorted(all_variables):
                        source=ordinals[variable]
                        offset,columns,_=trace.word_domains[source]
                        coordinate=((variable+7)*73+trial*101)&255
                        assignments.append((trace.word_expressions[variable],z.BitVecVal(offset^apply(columns,coordinate),32)))
                    difference=z.simplify(z.substitute(index^candidate,*assignments))
                    if not z.is_bv_value(difference) or difference.as_long():plausible=False;break
                if not plausible:continue
                solver=z.Solver();solver.set(timeout=self.timeout_ms)
                solver.add(index!=candidate)
                solver.add(*(trace.domain_constraints[variable] for variable in all_variables))
                verdict=solver.check();self.outcomes[str(verdict)]+=1
                if verdict==z.unsat:return candidate
        return index
