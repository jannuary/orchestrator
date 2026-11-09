"""Prove reusable native column register rewrites; keep all templates in RAM.

Every rewrite requires UNSAT for either unrestricted word inputs or the exact
validated affine lookup-word planes. No sampled hypothesis is accepted alone.
"""
from collections import Counter
from functools import reduce

from analyze_table_algebra import independent
from recover_guid_word_consumers import GPRS,Code
from trace_lookup_dataflow import LookupTrace
from verify_fill_dispatch import segment_read


class ColumnRewriter:
    def __init__(self,expected,image,reference,raw_tables,normalized_arrays):
        self.z=reference['z'];self.reference=reference;self.points={};self.starts={};self.contexts={};self.active_group=None
        self.proofs=Counter();self.applied=0;self.group_count=0;self.skipped=0
        self.planes=[]
        for data in normalized_arrays:
            words=[int.from_bytes(data[j:j+4],'little') for j in range(0,1024,4)]
            columns=independent([word^words[0] for word in words]);assert len(columns)==8
            self.planes.append((words[0],columns))
        regular=[event for event in expected if event[1]<4]
        first_final=next(event[0] for event in expected if event[1]>=4)
        for group in range(len(regular)//4):
            events=regular[4*group:4*group+4]
            if {event[1] for event in events}!={0,1,2,3}:self.skipped+=1;continue
            begin=events[0][0]-0x4000000
            end=(regular[4*group+4][0] if 4*group+4<len(regular) else first_final)-0x4000000
            if not 0<end-begin<=2048:self.skipped+=1;continue
            self._build(group,begin,end,events,image,raw_tables)

    def _build(self,group,begin,end,events,image,raw_tables):
        from capstone import CS_OP_MEM,CS_GRP_JUMP,CS_GRP_CALL,CS_GRP_RET
        z=self.z;trace=LookupTrace(None,[],[],[]);trace.started=True
        incoming={name:z.BitVec('rewrite_input_'+name,64) for name in GPRS}
        flags={name:z.Bool('rewrite_flag_'+name) for name in ('cf','pf','zf','sf','of')}
        trace.registers=incoming.copy();trace.flags=flags.copy()
        foreign=list(incoming.values())+list(flags.values());trace.variable_names={str(variable):index+10 for index,variable in enumerate(foreign)}
        words=[z.BitVec('rewrite_word_'+str(index),32) for index in range(4)]
        trace.variable_names.update({str(word):index for index,word in enumerate(words)})
        loads={event[0]-0x4000000:index for index,event in enumerate(events)};memory={};code=Code(image)
        original_read,original_write=trace.read,trace.write;reads=[0]
        def read(mu,ins,operand):
            if operand.type!=CS_OP_MEM:return original_read(mu,ins,operand)
            if ins.address in loads:
                assert operand.size==4;reads[0]+=1;return words[loads[ins.address]]
            key=(ins.address+0x4000000,operand.size)
            if key not in memory:
                variable=z.BitVec('rewrite_memory_%x_%d'%key,operand.size*8)
                memory[key]=variable;foreign.append(variable);trace.variable_names[str(variable)]=40+len(memory)
            return memory[key]
        def write(mu,ins,operand,value):
            if operand.type!=CS_OP_MEM:return original_write(mu,ins,operand,value)
        trace.read,trace.write=read,write
        contributions=[];constraints=[]
        for position,event in enumerate(events):
            ordinal=event[1]
            expression=z.substitute(self.reference['contributions'][ordinal],(self.reference['words'][ordinal],words[position]))
            contributions.append(expression);offset,columns=self.planes[ordinal]
            coordinate=z.BitVec('rewrite_domain_%d_%d'%(group,position),8);plane=z.BitVecVal(offset,32)
            for bit,column in enumerate(columns):plane^=z.If(z.Extract(bit,bit,coordinate)==1,z.BitVecVal(column,32),z.BitVecVal(0,32))
            constraints.append(expression==plane)
        combined=z.simplify(reduce(lambda a,b:a^b,contributions));zero_words=[(word,z.BitVecVal(0,32)) for word in words]
        pc=begin;seen={};points=[]
        while pc<end:
            ins=next(trace.decoder.disasm(segment_read(image,pc,16),pc,count=1))
            if pc+ins.size>end or any(ins.group(kind) for kind in (CS_GRP_JUMP,CS_GRP_CALL,CS_GRP_RET)):break
            trace.step(code,pc,ins.size)
            if not trace.active:break
            pc+=ins.size
            if reads[0]!=4:continue
            for name,full in trace.registers.items():
                full=z.simplify(trace.resize(full,32));identifier=full.get_id()
                if identifier in seen:continue
                seen[identifier]=full
                if not set(range(4))<=trace.dependencies(full):continue
                stack=[full];visited=set();valid=True
                while stack:
                    node=stack.pop()
                    if node.get_id() in visited:continue
                    visited.add(node.get_id())
                    if not node.children() and node.decl().kind()==z.Z3_OP_UNINTERPRETED and str(node) not in trace.variable_names:valid=False;break
                    stack.extend(node.children())
                if not valid:continue
                rest=z.simplify(z.substitute(full,*zero_words));claim=full==(combined^rest)
                plausible=True
                for trial in range(2):
                    substitutions=[(variable,z.BoolVal(bool(trial)) if z.is_bool(variable) else z.BitVecVal((trial+1)*0x513729,variable.size())) for variable in foreign]
                    substitutions.extend((word,z.BitVecVal(raw_tables[event[1]][(37*position+73*trial)&255],32)) for position,(word,event) in enumerate(zip(words,events)))
                    if not z.is_true(z.simplify(z.substitute(claim,*substitutions))):plausible=False;break
                if not plausible:continue
                solver=z.Solver();solver.set(timeout=750);solver.add(z.Not(claim));verdict=solver.check()
                mode='unrestricted'
                if verdict!=z.unsat:
                    solver=z.Then('simplify','propagate-values','solve-eqs','simplify','bit-blast','aig','sat').solver()
                    solver.set(timeout=2000);solver.add(z.Not(claim),*constraints);verdict=solver.check();mode='word_planes'
                self.proofs[mode+'_'+str(verdict)]+=1
                if verdict==z.unsat:
                    points.append((pc+0x4000000,dict(group=group,register=name,rest=rest,
                        incoming=incoming,flags=flags,memory=memory.copy())))
        if points:
            self.starts[(group,begin+0x4000000)]=True
            for pc,point in points:self.points.setdefault(pc,[]).append(point)
            self.group_count+=1
        else:self.skipped+=1

    def bind(self,trace,mu):
        original_read=trace.read
        def read(m,instruction,operand):
            result=original_read(m,instruction,operand)
            from capstone import CS_OP_MEM
            if operand.type==CS_OP_MEM and self.active_group in self.contexts:
                self.contexts[self.active_group]['memory'][(instruction.address,operand.size)]=result
            return result
        trace.read=read

    def step(self,trace,mu,pc):
        z=self.z;n=trace.regular_reads;last=(n-1)//4 if n else -1
        for point in self.points.get(pc,()):
            group=point['group']
            if group!=last or group not in self.contexts:continue
            context=self.contexts[group];regular=[event for event in trace.events if event['ordinal']<4]
            events=regular[4*group:4*group+4]
            if len(events)!=4:continue
            substitutions=[(variable,context['registers'][name]) for name,variable in point['incoming'].items()]
            substitutions.extend((variable,context['flags'][name]) for name,variable in point['flags'].items())
            if any(key not in context['memory'] for key in point['memory']):continue
            substitutions.extend((variable,context['memory'][key]) for key,variable in point['memory'].items())
            rest=z.simplify(z.substitute(point['rest'],*substitutions))
            normalized=rest
            for event in events:normalized^=trace.word_expressions[event['variable']]
            name=point['register'];old=trace.registers[name]
            trace.registers[name]=z.simplify(z.Concat(z.Extract(63,32,old),normalized));self.applied+=1
        group=n//4
        if n%4==0 and (group,pc) in self.starts:
            registers={name:trace.reg(mu,name) for name in GPRS}
            if trace.started:flags=trace.flags.copy()
            else:
                value=mu.reg_read(trace.x86.UC_X86_REG_EFLAGS)
                flags={name:z.BoolVal(bool(value&(1<<bit))) for name,bit in (('cf',0),('pf',2),('zf',6),('sf',7),('of',11))}
            self.contexts[group]=dict(registers=registers,flags=flags,memory={});self.active_group=group

    def summary(self):
        return dict(proved_groups=self.group_count,skipped_groups=self.skipped,
            proved_register_points=sum(len(points) for points in self.points.values()),applied_rewrites=self.applied,
            proof_outcomes=dict(self.proofs),scope='source register identities only; every replacement proved unrestricted or under exact validated lookup-word planes; flags and memory effects remain modeled separately; no templates/constants emitted')
