"""Prove inverses of source-derived word contributions without table data.

Only source instructions contribute to the inverses. Original artifacts are
hashed for identity; no lookup words, fitted byte maps or keys are consumed.
All expressions, offsets and source-derived binary matrices stay in RAM.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random

from analyze_guid_column import model,COLUMNS
from analyze_table_algebra import Basis,apply,independent
from scan_auth_substitutions import TARGETS
from verify_fill_dispatch import segment_read


def bit_map(z,columns,value):
    result=z.BitVecVal(0,32)
    for bit,column in enumerate(columns):
        if column:result^=z.If(z.Extract(bit,bit,value)==1,z.BitVecVal(column,32),z.BitVecVal(0,32))
    return z.simplify(result)


def recover(analysis,image,inverse_callback=None,allow_multiplication=False):
    from capstone import Cs,CS_ARCH_X86,CS_MODE_64,CS_OP_IMM
    decoder=Cs(CS_ARCH_X86,CS_MODE_64);decoder.detail=True
    offsets={0};rotations={0};multipliers={1};z=analysis['z'];rng=random.Random(0x452781);rows=[]
    for ins in decoder.disasm(segment_read(image,analysis['begin'],analysis['end']-analysis['begin']),analysis['begin']):
        for operand in ins.operands:
            if operand.type!=CS_OP_IMM:continue
            value=operand.imm&0xffffffff
            if allow_multiplication and ins.mnemonic=='imul' and value&1:multipliers.add(value)
            offsets.update(value_&0xffffffff for value_ in (value,-value,value>>1,-(value>>1),value^0x80000000,(value>>1)^0x80000000))
            if ins.mnemonic in ('rol','ror','shrd','shld'):
                rotations.update((value%32,(-value)%32))
    offsets=[0]+sorted(offsets-{0});rotations=[0]+sorted(rotations-{0})
    for index,expression in enumerate(analysis['contributions']):
        word=analysis['words'][index];count=0;proofs={};found=False
        def evaluate(value):return z.simplify(z.substitute(expression,(word,z.BitVecVal(value&0xffffffff,32)))).as_long()
        def rotate_right(value,rotation):return ((value>>rotation)|(value<<((32-rotation)%32)))&0xffffffff
        word_multipliers=sorted(multipliers) if allow_multiplication else [1]
        # Reuse the proven rotation/addition family on a modular-multiply
        # coordinate. Odd multiplication is a bijection over word32.
        if allow_multiplication and word_multipliers!=[1]:
            multiplied=False;stack=[expression];seen=set()
            while stack:
                node=stack.pop()
                if node.get_id() in seen:continue
                seen.add(node.get_id());multiplied|=node.decl().kind()==z.Z3_OP_BMUL;stack.extend(node.children())
            if not multiplied:word_multipliers=[1]
        original_evaluate=evaluate
        for multiplier in word_multipliers:
          inverse_multiplier=pow(multiplier,-1,1<<32)
          def evaluate(value):return original_evaluate((value*inverse_multiplier)&0xffffffff)
          for rotation in rotations:
            for offset in offsets:
                count+=1;origin=evaluate(rotate_right((-offset)&0xffffffff,rotation))
                columns=[evaluate(rotate_right(((1<<bit)-offset)&0xffffffff,rotation))^origin for bit in range(32)]
                if len(independent(columns))!=32:continue
                plausible=True
                for _ in range(4):
                    sample=rng.getrandbits(32)
                    if evaluate(rotate_right((sample-offset)&0xffffffff,rotation))^origin!=apply(columns,sample):plausible=False;break
                if not plausible:continue
                coordinate=z.BitVec('source_coordinate_'+str(index),32)
                before=z.RotateRight(coordinate-z.BitVecVal(offset,32),rotation)*z.BitVecVal(inverse_multiplier,32)
                shifted=z.simplify(z.substitute(expression,(word,before)))
                forward=bit_map(z,columns,coordinate)^z.BitVecVal(origin,32)
                solver=z.Solver();solver.set(timeout=15000);solver.add(shifted!=forward)
                verdict=solver.check();proofs[str(verdict)]=proofs.get(str(verdict),0)+1
                if verdict!=z.unsat:continue
                basis=Basis(columns);inverse_columns=[basis.coordinates(1<<bit) for bit in range(32)]
                assert all(apply(inverse_columns,column)==1<<bit for bit,column in enumerate(columns))
                assert all(apply(columns,column)==1<<bit for bit,column in enumerate(inverse_columns))
                lemma=z.Solver();lemma.add(z.RotateLeft(before*z.BitVecVal(multiplier,32),rotation)+z.BitVecVal(offset,32)!=coordinate)
                assert lemma.check()==z.unsat
                encoded=z.BitVec('encoded_word_'+str(index),32)
                inverse=z.simplify(z.RotateRight(bit_map(z,inverse_columns,encoded^z.BitVecVal(origin,32))-z.BitVecVal(offset,32),rotation)*z.BitVecVal(inverse_multiplier,32))
                reverse=z.Solver();reverse.set(timeout=1000);reverse.add(z.substitute(expression,(word,inverse))!=encoded)
                inverse_verdict=reverse.check()
                assert inverse_verdict!=z.sat,'direct inverse contradicts proved coordinate form and exact inverses'
                if inverse_callback is not None:inverse_callback(index,encoded,inverse)
                rows.append(dict(word=index,status='proved source-only word inverse',hypotheses_checked=count,
                    source_form_proofs=proofs,inverse_composition_check=str(inverse_verdict),
                    inverse_proof='source-coordinate UNSAT, exact 64 matrix-basis checks, odd-multiply/rotation/addition cancellation UNSAT',
                    source_odd_multiply_supported=multiplier!=1,private_parameters_emitted=False))
                found=True;break
            if found:break
          if found:break
        if not found:rows.append(dict(word=index,status='no proved inverse in source-derived form family',hypotheses_checked=count,source_form_proofs=proofs))
    return dict(source_offset_candidates=len(offsets),source_rotation_candidates=len(rotations),source_multiplier_candidates=len(multipliers),words=rows,
        scope='odd-multiply/rotation/addition/binary-linear form inferred from source operations and proved over word32; no lookup data or fitted cryptographic byte encoding; all offsets/matrices/expressions RAM-only')


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path)
    parser.add_argument('--column',choices=COLUMNS,default='corefp_3bd20a');parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();filename,digest=TARGETS['corefp']
    image=(args.checkout/'rootfs/system/lib64'/filename).read_bytes();assert hashlib.sha256(image).hexdigest()==digest
    analysis=model(image,args.column);assert analysis['proof']=='unsat'
    report=dict(status='source-only GUID word inverse investigation',column=args.column,artifact_sha256=digest,**recover(analysis,image))
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
