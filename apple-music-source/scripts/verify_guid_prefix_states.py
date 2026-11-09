"""Check prefix-key hypotheses and later multisets on invented AES graphs."""
import argparse
import json
from pathlib import Path
import random
import sys
from types import SimpleNamespace

from analyze_guid_prefix_states import analyze
from analyze_table_algebra import FORWARD,INVERSE
from analyze_round_key_schedule import mix_round_key


def main():
 parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True);parser.add_argument('--inverse',action='store_true');args=parser.parse_args();direction=-1 if args.inverse else 1;matrix=INVERSE if args.inverse else FORWARD
 sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
 from apple_music_source.crypto.aes import AES,_SBOX,_INV_SBOX,_gmul
 rng=random.Random(0x581223);key=bytes(rng.randrange(256) for _ in range(16));plain=bytes(rng.randrange(256) for _ in range(16));cipher=AES(key)
 box=_INV_SBOX if args.inverse else _SBOX
 model=dict(mix_name='AES-inverse-MixColumns' if args.inverse else 'AES-forward-MixColumns',spec_name='AES-inverse-S-box' if args.inverse else 'AES-S-box',decoders=[tuple(1<<bit for bit in range(8))]*4,input_positions=(0,1,2,3),input_rows=(0,1,2,3),output_rows=(0,1,2,3),translations=(0,0,0,0),mixing_coefficients=[[matrix[j][i] for j in range(4)] for i in range(4)])
 state=bytes(a^b for a,b in zip(plain,cipher._round_keys[-1] if args.inverse else key));events=[];groups=None
 for level in range(9):
  next_groups=[];mixed=[0]*16
  for column in range(4):
   group=[]
   for row in range(4):
    source=(column+direction*row)%4;variable=level*16+column*4+row
    events.append(dict(variable=variable,ordinal=row,index=state[4*source+row],dependencies=set(groups[source]) if groups else set()));group.append(variable)
    for out in range(4):mixed[4*column+out]^=_gmul(matrix[out][row],box[state[4*source+row]])
   next_groups.append(group)
  state=bytes(a^b for a,b in zip(mixed,mix_round_key(cipher._round_keys[9-level],inverse=True) if args.inverse else cipher._round_keys[level+1]));groups=next_groups
 # Same-layer false edge deliberately breaks complete graph depths after the
 # first three layers, while the actual byte values remain ordinary AES.
 events[49]['dependencies'].add(48)
 trace=SimpleNamespace(events=events);accepted=[]
 result=analyze(trace,[model],range(4),lambda master,details:accepted.append(master==key))
 assert accepted==[True] and result['complete_prefix_layers']==3 and result['matching_full_row_multisets']==1
 assert not result['checks'][0]['ordering_proved']
 bad=[dict(event) for event in events];bad[100]['index']^=1
 wrong=analyze(SimpleNamespace(events=bad),[model],range(4));assert wrong['matching_full_row_multisets']==0
 bad_prefix=[dict(event) for event in events];bad_prefix[16]['index']^=1
 wrong_prefix=analyze(SimpleNamespace(events=bad_prefix),[model],range(4));assert wrong_prefix['matching_full_row_multisets']==0
 # A truncated symbolic trace may supply separately observed complete indices.
 bounded=analyze(SimpleNamespace(events=events[:80]),[model],range(4),all_lookup_events=events)
 assert bounded['matching_full_row_multisets']==1
 # Multisets intentionally do not establish ordering: exchanging later equal-
 # row event values preserves the check and must never claim an ordering proof.
 reordered=[dict(event) for event in events];reordered[80]['index'],reordered[84]['index']=reordered[84]['index'],reordered[80]['index']
 observational=analyze(SimpleNamespace(events=events[:80]),[model],range(4),all_lookup_events=reordered)
 assert observational['matching_full_row_multisets']==1 and not observational['checks'][0]['ordering_proved']
 report=dict(status='pass',direction=direction,correct_key_from_complete_prefix=True,wrong_later_value_rejected=True,wrong_prefix_value_rejected=True,bounded_trace_with_complete_observations=True,multiset_ordering_limit_explicit=True,parameter_bytes_written=0,scope='invented AES values only; validates bounded hypothesis checks and their ordering limitation')
 args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
