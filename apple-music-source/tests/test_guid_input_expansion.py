"""Public invented-input known answers from original expansion instructions."""
import json
from pathlib import Path
import unittest

import _support  # noqa: F401
from apple_music_source.auth._guid_input_expansion import expand328


class GuidInputExpansionTests(unittest.TestCase):
    def test_original_instruction_known_answers(self):
        vectors=json.loads((Path(__file__).parent/'vectors/guid_input_expansion.json').read_text())
        self.assertEqual(len(vectors['cases']),4)
        for case in vectors['cases']:
            value=bytearray.fromhex(case['input']);saved=bytes(value)
            with self.subTest(length=len(value)):
                self.assertEqual(expand328(value),bytes.fromhex(case['output']))
                self.assertEqual(bytes(value),saved)
                self.assertEqual(len(expand328(value)),328)

    def test_byte_views_and_invalid_inputs(self):
        self.assertEqual(expand328(memoryview(bytes(range(16))).cast('H')),expand328(bytes(range(16))))
        for value in (b'',bytearray(),memoryview(b''),'identifier',None,False):
            with self.assertRaises(ValueError):expand328(value)
