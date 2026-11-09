"""Public invented-message KATs recorded from pristine source execution.

The oracle runs without SPC, certificate, device or session setup. Vector
provenance is in vectors/corelskd_static_ciphers.json; no vendor table or key
bytes are stored in these test vectors. Tests need no external oracle.
"""
import json
from pathlib import Path
import unittest

import _support  # noqa: F401
from apple_music_source.crypto import AESError
from apple_music_source.crypto._corelskd_ciphers import encrypt, decrypt


class StaticCoreLSKDCipherTests(unittest.TestCase):
    def test_pristine_source_known_answers(self):
        vectors=json.loads((Path(__file__).parent/'vectors/corelskd_static_ciphers.json').read_text())
        self.assertEqual(len(vectors['cases']),4)
        for case in vectors['cases']:
            variant=case['variant'];iv=bytes.fromhex(case['iv'])
            plain=bytes.fromhex(case['plaintext']);ciphertext=bytes.fromhex(case['ciphertext'])
            with self.subTest(variant=variant,length=len(plain)):
                self.assertEqual(encrypt(variant,plain,iv),ciphertext)
                self.assertEqual(decrypt(variant,ciphertext,iv),plain)

    def test_unknown_variants_fail_closed(self):
        for variant in (-1,2,True,False,0.0,'0',None):
            for operation in (encrypt,decrypt):
                with self.subTest(variant=variant,operation=operation.__name__):
                    with self.assertRaises(AESError):operation(variant,bytes(16),bytes(16))
