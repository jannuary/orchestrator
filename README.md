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

Credentials are read from `~/.config/apple-music-source/credentials.json`
(`{"username": ..., "password": ...}`) unless `--credentials` is given.

## Run

```sh
python3 server.py --session /path/to/session
```

The FairPlay certificate defaults to [`certs/fps-certificate.bin`](certs)
(Apple's public FPS1 certificate); override with `--certificate`.

### Endpoints

- `GET /decrypt/<adamId>?quality=alac` — stream a decrypted track. `quality`
  accepts `hires`, `alac`, `256`, `128`, `64`; the closest available tier is
  used. `Range: bytes=...` is honoured.
- `GET /healthz` — liveness probe.

The session directory may also be supplied with
`APPLE_MUSIC_SOURCE_SESSION`. For an installed copy, point
`APPLE_MUSIC_SOURCE_PACKAGE` at the vendored package root.

## Layout

- `src/source.py` — source client: catalog playlist, FairPlay key captures
- `src/keys.py` — per-key CoreLSKD decryption material
- `src/decrypt.py` — fMP4 `cbcs` sample decryption and reassembly
- `src/playlist.py` — master/media playlist selection
- `scripts/build_source_native.py` — native build plus R1 probe
- `scripts/source_login.py` — account login and token acquisition
- `apple-music-source/` — vendored source package (see its README and AUDIT)
