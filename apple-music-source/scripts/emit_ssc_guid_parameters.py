"""Emit documented static StoreServices parameters after the caller's oracle gate."""
import hashlib
from pathlib import Path


def emit(path,parameters,inverse=False):
    if len(parameters)!=4 or any(type(value) is not bytes or len(value)!=16 for value in parameters):raise ValueError('invalid static parameter shape')
    source='''"""Static protocol parameters for one StoreServices GUID AES/CBC path.

Pinned libstoreservicescore.so SHA256:
6238261363d7943f1a0a27116b52544831f3e295e8533a634641fe5b09d92c7e
Source interval: 0x1f78b0..0x1fddc2.

64 named bytes: AES-128 key, plaintext/ciphertext XOR masks and initial CBC
feedback. Recovered from native instructions, checked against full source/
original outputs on invented profiles. No lookup words, binary/image bank,
encoding maps, account/session/content secrets or captured exchange is stored.
This is a block primitive, not a complete GUID or authentication provider.
"""
'''
    if inverse:source=source.replace('0x1f78b0..0x1fddc2','0x230ed0..0x2360e2').replace('one StoreServices GUID AES/CBC path','the inverse StoreServices GUID AES/CBC path')
    for name,value in zip(('KEY','INPUT_MASK','OUTPUT_MASK','INITIAL_FEEDBACK'),parameters):source+='\n'+name+' = bytes.fromhex("'+value.hex()+'")\n'
    path=Path(path);path.write_text(source)
    return dict(static_protocol_parameter_bytes=64,sha256=hashlib.sha256(path.read_bytes()).hexdigest(),original_table_or_image_bytes=0,account_session_content_secret_bytes=0)
