"""Validate round-state dependencies and key expansion without writing keys.

This developer analysis keeps decoded bytes, candidate keys and encodings only
in RAM. A match is evidence about the observed round prefix, not a standalone
cipher implementation, a whole-source proof or successful authentication.
"""
from itertools import permutations

from analyze_table_algebra import apply


def invert_first_round_key(round_key):
    return invert_round_key(round_key,1)


def invert_round_key(round_key,round_number):
    from apple_music_source.crypto.aes import _SBOX,_gmul
    if len(round_key)!=16 or not 1<=round_number<=10:raise ValueError('invalid AES-128 round-key shape')
    key=bytes(round_key);xor=lambda a,b:[x^y for x,y in zip(a,b)]
    for level in range(round_number,0,-1):
        words=[list(key[j:j+4]) for j in range(0,16,4)]
        last=xor(words[3],words[2]);second_last=xor(words[2],words[1]);second=xor(words[1],words[0])
        transformed=[_SBOX[x] for x in last[1:]+last[:1]];rcon=1
        for _ in range(level-1):rcon=_gmul(rcon,2)
        transformed[0]^=rcon;key=bytes(xor(words[0],transformed)+second+second_last+last)
    return key


def mix_round_key(round_key,inverse=False):
    from apple_music_source.crypto.aes import _gmul
    from analyze_table_algebra import FORWARD,INVERSE
    matrix=INVERSE if inverse else FORWARD;result=[]
    for column in range(4):
        for row in range(4):
            value=0
            for source in range(4):value^=_gmul(matrix[row][source],round_key[4*column+source])
            result.append(value)
    return bytes(result)


def analyze(trace,models,regular,key_callback=None):
    from apple_music_source.crypto.aes import AES,_SBOX,_INV_SBOX,_gmul
    events=[];seen=set();duplicates=0;regular_occurrences=0
    for event in trace.events:
        if event['ordinal'] not in regular:continue
        regular_occurrences+=1
        if regular_occurrences>16 and event['variable'] in seen:duplicates+=1;continue
        seen.add(event['variable']);events.append(event)
    # Native scheduling can start a next-round lookup before the final lookup
    # of the current round. Execution-order chunks silently truncate that DAG.
    # Assign each distinct lookup by dependency depth before checking layers.
    table_indices={ordinal:i for i,ordinal in enumerate(regular)};layers=[];groups=[];cursor=0;depth={};by_depth={}
    for event in events:
        dependencies=event['dependencies']
        if any(variable not in depth for variable in dependencies):break
        prior={depth[variable] for variable in dependencies}
        if len(prior)>1:break
        level=next(iter(prior))+1 if prior else 0
        depth[event['variable']]=level;by_depth.setdefault(level,[]).append(event)
    for level in range(len(by_depth)):
        layer=by_depth.get(level,[])
        if len(layer)!=16:break
        if layers and len({event['variable'] for event in layer})!=16:break
        if any(sum(event['ordinal']==ordinal for event in layer)!=4 for ordinal in regular):break
        if not layers:
            if any(event['dependencies'] for event in layer):break
            groups.append(None)
        else:
            previous={event['variable'] for event in layers[-1]}
            if any(len(event['dependencies'])!=4 or not event['dependencies']<=previous for event in layer):break
            unique=sorted({tuple(sorted(event['dependencies'])) for event in layer})
            if len(unique)!=4 or set().union(*(set(group) for group in unique))!=previous:break
            if any(sum(tuple(sorted(event['dependencies']))==group for event in layer)!=4 for group in unique):break
            groups.append(unique)
        layers.append(layer);cursor+=16
    result=dict(observed_round_input_layers=len(layers),unambiguous_regular_lookups=cursor,
                proven_repeated_lookups_ignored=duplicates,candidate_encodings=len(models),private_parameters_emitted=False,
                layer_grouping='lookup dependency depth, allowing interleaved native round scheduling')
    if len(layers)<3:return dict(result,status='insufficient unambiguous round prefix')
    candidate_layouts=valid_layouts=key_candidates=0;matching_models=[];independent_checks=[];directions=[]
    for model in models:
        if (model['mix_name'],model['spec_name'])==('AES-forward-MixColumns','AES-S-box'):direction=1;box=_SBOX
        elif (model['mix_name'],model['spec_name'])==('AES-inverse-MixColumns','AES-inverse-S-box'):direction=-1;box=_INV_SBOX
        else:continue
        rows=model['input_rows'];output_rows=model['output_rows'];coefficients=model['mixing_coefficients']
        def row(event):return rows[table_indices[event['ordinal']]]
        def value(event):
            i=table_indices[event['ordinal']]
            return apply(model['decoders'][model['input_positions'][i]],event['index'])^model['translations'][i]
        for initial in permutations(range(4)):
            candidate_layouts+=1;labels={group:initial[j] for j,group in enumerate(groups[1])};keys=[];valid=True
            for level in range(1,len(layers)):
                layer=layers[level];previous={event['variable']:event for event in layers[level-1]}
                if level>1:
                    next_labels={}
                    for group in groups[level]:
                        columns={(labels[tuple(sorted(previous[variable]['dependencies']))]-direction*row(previous[variable]))%4 for variable in group}
                        if len(columns)!=1:valid=False;break
                        next_labels[group]=columns.pop()
                    if not valid or set(next_labels.values())!=set(range(4)):valid=False;break
                    labels=next_labels
                key=[None]*16
                for event in layer:
                    group=tuple(sorted(event['dependencies']));canonical_row=row(event);physical_row=output_rows.index(canonical_row)
                    mixed=0
                    for variable in group:
                        before=previous[variable];i=table_indices[before['ordinal']]
                        mixed^=_gmul(coefficients[i][physical_row],box[value(before)])
                    at=4*labels[group]+canonical_row
                    if key[at] is not None:valid=False;break
                    key[at]=value(event)^mixed
                if not valid or any(value_ is None for value_ in key):valid=False;break
                keys.append(bytes(key))
            if not valid:continue
            valid_layouts+=1
            master=invert_first_round_key(keys[0]) if direction==1 else invert_round_key(mix_round_key(keys[0]),9)
            expanded=AES(master)._round_keys
            if direction==1:expected=[bytes(expanded[level+1]) for level in range(len(keys))]
            else:expected=[mix_round_key(expanded[9-level],inverse=True) for level in range(len(keys))]
            if keys!=expected:continue
            key_candidates+=1;matching_models.append(model);independent_checks.append(len(keys)-1)
            directions.append('forward' if direction==1 else 'equivalent-inverse')
            if key_callback is not None:key_callback(master,dict(model=model,first_group_labels={group:initial[j] for j,group in enumerate(groups[1])},
                                                               layers=layers,groups=groups,cipher_direction=direction))
    result.update(status='complete observed-prefix AES-128 schedule check',column_layouts_checked=candidate_layouts,
                  ShiftRows_compatible_layouts=valid_layouts,matching_key_schedule_candidates=key_candidates,
                  independently_matching_round_keys=independent_checks,
                  matching_cipher_directions=directions,
                  recovered_key_bytes_written=0,
                  scope='observed unambiguous AES-128 forward/equivalent-inverse prefix only; first observed key reversed in RAM, later keys checked independently; not complete cipher/chaining/source/auth proof')
    return result


def recover_input(master,details,regular):
    """Return one logical input only to the RAM-only caller, never a report."""
    model=details['model'];events={event['variable']:event for event in details['layers'][0]}
    direction=details.get('cipher_direction',1)
    if direction==1:initial_key=master
    else:
        from apple_music_source.crypto.aes import AES
        initial_key=AES(master)._round_keys[-1]
    indices={ordinal:i for i,ordinal in enumerate(regular)};state=[None]*16
    for group,column in details['first_group_labels'].items():
        for variable in group:
            event=events[variable];i=indices[event['ordinal']];row=model['input_rows'][i]
            value=apply(model['decoders'][model['input_positions'][i]],event['index'])^model['translations'][i]
            at=4*((column+direction*row)%4)+row;assert state[at] is None
            state[at]=value^initial_key[at]
    assert all(value is not None for value in state)
    return bytes(state)
