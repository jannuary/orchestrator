# Standalone source closure audit — updated 2026-11-06

## Current package status (2026-11-06)

The package includes vendor-derived CoreADI and Mescal source under
`_native/auth/`. The wheel backend compiles these files into
`libcoreadi_source.so` and `libmescal_source.so`; runtime does not load the
original SDK libraries. `SourceLoginClient` uses these providers for anonymous
machine data, SAP signing, GUID derivation, account login, optional 2FA retry,
and private session storage. It requires matching existing `adi.pb` and
`ANDROID_ID`; fresh provisioning and account-bound OTP remain unavailable.

A package-level live login completed on 2026-11-06 using the existing
provisioned device state. `SourceLoginClient` saved the account session, acquired
the developer and Music tokens, and verified the Music storefront through AMP
with HTTP 200. The transport required certificate and hostname verification.
This confirms the source login path for an already-provisioned device; it does
not verify fresh provisioning or a different device profile.

The run exposed and fixed a CoreADI adapter field-order bug. The C interface
returns a 60-byte MID and 24-byte OTP, while the Python `OTP` dataclass declares
its fields in the opposite constructor order. The adapter now constructs it by
field name. The native login headers then matched the SDK mapping: the 24-byte
OTP is `X-Apple-AMD` and the 60-byte MID is `X-Apple-AMD-M`.

The package also includes `SourceFastLoginClient` for Apple's fast native login
route, using source CoreADI headers, Mescal SAP setup/signing, and an explicit
device profile. The client retries up to three times with identical request
bytes when Apple's edge returns a transient empty response. The fast route has
returned HTTP 204 with empty bodies in earlier runs. The standard native route
now completes the package-level source login described above.

The package CoreLSKD C sources were compiled separately and run against the
existing WCT3 capture `rootfs/data/captures/capture_0.bin`. The source output
matched all 64 captured SDK reference bytes. The extracted 16-byte AES key,
decoded IV, and package AES-CBC implementation independently reproduced the
same output. The source-built shared library depends only on libc. This verifies
blob-free key extraction and decryption from an existing `/key` capture, not
SPC or CKC acquisition.

The package now also carries the standalone source-only FairPlay generator
under `_native/keygen_experimental/`. `crypto.fps.SourceSession` builds an
FPS-format SPC and retains its matching source session for CKC operations; the
existing `auth.fps` API posts the SPC to Apple's fixed HTTPS FPS endpoint.
`build_backend.py` compiles the copied sources and generated C data into
`libapple_music_fps_source.so`. The closure manifest records 321 copied
source files (about 785 MB). Compilation and import use package-owned files;
they do not load an SDK or executable image. Online CKC processing and content
key recovery remain experimental and unverified.

`AdiProvisioning.provision()` now checks for a provisioning-capable CoreADI
backend before performing URL lookup or starting a remote session. Passing
`UnimplementedCoreADI` or the OTP-only `SourceCoreADI` fails locally, avoiding
an orphaned server session. This protects the current boundary; it does not
implement fresh-device SPIM/CPIM/PTM/TK processing.

CoreADI source output is a 60-byte MID and 24-byte OTP; the request adapter uses
the SDK's observed AMD header mapping. SAP setup and Mescal signing complete
from the package source providers. Earlier source requests with the reversed
CoreADI dataclass fields were rejected with `AMD-Action::RP`; after correcting
the field order, package-level login and token acquisition succeeded. SPC
generation is now included in the package; successful online CKC processing and
FairPlay content-key recovery remain unverified.

## Active continuation: initializer origins and instruction-level round arithmetic

Historical notes below describe the state at their dated checkpoints. Current
source status is summarized above. Full standalone crypto/auth remains
incomplete. This continuation adds bounded
native word-operand decoders, caller-parameterized plaintext whitening in CBC,
and developer reconstruction tools. It now supplies the fixed parameters for
the two documented GUID block paths, but does not yet provide complete GUID
derivation, Mescal signing or CoreADI authentication. Other native cipher
parameter initializers also remain unfinished.

### CoreADI cipher path located; byte-boundary closure remains open (2026-11-03)

The direct-reference inventory for the six unresolved first-GUID parameter
inputs finds 11 physical regions totaling 368 bytes. All are in read-only,
non-relocated storage. Across 6,197 RIP-relative instruction starts in the
48 existing CoreFP translation pages, their direct references are loads or
address materializations in the two recovered selectors. This bounded scan
finds no generator; it does not rule out indirect or untranslated references.
No parameter bytes were exported (`research/guid-parameter-origins.json`).

The independent CoreADI investigation now distinguishes a source-oracle
coverage stop from native rejection. Three invented provisioning buffers of
32/256/1024 bytes stop the existing source oracle at `0x10086e27`, with no
MID/OTP. The original code initializes successfully and rejects invented
state with `-45061`; no successful provisioning/OTP claim follows. Original
and translated oracles use no host provisioning state or network
(`research/coreadi-live-substitution-reads.json`,
`research/coreadi-invented-reference-init.json`).

Five statically classified inversion-family word regions are read during
every observed public operation, including initialization. Runtime write/read
tracing identifies eight 1,024-byte word arrays. The previously missed array
is written at CoreADI `0x976c1` (256 writes), and first read at `0x99876`.
The later read at `0x99fe0` has a universally proved address bound within that
array. All contents remain RAM-only. The eight arrays have rank-eight
inversion differential structure and a coherent shared encoding for AES
inverse MixColumns and inverse S-box substitutions
(`research/coreadi-runtime-table-algebra.json`). This identifies algebraic
structure, not the complete cipher or admissible parameter origins.

Tracing starts at the true first lookup, `0x99876`, and reaches all 16 final
lookups after 208 total word reads and 4,255 instructions. There are no
unmodeled reads on that observed block; 45 simple byte projections have
UNSAT proofs (`research/coreadi-complete-round-dataflow.json`). A four-layer
nearest-dependency-frontier hypothesis yields one AES-128 inverse schedule
candidate within four encoding models, with two later round keys matching
independently. The frontier removes older edges as a hypothesis; those edges
are not silently promoted to a source equivalence proof.

The stronger prefix checker has proved 34 projections (22 direct and 12 AIG
UNSAT), leaving 12 unresolved within its solver limits. The checker retains
the original expressions for every unresolved case. A subsequent optional
bit-split checker admits a rewrite only if all eight output-bit differences
are UNSAT; invented rare-branch controls confirm rejection of an alteration
that the sample filters miss (`research/20261103-split-projection-controls.json`).

The native block produces 16 contiguous output bytes at the identified store
sites, but that output does not equal the unwhitened AES result of the
candidate (`research/coreadi-prefix-native-block-output.json`). Output
encoding/masks, input-byte boundaries, the full key schedule and parameter
stability remain to be established. No CoreADI key, fitted map, runtime word
array or cipher provider is shipped from this investigation. Fresh
provisioning, OTP/MID and the full standalone crypto/auth objective remain
incomplete. All current changes remain offline and uncommitted.

### Complete first-field arithmetic; fixed parameters still unresolved (2026-11-02)

Both straight-line middle spans now have parametric Python reconstructions:
`0x2f8d76..0x2fa884` (2,053 instructions) for the forward record and
`0x2f6793..0x2f7fd2` (1,906 instructions) for the first-field hash.
The generated developer modules contain ordinary masked arithmetic and bounded
array operations, with no instruction decoder or embedded image-data bank.
All 50 forward and 44 hash data-dependent byte reads have proved bounds.
The source models match complete original scalar/fold states on four
protocol-parameter profiles and twelve arbitrary-parameter profiles each.
The guarded source phase denies vendor reads, dynamic loading and networking
(`research/guid-middle-source-guarded-validation.json`,
`research/guid-hash-middle-source-guarded-validation.json`).

The code emitter now parenthesizes composed unary expressions before reuse.
Differential hash execution exposed the previous precedence error; both
models were regenerated and revalidated after its correction.

`scripts/guid_field_source_model.py` composes record sizing, expansion, both
middle calculations and both tails directly from an Android ID. Its complete
first-field result matches the freshly linked native source provider on four
invented profiles (record lengths 147, 112, 106 and 153); all
intermediate device values and fixed oracle parameters stay in RAM
(`research/guid-source-record-native-parity.json`). This developer pipeline
still requires six explicit unresolved parameter inputs: forward state 64,
readonly seed 48, lookup 64; hash state 64, readonly seed 64, lookup 64 bytes.
Those 368 bytes are NOT shipped or counted as the separately documented 368
bytes of approved static protocol parameters already in the package.
The two lookup banks cannot be removed by discarding unused output bits:
several reads require every bit, and zero-bank controls alter every checked
whole record/hash result. No fitted polynomial or renamed bank is shipped.

`auth/_guid_hash_tail.py` is now package-owned source. It applies all 32
header updates modulo the 20-byte state, folds the clear 64/64/328-byte
working states and runs the recovered final mixer. Its actual Python header
function has universal bit-vector equivalence to the original instructions
over all 12 independent scalar and 20 initial-state bytes (UNSAT).
Independent original execution covers 3,072 complete headers with every value of each scalar
parameter, plus 16 whole tails, 7,296 fold iterations and 4,096 mixer
iterations. Complete output and suffix preservation are compared
(`research/guid-hash-tail-original-validation.json`). The three shipped
known answers use explicitly invented states, not native device captures.
This bounded primitive does not claim to acquire its missing initial states.

Full first-field parameter generation, Mescal signing, CoreADI fresh
provisioning/OTP/MID and standalone SPC/CKC acquisition remain unfinished.
The package has no new capture-dependent or vendor-backed fallback.

### Complete record-tail reconstruction (2026-11-02)

The developer model `scripts/guid_record_tail_model.py` now reconstructs the
entire generated record after the native middle-state calculation. It starts
from the clear 0x35 fill, applies all 32 header-byte updates, folds the 64-,
64- and 328-byte states, then applies the recovered cyclic mixer. Its output
reproduces the complete 147- and 112-byte native records on the two traced
profiles. Intermediate scalar/array states stay in RAM; neither those inputs
nor the resulting device records are saved
(`research/guid-record-tail-native-validation.json`).

All 32 header updates have universal bit-vector proofs over independent
record and scalar bytes. Original execution checks every native record length
from 80 through 200, comparing the complete output and untouched suffix
(`research/guid-record-header-arithmetic.json`). The three fold loops match
55,176 original iterations across the same 121 lengths
(`research/guid-record-folds-original-validation.json`). These are arithmetic
source reconstructions with no copied lookup bank.

The record tail remains a developer model while its fixed input-state
parameters are unresolved; its arithmetic generator is now reconstructed. The package does not expose an acquisition API that requires a
captured native state. Both middle-state spans now have parametric arithmetic models, while
the forward record and first-field hash retain unexplained live lookups. Full GUID derivation, Mescal signing, CoreADI and
standalone SPC/CKC acquisition remain unfinished.

### First GUID input-record path (2026-11-02)

The call chain now distinguishes two selectors of the same helper: entry
`0x2f85d5` takes the Android ID directly and generates a variable-length
record; entry `0x2f6493` hashes that record into the first field
(`guid-initializer-call-chain.json`). Pointer relationships are recorded as
abstract labels; device buffers and native addresses remain in RAM.

`auth/_guid_record_size.py` supplies the record-size rule: start at residue 5,
subtract the repeated input bytes modulo 121 for input-length plus 355 steps,
and add 80. The selected transform accepts 8..80 input bytes and produces
80..200 output bytes. Twelve invented whole loops match 4,628 original
iterations and native stopping conditions. All 30,976 combinations of one
input byte and prior residue match independently
(`guid-record-size-original-validation.json`). The four earlier observed
record lengths 147, 112, 106 and 153 are reproduced.

`auth/_guid_record_mixer.py` supplies the final 256 cyclic updates of that
record, after removing XOR-0x47 storage encoding. Its taps use ordinary signed
cyclic indexing; the separate final 20-byte field mixer has different native
index arithmetic. Thirteen invented states match 3,328 original updates,
including aliasing taps at short lengths. A read-boundary watch confirms the
complete intermediate record on both native profiles
(`guid-record-mixer-original-validation.json`,
`guid-initializer-input-cyclic-mixer-validation.json`).

The Android-ID transform also repeats its input into 328 bytes and runs the
same four ARX passes as the recovered expander, using XOR-0x54 wire cells.
The existing arithmetic is reused with explicit input/output encoding
conversion. Four invented inputs match 1,312 original copy iterations and
5,248 original mixing iterations, comparing the complete state after every
update (`guid-forward-expansion-original-validation.json`). Subsequent
record transforms and the live 64-byte lookup remain unreconstructed; these
stages do not complete the first field, signing or full authentication.

### MAC field hash identified (2026-11-02)

Offline source tracing now identifies the second field as the first seven
bytes of SHA-1 of a 38-byte message: the supplied six-byte MAC followed by
32 bytes. The complete 80-word schedule obeys the SHA-1 recurrence, all five
initial words equal the standard IV, message padding is valid, and Python's
independent `hashlib.sha1` reproduces the field on two invented profiles.
The 32 suffix bytes agree across these profiles and decode from CoreFP's
read-only interval `0x23954c..0x23956c`. Runtime reads at
`0x67ce8a..0x67cfa7` confirm the native copy of those bytes
(`guid-MAC-SHA1-static-suffix-provenance.json`). The named SHA-1 message suffix
is shipped in `auth/_guid_mac_parameters.py`, bringing documented static
parameters to 368 bytes, including the existing six block paths' 336 bytes.
No image or opaque lookup bank is shipped.

`derive_android_guid_mac_field` now implements the complete second field.
Sixteen further fresh native-source comparisons pass on invented MACs with
varying Android IDs and serials
(`guid-MAC-field-independent-validation.json`). Full GUID derivation and
native authentication remain incomplete; the first field still fails closed
through the complete-provider API.

The native hash state uses XOR encoding `0x77143e48`; the schedule uses
`0x544b0786`. Its final serialization is independently checked on 518 original
word-store cases and all 256 byte codec inputs
(`guid-MAC-word-serialization-original-validation.json`). These encodings
remain developer analysis details, not package data dependencies. Reports
contain equality flags, lengths, source PCs and offsets, never native buffers.

### GUID field final stages and producer locations

Source read-boundary tracing locates the final descriptor copies at CoreFP
`0x668919..0x6689be` and `0x67933e..0x680a75`. A two-pass watch with invented,
replayed entropy/time inputs follows their source buffers backwards. The first
field's final producer is the 256-update byte mixer at
`0x2f8510..0x2f85c7`; its state has 20 bytes, and the field takes the first 18.
The second field's final stage multiplies each source byte by 167 and adds 18
modulo 256, at `0x5e2151..0x5e2176`, before copying seven bytes. Both bounded
stage predictions match the actual native fields on the traced profiles
(`guid-native-field-producer-stages.json`).

`auth/_guid_field_stages.py` implements these stages without image data or
lookup banks. The mixer preserves native unsigned 32-bit wrap **before**
modulo when computing early negative tap offsets. It also supplies a
mathematical inverse: no tap equals the byte updated at that iteration.
Four invented full states match **1,024 original instruction iterations**;
all **256** byte-transform inputs match the pinned instructions. The three
package tests use public invented-state known answers and validate inversion,
input copying, byte views and shape rejection
(`guid-field-stages-original-validation.json`).

The initial 20-byte mixer state and the second field's input buffer have not
been reconstructed. These are final-stage primitives, not complete field
initializers or native authentication. Earlier fixed-cipher, hash/HMAC and
simple packing hypotheses are bounded negative checks only
(`guid-field-fixed-cipher-hypotheses.json`). Developer trace reports contain
PCs, offsets and booleans, with no buffer values or pointers.

### GUID input expansion stage

`auth/_guid_input_expansion.py` reconstructs `0x2f65b0..0x2f6788` as a
repeated-input fill of 328 bytes followed by four cyclic ARX passes. Removing
the source cells' XOR-0x47 encoding exposes rotations and byte arithmetic;
there is no lookup bank or fitted parameter. A universal proof checks the
72-instruction arithmetic body against the compact formula (UNSAT), rejects
a missing tap (SAT), and exhaustively checks all 5,248 index reductions
(`guid-input-expansion-arithmetic-proof.json`). Four invented inputs match
1,312 original copy iterations and 5,248 original mixing iterations
(`guid-input-expansion-original-validation.json`).

The package also matches the full native intermediate state for four real
source-path calls with invented device profiles. Their intermediate input
records have 147, 112, 106 and 153 bytes. The later pre-fold buffer differs from
this state, so further transformations remain between this expansion and the
final field mixer (`guid-native-expansion-complete-state-validation.json`).
The caller's record generation is also unreconstructed. A source lookup at
CoreFP `0x26d800` remains unexplained; the package does not copy that 64-byte
bank. Bounded MD5/SHA specification-constant comparisons found no match
(`guid-initializer-table-specification-controls.json`).

Runtime checks confirm that the 64-byte lookup is live and unchanged from the
pinned image on all four profiles. In two positive source calls, replacing its
reads with zeros, a low-bit flip or invented values changes the first field;
the source calls still return normally and the second field remains equal
(`guid-lookup-positive-output-dependency.json`). It cannot be discarded on the
basis of the current evidence. This bank remains excluded from the package.

The current offline package suite passes **189 tests**, including original-instruction
known answers for the recovered GUID stages, record sizes, byte-view handling
and invalid-input rejection (`20261102-guid-record-stages-package-tests.log`). This is a stage implementation,
not a complete native GUID/auth provider.

### Fixed CoreFP GUID cipher paths

The blob-free boundary permits documented static vendor protocol constants,
while excluding original image/lookup banks and account/session/content
material. `_guid_parameters.py` contains **112 bytes**: one shared AES-128 key
and separately named input mask, output mask and initial feedback for each of
the two CoreFP GUID block paths. Their pinned artifact hash and source
intervals are recorded in that module. There are no encoding matrices, table
words, executable bytes, snapshots or user credentials in this initializer.

`_guid_cipher.py` implements both paths with the package's portable AES/CBC.
They import no wrapper, vendor library, image, emulator, source generator or
solver. These internal operations intentionally remain separate: their masks
and initial feedback differ, so they are not presented as mutually inverse
public encryption/decryption methods. Complete GUID field derivation and the
remaining auth providers are still unfinished.

The explicit developer generator exports these constants only after all eight
complete source/original blocks and 1,280 lookup reads agree, and parameters
fit to the first invented profile predict the second unchanged
(`mescal-guid-static-parameter-export.json`). A subsequent fresh verification
uses **two additional invented profiles** and disables key, mask, encoding and
table-model fitting. All eight source/original outputs agree, and the fixed
package functions reproduce four 32-byte stream prefixes
(`mescal-guid-fixed-independent-validation.json`). A subsequent full-stream
check reproduces both complete 128-byte streams, covering all sixteen
source/original blocks and 2,560 lookup reads without fitting
(`mescal-guid-fixed-all-streams.json`). No account or provisioning
state is read; no network request occurs. The original artifacts and source VM
remain developer oracles only.

### Fixed StoreServices GUID streams

`auth/_ssc_guid_parameters.py` supplies 64 named static protocol bytes for
`auth/_ssc_guid_cipher.py:encrypt_blocks`: key, input mask, output mask and
initial CBC feedback. The pinned StoreServices artifact hash and instruction
interval are recorded in the module. No lookup arrays or encoding maps ship.
The separately initialized inverse path below brings the current total to
**336 named static parameter bytes**. It remains an
internal block primitive; complete GUID field derivation is unfinished.

The developer model identifies a unique AES key from a complete round prefix
and checks the remaining decoded lookup-value multisets. This is explicitly
an observational hypothesis, rather than a proof of later lookup ordering.
Complete output checks independently validate the resulting byte behavior:
all sixteen source/original blocks and 2,560 reads agree across two invented
profiles, and two blocks predict both full 128-byte streams
(`storeservices-guid-full-stream-parameter-export.json`). After export, the
unchanged package constants reproduce both full streams on **two additional
invented profiles** with fitting disabled; all sixteen source/original blocks
again agree (`storeservices-guid-fixed-independent-full-streams.json`).

Invented controls reject wrong prefix and later lookup values, and explicitly
show that a row-multiset match alone does not prove ordering
(`guid-prefix-state-controls.json`, `guid-inverse-prefix-state-controls.json`).
No account/device capture, network request or provisioning state is used.

The inverse path uses `auth/_ssc_guid_inverse_parameters.py` (another 64
named bytes) and `decrypt_blocks`. The two paths have independent masks and
feedback and are not asserted to invert one another. Its 170-instruction
column model passes 389 original-instruction comparisons. Explicit prefix
relations give an UNSAT decomposition and independence from other incoming
state, and every fitting-run call site checks those relations. A six-layer
prefix yields one inverse-AES key with four later round keys independently
matching. All sixteen blocks, 2,560 word reads and both full 128-byte streams
match (`storeservices-guid-inverse-full-stream-parameter-export.json`). The
fixed implementation then matches another sixteen source/original blocks on
two additional profiles with fitting disabled
(`storeservices-guid-inverse-fixed-independent-full-streams.json`).

The current package suite passes **178 tests**, including four recorded
pristine-source CoreLSKD known-answer vectors and strict variant rejection
(`20261101-static-kernel-known-answer-tests.log`). These public test vectors
contain invented IV/plaintext/ciphertext messages, never key or table bytes.

### Fixed CoreLSKD byte ciphers

`crypto/_corelskd_parameters.py` contains **96 documented static protocol
bytes**: an AES-128 key, IV mask and ciphertext mask for each of two native
forward byte transforms. Source intervals and the pinned CoreLSKD artifact
hash are recorded in the module. Together with the CoreFP GUID parameters these two sets comprise 208 named
bytes; the separately documented StoreServices streams add 128. All contain
zero original lookup-bank bytes.
`crypto/_corelskd_ciphers.py` uses portable AES/CBC only. Its decrypt operation
is the mathematical inverse of the selected forward transform, rather than a
claim about the other native variant.

The export gate checks two original/source calls, sixteen same-session
predictions and sixteen predictions in fresh source sessions
(`corelskd-static-parameter-export.json`). Fixed constants then reproduce 24
messages in three further sessions with changed entropy, clocks and device
inputs (`corelskd-fixed-fresh-sessions.json`). More decisively, another 24
messages match in three pristine mapped-source runtimes with **no SPC,
certificate, device or session initialization** (`corelskd-fixed-pristine.json`).
No constants are refitted in these checks. Original images and source VMs are
developer oracles only and are absent from the package runtime.

The current offline package suite passes **176 tests**, including wheel/sdist
installation outside the checkout (`20261101-static-ciphers-package-tests.log`).
These internal byte ciphers do not close native initialization, complete
SPC/CKC acquisition, GUID derivation or CoreADI/Mescal authentication.

### Shipped native-auth word decoders

`_native/auth_word_codecs.c` and `.h` now provide five bounded, source-owned
word operand decoders: four CoreFP prefixes and one StoreServices prefix.
Their source intervals and file hashes are recorded under
`recovered_runtime_models.auth_word_codecs` in the provenance manifest.
The build compiles these into the existing package-owned library. Unsupported
decoder IDs and null outputs fail closed; error returns preserve output.
There is no public authentication-provider facade around these helpers.

`generate_auth_word_codecs.py` translates only arithmetic and bit operations
from the verified instruction prefixes. Complete artifacts are hashed for
identity, but no lookup words, fitted maps, model assignments, recovered keys
or runtime values contribute to the generated functions. The 240-line C file
has no image or lookup arrays. Generation is an explicit developer action;
installation/build uses the shipped source and does not access an original
artifact, source checkout, emulator or solver.

Each recovered prefix is proved injective over the complete 32-bit input
domain. The owned C passes **1,920 original-prefix comparisons** and **6,425
independent source-expression comparisons**, including every word from the
five source arrays, boundary words and invented inputs. The test changes
unrelated incoming registers and carry state. Evidence:
`mescal-guid-source-word-decoders.json`, `auth-word-codecs-differential.json`.
Invented controls reject cross-gap pointer definitions, partial-register
clobbers, foreign-register mixes and a lossy byte projection that remains
bijective on all 256 sampled words (`auth-word-research-controls.json`).

The full offline package suite now passes **174 tests**, including source-only
guard checks and wheel/sdist installation outside the checkout with the new
native exports (`20261101-auth-word-package-tests.log`).

These are operand decoders, not lookup-data generators or whole cipher/auth
algorithms. Their surrounding source runtime still requires vendor-derived
initialization and integrity data. Full native GUID/signing and CoreADI proofs
remain unimplemented in the standalone package.

### Live GUID cipher-column semantics

`recover_guid_xor_components.py` extends the analysis to prefixes that mix a
loaded word with other incoming registers immediately. It accepts only an
UNSAT proof of `F(word,other) = G(word) XOR F(0,other)` over the complete input
state. It refuses unmodeled internally undefined flags. Four source components
are proved, each with a complete 256-word inversion-family relation and **768
paired original-prefix executions**. Two regions were not covered by the
isolated word decoders. These are XOR contributions, not additional shipped
word decoders (`mescal-guid-xor-components.json`). Invented XOR/addition/AND
controls accept XOR separation and find counterexamples for the other two
mixes (`guid-xor-component-controls.json`).

`analyze_guid_column.py` reconstructs the complete register result of two
straight-line, four-lookup combinations on the live CoreFP GUID route:

| CoreFP source interval | Instructions | Exact coherent table family |
| --- | ---: | --- |
| `0x3bd20a..0x3bd2c9` | 50 | AES inverse S-box + inverse MixColumns |
| `0x6523aa..0x65246f` | 52 | AES S-box + forward MixColumns |

Each combination has a proved four-component XOR decomposition, four distinct
256-word inversion-family contributions, combined affine rank 32, and a common
byte encoding that explains substitution and mixing together. Each has four
matching normalizations among 2,040 common-scale hypotheses. The register
results match **389 original-instruction trials per combination** (778 total).
Omitting a contribution produces a solver counterexample in each case.
Evidence: `mescal-guid-first-column-controls.json`,
`mescal-guid-second-column.json`.

The original-instruction differential harness supplies word arguments at the
expected read PCs and maps their operands when necessary. It varies other
inputs and includes every source-array word plus invented and boundary cases.
It does **not** establish real-caller reachability, table bounds, permissions
or faults. One store in the first combination is outside the register-result
model. A separate frame read in the second is modeled as an additional input;
the resulting word combination is proved independent of it once the returned
lookup words are supplied. Initial flags are explicit parameters, and unknown
internal flag/value dependencies are rejected.

These column identities are extended by the live round investigation below.
They do not by themselves establish complete AES functions. All arrays,
expressions, encodings and cryptographic values stay in RAM. No new runtime
provider or SDK fallback is introduced by this research.

### Live GUID regular rounds and final-index boundary

The initial experiments in this section retained every fitted parameter in
RAM. The later explicit static initializer above supersedes that restriction
for its 112 named vendor protocol parameter bytes only.

`trace_guid_rounds.py` captures one block in each CoreFP path during a source
GUID call with invented AndroidID, MAC and serial inputs. It clones each
pre-lookup state into the pinned original-instruction developer oracle. All
**160 lookup reads per path** (144 regular and 16 final) match in PC, table,
index and word. Snapshots, indices, words, GUID fields and keys remain in RAM.
This uses vendor-dependent source objects as developer oracles, not installed
package providers (`mescal-guid-final-translated-rounds.json`).

The forward dependency graph has nine complete 16-byte input layers and eight
AES-128 round keys. A unique candidate explains the first observed key and
**seven later keys match independently**. The inverse graph contains older
dependencies and one union of two preceding-column groups. The explicit
nearest-frontier hypothesis projects 20 older/union edges and resolves that
one union using the missing table ordinal among its siblings. The resulting
nine layers independently match seven later equivalent-inverse round keys.
Both paths produce the same unique master-key candidate in RAM. The removed
dependencies have **not** been proved semantically redundant; the inverse
result remains a checked grouping hypothesis. A consecutive execution-order
grouping is rejected on both actual paths and is not used as a fallback.

`verify_frontier_aes_rounds.py` checks both directions with invented keys,
independently generated AES states, pipelined instruction order, an extra
older edge and one union. It rejects a changed later key, a union missing a
true parent and an unknown parent (`guid-frontier-controls.json`). Existing
direction controls check inversion of all ten AES-128 round keys and reject
wrong keys and ShiftRows (`guid-key-schedule-direction-controls.json`).

The final-stage indices reject reuse of the regular-stage byte translations.
Allowing a separate XOR translation per final table yields one row-codec
assignment per path for all 16 observed indices. This is a row-multiset fit
on one block, not a held-out prediction or proof of final column placement,
output encoding, whitening, chaining or parameter initialization. Those
boundaries remain under investigation. No fitted translation is emitted.

The expanded experiment captures two blocks per direction with two invented
device profiles: **eight complete regular schedules and 1,280 matching
source/original lookup reads**, with one master-key candidate per path shared
across all blocks. The three later forward outputs share the first block's
output XOR mask. The inverse path rejects that fixed-mask model on both
second blocks. A separately fitted previous-input XOR relation from the first
profile predicts the second profile's second-block residual unchanged
(`mescal-guid-heldout-cbc-feedback.json`). This tests CBC feedback rather than
claiming the failed fixed-output-mask model succeeded.

Exactly 16 input-buffer byte reads per block are recovered from original
instructions in `0x3bca00..0x3bd20a` and `0x651a10..0x6523aa`. Each set is a
contiguous 16-byte caller buffer. The inverse logical input has a stable XOR
mask at all 16 byte positions across the four captures. The forward
logical input instead has a previous-caller-output XOR relation that holds
on the held-out profile (`mescal-guid-caller-buffer-parity.json`). Buffer and
mask bytes remain in RAM. Complete caller-buffer message prediction and
source/original output-store parity are checked separately below.

`analyze_guid_buffer_cbc.py` fits a bounded CBC model using only the first
invented profile's two caller blocks. For encryption its form is
`C[n] = AES(P[n] XOR C[n-1] XOR input_mask) XOR output_mask`; for decryption
it is `P[n] = AES^-1(C[n] XOR input_mask) XOR C[n-1] XOR output_mask`.
Each path has its own initial feedback and masks. Using those first-profile
parameters unchanged, the model predicts both complete 16-byte output buffers
and both logical AES inputs of the second profile in **both directions**:
four independent held-out blocks, with changed caller inputs. The two paths
share a master-key candidate but their fitted masks are not reciprocal and
their initial feedback differs; whole-call inverse parity is not asserted
(`mescal-guid-buffer-cbc-heldout.json`).

Invented controls reject a changed held-out output, changed caller input and
its following feedback, master-key changes and an incomplete capture
(`guid-buffer-cbc-controls.json`). This is behavioral evidence about the
captured original block paths. The parameters remain in RAM, have no
source-owned initializer, and are neither embedded nor passed to a shipped
native-auth provider. It does not establish installed package GUID, signing,
provisioning or account authentication.

The final page-return probe snapshots only writable source regions after all
block stores, keeping them in RAM. All **eight complete 16-byte output
buffers** match the original-instruction oracle, alongside all 1,280 lookup
reads. The package's `MaskedCBC` implementation also matches both complete
32-byte caller messages per direction, including the two held-out messages,
with first-profile parameters unchanged
(`mescal-guid-complete-block-parity.json`). This closes the observed block
input/output and CBC relationship; it does not supply those parameters in the
standalone runtime. Whole GUID formatting/orchestration, additional paths,
native parameter initialization and the auth providers remain unresolved.

The shipped `MaskedCBC` now accepts keyword-only `plaintext_mask` (16 bytes,
zero by default). Encryption XORs it into each plaintext block before CBC;
decryption removes it after CBC. Existing three-argument behavior and logical
ciphertext feedback are preserved. Parameters are validated, copied, and not
included in the object representation. A NIST multi-block vector with
independently whitened input/output and IV checks both directions; mutation
and invalid-mask controls also pass. The complete offline suite now passes
**176 tests**, including wheel/sdist installation outside the checkout
(`20261101-guid-cbc-package-tests.log`). That caller-parameterized API embeds
no key or mask; the separately documented fixed GUID paths now do include
their 112 named static protocol parameter bytes.

`analyze_guid_key_arithmetic.py` proves first-transition index projections
against the actual instruction-derived word contributions. No lookup-array
values or word-plane constraints are supplied to the solver. All **16 forward
projections** are UNSAT: 13 with the ordinary solver and three with a separate
bit-blast/AIG fallback after ordinary timeouts. The first three inverse
projections are UNSAT; the fourth remains unknown under both bounds, so no
complete inverse transition proof is claimed
(`mescal-guid-source-key-projections-aig.json`). The surrounding observed path
is fixed and row labels still come from developer table analysis. Invented
controls prove 16 projections and reject a changed expression and unknown
origin (`guid-source-key-arithmetic-controls.json`).

Additional developer controls prove complete source-word inverse formulas
using exact matrix inverses and rotation/addition cancellation. A bounded
direct composition solver may return unknown; unknown is never counted as
UNSAT. Invented inverse controls pass 3,096 two-direction comparisons
(`guid-word-inverse-controls.json`). Normalized-word tracer controls pass
16 instruction-program cases (`guid-normalized-word-tracer-controls.json`).
These developer tools do not change the installed native runtime or provide
CoreADI, Mescal signing, or a complete standalone GUID implementation.

### StoreServices input-index contributions

The first StoreServices GUID column needs more than a word-only decoder.
Its source retains functions of two lookup input bytes alongside the returned
words. `analyze_ssc_guid_column.py` recovers the `0x1f8249..0x1f8442`
register result (125 instructions). Word-XOR separation and separation of the
two index contributions are UNSAT. A further UNSAT proof reduces those index
contributions to two canonical bytes under the source-prefix aliases: the
two frame reads use the same `[rbp-0x38]` word, and R11/R12 copy the same
unchanged EBX at `0x1f7f71`/`0x1f7f88` without later clobbers.

After all four source index bijections and these index-dependent corrections,
the four complete 256-word functions have affine rank 8. A common encoding
explains **AES forward S-box + MixColumns**, with input positions `[3,0,1,2]`.
The complete register-result expression also passes **389 original-instruction
comparisons** (`storeservices-guid-first-column.json`). This remains a column
result under documented prefix relationships, not a complete StoreServices
cipher, caller/fault proof, additional exported parameter set, or full GUID
provider. All normalization maps and table words remain RAM-only.

Separate invented-device probes show that the 18-byte first GUID field depends
on AndroidID and the 7-byte second field depends on MAC; changing the separate
serial has no effect when AndroidID is configured. Repeated calls agree.
Four-point tests reject affine input/output mappings for both fields. Simple
raw-identifier and tested direct-hash layout hypotheses also fail
(`guid-field-input-dependencies.json`, `guid-field-degree-controls.json`,
`guid-field-layout-hypotheses.json`). The 3-byte AndroidID experiment fails in
the current source oracle; reference behavior for that length is unverified.

`substitution-parameter-read-models.json` inventories original Core segment
reads before the first cipher-block boundary, for one invented call to each
kernel. The setups read **12,176** and **11,148** distinct readonly bytes.
Existing control-reference and arithmetic SIMD models reproduce **208** and
**204** of these bytes, with zero mismatches. **11,968** and **10,944** observed
readonly bytes have no explanation in those existing models. These are
observed setup read sets, not a complete dependency inventory for all callers.
Mutable globals are counted separately and never replaced with pristine data.
The report emits neither data values nor data-dependent addresses or indices.

`analyze_encoded_key_schedule.py` checks that each encoded round-key byte is a
constant XOR a selected byte of four symbolic lookup words. Acceptance requires
an unconstrained 32-bit-word UNSAT proof, without actual lookup values or
word-output-domain assumptions. It then checks the common affine row-offset
relation implied by the linear AES-128 key-schedule recurrences. The original
prefix experiment proves 80 projections in the first kernel; the second
experiment proves 58 before a bounded timeout. A timeout is not accepted.
`encoded-key-arithmetic-controls.json` passes 112 invented projection proofs
and rejects incorrect projection and key-recurrence controls.

`trace_lookup_dataflow.py` can replace an index with a simpler byte projection
only after proving it equal for all four unconstrained input words. Invented
assignments filter bad candidates; they cannot authorize replacement. The
sampling-resistant counterexample in `index-normalization-controls.json`
agrees at all filter assignments and is still rejected by the solver. The
16 existing instruction-program controls also pass with the new tracer.

The dependency graph revealed interleaved native round scheduling. Grouping
lookups into consecutive execution-order chunks incorrectly truncated the
first kernel's round analysis. The analyzer now groups by dependency depth,
with explicit checks for complete 16-byte layers and the expected previous
layer. The interleaving regression retains successful key/input reconstruction
while wrong-key and wrong-ShiftRows controls still fail
(`round-key-schedule-interleaving-controls.json`).

The corrected complete-block experiment
(`substitution-depth-grouped-rounds.json`) verifies **nine input layers and
eight round keys per kernel**, with a unique key candidate and **seven later
round keys** matching independently. All **128 encoded round-key projections
per kernel** are proved; the row-offset relations hold across all eight keys.
The tracer separately proves 148 and 153 byte-projection normalizations,
with no remaining normalization or alias timeouts at the 15-second bound.
Original/source execution and whole-message AES encryption/decryption still
match in both calls. Final-round output/key initialization and arbitrary
control paths are not proved by this experiment.

These proofs concern arithmetic and the executed dependency graph. Row/column
labels and byte encodings are still established using developer table analysis.
The byte maps are not copied into the package. Native key/mask initialization,
full standalone SPC/CKC processing, CoreADI provisioning/OTP/MID, Mescal
signing/GUID, and installed end-to-end positive validation remain unresolved.

### Native-auth substitution targets

`scan_auth_substitutions.py` applies the same bounded classification to all
16-byte-aligned 256-word windows in pinned, file-backed, readonly PT_LOAD
segments. It examines all 48 CoreADI candidates, all 495 CoreFP candidates,
and all 18 StoreServices candidates. **34, 272 and 18**, respectively, match
GF(256) inversion under affine input/output maps. Every positive independently
reconstructs all 256 words in RAM. Maps, translations and words are not emitted.
Evidence: `coreadi-substitution-classification.json`,
`corefp-substitution-classification.json`,
`storeservices-substitution-classification.json`. These scans exclude other
alignments, byte tables and other nonlinear encodings; a negative candidate
is not evidence that a complete function lacks AES or another cipher.

`probe_auth_substitution_reads.py` links a temporary read-count shim around
the existing source Mescal oracle and derives native GUID fields for explicitly
invented AndroidID, serial and MAC inputs. It reads no local hardware identity
or account/provisioning state and makes no network request. The successful
18/7-byte field result stays in RAM. Of the 290 classified CoreFP/StoreServices
positive windows, **16** are read on this route: eight in each module, with
**1,792** candidate-window reads and **4,792** distinct candidate-window bytes.
The wrapped source runtime records 11,251,173 total reads. Evidence:
`mescal-guid-substitution-live-uses.json`.

This establishes live reconstruction targets for the GUID route. The oracle
still uses vendor-derived image and integrity data; its successful result is
not a blob-free GUID implementation. Neither the scan nor this GUID experiment
implements Mescal signing, CoreADI OTP/MID or fresh provisioning. All additions
in this subsection are developer tools, not installed-provider fallbacks.

The continuation broadens the scan to minimally aligned uint32 arrays.
`corefp-word-aligned-substitutions.json` tests all 641 four-byte-aligned
rank-eight candidates and confirms 288 inversion-family windows; StoreServices
still has 18 positives at this alignment. Candidate read PCs are now obtained
from the source execution state at each wrapped native page call, without
recording registers or lookup indices. There are no missing PCs or saturated
site counters in the recorded run. Unwind ranges containing these reads identify
two CoreFP and two StoreServices functions
(`mescal-guid-cipher-function-ranges.json`).

A same-basic-block reaching-definition inventory at validated translated
instruction boundaries finds 17 CoreFP and 18 StoreServices constant-base
word-array candidates. It rejects definitions across gaps/control transfers.
Ordinary linear disassembly is insufficient here because the functions contain
skipped data islands. Many arrays have raw affine rank greater than eight.
For example, the live CoreFP load at `0x3bd265` reads a rank-32 array; its six
arithmetic decoder instructions produce an exact rank-eight inversion family,
verified against original execution on 384 inputs
(`corefp-live-word-normalization.json`).

The separate additive-offset search finds four additional mathematical
inversion-family relations using source-constant hypotheses. Those data
relations alone do not prove a consumer implements the proposed normalization
(`mescal-guid-normalized-word-tables.json`). The stronger register-only
source-prefix recovery yields the five shipped decoders described above.
An expanded source GUID trace observes **31** inventoried/classified windows:
16 in CoreFP and 15 in StoreServices. Each of the five decoder load sites
executes **eight times** on the explicit invented device profile
(`mescal-guid-decoder-live-sites.json`). These results still do not reconstruct
the remaining array contents, parameter generation, complete cipher or auth.

## Previous checkpoint: whole-message cipher parity without target tables

The package now exports `MaskedCBC`, a source-owned AES-128 byte transform
with caller-supplied key, IV mask and output mask. Its first chain value is
`iv XOR iv_mask`. It applies ordinary CBC to unchanged plaintext, masks each
returned ciphertext block, and feeds back the **unmasked** ciphertext. Decryption
removes the output mask before ordinary CBC decryption. It applies no padding.
There are no target keys, masks, table words or fitted encodings in this API.
Its AES S-box is generated from the public specification; "table-free" in
the developer report names means no target-derived tables or integrity banks,
not absence of ordinary specification-generated AES lookup tables.
This implements byte results, not native packets, faults, budgets or aliases.

The developer analysis validates actual lookup dependencies against AES
ShiftRows and the AES-128 key schedule. The first round key is inverted only
in RAM; four and five later round keys match independently in the two observed
prefixes. Each kernel has a unique matching candidate. Three-block traces
establish logical ciphertext feedback, explaining why chaining the raw masked
output failed earlier. Evidence: `substitution-aes-key-schedule-prefix.json`,
`substitution-aes-logical-chaining.json`. These remain observations on executed
paths, not a proof of every native path or parameter initialization.

`substitution-table-free-messages.json` checks **16 complete original-instruction
messages** across both kernels at lengths 16, 32, 48 and 64 bytes, with fixed
and randomized invented inputs. Key and masks are inferred from the first
block once per kernel and reused unchanged. All 16 table-free encryptions
match the complete original outputs, all inversions recover their inputs,
and the source runtime independently matches all 16 original outputs. Only
the baseline block is used for parameter fitting; the other blocks and messages
are predictions. Parameters and outputs remain RAM-only.

`substitution-table-free-heldout.json` additionally derives one baseline from
original instructions per kernel, then reuses it without refitting for **128
new source-runtime messages per kernel** (256 total, 10,240 bytes). These cases
vary invented IVs and data, cycle lengths 16/32/48/64, and do not freeze host
RNG/clock state. All encryption and decryption comparisons pass. These held-out
cases compare against the reconstructed source runtime, not separate original
instruction executions; the two baseline original/source comparisons also pass.

The full package suite passes **172 tests**, including NIST zero-mask controls,
independent ordinary-CBC comparisons with invented nonuniform masks,
multiblock continuation, strict input validation, and wheel/sdist installation
outside the checkout (`20261101-masked-cbc-package-tests.log`).

**Full standalone crypto/auth remains incomplete.** The parameter initializer
for these kernels is not reconstructed. The runtime cannot supply its own
native key/masks, generate a fresh SPC, complete standalone CKC acquisition,
provide CoreADI provisioning/OTP/MID or Mescal signing/GUID derivation. The
developer parameter inference is not shipped as a runtime fallback and still
needs pinned original artifacts. End-to-end installed positive validation is
absent.

## Previous checkpoint: symbolic index proof and coherent AES round tables

Full standalone crypto/auth remains incomplete. These are developer
reconstruction results, not new installed-package cipher/auth APIs. No inferred
encoding matrices, scalar normalizations, translations, keys, lookup words or
private exchanges are written into the package or reports.

`prove_lookup_index.py` models the 35 instructions at Core virtual
`0x1052c006..0x1052c0c4` in the byte domain. Source shuffle/comparison operands
prove that the conditional vector replacement preserves the selected low byte;
the index mask is independently checked to select exactly eight bits. The
source preparation gives `low XMM3 = low XMM8 XOR immediate(0x1052bee7)` and a
broadcast XMM4. For the normalized pointer biases, Z3 finds no counterexample
across **24 symbolic input bits and four lanes** to
`raw_index XOR store_index XOR low(XMM4) XOR low(XMM8) = constant`.
The constant remains in RAM. Omitting either seed gives a satisfiable negative
control. `substitution-index-symbolic-verified.json` also checks the model
against original execution in five fixed/perturbed/repeated invented cases:
**1,280 raw and 1,280 store indices match**, and all five whole-kernel outputs
match the source runtime. The proof scope is this index expression and its
verified selector conditions, not arbitrary source control flow or full crypto.

`analyze_table_algebra.py` reconstructs linear output spaces in RAM and checks
whether the normalized cross-ratio matrices form a common GF(256) field. It
verifies the eight-dimensional matrix algebra, invertibility of all 255 nonzero
members, and all eight field isomorphisms before comparing public MixColumns
coefficients under row/column permutations. Both tested kernels match **AES
forward MixColumns**. Synthetic encoded forward/inverse controls pass; unrelated
field mixing and incompatible final-word encodings are rejected. This
establishes a mixing-space relation, not a key or complete AES implementation.
Evidence: `table-algebra-controls.json`, `substitution-word-mixing-algebra.json`.

All eight temporary tables in both kernels have inversion-family differential
structure and are nonlinear (`substitution-word-substitution-structure.json`).
`analyze_round_substitutions.py` then requires the same byte encoding to explain
both mixing and nonlinear substitution, with a coherent assignment of input/
output rows. It checks the complete 256-entry substitutions after the derivative
filter. Each kernel has four matching normalizations among **2,040** common
scale/substitution hypotheses, all using **AES S-box + forward MixColumns**.
The inferred logical input-byte positions agree with the source table usage:
`[3,1,0,2]` and `[3,0,1,2]` in regular-table order. All inferred mathematical
parameters stay in RAM. Forward/inverse specification-generated controls pass,
and incompatible nonlinear input encodings are rejected. Evidence:
`round-substitution-controls.json`, `substitution-coherent-round-encodings.json`.

These results justify tracing the actual round dependency graph and key schedule
next. They do not establish ShiftRows, a key schedule, external encodings,
chaining, complete SPC/CKC processing, CoreADI, Mescal or end-to-end standalone
operation. At this earlier checkpoint the package suite recorded **168 passing
tests**; this research alone introduced no runtime API or initializer bytes.


## Previous checkpoint: decoded cipher lookup boundaries

Full standalone crypto/auth remains incomplete. A bounded static scan of the
pinned Core readonly region (850,424 bytes) examines 16-byte-aligned,
1,024-byte windows. Of 108 distinct-entry affine-rank-eight candidates, **95**
are exactly equivalent to GF(256) inversion under affine input/output maps.
Each positive reconstructs all 256 entries independently in RAM. Candidate
windows are not asserted object declarations, live uses, standard AES tables,
or key-independent constants. The scan excludes other alignments and
nonlinear word encodings. No fitted maps or table words are emitted.
Evidence: `research/substitution-window-classification.json`.

The original-instruction oracle now traces candidate-window reads. In invented
48-byte calls, both source/original outputs still match. The first kernel reads
four classified image windows and the second six; each touched window covers
all 256 indices during temporary table construction. That observation corrects
the interpretation of these locations as direct per-block round tables.
Evidence: `research/substitution-window-live-uses.json`.

At the first data-block boundary, each kernel has eight temporary allocations:
five of 1,028 bytes and three of 1,032 bytes. The first 256 words in every
allocation are distinct and have affine rank eight. None equals the tested
standard forward/inverse AES T-table families, including input/output XOR
translations, word-byte reversal and coefficient rotations. Byte-width and
four/eight-byte prefix hypotheses do not reveal another bijective rank-eight
array. This bounded negative result does not rule out other encodings or
establish the complete cipher. Evidence:
`research/substitution-runtime-prefixes.json`.

`substitution-runtime-table-uses.json` additionally records all lookup PCs,
widths and offset ranges after the first data-block boundary. Four temporary
tables receive roughly 41–43 word reads and the other four receive four reads
in the tested single-block calls; this distinguishes the two table groups
without guessing their cryptographic meaning. All four original/source outputs
match. An initial cross-input comparison was confounded by advancing host RNG/
clock callbacks. `substitution-runtime-tables-frozen.json` restores those
callbacks before each call: random IV/data changes all eight arrays, while
repeating the fixed IV/data case reproduces all eight exactly. All six complete
kernel outputs match the source runtime. This establishes input-dependent
representations in these cases, not an identified key schedule or an AES proof.

The stronger controlled experiment in
`substitution-runtime-table-relations.json` separates a data-only bit flip, an
IV-only bit flip, their equal-XOR cancellation, and a repeated fixed case.
Host RNG/clock state is frozen, and all **10 original/source outputs match**.
Either single flip changes all eight temporary tables and the output. Equal
flips change all eight tables while preserving the output. Each changed table
is related to its fixed-case table by exactly one input-byte XOR translation
and one output-word XOR translation across all 256 entries. The inferred
translations stay in RAM; this is a verified representation relation for these
inputs, not a source-derived initializer or complete replacement. The relation
checker also passes two invented positive controls and one independent random
negative control (`runtime-table-relation-controls.json`). The next boundary is
to derive those varying translations from the original table-construction
state, then normalize the actual round/feedback operations. Fitting and shipping
reference tables or inferred encoding constants would not satisfy source closure.

`substitution-source-output-mask.json` then checks the output translation
against original construction instructions for the first kernel. The vector
expression at `0x1052c11e..0x1052c12c` broadcasts `R9D XOR low32(XMM5)` before
XORing the raw word and fixed raw-word arithmetic. The change in that source
mask predicts the unique output-word translation exactly in **all five**
fixed/data-only/IV-only/cancelling/repeated cases; all five complete original/
source outputs match. The table is allocation ordinal 3 in this experiment.
The observer identifies it through the actual effective store address at
`0x1052c1c8`; R11 alone is an encoded base and cannot identify the allocation.
Mask values remain in RAM. Correct/incorrect predicted-mask controls pass.
`substitution-source-construction-masks.json` now also follows all four raw
lookup loads (`0x1052c0e4/0f3/106/112`) to the four effective stores
(`0x1052c1c8/1ce/1d6/1de`). The 256 raw-index/store-index pairs form a bijection
in every case. Comparing the store indices for the same raw index predicts one
constant input-byte XOR shift across the entire domain. Combined with the
source word mask, these source construction observations predict all 256 words
of the changed table in **all five** cases. No lookup word is used to derive the
input shift, and no indices, shift values or word masks are written. All five
complete source/original kernel outputs still agree. This closes the traced
mask relation for this table, while an independent source formula for the
index-construction loop and the fixed substitution/round/feedback semantics
remain unresolved. It is not a shipped standalone cipher initializer.

The new runtime-table classifier passes eight specification-generated exact/
translated positive controls and one invented random-permutation negative
control (`research/runtime-table-classifier-controls.json`). Table contents,
comparison parameters, registers, buffers and possible key-dependent values
remain RAM-only. No account, license or other network request was made.

## Previous checkpoint: source-owned arithmetic copy stages

Full standalone crypto/auth remains incomplete. The package now compiles
`copy_codecs.c/.h`, which reconstructs the output-byte arithmetic in two input
copy stages directly from instructions. There is no vendor word table, fitted
S-box/encoding matrix, wrapper link, ELF loader or captured private input in
this component. Initialization-byte coverage remains **138,744**; these are
algorithms and are not counted as additional recovered initializer data.

Stage 0 covers the output expression in Core-relative
`0x527a59..0x527aad`. It takes the incoming control byte, unsigned index and
input byte; only control bits 2 and 3 affect the result. The full copy counter
is now explained directly: BL starts at `0xd0` (`0x5279e7`), the body saves it
at frame `-0x78`, and `0x527d1c/0x527d20` restores it and adds two. The index
starts at zero and increments by one. Consequently the affecting bits equal
`(2*index)&12`; no fitted counter table is needed. The owned bounded forward
helper implements that stream, and its XOR transform is its own inverse. This
does not implement the original saved frame byte, flags or full cipher loop.
Stage 1 covers `0x53172e..0x531759`: it adds the upper control nibble,
`low8(index) XOR 120`, and 116 modulo 256. Source initialization zeros its
control/index counters and advances them by two/one; the owned bounded helper
implements that forward copy and its mathematical inverse. Both stream
helpers share the same up-front bounds checks. Copy order remains
forward even when buffers overlap. Invalid bounds/pointers reject before any
write. These helpers remain internal and do not implement packet validation or
an encryption/acquisition/authentication API.

`research/copy-codecs-verification.json` records **365,300 original-instruction
comparisons**: 262,144 stage-0 cases, 102,400 stage-1 cases and 756 additional
high/wrapping-index cases. `copy-codecs-original-boundary.json` checks both
stages inside complete original 48-byte kernel calls: all 96 output bytes match,
all observed indices match, and the stage-1 counter is exactly twice the index.
The complete source/original kernel output also agrees in both calls.
`copy-codecs-complete-original.json` then exercises lengths 16, 32, 48 and 64
with one fixed and three independently invented IV/data cases per length and
kernel. All **32 complete source/original kernel outputs** agree. Both entire
owned copy helpers reproduce the **1,280 original copy bytes** exactly; no
counter or index mismatch occurs. No operand values are written in the reports.

The package suite passes **168 tests**, including original-vector regressions,
counter rollover, mathematical inverse, overlapping forward copy, bounds
preservation, and installed wheel/sdist symbol execution outside the checkout.
The developer oracle uses the pinned original code only for validation; the
package build compiles its owned C directly. No inferred cryptographic encoding
maps or possible key-dependent table constants have been written into a model.
Remaining full-cipher, image/integrity, registry lifetime and native auth closure
is unchanged by this bounded component.

## Previous checkpoint: extended source-control flow and cipher boundaries

Full standalone crypto/auth remains incomplete. The initializer now models
**3,279 four-byte control cells / 13,116 bytes**, for **138,744 modeled bytes**
combined with the existing semantic/linking components. Forty-three additional
cells are explained by extending the bounded affine-flow window from 24
instructions/192 bytes to 96 instructions/512 bytes. All existing conservative
control-transfer, register-width, source-address and effective-address checks
remain. A dispatch offset can remain in a register through independent SIMD
setup before its eventual jump; the old window rejected such sequences.

A concrete regression loads the signed offset from `0x10014a18` at
`0x1052b38f`, adds source base `0x1052952b` to RSI, preserves RSI across setup,
and jumps at `0x1052b456` to source destination `0x1052b460`. The source test
checks this destination and partial read semantics without any ELF. The
extended initializer passes **76,164 admitted read comparisons** and **28,769
rejection/preservation checks**. The whole package passes **164 tests**;
the updated control-reference regression also passes its four targeted tests.

`research/control-data-extended-union.json` records the admitted source
identities. `control-refs-extended-live.json` poisons all 138,744 modeled
initializer bytes before rebuilding the temporary developer oracle. Two bad
invented certificates and one public-certificate SPC run reproduce baseline
output, terminal native state and all regions exactly. The negative ABI
initializer control changes executed behavior in all three cases. Remaining
original image bytes and both integrity banks are still present only in that
developer experiment; installed standalone SPC/auth is not established.

## Source kernel translation closure

The original-instruction snapshot oracle in
`scripts/probe_substitution_original.py` exposed an actual missing native path
at Core-relative `0x53a618` during a 48-byte call. The original instructions
returned, while the source runner stopped there. Only **18 instructions / 92
bytes** were absent from existing semantic source coverage. Their observed
basic block is recorded in `substitution-missing-coverage.json`.

`expand_native.py` and `generate_native.py` now include that block in the root
runtime: `native_generated/block_page_53.c`, bounds, full inventory and native
manifest. The build succeeded; other generated C pages were preserved. The
native source inventory now contains **585,388 instructions / 7,258 fragments**.
`substitution-original-expanded-parity.json` compares both kernels at lengths
16, 32, 48 and 64: **all eight source/original outputs match in RAM**, with
original/source returns and no original faults. The lowering suite passes
**157,040 differential/budget cases**, **172,384 lifetime/guard checks** and
**12 direct-entry checks**. None of these developer-runtime changes is claimed
as the still-missing installed-package acquisition/auth runtime.

The oracle loads only the digest-pinned public artifacts, clones the invented
runtime's mapped memory, registers and XMM state into original instruction
execution, and models bounded ordinary malloc/free services. Host RNG/clock
state is restored before source execution, so the comparison receives the same
inputs. Buffer and state values remain RAM-only; reports include code locations,
import names and parity booleans. The optional buffer-access view reports only
operand roles, offsets, widths and PCs, never data values. Both tested kernels
read 16 bytes from argument 0, read the admitted input length, and write each
destination byte twice in this fixture. The destination is also reread.

Further bounded mode observations are in `substitution-mode-expanded.json`:
both kernels now execute three-block calls; 32 arbitrary IV/data XOR
cancellations pass for each kernel. Repeated single-block calls agree with the
first output block but not later blocks when raw prior output is used as IV.
Thus the feedback representation still needs source-level reconstruction;
substituting ordinary CBC is not justified. `substitution-inverse-relations.json`
also rejects direct inverse compositions and constant-XOR inverse compositions
for the tested 32 invented blocks. No inferred encoding matrices or possible
key-dependent constants have been embedded as replacement data.

REA tools became callable during this pass, but native pseudocode remains
unavailable: no configured Ghidra installation, Hopper launcher, IDA or Kuna
provider exists in the reported environment. The artifact was closed after
that diagnostic; no provider was installed, configured, downloaded or invoked
on accounts/session material. Local instruction and controlled RAM-oracle work
continues without that decompiler.

## Previous checkpoint: encoded local function references

Full standalone crypto/auth remains incomplete. The source-control initializer
now covers **3,236 four-byte cells / 12,944 bytes**, including **36 distinct
encoded local function slots** in writable storage. Combined with the existing
fill/SIMD/global/linking models, the union is **138,572 bytes**. The previous
ABI-only component intentionally still rejects unexplained encoded addends;
the separate control-reference component now explains these recovered slots.

The collector admits these writable cells only when they are local RELATIVE
relocations, their live word equals independently linked pristine storage, and
the consuming instruction's effective address matches the observed address.
Named-import slots are excluded. An initial ADD requires a nearby contiguous
source MOV-immediate producer, with its live register checked. A stored frame
reference requires a source-declared call through the same frame displacement
in the same unwind-defined function and a translated function-entry target.
Every generated destination/base expression is rechecked against the pinned
original instructions and pristine development oracle. No resolved word array
is emitted. These functions initialize ordinary RAM and do not replace mutable
reads, permission checks or source call execution.

For example, Core virtual slot `0x10690068` is now initialized as the source
clock function `0x101a07d0` minus the immediate from `0x101b0c6b`. The ADD at
`0x101b0c72` recovers that function, the store at `0x101b0c76` places it in frame
slot `-0x1528`, and the call at `0x1024b219` uses that slot. The developer
collector rejects changed words/registers/effective addresses, wrong widths,
ordinary globals and imported slots (201 negative admission checks).

Evidence: `research/control-data-union.json` is the verified union of the older
readonly inventory and the new live run. `control-refs-rw-verification.json`
records **74,022 admitted reads** and **29,535 rejection/preservation checks**.
`control-refs-rw-live-reconstruction.json` poisons all modeled initializer bytes
with `0xa5` before rebuilding the temporary developer oracle: two invented bad
certificates and one public-certificate SPC run match baseline output, terminal
native state and every memory region exactly. The successful case produces
6,624 bytes, compared only in RAM. A second experiment,
`local-functions-live-reconstruction.json`, zeros only the recovered local
function slots as its negative control; that changes executed behavior in all
three cases, while the reconstructed run still matches completely. Remaining original image data and both
integrity banks are retained in that developer experiment, so this is not a
standalone SPC/CKC/auth completion claim. The package suite passes **164 tests**,
including wheel/sdist installation outside the checkout.

## Ongoing research: algebraic substitution semantics

The remaining-read inventory records 21,596 unique read tuples outside the
current initializer models on an invented/public-certificate run (20,026 in
readonly regions, 1,570 in writable regions). This is an observed inventory,
not a proof that every tuple needs a static initializer: writable values may be
ordinary runtime state. No data words are recorded in that report.

`scripts/probe_substitution_equivalence.py` now proves exact affine equivalence
to GF(256) inversion for five full 256-entry substitutions at Core virtual
`0x1003f340`, `0x10063830`, `0x100aa7f0`, `0x100a8b50`, and `0x100686e0`.
A sixth at `0x10081ed0` has the same property after evaluating its checked
post-load source arithmetic at `0x1052b84d..0x1052b878`. The original decoded
functions containing these consumers include `0x10526bc0..0x10530964`,
`0x10530970..0x1053a675`, and the large dispatcher function. This does not yet
identify complete AES rounds, keys, state layout or surrounding auth behavior.

The method computes XOR differential multiplicities, uses the unique
multiplicity-four output to remove translation, and searches invertible linear
input/output maps to inversion in the AES field. Each candidate is checked over
all 256 inputs. A specification-generated AES S-box, three independently
constructed affine-encoded inversion fixtures, and a rejected random
permutation check the search. `research/substitution-equivalence.json` reports
only relations, source addresses and counts. Original words, inferred encoding
maps/shifts and possible key-dependent constants remain RAM-only. None are
shipped as replacement data or claimed as a completed crypto implementation.

Additional boundary work is saved in `substitution-entry-parameters.json` and
`scripts/probe_substitution_calls.py`. On invented ordinary buffers, the source
packet functions at `0x10526bc0` and `0x10530970` return after modifying 48 and
16 destination bytes respectively. Their admitted control selectors are 9 and
4. The first takes data from argument 2 and writes argument 1; the second takes
data from argument 1 and writes argument 2 (zero-based argument numbering).
Argument 0 contributes through its first 16 bytes in the tested offsets.

The first sensitivity probe exhausted its own scratch heap late in the run;
its incomplete tail is not negative crypto evidence. The corrected harness
snapshots/restores the runtime and all mutable regions in RAM around every
trial. `substitution-sensitivity-isolated.json` completes all 36 bit-change
cases. For the 48-byte function, changing data byte 0 affects all three output
blocks; changing byte 16 affects the last two; changing byte 32 affects only
the last. Changes beyond the admitted data length have no observed effect.
`substitution-xor-cancellation.json` checks eight independent bit changes:
applying the same change to argument 0 and the first data byte cancels exactly
in both kernels. These are consistent with a pre-cipher XOR/IV boundary rather
than an independently supplied raw AES key. They are finite observations, not
a complete mode proof. `substitution-cross-kernels.json` shows the kernels do
not yield the same output when given the same invented IV/data. No raw-key AES
ECB/CBC hypothesis tested so far matches. The round-key hypotheses were also
rerun with isolated snapshots: `substitution-expanded-isolated.json` has 24
returning AES-128 forward/reverse/inverse-mixed context-layout trials and no
matches among the tested ECB/zero-IV CBC encryption/decryption hypotheses. No AES key, table, output buffer or
inferred encoding is written; all comparisons use RAM-only invented operands.

The next concrete reduction is to connect these relations through the actual
source consumers, so encodings can be derived or eliminated at operation
boundaries. Merely storing fitted matrices or renamed table data would not
establish source-owned full crypto/auth. Both instruction-dependent integrity
banks, other image data, registry mutations/expiry, CoreADI and Mescal native
primitives and standalone session integration remain open.

## Previous checkpoint: source ABI globals and symbolic linking

Full standalone crypto/auth remains incomplete. `abi_layout.c/.h` now models
**125,384 additional pristine initializer bytes**: 73,320 bytes of zero-initialized
global storage plus 6,508 relocation words. This is source layout/linking
metadata, not a relocated-word or image dump. Zero globals follow normal C
initialization semantics. Relative/defined references require an allocated data
location or an existing translated source instruction. Named imports are
computed as caller binding plus addend modulo 2^64; their values are neither
captured nor fixed to an original library. The model never calls a binding,
parses an ELF, loads a library, or supplies a cryptographic provider.

All 15,679 relocation locations remain in a layout directory so unsupported
slots cannot accidentally fall through to zero-global handling. **9,171 slots
remain unsupported**, including untranslated functions and unexplained encoded
destinations. These are not all classified as secrets or required live data.
For example, the local time-helper reference at `0x10690068` is currently
unsupported: its standard RELATIVE addend is not itself a recognized source
destination. Its source consumer at `0x101b0c72` adds a code-defined offset and
stores a function reference in main-frame slot `-0x1528`, called at
`0x1024b219`. Unwind metadata places producer and consumer in the same original
function (`0x1b0990..0x514c63`, Core-relative), and the decoded callee is
`0x101a07d0`. Recovering that stored-control-reference flow is a concrete next
step; the initializer does not admit unexplained addends as arbitrary constants.

`scripts/generate_abi_layout.py` uses the pinned objects only during development
to recover symbol names, allocated locations, zero-storage ranges and relocation
rules. Generated C represents named-symbol expressions and source locations,
not resolved words. The package build compiles the shipped source directly.
The App control collector now recognizes explicit `STEP` identities as well as
Core `kg_pc_` labels; the earlier 3,137-cell control model remains valid.

`research/abi-layout-verification.json` records **935,340 admitted 1..8-byte read
comparisons**, **6,382 alternate-binding comparisons**, and **76,913 rejection/
preservation checks**. Independent ordinary ELF linking creates the development
RAM oracle. Alternate zero/high/wrapping binding addresses demonstrate that the
model resolves names at call time rather than replaying original token values.
Missing/ambiguous/malformed names, unsupported slots, gaps, overflow, bad counts,
bad widths and null outputs reject without partial output writes.

The live composition now covers a **138,184-byte union** with the prior control,
fill and SIMD models. `scripts/probe_control_reconstruction.py --abi-layout`
poisons every covered byte in a temporary initializer before compilation, then
constructs initial memory from source. The 1/32-byte rejected certificates and
the successful public-certificate/invented-account case match baseline behavior,
complete terminal native state and every mapped region; SPC output is compared
exactly through RAM pipes. The positive case yields 6,624 bytes. Zeroing ABI
values while preserving the older models changes executed behavior in all
three cases. No output bytes or state digests are stored in the report:
`research/abi-layout-live-reconstruction.json`.

The final package suite passes **162 tests**, including installed wheel and
independently rebuilt sdist execution outside the checkout. Test output is in
`research/20261031-abi-layout-package-tests.log`. Symbol bindings are ordinary
source-runtime linker inputs; public auth still lacks native proof primitives.
This is not an installed SPC engine, a full initializer, a mutable-memory
fallback, or complete crypto/auth. Remaining image and integrity banks are
still retained by the development oracle. All work stayed offline, with
invented inputs and only the public certificate field; no private session,
account request, production controller, original-path move, commit or revert.

## Active continuation: live source control-reference data closure

Full standalone crypto/auth remains incomplete. This pass moves from isolated
lifecycle operations to reducing a data dependency in the live SPC runner.
`control_refs.c/.h` describes decoded source-control references: each cell is
computed from a destination already represented by a generated source label
(or a named import) and an instruction-derived base expression. It contains no
copied word/byte initializer, instruction encoding, opaque cryptographic table,
or integrity-fold/pair result. Its explicit switch cases are source program
control metadata, not an independently designed cryptographic algorithm.

The developer collector `scripts/probe_control_data.py` only observes successful
4/8-byte native reads from readonly mapped regions. It re-decodes the source
instruction window, checks the original load's effective address, propagates
affine load-to-transfer expressions, and rejects unsupported truncations,
conditional transfers, arbitrary fixture integers as bases, and destinations
without source-label/import identities. Initial-register base terms are admitted
only as source-label/readonly addresses. Reports retain decoded control edges
and base derivations; no raw data words, SPC bytes or private state are logged.
This does not classify bulk/older-graph reads, every possible input, or writable
image initialization, and does not prove a minimal closure.

The successful invented-account/public-certificate SPC profile had 1,906,827
readonly native reads (23,310 unique PC/address/width tuples). Of those,
1,674,703 reads use **3,137 recognized control cells / 12,548 distinct bytes**.
Those are read counts, not a percentage of the image bytes or the full engine.
The generation script independently rechecks the instruction recipe, source
destinations, base terms and pinned pristine data equality before emitting C.
No developer ELF access, graph inventory, wrapper checkout, or generator is
required by the installed model or distribution build.

`research/control-refs-verification.json` records **72,658 admitted read
comparisons** against the pinned oracle and **27,731 rejection/output-preservation
checks**, covering every byte and width 1..8, cross-cell reads, gaps, overflow,
null outputs and bad widths. Unknown addresses fail without writing output.
The model initializes ordinary memory; it must not override mutable reads,
permissions, shadow state, faults or instruction budgets.

`scripts/probe_control_reconstruction.py` removes all modeled bytes from a
temporary source initializer before compilation, including the prior 92 fill
and 160 SIMD bytes. It reconstructs their **12,800-byte union** from source.
Thus the initializer sees none of those original values, even transiently.
Three cases (invented 1/32-byte rejected certificates and the public-certificate
field with otherwise invented inputs) match baseline API/fault/step/clock
results, complete terminal native state and all mapped regions. State digests
are compared only in RAM and not reported. Output SPC bytes are compared exactly
through anonymous pipes and not saved or printed. The successful case produces
6,624 bytes; a zero-control version changes executed behavior in all three cases,
not merely unused terminal image bytes. Report:
`research/control-refs-live-reconstruction.json`.

Other original image and integrity banks remain in that development oracle.
This is a verified partial initializer replacement, **not blob-free installed
SPC generation, valid CKC processing, SDK parity on this new fixture, or native
authentication**. The package's public capability claims remain unchanged.
The new data model is compiled by the package-owned backend, and installed
wheel/sdist smoke checks exercise the dispatcher destination and refusal path.
The final package suite passes **159 tests**, including source-only wheel/sdist
builds and installed execution outside the checkout. Test output is saved in
`research/20261031-control-refs-package-tests.log`.

Next work must cover remaining pointer/control references and actual registry
mutators, then the remaining data and instruction-dependent banks. Extend the
same evidence discipline to Mescal and CoreADI rather than copying unexplained
constants or substituting a standard hash/signature. A scan of the five pinned
Core/App/auth artifacts found no unencoded AES S-box/T-box, SHA-256, MD5 or CRC
tables matching independently generated standard forms; that simple replacement
route does not supply the missing image algorithms. No source runtime guard,
original path or existing user edit was removed. All work stayed offline.

## Main-thread continuation: shared cleanup and logical worker boundaries

Full standalone crypto/auth remains incomplete. The new
`ams_registry_release_shared` handles canonical mode-3 cleanup with a present or
absent shared object, including the four external buffers. The old inline and
buffer-only interfaces retain their conservative mode-3 refusal contracts.
Caller-held locks remain explicit. Shared storage must be disjoint from the
record, registry, buffer mappings and owned buffers; all guards precede cleanup
or allocator callbacks. The shared reference/time update occurs after the last
buffer callback and before generation clear, matching the original order.

`ams_registry_shared` contains decoded references, timestamp, baseline and
cumulative counter. The recovered `0x24b10d..0x24b57a` semantics are:

- Decrement nonzero references; retain zero.
- Initialize a zero timestamp from the original time-helper result.
- If current seconds exceed the timestamp, compute unsigned elapsed time.
  If elapsed exceeds `counter-baseline` modulo 2^64, set counter to
  `baseline+elapsed` modulo 2^64. A backward/equal clock leaves it unchanged.
- The original time helper returns zero on gettimeofday failure.

The representation seeds cancel. Bytewise XOR keys for timestamp and counter
are independently eliminated; the temporary accumulator's key is read again
and cancels. Arithmetic mixtures reduce using
`(x XOR k)+2*(x AND k)=x+k` modulo 2^64. The offset constants in the two comparison
arms each sum to `0x8ad9cb0b`; explicit carry correction therefore gives an
ordinary unsigned elapsed-versus-counter-difference comparison. No original
image bytes, fold result constants or lookup bank are installed for this step.

`research/registry-shared-release.json` contains **328 original-ELF comparisons**:
264 present shared objects (including eight time failures), 64 absent objects,
all external-pointer combinations, independent 64-bit representation seeds,
and uint32/uint64 wrap, initial/backward/equal clocks. Every logical record byte,
allocation byte, shared object byte, counter cell, generation and release order
is checked. There are **652 allocator releases**. This supersedes the earlier
28-case observation-only result for these bounded operations, not for full
construction or synchronization.

`ams_registry_worker_begin/wake` implement logical boundaries of the original
`0xdc000..0xdc7c9` worker. Entry takes a reference modulo 2^32. On wake it clamps
the counter to the saved wake counter, maintains time without dropping a user
reference, and sets the next wake counter to `counter+5` modulo 2^64. References
zero or one take the stop branch; that branch decrements modulo 2^32 and clears
the active flag. The zero underflow case is deliberately retained. Other values
continue to a five-second sleep. This is not a session/context validity check.

`research/registry-worker-verification.json` contains **256 original-worker
comparisons**, with independent representation seeds and integer/clock limits:
118 stop boundaries and 138 repeated-sleep boundaries. The original entry and
first wake execute under an explicit single-thread test scheduler and clock.
Null locks only are exercised. The temporary oracle now supplies bounded seed-
table and counter-cell mappings; earlier exploratory runs missing them were
invalid fixtures and are not worker evidence.

The final package suite passes **157 tests**, including isolated installed-wheel
and rebuilt-sdist execution of shared cleanup and worker start/stop. The
previous 520 reset and 288 external-buffer comparisons also pass. Together with
the 328 shared and 256 worker cases, these are **1,392 bounded original-code
comparisons**, not an end-to-end crypto/auth result. Test output is saved in
`research/20261031-shared-worker-tests.log`.

These internal native state operations do not start host threads, resume the
original encoded runtime, rotate its representations, implement record expiry,
or supply complete constructor/mutator/crypto/auth semantics. No original
lifetime guard is removed. Remaining closure includes registry mutation and
expiry coverage, instruction-dependent banks and image data, CoreADI
provisioning/OTP/MID, Mescal signing/GUID, and complete standalone integration.
All inputs were invented and offline; no private exchange, account/network
request, retained harness, production controller, commit or revert was used.

The user has explicitly requested persistent work until full completion. The
completion goal remains active; these checkpoints do not pause or complete it.
Next work must connect the canonical lifecycle across remaining registry
mutators/expiry and remove the remaining runtime data dependencies, followed by
the missing native auth primitives and actual standalone integration. Do not
repeat passing checks without new changes or an unresolved concern.

## Main-thread continuation: external ownership and shared-state research

Full standalone crypto/auth remains incomplete. `registry.c/.h` now includes
`ams_registry_release_buffers`, a bounded canonical cleanup of kind-15 records
outside shared mode 3. Four buffer mappings correspond to record pointers at
`0x110`, `0xb8`, `0xc8`, and `0x130`. Cleanup preserves their original release
order; only the `0xc8` buffer is overwritten, for
`(LE32(record+0xd0)-0x193931bf) modulo 2^32` bytes, before its release. The record
pointers and associated scalar fields are reset, then its generation is cleared.

Each mapping has an abstract address, writable host storage, and capacity. A
caller-supplied void allocator callback releases that address; this is ordinary
memory ownership, not a missing cryptographic provider. Address values are never
assumed to be host pointers. Capacity, overflow, duplicate/overlapping ownership,
and registry/record/mapping alias checks all precede writes and callbacks. The
callback must return normally and not reenter or mutate other objects. Mode 3
refuses without side effects. This native building block is not yet connected
to a public Python session or acquisition API.

The developer oracle now executes the original helper dispatcher rather than
substituting success for the whole helper. Selector 1/token `0x990` reaches the
imported `free`; an explicit test allocator records releases while keeping bytes
mapped for in-RAM comparison. The saved selector at `rbp-0x9dc` is initialized
by executing its original producer with recovered caller control state 8.
Selector 1/token `0x9cd` is an unlock helper; its final null-lock path executes
and returns to `0x3f0cb7` without imports. This does not prove non-null locking or
the reset walker's eventual function return.

`research/registry-owned-buffers.json` records **288 original-ELF comparisons**:
all 16 pointer-presence combinations and 18 overwrite lengths from zero to 256.
They compare every logical record byte, every mapped allocation byte, generation
clear, pointer encoding consistency and release order: **576 allocator releases**
and **9,728 requested overwrite bytes**. The prior **520 reset comparisons** also
pass after the shared prefix refactor. The package suite passes **150 tests**,
including external-buffer cleanup from an installed wheel and separately rebuilt
sdist with checkout/socket access denied. New native guards exercise short and
wrapped lengths, missing allocator/mappings, aliasing, duplicate/overlapping
ownership, address overflow, idempotence and mode-3 atomic refusal.

Mode-3 research is separately recorded in `research/registry-shared-cleanup.json`.
With invented timer/rate-limit fields, a mapped counter cell, null locks and an
explicit deterministic test clock, 28 cases show saturating logical reference
decrement and initial timestamp publication. These are observations, not a
validated constructor fixture or full shared-state equivalence proof. The oracle
now rejects application data accesses into the mapped base-zero ELF header; a
negative missing-pool-pointer control verifies this. Earlier exploratory traces
which omitted the pool mapping are invalid fixtures, not evidence of success.

Remaining work includes complete shared-state and timer semantics, locking and
expiry, removal of instruction-dependent banks and remaining image data,
CoreADI provisioning/OTP/MID, Mescal signing/GUID and successful standalone
integration. No network, account, license request, production controller,
retained private harness, private exchange output, commit or revert was used.

## Main-thread continuation: bounded registry reset

Full standalone crypto/auth remains incomplete. This change adds canonical
registry reset operations in `registry.c/.h`; public crypto/auth session APIs
remain unchanged. The original ELF is used only by developer differential
scripts, never by the package build or installed runtime.

`ams_registry_release_unowned` skips free slots without accessing record storage
and clears occupied generations for null or non-owned records. Kind 15 refuses
without writes. `ams_registry_release_inline` additionally resets kind-15 records
whose external pointers at `0xb8`, `0xc8`, `0x110`, and `0x130` are null and whose
mode at `0x12c` is not 3. Unsupported ownership returns the cleanup-required
status without changing either object. Invalid sizes and overlapping registry/
record storage are rejected. The caller supplies decoded, writable storage and
holds the registry lock.

The recovered inline path overwrites record ranges `[0,16)`, `[0xdc,0xec)`, and
`[0x70,0xb0)` and resets eleven scalar fields before clearing the generation.
The byte overwrite is arithmetic source, recovered from
`0x48430b..0x484355` and `0x1b6cf0..0x1b6d60`; it depends on the abstract address
of the walker's remaining-length scratch cell. That address is explicit input;
no fixed captured overwrite bytes or image tables are shipped. This is the
original overwrite behavior, not a secure-erasure claim.

`scripts/trace_registry_release.py` runs the original initializer and bounded
reset walker on invented records. The owned continuation requires the caller's
saved control state 8 and saved seed-selector pointer; omitting them gives an
invalid fixture, not evidence that the original operation fails. Traces stop
at the still-unmodeled final helper at return PC `0x3f0cb7`. No helper success is
assumed. Unaligned emulated frames were rejected as invalid codec fixtures;
the relocation comparisons use aligned frames only.

`research/registry-release-verification.json` records **520 original-ELF
comparisons**: 256 record kinds, four occupied null records, four free slots,
and 256 randomized no-external-buffer cleanup records across 128 aligned scratch
addresses. The cleanup comparisons check every logical record byte, generation
clear, and encoded-pointer consistency. Five additional native refusal checks
cover each unsupported ownership branch without writes. Six package tests cover
release/reuse, guards, idempotence, inline field preservation and atomic refusal.
The full package suite passes **146 tests**, including wheel/sdist builds and
installation outside the checkout. This establishes bounded logical operation
equivalence, not full registers/flags, instruction budgets, native fault/alias
equivalence, complete teardown, session parity, or key acquisition.

Remaining lifecycle work includes external-buffer cleanup, the final helper,
locking and expiry. The instruction-dependent banks, remaining image data,
CoreADI provisioning/OTP/MID and Mescal signing/GUID reconstruction remain
unresolved. All work here used synthetic inputs offline; no private exchange,
network request, server, production-controller access, commit or revert.

## Continuation: canonical generation allocator and installed-record consumption

**Full standalone crypto/auth and a complete bank-free registry remain
incomplete.** This pass implements a package-owned native generation allocator;
it does not enable the public session/auth interfaces or remove either bank.
Original runtime paths and prior uncommitted edits remain in place. No commits,
network/account/license requests, localhost/replay services, private exchange
inputs, or retained harness interactions were used.

### Implemented source state machine

`_native/registry.c/.h` is compiled by the package build. It stores canonical
32-bit generations in 1,024 slots, rather than encoded native tags. The relation
is `original_tag = generation + 0x69cad980 (modulo 2^32)`. The original allocation
body `0x1f7300..0x2079d4` simplifies to:

- Probe `candidate & 1023`; generation zero is a free slot.
- For an occupied slot, increment the candidate modulo 2^32 and continue, for
  at most 1,024 probes. Exhaustion makes no tag write.
- On success, store the candidate generation and derive the internal record
  handle as `candidate XOR 0x51dc9294`.
- The pre-codec comparison `0x3ee473..0x3ee4e5` selects
  `(internal_handle & 1023) XOR 0x294` and compares the canonical generation
  with `internal_handle XOR 0x51dc9294`.

The original occupied-slot loop and full-table exit at
`0x1f736a..0x1f73ce` have no labels in the existing generated native pages.
Their behavior was recovered from the original ELF, not inferred from the
source runtime's successful-SPC fixture. This is a bounded missing-native-code
finding; graph fallbacks have not been exhaustively audited.

The allocator deliberately preserves unsigned wrap **through zero** in a
collision chain. A free default tag also passes its corresponding pre-codec
comparison. Neither fact is promoted to a valid/acquired crypto-context check.
The original outer entropy/nonzero check remains a caller obligation. The new
allocator has an explicit probe quota and resumable search state; this quota is
**not an original instruction budget**. Registry/search objects must be disjoint
and the caller must hold the registry lock across resumptions. Invalid/overlapping
controls fail without writing storage. Terminal search states are checked for
consistency. Record memory/codec lifetimes and expiry are not implemented here.

`research/registry-allocator.json` records the pinned original-ELF differential:

- **1,081 allocation/probe comparisons**, covering every collision-chain length
  from zero to 1,024 occupied slots, complete exhaustion, zero quotas,
  resumptions, unsigned wrap and the observable wrap-through-zero case.
- **55 probe-boundary comparisons** are included in that total.
- **3,072 independent original tag comparisons** cover every slot with matching,
  stale and default generations.
- The relation compares logical generations, candidate/probe state and defined
  outputs at probe/operation boundaries. It does not prove complete GPR/flag
  state, arbitrary alias/native-fault behavior or original instruction budgets.

Six new package tests cover allocation/resumption, full tables, wrap-through-zero,
generation reuse/stale rejection, control guards/overlap and initialization.
The final package suite passes **140 tests**, including wheel and sdist builds,
installation outside the checkout, and native allocator execution under the
existing checkout/socket-denial smoke check. The package needs no vendor ELF,
wrapper runtime, emulator, integrity bank or proof provider for this component.
The original ELF remains a development oracle only.

### First nonvacuous installed-record trace, with a narrow relation

`scripts/probe_registry_lifetime.py --registry-operations` now invokes original
finalize/decrypt dispatch on invented handles. Ordinary invented handles reject
before record consumption. The probe then explicitly constructs **one synthetic
reservation** with the new canonical allocator: slot/generation one, plus the
corresponding stored internal handle at record offset `0xf0`. That offset is
linked to the actual producer store `0x4bc6ee`. The rest of the record retains its
setup defaults. This is fixture construction, **not valid CKC processing or an
acquired crypto context**. It does not disable dispatcher, shadow, fault, bank
range/relation, step-budget or session deadline guards.

Primary current report: `research/registry-worker-lifetime.json`.
`research/registry-operations.json` retains an earlier operation-only run; its
mutation-boundary count includes the synthetic fixture write. The latest probe
accounts for that write separately from native execution.

- Public certificate field only, otherwise invented deterministic inputs;
  successful 7,056-byte FPS-format SPC. SPC bytes are compared in RAM only.
- **1,656 installed-record native reads**, **four actual decode/encode cycles**
  through `0x3ee66f` and `0x3ede57`, and **eight encoded-record mutation
  boundaries**. These are changes due to the record codec. The decoded records
  have **no application-field changes** across the exercised operations.
- The source oracle reports status zero for two finalize operations and one
  decrypt dispatch over the synthetic default record. This is not a validated
  media decryption/key-acquisition result; no decrypted-content equivalence or
  valid-key claim follows from those statuses.
- Twelve operation-boundary canonical snapshots match between original-fold and
  continuous zero-fold runs. Each snapshot contains all 1,024 decoded records
  and canonical generation tags (348,160 bytes). Encoded pointer consistency is
  checked before decoding each record with its setup seed. Snapshots travel only
  through an anonymous pipe for RAM comparison; no bytes or fingerprints are
  written to files, reports or tool output. Only booleans/counts/offsets are kept.
- The sole canonical field/tag change is the explicit synthetic reservation
  (slot one, record byte offset `0xf0`). Output SPC, operation statuses, native
  step/clock counts, canonical snapshots and canonical deltas match between the
  two runs. This is a **bounded representation observation**, not a proof for
  every mutator, thread, alias, fault, budget or subsequent session operation.
- Paired-byte bank calls remain zero. Pair-bank elimination is still untested.

The optional worker-wake probe now checks pending/active/sleeping flags before
attempting a resume. This fixture has **no worker** in either run, so the report
correctly records `attempted=false`. It supplies **no worker/expiry evidence**.
The temporary continuation code will require the real monotonic deadline before
resuming an actually saved worker; original parent reuse guards remain unchanged.
It is not part of the package or original production runtime.

### Newly located teardown obligations

`research/registry-fold-inventory.json` is a bounded static Capstone inventory
of 20 matching eight-dword-read sequences following the known mask constant,
from 69 constant-header candidates. Only nine first-read addresses have labels
in the generated native pages. This is **not an exhaustive inventory of all
binary bank accesses**, a reachability proof, or an audit of graph fallbacks.

Previously unmodeled sequences include `0x1b9ab7`, `0x1c0d2c`, `0x1c150c`,
`0x23494d`, `0x3f0520`, `0x3f0d6f`, `0x4bd3a4`, `0x4bdb07` and
`0x4be3e6`, plus `0x14746d` and `0x14862c`. The last mixes an address-derived
record seed into a second accumulator before the eighth read; the inventory
records that distinction rather than calling every span the same codec.
Original clear-tag stores `0x1b99ff` and `0x3f0cc7` also lack generated native
labels. The original instructions around `0x3f042e..0x3f0477` check the slot's
free tag and retain its tag address at `RBP-0x4860`; `0x3f0cc7` later writes the
free tag. Teardown code near `0x1b99ff` walks tag/record arrays. These are static
observations, not executed teardown/lifetime coverage.

**Next implementation target:** recover those release/reset operations and their
record/buffer ownership, including the unmodeled fold/codec consumers, and extend
the canonical registry across actual application field mutations and worker
expiry. The generation allocator is source-complete within its stated contract;
the full encoded-record registry is not. No seed-zero experiment is installed as
a bank replacement. Both integrity banks, remaining image initialization data,
CoreADI OTP/MID/fresh provisioning, and Mescal signing/GUID primitives remain
unresolved. REA decompilation was unavailable; this pass used local instruction
source, Capstone and pinned-ELF Unicorn execution instead.

## Continuation: actual setup registry and a successful offline SPC boundary

**No production integrity bank was removed, and full standalone crypto/auth is
still incomplete.** This pass changes developer probes and evidence only.
It does not install a zero-seed replacement into the package or original runner.

`scripts/probe_registry_lifetime.py` instruments a temporary copy of generated
page `1b`, the native read API, and the generator's read-capable `kg_memory`
translations. The last observer covers service-side bulk copies that are not
visible as native scalar reads. Existing source/build files remain unchanged.
The probe rejects overlapping setup record allocations instead of assuming
independent objects. Record contents and codec seeds remain process-local.

On the deterministic invented 32-zero-byte certificate fixture:

- All 1,024 registry entries are initialized and installed. The recovered scalar
  pointer and 336-byte record codecs match **all 1,024 actual producer outputs**,
  not just independently invented codec inputs.
- Eight actual setup records are passed to original digest-pinned ELF codec
  consumers in `scripts/registry_consumer_oracle.py`: **24 successful executions**
  (decode, encode a synthetic edit under an alternate seed, decode again).
  Eight mismatched-seed negative controls reject interpreting that rekeying as
  simple seed cancellation. Edits here are synthetic; they are not recovered
  application mutation consumers or a complete lifetime proof.
- There are 210,944 native record reads **before installation**, and no native
  record reads afterward on this fixture. The source API rejects the certificate.
  Thus earlier rejected-certificate fold experiments did not cover installed
  record consumption. Report: `research/registry-lifetime.json`.

A separate positive probe reads **only the public 2,598-byte certificate field**
from the existing `RCP1` SPC fixture, seeking over all account/content/SPC fields.
Account zero, content, seed, entropy and time are invented/deterministic. No
session credentials, private exchange, real CKC, network request or retained
harness is used. Output SPCs are compared in RAM through an anonymous pipe and
are not written to a report, file or tool output.

`research/registry-invalid-ckc.json` records successful FPS-format SPC generation
and a subsequent invented all-zero 876-byte CKC rejection:

- Original source oracle: **7,056 output bytes**, API/status zero, 114,828,711
  generation steps, 21 clock calls. The setup fold is called 1,024 times; all
  actual setup pointer/record outputs again match the codec model.
- A continuous zero-fold hypothesis produces byte-identical, nonempty SPC output
  with the same generation steps and clock calls. Its invalid-base rejection
  predicate is preserved. Encoded registry memory differs: this is evidence at
  this SPC output boundary, **not** full-state cancellation or a session-wide
  replacement proof.
- There are **zero paired-byte bank calls** on this trace. Pair-only and combined
  zero hypotheses also match the SPC, but that comparison is vacuous for the
  paired-byte bank and does not eliminate its valid-CKC dependency.
- No installed records are read through native reads or read-capable generator
  translations; no boundary-to-boundary record mutations are observed. The
  probe does not claim to capture a transient write-and-restore sequence or prove
  unobservability across every future API/thread/expiry path.
- The invented CKC is rejected at Core `0x1c05e1` after 7,140 steps, before any
  installed-record consumption or paired-byte lookup. Matching this rejection
  is **not** evidence of successful context/post/decrypt or key acquisition.
- Mapped image data is still consumed. Native-read coverage observes 427, 104,
  118,138 and 20,201 distinct byte addresses in the four image regions,
  respectively. These are read addresses, not a minimal initialization closure;
  writable state may already have changed, and service-side image copies are
  not counted in these particular native-read coverage totals.

`research/registry-public-certificate.json` separately records the non-FPS-format
SPC boundary (113,435,038 steps, 15 clock calls), with the same 7,056-byte output
equality on that fixture. `research/registry-guard-checks.json` checks the
experimental predicates against the original source API: **21 fold rejection
cases, 10 pair rejection/output-preservation cases, and 3 pair acceptance cases**.
This checks rejection behavior only, not valid lookup-value equivalence.

**Next blocker:** the successful SPC path does not exercise installed registry
consumers. The representation proof must extend to actual application access,
mutation and worker/expiry lifetimes, with valid CKC/post/decrypt coverage or
an equivalent complete static proof. The generic codec's algebraic rekeying and
a matching invalid-CKC rejection cannot supply that missing evidence. The prior
retained harness PIDs are no longer alive; they were not attached or modified.
Image-data reconstruction, CoreADI and Mescal remain outstanding independently.

## Continuation: integrity consumer algorithm and falsified cancellation

**Full blob-free crypto and auth remain incomplete. Neither integrity bank has
been removed or reduced.** This continuation reconstructs the actual
pointer/table codec around the folds and adds a proven 160-byte pristine data
model. It preserves the prior 92-byte fill reconstruction and all original paths.
No commits, original-path moves/deletions, production/runtime harness requests,
account/network operations, or private exchange inputs were used.

### Producer/consumer semantics recovered

`scripts/verify_integrity_codec.py` now derives and independently checks the
forward consumer `0x3edebc..0x3ee383` and inverse consumer
`0x3ee6a1..0x3eed16` against the digest-pinned original ELF under Unicorn.
The parameter `f` below is the **still-unrecovered fold result**, not a source
replacement for it. All word arithmetic is modulo 2^32:

- `P = 0x1000193`, `C = 0x678086cb`, `k = f*C`.
- Pointer bytes undergo descending swaps `(i, (((k+i) XOR k)*P) % i)`
  for `i=7..2`, then `(1,0)`. All chosen partners are strictly less than `i`.
  This is a permutation, not an integrity lookup.
- The two resulting words are multiplied by `P`, with respective additions
  `q0 = k*k XOR k` and `q1 = k*(k+1) XOR k`. Encoding the all-zero temporary
  therefore yields the two-word `q`. The encoded registry pointer XORs this
  zero encoding and subtracts `0x87a0e6b449599d30`.
- The inverse adds that offset, XORs `q`, subtracts `q` wordwise, multiplies
  by the inverse of `P` modulo 2^32, then reverses the byte swaps. The final
  pointer store subtracts the offset again. The inverse is checked against
  the original consumer, not just against the forward model.
- A **336-byte mutable record (42 words)** has seed `s=low32(address)*C XOR f`.
  Byte position `i` uses mask `((i-s)*(i+s)) XOR s`: XOR the low mask byte,
  multiply by `P` modulo 256, then shuffle words descending `i=41..1`, with
  partner `(((s+i) XOR s)*P) % i`. The consumer reverses the word swaps and
  byte transform. This is a record codec; no claim that the record is purely
  function pointers is made. Setup before `0x1b65fb` writes heterogeneous
  fields (e.g. `0x1b640a..0x1b64e9`) before applying the related encoding.

This proves an algebraic inverse for a common seed, but **does not prove that
changing/removing the seed preserves encoded memory, registers or faults**.
The oracle confirms 256 invented pointer encodings change when the seed changes.
A record already encoded by its producer cannot be decoded using a freely
chosen substitute seed. A replacement must cover the registry/record lifetime
and all consumers, including mutations and aliasing; a pointer roundtrip alone
is insufficient.

### Full-state cancellation hypothesis tested and rejected

`scripts/probe_fold_boundaries.py` clones complete native state and every mapped
region at each native-run entry, retaining addresses, permissions and budgets.
It runs the source-runtime oracle and a candidate returning the fold's input
instead of its result, each to the next real import/fault/limit boundary. Clones
are discarded after each comparison; this is **not** a continuous alternate
session. Host-overlapping regions are rejected rather than cloned incorrectly.
Reports retain counts/addresses only; no state snapshots or table bytes are saved.

With deterministic invented entropy/time and a 32-zero-byte certificate:

- 3,197 boundaries, 1,024 affected; **zero affected full states match**.
- All 1,024 folds are at `0x1b65fb`, none at `0x3ede57` or the other seven
  hooks. Earlier reports proving live folds did not establish which site.
- Every affected boundary differs in GPRs, SIMD/TLS state and mapped memory.
  The first eight differ in 357–363 mapped bytes. Flags, shadow metadata,
  status/PC, fault metadata and step counts match on this fixture.
- These results reject this particular larger-boundary substitution; they do
  not prove every possible higher-level semantic reduction impossible. The
  source runtime is the oracle for this probe, not renewed full-ELF parity.

Report: `research/fold-boundaries.json`. This fixture's unchanged eventual
certificate rejection cannot be used as evidence of bank cancellation.

### Proven integrated data replacement and validation

`_native/integrity_codec_data.c/.h` generates **160 bytes** at ten CoreLSKD-relative
16-byte ranges: `0x580`, `0xe20`, `0xe30`, `0x1170`, `0x25b0`, `0x25c0`,
`0x35d0`, `0x4690`, `0x4c40`, `0x4f40`. Their contents follow from consecutive
SIMD indices, byte masks, the FNV multiplier and its Newton-computed modular
inverse. No original bytes, fold results, opcode synthesis or opaque banks are
encoded in the model. It is compiled into the package-owned native backend;
no new public crypto/auth helper or completeness claim is added.

The model initializes ordinary mapped memory. It does not override mutable
reads, permissions, guards, shadow policy, faults or budgets.

- `research/integrity-codec-verification.json`: **1,000** original-data reads;
  **90** original-ELF/model consumer execution pairs, comparing all 16 GPRs,
  RIP, flags, 16 XMM registers, all mapped bytes, faults and executed steps.
  Includes 64 ordinary forward/inverse cases, 8 alias/fault/permission cases,
  and 18 instruction-budget cases. Scalar pointer and record formulas agree
  with the original consumers; 4,096 invented scalar roundtrips also pass.
- `scripts/probe_codec_reconstruction.py` builds temporary offline source
  oracles without ever copying these 160 bytes or the prior 92 fill bytes.
  Three invented 1/32/128-byte certificates match baseline API results and
  SHA-256 fingerprints of complete terminal native state (including shadow
  metadata) and all mapped regions. The originals remain offline dev oracles.
  **57,000** native reads into the modeled codec ranges occur across the three
  cases. A zero-codec negative control preserves the fill model and produces
  the same API rejection/steps but different complete-state fingerprints.
  Those fingerprints include the changed image ranges themselves; they are
  evidence of non-equivalence, not a measurement of propagated output changes.
  Report: `research/codec-live-reconstruction.json`.
- Package suite: **134 tests passed**. Build/install tests exercise the native
  data model outside the checkout, including the sdist checkout/socket-denial
  smoke check. No vendor SDK, ELF, emulator, wrapper library, provider or bank
  is needed by the package. That verifies the shipped smaller closure, not SPC
  acquisition or authentication.

Together with the prior 92-byte fill model, **252 initialization bytes** now have
reproducible semantic models. The original mapped allocation remains 1,879,649
bytes and is not shrunk; 1,879,397 initialization bytes remain unmodeled, without
claiming each is live or irreducible. The 185,729,024-byte fold bank and
11,665,424-byte CKC pair bank remain unchanged in the offline runtime and remain
excluded from the package. CoreADI's 1,289,076-byte data closure/fresh provisioning
and Mescal's 3,080,356-byte images/9,158,688-byte pair bank/signing/GUID algorithms
remain unresolved. No new auth implementation is claimed.

**Next falsifiable blocker:** replace the setup encoded-record registry together
with its actual access/mutation consumers, starting at the live `0x1b65fb`
producer and its registry store `0x1b630f`; prove the complete boundary state or
an explicitly justified representation relation, including shadow lifetimes,
aliases, failures and budgets. The recovered parameterized codec makes that
question concrete. It does not justify dropping the seed, substituting a
constant, or changing existing guards. `0x3ede57` remains an independently
verified post-fold consumer model, not a reached successful SPC path.


## Continuation: first live image-data replacement

The full objective remains incomplete. No cryptographic integrity-bank
replacement, CoreADI OTP/MID/fresh provisioning, or Mescal signing/GUID-field
algorithm was recovered in this continuation. The only new package-native
implementation is a small, falsifiable **read-only data-model replacement** on
the measured SPC path. It does not expand the public crypto/auth capabilities.

`_native/fill_dispatch.c/.h` reconstructs app range
`0x525a00..0x525a5c` (92 bytes, 23 destinations), including the previously
measured first image read at `0x525a1c`. The consuming routine at
`0x42ced0..0x42cffb` is a standard byte fill: leading bytes to align the
destination, whole words via a Duff-style loop, then trailing bytes. Three
finite control models select the remaining stores. Prefix/bulk stores have
seven-byte source-layout spacing; the final suffix store has three-byte
spacing. The code serializes signed relative **control destinations**, not
instruction bytes. No oracle outputs or binary table bytes appear in the
implementation. This finite control structure is admissible under the same
boundary as the existing comparison-selection branches.

This is a model of **pristine initialization data**, not an immutable memory
override. The offline integration materializes it into the existing image
region before execution. Original memory permissions, mutable/aliased memory,
shadow guards, faults, and step budgets remain in force. The package does not
ship the surrounding session runtime or automatically substitute this model
into an external provider.

New evidence (ordinary local source/disassembly/Unicorn tooling; no REA-native
decompiler was available; no engine or configuration was installed):

- `scripts/verify_fill_dispatch.py APP_ELF --output REPORT`: digest-pinned
  original is an offline oracle only. **708** reads across every valid offset
  and width match, including reads crossing model boundaries. **373** original
  routine execution pairs match all general registers, flags, mapped memory,
  faults and termination: 8 invalid-destination cases, 9 instruction-budget
  cases, and 4 table/stack-alias cases. Completed ordinary cases also independently
  satisfy the byte-fill operation. Report: `research/fill-dispatch-verification.json`.
- `scripts/probe_fill_reconstruction.py CHECKOUT --output REPORT` builds a
  temporary original-source generator with **no copy of those original 92
  bytes**, filling the range with the package model instead. Three deterministic
  invented certificates (1/32/128 zero bytes) match baseline status, PC, faults,
  output length, source steps and clock calls. All reject with no SPC; no success
  inference is made. A zero-data negative control stops after 93 steps at
  `0x525a1c` in all three cases, whereas reconstructed runs reach the baseline
  rejection after roughly 14.58 million steps. Report:
  `research/fill-live-reconstruction.json`. Other copied images and both integrity
  banks remain present in this **oracle** build.
- Package suite: **132 tests passed**, including source-only model checks and
  distribution build/install checks. Installed wheel/sdist smoke checks directly
  call the new compiled model, with checkout/socket denial on the sdist test.

The 1,879,649-byte original mapped-image allocation has **not** been removed or
shrunk in the original runtime. Only 92 of its source-initialized bytes have a
new verified semantic reconstruction; this is not a claim that the other
1,879,557 bytes are all live or irreducible. Neither the 185,729,024-byte fold
bank nor the 11,665,424-byte CKC pair bank has been reduced. The previous audit's
successful full-runtime results remain historical, not renewed here.

Bounded GUID probes used invented AndroidIDs/MACs only. Fields were deterministic;
AndroidID changes affected only the first field and MAC changes only the second,
with diffusion across every output byte. Plain concatenation and the tested
unkeyed MD5/SHA-1/SHA-256 candidates did not explain the outputs. An AndroidID of
length one failed the recovered provider; the existing permissive 1..4096 input
adapter is not proof that every such input succeeds. No new field algorithm is
claimed. Exploratory source call-edge metadata is in
`research/guid-call-edges.json`; it is not a cryptographic derivation.

Next research blocker remains **higher-level semantic reduction of the
instruction-dependent folds/pairs**, not table serialization or reassembly.
On the measured fold site `0x3ede57`, eight dependent word reads feed the
multiply/dispatch state at `0x3edebc` onward. A valid replacement must prove the
resulting algorithm and preserve its downstream behavior, or prove an equivalent
higher-level operation without those reads. No such proof was found. GUID's
field-producing CoreFP path also still traverses its paired-byte operations;
call-edge tracing alone cannot justify substituting a standard hash. CoreADI's
fresh provisioning code/data closure remains missing as documented below.

## Result and boundary

The package builds its own native library and provides useful crypto/protocol
operations. It does **not** yet implement blob-free SPC creation, an owned FPS
session, successful CKC processing, context construction/finalization, or native
account authentication. Packet adapters for those operations are not their
cryptographic implementation. Full standalone crypto **and** auth remains an
unresolved objective; this change extracts the valid smaller closure rather than
silently substituting data, removing checks, or treating protocol interfaces as
implementations.

Generated control flow is eligible source. In particular, the 3,598-instruction
CoreLSKD translation is shipped and compiled. The other generated runners are
not rejected because they are generated: their reachable data dependencies have
not been replaced with admissible source. No original has been edited or
removed to make this package build. No native SDK fallback is provided.

Paths below are relative to the original checkout unless prefixed `src/`.
`closure_manifest.json` beside this audit records exact copied-source sizes and
SHA-256s, audited generator hashes, image metadata, and hook/coverage summaries.
Developer scripts under `scripts/` are optional audit tools, not package runtime
loaders. Run them from a checkout with its existing build objects; distribution
build/install/tests do not invoke them.

## What the verified runtime established

Read-only evidence:

- `build/re/keygen-notes/ckc-source-continuation-20261030-progress.json`:
  `verified_target_pair`, source context/post/decrypt and independent AES parity.
- `build/re/keygen-notes/ckc-independent-rerun-20261030T092404Z.json`:
  whole SPC equal, successful reference and source context/post, exactly 64
  decrypted bytes, R1 capture, source AES key extraction, independent AES-CBC
  plaintext equality, no reference key supplied to source.
- Scope is one pair, `6774745741` / `skd://itunes.apple.com/p1456800325/c6`.
  Production controller/cache, other catalog items, and successful persistent
  conversion were not verified by that run. Key equivalence is evidenced by
  independent plaintext equality, not a direct reference-key comparison.

These are historical assertions, not newly repeated live-license tests. This
audit did not connect to, inspect memory of, signal, or change the retained
harness. No retained exchange or private fixture was read.

`tools/crypto/keygen_experimental/replay_ckc_source.py` constructs
`source_protocol.SourceSession` with `build/spc-payload/libwrapper_spc_generate.so`.
The local ELF dynamic metadata establishes this load closure:

| Component | Load/use evidence | Source/data role |
| --- | --- | --- |
| `libwrapper_spc_generate.so` | explicit `ctypes.CDLL`; `DT_NEEDED` native + libc | owns session, copies `kg_images` |
| `libwrapper_spc_native.so` | `DT_NEEDED` from generate | native/app C groups, both integrity banks |
| `libwrapper_spc_payload.so` | `DT_NEEDED` from native | older graph fallback and constant bank |
| R1 `probe.so` | optional `load_probe` in replay adapter | package-external observer, not key-generation fallback |
| `libwrapper_crypto.so` | `r1_replay_parity.verify_probe` | recovered R1 and key extraction |
| `libcrypto.so.3` | `r1_replay_parity.aes_cbc` | independent OpenSSL AES parity oracle |

The first two libraries carry an original build-directory RUNPATH. None is
redistributed or linked by this package. The historical report is not a complete
saved process-map inventory: the table distinguishes explicit loads, mandatory
loader dependencies, and optional probe support rather than inventing one.

The denial preload at
`build/re/keygen-notes/source-generation/no-sdk/deny-sdk.c` aborts named
`dlopen`/`open`/`open64`/`openat` attempts containing `libCoreLSKD`,
`libandroidappmusic`, or `libunicorn`. Replay checks its presence in process maps.
It does not inspect compiled C arrays, ban wrapper-named source libraries,
establish a general network sandbox, or eliminate binary-derived data.
“SDK-denied source execution” is therefore compatible with the parity report;
“blob-free full runtime” is not established by that report.

## Crypto data provenance and actual lookup policies

`crypto/keygen_experimental/CMakeLists.txt` builds all native/app `block_*.c`,
SPC `integrity_generated/table_*.c`, and CKC `ckc_integrity_table_*.c` and links
the payload runner. Linkage alone does not prove a fallback is executed.

`spc_generate.c:kg_generate` unconditionally allocates and copies every
`kg_images` entry, before setup at application entry `0x3dcb80`. The generator
`tools/crypto/keygen_experimental/generate_source_images.py:module/main` reads
pinned ELF artifacts, copies `.rodata`, materializes writable sections including
zero-initialized BSS, applies relocations, and copies ELF header bytes. It does
not regenerate these ranges from standard algorithms. The manifest identifies
CoreLSKD SHA-256 `1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b`
and app SHA-256 `0a575431868e40ddb29e9e0bac7a4993d6e05971b45403cabe358c081b54a36e`.

| `kg_images` virtual range (end exclusive) | Bytes | Role |
| --- | ---: | --- |
| `0..0x200` | 512 | app header/TLS model |
| `0x4c9e20..0x54f071` | 545,361 | app rodata |
| `0x5be7c0..0x60afb4` | 313,332 | app relocated writable image |
| `0x10000000..0x100cf9f8` | 850,424 | core header + rodata |
| `0x1066d000..0x10696824` | 170,020 | core relocated writable image |
| **Total** | **1,879,649** | copied/mapped, not a proven minimal live subset |

`spc_native.c:wrapper_kg_native_read` first resolves caller regions, then calls
`spc_native_lookup.c:wrapper_kg_native_lookup`, which always returns failure.
It does **not** fall back to `spc_payload_constants.inc`. Guarded reads in
`spc_native_internal.h` additionally enforce byte/word shadow lifetime, frame,
whole-cell and parity policies. `wrapper_kg_native_run` only admits the older
graph fallback when its shadow policy allows it. Those guards remain untouched.

Older `spc_payload.c`/context/initial/intervening/continuation paths instead
resolve regions and then their own `payload_constant_read[_imported]` bank.
`generate_payload_constants.py:generate` reads declared `.rodata` neighborhoods
and `.data.rel.ro` slots from the pinned ELF. It emits 72,432 selected bytes in
168 ranges, 92 relative relocation slots, and special malloc/free import slots.
The manifest reports 5,797 unique originally read bytes; rounding is 256 bytes
for rodata and 8 bytes for relro. These are selected binary data, not proof of
standard AES tables. The full session already maps broad image regions, so the
existence/linkage of this fallback bank does **not** establish that all 72,432
bytes, or any particular fallback access, were necessary in the successful run.

The separate integrity dependencies cannot be dismissed as unused linked data:

| Symbol / generated bank | Derivation and logical data size | Source sites |
| --- | --- | --- |
| `wrapper_kg_integrity_fold` / `delta[row][32768]` | `generate_integrity.py` + `identity_builder.c`: eight `v ^= LE32(binary[base+(v&32767)])` rounds, emit delta for each low-15-bit input. 1,417 windows `0xdc000..0x664000`, stride 4096; **185,729,024 bytes** | nine distinct hooks: `0x1b65fb`, `0x207b91`, `0x23915b`, `0x3ede57`, `0x3ee66f`, `0x4b7898`, `0x4bc9da`, `0x50cb28`, `0x50d8b3` |
| `wrapper_kg_ckc_integrity_word` → `wrapper_kg_ckc_integrity_pair` | `generate_ckc_pairs.py`: byte(a) XOR byte(a+2), or byte(a-32766), over CoreLSKD `0xdc000..0x66c008`; **11,665,424 bytes** | 3,693 distinct generated call sites; 3,671 are inside historical reference basic-block coverage; examples and lines in manifest |

All nine fold sites lie in the historical reference coverage. For example,
`native_generated/block_page_3e.c` at guest `0x3ede43` loads the relocated base
slot `0x10695d80`, followed by the fold hook at `0x3ede57`. The fast path has
specific mask, shadow, non-overlap, output-memory, and budget preconditions;
otherwise ordinary reads fault because original instruction bytes are absent.
CKC word sites similarly conditionally invoke pair substitutions. Static coverage
of a hook's block does not itself prove its fast branch was selected.

A new synthetic runtime probe supplies stronger, separate evidence:
`scripts/probe_crypto_dependencies.py` interposes exported native read/fold
functions in a fresh child. With a 32-zero-byte invented certificate and invented
content/seed, SPC is rejected (`api=-3`, no output), but one measured run made
**1,346,271 native reads, 773,962 reads in the four non-TLS image ranges, 1,024 fold calls**, first
image read `0x525a1c`. Counts can vary with OS inputs. This proves a live fold
and image dependency before certificate rejection; it is not successful SPC
parity, a CKC table trace, or proof that every mapped byte is indispensable.

The fold and pair outputs depend on the pinned binary's instruction bytes.
Calling these arrays “derived source”, encoding them differently, or assembling
instruction words back from recovered C does not make them standard algorithm
constants. No validated source replacement eliminating their semantic dependence
has been recovered here. An admissible full closure needs such a replacement
and a minimal reproducible data model, followed by renewed parity validation.

## Independent auth audit

| Capability | Recovered implementation and actual gap |
| --- | --- |
| Anonymous CoreADI MID/OTP | `crypto/auth/coreadi/coreadi.c:generate` invokes `kq56gsgHG6`, `nf92ngaK92`, `Sph98paBcz`, then `qi864985u0`; source adapter `tools/auth/coreadi_source.py:SourceCoreADI` accepts existing `adi.pb` + matching AndroidID and only anonymous account `-1`/uint64 max. It is not fresh provisioning or account-bound OTP. |
| CoreADI data | `tools/auth/coreadi_generate.py` copies relocated non-executable PT_LOAD memory from its oracle into `generated/image_*.c`; `generate` maps all entries. Exact ranges: `0..881628`, `0x244000..+74936`, `0x10000000..+319864`, `0x10183000..+12648`: **1,289,076 bytes**. `adi_native_read` only reads mapped regions; no source algorithm regenerates the image bank. |
| CoreADI provisioning | `tools/auth/adi_protocol.py:AdiProvisioning` implements lookup/start/finish/teardown HTTP orchestration. `CoreADI` is a Protocol; `UnimplementedCoreADI` raises. `SourceCoreADI` has no `start_provisioning`/`end_provisioning`, synchronization, or fresh-device producer. This is a missing recovered implementation in addition to data provenance gaps. |

| Mescal initialization/signing | `crypto/auth/mescal/mescal.c:create_with_trace`, `wrapper_mescal_exchange`, `wrapper_mescal_sign` execute recovered source. `new_runtime` maps all ELF-derived `generated/images.inc` entries, **3,080,356 bytes** (`tools/auth/mescal_manifest.json`). `mescal_generate.py` reuses the ELF section/relocation materializer for storeservicescore/CoreFP. |
| Mescal pair data | `mescal_integrity_generate.py` reads pinned CoreFP SHA-256 `cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175`; `delta[2]` covers `0x2a2000..0x700010`: **9,158,688 bytes** of binary-dependent paired XORs. `mescal_integrity.c:mescal_integrity_pair`; source sites include CoreFP `0x33a5f8` in `mescal_corefp_page_33.c` and page `5d`. |
| GUID fields | Independently audited: `wrapper_mescal_guid_fields` configures AndroidID at storeservicescore `0x205190`, then queries selector 2 at `0x203f10`. These are not simple AndroidID/MAC concatenation or the SHA-1 formatting rule. A synthetic successful run with invented ID/MAC, temporary relinking with `--wrap=mescal_integrity_pair` and `--wrap=mescal_native_read`, observed **8,567 pair calls, 11,248,686 reads, 5,111,386 image reads**, first image read `0x9766c`. Hidden symbol visibility makes the crypto preload's zero Mescal count inconclusive; the separate wrapped probe fixes that instrumentation issue. |
| Token requests | `tools/auth/token_client.py:api_token_signing_bytes`, `TokenClient.developer_token/music_user_token/acquire` and `native_adjuster.py:NativeRequestAdjuster.adjust` are source protocol/orchestration. They consume `machine_data.otp(-1)` and `signer.sign(exact_bytes)`. Source request construction cannot manufacture a valid MID/OTP, signature, server-issued native token, or developer/Music-user token. |

The native ABI contract is independently exposed by the public
[`Dadoum/Provision` ADI caller](https://github.com/Dadoum/Provision/blob/main/lib/provision/adi.d): provisioning start takes a 64-bit DSID and SPIM bytes and returns CPIM bytes plus a 32-bit session; finish and destroy consume that 32-bit session; synchronization returns machine-identifier and synchronization-resume-metadata byte arrays. The offline probe `build/re/auth-reimplementation/coreadi-provision-start-synthetic.json` invoked `rsegvyrt87` with a synthetic 16-byte SPIM and observed `-45032` (`dataTooShort`), no CPIM and no session. Its coverage added 26 StoreServices and 104 CoreADI blocks, all translated to C. The observed failure path read 780 unique bytes from non-executable CoreADI segments. This is failure-path coverage only; it does not prove valid SPIM parsing, CPIM production, PTM/TK verification, synchronization, or teardown. `uv5t6nhkui`, `tn46gtiuhw`, and `fy34trz2st` still have no executed bounds. The 1,289,076-byte CoreADI data bank remains mapped, so the closure is not blob-free.

`SourceCoreADI.start_provisioning()` now reaches the translated `rsegvyrt87` path with an empty provisioning file model. The same synthetic challenge returns `-45032` from the package native library, matching the offline oracle. This backend still lacks end/destroy operations, so `AdiProvisioning.provision()` rejects it before making a network request. The new bridge also still maps the vendor-derived data bank; this is partial operation coverage, not blob-free provisioning.

CoreADI synthetic rejection probe (`scripts/probe_coreadi_dependencies.py`) uses
invented provisioning only: `api=-2`, PC `0x10086e27`, no MID/OTP, 298,257 reads,
231,395 image reads, first `0x2442a4`; rodata addresses include `0x8f46c` and
`0x8f4b4`. This demonstrates mapped-data consumption, not successful OTP or the
minimum proprietary subset. The bank mixes relocations, zero state, metadata,
and constants; this audit does not falsely classify every byte as irreducible
secret data. Recovering a reproducible CoreADI data model remains unresolved.

The original auth README records bounded source/reference successes and a later
successful source sign-in/token flow. Those builds include the data banks above;
they are evidence of recovered runtime behavior, not this package's blob-free
login parity. No account requests were repeated during this work.

## Extracted closure and reproducibility

The build backend compiles the following package-owned C in one library with
libc only, no wrapper/SDK links, no RUNPATH, and no data-image include:

- Existing `corelskd_r1.c/.h/_generated.inc`: block, CBC, extraction. Generated
  arithmetic/control flow is allowed; caller context is input, not embedded data.
- Exact copies of `spc_v2.c/.h`, `ckc_packet.c/.h`, `mt19937.c/.h`,
  `compare_select.c/.h`, `field_copy.c/.h`, `append_bytes.c/.h` from
  `crypto/keygen_experimental/`. Their closure is integer arithmetic, bounded
  caller buffers, memcpy/memmove/memset. The comparison selection array contains
  16 finite control destinations, explicitly enumerated as recovered branches;
  it is not a cryptographic substitution/integrity bank.
- `crypto/protocol.py`: exposes the complete public functions of those modules,
  owned result bytes, unsigned-range validation, strict envelopes, and explicit
  integer virtual addresses. C failure contracts remain intact.
- `crypto/corelskd.py:initial_iv`: extracts the previously unexposed bijective
  chain decoding from `tools/crypto/keygen_experimental/r1_replay_parity.py`;
  rejects duplicate encoding entries. It does not acquire state.
- `auth/sap.py:establish_signer`: extracted from `tools/auth/fresh_login.py`,
  implementing the certificate/setup exchange, exact returned buffers, phase and
  round bounds, and checked destinations. Existing auth protocol modules remain
  package-local; missing cryptographic providers are still explicit gaps.

Standard constants are demonstrably reproducible: AES S-boxes are generated
from GF(2^8) inversion and affine transformation in Python/C; MT19937 recurrence
and tempering use the standard literal polynomial/masks and are independently
checked against Python's implementation. No target image/table generation is
part of a wheel or sdist build. The package ships no session, account state,
certificate capture, CKC, key context, original ELF, or opaque integrity bank.

## Checks actually performed

- `python3 -m unittest discover -s tests -v` in the package: **130 passed**.
  Includes NIST AES, CoreLSKD synthetic block/CBC and extraction rejection,
  SPC header/length/alignment failures, all four dispatcher layouts and status
  failures, native output-preservation contracts, all five field-copy bodies,
  address-bound packets, encoded overflow, 4,992 independent stdlib MT outputs,
  256 word encodings, and all 256 IV permutation inputs.
- Mock-only auth tests cover SAP exact-buffer exchange, malformed responses,
  invalid phases, bounded non-completion, rejected destinations, login/provisioning
  lifetime/fault paths, token failures, and private session-store behavior.
- Packaging tests build a wheel and sdist, install the wheel elsewhere, and
  independently install/build from the extracted sdist elsewhere with no index
  or build dependencies. The installed sdist crypto calls run under an audit
  hook rejecting checkout reads and socket operations. `readelf` confirms no
  wrapper dependency or RPATH/RUNPATH in the package-built library.
- Original suites: **109** `tools/auth` tests, **5** native-session tests,
  **10** FPS-request tests passed offline with invented inputs/mocked transports.
- Original R1 differential test also passed **64 C/Unicorn cases**, comparing
  every register and mapped byte plus CBC chaining/in-place behavior, using an
  invented WCT2 input with random context and zero initial state. No real capture
  was used; successful extracted-key parity is still historical evidence only.
- Original CKC adapter verification passed **128 source/original packet
  comparisons**, 12 invalid-buffer cases, and two null-exchange backend
  rejections. This verifies argument packing/rejection, not successful CKC
  decryption. The copied `ckc_packet.c/.h` are byte-identical to that source.
- Developer provenance check validates every copied C/header/include byte for
  byte against its original and computes exact static hook/coverage metadata:
  `python scripts/audit_closure.py SOURCE_CHECKOUT --output OUTPUT.json`.
- Synthetic source-runtime probes above executed independently of the retained
  harness. They establish dependencies only; they do not establish installed
  package parity for successful SPC/CKC/auth.

Fresh provisioning, elimination of the binary-dependent banks, a minimal live
data-read closure for the successful license case, and parity across additional
catalog pairs remain unverified and unimplemented. No source-only completeness
claim is made for those capabilities.
