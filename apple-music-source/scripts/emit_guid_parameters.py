"""Emit named static GUID cipher parameters after full oracle validation.

Only this explicitly requested developer operation writes static vendor
protocol parameters. It never writes tables, encodings, snapshots, GUID
fields, or account/session/content secrets. Installation does not run it.
"""
import hashlib
from pathlib import Path

from scan_auth_substitutions import TARGETS


def emit(path,parameters):
    if set(parameters)!={0,1}:raise ValueError('both validated cipher paths required')
    if any(len(values)!=4 or any(len(value)!=16 for value in values) for values in parameters.values()):
        raise ValueError('invalid protocol parameter shape')
    if parameters[0][0]!=parameters[1][0]:raise ValueError('shared GUID key not established')
    filename,digest=TARGETS['corefp']
    text='''"""Static CoreFP GUID cipher parameters, not account/session/content keys.

These 112 bytes parameterize standard AES-128 with named XOR masks and
initial CBC feedback. There are no original image bytes, lookup tables,
affine encoding matrices, runtime snapshots or captured user material.

Developer provenance: scripts/trace_guid_rounds.py --blocks 2 --profiles 2
--export-guid-parameters. Before export, reconstructed C and original
instructions must agree on all eight complete output blocks and 1,280
lookup reads. Parameters fit to the first invented device profile must
predict both blocks of the second profile without refitting.

The forward and inverse native paths have different masks/initial feedback;
these two protocol operations are not asserted to invert one another.
"""

'''
    text+='ARTIFACT_SHA256 = '+repr(digest)+'\n'
    text+='SOURCE_INTERVALS = ((0x3BCA00, 0x3C0A7E), (0x651A10, 0x656595))\n\n'
    text+='KEY = bytes.fromhex('+repr(parameters[0][0].hex())+')\n'
    for kernel,prefix in ((1,'ENCRYPT'),(0,'DECRYPT')):
        for label,value in zip(('INPUT_MASK','OUTPUT_MASK','INITIAL_FEEDBACK'),parameters[kernel][1:]):
            text+=prefix+'_'+label+' = bytes.fromhex('+repr(value.hex())+')\n'
    destination=Path(path);destination.parent.mkdir(parents=True,exist_ok=True)
    destination.write_text(text)
    return dict(static_protocol_parameter_bytes=112,original_image_or_table_bytes=0,
                account_session_content_secret_bytes=0,module_sha256=hashlib.sha256(text.encode()).hexdigest())
