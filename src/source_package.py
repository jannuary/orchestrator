"""Locate the vendored ``apple-music-source`` package and its native build."""

from __future__ import annotations

import os
import sys
from pathlib import Path

REPOSITORY_ROOT = Path(__file__).resolve().parents[1]
PACKAGE_ROOT = Path(
    os.environ.get("APPLE_MUSIC_SOURCE_PACKAGE", REPOSITORY_ROOT / "apple-music-source")
).expanduser()
PACKAGE_SOURCE = PACKAGE_ROOT / "src"
NATIVE_DIRECTORY = PACKAGE_SOURCE / "apple_music_source" / "_native"

FPS_LIBRARY = NATIVE_DIRECTORY / "libapple_music_fps_source.so"
CORELSKD_LIBRARY = NATIVE_DIRECTORY / "libcorelskd_r1.so"
R1_PROBE_LIBRARY = NATIVE_DIRECTORY / "r1_probe.so"
REQUIRED_LIBRARIES = (FPS_LIBRARY, CORELSKD_LIBRARY, R1_PROBE_LIBRARY)

BUILD_COMMAND = "python3 scripts/build_source_native.py"


class SourceUnavailable(RuntimeError):
    pass


def ensure_importable() -> None:
    package_source = str(PACKAGE_SOURCE)
    if package_source not in sys.path:
        sys.path.insert(0, package_source)


def missing_libraries() -> list[Path]:
    return [path for path in REQUIRED_LIBRARIES if not path.is_file()]


def require_libraries() -> None:
    missing = missing_libraries()
    if not missing:
        return
    names = ", ".join(str(path) for path in missing)
    raise SourceUnavailable(f"native source libraries are missing ({names}); run {BUILD_COMMAND}")
