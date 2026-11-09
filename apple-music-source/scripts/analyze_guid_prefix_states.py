"""Test a verified complete round prefix against later decoded lookup values.

Later per-row multisets are an explicit observational check, not a proof of
round ordering or dependency removal. Candidate keys/states never leave RAM.
"""
from collections import Counter,defaultdict
from types import SimpleNamespace

from analyze_frontier_aes_rounds import check as frontier_check
from analyze_round_key_schedule import recover_input,mix_round_key
from analyze_table_algebra import apply,FORWARD,INVERSE


def analyze(trace,models,regular,key_callback=None,all_lookup_events=None):
    from apple_music_source.crypto.aes import AES,_SBOX,_INV_SBOX,_gmul
    events=[event for event in trace.events if event['ordinal'] in regular]
    depth={};layers=defaultdict(list)
    for event in events:
        if any(parent not in depth for parent in event['dependencies']):
            return dict(status='unresolved prefix parents',key_bytes_written=0)
        level=1+max(depth[parent] for parent in event['dependencies']) if event['dependencies'] else 0
        depth[event['variable']]=level;layers[level].append(event)
    count=0
    while len(layers[count])==16:count+=1
    if count<3:return dict(status='insufficient complete prefix',complete_prefix_layers=count,key_bytes_written=0)
    selected=[event for level in range(count) for event in layers[level]]
    candidates=[]
    prefix=frontier_check(SimpleNamespace(events=selected),models,regular,lambda master,details:candidates.append((master,details)))
    checks=[];matching=0
    full_events=events if all_lookup_events is None else [event for event in all_lookup_events if event['ordinal'] in regular]
    for master,details in candidates:
        direction=details['cipher_direction'];inverse=direction==-1;matrix=INVERSE if inverse else FORWARD;box=_INV_SBOX if inverse else _SBOX
        cipher=AES(master);plain=recover_input(master,details,regular)
        state=bytes(a^b for a,b in zip(plain,cipher._round_keys[-1] if inverse else master));predicted=[]
        for level in range(9):
            predicted.append(state);mixed=[]
            for column in range(4):
                for row in range(4):
                    value=0
                    for source in range(4):value^=_gmul(matrix[row][source],box[state[4*((column+direction*source)%4)+source]])
                    mixed.append(value)
            round_key=mix_round_key(cipher._round_keys[9-level],inverse=True) if inverse else cipher._round_keys[level+1]
            state=bytes(a^b for a,b in zip(mixed,round_key))
        model=details['model'];table_index={ordinal:index for index,ordinal in enumerate(regular)}
        def decoded(event):
            index=table_index[event['ordinal']]
            return apply(model['decoders'][model['input_positions'][index]],event['index'])^model['translations'][index]
        equal=[];later_equal=[]
        for ordinal in regular:
            row=model['input_rows'][table_index[ordinal]]
            expected=Counter(predicted[level][4*column+row] for level in range(9) for column in range(4))
            actual=Counter(decoded(event) for event in full_events if event['ordinal']==ordinal)
            prefix_values=Counter(decoded(event) for event in selected if event['ordinal']==ordinal)
            expected_prefix=Counter(predicted[level][4*column+row] for level in range(count) for column in range(4))
            equal.append(actual==expected);later_equal.append(actual-prefix_values==expected-expected_prefix)
        valid=all(equal) and all(later_equal)
        checks.append(dict(all_nine_layer_row_multisets_equal=all(equal),later_row_multisets_equal=all(later_equal),
                           observed_regular_lookups=len(full_events),prefix_layers=count,ordering_proved=False))
        if valid:
            matching+=1
            if key_callback is not None:key_callback(master,details)
    return dict(status='complete-prefix and later row-multiset hypothesis checked',complete_prefix_layers=count,
                prefix_schedule=prefix,candidates_checked=len(candidates),matching_full_row_multisets=matching,
                checks=checks,key_bytes_written=0,
                scope='key candidate from complete projected prefix, later per-row value multisets checked independently; does not establish ordering, final output, parameter initialization or GUID/auth')
