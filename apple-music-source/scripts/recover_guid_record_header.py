"""Recover bounded arithmetic of the GUID record's first 32 byte updates.

All memory/register inputs are invented. Symbolic byte parameters and record
bytes remain in RAM. Reports contain only PCs, operand roles and universally
proved arithmetic forms; no device/private buffers or opaque tables.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random

from scan_auth_substitutions import TARGETS
from verify_fill_dispatch import segment_read
from trace_lookup_dataflow import LookupTrace


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('checkout',type=Path);p.add_argument('--output',type=Path,required=True);args=p.parse_args()
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_64,UC_HOOK_CODE
    from unicorn import x86_const as r
    from capstone import Cs,CS_ARCH_X86,CS_MODE_64,CS_OP_MEM
    import z3 as z
    name,digest=TARGETS['corefp'];image=(args.checkout/'rootfs/system/lib64'/name).read_bytes();assert hashlib.sha256(image).hexdigest()==digest
    begin,end=0x2fa8d0,0x2fb47d;code=segment_read(image,begin,end-begin)
    decoder=Cs(CS_ARCH_X86,CS_MODE_64);decoder.detail=True;instructions=list(decoder.disasm(code,begin));assert sum(i.size for i in instructions)==len(code)
    offsets=sorted({op.mem.disp for i in instructions for op in i.operands if op.type==CS_OP_MEM and op.size==1 and i.reg_name(op.mem.base)=='rbp'})
    mu=Uc(UC_ARCH_X86,UC_MODE_64);mu.mem_map(0x2fa000,8192);mu.mem_write(begin,code)
    frame,buffer,length_pointer=0x90010800,0x90020000,0x90030000
    for address in (frame&~4095,buffer,length_pointer):mu.mem_map(address,4096)
    rng=random.Random(0x61533);mu.mem_write(frame-0x400,bytes(rng.randrange(256) for _ in range(0x400)))
    mu.mem_write(frame-0x158,((buffer-0xc18e2b1f7b8a47ec)&0xffffffffffffffff).to_bytes(8,'little'));mu.mem_write(length_pointer,(147^0x30b1a88a).to_bytes(4,'little'));mu.mem_write(buffer,bytes([0x72])*200)
    mu.reg_write(r.UC_X86_REG_RBP,frame);mu.reg_write(r.UC_X86_REG_R13,length_pointer);mu.reg_write(r.UC_X86_REG_R8,0xc18e2b1f7b8a47ec);mu.reg_write(r.UC_X86_REG_R9,1<<32)
    trace=LookupTrace(mu,[],[],[]);variables={};values={}
    for role,address in [(('frame',off),frame+off) for off in offsets]+[(('record',i),buffer+i) for i in range(32)]:
        v=z.BitVec(f'{role[0]}_{abs(role[1])}',8);index=len(trace.variables);trace.variables.append(v);trace.values.append(mu.mem_read(address,1)[0]);trace.variable_names[str(v)]=index;trace.memory[address]=v;variables[role]=v;values[index]=role
    cache={i.address:i for i in instructions};divisions=[0]
    def step(uc,pc,size,user):
        i=cache[pc]
        if i.mnemonic=='div':
            divisor=trace.read(uc,i,i.operands[0]);low=trace.reg(uc,'eax');high=trace.reg(uc,'edx')
            assert not (trace.dependencies(divisor)|trace.dependencies(low)|trace.dependencies(high))
            numerator=(trace.concrete(high)<<32)|trace.concrete(low);q,rem=divmod(numerator,trace.concrete(divisor));assert q<1<<32
            trace.put_reg(uc,'eax',trace.literal(q,32));trace.put_reg(uc,'edx',trace.literal(rem,32));divisions[0]+=1
        else:trace.step(uc,pc,size)
    hook=mu.hook_add(UC_HOOK_CODE,step);mu.emu_start(begin,end,count=4096);mu.hook_del(hook);assert trace.active and not trace.errors,trace.summary()
    rows=[]
    for index in range(32):
        expression=trace.memory[buffer+index];assert trace.concrete(expression)==mu.mem_read(buffer+index,1)[0]
        roles=[values[i] for i in sorted(trace.dependencies(expression))];frame_roles=[role for role in roles if role[0]=='frame'];record_roles=[role for role in roles if role[0]=='record'];assert record_roles==[('record',index)],roles
        old=variables[('record',index)];clear=expression^0x47;old_clear=old^0x47
        row=dict(record_offset=index,frame_offsets=[hex(-role[1]) for role in frame_roles],universal_form=None)
        if len(frame_roles)<=1:
            parameter=variables[frame_roles[0]] if frame_roles else None
            def evaluate(value):
                subs=[(old,z.BitVecVal(0x47,8))]+([] if parameter is None else [(parameter,z.BitVecVal(value,8))])
                result=z.simplify(z.substitute(clear,*subs));assert z.is_bv_value(result);return result.as_long()
            samples=[evaluate(i) for i in range(256)] if parameter is not None else [evaluate(0)]
            candidates=[]
            if parameter is None:candidates=[(None,samples[0],z.BitVecVal(samples[0],8))]
            else:
                for mask in range(256):
                    constant=(samples[0]-mask)&255
                    if all(samples[x]==((x^mask)+constant)&255 for x in range(256)):
                        candidates.append((mask,constant,(parameter^mask)+constant))
            for mask,constant,tweak in candidates:
                solver=z.Solver();solver.set(timeout=10000);solver.add(clear!=old_clear+tweak)
                if solver.check()==z.unsat:
                    row['universal_form']=dict(operation='add_to_clear_record',parameter_xor=mask,add_constant=constant,proof='UNSAT');break
        if row['universal_form'] is None:
            sums={8:([(0x3e,1),(0x3d,1)],0x81),15:([(0xcb,1),(0xca,1)],0x92),19:([(0xc9,1),(0xc8,1),(0x34,1),(0x35,-1)],0x94),20:([(0x3a,1),(0x39,1)],4),29:([(0xcf,1),(0xce,1)],0x3e),30:([(0x2a,1),(0x37,-1)],0xc1)}
            if index in sums:
                terms,constant=sums[index];tweak=z.BitVecVal(constant,8)
                for off,sign in terms:tweak+=sign*variables[('frame',-off)]
                form=dict(operation='add_scalar_sum',terms=[dict(frame_offset=hex(off),coefficient=sign) for off,sign in terms],add_constant=constant)
            elif index==18:
                x=variables[('frame',-0xb8)];tweak=x+((42-2*x)&238)+44
                form=dict(operation='add_shaped_byte',frame_offset='0xb8',formula='x + ((42 - 2*x) & 238) + 44')
            else:raise AssertionError(index)
            solver=z.Solver();solver.set(timeout=10000);solver.add(clear!=old_clear+tweak);verdict=solver.check();assert verdict==z.unsat,(index,str(verdict));form['proof']='UNSAT';row['universal_form']=form
        rows.append(row)
    def increment(row,parameters):
        form=row['universal_form'];operation=form['operation']
        if operation=='add_to_clear_record':
            value=0 if not row['frame_offsets'] else parameters[int(row['frame_offsets'][0],16)]^form['parameter_xor']
            return (value+form['add_constant'])&255
        if operation=='add_scalar_sum':return (sum(term['coefficient']*parameters[int(term['frame_offset'],16)] for term in form['terms'])+form['add_constant'])&255
        x=parameters[0xb8];return (x+((42-2*x)&238)+44)&255
    length_checks=0
    for length in range(80,201):
        parameters={-off:rng.randrange(256) for off in offsets}
        for off,value in parameters.items():mu.mem_write(frame-off,bytes([value]))
        mu.mem_write(frame-0x158,((buffer-0xc18e2b1f7b8a47ec)&0xffffffffffffffff).to_bytes(8,'little'));mu.mem_write(length_pointer,(length^0x30b1a88a).to_bytes(4,'little'))
        original=bytes(rng.randrange(256) for _ in range(200));mu.mem_write(buffer,original)
        mu.reg_write(r.UC_X86_REG_RBP,frame);mu.reg_write(r.UC_X86_REG_R13,length_pointer);mu.reg_write(r.UC_X86_REG_R8,0xc18e2b1f7b8a47ec);mu.reg_write(r.UC_X86_REG_R9,1<<32)
        mu.emu_start(begin,end,count=4096)
        expected=bytearray(original)
        for row in rows:
            index=row['record_offset'];expected[index]=(((original[index]^0x47)+increment(row,parameters))&255)^0x47
        assert bytes(mu.mem_read(buffer,200))==expected,length;length_checks+=1
    report=dict(status='record-header arithmetic recovered' if all(x['universal_form'] for x in rows) else 'bounded record-header dataflow captured',artifact_sha256=digest,original_interval=[hex(begin),hex(end)],instructions=trace.instructions+divisions[0],concrete_index_divisions=divisions[0],independent_frame_byte_parameters=len(offsets),record_bytes=len(rows),all_native_output_lengths_checked=length_checks,whole_output_and_suffix_compared=True,universally_normalized_bytes=sum(x['universal_form'] is not None for x in rows),bytes=rows,network_requests=0,private_material_written=False,scope='universal byte arithmetic at length 147 plus whole-output original execution over all 121 native record lengths; scalar parameter origins and whole first GUID/auth remain unresolved')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps({k:v for k,v in report.items() if k!='bytes'}))


if __name__=='__main__':main()
