"""Find constant-base word lookups around observed GUID cipher read sites.

Only same-basic-block reaching definitions are admitted. This is a bounded
static inventory, not a claim that every indexed region is a complete table.
Values, immediate pools and cryptographic intermediates stay in RAM.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import sys

from scan_auth_substitutions import TARGETS, readonly_segments
from verify_fill_dispatch import segment_read


def root(name):
    if name.startswith('r') and name[-1:] in ('d', 'w', 'b') and name[1:-1].isdigit():
        return name[:-1]
    return {'eax':'rax','ax':'rax','al':'rax','ah':'rax', 'ebx':'rbx','bx':'rbx','bl':'rbx','bh':'rbx',
            'ecx':'rcx','cx':'rcx','cl':'rcx','ch':'rcx', 'edx':'rdx','dx':'rdx','dl':'rdx','dh':'rdx',
            'esi':'rsi','si':'rsi','sil':'rsi','edi':'rdi','di':'rdi','dil':'rdi',
            'ebp':'rbp','bp':'rbp','bpl':'rbp','esp':'rsp','sp':'rsp','spl':'rsp'}.get(name,name)


def constant_before(instructions, position, register, depth=0):
    from capstone import CS_OP_IMM, CS_OP_REG, CS_OP_MEM, CS_GRP_JUMP, CS_GRP_CALL, CS_GRP_RET
    if depth > 12:return None
    for index in range(position - 1, max(-1, position - 65), -1):
        ins = instructions[index]
        if ins.address+ins.size!=instructions[index+1].address:return None
        if any(ins.group(group) for group in (CS_GRP_JUMP, CS_GRP_CALL, CS_GRP_RET)):return None
        written = {root(ins.reg_name(reg)) for reg in ins.regs_access()[1]}
        if register not in written:continue
        operands = ins.operands
        if not operands or operands[0].type != CS_OP_REG or root(ins.reg_name(operands[0].reg)) != register or operands[0].size not in (4,8):return None
        width = operands[0].size * 8
        if ins.mnemonic in ('mov','movabs') and operands[1].type == CS_OP_IMM:
            return operands[1].imm % (1 << width)
        if ins.mnemonic == 'mov' and operands[1].type == CS_OP_REG:
            value = constant_before(instructions,index,root(ins.reg_name(operands[1].reg)),depth+1)
            return None if value is None else value % (1 << width)
        if ins.mnemonic == 'lea' and operands[1].type == CS_OP_MEM:
            mem=operands[1].mem;value=mem.disp
            for reg,scale in ((mem.base,1),(mem.index,mem.scale)):
                if not reg:continue
                part=ins.address+ins.size if ins.reg_name(reg)=='rip' else constant_before(instructions,index,root(ins.reg_name(reg)),depth+1)
                if part is None:return None
                value+=part*scale
            return value % (1 << width)
        if ins.mnemonic in ('add','sub','xor') and operands[1].type == CS_OP_IMM:
            value=constant_before(instructions,index,register,depth+1)
            if value is None:return None
            immediate=operands[1].imm
            return {'add':lambda:value+immediate,'sub':lambda:value-immediate,'xor':lambda:value^immediate}[ins.mnemonic]() % (1 << width)
        return None
    return None


def translated_instructions(checkout,image,decoder,target,begin,end):
    source_module='ssc' if target=='storeservices' else target
    pcs=set()
    for page in range(begin>>16,((end-1)>>16)+1):
        path=checkout/'crypto/auth/mescal/generated'/('mescal_%s_page_%x.c'%(source_module,page))
        if path.exists():
            pcs.update(int(value,16) for value in re.findall(r'kg_pc_[0-9a-f]+: STEP\(0x([0-9a-f]+)\)',path.read_text()))
    instructions=[]
    for pc in sorted(pc for pc in pcs if begin<=pc<end):
        ins=next(decoder.disasm(segment_read(image,pc,16),pc,count=1))
        assert ins.address==pc
        instructions.append(ins)
    return instructions


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('checkout',type=Path)
    parser.add_argument('--read-sites',type=Path,required=True)
    parser.add_argument('--function-ranges',type=Path,required=True)
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args()
    from capstone import Cs,CS_ARCH_X86,CS_MODE_64,CS_OP_MEM
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from classify_runtime_tables import rank
    decoder=Cs(CS_ARCH_X86,CS_MODE_64);decoder.detail=True
    read_sites=json.loads(args.read_sites.read_text());functions=json.loads(args.function_ranges.read_text())
    rows=[]
    for module in functions['rows']:
        target=module['target'];bias=0x4000000 if target=='corefp' else 0
        filename,digest=TARGETS[target];image=(args.checkout/'rootfs/system/lib64'/filename).read_bytes()
        assert hashlib.sha256(image).hexdigest()==digest
        readonly=readonly_segments(image,4)
        sites={int(site['pc'],16)-bias for window in read_sites['windows'] if read_sites['target_names'][str(window['target'])]==target for site in window['sites']}
        tables={};ranges=[]
        for function in module['fde_ranges']:
            begin,end=(int(function[name],16) for name in ('begin','end'))
            if end-begin>0x20000:
                relevant=[site for site in sites if begin<=site<end]
                begin,end=max(begin,min(relevant)-0x300),min(end,max(relevant)+0x300)
            # Obfuscated functions contain skipped data islands. Linear
            # disassembly can stop there or invent misaligned instructions.
            # Use existing translated instruction boundaries, validating each
            # instruction against the pinned ELF, and reject cross-gap defs.
            instructions=translated_instructions(args.checkout,image,decoder,target,begin,end)
            ranges.append(dict(begin=hex(begin),end=hex(end),instructions=len(instructions)))
            for position,ins in enumerate(instructions):
                for operand in ins.operands:
                    if operand.type!=CS_OP_MEM or operand.size!=4 or not operand.mem.index or operand.mem.scale!=4:continue
                    if not operand.mem.base or ins.reg_name(operand.mem.base)=='rip':continue
                    base=constant_before(instructions,position,root(ins.reg_name(operand.mem.base)))
                    if base is None:continue
                    base=(base+operand.mem.disp) % (1<<64)
                    if not any(address<=base and base+1024<=address+len(data) for address,data in readonly):continue
                    tables.setdefault(base,set()).add(ins.address)
        found=[]
        for base,uses in sorted(tables.items()):
            data=segment_read(image,base,1024)
            words=[int.from_bytes(data[j:j+4],'little') for j in range(0,1024,4)]
            found.append(dict(elf_virtual_address=hex(base),source_load_sites=[hex(pc) for pc in sorted(uses)],
                              raw_affine_rank=rank([word^words[0] for word in words]),distinct_words=len(set(words))))
        rows.append(dict(target=target,artifact_sha256=digest,scanned_ranges=ranges,candidate_tables=found))
    report=dict(status='bounded constant-base word-lookup inventory',rows=rows,
        scope='static same-basic-block reaching definitions at translated instruction boundaries validated against pinned ELF around live GUID cipher ranges; not complete use coverage, table declarations, full cipher or auth closure; no values or immediate constants emitted')
    args.output.write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(dict(status=report['status'],modules=[dict(target=row['target'],candidate_tables=len(row['candidate_tables'])) for row in rows])))


if __name__=='__main__':main()
