"""Dependency-free PEP 517 backend for the source package.

The build compiles the package-owned CoreLSKD translation and bounded protocol primitives.  It
uses the system C compiler and libc, and never fetches or links a vendor SDK.
"""

from __future__ import annotations

import base64
from concurrent.futures import ThreadPoolExecutor
import hashlib
import os
import platform
import shutil
import subprocess
import sys
import tarfile
import tempfile
import zipfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent
SRC = ROOT / "src"
PACKAGE = SRC / "apple_music_source"
NATIVE = PACKAGE / "_native"
NAME = "apple_music_source"
DIST = "apple-music-source"
VERSION = "0.1.0"
DIST_INFO = f"{NAME}-{VERSION}.dist-info"
LIBRARY = "libcorelskd_r1.so"
COREADI_LIBRARY = "libcoreadi_source.so"
MESCAL_LIBRARY = "libmescal_source.so"
FPS_LIBRARY = "libapple_music_fps_source.so"
AUTH_COMPILE_WORKERS = 2
AUTH_OPTIMIZATION_LEVEL = "-O1"


class BuildError(RuntimeError):
    pass


def _platform_tag() -> str:
    if sys.platform.startswith("linux") and platform.machine().lower() in ("x86_64", "amd64"):
        return "linux_x86_64"
    raise BuildError(
        "this package currently builds a Linux x86_64 wheel only; "
        "the C sources are portable, but no other platform is verified"
    )


def _run(command: list[str]) -> None:
    try:
        subprocess.run(command, check=True)
    except FileNotFoundError as error:
        raise BuildError("a C compiler is required to build the native library") from error
    except subprocess.CalledProcessError as error:
        raise BuildError(f"native build failed with exit status {error.returncode}") from error


def build_native(destination: Path) -> Path:
    """Compile the package-owned C source into ``destination``."""
    destination.mkdir(parents=True, exist_ok=True)
    compiler = os.environ.get("CC", "cc")
    output = destination / LIBRARY
    _run([
        compiler,
        "-std=c99",
        "-O2",
        "-fPIC",
        "-shared",
        "-Wall",
        "-Wextra",
        f"-I{NATIVE}",
        f"-Wl,-soname,{LIBRARY}",
        *[str(NATIVE / (name + ".c")) for name in (
            "corelskd_r1", "spc_v2", "ckc_packet", "mt19937",
            "compare_select", "field_copy", "append_bytes", "fill_dispatch", "integrity_codec_data", "registry", "control_refs", "abi_layout", "copy_codecs", "auth_word_codecs",
        )],
        "-o",
        str(output),
    ])
    return output


def build_auth_native(destination: Path) -> tuple[Path, Path]:
    """Compile source-reconstructed CoreADI and Mescal backends."""
    destination.mkdir(parents=True, exist_ok=True)
    compiler = os.environ.get("CC", "cc")
    coreadi = NATIVE / "auth" / "coreadi"
    mescal = NATIVE / "auth" / "mescal"
    coreadi_output = destination / COREADI_LIBRARY
    mescal_output = destination / MESCAL_LIBRARY
    coreadi_sources = [coreadi / "coreadi.c"]
    coreadi_sources.extend(sorted((coreadi / "generated").glob("*_page_*.c")))
    coreadi_sources.extend(sorted((coreadi / "generated").glob("image_*.c")))
    mescal_sources = [mescal / "mescal.c", mescal / "mescal_integrity.c"]
    mescal_sources.extend(sorted((mescal / "generated").glob("mescal_*.c")))
    _build_auth_library(
        compiler,
        coreadi_sources,
        coreadi_output,
        "coreadi",
        ["-Wall", "-Wextra"],
    )
    _build_auth_library(
        compiler,
        mescal_sources,
        mescal_output,
        "mescal",
        ["-fvisibility=hidden", "-Wall", "-Wextra", "-Wno-unused-label", "-Wno-misleading-indentation"],
    )
    return coreadi_output, mescal_output


def build_fps_native(destination: Path) -> Path:
    destination.mkdir(parents=True, exist_ok=True)
    compiler = os.environ.get("CC", "cc")
    source_root = NATIVE / "keygen_experimental"
    generated_sources = []
    for directory, pattern in (
        ("native_generated", "block_*.c"),
        ("app_generated", "block_*.c"),
        ("integrity_generated", "table_*.c"),
        ("ckc_integrity_generated", "ckc_integrity_table_*.c"),
    ):
        generated_sources.extend(sorted((source_root / directory).glob(pattern)))
    sources = [source_root / name for name in (
        "append_bytes.c", "ckc_integrity.c", "ckc_packet.c", "compare_select.c",
        "field_copy.c", "spc_context.c", "spc_continuation.c", "spc_generate.c",
        "spc_graph.c", "spc_initial.c", "spc_integrity.c", "spc_intervening.c",
        "spc_native.c", "spc_native_lookup.c", "spc_payload.c",
    )]
    sources.extend(generated_sources)
    output = destination / FPS_LIBRARY
    with tempfile.TemporaryDirectory(prefix="apple-music-source-fps-") as temporary:
        temporary_path = Path(temporary)
        object_paths = [temporary_path / f"{index}.o" for index in range(len(sources))]

        def compile_source(source_and_object: tuple[Path, Path]) -> None:
            source, object_path = source_and_object
            _run([
                compiler, "-std=c99", "-O0", "-fPIC", "-Wall", "-Wextra",
                f"-I{source_root}", "-c", str(source), "-o", str(object_path),
            ])

        with ThreadPoolExecutor(max_workers=min(AUTH_COMPILE_WORKERS, os.cpu_count() or 1)) as executor:
            list(executor.map(compile_source, zip(sources, object_paths)))
        _run([compiler, "-shared", *[str(object_path) for object_path in object_paths], "-o", str(output)])
    return output


def _build_auth_library(
    compiler: str,
    sources: list[Path],
    output: Path,
    name: str,
    options: list[str],
) -> None:
    with tempfile.TemporaryDirectory(prefix=f"apple-music-source-{name}-") as temporary:
        temporary_path = Path(temporary)
        object_paths = [temporary_path / f"{index}.o" for index in range(len(sources))]

        def compile_source(source_and_object: tuple[Path, Path]) -> None:
            source, object_path = source_and_object
            _run([
                compiler,
                "-std=c99",
                AUTH_OPTIMIZATION_LEVEL,
                "-fPIC",
                *options,
                "-c",
                str(source),
                "-o",
                str(object_path),
            ])

        with ThreadPoolExecutor(max_workers=min(AUTH_COMPILE_WORKERS, os.cpu_count() or 1)) as executor:
            list(executor.map(compile_source, zip(sources, object_paths)))
        _run([
            compiler,
            "-shared",
            *[str(object_path) for object_path in object_paths],
            "-o",
            str(output),
        ])


def _package_files():
    for path in sorted(PACKAGE.rglob("*")):
        if not path.is_file():
            continue
        relative = path.relative_to(PACKAGE)
        if "__pycache__" in relative.parts or path.suffix in (".pyc", ".so", ".o"):
            continue
        yield path, relative


def _metadata() -> bytes:
    readme = (ROOT / "README.md").read_text(encoding="utf-8")
    return (
        "Metadata-Version: 2.1\n"
        f"Name: {DIST}\n"
        f"Version: {VERSION}\n"
        "Summary: Source Apple Music crypto and authentication helpers\n"
        "License: MIT\n"
        "Requires-Python: >=3.10\n"
        "Description-Content-Type: text/markdown\n"
        "Classifier: Programming Language :: Python :: 3\n"
        "Classifier: Operating System :: POSIX :: Linux\n"
        "Classifier: Topic :: Security :: Cryptography\n"
        "\n" + readme
    ).encode("utf-8")


def _wheel_metadata() -> bytes:
    return (
        "Wheel-Version: 1.0\n"
        "Generator: apple-music-source-build-backend\n"
        "Root-Is-Purelib: false\n"
        f"Tag: py3-none-{_platform_tag()}\n"
    ).encode("ascii")


def prepare_metadata_for_build_wheel(metadata_directory, config_settings=None):
    directory = Path(metadata_directory) / DIST_INFO
    directory.mkdir(parents=True, exist_ok=True)
    (directory / "METADATA").write_bytes(_metadata())
    (directory / "WHEEL").write_bytes(_wheel_metadata())
    return DIST_INFO


def get_requires_for_build_wheel(config_settings=None):
    return []


def get_requires_for_build_sdist(config_settings=None):
    return []


def _record_line(relative: str, data: bytes) -> str:
    digest = base64.urlsafe_b64encode(hashlib.sha256(data).digest()).rstrip(b"=").decode("ascii")
    return f"{relative},sha256={digest},{len(data)}"


def build_wheel(wheel_directory, config_settings=None, metadata_directory=None):
    platform_tag = _platform_tag()
    filename = f"{NAME}-{VERSION}-py3-none-{platform_tag}.whl"
    output = Path(wheel_directory) / filename
    output.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="apple-music-source-wheel-") as temporary:
        stage = Path(temporary)
        package = stage / PACKAGE.name
        shutil.copytree(PACKAGE, package, ignore=shutil.ignore_patterns("__pycache__", "*.pyc", "*.so", "*.o"))
        build_native(package / "_native")
        build_auth_native(package / "_native")
        build_fps_native(package / "_native")
        info = stage / DIST_INFO
        info.mkdir()
        metadata = _metadata()
        wheel = _wheel_metadata()
        (info / "METADATA").write_bytes(metadata)
        (info / "WHEEL").write_bytes(wheel)
        files = []
        records = []
        for path in sorted(package.rglob("*")):
            if path.is_file():
                relative = path.relative_to(stage).as_posix()
                files.append(path)
                records.append(_record_line(relative, path.read_bytes()))
        for name, data in (("METADATA", metadata), ("WHEEL", wheel)):
            files.append(info / name)
            records.append(_record_line(f"{DIST_INFO}/{name}", data))
        records.append(f"{DIST_INFO}/RECORD,,")
        (info / "RECORD").write_text("\n".join(records) + "\n", encoding="ascii")
        files.append(info / "RECORD")
        with zipfile.ZipFile(output, "w", compression=zipfile.ZIP_DEFLATED) as archive:
            for path in files:
                archive.write(path, path.relative_to(stage).as_posix())
    return filename


def build_sdist(sdist_directory, config_settings=None):
    filename = f"{DIST}-{VERSION}.tar.gz"
    output = Path(sdist_directory) / filename
    output.parent.mkdir(parents=True, exist_ok=True)
    root = f"{DIST}-{VERSION}"
    includes = [ROOT / "pyproject.toml", ROOT / "README.md", ROOT / "LICENSE",
                ROOT / "build_backend.py", SRC, ROOT / "tests", ROOT / "scripts"]
    with tarfile.open(output, "w:gz") as archive:
        for item in includes:
            if not item.exists():
                continue
            if item.is_file():
                archive.add(item, arcname=f"{root}/{item.name}", recursive=False)
                continue
            for path in sorted(item.rglob("*")):
                if not path.is_file():
                    continue
                relative = path.relative_to(ROOT)
                if "__pycache__" in relative.parts or path.suffix in (".pyc", ".so", ".o"):
                    continue
                archive.add(path, arcname=f"{root}/{relative.as_posix()}", recursive=False)
    return filename


def build_editable(wheel_directory, config_settings=None, metadata_directory=None):
    raise BuildError("editable installs are not supported; install a built wheel or the sdist")


def get_requires_for_build_editable(config_settings=None):
    return []
