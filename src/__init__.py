"""Python implementation of the Apple Music ALAC/SAMPLE-AES decryption service.

Serves a track decrypted from its Apple enhanced-HLS asset given an
``adamId``, using the vendored source package for session tokens, the master
playlist, and FairPlay key captures.
"""

from .keys import KeyMaterial
from .playlist import (MediaPlaylist, MediaSegment, PlaylistError,
                        load_media_playlist, load_media_playlist_text,
                        select_alac_media_url, select_media_url, valid_qualities)
from .decrypt import (DecryptError, DecryptedTrack, decrypt_track,
                      decrypt_track_streaming)
from .source import SourceClient, SourceError, SourceUnavailable

PipelineError = DecryptError

__all__ = [
    "KeyMaterial", "SourceClient", "SourceError", "SourceUnavailable",
    "MediaPlaylist", "MediaSegment",
    "load_media_playlist", "load_media_playlist_text",
    "select_alac_media_url", "select_media_url", "valid_qualities",
    "decrypt_track", "decrypt_track_streaming", "DecryptedTrack",
    "PipelineError", "PlaylistError", "DecryptError",
]
