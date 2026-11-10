from __future__ import annotations

import ctypes
from functools import lru_cache

AES_BLOCK_SIZE = 16


class AesBackend:
    def __init__(self) -> None:
        self.library = ctypes.CDLL("libcrypto.so.3")
        signatures = {
            "EVP_CIPHER_CTX_new": ([], ctypes.c_void_p),
            "EVP_CIPHER_CTX_free": ([ctypes.c_void_p], None),
            "EVP_aes_128_cbc": ([], ctypes.c_void_p),
            "EVP_DecryptInit_ex": ([ctypes.c_void_p, ctypes.c_void_p, ctypes.c_void_p,
                                    ctypes.c_void_p, ctypes.c_void_p], ctypes.c_int),
            "EVP_CIPHER_CTX_set_padding": ([ctypes.c_void_p, ctypes.c_int], ctypes.c_int),
            "EVP_DecryptUpdate": ([ctypes.c_void_p, ctypes.c_void_p,
                                   ctypes.POINTER(ctypes.c_int), ctypes.c_void_p,
                                   ctypes.c_int], ctypes.c_int),
            "EVP_DecryptFinal_ex": ([ctypes.c_void_p, ctypes.c_void_p,
                                     ctypes.POINTER(ctypes.c_int)], ctypes.c_int),
        }
        for name, (arguments, result) in signatures.items():
            function = getattr(self.library, name)
            function.argtypes = arguments
            function.restype = result

    def decrypt(self, key: bytes, iv: bytes, data: bytes) -> bytes:
        if len(key) != AES_BLOCK_SIZE or len(iv) != AES_BLOCK_SIZE or len(data) % AES_BLOCK_SIZE:
            raise ValueError("AES-CBC requires a 128-bit key, IV and complete blocks")
        context = self.library.EVP_CIPHER_CTX_new()
        if not context:
            raise RuntimeError("could not allocate AES context")
        try:
            if self.library.EVP_DecryptInit_ex(context, self.library.EVP_aes_128_cbc(),
                                               None, key, iv) != 1:
                raise RuntimeError("could not initialize AES-CBC")
            if self.library.EVP_CIPHER_CTX_set_padding(context, 0) != 1:
                raise RuntimeError("could not disable AES padding")
            output = ctypes.create_string_buffer(len(data) + AES_BLOCK_SIZE)
            output_length = ctypes.c_int()
            if self.library.EVP_DecryptUpdate(context, output, ctypes.byref(output_length),
                                              data, len(data)) != 1:
                raise RuntimeError("AES-CBC decryption failed")
            final_length = ctypes.c_int()
            if self.library.EVP_DecryptFinal_ex(context, ctypes.byref(output, output_length.value),
                                                ctypes.byref(final_length)) != 1:
                raise RuntimeError("AES-CBC finalization failed")
            return output.raw[:output_length.value + final_length.value]
        finally:
            self.library.EVP_CIPHER_CTX_free(context)


@lru_cache(maxsize=1)
def aes_backend() -> AesBackend | None:
    try:
        return AesBackend()
    except OSError:
        return None
