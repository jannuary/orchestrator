"""Validate observed lookup-layer order against independent AES round keys.

This tests an explicit execution-order hypothesis, not a symbolic dependency
proof. State bytes, input permutations, decoded keys and maps stay in RAM.
"""
from itertools import permutations
from collections import defaultdict

from analyze_table_algebra import apply,FORWARD,INVERSE
from analyze_round_key_schedule import invert_first_round_key,invert_round_key,mix_round_key


def analyze(events,models,regular,key_callback=None):
    from apple_music_source.crypto.aes import AES,_SBOX,_INV_SBOX,_gmul
    events=[event for event in events if event['ordinal'] in regular]
    layers=[events[start:start+16] for start in range(0,len(events)-15,16)]
    indices={ordinal:index for index,ordinal in enumerate(regular)}
    for layer in layers:
        if any({event['ordinal'] for event in layer[start:start+4]}!=set(regular) for start in range(0,16,4)):
            return dict(status='execution-order hypothesis shape rejected',complete_lookup_layers=0,key_bytes_written=0)
    if len(layers)<3 or len(layers)>9:return dict(status='insufficient supported lookup layers',complete_lookup_layers=len(layers),key_bytes_written=0)
    checked=paths=0;keys=set();independent_counts=[];directions=set()
    for model in models:
        if (model['mix_name'],model['spec_name'])==('AES-forward-MixColumns','AES-S-box'):direction=1;box=_SBOX;matrix=FORWARD
        elif (model['mix_name'],model['spec_name'])==('AES-inverse-MixColumns','AES-inverse-S-box'):direction=-1;box=_INV_SBOX;matrix=INVERSE
        else:continue
        states=[]
        for layer in layers:
            options=defaultdict(list)
            for columns in permutations(range(4)):
                state=[None]*16
                for group in range(4):
                    for event in layer[4*group:4*group+4]:
                        index=indices[event['ordinal']];row=model['input_rows'][index]
                        value=apply(model['decoders'][model['input_positions'][index]],event['index'])^model['translations'][index]
                        position=4*((columns[group]+direction*row)%4)+row
                        assert state[position] is None;state[position]=value
                options[bytes(state)].append(columns)
            states.append(options)
        def transform(state):
            result=[]
            for column in range(4):
                for row in range(4):
                    value=0
                    for source in range(4):value^=_gmul(matrix[row][source],box[state[4*((column+direction*source)%4)+source]])
                    result.append(value)
            return bytes(result)
        for first in states[0]:
            mixed_first=transform(first)
            for second in states[1]:
                checked+=1;observed=bytes(a^b for a,b in zip(second,mixed_first))
                master=invert_first_round_key(observed) if direction==1 else invert_round_key(mix_round_key(observed),9)
                expanded=AES(master)._round_keys;previous=second;valid=True
                for level in range(2,len(layers)):
                    round_key=bytes(expanded[level]) if direction==1 else mix_round_key(expanded[10-level],inverse=True)
                    predicted=bytes(a^b for a,b in zip(transform(previous),round_key))
                    if predicted not in states[level]:valid=False;break
                    previous=predicted
                if not valid:continue
                paths+=1;independent_counts.append(len(layers)-2);directions.add('forward' if direction==1 else 'equivalent-inverse')
                if master not in keys:
                    keys.add(master)
                    if key_callback is not None:key_callback(master,dict(model=model,cipher_direction=direction,first_input_state=first))
    return dict(status='observed execution-order AES-128 schedule hypothesis checked',complete_lookup_layers=len(layers),
        column_layout_pairs_checked=checked,matching_state_paths=paths,unique_key_candidates=len(keys),
        independently_matching_later_rounds=independent_counts,matching_directions=sorted(directions),key_bytes_written=0,
        scope='assumes consecutive 16-read layers and four-read output-column groups; enumerates column permutations independently per layer and validates later states with the inferred AES key schedule; not a symbolic dataflow proof, final round, complete cipher, initialization or auth claim')
