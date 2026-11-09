"""Offline tests for recovered login plist/action/header protocol semantics."""
import base64
import hashlib
import plistlib
import unittest

import _support  # noqa: F401

from apple_music_source.auth import (
    AndroidGUIDFields,
    AUTHENTICATE_BAG_KEY,
    AuthenticateClassification,
    NativeGUIDProviderUnavailable,
    PreparedAuthenticate,
    append_verification_code,
    build_authenticate_body,
    classify_authenticate_response,
    cookie_header,
    decode_android_guid_fields,
    derive_android_guid_fields,
    device_id_from_descriptor,
    format_android_guid,
    format_device_id,
    parse_login_actions,
    parse_protocol_actions,
    resolve_bag_url,
)


class AuthenticateBodyTests(unittest.TestCase):
    def test_body_contains_recovered_string_fields(self):
        body = build_authenticate_body(
            username="user@example.test", password="not-a-real-password",
            guid="device-guid", attempt=2,
        )
        value = plistlib.loads(body)
        self.assertEqual(
            value,
            {
                "attempt": "2",
                "password": "not-a-real-password",
                "appleId": "user@example.test",
                "rmp": "0",
                "createSession": "true",
                "why": "signIn",
                "guid": "device-guid",
            },
        )
        self.assertIsInstance(body, bytes)

    def test_empty_username_and_password_are_omitted(self):
        value = plistlib.loads(build_authenticate_body(username="", password=""))
        self.assertNotIn("appleId", value)
        self.assertNotIn("password", value)
        self.assertNotIn("guid", value)

    def test_attempt_is_a_decimal_string(self):
        for attempt in (0, 1, -1, (1 << 31) - 1, -(1 << 31)):
            with self.subTest(attempt=attempt):
                self.assertEqual(
                    plistlib.loads(build_authenticate_body(
                        username="u", password="p", attempt=attempt))["attempt"],
                    str(attempt),
                )
        for bad in (True, 1 << 31, -(1 << 31) - 1, 1.5):
            with self.subTest(attempt=bad):
                with self.assertRaises(ValueError):
                    build_authenticate_body(username="u", password="p", attempt=bad)

    def test_nul_and_non_string_credentials_are_rejected(self):
        for kwargs in (
            {"username": "u\0", "password": "p"},
            {"username": "u", "password": "p\0"},
            {"username": "u", "password": "p", "guid": "g\0"},
            {"username": 1, "password": "p"},
        ):
            with self.subTest(**{k: repr(v) for k, v in kwargs.items()}):
                with self.assertRaises(ValueError):
                    build_authenticate_body(**kwargs)

    def test_prepared_body_is_immutable_and_hidden(self):
        prepared = PreparedAuthenticate.create(username="u", password="secret")
        self.assertNotIn("secret", repr(prepared))
        self.assertEqual(prepared.method, "POST")
        self.assertEqual(prepared.content_type, "application/x-apple-plist")
        with self.assertRaises(Exception):
            prepared.body = b"changed"

    def test_verification_code_append(self):
        self.assertEqual(append_verification_code("pw", "123456"), "pw123456")
        for bad in ("12345", "1234567", "12345a", "\u0661\u0662\u0663\u0664\u0665\u0666", ""):
            with self.subTest(code=bad):
                with self.assertRaises(ValueError):
                    append_verification_code("pw", bad)
        with self.assertRaises(ValueError):
            append_verification_code("p\0", "123456")


class ClassificationTests(unittest.TestCase):
    def test_created_account_is_response_type_six(self):
        classification = classify_authenticate_response(
            {}, has_created_account=True)
        self.assertEqual(classification.response_type, 6)
        self.assertEqual(classification.status_type, 6)

    def test_unknown_response_is_type_four(self):
        classification = classify_authenticate_response(None)
        self.assertEqual(classification, AuthenticateClassification(4, 0, None, None, ""))

    def test_recovered_failure_mappings(self):
        cases = (
            ({"failureType": -5000, "errorCode": -22947}, 1),
            ({"failureType": -5000, "errorCode": 1}, 0),
            ({"failureType": -128}, 5),
            ({"failureType": 9008}, 2),
            ({"failureType": 9009}, 3),
            ({"failureType": 5000}, 4),
        )
        for fields, expected in cases:
            with self.subTest(fields=fields):
                self.assertEqual(
                    classify_authenticate_response(fields).response_type, expected)

    def test_status_type_and_message(self):
        classification = classify_authenticate_response(
            {"status": "9009", "customerMessage": "text"})
        self.assertEqual((classification.status_type, classification.customer_message),
                         (3, "text"))
        self.assertEqual(
            classify_authenticate_response({"status": 0}).status_type, 6)

    def test_rejects_malformed_numeric_fields(self):
        for fields in (
            {"failureType": True},
            {"failureType": "12x"},
            {"failureType": 1.5},
            {"status": "-"},
            {"customerMessage": 5},
        ):
            with self.subTest(fields=fields):
                with self.assertRaises(ValueError):
                    classify_authenticate_response(fields)
        with self.assertRaises(ValueError):
            classify_authenticate_response([])


class LoginActionTests(unittest.TestCase):
    def _account(self, **overrides):
        fields = {
            "accountInfo": {
                "dsPersonId": 42,
                "appleId": "user@example.test",
                "creditDisplay": "None",
                "address": {"firstName": "Test", "lastName": "User"},
            },
            "xToken": "server-token",
        }
        fields.update(overrides)
        return fields

    def test_parses_verified_account_and_storefront(self):
        actions = parse_login_actions(
            self._account(), {"X-Set-Apple-Store-Front": "143441-1,29"})
        self.assertTrue(actions.has_created_account)
        self.assertTrue(actions.can_persist_account)
        account = actions.account
        self.assertEqual(
            (account.dsid, account.account_id, account.token, account.storefront),
            (42, "user@example.test", "server-token", "143441-1,29"),
        )
        self.assertEqual((account.first_name, account.last_name), ("Test", "User"))
        self.assertNotIn("server-token", repr(actions))
        self.assertNotIn("server-token", repr(account))

    def test_account_requires_dsid_and_name(self):
        for fields in (
            {"accountInfo": {"appleId": "u", "dsPersonId": 0}},
            {"accountInfo": {"dsPersonId": 1}},
            {"accountInfo": "invalid"},
            {},
        ):
            with self.subTest(fields=fields):
                self.assertIsNone(parse_login_actions(fields, ()).account)

    def test_signed_and_string_dsids(self):
        for value in (42, "42", "+42"):
            with self.subTest(value=value):
                fields = self._account()
                fields["accountInfo"]["dsPersonId"] = value
                self.assertEqual(parse_login_actions(fields).account.dsid, 42)
        for value in (True, "abc", 1.5, None):
            with self.subTest(value=value):
                fields = self._account()
                fields["accountInfo"]["dsPersonId"] = value
                if value is None:
                    self.assertIsNone(parse_login_actions(fields).account)
                else:
                    with self.assertRaises(ValueError):
                        parse_login_actions(fields)

    def test_nested_set_current_user_account(self):
        fields = {
            "set-current-user": {
                "accountInfo": {"dsPersonId": 7, "accountName": "nested"},
                "xToken": "nested-token",
            }
        }
        actions = parse_login_actions(fields)
        self.assertEqual(actions.account.dsid, 7)
        self.assertEqual(actions.account.account_id, "nested")
        self.assertEqual(actions.account.token, "nested-token")

    def test_credentials_ready_requires_token(self):
        fields = self._account()
        del fields["xToken"]
        actions = parse_login_actions(fields)
        self.assertTrue(actions.has_created_account)
        self.assertFalse(actions.account.credentials_ready)
        self.assertFalse(actions.can_persist_account)

    def test_goto_redirect_blocks_persistence(self):
        actions = parse_login_actions(
            self._account(action={"kind": "Goto", "url": "https://example.test/next"}))
        self.assertEqual(actions.redirect_url, "https://example.test/next")
        self.assertFalse(actions.can_persist_account)

    def test_reset_blocks_persistence(self):
        for kind in ("Reset", "SetUserAndReset"):
            with self.subTest(kind=kind):
                actions = parse_login_actions(self._account(action={"kind": kind}))
                self.assertTrue(actions.reset_requested)
                self.assertFalse(actions.can_persist_account)

    def test_unknown_actions_remain_visible(self):
        for fields in (
            {"action": {"kind": "unknown"}},
            {"action": {"kind": "Goto"}},
            {"action": "invalid"},
            {"dialog": {"kind": "other"}},
            {"dialog": "invalid"},
        ):
            with self.subTest(fields=fields):
                actions = parse_login_actions(fields)
                self.assertTrue(actions.unhandled_actions)
                self.assertFalse(actions.can_persist_account)

    def test_authorization_dialog_requests_authentication(self):
        actions = parse_login_actions({"dialog": {"kind": "authorization"}})
        self.assertTrue(actions.authenticate_requested)
        self.assertFalse(actions.can_persist_account)

    def test_failure_dialog_classifications(self):
        for failure in (1001, 1003, 1004, 2034):
            with self.subTest(failure=failure):
                actions = parse_login_actions({"failureType": failure})
                self.assertTrue(actions.authenticate_requested)
        for failure in (5002, 5105):
            with self.subTest(failure=failure):
                actions = parse_login_actions({"failureType": failure})
                self.assertIn("failure-dialog", actions.unhandled_actions)

    def test_unsupported_action_keys_are_listed(self):
        actions = parse_login_actions(self._account(cookies={}))
        self.assertIn("cookies", actions.unhandled_actions)
        self.assertFalse(actions.can_persist_account)

    def test_header_validation_and_embedded_headers(self):
        actions = parse_login_actions(
            self._account(headers={"Not-Present": "value"}),
            [("X-Set-Apple-Store-Front", "1,2")],
        )
        self.assertIn(("Not-Present", "value"), actions.effective_headers)
        with self.assertRaises(ValueError):
            parse_login_actions({}, [("bad\r\n", "value")])
        with self.assertRaises(ValueError):
            parse_login_actions({"headers": {"x": "bad\0"}})

    def test_storefront_trims_non_alphanumeric_ends(self):
        actions = parse_login_actions(
            self._account(), {"X-Set-Apple-Store-Front": " ,143441-1,29; "})
        self.assertEqual(actions.account.storefront, "143441-1,29")

    def test_none_fields_are_an_empty_action_set(self):
        actions = parse_login_actions(None)
        self.assertIsNone(actions.account)
        self.assertEqual(actions.classification.response_type, 4)


class ProtocolActionTests(unittest.TestCase):
    def test_cookie_header_formatting(self):
        header = cookie_header("session", {
            "value": "abc",
            "domain": ".apple.com",
            "path": "/",
            "isHTTPOnly": "1",
            "isSecure": "1",
            "expires": "1",
        })
        self.assertEqual(
            header,
            "session=abc; domain=.apple.com; path=/; HttpOnly; secure; expires=1",
        )

    def test_non_string_cookie_attributes_are_ignored(self):
        # The native helper filters non-CFString pairs rather than coercing them.
        self.assertEqual(
            cookie_header("n", {"value": "v", "isSecure": True, "max-age": 5}),
            "n=v",
        )

    def test_cookie_header_rejects_injection(self):
        for name, properties in (
            ("bad name", {"value": "v"}),
            ("n", {"value": "a;b"}),
            ("n", {"value": "a\r\nb"}),
            ("n", {"value": "v", "path": "a;b"}),
            ("n", "not-a-mapping"),
        ):
            with self.subTest(name=name, properties=properties):
                with self.assertRaises(ValueError):
                    cookie_header(name, properties)

    def test_parse_cookie_and_ping_actions(self):
        actions = parse_protocol_actions({
            "cookies": {"a": {"value": "1", "domain": ".apple.com"},
                        "b": {"value": "2"}},
            "ping": "https://example.test/one",
            "pings": ["https://example.test/two"],
            "duAnonymousPings": ["https://example.test/three"],
        })
        self.assertEqual(actions.handled, ("cookies", "ping", "pings", "duAnonymousPings"))
        self.assertEqual(len(actions.cookies), 2)
        self.assertEqual(actions.cookies[0].domain, ".apple.com")
        self.assertEqual(actions.pings, (
            "https://example.test/one",
            "https://example.test/two",
            "https://example.test/three",
        ))
        self.assertNotIn("1", repr(actions))

    def test_cookie_and_ping_bounds(self):
        self.assertEqual(parse_protocol_actions({"cookies": []}).handled, ("cookies",))
        with self.assertRaises(ValueError):
            parse_protocol_actions({"cookies": {str(i): {} for i in range(513)}})
        with self.assertRaises(ValueError):
            parse_protocol_actions({"cookies": "invalid"})
        with self.assertRaises(ValueError):
            parse_protocol_actions({"ping": 5})
        with self.assertRaises(ValueError):
            parse_protocol_actions({"pings": ["x"] * 33})
        with self.assertRaises(ValueError):
            parse_protocol_actions({"pings": ["x"] * 20, "duAnonymousPings": ["y"] * 20})


class DeviceIdentityTests(unittest.TestCase):
    def test_raw_field_provider_fails_closed(self):
        with self.assertRaises(NativeGUIDProviderUnavailable):
            derive_android_guid_fields(b"android", b"\x00" * 6)

    def test_guid_formatting(self):
        android = b"android-id"
        fields = AndroidGUIDFields(first=b"\x01\x02", second=b"\x03")
        guid = format_android_guid(android, fields, serial="SERIAL")
        parts = guid.split(".")
        self.assertEqual(parts[0], "0102")
        self.assertEqual(parts[1], "03")
        self.assertEqual(parts[2], "SERIAL")
        self.assertEqual(parts[3], hashlib.sha1(android).hexdigest()[-14:])
        self.assertEqual(parts[4:], ["0" * 14, "0" * 14])
        self.assertNotIn("\0", guid)

    def test_absent_fields_and_serial_use_zero_blocks(self):
        guid = format_android_guid(b"id", AndroidGUIDFields())
        parts = guid.split(".")
        self.assertEqual(parts[0], "0" * 36)
        self.assertEqual(parts[1], "0" * 14)
        self.assertEqual(parts[2], "0" * 14)

    def test_empty_but_present_fields_are_distinct_from_absent(self):
        guid = format_android_guid(b"id", AndroidGUIDFields(first=b"", second=b""))
        parts = guid.split(".")
        self.assertEqual(parts[0], "")
        self.assertEqual(parts[1], "")

    def test_invalid_guid_inputs(self):
        with self.assertRaises(ValueError):
            format_android_guid(b"", AndroidGUIDFields())
        with self.assertRaises(ValueError):
            format_android_guid("id", AndroidGUIDFields())
        with self.assertRaises(ValueError):
            format_android_guid(b"id", {"first": b""})
        with self.assertRaises(ValueError):
            format_android_guid(b"id", AndroidGUIDFields(), serial="bad\0")
        with self.assertRaises(ValueError):
            AndroidGUIDFields(first=b"x" * 24)

    def test_descriptor_decode_and_device_id(self):
        descriptor = bytearray(56)
        descriptor[0] = 1
        descriptor[1:3] = b"AB"
        descriptor[24:28] = (2).to_bytes(4, "little")
        descriptor[28] = 1
        descriptor[29:30] = b"C"
        descriptor[52:56] = (1).to_bytes(4, "little")
        fields = decode_android_guid_fields(bytes(descriptor))
        self.assertEqual((fields.first, fields.second), (b"AB", b"C"))
        self.assertEqual(decode_android_guid_fields(bytes(56)), AndroidGUIDFields())
        for bad in (b"", bytes(55), bytes(57)):
            with self.subTest(length=len(bad)):
                with self.assertRaises(ValueError):
                    decode_android_guid_fields(bad)
        raw = b"\x01" * 20
        self.assertEqual(format_device_id(raw), "01" * 20)
        self.assertEqual(
            device_id_from_descriptor((20).to_bytes(4, "little") + raw), raw)
        with self.assertRaises(ValueError):
            device_id_from_descriptor(b"\x00" * 23)
        with self.assertRaises(ValueError):
            device_id_from_descriptor((21).to_bytes(4, "little") + b"\x00" * 20)


class BagTests(unittest.TestCase):
    def test_resolves_top_level_and_dotted_keys(self):
        bag = {AUTHENTICATE_BAG_KEY: "https://example.test/auth",
               "nested": {"value": "https://example.test/nested"}}
        self.assertEqual(resolve_bag_url(bag), "https://example.test/auth")
        self.assertEqual(resolve_bag_url(bag, "nested.value"),
                         "https://example.test/nested")

    def test_rejects_missing_or_unsafe_urls(self):
        for bag, key in (
            ({}, AUTHENTICATE_BAG_KEY),
            ({AUTHENTICATE_BAG_KEY: ""}, AUTHENTICATE_BAG_KEY),
            ({AUTHENTICATE_BAG_KEY: "file:///etc/passwd"}, AUTHENTICATE_BAG_KEY),
            ({AUTHENTICATE_BAG_KEY: "https://user:pw@example.test/"}, AUTHENTICATE_BAG_KEY),
            ({AUTHENTICATE_BAG_KEY: "https://example.test/\0"}, AUTHENTICATE_BAG_KEY),
            ([], AUTHENTICATE_BAG_KEY),
        ):
            with self.subTest(bag=bag):
                with self.assertRaises((KeyError, ValueError)):
                    resolve_bag_url(bag, key)


if __name__ == "__main__":
    unittest.main()
