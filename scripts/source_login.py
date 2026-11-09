#!/usr/bin/env python3
"""Log an Apple Music account into a source session directory.

The device state directory must contain matching ``adi.pb`` and ``ANDROID_ID``
files (for example a previously saved session). The destination receives the
account databases, device identity, and verified web tokens the orchestrator
uses to fetch playlists and FairPlay keys; an existing destination is replaced.

Run the script in a terminal to be prompted for the Apple ID, password and
two-factor code. Pass ``--credentials`` and ``--verification-code-file`` to
run without prompts. The same login is available over ``POST /login``.
"""

from __future__ import annotations

import argparse
import getpass
import json
import sys
from pathlib import Path

REPOSITORY_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPOSITORY_ROOT))

from src.login import DEFAULT_STOREFRONT, LoginError, LoginManager

VERIFICATION_CODE_ATTEMPTS = 3
DEFAULT_CREDENTIALS = Path.home() / ".config" / "apple-music-source" / "credentials.json"


def read_credentials(credentials_file: Path) -> tuple[str, str]:
    if credentials_file.is_file():
        stored = json.loads(credentials_file.read_text())
        return stored["username"], stored["password"]
    if not sys.stdin.isatty():
        raise SystemExit(
            f"no credentials file at {credentials_file}; "
            "pass --credentials or run in a terminal to be prompted"
        )
    username = input("Apple ID: ").strip()
    password = getpass.getpass("Password: ")
    if not username or not password:
        raise SystemExit("Apple ID and password are required")
    return username, password


def prompt_verification_code() -> str:
    if not sys.stdin.isatty():
        raise SystemExit(
            "Apple requires a two-factor code; pass --verification-code-file "
            "or run in a terminal to be prompted"
        )
    print("Apple sent a two-factor code to your devices.", file=sys.stderr)
    return input("Two-factor code: ").strip()


def parse_arguments() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--device-state", type=Path, required=True)
    parser.add_argument("--session", type=Path, required=True)
    parser.add_argument("--credentials", type=Path, default=DEFAULT_CREDENTIALS)
    parser.add_argument("--bag", type=Path)
    parser.add_argument("--storefront", default=DEFAULT_STOREFRONT)
    parser.add_argument("--verification-code-file", type=Path)
    return parser.parse_args()


def main() -> None:
    arguments = parse_arguments()
    username, password = read_credentials(arguments.credentials)
    verification_code = None
    if arguments.verification_code_file is not None:
        verification_code = arguments.verification_code_file.read_text().strip()
    manager = LoginManager(
        session_directory=arguments.session,
        device_state=arguments.device_state,
        storefront=arguments.storefront,
        bag_file=arguments.bag,
    )
    try:
        result = manager.authenticate(username, password, verification_code)
        if verification_code is None:
            for _ in range(VERIFICATION_CODE_ATTEMPTS):
                if result.session_saved or not result.verification_required:
                    break
                result = manager.authenticate(
                    username, password, prompt_verification_code()
                )
    except LoginError as error:
        raise SystemExit(f"login failed: {error}")
    finally:
        manager.close()
    report = {
        "status": "logged_in" if result.session_saved else "login_failed",
        "verification_required": bool(result.verification_required),
        "session_saved": result.session_saved,
        "storefront": result.storefront,
    }
    print(json.dumps(report, sort_keys=True))
    if not result.session_saved:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
