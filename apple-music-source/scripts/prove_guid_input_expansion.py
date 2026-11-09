"""Prove the original expansion byte arithmetic equals the compact ARX stage."""
import argparse
import hashlib
import json
from pathlib import Path

from recover_guid_word_consumers import GPRS,Code
from scan_auth_substitutions import TARGETS
from trace_lookup_dataflow import LookupTrace
from verify_fill_dispatch import segment_read


def main():
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('checkout',type=Path);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
 filename,digest=TARGETS['corefp'];image=(args.checkout/'rootfs/system/lib64'/filename).read_bytes();assert hashlib.sha256(image).hexdigest()==digest
 trace=LookupTrace(None,[],[],[]);z=trace.z;trace.started=True;trace.registers={name:z.BitVec('incoming_'+name,64) for name in GPRS};trace.flags={name:z.Bool('flag_'+name) for name in ('cf','pf','zf','sf','of')}
 counter=z.BitVec('counter',32);words=[z.BitVec('byte_'+str(i),8) for i in range(4)];loads={0x2f6650:counter,0x2f669b:words[0],0x2f66d4:words[1],0x2f66ed:words[2],0x2f6723:words[3]}
 ordinary=trace.read
 def read(mu,ins,operand):
  from capstone import CS_OP_MEM
  if operand.type==CS_OP_MEM:
   assert ins.address in loads;return loads[ins.address]
  return ordinary(mu,ins,operand)
 trace.read=read;code=Code(image);pc=0x2f6650
 while pc<0x2f6753:
  ins=next(trace.decoder.disasm(segment_read(image,pc,16),pc,count=1));trace.step(code,pc,ins.size);assert trace.active and not trace.errors;pc+=ins.size
 assert pc==0x2f6753
 clear=[word^0x47 for word in words]
 expected=((clear[2]^z.RotateLeft(clear[0],3))+z.RotateLeft(clear[1],5)-z.RotateLeft(clear[3],7))^0x47
 output=z.Extract(7,0,trace.registers['rdi']);solver=z.Solver();solver.set(timeout=15000);solver.add(output!=expected);proof=str(solver.check());assert proof=='unsat'
 wrong=(clear[2]+z.RotateLeft(clear[1],5)-z.RotateLeft(clear[3],7))^0x47
 negative=z.Solver();negative.set(timeout=15000);negative.add(output!=wrong);control=str(negative.check());assert control=='sat'
 checks=0
 for index in range(4*328):
  for offset in (0,315,271,173):
   value=index+offset;quotient=((value>>3)*0xc7d)>>17
   assert value-quotient*328==value%328;checks+=1
 report=dict(status='pass',artifact_sha256=digest,source_instructions=trace.instructions,full_byte_ARX_equivalence=proof,omitted_tap_counterexample=control,exhaustive_modulo_index_checks=checks,parameter_bytes_written=0,scope='universal arithmetic equivalence over four independent source byte operands and arbitrary incoming state; finite index normalization for all four passes; no input selection, caller bounds or GUID/auth claim')
 args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
