"""Verify round-prefix analysis with invented AES and deliberately wrong rounds."""
import argparse
import json
from pathlib import Path
import random
import sys
from types import SimpleNamespace

from analyze_table_algebra import Basis,apply,FORWARD,INVERSE
from analyze_round_key_schedule import analyze,invert_first_round_key,invert_round_key,mix_round_key,recover_input


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,required=True);args=p.parse_args()
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.crypto.aes import AES,_SBOX,_INV_SBOX,_gmul
    rng=random.Random(0x445319);key=bytes(rng.randrange(256) for _ in range(16));aes=AES(key)
    assert invert_first_round_key(bytes(aes._round_keys[1]))==key
    assert all(invert_round_key(bytes(aes._round_keys[level]),level)==key for level in range(1,11))
    encoders=[]
    for _ in range(4):
        columns=[1<<bit for bit in range(8)]
        for _ in range(64):
            a,b=rng.sample(range(8),2);columns[a]^=columns[b]
        encoders.append(columns)
    decoders=[tuple(Basis(columns).coordinates(1<<bit) for bit in range(8)) for columns in encoders]
    translations=[rng.randrange(256) for _ in range(4)]
    model=dict(mix_name='AES-forward-MixColumns',spec_name='AES-S-box',decoders=decoders,
               input_rows=(0,1,2,3),output_rows=(0,1,2,3),input_positions=(0,1,2,3),
               mixing_coefficients=[[FORWARD[j][i] for j in range(4)] for i in range(4)],translations=translations)
    inverse_model={**model,'mix_name':'AES-inverse-MixColumns','spec_name':'AES-inverse-S-box',
                   'mixing_coefficients':[[INVERSE[j][i] for j in range(4)] for i in range(4)]}
    def trace(wrong_key=False,wrong_rows=False,duplicate_input=False,inverse=False):
        initial=aes._round_keys[-1] if inverse else key;matrix=INVERSE if inverse else FORWARD;box=_INV_SBOX if inverse else _SBOX
        direction=-1 if inverse else 1
        plaintext=bytes(rng.randrange(256) for _ in range(16));state=[plaintext[j]^initial[j] for j in range(16)];events=[];previous_groups=None
        if duplicate_input:
            state[4]=state[0];plaintext=bytes(value^initial[j] for j,value in enumerate(state))
        for level in range(8):
            groups=[];mixed=[0]*16
            for column in range(4):
                group=[]
                for row in range(4):
                    source_column=(column+direction*(2 if wrong_rows else 1)*row)%4
                    u=state[4*source_column+row];value=len(events);index=apply(encoders[row],u^translations[row])
                    if level==0 and duplicate_input:
                        previous=next((event for event in events if event['ordinal']==row and event['index']==index),None)
                        if previous is not None:value=previous['variable']
                    group.append(value)
                    events.append(dict(variable=value,ordinal=row,index=index,
                                       dependencies=set() if previous_groups is None else set(previous_groups[source_column])))
                    for output_row in range(4):mixed[4*column+output_row]^=_gmul(matrix[output_row][row],box[u])
                groups.append(group)
            round_key=mix_round_key(aes._round_keys[9-level],inverse=True) if inverse else aes._round_keys[level+1]
            state=[value^round_key[j] for j,value in enumerate(mixed)]
            if wrong_key and level==2:state[0]^=1
            previous_groups=groups
        return SimpleNamespace(events=events,plaintext=plaintext)
    positive_trace=trace();checked=[]
    def check_input(master,details):
        assert master==key and recover_input(master,details,range(4))==positive_trace.plaintext;checked.append(True)
    positive=analyze(positive_trace,[model],range(4),check_input);assert positive['matching_key_schedule_candidates']==1 and checked==[True]
    assert positive['independently_matching_round_keys']==[6]
    negative_key=analyze(trace(True),[model],range(4));assert negative_key['matching_key_schedule_candidates']==0
    negative_rows=analyze(trace(False,True),[model],range(4));assert negative_rows['matching_key_schedule_candidates']==0
    duplicated=trace(duplicate_input=True);duplicate_checks=[]
    def check_duplicated(master,details):
        assert master==key and recover_input(master,details,range(4))==duplicated.plaintext;duplicate_checks.append(True)
    duplicate_report=analyze(duplicated,[model],range(4),check_duplicated)
    assert duplicate_report['matching_key_schedule_candidates']==1 and duplicate_checks==[True]
    interleaved=trace();lookahead=interleaved.events.pop(7*16+4);interleaved.events.insert(6*16+15,lookahead)
    interleaved_checks=[]
    def check_interleaved(master,details):
        assert master==key and recover_input(master,details,range(4))==interleaved.plaintext;interleaved_checks.append(True)
    interleaved_report=analyze(interleaved,[model],range(4),check_interleaved)
    assert interleaved_report['matching_key_schedule_candidates']==1 and interleaved_checks==[True]
    assert interleaved_report['observed_round_input_layers']==8
    inverse_trace=trace(inverse=True);inverse_checks=[]
    def check_inverse(master,details):
        assert master==key and recover_input(master,details,range(4))==inverse_trace.plaintext;inverse_checks.append(True)
    inverse_report=analyze(inverse_trace,[inverse_model],range(4),check_inverse)
    assert inverse_report['matching_key_schedule_candidates']==1 and inverse_checks==[True]
    assert inverse_report['independently_matching_round_keys']==[6]
    assert inverse_report['matching_cipher_directions']==['equivalent-inverse']
    assert analyze(trace(wrong_key=True,inverse=True),[inverse_model],range(4))['matching_key_schedule_candidates']==0
    assert analyze(trace(wrong_rows=True,inverse=True),[inverse_model],range(4))['matching_key_schedule_candidates']==0
    report=dict(status='pass',inverse_first_round_key=True,positive=positive,wrong_round_key_rejected=True,
                wrong_ShiftRows_rejected=True,duplicate_initial_Sbox_input_supported=True,
                interleaved_round_lookup_supported=True,
                inverse_AES128_schedule=inverse_report,inverse_wrong_key_and_rows_rejected=True,
                all_ten_round_keys_invert_to_master=True,
                scope='invented data/key only; no key/state/encoding bytes emitted')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report))


if __name__=='__main__':main()
