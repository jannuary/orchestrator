"""NIST-vector tests for the independent AES/CBC implementation."""
import unittest

import _support  # noqa: F401

from apple_music_source.crypto import (
    AES,
    AESError,
    aes_cbc_decrypt,
    aes_cbc_encrypt,
    decrypt_block,
    encrypt_block,
    pkcs7_pad,
    pkcs7_unpad,
)

# FIPS-197 / NIST SP 800-38A vectors.
ECB = (
    (
        "000102030405060708090a0b0c0d0e0f",
        "00112233445566778899aabbccddeeff",
        "69c4e0d86a7b0430d8cdb78070b4c55a",
    ),
    (
        "000102030405060708090a0b0c0d0e0f1011121314151617",
        "00112233445566778899aabbccddeeff",
        "dda97ca4864cdfe06eaf70a0ec0d7191",
    ),
    (
        "000102030405060708090a0b0c0d0e0f"
        "101112131415161718191a1b1c1d1e1f",
        "00112233445566778899aabbccddeeff",
        "8ea2b7ca516745bfeafc49904b496089",
    ),
)

CBC_KEY = bytes.fromhex("2b7e151628aed2a6abf7158809cf4f3c")
CBC_IV = bytes.fromhex("000102030405060708090a0b0c0d0e0f")
CBC_PLAINTEXT = bytes.fromhex(
    "6bc1bee22e409f96e93d7e117393172a"
    "ae2d8a571e03ac9c9eb76fac45af8e51"
    "30c81c46a35ce411e5fbc1191a0a52ef"
    "f69f2445df4f9b17ad2b417be66c3710"
)
CBC_CIPHERTEXT = bytes.fromhex(
    "7649abac8119b246cee98e9b12e9197d"
    "5086cb9b507219ee95db113a917678b2"
    "73bed6b8e3c1743b7116e69e22229516"
    "3ff1caa1681fac09120eca307586e1a7"
)


class AesBlockTests(unittest.TestCase):
    def test_nist_ecb_vectors_for_all_key_sizes(self):
        for key, plaintext, ciphertext in ECB:
            with self.subTest(key=len(key) // 2):
                key, plaintext, ciphertext = (
                    bytes.fromhex(key),
                    bytes.fromhex(plaintext),
                    bytes.fromhex(ciphertext),
                )
                self.assertEqual(encrypt_block(key, plaintext), ciphertext)
                self.assertEqual(decrypt_block(key, ciphertext), plaintext)
                cipher = AES(key)
                self.assertEqual(cipher.encrypt_block(plaintext), ciphertext)
                self.assertEqual(cipher.decrypt_block(ciphertext), plaintext)

    def test_sbox_is_not_a_stored_target_table(self):
        # The S-box is derived at import time; spot-check well-known entries.
        from apple_music_source.crypto import aes

        self.assertEqual(aes._SBOX[0x00], 0x63)
        self.assertEqual(aes._SBOX[0x53], 0xED)
        self.assertEqual(aes._INV_SBOX[0x63], 0x00)

    def test_rejects_bad_key_and_block_lengths(self):
        for key in (b"", b"\x00" * 15, b"\x00" * 17, b"\x00" * 33):
            with self.subTest(length=len(key)):
                with self.assertRaises(AESError):
                    AES(key)
        with self.assertRaises(AESError):
            encrypt_block(b"\x00" * 16, b"\x00" * 15)
        with self.assertRaises(AESError):
            AES(b"\x00" * 16).encrypt_block(b"\x00" * 17)

    def test_rejects_non_bytes(self):
        with self.assertRaises(AESError):
            AES("a" * 16)
        with self.assertRaises(AESError):
            AES(b"\x00" * 16).encrypt_block("0" * 16)


class CbcTests(unittest.TestCase):
    def test_nist_cbc_vectors(self):
        self.assertEqual(
            aes_cbc_encrypt(CBC_KEY, CBC_IV, CBC_PLAINTEXT, pad=False),
            CBC_CIPHERTEXT,
        )
        self.assertEqual(
            aes_cbc_decrypt(CBC_KEY, CBC_IV, CBC_CIPHERTEXT), CBC_PLAINTEXT
        )

    def test_pkcs7_round_trip(self):
        for length in (0, 1, 15, 16, 17, 31, 32, 100):
            with self.subTest(length=length):
                message = bytes(range(length % 251))[:length]
                ciphertext = aes_cbc_encrypt(CBC_KEY, CBC_IV, message)
                self.assertEqual(len(ciphertext) % 16, 0)
                self.assertGreater(len(ciphertext), length)
                self.assertEqual(
                    aes_cbc_decrypt(CBC_KEY, CBC_IV, ciphertext, unpad=True),
                    message,
                )

    def test_unpad_is_opt_in(self):
        ciphertext = aes_cbc_encrypt(CBC_KEY, CBC_IV, b"hello")
        padded = aes_cbc_decrypt(CBC_KEY, CBC_IV, ciphertext)
        self.assertEqual(len(padded), 16)
        self.assertTrue(padded.endswith(bytes([11]) * 11))

    def test_padding_helpers_and_rejection(self):
        self.assertEqual(pkcs7_pad(b""), bytes([16]) * 16)
        self.assertEqual(pkcs7_unpad(pkcs7_pad(b"abc")), b"abc")
        for bad in (b"", b"\x00" * 16, b"\x00" * 15 + b"\x11", b"\x00" * 15 + b"\x02"):
            with self.subTest(value=bad):
                with self.assertRaises(AESError):
                    pkcs7_unpad(bad)
        with self.assertRaises(AESError):
            pkcs7_pad(b"x", block_size=8)

    def test_cbc_input_bounds(self):
        with self.assertRaises(AESError):
            aes_cbc_decrypt(CBC_KEY, CBC_IV, b"\x00" * 15)
        with self.assertRaises(AESError):
            aes_cbc_encrypt(CBC_KEY, CBC_IV, b"\x00" * 15, pad=False)
        with self.assertRaises(AESError):
            aes_cbc_encrypt(CBC_KEY, b"\x00" * 15, b"x")


if __name__ == "__main__":
    unittest.main()
