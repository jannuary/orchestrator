#!/usr/bin/env python3
"""Log an Apple Music account into a new source session directory.

The device state directory must contain matching ``adi.pb`` and ``ANDROID_ID``
files (for example a previously saved session). The destination receives the
account databases, device identity, and verified web tokens the orchestrator
uses to fetch playlists and FairPlay keys.

Run the script in a terminal to be prompted for the Apple ID, password and
two-factor code. Pass ``--credentials`` and ``--verification-code-file`` to
run without prompts.
"""

from __future__ import annotations

import argparse
import getpass
import json
import plistlib
import sys
from pathlib import Path

REPOSITORY_ROOT = Path(__file__).resolve().parents[1]
PACKAGE_SOURCE = REPOSITORY_ROOT / "apple-music-source" / "src"
sys.path.insert(0, str(PACKAGE_SOURCE))

from apple_music_source.auth import (
    HttpsTransport,
    SourceLoginClient,
    SourceLoginOutcome,
    load_bag,
)

BAG_URL = "https://init.itunes.apple.com/bag.xml?ix=6"
SOURCE_USER_AGENT = "Music/5.0.2 Android/10 model/Pixel 8 build/7663314 (dt:66)"
DEFAULT_STOREFRONT = "143480-2,31"
DEFAULT_CREDENTIALS = Path.home() / ".config" / "apple-music-source" / "credentials.json"
REQUEST_TIMEOUT_SECONDS = 45.0
VERIFICATION_CODE_ATTEMPTS = 3


def load_or_fetch_bag(transport: HttpsTransport, bag_file: Path | None):
    if bag_file is not None and bag_file.is_file():
        return load_bag(bag_file)
    response = transport.get(
        BAG_URL,
        {"User-Agent": SOURCE_USER_AGENT, "Content-Type": "application/x-apple-plist"},
        timeout=REQUEST_TIMEOUT_SECONDS,
    )
    if response.status != 200:
        raise SystemExit(f"URL bag request failed with HTTP {response.status}")
    if bag_file is not None:
        bag_file.write_bytes(response.body)
    return plistlib.loads(response.body)


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


def authenticate(
    client: SourceLoginClient,
    username: str,
    password: str,
    verification_code_file: Path | None,
) -> SourceLoginOutcome:
    if verification_code_file is not None:
        return client.authenticate(
            username=username,
            password=password,
            verification_code=verification_code_file.read_text().strip(),
            acquire_web_tokens=True,
        )
    outcome = client.authenticate(
        username=username, password=password, acquire_web_tokens=True
    )
    for _ in range(VERIFICATION_CODE_ATTEMPTS):
        if outcome.session_saved or not outcome.verification_required:
            break
        outcome = client.submit_verification_code(
            username=username,
            password=password,
            code=prompt_verification_code(),
            acquire_web_tokens=True,
        )
    return outcome


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
    if arguments.session.exists():
        raise SystemExit(f"session destination already exists: {arguments.session}")
    username, password = read_credentials(arguments.credentials)
    arguments.session.parent.mkdir(parents=True, exist_ok=True)
    transport = HttpsTransport()
    bag = load_or_fetch_bag(transport, arguments.bag)
    with SourceLoginClient(
        device_state=arguments.device_state,
        destination=arguments.session,
        bag=bag,
        transport=transport,
        storefront=arguments.storefront,
    ) as client:
        outcome = authenticate(
            client, username, password, arguments.verification_code_file
        )
    report = {
        "status": "logged_in" if outcome.session_saved else "login_failed",
        "verification_required": bool(outcome.verification_required),
        "session_saved": outcome.session_saved,
        "token_verification": dict(outcome.token_verification or {}),
    }
    print(json.dumps(report, sort_keys=True))
    if not outcome.session_saved:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
