"""Investigate source-index corrections for the second StoreServices column.

Private arrays, maps and candidates remain in RAM. This is a bounded column
model under explicit prefix-state relations, not a complete cipher/auth claim.
"""
import argparse
import hashlib
import json
from pathlib import Path
import sys

from analyze_guid_column import model
from analyze_round_substitutions import analyze as substitutions
from analyze_table_algebra import independent
from scan_auth_substitutions import TARGETS
from verify_fill_dispatch import segment_read


def build(image):
 analysis=model(image,'storeservices_2316f0');z=analysis['z'];u=[z.BitVec('ssc_second_u'+str(i),8) for i in range(4)]
 # Prefix at 0x231674..0x2316d6 takes byte 16..23 of the packed word.
 a=z.ZeroExt(24,u[1]);edx=a^0x56;edx=edx-((edx*2)&0xffffff82)+0xd07634c1;edx^=0x430644a0;edx=edx-((edx*2)&0x26a0aefc)+0x175d5f7e
 index1=(a^0x2c)-((z.ZeroExt(24,u[1])<<1)&0x126)+0x94c393;index1^=0x349210;index1=index1-((index1*2)&0x1403ef4)+0x19f29f7a;index1^=0x1952ce0a
 # Low-byte chain at 0x231119..0x23114f then 0x231556..0x231575;
 # other packed inputs enter at bit 8 or above and cannot alter this byte.
 low=u[2]^0x45;low=(low-((low*2)&0x96)+0xcb)^0xcb;low=(low-((low*2)&0x96)+0x4b)^0x4b;low=low-((low*2)&0x38)+0x9c
 bindings={name:z.BitVecVal(0,64) for name in analysis['incoming']};bindings.update(r8=z.ZeroExt(56,u[0]),rdx=z.ZeroExt(32,edx),r11=z.ZeroExt(56,low),r15=z.ZeroExt(56,u[2]))
 pairs=[(variable,bindings[name]) for name,variable in analysis['incoming'].items()];pairs += [(variable,z.BoolVal(False)) for variable in analysis['flags'].values()]
 for (pc,width),variable in analysis['memory_inputs'].items():pairs.append((variable,u[3] if (pc,width)==(0x231963,1) else z.BitVecVal(0,width*8)))
 full=z.simplify(z.substitute(analysis['full'],*pairs))
 general=z.substitute(analysis['full'],(analysis['incoming']['r8'],z.ZeroExt(56,u[0])),(analysis['incoming']['rdx'],z.ZeroExt(32,edx)),(analysis['incoming']['r11'],z.Concat(z.Extract(63,8,analysis['incoming']['r11']),low)))
 guard=z.Solver();guard.set(timeout=15000);guard.add(general!=full);foreign_proof=str(guard.check());assert foreign_proof=='unsat'
 zero=[(word,z.BitVecVal(0,32)) for word in analysis['words']]+[(byte,z.BitVecVal(0,8)) for byte in u]
 origin=z.simplify(z.substitute(full,*zero));components=[]
 for i in range(4):components.append(z.simplify(z.substitute(full,*[(variable,value) for variable,value in zero if not z.eq(variable,analysis['words'][i]) and not z.eq(variable,u[i])])^origin))
 combined=origin
 for component in components:combined^=component
 solver=z.Solver();solver.set(timeout=15000);solver.add(full!=combined);proof=str(solver.check())
 indices=[u[0]^0x20,z.Extract(7,0,index1),u[2]^0x7b,u[3]^0x77];tables=[];arrays=[];ranks=[]
 for i,(_,base) in enumerate(analysis['loads']):
  raw=segment_read(image,base,1024);words=[int.from_bytes(raw[j:j+4],'little') for j in range(0,1024,4)];mapping=[];values=[]
  for value in range(256):
   index=z.simplify(z.substitute(indices[i],(u[i],z.BitVecVal(value,8)))).as_long();mapping.append(index)
   word=words[index];evaluated=z.simplify(z.substitute(components[i],(u[i],z.BitVecVal(value,8)),(analysis['words'][i],z.BitVecVal(word,32))))
   assert z.is_bv_value(evaluated);values.append(evaluated.as_long())
  assert len(set(mapping))==256;tables.append(mapping);arrays.append(b''.join(value.to_bytes(4,'little') for value in values));ranks.append(len(independent([value^values[0] for value in values])))
 models=[];coherent=substitutions(arrays,range(4),models.append) if ranks==[8]*4 else None
 return dict(analysis=analysis,arrays=arrays,indices=tables,models=models,result=coherent,ranks=ranks,prefix_conditioned_XOR_proof=proof,foreign_state_independence=foreign_proof,prefix_variables=u,prefix_edx=edx,prefix_r11_low=low)


def main():
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
 filename,digest=TARGETS['storeservices'];image=(args.checkout/'rootfs/system/lib64'/filename).read_bytes();assert hashlib.sha256(image).hexdigest()==digest
 private=build(image);report=dict(status='bounded source-index correction investigation',artifact_sha256=digest,source_instructions=private['analysis']['instructions'],unconditioned_word_XOR_proof=private['analysis']['proof'],prefix_conditioned_XOR_proof=private['prefix_conditioned_XOR_proof'],foreign_state_independence=private['foreign_state_independence'],canonical_index_maps=4,word_ranks=private['ranks'],coherent_substitutions=private['result'],parameter_bytes_written=0,scope='column under explicit prefix-state relations; these relations and whole-caller outputs still need runtime validation')
 args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
