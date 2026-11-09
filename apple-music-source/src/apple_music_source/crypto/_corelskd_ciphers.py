"""Two fixed CoreLSKD AES/CBC byte transforms, without SDK/context captures.

Internal primitives for source integration. Each variant has its own key and
masks; decrypt is the mathematical inverse of that variant's forward transform.
These functions do not generate an SPC, process a CKC or acquire a content key.
"""
from .aes import AESError
from .masked_cbc import MaskedCBC
from . import _corelskd_parameters as parameters


def _cipher(variant):
    if type(variant) is not int or variant not in (0,1):raise AESError('unknown CoreLSKD cipher variant')
    prefix='KERNEL_'+str(variant)+'_'
    return MaskedCBC(getattr(parameters,prefix+'KEY'),getattr(parameters,prefix+'IV_MASK'),
                     getattr(parameters,prefix+'OUTPUT_MASK'))


def encrypt(variant:int,plaintext:bytes,iv:bytes)->bytes:
    """Execute one source forward byte transform, without padding."""
    return _cipher(variant).encrypt(plaintext,iv)


def decrypt(variant:int,ciphertext:bytes,iv:bytes)->bytes:
    """Invert that variant's forward byte transform, without padding."""
    return _cipher(variant).decrypt(ciphertext,iv)
