"""Recognize verified register-only word decoders on GUID lookup paths.

All word arrays, expressions, normalizations and fitted maps stay in RAM.
This recovers operand semantics, not a table initializer or auth provider.
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
from scan_auth_substitutions import TARGETS
from trace_lookup_dataflow import LookupTrace
from verify_fill_dispatch import segment_read


GPRS=('rax','rbx','rcx','rdx','rsi','rdi','rbp','rsp','r8','r9','r10','r11','r12','r13','r14','r15')


class Code:
    def __init__(self,image):self.image=image
    def mem_read(self,address,size):return segment_read(self.image,address,size)
    def reg_read(self,register):raise ValueError('unmodeled incoming register')


def candidates(image,load_pc):
    from capstone import CS_OP_MEM,CS_OP_REG,CS_GRP_JUMP,CS_GRP_CALL,CS_GRP_RET
    trace=LookupTrace(None,[],[],[]);z=trace.z;trace.started=True
    trace.registers={name:z.BitVec('input_'+name,64) for name in GPRS}
    trace.variable_names={str(variable):j+1 for j,variable in enumerate(trace.registers.values())}
    trace.flags={name:z.Bool('input_flag_'+name) for name in ('cf','pf','zf','sf','of')}
    trace.variable_names.update({str(variable):j+17 for j,variable in enumerate(trace.flags.values())})
    word=z.BitVec('word',32);trace.variable_names[str(word)]=0
    code=Code(image)
    load=next(trace.decoder.disasm(segment_read(image,load_pc,16),load_pc,count=1))
    if load.mnemonic!='mov' or load.operands[0].type!=CS_OP_REG or load.operands[0].size!=4 or load.operands[1].type!=CS_OP_MEM:return
    destination=load.reg_name(load.operands[0].reg)
    trace.put_reg(code,destination,word)
    pc=load_pc+load.size;begin=pc;seen=set()
    for _ in range(64):
        ins=next(trace.decoder.disasm(segment_read(image,pc,16),pc,count=1))
        if any(ins.group(group) for group in (CS_GRP_JUMP,CS_GRP_CALL,CS_GRP_RET)):break
        if ins.mnemonic in ('push','pop','leave') or (ins.mnemonic!='lea' and any(operand.type==CS_OP_MEM for operand in ins.operands)):break
        trace.step(code,pc,ins.size)
        if not trace.active:break
        pc+=ins.size
        for name,expression in trace.registers.items():
            expression=z.simplify(trace.resize(expression,32))
            if expression.get_id() in seen:continue
            seen.add(expression.get_id())
            if trace.dependencies(expression)==frozenset((0,)):
                yield dict(z=z,word=word,expression=expression,begin=begin,end=pc,output_register=name,input_register=destination)


def verify_original(image,words,candidate):
    from unicorn import Uc,UC_ARCH_X86,UC_MODE_64
    from unicorn import x86_const as r
    z=candidate['z'];word=candidate['word'];expression=candidate['expression']
    begin,end=candidate['begin'],candidate['end'];mu=Uc(UC_ARCH_X86,UC_MODE_64)
    page=begin&~4095;mu.mem_map(page,((end+4095)&~4095)-page)
    mu.mem_write(begin,segment_read(image,begin,end-begin))
    rng=random.Random(0x784321);trials=words+[rng.getrandbits(32) for _ in range(128)]
    for value in trials:
        for name in GPRS:mu.reg_write(getattr(r,'UC_X86_REG_'+name.upper()),rng.getrandbits(64))
        mu.reg_write(r.UC_X86_REG_EFLAGS,2|(rng.randrange(2)))
        mu.reg_write(getattr(r,'UC_X86_REG_'+candidate['input_register'].upper()),value)
        mu.emu_start(begin,end,count=128)
        expected=z.simplify(z.substitute(expression,(word,z.BitVecVal(value,32)))).as_long()
        assert mu.reg_read(getattr(r,'UC_X86_REG_'+candidate['output_register'].upper()))&0xffffffff==expected
    return len(trials)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout',type=Path)
    parser.add_argument('--inventory',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args()
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.crypto.aes import _gpow
    inverse=(C.c_uint8*256)(*(_gpow(value,254) if value else 0 for value in range(256)))
    inventory=json.loads(args.inventory.read_text());modules=[]
    with tempfile.TemporaryDirectory(prefix='ams-guid-word-consumers-') as directory:
        source,library=Path(directory)/'classify.c',Path(directory)/'classify.so'
        source.write_text(SEARCH)
        subprocess.run(['cc','-std=c99','-O3','-shared','-fPIC',str(source),'-o',str(library)],check=True,capture_output=True)
        search=C.CDLL(str(library)).equivalent
        search.argtypes=[C.POINTER(C.c_uint8),C.POINTER(C.c_uint8),C.POINTER(C.c_uint64),C.POINTER(C.c_uint8),C.POINTER(C.c_uint8)];search.restype=C.c_int
        for module in inventory['rows']:
            filename,digest=TARGETS[module['target']]
            image=(args.checkout/'rootfs/system/lib64'/filename).read_bytes()
            assert hashlib.sha256(image).hexdigest()==module['artifact_sha256']==digest
            tables=[]
            for table in module['candidate_tables']:
                if table['distinct_words']!=256 or table['raw_affine_rank']==8:continue
                base=int(table['elf_virtual_address'],16);data=segment_read(image,base,1024)
                words=[int.from_bytes(data[j:j+4],'little') for j in range(0,1024,4)]
                result=dict(elf_virtual_address=hex(base),raw_affine_rank=table['raw_affine_rank'],status='no supported normalization found',tested_expressions=0)
                found=False
                for pc in table['source_load_sites'][:4]:
                    for candidate in candidates(image,int(pc,16)):
                        result['tested_expressions']+=1
                        z=candidate['z'];word=candidate['word'];expression=candidate['expression']
                        normalized=[z.simplify(z.substitute(expression,(word,z.BitVecVal(value,32)))).as_long() for value in words]
                        if len(set(normalized))!=256 or rank([value^normalized[0] for value in normalized])!=8:continue
                        other=z.BitVec('other_word',32);solver=z.Solver();solver.set(timeout=3000)
                        solver.add(word!=other,expression==z.substitute(expression,(word,other)))
                        if solver.check()!=z.unsat:continue
                        classified=investigate(normalized,search,inverse)
                        if not classified.get('affine_equivalent_to_gf256_inversion'):continue
                        comparisons=verify_original(image,words,candidate)
                        result.update(status='verified source word decoder',source_load=pc,
                            source_decoder_begin=hex(candidate['begin']),source_decoder_end=hex(candidate['end']),
                            source_output_register=candidate['output_register'],full_word_injectivity_proved=True,
                            normalized_affine_rank=8,original_instruction_comparisons=comparisons,
                            independent_full_table_reconstruction_checks=classified['independent_full_table_reconstruction_checks'])
                        found=True;break
                    if found:break
                tables.append(result)
            modules.append(dict(target=module['target'],artifact_sha256=digest,tables=tables))
    report=dict(status='bounded source word-consumer recovery',modules=modules,
        scope='register-only decoder prefixes at statically inventoried load sites; every positive is globally injective over word32 and matches original prefix execution; not a table initializer, complete cipher, key recovery or auth implementation; all words, expressions, offsets and maps RAM-only')
    args.output.write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(dict(status=report['status'],modules=[dict(target=module['target'],word_tables=len(module['tables']),
        verified_decoders=sum(table['status']=='verified source word decoder' for table in module['tables'])) for module in modules])))


if __name__=='__main__':main()
