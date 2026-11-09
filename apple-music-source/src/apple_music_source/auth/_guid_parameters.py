"""Static CoreFP GUID cipher parameters, not account/session/content keys.

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

ARTIFACT_SHA256 = 'cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175'
SOURCE_INTERVALS = ((0x3BCA00, 0x3C0A7E), (0x651A10, 0x656595))

KEY = bytes.fromhex('e432d8e4715951de4d51a22ebe3f4299')
ENCRYPT_INPUT_MASK = bytes.fromhex('d9a17137bd098d947d99210ba9d1bcb1')
ENCRYPT_OUTPUT_MASK = bytes.fromhex('10f83ddb667df49863de86b18cbdc3a5')
ENCRYPT_INITIAL_FEEDBACK = bytes.fromhex('1ebe7507673bfd0aea526549ced0fa14')
DECRYPT_INPUT_MASK = bytes.fromhex('06091e97a0b743ce4d8019dd602ecc40')
DECRYPT_OUTPUT_MASK = bytes.fromhex('c056d48b92700fb148d4f3ddc6b6232a')
DECRYPT_INITIAL_FEEDBACK = bytes.fromhex('084f564ba1f14a5cc40cfa252243f5f1')
