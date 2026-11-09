"""Source GUID cipher paths with static protocol parameters and portable AES.

Internal block operations only: these are two separately parameterized native
protocol paths, not a mutually inverse public cipher API or a complete GUID
provider. No native library, emulator, wrapper checkout or image is accessed.
"""
from ..crypto.masked_cbc import MaskedCBC
from . import _guid_parameters as parameters


def _xor(left,right):
    return bytes(a^b for a,b in zip(left,right))


def encrypt_blocks(plaintext:bytes)->bytes:
    """Execute the CoreFP forward GUID path, without padding."""
    mask=parameters.ENCRYPT_OUTPUT_MASK
    cipher=MaskedCBC(parameters.KEY,mask,mask,
                     plaintext_mask=_xor(parameters.ENCRYPT_INPUT_MASK,mask))
    return cipher.encrypt(plaintext,parameters.ENCRYPT_INITIAL_FEEDBACK)


def decrypt_blocks(ciphertext:bytes)->bytes:
    """Execute the distinct CoreFP inverse GUID path, without padding."""
    mask=parameters.DECRYPT_INPUT_MASK
    cipher=MaskedCBC(parameters.KEY,mask,mask,
                     plaintext_mask=_xor(mask,parameters.DECRYPT_OUTPUT_MASK))
    return cipher.decrypt(ciphertext,parameters.DECRYPT_INITIAL_FEEDBACK)
