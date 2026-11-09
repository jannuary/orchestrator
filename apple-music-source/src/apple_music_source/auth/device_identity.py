"""Source derivation and formatting of the native Android GUID and DeviceID.

This module never assumes that an Android identifier is itself the native GUID,
loads a vendor SDK, or fabricates available hardware fields.
"""
from __future__ import annotations

from dataclasses import dataclass, field
import hashlib
import struct
from pathlib import Path
from typing import Optional

_IFCONF_REQUEST = 0x8912
_IF_FLAGS_REQUEST = 0x8913
_IF_HARDWARE_ADDRESS_REQUEST = 0x8927
_IFCONF_BUFFER_BYTES = 1024
_IFREQ_NAME_BYTES = 16
_IFREQ_DATA_BYTES = 24
_IFREQ_RECORD_BYTES = 40
_IFREQ_FLAGS_OFFSET = 16
_IFREQ_HARDWARE_TYPE_OFFSET = 16
_IFREQ_HARDWARE_ADDRESS_OFFSET = 18
_IFF_LOOPBACK = 8
_ARPHRD_ETHER = 1
_MAC_ADDRESS_BYTES = 6
_IFCONF_PACK_FORMAT = '<i4xQ'
_UNSIGNED_SHORT_FORMAT = '<H'
_UNSIGNED_INTEGER_FORMAT = '<I'


class NativeGUIDProviderUnavailable(NotImplementedError):
    """The configured source provider could not derive native GUID fields."""


def derive_android_guid_mac_field(mac: bytes) -> bytes:
    """Derive the seven-byte MAC field from exactly six raw MAC bytes.

    The recovered native path hashes the raw MAC followed by a documented
    static 32-byte protocol suffix, then takes the first seven SHA-1 bytes.
    This supplies the MAC field only. ``derive_android_guid_fields`` runs the
    complete source Mescal GUID provider for both fields.
    """
    from ._guid_mac_parameters import SHA1_SUFFIX

    if not isinstance(mac, bytes) or len(mac) != 6:
        raise ValueError('MAC must contain exactly six raw bytes')
    return hashlib.sha1(mac + SHA1_SUFFIX).digest()[:7]


def derive_android_guid_fields(
    android_id: bytes,
    mac_address: bytes,
    *,
    system_serial: bytes = b'',
    library: Path | None = None,
) -> AndroidGUIDFields:
    """Configure AndroidID, then derive native fields with the selected MAC."""
    from .mescal_source import SourceMescal

    descriptor = SourceMescal.guid_descriptor(
        android_id,
        mac_address,
        serial=system_serial,
        library=library,
    )
    return decode_android_guid_fields(descriptor)


def local_hardware_mac() -> bytes:
    """Read the first non-loopback IPv4 Ethernet interface on Linux."""
    import array
    import fcntl
    import socket
    import sys

    if not sys.platform.startswith('linux') or struct.calcsize('P') != struct.calcsize('Q'):
        raise NotImplementedError('local GUID profile requires 64-bit Linux')
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as interface_socket:
        records = array.array('B', bytes(_IFCONF_BUFFER_BYTES))
        address, _ = records.buffer_info()
        result = fcntl.ioctl(
            interface_socket.fileno(),
            _IFCONF_REQUEST,
            struct.pack(_IFCONF_PACK_FORMAT, len(records), address),
        )
        size = struct.unpack_from(_UNSIGNED_INTEGER_FORMAT, result)[0]
        if size > len(records) or size % _IFREQ_RECORD_BYTES:
            raise ValueError('unsupported local interface snapshot')
        for offset in range(0, size, _IFREQ_RECORD_BYTES):
            name = records[offset:offset + _IFREQ_NAME_BYTES].tobytes().split(b'\0')[0]
            request = struct.pack(f'{_IFREQ_NAME_BYTES}s{_IFREQ_DATA_BYTES}x', name)
            flags = struct.unpack_from(
                _UNSIGNED_SHORT_FORMAT,
                fcntl.ioctl(interface_socket.fileno(), _IF_FLAGS_REQUEST, request),
                _IFREQ_FLAGS_OFFSET,
            )[0]
            if flags & _IFF_LOOPBACK:
                continue
            hardware = fcntl.ioctl(interface_socket.fileno(), _IF_HARDWARE_ADDRESS_REQUEST, request)
            hardware_type = struct.unpack_from(
                _UNSIGNED_SHORT_FORMAT,
                hardware,
                _IFREQ_HARDWARE_TYPE_OFFSET,
            )[0]
            if hardware_type != _ARPHRD_ETHER:
                raise ValueError('selected local interface is not Ethernet')
            address_end = _IFREQ_HARDWARE_ADDRESS_OFFSET + _MAC_ADDRESS_BYTES
            return hardware[_IFREQ_HARDWARE_ADDRESS_OFFSET:address_end]
    raise ValueError('no local non-loopback IPv4 interface')


def local_android_guid(android_id: bytes, *, library: Path | None = None) -> str:
    """Derive the current Linux launcher's native GUID from local hardware."""
    fields = derive_android_guid_fields(android_id, local_hardware_mac(), library=library)
    if fields.first is None or fields.second is None:
        raise NativeGUIDProviderUnavailable('native hardware GUID fields are unavailable')
    return format_android_guid(android_id, fields)


@dataclass(frozen=True)
class AndroidGUIDFields:
    # None means the provider's availability flag was clear. b'' means a set
    # flag with zero bytes, which the original formatter treats differently.
    first: Optional[bytes] = field(default=None, repr=False)
    second: Optional[bytes] = field(default=None, repr=False)

    def __post_init__(self):
        for value in (self.first, self.second):
            if value is not None and (not isinstance(value, bytes) or len(value) > 23):
                raise ValueError('native GUID fields must be absent or at most 23 bytes')


def decode_android_guid_fields(descriptor: bytes) -> AndroidGUIDFields:
    """Decode the QHioSBsQR selector-2 result descriptor (56 bytes)."""
    if not isinstance(descriptor, bytes) or len(descriptor) != 56:
        raise ValueError('Android GUID descriptor must contain 56 bytes')
    values = []
    for flag, begin, length in ((0, 1, 24), (28, 29, 52)):
        if not descriptor[flag]:
            values.append(None)
            continue
        count = struct.unpack_from('<I', descriptor, length)[0]
        if count > 23:
            raise ValueError('Android GUID field exceeds descriptor capacity')
        values.append(descriptor[begin:begin + count])
    return AndroidGUIDFields(*values)


def format_android_guid(android_id: bytes, fields: AndroidGUIDFields, *, serial: str = '') -> str:
    """Reproduce DeviceGUID::configure's six concatenated native fields.

    AndroidID is the exact byte string passed to native configuration, without
    an automatically added NUL, whitespace trimming, or numeric conversion.
    The serial input is the separately supplied configuration string.
    """
    if not isinstance(android_id, bytes) or not android_id:
        raise ValueError('a nonempty Android identifier byte string is required')
    if not isinstance(fields, AndroidGUIDFields):
        raise ValueError('verified raw Android GUID fields are required')
    if not isinstance(serial, str) or '\0' in serial:
        raise ValueError('serial must be a string without NUL')
    first = fields.first.hex() + '.' if fields.first is not None else '0' * 36 + '.'
    second = fields.second.hex() + '.' if fields.second is not None else '0' * 14 + '.'
    third = serial + '.' if serial else '0' * 14 + '.'
    fourth = hashlib.sha1(android_id).hexdigest()[-14:] + '.'
    return first + second + third + fourth + '0' * 14 + '.' + '0' * 14


def device_id_from_descriptor(descriptor: bytes) -> bytes:
    """Extract the raw DeviceID from FKgu8fbnvGFG's length+20-byte result."""
    if not isinstance(descriptor, bytes) or len(descriptor) != 24:
        raise ValueError('DeviceID descriptor must contain 24 bytes')
    count = struct.unpack_from(_UNSIGNED_INTEGER_FORMAT, descriptor)[0]
    if count > 20:
        raise ValueError('DeviceID exceeds descriptor capacity')
    return descriptor[4:4 + count]


def format_device_id(raw: bytes) -> str:
    """Native DeviceID() is the lowercase Base16Representation of raw bytes."""
    if not isinstance(raw, bytes) or len(raw) > 20:
        raise ValueError('DeviceID must contain at most 20 bytes')
    return raw.hex()
