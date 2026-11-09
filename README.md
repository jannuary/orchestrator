# orchestrator

HTTP service that serves Apple Music ALAC ("hi-res lossless") tracks as
decrypted `.m4a` files. It runs standalone: account login, tokens, playlist
resolution, FairPlay key exchange and sample decryption all come from the
in-tree [`apple-music-source`](apple-music-source) package. No wrapper
checkout or lite-server is involved.

## Requirements

- Linux x86_64 with a C compiler (`cc`) for the source package's native build
- Python 3.10+
- `m3u8` (see `pyproject.toml`)

## Setup

Build the native source libraries and the key-capture probe once per checkout
(the generated C is large, so this takes a few minutes):

```sh
python3 scripts/build_source_native.py
```

Log an account into a session directory. The device state directory must
contain matching device identity files (`adi.pb`, `ANDROID_ID`); a previously
saved session works:

```sh
python3 scripts/source_login.py \
    --device-state /path/to/device-state \
    --session /path/to/session
```

Run the script in a terminal to be prompted for the Apple ID, password and
two-factor code; it also reads
`~/.config/apple-music-source/credentials.json` by default. The same login is
available over HTTP once the server is running (see `POST /login` below).

## Run

```sh
python3 server.py --session /path/to/session \
    --device-state /path/to/device-state
```

`--session` may point at a directory that does not exist yet; the server then
starts unauthenticated and `POST /login` creates it. `--device-state` defaults
to `--session` and must contain the `adi.pb` / `ANDROID_ID` pair used by a
login.

The FairPlay certificate defaults to [`certs/fps-certificate.bin`](certs)
(Apple's public FPS1 certificate); override with `--certificate`.

### Endpoints

- `POST /login` — two-phase account login. Send `X-Apple-User` and
  `X-Apple-Password`; if Apple asks for a two-factor code the reply is `401`
  `{"status": "2fa_required"}`, and reposting the same headers plus
  `X-Apple-2FA-Code` finishes the login and writes the session directory.
  Successful logins return `200` with the storefront.
- `GET /token` — the session's `dev_token`, `music_token` and storefront, in
  the wrapper's `{"code", "msg", "data"}` envelope, so clients can adopt them
  for Apple Music API calls.
- `GET /key?adamId=<id>&uri=<skd://...>` — the CoreLSKD material for one
  catalog FairPlay key URI (`ctx`, `state`, `rax`, `rcx`), also in the
  wrapper's envelope. Used by clients that decrypt HLS segments themselves.
  Live-radio `skd://linear/` keys are not served.
- `GET /decrypt/<adamId>?quality=alac` — stream a decrypted track. `quality`
  accepts `hires`, `alac`, `256`, `128`, `64`; the closest available tier is
  used. `Range: bytes=...` is honoured. Returns `503` until a login exists.
- `GET /healthz` — liveness probe.

Example login:

```sh
curl -i -X POST http://127.0.0.1:8123/login \
    -H 'X-Apple-User: you@example.com' \
    -H 'X-Apple-Password: secret'
curl -i -X POST http://127.0.0.1:8123/login \
    -H 'X-Apple-User: you@example.com' \
    -H 'X-Apple-Password: secret' \
    -H 'X-Apple-2FA-Code: 123456'
```

The session directory may also be supplied with
`APPLE_MUSIC_SOURCE_SESSION`. For an installed copy, point
`APPLE_MUSIC_SOURCE_PACKAGE` at the vendored package root.

## Layout

- `src/source.py` — source client: catalog playlist, FairPlay key captures
- `src/login.py` — two-phase `/login` (credentials, then two-factor code)
- `src/keys.py` — per-key CoreLSKD decryption material
- `src/decrypt.py` — fMP4 `cbcs` sample decryption and reassembly
- `src/playlist.py` — master/media playlist selection
- `scripts/build_source_native.py` — native build plus R1 probe
- `scripts/source_login.py` — account login and token acquisition
- `apple-music-source/` — vendored source package (see its README and AUDIT)
