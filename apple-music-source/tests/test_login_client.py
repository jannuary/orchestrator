"""Offline tests for login orchestration and guarded session publication."""
import plistlib
from pathlib import Path
import sqlite3
import tempfile
import unittest

import _support  # noqa: F401

from apple_music_source.auth import (
    AdjustedRequest,
    HttpResult,
    LoginClient,
    PlistResponseParser,
    PreparedAuthenticate,
    SessionAccount,
    SessionCookie,
    UnimplementedAdjuster,
    commit_session,
    load_bag,
)

BAG = {"authenticateAccount": "https://example.test/authenticate"}


def account_fields(dsid=42, token="server-token"):
    return {
        "accountInfo": {
            "dsPersonId": dsid,
            "appleId": "user@example.test",
            "creditDisplay": "None",
            "address": {"firstName": "Test", "lastName": "User"},
        },
        "xToken": token,
    }


def plist_response(fields, status=200):
    return HttpResult(status, plistlib.dumps(fields, fmt=plistlib.FMT_XML))


class Transport:
    def __init__(self, *responses):
        self.responses = list(responses)
        self.calls = []

    def post(self, url, body, headers, *, timeout):
        self.calls.append({"url": url, "body": body, "headers": dict(headers),
                           "timeout": timeout})
        if not self.responses:
            raise AssertionError("unexpected transport call")
        return self.responses.pop(0)


class Adjuster:
    def __init__(self, *, headers=None, body=None):
        self.headers = headers if headers is not None else {}
        self.body = body
        self.requests = []

    def adjust(self, request):
        self.requests.append(request)
        return AdjustedRequest(self.body if self.body is not None else request.body,
                               self.headers)


class LoginTests(unittest.TestCase):
    def test_default_adjuster_fails_before_network(self):
        transport = Transport()
        client = LoginClient(BAG, transport=transport)
        with self.assertRaises(NotImplementedError):
            client.authenticate(username="u", password="p")
        self.assertEqual(transport.calls, [])

    def test_successful_login_retains_adjusted_storefront(self):
        transport = Transport(plist_response(account_fields()))
        adjuster = Adjuster(headers={
            "X-Apple-Store-Front": "143441-1,29",
            "X-Apple-AMD": "proof",
        })
        result = LoginClient(BAG, transport=transport, adjuster=adjuster).authenticate(
            username="user@example.test", password="password", guid="guid")
        self.assertEqual(result.url, BAG["authenticateAccount"])
        self.assertTrue(result.created_account)
        self.assertFalse(result.requires_verification_code)
        self.assertEqual(result.account.dsid, 42)
        self.assertEqual(result.account.storefront, "143441-1,29")
        self.assertNotIn("password", repr(result.request))
        call = transport.calls[0]
        self.assertEqual(call["timeout"], 45.0)
        self.assertEqual(call["body"], result.request.body)
        self.assertEqual(call["headers"]["X-Apple-AMD"], "proof")
        self.assertIs(adjuster.requests[0], result.request)

    def test_adjuster_cannot_change_signed_body(self):
        transport = Transport(plist_response(account_fields()))
        adjuster = Adjuster(body=b"different")
        with self.assertRaises(ValueError):
            LoginClient(BAG, transport=transport, adjuster=adjuster).authenticate(
                username="u", password="p")
        self.assertEqual(transport.calls, [])

    def test_transport_must_return_http_result(self):
        transport = Transport(b"not-http-result")
        with self.assertRaises(TypeError):
            LoginClient(BAG, transport=transport, adjuster=Adjuster()).authenticate(
                username="u", password="p")

    def test_verification_code_is_appended_explicitly(self):
        transport = Transport(plist_response({"failureType": 5000}))
        adjuster = Adjuster()
        client = LoginClient(BAG, transport=transport, adjuster=adjuster)
        client.authenticate_with_verification_code(
            username="u", password="pw", code="123456")
        self.assertEqual(plistlib.loads(adjuster.requests[0].body)["password"], "pw123456")

    def test_challenge_requires_code_but_does_not_retry(self):
        transport = Transport(plist_response({
            "failureType": -5000, "errorCode": -22947}))
        client = LoginClient(BAG, transport=transport, adjuster=Adjuster())
        result = client.authenticate(username="u", password="p")
        self.assertTrue(result.requires_verification_code)
        self.assertFalse(result.created_account)
        self.assertEqual(len(transport.calls), 1)

    def test_http_failure_never_creates_account(self):
        transport = Transport(plist_response(account_fields(), status=500))
        result = LoginClient(BAG, transport=transport, adjuster=Adjuster()).authenticate(
            username="u", password="p")
        self.assertFalse(result.created_account)
        self.assertTrue(result.parsed.has_created_account)
        with self.assertRaises(ValueError):
            result.commit("/tmp/unused", guid="g", device_seed=b"s")

    def test_commit_refuses_non_created_login(self):
        transport = Transport(plist_response({"failureType": 5000}))
        result = LoginClient(BAG, transport=transport, adjuster=Adjuster()).authenticate(
            username="u", password="p")
        with tempfile.TemporaryDirectory() as directory:
            destination = Path(directory) / "session"
            with self.assertRaises(ValueError):
                result.commit(destination, guid="g", device_seed=b"seed")
            self.assertFalse(destination.exists())

    def test_commit_mismatched_account_is_rejected(self):
        transport = Transport(plist_response(account_fields()))
        result = LoginClient(BAG, transport=transport, adjuster=Adjuster()).authenticate(
            username="u", password="p")
        wrong = SessionAccount(43, "user@example.test", "server-token")
        with tempfile.TemporaryDirectory() as directory:
            destination = Path(directory) / "session"
            with self.assertRaises(ValueError):
                result.commit(destination, wrong, guid="g", device_seed=b"seed")
            self.assertFalse(destination.exists())

    def test_commit_publishes_a_readable_private_session(self):
        transport = Transport(plist_response(account_fields()))
        result = LoginClient(BAG, transport=transport, adjuster=Adjuster()).authenticate(
            username="u", password="p")
        cookie = SessionCookie("example.test", "session", "cookie-value",
                               expires=1700000000)
        with tempfile.TemporaryDirectory() as directory:
            destination = Path(directory) / "session"
            result.commit(destination, cookies=[cookie], guid="device-guid",
                          device_seed=b"seed")
            self.assertTrue(destination.is_dir())
            self.assertEqual((destination / "device.json").read_text(),
                             '{"guid": "device-guid"}')
            self.assertEqual((destination / "DEVICE_SEED").read_bytes(), b"seed")
            db = sqlite3.connect(destination / "mpl_db" / "accounts.sqlitedb")
            try:
                self.assertEqual(
                    db.execute("SELECT dsid, id, storeFront FROM account").fetchall(),
                    [(42, "user@example.test", "")],
                )
            finally:
                db.close()
            self.assertEqual((destination / "mpl_db").stat().st_mode & 0o777, 0o700)
            with self.assertRaises(FileExistsError):
                result.commit(destination, guid="g", device_seed=b"s")

    def test_protocol_actions_are_handled_before_persistence(self):
        class ActionTransport(Transport):
            def __init__(self, *responses):
                super().__init__(*responses)
                self.effects = []

            def handle_login_actions(self, url, fields, *, user_agent=""):
                self.effects.append((url, dict(fields), user_agent))
                from apple_music_source.auth import ActionEffects
                return ActionEffects(("cookies",), 1, 0, 0, 0)

        fields = account_fields()
        fields["cookies"] = {"c": {"value": "v"}}
        transport = ActionTransport(plist_response(fields))
        result = LoginClient(
            BAG, transport=transport,
            adjuster=Adjuster(headers={"User-Agent": "ua"}),
        ).authenticate(username="u", password="p")
        self.assertEqual(len(transport.effects), 1)
        self.assertEqual(transport.effects[0][2], "ua")
        # Only SUPPORTED_ACTIONS that the transport reports as handled clear.
        self.assertNotIn("cookies", result.parsed.actions.unhandled_actions)


class ParserTests(unittest.TestCase):
    def test_empty_body_is_empty_response(self):
        parsed = PlistResponseParser().parse(b"")
        self.assertIsNone(parsed.fields)
        self.assertFalse(parsed.has_created_account)
        self.assertIsNotNone(parsed.actions)

    def test_invalid_inputs_raise(self):
        parser = PlistResponseParser()
        with self.assertRaises(ValueError):
            parser.parse("not-bytes")
        with self.assertRaises(ValueError):
            parser.parse(b"not a plist")
        with self.assertRaises(ValueError):
            parser.parse(plistlib.dumps(["not", "a", "dict"]))

    def test_parses_account(self):
        parsed = PlistResponseParser().parse(plist_response(account_fields()).body)
        self.assertTrue(parsed.has_created_account)
        self.assertEqual(parsed.actions.account.dsid, 42)


class BagFileTests(unittest.TestCase):
    def test_load_bag_is_read_only(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "bag.plist"
            path.write_bytes(plistlib.dumps(BAG))
            self.assertEqual(load_bag(path), BAG)
            path.write_bytes(plistlib.dumps(["not", "a", "dict"]))
            with self.assertRaises(ValueError):
                load_bag(path)


if __name__ == "__main__":
    unittest.main()
