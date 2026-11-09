"""Reconstruct one live CoreFP four-lookup register-result combination.

Only operand arithmetic is modeled. Memory writes, permissions and faults are
outside this model. Arrays, expressions and fitted parameters stay in RAM.
"""
import argparse
import ctypes as C
import hashlib
import json
from pathlib import Path
import random
import subprocess
import sys
import tempfile

from classify_runtime_tables import rank
from probe_substitution_equivalence import SEARCH,investigate
from recover_guid_word_consumers import GPRS,Code
from scan_auth_substitutions import TARGETS
from trace_lookup_dataflow import LookupTrace
from verify_fill_dispatch import segment_read


BEGIN,END=0x3bd20a,0x3bd2c9
LOADS=((0x3bd20a,0xe5950),(0x3bd236,0x262ce0),(0x3bd265,0x903a0),(0x3bd2a5,0x27cff0))
COLUMNS={
 'corefp_3bd20a':(BEGIN,END,LOADS,'r9',[(0x3bd287,8)]),
 'corefp_6523aa':(0x6523aa,0x65246f,((0x6523aa,0x40590),(0x6523bc,0xd45e0),(0x6523cc,0x297190),(0x6523fa,0x215d00)),'rcx',[]),
 'storeservices_1f8249':(0x1f8249,0x1f8442,((0x1f8249,0x9d1d0),(0x1f82d6,0xa0370),(0x1f8407,0x9ff40),(0x1f8411,0x9fa10)),'rdx',[]),
 'storeservices_2316f0':(0x2316f0,0x23198c,((0x2316f0,0x9a1a0),(0x231701,0x9c500),(0x231773,0x9a6f0),(0x23197a,0x9de30)),'r11',[(0x23172d,4),(0x231796,4),(0x231824,4),(0x231941,4),(0x23194a,8),(0x231951,8),(0x231955,8)]),
}


def model(image,column='corefp_3bd20a'):
    from capstone import CS_OP_MEM,CS_GRP_JUMP,CS_GRP_CALL,CS_GRP_RET
    trace=LookupTrace(None,[],[],[]);z=trace.z;trace.started=True
    incoming={name:z.BitVec('input_'+name,64) for name in GPRS}
    flags={name:z.Bool('input_flag_'+name) for name in ('cf','pf','zf','sf','of')}
    trace.registers=incoming.copy();trace.flags=flags.copy()
    words=[z.BitVec('word_'+str(index),32) for index in range(4)]
    trace.variable_names={str(word):index for index,word in enumerate(words)}
    foreign=list(incoming.values())+list(flags.values())
    trace.variable_names.update({str(variable):index+10 for index,variable in enumerate(foreign)})
    begin,end,loads,output,expected_stores=COLUMNS[column]
    read_base,write_base=trace.read,trace.write;stores=[];memory_inputs={};indices={};frame_values={};forwarded_reads=set()
    forward_frame=column=='storeservices_2316f0'
    def read(mu,ins,operand):
        if operand.type==CS_OP_MEM:
            if ins.address in dict(loads):
                assert operand.size==4
                indices[ins.address]=trace.reg(mu,ins.reg_name(operand.mem.index))
                return words[next(index for index,(pc,_) in enumerate(loads) if pc==ins.address)]
            key=(ins.address,operand.size)
            if forward_frame and ins.reg_name(operand.mem.base)=='rbp' and not operand.mem.index:
                offset=operand.mem.disp
                for (start,width),expression in frame_values.items():
                    if start<=offset and offset+operand.size<=start+width:
                        forwarded_reads.add(key)
                        return z.Extract(8*(offset-start+operand.size)-1,8*(offset-start),expression)
            if key not in memory_inputs:
                variable=z.BitVec('memory_%x_%d'%key,operand.size*8)
                memory_inputs[key]=variable;foreign.append(variable);trace.variable_names[str(variable)]=40+len(memory_inputs)
            return memory_inputs[key]
        return read_base(mu,ins,operand)
    def write(mu,ins,operand,value):
        if operand.type==CS_OP_MEM:
            stores.append((ins.address,operand.size))
            if forward_frame:
                assert ins.reg_name(operand.mem.base)=='rbp' and not operand.mem.index
                offset=operand.mem.disp
                assert not any(start<offset+operand.size and offset<start+width for start,width in frame_values),'overlapping symbolic frame stores'
                frame_values[offset,operand.size]=trace.resize(value,operand.size*8)
            return
        return write_base(mu,ins,operand,value)
    trace.read,trace.write=read,write;code=Code(image);pc=begin
    while pc<end:
        ins=next(trace.decoder.disasm(segment_read(image,pc,16),pc,count=1))
        assert pc+ins.size<=end
        assert not any(ins.group(group) for group in (CS_GRP_JUMP,CS_GRP_CALL,CS_GRP_RET))
        trace.step(code,pc,ins.size);assert trace.active and not trace.errors
        pc+=ins.size
    assert pc==end and stores==expected_stores
    full=z.simplify(trace.resize(trace.registers[output],32))
    stack=[full];seen=set()
    while stack:
        node=stack.pop()
        if node.get_id() in seen:continue
        seen.add(node.get_id())
        if not node.children() and node.decl().kind()==z.Z3_OP_UNINTERPRETED:
            assert str(node) in trace.variable_names,'unmodeled internal flag or value'
        stack.extend(node.children())
    zero_words=[(word,z.BitVecVal(0,32)) for word in words]
    zero_foreign=[(variable,z.BoolVal(False) if z.is_bool(variable) else z.BitVecVal(0,variable.size())) for variable in foreign]
    origin=z.simplify(z.substitute(full,*(zero_words+zero_foreign)))
    contributions=[]
    for index in range(4):
        substitutions=zero_foreign+[(word,z.BitVecVal(0,32)) for j,word in enumerate(words) if j!=index]
        contributions.append(z.simplify(z.substitute(full,*substitutions)^origin))
    rest=z.simplify(z.substitute(full,*zero_words));combined=rest
    for contribution in contributions:combined^=contribution
    solver=z.Solver();solver.set(timeout=15000);solver.add(full!=combined)
    verdict=str(solver.check())
    missing=rest
    for contribution in contributions[1:]:missing^=contribution
    control=z.Solver();control.set(timeout=15000);control.add(full!=missing)
    negative=str(control.check())
    return dict(z=z,full=full,words=words,incoming=incoming,flags=flags,contributions=contributions,
                proof=verdict,omitted_contribution_control=negative,instructions=trace.instructions,foreign_dependencies=len(trace.dependencies(rest)),stores=len(stores),
                begin=begin,end=end,loads=loads,output_register=output,memory_inputs=memory_inputs,index_expressions=indices,forwarded_reads=forwarded_reads)


def execute_original(image,tables,analysis):
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_64,UC_HOOK_MEM_READ,UC_HOOK_MEM_READ_UNMAPPED
    from unicorn import x86_const as r
    from capstone import Cs,CS_ARCH_X86,CS_MODE_64,CS_OP_MEM
    from inventory_guid_word_tables import root
    decoder=Cs(CS_ARCH_X86,CS_MODE_64);decoder.detail=True
    begin,end,loads,output=(analysis[name] for name in ('begin','end','loads','output_register'))
    first=next(decoder.disasm(segment_read(image,begin,16),begin,count=1))
    memory=next(operand.mem for operand in first.operands if operand.type==CS_OP_MEM)
    base_name=first.reg_name(memory.base);index_name=first.reg_name(memory.index)
    assert base_name in GPRS and index_name in GPRS and base_name!=index_name
    initial_indices=set();initial_bases={};written=set()
    for ins in decoder.disasm(segment_read(image,begin,end-begin),begin):
        if ins.address in dict(loads):
            mem=next(operand.mem for operand in ins.operands if operand.type==CS_OP_MEM)
            base_reg,index_reg=root(ins.reg_name(mem.base)),root(ins.reg_name(mem.index))
            if index_reg not in written:initial_indices.add(index_reg)
            if base_reg not in written:initial_bases[base_reg]=(dict(loads)[ins.address]-mem.disp)&((1<<64)-1)
        written.update(root(ins.reg_name(register)) for register in ins.regs_access()[1])
    mu=Uc(UC_ARCH_X86,UC_MODE_64);mapped=set()
    def map_range(begin,end):
        for page in range(begin&~4095,(end+4095)&~4095,4096):
            if page not in mapped:mu.mem_map(page,4096);mapped.add(page)
    map_range(begin,end);mu.mem_write(begin,segment_read(image,begin,end-begin))
    for _,base in loads:map_range(base,base+1024)
    stack=0x90000000;map_range(stack,stack+0x10000)
    selected=[0]*4;reads=[];extra_values={}
    def read(m,kind,address,width,value,user):
        pc=m.reg_read(r.UC_X86_REG_RIP)
        if pc in dict(loads):
            assert width==4
            index=next(index for index,(site,_) in enumerate(loads) if site==pc)
            m.mem_write(address,selected[index].to_bytes(4,'little'));reads.append(pc)
        else:
            if (pc,width) in analysis.get('forwarded_reads',set()):return
            assert (pc,width) in extra_values
            m.mem_write(address,extra_values[(pc,width)].to_bytes(width,'little'))
    mu.hook_add(UC_HOOK_MEM_READ,read)
    def missing(m,kind,address,width,value,user):
        # This is a word-argument differential harness, not a real caller or
        # table-bound check. Map only expected read operands; never permit an
        # unexpected instruction or memory operation to continue.
        pc=m.reg_read(r.UC_X86_REG_RIP)
        assert (pc in dict(loads) and width==4) or (pc,width) in extra_values
        map_range(address,address+width)
        return True
    mu.hook_add(UC_HOOK_MEM_READ_UNMAPPED,missing)
    rng=random.Random(0x441587);trials=[]
    trials.extend([[tables[j][(index+37*j)%256] for j in range(4)] for index in range(256)])
    trials.extend([[rng.getrandbits(32) for _ in range(4)] for _ in range(128)])
    trials.extend([[value]*4 for value in (0,1,0x7fffffff,0x80000000,0xffffffff)])
    z=analysis['z']
    for trial in trials:
        selected[:]=trial;reads.clear()
        incoming={name:rng.getrandbits(32) for name in GPRS}
        incoming.update(initial_bases)
        for name in initial_indices:incoming[name]=0
        incoming['rbp']=stack+0x8000
        extra_values.clear();extra_values.update({key:rng.getrandbits(key[1]*8) for key in analysis['memory_inputs']})
        initial_flags=2|rng.randrange(2)
        for name,value in incoming.items():mu.reg_write(getattr(r,'UC_X86_REG_'+name.upper()),value)
        mu.reg_write(r.UC_X86_REG_EFLAGS,initial_flags)
        mu.emu_start(begin,end,count=analysis['instructions']+8)
        substitutions=[(analysis['incoming'][name],z.BitVecVal(value,64)) for name,value in incoming.items()]
        substitutions.extend((analysis['flags'][name],z.BoolVal(bool(initial_flags&(1<<bit)))) for name,bit in (('cf',0),('pf',2),('zf',6),('sf',7),('of',11)))
        substitutions.extend((word,z.BitVecVal(value,32)) for word,value in zip(analysis['words'],trial))
        substitutions.extend((variable,z.BitVecVal(extra_values[key],key[1]*8)) for key,variable in analysis['memory_inputs'].items())
        expected=z.simplify(z.substitute(analysis['full'],*substitutions)).as_long()
        assert mu.reg_read(getattr(r,'UC_X86_REG_'+output.upper()))&0xffffffff==expected and reads==[pc for pc,_ in loads]
    return len(trials)


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path)
    parser.add_argument('--column',choices=COLUMNS,default='corefp_3bd20a')
    parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    target='storeservices' if args.column.startswith('storeservices_') else 'corefp'
    filename,digest=TARGETS[target];image=(args.checkout/'rootfs/system/lib64'/filename).read_bytes()
    assert hashlib.sha256(image).hexdigest()==digest
    analysis=model(image,args.column);tables=[];loads=analysis['loads']
    for _,base in loads:
        data=segment_read(image,base,1024);tables.append([int.from_bytes(data[j:j+4],'little') for j in range(0,1024,4)])
    comparisons=execute_original(image,tables,analysis)
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.crypto.aes import _gpow
    from analyze_table_algebra import independent
    inverse=(C.c_uint8*256)(*(_gpow(value,254) if value else 0 for value in range(256)))
    rows=[];spaces=[];z=analysis['z'];arrays=[]
    with tempfile.TemporaryDirectory(prefix='ams-guid-column-') as directory:
        source,library=Path(directory)/'classify.c',Path(directory)/'classify.so';source.write_text(SEARCH)
        subprocess.run(['cc','-std=c99','-O3','-shared','-fPIC',str(source),'-o',str(library)],check=True,capture_output=True)
        search=C.CDLL(str(library)).equivalent
        search.argtypes=[C.POINTER(C.c_uint8),C.POINTER(C.c_uint8),C.POINTER(C.c_uint64),C.POINTER(C.c_uint8),C.POINTER(C.c_uint8)];search.restype=C.c_int
        for index,(words,contribution) in enumerate(zip(tables,analysis['contributions'])):
            decoded=[z.simplify(z.substitute(contribution,(analysis['words'][index],z.BitVecVal(value,32)))).as_long() for value in words]
            space=independent([value^decoded[0] for value in decoded]);spaces.extend(space)
            arrays.append(b''.join(value.to_bytes(4,'little') for value in decoded))
            rows.append(dict(source_load=hex(loads[index][0]),source_table=hex(loads[index][1]),affine_rank=len(space),
                distinct_words=len(set(decoded)),classification=investigate(decoded,search,inverse)))
    from analyze_round_substitutions import analyze
    coherent=analyze(arrays,range(4)) if all(row['affine_rank']==8 for row in rows) else None
    report=dict(status='one source GUID cipher-column investigation',column=args.column,artifact_sha256=digest,source_begin=hex(analysis['begin']),source_end=hex(analysis['end']),
        source_instructions=analysis['instructions'],xor_decomposition_proof=analysis['proof'],
        original_instruction_comparisons=comparisons,additional_input_dependencies=analysis['foreign_dependencies'],
        additional_memory_read_inputs=len(analysis['memory_inputs']),omitted_contribution_counterexample=analysis['omitted_contribution_control'],
        excluded_memory_stores=analysis['stores'],word_contributions=rows,combined_word_space_rank=rank(spaces),coherent_substitutions=coherent,
        scope='register result of one straight-line four-lookup combination, parameterized by returned words; original trials map expected read operands to supplied words and vary remaining inputs, without establishing real-call reachability or table bounds; memory stores and permission/fault semantics excluded; no whole cipher, table initializer, recovered parameters or native-auth provider; words/expressions/maps RAM-only')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
