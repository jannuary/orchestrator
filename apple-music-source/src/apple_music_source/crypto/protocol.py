"""Recovered, blob-free SPC envelopes and CoreLSKD dispatcher primitives.

These operate on caller-owned bytes and integer virtual addresses. Packet
construction does not run the backend or acquire a key. Native code is built
from this distribution; no original runtime or table bank is loaded.
"""
from __future__ import annotations

import ctypes as C
from dataclasses import dataclass, field

from .corelskd import load_library

__all__ = ["SPCV2", "CryptoPrimitives", "DispatchPacket", "decode_dispatch_status"]


def _data(value, name):
    if not isinstance(value, (bytes, bytearray, memoryview)):
        raise TypeError(f"{name} must be bytes-like")
    return bytes(value)


def _uint(value, bits, name):
    if isinstance(value, bool) or not isinstance(value, int) or not 0 <= value < 1 << bits:
        raise ValueError(f"{name} must be an unsigned {bits}-bit integer")
    return value


def _buffer(data):
    return C.create_string_buffer(data, max(1, len(data)))


class _View(C.Structure):
    _fields_ = [(n, C.c_void_p) for n in ("field16", "field256", "field20", "payload")] + [("payload_size", C.c_size_t)]


@dataclass(frozen=True)
class SPCV2:
    """An immutable envelope, with no claim that its fields are authenticated."""
    field16: bytes = field(repr=False)
    field256: bytes = field(repr=False)
    field20: bytes = field(repr=False)
    payload: bytes = field(repr=False)

    def __post_init__(self):
        for name, size in (("field16", 16), ("field256", 256), ("field20", 20)):
            data = _data(getattr(self, name), name)
            if len(data) != size:
                raise ValueError(f"{name} must contain {size} bytes")
            object.__setattr__(self, name, data)
        payload = _data(self.payload, "payload")
        if not payload or len(payload) > 0xffffffff or len(payload) % 16:
            raise ValueError("payload must be nonempty, uint32-sized, and block aligned")
        object.__setattr__(self, "payload", payload)

    def pack(self):
        return CryptoPrimitives().pack_spc(self)

    @classmethod
    def parse(cls, packet):
        return CryptoPrimitives().parse_spc(packet)


@dataclass(frozen=True)
class DispatchPacket:
    """Backend operation selector plus its 192-byte argument vector."""
    token: int
    arguments: bytes = field(repr=False)
    version: int = 1


class CryptoPrimitives:
    """Bounded native primitives; no network, sessions, or global mutable state."""
    def __init__(self):
        self._lib = load_library()
        p, n, u, q = C.c_void_p, C.c_size_t, C.c_uint32, C.c_uint64
        signatures = {
            "spc_v2_parse": [p, n, C.POINTER(_View)],
            "spc_v2_pack": [p, n, C.POINTER(_View), C.POINTER(n)],
            "ckc_persistent_packet": [p, n, q, q, u, q, q],
            "ckc_context_packet": [p, n, q, q, u, q],
            "context_finalize_packet": [p, n, q],
            "context_decrypt_packet": [p, n, q, u, q, q, u],
            "compare_select": [q, q, C.c_uint, u, u, u, C.POINTER(u)],
            "compare_packet": [q, p, n, C.POINTER(u)],
            "field_copy": [u, u, p, n, p, n],
            "field_packet": [q, p, n, C.POINTER(u), C.POINTER(q), C.POINTER(q)],
            "append_bytes": [p, n, u, p, n],
            "mt19937_twist": [C.POINTER(u)],
            "mt19937_temper": [u],
            "mt19937_encode_word": [u, p],
        }
        for name, args in signatures.items():
            f = getattr(self._lib, "wrapper_kg_" + name)
            f.argtypes = args
            f.restype = None if name in ("mt19937_twist", "mt19937_encode_word") else (u if name == "mt19937_temper" else C.c_int)

    def _call(self, name, *args):
        return getattr(self._lib, "wrapper_kg_" + name)(*args)

    def pack_spc(self, envelope):
        if not isinstance(envelope, SPCV2):
            raise TypeError("envelope must be SPCV2")
        buffers = [_buffer(getattr(envelope, name)) for name in ("field16", "field256", "field20", "payload")]
        view = _View(*(C.cast(b, C.c_void_p) for b in buffers), len(envelope.payload))
        output, written = C.create_string_buffer(304 + len(envelope.payload)), C.c_size_t()
        if self._call("spc_v2_pack", output, len(output), C.byref(view), C.byref(written)):
            raise ValueError("SPC envelope rejected")
        return output.raw[:written.value]

    def parse_spc(self, packet):
        data = _data(packet, "packet")
        source, view = _buffer(data), _View()
        if self._call("spc_v2_parse", source, len(data), C.byref(view)):
            raise ValueError("invalid SPC v2 envelope")
        return SPCV2(*(C.string_at(getattr(view, name), size) for name, size in
                       (("field16", 16), ("field256", 256), ("field20", 20), ("payload", view.payload_size))))

    def dispatch(self, operation, *values):
        specs = {
            "persistent": ("ckc_persistent_packet", 0x13c604d2, (64, 64, 32, 64, 64)),
            "context": ("ckc_context_packet", 0xc84dc4a3, (64, 64, 32, 64)),
            "finalize": ("context_finalize_packet", 0x68df9ab6, (64,)),
            "decrypt": ("context_decrypt_packet", 0xdf65877e, (64, 32, 64, 64, 32)),
        }
        if operation not in specs:
            raise ValueError("unsupported dispatcher operation")
        name, token, widths = specs[operation]
        if len(values) != len(widths):
            raise ValueError("wrong argument count")
        args = [_uint(v, w, f"argument {i}") for i, (v, w) in enumerate(zip(values, widths))]
        output = C.create_string_buffer(192)
        if self._call(name, output, len(output), *args):
            raise ValueError("dispatcher packet rejected")
        return DispatchPacket(token, output.raw)

    def compare(self, a, b, *, mode, selector, body=0x10a1, dispatch=3):
        values = [_uint(v, bits, name) for v, bits, name in
                  ((a, 64, "a"), (b, 64, "b"), (mode, 32, "mode"), (selector, 32, "selector"), (body, 32, "body"), (dispatch, 32, "dispatch"))]
        out = C.c_uint32()
        if self._call("compare_select", *values, C.byref(out)):
            raise ValueError("unsupported comparison selector/body")
        return out.value

    def compare_packet(self, address, packet):
        address, data = _uint(address, 64, "address"), _data(packet, "packet")
        out = C.c_uint32()
        if self._call("compare_packet", address, _buffer(data), len(data), C.byref(out)):
            raise ValueError("invalid comparison packet")
        return out.value

    def field_packet(self, address, packet):
        address, data = _uint(address, 64, "address"), _data(packet, "packet")
        body, dst, src = C.c_uint32(), C.c_uint64(), C.c_uint64()
        if self._call("field_packet", address, _buffer(data), len(data), C.byref(body), C.byref(dst), C.byref(src)):
            raise ValueError("invalid field packet")
        return body.value, dst.value, src.value

    def copy_field(self, body, destination, source, *, dispatch=10):
        body, dispatch = _uint(body, 32, "body"), _uint(dispatch, 32, "dispatch")
        dst, src = _data(destination, "destination"), _data(source, "source")
        output = _buffer(dst)
        if self._call("field_copy", dispatch, body, output, len(dst), _buffer(src), len(src)):
            raise ValueError("invalid field-copy buffers or body")
        return output.raw[:len(dst)]

    def append_encoded(self, descriptor, data):
        descriptor, data = _data(descriptor, "descriptor"), _data(data, "data")
        if len(data) > 299:
            raise ValueError("append exceeds the bounded descriptor")
        output = _buffer(descriptor)
        status = self._call("append_bytes", output, len(descriptor), 0x2167c5a6 + len(data), _buffer(data), len(data))
        if status:
            raise ValueError(f"encoded append rejected ({status})")
        return output.raw[:len(descriptor)]

    def twist(self, state):
        """MT19937 compatibility recurrence, never an entropy source."""
        values = tuple(state)
        if len(values) != 624:
            raise ValueError("MT state must contain 624 uint32 words")
        output = (C.c_uint32 * 624)(*[_uint(v, 32, "state word") for v in values])
        self._call("mt19937_twist", output)
        return tuple(output)

    def temper(self, value):
        return self._call("mt19937_temper", _uint(value, 32, "value"))

    def encode_word(self, value):
        output = C.create_string_buffer(4)
        self._call("mt19937_encode_word", _uint(value, 32, "value"), output)
        return output.raw


def decode_dispatch_status(packet):
    """Decode the one-element big-endian result, without executing it."""
    data = _data(packet, "packet")
    lib = load_library()
    f = lib.wrapper_kg_ckc_packet_status
    f.argtypes = [C.c_void_p, C.c_size_t, C.POINTER(C.c_uint32)]
    f.restype = C.c_int
    status = C.c_uint32()
    if f(_buffer(data), len(data), C.byref(status)):
        raise ValueError("invalid dispatcher result")
    return status.value
