# provision_loader

In-tree C-ABI shim around [Dadoum/Provision][provision] so the Python side can
load Apple's `libstoreservicescore.so` from `apple-music-source/vendor/`
through Provision's in-process bionic ELF loader and drive full CoreADI
provisioning without a separate daemon.

## Layout

- `source/shim.d` — extern(C) wrapper exposing the CoreADI operations we call
  from Python.
- `vendor/` — snapshot of Dadoum/Provision's `lib/`, under LGPL-2.1
  (see `vendor/COPYING-LGPLv2`). The upstream `provision/adi.d` carries one
  small patch so it compiles against current Phobos:
  `request.headers["X-Apple-I-Client-Time"] = ...`
  becomes
  `request.addHeaders(["X-Apple-I-Client-Time": ...])`.
- `dub.sdl` — the shim package; produces `build/libams_provision.so`.
- `.gitignore` — excludes `build/` and the dub cache.

## Build

Requires `ldc2` and `dub` (on Fedora: `dnf install ldc dub`).

```
dub build --build=release
```

First build fetches `requests`, `slf4d`, and the pinned `plist-d` through dub.

## Python binding

`apple_music_source.auth.provision_source.ProvisionCoreADI` ctypes-binds the
emitted `libams_provision.so` and implements the `CoreADI` protocol, so it is
a drop-in backend for `AdiProvisioning`.

[provision]: https://github.com/Dadoum/Provision
