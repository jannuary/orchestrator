"""Source-recovered Apple Music authentication protocol and helpers.

Included and source-complete:

* login plist construction, explicit 2FA appending, response classification;
* login action/account parsing, cookie formatting, guarded session storage;
* native-session reading, FPS request construction and fixed-host HTTPS posting;
* developer/Music-user token exchange orchestration and API-token signing string;
* native authentication header assembly with caller-supplied crypto providers;
* source CoreADI anonymous machine-data generation from existing provisioning;
* source Mescal SAP signing and Android GUID field generation;
* source login orchestration with explicit 2FA and private session saving;
* ADI provisioning protocol and its explicit fresh-provisioning boundary;
* Android GUID/DeviceID formatting.

Deliberately not included (fail-closed interfaces are provided):

* fresh CoreADI device provisioning and account-bound OTP.

The source providers include the generated vendor-derived data needed for
already-provisioned anonymous login. They compile from package source when the
wheel is built and load no original SDK library.
"""

from .adi_protocol import (
    CLIENT_INFO,
    LOOKUP_URL,
    ROUTING_INFO,
    AKD_USER_AGENT,
    AdiProvisioning,
    CoreADI,
    DeviceIdentity,
    HttpResponse as AdiHttpResponse,
    NotProvisioned,
    OTP,
    ProvisioningError,
    ProvisioningSession,
    SynchronizationResult,
    Transport as AdiTransport,
    UnimplementedCoreADI,
    build_anisette_headers,
    check_status,
)
from .device_identity import (
    AndroidGUIDFields,
    NativeGUIDProviderUnavailable,
    decode_android_guid_fields,
    derive_android_guid_fields,
    derive_android_guid_mac_field,
    device_id_from_descriptor,
    format_android_guid,
    format_device_id,
    local_android_guid,
    local_hardware_mac,
)
from .fps import FpsRequest, FpsRequestError, FpsResponse, build_fps_request, post_fps_request
from .sap import establish_signer
from .http_transport import HttpsTransport, apple_https_url
from .login_actions import CreatedAccount, LoginActions, parse_login_actions
from .login_client import (
    AdjustedRequest,
    HttpResult,
    LoginClient,
    LoginResult,
    ParsedResponse,
    PlistResponseParser,
    RequestAdjuster,
    ResponseParser,
    Transport,
    UnimplementedAdjuster,
    load_bag,
    resolve_bag_url,
)
from .login_protocol import (
    AUTHENTICATE_BAG_KEY,
    AuthenticateClassification,
    PreparedAuthenticate,
    append_verification_code,
    build_authenticate_body,
    classify_authenticate_response,
)
from .native_adjuster import BodySigner, MachineData, NativeRequestAdjuster
from .coreadi_source import SourceCoreADI
from .omnisette_source import (
    OMNISETTE_URL_ENV,
    SIDESTORE_DIRECTORY_URL,
    OmnisetteCoreADI,
    OmnisetteUnavailable,
    fetch_sidestore_servers,
)
from .provision_source import ProvisionCoreADI, ProvisionError
from .mescal_source import SourceMescal, SourceMescalError
from .source_login import SourceLoginClient, SourceLoginOutcome
from .fast_login import FastLoginProfile, SourceFastLoginClient
from .native_session import APPLE_EPOCH, NativeSession
from .protocol_actions import (
    ActionEffects,
    CookieAction,
    ProtocolActions,
    cookie_header,
    parse_protocol_actions,
)
from .session_store import SessionAccount, SessionCookie, commit_session
from .token_client import (
    TokenClient,
    TokenServiceError,
    WebTokens,
    api_token_signing_bytes,
    verify_amp_tokens,
)

__all__ = [
    "establish_signer",
    "AKD_USER_AGENT",
    "APPLE_EPOCH",
    "AUTHENTICATE_BAG_KEY",
    "ActionEffects",
    "AdiHttpResponse",
    "AdiProvisioning",
    "AdiTransport",
    "AdjustedRequest",
    "AndroidGUIDFields",
    "AuthenticateClassification",
    "BodySigner",
    "CLIENT_INFO",
    "CookieAction",
    "CoreADI",
    "CreatedAccount",
    "DeviceIdentity",
    "FpsRequest",
    "FpsRequestError",
    "FpsResponse",
    "FastLoginProfile",
    "HttpResult",
    "HttpsTransport",
    "LOOKUP_URL",
    "LoginActions",
    "LoginClient",
    "LoginResult",
    "MachineData",
    "NativeGUIDProviderUnavailable",
    "NativeRequestAdjuster",
    "NativeSession",
    "NotProvisioned",
    "OTP",
    "ParsedResponse",
    "PlistResponseParser",
    "PreparedAuthenticate",
    "ProtocolActions",
    "ProvisioningError",
    "ProvisioningSession",
    "SynchronizationResult",
    "RequestAdjuster",
    "ResponseParser",
    "ROUTING_INFO",
    "SessionAccount",
    "SessionCookie",
    "OMNISETTE_URL_ENV",
    "OmnisetteCoreADI",
    "OmnisetteUnavailable",
    "SIDESTORE_DIRECTORY_URL",
    "fetch_sidestore_servers",
    "ProvisionCoreADI",
    "ProvisionError",
    "SourceCoreADI",
    "SourceFastLoginClient",
    "SourceLoginClient",
    "SourceLoginOutcome",
    "SourceMescal",
    "SourceMescalError",
    "TokenClient",
    "TokenServiceError",
    "Transport",
    "UnimplementedAdjuster",
    "UnimplementedCoreADI",
    "WebTokens",
    "api_token_signing_bytes",
    "append_verification_code",
    "apple_https_url",
    "build_anisette_headers",
    "build_authenticate_body",
    "build_fps_request",
    "check_status",
    "classify_authenticate_response",
    "commit_session",
    "cookie_header",
    "decode_android_guid_fields",
    "derive_android_guid_fields",
    "device_id_from_descriptor",
    "format_android_guid",
    "format_device_id",
    "load_bag",
    "local_android_guid",
    "local_hardware_mac",
    "parse_login_actions",
    "parse_protocol_actions",
    "post_fps_request",
    "resolve_bag_url",
    "verify_amp_tokens",
]
