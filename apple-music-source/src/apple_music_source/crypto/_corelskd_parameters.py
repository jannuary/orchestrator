"""Static CoreLSKD AES parameters; no account/session/content keys.

Two source byte transforms use distinct AES-128 keys, IV XOR masks and
ciphertext XOR masks (96 bytes total). They use standard CBC feedback.
No image data, S-box bank, encoding matrix or captured user context is present.

Developer generation requires original/source equality and unchanged-model
predictions in a fresh source session with different entropy, device seed and
content. Runtime does not access the generator, wrapper or original image.
"""

ARTIFACT_SHA256 = '1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b'
SOURCE_INTERVALS = ((0x526BC0, 0x530964), (0x530970, 0x53A675))

KERNEL_0_KEY = bytes.fromhex('014ae5d09113379ff30b4e3de78aeb62')
KERNEL_0_IV_MASK = bytes.fromhex('6b519b37e8503d39a5053e2d25bf9eff')
KERNEL_0_OUTPUT_MASK = bytes.fromhex('7bd04b612e877d04483f8811c8a5b1a5')
KERNEL_1_KEY = bytes.fromhex('cfa9e335802e3f7215af0fa0f72e2afb')
KERNEL_1_IV_MASK = bytes.fromhex('6b519b37e8503d39a5053e2d25bf9eff')
KERNEL_1_OUTPUT_MASK = bytes.fromhex('7bd04b612e877d04483f8811c8a5b1a5')
