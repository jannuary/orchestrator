# apple-music-source

A standalone source package of audited crypto primitives and authentication
code. It includes generated vendor-derived data as C source for CoreADI and
Mescal, so anonymous login on an already-provisioned device is supported.
Fresh provisioning remains incomplete. The source-only SPC generator and FPS
request path are included. See the package-owned
[audit](src/apple_music_source/AUDIT.md) and
[provenance manifest](src/apple_music_source/closure_manifest.json).  It does **not** import, load, or fall back to the
`wrapper` checkout, a vendor SDK, an original `.so`, an ELF image, an emulator,
or a captured session.

Documented static protocol constants are part of the source implementation.
The internal CoreFP GUID cipher paths use standard AES-128 plus 112 bytes of
named keys, XOR masks and initial feedback. Two internal CoreLSKD AES/CBC
kernels use another 96 bytes of named keys and masks. These 208 static bytes
are documented protocol parameters, with no original lookup/image bank. The
two internal StoreServices GUID streams add 128 named static parameter
bytes, independently checked on further invented profiles. The six byte paths
therefore ship 336 documented parameter bytes in total. Account, session and content secrets are never embedded. These block
paths do not yet implement complete GUID derivation or a native auth provider.

The package models **138,744 initialization bytes** using source algorithms,
decoded source-control references, zero-global semantics and symbolic linking.
It also builds canonical generation-tag
allocation, bounded record/buffer/shared cleanup, and logical worker entry/wake
operations. These are checked against the original code using invented inputs.
They remain internal runtime components: full registry mutation/lifetimes,
synchronization, worker expiry, and valid CKC/session processing are unresolved.
Neither integrity bank has been removed.

## What is in the package

### Crypto (`apple_music_source.crypto`)

- **Portable AES-128/192/256 and AES-CBC** (`aes.py`).  The S-box is generated
  from GF(2^8) arithmetic at import time; no target-derived tables are present.
- **Caller-parameterized masked AES-128 CBC** (`MaskedCBC`). The initial chain
  is `iv XOR iv_mask`; returned ciphertext blocks are XORed with `output_mask`,
  while feedback uses the unmasked ciphertext. Encryption and decryption are
  unpadded and use no target-derived tables. An optional `plaintext_mask` XORs
  each plaintext block before encryption and after decryption; it defaults to
  zero. The generic API takes caller-supplied parameters. Internal
  `_corelskd_ciphers` supplies two verified static vendor variants; these byte
  transforms do not generate an SPC, process a CKC or acquire a content key.
- **CoreLSKD block transform, CBC chaining, and AES key extraction**
  (`corelskd.py`).  The package ships the source-level C translation in
  `_native/corelskd_r1.c` and `_native/corelskd_r1_generated.inc`, and the wheel
  build compiles it into `libcorelskd_r1.so`.  It executes no original machine
  code and needs the caller's existing `ctx`, `state`, `rax`, and `rcx` from a
  `/key` response.

The CoreLSKD include is generated C control flow translated from a pinned build
interval (documented in its header).  It is source, not an opaque table or an
image. The same package-owned library builds the bounded compatibility modules
below, plus internal `fill_dispatch.c`, `integrity_codec_data.c`, `control_refs.c`,
`abi_layout.c`, `registry.c`, `copy_codecs.c` and `auth_word_codecs.c` helpers for future session/auth integration. The data models initialize
ordinary memory; they are not mutable-memory fallbacks or public SPC-generation
APIs. Decoded control references identify source branch destinations and bases,
not opaque cryptographic or integrity lookup values. Symbolic ABI initializers
resolve source-owned bindings by name; they never call those bindings or load
an original ELF/SDK.

The internal copy helpers reconstruct two arithmetic byte stages from the
cipher functions, including bounded forward-copy transforms and their inverses.
They do not implement the surrounding cipher, packet validation or acquisition.

The auth word helpers reconstruct five register-only operand decoders used on
the native GUID path. They contain source arithmetic and bit operations, with
no lookup data or fitted cryptographic parameters. These helpers alone do not implement complete GUID/signing algorithms or
CoreADI proofs; the fixed GUID cipher paths above are separate primitives.

Additional native APIs in `apple_music_source.crypto`:

- `SPCV2`: strict parse/pack of the observed v2 envelope (no field derivation).
- `CryptoPrimitives.dispatch`: the persistent/context/finalize/decrypt argument
  vectors and operation tokens; `decode_dispatch_status` decodes responses.
- `CryptoPrimitives`: recovered comparison dispatch, address-bound argument
  decoding, field-copy bodies, encoded append, MT19937 twist/temper/word encoding.
- `initial_iv(ctx, state)`: decode a bijective initial CBC chain, so an extracted
  key can be used directly with independent AES.

These helpers are usable without captured state, except the explicitly named
CoreLSKD context/key/IV operations. Dispatcher packets do not process a CKC or
create a session. MT19937 is a compatibility primitive, never an entropy source.

### Authentication (`apple_music_source.auth`)

Source-complete pieces:

- login plist construction, explicit six-digit 2FA append, response
  classification;
- login action/account parsing, cookie formatting, guarded private session
  commit;
- native session header/cookie loading, FPS request construction, and fixed-host
  HTTPS posting that returns the FPS status and decoded CKC;
- SAP certificate/setup handshake (`establish_signer`) with exact exchange
  buffers, bounded rounds, and an explicit signer/transport;
- fast native account login with source CoreADI headers and an explicit device
  profile (`SourceFastLoginClient`);
- developer/Music-user token exchange orchestration and the API-token signing
  string;
- native authentication header assembly with caller-supplied `MachineData` and
  `BodySigner` providers;
- ADI provisioning protocol (`lookup`, `start`, `finish`, teardown) with an
  explicit `CoreADI` boundary;
- source Mescal derivation and formatting of Android GUID/DeviceID fields.

`derive_android_guid_mac_field(mac)` derives the complete seven-byte second
GUID field from six raw MAC bytes using SHA-1 and a documented 32-byte static
protocol suffix. Sixteen invented profiles match the native source oracle.
The suffix has an identified read-only source and a verified hash-message role;
it adds 32 parameter bytes to the six block paths' 336 bytes. The complete
native GUID fields are now available through the generated Mescal source data.

The first GUID field's input-record reconstruction now includes its native
80..200-byte size calculation and a 256-step cyclic byte mixer. Original
instructions validate 30,976 byte/residue size transitions and 3,328 mixer
updates. The Android-ID transform's initial ARX expansion reuses the existing
source arithmetic with its documented wire encoding. Both middle calculations
now have developer source models, and their complete first-field arithmetic
matches four native profiles. Six fixed state/lookup parameters remain explicit
and unresolved in that arithmetic model, including two unexplained 64-byte
lookup banks. The package's working GUID provider executes the generated
Mescal source data described below.

Internal GUID reconstruction also supplies the fixed CoreFP/StoreServices
block streams, a four-pass 328-byte input expansion, a 256-update cyclic mixer
on 20-byte states, and the native byte transform. The mixer matches pinned original instructions, including
unsigned wrap before modulo. `_guid_hash_tail` additionally reconstructs all
32 header updates, three folds and the final mixer from explicit working
states. The header has a universal bit-vector equivalence proof over all
scalar and initial-state bytes. These primitives do not supply the unresolved
fixed parameters or constitute a complete GUID provider on their own. The
complete provider is included as generated Mescal source data.

**Unresolved capabilities** (existing interfaces fail closed):

- fresh CoreADI device provisioning and account-bound OTP;
- online CKC context processing and FairPlay content-key acquisition remain
  experimental; the source session APIs do not claim that an online CKC yields
  a verified content key.

CoreADI anonymous machine data, Mescal SAP/request signing, Mescal GUID fields,
and fresh-account login are implemented from source. A live
`SourceLoginClient` run saved an account session, acquired both web tokens, and
verified AMP access for an already-provisioned device. `SourceFastLoginClient`
posts to Apple's fast native login route using source CoreADI data and an
explicit anisette device profile. `SourceLoginClient` uses the URL-bag/SAP
route. The generated vendor pages and integrity data ship as C source and
compile into package-owned shared libraries at wheel build time; no vendor
`.so` or ELF image is loaded. Both clients require a matching existing
`adi.pb` and `ANDROID_ID`; fresh provisioning remains unsupported.
The [audit](src/apple_music_source/AUDIT.md) documents the remaining FairPlay
crypto gaps and provenance.

## Install

Requirements:

- Python 3.10 or newer;
- a C compiler (`cc`) at wheel-build time;
- Linux x86_64, glibc (the only platform verified);
- no Python package dependencies and no network access.

```sh
# from this directory, or from a copied sdist
python3 -m pip install --no-index --no-build-isolation .
```

Build artifacts explicitly:

```sh
python3 - <<'PY'
import build_backend
print(build_backend.build_wheel('dist'))
print(build_backend.build_sdist('dist'))
PY
```

The wheel includes `libcorelskd_r1.so`, `libcoreadi_source.so`,
`libmescal_source.so`, and `libapple_music_fps_source.so`, all built from
package-owned C sources. It contains no
repo/build path and loads no original SDK library.
Editable installs are not supported.

## Use

```python
from apple_music_source.crypto import AES, aes_cbc_decrypt, aes_cbc_encrypt
from apple_music_source.crypto.corelskd import CoreLSKD

ciphertext = aes_cbc_encrypt(key, iv, b"plaintext")
assert aes_cbc_decrypt(key, iv, ciphertext, unpad=True) == b"plaintext"

# Caller already has a /key capture.  No key acquisition happens here.
core = CoreLSKD()                       # installed wheel library
content_key = core.extract_key(ctx, state, rax, rcx)
plain = core.cbc(ctx, state, rax, rcx, iv, ciphertext_blocks)
```

Protocol-only authentication remains available when an application supplies
its own transport and providers:

```python
from apple_music_source.auth import (
    LoginClient, NativeRequestAdjuster, UnimplementedAdjuster,
    build_fps_request, NativeSession,
)

client = LoginClient(bag, transport=my_transport)  # UnimplementedAdjuster
# raises before sending unless a real RequestAdjuster is supplied
```

Source-backed fast login uses a caller-selected anisette device profile:

```python
from pathlib import Path
from apple_music_source.auth import (
    DeviceIdentity,
    FastLoginProfile,
    HttpsTransport,
    SourceFastLoginClient,
)

profile = FastLoginProfile(
    device=DeviceIdentity(
        device_identifier=device_identifier,
        local_user_uuid=local_user_uuid,
    ),
    guid=device_guid,
)
login = SourceFastLoginClient(
    device_state=Path("device-state"),
    destination=Path("native-session"),
    profile=profile,
    transport=HttpsTransport(),
    sap_setup_bag=service_bag,
)
outcome = login.authenticate(username=username, password=password)
if outcome.verification_required:
    outcome = login.submit_verification_code(
        username=username,
        password=password,
        code=verification_code,
    )
```

`FastLoginProfile` requires an explicit `DeviceIdentity` and GUID. The device
state directory must contain matching `adi.pb` and `ANDROID_ID` files from an
already-provisioned device. `sap_setup_bag` supplies the SAP certificate and
exchange URLs and version for source Mescal signing. A session is saved only
after a verified account action. Fresh provisioning is not included. The older
bag/SAP flow remains available through `SourceLoginClient`.

The package can generate an FPS-format SPC and retain the matching source
session. Post the SPC with the existing fixed-host FPS transport:

```python
from apple_music_source.auth import HttpsTransport, build_fps_request, post_fps_request
from apple_music_source.crypto import SourceSession

with SourceSession(account, certificate, content, device_seed, format_version=key_format) as source:
    request = build_fps_request(metadata=metadata, spc=source.spc, headers=authenticated_headers)
    response = post_fps_request(request, transport=HttpsTransport())
    if not response.successful:
        raise RuntimeError("Apple did not return a usable FPS CKC")
    source_exchange_result = source.persistent_response(response.ckc)
```

The online CKC exchange result is exposed for investigation and is not
verified content-key material. Keep account headers private and use a matching
certificate, content identifier, device seed, and key format.

With a caller-owned signer and machine-data provider:

```python
adjuster = NativeRequestAdjuster(
    machine_data=my_coreadi_provider,   # .otp(-1) -> object with .mid/.otp
    signer=my_mescal_signer,            # .sign(bytes) -> bytes
    user_agent="...",
)
client = LoginClient(bag, transport=my_transport, adjuster=adjuster)
```

The package never logs credentials, tokens, cookies, MID/OTP values, or keys.
`commit_session` writes an explicitly requested private session directory and
refuses to replace an existing one.  The default transport is not created for
you; `HttpsTransport` is an optional, explicit network boundary and is never
used by the offline tests.

## Inputs the caller must supply

| Area | Required inputs |
| --- | --- |
| AES-CBC | key, IV, ciphertext |
| CoreLSKD transform | 0x8000-byte `ctx`, at least 0x2100-byte `state`, `rax`, `rcx` |
| Login | URL bag, username, password, optional 6-digit code, existing device state, transport |
| CoreADI OTP/MID | matching provisioned `adi.pb` and Android ID |
| Mescal signing | derived SAP device identifier and exact request bytes |
| GUID fields | Android ID and six-byte hardware MAC; optional serial |
| Token exchange | native session DSID/X-Token/GUID or caller auth, signer, machine data, transport |
| FPS request | SPC, `adamId`, `keyUri`, GUID, authenticated headers and an explicit TLS transport |
| FPS CKC processing | A matching source SPC session and CKC context backend; not included |
| Session commit | verified account/DSID/token, cookies, GUID, device seed; optionally `adi.pb` + Android ID |

No credentials, session databases, account/session/content keys, cookies, captured responses, or
private reports are embedded in this package or its tests.

## Verify offline

```sh
python3 -m unittest discover -s tests -v
```

The package tests use only invented values: NIST AES vectors, synthetic CoreLSKD
captures, synthetic plists, fake transports, and temporary directories.  They
make no network requests and do not read the wrapper checkout.

## Bounded protocol APIs

```python
from apple_music_source.crypto import SPCV2, CryptoPrimitives

# Caller supplies the already-derived fields; this only encodes the envelope.
envelope = SPCV2(bytes(16), bytes(256), bytes(20), bytes(16))
assert SPCV2.parse(envelope.pack()) == envelope

# Values are virtual integers, never host pointers. This does not call a backend.
packet = CryptoPrimitives().dispatch("decrypt", 1, 5, 2, 3, 64)
assert packet.token == 0xdf65877e
```

## Limits

- The login/token code implements the recovered protocol, not a complete
  account login.  It cannot sign a request without a real provider.
- online CKC context processing and content-key acquisition remain
  experimental and are not documented as verified.
- CoreLSKD needs an existing key context; it does not acquire one.
- `corelskd_r1_generated.inc` is source-reconstructed translation, not an
  independent cryptographic design review.
- Linux x86_64 is the only tested build target.  Other POSIX systems may compile
  the C, but are not claimed.
