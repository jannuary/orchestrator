"""RAM-only symbolic tracking of an observed native lookup-round path.

No expressions, lookup indices, table values, decoded states or keys are
serialized. The public summary contains code locations and dependency counts.
This is developer evidence for the selected execution, not a runtime emulator.
"""
from collections import Counter
from functools import reduce


class LookupTrace:
    def __init__(self,mu,allocated,regular,final,word_domains=None,maximum_regular_reads=0,normalize_round_indices=False,normalization_timeout_ms=1500,inline_word_domains=False):
        import z3
        from capstone import Cs,CS_ARCH_X86,CS_MODE_64
        from unicorn import x86_const
        self.z=z3;self.x86=x86_const;self.allocated=allocated;self.regular=set(regular);self.final=set(final)
        self.decoder=Cs(CS_ARCH_X86,CS_MODE_64);self.decoder.detail=True;self.cache={}
        self.registers={};self.memory={};self.events=[];self.variables=[];self.values=[]
        self.started=False;self.active=True;self.status='awaiting first lookup';self.errors=[];self.instructions=0
        self.replay_checks=0;self.alias_proofs=0;self.final_reads=0;self.flags={};self.variable_names={}
        self.dependency_cache={};self.concrete_cache={}
        self.word_domains={};self.word_expressions={};self.word_values={};self.opaque_reads=[]
        self.domain_constraints={};self.alias_verdicts=Counter()
        self.maximum_regular_reads=maximum_regular_reads;self.regular_reads=0
        self.normalize_round_indices=normalize_round_indices;self.index_normalizations=Counter()
        self.normalization_timeout_ms=normalization_timeout_ms
        self.word_value_transform=None;self.word_expression_transform=None;self.custom_index_normalizer=None
        self.index_expression_transform=None;self.index_value_transform=None
        self.indexed_word_value_transform=None;self.indexed_word_expression_transform=None
        self.indexed_word_inverse_checks=0
        self.inline_word_domains=inline_word_domains;self.inlined_word_domains=0
        if word_domains is not None:
            from analyze_table_algebra import Basis,independent
            for ordinal,data in (word_domains.items() if isinstance(word_domains,dict) else enumerate(word_domains)):
                words=[int.from_bytes(data[j:j+4],'little') for j in range(0,1024,4)]
                columns=independent([word^words[0] for word in words]);assert len(columns)==8
                self.word_domains[ordinal]=(words[0],columns,Basis(columns))

    def literal(self,value,width):return self.z.BitVecVal(value%(1<<width),width)

    def resize(self,value,width,signed=False):
        old=value.size()
        return (self.z.SignExt(width-old,value) if signed else self.z.ZeroExt(width-old,value)) if old<width else self.z.Extract(width-1,0,value)

    def alias(self,name):
        root={'eax':'rax','ax':'rax','al':'rax','ah':'rax','ebx':'rbx','bx':'rbx','bl':'rbx','bh':'rbx',
              'ecx':'rcx','cx':'rcx','cl':'rcx','ch':'rcx','edx':'rdx','dx':'rdx','dl':'rdx','dh':'rdx',
              'esi':'rsi','si':'rsi','sil':'rsi','edi':'rdi','di':'rdi','dil':'rdi',
              'ebp':'rbp','bp':'rbp','bpl':'rbp','esp':'rsp','sp':'rsp','spl':'rsp'}
        if name in root:
            width=32 if name.startswith('e') else 16 if name in ('ax','bx','cx','dx','si','di','bp','sp') else 8
            return root[name],width,8 if name in ('ah','bh','ch','dh') else 0
        if name.startswith('r') and name[-1:] in ('d','w','b') and name[1:-1].isdigit():
            return name[:-1],{'d':32,'w':16,'b':8}[name[-1]],0
        return name,128 if name.startswith('xmm') else 64,0

    def reg(self,mu,name):
        root,width,offset=self.alias(name)
        if root not in self.registers:
            self.registers[root]=self.literal(mu.reg_read(getattr(self.x86,'UC_X86_REG_'+root.upper())),128 if root.startswith('xmm') else 64)
        return self.z.Extract(offset+width-1,offset,self.registers[root])

    def put_reg(self,mu,name,value):
        root,width,offset=self.alias(name);value=self.resize(value,width);old=self.reg(mu,root)
        if width in (64,128):new=value
        elif width==32:new=self.z.ZeroExt(32,value)
        else:
            pieces=[]
            if old.size()>offset+width:pieces.append(self.z.Extract(old.size()-1,offset+width,old))
            pieces.append(value)
            if offset:pieces.append(self.z.Extract(offset-1,0,old))
            new=self.z.Concat(*pieces) if len(pieces)>1 else pieces[0]
        self.registers[root]=self.z.simplify(new)

    def dependencies(self,expression):
        # z3util.get_vars recursively revisits shared children. Cipher MBA
        # expressions are DAGs; traversing them as trees grows exponentially.
        # Retain AST references with cached IDs so IDs cannot be recycled.
        stack=[(expression,False)]
        while stack:
            node,ready=stack.pop();key=node.get_id()
            if key in self.dependency_cache:continue
            children=node.children()
            if not children:
                variable=self.variable_names.get(str(node))
                result=frozenset() if variable is None else frozenset((variable,))
            elif ready:
                result=frozenset().union(*(self.dependency_cache[child.get_id()][1] for child in children))
            else:
                stack.append((node,True));stack.extend((child,False) for child in children if child.get_id() not in self.dependency_cache);continue
            self.dependency_cache[key]=(node,result)
        return self.dependency_cache[expression.get_id()][1]

    def concrete(self,expression):
        if self.z.is_bv_value(expression):return expression.as_long()
        key=expression.get_id()
        if key in self.concrete_cache:return self.concrete_cache[key][1]
        substitutions=tuple((variable,self.literal(value,variable.size())) for variable,value in zip(self.variables,self.values))
        result=self.z.simplify(self.z.substitute(expression,*substitutions)).as_long()
        self.concrete_cache[key]=(expression,result);return result

    def address(self,mu,instruction,operand):
        mem=operand.mem;result=self.literal(mem.disp,64)
        if mem.base:
            name=instruction.reg_name(mem.base)
            result+=self.literal(instruction.address+instruction.size,64) if name=='rip' else self.resize(self.reg(mu,name),64)
        if mem.index:result+=self.resize(self.reg(mu,instruction.reg_name(mem.index)),64)*mem.scale
        if mem.segment:
            name=instruction.reg_name(mem.segment)
            assert name=='fs';result+=self.literal(mu.reg_read(self.x86.UC_X86_REG_FS_BASE),64)
        return self.z.simplify(result)

    def normalize_index(self,index):
        """Replace a proved byte projection, never a sampled conjecture."""
        z=self.z;upstream=sorted(self.dependencies(index))
        if len(upstream)!=4 or any(j not in self.word_expressions for j in upstream):return index
        variables=[self.word_expressions[j] for j in upstream]
        origin=z.simplify(z.substitute(index,*[(word,self.literal(0,32)) for word in variables]))
        if not z.is_bv_value(origin):return index
        word=reduce(lambda a,b:a^b,variables)
        for byte in range(4):
            candidate=z.simplify(z.Extract(8*byte+7,8*byte,word)^origin)
            # Reject false candidates before asking the solver. These invented
            # assignments are filters only; acceptance still requires UNSAT.
            plausible=True
            for trial in range(2):
                assignment=[(variable,self.literal(((j+1)*0x13579bdf)^(trial*0xa5c3017b),32)) for j,variable in enumerate(variables)]
                difference=z.simplify(z.substitute(index^candidate,*assignment))
                if not z.is_bv_value(difference) or difference.as_long():plausible=False;break
            if not plausible:continue
            solver=z.Solver();solver.set(timeout=self.normalization_timeout_ms);solver.add(index!=candidate)
            verdict=solver.check();self.index_normalizations[str(verdict)]+=1
            if verdict==z.unsat:return candidate
        return index

    def read(self,mu,instruction,operand):
        from capstone import CS_OP_REG,CS_OP_IMM,CS_OP_MEM
        width=operand.size*8
        if operand.type==CS_OP_REG:return self.reg(mu,instruction.reg_name(operand.reg))
        if operand.type==CS_OP_IMM:return self.literal(operand.imm,width)
        assert operand.type==CS_OP_MEM
        address=self.address(mu,instruction,operand);at=self.concrete(address)
        for ordinal,(base,size) in enumerate(self.allocated):
            if width==32 and base<=at<base+1024 and not (at-base)%4:
                index=self.z.simplify(self.z.Extract(7,0,self.z.LShR(address-base,2)))
                raw_index=(at-base)//4
                assert self.concrete(index)==raw_index,'raw lookup index replay mismatch'
                expected_index=raw_index
                assert (self.index_expression_transform is None)==(self.index_value_transform is None)
                if self.index_expression_transform is not None:
                    index=self.z.simplify(self.index_expression_transform(ordinal,index))
                    expected_index=self.index_value_transform(ordinal,raw_index)
                if self.custom_index_normalizer is not None:index=self.custom_index_normalizer(self,index,ordinal)
                if self.normalize_round_indices:index=self.normalize_index(index)
                assert self.concrete(index)==expected_index,'lookup index replay mismatch'
                self.replay_checks+=1;alias=None
                for previous in reversed(self.events):
                    if previous['ordinal']!=ordinal or previous['index']!=expected_index:continue
                    if self.z.eq(index,previous['expression']):alias=previous['variable'];break
                    solver=self.z.Solver();solver.set(timeout=300);solver.add(index!=previous['expression'])
                    verdict=solver.check();self.alias_verdicts['word32_'+str(verdict)]+=1
                    if verdict!=self.z.unsat and self.domain_constraints:
                        upstream=self.dependencies(index)|self.dependencies(previous['expression'])
                        solver=self.z.Then('simplify','propagate-values','solve-eqs','simplify','bit-blast','aig','sat').solver()
                        solver.set(timeout=15000);solver.add(index!=previous['expression'])
                        solver.add(*(self.domain_constraints[j] for j in upstream if j in self.domain_constraints))
                        verdict=solver.check();self.alias_verdicts['domain_'+str(verdict)]+=1
                    if verdict==self.z.unsat:alias=previous['variable'];self.alias_proofs+=1;break
                value=int.from_bytes(mu.mem_read(at,4),'little');raw_word=value
                assert not (self.indexed_word_value_transform and self.word_value_transform)
                if self.indexed_word_value_transform is not None:value=self.indexed_word_value_transform(ordinal,expected_index,value)
                if self.word_value_transform is not None:value=self.word_value_transform(ordinal,value)
                if alias is None:
                    alias=len(self.variables)
                    if ordinal in self.word_domains:
                        offset,columns,basis=self.word_domains[ordinal];variable=self.z.BitVec('lookup_'+str(alias),32)
                        coordinate=value;domain=self.z.BitVec('domain_'+str(alias),8);expression=self.literal(offset,32)
                        for bit,column in enumerate(columns):
                            expression^=self.z.If(self.z.Extract(bit,bit,domain)==1,self.literal(column,32),self.literal(0,32))
                        if self.inline_word_domains:
                            variable=domain;coordinate=basis.coordinates(value^offset)
                            self.word_expressions[alias]=self.z.simplify(expression);self.inlined_word_domains+=1
                        else:
                            self.domain_constraints[alias]=(variable==self.z.simplify(expression))
                            self.word_expressions[alias]=variable
                    else:
                        variable=self.z.BitVec('lookup_'+str(alias),32);coordinate=value;self.word_expressions[alias]=variable
                    self.variables.append(variable);self.values.append(coordinate);self.variable_names[str(variable)]=alias
                    self.word_values[alias]=value
                else:assert self.word_values[alias]==value,'aliased lookup replay mismatch'
                self.events.append(dict(pc=instruction.address,ordinal=ordinal,index=expected_index,
                                        expression=index,variable=alias,dependencies=self.dependencies(index)))
                if ordinal in self.final:self.final_reads+=1
                if ordinal in self.regular:self.regular_reads+=1
                if self.final_reads==16:self.active=False;self.status='complete first block'
                elif self.maximum_regular_reads and self.regular_reads>=self.maximum_regular_reads:
                    self.active=False;self.status='complete requested regular-lookup prefix'
                expression=self.word_expressions[alias]
                if self.indexed_word_expression_transform is not None:
                    assert self.word_expression_transform is None
                    restored=self.indexed_word_expression_transform(ordinal,index,expression)
                    assert self.concrete(restored)==raw_word,'indexed word inverse replay mismatch'
                    self.indexed_word_inverse_checks+=1
                    return restored
                return self.word_expression_transform(ordinal,expression) if self.word_expression_transform is not None else expression
        if self.dependencies(address) and width==8 and 0x10000000<=at<0x100cf9f8:
            # A readonly byte substitution can be interleaved with the last
            # word lookups. Keep it symbolic rather than concretizing a
            # data-dependent read; this is an observed-path developer model.
            alias=len(self.variables);variable=self.z.BitVec('image_byte_'+str(alias),8)
            self.variables.append(variable);self.values.append(mu.mem_read(at,1)[0]);self.variable_names[str(variable)]=alias
            self.opaque_reads.append(dict(pc=hex(instruction.address),width=1));return variable
        assert not self.dependencies(address),'unmodeled data-dependent ordinary-memory read'
        concrete=bytes(mu.mem_read(at,operand.size))
        return self.z.Concat(*(self.memory.get(at+j,self.literal(concrete[j],8)) for j in reversed(range(operand.size)))) if operand.size>1 else self.memory.get(at,self.literal(concrete[0],8))

    def write(self,mu,instruction,operand,value):
        from capstone import CS_OP_REG,CS_OP_MEM
        value=self.resize(value,operand.size*8)
        if operand.type==CS_OP_REG:self.put_reg(mu,instruction.reg_name(operand.reg),value);return
        assert operand.type==CS_OP_MEM
        address=self.address(mu,instruction,operand);assert not self.dependencies(address),'unmodeled data-dependent memory store'
        at=self.concrete(address)
        for j in range(operand.size):self.memory[at+j]=self.z.simplify(self.z.Extract(8*j+7,8*j,value))

    def arithmetic_flags(self,a,b,result,subtract=False,carry=None):
        z=self.z;n=a.size();wide=(z.ZeroExt(1,a)-z.ZeroExt(1,b) if subtract else z.ZeroExt(1,a)+z.ZeroExt(1,b))
        carry_word=z.If(carry,self.literal(1,n+1),self.literal(0,n+1)) if carry is not None else self.literal(0,n+1)
        if carry is not None:wide=wide-carry_word if subtract else wide+carry_word
        sign=lambda x:z.Extract(n-1,n-1,x)
        self.flags['cf']=z.ULT(z.ZeroExt(1,a),z.ZeroExt(1,b)+carry_word) if subtract else z.Extract(n,n,wide)==1
        self.flags['of']=z.And(sign(a)!=sign(b),sign(result)!=sign(a)) if subtract else z.And(sign(a)==sign(b),sign(result)!=sign(a))
        self.result_flags(result)

    def result_flags(self,result):
        z=self.z;self.flags['zf']=result==0;self.flags['sf']=z.Extract(result.size()-1,result.size()-1,result)==1
        self.flags['pf']=z.Not(reduce(z.Xor,(z.Extract(i,i,result)==1 for i in range(8))))

    def condition(self,mnemonic):
        f=self.flags;z=self.z;condition=mnemonic.replace('cmov','').replace('set','')
        return {'e':lambda:f['zf'],'z':lambda:f['zf'],'ne':lambda:z.Not(f['zf']),'nz':lambda:z.Not(f['zf']),
                'b':lambda:f['cf'],'c':lambda:f['cf'],'ae':lambda:z.Not(f['cf']),'nc':lambda:z.Not(f['cf']),
                'a':lambda:z.And(z.Not(f['cf']),z.Not(f['zf'])),'be':lambda:z.Or(f['cf'],f['zf']),
                's':lambda:f['sf'],'ns':lambda:z.Not(f['sf']),'o':lambda:f['of'],'no':lambda:z.Not(f['of']),
                'l':lambda:f['sf']!=f['of'],'ge':lambda:f['sf']==f['of'],
                'g':lambda:z.And(z.Not(f['zf']),f['sf']==f['of']),'le':lambda:z.Or(f['zf'],f['sf']!=f['of'])}[condition]()

    def step(self,mu,pc,size,user=None):
        if not self.active:return
        try:
            z=self.z
            if not self.started:
                self.started=True;self.status='tracing';flags=mu.reg_read(self.x86.UC_X86_REG_EFLAGS)
                self.flags={name:z.BoolVal(bool(flags&(1<<bit))) for name,bit in (('cf',0),('pf',2),('zf',6),('sf',7),('of',11))}
            instruction=self.cache.get(pc)
            if instruction is None:instruction=next(self.decoder.disasm(bytes(mu.mem_read(pc,size)),pc));self.cache[pc]=instruction
            self.instructions+=1;mnemonic=instruction.mnemonic;operands=instruction.operands
            if mnemonic in ('nop','jmp') or mnemonic.startswith('j'):return
            if mnemonic in ('mov','movabs','movzx','movsx','movsxd'):
                value=self.read(mu,instruction,operands[1]);self.write(mu,instruction,operands[0],self.resize(value,operands[0].size*8,mnemonic in ('movsx','movsxd')));return
            if mnemonic=='lea':self.write(mu,instruction,operands[0],self.address(mu,instruction,operands[1]));return
            if mnemonic.startswith('set'):
                self.write(mu,instruction,operands[0],z.If(self.condition(mnemonic),self.literal(1,8),self.literal(0,8)));return
            if mnemonic.startswith('cmov'):
                self.write(mu,instruction,operands[0],z.If(self.condition(mnemonic),self.read(mu,instruction,operands[1]),self.read(mu,instruction,operands[0])));return
            a=self.read(mu,instruction,operands[0]);n=a.size()
            if mnemonic in ('neg','not','inc','dec','bswap'):
                result={'neg':lambda:-a,'not':lambda:~a,'inc':lambda:a+1,'dec':lambda:a-1,
                        'bswap':lambda:z.Concat(*(z.Extract(j+7,j,a) for j in range(0,n,8)))}[mnemonic]()
                if mnemonic=='neg':self.arithmetic_flags(self.literal(0,n),a,result,True)
                elif mnemonic in ('inc','dec'):
                    cf=self.flags['cf'];self.arithmetic_flags(a,self.literal(1,n),result,mnemonic=='dec');self.flags['cf']=cf
            else:
                b=self.resize(self.read(mu,instruction,operands[1]),n)
                if mnemonic in ('add','sub','adc','sbb','cmp'):
                    carry=self.flags['cf'] if mnemonic in ('adc','sbb') else None;subtract=mnemonic in ('sub','sbb','cmp')
                    result=a-b if subtract else a+b
                    if carry is not None:
                        carry_word=z.If(carry,self.literal(1,n),self.literal(0,n))
                        result=result-carry_word if subtract else result+carry_word
                    self.arithmetic_flags(a,b,result,subtract,carry)
                    if mnemonic=='cmp':return
                elif mnemonic in ('xor','and','or','test'):
                    result={'xor':lambda:a^b,'and':lambda:a&b,'or':lambda:a|b,'test':lambda:a&b}[mnemonic]()
                    self.flags['cf']=self.flags['of']=z.BoolVal(False);self.result_flags(result)
                    if mnemonic=='test':return
                elif mnemonic=='imul':
                    if len(operands)==3:a=b;b=self.resize(self.read(mu,instruction,operands[2]),n,True)
                    result=a*b;wide=z.SignExt(n,a)*z.SignExt(n,b)
                    self.flags['cf']=self.flags['of']=wide!=z.SignExt(n,result)
                    for flag in ('zf','sf','pf'):self.flags[flag]=z.Bool('undefined_'+flag+'_'+str(self.instructions))
                elif mnemonic in ('shl','sal','shr','sar','rol','ror','shrd','shld'):
                    if mnemonic in ('shrd','shld'):
                        c=self.resize(self.read(mu,instruction,operands[2]),n)&(63 if n==64 else 31)
                        result=z.Extract(n-1,0,z.LShR(z.Concat(b,a),z.ZeroExt(n,c))) if mnemonic=='shrd' else z.Extract(2*n-1,n,z.Concat(a,b)<<z.ZeroExt(n,c))
                    else:
                        c=b&(63 if n==64 else 31)
                        result={'shl':lambda:a<<c,'sal':lambda:a<<c,'shr':lambda:z.LShR(a,c),'sar':lambda:a>>c,
                                'rol':lambda:z.RotateLeft(a,c),'ror':lambda:z.RotateRight(a,c)}[mnemonic]()
                    if mnemonic in ('rol','ror'):
                        c=c&(n-1)
                        self.flags['cf']=z.If(c==0,self.flags['cf'],z.Extract(0,0,result)==1 if mnemonic=='rol' else z.Extract(n-1,n-1,result)==1)
                    else:
                        cf=z.Extract(0,0,z.LShR(a,c-1))==1 if mnemonic in ('shr','sar','shrd') else z.Extract(n-1,n-1,a<<(c-1))==1
                        old_result_flags={name:self.flags[name] for name in ('zf','sf','pf')}
                        self.flags['cf']=z.If(c==0,self.flags['cf'],cf);self.result_flags(result)
                        for name,old in old_result_flags.items():self.flags[name]=z.If(c==0,old,self.flags[name])
                    # OF is undefined for multi-bit shifts; reject its use by
                    # keeping a distinct symbolic flag, rather than guessing.
                    defined_of=(z.Xor(z.Extract(n-1,n-1,result)==1,self.flags['cf']) if mnemonic in ('rol','shl','sal','shld') else
                                z.Extract(n-1,n-1,result)!=z.Extract(n-2,n-2,result) if mnemonic=='ror' else
                                z.BoolVal(False) if mnemonic=='sar' else
                                z.Extract(n-1,n-1,a)!=z.Extract(n-1,n-1,result) if mnemonic=='shrd' else z.Extract(n-1,n-1,a)==1)
                    self.flags['of']=z.If(c==0,self.flags['of'],z.If(c==1,defined_of,z.Bool('undefined_of_'+str(self.instructions))))
                else:raise ValueError('unsupported instruction '+mnemonic)
            self.write(mu,instruction,operands[0],z.simplify(result))
        except Exception as error:
            self.active=False;self.status='unsupported observed path';self.errors.append(dict(pc=hex(pc),kind=type(error).__name__,operation=instruction.mnemonic if 'instruction' in locals() else 'decode'))

    def summary(self):
        return dict(status=self.status,instructions=self.instructions,lookup_occurrences=len(self.events),
                    distinct_lookup_values=len(self.word_values),symbolic_index_replay_checks=self.replay_checks,
                    proven_lookup_aliases=self.alias_proofs,final_lookup_reads=self.final_reads,errors=self.errors,
                    alias_proof_outcomes=dict(self.alias_verdicts),
                    byte_projection_normalization_outcomes=dict(self.index_normalizations),
                    word_output_domains_constrained=len(self.word_domains),symbolic_readonly_byte_reads=self.opaque_reads,
                    requested_regular_lookup_limit=self.maximum_regular_reads,
                    upstream_dependency_counts=dict(Counter(len(event['dependencies']) for event in self.events)),
                    sites=[dict(pc=hex(event['pc']),table=event['ordinal'],value=event['variable'],
                                upstream_values=sorted(event['dependencies'])) for event in self.events],
                    private_expressions_and_values_emitted=False,
                    scope='symbolic data flow for the observed first-block path; not universal execution or complete cipher/key/auth validation')
