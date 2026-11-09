"""Check final-lookup index rows against independently predicted AES states.

Tests reuse of the observed regular-round byte codecs, retaining all decoded
states and maps in RAM. It deliberately does not infer output encodings.
"""
from collections import Counter
from itertools import permutations

from analyze_round_key_schedule import recover_input,mix_round_key
from analyze_table_algebra import apply,FORWARD,INVERSE


def check(master,details,observed):
    from apple_music_source.crypto.aes import AES,_SBOX,_INV_SBOX,_gmul
    inverse=details['cipher_direction']==-1;direction=-1 if inverse else 1
    matrix=INVERSE if inverse else FORWARD;box=_INV_SBOX if inverse else _SBOX
    aes=AES(master);original=recover_input(master,details,range(4))
    initial=aes._round_keys[-1] if inverse else master
    state=[a^b for a,b in zip(original,initial)]
    for level in range(9):
        mixed=[]
        for column in range(4):
            for row in range(4):
                value=0
                for source in range(4):value^=_gmul(matrix[row][source],box[state[4*((column+direction*source)%4)+source]])
                mixed.append(value)
        key=mix_round_key(aes._round_keys[9-level],inverse=True) if inverse else aes._round_keys[level+1]
        state=[a^b for a,b in zip(mixed,key)]
    final=[event for event in observed if event[1]>=4]
    if len(final)!=16 or any(sum(event[1]==ordinal for event in final)!=4 for ordinal in range(4,8)):
        return dict(status='final index shape rejected',private_bytes_written=False)
    model=details['model'];matches=translated_matches=0
    for assignment in permutations(range(4)):
        valid=True
        for ordinal,index in enumerate(assignment,4):
            decoded=Counter(apply(model['decoders'][model['input_positions'][index]],event[2])^model['translations'][index]
                            for event in final if event[1]==ordinal)
            row=model['input_rows'][index]
            if decoded!=Counter(state[4*column+row] for column in range(4)):valid=False;break
        if valid:matches+=1
        valid=True
        for ordinal,index in enumerate(assignment,4):
            decoded=[apply(model['decoders'][model['input_positions'][index]],event[2])
                     for event in final if event[1]==ordinal]
            row=model['input_rows'][index];expected=Counter(state[4*column+row] for column in range(4))
            candidates={decoded[0]^value for value in expected}
            if not any(Counter(value^shift for value in decoded)==expected for shift in candidates):valid=False;break
        if valid:translated_matches+=1
    return dict(status='final index codec-reuse hypothesis checked',final_lookup_indices=16,
                matching_row_codec_assignments=matches,matching_translated_row_codec_assignments=translated_matches,private_bytes_written=False,
                scope='predicted final AES input row multisets only; execution-order column placement, final output encoding, whitening, chaining and source initializer remain unproved')
