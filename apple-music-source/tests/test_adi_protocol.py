"""Offline tests for the ADI provisioning protocol around an injectable backend."""
import base64
import plistlib
import unittest

import _support  # noqa: F401

from apple_music_source.auth import (
    AdiHttpResponse,
    AdiProvisioning,
    AKD_USER_AGENT,
    DeviceIdentity,
    LOOKUP_URL,
    NotProvisioned,
    OTP,
    ProvisioningError,
    ProvisioningSession,
    UnimplementedCoreADI,
    build_anisette_headers,
    check_status,
)

START_URL = "https://gsa.apple.com/grandslam/GsService2/midStartProvisioning"
FINISH_URL = "https://gsa.apple.com/grandslam/GsService2/midFinishProvisioning"


def _plist(values):
    return plistlib.dumps(values, fmt=plistlib.FMT_XML)


def _bag():
    return {
        "Status": {"ec": 0},
        "urls": {"midStartProvisioning": START_URL,
                 "midFinishProvisioning": FINISH_URL},
    }


def _start(spim=b"\x01spim"):
    return {"Status": {"ec": 0},
            "Response": {"spim": base64.b64encode(spim).decode("ascii")}}


def _finish(ptm=b"\x02ptm", tk=b"\x03tk", code=0):
    document = {"Status": {"ec": code}}
    if code == 0:
        document["Response"] = {
            "ptm": base64.b64encode(ptm).decode("ascii"),
            "tk": base64.b64encode(tk).decode("ascii"),
        }
    return document


def _device():
    return DeviceIdentity(device_identifier="device-0001",
                          local_user_uuid="uuid-0001",
                          serial_number="SERIAL01")


class Transport:
    def __init__(self, bag=None, start=None, finish=None):
        self.bag = _bag() if bag is None else bag
        self.start = _start() if start is None else start
        self.finish = _finish() if finish is None else finish
        self.calls = []

    def get(self, url, headers, *, timeout):
        self.calls.append({"method": "GET", "url": url,
                           "headers": dict(headers), "timeout": timeout})
        return AdiHttpResponse(200, _plist(self.bag))

    def post(self, url, body, headers, *, timeout):
        self.calls.append({"method": "POST", "url": url, "body": body,
                           "headers": dict(headers), "timeout": timeout})
        if url == START_URL:
            return AdiHttpResponse(200, _plist(self.start))
        if url == FINISH_URL:
            return AdiHttpResponse(200, _plist(self.finish))
        raise AssertionError("unexpected POST " + url)


class Backend:
    def __init__(self, provisioned=True):
        self.provisioned = provisioned
        self.calls = []

    def is_provisioned(self, ds_id):
        self.calls.append(("is_provisioned", ds_id))
        return self.provisioned

    def start_provisioning(self, ds_id, spim):
        self.calls.append(("start", ds_id, spim))
        return ProvisioningSession(b"cpim-bytes", 7)

    def end_provisioning(self, session, ptm, tk):
        self.calls.append(("end", session, ptm, tk))

    def destroy_session(self, session):
        self.calls.append(("destroy", session))

    def request_otp(self, ds_id):
        self.calls.append(("otp", ds_id))
        return OTP(b"\x01otp", b"\x02mid")

    def synchronize(self, ds_id, sim):
        self.calls.append(("sync", ds_id, sim))


class HeaderTests(unittest.TestCase):
    def test_builds_native_anisette_headers(self):
        headers = build_anisette_headers(OTP(b"otp", b"mid"), _device())
        self.assertEqual(base64.b64decode(headers["X-Apple-I-MD"]), b"otp")
        self.assertEqual(base64.b64decode(headers["X-Apple-I-MD-M"]), b"mid")
        self.assertEqual(headers["X-Apple-I-MD-RINFO"], "17106176")
        self.assertEqual(headers["X-Apple-I-MD-LU"], "uuid-0001")
        self.assertEqual(headers["X-Apple-I-SRL-NO"], "SERIAL01")
        self.assertEqual(headers["X-Mme-Device-Id"], "device-0001")

    def test_rejects_bad_routing_info_and_types(self):
        otp = OTP(b"otp", b"mid")
        for value in ("", "0x10", "1.0", "\u0661", 1, None):
            with self.subTest(value=value):
                with self.assertRaises(ValueError):
                    build_anisette_headers(otp, _device(), routing_info=value)
        with self.assertRaises(ValueError):
            build_anisette_headers("not-otp", _device())
        with self.assertRaises(ValueError):
            build_anisette_headers(otp, "not-device")

    def test_device_identity_rejects_control_characters(self):
        for name in ("device_identifier", "local_user_uuid", "serial_number"):
            with self.subTest(name=name):
                kwargs = {"device_identifier": "d", "local_user_uuid": "u",
                          "serial_number": "0"}
                kwargs[name] = "bad\r\n"
                with self.assertRaises(ValueError):
                    DeviceIdentity(**kwargs)

    def test_otp_repr_hides_secrets(self):
        otp = OTP(b"private-otp", b"private-mid")
        self.assertNotIn("private", repr(otp))


class StatusTests(unittest.TestCase):
    def test_accepts_integer_and_decimal_string(self):
        for code in (0, "0"):
            with self.subTest(code=code):
                self.assertEqual(
                    check_status({"Status": {"ec": code}, "Response": {"x": 1}}),
                    {"x": 1})
        self.assertEqual(check_status({"urls": {}}, require_response=False), {})

    def test_nonzero_status_raises_with_code_and_message(self):
        with self.assertRaises(ProvisioningError) as raised:
            check_status({"Status": {"ec": 434, "em": "message"}})
        self.assertEqual((raised.exception.code, raised.exception.message),
                         (434, "message"))
        self.assertNotIn("message", str(raised.exception))

    def test_rejects_malformed_documents(self):
        for document in ({}, {"Status": {"ec": "x"}}, {"Status": {"ec": True}},
                         {"Status": {"ec": 0}}, []):
            with self.subTest(document=document):
                with self.assertRaises(ValueError):
                    check_status(document)


class ProvisioningTests(unittest.TestCase):
    def test_happy_path_uses_lookup_start_finish_end(self):
        backend, transport = Backend(), Transport()
        AdiProvisioning(backend, transport, _device()).provision()
        self.assertEqual([call[0] for call in backend.calls],
                         ["start", "end"])
        self.assertEqual(backend.calls[0], ("start", -2, b"\x01spim"))
        self.assertEqual(backend.calls[1], ("end", 7, b"\x02ptm", b"\x03tk"))
        self.assertEqual([call["url"] for call in transport.calls],
                         [LOOKUP_URL, START_URL, FINISH_URL])

    def test_request_bodies_are_the_recovered_plists(self):
        transport = Transport()
        AdiProvisioning(Backend(), transport, _device()).provision()
        self.assertEqual(plistlib.loads(transport.calls[1]["body"]),
                         {"Header": {}, "Request": {}})
        self.assertEqual(plistlib.loads(transport.calls[2]["body"]), {
            "Header": {},
            "Request": {"cpim": base64.b64encode(b"cpim-bytes").decode()},
        })

    def test_headers_carry_device_identity_and_timestamp(self):
        transport = Transport()
        AdiProvisioning(Backend(), transport, _device(),
                        clock=lambda: 1700000000).lookup()
        headers = transport.calls[0]["headers"]
        self.assertEqual(headers["User-Agent"], AKD_USER_AGENT)
        self.assertEqual(headers["X-Mme-Device-Id"], "device-0001")
        self.assertNotIn("X-Apple-I-Client-Time", headers)
        transport.calls.clear()
        AdiProvisioning(Backend(), transport, _device(),
                        clock=lambda: 1700000000).provision()
        self.assertEqual(transport.calls[1]["headers"]["X-Apple-I-Client-Time"],
                         "2023-11-14T22:13:20Z")

    def test_finish_routing_information_overrides_the_default(self):
        finish = _finish()
        finish["Response"]["X-Apple-I-MD-RINFO"] = 12345
        backend = Backend()
        provisioning = AdiProvisioning(backend, Transport(finish=finish), _device())
        provisioning.provision()
        headers = provisioning.headers()
        self.assertEqual(headers["X-Apple-I-MD-RINFO"], "12345")

    def test_invalid_finish_routing_information_is_rejected(self):
        finish = _finish()
        finish["Response"]["X-Apple-I-MD-RINFO"] = "not-a-number"
        backend = Backend()
        with self.assertRaises(ValueError):
            AdiProvisioning(backend, Transport(finish=finish), _device()).provision()
        self.assertEqual(backend.calls[-1], ("destroy", 7))

    def test_lookup_accepts_a_bag_without_status(self):
        transport = Transport(bag=_bag())
        del transport.bag["Status"]
        self.assertEqual(AdiProvisioning(Backend(), transport, _device()).lookup(),
                         {"start": START_URL, "finish": FINISH_URL})

    def test_lookup_failure_never_touches_backend(self):
        backend = Backend()
        transport = Transport(bag={"Status": {"ec": 433}})
        with self.assertRaises(ProvisioningError):
            AdiProvisioning(backend, transport, _device()).provision()
        self.assertEqual(backend.calls, [])
        self.assertEqual(len(transport.calls), 1)

    def test_bag_without_provisioning_urls_is_rejected(self):
        transport = Transport(bag={"Status": {"ec": 0}, "urls": {}})
        with self.assertRaises(ValueError):
            AdiProvisioning(Backend(), transport, _device()).lookup()

    def test_bag_rejects_relative_and_credentialed_urls(self):
        for bad in ("not-a-url", "https://user:pw@gsa.apple.com/x", "/relative"):
            with self.subTest(url=bad):
                transport = Transport(bag={
                    "Status": {"ec": 0},
                    "urls": {"midStartProvisioning": bad,
                             "midFinishProvisioning": FINISH_URL},
                })
                with self.assertRaises(ValueError):
                    AdiProvisioning(Backend(), transport, _device()).lookup()

    def test_finish_failure_destroys_the_session(self):
        backend = Backend()
        with self.assertRaises(ProvisioningError):
            AdiProvisioning(backend, Transport(finish=_finish(code=434)),
                            _device()).provision()
        self.assertEqual([call[0] for call in backend.calls], ["start", "destroy"])

    def test_transport_error_destroys_the_session(self):
        class Failing(Transport):
            def post(self, url, body, headers, *, timeout):
                if url == FINISH_URL:
                    raise OSError("offline")
                return super().post(url, body, headers, timeout=timeout)

        backend = Backend()
        with self.assertRaises(OSError):
            AdiProvisioning(backend, Failing(), _device()).provision()
        self.assertEqual([call[0] for call in backend.calls], ["start", "destroy"])

    def test_start_failure_does_not_attempt_teardown(self):
        backend = Backend()
        with self.assertRaises(ProvisioningError):
            AdiProvisioning(backend, Transport(start={"Status": {"ec": 433}}),
                            _device()).provision()
        self.assertEqual(backend.calls, [])

    def test_malformed_spim_is_rejected_before_start(self):
        backend = Backend()
        with self.assertRaises(ValueError):
            AdiProvisioning(
                backend,
                Transport(start={"Status": {"ec": 0},
                                 "Response": {"spim": "not base64!"}}),
                _device(),
            ).provision()
        self.assertEqual(backend.calls, [])

    def test_malformed_ptm_is_rejected_and_session_destroyed(self):
        finish = _finish()
        finish["Response"]["ptm"] = "not base64!"
        backend = Backend()
        with self.assertRaises(ValueError):
            AdiProvisioning(backend, Transport(finish=finish), _device()).provision()
        self.assertEqual([call[0] for call in backend.calls], ["start", "destroy"])

    def test_lookup_is_cached_for_provision(self):
        backend, transport = Backend(), Transport()
        provisioning = AdiProvisioning(backend, transport, _device())
        provisioning.lookup()
        provisioning.provision()
        self.assertEqual(
            len([call for call in transport.calls if call["url"] == LOOKUP_URL]), 1)

    def test_rejects_invalid_configuration(self):
        for kwargs in ({"ds_id": True}, {"ds_id": "1"}, {"timeout": 0},
                       {"timeout": -1}):
            with self.subTest(kwargs=kwargs):
                with self.assertRaises(ValueError):
                    AdiProvisioning(Backend(), Transport(), _device(), **kwargs)


class MachineDataTests(unittest.TestCase):
    def test_headers_require_a_provisioned_backend(self):
        backend = Backend(provisioned=False)
        provisioning = AdiProvisioning(backend, Transport(), _device())
        with self.assertRaises(NotProvisioned):
            provisioning.headers()
        self.assertEqual(backend.calls, [("is_provisioned", -2)])

    def test_headers_request_a_fresh_otp(self):
        backend = Backend()
        headers = AdiProvisioning(backend, Transport(), _device()).headers()
        self.assertEqual(backend.calls, [("is_provisioned", -2), ("otp", -2)])
        self.assertEqual(base64.b64decode(headers["X-Apple-I-MD"]), b"\x01otp")

    def test_synchronize_requires_bytes(self):
        backend = Backend()
        provisioning = AdiProvisioning(backend, Transport(), _device())
        for bad in ("", None, "sim"):
            with self.subTest(sim=bad):
                with self.assertRaises(ValueError):
                    provisioning.synchronize(bad)
        provisioning.synchronize(b"sim")
        self.assertEqual(backend.calls, [("sync", -2, b"sim")])


class BoundaryTests(unittest.TestCase):
    def test_unimplemented_backend_raises_for_every_operation(self):
        backend = UnimplementedCoreADI()
        calls = (
            lambda: backend.is_provisioned(-2),
            lambda: backend.start_provisioning(-2, b"spim"),
            lambda: backend.end_provisioning(1, b"ptm", b"tk"),
            lambda: backend.destroy_session(1),
            lambda: backend.request_otp(-2),
            lambda: backend.synchronize(-2, b"sim"),
        )
        for call in calls:
            with self.assertRaises(NotImplementedError):
                call()

    def test_default_boundary_never_returns_fake_machine_data(self):
        provisioning = AdiProvisioning(UnimplementedCoreADI(), Transport(), _device())
        with self.assertRaises(NotImplementedError):
            provisioning.provision()
        with self.assertRaises(NotImplementedError):
            provisioning.headers()

    def test_http_response_validation(self):
        self.assertEqual(AdiHttpResponse(200, b"").status, 200)
        for status, body in ((True, b""), ("200", b""), (200, "body")):
            with self.subTest(status=status, body=body):
                with self.assertRaises(ValueError):
                    AdiHttpResponse(status, body)


if __name__ == "__main__":
    unittest.main()
