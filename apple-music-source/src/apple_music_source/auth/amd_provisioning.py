"""AMD-Action::SP handshake: drive /otp/1.5/finish to provision ADI.

The real Apple Music SDK does not provision ADI through Grand Slam. When a
freshly installed client calls ``/auth/v1/native`` without an X-Apple-AMD-M
header, the server returns ``x-apple-amd-action: SP`` together with an
``x-apple-amd-data`` server-provisioning-intermediate-metadata (SPIM) blob.
The client feeds that SPIM to its CoreADI's ``startProvisioning``, uploads
the resulting client-provisioning-intermediate-metadata (CPIM) to the
``amd-finish-provisioning`` endpoint, receives the persistence settingInfo
(PTM) and transportKey (TK), and finalises with ``endProvisioning``.

This module is the orchestrator's implementation of that handshake. It talks
directly to the CoreADI backend and to Apple over the verified transport; it
never persists secrets or logs credentials.
"""
from __future__ import annotations

import base64
import plistlib
from typing import Mapping, Optional, Protocol

from .adi_protocol import ProvisioningSession
from .login_client import HttpResult, Transport, resolve_bag_url

AMD_FINISH_BAG_KEY = 'amd-finish-provisioning'
AMD_ANONYMOUS_DS_ID = -1
_FINISH_TIMEOUT_SECONDS = 45.0


class ProvisioningBackend(Protocol):
    def start_provisioning(self, ds_id: int, spim: bytes) -> ProvisioningSession:
        ...

    def end_provisioning(self, session: int, ptm: bytes, tk: bytes) -> None:
        ...

    def destroy_session(self, session: int) -> None:
        ...


class AmdProvisioningError(RuntimeError):
    pass


def extract_amd_spim(headers) -> Optional[bytes]:
    """Return the decoded SPIM when the response carries AMD-Action::SP.

    Header lookup is case-insensitive because the live Apple edge returns
    them lowercased while plenty of middleware mangles the casing.
    """
    action = None
    data = None
    for name, value in headers:
        lowered = name.lower()
        if lowered == 'x-apple-amd-action':
            action = value.strip()
        elif lowered == 'x-apple-amd-data':
            data = value.strip()
    if action != 'SP' or not data:
        return None
    try:
        return base64.b64decode(data, validate=False)
    except Exception as error:
        raise AmdProvisioningError('invalid x-apple-amd-data base64') from error


def perform_amd_finish_provisioning(
    *,
    backend: ProvisioningBackend,
    transport: Transport,
    bag: Mapping,
    guid: str,
    user_agent: str,
    storefront: str,
    spim: bytes,
    language: str = 'en-US',
) -> None:
    """Run startProvisioning → POST /otp/1.5/finish → endProvisioning."""
    if not isinstance(spim, bytes) or not spim:
        raise AmdProvisioningError('spim must be non-empty bytes')
    url = resolve_bag_url(bag, AMD_FINISH_BAG_KEY)
    session = backend.start_provisioning(AMD_ANONYMOUS_DS_ID, spim)
    try:
        body = plistlib.dumps(
            {
                'clientData': base64.b64encode(session.cpim).decode('ascii'),
                'guid': guid,
            },
            fmt=plistlib.FMT_XML,
            sort_keys=False,
        )
        headers = {
            'User-Agent': user_agent,
            'Accept-Language': language,
            'Expect': '',
            'Content-Type': 'application/x-apple-plist',
        }
        if storefront:
            headers['X-Apple-Store-Front'] = storefront
        response = transport.post(url, body, headers, timeout=_FINISH_TIMEOUT_SECONDS)
        if not isinstance(response, HttpResult):
            raise AmdProvisioningError('transport must return HttpResult')
        if response.status != 200:
            raise AmdProvisioningError(
                f'amd-finish-provisioning returned HTTP {response.status}')
        try:
            document = plistlib.loads(response.body)
        except Exception as error:
            raise AmdProvisioningError('amd-finish-provisioning response is not a plist') from error
        if not isinstance(document, Mapping):
            raise AmdProvisioningError('amd-finish-provisioning response must be a dict')
        setting_info = document.get('settingInfo')
        transport_key = document.get('transportKey')
        if not isinstance(setting_info, str) or not isinstance(transport_key, str):
            raise AmdProvisioningError(
                'amd-finish-provisioning response missing settingInfo/transportKey')
        ptm = base64.b64decode(setting_info, validate=False)
        tk = base64.b64decode(transport_key, validate=False)
        if not ptm or not tk:
            raise AmdProvisioningError('amd-finish-provisioning returned empty PTM/TK')
        backend.end_provisioning(session.session, ptm, tk)
    except BaseException:
        try:
            backend.destroy_session(session.session)
        except Exception:
            pass
        raise
