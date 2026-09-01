"""Python implementation of the Apple Music ALAC/SAMPLE-AES decryption service.

Serves a track decrypted from Encrypted DASH/ffmpeg HLS given an ``adamId``,
by talking to an existing local "wrapper-lite" server (the same one the Go
downloader consumes) that provides the ``/m3u8`` and ``/key`` endpoints.
"""

from .lite import LiteClient, LiteError
from .playlist import (MediaPlaylist, MediaSegment, PlaylistError,
                        load_media_playlist, load_media_playlist_text,
                        select_alac_media_url, select_media_url, valid_qualities)
from .decrypt import DecryptError, decrypt_track, decrypt_track_streaming

PipelineError = DecryptError

__all__ = [
    "LiteClient", "MediaPlaylist", "MediaSegment",
    "load_media_playlist", "load_media_playlist_text",
    "select_alac_media_url", "select_media_url", "valid_qualities",
    "decrypt_track", "decrypt_track_streaming",
    "PipelineError", "LiteError", "PlaylistError", "DecryptError",
]
