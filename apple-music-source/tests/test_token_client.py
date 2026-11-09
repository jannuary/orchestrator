"""Offline tests for developer/Music-user token exchange (invented values)."""
import base64
import json
from pathlib import Path
import tempfile
from types import SimpleNamespace
import unittest

import _support  # noqa: F401

from apple_music_source.auth import (
    HttpResult,
    TokenClient,
    TokenServiceError,
    WebTokens,
    api_token_signing_bytes,
    verify_amp_tokens,
)

BAG = {
    "sf-api-token-service-url": "https://sf-api-token-service.itunes.apple.com/apiToken",
    "createMusicToken": "https://play.itunes.apple.com/WebObjects/MZPlay.woa/wa/createMusicToken",
    "signed-actions": {"apiToken": {"apiToken": {
        "headers": ["x-apple-store-front", "x-apple-client-application",
                    "x-request-timestamp", "x-apple-amd-m", "x-dsid"],
        "fields": ["clientId"],
    }}},
}


class Transport:
    def __init__(self, *responses):
        self.responses = list(responses)
        self.calls = []

    def get(self, url, headers, *, timeout):
        self.calls.append(("GET", url, None, dict(headers)))
        return self.responses.pop(0)

    def post(self, url, body, headers, *, timeout):
        self.calls.append(("POST", url, body, dict(headers)))
        return self.responses.pop(0)


class Machine:
    def __init__(self):
        self.accounts = []

    def otp(self, account):
        self.accounts.append(account)
        return SimpleNamespace(mid=b"mid", otp=b"otp")


class Signer:
    def __init__(self):
        self.messages = []

    def sign(self, data):
        self.messages.append(data)
        return b"signature"


def json_response(data, status=200):
    return HttpResult(status, json.dumps(data).encode())


class TokenTests(unittest.TestCase):
    def client(self, transport):
        self.machine, self.signer = Machine(), Signer()
        session = SimpleNamespace(dsid=42, token="native-test-token",
                                  storefront="143441-1,1")
        return TokenClient(session=session, guid="test-guid", bag=BAG,
                           transport=transport, machine_data=self.machine,
                           signer=self.signer, clock=lambda: 1700000000)

    def test_signing_policy_order_case_and_missing_values(self):
        headers = {"X-DSID": " 42 ", "x-apple-amd-m": "\tmid\t",
                   "x-apple-store-front": " storefront "}
        actual = api_token_signing_bytes(
            BAG["sf-api-token-service-url"], headers,
            {"clientId": "musicAndroid", "version": "not-signed"}, BAG)
        self.assertEqual(actual, b"storefrontmid42musicAndroid")
        self.assertNotIn(b"not-signed", actual)
        with self.assertRaises(ValueError):
            api_token_signing_bytes(BAG["sf-api-token-service-url"], {}, {}, {})
        with self.assertRaises(ValueError):
            api_token_signing_bytes(
                "https://example.test/other", headers, {"clientId": "x"}, BAG)

    def test_exchange_signs_developer_get_and_uses_developer_assertion(self):
        transport = Transport(json_response({"token": "developer.test.jwt"}),
                              json_response({"music_token": "music-test-token"}))
        tokens = self.client(transport).acquire()
        self.assertEqual((tokens.dev_token, tokens.music_token),
                         ("developer.test.jwt", "music-test-token"))
        self.assertEqual(self.machine.accounts, [-1, -1])
        expected = b"143441-1,1" + base64.b64encode(b"mid") + b"42musicAndroid"
        self.assertEqual(self.signer.messages, [expected])
        method, url, body, headers = transport.calls[0]
        self.assertEqual(method, "GET")
        self.assertTrue(url.endswith("?clientId=musicAndroid&version=1"))
        self.assertIsNone(body)
        self.assertEqual(headers["X-Apple-ActionSignature"],
                         base64.b64encode(b"signature").decode())
        self.assertNotIn("X-Request-Timestamp", headers)
        self.assertNotIn("X-Apple-Client-Application", headers)
        method, url, body, headers = transport.calls[1]
        self.assertEqual(method, "POST")
        self.assertEqual(json.loads(body), {
            "guid": "test-guid",
            "assertion": "developer.test.jwt",
            "tcc-acceptance-date": "1700000000000",
        })
        self.assertNotIn("X-Apple-ActionSignature", headers)
        self.assertEqual(headers["X-Apple-Requesting-Bundle-Id"],
                         "com.apple.android.music")

    def test_developer_rejection_never_attempts_music_exchange(self):
        transport = Transport(json_response({"status": "rejected"}, 401))
        with self.assertRaises(TokenServiceError) as raised:
            self.client(transport).acquire()
        self.assertEqual(raised.exception.stage, "developer-token")
        self.assertEqual(len(transport.calls), 1)

    def test_missing_token_is_not_replaced_by_cached_material(self):
        transport = Transport(json_response({"token": "developer"}),
                              json_response({"errors": ["private-server-text"]}))
        with self.assertRaises(TokenServiceError) as raised:
            self.client(transport).acquire()
        self.assertEqual(raised.exception.stage, "music-user-token")
        self.assertNotIn("private-server-text", str(raised.exception))

    def test_invalid_payloads_fail_closed(self):
        for payload in (b"not-json", b"[]", b'{"token": 5}', b'{"token": ""}'):
            with self.subTest(payload=payload):
                transport = Transport(HttpResult(200, payload))
                with self.assertRaises(TokenServiceError):
                    self.client(transport).developer_token()
        with self.assertRaises(ValueError):
            TokenClient(
                session=SimpleNamespace(dsid=1, token="t", storefront=""),
                guid="", bag=BAG, transport=Transport(), machine_data=Machine(),
                signer=Signer())

    def test_missing_machine_data_fails_closed(self):
        class EmptyMachine:
            def otp(self, account):
                return SimpleNamespace(mid=b"", otp=b"")

        session = SimpleNamespace(dsid=1, token="t", storefront="")
        client = TokenClient(session=session, guid="g", bag=BAG,
                             transport=Transport(), machine_data=EmptyMachine(),
                             signer=Signer())
        with self.assertRaises(ValueError):
            client.developer_token()

    def test_cache_files_are_private_and_compatible(self):
        tokens = WebTokens("developer-secret", "music-secret", "us")
        self.assertNotIn("secret", repr(tokens))
        with tempfile.TemporaryDirectory() as directory:
            base = Path(directory)
            tokens.save(base)
            cache = json.loads((base / "token_cache.json").read_text())
            self.assertEqual(cache, {
                "dev_token": "developer-secret",
                "music_token": "music-secret",
                "storefront_id": "us",
            })
            for name in ("token_cache.json", "DEV_TOKEN", "MUSIC_TOKEN",
                         "STOREFRONT_ID"):
                self.assertEqual((base / name).stat().st_mode & 0o777, 0o600)

    def test_amp_verification_sets_region_and_uses_the_new_pair(self):
        transport = Transport(json_response(
            {"data": [{"id": "tr", "type": "storefronts"}]}))
        tokens, metadata = verify_amp_tokens(
            transport, WebTokens("developer-secret", "music-secret"))
        self.assertEqual(tokens.storefront_id, "tr")
        self.assertEqual(metadata["amp_http_status"], 200)
        headers = transport.calls[0][3]
        self.assertEqual(headers["Authorization"], "Bearer developer-secret")
        self.assertEqual(headers["media-user-token"], "music-secret")
        self.assertNotIn("X-Token", headers)
        for data in ({"data": []}, {"data": ["invalid-row"]}):
            with self.assertRaises(ValueError):
                verify_amp_tokens(Transport(json_response(data)), tokens)
        with self.assertRaises(TokenServiceError):
            verify_amp_tokens(Transport(json_response({}, 401)), tokens)


if __name__ == "__main__":
    unittest.main()
