"""Dependency-free PEP 517 backend for the source package.

The build compiles the package-owned CoreLSKD translation and bounded protocol primitives.  It
uses the system C compiler and libc, and never fetches or links a vendor SDK.
"""

from __future__ import annotations

import base64
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
import os
import platform
import re
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
DEFAULT_COMPILE_WORKERS = 2
NATIVE_BLOCKS_PER_COMPILE_UNIT = 32
FALLBACK_SOURCE_BYTES_PER_COMPILE_UNIT = 1024 * 1024
FALLBACK_TRACE_FILES = (
    "spc_context.c", "spc_initial.c", "spc_intervening.c",
    "spc_continuation.c", "spc_payload.c",
)
BUILD_STATE_DIRECTORY = ".build-state"
AUTH_OPTIMIZATION_LEVEL = "-O1"
FPS_OPTIMIZATION_LEVEL = "-O1"


class BuildError(RuntimeError):
    pass


def _platform_tag() -> str:
    machine = platform.machine().lower()
    linux_architectures = {
        "x86_64": "x86_64",
        "amd64": "x86_64",
        "aarch64": "aarch64",
        "arm64": "aarch64",
    }
    architecture = linux_architectures.get(machine)
    if sys.platform.startswith("linux") and architecture is not None:
        return f"linux_{architecture}"
    raise BuildError(f"unsupported wheel platform: {sys.platform}/{machine}")


def _run(command: list[str]) -> None:
    try:
        subprocess.run(command, check=True)
    except FileNotFoundError as error:
        raise BuildError("a C compiler is required to build the native library") from error
    except subprocess.CalledProcessError as error:
        raise BuildError(f"native build failed with exit status {error.returncode}") from error


def native_compiler() -> str:
    return os.environ.get("CC") or shutil.which("clang") or "cc"


def _compile_workers() -> int:
    configured_workers = os.environ.get("APPLE_MUSIC_BUILD_JOBS", str(DEFAULT_COMPILE_WORKERS))
    try:
        workers = int(configured_workers)
    except ValueError as error:
        raise BuildError("APPLE_MUSIC_BUILD_JOBS must be a positive integer") from error
    if workers < 1:
        raise BuildError("APPLE_MUSIC_BUILD_JOBS must be a positive integer")
    return min(workers, os.cpu_count() or 1)


def _build_signature(sources: list[Path], options: list[str]) -> str:
    compiler = native_compiler()
    compiler_version = subprocess.check_output([compiler, "--version"])
    digest = hashlib.sha256(compiler_version)
    digest.update(Path(__file__).read_bytes())
    digest.update(json.dumps([shutil.which(compiler), options]).encode())
    dependencies = set(sources)
    dependencies.update(NATIVE.rglob("*.h"))
    dependencies.update(NATIVE.rglob("*.inc"))
    for source in sorted(dependencies):
        digest.update(str(source.relative_to(NATIVE)).encode())
        digest.update(hashlib.sha256(source.read_bytes()).digest())
    return digest.hexdigest()


def _native_page_parts(source: str) -> tuple[str, list[str], str]:
    page = re.fullmatch(
        r"(.*?)(int\s+(\w+)\(unsigned block,([^)]*)\)\s*\{\s*"
        r"NATIVE_LOCALS;\s*switch\s*\(block\)\s*\{)(.*)"
        r"default:return WRAPPER_KG_PAYLOAD_INVALID;\s*\}\s*NATIVE_DONE;\s*\}\s*",
        source,
        re.DOTALL,
    )
    if page is None:
        raise BuildError("unsupported generated native page layout")
    preamble, _, function_name, arguments, body = page.groups()
    blocks = re.split(r"^\s*case (\d+):\s*\n", body, flags=re.MULTILINE)
    if blocks[0].strip():
        raise BuildError(f"unexpected statements before blocks in {function_name}")
    functions: list[str] = []
    declarations: list[str] = []
    dispatch_cases: list[str] = []
    for block_index in range(1, len(blocks), 2):
        block_number = blocks[block_index]
        statements = blocks[block_index + 1].rstrip()
        if not statements.endswith("break;"):
            raise BuildError(f"missing terminal break in {function_name} block {block_number}")
        statements = statements.removesuffix("break;")
        labels = set(re.findall(r"^\s*(\w+):", statements, flags=re.MULTILINE))
        destinations = set(re.findall(r"\bgoto\s+(\w+)", statements))
        if destinations - labels:
            raise BuildError(f"cross-block jump in {function_name} block {block_number}")
        block_function = f"{function_name}_block_{block_number}"
        declaration = f'__attribute__((noinline,visibility("hidden"))) int {block_function}({arguments})'
        declarations.append(declaration + ";\n")
        functions.append(
            declaration + "{\n"
            f"NATIVE_LOCALS;\n(void)regions;(void)count;\n{statements}\nNATIVE_DONE;\n}}\n"
        )
        dispatch_cases.append(
            f"case {block_number}:return {block_function}(bias,fs,regions,count,max_steps);\n"
        )
    dispatch = (
        "".join(declarations) + f"int {function_name}(unsigned block,{arguments}){{\nswitch(block){{\n"
        + "".join(dispatch_cases)
        + "default:fs->cpu.steps=0;return WRAPPER_KG_PAYLOAD_INVALID;}\n}\n"
    )
    return preamble, functions, dispatch


def split_native_page(source: str) -> str:
    preamble, functions, dispatch = _native_page_parts(source)
    return preamble + "".join(functions) + dispatch


def _fallback_compile_units(source: Path, temporary: Path, source_index: int) -> list[Path]:
    contents = source.read_text()
    function = re.search(r"^int (\w+)\((.*?)\)\s*\{", contents, re.MULTILINE | re.DOTALL)
    if function is None:
        raise BuildError(f"missing fallback entry point in {source.name}")
    function_end = contents.index("\n}", function.end()) + len("\n}")
    function_name, arguments = function.groups()
    remaining_arguments = arguments.split(",", 1)[1]
    argument_names = []
    for argument in remaining_arguments.split(","):
        name = re.search(r"(\w+)\s*$", argument)
        if name is None:
            raise BuildError(f"unsupported fallback argument in {source.name}")
        argument_names.append(name[1])
    call_arguments = ",".join(argument_names)
    body = contents[function.end():function_end - 1]
    switch = re.search(r"switch\s*\(path\)\s*\{", body)
    if switch is None:
        raise BuildError(f"missing fallback paths in {source.name}")
    switch_end = body.index("\n#undef STEP", switch.end())
    cases = body[switch.end():switch_end].rstrip()
    if not cases.endswith("}"):
        raise BuildError(f"missing fallback switch end in {source.name}")
    cases = cases[:-1]
    cases = re.sub(
        r'^#include "([^"\n]+)"',
        lambda match: (source.parent / match[1]).read_text(),
        cases, flags=re.MULTILINE,
    )
    blocks = re.split(r"^\s*case (\d+):\s*\n", cases, flags=re.MULTILINE)
    if blocks[0].strip():
        raise BuildError(f"unexpected fallback path preamble in {source.name}")
    preamble = contents[:function.start()]
    functions: list[str] = []
    declarations: list[str] = []
    dispatch: list[str] = []
    for index in range(1, len(blocks), 2):
        path_number = blocks[index]
        statements = blocks[index + 1].rstrip()
        if not statements.endswith("break;"):
            raise BuildError(f"missing fallback path terminator in {source.name}")
        statements = statements.removesuffix("break;")
        labels = set(re.findall(r"^\s*(\w+):", statements, flags=re.MULTILINE))
        destinations = set(re.findall(r"\bgoto\s+(\w+)", statements))
        if destinations - labels:
            raise BuildError(f"cross-path jump in {source.name}")
        path_function = f"{function_name}_path_{path_number}"
        declaration = f'__attribute__((noinline,visibility("hidden"))) int {path_function}({remaining_arguments})'
        declarations.append(declaration + ";\n")
        functions.append(
            declaration + "{\n"
            f"const unsigned path={path_number};\n"
            + body[:switch.start()] + statements + body[switch_end:] + "}\n"
        )
        dispatch.append(f"case {path_number}:return {path_function}({call_arguments});\n")
    dispatcher = (
        "".join(declarations) + f"int {function_name}({arguments}){{\nswitch(path){{\n"
        + "".join(dispatch) + "default:return WRAPPER_KG_PAYLOAD_INVALID;}}\n"
    )
    units = [preamble + dispatcher + contents[function_end:]]
    grouped_functions = ""
    grouped_count = 0
    for path_function in functions:
        if grouped_functions and (
            len(grouped_functions) + len(path_function) > FALLBACK_SOURCE_BYTES_PER_COMPILE_UNIT
            or grouped_count == NATIVE_BLOCKS_PER_COMPILE_UNIT
        ):
            units.append(preamble + grouped_functions)
            grouped_functions = ""
            grouped_count = 0
        grouped_functions += path_function
        grouped_count += 1
    if grouped_functions:
        units.append(preamble + grouped_functions)
    paths = []
    for unit_index, unit in enumerate(units):
        path = temporary / f"{source_index}_fallback_{unit_index}.c"
        path.write_text(unit)
        paths.append(path)
    return paths


def _native_compile_units(source: Path, temporary: Path, source_index: int) -> list[Path]:
    if source.name in FALLBACK_TRACE_FILES:
        return _fallback_compile_units(source, temporary, source_index)
    if "_page_" not in source.stem or source.parent.name not in ("generated", "native_generated", "app_generated"):
        return [source]
    preamble, functions, dispatch = _native_page_parts(source.read_text())
    contents = [preamble + dispatch]
    for start in range(0, len(functions), NATIVE_BLOCKS_PER_COMPILE_UNIT):
        contents.append(preamble + "".join(functions[start:start + NATIVE_BLOCKS_PER_COMPILE_UNIT]))
    paths = []
    for unit_index, content in enumerate(contents):
        path = temporary / f"{source_index}_{unit_index}.c"
        path.write_text(content)
        paths.append(path)
    return paths


def _build_shared_library(
    sources: list[Path],
    output: Path,
    options: list[str],
    source_options_overrides: dict[Path, tuple[str, ...]] | None = None,
) -> Path:
    compiler = native_compiler()
    output.parent.mkdir(parents=True, exist_ok=True)
    source_options_overrides = source_options_overrides or {}
    override_signature = json.dumps({
        source.relative_to(NATIVE).as_posix(): source_options
        for source, source_options in source_options_overrides.items()
    }, sort_keys=True)
    signature = _build_signature(sources, [*options, override_signature])
    state_directory = output.parent / BUILD_STATE_DIRECTORY
    state_file = state_directory / output.name
    if output.is_file() and state_file.is_file():
        try:
            state = json.loads(state_file.read_text())
        except (OSError, ValueError):
            state = {}
        if state.get("signature") == signature and state.get("output") == hashlib.sha256(output.read_bytes()).hexdigest():
            print(f"reusing {output.name}", flush=True)
            return output
    with tempfile.TemporaryDirectory(prefix=f"{output.stem}-", dir=output.parent) as temporary:
        temporary_path = Path(temporary)
        compile_jobs: list[tuple[Path, Path, Path]] = []
        for source_index, source in enumerate(sources):
            for compiled_source in _native_compile_units(source, temporary_path, source_index):
                object_path = temporary_path / f"{len(compile_jobs)}.o"
                compile_jobs.append((source, compiled_source, object_path))

        def compile_source(job: tuple[Path, Path, Path]) -> None:
            source, compiled_source, object_path = job
            source_options = options
            source_override = source_options_overrides.get(source)
            if source_override is not None:
                source_options = [option for option in options if not option.startswith("-O")]
                source_options.extend(source_override)
            _run([compiler, "-std=c99", "-fPIC", *source_options,
                  f"-I{source.parent}", "-c", str(compiled_source), "-o", str(object_path)])

        with ThreadPoolExecutor(max_workers=_compile_workers()) as executor:
            list(executor.map(compile_source, compile_jobs))
        object_paths = [job[2] for job in compile_jobs]
        temporary_output = temporary_path / output.name
        _run([compiler, "-shared", "-Wl,-s", f"-Wl,-soname,{output.name}",
              *map(str, object_paths), "-o", str(temporary_output)])
        temporary_output.replace(output)
    state_directory.mkdir(exist_ok=True)
    state_file.write_text(json.dumps({
        "signature": signature,
        "output": hashlib.sha256(output.read_bytes()).hexdigest(),
    }))
    return output


def build_native(destination: Path) -> Path:
    sources = [NATIVE / (name + ".c") for name in (
        "corelskd_r1", "spc_v2", "ckc_packet", "mt19937",
        "compare_select", "field_copy", "append_bytes", "fill_dispatch", "integrity_codec_data",
        "registry", "control_refs", "abi_layout", "copy_codecs", "auth_word_codecs",
    )]
    return _build_shared_library(sources, destination / LIBRARY,
                                 ["-O2", "-Wall", "-Wextra", f"-I{NATIVE}"])


def build_auth_native(destination: Path) -> tuple[Path, Path]:
    """Compile source-reconstructed CoreADI and Mescal backends."""
    destination.mkdir(parents=True, exist_ok=True)
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
        coreadi_sources,
        coreadi_output,
        ["-Wall", "-Wextra"],
    )
    _build_auth_library(
        mescal_sources,
        mescal_output,
        ["-fvisibility=hidden", "-Wall", "-Wextra", "-Wno-unused-label", "-Wno-misleading-indentation"],
    )
    return coreadi_output, mescal_output


def build_fps_native(destination: Path) -> Path:
    destination.mkdir(parents=True, exist_ok=True)
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
    return _build_shared_library(
        sources, output,
        [FPS_OPTIMIZATION_LEVEL, "-Wall", "-Wextra", f"-I{source_root}"],
        {
            source_root / name: ("-Oz", "-DWRAPPER_KG_COMPACT_ARITHMETIC", "-fno-asynchronous-unwind-tables")
            for name in FALLBACK_TRACE_FILES
        },
    )


def _build_auth_library(
    sources: list[Path],
    output: Path,
    options: list[str],
) -> None:
    _build_shared_library(sources, output, [AUTH_OPTIMIZATION_LEVEL, *options])


def _package_files():
    for path in sorted(PACKAGE.rglob("*")):
        if not path.is_file():
            continue
        relative = path.relative_to(PACKAGE)
        if BUILD_STATE_DIRECTORY in relative.parts or "__pycache__" in relative.parts or path.suffix in (".pyc", ".so", ".o"):
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
    libraries = [build_native(NATIVE), *build_auth_native(NATIVE), build_fps_native(NATIVE)]
    return _package_wheel(Path(wheel_directory), libraries)


def _package_wheel(wheel_directory: Path, libraries: list[Path]) -> str:
    platform_tag = _platform_tag()
    filename = f"{NAME}-{VERSION}-py3-none-{platform_tag}.whl"
    output = Path(wheel_directory) / filename
    output.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="apple-music-source-wheel-") as temporary:
        stage = Path(temporary)
        package = stage / PACKAGE.name
        shutil.copytree(PACKAGE, package, ignore=shutil.ignore_patterns("__pycache__", "*.pyc", "_native"))
        native_destination = package / "_native"
        native_destination.mkdir()
        for library in libraries:
            shutil.copy2(library, native_destination / library.name)
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
                if BUILD_STATE_DIRECTORY in relative.parts or "__pycache__" in relative.parts or path.suffix in (".pyc", ".so", ".o"):
                    continue
                archive.add(path, arcname=f"{root}/{relative.as_posix()}", recursive=False)
    return filename


def build_editable(wheel_directory, config_settings=None, metadata_directory=None):
    raise BuildError("editable installs are not supported; install a built wheel or the sdist")


def get_requires_for_build_editable(config_settings=None):
    return []
