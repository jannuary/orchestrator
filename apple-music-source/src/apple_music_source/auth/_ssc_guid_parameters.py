"""Static protocol parameters for one StoreServices GUID AES/CBC path.

Pinned libstoreservicescore.so SHA256:
6238261363d7943f1a0a27116b52544831f3e295e8533a634641fe5b09d92c7e
Source interval: 0x1f78b0..0x1fddc2.

64 named bytes: AES-128 key, plaintext/ciphertext XOR masks and initial CBC
feedback. Recovered from native instructions, checked against full source/
original outputs on invented profiles. No lookup words, binary/image bank,
encoding maps, account/session/content secrets or captured exchange is stored.
This is a block primitive, not a complete GUID or authentication provider.
"""

KEY = bytes.fromhex("e432d8e4715951de4d51a22ebe3f4299")

INPUT_MASK = bytes.fromhex("99091dd7b911f66b8020913dffcd1562")

OUTPUT_MASK = bytes.fromhex("0b45c3d25287970d864f70d5557fa49b")

INITIAL_FEEDBACK = bytes.fromhex("05038b0e53c19e9f0fc3932d17129d2a")
