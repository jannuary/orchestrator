"""Recovered native authentication header construction.

The two providers must implement the real CoreADI and Mescal primitives. This
module performs only the observed wire encoding; it never invents proof bytes,
loads an SDK, or falls back to unsigned authentication.
"""
import base64
from typing import Protocol

from .login_client import AdjustedRequest


class MachineData(Protocol):
    def otp(self, account: int):
        """Return an object with binary mid and otp fields for the account."""
        ...


class BodySigner(Protocol):
    def sign(self, body: bytes) -> bytes:
        ...


def _encoded(data):
    if not isinstance(data, bytes) or not 0 < len(data) <= 65536:
        raise ValueError('cryptographic provider returned invalid output')
    return base64.b64encode(data).decode('ascii')


class NativeRequestAdjuster:
    def __init__(self, *, machine_data: MachineData, signer: BodySigner,
                 user_agent: str, storefront: str = '', language: str = 'en-US'):
        if not user_agent:
            raise ValueError('native user agent is required')
        for value in (user_agent, storefront, language):
            if not isinstance(value, str) or any(c in value for c in '\r\n\x00'):
                raise ValueError('invalid native header value')
        self.machine_data = machine_data
        self.signer = signer
        self.base = {'User-Agent': user_agent, 'Accept-Language': language, 'Expect': ''}
        if storefront:
            self.base['X-Apple-Store-Front'] = storefront

    def adjust(self, request):
        # New native authentication uses the anonymous AMD style. The reference
        # CoreADI account selector is UINT64_MAX, represented here as -1.
        headers = dict(self.base)
        headers['Content-Type'] = request.content_type
        try:
            proof = self.machine_data.otp(-1)
        except Exception:
            proof = None
        if proof is not None:
            headers['X-Apple-AMD-M'] = _encoded(proof.mid)
            headers['X-Apple-AMD'] = _encoded(proof.otp)
        # Sign the exact serialized bytes that will be sent, once.
        headers['X-Apple-ActionSignature'] = _encoded(self.signer.sign(request.body))
        return AdjustedRequest(request.body, headers)
