module shim;

import core.memory : GC;
import core.runtime : Runtime;
import core.stdc.stdint;
import core.stdc.string : strdup, memcpy;
import core.stdc.stdlib : free;
import std.conv : to;
import std.string : toStringz, fromStringz;

import provision.adi;

pragma(crt_constructor)
extern(C) void ams_provision_init() {
    Runtime.initialize();
}

pragma(crt_destructor)
extern(C) void ams_provision_fini() {
    Runtime.terminate();
}

enum AmsStatus : int {
    ok = 0,
    exception = -1,
    buffer_too_small = -2,
    invalid_argument = -3,
}

extern(C) struct AmsOtpResult {
    size_t otp_length;
    size_t mid_length;
}

extern(C) struct AmsStartResult {
    size_t cpim_length;
    uint session;
}

__gshared string last_error = "";

private int wrap_exception(scope void delegate() action) {
    try {
        GC.disable();
        scope(exit) {
            GC.enable();
            GC.collect();
        }
        action();
        return AmsStatus.ok;
    } catch (ADIException error) {
        last_error = "ADI error " ~ to!string(cast(int) error.adiError());
        return cast(int) error.adiError();
    } catch (Throwable error) {
        last_error = error.classinfo.name ~ ": " ~ error.msg;
        return AmsStatus.exception;
    }
}

extern(C) export ADI ams_provision_adi_create(const(char)* library_path) {
    try {
        GC.disable();
        scope(exit) {
            GC.enable();
            GC.collect();
        }
        auto path = fromStringz(library_path).idup;
        auto adi = new ADI(path);
        GC.addRoot(cast(void*) adi);
        return adi;
    } catch (Throwable error) {
        last_error = error.classinfo.name ~ ": " ~ error.msg;
        return null;
    }
}

extern(C) export void ams_provision_adi_destroy(ADI handle) {
    if (handle is null) return;
    try {
        GC.removeRoot(cast(void*) handle);
    } catch (Throwable) {}
}

extern(C) export int ams_provision_adi_set_provisioning_path(ADI handle, const(char)* path) {
    if (handle is null || path is null) return AmsStatus.invalid_argument;
    return wrap_exception({
        handle.provisioningPath = fromStringz(path).idup;
    });
}

extern(C) export int ams_provision_adi_set_identifier(ADI handle, const(char)* identifier) {
    if (handle is null || identifier is null) return AmsStatus.invalid_argument;
    return wrap_exception({
        handle.identifier = fromStringz(identifier).idup;
    });
}

extern(C) export int ams_provision_adi_is_provisioned(ADI handle, long ds_id, int* out_provisioned) {
    if (handle is null || out_provisioned is null) return AmsStatus.invalid_argument;
    return wrap_exception({
        *out_provisioned = handle.isMachineProvisioned(ds_id) ? 1 : 0;
    });
}

extern(C) export int ams_provision_adi_request_otp(ADI handle, long ds_id,
        ubyte* otp_buffer, size_t otp_capacity,
        ubyte* mid_buffer, size_t mid_capacity,
        AmsOtpResult* result) {
    if (handle is null || otp_buffer is null || mid_buffer is null || result is null) {
        return AmsStatus.invalid_argument;
    }
    return wrap_exception({
        auto otp = handle.requestOTP(ds_id);
        auto otp_bytes = otp.oneTimePassword;
        auto mid_bytes = otp.machineIdentifier;
        if (otp_bytes.length > otp_capacity || mid_bytes.length > mid_capacity) {
            throw new Exception("output buffer too small for OTP/MID");
        }
        memcpy(otp_buffer, otp_bytes.ptr, otp_bytes.length);
        memcpy(mid_buffer, mid_bytes.ptr, mid_bytes.length);
        result.otp_length = otp_bytes.length;
        result.mid_length = mid_bytes.length;
    });
}

extern(C) export int ams_provision_adi_start_provisioning(ADI handle, long ds_id,
        const(ubyte)* spim_data, size_t spim_length,
        ubyte* cpim_buffer, size_t cpim_capacity,
        AmsStartResult* result) {
    if (handle is null || spim_data is null || cpim_buffer is null || result is null) {
        return AmsStatus.invalid_argument;
    }
    return wrap_exception({
        auto spim = cast(ubyte[]) spim_data[0 .. spim_length].dup;
        auto cpim = handle.startProvisioning(ds_id, spim);
        auto cpim_bytes = cpim.clientProvisioningIntermediateMetadata;
        if (cpim_bytes.length > cpim_capacity) {
            handle.destroyProvisioning(cpim.session);
            throw new Exception("output buffer too small for CPIM");
        }
        memcpy(cpim_buffer, cpim_bytes.ptr, cpim_bytes.length);
        result.cpim_length = cpim_bytes.length;
        result.session = cpim.session;
    });
}

extern(C) export int ams_provision_adi_end_provisioning(ADI handle, uint session,
        const(ubyte)* ptm_data, size_t ptm_length,
        const(ubyte)* tk_data, size_t tk_length) {
    if (handle is null || ptm_data is null || tk_data is null) return AmsStatus.invalid_argument;
    return wrap_exception({
        auto ptm = cast(ubyte[]) ptm_data[0 .. ptm_length].dup;
        auto tk = cast(ubyte[]) tk_data[0 .. tk_length].dup;
        handle.endProvisioning(session, ptm, tk);
    });
}

extern(C) export int ams_provision_adi_destroy_session(ADI handle, uint session) {
    if (handle is null) return AmsStatus.invalid_argument;
    return wrap_exception({
        handle.destroyProvisioning(session);
    });
}

extern(C) export const(char)* ams_provision_last_error() {
    if (last_error.length == 0) return null;
    return last_error.toStringz;
}
