"""Validate caller-buffer CBC with RAM-only parameters and held-out messages.

Two blocks in the first invented profile identify a bounded whitening model.
The second profile is predicted without fitting to its buffers or logical state.
This is behavioral developer evidence, not an initializer or auth provider.
"""


def xor(*values):
    if not values or any(len(value)!=16 for value in values):raise ValueError('invalid block shape')
    result=bytearray(16)
    for value in values:
        for index,byte in enumerate(value):result[index]^=byte
    return bytes(result)


def analyze(blocks,parameter_callback=None):
    from apple_music_source.crypto.aes import AES
    from apple_music_source.crypto.masked_cbc import MaskedCBC
    rows=[];parameters={}
    for kernel in range(2):
        wanted=[(kernel,profile,block) for profile in range(2) for block in range(2)]
        if any(key not in blocks or blocks[key][3] is None for key in wanted):
            rows.append(dict(kernel=kernel,status='insufficient caller buffers',private_bytes_written=False));continue
        first,second=(blocks[kernel,0,block] for block in range(2))
        key,logical,mask,raw,actual=first
        if any(blocks[at][0]!=key for at in wanted):
            rows.append(dict(kernel=kernel,status='master key changed',private_bytes_written=False));continue
        inverse=kernel==0
        if inverse:
            input_mask=xor(logical,raw);output_mask=xor(second[2],raw);iv=xor(mask,output_mask)
        else:
            output_mask=mask;input_mask=xor(second[1],second[3],actual);iv=xor(logical,raw,input_mask)
        cipher=AES(key);checks=[]
        ciphertext_mask=input_mask if inverse else output_mask
        portable=MaskedCBC(key,ciphertext_mask,ciphertext_mask,plaintext_mask=xor(input_mask,output_mask))
        for profile in range(2):
            chain=iv;outputs=states=0
            for block in range(2):
                _,expected_state,_,raw,expected_output=blocks[kernel,profile,block]
                state=xor(raw,input_mask) if inverse else xor(raw,chain,input_mask)
                predicted=xor(cipher.decrypt_block(state),chain,output_mask) if inverse else xor(cipher.encrypt_block(state),output_mask)
                states+=state==expected_state;outputs+=predicted==expected_output
                chain=raw if inverse else predicted
            message=b''.join(blocks[kernel,profile,block][3] for block in range(2))
            expected=b''.join(blocks[kernel,profile,block][4] for block in range(2))
            package_output=portable.decrypt(message,iv) if inverse else portable.encrypt(message,iv)
            checks.append(dict(profile=profile,matched_logical_inputs=states,matched_complete_outputs=outputs,
                               package_CBC_complete_message_equal=package_output==expected,
                               independent_heldout=profile!=0))
        parameters[kernel]=(key,input_mask,output_mask,iv)
        rows.append(dict(kernel=kernel,direction='inverse' if inverse else 'forward',
            status='caller-buffer whitening CBC hypothesis checked',training_blocks=2,heldout_blocks=2,
            heldout_inputs_changed=all(blocks[kernel,1,block][3]!=blocks[kernel,0,block][3] for block in range(2)),
            message_checks=checks,private_bytes_written=False))
    reciprocal=None
    if len(parameters)==2:
        dec_key,dec_in,dec_out,dec_iv=parameters[0];enc_key,enc_in,enc_out,enc_iv=parameters[1]
        reciprocal=dict(same_master_key=dec_key==enc_key,reciprocal_whitening_masks=dec_in==enc_out and dec_out==enc_in,
                        same_initial_feedback=dec_iv==enc_iv)
    if parameter_callback is not None and len(parameters)==2 and all(
            message['matched_logical_inputs']==message['matched_complete_outputs']==2 and message['package_CBC_complete_message_equal']
            for row in rows for message in row.get('message_checks',[])):
        parameter_callback(parameters)
    return dict(status='bounded caller-buffer CBC investigation',paths=rows,reciprocal_parameter_relations=reciprocal,
                private_bytes_written=False,
                scope='parameters inferred from two first-profile blocks and used unchanged for two other-profile blocks per direction; this function emits no parameters, but an explicit outer generator may export named static protocol parameters after extra oracle checks; no full GUID or native-auth claim')
