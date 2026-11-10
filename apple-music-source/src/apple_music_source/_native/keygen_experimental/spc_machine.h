#ifndef WRAPPER_KG_SPC_MACHINE_H
#define WRAPPER_KG_SPC_MACHINE_H
#include "spc_payload.h"
#ifndef WRAPPER_KG_NO_CONSTANTS
#include "spc_payload_constants.inc"
#endif

enum { OP_ADD,OP_ADC,OP_SUB,OP_XOR,OP_AND,OP_OR,OP_NEG,OP_NOT,OP_IMUL,
       OP_SHL,OP_SHR,OP_SAR,OP_ROL,OP_ROR,OP_SBB };
enum { COND_E,COND_NE,COND_B,COND_AE,COND_A,COND_BE,
       COND_L,COND_LE,COND_G,COND_GE,COND_S,COND_NS,COND_O,COND_NO,COND_P,COND_NP };
#define CF UINT64_C(1)
#define PF UINT64_C(4)
#define AF UINT64_C(16)
#define ZF UINT64_C(64)
#define SF UINT64_C(128)
#define OF UINT64_C(2048)
#define ARITH (CF|PF|AF|ZF|SF|OF)
static inline uint64_t mask(unsigned bits) { return UINT64_MAX >> (64-bits); }
static inline uint64_t common(uint64_t r, unsigned bits) {
#if defined(__GNUC__)
    unsigned byte_parity=(unsigned)__builtin_parity((unsigned char)r);
#else
    unsigned byte_parity=(unsigned)r & 255;
    byte_parity ^= byte_parity>>4; byte_parity ^= byte_parity>>2; byte_parity ^= byte_parity>>1;
#endif
    return ((byte_parity&1)?0:PF) | (r?0:ZF) |
           ((r & (UINT64_C(1)<<(bits-1)))?SF:0);
}
static inline void logical(wrapper_kg_payload_state *s,uint64_t r,unsigned bits) {
    s->flags=(s->flags & ~ARITH)|common(r,bits);
}
#if defined(__GNUC__) && defined(__OPTIMIZE__)
__attribute__((always_inline))
#endif
static inline uint64_t operation(wrapper_kg_payload_state *s,unsigned op,
                          uint64_t a,uint64_t b,unsigned bits) {
    uint64_t m=mask(bits),sign=UINT64_C(1)<<(bits-1),r=0,t,c=0,overflow=0;
    unsigned n=(unsigned)b & (bits==64?63:31);
    a &= m; b &= m;
    switch(op) {
    case OP_NOT:return (~a)&m;
    case OP_NEG:b=a;a=0; /* fall through */
    case OP_SUB:
        r=(a-b)&m;c=a<b;overflow=((a^b)&(a^r)&sign)!=0;
        s->flags=(s->flags&~ARITH)|common(r,bits)|(c?CF:0)|
            (overflow?OF:0)|((a^b^r)&AF);return r;
    case OP_SBB:
        c=(s->flags&CF)!=0;r=(a-b-c)&m;
        overflow=((a^b)&(a^r)&sign)!=0;
        c=(a<b)||(c && a==b);
        s->flags=(s->flags&~ARITH)|common(r,bits)|(c?CF:0)|
            (overflow?OF:0)|((a^b^r)&AF);return r;
    case OP_ADD:case OP_ADC:
        c=op==OP_ADC && (s->flags&CF);
        t=(a+b)&m;r=(t+c)&m;c=(t<a)||(r<t);
        overflow=((~(a^b))&(a^r)&sign)!=0;
        s->flags=(s->flags&~ARITH)|common(r,bits)|(c?CF:0)|
            (overflow?OF:0)|((a^b^r)&AF);return r;
    case OP_AND:r=a&b;break;
    case OP_OR:r=a|b;break;
    case OP_XOR:r=a^b;break;
    case OP_IMUL: {
        uint64_t aa=(a&sign)?((~a+1)&m):a;
        uint64_t bb=(b&sign)?((~b+1)&m):b;
        uint64_t limit=((a^b)&sign)?sign:sign-1;
        r=(a*b)&m;overflow=bb && aa>limit/bb;
        /* SF/ZF/PF/AF are architecturally undefined for IMUL. These values
         * model the offline Unicorn boundary, not all physical processors. */
        s->flags=(s->flags&~ARITH)|common(r,bits)|
            (overflow?(CF|OF):0);return r;
    }
    case OP_ROL:case OP_ROR:
        n%=bits;if(!n)return a;
        r=op==OP_ROL?((a<<n)|(a>>(bits-n)))&m:
                         ((a>>n)|(a<<(bits-n)))&m;
        c=op==OP_ROL?(r&1):(r>>(bits-1));
        overflow=op==OP_ROL?((r>>(bits-1))^c):
                                ((r>>(bits-1))^(r>>(bits-2)));
        s->flags=(s->flags&~(CF|OF))|(c?CF:0)|((overflow&1)?OF:0);
        return r;
    case OP_SHL:case OP_SHR:case OP_SAR:
        if(!n)return a;
        if(op==OP_SHL) {
            r=n>=bits?0:(a<<n)&m;
            c=n>bits?0:(a>>(bits-n))&1;
            overflow=((r>>(bits-1))^c)&1;
        } else {
            c=n>bits?((op==OP_SAR && (a&sign))?1:0):(a>>(n-1))&1;
            r=n>=bits?0:a>>n;
            if(op==OP_SAR && (a&sign))r|=n>=bits?m:(m^(m>>n));
            /* Match the offline oracle: multi-bit SHR clears undefined OF. */
            overflow=op==OP_SHR && n==1 && (a&sign);
        }
        s->flags=(s->flags&~ARITH)|common(r,bits)|(c?CF:0)|(overflow?OF:0);
        return r;
    }
    logical(s,r,bits);return r;
}
static inline uint64_t shift_double(wrapper_kg_payload_state *s,uint64_t a,
                              uint64_t b,uint64_t count,unsigned bits) {
    unsigned n=(unsigned)count&(bits==64?63:31);
    uint64_t r,m=mask(bits),c;
    a&=m;b&=m;
    if(!n)return a;
    r=((a>>n)|(b<<(bits-n)))&m;c=(a>>(n-1))&1;
    /* Match the oracle's last single-bit shift for undefined multi-bit OF. */
    s->flags=(s->flags&~ARITH)|common(r,bits)|(c?CF:0)|
        ((((n==1?a>>(bits-1):(bits==64?0:b>>(n-2)))^(r>>(bits-1)))&1)?OF:0);
    return r;
}
static inline uint64_t shift_left_double(wrapper_kg_payload_state *s,uint64_t a,
    uint64_t b,uint64_t count,unsigned bits) {
    unsigned n=(unsigned)count&(bits==64?63:31);
    uint64_t r,m=mask(bits),c;
    a&=m;b&=m;
    if(!n)return a;
    r=((a<<n)|(b>>(bits-n)))&m;c=(a>>(bits-n))&1;
    s->flags=(s->flags&~ARITH)|common(r,bits)|(c?CF:0)|
        ((((r>>(bits-1))^c)&1)?OF:0);
    return r;
}
static inline void multiply(wrapper_kg_payload_state *s,uint64_t b,unsigned bits) {
    uint64_t a=s->gpr[0]&mask(bits),lo,hi,overflow;
    if(bits==64) {
        uint64_t a0=(uint32_t)a,a1=a>>32,b0=(uint32_t)b,b1=b>>32;
        uint64_t w0=a0*b0,t=a1*b0+(w0>>32),w1=(uint32_t)t,w2=t>>32;
        w1+=a0*b1;hi=a1*b1+w2+(w1>>32);lo=(w1<<32)+(uint32_t)w0;
        s->gpr[0]=lo;s->gpr[3]=hi;
    } else {
        lo=a*(b&mask(bits));hi=lo>>bits;
        if(bits==8)s->gpr[0]=(s->gpr[0]&~UINT64_C(65535))|(lo&65535);
        else {s->gpr[0]=(uint32_t)lo;s->gpr[3]=(uint32_t)hi;}
    }
    overflow=hi!=0;
    s->flags=(s->flags&~ARITH)|common(lo&mask(bits),bits)|
             (overflow?(CF|OF):0);
}
/* Unsigned x86 DIV, with explicit zero/quotient-overflow rejection.
 * No host wide-integer extension or undefined C division is used. */
static inline int divide(wrapper_kg_payload_state *s,uint64_t divisor,unsigned bits) {
    uint64_t lo=s->gpr[0],hi=s->gpr[3],q=0,r;
    unsigned i;
    if(bits==32) {
        uint64_t numerator=((uint64_t)(uint32_t)hi<<32)|(uint32_t)lo;
        divisor=(uint32_t)divisor;hi=(uint32_t)hi;
        if(!divisor || hi>=divisor)return 0;
        q=numerator/divisor;r=numerator%divisor;
    } else if(bits==64) {
        if(!divisor || hi>=divisor)return 0;
        r=hi;
        for(i=64;i-- > 0;) {
            uint64_t carry=r>>63;
            r=(r<<1)|((lo>>i)&1);
            if(carry || r>=divisor) {r-=divisor;q|=UINT64_C(1)<<i;}
        }
    } else return 0;
    s->gpr[0]=q;s->gpr[3]=r;
    /* DIV flags are undefined architecturally; preserve them as in the
     * configured offline oracle. No all-CPU undefined-flag claim is made. */
    return 1;
}
static inline int condition(const wrapper_kg_payload_state *s,unsigned cond) {
    switch(cond) {
    case COND_E:return (s->flags&ZF)!=0;
    case COND_NE:return !(s->flags&ZF);
    case COND_B:return (s->flags&CF)!=0;
    case COND_AE:return !(s->flags&CF);
    case COND_A:return !(s->flags&(CF|ZF));
    case COND_BE:return (s->flags&(CF|ZF))!=0;
    case COND_L:return !!(s->flags&SF)!=!!(s->flags&OF);
    case COND_LE:return (s->flags&ZF) || (!!(s->flags&SF)!=!!(s->flags&OF));
    case COND_G:return !(s->flags&ZF) && (!!(s->flags&SF)==!!(s->flags&OF));
    case COND_GE:return !!(s->flags&SF)==!!(s->flags&OF);
    case COND_S:return (s->flags&SF)!=0;
    case COND_NS:return !(s->flags&SF);
    case COND_O:return (s->flags&OF)!=0;
    case COND_NO:return !(s->flags&OF);
    case COND_P:return (s->flags&PF)!=0;
    case COND_NP:return !(s->flags&PF);
    default:return 0;
    }
}
static inline int valid(const wrapper_kg_payload_region *r,size_t count) {
    size_t i,j;
    if(!r || !count || count>1024)return 0;
    for(i=0;i<count;++i) {
        if(!r[i].data || !r[i].size || r[i].size>UINT64_MAX-r[i].address ||
           !r[i].permissions || (r[i].permissions&~3u))return 0;
        for(j=0;j<i;++j)
            if(r[i].address<r[j].address+r[j].size &&
               r[j].address<r[i].address+r[i].size)return 0;
    }
    return 1;
}
static inline unsigned char *translate(const wrapper_kg_payload_region *r,size_t count,
                               uint64_t address,unsigned width,unsigned access) {
    size_t i;
    for(i=0;i<count;++i)
        if(address>=r[i].address && width<=r[i].size &&
           address-r[i].address<=r[i].size-width && (r[i].permissions&access))
            return r[i].data+(size_t)(address-r[i].address);
    return 0;
}

#endif
