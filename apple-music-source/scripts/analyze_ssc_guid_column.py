"""Normalize the index-dependent StoreServices GUID column in RAM.

The source retains functions of two input indices alongside table words.
Those functions must be removed before testing AES table structure. No
normalization, table, key or encoding bytes are emitted by this tool.
"""
import argparse
import hashlib
import json
from pathlib import Path
import sys

from analyze_guid_column import model,execute_original
from analyze_round_substitutions import analyze as analyze_substitutions
from classify_runtime_tables import rank
from scan_auth_substitutions import TARGETS
from verify_fill_dispatch import segment_read


def build(image):
    """Return private source normalization expressions/models to a RAM caller."""
    analysis=model(image,'storeservices_1f8249');z=analysis['z']
    assert analysis['proof']=='unsat' and analysis['omitted_contribution_control']=='sat'
    u2,u3=z.BitVec('frame_byte',8),z.BitVec('register_byte',8)
    substitutions=[]
    for name,variable in analysis['incoming'].items():
        value=z.ZeroExt(56,u3)<<16 if name in ('r11','r12') else z.BitVecVal(0,64)
        substitutions.append((variable,value))
    substitutions.extend((variable,z.BoolVal(False)) for variable in analysis['flags'].values())
    assert set(analysis['memory_inputs'])=={(0x1f8264,4),(0x1f83b3,4)}
    substitutions.extend((variable,z.ZeroExt(24,u2)<<8) for variable in analysis['memory_inputs'].values())
    zero_words=[(word,z.BitVecVal(0,32)) for word in analysis['words']]
    rest=z.simplify(z.substitute(analysis['full'],*(substitutions+zero_words)))
    origin=z.simplify(z.substitute(rest,(u2,z.BitVecVal(0,8)),(u3,z.BitVecVal(0,8))))
    h2=z.simplify(z.substitute(rest,(u3,z.BitVecVal(0,8)))^origin)
    h3=z.simplify(z.substitute(rest,(u2,z.BitVecVal(0,8)))^origin)
    solver=z.Solver();solver.set(timeout=15000);solver.add(rest!=origin^h2^h3)
    rest_proof=str(solver.check());assert rest_proof=='unsat'
    # Prove that the canonical-byte reduction loses no other bits, under the
    # actual prefix aliases: R11=R12 and the two reads use the same frame word.
    frame=z.BitVec('shared_frame',32);register=analysis['incoming']['r12']
    general=z.substitute(analysis['full'],*zero_words,
        (analysis['incoming']['r11'],register),
        *[(variable,frame) for variable in analysis['memory_inputs'].values()])
    canonical=z.substitute(rest,(u2,z.Extract(15,8,frame)),(u3,z.Extract(23,16,register)))
    proof=z.Solver();proof.set(timeout=15000);proof.add(general!=canonical)
    byte_proof=str(proof.check());assert byte_proof=='unsat'
    # Source prefix at 0x1f7f71 and 0x1f7f88 copies the same unchanged EBX.
    # The frame operands are both [rbp-0x38]; ordinary memory is stable here.
    indices=[]
    for position,(pc,_) in enumerate(analysis['loads']):
        if position==0:index=z.ZeroExt(24,z.BitVec('first_byte',8)^0x66)
        else:
            local=list(substitutions)
            if position==1:
                local=[pair for pair in local if not z.eq(pair[0],analysis['incoming']['rsi'])]
                local.append((analysis['incoming']['rsi'],z.ZeroExt(56,z.BitVec('second_byte',8))))
            index=z.simplify(z.substitute(analysis['index_expressions'][pc],*local))
        variable=(z.BitVec('first_byte',8),z.BitVec('second_byte',8),u2,u3)[position]
        mapping=[]
        for value in range(256):
            evaluated=z.simplify(z.substitute(index,(variable,z.BitVecVal(value,8))))
            assert z.is_bv_value(evaluated) and 0<=evaluated.as_long()<256
            mapping.append(evaluated.as_long())
        assert len(set(mapping))==256;indices.append(mapping)
    arrays=[];tables=[];ranks=[]
    for position,(_,base) in enumerate(analysis['loads']):
        data=segment_read(image,base,1024);table=[int.from_bytes(data[i:i+4],'little') for i in range(0,1024,4)];tables.append(table)
        normalized=[]
        for value,index in enumerate(indices[position]):
            expression=z.substitute(analysis['contributions'][position],(analysis['words'][position],z.BitVecVal(table[index],32)))
            if position==2:expression^=z.substitute(h2,(u2,z.BitVecVal(value,8)))
            if position==3:expression^=z.substitute(h3,(u3,z.BitVecVal(value,8)))
            normalized.append(z.simplify(expression).as_long())
        ranks.append(rank([value^normalized[0] for value in normalized]))
        arrays.append(b''.join(value.to_bytes(4,'little') for value in normalized))
    models=[];result=analyze_substitutions(arrays,range(4),models.append)
    return dict(analysis=analysis,rest_proof=rest_proof,byte_proof=byte_proof,
                indices=indices,arrays=arrays,tables=tables,ranks=ranks,
                models=models,result=result,h2=h2,h3=h3,u2=u2,u3=u3)


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path)
    parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    name,digest=TARGETS['storeservices'];image=(args.checkout/'rootfs/system/lib64'/name).read_bytes()
    assert hashlib.sha256(image).hexdigest()==digest
    private=build(image);analysis=private['analysis']
    comparisons=execute_original(image,private['tables'],analysis)
    report=dict(status='bounded StoreServices input-index normalization',artifact_sha256=digest,
                source_interval=['0x1f8249','0x1f8442'],instructions=analysis['instructions'],
                word_XOR_separation=analysis['proof'],input_index_XOR_separation=private['rest_proof'],
                canonical_byte_reduction_under_prefix_aliases=private['byte_proof'],
                canonical_index_bijections=4,normalized_word_ranks=private['ranks'],
                original_instruction_comparisons=comparisons,coherent_substitutions=private['result'],
                network_requests=0,private_bytes_written=False,
                scope='one register-result column under documented source-prefix aliases; no caller bounds/faults, full cipher, parameters or GUID/auth claim; all tables, maps and normalizations RAM-only')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
