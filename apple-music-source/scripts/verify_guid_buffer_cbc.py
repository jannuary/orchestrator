"""Check RAM-only caller-buffer inference on invented whitened CBC messages."""
import argparse
import json
from pathlib import Path
import random
import sys

from analyze_guid_buffer_cbc import analyze,xor


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'src'))
    from apple_music_source.crypto.aes import AES
    rng=random.Random(0x792514);block=lambda:bytes(rng.randrange(256) for _ in range(16))
    key,input_mask,output_mask,iv=block(),block(),block(),block();cipher=AES(key);blocks={}
    for profile in range(2):
        chain=iv
        for ordinal in range(2):
            raw=block();logical=xor(raw,chain,input_mask);actual=xor(cipher.encrypt_block(logical),output_mask)
            blocks[1,profile,ordinal]=(key,logical,output_mask,raw,actual)
            inverse_state=xor(actual,output_mask);inverse_mask=xor(raw,cipher.decrypt_block(inverse_state))
            blocks[0,profile,ordinal]=(key,inverse_state,inverse_mask,actual,raw)
            chain=actual
    positive=analyze(blocks)
    assert all(path['heldout_inputs_changed'] and all(message['matched_logical_inputs']==message['matched_complete_outputs']==2 for message in path['message_checks']) for path in positive['paths'])
    assert all(message['package_CBC_complete_message_equal'] for path in positive['paths'] for message in path['message_checks'])
    assert all(positive['reciprocal_parameter_relations'].values())
    wrong=dict(blocks);at=(1,1,0);values=list(wrong[at]);values[4]=xor(values[4],bytes([1])+bytes(15));wrong[at]=tuple(values)
    rejected=analyze(wrong)
    assert rejected['paths'][1]['message_checks'][1]['matched_complete_outputs']==1
    assert not rejected['paths'][1]['message_checks'][1]['package_CBC_complete_message_equal']
    wrong=dict(blocks);at=(0,1,0);values=list(wrong[at]);values[3]=xor(values[3],bytes([1])+bytes(15));wrong[at]=tuple(values)
    rejected=analyze(wrong)
    assert rejected['paths'][0]['message_checks'][1]['matched_complete_outputs']==0
    wrong=dict(blocks);at=(0,1,0);values=list(wrong[at]);values[0]=block();wrong[at]=tuple(values)
    assert analyze(wrong)['paths'][0]['status']=='master key changed'
    missing=dict(blocks);del missing[0,1,1]
    assert analyze(missing)['paths'][0]['status']=='insufficient caller buffers'
    report=dict(status='pass',positive=positive,changed_heldout_output_rejected=True,
                changed_caller_input_and_following_feedback_rejected=True,key_change_rejected=True,incomplete_capture_rejected=True,
                scope='invented keys, whitening masks, IV and caller messages only; no native values emitted')
    args.output.write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(dict(status='pass',directions=2,heldout_blocks=4)))


if __name__=='__main__':main()
