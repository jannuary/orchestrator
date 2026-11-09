#!/usr/bin/env python3
"""Build the vendored source package's native libraries and the R1 probe.

The probe is a read-only observer of the source runtime's key-entry step. It
is loaded before the FPS library so its page implementation interposes; it
records the context, chaining state and entry registers the orchestrator needs
to decrypt samples and never writes runtime state.
"""

from __future__ import annotations

import hashlib
import os
import subprocess
import sys
import tempfile
from pathlib import Path

REPOSITORY_ROOT = Path(__file__).resolve().parents[1]
PACKAGE_ROOT = REPOSITORY_ROOT / "apple-music-source"
PACKAGE_SOURCE = PACKAGE_ROOT / "src"
NATIVE_DIRECTORY = PACKAGE_SOURCE / "apple_music_source" / "_native"
KEYGEN_DIRECTORY = NATIVE_DIRECTORY / "keygen_experimental"
R1_PAGE = KEYGEN_DIRECTORY / "native_generated" / "block_page_1d.c"
R1_LABEL = "kg_pc_1d5709: STEP(0x1d5709);"
R1_PROBE_SOURCE = """#include "spc_native_internal.h"
#include <string.h>

static unsigned char probe_context[0x8000];
static unsigned char probe_state[0x2100];
static uint64_t probe_rax;
static uint64_t probe_rcx;
static int probe_armed;
static int probe_status;

void wrapper_kg_r1_probe_clear(void) {
    volatile unsigned char *cursor;
    size_t index;
    for (index = 0, cursor = probe_context; index < sizeof probe_context; ++index) {
        cursor[index] = 0;
    }
    for (index = 0, cursor = probe_state; index < sizeof probe_state; ++index) {
        cursor[index] = 0;
    }
    probe_rax = probe_rcx = 0;
    probe_armed = probe_status = 0;
}

void wrapper_kg_r1_probe_arm(void) {
    wrapper_kg_r1_probe_clear();
    probe_armed = 1;
}

static void probe_capture(const wrapper_kg_native_state *state,
                          const wrapper_kg_payload_region *regions,
                          size_t count) {
    const wrapper_kg_payload_state *cpu = &state->cpu;
    const unsigned char *context;
    const unsigned char *stack;
    if (!probe_armed || probe_status || (cpu->gpr[4] & 255) != 8) {
        return;
    }
    probe_status = -1;
    if (cpu->gpr[6] < 0x2000 || cpu->gpr[0] > 255 || cpu->gpr[2] > 255 ||
        !kg_shadow_read_allowed(state, cpu->gpr[9], sizeof probe_context) ||
        !kg_shadow_read_allowed(state, cpu->gpr[6] - 0x2000, sizeof probe_state)) {
        return;
    }
    context = translate(regions, count, cpu->gpr[9], sizeof probe_context, 1);
    stack = translate(regions, count, cpu->gpr[6] - 0x2000, sizeof probe_state, 1);
    if (!context || !stack) {
        return;
    }
    memcpy(probe_context, context, sizeof probe_context);
    memcpy(probe_state, stack, sizeof probe_state);
    probe_rax = cpu->gpr[0];
    probe_rcx = cpu->gpr[2];
    probe_status = 1;
}

int wrapper_kg_r1_probe_copy(unsigned char *context, unsigned char *state,
                             uint64_t *rax, uint64_t *rcx) {
    if (probe_status != 1) {
        return probe_status;
    }
    if (!context || !state || !rax || !rcx) {
        return -1;
    }
    memcpy(context, probe_context, sizeof probe_context);
    memcpy(state, probe_state, sizeof probe_state);
    *rax = probe_rax;
    *rcx = probe_rcx;
    return 1;
}
"""


def build_native_libraries() -> None:
    sys.path.insert(0, str(PACKAGE_ROOT))
    import build_backend

    print("building CoreLSKD bundle", flush=True)
    build_backend.build_native(NATIVE_DIRECTORY)
    print("building CoreADI and Mescal", flush=True)
    build_backend.build_auth_native(NATIVE_DIRECTORY)
    print("building FPS runtime", flush=True)
    build_backend.build_fps_native(NATIVE_DIRECTORY)


def build_r1_probe() -> Path:
    sys.path.insert(0, str(PACKAGE_ROOT))
    import build_backend

    output = NATIVE_DIRECTORY / "r1_probe.so"
    signature = build_backend._build_signature(
        [R1_PAGE], [R1_PROBE_SOURCE, "-O2", "-Wl,-s",
                    hashlib.sha256((NATIVE_DIRECTORY / build_backend.FPS_LIBRARY).read_bytes()).hexdigest()],
    )
    state_file = NATIVE_DIRECTORY / build_backend.BUILD_STATE_DIRECTORY / output.name
    if output.is_file() and state_file.is_file():
        output_signature = hashlib.sha256(output.read_bytes()).hexdigest()
        if state_file.read_text() == signature + output_signature:
            print("reusing r1_probe.so", flush=True)
            return output
    page = R1_PAGE.read_text()
    if page.count(R1_LABEL) != 1:
        raise SystemExit(f"key entry label not found once in {R1_PAGE}")
    page = page.replace('#include "../spc_native_internal.h"', "", 1)
    page = page.replace(R1_LABEL, R1_LABEL + " probe_capture(fs,regions,count);", 1)
    compiler = os.environ.get("CC", "cc")
    with tempfile.TemporaryDirectory(prefix="r1-probe-", dir=NATIVE_DIRECTORY) as temporary:
        source = Path(temporary) / "probe.c"
        temporary_output = Path(temporary) / output.name
        source.write_text(R1_PROBE_SOURCE + page)
        subprocess.run(
            [
                compiler,
                "-shared",
                "-fPIC",
                "-O2",
                "-Wl,-s",
                f"-I{KEYGEN_DIRECTORY}",
                f"-I{NATIVE_DIRECTORY}",
                str(source),
                f"-L{NATIVE_DIRECTORY}",
                "-l:libapple_music_fps_source.so",
                "-Wl,-rpath,$ORIGIN",
                "-o",
                str(temporary_output),
            ],
            check=True,
        )
        temporary_output.replace(output)
    state_file.parent.mkdir(exist_ok=True)
    state_file.write_text(signature + hashlib.sha256(output.read_bytes()).hexdigest())
    return output


def main() -> None:
    build_native_libraries()
    print(f"built R1 probe {build_r1_probe()}", flush=True)


if __name__ == "__main__":
    main()
