"""Source Apple Music crypto and authentication package.

This distribution contains no vendor shared library, executable image, or
captured session/key material. It includes generated vendor-derived data as C
source for CoreADI and Mescal. It also contains:

* an independent AES implementation and the source-reconstructed CoreLSKD
  block/CBC/key-extraction transform (package-owned C, built at wheel time);
* the recovered login/token/provisioning protocol and session formatting code,
  with explicit fail-closed boundaries for CoreADI and Mescal signing.

See :mod:`apple_music_source.crypto` and :mod:`apple_music_source.auth`, and the
package README for the exact capability and input matrix.
"""

from . import auth, crypto
from .auth import *  # noqa: F401,F403
from .crypto import *  # noqa: F401,F403

__version__ = "0.1.0"

__all__ = [
    "__version__",
    "CAPABILITIES",
    "auth",
    "crypto",
] + auth.__all__ + crypto.__all__

CAPABILITIES = {
    "aes_cbc": "source-complete (portable Python AES-128/192/256)",
    "corelskd_block_cbc": "source-reconstructed C; requires caller key context",
    "corelskd_key_extract": "source-reconstructed C; requires caller key context",
    "login_protocol": "source-complete; caller supplies credentials and existing device provisioning",
    "source_login": "source-reconstructed CoreADI/Mescal; anonymous login with existing adi.pb; fresh provisioning wired through source CoreADI (end/destroy entries unverified against a live GSA exchange)",
    "source_fast_login": "source CoreADI Anisette headers; caller supplies device identity and GUID; account success unverified",
    "login_actions": "source-complete parser; side effects are caller-owned",
    "session_store": "source-complete; writes only a verified server session",
    "native_session_headers": "source-complete; reads an existing native session",
    "http_transport": "included; explicit opt-in, TLS verification, no redirects",
    "token_exchange": "source-complete orchestration; caller supplies signer/AMD",
    "adi_provisioning_protocol": "source-complete; caller supplies CoreADI",
    "guid_deviceid_formatting": "source-reconstructed; Mescal derives fields from Android ID and MAC",
    "fps_request_building": "source-complete; caller supplies SPC and auth headers",
    "fps_response_transport": "source-complete; fixed Apple catalog endpoint; caller supplies SPC, auth headers and TLS transport",
    "coreadi_otp": "source-reconstructed; anonymous machine data from existing adi.pb",
    "mescal_signing": "source-reconstructed; generated vendor-derived data included",
    "mescal_guid_fields": "source-reconstructed; generated vendor-derived data included",
    "spc_v2_envelope": "native source; strict framing only, no cryptographic generation",
    "ckc_dispatch_packets": "native source; persistent/context/finalize/decrypt argument encoding",
    "keygen_primitives": "native source; MT19937, comparison dispatch, field copy, encoded append",
    "initial_iv_decode": "source; requires caller context and bijective chain encoding",
    "sap_setup_protocol": "source-complete handshake; caller supplies signer and transport",
    "spc_generation": "not included (mapped ELF-derived data and integrity substitutions; see AUDIT.md)",
    "ckc_key_acquisition": "FPS response transport included; source SPC generation and CKC processing not included",
}
