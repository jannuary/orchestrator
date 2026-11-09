#include "../mescal_internal.h"
int mescal_corefp_page_3d(unsigned block,uint64_t bias,wrapper_kg_native_state *fs,const wrapper_kg_payload_region *regions,size_t count,size_t max_steps){
NATIVE_LOCALS;
switch(block){
case 0:
next_pc=bias+UINT64_C(0x3d0302);
switch(s->pc-bias){
case UINT64_C(0x3d0066):goto kg_pc_3d0066;
case UINT64_C(0x3d0069):goto kg_pc_3d0069;
case UINT64_C(0x3d006c):goto kg_pc_3d006c;
case UINT64_C(0x3d006e):goto kg_pc_3d006e;
case UINT64_C(0x3d0070):goto kg_pc_3d0070;
case UINT64_C(0x3d0076):goto kg_pc_3d0076;
case UINT64_C(0x3d007c):goto kg_pc_3d007c;
case UINT64_C(0x3d007f):goto kg_pc_3d007f;
case UINT64_C(0x3d0085):goto kg_pc_3d0085;
case UINT64_C(0x3d0087):goto kg_pc_3d0087;
case UINT64_C(0x3d0089):goto kg_pc_3d0089;
case UINT64_C(0x3d008f):goto kg_pc_3d008f;
case UINT64_C(0x3d0091):goto kg_pc_3d0091;
case UINT64_C(0x3d0093):goto kg_pc_3d0093;
case UINT64_C(0x3d0095):goto kg_pc_3d0095;
case UINT64_C(0x3d0098):goto kg_pc_3d0098;
case UINT64_C(0x3d009c):goto kg_pc_3d009c;
case UINT64_C(0x3d009f):goto kg_pc_3d009f;
case UINT64_C(0x3d00a6):goto kg_pc_3d00a6;
case UINT64_C(0x3d00a9):goto kg_pc_3d00a9;
case UINT64_C(0x3d00ad):goto kg_pc_3d00ad;
case UINT64_C(0x3d00b0):goto kg_pc_3d00b0;
case UINT64_C(0x3d00b4):goto kg_pc_3d00b4;
case UINT64_C(0x3d00b8):goto kg_pc_3d00b8;
case UINT64_C(0x3d00bd):goto kg_pc_3d00bd;
case UINT64_C(0x3d00bf):goto kg_pc_3d00bf;
case UINT64_C(0x3d00c1):goto kg_pc_3d00c1;
case UINT64_C(0x3d00c4):goto kg_pc_3d00c4;
case UINT64_C(0x3d00c8):goto kg_pc_3d00c8;
case UINT64_C(0x3d00cc):goto kg_pc_3d00cc;
case UINT64_C(0x3d00d0):goto kg_pc_3d00d0;
case UINT64_C(0x3d00d4):goto kg_pc_3d00d4;
case UINT64_C(0x3d00d6):goto kg_pc_3d00d6;
case UINT64_C(0x3d00dc):goto kg_pc_3d00dc;
case UINT64_C(0x3d00df):goto kg_pc_3d00df;
case UINT64_C(0x3d00e5):goto kg_pc_3d00e5;
case UINT64_C(0x3d00e7):goto kg_pc_3d00e7;
case UINT64_C(0x3d00e9):goto kg_pc_3d00e9;
case UINT64_C(0x3d00ef):goto kg_pc_3d00ef;
case UINT64_C(0x3d00f5):goto kg_pc_3d00f5;
case UINT64_C(0x3d00f8):goto kg_pc_3d00f8;
case UINT64_C(0x3d00fe):goto kg_pc_3d00fe;
case UINT64_C(0x3d0100):goto kg_pc_3d0100;
case UINT64_C(0x3d0102):goto kg_pc_3d0102;
case UINT64_C(0x3d0108):goto kg_pc_3d0108;
case UINT64_C(0x3d010a):goto kg_pc_3d010a;
case UINT64_C(0x3d010d):goto kg_pc_3d010d;
case UINT64_C(0x3d0110):goto kg_pc_3d0110;
case UINT64_C(0x3d0112):goto kg_pc_3d0112;
case UINT64_C(0x3d0114):goto kg_pc_3d0114;
case UINT64_C(0x3d0117):goto kg_pc_3d0117;
case UINT64_C(0x3d0119):goto kg_pc_3d0119;
case UINT64_C(0x3d011c):goto kg_pc_3d011c;
case UINT64_C(0x3d011e):goto kg_pc_3d011e;
case UINT64_C(0x3d0121):goto kg_pc_3d0121;
case UINT64_C(0x3d0123):goto kg_pc_3d0123;
case UINT64_C(0x3d0126):goto kg_pc_3d0126;
case UINT64_C(0x3d012b):goto kg_pc_3d012b;
case UINT64_C(0x3d0132):goto kg_pc_3d0132;
case UINT64_C(0x3d0135):goto kg_pc_3d0135;
case UINT64_C(0x3d0139):goto kg_pc_3d0139;
case UINT64_C(0x3d013c):goto kg_pc_3d013c;
case UINT64_C(0x3d013f):goto kg_pc_3d013f;
case UINT64_C(0x3d0141):goto kg_pc_3d0141;
case UINT64_C(0x3d0145):goto kg_pc_3d0145;
case UINT64_C(0x3d0148):goto kg_pc_3d0148;
case UINT64_C(0x3d014b):goto kg_pc_3d014b;
case UINT64_C(0x3d014e):goto kg_pc_3d014e;
case UINT64_C(0x3d0151):goto kg_pc_3d0151;
case UINT64_C(0x3d0153):goto kg_pc_3d0153;
case UINT64_C(0x3d0158):goto kg_pc_3d0158;
case UINT64_C(0x3d015d):goto kg_pc_3d015d;
case UINT64_C(0x3d0160):goto kg_pc_3d0160;
case UINT64_C(0x3d0166):goto kg_pc_3d0166;
case UINT64_C(0x3d0168):goto kg_pc_3d0168;
case UINT64_C(0x3d016a):goto kg_pc_3d016a;
case UINT64_C(0x3d0170):goto kg_pc_3d0170;
case UINT64_C(0x3d0173):goto kg_pc_3d0173;
case UINT64_C(0x3d0177):goto kg_pc_3d0177;
case UINT64_C(0x3d017b):goto kg_pc_3d017b;
case UINT64_C(0x3d017d):goto kg_pc_3d017d;
case UINT64_C(0x3d0180):goto kg_pc_3d0180;
case UINT64_C(0x3d0184):goto kg_pc_3d0184;
case UINT64_C(0x3d0188):goto kg_pc_3d0188;
case UINT64_C(0x3d018c):goto kg_pc_3d018c;
case UINT64_C(0x3d018e):goto kg_pc_3d018e;
case UINT64_C(0x3d0190):goto kg_pc_3d0190;
case UINT64_C(0x3d0193):goto kg_pc_3d0193;
case UINT64_C(0x3d019a):goto kg_pc_3d019a;
case UINT64_C(0x3d019e):goto kg_pc_3d019e;
case UINT64_C(0x3d01a2):goto kg_pc_3d01a2;
case UINT64_C(0x3d01a4):goto kg_pc_3d01a4;
case UINT64_C(0x3d01a7):goto kg_pc_3d01a7;
case UINT64_C(0x3d01aa):goto kg_pc_3d01aa;
case UINT64_C(0x3d01ad):goto kg_pc_3d01ad;
case UINT64_C(0x3d01af):goto kg_pc_3d01af;
case UINT64_C(0x3d01b2):goto kg_pc_3d01b2;
case UINT64_C(0x3d01b4):goto kg_pc_3d01b4;
case UINT64_C(0x3d01b6):goto kg_pc_3d01b6;
case UINT64_C(0x3d01b8):goto kg_pc_3d01b8;
case UINT64_C(0x3d01bd):goto kg_pc_3d01bd;
case UINT64_C(0x3d01c2):goto kg_pc_3d01c2;
case UINT64_C(0x3d01c5):goto kg_pc_3d01c5;
case UINT64_C(0x3d01cb):goto kg_pc_3d01cb;
case UINT64_C(0x3d01cd):goto kg_pc_3d01cd;
case UINT64_C(0x3d01cf):goto kg_pc_3d01cf;
case UINT64_C(0x3d01d4):goto kg_pc_3d01d4;
case UINT64_C(0x3d01da):goto kg_pc_3d01da;
case UINT64_C(0x3d01e1):goto kg_pc_3d01e1;
case UINT64_C(0x3d01e4):goto kg_pc_3d01e4;
case UINT64_C(0x3d01e7):goto kg_pc_3d01e7;
case UINT64_C(0x3d01ea):goto kg_pc_3d01ea;
case UINT64_C(0x3d01f1):goto kg_pc_3d01f1;
case UINT64_C(0x3d01f4):goto kg_pc_3d01f4;
case UINT64_C(0x3d01f7):goto kg_pc_3d01f7;
case UINT64_C(0x3d01fa):goto kg_pc_3d01fa;
case UINT64_C(0x3d01fc):goto kg_pc_3d01fc;
case UINT64_C(0x3d01ff):goto kg_pc_3d01ff;
case UINT64_C(0x3d0201):goto kg_pc_3d0201;
case UINT64_C(0x3d0204):goto kg_pc_3d0204;
case UINT64_C(0x3d0207):goto kg_pc_3d0207;
case UINT64_C(0x3d020a):goto kg_pc_3d020a;
case UINT64_C(0x3d0210):goto kg_pc_3d0210;
case UINT64_C(0x3d0217):goto kg_pc_3d0217;
case UINT64_C(0x3d021b):goto kg_pc_3d021b;
case UINT64_C(0x3d021e):goto kg_pc_3d021e;
case UINT64_C(0x3d0222):goto kg_pc_3d0222;
case UINT64_C(0x3d0226):goto kg_pc_3d0226;
case UINT64_C(0x3d022a):goto kg_pc_3d022a;
case UINT64_C(0x3d022d):goto kg_pc_3d022d;
case UINT64_C(0x3d0230):goto kg_pc_3d0230;
case UINT64_C(0x3d0234):goto kg_pc_3d0234;
case UINT64_C(0x3d0238):goto kg_pc_3d0238;
case UINT64_C(0x3d023b):goto kg_pc_3d023b;
case UINT64_C(0x3d023e):goto kg_pc_3d023e;
case UINT64_C(0x3d0241):goto kg_pc_3d0241;
case UINT64_C(0x3d0243):goto kg_pc_3d0243;
case UINT64_C(0x3d0245):goto kg_pc_3d0245;
case UINT64_C(0x3d024a):goto kg_pc_3d024a;
case UINT64_C(0x3d024f):goto kg_pc_3d024f;
case UINT64_C(0x3d0252):goto kg_pc_3d0252;
case UINT64_C(0x3d0258):goto kg_pc_3d0258;
case UINT64_C(0x3d025a):goto kg_pc_3d025a;
case UINT64_C(0x3d025c):goto kg_pc_3d025c;
case UINT64_C(0x3d0261):goto kg_pc_3d0261;
case UINT64_C(0x3d0268):goto kg_pc_3d0268;
case UINT64_C(0x3d026c):goto kg_pc_3d026c;
case UINT64_C(0x3d026f):goto kg_pc_3d026f;
case UINT64_C(0x3d0272):goto kg_pc_3d0272;
case UINT64_C(0x3d0275):goto kg_pc_3d0275;
case UINT64_C(0x3d027b):goto kg_pc_3d027b;
case UINT64_C(0x3d0282):goto kg_pc_3d0282;
case UINT64_C(0x3d0285):goto kg_pc_3d0285;
case UINT64_C(0x3d0287):goto kg_pc_3d0287;
case UINT64_C(0x3d028a):goto kg_pc_3d028a;
case UINT64_C(0x3d028d):goto kg_pc_3d028d;
case UINT64_C(0x3d028f):goto kg_pc_3d028f;
case UINT64_C(0x3d0292):goto kg_pc_3d0292;
case UINT64_C(0x3d0294):goto kg_pc_3d0294;
case UINT64_C(0x3d0298):goto kg_pc_3d0298;
case UINT64_C(0x3d029b):goto kg_pc_3d029b;
case UINT64_C(0x3d029e):goto kg_pc_3d029e;
case UINT64_C(0x3d02a2):goto kg_pc_3d02a2;
case UINT64_C(0x3d02a5):goto kg_pc_3d02a5;
case UINT64_C(0x3d02a8):goto kg_pc_3d02a8;
case UINT64_C(0x3d02ab):goto kg_pc_3d02ab;
case UINT64_C(0x3d02ad):goto kg_pc_3d02ad;
case UINT64_C(0x3d02af):goto kg_pc_3d02af;
case UINT64_C(0x3d02b2):goto kg_pc_3d02b2;
case UINT64_C(0x3d02b5):goto kg_pc_3d02b5;
case UINT64_C(0x3d02b8):goto kg_pc_3d02b8;
case UINT64_C(0x3d02ba):goto kg_pc_3d02ba;
case UINT64_C(0x3d02bd):goto kg_pc_3d02bd;
case UINT64_C(0x3d02c1):goto kg_pc_3d02c1;
case UINT64_C(0x3d02c4):goto kg_pc_3d02c4;
case UINT64_C(0x3d02c7):goto kg_pc_3d02c7;
case UINT64_C(0x3d02cb):goto kg_pc_3d02cb;
case UINT64_C(0x3d02ce):goto kg_pc_3d02ce;
case UINT64_C(0x3d02d2):goto kg_pc_3d02d2;
case UINT64_C(0x3d02d6):goto kg_pc_3d02d6;
case UINT64_C(0x3d02d9):goto kg_pc_3d02d9;
case UINT64_C(0x3d02dd):goto kg_pc_3d02dd;
case UINT64_C(0x3d02e1):goto kg_pc_3d02e1;
case UINT64_C(0x3d02e4):goto kg_pc_3d02e4;
case UINT64_C(0x3d02e7):goto kg_pc_3d02e7;
case UINT64_C(0x3d02eb):goto kg_pc_3d02eb;
case UINT64_C(0x3d02ed):goto kg_pc_3d02ed;
case UINT64_C(0x3d02f0):goto kg_pc_3d02f0;
case UINT64_C(0x3d02f7):goto kg_pc_3d02f7;
case UINT64_C(0x3d02fe):goto kg_pc_3d02fe;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1577: [0x3d0066,0x3d0302), 190 instructions. */
kg_pc_3d0066: STEP(0x3d0066); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d0069: STEP(0x3d0069); /* and esi, 0xe */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xe);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d006c: STEP(0x3d006c); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d006e: STEP(0x3d006e); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d0070: STEP(0x3d0070); /* add edx, 0x2912b007 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x2912b007);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d0076: STEP(0x3d0076); /* xor edx, 0xd57b137 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xd57b137);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d007c: STEP(0x3d007c); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d007f: STEP(0x3d007f); /* and esi, 0x888389c */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x888389c);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d0085: STEP(0x3d0085); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d0087: STEP(0x3d0087); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d0089: STEP(0x3d0089); /* add edx, 0xcdc5c4e */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xcdc5c4e);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d008f: STEP(0x3d008f); /* add cl, cl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0091: STEP(0x3d0091); /* mov eax, ecx */
s->gpr[0] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d0093: STEP(0x3d0093); /* xor al, 0x78 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x78);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0095: STEP(0x3d0095); /* mov r13d, eax */
s->gpr[13] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d0098: STEP(0x3d0098); /* or r13b, 0x70 */
x = (s->gpr[13] & UINT64_C(0xff)); y = UINT64_C(0x70);
s->gpr[13] = (s->gpr[13] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_OR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d009c: STEP(0x3d009c); /* xor r13b, cl */
x = (s->gpr[13] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[13] = (s->gpr[13] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d009f: STEP(0x3d009f); /* xor rdx, 0x28995d88 */
x = s->gpr[3]; y = UINT64_C(0x28995d88);
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_3d00a6: STEP(0x3d00a6); /* add r13b, r13b */
x = (s->gpr[13] & UINT64_C(0xff)); y = (s->gpr[13] & UINT64_C(0xff));
s->gpr[13] = (s->gpr[13] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d00a9: STEP(0x3d00a9); /* xor r13b, 0xef */
x = (s->gpr[13] & UINT64_C(0xff)); y = UINT64_C(0xef);
s->gpr[13] = (s->gpr[13] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d00ad: STEP(0x3d00ad); /* add r13b, al */
x = (s->gpr[13] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[13] = (s->gpr[13] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d00b0: STEP(0x3d00b0); /* add r13b, 0x71 */
x = (s->gpr[13] & UINT64_C(0xff)); y = UINT64_C(0x71);
s->gpr[13] = (s->gpr[13] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d00b4: STEP(0x3d00b4); /* xor r13b, 0xc8 */
x = (s->gpr[13] & UINT64_C(0xff)); y = UINT64_C(0xc8);
s->gpr[13] = (s->gpr[13] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d00b8: STEP(0x3d00b8); /* lea eax, [r13 + r13] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[13] + (s->gpr[13] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d00bd: STEP(0x3d00bd); /* add al, 0xa2 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xa2);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d00bf: STEP(0x3d00bf); /* and al, 0xec */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xec);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d00c1: STEP(0x3d00c1); /* sub r13b, al */
x = (s->gpr[13] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[13] = (s->gpr[13] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d00c4: STEP(0x3d00c4); /* add r13b, 0xc7 */
x = (s->gpr[13] & UINT64_C(0xff)); y = UINT64_C(0xc7);
s->gpr[13] = (s->gpr[13] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d00c8: STEP(0x3d00c8); /* xor r13b, byte ptr [rdx + r8] */
READ(b, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[8] * UINT64_C(0x1))), 1);
x = (s->gpr[13] & UINT64_C(0xff)); y = b;
s->gpr[13] = (s->gpr[13] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d00cc: STEP(0x3d00cc); /* mov dword ptr [rbp - 0x70], r14d */
WRITE((UINT64_C(0xffffffffffffff90) + s->gpr[6]), 4, (s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d00d0: STEP(0x3d00d0); /* movzx eax, r14b */
s->gpr[0] = (uint32_t)((s->gpr[14] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d00d4: STEP(0x3d00d4); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d00d6: STEP(0x3d00d6); /* xor ecx, 0xea */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xea);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d00dc: STEP(0x3d00dc); /* lea edx, [rcx + rcx] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d00df: STEP(0x3d00df); /* and edx, 0x176 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x176);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d00e5: STEP(0x3d00e5); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d00e7: STEP(0x3d00e7); /* add ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d00e9: STEP(0x3d00e9); /* add ecx, 0xb9aeb1bb */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xb9aeb1bb);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d00ef: STEP(0x3d00ef); /* xor ecx, 0x31aff92b */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x31aff92b);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d00f5: STEP(0x3d00f5); /* lea edx, [rcx + rcx] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d00f8: STEP(0x3d00f8); /* and edx, 0x10008e54 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x10008e54);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d00fe: STEP(0x3d00fe); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d0100: STEP(0x3d0100); /* add ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d0102: STEP(0x3d0102); /* add ecx, 0x9a9c472a */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x9a9c472a);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d0108: STEP(0x3d0108); /* not al */
x = (s->gpr[0] & UINT64_C(0xff)); y = 0;
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_NOT, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d010a: STEP(0x3d010a); /* lea edx, [rax + rax] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d010d: STEP(0x3d010d); /* shl al, 2 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x2);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0110: STEP(0x3d0110); /* and al, 0xec */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xec);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0112: STEP(0x3d0112); /* sub dl, al */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0114: STEP(0x3d0114); /* add dl, 0x77 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x77);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0117: STEP(0x3d0117); /* mov ebx, edx */
s->gpr[1] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d0119: STEP(0x3d0119); /* xor bl, 0xa1 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0xa1);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d011c: STEP(0x3d011c); /* add dl, dl */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d011e: STEP(0x3d011e); /* and dl, 0x16 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x16);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0121: STEP(0x3d0121); /* sub bl, dl */
x = (s->gpr[1] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0123: STEP(0x3d0123); /* mov eax, dword ptr [rbp - 0x78] */
READ(a, (UINT64_C(0xffffffffffffff88) + s->gpr[6]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_3d0126: STEP(0x3d0126); /* add eax, 0x4f9a147d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x4f9a147d);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d012b: STEP(0x3d012b); /* xor rcx, 0x129d0f9c */
x = s->gpr[2]; y = UINT64_C(0x129d0f9c);
s->gpr[2] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_3d0132: STEP(0x3d0132); /* add bl, 0x5c */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x5c);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0135: STEP(0x3d0135); /* xor bl, byte ptr [rcx + r8] */
READ(b, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[8] * UINT64_C(0x1))), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0139: STEP(0x3d0139); /* mov byte ptr [rbp - 0x78], bl */
WRITE((UINT64_C(0xffffffffffffff88) + s->gpr[6]), 1, (s->gpr[1] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d013c: STEP(0x3d013c); /* mov rsi, r9 */
s->gpr[4] = s->gpr[9];
++s->steps;
kg_pc_3d013f: STEP(0x3d013f); /* xor esi, eax */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d0141: STEP(0x3d0141); /* movzx r10d, sil */
s->gpr[10] = (uint32_t)((s->gpr[4] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d0145: STEP(0x3d0145); /* mov eax, r10d */
s->gpr[0] = (uint32_t)((s->gpr[10] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d0148: STEP(0x3d0148); /* xor eax, 0x48 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x48);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d014b: STEP(0x3d014b); /* lea ecx, [rsi + rsi] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d014e: STEP(0x3d014e); /* and ecx, 0xe */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xe);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d0151: STEP(0x3d0151); /* sub eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_3d0153: STEP(0x3d0153); /* add eax, 0xc8bcb407 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xc8bcb407);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d0158: STEP(0x3d0158); /* xor eax, 0x40b0a607 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x40b0a607);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d015d: STEP(0x3d015d); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d0160: STEP(0x3d0160); /* and ecx, 0x82528 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x82528);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d0166: STEP(0x3d0166); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d0168: STEP(0x3d0168); /* add ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d016a: STEP(0x3d016a); /* add ecx, 0xe774f294 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xe774f294);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d0170: STEP(0x3d0170); /* add r10b, r10b */
x = (s->gpr[10] & UINT64_C(0xff)); y = (s->gpr[10] & UINT64_C(0xff));
s->gpr[10] = (s->gpr[10] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0173: STEP(0x3d0173); /* xor r10b, 0x98 */
x = (s->gpr[10] & UINT64_C(0xff)); y = UINT64_C(0x98);
s->gpr[10] = (s->gpr[10] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0177: STEP(0x3d0177); /* lea eax, [r10 + r10] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[10] + (s->gpr[10] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d017b: STEP(0x3d017b); /* and al, 0xf8 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xf8);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d017d: STEP(0x3d017d); /* sub r10b, al */
x = (s->gpr[10] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[10] = (s->gpr[10] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0180: STEP(0x3d0180); /* add r10b, 0x7d */
x = (s->gpr[10] & UINT64_C(0xff)); y = UINT64_C(0x7d);
s->gpr[10] = (s->gpr[10] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0184: STEP(0x3d0184); /* xor r10b, 0x9d */
x = (s->gpr[10] & UINT64_C(0xff)); y = UINT64_C(0x9d);
s->gpr[10] = (s->gpr[10] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0188: STEP(0x3d0188); /* lea eax, [r10 + r10] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[10] + (s->gpr[10] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d018c: STEP(0x3d018c); /* add al, 0x22 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x22);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d018e: STEP(0x3d018e); /* and al, 0x7a */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x7a);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0190: STEP(0x3d0190); /* sub r10b, al */
x = (s->gpr[10] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[10] = (s->gpr[10] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0193: STEP(0x3d0193); /* xor rcx, 0x6f78e038 */
x = s->gpr[2]; y = UINT64_C(0x6f78e038);
s->gpr[2] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_3d019a: STEP(0x3d019a); /* add r10b, 0x8e */
x = (s->gpr[10] & UINT64_C(0xff)); y = UINT64_C(0x8e);
s->gpr[10] = (s->gpr[10] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d019e: STEP(0x3d019e); /* xor r10b, byte ptr [rcx + r8] */
READ(b, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[8] * UINT64_C(0x1))), 1);
x = (s->gpr[10] & UINT64_C(0xff)); y = b;
s->gpr[10] = (s->gpr[10] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d01a2: STEP(0x3d01a2); /* mov eax, edi */
s->gpr[0] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d01a4: STEP(0x3d01a4); /* shr eax, 0x10 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_3d01a7: STEP(0x3d01a7); /* movzx eax, al */
s->gpr[0] = (uint32_t)((s->gpr[0] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d01aa: STEP(0x3d01aa); /* xor eax, 0x79 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x79);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d01ad: STEP(0x3d01ad); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d01af: STEP(0x3d01af); /* and ecx, 0x4d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x4d);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d01b2: STEP(0x3d01b2); /* add ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d01b4: STEP(0x3d01b4); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d01b6: STEP(0x3d01b6); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d01b8: STEP(0x3d01b8); /* add eax, 0x58c7c94d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x58c7c94d);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d01bd: STEP(0x3d01bd); /* xor eax, 0x1cdff84d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1cdff84d);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d01c2: STEP(0x3d01c2); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d01c5: STEP(0x3d01c5); /* and ecx, 0x304ec2 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x304ec2);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d01cb: STEP(0x3d01cb); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d01cd: STEP(0x3d01cd); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d01cf: STEP(0x3d01cf); /* add eax, 0x22b9a761 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x22b9a761);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d01d4: STEP(0x3d01d4); /* xor rax, 0x66a196a6 */
x = s->gpr[0]; y = UINT64_C(0x66a196a6);
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_3d01da: STEP(0x3d01da); /* lea rcx, [rip - 0x16f161] */
s->gpr[2] = (UINT64_C(0xffffffffffe90e9f) + (bias + UINT64_C(0x3d01e1)));
++s->steps;
kg_pc_3d01e1: STEP(0x3d01e1); /* mov al, byte ptr [rax + rcx] */
READ(a, (UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1))), 1);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d01e4: STEP(0x3d01e4); /* rol al, 5 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x5);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ROL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d01e7: STEP(0x3d01e7); /* movzx edx, al */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d01ea: STEP(0x3d01ea); /* lea eax, [rdx*8] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + (s->gpr[3] * UINT64_C(0x8))));
++s->steps;
kg_pc_3d01f1: STEP(0x3d01f1); /* lea eax, [rax + rax*8] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x8))));
++s->steps;
kg_pc_3d01f4: STEP(0x3d01f4); /* imul ecx, edx, -0x70 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffffffffff90);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_3d01f7: STEP(0x3d01f7); /* and cl, 0x80 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x80);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d01fa: STEP(0x3d01fa); /* add cl, al */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d01fc: STEP(0x3d01fc); /* add cl, 0x44 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x44);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d01ff: STEP(0x3d01ff); /* xor dl, cl */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0201: STEP(0x3d0201); /* mov rdi, rdx */
s->gpr[5] = s->gpr[3];
++s->steps;
kg_pc_3d0204: STEP(0x3d0204); /* mov eax, r14d */
s->gpr[0] = (uint32_t)((s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d0207: STEP(0x3d0207); /* shr eax, 0x18 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_3d020a: STEP(0x3d020a); /* xor rax, 0xca */
x = s->gpr[0]; y = UINT64_C(0xca);
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_3d0210: STEP(0x3d0210); /* lea rcx, [rip - 0x2c64c7] */
s->gpr[2] = (UINT64_C(0xffffffffffd39b39) + (bias + UINT64_C(0x3d0217)));
++s->steps;
kg_pc_3d0217: STEP(0x3d0217); /* mov r9b, byte ptr [rax + rcx] */
READ(a, (UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1))), 1);
s->gpr[9] = (s->gpr[9] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d021b: STEP(0x3d021b); /* mov r12d, r9d */
s->gpr[12] = (uint32_t)((s->gpr[9] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d021e: STEP(0x3d021e); /* shl r12b, 4 */
x = (s->gpr[12] & UINT64_C(0xff)); y = UINT64_C(0x4);
s->gpr[12] = (s->gpr[12] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0222: STEP(0x3d0222); /* xor r12b, 0xb0 */
x = (s->gpr[12] & UINT64_C(0xff)); y = UINT64_C(0xb0);
s->gpr[12] = (s->gpr[12] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0226: STEP(0x3d0226); /* lea eax, [r12 + r12] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[12] + (s->gpr[12] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d022a: STEP(0x3d022a); /* sub r12b, al */
x = (s->gpr[12] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[12] = (s->gpr[12] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d022d: STEP(0x3d022d); /* mov r14d, esi */
s->gpr[14] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d0230: STEP(0x3d0230); /* shr r14d, 8 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[14] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_3d0234: STEP(0x3d0234); /* movzx eax, r14b */
s->gpr[0] = (uint32_t)((s->gpr[14] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d0238: STEP(0x3d0238); /* xor eax, 0x7c */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x7c);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d023b: STEP(0x3d023b); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d023e: STEP(0x3d023e); /* and ecx, 0xffffff8a */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffff8a);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d0241: STEP(0x3d0241); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d0243: STEP(0x3d0243); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d0245: STEP(0x3d0245); /* add eax, 0x583aafc5 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x583aafc5);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d024a: STEP(0x3d024a); /* xor eax, 0x3a18aec1 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x3a18aec1);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d024f: STEP(0x3d024f); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d0252: STEP(0x3d0252); /* and ecx, 0xc444124c */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xc444124c);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d0258: STEP(0x3d0258); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d025a: STEP(0x3d025a); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d025c: STEP(0x3d025c); /* add eax, 0x73a60926 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x73a60926);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d0261: STEP(0x3d0261); /* xor r14d, 0xc92672 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0xc92672);
s->gpr[14] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d0268: STEP(0x3d0268); /* lea ecx, [r14 + r14] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[14] + (s->gpr[14] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d026c: STEP(0x3d026c); /* add ecx, 0x36 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x36);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d026f: STEP(0x3d026f); /* and ecx, 0x36 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x36);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d0272: STEP(0x3d0272); /* sub r14d, ecx */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[14] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_3d0275: STEP(0x3d0275); /* xor rax, 0x11840801 */
x = s->gpr[0]; y = UINT64_C(0x11840801);
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_3d027b: STEP(0x3d027b); /* lea rcx, [rip - 0x2f40f2] */
s->gpr[2] = (UINT64_C(0xffffffffffd0bf0e) + (bias + UINT64_C(0x3d0282)));
++s->steps;
kg_pc_3d0282: STEP(0x3d0282); /* mov al, byte ptr [rax + rcx] */
READ(a, (UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1))), 1);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0285: STEP(0x3d0285); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d0287: STEP(0x3d0287); /* or cl, 0xfb */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xfb);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_OR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d028a: STEP(0x3d028a); /* lea edx, [rax + rax] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d028d: STEP(0x3d028d); /* not dl */
x = (s->gpr[3] & UINT64_C(0xff)); y = 0;
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_NOT, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d028f: STEP(0x3d028f); /* and dl, 8 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x8);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0292: STEP(0x3d0292); /* add dl, cl */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0294: STEP(0x3d0294); /* add r14b, 0x16 */
x = (s->gpr[14] & UINT64_C(0xff)); y = UINT64_C(0x16);
s->gpr[14] = (s->gpr[14] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0298: STEP(0x3d0298); /* mov ecx, r14d */
s->gpr[2] = (uint32_t)((s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d029b: STEP(0x3d029b); /* xor cl, 0x2d */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x2d);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d029e: STEP(0x3d029e); /* lea r8d, [r14 + r14] */
s->gpr[8] = (uint32_t)((UINT64_C(0x0) + s->gpr[14] + (s->gpr[14] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d02a2: STEP(0x3d02a2); /* mov ebx, r8d */
s->gpr[1] = (uint32_t)((s->gpr[8] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d02a5: STEP(0x3d02a5); /* and bl, 0x6c */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x6c);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02a8: STEP(0x3d02a8); /* xor bl, 0x24 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x24);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02ab: STEP(0x3d02ab); /* add cl, dl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02ad: STEP(0x3d02ad); /* add cl, bl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[1] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02af: STEP(0x3d02af); /* lea ebx, [rcx + rcx] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d02b2: STEP(0x3d02b2); /* add bl, 0x16 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x16);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02b5: STEP(0x3d02b5); /* and bl, 0x14 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x14);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02b8: STEP(0x3d02b8); /* sub cl, bl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[1] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02ba: STEP(0x3d02ba); /* mov r11d, r14d */
s->gpr[11] = (uint32_t)((s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d02bd: STEP(0x3d02bd); /* xor r11b, 0x18 */
x = (s->gpr[11] & UINT64_C(0xff)); y = UINT64_C(0x18);
s->gpr[11] = (s->gpr[11] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02c1: STEP(0x3d02c1); /* lea ebx, [rdx + 1] */
s->gpr[1] = (uint32_t)((UINT64_C(0x1) + s->gpr[3]));
++s->steps;
kg_pc_3d02c4: STEP(0x3d02c4); /* and r11b, bl */
x = (s->gpr[11] & UINT64_C(0xff)); y = (s->gpr[1] & UINT64_C(0xff));
s->gpr[11] = (s->gpr[11] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02c7: STEP(0x3d02c7); /* xor r14b, 0xc4 */
x = (s->gpr[14] & UINT64_C(0xff)); y = UINT64_C(0xc4);
s->gpr[14] = (s->gpr[14] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02cb: STEP(0x3d02cb); /* sub r14b, dl */
x = (s->gpr[14] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[14] = (s->gpr[14] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02ce: STEP(0x3d02ce); /* and r8b, 0xbe */
x = (s->gpr[8] & UINT64_C(0xff)); y = UINT64_C(0xbe);
s->gpr[8] = (s->gpr[8] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02d2: STEP(0x3d02d2); /* xor r8b, 0x36 */
x = (s->gpr[8] & UINT64_C(0xff)); y = UINT64_C(0x36);
s->gpr[8] = (s->gpr[8] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02d6: STEP(0x3d02d6); /* add r14b, r8b */
x = (s->gpr[14] & UINT64_C(0xff)); y = (s->gpr[8] & UINT64_C(0xff));
s->gpr[14] = (s->gpr[14] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02d9: STEP(0x3d02d9); /* add r14b, 0x20 */
x = (s->gpr[14] & UINT64_C(0xff)); y = UINT64_C(0x20);
s->gpr[14] = (s->gpr[14] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02dd: STEP(0x3d02dd); /* lea edx, [r14 + r14] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[14] + (s->gpr[14] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d02e1: STEP(0x3d02e1); /* and dl, 0x14 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x14);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02e4: STEP(0x3d02e4); /* sub r14b, dl */
x = (s->gpr[14] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[14] = (s->gpr[14] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d02e7: STEP(0x3d02e7); /* mov qword ptr [rbp - 0x80], rsi */
WRITE((UINT64_C(0xffffffffffffff80) + s->gpr[6]), 8, s->gpr[4]);
++s->steps;
kg_pc_3d02eb: STEP(0x3d02eb); /* mov edx, esi */
s->gpr[3] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d02ed: STEP(0x3d02ed); /* shr edx, 0x18 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_3d02f0: STEP(0x3d02f0); /* xor rdx, 0xd4 */
x = s->gpr[3]; y = UINT64_C(0xd4);
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_3d02f7: STEP(0x3d02f7); /* lea rbx, [rip - 0x2c65ae] */
s->gpr[1] = (UINT64_C(0xffffffffffd39a52) + (bias + UINT64_C(0x3d02fe)));
++s->steps;
kg_pc_3d02fe: STEP(0x3d02fe); /* mov r8b, byte ptr [rdx + rbx] */
READ(a, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[1] * UINT64_C(0x1))), 1);
s->gpr[8] = (s->gpr[8] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;

break;
case 1:
next_pc=bias+UINT64_C(0x3d05c1);
switch(s->pc-bias){
case UINT64_C(0x3d0302):goto kg_pc_3d0302;
case UINT64_C(0x3d0305):goto kg_pc_3d0305;
case UINT64_C(0x3d0308):goto kg_pc_3d0308;
case UINT64_C(0x3d030b):goto kg_pc_3d030b;
case UINT64_C(0x3d030e):goto kg_pc_3d030e;
case UINT64_C(0x3d0311):goto kg_pc_3d0311;
case UINT64_C(0x3d0314):goto kg_pc_3d0314;
case UINT64_C(0x3d0316):goto kg_pc_3d0316;
case UINT64_C(0x3d0319):goto kg_pc_3d0319;
case UINT64_C(0x3d031c):goto kg_pc_3d031c;
case UINT64_C(0x3d0320):goto kg_pc_3d0320;
case UINT64_C(0x3d0323):goto kg_pc_3d0323;
case UINT64_C(0x3d0325):goto kg_pc_3d0325;
case UINT64_C(0x3d0328):goto kg_pc_3d0328;
case UINT64_C(0x3d032e):goto kg_pc_3d032e;
case UINT64_C(0x3d0331):goto kg_pc_3d0331;
case UINT64_C(0x3d0334):goto kg_pc_3d0334;
case UINT64_C(0x3d033a):goto kg_pc_3d033a;
case UINT64_C(0x3d0341):goto kg_pc_3d0341;
case UINT64_C(0x3d0345):goto kg_pc_3d0345;
case UINT64_C(0x3d034c):goto kg_pc_3d034c;
case UINT64_C(0x3d0350):goto kg_pc_3d0350;
case UINT64_C(0x3d0354):goto kg_pc_3d0354;
case UINT64_C(0x3d0357):goto kg_pc_3d0357;
case UINT64_C(0x3d035a):goto kg_pc_3d035a;
case UINT64_C(0x3d035e):goto kg_pc_3d035e;
case UINT64_C(0x3d0362):goto kg_pc_3d0362;
case UINT64_C(0x3d0366):goto kg_pc_3d0366;
case UINT64_C(0x3d036a):goto kg_pc_3d036a;
case UINT64_C(0x3d036e):goto kg_pc_3d036e;
case UINT64_C(0x3d0372):goto kg_pc_3d0372;
case UINT64_C(0x3d0375):goto kg_pc_3d0375;
case UINT64_C(0x3d0379):goto kg_pc_3d0379;
case UINT64_C(0x3d037c):goto kg_pc_3d037c;
case UINT64_C(0x3d0380):goto kg_pc_3d0380;
case UINT64_C(0x3d0383):goto kg_pc_3d0383;
case UINT64_C(0x3d0387):goto kg_pc_3d0387;
case UINT64_C(0x3d038b):goto kg_pc_3d038b;
case UINT64_C(0x3d038f):goto kg_pc_3d038f;
case UINT64_C(0x3d0396):goto kg_pc_3d0396;
case UINT64_C(0x3d0399):goto kg_pc_3d0399;
case UINT64_C(0x3d039d):goto kg_pc_3d039d;
case UINT64_C(0x3d03a4):goto kg_pc_3d03a4;
case UINT64_C(0x3d03a8):goto kg_pc_3d03a8;
case UINT64_C(0x3d03ac):goto kg_pc_3d03ac;
case UINT64_C(0x3d03b0):goto kg_pc_3d03b0;
case UINT64_C(0x3d03b4):goto kg_pc_3d03b4;
case UINT64_C(0x3d03b7):goto kg_pc_3d03b7;
case UINT64_C(0x3d03bb):goto kg_pc_3d03bb;
case UINT64_C(0x3d03be):goto kg_pc_3d03be;
case UINT64_C(0x3d03c0):goto kg_pc_3d03c0;
case UINT64_C(0x3d03c2):goto kg_pc_3d03c2;
case UINT64_C(0x3d03c5):goto kg_pc_3d03c5;
case UINT64_C(0x3d03c8):goto kg_pc_3d03c8;
case UINT64_C(0x3d03ca):goto kg_pc_3d03ca;
case UINT64_C(0x3d03cc):goto kg_pc_3d03cc;
case UINT64_C(0x3d03ce):goto kg_pc_3d03ce;
case UINT64_C(0x3d03d1):goto kg_pc_3d03d1;
case UINT64_C(0x3d03d4):goto kg_pc_3d03d4;
case UINT64_C(0x3d03d6):goto kg_pc_3d03d6;
case UINT64_C(0x3d03d8):goto kg_pc_3d03d8;
case UINT64_C(0x3d03da):goto kg_pc_3d03da;
case UINT64_C(0x3d03dc):goto kg_pc_3d03dc;
case UINT64_C(0x3d03df):goto kg_pc_3d03df;
case UINT64_C(0x3d03e6):goto kg_pc_3d03e6;
case UINT64_C(0x3d03e8):goto kg_pc_3d03e8;
case UINT64_C(0x3d03eb):goto kg_pc_3d03eb;
case UINT64_C(0x3d03ee):goto kg_pc_3d03ee;
case UINT64_C(0x3d03f4):goto kg_pc_3d03f4;
case UINT64_C(0x3d03f6):goto kg_pc_3d03f6;
case UINT64_C(0x3d03f8):goto kg_pc_3d03f8;
case UINT64_C(0x3d03fd):goto kg_pc_3d03fd;
case UINT64_C(0x3d0402):goto kg_pc_3d0402;
case UINT64_C(0x3d0405):goto kg_pc_3d0405;
case UINT64_C(0x3d040b):goto kg_pc_3d040b;
case UINT64_C(0x3d040d):goto kg_pc_3d040d;
case UINT64_C(0x3d040f):goto kg_pc_3d040f;
case UINT64_C(0x3d0415):goto kg_pc_3d0415;
case UINT64_C(0x3d0418):goto kg_pc_3d0418;
case UINT64_C(0x3d041b):goto kg_pc_3d041b;
case UINT64_C(0x3d041d):goto kg_pc_3d041d;
case UINT64_C(0x3d0420):goto kg_pc_3d0420;
case UINT64_C(0x3d0422):goto kg_pc_3d0422;
case UINT64_C(0x3d0424):goto kg_pc_3d0424;
case UINT64_C(0x3d042b):goto kg_pc_3d042b;
case UINT64_C(0x3d042d):goto kg_pc_3d042d;
case UINT64_C(0x3d0434):goto kg_pc_3d0434;
case UINT64_C(0x3d0437):goto kg_pc_3d0437;
case UINT64_C(0x3d043b):goto kg_pc_3d043b;
case UINT64_C(0x3d043e):goto kg_pc_3d043e;
case UINT64_C(0x3d0441):goto kg_pc_3d0441;
case UINT64_C(0x3d0444):goto kg_pc_3d0444;
case UINT64_C(0x3d044a):goto kg_pc_3d044a;
case UINT64_C(0x3d044d):goto kg_pc_3d044d;
case UINT64_C(0x3d0450):goto kg_pc_3d0450;
case UINT64_C(0x3d0452):goto kg_pc_3d0452;
case UINT64_C(0x3d0454):goto kg_pc_3d0454;
case UINT64_C(0x3d045a):goto kg_pc_3d045a;
case UINT64_C(0x3d0460):goto kg_pc_3d0460;
case UINT64_C(0x3d0463):goto kg_pc_3d0463;
case UINT64_C(0x3d0469):goto kg_pc_3d0469;
case UINT64_C(0x3d046b):goto kg_pc_3d046b;
case UINT64_C(0x3d046d):goto kg_pc_3d046d;
case UINT64_C(0x3d0473):goto kg_pc_3d0473;
case UINT64_C(0x3d047a):goto kg_pc_3d047a;
case UINT64_C(0x3d047d):goto kg_pc_3d047d;
case UINT64_C(0x3d0484):goto kg_pc_3d0484;
case UINT64_C(0x3d048b):goto kg_pc_3d048b;
case UINT64_C(0x3d048f):goto kg_pc_3d048f;
case UINT64_C(0x3d0496):goto kg_pc_3d0496;
case UINT64_C(0x3d0499):goto kg_pc_3d0499;
case UINT64_C(0x3d049d):goto kg_pc_3d049d;
case UINT64_C(0x3d04a0):goto kg_pc_3d04a0;
case UINT64_C(0x3d04a6):goto kg_pc_3d04a6;
case UINT64_C(0x3d04a8):goto kg_pc_3d04a8;
case UINT64_C(0x3d04ae):goto kg_pc_3d04ae;
case UINT64_C(0x3d04b4):goto kg_pc_3d04b4;
case UINT64_C(0x3d04b7):goto kg_pc_3d04b7;
case UINT64_C(0x3d04bd):goto kg_pc_3d04bd;
case UINT64_C(0x3d04bf):goto kg_pc_3d04bf;
case UINT64_C(0x3d04c1):goto kg_pc_3d04c1;
case UINT64_C(0x3d04c7):goto kg_pc_3d04c7;
case UINT64_C(0x3d04ca):goto kg_pc_3d04ca;
case UINT64_C(0x3d04ce):goto kg_pc_3d04ce;
case UINT64_C(0x3d04d2):goto kg_pc_3d04d2;
case UINT64_C(0x3d04d6):goto kg_pc_3d04d6;
case UINT64_C(0x3d04da):goto kg_pc_3d04da;
case UINT64_C(0x3d04dd):goto kg_pc_3d04dd;
case UINT64_C(0x3d04e0):goto kg_pc_3d04e0;
case UINT64_C(0x3d04e3):goto kg_pc_3d04e3;
case UINT64_C(0x3d04e6):goto kg_pc_3d04e6;
case UINT64_C(0x3d04e9):goto kg_pc_3d04e9;
case UINT64_C(0x3d04ec):goto kg_pc_3d04ec;
case UINT64_C(0x3d04ef):goto kg_pc_3d04ef;
case UINT64_C(0x3d04f1):goto kg_pc_3d04f1;
case UINT64_C(0x3d04f3):goto kg_pc_3d04f3;
case UINT64_C(0x3d04f9):goto kg_pc_3d04f9;
case UINT64_C(0x3d04ff):goto kg_pc_3d04ff;
case UINT64_C(0x3d0502):goto kg_pc_3d0502;
case UINT64_C(0x3d0508):goto kg_pc_3d0508;
case UINT64_C(0x3d050a):goto kg_pc_3d050a;
case UINT64_C(0x3d050c):goto kg_pc_3d050c;
case UINT64_C(0x3d0512):goto kg_pc_3d0512;
case UINT64_C(0x3d0517):goto kg_pc_3d0517;
case UINT64_C(0x3d051a):goto kg_pc_3d051a;
case UINT64_C(0x3d051c):goto kg_pc_3d051c;
case UINT64_C(0x3d051f):goto kg_pc_3d051f;
case UINT64_C(0x3d0526):goto kg_pc_3d0526;
case UINT64_C(0x3d052d):goto kg_pc_3d052d;
case UINT64_C(0x3d0530):goto kg_pc_3d0530;
case UINT64_C(0x3d0534):goto kg_pc_3d0534;
case UINT64_C(0x3d0537):goto kg_pc_3d0537;
case UINT64_C(0x3d053a):goto kg_pc_3d053a;
case UINT64_C(0x3d0541):goto kg_pc_3d0541;
case UINT64_C(0x3d0544):goto kg_pc_3d0544;
case UINT64_C(0x3d0547):goto kg_pc_3d0547;
case UINT64_C(0x3d054a):goto kg_pc_3d054a;
case UINT64_C(0x3d054d):goto kg_pc_3d054d;
case UINT64_C(0x3d0550):goto kg_pc_3d0550;
case UINT64_C(0x3d0553):goto kg_pc_3d0553;
case UINT64_C(0x3d0556):goto kg_pc_3d0556;
case UINT64_C(0x3d0559):goto kg_pc_3d0559;
case UINT64_C(0x3d055c):goto kg_pc_3d055c;
case UINT64_C(0x3d0560):goto kg_pc_3d0560;
case UINT64_C(0x3d0564):goto kg_pc_3d0564;
case UINT64_C(0x3d0566):goto kg_pc_3d0566;
case UINT64_C(0x3d0569):goto kg_pc_3d0569;
case UINT64_C(0x3d056b):goto kg_pc_3d056b;
case UINT64_C(0x3d0572):goto kg_pc_3d0572;
case UINT64_C(0x3d0575):goto kg_pc_3d0575;
case UINT64_C(0x3d0578):goto kg_pc_3d0578;
case UINT64_C(0x3d057c):goto kg_pc_3d057c;
case UINT64_C(0x3d057f):goto kg_pc_3d057f;
case UINT64_C(0x3d0582):goto kg_pc_3d0582;
case UINT64_C(0x3d0585):goto kg_pc_3d0585;
case UINT64_C(0x3d0589):goto kg_pc_3d0589;
case UINT64_C(0x3d058d):goto kg_pc_3d058d;
case UINT64_C(0x3d0591):goto kg_pc_3d0591;
case UINT64_C(0x3d0595):goto kg_pc_3d0595;
case UINT64_C(0x3d059c):goto kg_pc_3d059c;
case UINT64_C(0x3d059f):goto kg_pc_3d059f;
case UINT64_C(0x3d05a2):goto kg_pc_3d05a2;
case UINT64_C(0x3d05a6):goto kg_pc_3d05a6;
case UINT64_C(0x3d05a9):goto kg_pc_3d05a9;
case UINT64_C(0x3d05ac):goto kg_pc_3d05ac;
case UINT64_C(0x3d05ae):goto kg_pc_3d05ae;
case UINT64_C(0x3d05b1):goto kg_pc_3d05b1;
case UINT64_C(0x3d05b4):goto kg_pc_3d05b4;
case UINT64_C(0x3d05bb):goto kg_pc_3d05bb;
case UINT64_C(0x3d05be):goto kg_pc_3d05be;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1578: [0x3d0302,0x3d05c1), 190 instructions. */
kg_pc_3d0302: STEP(0x3d0302); /* mov edx, r8d */
s->gpr[3] = (uint32_t)((s->gpr[8] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d0305: STEP(0x3d0305); /* shl dl, 4 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x4);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0308: STEP(0x3d0308); /* xor dl, 0xb0 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0xb0);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d030b: STEP(0x3d030b); /* mov ebx, r8d */
s->gpr[1] = (uint32_t)((s->gpr[8] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d030e: STEP(0x3d030e); /* shl bl, 5 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x5);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0311: STEP(0x3d0311); /* or bl, 0x9f */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x9f);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_OR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0314: STEP(0x3d0314); /* add bl, dl */
x = (s->gpr[1] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0316: STEP(0x3d0316); /* add bl, 0x35 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x35);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0319: STEP(0x3d0319); /* xor bl, r8b */
x = (s->gpr[1] & UINT64_C(0xff)); y = (s->gpr[8] & UINT64_C(0xff));
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d031c: STEP(0x3d031c); /* add r12b, 0x72 */
x = (s->gpr[12] & UINT64_C(0xff)); y = UINT64_C(0x72);
s->gpr[12] = (s->gpr[12] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0320: STEP(0x3d0320); /* xor r12b, r9b */
x = (s->gpr[12] & UINT64_C(0xff)); y = (s->gpr[9] & UINT64_C(0xff));
s->gpr[12] = (s->gpr[12] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0323: STEP(0x3d0323); /* mov edx, esi */
s->gpr[3] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d0325: STEP(0x3d0325); /* shr edx, 0x10 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_3d0328: STEP(0x3d0328); /* mov dword ptr [rbp - 0xd0], edx */
WRITE((UINT64_C(0xffffffffffffff30) + s->gpr[6]), 4, (s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d032e: STEP(0x3d032e); /* mov edx, dword ptr [rbp - 0x70] */
READ(a, (UINT64_C(0xffffffffffffff90) + s->gpr[6]), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_3d0331: STEP(0x3d0331); /* shr edx, 8 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_3d0334: STEP(0x3d0334); /* mov dword ptr [rbp - 0xb0], edx */
WRITE((UINT64_C(0xffffffffffffff50) + s->gpr[6]), 4, (s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d033a: STEP(0x3d033a); /* mov r9, qword ptr [rbp - 0xf8] */
READ(a, (UINT64_C(0xffffffffffffff08) + s->gpr[6]), 8);
s->gpr[9] = a;
++s->steps;
kg_pc_3d0341: STEP(0x3d0341); /* xor r9b, 0x96 */
x = (s->gpr[9] & UINT64_C(0xff)); y = UINT64_C(0x96);
s->gpr[9] = (s->gpr[9] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0345: STEP(0x3d0345); /* mov rsi, qword ptr [rbp - 0xb8] */
READ(a, (UINT64_C(0xffffffffffffff48) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_3d034c: STEP(0x3d034c); /* xor sil, 0x88 */
x = (s->gpr[4] & UINT64_C(0xff)); y = UINT64_C(0x88);
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0350: STEP(0x3d0350); /* xor r15b, 7 */
x = (s->gpr[15] & UINT64_C(0xff)); y = UINT64_C(0x7);
s->gpr[15] = (s->gpr[15] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0354: STEP(0x3d0354); /* xor bl, 0x36 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x36);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0357: STEP(0x3d0357); /* mov r8, rdi */
s->gpr[8] = s->gpr[5];
++s->steps;
kg_pc_3d035a: STEP(0x3d035a); /* xor r8b, 0xc9 */
x = (s->gpr[8] & UINT64_C(0xff)); y = UINT64_C(0xc9);
s->gpr[8] = (s->gpr[8] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d035e: STEP(0x3d035e); /* xor r13b, 0xa2 */
x = (s->gpr[13] & UINT64_C(0xff)); y = UINT64_C(0xa2);
s->gpr[13] = (s->gpr[13] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0362: STEP(0x3d0362); /* mov dil, byte ptr [rbp - 0x78] */
READ(a, (UINT64_C(0xffffffffffffff88) + s->gpr[6]), 1);
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0366: STEP(0x3d0366); /* xor dil, 0x2b */
x = (s->gpr[5] & UINT64_C(0xff)); y = UINT64_C(0x2b);
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d036a: STEP(0x3d036a); /* xor r12b, 0x9a */
x = (s->gpr[12] & UINT64_C(0xff)); y = UINT64_C(0x9a);
s->gpr[12] = (s->gpr[12] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d036e: STEP(0x3d036e); /* xor r10b, 0xa8 */
x = (s->gpr[10] & UINT64_C(0xff)); y = UINT64_C(0xa8);
s->gpr[10] = (s->gpr[10] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0372: STEP(0x3d0372); /* add cl, 0xd5 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xd5);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0375: STEP(0x3d0375); /* lea edx, [r11 + r11] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[11] + (s->gpr[11] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d0379: STEP(0x3d0379); /* and dl, 0x80 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x80);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d037c: STEP(0x3d037c); /* add r14b, 0xa */
x = (s->gpr[14] & UINT64_C(0xff)); y = UINT64_C(0xa);
s->gpr[14] = (s->gpr[14] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0380: STEP(0x3d0380); /* add dl, r11b */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[11] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0383: STEP(0x3d0383); /* mov byte ptr [rbp - 0x45], r9b */
WRITE((UINT64_C(0xffffffffffffffbb) + s->gpr[6]), 1, (s->gpr[9] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d0387: STEP(0x3d0387); /* mov byte ptr [rbp - 0x46], sil */
WRITE((UINT64_C(0xffffffffffffffba) + s->gpr[6]), 1, (s->gpr[4] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d038b: STEP(0x3d038b); /* mov byte ptr [rbp - 0x4a], r15b */
WRITE((UINT64_C(0xffffffffffffffb6) + s->gpr[6]), 1, (s->gpr[15] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d038f: STEP(0x3d038f); /* mov r11, qword ptr [rbp - 0x268] */
READ(a, (UINT64_C(0xfffffffffffffd98) + s->gpr[6]), 8);
s->gpr[11] = a;
++s->steps;
kg_pc_3d0396: STEP(0x3d0396); /* mov byte ptr [rbp - 0x50], bl */
WRITE((UINT64_C(0xffffffffffffffb0) + s->gpr[6]), 1, (s->gpr[1] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d0399: STEP(0x3d0399); /* mov byte ptr [rbp - 0x4b], r8b */
WRITE((UINT64_C(0xffffffffffffffb5) + s->gpr[6]), 1, (s->gpr[8] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d039d: STEP(0x3d039d); /* lea r15, [rip - 0x39d6b4] */
s->gpr[15] = (UINT64_C(0xffffffffffc6294c) + (bias + UINT64_C(0x3d03a4)));
++s->steps;
kg_pc_3d03a4: STEP(0x3d03a4); /* mov byte ptr [rbp - 0x49], r13b */
WRITE((UINT64_C(0xffffffffffffffb7) + s->gpr[6]), 1, (s->gpr[13] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d03a8: STEP(0x3d03a8); /* mov byte ptr [rbp - 0x41], dil */
WRITE((UINT64_C(0xffffffffffffffbf) + s->gpr[6]), 1, (s->gpr[5] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d03ac: STEP(0x3d03ac); /* mov byte ptr [rbp - 0x44], r12b */
WRITE((UINT64_C(0xffffffffffffffbc) + s->gpr[6]), 1, (s->gpr[12] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d03b0: STEP(0x3d03b0); /* mov byte ptr [rbp - 0x4d], r10b */
WRITE((UINT64_C(0xffffffffffffffb3) + s->gpr[6]), 1, (s->gpr[10] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d03b4: STEP(0x3d03b4); /* movzx ecx, cl */
s->gpr[2] = (uint32_t)((s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d03b7: STEP(0x3d03b7); /* movzx edx, r14b */
s->gpr[3] = (uint32_t)((s->gpr[14] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d03bb: STEP(0x3d03bb); /* cmove edx, ecx */
s->gpr[3] = (uint32_t)((condition(s, COND_E) ? (s->gpr[2] & UINT64_C(0xffffffff)) : (s->gpr[3] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_3d03be: STEP(0x3d03be); /* and al, 0xfb */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xfb);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d03c0: STEP(0x3d03c0); /* xor al, 0xca */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xca);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d03c2: STEP(0x3d03c2); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d03c5: STEP(0x3d03c5); /* and cl, 0x32 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x32);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d03c8: STEP(0x3d03c8); /* sub al, cl */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d03ca: STEP(0x3d03ca); /* add al, 0x99 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x99);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d03cc: STEP(0x3d03cc); /* xor al, 0x11 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x11);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d03ce: STEP(0x3d03ce); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d03d1: STEP(0x3d03d1); /* and cl, 6 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x6);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d03d4: STEP(0x3d03d4); /* sub al, cl */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d03d6: STEP(0x3d03d6); /* add al, 3 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x3);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d03d8: STEP(0x3d03d8); /* xor al, dl */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d03da: STEP(0x3d03da); /* xor al, 0x50 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x50);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d03dc: STEP(0x3d03dc); /* mov byte ptr [rbp - 0x4e], al */
WRITE((UINT64_C(0xffffffffffffffb2) + s->gpr[6]), 1, (s->gpr[0] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d03df: STEP(0x3d03df); /* movzx ecx, byte ptr [rbp - 0xb0] */
READ(a, (UINT64_C(0xffffffffffffff50) + s->gpr[6]), 1);
s->gpr[2] = (uint32_t)(a);
++s->steps;
kg_pc_3d03e6: STEP(0x3d03e6); /* mov eax, ecx */
s->gpr[0] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d03e8: STEP(0x3d03e8); /* xor eax, 0x59 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x59);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d03eb: STEP(0x3d03eb); /* lea edx, [rax + rax] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d03ee: STEP(0x3d03ee); /* and edx, 0x16e */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x16e);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d03f4: STEP(0x3d03f4); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d03f6: STEP(0x3d03f6); /* add eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d03f8: STEP(0x3d03f8); /* add eax, 0x1cd54fb7 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1cd54fb7);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d03fd: STEP(0x3d03fd); /* xor eax, 0xccf5a1d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xccf5a1d);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d0402: STEP(0x3d0402); /* lea edx, [rax + rax] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d0405: STEP(0x3d0405); /* and edx, 0x20045238 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x20045238);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d040b: STEP(0x3d040b); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d040d: STEP(0x3d040d); /* add edx, eax */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d040f: STEP(0x3d040f); /* add edx, 0x59c6291c */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x59c6291c);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d0415: STEP(0x3d0415); /* xor cl, 0xc6 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xc6);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0418: STEP(0x3d0418); /* lea esi, [rcx + rcx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d041b: STEP(0x3d041b); /* mov al, 8 */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((UINT64_C(0x8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d041d: STEP(0x3d041d); /* sub al, sil */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[4] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0420: STEP(0x3d0420); /* or al, 0x25 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x25);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_OR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0422: STEP(0x3d0422); /* add al, cl */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0424: STEP(0x3d0424); /* xor rdx, 0x49dc3c04 */
x = s->gpr[3]; y = UINT64_C(0x49dc3c04);
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_3d042b: STEP(0x3d042b); /* add al, 0x69 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x69);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d042d: STEP(0x3d042d); /* lea rcx, [rip - 0x2f42a4] */
s->gpr[2] = (UINT64_C(0xffffffffffd0bd5c) + (bias + UINT64_C(0x3d0434)));
++s->steps;
kg_pc_3d0434: STEP(0x3d0434); /* xor al, byte ptr [rdx + rcx] */
READ(b, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x1))), 1);
x = (s->gpr[0] & UINT64_C(0xff)); y = b;
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0437: STEP(0x3d0437); /* mov r10, qword ptr [rbp - 0x68] */
READ(a, (UINT64_C(0xffffffffffffff98) + s->gpr[6]), 8);
s->gpr[10] = a;
++s->steps;
kg_pc_3d043b: STEP(0x3d043b); /* mov ecx, r10d */
s->gpr[2] = (uint32_t)((s->gpr[10] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d043e: STEP(0x3d043e); /* shr ecx, 0x10 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[2] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_3d0441: STEP(0x3d0441); /* movzx ecx, cl */
s->gpr[2] = (uint32_t)((s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d0444: STEP(0x3d0444); /* xor ecx, 0xee */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xee);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d044a: STEP(0x3d044a); /* lea edx, [rcx + rcx] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d044d: STEP(0x3d044d); /* and edx, 0xffffffda */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffda);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d0450: STEP(0x3d0450); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d0452: STEP(0x3d0452); /* add ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d0454: STEP(0x3d0454); /* add ecx, 0x2b7843ed */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x2b7843ed);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d045a: STEP(0x3d045a); /* xor ecx, 0xb5463ef */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xb5463ef);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d0460: STEP(0x3d0460); /* lea edx, [rcx + rcx] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d0463: STEP(0x3d0463); /* and edx, 0x404872c8 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x404872c8);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d0469: STEP(0x3d0469); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d046b: STEP(0x3d046b); /* add ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d046d: STEP(0x3d046d); /* add ecx, 0x6065b964 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x6065b964);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d0473: STEP(0x3d0473); /* mov rdx, qword ptr [rbp - 0xd8] */
READ(a, (UINT64_C(0xffffffffffffff28) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_3d047a: STEP(0x3d047a); /* shr edx, 0x18 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_3d047d: STEP(0x3d047d); /* xor rdx, 0x9c */
x = s->gpr[3]; y = UINT64_C(0x9c);
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_3d0484: STEP(0x3d0484); /* lea r14, [rip - 0x2c673b] */
s->gpr[14] = (UINT64_C(0xffffffffffd398c5) + (bias + UINT64_C(0x3d048b)));
++s->steps;
kg_pc_3d048b: STEP(0x3d048b); /* mov r8b, byte ptr [rdx + r14] */
READ(a, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[14] * UINT64_C(0x1))), 1);
s->gpr[8] = (s->gpr[8] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d048f: STEP(0x3d048f); /* movzx edx, byte ptr [rbp - 0xd0] */
READ(a, (UINT64_C(0xffffffffffffff30) + s->gpr[6]), 1);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_3d0496: STEP(0x3d0496); /* xor edx, 0x40 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x40);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d0499: STEP(0x3d0499); /* mov rsi, qword ptr [rbp - 0x80] */
READ(a, (UINT64_C(0xffffffffffffff80) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_3d049d: STEP(0x3d049d); /* shr esi, 0xf */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xf);
s->gpr[4] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_3d04a0: STEP(0x3d04a0); /* and esi, 0x13c */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x13c);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d04a6: STEP(0x3d04a6); /* sub edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_3d04a8: STEP(0x3d04a8); /* add edx, 0x1565a9e */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1565a9e);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d04ae: STEP(0x3d04ae); /* xor edx, 0x505af8 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x505af8);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d04b4: STEP(0x3d04b4); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d04b7: STEP(0x3d04b7); /* and esi, 0xc06ce */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xc06ce);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d04bd: STEP(0x3d04bd); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d04bf: STEP(0x3d04bf); /* add esi, edx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d04c1: STEP(0x3d04c1); /* add esi, 0x3c1e2f67 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x3c1e2f67);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d04c7: STEP(0x3d04c7); /* mov edi, r8d */
s->gpr[5] = (uint32_t)((s->gpr[8] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d04ca: STEP(0x3d04ca); /* shl dil, 4 */
x = (s->gpr[5] & UINT64_C(0xff)); y = UINT64_C(0x4);
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d04ce: STEP(0x3d04ce); /* xor dil, 0xb0 */
x = (s->gpr[5] & UINT64_C(0xff)); y = UINT64_C(0xb0);
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d04d2: STEP(0x3d04d2); /* lea r9d, [rdi + rdi] */
s->gpr[9] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d04d6: STEP(0x3d04d6); /* and r9b, 0x60 */
x = (s->gpr[9] & UINT64_C(0xff)); y = UINT64_C(0x60);
s->gpr[9] = (s->gpr[9] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d04da: STEP(0x3d04da); /* sub r9b, dil */
x = (s->gpr[9] & UINT64_C(0xff)); y = (s->gpr[5] & UINT64_C(0xff));
s->gpr[9] = (s->gpr[9] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d04dd: STEP(0x3d04dd); /* mov edx, dword ptr [rbp - 0x70] */
READ(a, (UINT64_C(0xffffffffffffff90) + s->gpr[6]), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_3d04e0: STEP(0x3d04e0); /* shr edx, 0x10 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_3d04e3: STEP(0x3d04e3); /* movzx edi, dl */
s->gpr[5] = (uint32_t)((s->gpr[3] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d04e6: STEP(0x3d04e6); /* xor edi, 7 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x7);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d04e9: STEP(0x3d04e9); /* lea ebx, [rdi + rdi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d04ec: STEP(0x3d04ec); /* and ebx, 0xffffff9e */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffff9e);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d04ef: STEP(0x3d04ef); /* neg ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = 0;
s->gpr[1] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d04f1: STEP(0x3d04f1); /* add edi, ebx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d04f3: STEP(0x3d04f3); /* add edi, 0x92d68dcf */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x92d68dcf);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d04f9: STEP(0x3d04f9); /* xor edi, 0x1404be8f */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x1404be8f);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d04ff: STEP(0x3d04ff); /* lea ebx, [rdi + rdi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d0502: STEP(0x3d0502); /* and ebx, 0xa422bc */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0xa422bc);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d0508: STEP(0x3d0508); /* neg ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = 0;
s->gpr[1] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d050a: STEP(0x3d050a); /* add edi, ebx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d050c: STEP(0x3d050c); /* add edi, 0x17e995e */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x17e995e);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d0512: STEP(0x3d0512); /* mov ebx, 0x87acaa93 */
s->gpr[1] = (uint32_t)(UINT64_C(0x87acaa93));
++s->steps;
kg_pc_3d0517: STEP(0x3d0517); /* xor rbx, rdi */
x = s->gpr[1]; y = s->gpr[5];
s->gpr[1] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_3d051a: STEP(0x3d051a); /* xor al, 0x96 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x96);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d051c: STEP(0x3d051c); /* mov byte ptr [rbp - 0x42], al */
WRITE((UINT64_C(0xffffffffffffffbe) + s->gpr[6]), 1, (s->gpr[0] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d051f: STEP(0x3d051f); /* xor rcx, 0x4049990c */
x = s->gpr[2]; y = UINT64_C(0x4049990c);
s->gpr[2] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_3d0526: STEP(0x3d0526); /* lea rdx, [rip - 0x16f4ad] */
s->gpr[3] = (UINT64_C(0xffffffffffe90b53) + (bias + UINT64_C(0x3d052d)));
++s->steps;
kg_pc_3d052d: STEP(0x3d052d); /* mov al, byte ptr [rcx + rdx] */
READ(a, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x1))), 1);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0530: STEP(0x3d0530); /* add r9b, 0xca */
x = (s->gpr[9] & UINT64_C(0xff)); y = UINT64_C(0xca);
s->gpr[9] = (s->gpr[9] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0534: STEP(0x3d0534); /* xor r9b, r8b */
x = (s->gpr[9] & UINT64_C(0xff)); y = (s->gpr[8] & UINT64_C(0xff));
s->gpr[9] = (s->gpr[9] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0537: STEP(0x3d0537); /* rol al, 5 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x5);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ROL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d053a: STEP(0x3d053a); /* xor rsi, 0x3d182ff6 */
x = s->gpr[4]; y = UINT64_C(0x3d182ff6);
s->gpr[4] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_3d0541: STEP(0x3d0541); /* mov cl, byte ptr [rsi + rdx] */
READ(a, (UINT64_C(0x0) + s->gpr[4] + (s->gpr[3] * UINT64_C(0x1))), 1);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0544: STEP(0x3d0544); /* rol cl, 5 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x5);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ROL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0547: STEP(0x3d0547); /* movzx esi, al */
s->gpr[4] = (uint32_t)((s->gpr[0] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d054a: STEP(0x3d054a); /* mov al, byte ptr [rbx + rdx] */
READ(a, (UINT64_C(0x0) + s->gpr[1] + (s->gpr[3] * UINT64_C(0x1))), 1);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d054d: STEP(0x3d054d); /* rol al, 5 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x5);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ROL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0550: STEP(0x3d0550); /* movzx ecx, cl */
s->gpr[2] = (uint32_t)((s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d0553: STEP(0x3d0553); /* movzx eax, al */
s->gpr[0] = (uint32_t)((s->gpr[0] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d0556: STEP(0x3d0556); /* mov rdx, r10 */
s->gpr[3] = s->gpr[10];
++s->steps;
kg_pc_3d0559: STEP(0x3d0559); /* shr edx, 0x18 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_3d055c: STEP(0x3d055c); /* xor rdx, 0x18 */
x = s->gpr[3]; y = UINT64_C(0x18);
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_3d0560: STEP(0x3d0560); /* mov dl, byte ptr [rdx + r14] */
READ(a, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[14] * UINT64_C(0x1))), 1);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0564: STEP(0x3d0564); /* mov ebx, edx */
s->gpr[1] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d0566: STEP(0x3d0566); /* shl bl, 4 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x4);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0569: STEP(0x3d0569); /* xor bl, dl */
x = (s->gpr[1] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d056b: STEP(0x3d056b); /* lea edx, [rsi*8] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + (s->gpr[4] * UINT64_C(0x8))));
++s->steps;
kg_pc_3d0572: STEP(0x3d0572); /* lea edx, [rdx + rdx*8] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x8))));
++s->steps;
kg_pc_3d0575: STEP(0x3d0575); /* imul edi, esi, -0x70 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffffffffff90);
s->gpr[5] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_3d0578: STEP(0x3d0578); /* and dil, 0x30 */
x = (s->gpr[5] & UINT64_C(0xff)); y = UINT64_C(0x30);
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d057c: STEP(0x3d057c); /* sub dl, dil */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[5] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d057f: STEP(0x3d057f); /* add dl, 0x19 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x19);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0582: STEP(0x3d0582); /* xor sil, dl */
x = (s->gpr[4] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0585: STEP(0x3d0585); /* xor sil, 0xb8 */
x = (s->gpr[4] & UINT64_C(0xff)); y = UINT64_C(0xb8);
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0589: STEP(0x3d0589); /* mov byte ptr [rbp - 0x47], sil */
WRITE((UINT64_C(0xffffffffffffffb9) + s->gpr[6]), 1, (s->gpr[4] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d058d: STEP(0x3d058d); /* xor r9b, 0x69 */
x = (s->gpr[9] & UINT64_C(0xff)); y = UINT64_C(0x69);
s->gpr[9] = (s->gpr[9] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0591: STEP(0x3d0591); /* mov byte ptr [rbp - 0x4c], r9b */
WRITE((UINT64_C(0xffffffffffffffb4) + s->gpr[6]), 1, (s->gpr[9] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d0595: STEP(0x3d0595); /* lea edx, [rcx*8] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + (s->gpr[2] * UINT64_C(0x8))));
++s->steps;
kg_pc_3d059c: STEP(0x3d059c); /* lea edx, [rdx + rdx*8] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x8))));
++s->steps;
kg_pc_3d059f: STEP(0x3d059f); /* imul esi, ecx, -0x70 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffffffffff90);
s->gpr[4] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_3d05a2: STEP(0x3d05a2); /* and sil, 0x10 */
x = (s->gpr[4] & UINT64_C(0xff)); y = UINT64_C(0x10);
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d05a6: STEP(0x3d05a6); /* sub dl, sil */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[4] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d05a9: STEP(0x3d05a9); /* add dl, 0xc */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0xc);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d05ac: STEP(0x3d05ac); /* xor cl, dl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d05ae: STEP(0x3d05ae); /* xor cl, 0x9c */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x9c);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d05b1: STEP(0x3d05b1); /* mov byte ptr [rbp - 0x4f], cl */
WRITE((UINT64_C(0xffffffffffffffb1) + s->gpr[6]), 1, (s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d05b4: STEP(0x3d05b4); /* lea ecx, [rax*8] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + (s->gpr[0] * UINT64_C(0x8))));
++s->steps;
kg_pc_3d05bb: STEP(0x3d05bb); /* lea ecx, [rcx + rcx*8] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x8))));
++s->steps;
kg_pc_3d05be: STEP(0x3d05be); /* imul edx, eax, -0x70 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffffffffff90);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;

break;
case 2:
next_pc=bias+UINT64_C(0x3d0610);
switch(s->pc-bias){
case UINT64_C(0x3d05c1):goto kg_pc_3d05c1;
case UINT64_C(0x3d05c4):goto kg_pc_3d05c4;
case UINT64_C(0x3d05c6):goto kg_pc_3d05c6;
case UINT64_C(0x3d05c9):goto kg_pc_3d05c9;
case UINT64_C(0x3d05cb):goto kg_pc_3d05cb;
case UINT64_C(0x3d05cd):goto kg_pc_3d05cd;
case UINT64_C(0x3d05d0):goto kg_pc_3d05d0;
case UINT64_C(0x3d05d3):goto kg_pc_3d05d3;
case UINT64_C(0x3d05d6):goto kg_pc_3d05d6;
case UINT64_C(0x3d05e0):goto kg_pc_3d05e0;
case UINT64_C(0x3d05eb):goto kg_pc_3d05eb;
case UINT64_C(0x3d05f2):goto kg_pc_3d05f2;
case UINT64_C(0x3d05f9):goto kg_pc_3d05f9;
case UINT64_C(0x3d0600):goto kg_pc_3d0600;
case UINT64_C(0x3d0607):goto kg_pc_3d0607;
case UINT64_C(0x3d060e):goto kg_pc_3d060e;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1579: [0x3d05c1,0x3d0610), 16 instructions. */
kg_pc_3d05c1: STEP(0x3d05c1); /* and dl, 0x50 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x50);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d05c4: STEP(0x3d05c4); /* sub cl, dl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d05c6: STEP(0x3d05c6); /* add cl, 0x2c */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x2c);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d05c9: STEP(0x3d05c9); /* xor al, cl */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d05cb: STEP(0x3d05cb); /* xor al, 0xee */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xee);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d05cd: STEP(0x3d05cd); /* mov byte ptr [rbp - 0x43], al */
WRITE((UINT64_C(0xffffffffffffffbd) + s->gpr[6]), 1, (s->gpr[0] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d05d0: STEP(0x3d05d0); /* xor bl, 0x27 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x27);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d05d3: STEP(0x3d05d3); /* mov byte ptr [rbp - 0x48], bl */
WRITE((UINT64_C(0xffffffffffffffb8) + s->gpr[6]), 1, (s->gpr[1] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d05d6: STEP(0x3d05d6); /* mov dword ptr [rbp - 0x84], 0x5ccfca1e */
WRITE((UINT64_C(0xffffffffffffff7c) + s->gpr[6]), 4, UINT64_C(0x5ccfca1e));
++s->steps;
kg_pc_3d05e0: STEP(0x3d05e0); /* mov qword ptr [rbp - 0x188], 0x37c606c */
WRITE((UINT64_C(0xfffffffffffffe78) + s->gpr[6]), 8, UINT64_C(0x37c606c));
++s->steps;
kg_pc_3d05eb: STEP(0x3d05eb); /* lea r8, [rip - 0x3cff12] */
s->gpr[8] = (UINT64_C(0xffffffffffc300ee) + (bias + UINT64_C(0x3d05f2)));
++s->steps;
kg_pc_3d05f2: STEP(0x3d05f2); /* lea r9, [rip - 0x151729] */
s->gpr[9] = (UINT64_C(0xffffffffffeae8d7) + (bias + UINT64_C(0x3d05f9)));
++s->steps;
kg_pc_3d05f9: STEP(0x3d05f9); /* lea r10, [rip - 0x308730] */
s->gpr[10] = (UINT64_C(0xffffffffffcf78d0) + (bias + UINT64_C(0x3d0600)));
++s->steps;
kg_pc_3d0600: STEP(0x3d0600); /* lea rsi, [rip + 0x7d] */
s->gpr[4] = (UINT64_C(0x7d) + (bias + UINT64_C(0x3d0607)));
++s->steps;
kg_pc_3d0607: STEP(0x3d0607); /* mov rdx, qword ptr [rbp - 0x270] */
READ(a, (UINT64_C(0xfffffffffffffd90) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_3d060e: STEP(0x3d060e); /* nop  */
++s->steps;

break;
case 3:
next_pc=bias+UINT64_C(0x3d0683);
switch(s->pc-bias){
case UINT64_C(0x3d0610):goto kg_pc_3d0610;
case UINT64_C(0x3d0617):goto kg_pc_3d0617;
case UINT64_C(0x3d061e):goto kg_pc_3d061e;
case UINT64_C(0x3d0627):goto kg_pc_3d0627;
case UINT64_C(0x3d0629):goto kg_pc_3d0629;
case UINT64_C(0x3d062c):goto kg_pc_3d062c;
case UINT64_C(0x3d062e):goto kg_pc_3d062e;
case UINT64_C(0x3d0635):goto kg_pc_3d0635;
case UINT64_C(0x3d0637):goto kg_pc_3d0637;
case UINT64_C(0x3d063f):goto kg_pc_3d063f;
case UINT64_C(0x3d0647):goto kg_pc_3d0647;
case UINT64_C(0x3d064a):goto kg_pc_3d064a;
case UINT64_C(0x3d064d):goto kg_pc_3d064d;
case UINT64_C(0x3d0650):goto kg_pc_3d0650;
case UINT64_C(0x3d0652):goto kg_pc_3d0652;
case UINT64_C(0x3d0655):goto kg_pc_3d0655;
case UINT64_C(0x3d065c):goto kg_pc_3d065c;
case UINT64_C(0x3d0660):goto kg_pc_3d0660;
case UINT64_C(0x3d0662):goto kg_pc_3d0662;
case UINT64_C(0x3d0669):goto kg_pc_3d0669;
case UINT64_C(0x3d066d):goto kg_pc_3d066d;
case UINT64_C(0x3d0674):goto kg_pc_3d0674;
case UINT64_C(0x3d0678):goto kg_pc_3d0678;
case UINT64_C(0x3d067a):goto kg_pc_3d067a;
case UINT64_C(0x3d067e):goto kg_pc_3d067e;
case UINT64_C(0x3d0681):goto kg_pc_3d0681;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1580: [0x3d0610,0x3d0683), 26 instructions. */
kg_pc_3d0610: STEP(0x3d0610); /* mov rbx, qword ptr [rbp - 0x188] */
READ(a, (UINT64_C(0xfffffffffffffe78) + s->gpr[6]), 8);
s->gpr[1] = a;
++s->steps;
kg_pc_3d0617: STEP(0x3d0617); /* lea rdi, [rbx - 0x37c605d] */
s->gpr[5] = (UINT64_C(0xfffffffffc839fa3) + s->gpr[1]);
++s->steps;
kg_pc_3d061e: STEP(0x3d061e); /* movzx eax, byte ptr [rbx + r8 - 0x37c605d] */
READ(a, (UINT64_C(0xfffffffffc839fa3) + s->gpr[1] + (s->gpr[8] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_3d0627: STEP(0x3d0627); /* mov ecx, edi */
s->gpr[2] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d0629: STEP(0x3d0629); /* shl ecx, 6 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x6);
s->gpr[2] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_3d062c: STEP(0x3d062c); /* add ecx, edi */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d062e: STEP(0x3d062e); /* xor al, byte ptr [rbp + rbx - 0x37c60ad] */
READ(b, (UINT64_C(0xfffffffffc839f53) + s->gpr[6] + (s->gpr[1] * UINT64_C(0x1))), 1);
x = (s->gpr[0] & UINT64_C(0xff)); y = b;
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0635: STEP(0x3d0635); /* xor al, cl */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0637: STEP(0x3d0637); /* xor al, byte ptr [rbx + r9 - 0x37c6059] */
READ(b, (UINT64_C(0xfffffffffc839fa7) + s->gpr[1] + (s->gpr[9] * UINT64_C(0x1))), 1);
x = (s->gpr[0] & UINT64_C(0xff)); y = b;
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d063f: STEP(0x3d063f); /* xor al, byte ptr [rbx + r10 - 0x37c6058] */
READ(b, (UINT64_C(0xfffffffffc839fa8) + s->gpr[1] + (s->gpr[10] * UINT64_C(0x1))), 1);
x = (s->gpr[0] & UINT64_C(0xff)); y = b;
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0647: STEP(0x3d0647); /* movzx eax, al */
s->gpr[0] = (uint32_t)((s->gpr[0] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d064a: STEP(0x3d064a); /* lea ecx, [rax + rax*2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_3d064d: STEP(0x3d064d); /* shl ecx, 3 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x3);
s->gpr[2] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_3d0650: STEP(0x3d0650); /* sub ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_3d0652: STEP(0x3d0652); /* add cl, 0x62 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x62);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d0655: STEP(0x3d0655); /* mov byte ptr [rdx + rbx - 0x37c605d], cl */
WRITE((UINT64_C(0xfffffffffc839fa3) + s->gpr[3] + (s->gpr[1] * UINT64_C(0x1))), 1, (s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d065c: STEP(0x3d065c); /* lea rax, [rbx - 1] */
s->gpr[0] = (UINT64_C(0xffffffffffffffff) + s->gpr[1]);
++s->steps;
kg_pc_3d0660: STEP(0x3d0660); /* xor edi, edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d0662: STEP(0x3d0662); /* cmp rbx, 0x37c605d */
x = s->gpr[1]; y = UINT64_C(0x37c605d);
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_3d0669: STEP(0x3d0669); /* sete dil */
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d066d: STEP(0x3d066d); /* mov qword ptr [rbp - 0x188], rax */
WRITE((UINT64_C(0xfffffffffffffe78) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_3d0674: STEP(0x3d0674); /* lea eax, [rdi + r11] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[11] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d0678: STEP(0x3d0678); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_3d067a: STEP(0x3d067a); /* movsxd rax, dword ptr [r15 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[15] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d067e: STEP(0x3d067e); /* add rax, rsi */
x = s->gpr[0]; y = s->gpr[4];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d0681: STEP(0x3d0681); /* jmp rax */
x = s->gpr[0];
next_pc = x;
++s->steps;

break;
case 4:
next_pc=bias+UINT64_C(0x3d0684);
switch(s->pc-bias){
case UINT64_C(0x3d0683):goto kg_pc_3d0683;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1581: [0x3d0683,0x3d0684), 1 instructions. */
kg_pc_3d0683: STEP(0x3d0683); /* pop rbp */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
s->gpr[6] = x;
++s->steps;

break;
case 5:
next_pc=bias+UINT64_C(0x3d068a);
switch(s->pc-bias){
case UINT64_C(0x3d0684):goto kg_pc_3d0684;
case UINT64_C(0x3d0688):goto kg_pc_3d0688;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1582: [0x3d0684,0x3d068a), 2 instructions. */
kg_pc_3d0684: STEP(0x3d0684); /* lea r11d, [r11 + rdi*2] */
s->gpr[11] = (uint32_t)((UINT64_C(0x0) + s->gpr[11] + (s->gpr[5] * UINT64_C(0x2))));
++s->steps;
kg_pc_3d0688: STEP(0x3d0688); /* jmp 0x3d0610 */
x = (bias + UINT64_C(0x3d0610));
next_pc = x;
++s->steps;

break;
case 6:
next_pc=bias+UINT64_C(0x3d06a8);
switch(s->pc-bias){
case UINT64_C(0x3d068c):goto kg_pc_3d068c;
case UINT64_C(0x3d0696):goto kg_pc_3d0696;
case UINT64_C(0x3d069b):goto kg_pc_3d069b;
case UINT64_C(0x3d06a0):goto kg_pc_3d06a0;
case UINT64_C(0x3d06a3):goto kg_pc_3d06a3;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1583: [0x3d068c,0x3d06a8), 5 instructions. */
kg_pc_3d068c: STEP(0x3d068c); /* cmp dword ptr [rbp - 0x84], 0x5ccfca1e */
READ(a, (UINT64_C(0xffffffffffffff7c) + s->gpr[6]), 4);
x = a; y = UINT64_C(0x5ccfca1e);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_3d0696: STEP(0x3d0696); /* mov ecx, 0x1f7ade0d */
s->gpr[2] = (uint32_t)(UINT64_C(0x1f7ade0d));
++s->steps;
kg_pc_3d069b: STEP(0x3d069b); /* mov eax, 0x1f7a39e5 */
s->gpr[0] = (uint32_t)(UINT64_C(0x1f7a39e5));
++s->steps;
kg_pc_3d06a0: STEP(0x3d06a0); /* cmove eax, ecx */
s->gpr[0] = (uint32_t)((condition(s, COND_E) ? (s->gpr[2] & UINT64_C(0xffffffff)) : (s->gpr[0] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_3d06a3: STEP(0x3d06a3); /* jmp 0x3d26b8 */
x = (bias + UINT64_C(0x3d26b8));
next_pc = x;
++s->steps;

break;
case 7:
next_pc=bias+UINT64_C(0x3d26d4);
switch(s->pc-bias){
case UINT64_C(0x3d26b8):goto kg_pc_3d26b8;
case UINT64_C(0x3d26bf):goto kg_pc_3d26bf;
case UINT64_C(0x3d26c2):goto kg_pc_3d26c2;
case UINT64_C(0x3d26c9):goto kg_pc_3d26c9;
case UINT64_C(0x3d26ca):goto kg_pc_3d26ca;
case UINT64_C(0x3d26cc):goto kg_pc_3d26cc;
case UINT64_C(0x3d26ce):goto kg_pc_3d26ce;
case UINT64_C(0x3d26d0):goto kg_pc_3d26d0;
case UINT64_C(0x3d26d2):goto kg_pc_3d26d2;
case UINT64_C(0x3d26d3):goto kg_pc_3d26d3;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1584: [0x3d26b8,0x3d26d4), 10 instructions. */
kg_pc_3d26b8: STEP(0x3d26b8); /* mov rcx, qword ptr [rbp - 0x278] */
READ(a, (UINT64_C(0xfffffffffffffd88) + s->gpr[6]), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_3d26bf: STEP(0x3d26bf); /* mov dword ptr [rcx + 0x10], eax */
WRITE((UINT64_C(0x10) + s->gpr[2]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d26c2: STEP(0x3d26c2); /* add rsp, 0x428 */
x = s->gpr[7]; y = UINT64_C(0x428);
s->gpr[7] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d26c9: STEP(0x3d26c9); /* pop rbx */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
s->gpr[1] = x;
++s->steps;
kg_pc_3d26ca: STEP(0x3d26ca); /* pop r12 */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
s->gpr[12] = x;
++s->steps;
kg_pc_3d26cc: STEP(0x3d26cc); /* pop r13 */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
s->gpr[13] = x;
++s->steps;
kg_pc_3d26ce: STEP(0x3d26ce); /* pop r14 */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
s->gpr[14] = x;
++s->steps;
kg_pc_3d26d0: STEP(0x3d26d0); /* pop r15 */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
s->gpr[15] = x;
++s->steps;
kg_pc_3d26d2: STEP(0x3d26d2); /* pop rbp */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
s->gpr[6] = x;
++s->steps;
kg_pc_3d26d3: STEP(0x3d26d3); /* ret  */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
next_pc = x;
++s->steps;

break;
case 8:
next_pc=bias+UINT64_C(0x3d271b);
switch(s->pc-bias){
case UINT64_C(0x3d26e0):goto kg_pc_3d26e0;
case UINT64_C(0x3d26e1):goto kg_pc_3d26e1;
case UINT64_C(0x3d26e4):goto kg_pc_3d26e4;
case UINT64_C(0x3d26e6):goto kg_pc_3d26e6;
case UINT64_C(0x3d26eb):goto kg_pc_3d26eb;
case UINT64_C(0x3d26f1):goto kg_pc_3d26f1;
case UINT64_C(0x3d26f4):goto kg_pc_3d26f4;
case UINT64_C(0x3d26f7):goto kg_pc_3d26f7;
case UINT64_C(0x3d26f9):goto kg_pc_3d26f9;
case UINT64_C(0x3d26fc):goto kg_pc_3d26fc;
case UINT64_C(0x3d26ff):goto kg_pc_3d26ff;
case UINT64_C(0x3d2701):goto kg_pc_3d2701;
case UINT64_C(0x3d2704):goto kg_pc_3d2704;
case UINT64_C(0x3d270b):goto kg_pc_3d270b;
case UINT64_C(0x3d270f):goto kg_pc_3d270f;
case UINT64_C(0x3d2716):goto kg_pc_3d2716;
case UINT64_C(0x3d2719):goto kg_pc_3d2719;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1585: [0x3d26e0,0x3d271b), 17 instructions. */
kg_pc_3d26e0: STEP(0x3d26e0); /* push rbp */
x = s->gpr[6]; y = s->gpr[7] - 8;
WRITE(y, 8, x);
s->gpr[7] = y;
++s->steps;
kg_pc_3d26e1: STEP(0x3d26e1); /* mov rbp, rsp */
s->gpr[6] = s->gpr[7];
++s->steps;
kg_pc_3d26e4: STEP(0x3d26e4); /* mov eax, edi */
s->gpr[0] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d26e6: STEP(0x3d26e6); /* xor eax, 0x5b4e9689 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x5b4e9689);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d26eb: STEP(0x3d26eb); /* imul ecx, eax, 0x34bcad33 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x34bcad33);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_3d26f1: STEP(0x3d26f1); /* add ecx, dword ptr [rdi + 8] */
READ(b, (UINT64_C(0x8) + s->gpr[5]), 4);
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = b;
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d26f4: STEP(0x3d26f4); /* mov rax, qword ptr [rdi] */
READ(a, (UINT64_C(0x0) + s->gpr[5]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_3d26f7: STEP(0x3d26f7); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d26f9: STEP(0x3d26f9); /* test rax, rax */
x = s->gpr[0]; y = s->gpr[0];
(void)operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_3d26fc: STEP(0x3d26fc); /* sete dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d26ff: STEP(0x3d26ff); /* add ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2701: STEP(0x3d2701); /* movsxd rcx, ecx */
s->gpr[2] = (((s->gpr[2] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d2704: STEP(0x3d2704); /* lea rdx, [rip - 0x3a319f] */
s->gpr[3] = (UINT64_C(0xffffffffffc5ce61) + (bias + UINT64_C(0x3d270b)));
++s->steps;
kg_pc_3d270b: STEP(0x3d270b); /* movsxd rcx, dword ptr [rdx + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d270f: STEP(0x3d270f); /* lea rdx, [rip - 0x1f] */
s->gpr[3] = (UINT64_C(0xffffffffffffffe1) + (bias + UINT64_C(0x3d2716)));
++s->steps;
kg_pc_3d2716: STEP(0x3d2716); /* add rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d2719: STEP(0x3d2719); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
case 9:
next_pc=bias+UINT64_C(0x3d2721);
switch(s->pc-bias){
case UINT64_C(0x3d271b):goto kg_pc_3d271b;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1586: [0x3d271b,0x3d2721), 1 instructions. */
kg_pc_3d271b: STEP(0x3d271b); /* or dword ptr [rax - 0xa427], edi */
READ(a, (UINT64_C(0xffffffffffff5bd9) + s->gpr[0]), 4);
x = a; y = (s->gpr[5] & UINT64_C(0xffffffff));
WRITE((UINT64_C(0xffffffffffff5bd9) + s->gpr[0]), 4, operation(s, OP_OR, x, y, 32));
++s->steps;

break;
case 10:
next_pc=bias+UINT64_C(0x3d2723);
switch(s->pc-bias){
case UINT64_C(0x3d271c):goto kg_pc_3d271c;
case UINT64_C(0x3d2721):goto kg_pc_3d2721;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1587: [0x3d271c,0x3d2723), 2 instructions. */
kg_pc_3d271c: STEP(0x3d271c); /* mov eax, 0xffff5bd9 */
s->gpr[0] = (uint32_t)(UINT64_C(0xffff5bd9));
++s->steps;
kg_pc_3d2721: STEP(0x3d2721); /* jmp 0x3d273b */
x = (bias + UINT64_C(0x3d273b));
next_pc = x;
++s->steps;

break;
case 11:
next_pc=bias+UINT64_C(0x3d273b);
switch(s->pc-bias){
case UINT64_C(0x3d2725):goto kg_pc_3d2725;
case UINT64_C(0x3d272f):goto kg_pc_3d272f;
case UINT64_C(0x3d2732):goto kg_pc_3d2732;
case UINT64_C(0x3d2739):goto kg_pc_3d2739;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1588: [0x3d2725,0x3d273b), 4 instructions. */
kg_pc_3d2725: STEP(0x3d2725); /* movabs rcx, 0x4900000001 */
s->gpr[2] = UINT64_C(0x4900000001);
++s->steps;
kg_pc_3d272f: STEP(0x3d272f); /* mov qword ptr [rax], rcx */
WRITE((UINT64_C(0x0) + s->gpr[0]), 8, s->gpr[2]);
++s->steps;
kg_pc_3d2732: STEP(0x3d2732); /* mov dword ptr [rax + 8], 0 */
WRITE((UINT64_C(0x8) + s->gpr[0]), 4, UINT64_C(0x0));
++s->steps;
kg_pc_3d2739: STEP(0x3d2739); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;

break;
case 12:
next_pc=bias+UINT64_C(0x3d2740);
switch(s->pc-bias){
case UINT64_C(0x3d273b):goto kg_pc_3d273b;
case UINT64_C(0x3d273e):goto kg_pc_3d273e;
case UINT64_C(0x3d273f):goto kg_pc_3d273f;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1589: [0x3d273b,0x3d2740), 3 instructions. */
kg_pc_3d273b: STEP(0x3d273b); /* mov dword ptr [rdi + 0xc], eax */
WRITE((UINT64_C(0xc) + s->gpr[5]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d273e: STEP(0x3d273e); /* pop rbp */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
s->gpr[6] = x;
++s->steps;
kg_pc_3d273f: STEP(0x3d273f); /* ret  */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
next_pc = x;
++s->steps;

break;
case 13:
next_pc=bias+UINT64_C(0x3d277a);
switch(s->pc-bias){
case UINT64_C(0x3d2740):goto kg_pc_3d2740;
case UINT64_C(0x3d274a):goto kg_pc_3d274a;
case UINT64_C(0x3d274d):goto kg_pc_3d274d;
case UINT64_C(0x3d2754):goto kg_pc_3d2754;
case UINT64_C(0x3d2755):goto kg_pc_3d2755;
case UINT64_C(0x3d2758):goto kg_pc_3d2758;
case UINT64_C(0x3d275c):goto kg_pc_3d275c;
case UINT64_C(0x3d275e):goto kg_pc_3d275e;
case UINT64_C(0x3d2761):goto kg_pc_3d2761;
case UINT64_C(0x3d2763):goto kg_pc_3d2763;
case UINT64_C(0x3d2765):goto kg_pc_3d2765;
case UINT64_C(0x3d276b):goto kg_pc_3d276b;
case UINT64_C(0x3d276e):goto kg_pc_3d276e;
case UINT64_C(0x3d2775):goto kg_pc_3d2775;
case UINT64_C(0x3d2778):goto kg_pc_3d2778;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1590: [0x3d2740,0x3d277a), 15 instructions. */
kg_pc_3d2740: STEP(0x3d2740); /* movabs rax, 0xbfa30f67c824c0e8 */
s->gpr[0] = UINT64_C(0xbfa30f67c824c0e8);
++s->steps;
kg_pc_3d274a: STEP(0x3d274a); /* xor rax, rdi */
x = s->gpr[0]; y = s->gpr[5];
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_3d274d: STEP(0x3d274d); /* imul rdx, rax, 0x51bb7edb */
x = s->gpr[0]; y = UINT64_C(0x51bb7edb);
s->gpr[3] = operation(s, OP_IMUL, x, y, 64);
++s->steps;
kg_pc_3d2754: STEP(0x3d2754); /* push rbp */
x = s->gpr[6]; y = s->gpr[7] - 8;
WRITE(y, 8, x);
s->gpr[7] = y;
++s->steps;
kg_pc_3d2755: STEP(0x3d2755); /* mov rbp, rsp */
s->gpr[6] = s->gpr[7];
++s->steps;
kg_pc_3d2758: STEP(0x3d2758); /* mov rax, qword ptr [rdi + 8] */
READ(a, (UINT64_C(0x8) + s->gpr[5]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_3d275c: STEP(0x3d275c); /* mov ecx, edx */
s->gpr[2] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d275e: STEP(0x3d275e); /* xor ecx, dword ptr [rdi + 4] */
READ(b, (UINT64_C(0x4) + s->gpr[5]), 4);
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = b;
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2761: STEP(0x3d2761); /* mov esi, dword ptr [rdi] */
READ(a, (UINT64_C(0x0) + s->gpr[5]), 4);
s->gpr[4] = (uint32_t)(a);
++s->steps;
kg_pc_3d2763: STEP(0x3d2763); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2765: STEP(0x3d2765); /* add edx, 0xfffff983 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffff983);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d276b: STEP(0x3d276b); /* movsxd rdx, edx */
s->gpr[3] = (((s->gpr[3] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d276e: STEP(0x3d276e); /* lea rsi, [rip - 0x21] */
s->gpr[4] = (UINT64_C(0xffffffffffffffdf) + (bias + UINT64_C(0x3d2775)));
++s->steps;
kg_pc_3d2775: STEP(0x3d2775); /* add rsi, rdx */
x = s->gpr[4]; y = s->gpr[3];
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d2778: STEP(0x3d2778); /* jmp rsi */
x = s->gpr[4];
next_pc = x;
++s->steps;

break;
case 14:
next_pc=bias+UINT64_C(0x3d28ee);
switch(s->pc-bias){
case UINT64_C(0x3d2820):goto kg_pc_3d2820;
case UINT64_C(0x3d2821):goto kg_pc_3d2821;
case UINT64_C(0x3d2824):goto kg_pc_3d2824;
case UINT64_C(0x3d2826):goto kg_pc_3d2826;
case UINT64_C(0x3d2828):goto kg_pc_3d2828;
case UINT64_C(0x3d282a):goto kg_pc_3d282a;
case UINT64_C(0x3d282c):goto kg_pc_3d282c;
case UINT64_C(0x3d282d):goto kg_pc_3d282d;
case UINT64_C(0x3d2831):goto kg_pc_3d2831;
case UINT64_C(0x3d2834):goto kg_pc_3d2834;
case UINT64_C(0x3d2837):goto kg_pc_3d2837;
case UINT64_C(0x3d283c):goto kg_pc_3d283c;
case UINT64_C(0x3d2842):goto kg_pc_3d2842;
case UINT64_C(0x3d2844):goto kg_pc_3d2844;
case UINT64_C(0x3d2847):goto kg_pc_3d2847;
case UINT64_C(0x3d2849):goto kg_pc_3d2849;
case UINT64_C(0x3d284b):goto kg_pc_3d284b;
case UINT64_C(0x3d2853):goto kg_pc_3d2853;
case UINT64_C(0x3d285a):goto kg_pc_3d285a;
case UINT64_C(0x3d285e):goto kg_pc_3d285e;
case UINT64_C(0x3d2860):goto kg_pc_3d2860;
case UINT64_C(0x3d2866):goto kg_pc_3d2866;
case UINT64_C(0x3d286c):goto kg_pc_3d286c;
case UINT64_C(0x3d286f):goto kg_pc_3d286f;
case UINT64_C(0x3d2875):goto kg_pc_3d2875;
case UINT64_C(0x3d2877):goto kg_pc_3d2877;
case UINT64_C(0x3d2879):goto kg_pc_3d2879;
case UINT64_C(0x3d287f):goto kg_pc_3d287f;
case UINT64_C(0x3d2885):goto kg_pc_3d2885;
case UINT64_C(0x3d2888):goto kg_pc_3d2888;
case UINT64_C(0x3d288e):goto kg_pc_3d288e;
case UINT64_C(0x3d2890):goto kg_pc_3d2890;
case UINT64_C(0x3d2894):goto kg_pc_3d2894;
case UINT64_C(0x3d289b):goto kg_pc_3d289b;
case UINT64_C(0x3d289d):goto kg_pc_3d289d;
case UINT64_C(0x3d28a3):goto kg_pc_3d28a3;
case UINT64_C(0x3d28a9):goto kg_pc_3d28a9;
case UINT64_C(0x3d28ac):goto kg_pc_3d28ac;
case UINT64_C(0x3d28b2):goto kg_pc_3d28b2;
case UINT64_C(0x3d28b4):goto kg_pc_3d28b4;
case UINT64_C(0x3d28ba):goto kg_pc_3d28ba;
case UINT64_C(0x3d28bd):goto kg_pc_3d28bd;
case UINT64_C(0x3d28c4):goto kg_pc_3d28c4;
case UINT64_C(0x3d28c7):goto kg_pc_3d28c7;
case UINT64_C(0x3d28c9):goto kg_pc_3d28c9;
case UINT64_C(0x3d28cc):goto kg_pc_3d28cc;
case UINT64_C(0x3d28cf):goto kg_pc_3d28cf;
case UINT64_C(0x3d28d2):goto kg_pc_3d28d2;
case UINT64_C(0x3d28d9):goto kg_pc_3d28d9;
case UINT64_C(0x3d28dd):goto kg_pc_3d28dd;
case UINT64_C(0x3d28e4):goto kg_pc_3d28e4;
case UINT64_C(0x3d28e7):goto kg_pc_3d28e7;
case UINT64_C(0x3d28ec):goto kg_pc_3d28ec;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1591: [0x3d2820,0x3d28ee), 53 instructions. */
kg_pc_3d2820: STEP(0x3d2820); /* push rbp */
x = s->gpr[6]; y = s->gpr[7] - 8;
WRITE(y, 8, x);
s->gpr[7] = y;
++s->steps;
kg_pc_3d2821: STEP(0x3d2821); /* mov rbp, rsp */
s->gpr[6] = s->gpr[7];
++s->steps;
kg_pc_3d2824: STEP(0x3d2824); /* push r15 */
x = s->gpr[15]; y = s->gpr[7] - 8;
WRITE(y, 8, x);
s->gpr[7] = y;
++s->steps;
kg_pc_3d2826: STEP(0x3d2826); /* push r14 */
x = s->gpr[14]; y = s->gpr[7] - 8;
WRITE(y, 8, x);
s->gpr[7] = y;
++s->steps;
kg_pc_3d2828: STEP(0x3d2828); /* push r13 */
x = s->gpr[13]; y = s->gpr[7] - 8;
WRITE(y, 8, x);
s->gpr[7] = y;
++s->steps;
kg_pc_3d282a: STEP(0x3d282a); /* push r12 */
x = s->gpr[12]; y = s->gpr[7] - 8;
WRITE(y, 8, x);
s->gpr[7] = y;
++s->steps;
kg_pc_3d282c: STEP(0x3d282c); /* push rbx */
x = s->gpr[1]; y = s->gpr[7] - 8;
WRITE(y, 8, x);
s->gpr[7] = y;
++s->steps;
kg_pc_3d282d: STEP(0x3d282d); /* sub rsp, 0x48 */
x = s->gpr[7]; y = UINT64_C(0x48);
s->gpr[7] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_3d2831: STEP(0x3d2831); /* mov r15, rdi */
s->gpr[15] = s->gpr[5];
++s->steps;
kg_pc_3d2834: STEP(0x3d2834); /* mov eax, r15d */
s->gpr[0] = (uint32_t)((s->gpr[15] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d2837: STEP(0x3d2837); /* xor eax, 0x39655707 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x39655707);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d283c: STEP(0x3d283c); /* imul edx, eax, 0x54f99365 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x54f99365);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_3d2842: STEP(0x3d2842); /* mov eax, dword ptr [rdi] */
READ(a, (UINT64_C(0x0) + s->gpr[5]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_3d2844: STEP(0x3d2844); /* mov ecx, dword ptr [rdi + 0x18] */
READ(a, (UINT64_C(0x18) + s->gpr[5]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
kg_pc_3d2847: STEP(0x3d2847); /* sub ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_3d2849: STEP(0x3d2849); /* sub eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_3d284b: STEP(0x3d284b); /* mov qword ptr [rbp - 0x38], 0 */
WRITE((UINT64_C(0xffffffffffffffc8) + s->gpr[6]), 8, UINT64_C(0x0));
++s->steps;
kg_pc_3d2853: STEP(0x3d2853); /* mov dword ptr [rbp - 0x30], 0x1e321b37 */
WRITE((UINT64_C(0xffffffffffffffd0) + s->gpr[6]), 4, UINT64_C(0x1e321b37));
++s->steps;
kg_pc_3d285a: STEP(0x3d285a); /* mov byte ptr [rbp - 0x29], 0x5a */
WRITE((UINT64_C(0xffffffffffffffd7) + s->gpr[6]), 1, UINT64_C(0x5a));
++s->steps;
kg_pc_3d285e: STEP(0x3d285e); /* mov edx, eax */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d2860: STEP(0x3d2860); /* and edx, 0x3f000000 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x3f000000);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d2866: STEP(0x3d2866); /* xor edx, 0x22000000 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x22000000);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d286c: STEP(0x3d286c); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d286f: STEP(0x3d286f); /* and esi, 0x6000000 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x6000000);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d2875: STEP(0x3d2875); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d2877: STEP(0x3d2877); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2879: STEP(0x3d2879); /* add edx, 0x4336d164 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x4336d164);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d287f: STEP(0x3d287f); /* xor edx, 0x2b1ad101 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x2b1ad101);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2885: STEP(0x3d2885); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d2888: STEP(0x3d2888); /* and esi, 0xa4400008 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xa4400008);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d288e: STEP(0x3d288e); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_3d2890: STEP(0x3d2890); /* lea r12d, [rdx + rsi] */
s->gpr[12] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d2894: STEP(0x3d2894); /* add r12d, 0x52a03796 */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x52a03796);
s->gpr[12] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d289b: STEP(0x3d289b); /* mov edx, eax */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d289d: STEP(0x3d289d); /* and edx, 0x30000000 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x30000000);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d28a3: STEP(0x3d28a3); /* xor edx, 0xa05c5080 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xa05c5080);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d28a9: STEP(0x3d28a9); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d28ac: STEP(0x3d28ac); /* and esi, 0x40b00100 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x40b00100);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d28b2: STEP(0x3d28b2); /* sub edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_3d28b4: STEP(0x3d28b4); /* cmp edx, 0x7fac4f80 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x7fac4f80);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_3d28ba: STEP(0x3d28ba); /* sete bl */
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d28bd: STEP(0x3d28bd); /* cmp r12d, 0x118c37f3 */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x118c37f3);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_3d28c4: STEP(0x3d28c4); /* sete dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d28c7: STEP(0x3d28c7); /* or dl, bl */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[1] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_OR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d28c9: STEP(0x3d28c9); /* movzx esi, dl */
s->gpr[4] = (uint32_t)((s->gpr[3] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d28cc: STEP(0x3d28cc); /* lea edx, [rcx + rsi] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d28cf: STEP(0x3d28cf); /* movsxd rdx, edx */
s->gpr[3] = (((s->gpr[3] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d28d2: STEP(0x3d28d2); /* lea r14, [rip - 0x19cec9] */
s->gpr[14] = (UINT64_C(0xffffffffffe63137) + (bias + UINT64_C(0x3d28d9)));
++s->steps;
kg_pc_3d28d9: STEP(0x3d28d9); /* movsxd rdx, dword ptr [r14 + rdx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[14] + (s->gpr[3] * UINT64_C(0x4))), 4);
s->gpr[3] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d28dd: STEP(0x3d28dd); /* lea rdi, [rip - 0x1b] */
s->gpr[5] = (UINT64_C(0xffffffffffffffe5) + (bias + UINT64_C(0x3d28e4)));
++s->steps;
kg_pc_3d28e4: STEP(0x3d28e4); /* add rdi, rdx */
x = s->gpr[5]; y = s->gpr[3];
s->gpr[5] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d28e7: STEP(0x3d28e7); /* mov edx, 0xa3bb9db1 */
s->gpr[3] = (uint32_t)(UINT64_C(0xa3bb9db1));
++s->steps;
kg_pc_3d28ec: STEP(0x3d28ec); /* jmp rdi */
x = s->gpr[5];
next_pc = x;
++s->steps;

break;
case 15:
next_pc=bias+UINT64_C(0x3d2961);
switch(s->pc-bias){
case UINT64_C(0x3d28ef):goto kg_pc_3d28ef;
case UINT64_C(0x3d28f3):goto kg_pc_3d28f3;
case UINT64_C(0x3d28f7):goto kg_pc_3d28f7;
case UINT64_C(0x3d28f9):goto kg_pc_3d28f9;
case UINT64_C(0x3d28ff):goto kg_pc_3d28ff;
case UINT64_C(0x3d2901):goto kg_pc_3d2901;
case UINT64_C(0x3d2906):goto kg_pc_3d2906;
case UINT64_C(0x3d290b):goto kg_pc_3d290b;
case UINT64_C(0x3d2915):goto kg_pc_3d2915;
case UINT64_C(0x3d2919):goto kg_pc_3d2919;
case UINT64_C(0x3d291c):goto kg_pc_3d291c;
case UINT64_C(0x3d2923):goto kg_pc_3d2923;
case UINT64_C(0x3d2925):goto kg_pc_3d2925;
case UINT64_C(0x3d2929):goto kg_pc_3d2929;
case UINT64_C(0x3d292d):goto kg_pc_3d292d;
case UINT64_C(0x3d2931):goto kg_pc_3d2931;
case UINT64_C(0x3d2935):goto kg_pc_3d2935;
case UINT64_C(0x3d2937):goto kg_pc_3d2937;
case UINT64_C(0x3d2939):goto kg_pc_3d2939;
case UINT64_C(0x3d293c):goto kg_pc_3d293c;
case UINT64_C(0x3d293f):goto kg_pc_3d293f;
case UINT64_C(0x3d2943):goto kg_pc_3d2943;
case UINT64_C(0x3d2947):goto kg_pc_3d2947;
case UINT64_C(0x3d2949):goto kg_pc_3d2949;
case UINT64_C(0x3d294e):goto kg_pc_3d294e;
case UINT64_C(0x3d2951):goto kg_pc_3d2951;
case UINT64_C(0x3d2955):goto kg_pc_3d2955;
case UINT64_C(0x3d2959):goto kg_pc_3d2959;
case UINT64_C(0x3d295c):goto kg_pc_3d295c;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1592: [0x3d28ef,0x3d2961), 29 instructions. */
kg_pc_3d28ef: STEP(0x3d28ef); /* lea r13d, [rcx + rsi*4] */
s->gpr[13] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[4] * UINT64_C(0x4))));
++s->steps;
kg_pc_3d28f3: STEP(0x3d28f3); /* mov r8, qword ptr [r15 + 0x20] */
READ(a, (UINT64_C(0x20) + s->gpr[15]), 8);
s->gpr[8] = a;
++s->steps;
kg_pc_3d28f7: STEP(0x3d28f7); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d28f9: STEP(0x3d28f9); /* xor ecx, 0x5f837851 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x5f837851);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d28ff: STEP(0x3d28ff); /* add eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2901: STEP(0x3d2901); /* and eax, 0x2fb3dd5a */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x2fb3dd5a);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d2906: STEP(0x3d2906); /* xor eax, 0xb10d58 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xb10d58);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d290b: STEP(0x3d290b); /* movabs rsi, 0xba789480ae5033ef */
s->gpr[4] = UINT64_C(0xba789480ae5033ef);
++s->steps;
kg_pc_3d2915: STEP(0x3d2915); /* lea rdi, [rbp - 0x68] */
s->gpr[5] = (UINT64_C(0xffffffffffffff98) + s->gpr[6]);
++s->steps;
kg_pc_3d2919: STEP(0x3d2919); /* xor rsi, rdi */
x = s->gpr[4]; y = s->gpr[5];
s->gpr[4] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_3d291c: STEP(0x3d291c); /* imul rsi, rsi, 0x16d528d1 */
x = s->gpr[4]; y = UINT64_C(0x16d528d1);
s->gpr[4] = operation(s, OP_IMUL, x, y, 64);
++s->steps;
kg_pc_3d2923: STEP(0x3d2923); /* add ecx, esi */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2925: STEP(0x3d2925); /* lea edx, [r13 - 6] */
s->gpr[3] = (uint32_t)((UINT64_C(0xfffffffffffffffa) + s->gpr[13]));
++s->steps;
kg_pc_3d2929: STEP(0x3d2929); /* mov qword ptr [rbp - 0x50], r8 */
WRITE((UINT64_C(0xffffffffffffffb0) + s->gpr[6]), 8, s->gpr[8]);
++s->steps;
kg_pc_3d292d: STEP(0x3d292d); /* lea rbx, [rbp - 0x29] */
s->gpr[1] = (UINT64_C(0xffffffffffffffd7) + s->gpr[6]);
++s->steps;
kg_pc_3d2931: STEP(0x3d2931); /* mov qword ptr [rbp - 0x58], rbx */
WRITE((UINT64_C(0xffffffffffffffa8) + s->gpr[6]), 8, s->gpr[1]);
++s->steps;
kg_pc_3d2935: STEP(0x3d2935); /* xor edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2937: STEP(0x3d2937); /* mov ebx, esi */
s->gpr[1] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d2939: STEP(0x3d2939); /* xor bl, 0x19 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x19);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d293c: STEP(0x3d293c); /* mov byte ptr [rbp - 0x64], bl */
WRITE((UINT64_C(0xffffffffffffff9c) + s->gpr[6]), 1, (s->gpr[1] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d293f: STEP(0x3d293f); /* lea rsi, [rbp - 0x38] */
s->gpr[4] = (UINT64_C(0xffffffffffffffc8) + s->gpr[6]);
++s->steps;
kg_pc_3d2943: STEP(0x3d2943); /* mov qword ptr [rbp - 0x60], rsi */
WRITE((UINT64_C(0xffffffffffffffa0) + s->gpr[6]), 8, s->gpr[4]);
++s->steps;
kg_pc_3d2947: STEP(0x3d2947); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2949: STEP(0x3d2949); /* add eax, 0xfcbefbf4 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xfcbefbf4);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d294e: STEP(0x3d294e); /* mov dword ptr [rbp - 0x68], eax */
WRITE((UINT64_C(0xffffffffffffff98) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d2951: STEP(0x3d2951); /* lea rax, [rbp - 0x30] */
s->gpr[0] = (UINT64_C(0xffffffffffffffd0) + s->gpr[6]);
++s->steps;
kg_pc_3d2955: STEP(0x3d2955); /* mov qword ptr [rbp - 0x48], rax */
WRITE((UINT64_C(0xffffffffffffffb8) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_3d2959: STEP(0x3d2959); /* mov dword ptr [rbp - 0x40], edx */
WRITE((UINT64_C(0xffffffffffffffc0) + s->gpr[6]), 4, (s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d295c: STEP(0x3d295c); /* call 0x2b83b0 */
x = (bias + UINT64_C(0x2b83b0));
y = s->gpr[7] - 8;
WRITE(y, 8, bias + UINT64_C(0x3d2961));
s->gpr[7] = y;
next_pc = x;
++s->steps;

break;
case 16:
next_pc=bias+UINT64_C(0x3d298c);
switch(s->pc-bias){
case UINT64_C(0x3d2961):goto kg_pc_3d2961;
case UINT64_C(0x3d2964):goto kg_pc_3d2964;
case UINT64_C(0x3d2966):goto kg_pc_3d2966;
case UINT64_C(0x3d2968):goto kg_pc_3d2968;
case UINT64_C(0x3d296e):goto kg_pc_3d296e;
case UINT64_C(0x3d2972):goto kg_pc_3d2972;
case UINT64_C(0x3d2975):goto kg_pc_3d2975;
case UINT64_C(0x3d2979):goto kg_pc_3d2979;
case UINT64_C(0x3d297c):goto kg_pc_3d297c;
case UINT64_C(0x3d2980):goto kg_pc_3d2980;
case UINT64_C(0x3d2987):goto kg_pc_3d2987;
case UINT64_C(0x3d298a):goto kg_pc_3d298a;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1593: [0x3d2961,0x3d298c), 12 instructions. */
kg_pc_3d2961: STEP(0x3d2961); /* mov edx, dword ptr [rbp - 0x3c] */
READ(a, (UINT64_C(0xffffffffffffffc4) + s->gpr[6]), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_3d2964: STEP(0x3d2964); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2966: STEP(0x3d2966); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2968: STEP(0x3d2968); /* cmp edx, 0x5c44c60d */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x5c44c60d);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_3d296e: STEP(0x3d296e); /* setne sil */
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2972: STEP(0x3d2972); /* sete cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2975: STEP(0x3d2975); /* lea edi, [rcx + r13] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[13] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d2979: STEP(0x3d2979); /* movsxd rdi, edi */
s->gpr[5] = (((s->gpr[5] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d297c: STEP(0x3d297c); /* movsxd rdi, dword ptr [r14 + rdi*4] */
READ(a, (UINT64_C(0x0) + s->gpr[14] + (s->gpr[5] * UINT64_C(0x4))), 4);
s->gpr[5] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d2980: STEP(0x3d2980); /* lea rbx, [rip - 0x98] */
s->gpr[1] = (UINT64_C(0xffffffffffffff68) + (bias + UINT64_C(0x3d2987)));
++s->steps;
kg_pc_3d2987: STEP(0x3d2987); /* add rbx, rdi */
x = s->gpr[1]; y = s->gpr[5];
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d298a: STEP(0x3d298a); /* jmp rbx */
x = s->gpr[1];
next_pc = x;
++s->steps;

break;
case 17:
next_pc=bias+UINT64_C(0x3d29d0);
switch(s->pc-bias){
case UINT64_C(0x3d298f):goto kg_pc_3d298f;
case UINT64_C(0x3d2992):goto kg_pc_3d2992;
case UINT64_C(0x3d2995):goto kg_pc_3d2995;
case UINT64_C(0x3d2998):goto kg_pc_3d2998;
case UINT64_C(0x3d299b):goto kg_pc_3d299b;
case UINT64_C(0x3d299e):goto kg_pc_3d299e;
case UINT64_C(0x3d29a0):goto kg_pc_3d29a0;
case UINT64_C(0x3d29a2):goto kg_pc_3d29a2;
case UINT64_C(0x3d29a9):goto kg_pc_3d29a9;
case UINT64_C(0x3d29ac):goto kg_pc_3d29ac;
case UINT64_C(0x3d29af):goto kg_pc_3d29af;
case UINT64_C(0x3d29b1):goto kg_pc_3d29b1;
case UINT64_C(0x3d29b4):goto kg_pc_3d29b4;
case UINT64_C(0x3d29b7):goto kg_pc_3d29b7;
case UINT64_C(0x3d29ba):goto kg_pc_3d29ba;
case UINT64_C(0x3d29bd):goto kg_pc_3d29bd;
case UINT64_C(0x3d29c0):goto kg_pc_3d29c0;
case UINT64_C(0x3d29c4):goto kg_pc_3d29c4;
case UINT64_C(0x3d29cb):goto kg_pc_3d29cb;
case UINT64_C(0x3d29ce):goto kg_pc_3d29ce;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1594: [0x3d298f,0x3d29d0), 20 instructions. */
kg_pc_3d298f: STEP(0x3d298f); /* mov al, sil */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((s->gpr[4] & UINT64_C(0xff))) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2992: STEP(0x3d2992); /* lea ecx, [rcx + rcx*8] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x8))));
++s->steps;
kg_pc_3d2995: STEP(0x3d2995); /* shl eax, 2 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x2);
s->gpr[0] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_3d2998: STEP(0x3d2998); /* sub r13d, eax */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_3d299b: STEP(0x3d299b); /* sub r13d, ecx */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_3d299e: STEP(0x3d299e); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d29a0: STEP(0x3d29a0); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d29a2: STEP(0x3d29a2); /* cmp r12d, 0x118c37f3 */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x118c37f3);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_3d29a9: STEP(0x3d29a9); /* setne al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d29ac: STEP(0x3d29ac); /* sete dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d29af: STEP(0x3d29af); /* mov ecx, edx */
s->gpr[2] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d29b1: STEP(0x3d29b1); /* shl ecx, 4 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x4);
s->gpr[2] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_3d29b4: STEP(0x3d29b4); /* lea ecx, [rcx + rax*2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_3d29b7: STEP(0x3d29b7); /* add ecx, r13d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[13] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d29ba: STEP(0x3d29ba); /* add r13d, edx */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d29bd: STEP(0x3d29bd); /* movsxd rax, r13d */
s->gpr[0] = (((s->gpr[13] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d29c0: STEP(0x3d29c0); /* movsxd rax, dword ptr [r14 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[14] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d29c4: STEP(0x3d29c4); /* lea rdx, [rip - 0x3c] */
s->gpr[3] = (UINT64_C(0xffffffffffffffc4) + (bias + UINT64_C(0x3d29cb)));
++s->steps;
kg_pc_3d29cb: STEP(0x3d29cb); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d29ce: STEP(0x3d29ce); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
case 18:
next_pc=bias+UINT64_C(0x3d2a5b);
switch(s->pc-bias){
case UINT64_C(0x3d29d1):goto kg_pc_3d29d1;
case UINT64_C(0x3d29d4):goto kg_pc_3d29d4;
case UINT64_C(0x3d29d7):goto kg_pc_3d29d7;
case UINT64_C(0x3d29db):goto kg_pc_3d29db;
case UINT64_C(0x3d29df):goto kg_pc_3d29df;
case UINT64_C(0x3d29e1):goto kg_pc_3d29e1;
case UINT64_C(0x3d29e7):goto kg_pc_3d29e7;
case UINT64_C(0x3d29eb):goto kg_pc_3d29eb;
case UINT64_C(0x3d29ef):goto kg_pc_3d29ef;
case UINT64_C(0x3d29f2):goto kg_pc_3d29f2;
case UINT64_C(0x3d29fc):goto kg_pc_3d29fc;
case UINT64_C(0x3d29ff):goto kg_pc_3d29ff;
case UINT64_C(0x3d2a09):goto kg_pc_3d2a09;
case UINT64_C(0x3d2a0d):goto kg_pc_3d2a0d;
case UINT64_C(0x3d2a17):goto kg_pc_3d2a17;
case UINT64_C(0x3d2a1a):goto kg_pc_3d2a1a;
case UINT64_C(0x3d2a1d):goto kg_pc_3d2a1d;
case UINT64_C(0x3d2a27):goto kg_pc_3d2a27;
case UINT64_C(0x3d2a2a):goto kg_pc_3d2a2a;
case UINT64_C(0x3d2a2c):goto kg_pc_3d2a2c;
case UINT64_C(0x3d2a2e):goto kg_pc_3d2a2e;
case UINT64_C(0x3d2a31):goto kg_pc_3d2a31;
case UINT64_C(0x3d2a35):goto kg_pc_3d2a35;
case UINT64_C(0x3d2a38):goto kg_pc_3d2a38;
case UINT64_C(0x3d2a3b):goto kg_pc_3d2a3b;
case UINT64_C(0x3d2a3e):goto kg_pc_3d2a3e;
case UINT64_C(0x3d2a40):goto kg_pc_3d2a40;
case UINT64_C(0x3d2a42):goto kg_pc_3d2a42;
case UINT64_C(0x3d2a44):goto kg_pc_3d2a44;
case UINT64_C(0x3d2a48):goto kg_pc_3d2a48;
case UINT64_C(0x3d2a4b):goto kg_pc_3d2a4b;
case UINT64_C(0x3d2a4f):goto kg_pc_3d2a4f;
case UINT64_C(0x3d2a56):goto kg_pc_3d2a56;
case UINT64_C(0x3d2a59):goto kg_pc_3d2a59;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1595: [0x3d29d1,0x3d2a5b), 34 instructions. */
kg_pc_3d29d1: STEP(0x3d29d1); /* mov edx, dword ptr [rbp - 0x30] */
READ(a, (UINT64_C(0xffffffffffffffd0) + s->gpr[6]), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_3d29d4: STEP(0x3d29d4); /* add edx, -4 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffffffffffffffc);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d29d7: STEP(0x3d29d7); /* mov r10, qword ptr [rbp - 0x38] */
READ(a, (UINT64_C(0xffffffffffffffc8) + s->gpr[6]), 8);
s->gpr[10] = a;
++s->steps;
kg_pc_3d29db: STEP(0x3d29db); /* lea r8, [r10 + 4] */
s->gpr[8] = (UINT64_C(0x4) + s->gpr[10]);
++s->steps;
kg_pc_3d29df: STEP(0x3d29df); /* xor esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d29e1: STEP(0x3d29e1); /* cmp edx, 0x1e321b37 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1e321b37);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_3d29e7: STEP(0x3d29e7); /* setb sil */
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d29eb: STEP(0x3d29eb); /* shl rsi, 0x20 */
x = s->gpr[4]; y = UINT64_C(0x20);
s->gpr[4] = operation(s, OP_SHL, x, y, 64);
++s->steps;
kg_pc_3d29ef: STEP(0x3d29ef); /* or rsi, rdx */
x = s->gpr[4]; y = s->gpr[3];
s->gpr[4] = operation(s, OP_OR, x, y, 64);
++s->steps;
kg_pc_3d29f2: STEP(0x3d29f2); /* movabs rbx, 0x3cbc4e132d6fd5c7 */
s->gpr[1] = UINT64_C(0x3cbc4e132d6fd5c7);
++s->steps;
kg_pc_3d29fc: STEP(0x3d29fc); /* add rbx, rsi */
x = s->gpr[1]; y = s->gpr[4];
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d29ff: STEP(0x3d29ff); /* movabs rsi, 0x68763d968bc1e04 */
s->gpr[4] = UINT64_C(0x68763d968bc1e04);
++s->steps;
kg_pc_3d2a09: STEP(0x3d2a09); /* lea rsi, [rsi + rbx*2] */
s->gpr[4] = (UINT64_C(0x0) + s->gpr[4] + (s->gpr[1] * UINT64_C(0x2)));
++s->steps;
kg_pc_3d2a0d: STEP(0x3d2a0d); /* movabs rdi, 0x1481656273a3c496 */
s->gpr[5] = UINT64_C(0x1481656273a3c496);
++s->steps;
kg_pc_3d2a17: STEP(0x3d2a17); /* and rdi, rsi */
x = s->gpr[5]; y = s->gpr[4];
s->gpr[5] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_3d2a1a: STEP(0x3d2a1a); /* sub rbx, rdi */
x = s->gpr[1]; y = s->gpr[5];
s->gpr[1] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_3d2a1d: STEP(0x3d2a1d); /* movabs rsi, 0xcd84649dee2ff14d */
s->gpr[4] = UINT64_C(0xcd84649dee2ff14d);
++s->steps;
kg_pc_3d2a27: STEP(0x3d2a27); /* add rsi, rbx */
x = s->gpr[4]; y = s->gpr[1];
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d2a2a: STEP(0x3d2a2a); /* xor edi, edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2a2c: STEP(0x3d2a2c); /* xor ebx, ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2a2e: STEP(0x3d2a2e); /* cmp r8, r10 */
x = s->gpr[8]; y = s->gpr[10];
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_3d2a31: STEP(0x3d2a31); /* setbe dil */
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_BE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2a35: STEP(0x3d2a35); /* mov dword ptr [rbp - 0x30], edx */
WRITE((UINT64_C(0xffffffffffffffd0) + s->gpr[6]), 4, (s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d2a38: STEP(0x3d2a38); /* seta bl */
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_A)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2a3b: STEP(0x3d2a3b); /* lea edx, [rbx + rbx*4] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[1] * UINT64_C(0x4))));
++s->steps;
kg_pc_3d2a3e: STEP(0x3d2a3e); /* add edi, edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2a40: STEP(0x3d2a40); /* add ebx, ecx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2a42: STEP(0x3d2a42); /* sub ecx, edi */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_3d2a44: STEP(0x3d2a44); /* lea r8d, [rcx + rdx*2] */
s->gpr[8] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_3d2a48: STEP(0x3d2a48); /* movsxd rcx, ebx */
s->gpr[2] = (((s->gpr[1] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d2a4b: STEP(0x3d2a4b); /* movsxd rcx, dword ptr [r14 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[14] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d2a4f: STEP(0x3d2a4f); /* lea rdx, [rip - 0x85] */
s->gpr[3] = (UINT64_C(0xffffffffffffff7b) + (bias + UINT64_C(0x3d2a56)));
++s->steps;
kg_pc_3d2a56: STEP(0x3d2a56); /* add rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d2a59: STEP(0x3d2a59); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
case 19:
next_pc=bias+UINT64_C(0x3d2ac0);
switch(s->pc-bias){
case UINT64_C(0x3d2a5e):goto kg_pc_3d2a5e;
case UINT64_C(0x3d2a60):goto kg_pc_3d2a60;
case UINT64_C(0x3d2a66):goto kg_pc_3d2a66;
case UINT64_C(0x3d2a68):goto kg_pc_3d2a68;
case UINT64_C(0x3d2a6e):goto kg_pc_3d2a6e;
case UINT64_C(0x3d2a74):goto kg_pc_3d2a74;
case UINT64_C(0x3d2a78):goto kg_pc_3d2a78;
case UINT64_C(0x3d2a7f):goto kg_pc_3d2a7f;
case UINT64_C(0x3d2a81):goto kg_pc_3d2a81;
case UINT64_C(0x3d2a83):goto kg_pc_3d2a83;
case UINT64_C(0x3d2a8a):goto kg_pc_3d2a8a;
case UINT64_C(0x3d2a8d):goto kg_pc_3d2a8d;
case UINT64_C(0x3d2a91):goto kg_pc_3d2a91;
case UINT64_C(0x3d2a98):goto kg_pc_3d2a98;
case UINT64_C(0x3d2a9b):goto kg_pc_3d2a9b;
case UINT64_C(0x3d2a9e):goto kg_pc_3d2a9e;
case UINT64_C(0x3d2aa1):goto kg_pc_3d2aa1;
case UINT64_C(0x3d2aa3):goto kg_pc_3d2aa3;
case UINT64_C(0x3d2aa6):goto kg_pc_3d2aa6;
case UINT64_C(0x3d2aa9):goto kg_pc_3d2aa9;
case UINT64_C(0x3d2aad):goto kg_pc_3d2aad;
case UINT64_C(0x3d2ab4):goto kg_pc_3d2ab4;
case UINT64_C(0x3d2ab7):goto kg_pc_3d2ab7;
case UINT64_C(0x3d2abc):goto kg_pc_3d2abc;
case UINT64_C(0x3d2abe):goto kg_pc_3d2abe;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1596: [0x3d2a5e,0x3d2ac0), 25 instructions. */
kg_pc_3d2a5e: STEP(0x3d2a5e); /* mov ecx, esi */
s->gpr[2] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d2a60: STEP(0x3d2a60); /* xor ecx, 0xdeef0ddc */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xdeef0ddc);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2a66: STEP(0x3d2a66); /* add esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2a68: STEP(0x3d2a68); /* and esi, 0xce7ddf2e */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xce7ddf2e);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d2a6e: STEP(0x3d2a6e); /* xor esi, 0x4221c406 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x4221c406);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2a74: STEP(0x3d2a74); /* lea r9d, [rcx + rsi] */
s->gpr[9] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d2a78: STEP(0x3d2a78); /* add r9d, 0x388b3de7 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x388b3de7);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2a7f: STEP(0x3d2a7f); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2a81: STEP(0x3d2a81); /* xor edi, edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2a83: STEP(0x3d2a83); /* cmp r9d, 0x1fca2d7e */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x1fca2d7e);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_3d2a8a: STEP(0x3d2a8a); /* setne cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2a8d: STEP(0x3d2a8d); /* sete dil */
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2a91: STEP(0x3d2a91); /* lea esi, [rdi*8] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + (s->gpr[5] * UINT64_C(0x8))));
++s->steps;
kg_pc_3d2a98: STEP(0x3d2a98); /* lea esi, [rsi + rsi*2] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x2))));
++s->steps;
kg_pc_3d2a9b: STEP(0x3d2a9b); /* lea ecx, [rsi + rcx*2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[2] * UINT64_C(0x2))));
++s->steps;
kg_pc_3d2a9e: STEP(0x3d2a9e); /* mov esi, r8d */
s->gpr[4] = (uint32_t)((s->gpr[8] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d2aa1: STEP(0x3d2aa1); /* sub esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_3d2aa3: STEP(0x3d2aa3); /* add edi, r8d */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2aa6: STEP(0x3d2aa6); /* movsxd rcx, edi */
s->gpr[2] = (((s->gpr[5] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d2aa9: STEP(0x3d2aa9); /* movsxd rcx, dword ptr [r14 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[14] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d2aad: STEP(0x3d2aad); /* lea rdi, [rip - 0x56] */
s->gpr[5] = (UINT64_C(0xffffffffffffffaa) + (bias + UINT64_C(0x3d2ab4)));
++s->steps;
kg_pc_3d2ab4: STEP(0x3d2ab4); /* add rdi, rcx */
x = s->gpr[5]; y = s->gpr[2];
s->gpr[5] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d2ab7: STEP(0x3d2ab7); /* mov ebx, 0xd7902b7 */
s->gpr[1] = (uint32_t)(UINT64_C(0xd7902b7));
++s->steps;
kg_pc_3d2abc: STEP(0x3d2abc); /* mov ecx, esi */
s->gpr[2] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d2abe: STEP(0x3d2abe); /* jmp rdi */
x = s->gpr[5];
next_pc = x;
++s->steps;

break;
case 20:
next_pc=bias+UINT64_C(0x3d2b33);
switch(s->pc-bias){
case UINT64_C(0x3d2ad0):goto kg_pc_3d2ad0;
case UINT64_C(0x3d2ad2):goto kg_pc_3d2ad2;
case UINT64_C(0x3d2ad9):goto kg_pc_3d2ad9;
case UINT64_C(0x3d2adc):goto kg_pc_3d2adc;
case UINT64_C(0x3d2ae2):goto kg_pc_3d2ae2;
case UINT64_C(0x3d2ae8):goto kg_pc_3d2ae8;
case UINT64_C(0x3d2aec):goto kg_pc_3d2aec;
case UINT64_C(0x3d2aef):goto kg_pc_3d2aef;
case UINT64_C(0x3d2af5):goto kg_pc_3d2af5;
case UINT64_C(0x3d2afb):goto kg_pc_3d2afb;
case UINT64_C(0x3d2afe):goto kg_pc_3d2afe;
case UINT64_C(0x3d2b00):goto kg_pc_3d2b00;
case UINT64_C(0x3d2b02):goto kg_pc_3d2b02;
case UINT64_C(0x3d2b05):goto kg_pc_3d2b05;
case UINT64_C(0x3d2b08):goto kg_pc_3d2b08;
case UINT64_C(0x3d2b0a):goto kg_pc_3d2b0a;
case UINT64_C(0x3d2b0d):goto kg_pc_3d2b0d;
case UINT64_C(0x3d2b10):goto kg_pc_3d2b10;
case UINT64_C(0x3d2b13):goto kg_pc_3d2b13;
case UINT64_C(0x3d2b16):goto kg_pc_3d2b16;
case UINT64_C(0x3d2b19):goto kg_pc_3d2b19;
case UINT64_C(0x3d2b1b):goto kg_pc_3d2b1b;
case UINT64_C(0x3d2b1d):goto kg_pc_3d2b1d;
case UINT64_C(0x3d2b1f):goto kg_pc_3d2b1f;
case UINT64_C(0x3d2b23):goto kg_pc_3d2b23;
case UINT64_C(0x3d2b2a):goto kg_pc_3d2b2a;
case UINT64_C(0x3d2b2d):goto kg_pc_3d2b2d;
case UINT64_C(0x3d2b2f):goto kg_pc_3d2b2f;
case UINT64_C(0x3d2b31):goto kg_pc_3d2b31;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1597: [0x3d2ad0,0x3d2b33), 29 instructions. */
kg_pc_3d2ad0: STEP(0x3d2ad0); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2ad2: STEP(0x3d2ad2); /* cmp r9d, 0x1fca2d7e */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x1fca2d7e);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_3d2ad9: STEP(0x3d2ad9); /* setb cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2adc: STEP(0x3d2adc); /* lea edi, [rbx - 0xd7902b7] */
s->gpr[5] = (uint32_t)((UINT64_C(0xfffffffff286fd49) + s->gpr[1]));
++s->steps;
kg_pc_3d2ae2: STEP(0x3d2ae2); /* movzx edx, byte ptr [r10 + rdi + 4] */
READ(a, (UINT64_C(0x4) + s->gpr[10] + (s->gpr[5] * UINT64_C(0x1))), 1);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_3d2ae8: STEP(0x3d2ae8); /* mov byte ptr [r10 + rdi], dl */
WRITE((UINT64_C(0x0) + s->gpr[10] + (s->gpr[5] * UINT64_C(0x1))), 1, (s->gpr[3] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d2aec: STEP(0x3d2aec); /* lea edi, [rbx + 1] */
s->gpr[5] = (uint32_t)((UINT64_C(0x1) + s->gpr[1]));
++s->steps;
kg_pc_3d2aef: STEP(0x3d2aef); /* add ebx, 0x12512ac8 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x12512ac8);
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2af5: STEP(0x3d2af5); /* cmp ebx, 0x1fca2d7e */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x1fca2d7e);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_3d2afb: STEP(0x3d2afb); /* setb dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2afe: STEP(0x3d2afe); /* xor dl, cl */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2b00: STEP(0x3d2b00); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2b02: STEP(0x3d2b02); /* cmp ebx, r9d */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[9] & UINT64_C(0xffffffff));
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_3d2b05: STEP(0x3d2b05); /* setb al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2b08: STEP(0x3d2b08); /* test dl, dl */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
(void)operation(s, OP_AND, x, y, 8);
++s->steps;
kg_pc_3d2b0a: STEP(0x3d2b0a); /* cmove ecx, eax */
s->gpr[2] = (uint32_t)((condition(s, COND_E) ? (s->gpr[0] & UINT64_C(0xffffffff)) : (s->gpr[2] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_3d2b0d: STEP(0x3d2b0d); /* movzx eax, cl */
s->gpr[0] = (uint32_t)((s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d2b10: STEP(0x3d2b10); /* xor cl, 1 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x1);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2b13: STEP(0x3d2b13); /* movzx ecx, cl */
s->gpr[2] = (uint32_t)((s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_3d2b16: STEP(0x3d2b16); /* imul ecx, ecx, -0x16 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffffffffffea);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_3d2b19: STEP(0x3d2b19); /* add ecx, esi */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2b1b: STEP(0x3d2b1b); /* add eax, esi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2b1d: STEP(0x3d2b1d); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_3d2b1f: STEP(0x3d2b1f); /* movsxd rax, dword ptr [r14 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[14] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d2b23: STEP(0x3d2b23); /* lea rdx, [rip - 0x5a] */
s->gpr[3] = (UINT64_C(0xffffffffffffffa6) + (bias + UINT64_C(0x3d2b2a)));
++s->steps;
kg_pc_3d2b2a: STEP(0x3d2b2a); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d2b2d: STEP(0x3d2b2d); /* mov esi, ecx */
s->gpr[4] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d2b2f: STEP(0x3d2b2f); /* mov ebx, edi */
s->gpr[1] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d2b31: STEP(0x3d2b31); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
case 21:
next_pc=bias+UINT64_C(0x3d2b8b);
switch(s->pc-bias){
case UINT64_C(0x3d2b35):goto kg_pc_3d2b35;
case UINT64_C(0x3d2b37):goto kg_pc_3d2b37;
case UINT64_C(0x3d2b3d):goto kg_pc_3d2b3d;
case UINT64_C(0x3d2b3f):goto kg_pc_3d2b3f;
case UINT64_C(0x3d2b45):goto kg_pc_3d2b45;
case UINT64_C(0x3d2b4b):goto kg_pc_3d2b4b;
case UINT64_C(0x3d2b4e):goto kg_pc_3d2b4e;
case UINT64_C(0x3d2b54):goto kg_pc_3d2b54;
case UINT64_C(0x3d2b56):goto kg_pc_3d2b56;
case UINT64_C(0x3d2b58):goto kg_pc_3d2b58;
case UINT64_C(0x3d2b5e):goto kg_pc_3d2b5e;
case UINT64_C(0x3d2b61):goto kg_pc_3d2b61;
case UINT64_C(0x3d2b64):goto kg_pc_3d2b64;
case UINT64_C(0x3d2b6b):goto kg_pc_3d2b6b;
case UINT64_C(0x3d2b6e):goto kg_pc_3d2b6e;
case UINT64_C(0x3d2b71):goto kg_pc_3d2b71;
case UINT64_C(0x3d2b73):goto kg_pc_3d2b73;
case UINT64_C(0x3d2b76):goto kg_pc_3d2b76;
case UINT64_C(0x3d2b79):goto kg_pc_3d2b79;
case UINT64_C(0x3d2b7b):goto kg_pc_3d2b7b;
case UINT64_C(0x3d2b7f):goto kg_pc_3d2b7f;
case UINT64_C(0x3d2b86):goto kg_pc_3d2b86;
case UINT64_C(0x3d2b89):goto kg_pc_3d2b89;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1598: [0x3d2b35,0x3d2b8b), 23 instructions. */
kg_pc_3d2b35: STEP(0x3d2b35); /* mov edi, esi */
s->gpr[5] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d2b37: STEP(0x3d2b37); /* xor edi, 0x8a0d5974 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x8a0d5974);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2b3d: STEP(0x3d2b3d); /* add esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2b3f: STEP(0x3d2b3f); /* and esi, 0x67b9767e */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x67b9767e);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_3d2b45: STEP(0x3d2b45); /* xor esi, 0x63a14416 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x63a14416);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2b4b: STEP(0x3d2b4b); /* lea edx, [rsi + rdi] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d2b4e: STEP(0x3d2b4e); /* add edx, 0x6fe74fda */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x6fe74fda);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2b54: STEP(0x3d2b54); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2b56: STEP(0x3d2b56); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2b58: STEP(0x3d2b58); /* cmp edx, 0x23c40b19 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x23c40b19);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_3d2b5e: STEP(0x3d2b5e); /* setne cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2b61: STEP(0x3d2b61); /* sete al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2b64: STEP(0x3d2b64); /* lea ebx, [rax*4] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + (s->gpr[0] * UINT64_C(0x4))));
++s->steps;
kg_pc_3d2b6b: STEP(0x3d2b6b); /* lea ebx, [rbx + rbx*2] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[1] * UINT64_C(0x2))));
++s->steps;
kg_pc_3d2b6e: STEP(0x3d2b6e); /* shl ecx, 2 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x2);
s->gpr[2] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_3d2b71: STEP(0x3d2b71); /* sub ecx, ebx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_3d2b73: STEP(0x3d2b73); /* add ecx, r8d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2b76: STEP(0x3d2b76); /* add eax, r8d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2b79: STEP(0x3d2b79); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_3d2b7b: STEP(0x3d2b7b); /* movsxd rax, dword ptr [r14 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[14] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d2b7f: STEP(0x3d2b7f); /* lea rbx, [rip - 0x51] */
s->gpr[1] = (UINT64_C(0xffffffffffffffaf) + (bias + UINT64_C(0x3d2b86)));
++s->steps;
kg_pc_3d2b86: STEP(0x3d2b86); /* add rbx, rax */
x = s->gpr[1]; y = s->gpr[0];
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d2b89: STEP(0x3d2b89); /* jmp rbx */
x = s->gpr[1];
next_pc = x;
++s->steps;

break;
case 22:
next_pc=bias+UINT64_C(0x3d2cf2);
switch(s->pc-bias){
case UINT64_C(0x3d2cc4):goto kg_pc_3d2cc4;
case UINT64_C(0x3d2cc8):goto kg_pc_3d2cc8;
case UINT64_C(0x3d2cca):goto kg_pc_3d2cca;
case UINT64_C(0x3d2ccc):goto kg_pc_3d2ccc;
case UINT64_C(0x3d2ccf):goto kg_pc_3d2ccf;
case UINT64_C(0x3d2cd2):goto kg_pc_3d2cd2;
case UINT64_C(0x3d2cd6):goto kg_pc_3d2cd6;
case UINT64_C(0x3d2cd8):goto kg_pc_3d2cd8;
case UINT64_C(0x3d2cdb):goto kg_pc_3d2cdb;
case UINT64_C(0x3d2cdd):goto kg_pc_3d2cdd;
case UINT64_C(0x3d2cdf):goto kg_pc_3d2cdf;
case UINT64_C(0x3d2ce2):goto kg_pc_3d2ce2;
case UINT64_C(0x3d2ce6):goto kg_pc_3d2ce6;
case UINT64_C(0x3d2ced):goto kg_pc_3d2ced;
case UINT64_C(0x3d2cf0):goto kg_pc_3d2cf0;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1599: [0x3d2cc4,0x3d2cf2), 15 instructions. */
kg_pc_3d2cc4: STEP(0x3d2cc4); /* mov rax, qword ptr [r15 + 0x10] */
READ(a, (UINT64_C(0x10) + s->gpr[15]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_3d2cc8: STEP(0x3d2cc8); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2cca: STEP(0x3d2cca); /* xor esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2ccc: STEP(0x3d2ccc); /* test rax, rax */
x = s->gpr[0]; y = s->gpr[0];
(void)operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_3d2ccf: STEP(0x3d2ccf); /* setne dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2cd2: STEP(0x3d2cd2); /* sete sil */
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2cd6: STEP(0x3d2cd6); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2cd8: STEP(0x3d2cd8); /* lea edx, [rdx + rdx*2] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_3d2cdb: STEP(0x3d2cdb); /* add edx, ecx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2cdd: STEP(0x3d2cdd); /* add esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_3d2cdf: STEP(0x3d2cdf); /* movsxd rcx, esi */
s->gpr[2] = (((s->gpr[4] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d2ce2: STEP(0x3d2ce2); /* movsxd rcx, dword ptr [r14 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[14] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d2ce6: STEP(0x3d2ce6); /* lea rsi, [rip - 0x29] */
s->gpr[4] = (UINT64_C(0xffffffffffffffd7) + (bias + UINT64_C(0x3d2ced)));
++s->steps;
kg_pc_3d2ced: STEP(0x3d2ced); /* add rsi, rcx */
x = s->gpr[4]; y = s->gpr[2];
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d2cf0: STEP(0x3d2cf0); /* jmp rsi */
x = s->gpr[4];
next_pc = x;
++s->steps;

break;
case 23:
next_pc=bias+UINT64_C(0x3d2cf4);
switch(s->pc-bias){
case UINT64_C(0x3d2cf2):goto kg_pc_3d2cf2;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1600: [0x3d2cf2,0x3d2cf4), 1 instructions. */
kg_pc_3d2cf2: STEP(0x3d2cf2); /* sar dword ptr [rsi], cl */
READ(a, (UINT64_C(0x0) + s->gpr[4]), 4);
x = a; y = (s->gpr[2] & UINT64_C(0xff));
WRITE((UINT64_C(0x0) + s->gpr[4]), 4, operation(s, OP_SAR, x, y, 32));
++s->steps;

break;
case 24:
next_pc=bias+UINT64_C(0x3d2cf8);
switch(s->pc-bias){
case UINT64_C(0x3d2cf3):goto kg_pc_3d2cf3;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1601: [0x3d2cf3,0x3d2cf8), 1 instructions. */
kg_pc_3d2cf3: STEP(0x3d2cf3); /* mov rax, qword ptr ds:[r15 + 8] */
READ(a, (UINT64_C(0x8) + fs->tls_base + s->gpr[15]), 8);
s->gpr[0] = a;
++s->steps;

break;
case 25:
next_pc=bias+UINT64_C(0x3d2cf8);
switch(s->pc-bias){
case UINT64_C(0x3d2cf4):goto kg_pc_3d2cf4;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1602: [0x3d2cf4,0x3d2cf8), 1 instructions. */
kg_pc_3d2cf4: STEP(0x3d2cf4); /* mov rax, qword ptr [r15 + 8] */
READ(a, (UINT64_C(0x8) + s->gpr[15]), 8);
s->gpr[0] = a;
++s->steps;

break;
case 26:
next_pc=bias+UINT64_C(0x3d2d1c);
switch(s->pc-bias){
case UINT64_C(0x3d2cf5):goto kg_pc_3d2cf5;
case UINT64_C(0x3d2cf8):goto kg_pc_3d2cf8;
case UINT64_C(0x3d2cfa):goto kg_pc_3d2cfa;
case UINT64_C(0x3d2cfd):goto kg_pc_3d2cfd;
case UINT64_C(0x3d2d00):goto kg_pc_3d2d00;
case UINT64_C(0x3d2d04):goto kg_pc_3d2d04;
case UINT64_C(0x3d2d07):goto kg_pc_3d2d07;
case UINT64_C(0x3d2d0b):goto kg_pc_3d2d0b;
case UINT64_C(0x3d2d12):goto kg_pc_3d2d12;
case UINT64_C(0x3d2d15):goto kg_pc_3d2d15;
case UINT64_C(0x3d2d1a):goto kg_pc_3d2d1a;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1603: [0x3d2cf5,0x3d2d1c), 11 instructions. */
kg_pc_3d2cf5: STEP(0x3d2cf5); /* mov eax, dword ptr [rdi + 8] */
READ(a, (UINT64_C(0x8) + s->gpr[5]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_3d2cf8: STEP(0x3d2cf8); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2cfa: STEP(0x3d2cfa); /* test rax, rax */
x = s->gpr[0]; y = s->gpr[0];
(void)operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_3d2cfd: STEP(0x3d2cfd); /* sete cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2d00: STEP(0x3d2d00); /* lea ecx, [rdx + rcx + 2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x2) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d2d04: STEP(0x3d2d04); /* movsxd rcx, ecx */
s->gpr[2] = (((s->gpr[2] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d2d07: STEP(0x3d2d07); /* movsxd rcx, dword ptr [r14 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[14] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d2d0b: STEP(0x3d2d0b); /* lea rsi, [rip - 0x1e] */
s->gpr[4] = (UINT64_C(0xffffffffffffffe2) + (bias + UINT64_C(0x3d2d12)));
++s->steps;
kg_pc_3d2d12: STEP(0x3d2d12); /* add rsi, rcx */
x = s->gpr[4]; y = s->gpr[2];
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d2d15: STEP(0x3d2d15); /* mov edx, 0x5c44c60d */
s->gpr[3] = (uint32_t)(UINT64_C(0x5c44c60d));
++s->steps;
kg_pc_3d2d1a: STEP(0x3d2d1a); /* jmp rsi */
x = s->gpr[4];
next_pc = x;
++s->steps;

break;
case 27:
next_pc=bias+UINT64_C(0x3d2d4a);
switch(s->pc-bias){
case UINT64_C(0x3d2d1d):goto kg_pc_3d2d1d;
case UINT64_C(0x3d2d20):goto kg_pc_3d2d20;
case UINT64_C(0x3d2d22):goto kg_pc_3d2d22;
case UINT64_C(0x3d2d26):goto kg_pc_3d2d26;
case UINT64_C(0x3d2d28):goto kg_pc_3d2d28;
case UINT64_C(0x3d2d2b):goto kg_pc_3d2d2b;
case UINT64_C(0x3d2d2e):goto kg_pc_3d2d2e;
case UINT64_C(0x3d2d32):goto kg_pc_3d2d32;
case UINT64_C(0x3d2d35):goto kg_pc_3d2d35;
case UINT64_C(0x3d2d39):goto kg_pc_3d2d39;
case UINT64_C(0x3d2d40):goto kg_pc_3d2d40;
case UINT64_C(0x3d2d43):goto kg_pc_3d2d43;
case UINT64_C(0x3d2d48):goto kg_pc_3d2d48;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1604: [0x3d2d1d,0x3d2d4a), 13 instructions. */
kg_pc_3d2d1d: STEP(0x3d2d1d); /* mov ecx, dword ptr [rbp - 0x30] */
READ(a, (UINT64_C(0xffffffffffffffd0) + s->gpr[6]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
kg_pc_3d2d20: STEP(0x3d2d20); /* mov dword ptr [rax], ecx */
WRITE((UINT64_C(0x0) + s->gpr[0]), 4, (s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d2d22: STEP(0x3d2d22); /* mov rax, qword ptr [r15 + 8] */
READ(a, (UINT64_C(0x8) + s->gpr[15]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_3d2d26: STEP(0x3d2d26); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_3d2d28: STEP(0x3d2d28); /* test rax, rax */
x = s->gpr[0]; y = s->gpr[0];
(void)operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_3d2d2b: STEP(0x3d2d2b); /* sete cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_3d2d2e: STEP(0x3d2d2e); /* lea ecx, [rdx + rcx + 2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x2) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_3d2d32: STEP(0x3d2d32); /* movsxd rcx, ecx */
s->gpr[2] = (((s->gpr[2] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d2d35: STEP(0x3d2d35); /* movsxd rcx, dword ptr [r14 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[14] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_3d2d39: STEP(0x3d2d39); /* lea rsi, [rip - 0x4c] */
s->gpr[4] = (UINT64_C(0xffffffffffffffb4) + (bias + UINT64_C(0x3d2d40)));
++s->steps;
kg_pc_3d2d40: STEP(0x3d2d40); /* add rsi, rcx */
x = s->gpr[4]; y = s->gpr[2];
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d2d43: STEP(0x3d2d43); /* mov edx, 0x5c44c60d */
s->gpr[3] = (uint32_t)(UINT64_C(0x5c44c60d));
++s->steps;
kg_pc_3d2d48: STEP(0x3d2d48); /* jmp rsi */
x = s->gpr[4];
next_pc = x;
++s->steps;

break;
case 28:
next_pc=bias+UINT64_C(0x3d2d6c);
switch(s->pc-bias){
case UINT64_C(0x3d2d4d):goto kg_pc_3d2d4d;
case UINT64_C(0x3d2d51):goto kg_pc_3d2d51;
case UINT64_C(0x3d2d54):goto kg_pc_3d2d54;
case UINT64_C(0x3d2d59):goto kg_pc_3d2d59;
case UINT64_C(0x3d2d5d):goto kg_pc_3d2d5d;
case UINT64_C(0x3d2d61):goto kg_pc_3d2d61;
case UINT64_C(0x3d2d62):goto kg_pc_3d2d62;
case UINT64_C(0x3d2d64):goto kg_pc_3d2d64;
case UINT64_C(0x3d2d66):goto kg_pc_3d2d66;
case UINT64_C(0x3d2d68):goto kg_pc_3d2d68;
case UINT64_C(0x3d2d6a):goto kg_pc_3d2d6a;
case UINT64_C(0x3d2d6b):goto kg_pc_3d2d6b;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: cc75fb416f3f03b283d16a22d2ffb130a03c830a6a66f291389472bae524b175
 * Path 1605: [0x3d2d4d,0x3d2d6c), 12 instructions. */
kg_pc_3d2d4d: STEP(0x3d2d4d); /* mov rcx, qword ptr [rbp - 0x38] */
READ(a, (UINT64_C(0xffffffffffffffc8) + s->gpr[6]), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_3d2d51: STEP(0x3d2d51); /* mov qword ptr [rax], rcx */
WRITE((UINT64_C(0x0) + s->gpr[0]), 8, s->gpr[2]);
++s->steps;
kg_pc_3d2d54: STEP(0x3d2d54); /* mov edx, 0x5c44c60d */
s->gpr[3] = (uint32_t)(UINT64_C(0x5c44c60d));
++s->steps;
kg_pc_3d2d59: STEP(0x3d2d59); /* mov dword ptr [r15 + 0x28], edx */
WRITE((UINT64_C(0x28) + s->gpr[15]), 4, (s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_3d2d5d: STEP(0x3d2d5d); /* add rsp, 0x48 */
x = s->gpr[7]; y = UINT64_C(0x48);
s->gpr[7] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_3d2d61: STEP(0x3d2d61); /* pop rbx */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
s->gpr[1] = x;
++s->steps;
kg_pc_3d2d62: STEP(0x3d2d62); /* pop r12 */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
s->gpr[12] = x;
++s->steps;
kg_pc_3d2d64: STEP(0x3d2d64); /* pop r13 */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
s->gpr[13] = x;
++s->steps;
kg_pc_3d2d66: STEP(0x3d2d66); /* pop r14 */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
s->gpr[14] = x;
++s->steps;
kg_pc_3d2d68: STEP(0x3d2d68); /* pop r15 */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
s->gpr[15] = x;
++s->steps;
kg_pc_3d2d6a: STEP(0x3d2d6a); /* pop rbp */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
s->gpr[6] = x;
++s->steps;
kg_pc_3d2d6b: STEP(0x3d2d6b); /* ret  */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
next_pc = x;
++s->steps;

break;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
NATIVE_DONE;}
