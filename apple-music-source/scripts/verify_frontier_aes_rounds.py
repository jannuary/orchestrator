"""Check frontier hypotheses against invented AES with misleading graph edges."""
import argparse
import json
from pathlib import Path
import random
import sys
from types import SimpleNamespace

from analyze_frontier_aes_rounds import check
from analyze_guid_final_inputs import check as check_final_inputs
from analyze_round_key_schedule import mix_round_key,recover_input
from analyze_table_algebra import Basis,apply,FORWARD,INVERSE


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.crypto.aes import AES,_SBOX,_INV_SBOX,_gmul
    rng=random.Random(0x543193);key=bytes(rng.randrange(256) for _ in range(16));aes=AES(key)
    encoders=[]
    for _ in range(4):
        basis=[1<<bit for bit in range(8)]
        for _ in range(64):
            a,b=rng.sample(range(8),2);basis[a]^=basis[b]
        encoders.append(basis)
    decoders=[tuple(Basis(basis).coordinates(1<<bit) for bit in range(8)) for basis in encoders]
    translations=[rng.randrange(256) for _ in range(4)];rows=[]
    for inverse in (False,True):
        direction=-1 if inverse else 1;matrix=INVERSE if inverse else FORWARD;box=_INV_SBOX if inverse else _SBOX
        model=dict(mix_name='AES-inverse-MixColumns' if inverse else 'AES-forward-MixColumns',
                   spec_name='AES-inverse-S-box' if inverse else 'AES-S-box',
                   decoders=decoders,input_positions=(0,1,2,3),input_rows=(0,1,2,3),
                   output_rows=(0,1,2,3),translations=translations,
                   mixing_coefficients=[[matrix[j][i] for j in range(4)] for i in range(4)])
        def events(wrong_key=False,bad_union=False):
            original=bytes(rng.randrange(256) for _ in range(16))
            initial=aes._round_keys[-1] if inverse else key
            state=[a^b for a,b in zip(original,initial)];layers=[];groups=None
            for level in range(9):
                layer=[];next_groups=[];mixed=[0]*16
                for column in range(4):
                    group=[]
                    for row in range(4):
                        source=(column+direction*row)%4;value=level*16+column*4+row
                        layer.append(dict(variable=value,ordinal=row,index=apply(encoders[row],state[4*source+row]^translations[row]),
                                          dependencies=set(groups[source]) if groups else set()))
                        group.append(value)
                        for out in range(4):mixed[4*column+out]^=_gmul(matrix[out][row],box[state[4*source+row]])
                    next_groups.append(group)
                round_key=mix_round_key(aes._round_keys[9-level],inverse=True) if inverse else aes._round_keys[level+1]
                state=[a^b for a,b in zip(mixed,round_key)]
                if wrong_key and level==3:state[0]^=1
                layers.append(layer);groups=next_groups
            # One union contains the actual four parents and an already complete
            # sibling group. An older false edge tests nearest-frontier projection.
            ambiguous=layers[2][0];true=set(ambiguous['dependencies'])
            alternate=next(set(event['dependencies']) for event in layers[2] if event['dependencies']!=true)
            if bad_union:
                # Omit a true parent: the sibling missing its ordinal cannot fit.
                ambiguous['dependencies']=(true-{min(true)})|alternate
            else:ambiguous['dependencies']|=alternate
            layers[5][3]['dependencies']|={layers[0][0]['variable']}
            # Schedule any ready event, favoring deep work, to pipeline rounds.
            pending=[event for layer in layers for event in layer];ordered=[];seen=set()
            while pending:
                ready=[event for event in pending if event['dependencies']<=seen]
                assert ready
                event=max(ready,key=lambda event:(event['variable']//16,rng.random()))
                pending.remove(event);ordered.append(event);seen.add(event['variable'])
            final=[]
            for column in rng.sample(range(4),4):
                for row in rng.sample(range(4),4):
                    source=(column+direction*row)%4
                    final.append((0,row+4,apply(encoders[row],state[4*source+row]^translations[row]),0))
            return SimpleNamespace(events=ordered,final=final),original
        trace,original=events();accepted=[];final_checks=[]
        def accept(master,details):
            assert master==key and recover_input(master,details,range(4))==original
            final_result=check_final_inputs(master,details,trace.final)
            assert final_result['matching_row_codec_assignments']==1
            bad=list(trace.final);pc,ordinal,index,word=bad[0];bad[0]=(pc,ordinal,index^1,word)
            assert check_final_inputs(master,details,bad)['matching_row_codec_assignments']==0
            assert check_final_inputs(master,details,bad[:-1])['status']=='final index shape rejected'
            final_checks.append(final_result)
            accepted.append(True)
        positive=check(trace,[model],range(4),accept)
        assert accepted==[True] and positive['frontier_layers']==9
        assert positive['resolved_union_events']==1 and positive['projected_dependency_edges']==5
        assert positive['schedule']['independently_matching_round_keys']==[7]
        negative=check(events(wrong_key=True)[0],[model],range(4))
        assert negative['schedule']['matching_key_schedule_candidates']==0
        rejected=check(events(bad_union=True)[0],[model],range(4))
        assert rejected['status']=='ambiguous frontier union unresolved'
        malformed=SimpleNamespace(events=[dict(event) for event in trace.events])
        malformed.events[0]['dependencies']={99999}
        assert check(malformed,[model],range(4))['status']=='unresolved frontier parents'
        rows.append(dict(direction='equivalent-inverse' if inverse else 'forward',positive=positive,final_input_checks=final_checks,
                         wrong_later_key_rejected=True,incomplete_true_union_rejected=True,unknown_parent_rejected=True))
    report=dict(status='pass',cases=rows,private_bytes_written=False,
                scope='invented AES states, keys and graphs only; valid hypothesis plus independent later-key checks, no proof of source expressions')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(status='pass',directions=len(rows))))


if __name__=='__main__':main()
