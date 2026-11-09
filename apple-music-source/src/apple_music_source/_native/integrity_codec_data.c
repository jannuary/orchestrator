#include "integrity_codec_data.h"

/* Recovered consumers 0x3edebc..0x3ee383 and 0x3ee6a1..0x3eed16.
 * Their byte codec is ((x XOR mask(i,seed))*FNV_prime) mod 256;
 * decoding multiplies by the inverse prime and XORs the same mask.
 * mask(i,s) = ((i-s)*(i+s)) XOR s. Four SIMD lane groups enumerate
 * successive byte positions. These are arithmetic constants, not integrity
 * substitutions. scripts/verify_integrity_codec.py checks the actual consumers.
 */
static int word(uint64_t at, uint32_t *out) {
    uint64_t base;
    unsigned lane;
    uint32_t value;
    if (at >= 0x580 && at < 0x590) {
        base=0x580; value=(UINT32_C(0x1000193)&255)*UINT32_C(0x10001);
    } else if (at >= 0xe20 && at < 0xe30) {
        base=0xe20; value=255;
    } else if (at >= 0xe30 && at < 0xe40) {
        base=0xe30; value=16;
    } else if (at >= 0x1170 && at < 0x1180) {
        base=0x1170; value=4;
    } else if (at >= 0x25b0 && at < 0x25c0) {
        base=0x25b0; value=8;
    } else if (at >= 0x25c0 && at < 0x25d0) {
        /* Newton inversion of the odd FNV multiplier modulo 2^32. */
        unsigned j; base=0x25c0; value=1;
        for(j=0;j<5;++j)value*=2-UINT32_C(0x1000193)*value;
    } else if (at >= 0x35d0 && at < 0x35e0) {
        base=0x35d0; value=UINT32_C(255)*UINT32_C(0x10001);
    } else if (at >= 0x4690 && at < 0x46a0) {
        base=0x4690; value=12;
    } else if (at >= 0x4c40 && at < 0x4c50) {
        base=0x4c40; value=0;
    } else if (at >= 0x4f40 && at < 0x4f50) {
        base=0x4f40; value=32;
    } else return 0;
    lane=(unsigned)((at-base)/4);
    if(base==0x1170||base==0x25b0||base==0x4690||base==0x4c40)value+=lane;
    *out=value; return 1;
}
int ams_integrity_codec_data_read(uint64_t address,unsigned width,uint64_t *out) {
    uint64_t value=0;
    unsigned j;
    if(!out||!width||width>8||address>UINT64_MAX-(width-1))return 0;
    for(j=0;j<width;++j){uint32_t v;uint64_t at=address+j;
        if(!word(at,&v))return 0;
        value|=(uint64_t)((v>>(8*(unsigned)(at&3)))&255)<<(8*j);
    }
    *out=value;return 1;
}
