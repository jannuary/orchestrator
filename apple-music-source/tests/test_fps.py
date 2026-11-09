"""Offline tests for catalog FPS request construction."""
import base64
import json
import unittest

import _support  # noqa: F401

from apple_music_source.auth import FpsRequest, FpsRequestError, build_fps_request

NATIVE = {
    "Cookie": "session=value",
    "x-dsid": "42",
    "x-token": "server-token",
    "User-Agent": "ua",
    "X-Apple-Store-Front": "143441-1,29",
    "Content-Length": "999",
    "Content-Type": "text/plain",
}
WEB = {
    "Authorization": "Bearer developer",
    "x-apple-music-user-token": "music",
    "user-agent": "ua",
}
METADATA = {
    "adamId": "123456789",
    "keyUri": "skd://itunes.apple.com/123456789",
    "guid": "device-guid",
}


class FpsTests(unittest.TestCase):
    def test_native_authentication_request(self):
        request = build_fps_request(
            metadata=dict(METADATA),
            spc=b"\x00spc\xff",
            headers=NATIVE,
        )
        body = json.loads(request.body)
        self.assertEqual(body, {
            "guid": "device-guid",
            "adamId": "123456789",
            "keyUri": "skd://itunes.apple.com/123456789",
            "spc": base64.b64encode(b"\x00spc\xff").decode(),
        })
        self.assertEqual(request.headers["content-type"], "application/json")
        self.assertEqual(request.headers["accept-encoding"], "gzip")
        self.assertEqual(request.headers["x-apple-store-front"], "143441-1,29")
        self.assertNotIn("content-length", request.headers)
        self.assertNotIn("Content-Length", request.headers)
        self.assertNotIn("spc", repr(request))

    def test_web_token_authentication_request(self):
        request = build_fps_request(metadata=METADATA, spc=b"spc", headers=WEB)
        self.assertEqual(request.headers["authorization"], "Bearer developer")
        self.assertEqual(request.headers["x-apple-music-user-token"], "music")

    def test_offline_flag(self):
        request = build_fps_request(
            metadata={**METADATA, "offline": True}, spc=b"spc", headers=WEB)
        self.assertIs(json.loads(request.body)["offline"], True)
        with self.assertRaises(FpsRequestError):
            build_fps_request(metadata={**METADATA, "offline": "yes"},
                              spc=b"spc", headers=WEB)

    def test_missing_authentication_is_rejected(self):
        for headers in (
            {},
            {"x-dsid": "42", "x-token": "t", "user-agent": "ua"},
            {**WEB, "Authorization": ""},
            {**NATIVE, "X-Apple-Store-Front": ""},
            {k: v for k, v in NATIVE.items() if k.lower() != "cookie"},
        ):
            with self.subTest(headers=headers):
                with self.assertRaises(FpsRequestError):
                    build_fps_request(metadata=METADATA, spc=b"spc", headers=headers)

    def test_metadata_validation(self):
        for metadata in (
            {},
            {**METADATA, "adamId": "12a"},
            {**METADATA, "adamId": ""},
            {**METADATA, "keyUri": "https://example.test/key"},
            {**METADATA, "guid": ""},
            {**METADATA, "guid": "bad\0"},
            {**METADATA, "adamId": 0},
        ):
            with self.subTest(metadata=metadata):
                with self.assertRaises(FpsRequestError):
                    build_fps_request(metadata=metadata, spc=b"spc", headers=NATIVE)

    def test_spc_validation(self):
        for spc in (b"", "", 5):
            with self.subTest(spc=spc):
                with self.assertRaises(FpsRequestError):
                    build_fps_request(metadata=METADATA, spc=spc, headers=NATIVE)
        self.assertEqual(
            json.loads(build_fps_request(
                metadata=METADATA, spc=bytearray(b"spc"), headers=NATIVE).body)["spc"],
            base64.b64encode(b"spc").decode(),
        )

    def test_header_injection_is_rejected(self):
        for headers in (
            {"x": "bad\r\nvalue", **WEB},
            {"bad\r\nname": "value", **WEB},
            {"": "value", **WEB},
            {":authority": "value", **WEB},
            {**WEB, "x": 5},
        ):
            with self.subTest(headers=headers):
                with self.assertRaises(FpsRequestError):
                    build_fps_request(metadata=METADATA, spc=b"spc", headers=headers)

    def test_native_headers_are_never_logged(self):
        request = build_fps_request(metadata=METADATA, spc=b"spc", headers=NATIVE)
        self.assertNotIn("server-token", repr(request))
        self.assertNotIn("session=value", repr(request))


if __name__ == "__main__":
    unittest.main()
