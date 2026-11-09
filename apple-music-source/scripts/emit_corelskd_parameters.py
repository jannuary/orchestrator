"""Emit 96 named static CoreLSKD cipher parameters after guarded validation."""
from pathlib import Path
import hashlib

from verify_integrity_codec import HASH


def emit(path,parameters):
    assert set(parameters)=={0,1}
    assert all(len(values)==3 and all(len(value)==16 for value in values) for values in parameters.values())
    text='''"""Static CoreLSKD AES parameters; no account/session/content keys.

Two source byte transforms use distinct AES-128 keys, IV XOR masks and
ciphertext XOR masks (96 bytes total). They use standard CBC feedback.
No image data, S-box bank, encoding matrix or captured user context is present.

Developer generation requires original/source equality and unchanged-model
predictions in a fresh source session with different entropy, device seed and
content. Runtime does not access the generator, wrapper or original image.
"""

'''
    text+='ARTIFACT_SHA256 = '+repr(HASH)+'\n'
    text+='SOURCE_INTERVALS = ((0x526BC0, 0x530964), (0x530970, 0x53A675))\n\n'
    for kernel,values in sorted(parameters.items()):
        for label,value in zip(('KEY','IV_MASK','OUTPUT_MASK'),values):
            text+=f'KERNEL_{kernel}_{label} = bytes.fromhex('+repr(value.hex())+')\n'
    path=Path(path);path.parent.mkdir(parents=True,exist_ok=True);path.write_text(text)
    return dict(static_protocol_parameter_bytes=96,original_image_or_table_bank_bytes=0,account_session_content_secret_bytes=0,
                source_sha256=hashlib.sha256(text.encode()).hexdigest())
