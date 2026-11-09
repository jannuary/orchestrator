import plistlib
from types import SimpleNamespace
import unittest

import _support
from apple_music_source.auth import establish_signer

BAG = {"sign-sap-setup-cert": "https://s.mzstatic.com/cert",
       "sign-sap-setup": "https://fpinit.itunes.apple.com/setup"}


class Transport:
    def __init__(self, replies):
        self.replies = iter(replies)
        self.calls = []

    def get(self, url, headers, timeout):
        self.calls.append(("GET", url, None))
        return next(self.replies)

    def post(self, url, body, headers, timeout):
        self.calls.append(("POST", url, plistlib.loads(body)))
        return next(self.replies)


def reply(name, value):
    return SimpleNamespace(status=200, body=plistlib.dumps({name: value}))


class SapTests(unittest.TestCase):
    def test_exchange_exact_buffers_and_completion(self):
        received = []
        class Signer:
            def exchange(self, data):
                received.append(data)
                return (1, b"client") if data == b"cert" else (0, b"")
        t = Transport([reply("sign-sap-setup-cert", b"cert"), reply("sign-sap-setup-buffer", b"server")])
        establish_signer(Signer(), BAG, t)
        self.assertEqual(received, [b"cert", b"server"])
        self.assertEqual(t.calls[1][2], {"sign-sap-setup-buffer": b"client"})

    def test_bad_cert_never_calls_crypto(self):
        for response in (SimpleNamespace(status=503, body=b"error"),
                         SimpleNamespace(status=200, body=b"malformed"),
                         SimpleNamespace(status=200, body=plistlib.dumps([])),
                         reply("sign-sap-setup-cert", "not bytes")):
            class Signer:
                def exchange(self, data):
                    raise AssertionError("invalid cert must stop")
            with self.assertRaises(ValueError):
                establish_signer(Signer(), BAG, Transport([response]))

    def test_bounded_rounds_and_unsupported_phase(self):
        for phase, data in ((2, b"x"), (True, b"x"), (1, b""), (1, "x"), (1, b"x")):
            class Signer:
                def exchange(self, _): return phase, data
            t = Transport([reply("sign-sap-setup-cert", b"cert")] + [reply("sign-sap-setup-buffer", b"server")] * 3)
            with self.assertRaises(ValueError):
                establish_signer(Signer(), BAG, t)
            self.assertLessEqual(len(t.calls), 4)

    def test_rejects_bad_destination_and_headers_before_transport(self):
        for bag, agent in ((dict(BAG, **{"sign-sap-setup-cert": "https://example.org/cert"}), "a"), (BAG, "a\r\nb")):
            t = Transport([])
            with self.assertRaises(ValueError):
                establish_signer(None, bag, t, user_agent=agent)
            self.assertEqual(t.calls, [])
