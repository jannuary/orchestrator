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
        self.base = {'User-Agent': user_agent, 'Accept-Language': language}
        if storefront:
            self.base['X-Apple-Store-Front'] = storefront

    def adjust(self, request):
        # New native authentication uses the anonymous AMD style. The reference
        # CoreADI account selector is UINT64_MAX, represented here as -1.
        proof = self.machine_data.otp(-1)
        encoded_mid = _encoded(proof.mid)
        encoded_otp = _encoded(proof.otp)
        # Sign the exact serialized bytes that will be sent, once.
        signature = _encoded(self.signer.sign(request.body))
        headers = dict(self.base)
        headers.update({'Content-Type': request.content_type,
                        'X-Apple-AMD-M': encoded_mid,
                        'X-Apple-AMD': encoded_otp,
                        'X-Apple-ActionSignature': signature})
        return AdjustedRequest(request.body, headers)
