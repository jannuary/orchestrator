"""Prove isolated lookup-word XOR contributions in mixed register prefixes.

No expressions, words, offsets, register states or fitted maps are emitted.
This is developer analysis, not an installed cipher or authentication provider.
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


def components(image,load_pc):
    from capstone import CS_OP_MEM,CS_OP_REG,CS_GRP_JUMP,CS_GRP_CALL,CS_GRP_RET
    trace=LookupTrace(None,[],[],[]);z=trace.z;trace.started=True
    incoming={name:z.BitVec('input_'+name,64) for name in GPRS}
    flags={name:z.Bool('input_flag_'+name) for name in ('cf','pf','zf','sf','of')}
    trace.registers=incoming.copy();trace.flags=flags.copy()
    foreign=list(incoming.values())+list(flags.values())
    trace.variable_names={str(variable):j+1 for j,variable in enumerate(foreign)}
    word=z.BitVec('word',32);trace.variable_names[str(word)]=0;code=Code(image)
    first=next(trace.decoder.disasm(segment_read(image,load_pc,16),load_pc,count=1))
    if first.operands[0].type!=CS_OP_REG or first.operands[0].size!=4:return
    if first.mnemonic not in ('mov','xor','add','sub','and','or','imul'):return
    memory=[operand for operand in first.operands[1:] if operand.type==CS_OP_MEM]
    if len(memory)!=1 or memory[0].size!=4:return
    original_read=trace.read
    def read(mu,ins,operand):
        if ins.address==load_pc and operand.type==CS_OP_MEM:return word
        return original_read(mu,ins,operand)
    trace.read=read
    zero_foreign=[(variable,z.BoolVal(False) if z.is_bool(variable) else z.BitVecVal(0,variable.size())) for variable in foreign]
    pc=load_pc;seen={}
    for step in range(64):
        ins=next(trace.decoder.disasm(segment_read(image,pc,16),pc,count=1))
        if any(ins.group(group) for group in (CS_GRP_JUMP,CS_GRP_CALL,CS_GRP_RET)):break
        if ins.mnemonic in ('push','pop','leave'):break
        if step and ins.mnemonic!='lea' and any(operand.type==CS_OP_MEM for operand in ins.operands):break
        trace.step(code,pc,ins.size)
        if not trace.active:break
        pc+=ins.size
        for name,full in trace.registers.items():
            full=z.simplify(trace.resize(full,32));identifier=full.get_id()
            if identifier in seen:continue
            seen[identifier]=full
            dependencies=trace.dependencies(full)
            if 0 not in dependencies or len(dependencies)==1:continue
            # An undefined flag created inside the prefix is not an incoming
            # independent parameter. Its value may change with the word;
            # refuse any result that uses it rather than guessing semantics.
            stack=[full];visited=set();recognized=True
            while stack:
                node=stack.pop()
                if node.get_id() in visited:continue
                visited.add(node.get_id())
                if not node.children() and node.decl().kind()==z.Z3_OP_UNINTERPRETED and str(node) not in trace.variable_names:
                    recognized=False;break
                stack.extend(node.children())
            if not recognized:continue
            alone=z.simplify(z.substitute(full,*zero_foreign))
            origin=z.simplify(z.substitute(alone,(word,z.BitVecVal(0,32))))
            contribution=z.simplify(alone^origin)
            rest=z.simplify(z.substitute(full,(word,z.BitVecVal(0,32))))
            yield dict(z=z,word=word,expression=contribution,full=full,rest=rest,
                begin=load_pc,end=pc,output_register=name,incoming=incoming,flags=flags,load=first,
                separability_claim=full==(contribution^rest))


def prove(candidate,timeout_ms=3000):
    z=candidate['z'];solver=z.Solver();solver.set(timeout=timeout_ms)
    solver.add(z.Not(candidate['separability_claim']))
    return str(solver.check())


def verify_original(image,words,candidate):
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_64
    from unicorn import x86_const as r
    from capstone import CS_OP_MEM
    z=candidate['z'];word=candidate['word'];expression=candidate['expression']
    load=candidate['load'];operand=next(op for op in load.operands if op.type==CS_OP_MEM);mem=operand.mem
    if not mem.base or load.reg_name(mem.base)=='rip' or mem.segment:return None
    base_name=load.reg_name(mem.base);index_name=load.reg_name(mem.index) if mem.index else None
    if base_name not in GPRS or index_name==base_name:return None
    begin,end=candidate['begin'],candidate['end'];page=begin&~4095
    mu=Uc(UC_ARCH_X86,UC_MODE_64);mu.mem_map(page,((end+4095)&~4095)-page)
    data_page=0x80000000;mu.mem_map(data_page,4096);data_address=data_page+0x100
    mu.mem_write(begin,segment_read(image,begin,end-begin))
    rng=random.Random(0x754231);trials=words+[rng.getrandbits(32) for _ in range(128)]
    for value in trials:
        incoming={name:rng.getrandbits(64) for name in GPRS}
        incoming[base_name]=(data_address-mem.disp)&((1<<64)-1)
        if index_name:incoming[index_name]=0
        flags=2|rng.randrange(2);outputs=[]
        for input_word in (value,0):
            for name,initial in incoming.items():mu.reg_write(getattr(r,'UC_X86_REG_'+name.upper()),initial)
            mu.reg_write(r.UC_X86_REG_EFLAGS,flags);mu.mem_write(data_address,input_word.to_bytes(4,'little'))
            mu.emu_start(begin,end,count=128)
            outputs.append(mu.reg_read(getattr(r,'UC_X86_REG_'+candidate['output_register'].upper()))&0xffffffff)
        expected=z.simplify(z.substitute(expression,(word,z.BitVecVal(value,32)))).as_long()
        assert outputs[0]^outputs[1]==expected
    return len(trials)*2


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout',type=Path);parser.add_argument('--inventory',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.crypto.aes import _gpow
    inverse=(C.c_uint8*256)(*(_gpow(x,254) if x else 0 for x in range(256)))
    inventory=json.loads(args.inventory.read_text());modules=[]
    with tempfile.TemporaryDirectory(prefix='ams-guid-xor-components-') as directory:
        source,library=Path(directory)/'classify.c',Path(directory)/'classify.so';source.write_text(SEARCH)
        subprocess.run(['cc','-std=c99','-O3','-shared','-fPIC',str(source),'-o',str(library)],check=True,capture_output=True)
        search=C.CDLL(str(library)).equivalent
        search.argtypes=[C.POINTER(C.c_uint8),C.POINTER(C.c_uint8),C.POINTER(C.c_uint64),C.POINTER(C.c_uint8),C.POINTER(C.c_uint8)];search.restype=C.c_int
        for module in inventory['rows']:
            filename,digest=TARGETS[module['target']];image=(args.checkout/'rootfs/system/lib64'/filename).read_bytes()
            assert hashlib.sha256(image).hexdigest()==module['artifact_sha256']==digest
            tables=[]
            for table in module['candidate_tables']:
                if table['distinct_words']!=256 or table['raw_affine_rank']==8:continue
                data=segment_read(image,int(table['elf_virtual_address'],16),1024)
                words=[int.from_bytes(data[j:j+4],'little') for j in range(0,1024,4)]
                result=dict(elf_virtual_address=table['elf_virtual_address'],status='no proved supported XOR component',tested_expressions=0,proof_outcomes={})
                found=False
                for load_pc in table['source_load_sites'][:4]:
                    for candidate in components(image,int(load_pc,16)):
                        result['tested_expressions']+=1;z=candidate['z'];word=candidate['word'];expression=candidate['expression']
                        normalized=[z.simplify(z.substitute(expression,(word,z.BitVecVal(value,32)))).as_long() for value in words]
                        if len(set(normalized))!=256 or rank([value^normalized[0] for value in normalized])!=8:continue
                        verdict=prove(candidate);result['proof_outcomes'][verdict]=result['proof_outcomes'].get(verdict,0)+1
                        if verdict!='unsat':continue
                        classified=investigate(normalized,search,inverse)
                        if not classified.get('affine_equivalent_to_gf256_inversion'):continue
                        comparisons=verify_original(image,words,candidate)
                        if comparisons is None:continue
                        result.update(status='proved source XOR component',source_load=load_pc,source_prefix_end=hex(candidate['end']),
                            output_register=candidate['output_register'],original_prefix_executions=comparisons,
                            independent_full_table_reconstruction_checks=classified['independent_full_table_reconstruction_checks'])
                        found=True;break
                    if found:break
                tables.append(result)
            modules.append(dict(target=module['target'],artifact_sha256=digest,tables=tables))
    report=dict(status='bounded lookup-word XOR component recovery',modules=modules,
        scope='register-only prefixes; every positive proves F(word,other)=G(word) XOR F(0,other) over all input states and compares original instruction execution; not a whole word decoder, table initializer, cipher or auth provider; words/expressions/maps remain RAM-only')
    args.output.write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(dict(status=report['status'],modules=[dict(target=module['target'],proved_components=sum(table['status']=='proved source XOR component' for table in module['tables'])) for module in modules])))


if __name__=='__main__':main()
