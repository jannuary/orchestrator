"""Recovered SAP setup exchange around an explicit cryptographic signer.

The caller owns signer lifetime and transport. This implements the handshake,
not Mescal signatures; nothing is sent until the caller invokes this function.
"""
import plistlib

from .login_client import resolve_bag_url
from .http_transport import apple_https_url

__all__ = ["establish_signer"]


def _field(response, name, stage):
    if response.status != 200:
        raise ValueError(f"SAP {stage} service failed")
    try:
        document = plistlib.loads(response.body)
    except Exception as error:
        raise ValueError(f"invalid SAP {stage} plist") from error
    value = document.get(name) if isinstance(document, dict) else None
    if not isinstance(value, bytes) or not value:
        raise ValueError(f"SAP {stage} data missing")
    return value


def establish_signer(signer, bag, transport, *, user_agent="Music/5.0.2 Android/10 model/Pixel 8 build/7663314 (dt:66)"):
    """Complete up to three server exchange rounds or raise without fallback.

    ``signer.exchange(bytes)`` returns ``(phase, bytes)``: 0 means complete;
    1 means send the returned buffer to the setup service. This function does
    not manufacture the exchange bytes or return a signer on failure.
    """
    if not isinstance(user_agent, str) or not user_agent or any(c in user_agent for c in "\r\n\0"):
        raise ValueError("invalid SAP user agent")
    cert_url = resolve_bag_url(bag, "sign-sap-setup-cert")
    apple_https_url(cert_url)
    headers = {"User-Agent": user_agent, "Content-Type": "application/x-apple-plist"}
    cert = _field(transport.get(cert_url, headers, timeout=45), "sign-sap-setup-cert", "certificate")
    phase, data = signer.exchange(cert)
    for _ in range(3):
        if type(phase) is int and phase == 0:
            return
        if type(phase) is not int or phase != 1 or not isinstance(data, bytes) or not data:
            raise ValueError("unsupported SAP exchange phase")
        url = resolve_bag_url(bag, "sign-sap-setup")
        apple_https_url(url)
        body = plistlib.dumps({"sign-sap-setup-buffer": data}, fmt=plistlib.FMT_XML)
        reply = _field(transport.post(url, body, headers, timeout=45), "sign-sap-setup-buffer", "exchange")
        phase, data = signer.exchange(reply)
    if type(phase) is not int or phase != 0:
        raise ValueError("SAP exchange did not finish")
