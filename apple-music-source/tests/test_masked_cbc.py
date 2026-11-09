"""Specification/invented controls; no target key, mask, image or exchange."""
import unittest

import _support  # noqa: F401
from apple_music_source.crypto import MaskedCBC, AESError, aes_cbc_encrypt
from test_aes import CBC_KEY, CBC_IV, CBC_PLAINTEXT, CBC_CIPHERTEXT


def xor(left, right):
    return bytes(a ^ b for a, b in zip(left, right))


class MaskedCbcTests(unittest.TestCase):
    def test_zero_masks_match_nist_cbc(self):
        cipher = MaskedCBC(CBC_KEY, bytes(16), bytes(16))
        self.assertEqual(cipher.encrypt(CBC_PLAINTEXT, CBC_IV), CBC_CIPHERTEXT)
        self.assertEqual(cipher.decrypt(CBC_CIPHERTEXT, CBC_IV), CBC_PLAINTEXT)

    def test_masked_multiblock_result_matches_independent_cbc(self):
        iv_mask = bytes(range(16))
        output_mask = bytes((17 * i + 29) & 255 for i in range(16))
        cipher = MaskedCBC(CBC_KEY, iv_mask, output_mask)
        ordinary = aes_cbc_encrypt(CBC_KEY, xor(CBC_IV, iv_mask), CBC_PLAINTEXT, pad=False)
        expected = bytes(value ^ output_mask[i % 16] for i, value in enumerate(ordinary))
        encrypted = cipher.encrypt(CBC_PLAINTEXT, CBC_IV)
        self.assertEqual(encrypted, expected)
        self.assertEqual(cipher.decrypt(encrypted, CBC_IV), CBC_PLAINTEXT)
        # A fresh call always applies the IV mask; remove both masks from the
        # prior returned block when carrying the logical chain across calls.
        continuation_iv = xor(xor(encrypted[:16], output_mask), iv_mask)
        self.assertEqual(cipher.encrypt(CBC_PLAINTEXT[16:], continuation_iv), encrypted[16:])

    def test_empty_inputs_and_strict_unpadded_block_lengths(self):
        cipher = MaskedCBC(CBC_KEY, bytes(16), bytes(16))
        for function in (cipher.encrypt, cipher.decrypt):
            self.assertEqual(function(b"", CBC_IV), b"")
            for size in (1, 15, 17, 31):
                with self.assertRaises(AESError):
                    function(bytes(size), CBC_IV)
            for iv in (b"", bytes(15), bytes(17), "iv"):
                with self.assertRaises(AESError):
                    function(bytes(16), iv)

    def test_plaintext_whitening_matches_nist_message(self):
        plaintext_mask = bytes((31 * i + 7) & 255 for i in range(16))
        iv_mask, output_mask = bytes(range(16)), bytes(range(16, 32))
        whitened = bytes(value ^ plaintext_mask[i % 16] for i, value in enumerate(CBC_PLAINTEXT))
        expected = bytes(value ^ output_mask[i % 16] for i, value in enumerate(CBC_CIPHERTEXT))
        cipher = MaskedCBC(CBC_KEY, iv_mask, output_mask, plaintext_mask=plaintext_mask)
        self.assertEqual(cipher.encrypt(whitened, xor(CBC_IV, iv_mask)), expected)
        self.assertEqual(cipher.decrypt(expected, xor(CBC_IV, iv_mask)), whitened)

    def test_plaintext_mask_is_copied_and_validated(self):
        mask = bytearray(range(16))
        cipher = MaskedCBC(CBC_KEY, bytes(16), bytes(16), plaintext_mask=mask)
        reference = cipher.encrypt(CBC_PLAINTEXT, CBC_IV)
        mask[:] = bytes(16)
        self.assertEqual(cipher.encrypt(CBC_PLAINTEXT, CBC_IV), reference)
        for invalid in (bytes(15), bytes(17), "mask", None):
            with self.assertRaises(AESError):
                MaskedCBC(CBC_KEY, bytes(16), bytes(16), plaintext_mask=invalid)

    def test_parameters_are_copied_validated_and_not_in_repr(self):
        key, iv_mask, output_mask = bytearray(CBC_KEY), bytearray(range(16)), bytearray(range(16, 32))
        reference = MaskedCBC(bytes(key), bytes(iv_mask), bytes(output_mask))
        cipher = MaskedCBC(key, iv_mask, output_mask)
        key[:] = bytes(16)
        iv_mask[:] = bytes(16)
        output_mask[:] = bytes(16)
        self.assertEqual(cipher.encrypt(CBC_PLAINTEXT, CBC_IV), reference.encrypt(CBC_PLAINTEXT, CBC_IV))
        self.assertNotIn(CBC_KEY.hex(), repr(cipher))
        for values in ((bytes(24), bytes(16), bytes(16)), (bytes(16), bytes(15), bytes(16)),
                       (bytes(16), bytes(16), bytes(17)), ("key", bytes(16), bytes(16))):
            with self.assertRaises(AESError):
                MaskedCBC(*values)
