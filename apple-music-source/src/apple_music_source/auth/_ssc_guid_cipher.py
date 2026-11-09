"""Internal StoreServices GUID block streams, without SDK dependencies.

The named static parameters describe two native byte paths. These primitives do
not derive complete GUID fields or implement an authentication provider.
"""
from ..crypto.masked_cbc import MaskedCBC
from . import _ssc_guid_parameters as parameters


def encrypt_blocks(plaintext: bytes) -> bytes:
    """Apply the native forward AES-128/whitening/CBC stream without padding."""
    mask=bytes(a^b for a,b in zip(parameters.INPUT_MASK,parameters.OUTPUT_MASK))
    cipher=MaskedCBC(parameters.KEY,parameters.OUTPUT_MASK,parameters.OUTPUT_MASK,plaintext_mask=mask)
    return cipher.encrypt(plaintext,parameters.INITIAL_FEEDBACK)


def decrypt_blocks(ciphertext: bytes) -> bytes:
    """Apply the native inverse AES/whitening/CBC stream without padding.

    The two native paths have separate masks and feedback; this operation is
    not assumed to be the inverse of encrypt_blocks.
    """
    from . import _ssc_guid_inverse_parameters as inverse
    mask=bytes(a^b for a,b in zip(inverse.INPUT_MASK,inverse.OUTPUT_MASK))
    cipher=MaskedCBC(inverse.KEY,inverse.INPUT_MASK,inverse.INPUT_MASK,plaintext_mask=mask)
    return cipher.decrypt(ciphertext,inverse.INITIAL_FEEDBACK)
