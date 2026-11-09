#ifndef WRAPPER_SOURCE_MESCAL_H
#define WRAPPER_SOURCE_MESCAL_H
#include <stddef.h>
#include <stdint.h>
#if defined(__GNUC__)
#define MESCAL_API __attribute__((visibility("default")))
#else
#define MESCAL_API
#endif
typedef int (*mescal_entropy_fn)(void*,unsigned char*,size_t);
typedef uint64_t (*mescal_clock_fn)(void*);
typedef int (*mescal_time_fn)(void*,int64_t*,int64_t*);
typedef struct mescal_options {mescal_entropy_fn entropy;mescal_clock_fn clock;mescal_time_fn time;void *user;} mescal_options;
typedef struct mescal_result {uint32_t status;uint64_t pc,fault_address,steps;unsigned fault_size;} mescal_result;
typedef struct mescal_session mescal_session;
MESCAL_API int wrapper_mescal_create(const unsigned char*,size_t,const mescal_options*,mescal_session**,mescal_result*);
MESCAL_API int wrapper_mescal_exchange(mescal_session*,unsigned,const unsigned char*,size_t,unsigned char*,size_t,size_t*,unsigned*,mescal_result*);
MESCAL_API int wrapper_mescal_sign(mescal_session*,const unsigned char*,size_t,unsigned char*,size_t,size_t*,mescal_result*);
MESCAL_API void wrapper_mescal_free(mescal_session*);
/* Standalone GUID field provider, from an explicitly supplied hardware profile.
 * AndroidID configuration precedes the query; serial properties are unused on
 * this configured route. serial models a resolved property for ABI verification.
 * mac is the
 * selected non-loopback Ethernet address, six bytes. Output is the native
 * 56-byte descriptor, not a stored/captured GUID. */
MESCAL_API int wrapper_mescal_guid_fields(const unsigned char *android_id,size_t android_size,
    const unsigned char *serial,size_t serial_size,
    const unsigned char *mac,unsigned char *output,size_t capacity,
    const mescal_options *options,mescal_result *result);
#endif
