"""Prove a source lookup-index identity without exporting image constants.

This is an offline developer proof, not an initializer or runtime provider.
Original readonly words, symbolic expressions and address biases stay in RAM.
Only source locations, solver outcomes and counts enter the result.
"""
import hashlib
import struct

from verify_fill_dispatch import segment_read
from verify_integrity_codec import HASH


class IndexProof:
    def __init__(self,raw):
        from capstone import Cs,CS_ARCH_X86,CS_MODE_64
        from capstone.x86_const import X86_OP_MEM,X86_REG_RIP
        assert hashlib.sha256(raw).hexdigest()==HASH
        self.raw=raw;self.decoder=Cs(CS_ARCH_X86,CS_MODE_64);self.decoder.detail=True
        self.mem_kind=X86_OP_MEM;self.rip=X86_REG_RIP;self.cache={};self.models={}
        self.instructions=list(self.decoder.disasm(segment_read(raw,0x52c006,0xbe),0x52c006))
        assert self.instructions[-1].address+self.instructions[-1].size==0x52c0c4
        assert all(i.mnemonic in ('movd','pxor','pshufd','por','movdqa','paddd','pand','psubd') for i in self.instructions)
        self.r8=self.instruction(0x52bf2f).operands[1].imm&255
        self.seed_xor=self.instruction(0x52bee7).operands[1].imm&255
        replacement=self.constant(self.instruction(0x52bf27).operands[1],self.instruction(0x52bf27))
        mask=self.constant(self.instruction(0x52bf50).operands[1],self.instruction(0x52bf50))
        shuffle=self.constant_bytes(self.instruction(0x52bfe1))
        comparison=self.constant_bytes(self.instruction(0x52bfea))
        self.blend_guard=(list(shuffle[:4])==[0,4,8,12] and
                          all(comparison[j]==(replacement[j]&255) for j in range(4)))
        assert self.blend_guard,'the conditional replacement must preserve the selected low byte'
        assert mask==[255]*4,'the following model is a byte-domain identity'

    def instruction(self,pc):
        return next(self.decoder.disasm(segment_read(self.raw,pc,16),pc))

    def constant_bytes(self,instruction):
        operand=next(o for o in instruction.operands if o.type==self.mem_kind)
        assert operand.mem.base==self.rip and operand.mem.index==0
        return segment_read(self.raw,instruction.address+instruction.size+operand.mem.disp,16)

    def constant(self,operand,instruction):
        assert operand.type==self.mem_kind and operand.mem.base==self.rip and operand.mem.index==0
        return list(struct.unpack('<4I',self.constant_bytes(instruction)))

    def prove(self,raw_bias,store_bias):
        import z3 as z
        key=(raw_bias&255,store_bias&255)
        if key in self.cache:return self.cache[key]
        value=z.BitVec('index',8);seed4=z.BitVec('seed4',8);seed8=z.BitVec('seed8',8)
        fixed=lambda values:[z.BitVecVal(x&255,8) for x in values]
        registers={'xmm12':[value]*4,'xmm6':[value]*4,'xmm1':[value]*4,
                   'xmm3':[seed8^self.seed_xor]*4,'xmm4':[seed4]*4,
                   'xmm8':[seed8]+fixed([0]*3)}
        for name,pc in (('xmm7',0x52bf27),('xmm9',0x52bf50),('xmm11',0x52bf59)):
            instruction=self.instruction(pc);registers[name]=fixed(self.constant(instruction.operands[1],instruction))
        for instruction in self.instructions:
            operands=instruction.operands;name=instruction.reg_name(operands[0].reg);mnemonic=instruction.mnemonic
            if mnemonic=='movd':
                assert name=='xmm0' and instruction.reg_name(operands[1].reg)=='r8d'
                registers[name]=fixed([self.r8,0,0,0]);continue
            source=(fixed(self.constant(operands[1],instruction)) if operands[1].type==self.mem_kind
                    else registers[instruction.reg_name(operands[1].reg)])
            if mnemonic=='pshufd':
                control=operands[2].imm;registers[name]=[source[(control>>(2*j))&3] for j in range(4)];continue
            if mnemonic=='movdqa':registers[name]=list(source);continue
            left=registers[name]
            operations={'pxor':lambda a,b:a^b,'por':lambda a,b:a|b,'pand':lambda a,b:a&b,
                        'paddd':lambda a,b:a+b,'psubd':lambda a,b:a-b}
            registers[name]=[operations[mnemonic](a,b) for a,b in zip(left,source)]
        store=self.instruction(0x52c19c);store_constants=fixed(self.constant(store.operands[1],store))
        differences=[];fixed_terms=[];indices=[];identities=[]
        for lane in range(4):
            raw_index=registers['xmm0'][lane]+key[0]
            store_index=(value^store_constants[lane])+key[1]
            expression=raw_index^store_index^seed4^seed8
            indices.append((raw_index,store_index));identities.append(expression)
            fixed_term=z.simplify(z.substitute(expression,(value,z.BitVecVal(0,8)),
                                              (seed4,z.BitVecVal(0,8)),(seed8,z.BitVecVal(0,8))))
            fixed_terms.append(fixed_term);differences.append(expression!=fixed_term)
        solver=z.Solver();solver.set(timeout=10000);solver.add(z.Or(*differences))
        verdict=solver.check()
        negative_controls=[]
        for missing_seed in (seed4,seed8):
            solver=z.Solver();solver.set(timeout=10000)
            solver.add(z.Or(*(expression^missing_seed!=fixed_term for expression,fixed_term in zip(identities,fixed_terms))))
            negative_controls.append(str(solver.check()))
        result=dict(status=str(verdict),source_interval='0x1052c006..0x1052c0c4',
                    conditional_blend_preserves_low_byte=self.blend_guard,
                    source_seed_relation='low XMM3 = low XMM8 XOR immediate at 0x1052bee7; XMM4 is broadcast',
                    identity='raw_index XOR store_index XOR low(XMM4) XOR low(XMM8) is constant',
                    symbolic_input_bits=24,lanes=4,arithmetic_instructions=len(self.instructions),
                    all_lanes_share_constant=all(z.is_true(z.simplify(k==fixed_terms[0])) for k in fixed_terms),
                    omitted_seed_negative_controls=negative_controls,
                    constants_emitted=False,
                    scope='byte-index arithmetic and source selector guard only; normalized pointer biases are parameters; not fixed substitution, cipher, key, SPC or auth closure')
        self.models[key]=(value,seed4,seed8,indices);self.cache[key]=result;return result

    def verify_observations(self,raw_bias,store_bias,observations,index_map):
        import z3 as z
        key=(raw_bias&255,store_bias&255)
        self.prove(*key);value,seed4,seed8,indices=self.models[key]
        raw_matches=store_matches=0
        for raw_index,source_value,source_seed4,source_seed8,lane in observations:
            substitutions=((value,z.BitVecVal(source_value,8)),(seed4,z.BitVecVal(source_seed4,8)),
                           (seed8,z.BitVecVal(source_seed8,8)))
            predicted_raw,predicted_store=(z.simplify(z.substitute(expression,*substitutions)).as_long()
                                           for expression in indices[lane])
            raw_matches+=predicted_raw==raw_index
            store_matches+=predicted_store==index_map[raw_index]
        return dict(observed_indices=len(observations),raw_index_matches=raw_matches,store_index_matches=store_matches)
