"""Validate ordered-state inference with invented AES and shuffled schedules."""
import argparse
import json
from pathlib import Path
import random
import sys

from analyze_ordered_aes_rounds import analyze
from analyze_round_key_schedule import mix_round_key
from analyze_table_algebra import FORWARD,INVERSE,Basis,apply


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.crypto.aes import AES,_SBOX,_INV_SBOX,_gmul
    rng=random.Random(0x584127);key=bytes(rng.randrange(256) for _ in range(16));cipher=AES(key)
    encoders=[]
    for row in range(4):
        columns=[1<<bit for bit in range(8)]
        for _ in range(40):
            a,b=rng.sample(range(8),2);columns[a]^=columns[b]
        encoders.append(columns)
    decoders=[tuple(Basis(columns).coordinates(1<<bit) for bit in range(8)) for columns in encoders]
    translations=[rng.randrange(256) for _ in range(4)];rows=[]
    for inverse in (False,True):
        direction=-1 if inverse else 1;matrix=INVERSE if inverse else FORWARD;box=_INV_SBOX if inverse else _SBOX
        model=dict(mix_name='AES-inverse-MixColumns' if inverse else 'AES-forward-MixColumns',
                   spec_name='AES-inverse-S-box' if inverse else 'AES-S-box',
                   decoders=decoders,input_positions=(0,1,2,3),input_rows=(0,1,2,3),translations=translations)
        def events(wrong_round=False,wrong_rows=False,duplicate_columns=False):
            state=[rng.randrange(256) for _ in range(16)]
            if duplicate_columns:state[4:8]=state[:4]
            first=bytes(state);result=[]
            for level in range(9):
                order=rng.sample(range(4),4)
                for column in order:
                    for row in rng.sample(range(4),4):
                        source=(column+direction*row*(2 if wrong_rows else 1))%4
                        value=state[4*source+row]
                        result.append(dict(ordinal=row,index=apply(encoders[row],value^translations[row])))
                mixed=[]
                for column in range(4):
                    for row in range(4):
                        value=0
                        for source in range(4):value^=_gmul(matrix[row][source],box[state[4*((column+direction*source)%4)+source]])
                        mixed.append(value)
                round_key=mix_round_key(cipher._round_keys[9-level],inverse=True) if inverse else cipher._round_keys[level+1]
                state=[a^b for a,b in zip(mixed,round_key)]
                if wrong_round and level==3:state[0]^=1
            return result,first
        checks=[];positive,first=events()
        def check(master,details):assert master==key and details['first_input_state']==first;checks.append(True)
        verified=analyze(positive,[model],range(4),check)
        assert verified['unique_key_candidates']==1 and checks==[True]
        assert verified['independently_matching_later_rounds']==[7]
        assert analyze(events(wrong_round=True)[0],[model],range(4))['unique_key_candidates']==0
        assert analyze(events(wrong_rows=True)[0],[model],range(4))['unique_key_candidates']==0
        duplicated,first_duplicate=events(duplicate_columns=True);duplicate_checks=[]
        def check_duplicate(master,details):assert master==key and details['first_input_state']==first_duplicate;duplicate_checks.append(True)
        assert analyze(duplicated,[model],range(4),check_duplicate)['unique_key_candidates']==1 and duplicate_checks==[True]
        bad=[event.copy() for event in positive];bad[0]['ordinal']=bad[1]['ordinal']
        assert analyze(bad,[model],range(4))['status']=='execution-order hypothesis shape rejected'
        rows.append(dict(direction='equivalent-inverse' if inverse else 'forward',positive=verified,
                         changing_column_and_row_read_orders_supported=True,duplicate_initial_columns_supported=True,
                         wrong_round_key_and_rows_rejected=True,malformed_read_group_rejected=True))
    report=dict(status='pass',cases=rows,scope='invented keys, byte maps and lookup events only; hypotheses checked against independent AES transitions; no source data, states or key bytes emitted')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(status='pass',directions=len(rows),independent_later_rounds_per_case=7)))


if __name__=='__main__':main()
