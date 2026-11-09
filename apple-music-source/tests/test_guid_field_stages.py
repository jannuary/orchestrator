"""Invented-state original-instruction known answers for bounded GUID stages."""
import json
from pathlib import Path
import unittest

import _support  # noqa: F401
from apple_music_source.auth._guid_field_stages import mix20,unmix20,encode_bytes


class GuidFieldStageTests(unittest.TestCase):
    def test_original_instruction_known_answers_and_inverse(self):
        vectors=json.loads((Path(__file__).parent/'vectors/guid_field_mixer.json').read_text())
        self.assertEqual(len(vectors['cases']),4)
        for case in vectors['cases']:
            original=bytes.fromhex(case['input']);expected=bytes.fromhex(case['output'])
            with self.subTest(input=case['input']):
                self.assertEqual(mix20(original),expected)
                self.assertEqual(unmix20(expected),original)

    def test_state_is_copied_and_invalid_states_are_rejected(self):
        state=bytearray(range(20));saved=bytes(state);result=mix20(state)
        self.assertEqual(bytes(state),saved)
        self.assertEqual(unmix20(result),saved)
        for invalid in (b'',bytes(19),bytes(21),'x'*20,None,memoryview(bytes(40)).cast('H')):
            for operation in (mix20,unmix20):
                with self.assertRaises(ValueError):operation(invalid)

    def test_original_byte_transform_boundary_answers(self):
        self.assertEqual(encode_bytes(bytes([0,1,255])),bytes([18,185,107]))
        self.assertEqual(encode_bytes(b''),b'')
        self.assertEqual(encode_bytes(memoryview(bytes([0,1])).cast('H')),bytes([18,185]))
        self.assertEqual(len(set(encode_bytes(bytes(range(256))))),256)
        with self.assertRaises(ValueError):encode_bytes('not bytes')
