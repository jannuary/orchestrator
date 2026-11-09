#include "../spc_native_internal.h"
int wrapper_kg_native_page_48(unsigned block,uint64_t bias,wrapper_kg_native_state *fs,const wrapper_kg_payload_region *regions,size_t count,size_t max_steps) {
    NATIVE_LOCALS;
    switch(block) {
    case 0:
next_pc=bias+UINT64_C(0x4805b6);
switch(s->pc-bias){
case UINT64_C(0x48021c):goto kg_pc_48021c;
case UINT64_C(0x480222):goto kg_pc_480222;
case UINT64_C(0x480224):goto kg_pc_480224;
case UINT64_C(0x480226):goto kg_pc_480226;
case UINT64_C(0x48022c):goto kg_pc_48022c;
case UINT64_C(0x48022f):goto kg_pc_48022f;
case UINT64_C(0x480232):goto kg_pc_480232;
case UINT64_C(0x480235):goto kg_pc_480235;
case UINT64_C(0x48023f):goto kg_pc_48023f;
case UINT64_C(0x480242):goto kg_pc_480242;
case UINT64_C(0x480249):goto kg_pc_480249;
case UINT64_C(0x48024c):goto kg_pc_48024c;
case UINT64_C(0x480252):goto kg_pc_480252;
case UINT64_C(0x480258):goto kg_pc_480258;
case UINT64_C(0x48025c):goto kg_pc_48025c;
case UINT64_C(0x480263):goto kg_pc_480263;
case UINT64_C(0x480266):goto kg_pc_480266;
case UINT64_C(0x48026c):goto kg_pc_48026c;
case UINT64_C(0x48026f):goto kg_pc_48026f;
case UINT64_C(0x480272):goto kg_pc_480272;
case UINT64_C(0x48027c):goto kg_pc_48027c;
case UINT64_C(0x480284):goto kg_pc_480284;
case UINT64_C(0x480287):goto kg_pc_480287;
case UINT64_C(0x480291):goto kg_pc_480291;
case UINT64_C(0x480294):goto kg_pc_480294;
case UINT64_C(0x480297):goto kg_pc_480297;
case UINT64_C(0x48029d):goto kg_pc_48029d;
case UINT64_C(0x4802a1):goto kg_pc_4802a1;
case UINT64_C(0x4802a5):goto kg_pc_4802a5;
case UINT64_C(0x4802ab):goto kg_pc_4802ab;
case UINT64_C(0x4802ae):goto kg_pc_4802ae;
case UINT64_C(0x4802b4):goto kg_pc_4802b4;
case UINT64_C(0x4802b7):goto kg_pc_4802b7;
case UINT64_C(0x4802ba):goto kg_pc_4802ba;
case UINT64_C(0x4802bc):goto kg_pc_4802bc;
case UINT64_C(0x4802be):goto kg_pc_4802be;
case UINT64_C(0x4802c4):goto kg_pc_4802c4;
case UINT64_C(0x4802ca):goto kg_pc_4802ca;
case UINT64_C(0x4802cd):goto kg_pc_4802cd;
case UINT64_C(0x4802d3):goto kg_pc_4802d3;
case UINT64_C(0x4802d5):goto kg_pc_4802d5;
case UINT64_C(0x4802d7):goto kg_pc_4802d7;
case UINT64_C(0x4802dd):goto kg_pc_4802dd;
case UINT64_C(0x4802e0):goto kg_pc_4802e0;
case UINT64_C(0x4802ea):goto kg_pc_4802ea;
case UINT64_C(0x4802ed):goto kg_pc_4802ed;
case UINT64_C(0x4802f3):goto kg_pc_4802f3;
case UINT64_C(0x4802f6):goto kg_pc_4802f6;
case UINT64_C(0x4802f9):goto kg_pc_4802f9;
case UINT64_C(0x480303):goto kg_pc_480303;
case UINT64_C(0x480307):goto kg_pc_480307;
case UINT64_C(0x48030e):goto kg_pc_48030e;
case UINT64_C(0x480314):goto kg_pc_480314;
case UINT64_C(0x480318):goto kg_pc_480318;
case UINT64_C(0x48031c):goto kg_pc_48031c;
case UINT64_C(0x48031f):goto kg_pc_48031f;
case UINT64_C(0x480322):goto kg_pc_480322;
case UINT64_C(0x480325):goto kg_pc_480325;
case UINT64_C(0x480328):goto kg_pc_480328;
case UINT64_C(0x48032e):goto kg_pc_48032e;
case UINT64_C(0x480330):goto kg_pc_480330;
case UINT64_C(0x480332):goto kg_pc_480332;
case UINT64_C(0x480338):goto kg_pc_480338;
case UINT64_C(0x48033e):goto kg_pc_48033e;
case UINT64_C(0x480341):goto kg_pc_480341;
case UINT64_C(0x480347):goto kg_pc_480347;
case UINT64_C(0x480349):goto kg_pc_480349;
case UINT64_C(0x48034b):goto kg_pc_48034b;
case UINT64_C(0x480351):goto kg_pc_480351;
case UINT64_C(0x480354):goto kg_pc_480354;
case UINT64_C(0x480357):goto kg_pc_480357;
case UINT64_C(0x48035f):goto kg_pc_48035f;
case UINT64_C(0x480362):goto kg_pc_480362;
case UINT64_C(0x48036c):goto kg_pc_48036c;
case UINT64_C(0x48036f):goto kg_pc_48036f;
case UINT64_C(0x480372):goto kg_pc_480372;
case UINT64_C(0x480376):goto kg_pc_480376;
case UINT64_C(0x480380):goto kg_pc_480380;
case UINT64_C(0x480384):goto kg_pc_480384;
case UINT64_C(0x48038b):goto kg_pc_48038b;
case UINT64_C(0x480391):goto kg_pc_480391;
case UINT64_C(0x480395):goto kg_pc_480395;
case UINT64_C(0x480399):goto kg_pc_480399;
case UINT64_C(0x48039c):goto kg_pc_48039c;
case UINT64_C(0x48039f):goto kg_pc_48039f;
case UINT64_C(0x4803a7):goto kg_pc_4803a7;
case UINT64_C(0x4803aa):goto kg_pc_4803aa;
case UINT64_C(0x4803ad):goto kg_pc_4803ad;
case UINT64_C(0x4803b7):goto kg_pc_4803b7;
case UINT64_C(0x4803ba):goto kg_pc_4803ba;
case UINT64_C(0x4803bd):goto kg_pc_4803bd;
case UINT64_C(0x4803c1):goto kg_pc_4803c1;
case UINT64_C(0x4803cb):goto kg_pc_4803cb;
case UINT64_C(0x4803cf):goto kg_pc_4803cf;
case UINT64_C(0x4803d6):goto kg_pc_4803d6;
case UINT64_C(0x4803da):goto kg_pc_4803da;
case UINT64_C(0x4803e1):goto kg_pc_4803e1;
case UINT64_C(0x4803e4):goto kg_pc_4803e4;
case UINT64_C(0x4803eb):goto kg_pc_4803eb;
case UINT64_C(0x4803ef):goto kg_pc_4803ef;
case UINT64_C(0x4803f6):goto kg_pc_4803f6;
case UINT64_C(0x4803fb):goto kg_pc_4803fb;
case UINT64_C(0x480401):goto kg_pc_480401;
case UINT64_C(0x480403):goto kg_pc_480403;
case UINT64_C(0x480407):goto kg_pc_480407;
case UINT64_C(0x48040c):goto kg_pc_48040c;
case UINT64_C(0x480411):goto kg_pc_480411;
case UINT64_C(0x480414):goto kg_pc_480414;
case UINT64_C(0x48041a):goto kg_pc_48041a;
case UINT64_C(0x48041c):goto kg_pc_48041c;
case UINT64_C(0x48041e):goto kg_pc_48041e;
case UINT64_C(0x480423):goto kg_pc_480423;
case UINT64_C(0x480426):goto kg_pc_480426;
case UINT64_C(0x480429):goto kg_pc_480429;
case UINT64_C(0x480433):goto kg_pc_480433;
case UINT64_C(0x480436):goto kg_pc_480436;
case UINT64_C(0x48043d):goto kg_pc_48043d;
case UINT64_C(0x480444):goto kg_pc_480444;
case UINT64_C(0x48044a):goto kg_pc_48044a;
case UINT64_C(0x48044e):goto kg_pc_48044e;
case UINT64_C(0x480451):goto kg_pc_480451;
case UINT64_C(0x480455):goto kg_pc_480455;
case UINT64_C(0x48045c):goto kg_pc_48045c;
case UINT64_C(0x48045f):goto kg_pc_48045f;
case UINT64_C(0x480465):goto kg_pc_480465;
case UINT64_C(0x480468):goto kg_pc_480468;
case UINT64_C(0x480472):goto kg_pc_480472;
case UINT64_C(0x480475):goto kg_pc_480475;
case UINT64_C(0x480477):goto kg_pc_480477;
case UINT64_C(0x48047d):goto kg_pc_48047d;
case UINT64_C(0x480480):goto kg_pc_480480;
case UINT64_C(0x480485):goto kg_pc_480485;
case UINT64_C(0x480489):goto kg_pc_480489;
case UINT64_C(0x48048d):goto kg_pc_48048d;
case UINT64_C(0x480490):goto kg_pc_480490;
case UINT64_C(0x480493):goto kg_pc_480493;
case UINT64_C(0x480496):goto kg_pc_480496;
case UINT64_C(0x480499):goto kg_pc_480499;
case UINT64_C(0x48049c):goto kg_pc_48049c;
case UINT64_C(0x4804a2):goto kg_pc_4804a2;
case UINT64_C(0x4804a4):goto kg_pc_4804a4;
case UINT64_C(0x4804a6):goto kg_pc_4804a6;
case UINT64_C(0x4804ac):goto kg_pc_4804ac;
case UINT64_C(0x4804b2):goto kg_pc_4804b2;
case UINT64_C(0x4804b5):goto kg_pc_4804b5;
case UINT64_C(0x4804bb):goto kg_pc_4804bb;
case UINT64_C(0x4804bd):goto kg_pc_4804bd;
case UINT64_C(0x4804c0):goto kg_pc_4804c0;
case UINT64_C(0x4804c6):goto kg_pc_4804c6;
case UINT64_C(0x4804c9):goto kg_pc_4804c9;
case UINT64_C(0x4804cc):goto kg_pc_4804cc;
case UINT64_C(0x4804cf):goto kg_pc_4804cf;
case UINT64_C(0x4804d6):goto kg_pc_4804d6;
case UINT64_C(0x4804d9):goto kg_pc_4804d9;
case UINT64_C(0x4804e3):goto kg_pc_4804e3;
case UINT64_C(0x4804e6):goto kg_pc_4804e6;
case UINT64_C(0x4804e9):goto kg_pc_4804e9;
case UINT64_C(0x4804f3):goto kg_pc_4804f3;
case UINT64_C(0x4804f7):goto kg_pc_4804f7;
case UINT64_C(0x4804fe):goto kg_pc_4804fe;
case UINT64_C(0x480504):goto kg_pc_480504;
case UINT64_C(0x480508):goto kg_pc_480508;
case UINT64_C(0x48050c):goto kg_pc_48050c;
case UINT64_C(0x480512):goto kg_pc_480512;
case UINT64_C(0x480515):goto kg_pc_480515;
case UINT64_C(0x480518):goto kg_pc_480518;
case UINT64_C(0x48051b):goto kg_pc_48051b;
case UINT64_C(0x48051e):goto kg_pc_48051e;
case UINT64_C(0x480521):goto kg_pc_480521;
case UINT64_C(0x480523):goto kg_pc_480523;
case UINT64_C(0x480525):goto kg_pc_480525;
case UINT64_C(0x48052a):goto kg_pc_48052a;
case UINT64_C(0x48052f):goto kg_pc_48052f;
case UINT64_C(0x480532):goto kg_pc_480532;
case UINT64_C(0x480538):goto kg_pc_480538;
case UINT64_C(0x48053a):goto kg_pc_48053a;
case UINT64_C(0x48053c):goto kg_pc_48053c;
case UINT64_C(0x480542):goto kg_pc_480542;
case UINT64_C(0x480545):goto kg_pc_480545;
case UINT64_C(0x480548):goto kg_pc_480548;
case UINT64_C(0x48054f):goto kg_pc_48054f;
case UINT64_C(0x480552):goto kg_pc_480552;
case UINT64_C(0x48055c):goto kg_pc_48055c;
case UINT64_C(0x48055f):goto kg_pc_48055f;
case UINT64_C(0x480562):goto kg_pc_480562;
case UINT64_C(0x480566):goto kg_pc_480566;
case UINT64_C(0x48056a):goto kg_pc_48056a;
case UINT64_C(0x48056d):goto kg_pc_48056d;
case UINT64_C(0x480577):goto kg_pc_480577;
case UINT64_C(0x48057b):goto kg_pc_48057b;
case UINT64_C(0x480582):goto kg_pc_480582;
case UINT64_C(0x480588):goto kg_pc_480588;
case UINT64_C(0x48058c):goto kg_pc_48058c;
case UINT64_C(0x480590):goto kg_pc_480590;
case UINT64_C(0x480596):goto kg_pc_480596;
case UINT64_C(0x480599):goto kg_pc_480599;
case UINT64_C(0x48059f):goto kg_pc_48059f;
case UINT64_C(0x4805a2):goto kg_pc_4805a2;
case UINT64_C(0x4805a8):goto kg_pc_4805a8;
case UINT64_C(0x4805ae):goto kg_pc_4805ae;
case UINT64_C(0x4805b0):goto kg_pc_4805b0;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5239: [0x48021c,0x4805b6), 201 instructions. */
kg_pc_48021c: STEP(0x48021c); /* and edi, 0x12754 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x12754);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480222: STEP(0x480222); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480224: STEP(0x480224); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480226: STEP(0x480226); /* add esi, 0x5c12d3aa */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x5c12d3aa);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48022c: STEP(0x48022c); /* mov edi, r10d */
s->gpr[5] = (uint32_t)((s->gpr[10] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48022f: STEP(0x48022f); /* shr edi, 0x18 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[5] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_480232: STEP(0x480232); /* xor edi, 0x33 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x33);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480235: STEP(0x480235); /* movabs rax, 0xf7bbfff9ff3c8400 */
s->gpr[0] = UINT64_C(0xf7bbfff9ff3c8400);
++s->steps;
kg_pc_48023f: STEP(0x48023f); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480242: STEP(0x480242); /* mov qword ptr [rbp - 0x498], rdx */
WRITE((UINT64_C(0xfffffffffffffb68) + s->gpr[6]), 8, s->gpr[3]);
++s->steps;
kg_pc_480249: STEP(0x480249); /* mov eax, dword ptr [rdx + rdi*4] */
READ(a, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[5] * UINT64_C(0x4))), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_48024c: STEP(0x48024c); /* mov dword ptr [rbp - 0x380], eax */
WRITE((UINT64_C(0xfffffffffffffc80) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480252: STEP(0x480252); /* xor ecx, 0x50244 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x50244);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480258: STEP(0x480258); /* lea r9, [rdx + rcx*4] */
s->gpr[9] = (UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x4)));
++s->steps;
kg_pc_48025c: STEP(0x48025c); /* mov qword ptr [rbp - 0x498], r9 */
WRITE((UINT64_C(0xfffffffffffffb68) + s->gpr[6]), 8, s->gpr[9]);
++s->steps;
kg_pc_480263: STEP(0x480263); /* mov eax, dword ptr [rdx + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_480266: STEP(0x480266); /* mov dword ptr [rbp - 0x340], eax */
WRITE((UINT64_C(0xfffffffffffffcc0) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48026c: STEP(0x48026c); /* mov rdx, rcx */
s->gpr[3] = s->gpr[2];
++s->steps;
kg_pc_48026f: STEP(0x48026f); /* add rcx, rcx */
x = s->gpr[2]; y = s->gpr[2];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480272: STEP(0x480272); /* movabs r12, 0x200000000 */
s->gpr[12] = UINT64_C(0x200000000);
++s->steps;
kg_pc_48027c: STEP(0x48027c); /* lea rdi, [r12 - 0x120834a] */
s->gpr[5] = (UINT64_C(0xfffffffffedf7cb6) + s->gpr[12]);
++s->steps;
kg_pc_480284: STEP(0x480284); /* and rdi, rcx */
x = s->gpr[5]; y = s->gpr[2];
s->gpr[5] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_480287: STEP(0x480287); /* movabs rax, 0x2878301009041a4 */
s->gpr[0] = UINT64_C(0x2878301009041a4);
++s->steps;
kg_pc_480291: STEP(0x480291); /* xor rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_480294: STEP(0x480294); /* sub rdx, rdi */
x = s->gpr[3]; y = s->gpr[5];
s->gpr[3] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_480297: STEP(0x480297); /* xor esi, 0x7c1a4fe3 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x7c1a4fe3);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48029d: STEP(0x48029d); /* lea rcx, [r9 + rsi*4] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[9] + (s->gpr[4] * UINT64_C(0x4)));
++s->steps;
kg_pc_4802a1: STEP(0x4802a1); /* lea r9, [rcx + rdx*4] */
s->gpr[9] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x4)));
++s->steps;
kg_pc_4802a5: STEP(0x4802a5); /* mov eax, dword ptr [rbp - 0xf8] */
READ(a, (UINT64_C(0xffffffffffffff08) + s->gpr[6]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_4802ab: STEP(0x4802ab); /* movzx edx, ah */
s->gpr[3] = (uint32_t)(((s->gpr[0] >> 8) & UINT64_C(0xff)));
++s->steps;
kg_pc_4802ae: STEP(0x4802ae); /* xor edx, 0xb6 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xb6);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4802b4: STEP(0x4802b4); /* lea edi, [rdx + rdx] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_4802b7: STEP(0x4802b7); /* and edi, 0x1c */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x1c);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4802ba: STEP(0x4802ba); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4802bc: STEP(0x4802bc); /* add edx, edi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4802be: STEP(0x4802be); /* add edx, 0x1dd130e */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1dd130e);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4802c4: STEP(0x4802c4); /* xor edx, 0x5c5116 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x5c5116);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4802ca: STEP(0x4802ca); /* lea edi, [rdx + rdx] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_4802cd: STEP(0x4802cd); /* and edi, 0x3003214 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x3003214);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4802d3: STEP(0x4802d3); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4802d5: STEP(0x4802d5); /* add edx, edi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4802d7: STEP(0x4802d7); /* add edx, 0x63dcb90a */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x63dcb90a);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4802dd: STEP(0x4802dd); /* mov rdi, rsi */
s->gpr[5] = s->gpr[4];
++s->steps;
kg_pc_4802e0: STEP(0x4802e0); /* movabs rax, 0x604e06c82000010 */
s->gpr[0] = UINT64_C(0x604e06c82000010);
++s->steps;
kg_pc_4802ea: STEP(0x4802ea); /* xor rdi, rax */
x = s->gpr[5]; y = s->gpr[0];
s->gpr[5] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_4802ed: STEP(0x4802ed); /* and esi, 0x7dffffef */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x7dffffef);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4802f3: STEP(0x4802f3); /* add rsi, rsi */
x = s->gpr[4]; y = s->gpr[4];
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4802f6: STEP(0x4802f6); /* sub rdi, rsi */
x = s->gpr[5]; y = s->gpr[4];
s->gpr[5] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_4802f9: STEP(0x4802f9); /* movabs rax, 0xf5e1f3fbfdbef970 */
s->gpr[0] = UINT64_C(0xf5e1f3fbfdbef970);
++s->steps;
kg_pc_480303: STEP(0x480303); /* lea rsi, [r9 + rax] */
s->gpr[4] = (UINT64_C(0x0) + s->gpr[9] + (s->gpr[0] * UINT64_C(0x1)));
++s->steps;
kg_pc_480307: STEP(0x480307); /* mov qword ptr [rbp - 0x498], rsi */
WRITE((UINT64_C(0xfffffffffffffb68) + s->gpr[6]), 8, s->gpr[4]);
++s->steps;
kg_pc_48030e: STEP(0x48030e); /* xor edx, 0x625dfb49 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x625dfb49);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480314: STEP(0x480314); /* lea rsi, [rsi + rdx*4] */
s->gpr[4] = (UINT64_C(0x0) + s->gpr[4] + (s->gpr[3] * UINT64_C(0x4)));
++s->steps;
kg_pc_480318: STEP(0x480318); /* lea rsi, [rsi + rdi*4] */
s->gpr[4] = (UINT64_C(0x0) + s->gpr[4] + (s->gpr[5] * UINT64_C(0x4)));
++s->steps;
kg_pc_48031c: STEP(0x48031c); /* shr ebx, 0x10 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[1] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_48031f: STEP(0x48031f); /* movzx edi, bl */
s->gpr[5] = (uint32_t)((s->gpr[1] & UINT64_C(0xff)));
++s->steps;
kg_pc_480322: STEP(0x480322); /* xor edi, 0x3b */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x3b);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480325: STEP(0x480325); /* lea ebx, [rdi + rdi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_480328: STEP(0x480328); /* and ebx, 0x110 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x110);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48032e: STEP(0x48032e); /* neg ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = 0;
s->gpr[1] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480330: STEP(0x480330); /* add edi, ebx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480332: STEP(0x480332); /* add edi, 0x1e0b2b88 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x1e0b2b88);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480338: STEP(0x480338); /* xor edi, 0xc0b2b88 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xc0b2b88);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48033e: STEP(0x48033e); /* lea ebx, [rdi + rdi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_480341: STEP(0x480341); /* and ebx, 0x4000452 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x4000452);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480347: STEP(0x480347); /* neg ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = 0;
s->gpr[1] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480349: STEP(0x480349); /* add edi, ebx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48034b: STEP(0x48034b); /* add edi, 0x3bfe229 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x3bfe229);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480351: STEP(0x480351); /* mov rbx, rdx */
s->gpr[1] = s->gpr[3];
++s->steps;
kg_pc_480354: STEP(0x480354); /* add rdx, rdx */
x = s->gpr[3]; y = s->gpr[3];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480357: STEP(0x480357); /* lea rcx, [r12 - 0x10a534] */
s->gpr[2] = (UINT64_C(0xffffffffffef5acc) + s->gpr[12]);
++s->steps;
kg_pc_48035f: STEP(0x48035f); /* and rcx, rdx */
x = s->gpr[2]; y = s->gpr[3];
s->gpr[2] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_480362: STEP(0x480362); /* movabs rdx, 0x401232100085299 */
s->gpr[3] = UINT64_C(0x401232100085299);
++s->steps;
kg_pc_48036c: STEP(0x48036c); /* xor rbx, rdx */
x = s->gpr[1]; y = s->gpr[3];
s->gpr[1] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_48036f: STEP(0x48036f); /* sub rbx, rcx */
x = s->gpr[1]; y = s->gpr[2];
s->gpr[1] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_480372: STEP(0x480372); /* mov r15d, dword ptr [rax + r9] */
READ(a, (UINT64_C(0x0) + s->gpr[0] + (s->gpr[9] * UINT64_C(0x1))), 4);
s->gpr[15] = (uint32_t)(a);
++s->steps;
kg_pc_480376: STEP(0x480376); /* movabs rax, 0xe7ec7e4df7ffffc0 */
s->gpr[0] = UINT64_C(0xe7ec7e4df7ffffc0);
++s->steps;
kg_pc_480380: STEP(0x480380); /* lea rcx, [rsi + rax] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[4] + (s->gpr[0] * UINT64_C(0x1)));
++s->steps;
kg_pc_480384: STEP(0x480384); /* mov qword ptr [rbp - 0x498], rcx */
WRITE((UINT64_C(0xfffffffffffffb68) + s->gpr[6]), 8, s->gpr[2]);
++s->steps;
kg_pc_48038b: STEP(0x48038b); /* xor edi, 0x11bfe262 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x11bfe262);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480391: STEP(0x480391); /* lea rcx, [rcx + rdi*4] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[5] * UINT64_C(0x4)));
++s->steps;
kg_pc_480395: STEP(0x480395); /* lea rcx, [rcx + rbx*4] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[1] * UINT64_C(0x4)));
++s->steps;
kg_pc_480399: STEP(0x480399); /* mov rdx, rdi */
s->gpr[3] = s->gpr[5];
++s->steps;
kg_pc_48039c: STEP(0x48039c); /* add rdi, rdi */
x = s->gpr[5]; y = s->gpr[5];
s->gpr[5] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_48039f: STEP(0x48039f); /* lea rbx, [r12 - 0x28030de6] */
s->gpr[1] = (UINT64_C(0xffffffffd7fcf21a) + s->gpr[12]);
++s->steps;
kg_pc_4803a7: STEP(0x4803a7); /* mov r9, r12 */
s->gpr[9] = s->gpr[12];
++s->steps;
kg_pc_4803aa: STEP(0x4803aa); /* and rbx, rdi */
x = s->gpr[1]; y = s->gpr[5];
s->gpr[1] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_4803ad: STEP(0x4803ad); /* movabs rdi, 0x640ac30140186f2 */
s->gpr[5] = UINT64_C(0x640ac30140186f2);
++s->steps;
kg_pc_4803b7: STEP(0x4803b7); /* xor rdx, rdi */
x = s->gpr[3]; y = s->gpr[5];
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_4803ba: STEP(0x4803ba); /* sub rdx, rbx */
x = s->gpr[3]; y = s->gpr[1];
s->gpr[3] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_4803bd: STEP(0x4803bd); /* mov r12d, dword ptr [rax + rsi] */
READ(a, (UINT64_C(0x0) + s->gpr[0] + (s->gpr[4] * UINT64_C(0x1))), 4);
s->gpr[12] = (uint32_t)(a);
++s->steps;
kg_pc_4803c1: STEP(0x4803c1); /* movabs rax, 0xeffb737bffdeb59c */
s->gpr[0] = UINT64_C(0xeffb737bffdeb59c);
++s->steps;
kg_pc_4803cb: STEP(0x4803cb); /* lea rsi, [rcx + rax] */
s->gpr[4] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x1)));
++s->steps;
kg_pc_4803cf: STEP(0x4803cf); /* mov qword ptr [rbp - 0x498], rsi */
WRITE((UINT64_C(0xfffffffffffffb68) + s->gpr[6]), 8, s->gpr[4]);
++s->steps;
kg_pc_4803d6: STEP(0x4803d6); /* lea rdx, [rsi + rdx*4] */
s->gpr[3] = (UINT64_C(0x0) + s->gpr[4] + (s->gpr[3] * UINT64_C(0x4)));
++s->steps;
kg_pc_4803da: STEP(0x4803da); /* mov rsi, qword ptr [rbp - 0x920] */
READ(a, (UINT64_C(0xfffffffffffff6e0) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_4803e1: STEP(0x4803e1); /* mov r11d, esi */
s->gpr[11] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4803e4: STEP(0x4803e4); /* xor r11d, dword ptr [rbp - 0x350] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xfffffffffffffcb0) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1)));
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[11] = (uint32_t)(operation(s, OP_XOR, (s->gpr[11] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x4803ef);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xfffffffffffffcb0) + s->gpr[6]), 4);
x=(s->gpr[11] & UINT64_C(0xffffffff));y=b;
s->gpr[11] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4803eb: STEP(0x4803eb); /* xor r11d, dword ptr [rax + rcx] */
READ(b, (UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1))), 4);
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = b;
s->gpr[11] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4803ef: STEP(0x4803ef); /* xor r13d, 0xdb */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = UINT64_C(0xdb);
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4803f6: STEP(0x4803f6); /* lea ecx, [r13 + r13] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[13] + (s->gpr[13] * UINT64_C(0x1))));
++s->steps;
kg_pc_4803fb: STEP(0x4803fb); /* and ecx, 0x126 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x126);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480401: STEP(0x480401); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480403: STEP(0x480403); /* lea eax, [rcx + r13] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[13] * UINT64_C(0x1))));
++s->steps;
kg_pc_480407: STEP(0x480407); /* add eax, 0x817d593 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x817d593);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48040c: STEP(0x48040c); /* xor eax, 0x345ac4b9 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x345ac4b9);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480411: STEP(0x480411); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_480414: STEP(0x480414); /* and ecx, 0x300a2ffe */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x300a2ffe);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48041a: STEP(0x48041a); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_48041c: STEP(0x48041c); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48041e: STEP(0x48041e); /* add eax, 0x5935bfff */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x5935bfff);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480423: STEP(0x480423); /* mov ecx, r14d */
s->gpr[2] = (uint32_t)((s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480426: STEP(0x480426); /* shr ecx, 0x18 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[2] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_480429: STEP(0x480429); /* movabs rsi, 0xe6fd4f3faff9e438 */
s->gpr[4] = UINT64_C(0xe6fd4f3faff9e438);
++s->steps;
kg_pc_480433: STEP(0x480433); /* add rdx, rsi */
x = s->gpr[3]; y = s->gpr[4];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480436: STEP(0x480436); /* mov qword ptr [rbp - 0x498], rdx */
WRITE((UINT64_C(0xfffffffffffffb68) + s->gpr[6]), 8, s->gpr[3]);
++s->steps;
kg_pc_48043d: STEP(0x48043d); /* movzx esi, byte ptr [rbp - 0xf8] */
READ(a, (UINT64_C(0xffffffffffffff08) + s->gpr[6]), 1);
s->gpr[4] = (uint32_t)(a);
++s->steps;
kg_pc_480444: STEP(0x480444); /* xor esi, 0xa0 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xa0);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48044a: STEP(0x48044a); /* mov r13d, dword ptr [rdx + rsi*4] */
READ(a, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x4))), 4);
s->gpr[13] = (uint32_t)(a);
++s->steps;
kg_pc_48044e: STEP(0x48044e); /* xor ecx, 0x42 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x42);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480451: STEP(0x480451); /* lea rsi, [rdx + rcx*4] */
s->gpr[4] = (UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x4)));
++s->steps;
kg_pc_480455: STEP(0x480455); /* mov qword ptr [rbp - 0x498], rsi */
WRITE((UINT64_C(0xfffffffffffffb68) + s->gpr[6]), 8, s->gpr[4]);
++s->steps;
kg_pc_48045c: STEP(0x48045c); /* mov edx, dword ptr [rdx + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_48045f: STEP(0x48045f); /* mov dword ptr [rbp - 0x360], edx */
WRITE((UINT64_C(0xfffffffffffffca0) + s->gpr[6]), 4, (s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480465: STEP(0x480465); /* mov rdx, rcx */
s->gpr[3] = s->gpr[2];
++s->steps;
kg_pc_480468: STEP(0x480468); /* movabs rbx, 0x602cd5550282040 */
s->gpr[1] = UINT64_C(0x602cd5550282040);
++s->steps;
kg_pc_480472: STEP(0x480472); /* xor rdx, rbx */
x = s->gpr[3]; y = s->gpr[1];
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_480475: STEP(0x480475); /* add ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480477: STEP(0x480477); /* and ecx, 0x17e */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x17e);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48047d: STEP(0x48047d); /* sub rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_480480: STEP(0x480480); /* xor eax, 0x6578ae3e */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x6578ae3e);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480485: STEP(0x480485); /* lea rcx, [rsi + rax*4] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[4] + (s->gpr[0] * UINT64_C(0x4)));
++s->steps;
kg_pc_480489: STEP(0x480489); /* lea rbx, [rcx + rdx*4] */
s->gpr[1] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x4)));
++s->steps;
kg_pc_48048d: STEP(0x48048d); /* mov ecx, r14d */
s->gpr[2] = (uint32_t)((s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480490: STEP(0x480490); /* shr ecx, 0x10 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[2] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_480493: STEP(0x480493); /* movzx ecx, cl */
s->gpr[2] = (uint32_t)((s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_480496: STEP(0x480496); /* xor ecx, 0xf */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xf);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480499: STEP(0x480499); /* lea edx, [rcx + rcx] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_48049c: STEP(0x48049c); /* and edx, 0x15a */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x15a);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4804a2: STEP(0x4804a2); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4804a4: STEP(0x4804a4); /* add ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4804a6: STEP(0x4804a6); /* add ecx, 0x61d35aad */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x61d35aad);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4804ac: STEP(0x4804ac); /* xor ecx, 0x80f702b5 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x80f702b5);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4804b2: STEP(0x4804b2); /* lea edx, [rcx + rcx] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_4804b5: STEP(0x4804b5); /* and edx, 0xc200852a */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xc200852a);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4804bb: STEP(0x4804bb); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4804bd: STEP(0x4804bd); /* lea esi, [rcx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_4804c0: STEP(0x4804c0); /* add esi, 0xf7086295 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xf7086295);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4804c6: STEP(0x4804c6); /* mov rcx, rax */
s->gpr[2] = s->gpr[0];
++s->steps;
kg_pc_4804c9: STEP(0x4804c9); /* add rax, rax */
x = s->gpr[0]; y = s->gpr[0];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4804cc: STEP(0x4804cc); /* mov rdi, r9 */
s->gpr[5] = s->gpr[9];
++s->steps;
kg_pc_4804cf: STEP(0x4804cf); /* lea rdx, [r9 - 0x7ad680a] */
s->gpr[3] = (UINT64_C(0xfffffffff85297f6) + s->gpr[9]);
++s->steps;
kg_pc_4804d6: STEP(0x4804d6); /* and rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_4804d9: STEP(0x4804d9); /* movabs rax, 0x981040003d6b404 */
s->gpr[0] = UINT64_C(0x981040003d6b404);
++s->steps;
kg_pc_4804e3: STEP(0x4804e3); /* xor rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_4804e6: STEP(0x4804e6); /* sub rcx, rdx */
x = s->gpr[2]; y = s->gpr[3];
s->gpr[2] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_4804e9: STEP(0x4804e9); /* movabs r10, 0xe7f4caaabf5f7f00 */
s->gpr[10] = UINT64_C(0xe7f4caaabf5f7f00);
++s->steps;
kg_pc_4804f3: STEP(0x4804f3); /* lea rax, [rbx + r10] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[1] + (s->gpr[10] * UINT64_C(0x1)));
++s->steps;
kg_pc_4804f7: STEP(0x4804f7); /* mov qword ptr [rbp - 0x498], rax */
WRITE((UINT64_C(0xfffffffffffffb68) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_4804fe: STEP(0x4804fe); /* xor esi, 0x162c3a95 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x162c3a95);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480504: STEP(0x480504); /* lea rax, [rax + rsi*4] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[4] * UINT64_C(0x4)));
++s->steps;
kg_pc_480508: STEP(0x480508); /* lea r9, [rax + rcx*4] */
s->gpr[9] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x4)));
++s->steps;
kg_pc_48050c: STEP(0x48050c); /* mov eax, dword ptr [rbp - 0xd0] */
READ(a, (UINT64_C(0xffffffffffffff30) + s->gpr[6]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_480512: STEP(0x480512); /* shr eax, 0x10 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_480515: STEP(0x480515); /* movzx eax, al */
s->gpr[0] = (uint32_t)((s->gpr[0] & UINT64_C(0xff)));
++s->steps;
kg_pc_480518: STEP(0x480518); /* xor eax, 4 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x4);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48051b: STEP(0x48051b); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_48051e: STEP(0x48051e); /* and ecx, 0xffffff9c */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffff9c);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480521: STEP(0x480521); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480523: STEP(0x480523); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480525: STEP(0x480525); /* add eax, 0xa0eb8ace */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xa0eb8ace);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48052a: STEP(0x48052a); /* xor eax, 0x20c524ee */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x20c524ee);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48052f: STEP(0x48052f); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_480532: STEP(0x480532); /* and ecx, 0x5812ec */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x5812ec);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480538: STEP(0x480538); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_48053a: STEP(0x48053a); /* add ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48053c: STEP(0x48053c); /* add ecx, 0xbf3d0976 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xbf3d0976);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480542: STEP(0x480542); /* mov rax, rsi */
s->gpr[0] = s->gpr[4];
++s->steps;
kg_pc_480545: STEP(0x480545); /* add rsi, rsi */
x = s->gpr[4]; y = s->gpr[4];
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480548: STEP(0x480548); /* lea rdx, [rdi - 0x2201902] */
s->gpr[3] = (UINT64_C(0xfffffffffddfe6fe) + s->gpr[5]);
++s->steps;
kg_pc_48054f: STEP(0x48054f); /* and rdx, rsi */
x = s->gpr[3]; y = s->gpr[4];
s->gpr[3] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_480552: STEP(0x480552); /* movabs rsi, 0x248826001100c80 */
s->gpr[4] = UINT64_C(0x248826001100c80);
++s->steps;
kg_pc_48055c: STEP(0x48055c); /* xor rax, rsi */
x = s->gpr[0]; y = s->gpr[4];
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_48055f: STEP(0x48055f); /* sub rax, rdx */
x = s->gpr[0]; y = s->gpr[3];
s->gpr[0] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_480562: STEP(0x480562); /* movzx esi, r14b */
s->gpr[4] = (uint32_t)((s->gpr[14] & UINT64_C(0xff)));
++s->steps;
kg_pc_480566: STEP(0x480566); /* mov edx, dword ptr [r10 + rbx] */
READ(a, (UINT64_C(0x0) + s->gpr[10] + (s->gpr[1] * UINT64_C(0x1))), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_48056a: STEP(0x48056a); /* mov dword ptr [rbp - 0x78], edx */
WRITE((UINT64_C(0xffffffffffffff88) + s->gpr[6]), 4, (s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48056d: STEP(0x48056d); /* movabs r10, 0xd9fbeffff0a52ff0 */
s->gpr[10] = UINT64_C(0xd9fbeffff0a52ff0);
++s->steps;
kg_pc_480577: STEP(0x480577); /* lea rdx, [r9 + r10] */
s->gpr[3] = (UINT64_C(0x0) + s->gpr[9] + (s->gpr[10] * UINT64_C(0x1)));
++s->steps;
kg_pc_48057b: STEP(0x48057b); /* mov qword ptr [rbp - 0x498], rdx */
WRITE((UINT64_C(0xfffffffffffffb68) + s->gpr[6]), 8, s->gpr[3]);
++s->steps;
kg_pc_480582: STEP(0x480582); /* xor ecx, 0x3f13a7ba */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x3f13a7ba);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480588: STEP(0x480588); /* lea rdx, [rdx + rcx*4] */
s->gpr[3] = (UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x4)));
++s->steps;
kg_pc_48058c: STEP(0x48058c); /* lea rbx, [rdx + rax*4] */
s->gpr[1] = (UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x4)));
++s->steps;
kg_pc_480590: STEP(0x480590); /* mov eax, dword ptr [rbp - 0xd0] */
READ(a, (UINT64_C(0xffffffffffffff30) + s->gpr[6]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_480596: STEP(0x480596); /* movzx edx, ah */
s->gpr[3] = (uint32_t)(((s->gpr[0] >> 8) & UINT64_C(0xff)));
++s->steps;
kg_pc_480599: STEP(0x480599); /* mov edi, dword ptr [rbp - 0x320] */
READ(a, (UINT64_C(0xfffffffffffffce0) + s->gpr[6]), 4);
s->gpr[5] = (uint32_t)(a);
++s->steps;
kg_pc_48059f: STEP(0x48059f); /* rol edi, 0x10 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[5] = (uint32_t)(operation(s, OP_ROL, x, y, 32));
++s->steps;
kg_pc_4805a2: STEP(0x4805a2); /* mov eax, dword ptr [rbp - 0x9b8] */
READ(a, (UINT64_C(0xfffffffffffff648) + s->gpr[6]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_4805a8: STEP(0x4805a8); /* xor eax, dword ptr [rbp - 0x3d0] */
READ(b, (UINT64_C(0xfffffffffffffc30) + s->gpr[6]), 4);
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = b;
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4805ae: STEP(0x4805ae); /* xor eax, edi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4805b0: STEP(0x4805b0); /* mov edi, dword ptr [rbp - 0x380] */
READ(a, (UINT64_C(0xfffffffffffffc80) + s->gpr[6]), 4);
s->gpr[5] = (uint32_t)(a);
++s->steps;

break;
    case 1:
next_pc=bias+UINT64_C(0x48092b);
switch(s->pc-bias){
case UINT64_C(0x4805b6):goto kg_pc_4805b6;
case UINT64_C(0x4805b9):goto kg_pc_4805b9;
case UINT64_C(0x4805bb):goto kg_pc_4805bb;
case UINT64_C(0x4805bf):goto kg_pc_4805bf;
case UINT64_C(0x4805c2):goto kg_pc_4805c2;
case UINT64_C(0x4805c6):goto kg_pc_4805c6;
case UINT64_C(0x4805cc):goto kg_pc_4805cc;
case UINT64_C(0x4805cf):goto kg_pc_4805cf;
case UINT64_C(0x4805d2):goto kg_pc_4805d2;
case UINT64_C(0x4805dc):goto kg_pc_4805dc;
case UINT64_C(0x4805e4):goto kg_pc_4805e4;
case UINT64_C(0x4805e7):goto kg_pc_4805e7;
case UINT64_C(0x4805f1):goto kg_pc_4805f1;
case UINT64_C(0x4805f4):goto kg_pc_4805f4;
case UINT64_C(0x4805f7):goto kg_pc_4805f7;
case UINT64_C(0x4805fb):goto kg_pc_4805fb;
case UINT64_C(0x480605):goto kg_pc_480605;
case UINT64_C(0x480609):goto kg_pc_480609;
case UINT64_C(0x480610):goto kg_pc_480610;
case UINT64_C(0x480614):goto kg_pc_480614;
case UINT64_C(0x480618):goto kg_pc_480618;
case UINT64_C(0x48061c):goto kg_pc_48061c;
case UINT64_C(0x480620):goto kg_pc_480620;
case UINT64_C(0x480626):goto kg_pc_480626;
case UINT64_C(0x48062c):goto kg_pc_48062c;
case UINT64_C(0x48062f):goto kg_pc_48062f;
case UINT64_C(0x480633):goto kg_pc_480633;
case UINT64_C(0x480636):goto kg_pc_480636;
case UINT64_C(0x48063a):goto kg_pc_48063a;
case UINT64_C(0x480640):goto kg_pc_480640;
case UINT64_C(0x480643):goto kg_pc_480643;
case UINT64_C(0x480646):goto kg_pc_480646;
case UINT64_C(0x480648):goto kg_pc_480648;
case UINT64_C(0x48064a):goto kg_pc_48064a;
case UINT64_C(0x480650):goto kg_pc_480650;
case UINT64_C(0x480656):goto kg_pc_480656;
case UINT64_C(0x480659):goto kg_pc_480659;
case UINT64_C(0x48065f):goto kg_pc_48065f;
case UINT64_C(0x480661):goto kg_pc_480661;
case UINT64_C(0x480663):goto kg_pc_480663;
case UINT64_C(0x480669):goto kg_pc_480669;
case UINT64_C(0x48066c):goto kg_pc_48066c;
case UINT64_C(0x480676):goto kg_pc_480676;
case UINT64_C(0x480679):goto kg_pc_480679;
case UINT64_C(0x48067c):goto kg_pc_48067c;
case UINT64_C(0x480680):goto kg_pc_480680;
case UINT64_C(0x480683):goto kg_pc_480683;
case UINT64_C(0x48068d):goto kg_pc_48068d;
case UINT64_C(0x480691):goto kg_pc_480691;
case UINT64_C(0x480698):goto kg_pc_480698;
case UINT64_C(0x48069e):goto kg_pc_48069e;
case UINT64_C(0x4806a2):goto kg_pc_4806a2;
case UINT64_C(0x4806a6):goto kg_pc_4806a6;
case UINT64_C(0x4806ac):goto kg_pc_4806ac;
case UINT64_C(0x4806af):goto kg_pc_4806af;
case UINT64_C(0x4806b3):goto kg_pc_4806b3;
case UINT64_C(0x4806bd):goto kg_pc_4806bd;
case UINT64_C(0x4806c1):goto kg_pc_4806c1;
case UINT64_C(0x4806c8):goto kg_pc_4806c8;
case UINT64_C(0x4806cc):goto kg_pc_4806cc;
case UINT64_C(0x4806d0):goto kg_pc_4806d0;
case UINT64_C(0x4806d3):goto kg_pc_4806d3;
case UINT64_C(0x4806d9):goto kg_pc_4806d9;
case UINT64_C(0x4806dc):goto kg_pc_4806dc;
case UINT64_C(0x4806df):goto kg_pc_4806df;
case UINT64_C(0x4806e1):goto kg_pc_4806e1;
case UINT64_C(0x4806e3):goto kg_pc_4806e3;
case UINT64_C(0x4806e9):goto kg_pc_4806e9;
case UINT64_C(0x4806ef):goto kg_pc_4806ef;
case UINT64_C(0x4806f2):goto kg_pc_4806f2;
case UINT64_C(0x4806f8):goto kg_pc_4806f8;
case UINT64_C(0x4806fa):goto kg_pc_4806fa;
case UINT64_C(0x4806fc):goto kg_pc_4806fc;
case UINT64_C(0x480702):goto kg_pc_480702;
case UINT64_C(0x480705):goto kg_pc_480705;
case UINT64_C(0x480708):goto kg_pc_480708;
case UINT64_C(0x480712):goto kg_pc_480712;
case UINT64_C(0x480719):goto kg_pc_480719;
case UINT64_C(0x48071c):goto kg_pc_48071c;
case UINT64_C(0x480726):goto kg_pc_480726;
case UINT64_C(0x480729):goto kg_pc_480729;
case UINT64_C(0x48072c):goto kg_pc_48072c;
case UINT64_C(0x480732):goto kg_pc_480732;
case UINT64_C(0x480736):goto kg_pc_480736;
case UINT64_C(0x48073a):goto kg_pc_48073a;
case UINT64_C(0x48073d):goto kg_pc_48073d;
case UINT64_C(0x480740):goto kg_pc_480740;
case UINT64_C(0x480747):goto kg_pc_480747;
case UINT64_C(0x48074a):goto kg_pc_48074a;
case UINT64_C(0x480754):goto kg_pc_480754;
case UINT64_C(0x480757):goto kg_pc_480757;
case UINT64_C(0x48075a):goto kg_pc_48075a;
case UINT64_C(0x480764):goto kg_pc_480764;
case UINT64_C(0x480768):goto kg_pc_480768;
case UINT64_C(0x48076f):goto kg_pc_48076f;
case UINT64_C(0x480772):goto kg_pc_480772;
case UINT64_C(0x480775):goto kg_pc_480775;
case UINT64_C(0x480779):goto kg_pc_480779;
case UINT64_C(0x48077c):goto kg_pc_48077c;
case UINT64_C(0x48077f):goto kg_pc_48077f;
case UINT64_C(0x480783):goto kg_pc_480783;
case UINT64_C(0x480787):goto kg_pc_480787;
case UINT64_C(0x48078b):goto kg_pc_48078b;
case UINT64_C(0x480795):goto kg_pc_480795;
case UINT64_C(0x480799):goto kg_pc_480799;
case UINT64_C(0x4807a0):goto kg_pc_4807a0;
case UINT64_C(0x4807a3):goto kg_pc_4807a3;
case UINT64_C(0x4807a6):goto kg_pc_4807a6;
case UINT64_C(0x4807a8):goto kg_pc_4807a8;
case UINT64_C(0x4807aa):goto kg_pc_4807aa;
case UINT64_C(0x4807ad):goto kg_pc_4807ad;
case UINT64_C(0x4807b3):goto kg_pc_4807b3;
case UINT64_C(0x4807b5):goto kg_pc_4807b5;
case UINT64_C(0x4807b8):goto kg_pc_4807b8;
case UINT64_C(0x4807ba):goto kg_pc_4807ba;
case UINT64_C(0x4807bc):goto kg_pc_4807bc;
case UINT64_C(0x4807c0):goto kg_pc_4807c0;
case UINT64_C(0x4807c7):goto kg_pc_4807c7;
case UINT64_C(0x4807ca):goto kg_pc_4807ca;
case UINT64_C(0x4807cd):goto kg_pc_4807cd;
case UINT64_C(0x4807d3):goto kg_pc_4807d3;
case UINT64_C(0x4807d6):goto kg_pc_4807d6;
case UINT64_C(0x4807d9):goto kg_pc_4807d9;
case UINT64_C(0x4807db):goto kg_pc_4807db;
case UINT64_C(0x4807df):goto kg_pc_4807df;
case UINT64_C(0x4807e6):goto kg_pc_4807e6;
case UINT64_C(0x4807ec):goto kg_pc_4807ec;
case UINT64_C(0x4807ef):goto kg_pc_4807ef;
case UINT64_C(0x4807f5):goto kg_pc_4807f5;
case UINT64_C(0x4807fb):goto kg_pc_4807fb;
case UINT64_C(0x4807fe):goto kg_pc_4807fe;
case UINT64_C(0x480800):goto kg_pc_480800;
case UINT64_C(0x480802):goto kg_pc_480802;
case UINT64_C(0x480805):goto kg_pc_480805;
case UINT64_C(0x48080f):goto kg_pc_48080f;
case UINT64_C(0x480812):goto kg_pc_480812;
case UINT64_C(0x480815):goto kg_pc_480815;
case UINT64_C(0x480819):goto kg_pc_480819;
case UINT64_C(0x48081c):goto kg_pc_48081c;
case UINT64_C(0x480820):goto kg_pc_480820;
case UINT64_C(0x480823):goto kg_pc_480823;
case UINT64_C(0x480826):goto kg_pc_480826;
case UINT64_C(0x480830):goto kg_pc_480830;
case UINT64_C(0x480833):goto kg_pc_480833;
case UINT64_C(0x48083a):goto kg_pc_48083a;
case UINT64_C(0x48083c):goto kg_pc_48083c;
case UINT64_C(0x48083f):goto kg_pc_48083f;
case UINT64_C(0x480842):goto kg_pc_480842;
case UINT64_C(0x480845):goto kg_pc_480845;
case UINT64_C(0x48084a):goto kg_pc_48084a;
case UINT64_C(0x48084d):goto kg_pc_48084d;
case UINT64_C(0x480850):goto kg_pc_480850;
case UINT64_C(0x480852):goto kg_pc_480852;
case UINT64_C(0x480854):goto kg_pc_480854;
case UINT64_C(0x480859):goto kg_pc_480859;
case UINT64_C(0x48085e):goto kg_pc_48085e;
case UINT64_C(0x480861):goto kg_pc_480861;
case UINT64_C(0x480867):goto kg_pc_480867;
case UINT64_C(0x480869):goto kg_pc_480869;
case UINT64_C(0x48086b):goto kg_pc_48086b;
case UINT64_C(0x480870):goto kg_pc_480870;
case UINT64_C(0x480877):goto kg_pc_480877;
case UINT64_C(0x48087b):goto kg_pc_48087b;
case UINT64_C(0x480881):goto kg_pc_480881;
case UINT64_C(0x480883):goto kg_pc_480883;
case UINT64_C(0x480887):goto kg_pc_480887;
case UINT64_C(0x48088d):goto kg_pc_48088d;
case UINT64_C(0x480892):goto kg_pc_480892;
case UINT64_C(0x480899):goto kg_pc_480899;
case UINT64_C(0x48089d):goto kg_pc_48089d;
case UINT64_C(0x4808a4):goto kg_pc_4808a4;
case UINT64_C(0x4808a8):goto kg_pc_4808a8;
case UINT64_C(0x4808ab):goto kg_pc_4808ab;
case UINT64_C(0x4808ae):goto kg_pc_4808ae;
case UINT64_C(0x4808b5):goto kg_pc_4808b5;
case UINT64_C(0x4808b8):goto kg_pc_4808b8;
case UINT64_C(0x4808c2):goto kg_pc_4808c2;
case UINT64_C(0x4808c5):goto kg_pc_4808c5;
case UINT64_C(0x4808c8):goto kg_pc_4808c8;
case UINT64_C(0x4808ce):goto kg_pc_4808ce;
case UINT64_C(0x4808d2):goto kg_pc_4808d2;
case UINT64_C(0x4808d6):goto kg_pc_4808d6;
case UINT64_C(0x4808d9):goto kg_pc_4808d9;
case UINT64_C(0x4808dc):goto kg_pc_4808dc;
case UINT64_C(0x4808df):goto kg_pc_4808df;
case UINT64_C(0x4808e7):goto kg_pc_4808e7;
case UINT64_C(0x4808ea):goto kg_pc_4808ea;
case UINT64_C(0x4808f4):goto kg_pc_4808f4;
case UINT64_C(0x4808f7):goto kg_pc_4808f7;
case UINT64_C(0x4808fa):goto kg_pc_4808fa;
case UINT64_C(0x480904):goto kg_pc_480904;
case UINT64_C(0x480908):goto kg_pc_480908;
case UINT64_C(0x48090f):goto kg_pc_48090f;
case UINT64_C(0x480913):goto kg_pc_480913;
case UINT64_C(0x48091a):goto kg_pc_48091a;
case UINT64_C(0x480921):goto kg_pc_480921;
case UINT64_C(0x480924):goto kg_pc_480924;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5240: [0x4805b6,0x48092b), 197 instructions. */
kg_pc_4805b6: STEP(0x4805b6); /* rol edi, 8 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[5] = (uint32_t)(operation(s, OP_ROL, x, y, 32));
++s->steps;
kg_pc_4805b9: STEP(0x4805b9); /* xor eax, edi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4805bb: STEP(0x4805bb); /* rol r12d, 0x18 */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[12] = (uint32_t)(operation(s, OP_ROL, x, y, 32));
++s->steps;
kg_pc_4805bf: STEP(0x4805bf); /* xor eax, r12d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[12] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4805c2: STEP(0x4805c2); /* xor eax, dword ptr [r10 + r9] */
READ(b, (UINT64_C(0x0) + s->gpr[10] + (s->gpr[9] * UINT64_C(0x1))), 4);
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = b;
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4805c6: STEP(0x4805c6); /* mov dword ptr [rbp - 0xd0], eax */
WRITE((UINT64_C(0xffffffffffffff30) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4805cc: STEP(0x4805cc); /* mov rax, rcx */
s->gpr[0] = s->gpr[2];
++s->steps;
kg_pc_4805cf: STEP(0x4805cf); /* add rcx, rcx */
x = s->gpr[2]; y = s->gpr[2];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4805d2: STEP(0x4805d2); /* movabs r12, 0x10eb1ce0e */
s->gpr[12] = UINT64_C(0x10eb1ce0e);
++s->steps;
kg_pc_4805dc: STEP(0x4805dc); /* lea r9, [r12 + 0x2d4de5ec] */
s->gpr[9] = (UINT64_C(0x2d4de5ec) + s->gpr[12]);
++s->steps;
kg_pc_4805e4: STEP(0x4805e4); /* and r9, rcx */
x = s->gpr[9]; y = s->gpr[2];
s->gpr[9] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_4805e7: STEP(0x4805e7); /* movabs rcx, 0x14822a4962002602 */
s->gpr[2] = UINT64_C(0x14822a4962002602);
++s->steps;
kg_pc_4805f1: STEP(0x4805f1); /* xor rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_4805f4: STEP(0x4805f4); /* sub rax, r9 */
x = s->gpr[0]; y = s->gpr[9];
s->gpr[0] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_4805f7: STEP(0x4805f7); /* shr r8d, 0x18 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[8] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_4805fb: STEP(0x4805fb); /* movabs r10, 0xf6ddf67ffbbfce00 */
s->gpr[10] = UINT64_C(0xf6ddf67ffbbfce00);
++s->steps;
kg_pc_480605: STEP(0x480605); /* lea rcx, [rbx + r10] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[1] + (s->gpr[10] * UINT64_C(0x1)));
++s->steps;
kg_pc_480609: STEP(0x480609); /* mov qword ptr [rbp - 0x498], rcx */
WRITE((UINT64_C(0xfffffffffffffb68) + s->gpr[6]), 8, s->gpr[2]);
++s->steps;
kg_pc_480610: STEP(0x480610); /* xor r8d, 0x5d */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x5d);
s->gpr[8] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480614: STEP(0x480614); /* lea rcx, [rcx + r8*4] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[8] * UINT64_C(0x4)));
++s->steps;
kg_pc_480618: STEP(0x480618); /* lea r9, [rcx + rax*4] */
s->gpr[9] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x4)));
++s->steps;
kg_pc_48061c: STEP(0x48061c); /* rol r15d, 0x18 */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[15] = (uint32_t)(operation(s, OP_ROL, x, y, 32));
++s->steps;
kg_pc_480620: STEP(0x480620); /* mov ecx, dword ptr [rbp - 0x930] */
READ(a, (UINT64_C(0xfffffffffffff6d0) + s->gpr[6]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
kg_pc_480626: STEP(0x480626); /* xor ecx, dword ptr [rbp - 0xc0] */
READ(b, (UINT64_C(0xffffffffffffff40) + s->gpr[6]), 4);
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = b;
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48062c: STEP(0x48062c); /* xor ecx, r15d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[15] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48062f: STEP(0x48062f); /* rol r13d, 0x10 */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[13] = (uint32_t)(operation(s, OP_ROL, x, y, 32));
++s->steps;
kg_pc_480633: STEP(0x480633); /* xor ecx, r13d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[13] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480636: STEP(0x480636); /* xor ecx, dword ptr [r10 + rbx] */
READ(b, (UINT64_C(0x0) + s->gpr[10] + (s->gpr[1] * UINT64_C(0x1))), 4);
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = b;
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48063a: STEP(0x48063a); /* xor esi, 0xbe */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xbe);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480640: STEP(0x480640); /* lea ebx, [rsi + rsi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_480643: STEP(0x480643); /* and ebx, 0xffffffae */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffae);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480646: STEP(0x480646); /* neg ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = 0;
s->gpr[1] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480648: STEP(0x480648); /* add esi, ebx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48064a: STEP(0x48064a); /* add esi, 0x3ba8d7 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x3ba8d7);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480650: STEP(0x480650); /* xor esi, 0x1bf8c5 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x1bf8c5);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480656: STEP(0x480656); /* lea ebx, [rsi + rsi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_480659: STEP(0x480659); /* and ebx, 0x8cc0 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x8cc0);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48065f: STEP(0x48065f); /* neg ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = 0;
s->gpr[1] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480661: STEP(0x480661); /* add esi, ebx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480663: STEP(0x480663); /* add esi, 0x1acee660 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x1acee660);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480669: STEP(0x480669); /* mov rbx, r8 */
s->gpr[1] = s->gpr[8];
++s->steps;
kg_pc_48066c: STEP(0x48066c); /* movabs rax, 0x12445008c09c0 */
s->gpr[0] = UINT64_C(0x12445008c09c0);
++s->steps;
kg_pc_480676: STEP(0x480676); /* xor rbx, rax */
x = s->gpr[1]; y = s->gpr[0];
s->gpr[1] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_480679: STEP(0x480679); /* add r8d, r8d */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48067c: STEP(0x48067c); /* and r8d, 0x7e */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x7e);
s->gpr[8] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480680: STEP(0x480680); /* sub rbx, r8 */
x = s->gpr[1]; y = s->gpr[8];
s->gpr[1] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_480683: STEP(0x480683); /* movabs r8, 0xadf756da77ff67f8 */
s->gpr[8] = UINT64_C(0xadf756da77ff67f8);
++s->steps;
kg_pc_48068d: STEP(0x48068d); /* lea rax, [r9 + r8] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[9] + (s->gpr[8] * UINT64_C(0x1)));
++s->steps;
kg_pc_480691: STEP(0x480691); /* mov qword ptr [rbp - 0x498], rax */
WRITE((UINT64_C(0xfffffffffffffb68) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_480698: STEP(0x480698); /* xor esi, 0x1aeeb621 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x1aeeb621);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48069e: STEP(0x48069e); /* lea rax, [rax + rsi*4] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[4] * UINT64_C(0x4)));
++s->steps;
kg_pc_4806a2: STEP(0x4806a2); /* lea rax, [rax + rbx*4] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[1] * UINT64_C(0x4)));
++s->steps;
kg_pc_4806a6: STEP(0x4806a6); /* mov edi, dword ptr [rbp - 0xf8] */
READ(a, (UINT64_C(0xffffffffffffff08) + s->gpr[6]), 4);
s->gpr[5] = (uint32_t)(a);
++s->steps;
kg_pc_4806ac: STEP(0x4806ac); /* mov r10d, edi */
s->gpr[10] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4806af: STEP(0x4806af); /* mov ebx, dword ptr [r8 + r9] */
READ(a, (UINT64_C(0x0) + s->gpr[8] + (s->gpr[9] * UINT64_C(0x1))), 4);
s->gpr[1] = (uint32_t)(a);
++s->steps;
kg_pc_4806b3: STEP(0x4806b3); /* movabs rdi, 0xfffb6eebfdcfd900 */
s->gpr[5] = UINT64_C(0xfffb6eebfdcfd900);
++s->steps;
kg_pc_4806bd: STEP(0x4806bd); /* lea r8, [rax + rdi] */
s->gpr[8] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[5] * UINT64_C(0x1)));
++s->steps;
kg_pc_4806c1: STEP(0x4806c1); /* mov qword ptr [rbp - 0x498], r8 */
WRITE((UINT64_C(0xfffffffffffffb68) + s->gpr[6]), 8, s->gpr[8]);
++s->steps;
kg_pc_4806c8: STEP(0x4806c8); /* mov r9d, dword ptr [rdi + rax] */
READ(a, (UINT64_C(0x0) + s->gpr[5] + (s->gpr[0] * UINT64_C(0x1))), 4);
s->gpr[9] = (uint32_t)(a);
++s->steps;
kg_pc_4806cc: STEP(0x4806cc); /* rol r9d, 0x10 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[9] = (uint32_t)(operation(s, OP_ROL, x, y, 32));
++s->steps;
kg_pc_4806d0: STEP(0x4806d0); /* xor r9d, r11d */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = (s->gpr[11] & UINT64_C(0xffffffff));
s->gpr[9] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4806d3: STEP(0x4806d3); /* xor edx, 0xe5 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xe5);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4806d9: STEP(0x4806d9); /* lea edi, [rdx + rdx] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_4806dc: STEP(0x4806dc); /* and edi, 0x4e */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x4e);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4806df: STEP(0x4806df); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4806e1: STEP(0x4806e1); /* add edx, edi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4806e3: STEP(0x4806e3); /* add edx, 0x55552927 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x55552927);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4806e9: STEP(0x4806e9); /* xor edx, 0x875d3827 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x875d3827);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4806ef: STEP(0x4806ef); /* lea edi, [rdx + rdx] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_4806f2: STEP(0x4806f2); /* and edi, 0x80101cb0 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x80101cb0);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4806f8: STEP(0x4806f8); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4806fa: STEP(0x4806fa); /* add edx, edi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4806fc: STEP(0x4806fc); /* add edx, 0x6478ce58 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x6478ce58);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480702: STEP(0x480702); /* mov rdi, rsi */
s->gpr[5] = s->gpr[4];
++s->steps;
kg_pc_480705: STEP(0x480705); /* add rsi, rsi */
x = s->gpr[4]; y = s->gpr[4];
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480708: STEP(0x480708); /* movabs r11, 0x200000000 */
s->gpr[11] = UINT64_C(0x200000000);
++s->steps;
kg_pc_480712: STEP(0x480712); /* lea rax, [r11 - 0x5f02812] */
s->gpr[0] = (UINT64_C(0xfffffffffa0fd7ee) + s->gpr[11]);
++s->steps;
kg_pc_480719: STEP(0x480719); /* and rax, rsi */
x = s->gpr[0]; y = s->gpr[4];
s->gpr[0] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_48071c: STEP(0x48071c); /* movabs rsi, 0x168008002f81408 */
s->gpr[4] = UINT64_C(0x168008002f81408);
++s->steps;
kg_pc_480726: STEP(0x480726); /* xor rdi, rsi */
x = s->gpr[5]; y = s->gpr[4];
s->gpr[5] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_480729: STEP(0x480729); /* sub rdi, rax */
x = s->gpr[5]; y = s->gpr[0];
s->gpr[5] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_48072c: STEP(0x48072c); /* xor edx, 0xb670df52 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xb670df52);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480732: STEP(0x480732); /* lea rax, [r8 + rdx*4] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[8] + (s->gpr[3] * UINT64_C(0x4)));
++s->steps;
kg_pc_480736: STEP(0x480736); /* lea rax, [rax + rdi*4] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[5] * UINT64_C(0x4)));
++s->steps;
kg_pc_48073a: STEP(0x48073a); /* mov rsi, rdx */
s->gpr[4] = s->gpr[3];
++s->steps;
kg_pc_48073d: STEP(0x48073d); /* add rdx, rdx */
x = s->gpr[3]; y = s->gpr[3];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480740: STEP(0x480740); /* lea rdi, [r11 - 0x350192] */
s->gpr[5] = (UINT64_C(0xffffffffffcafe6e) + s->gpr[11]);
++s->steps;
kg_pc_480747: STEP(0x480747); /* and rdi, rdx */
x = s->gpr[5]; y = s->gpr[3];
s->gpr[5] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_48074a: STEP(0x48074a); /* movabs rdx, 0x16e8044001a80c8 */
s->gpr[3] = UINT64_C(0x16e8044001a80c8);
++s->steps;
kg_pc_480754: STEP(0x480754); /* xor rsi, rdx */
x = s->gpr[4]; y = s->gpr[3];
s->gpr[4] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_480757: STEP(0x480757); /* sub rsi, rdi */
x = s->gpr[4]; y = s->gpr[5];
s->gpr[4] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_48075a: STEP(0x48075a); /* movabs rdi, 0xfa5ffdfff41fafe0 */
s->gpr[5] = UINT64_C(0xfa5ffdfff41fafe0);
++s->steps;
kg_pc_480764: STEP(0x480764); /* lea rdx, [rax + rdi] */
s->gpr[3] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[5] * UINT64_C(0x1)));
++s->steps;
kg_pc_480768: STEP(0x480768); /* mov qword ptr [rbp - 0x498], rdx */
WRITE((UINT64_C(0xfffffffffffffb68) + s->gpr[6]), 8, s->gpr[3]);
++s->steps;
kg_pc_48076f: STEP(0x48076f); /* mov edi, dword ptr [rdi + rax] */
READ(a, (UINT64_C(0x0) + s->gpr[5] + (s->gpr[0] * UINT64_C(0x1))), 4);
s->gpr[5] = (uint32_t)(a);
++s->steps;
kg_pc_480772: STEP(0x480772); /* rol edi, 0x18 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[5] = (uint32_t)(operation(s, OP_ROL, x, y, 32));
++s->steps;
kg_pc_480775: STEP(0x480775); /* lea rax, [rdx + rsi*4] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x4)));
++s->steps;
kg_pc_480779: STEP(0x480779); /* xor edi, r9d */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[9] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48077c: STEP(0x48077c); /* rol ebx, 8 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[1] = (uint32_t)(operation(s, OP_ROL, x, y, 32));
++s->steps;
kg_pc_48077f: STEP(0x48077f); /* shr r10d, 0x18 */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[10] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_480783: STEP(0x480783); /* xor r10d, 0x47 */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x47);
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480787: STEP(0x480787); /* lea rdx, [rax + r10*4] */
s->gpr[3] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[10] * UINT64_C(0x4)));
++s->steps;
kg_pc_48078b: STEP(0x48078b); /* movabs rsi, 0xfa45feefff95fce0 */
s->gpr[4] = UINT64_C(0xfa45feefff95fce0);
++s->steps;
kg_pc_480795: STEP(0x480795); /* lea r15, [rdx + rsi] */
s->gpr[15] = (UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x1)));
++s->steps;
kg_pc_480799: STEP(0x480799); /* mov qword ptr [rbp - 0x498], r15 */
WRITE((UINT64_C(0xfffffffffffffb68) + s->gpr[6]), 8, s->gpr[15]);
++s->steps;
kg_pc_4807a0: STEP(0x4807a0); /* mov eax, dword ptr [rsi + rdx] */
READ(a, (UINT64_C(0x0) + s->gpr[4] + (s->gpr[3] * UINT64_C(0x1))), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_4807a3: STEP(0x4807a3); /* rol eax, 8 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[0] = (uint32_t)(operation(s, OP_ROL, x, y, 32));
++s->steps;
kg_pc_4807a6: STEP(0x4807a6); /* xor eax, edi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4807a8: STEP(0x4807a8); /* xor ebx, ecx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4807aa: STEP(0x4807aa); /* movzx ecx, bh */
s->gpr[2] = (uint32_t)(((s->gpr[1] >> 8) & UINT64_C(0xff)));
++s->steps;
kg_pc_4807ad: STEP(0x4807ad); /* xor ecx, 0xba */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xba);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4807b3: STEP(0x4807b3); /* mov edx, ecx */
s->gpr[3] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4807b5: STEP(0x4807b5); /* and edx, 0x4f */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x4f);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4807b8: STEP(0x4807b8); /* add edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4807ba: STEP(0x4807ba); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4807bc: STEP(0x4807bc); /* lea r8d, [rcx + rdx] */
s->gpr[8] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_4807c0: STEP(0x4807c0); /* add r8d, 0xae4254f */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0xae4254f);
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4807c7: STEP(0x4807c7); /* movzx edx, ah */
s->gpr[3] = (uint32_t)(((s->gpr[0] >> 8) & UINT64_C(0xff)));
++s->steps;
kg_pc_4807ca: STEP(0x4807ca); /* mov r9d, eax */
s->gpr[9] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4807cd: STEP(0x4807cd); /* xor edx, 0xcb */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xcb);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4807d3: STEP(0x4807d3); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_4807d6: STEP(0x4807d6); /* and esi, 0x1a */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x1a);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4807d9: STEP(0x4807d9); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4807db: STEP(0x4807db); /* lea r14d, [rdx + rsi] */
s->gpr[14] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_4807df: STEP(0x4807df); /* add r14d, 0x658270d */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0x658270d);
s->gpr[14] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4807e6: STEP(0x4807e6); /* mov edx, dword ptr [rbp - 0x340] */
READ(a, (UINT64_C(0xfffffffffffffcc0) + s->gpr[6]), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_4807ec: STEP(0x4807ec); /* rol edx, 0x10 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[3] = (uint32_t)(operation(s, OP_ROL, x, y, 32));
++s->steps;
kg_pc_4807ef: STEP(0x4807ef); /* xor edx, dword ptr [rbp - 0x310] */
READ(b, (UINT64_C(0xfffffffffffffcf0) + s->gpr[6]), 4);
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4807f5: STEP(0x4807f5); /* mov esi, dword ptr [rbp - 0x360] */
READ(a, (UINT64_C(0xfffffffffffffca0) + s->gpr[6]), 4);
s->gpr[4] = (uint32_t)(a);
++s->steps;
kg_pc_4807fb: STEP(0x4807fb); /* rol esi, 8 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[4] = (uint32_t)(operation(s, OP_ROL, x, y, 32));
++s->steps;
kg_pc_4807fe: STEP(0x4807fe); /* xor esi, edx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480800: STEP(0x480800); /* mov ecx, esi */
s->gpr[2] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480802: STEP(0x480802); /* mov rdx, r10 */
s->gpr[3] = s->gpr[10];
++s->steps;
kg_pc_480805: STEP(0x480805); /* movabs rsi, 0xa4b6218c0156980 */
s->gpr[4] = UINT64_C(0xa4b6218c0156980);
++s->steps;
kg_pc_48080f: STEP(0x48080f); /* xor rdx, rsi */
x = s->gpr[3]; y = s->gpr[4];
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_480812: STEP(0x480812); /* add r10d, r10d */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[10] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480815: STEP(0x480815); /* movzx edi, r10b */
s->gpr[5] = (uint32_t)((s->gpr[10] & UINT64_C(0xff)));
++s->steps;
kg_pc_480819: STEP(0x480819); /* sub rdx, rdi */
x = s->gpr[3]; y = s->gpr[5];
s->gpr[3] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_48081c: STEP(0x48081c); /* lea rax, [r15 + rdx*4] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[15] + (s->gpr[3] * UINT64_C(0x4)));
++s->steps;
kg_pc_480820: STEP(0x480820); /* mov esi, dword ptr [rbp - 0x78] */
READ(a, (UINT64_C(0xffffffffffffff88) + s->gpr[6]), 4);
s->gpr[4] = (uint32_t)(a);
++s->steps;
kg_pc_480823: STEP(0x480823); /* rol esi, 0x18 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[4] = (uint32_t)(operation(s, OP_ROL, x, y, 32));
++s->steps;
kg_pc_480826: STEP(0x480826); /* movabs rdx, 0xd6d2779cffaa5a00 */
s->gpr[3] = UINT64_C(0xd6d2779cffaa5a00);
++s->steps;
kg_pc_480830: STEP(0x480830); /* add rax, rdx */
x = s->gpr[0]; y = s->gpr[3];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480833: STEP(0x480833); /* mov qword ptr [rbp - 0x498], rax */
WRITE((UINT64_C(0xfffffffffffffb68) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_48083a: STEP(0x48083a); /* xor esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48083c: STEP(0x48083c); /* mov r15d, esi */
s->gpr[15] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48083f: STEP(0x48083f); /* mov dword ptr [rbp - 0x78], esi */
WRITE((UINT64_C(0xffffffffffffff88) + s->gpr[6]), 4, (s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480842: STEP(0x480842); /* movzx eax, bl */
s->gpr[0] = (uint32_t)((s->gpr[1] & UINT64_C(0xff)));
++s->steps;
kg_pc_480845: STEP(0x480845); /* xor eax, 0x8f */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x8f);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48084a: STEP(0x48084a); /* lea edx, [rax + rax] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_48084d: STEP(0x48084d); /* and edx, 0xffffff9a */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffff9a);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480850: STEP(0x480850); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480852: STEP(0x480852); /* add eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480854: STEP(0x480854); /* add eax, 0x8fd29cd */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x8fd29cd);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480859: STEP(0x480859); /* xor eax, 0x2fc2bdc */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x2fc2bdc);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48085e: STEP(0x48085e); /* lea edx, [rax + rax] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_480861: STEP(0x480861); /* and edx, 0x1000174e */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1000174e);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480867: STEP(0x480867); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480869: STEP(0x480869); /* add eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48086b: STEP(0x48086b); /* add eax, 0x19341ba7 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x19341ba7);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480870: STEP(0x480870); /* xor r8d, 0x55c3fcf */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x55c3fcf);
s->gpr[8] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480877: STEP(0x480877); /* lea edx, [r8 + r8] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[8] + (s->gpr[8] * UINT64_C(0x1))));
++s->steps;
kg_pc_48087b: STEP(0x48087b); /* and edx, 0x1f303a10 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1f303a10);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480881: STEP(0x480881); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480883: STEP(0x480883); /* lea ecx, [r8 + rdx] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[8] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_480887: STEP(0x480887); /* add ecx, 0x1f991d08 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x1f991d08);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48088d: STEP(0x48088d); /* xor eax, 0x13351927 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x13351927);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480892: STEP(0x480892); /* mov rdx, qword ptr [rbp - 0x990] */
READ(a, (UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_480899: STEP(0x480899); /* lea rdi, [rdx + rax*4] */
s->gpr[5] = (UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x4)));
++s->steps;
kg_pc_48089d: STEP(0x48089d); /* mov qword ptr [rbp - 0x990], rdi */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[5]);
++s->steps;
kg_pc_4808a4: STEP(0x4808a4); /* mov r8d, dword ptr [rdx + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[8] = (uint32_t)(a);
++s->steps;
kg_pc_4808a8: STEP(0x4808a8); /* mov rdx, rax */
s->gpr[3] = s->gpr[0];
++s->steps;
kg_pc_4808ab: STEP(0x4808ab); /* add rax, rax */
x = s->gpr[0]; y = s->gpr[0];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4808ae: STEP(0x4808ae); /* lea rsi, [r11 - 0x4848136] */
s->gpr[4] = (UINT64_C(0xfffffffffb7b7eca) + s->gpr[11]);
++s->steps;
kg_pc_4808b5: STEP(0x4808b5); /* and rsi, rax */
x = s->gpr[4]; y = s->gpr[0];
s->gpr[4] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_4808b8: STEP(0x4808b8); /* movabs rax, 0x308290030242409a */
s->gpr[0] = UINT64_C(0x308290030242409a);
++s->steps;
kg_pc_4808c2: STEP(0x4808c2); /* xor rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_4808c5: STEP(0x4808c5); /* sub rdx, rsi */
x = s->gpr[3]; y = s->gpr[4];
s->gpr[3] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_4808c8: STEP(0x4808c8); /* xor ecx, 0x1021075d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x1021075d);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4808ce: STEP(0x4808ce); /* lea rax, [rdi + rcx*4] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[5] + (s->gpr[2] * UINT64_C(0x4)));
++s->steps;
kg_pc_4808d2: STEP(0x4808d2); /* lea rax, [rax + rdx*4] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x4)));
++s->steps;
kg_pc_4808d6: STEP(0x4808d6); /* mov rdx, rcx */
s->gpr[3] = s->gpr[2];
++s->steps;
kg_pc_4808d9: STEP(0x4808d9); /* add rcx, rcx */
x = s->gpr[2]; y = s->gpr[2];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4808dc: STEP(0x4808dc); /* mov r10, r12 */
s->gpr[10] = s->gpr[12];
++s->steps;
kg_pc_4808df: STEP(0x4808df); /* lea rsi, [r12 + 0xce225e0] */
s->gpr[4] = (UINT64_C(0xce225e0) + s->gpr[12]);
++s->steps;
kg_pc_4808e7: STEP(0x4808e7); /* and rsi, rcx */
x = s->gpr[4]; y = s->gpr[2];
s->gpr[4] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_4808ea: STEP(0x4808ea); /* movabs rcx, 0xc10302972360608 */
s->gpr[2] = UINT64_C(0xc10302972360608);
++s->steps;
kg_pc_4808f4: STEP(0x4808f4); /* xor rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_4808f7: STEP(0x4808f7); /* sub rdx, rsi */
x = s->gpr[3]; y = s->gpr[4];
s->gpr[3] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_4808fa: STEP(0x4808fa); /* movabs rsi, 0x3df5bff3f6f6fd98 */
s->gpr[4] = UINT64_C(0x3df5bff3f6f6fd98);
++s->steps;
kg_pc_480904: STEP(0x480904); /* lea rcx, [rax + rsi] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[4] * UINT64_C(0x1)));
++s->steps;
kg_pc_480908: STEP(0x480908); /* mov qword ptr [rbp - 0x990], rcx */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[2]);
++s->steps;
kg_pc_48090f: STEP(0x48090f); /* lea rcx, [rcx + rdx*4] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x4)));
++s->steps;
kg_pc_480913: STEP(0x480913); /* mov r12d, dword ptr [rbp - 0x368] */
READ(a, (UINT64_C(0xfffffffffffffc98) + s->gpr[6]), 4);
s->gpr[12] = (uint32_t)(a);
++s->steps;
kg_pc_48091a: STEP(0x48091a); /* xor r12d, 0x41a06d0a */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x41a06d0a);
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480921: STEP(0x480921); /* mov r13d, r12d */
s->gpr[13] = (uint32_t)((s->gpr[12] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480924: STEP(0x480924); /* xor r13d, dword ptr [rbp - 0x3b8] */
READ(b, (UINT64_C(0xfffffffffffffc48) + s->gpr[6]), 4);
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = b;
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;

break;
    case 2:
next_pc=bias+UINT64_C(0x480ca6);
switch(s->pc-bias){
case UINT64_C(0x48092b):goto kg_pc_48092b;
case UINT64_C(0x48092f):goto kg_pc_48092f;
case UINT64_C(0x480932):goto kg_pc_480932;
case UINT64_C(0x480936):goto kg_pc_480936;
case UINT64_C(0x480939):goto kg_pc_480939;
case UINT64_C(0x48093c):goto kg_pc_48093c;
case UINT64_C(0x480943):goto kg_pc_480943;
case UINT64_C(0x480948):goto kg_pc_480948;
case UINT64_C(0x48094b):goto kg_pc_48094b;
case UINT64_C(0x48094e):goto kg_pc_48094e;
case UINT64_C(0x480951):goto kg_pc_480951;
case UINT64_C(0x480958):goto kg_pc_480958;
case UINT64_C(0x48095b):goto kg_pc_48095b;
case UINT64_C(0x48095e):goto kg_pc_48095e;
case UINT64_C(0x480968):goto kg_pc_480968;
case UINT64_C(0x48096b):goto kg_pc_48096b;
case UINT64_C(0x480972):goto kg_pc_480972;
case UINT64_C(0x480976):goto kg_pc_480976;
case UINT64_C(0x480979):goto kg_pc_480979;
case UINT64_C(0x48097d):goto kg_pc_48097d;
case UINT64_C(0x480984):goto kg_pc_480984;
case UINT64_C(0x48098b):goto kg_pc_48098b;
case UINT64_C(0x48098f):goto kg_pc_48098f;
case UINT64_C(0x480994):goto kg_pc_480994;
case UINT64_C(0x480996):goto kg_pc_480996;
case UINT64_C(0x480999):goto kg_pc_480999;
case UINT64_C(0x48099e):goto kg_pc_48099e;
case UINT64_C(0x4809a3):goto kg_pc_4809a3;
case UINT64_C(0x4809a7):goto kg_pc_4809a7;
case UINT64_C(0x4809ae):goto kg_pc_4809ae;
case UINT64_C(0x4809b1):goto kg_pc_4809b1;
case UINT64_C(0x4809b4):goto kg_pc_4809b4;
case UINT64_C(0x4809ba):goto kg_pc_4809ba;
case UINT64_C(0x4809bc):goto kg_pc_4809bc;
case UINT64_C(0x4809bf):goto kg_pc_4809bf;
case UINT64_C(0x4809c2):goto kg_pc_4809c2;
case UINT64_C(0x4809c8):goto kg_pc_4809c8;
case UINT64_C(0x4809cc):goto kg_pc_4809cc;
case UINT64_C(0x4809d3):goto kg_pc_4809d3;
case UINT64_C(0x4809d6):goto kg_pc_4809d6;
case UINT64_C(0x4809dc):goto kg_pc_4809dc;
case UINT64_C(0x4809e6):goto kg_pc_4809e6;
case UINT64_C(0x4809e9):goto kg_pc_4809e9;
case UINT64_C(0x4809ec):goto kg_pc_4809ec;
case UINT64_C(0x4809f0):goto kg_pc_4809f0;
case UINT64_C(0x4809f4):goto kg_pc_4809f4;
case UINT64_C(0x4809f8):goto kg_pc_4809f8;
case UINT64_C(0x4809fe):goto kg_pc_4809fe;
case UINT64_C(0x480a01):goto kg_pc_480a01;
case UINT64_C(0x480a04):goto kg_pc_480a04;
case UINT64_C(0x480a06):goto kg_pc_480a06;
case UINT64_C(0x480a08):goto kg_pc_480a08;
case UINT64_C(0x480a0e):goto kg_pc_480a0e;
case UINT64_C(0x480a14):goto kg_pc_480a14;
case UINT64_C(0x480a17):goto kg_pc_480a17;
case UINT64_C(0x480a1d):goto kg_pc_480a1d;
case UINT64_C(0x480a1f):goto kg_pc_480a1f;
case UINT64_C(0x480a21):goto kg_pc_480a21;
case UINT64_C(0x480a27):goto kg_pc_480a27;
case UINT64_C(0x480a2d):goto kg_pc_480a2d;
case UINT64_C(0x480a31):goto kg_pc_480a31;
case UINT64_C(0x480a34):goto kg_pc_480a34;
case UINT64_C(0x480a37):goto kg_pc_480a37;
case UINT64_C(0x480a41):goto kg_pc_480a41;
case UINT64_C(0x480a48):goto kg_pc_480a48;
case UINT64_C(0x480a4b):goto kg_pc_480a4b;
case UINT64_C(0x480a55):goto kg_pc_480a55;
case UINT64_C(0x480a58):goto kg_pc_480a58;
case UINT64_C(0x480a5b):goto kg_pc_480a5b;
case UINT64_C(0x480a5d):goto kg_pc_480a5d;
case UINT64_C(0x480a63):goto kg_pc_480a63;
case UINT64_C(0x480a66):goto kg_pc_480a66;
case UINT64_C(0x480a70):goto kg_pc_480a70;
case UINT64_C(0x480a74):goto kg_pc_480a74;
case UINT64_C(0x480a78):goto kg_pc_480a78;
case UINT64_C(0x480a7b):goto kg_pc_480a7b;
case UINT64_C(0x480a7f):goto kg_pc_480a7f;
case UINT64_C(0x480a86):goto kg_pc_480a86;
case UINT64_C(0x480a89):goto kg_pc_480a89;
case UINT64_C(0x480a93):goto kg_pc_480a93;
case UINT64_C(0x480a96):goto kg_pc_480a96;
case UINT64_C(0x480a98):goto kg_pc_480a98;
case UINT64_C(0x480a9b):goto kg_pc_480a9b;
case UINT64_C(0x480a9e):goto kg_pc_480a9e;
case UINT64_C(0x480aa4):goto kg_pc_480aa4;
case UINT64_C(0x480aa7):goto kg_pc_480aa7;
case UINT64_C(0x480aaa):goto kg_pc_480aaa;
case UINT64_C(0x480aad):goto kg_pc_480aad;
case UINT64_C(0x480ab3):goto kg_pc_480ab3;
case UINT64_C(0x480ab6):goto kg_pc_480ab6;
case UINT64_C(0x480ab8):goto kg_pc_480ab8;
case UINT64_C(0x480abe):goto kg_pc_480abe;
case UINT64_C(0x480ac0):goto kg_pc_480ac0;
case UINT64_C(0x480ac5):goto kg_pc_480ac5;
case UINT64_C(0x480ac8):goto kg_pc_480ac8;
case UINT64_C(0x480acb):goto kg_pc_480acb;
case UINT64_C(0x480acd):goto kg_pc_480acd;
case UINT64_C(0x480ad1):goto kg_pc_480ad1;
case UINT64_C(0x480ad8):goto kg_pc_480ad8;
case UINT64_C(0x480adb):goto kg_pc_480adb;
case UINT64_C(0x480ade):goto kg_pc_480ade;
case UINT64_C(0x480ae1):goto kg_pc_480ae1;
case UINT64_C(0x480ae4):goto kg_pc_480ae4;
case UINT64_C(0x480ae6):goto kg_pc_480ae6;
case UINT64_C(0x480aea):goto kg_pc_480aea;
case UINT64_C(0x480aee):goto kg_pc_480aee;
case UINT64_C(0x480af1):goto kg_pc_480af1;
case UINT64_C(0x480af6):goto kg_pc_480af6;
case UINT64_C(0x480afb):goto kg_pc_480afb;
case UINT64_C(0x480afe):goto kg_pc_480afe;
case UINT64_C(0x480b04):goto kg_pc_480b04;
case UINT64_C(0x480b06):goto kg_pc_480b06;
case UINT64_C(0x480b08):goto kg_pc_480b08;
case UINT64_C(0x480b0d):goto kg_pc_480b0d;
case UINT64_C(0x480b10):goto kg_pc_480b10;
case UINT64_C(0x480b16):goto kg_pc_480b16;
case UINT64_C(0x480b1d):goto kg_pc_480b1d;
case UINT64_C(0x480b22):goto kg_pc_480b22;
case UINT64_C(0x480b25):goto kg_pc_480b25;
case UINT64_C(0x480b2c):goto kg_pc_480b2c;
case UINT64_C(0x480b2f):goto kg_pc_480b2f;
case UINT64_C(0x480b35):goto kg_pc_480b35;
case UINT64_C(0x480b3c):goto kg_pc_480b3c;
case UINT64_C(0x480b41):goto kg_pc_480b41;
case UINT64_C(0x480b48):goto kg_pc_480b48;
case UINT64_C(0x480b52):goto kg_pc_480b52;
case UINT64_C(0x480b56):goto kg_pc_480b56;
case UINT64_C(0x480b59):goto kg_pc_480b59;
case UINT64_C(0x480b5f):goto kg_pc_480b5f;
case UINT64_C(0x480b66):goto kg_pc_480b66;
case UINT64_C(0x480b6b):goto kg_pc_480b6b;
case UINT64_C(0x480b6e):goto kg_pc_480b6e;
case UINT64_C(0x480b70):goto kg_pc_480b70;
case UINT64_C(0x480b73):goto kg_pc_480b73;
case UINT64_C(0x480b76):goto kg_pc_480b76;
case UINT64_C(0x480b79):goto kg_pc_480b79;
case UINT64_C(0x480b7c):goto kg_pc_480b7c;
case UINT64_C(0x480b7f):goto kg_pc_480b7f;
case UINT64_C(0x480b81):goto kg_pc_480b81;
case UINT64_C(0x480b83):goto kg_pc_480b83;
case UINT64_C(0x480b89):goto kg_pc_480b89;
case UINT64_C(0x480b8f):goto kg_pc_480b8f;
case UINT64_C(0x480b92):goto kg_pc_480b92;
case UINT64_C(0x480b98):goto kg_pc_480b98;
case UINT64_C(0x480b9a):goto kg_pc_480b9a;
case UINT64_C(0x480b9c):goto kg_pc_480b9c;
case UINT64_C(0x480ba2):goto kg_pc_480ba2;
case UINT64_C(0x480bac):goto kg_pc_480bac;
case UINT64_C(0x480bb3):goto kg_pc_480bb3;
case UINT64_C(0x480bb7):goto kg_pc_480bb7;
case UINT64_C(0x480bbe):goto kg_pc_480bbe;
case UINT64_C(0x480bc4):goto kg_pc_480bc4;
case UINT64_C(0x480bc8):goto kg_pc_480bc8;
case UINT64_C(0x480bcc):goto kg_pc_480bcc;
case UINT64_C(0x480bd3):goto kg_pc_480bd3;
case UINT64_C(0x480bd7):goto kg_pc_480bd7;
case UINT64_C(0x480bdd):goto kg_pc_480bdd;
case UINT64_C(0x480bdf):goto kg_pc_480bdf;
case UINT64_C(0x480be2):goto kg_pc_480be2;
case UINT64_C(0x480be8):goto kg_pc_480be8;
case UINT64_C(0x480beb):goto kg_pc_480beb;
case UINT64_C(0x480bee):goto kg_pc_480bee;
case UINT64_C(0x480bf8):goto kg_pc_480bf8;
case UINT64_C(0x480bff):goto kg_pc_480bff;
case UINT64_C(0x480c02):goto kg_pc_480c02;
case UINT64_C(0x480c0c):goto kg_pc_480c0c;
case UINT64_C(0x480c0f):goto kg_pc_480c0f;
case UINT64_C(0x480c12):goto kg_pc_480c12;
case UINT64_C(0x480c16):goto kg_pc_480c16;
case UINT64_C(0x480c20):goto kg_pc_480c20;
case UINT64_C(0x480c24):goto kg_pc_480c24;
case UINT64_C(0x480c2b):goto kg_pc_480c2b;
case UINT64_C(0x480c2f):goto kg_pc_480c2f;
case UINT64_C(0x480c32):goto kg_pc_480c32;
case UINT64_C(0x480c39):goto kg_pc_480c39;
case UINT64_C(0x480c3f):goto kg_pc_480c3f;
case UINT64_C(0x480c44):goto kg_pc_480c44;
case UINT64_C(0x480c4a):goto kg_pc_480c4a;
case UINT64_C(0x480c4e):goto kg_pc_480c4e;
case UINT64_C(0x480c52):goto kg_pc_480c52;
case UINT64_C(0x480c58):goto kg_pc_480c58;
case UINT64_C(0x480c5b):goto kg_pc_480c5b;
case UINT64_C(0x480c5e):goto kg_pc_480c5e;
case UINT64_C(0x480c65):goto kg_pc_480c65;
case UINT64_C(0x480c68):goto kg_pc_480c68;
case UINT64_C(0x480c72):goto kg_pc_480c72;
case UINT64_C(0x480c75):goto kg_pc_480c75;
case UINT64_C(0x480c78):goto kg_pc_480c78;
case UINT64_C(0x480c82):goto kg_pc_480c82;
case UINT64_C(0x480c86):goto kg_pc_480c86;
case UINT64_C(0x480c8d):goto kg_pc_480c8d;
case UINT64_C(0x480c91):goto kg_pc_480c91;
case UINT64_C(0x480c97):goto kg_pc_480c97;
case UINT64_C(0x480c9d):goto kg_pc_480c9d;
case UINT64_C(0x480ca0):goto kg_pc_480ca0;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5241: [0x48092b,0x480ca6), 195 instructions. */
kg_pc_48092b: STEP(0x48092b); /* mov rdi, qword ptr [rbp - 0x40] */
READ(a, (UINT64_C(0xffffffffffffffc0) + s->gpr[6]), 8);
s->gpr[5] = a;
++s->steps;
kg_pc_48092f: STEP(0x48092f); /* xor r13d, edi */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480932: STEP(0x480932); /* xor r13d, dword ptr [rsi + rax] */
READ(b, (UINT64_C(0x0) + s->gpr[4] + (s->gpr[0] * UINT64_C(0x1))), 4);
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = b;
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480936: STEP(0x480936); /* mov eax, r8d */
s->gpr[0] = (uint32_t)((s->gpr[8] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480939: STEP(0x480939); /* xor eax, 0x3a */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x3a);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48093c: STEP(0x48093c); /* xor r8d, 0x14948b00 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x14948b00);
s->gpr[8] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480943: STEP(0x480943); /* shrd r8d, eax, 8 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
z = UINT64_C(0x8);
s->gpr[8] = (uint32_t)(shift_double(s, x, y, z, 32));
++s->steps;
kg_pc_480948: STEP(0x480948); /* mov eax, r15d */
s->gpr[0] = (uint32_t)((s->gpr[15] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48094b: STEP(0x48094b); /* shr eax, 0x18 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_48094e: STEP(0x48094e); /* xor eax, 0x34 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x34);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480951: STEP(0x480951); /* mov dword ptr [rbp - 0xf8], r9d */
WRITE((UINT64_C(0xffffffffffffff08) + s->gpr[6]), 4, (s->gpr[9] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480958: STEP(0x480958); /* mov edx, r9d */
s->gpr[3] = (uint32_t)((s->gpr[9] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48095b: STEP(0x48095b); /* shr edx, 0x18 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_48095e: STEP(0x48095e); /* movabs rsi, 0xcfbf3f5a3727e7e0 */
s->gpr[4] = UINT64_C(0xcfbf3f5a3727e7e0);
++s->steps;
kg_pc_480968: STEP(0x480968); /* add rcx, rsi */
x = s->gpr[2]; y = s->gpr[4];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_48096b: STEP(0x48096b); /* mov qword ptr [rbp - 0x990], rcx */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[2]);
++s->steps;
kg_pc_480972: STEP(0x480972); /* mov r11d, dword ptr [rcx + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[11] = (uint32_t)(a);
++s->steps;
kg_pc_480976: STEP(0x480976); /* xor edx, 0x6f */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x6f);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480979: STEP(0x480979); /* lea rax, [rcx + rdx*4] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x4)));
++s->steps;
kg_pc_48097d: STEP(0x48097d); /* mov qword ptr [rbp - 0x990], rax */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_480984: STEP(0x480984); /* xor r14d, 0x249638d */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0x249638d);
s->gpr[14] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48098b: STEP(0x48098b); /* lea eax, [r14 + r14] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[14] + (s->gpr[14] * UINT64_C(0x1))));
++s->steps;
kg_pc_48098f: STEP(0x48098f); /* and eax, 0x2db88 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x2db88);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480994: STEP(0x480994); /* neg eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = 0;
s->gpr[0] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480996: STEP(0x480996); /* add eax, r14d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480999: STEP(0x480999); /* add eax, 0x22cdedc4 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x22cdedc4);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48099e: STEP(0x48099e); /* xor eax, 0x26dca9c6 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x26dca9c6);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4809a3: STEP(0x4809a3); /* lea r14, [rax + rax] */
s->gpr[14] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1)));
++s->steps;
kg_pc_4809a7: STEP(0x4809a7); /* lea rsi, [r10 + 0x608c2ff0] */
s->gpr[4] = (UINT64_C(0x608c2ff0) + s->gpr[10]);
++s->steps;
kg_pc_4809ae: STEP(0x4809ae); /* and r14, rsi */
x = s->gpr[14]; y = s->gpr[4];
s->gpr[14] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_4809b1: STEP(0x4809b1); /* mov esi, r12d */
s->gpr[4] = (uint32_t)((s->gpr[12] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4809b4: STEP(0x4809b4); /* xor esi, dword ptr [rbp - 0xd8] */
READ(b, (UINT64_C(0xffffffffffffff28) + s->gpr[6]), 4);
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = b;
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4809ba: STEP(0x4809ba); /* xor esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4809bc: STEP(0x4809bc); /* xor esi, r8d */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4809bf: STEP(0x4809bf); /* mov edx, dword ptr [rcx + rdx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x4))), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_4809c2: STEP(0x4809c2); /* mov dword ptr [rbp - 0x360], edx */
WRITE((UINT64_C(0xfffffffffffffca0) + s->gpr[6]), 4, (s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4809c8: STEP(0x4809c8); /* lea rdx, [rcx + rax*4] */
s->gpr[3] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x4)));
++s->steps;
kg_pc_4809cc: STEP(0x4809cc); /* mov qword ptr [rbp - 0x990], rdx */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[3]);
++s->steps;
kg_pc_4809d3: STEP(0x4809d3); /* xor esi, dword ptr [rcx + rax*4] */
READ(b, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x4))), 4);
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = b;
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4809d6: STEP(0x4809d6); /* mov dword ptr [rbp - 0x340], esi */
WRITE((UINT64_C(0xfffffffffffffcc0) + s->gpr[6]), 4, (s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4809dc: STEP(0x4809dc); /* movabs rcx, 0x3048940448610100 */
s->gpr[2] = UINT64_C(0x3048940448610100);
++s->steps;
kg_pc_4809e6: STEP(0x4809e6); /* xor rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_4809e9: STEP(0x4809e9); /* sub rax, r14 */
x = s->gpr[0]; y = s->gpr[14];
s->gpr[0] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_4809ec: STEP(0x4809ec); /* lea rax, [rdx + rax*4] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x4)));
++s->steps;
kg_pc_4809f0: STEP(0x4809f0); /* shr r9d, 0x10 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[9] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_4809f4: STEP(0x4809f4); /* movzx ecx, r9b */
s->gpr[2] = (uint32_t)((s->gpr[9] & UINT64_C(0xff)));
++s->steps;
kg_pc_4809f8: STEP(0x4809f8); /* xor ecx, 0xe7 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xe7);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4809fe: STEP(0x4809fe); /* lea edx, [rcx + rcx] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_480a01: STEP(0x480a01); /* and edx, 0xffffffb4 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffb4);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480a04: STEP(0x480a04); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480a06: STEP(0x480a06); /* add ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480a08: STEP(0x480a08); /* add ecx, 0x7e45bda */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x7e45bda);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480a0e: STEP(0x480a0e); /* xor ecx, 0x3445b5a */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x3445b5a);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480a14: STEP(0x480a14); /* lea edx, [rcx + rcx] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_480a17: STEP(0x480a17); /* and edx, 0x9400e5a */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x9400e5a);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480a1d: STEP(0x480a1d); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480a1f: STEP(0x480a1f); /* add ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480a21: STEP(0x480a21); /* add ecx, 0x1fe0f72d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x1fe0f72d);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480a27: STEP(0x480a27); /* xor ecx, 0x1b40f73e */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x1b40f73e);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480a2d: STEP(0x480a2d); /* lea r9, [rax + rcx*4] */
s->gpr[9] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x4)));
++s->steps;
kg_pc_480a31: STEP(0x480a31); /* mov rax, rcx */
s->gpr[0] = s->gpr[2];
++s->steps;
kg_pc_480a34: STEP(0x480a34); /* add rcx, rcx */
x = s->gpr[2]; y = s->gpr[2];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480a37: STEP(0x480a37); /* movabs rdx, 0x200000000 */
s->gpr[3] = UINT64_C(0x200000000);
++s->steps;
kg_pc_480a41: STEP(0x480a41); /* add rdx, -0x8470212 */
x = s->gpr[3]; y = UINT64_C(0xfffffffff7b8fdee);
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480a48: STEP(0x480a48); /* and rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_480a4b: STEP(0x480a4b); /* movabs rcx, 0x140110104238108 */
s->gpr[2] = UINT64_C(0x140110104238108);
++s->steps;
kg_pc_480a55: STEP(0x480a55); /* xor rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_480a58: STEP(0x480a58); /* sub rax, rdx */
x = s->gpr[0]; y = s->gpr[3];
s->gpr[0] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_480a5b: STEP(0x480a5b); /* mov ecx, ebx */
s->gpr[2] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480a5d: STEP(0x480a5d); /* mov dword ptr [rbp - 0x310], ebx */
WRITE((UINT64_C(0xfffffffffffffcf0) + s->gpr[6]), 4, (s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480a63: STEP(0x480a63); /* shr ebx, 0x18 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[1] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_480a66: STEP(0x480a66); /* movabs rsi, 0x3eddafeede7bfc00 */
s->gpr[4] = UINT64_C(0x3eddafeede7bfc00);
++s->steps;
kg_pc_480a70: STEP(0x480a70); /* lea r14, [r9 + rsi] */
s->gpr[14] = (UINT64_C(0x0) + s->gpr[9] + (s->gpr[4] * UINT64_C(0x1)));
++s->steps;
kg_pc_480a74: STEP(0x480a74); /* lea rax, [r14 + rax*4] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[14] + (s->gpr[0] * UINT64_C(0x4)));
++s->steps;
kg_pc_480a78: STEP(0x480a78); /* xor ebx, 0x2f */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x2f);
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480a7b: STEP(0x480a7b); /* lea rax, [rax + rbx*4] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[1] * UINT64_C(0x4)));
++s->steps;
kg_pc_480a7f: STEP(0x480a7f); /* mov qword ptr [rbp - 0x320], rax */
WRITE((UINT64_C(0xfffffffffffffce0) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_480a86: STEP(0x480a86); /* mov rdi, rbx */
s->gpr[5] = s->gpr[1];
++s->steps;
kg_pc_480a89: STEP(0x480a89); /* movabs rax, 0x22908070000006 */
s->gpr[0] = UINT64_C(0x22908070000006);
++s->steps;
kg_pc_480a93: STEP(0x480a93); /* xor rdi, rax */
x = s->gpr[5]; y = s->gpr[0];
s->gpr[5] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_480a96: STEP(0x480a96); /* add ebx, ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480a98: STEP(0x480a98); /* and ebx, 0xfffffff2 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffffff2);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480a9b: STEP(0x480a9b); /* sub rdi, rbx */
x = s->gpr[5]; y = s->gpr[1];
s->gpr[5] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_480a9e: STEP(0x480a9e); /* mov edx, dword ptr [rbp - 0xd0] */
READ(a, (UINT64_C(0xffffffffffffff30) + s->gpr[6]), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_480aa4: STEP(0x480aa4); /* movzx ecx, dl */
s->gpr[2] = (uint32_t)((s->gpr[3] & UINT64_C(0xff)));
++s->steps;
kg_pc_480aa7: STEP(0x480aa7); /* xor ecx, 2 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x2);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480aaa: STEP(0x480aaa); /* mov r10d, edx */
s->gpr[10] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480aad: STEP(0x480aad); /* mov dword ptr [rbp - 0x380], edx */
WRITE((UINT64_C(0xfffffffffffffc80) + s->gpr[6]), 4, (s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480ab3: STEP(0x480ab3); /* movzx eax, dh */
s->gpr[0] = (uint32_t)(((s->gpr[3] >> 8) & UINT64_C(0xff)));
++s->steps;
kg_pc_480ab6: STEP(0x480ab6); /* add edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480ab8: STEP(0x480ab8); /* and edx, 0x180 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x180);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480abe: STEP(0x480abe); /* sub ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_480ac0: STEP(0x480ac0); /* xor eax, 0xa9 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xa9);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480ac5: STEP(0x480ac5); /* lea edx, [rax + rax] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_480ac8: STEP(0x480ac8); /* and edx, 0x3c */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x3c);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480acb: STEP(0x480acb); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480acd: STEP(0x480acd); /* lea r8d, [rax + rdx] */
s->gpr[8] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_480ad1: STEP(0x480ad1); /* add r8d, 0x9aa11e */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x9aa11e);
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480ad8: STEP(0x480ad8); /* mov edx, dword ptr [rbp - 0x78] */
READ(a, (UINT64_C(0xffffffffffffff88) + s->gpr[6]), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_480adb: STEP(0x480adb); /* movzx eax, dh */
s->gpr[0] = (uint32_t)(((s->gpr[3] >> 8) & UINT64_C(0xff)));
++s->steps;
kg_pc_480ade: STEP(0x480ade); /* xor eax, 0xb */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xb);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480ae1: STEP(0x480ae1); /* mov r15d, edx */
s->gpr[15] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480ae4: STEP(0x480ae4); /* mov esi, edx */
s->gpr[4] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480ae6: STEP(0x480ae6); /* shr r15d, 7 */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = UINT64_C(0x7);
s->gpr[15] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_480aea: STEP(0x480aea); /* and r15d, 0x40 */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = UINT64_C(0x40);
s->gpr[15] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480aee: STEP(0x480aee); /* sub eax, r15d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[15] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_480af1: STEP(0x480af1); /* add eax, 0x24b6c620 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x24b6c620);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480af6: STEP(0x480af6); /* xor eax, 0x41976421 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x41976421);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480afb: STEP(0x480afb); /* lea edx, [rax + rax] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_480afe: STEP(0x480afe); /* and edx, 0x20343ae */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x20343ae);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480b04: STEP(0x480b04); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480b06: STEP(0x480b06); /* add eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480b08: STEP(0x480b08); /* add eax, 0x3cfb9d7 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x3cfb9d7);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480b0d: STEP(0x480b0d); /* mov edx, r11d */
s->gpr[3] = (uint32_t)((s->gpr[11] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480b10: STEP(0x480b10); /* xor edx, 0x8b3a */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x8b3a);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480b16: STEP(0x480b16); /* xor r11d, 0x14940000 */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = UINT64_C(0x14940000);
s->gpr[11] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480b1d: STEP(0x480b1d); /* shrd r11d, edx, 0x10 */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
z = UINT64_C(0x10);
s->gpr[11] = (uint32_t)(shift_double(s, x, y, z, 32));
++s->steps;
kg_pc_480b22: STEP(0x480b22); /* xor r11d, r13d */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = (s->gpr[13] & UINT64_C(0xffffffff));
s->gpr[11] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480b25: STEP(0x480b25); /* mov r13d, dword ptr [rbp - 0x360] */
READ(a, (UINT64_C(0xfffffffffffffca0) + s->gpr[6]), 4);
s->gpr[13] = (uint32_t)(a);
++s->steps;
kg_pc_480b2c: STEP(0x480b2c); /* mov ebx, r13d */
s->gpr[1] = (uint32_t)((s->gpr[13] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480b2f: STEP(0x480b2f); /* xor ebx, 0x8b3a */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x8b3a);
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480b35: STEP(0x480b35); /* xor r13d, 0x14940000 */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = UINT64_C(0x14940000);
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480b3c: STEP(0x480b3c); /* shrd r13d, ebx, 0x10 */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
z = UINT64_C(0x10);
s->gpr[13] = (uint32_t)(shift_double(s, x, y, z, 32));
++s->steps;
kg_pc_480b41: STEP(0x480b41); /* mov qword ptr [rbp - 0x990], r14 */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[14]);
++s->steps;
kg_pc_480b48: STEP(0x480b48); /* movabs rdx, 0x3eddafeede7bfc00 */
s->gpr[3] = UINT64_C(0x3eddafeede7bfc00);
++s->steps;
kg_pc_480b52: STEP(0x480b52); /* mov r14d, dword ptr [rdx + r9] */
READ(a, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[9] * UINT64_C(0x1))), 4);
s->gpr[14] = (uint32_t)(a);
++s->steps;
kg_pc_480b56: STEP(0x480b56); /* mov edx, r14d */
s->gpr[3] = (uint32_t)((s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480b59: STEP(0x480b59); /* xor edx, 0x948b3a */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x948b3a);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480b5f: STEP(0x480b5f); /* xor r14d, 0x14000000 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0x14000000);
s->gpr[14] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480b66: STEP(0x480b66); /* shrd r14d, edx, 0x18 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
z = UINT64_C(0x18);
s->gpr[14] = (uint32_t)(shift_double(s, x, y, z, 32));
++s->steps;
kg_pc_480b6b: STEP(0x480b6b); /* xor r14d, r11d */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = (s->gpr[11] & UINT64_C(0xffffffff));
s->gpr[14] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480b6e: STEP(0x480b6e); /* mov edx, esi */
s->gpr[3] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480b70: STEP(0x480b70); /* shr edx, 0x10 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_480b73: STEP(0x480b73); /* movzx edx, dl */
s->gpr[3] = (uint32_t)((s->gpr[3] & UINT64_C(0xff)));
++s->steps;
kg_pc_480b76: STEP(0x480b76); /* xor edx, 0x6d */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x6d);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480b79: STEP(0x480b79); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_480b7c: STEP(0x480b7c); /* and esi, 0x38 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x38);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480b7f: STEP(0x480b7f); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480b81: STEP(0x480b81); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480b83: STEP(0x480b83); /* add edx, 0x3948ec1c */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x3948ec1c);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480b89: STEP(0x480b89); /* xor edx, 0x153c6490 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x153c6490);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480b8f: STEP(0x480b8f); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_480b92: STEP(0x480b92); /* and esi, 0xa81fe4 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xa81fe4);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480b98: STEP(0x480b98); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480b9a: STEP(0x480b9a); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480b9c: STEP(0x480b9c); /* add edx, 0x15c7ff2 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x15c7ff2);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480ba2: STEP(0x480ba2); /* movabs r9, 0xfaffbbfbef71fbe0 */
s->gpr[9] = UINT64_C(0xfaffbbfbef71fbe0);
++s->steps;
kg_pc_480bac: STEP(0x480bac); /* mov rbx, qword ptr [rbp - 0x320] */
READ(a, (UINT64_C(0xfffffffffffffce0) + s->gpr[6]), 8);
s->gpr[1] = a;
++s->steps;
kg_pc_480bb3: STEP(0x480bb3); /* lea rsi, [rbx + r9] */
s->gpr[4] = (UINT64_C(0x0) + s->gpr[1] + (s->gpr[9] * UINT64_C(0x1)));
++s->steps;
kg_pc_480bb7: STEP(0x480bb7); /* mov qword ptr [rbp - 0x990], rsi */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[4]);
++s->steps;
kg_pc_480bbe: STEP(0x480bbe); /* xor edx, 0x2d28f7a2 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x2d28f7a2);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480bc4: STEP(0x480bc4); /* lea rsi, [rsi + rdx*4] */
s->gpr[4] = (UINT64_C(0x0) + s->gpr[4] + (s->gpr[3] * UINT64_C(0x4)));
++s->steps;
kg_pc_480bc8: STEP(0x480bc8); /* lea r11, [rsi + rdi*4] */
s->gpr[11] = (UINT64_C(0x0) + s->gpr[4] + (s->gpr[5] * UINT64_C(0x4)));
++s->steps;
kg_pc_480bcc: STEP(0x480bcc); /* xor r8d, 0x1ea9de */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x1ea9de);
s->gpr[8] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480bd3: STEP(0x480bd3); /* lea edi, [r8 + r8] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[8] + (s->gpr[8] * UINT64_C(0x1))));
++s->steps;
kg_pc_480bd7: STEP(0x480bd7); /* and edi, 0x188a */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x188a);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480bdd: STEP(0x480bdd); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480bdf: STEP(0x480bdf); /* add edi, r8d */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480be2: STEP(0x480be2); /* add edi, 0x3d0b8c45 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x3d0b8c45);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480be8: STEP(0x480be8); /* mov rsi, rdx */
s->gpr[4] = s->gpr[3];
++s->steps;
kg_pc_480beb: STEP(0x480beb); /* add rdx, rdx */
x = s->gpr[3]; y = s->gpr[3];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480bee: STEP(0x480bee); /* movabs r15, 0x10eb1ce0e */
s->gpr[15] = UINT64_C(0x10eb1ce0e);
++s->steps;
kg_pc_480bf8: STEP(0x480bf8); /* lea r8, [r15 + 0x6ba625ae] */
s->gpr[8] = (UINT64_C(0x6ba625ae) + s->gpr[15]);
++s->steps;
kg_pc_480bff: STEP(0x480bff); /* and r8, rdx */
x = s->gpr[8]; y = s->gpr[3];
s->gpr[8] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_480c02: STEP(0x480c02); /* movabs rdx, 0x84010c042d40621 */
s->gpr[3] = UINT64_C(0x84010c042d40621);
++s->steps;
kg_pc_480c0c: STEP(0x480c0c); /* xor rsi, rdx */
x = s->gpr[4]; y = s->gpr[3];
s->gpr[4] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_480c0f: STEP(0x480c0f); /* sub rsi, r8 */
x = s->gpr[4]; y = s->gpr[8];
s->gpr[4] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_480c12: STEP(0x480c12); /* mov r9d, dword ptr [r9 + rbx] */
READ(a, (UINT64_C(0x0) + s->gpr[9] + (s->gpr[1] * UINT64_C(0x1))), 4);
s->gpr[9] = (uint32_t)(a);
++s->steps;
kg_pc_480c16: STEP(0x480c16); /* movabs rdx, 0xff75bdfe3fffffe8 */
s->gpr[3] = UINT64_C(0xff75bdfe3fffffe8);
++s->steps;
kg_pc_480c20: STEP(0x480c20); /* lea r8, [r11 + rdx] */
s->gpr[8] = (UINT64_C(0x0) + s->gpr[11] + (s->gpr[3] * UINT64_C(0x1)));
++s->steps;
kg_pc_480c24: STEP(0x480c24); /* mov qword ptr [rbp - 0x990], r8 */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[8]);
++s->steps;
kg_pc_480c2b: STEP(0x480c2b); /* mov edx, dword ptr [rdx + r11] */
READ(a, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[11] * UINT64_C(0x1))), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_480c2f: STEP(0x480c2f); /* mov r11d, edx */
s->gpr[11] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480c32: STEP(0x480c32); /* xor r11d, 0x948b3a */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = UINT64_C(0x948b3a);
s->gpr[11] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480c39: STEP(0x480c39); /* xor edx, 0x14000000 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x14000000);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480c3f: STEP(0x480c3f); /* shrd edx, r11d, 0x18 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[11] & UINT64_C(0xffffffff));
z = UINT64_C(0x18);
s->gpr[3] = (uint32_t)(shift_double(s, x, y, z, 32));
++s->steps;
kg_pc_480c44: STEP(0x480c44); /* xor edi, 0x3d8f8447 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x3d8f8447);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480c4a: STEP(0x480c4a); /* lea rbx, [r8 + rdi*4] */
s->gpr[1] = (UINT64_C(0x0) + s->gpr[8] + (s->gpr[5] * UINT64_C(0x4)));
++s->steps;
kg_pc_480c4e: STEP(0x480c4e); /* lea r8, [rbx + rsi*4] */
s->gpr[8] = (UINT64_C(0x0) + s->gpr[1] + (s->gpr[4] * UINT64_C(0x4)));
++s->steps;
kg_pc_480c52: STEP(0x480c52); /* xor edx, dword ptr [rbp - 0x340] */
READ(b, (UINT64_C(0xfffffffffffffcc0) + s->gpr[6]), 4);
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480c58: STEP(0x480c58); /* mov rbx, rdi */
s->gpr[1] = s->gpr[5];
++s->steps;
kg_pc_480c5b: STEP(0x480c5b); /* add rdi, rdi */
x = s->gpr[5]; y = s->gpr[5];
s->gpr[5] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480c5e: STEP(0x480c5e); /* lea rsi, [r15 + 0x714499ee] */
s->gpr[4] = (UINT64_C(0x714499ee) + s->gpr[15]);
++s->steps;
kg_pc_480c65: STEP(0x480c65); /* and rsi, rdi */
x = s->gpr[4]; y = s->gpr[5];
s->gpr[4] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_480c68: STEP(0x480c68); /* movabs rdi, 0xb242044004cc01 */
s->gpr[5] = UINT64_C(0xb242044004cc01);
++s->steps;
kg_pc_480c72: STEP(0x480c72); /* xor rbx, rdi */
x = s->gpr[1]; y = s->gpr[5];
s->gpr[1] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_480c75: STEP(0x480c75); /* sub rbx, rsi */
x = s->gpr[1]; y = s->gpr[4];
s->gpr[1] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_480c78: STEP(0x480c78); /* movabs r15, 0xdeffbcfef4afe77c */
s->gpr[15] = UINT64_C(0xdeffbcfef4afe77c);
++s->steps;
kg_pc_480c82: STEP(0x480c82); /* lea rsi, [r8 + r15] */
s->gpr[4] = (UINT64_C(0x0) + s->gpr[8] + (s->gpr[15] * UINT64_C(0x1)));
++s->steps;
kg_pc_480c86: STEP(0x480c86); /* mov qword ptr [rbp - 0x990], rsi */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[4]);
++s->steps;
kg_pc_480c8d: STEP(0x480c8d); /* lea rsi, [rsi + rbx*4] */
s->gpr[4] = (UINT64_C(0x0) + s->gpr[4] + (s->gpr[1] * UINT64_C(0x4)));
++s->steps;
kg_pc_480c91: STEP(0x480c91); /* add ecx, 0x2bfdffc0 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x2bfdffc0);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480c97: STEP(0x480c97); /* xor ecx, 0x887f77e1 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x887f77e1);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480c9d: STEP(0x480c9d); /* lea edi, [rcx + rcx] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_480ca0: STEP(0x480ca0); /* and edi, 0x47098a7e */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x47098a7e);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;

break;
    case 3:
next_pc=bias+UINT64_C(0x481016);
switch(s->pc-bias){
case UINT64_C(0x480ca6):goto kg_pc_480ca6;
case UINT64_C(0x480ca8):goto kg_pc_480ca8;
case UINT64_C(0x480caa):goto kg_pc_480caa;
case UINT64_C(0x480cb0):goto kg_pc_480cb0;
case UINT64_C(0x480cb3):goto kg_pc_480cb3;
case UINT64_C(0x480cba):goto kg_pc_480cba;
case UINT64_C(0x480cbd):goto kg_pc_480cbd;
case UINT64_C(0x480cc1):goto kg_pc_480cc1;
case UINT64_C(0x480cc4):goto kg_pc_480cc4;
case UINT64_C(0x480cca):goto kg_pc_480cca;
case UINT64_C(0x480cd1):goto kg_pc_480cd1;
case UINT64_C(0x480cd6):goto kg_pc_480cd6;
case UINT64_C(0x480cdc):goto kg_pc_480cdc;
case UINT64_C(0x480ce0):goto kg_pc_480ce0;
case UINT64_C(0x480ce3):goto kg_pc_480ce3;
case UINT64_C(0x480ce6):goto kg_pc_480ce6;
case UINT64_C(0x480cf0):goto kg_pc_480cf0;
case UINT64_C(0x480cf7):goto kg_pc_480cf7;
case UINT64_C(0x480cfa):goto kg_pc_480cfa;
case UINT64_C(0x480d04):goto kg_pc_480d04;
case UINT64_C(0x480d07):goto kg_pc_480d07;
case UINT64_C(0x480d0a):goto kg_pc_480d0a;
case UINT64_C(0x480d14):goto kg_pc_480d14;
case UINT64_C(0x480d18):goto kg_pc_480d18;
case UINT64_C(0x480d1f):goto kg_pc_480d1f;
case UINT64_C(0x480d23):goto kg_pc_480d23;
case UINT64_C(0x480d29):goto kg_pc_480d29;
case UINT64_C(0x480d2c):goto kg_pc_480d2c;
case UINT64_C(0x480d30):goto kg_pc_480d30;
case UINT64_C(0x480d33):goto kg_pc_480d33;
case UINT64_C(0x480d35):goto kg_pc_480d35;
case UINT64_C(0x480d38):goto kg_pc_480d38;
case UINT64_C(0x480d3a):goto kg_pc_480d3a;
case UINT64_C(0x480d3c):goto kg_pc_480d3c;
case UINT64_C(0x480d3e):goto kg_pc_480d3e;
case UINT64_C(0x480d44):goto kg_pc_480d44;
case UINT64_C(0x480d4a):goto kg_pc_480d4a;
case UINT64_C(0x480d4d):goto kg_pc_480d4d;
case UINT64_C(0x480d53):goto kg_pc_480d53;
case UINT64_C(0x480d55):goto kg_pc_480d55;
case UINT64_C(0x480d57):goto kg_pc_480d57;
case UINT64_C(0x480d5d):goto kg_pc_480d5d;
case UINT64_C(0x480d63):goto kg_pc_480d63;
case UINT64_C(0x480d67):goto kg_pc_480d67;
case UINT64_C(0x480d6a):goto kg_pc_480d6a;
case UINT64_C(0x480d6d):goto kg_pc_480d6d;
case UINT64_C(0x480d74):goto kg_pc_480d74;
case UINT64_C(0x480d77):goto kg_pc_480d77;
case UINT64_C(0x480d81):goto kg_pc_480d81;
case UINT64_C(0x480d84):goto kg_pc_480d84;
case UINT64_C(0x480d87):goto kg_pc_480d87;
case UINT64_C(0x480d8b):goto kg_pc_480d8b;
case UINT64_C(0x480d8e):goto kg_pc_480d8e;
case UINT64_C(0x480d91):goto kg_pc_480d91;
case UINT64_C(0x480d98):goto kg_pc_480d98;
case UINT64_C(0x480d9d):goto kg_pc_480d9d;
case UINT64_C(0x480da7):goto kg_pc_480da7;
case UINT64_C(0x480dab):goto kg_pc_480dab;
case UINT64_C(0x480db2):goto kg_pc_480db2;
case UINT64_C(0x480db6):goto kg_pc_480db6;
case UINT64_C(0x480db9):goto kg_pc_480db9;
case UINT64_C(0x480dbc):goto kg_pc_480dbc;
case UINT64_C(0x480dbe):goto kg_pc_480dbe;
case UINT64_C(0x480dc4):goto kg_pc_480dc4;
case UINT64_C(0x480dca):goto kg_pc_480dca;
case UINT64_C(0x480dce):goto kg_pc_480dce;
case UINT64_C(0x480dd2):goto kg_pc_480dd2;
case UINT64_C(0x480dd6):goto kg_pc_480dd6;
case UINT64_C(0x480dda):goto kg_pc_480dda;
case UINT64_C(0x480ddd):goto kg_pc_480ddd;
case UINT64_C(0x480de7):goto kg_pc_480de7;
case UINT64_C(0x480dea):goto kg_pc_480dea;
case UINT64_C(0x480ded):goto kg_pc_480ded;
case UINT64_C(0x480df1):goto kg_pc_480df1;
case UINT64_C(0x480df4):goto kg_pc_480df4;
case UINT64_C(0x480dfe):goto kg_pc_480dfe;
case UINT64_C(0x480e02):goto kg_pc_480e02;
case UINT64_C(0x480e09):goto kg_pc_480e09;
case UINT64_C(0x480e0e):goto kg_pc_480e0e;
case UINT64_C(0x480e12):goto kg_pc_480e12;
case UINT64_C(0x480e16):goto kg_pc_480e16;
case UINT64_C(0x480e1a):goto kg_pc_480e1a;
case UINT64_C(0x480e1d):goto kg_pc_480e1d;
case UINT64_C(0x480e23):goto kg_pc_480e23;
case UINT64_C(0x480e2a):goto kg_pc_480e2a;
case UINT64_C(0x480e2f):goto kg_pc_480e2f;
case UINT64_C(0x480e32):goto kg_pc_480e32;
case UINT64_C(0x480e36):goto kg_pc_480e36;
case UINT64_C(0x480e3c):goto kg_pc_480e3c;
case UINT64_C(0x480e3e):goto kg_pc_480e3e;
case UINT64_C(0x480e41):goto kg_pc_480e41;
case UINT64_C(0x480e43):goto kg_pc_480e43;
case UINT64_C(0x480e45):goto kg_pc_480e45;
case UINT64_C(0x480e47):goto kg_pc_480e47;
case UINT64_C(0x480e4d):goto kg_pc_480e4d;
case UINT64_C(0x480e53):goto kg_pc_480e53;
case UINT64_C(0x480e56):goto kg_pc_480e56;
case UINT64_C(0x480e5c):goto kg_pc_480e5c;
case UINT64_C(0x480e5e):goto kg_pc_480e5e;
case UINT64_C(0x480e60):goto kg_pc_480e60;
case UINT64_C(0x480e66):goto kg_pc_480e66;
case UINT64_C(0x480e69):goto kg_pc_480e69;
case UINT64_C(0x480e73):goto kg_pc_480e73;
case UINT64_C(0x480e76):goto kg_pc_480e76;
case UINT64_C(0x480e78):goto kg_pc_480e78;
case UINT64_C(0x480e7d):goto kg_pc_480e7d;
case UINT64_C(0x480e80):goto kg_pc_480e80;
case UINT64_C(0x480e8a):goto kg_pc_480e8a;
case UINT64_C(0x480e8e):goto kg_pc_480e8e;
case UINT64_C(0x480e95):goto kg_pc_480e95;
case UINT64_C(0x480e9b):goto kg_pc_480e9b;
case UINT64_C(0x480e9f):goto kg_pc_480e9f;
case UINT64_C(0x480ea3):goto kg_pc_480ea3;
case UINT64_C(0x480eaa):goto kg_pc_480eaa;
case UINT64_C(0x480eae):goto kg_pc_480eae;
case UINT64_C(0x480eb1):goto kg_pc_480eb1;
case UINT64_C(0x480eb4):goto kg_pc_480eb4;
case UINT64_C(0x480eb8):goto kg_pc_480eb8;
case UINT64_C(0x480ebb):goto kg_pc_480ebb;
case UINT64_C(0x480ebe):goto kg_pc_480ebe;
case UINT64_C(0x480ec5):goto kg_pc_480ec5;
case UINT64_C(0x480ec8):goto kg_pc_480ec8;
case UINT64_C(0x480ed2):goto kg_pc_480ed2;
case UINT64_C(0x480ed5):goto kg_pc_480ed5;
case UINT64_C(0x480ed8):goto kg_pc_480ed8;
case UINT64_C(0x480ee2):goto kg_pc_480ee2;
case UINT64_C(0x480ee6):goto kg_pc_480ee6;
case UINT64_C(0x480eed):goto kg_pc_480eed;
case UINT64_C(0x480ef1):goto kg_pc_480ef1;
case UINT64_C(0x480ef7):goto kg_pc_480ef7;
case UINT64_C(0x480efa):goto kg_pc_480efa;
case UINT64_C(0x480efd):goto kg_pc_480efd;
case UINT64_C(0x480f03):goto kg_pc_480f03;
case UINT64_C(0x480f06):goto kg_pc_480f06;
case UINT64_C(0x480f09):goto kg_pc_480f09;
case UINT64_C(0x480f0b):goto kg_pc_480f0b;
case UINT64_C(0x480f0d):goto kg_pc_480f0d;
case UINT64_C(0x480f13):goto kg_pc_480f13;
case UINT64_C(0x480f19):goto kg_pc_480f19;
case UINT64_C(0x480f1c):goto kg_pc_480f1c;
case UINT64_C(0x480f22):goto kg_pc_480f22;
case UINT64_C(0x480f24):goto kg_pc_480f24;
case UINT64_C(0x480f27):goto kg_pc_480f27;
case UINT64_C(0x480f2d):goto kg_pc_480f2d;
case UINT64_C(0x480f34):goto kg_pc_480f34;
case UINT64_C(0x480f37):goto kg_pc_480f37;
case UINT64_C(0x480f3a):goto kg_pc_480f3a;
case UINT64_C(0x480f40):goto kg_pc_480f40;
case UINT64_C(0x480f42):goto kg_pc_480f42;
case UINT64_C(0x480f44):goto kg_pc_480f44;
case UINT64_C(0x480f4a):goto kg_pc_480f4a;
case UINT64_C(0x480f50):goto kg_pc_480f50;
case UINT64_C(0x480f53):goto kg_pc_480f53;
case UINT64_C(0x480f59):goto kg_pc_480f59;
case UINT64_C(0x480f5b):goto kg_pc_480f5b;
case UINT64_C(0x480f5d):goto kg_pc_480f5d;
case UINT64_C(0x480f63):goto kg_pc_480f63;
case UINT64_C(0x480f66):goto kg_pc_480f66;
case UINT64_C(0x480f6c):goto kg_pc_480f6c;
case UINT64_C(0x480f70):goto kg_pc_480f70;
case UINT64_C(0x480f7a):goto kg_pc_480f7a;
case UINT64_C(0x480f7e):goto kg_pc_480f7e;
case UINT64_C(0x480f85):goto kg_pc_480f85;
case UINT64_C(0x480f88):goto kg_pc_480f88;
case UINT64_C(0x480f8a):goto kg_pc_480f8a;
case UINT64_C(0x480f90):goto kg_pc_480f90;
case UINT64_C(0x480f96):goto kg_pc_480f96;
case UINT64_C(0x480f9a):goto kg_pc_480f9a;
case UINT64_C(0x480f9c):goto kg_pc_480f9c;
case UINT64_C(0x480f9f):goto kg_pc_480f9f;
case UINT64_C(0x480fa4):goto kg_pc_480fa4;
case UINT64_C(0x480fa8):goto kg_pc_480fa8;
case UINT64_C(0x480fab):goto kg_pc_480fab;
case UINT64_C(0x480fae):goto kg_pc_480fae;
case UINT64_C(0x480fb1):goto kg_pc_480fb1;
case UINT64_C(0x480fbb):goto kg_pc_480fbb;
case UINT64_C(0x480fc2):goto kg_pc_480fc2;
case UINT64_C(0x480fc5):goto kg_pc_480fc5;
case UINT64_C(0x480fcf):goto kg_pc_480fcf;
case UINT64_C(0x480fd2):goto kg_pc_480fd2;
case UINT64_C(0x480fd5):goto kg_pc_480fd5;
case UINT64_C(0x480fdb):goto kg_pc_480fdb;
case UINT64_C(0x480fdf):goto kg_pc_480fdf;
case UINT64_C(0x480fe3):goto kg_pc_480fe3;
case UINT64_C(0x480fed):goto kg_pc_480fed;
case UINT64_C(0x480ff1):goto kg_pc_480ff1;
case UINT64_C(0x480ff8):goto kg_pc_480ff8;
case UINT64_C(0x480ffc):goto kg_pc_480ffc;
case UINT64_C(0x480fff):goto kg_pc_480fff;
case UINT64_C(0x481002):goto kg_pc_481002;
case UINT64_C(0x481009):goto kg_pc_481009;
case UINT64_C(0x48100e):goto kg_pc_48100e;
case UINT64_C(0x481010):goto kg_pc_481010;
case UINT64_C(0x481013):goto kg_pc_481013;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5242: [0x480ca6,0x481016), 194 instructions. */
kg_pc_480ca6: STEP(0x480ca6); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480ca8: STEP(0x480ca8); /* add ecx, edi */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480caa: STEP(0x480caa); /* add ecx, 0xafc4c53f */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xafc4c53f);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480cb0: STEP(0x480cb0); /* mov r11d, r12d */
s->gpr[11] = (uint32_t)((s->gpr[12] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480cb3: STEP(0x480cb3); /* xor r11d, dword ptr [rbp - 0x120] */
READ(b, (UINT64_C(0xfffffffffffffee0) + s->gpr[6]), 4);
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = b;
s->gpr[11] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480cba: STEP(0x480cba); /* xor r11d, r13d */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = (s->gpr[13] & UINT64_C(0xffffffff));
s->gpr[11] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480cbd: STEP(0x480cbd); /* xor r11d, dword ptr [r15 + r8] */
READ(b, (UINT64_C(0x0) + s->gpr[15] + (s->gpr[8] * UINT64_C(0x1))), 4);
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = b;
s->gpr[11] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480cc1: STEP(0x480cc1); /* mov edi, r9d */
s->gpr[5] = (uint32_t)((s->gpr[9] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480cc4: STEP(0x480cc4); /* xor edi, 0x8b3a */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x8b3a);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480cca: STEP(0x480cca); /* xor r9d, 0x14940000 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x14940000);
s->gpr[9] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480cd1: STEP(0x480cd1); /* shrd r9d, edi, 0x10 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
z = UINT64_C(0x10);
s->gpr[9] = (uint32_t)(shift_double(s, x, y, z, 32));
++s->steps;
kg_pc_480cd6: STEP(0x480cd6); /* xor ecx, 0xc464d3d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xc464d3d);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480cdc: STEP(0x480cdc); /* lea r8, [rsi + rcx*4] */
s->gpr[8] = (UINT64_C(0x0) + s->gpr[4] + (s->gpr[2] * UINT64_C(0x4)));
++s->steps;
kg_pc_480ce0: STEP(0x480ce0); /* mov rdi, rcx */
s->gpr[5] = s->gpr[2];
++s->steps;
kg_pc_480ce3: STEP(0x480ce3); /* add rcx, rcx */
x = s->gpr[2]; y = s->gpr[2];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480ce6: STEP(0x480ce6); /* movabs r13, 0x200000000 */
s->gpr[13] = UINT64_C(0x200000000);
++s->steps;
kg_pc_480cf0: STEP(0x480cf0); /* lea rbx, [r13 - 0x43408a] */
s->gpr[1] = (UINT64_C(0xffffffffffbcbf76) + s->gpr[13]);
++s->steps;
kg_pc_480cf7: STEP(0x480cf7); /* and rbx, rcx */
x = s->gpr[1]; y = s->gpr[2];
s->gpr[1] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_480cfa: STEP(0x480cfa); /* movabs rcx, 0x1813a520021a044 */
s->gpr[2] = UINT64_C(0x1813a520021a044);
++s->steps;
kg_pc_480d04: STEP(0x480d04); /* xor rdi, rcx */
x = s->gpr[5]; y = s->gpr[2];
s->gpr[5] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_480d07: STEP(0x480d07); /* sub rdi, rbx */
x = s->gpr[5]; y = s->gpr[1];
s->gpr[5] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_480d0a: STEP(0x480d0a); /* movabs r15, 0xfd36f7eeffeccffc */
s->gpr[15] = UINT64_C(0xfd36f7eeffeccffc);
++s->steps;
kg_pc_480d14: STEP(0x480d14); /* lea rcx, [r8 + r15] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[8] + (s->gpr[15] * UINT64_C(0x1)));
++s->steps;
kg_pc_480d18: STEP(0x480d18); /* mov qword ptr [rbp - 0x990], rcx */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[2]);
++s->steps;
kg_pc_480d1f: STEP(0x480d1f); /* lea rcx, [rcx + rdi*4] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[5] * UINT64_C(0x4)));
++s->steps;
kg_pc_480d23: STEP(0x480d23); /* mov esi, dword ptr [rbp - 0x380] */
READ(a, (UINT64_C(0xfffffffffffffc80) + s->gpr[6]), 4);
s->gpr[4] = (uint32_t)(a);
++s->steps;
kg_pc_480d29: STEP(0x480d29); /* shr esi, 0x10 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[4] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_480d2c: STEP(0x480d2c); /* movzx ebx, sil */
s->gpr[1] = (uint32_t)((s->gpr[4] & UINT64_C(0xff)));
++s->steps;
kg_pc_480d30: STEP(0x480d30); /* xor ebx, 0x37 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x37);
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480d33: STEP(0x480d33); /* mov edi, ebx */
s->gpr[5] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480d35: STEP(0x480d35); /* and edi, 0x55 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x55);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480d38: STEP(0x480d38); /* add edi, edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480d3a: STEP(0x480d3a); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480d3c: STEP(0x480d3c); /* add edi, ebx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480d3e: STEP(0x480d3e); /* add edi, 0xc4fbd955 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xc4fbd955);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480d44: STEP(0x480d44); /* xor edi, 0x23e1c9d0 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x23e1c9d0);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480d4a: STEP(0x480d4a); /* lea ebx, [rdi + rdi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_480d4d: STEP(0x480d4d); /* and ebx, 0x40103d90 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x40103d90);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480d53: STEP(0x480d53); /* neg ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = 0;
s->gpr[1] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480d55: STEP(0x480d55); /* add edi, ebx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480d57: STEP(0x480d57); /* add edi, 0x204d1ec8 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x204d1ec8);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480d5d: STEP(0x480d5d); /* xor edi, 0xc7570eea */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xc7570eea);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480d63: STEP(0x480d63); /* lea rbx, [rcx + rdi*4] */
s->gpr[1] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[5] * UINT64_C(0x4)));
++s->steps;
kg_pc_480d67: STEP(0x480d67); /* mov rcx, rdi */
s->gpr[2] = s->gpr[5];
++s->steps;
kg_pc_480d6a: STEP(0x480d6a); /* add rdi, rdi */
x = s->gpr[5]; y = s->gpr[5];
s->gpr[5] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480d6d: STEP(0x480d6d); /* lea rsi, [r13 - 0x40c4118c] */
s->gpr[4] = (UINT64_C(0xffffffffbf3bee74) + s->gpr[13]);
++s->steps;
kg_pc_480d74: STEP(0x480d74); /* and rsi, rdi */
x = s->gpr[4]; y = s->gpr[5];
s->gpr[4] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_480d77: STEP(0x480d77); /* movabs rdi, 0x4438868206208c5 */
s->gpr[5] = UINT64_C(0x4438868206208c5);
++s->steps;
kg_pc_480d81: STEP(0x480d81); /* xor rcx, rdi */
x = s->gpr[2]; y = s->gpr[5];
s->gpr[2] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_480d84: STEP(0x480d84); /* sub rcx, rsi */
x = s->gpr[2]; y = s->gpr[4];
s->gpr[2] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_480d87: STEP(0x480d87); /* mov r8d, dword ptr [r15 + r8] */
READ(a, (UINT64_C(0x0) + s->gpr[15] + (s->gpr[8] * UINT64_C(0x1))), 4);
s->gpr[8] = (uint32_t)(a);
++s->steps;
kg_pc_480d8b: STEP(0x480d8b); /* mov esi, r8d */
s->gpr[4] = (uint32_t)((s->gpr[8] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480d8e: STEP(0x480d8e); /* xor esi, 0x3a */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x3a);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480d91: STEP(0x480d91); /* xor r8d, 0x14948b00 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x14948b00);
s->gpr[8] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480d98: STEP(0x480d98); /* shrd r8d, esi, 8 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
z = UINT64_C(0x8);
s->gpr[8] = (uint32_t)(shift_double(s, x, y, z, 32));
++s->steps;
kg_pc_480d9d: STEP(0x480d9d); /* movabs rdi, 0xf9fb16b7ff797ef0 */
s->gpr[5] = UINT64_C(0xf9fb16b7ff797ef0);
++s->steps;
kg_pc_480da7: STEP(0x480da7); /* lea rsi, [rbx + rdi] */
s->gpr[4] = (UINT64_C(0x0) + s->gpr[1] + (s->gpr[5] * UINT64_C(0x1)));
++s->steps;
kg_pc_480dab: STEP(0x480dab); /* mov qword ptr [rbp - 0x990], rsi */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[4]);
++s->steps;
kg_pc_480db2: STEP(0x480db2); /* lea rcx, [rsi + rcx*4] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[4] + (s->gpr[2] * UINT64_C(0x4)));
++s->steps;
kg_pc_480db6: STEP(0x480db6); /* xor r8d, r14d */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
s->gpr[8] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480db9: STEP(0x480db9); /* mov ebx, dword ptr [rdi + rbx] */
READ(a, (UINT64_C(0x0) + s->gpr[5] + (s->gpr[1] * UINT64_C(0x1))), 4);
s->gpr[1] = (uint32_t)(a);
++s->steps;
kg_pc_480dbc: STEP(0x480dbc); /* mov esi, ebx */
s->gpr[4] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480dbe: STEP(0x480dbe); /* xor esi, 0x948b3a */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x948b3a);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480dc4: STEP(0x480dc4); /* xor ebx, 0x14000000 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x14000000);
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480dca: STEP(0x480dca); /* shrd ebx, esi, 0x18 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
z = UINT64_C(0x18);
s->gpr[1] = (uint32_t)(shift_double(s, x, y, z, 32));
++s->steps;
kg_pc_480dce: STEP(0x480dce); /* shr r10d, 0x18 */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[10] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_480dd2: STEP(0x480dd2); /* xor r10d, 0x36 */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x36);
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480dd6: STEP(0x480dd6); /* lea rsi, [rcx + r10*4] */
s->gpr[4] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[10] * UINT64_C(0x4)));
++s->steps;
kg_pc_480dda: STEP(0x480dda); /* mov rcx, r10 */
s->gpr[2] = s->gpr[10];
++s->steps;
kg_pc_480ddd: STEP(0x480ddd); /* movabs rdi, 0x485200e624462d4 */
s->gpr[5] = UINT64_C(0x485200e624462d4);
++s->steps;
kg_pc_480de7: STEP(0x480de7); /* xor rcx, rdi */
x = s->gpr[2]; y = s->gpr[5];
s->gpr[2] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_480dea: STEP(0x480dea); /* add r10d, r10d */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[10] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480ded: STEP(0x480ded); /* and r10d, 0x56 */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x56);
s->gpr[10] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480df1: STEP(0x480df1); /* sub rcx, r10 */
x = s->gpr[2]; y = s->gpr[10];
s->gpr[2] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_480df4: STEP(0x480df4); /* movabs r10, 0xeef1de5f7e77dcec */
s->gpr[10] = UINT64_C(0xeef1de5f7e77dcec);
++s->steps;
kg_pc_480dfe: STEP(0x480dfe); /* lea rdi, [rsi + r10] */
s->gpr[5] = (UINT64_C(0x0) + s->gpr[4] + (s->gpr[10] * UINT64_C(0x1)));
++s->steps;
kg_pc_480e02: STEP(0x480e02); /* mov qword ptr [rbp - 0x990], rdi */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[5]);
++s->steps;
kg_pc_480e09: STEP(0x480e09); /* xor eax, 0x66ee1bcf */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x66ee1bcf);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480e0e: STEP(0x480e0e); /* lea rdi, [rdi + rax*4] */
s->gpr[5] = (UINT64_C(0x0) + s->gpr[5] + (s->gpr[0] * UINT64_C(0x4)));
++s->steps;
kg_pc_480e12: STEP(0x480e12); /* lea rcx, [rdi + rcx*4] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[5] + (s->gpr[2] * UINT64_C(0x4)));
++s->steps;
kg_pc_480e16: STEP(0x480e16); /* mov r15d, dword ptr [r10 + rsi] */
READ(a, (UINT64_C(0x0) + s->gpr[10] + (s->gpr[4] * UINT64_C(0x1))), 4);
s->gpr[15] = (uint32_t)(a);
++s->steps;
kg_pc_480e1a: STEP(0x480e1a); /* mov esi, r15d */
s->gpr[4] = (uint32_t)((s->gpr[15] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480e1d: STEP(0x480e1d); /* xor esi, 0x8b3a */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x8b3a);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480e23: STEP(0x480e23); /* xor r15d, 0x14940000 */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = UINT64_C(0x14940000);
s->gpr[15] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480e2a: STEP(0x480e2a); /* shrd r15d, esi, 0x10 */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
z = UINT64_C(0x10);
s->gpr[15] = (uint32_t)(shift_double(s, x, y, z, 32));
++s->steps;
kg_pc_480e2f: STEP(0x480e2f); /* xor r15d, edx */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[15] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480e32: STEP(0x480e32); /* movzx edx, byte ptr [rbp - 0x78] */
READ(a, (UINT64_C(0xffffffffffffff88) + s->gpr[6]), 1);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_480e36: STEP(0x480e36); /* xor edx, 0xaa */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xaa);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480e3c: STEP(0x480e3c); /* mov esi, edx */
s->gpr[4] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480e3e: STEP(0x480e3e); /* and esi, 0x47 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x47);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480e41: STEP(0x480e41); /* add esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480e43: STEP(0x480e43); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480e45: STEP(0x480e45); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480e47: STEP(0x480e47); /* add edx, 0x8b4e9147 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x8b4e9147);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480e4d: STEP(0x480e4d); /* xor edx, 0x543a251 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x543a251);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480e53: STEP(0x480e53); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_480e56: STEP(0x480e56); /* and esi, 0x100879b6 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x100879b6);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480e5c: STEP(0x480e5c); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480e5e: STEP(0x480e5e); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480e60: STEP(0x480e60); /* add edx, 0xb964fcdb */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xb964fcdb);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480e66: STEP(0x480e66); /* mov rsi, rax */
s->gpr[4] = s->gpr[0];
++s->steps;
kg_pc_480e69: STEP(0x480e69); /* movabs rdi, 0x14c9c00cfc0b0a56 */
s->gpr[5] = UINT64_C(0x14c9c00cfc0b0a56);
++s->steps;
kg_pc_480e73: STEP(0x480e73); /* xor rsi, rdi */
x = s->gpr[4]; y = s->gpr[5];
s->gpr[4] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_480e76: STEP(0x480e76); /* add eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480e78: STEP(0x480e78); /* and eax, 0x7e9eb52 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x7e9eb52);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480e7d: STEP(0x480e7d); /* sub rsi, rax */
x = s->gpr[4]; y = s->gpr[0];
s->gpr[4] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_480e80: STEP(0x480e80); /* movabs rdi, 0xedeb7fc676ee74b0 */
s->gpr[5] = UINT64_C(0xedeb7fc676ee74b0);
++s->steps;
kg_pc_480e8a: STEP(0x480e8a); /* lea rax, [rcx + rdi] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[5] * UINT64_C(0x1)));
++s->steps;
kg_pc_480e8e: STEP(0x480e8e); /* mov qword ptr [rbp - 0x990], rax */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_480e95: STEP(0x480e95); /* xor edx, 0x3769cffb */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x3769cffb);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480e9b: STEP(0x480e9b); /* lea rax, [rax + rdx*4] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x4)));
++s->steps;
kg_pc_480e9f: STEP(0x480e9f); /* lea rax, [rax + rsi*4] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[4] * UINT64_C(0x4)));
++s->steps;
kg_pc_480ea3: STEP(0x480ea3); /* xor r12d, dword ptr [rbp - 0x3b0] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xfffffffffffffc50) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0xffffffffffffffc0) + s->gpr[6]);
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, (s->gpr[12] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x480eae);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xfffffffffffffc50) + s->gpr[6]), 4);
x=(s->gpr[12] & UINT64_C(0xffffffff));y=b;
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480eaa: STEP(0x480eaa); /* xor r12d, dword ptr [rbp - 0x40] */
READ(b, (UINT64_C(0xffffffffffffffc0) + s->gpr[6]), 4);
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = b;
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480eae: STEP(0x480eae); /* xor r12d, r9d */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[9] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480eb1: STEP(0x480eb1); /* xor r12d, ebx */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480eb4: STEP(0x480eb4); /* xor r12d, dword ptr [rdi + rcx] */
READ(b, (UINT64_C(0x0) + s->gpr[5] + (s->gpr[2] * UINT64_C(0x1))), 4);
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = b;
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480eb8: STEP(0x480eb8); /* mov rcx, rdx */
s->gpr[2] = s->gpr[3];
++s->steps;
kg_pc_480ebb: STEP(0x480ebb); /* add rdx, rdx */
x = s->gpr[3]; y = s->gpr[3];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480ebe: STEP(0x480ebe); /* lea rsi, [r13 - 0x1dcf04c2] */
s->gpr[4] = (UINT64_C(0xffffffffe230fb3e) + s->gpr[13]);
++s->steps;
kg_pc_480ec5: STEP(0x480ec5); /* and rsi, rdx */
x = s->gpr[4]; y = s->gpr[3];
s->gpr[4] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_480ec8: STEP(0x480ec8); /* movabs rdx, 0x191b10020ee78260 */
s->gpr[3] = UINT64_C(0x191b10020ee78260);
++s->steps;
kg_pc_480ed2: STEP(0x480ed2); /* xor rcx, rdx */
x = s->gpr[2]; y = s->gpr[3];
s->gpr[2] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_480ed5: STEP(0x480ed5); /* sub rcx, rsi */
x = s->gpr[2]; y = s->gpr[4];
s->gpr[2] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_480ed8: STEP(0x480ed8); /* movabs rdi, 0xacd8ffcc0fd3d6a8 */
s->gpr[5] = UINT64_C(0xacd8ffcc0fd3d6a8);
++s->steps;
kg_pc_480ee2: STEP(0x480ee2); /* lea rdx, [rax + rdi] */
s->gpr[3] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[5] * UINT64_C(0x1)));
++s->steps;
kg_pc_480ee6: STEP(0x480ee6); /* mov qword ptr [rbp - 0x990], rdx */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[3]);
++s->steps;
kg_pc_480eed: STEP(0x480eed); /* lea rcx, [rdx + rcx*4] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x4)));
++s->steps;
kg_pc_480ef1: STEP(0x480ef1); /* mov edx, dword ptr [rbp - 0x310] */
READ(a, (UINT64_C(0xfffffffffffffcf0) + s->gpr[6]), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_480ef7: STEP(0x480ef7); /* shr edx, 0x10 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_480efa: STEP(0x480efa); /* movzx edx, dl */
s->gpr[3] = (uint32_t)((s->gpr[3] & UINT64_C(0xff)));
++s->steps;
kg_pc_480efd: STEP(0x480efd); /* xor edx, 0xdb */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xdb);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480f03: STEP(0x480f03); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_480f06: STEP(0x480f06); /* and esi, 0x4e */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x4e);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480f09: STEP(0x480f09); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480f0b: STEP(0x480f0b); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480f0d: STEP(0x480f0d); /* add edx, 0x878ffa27 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x878ffa27);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480f13: STEP(0x480f13); /* xor edx, 0x2dbdba16 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x2dbdba16);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480f19: STEP(0x480f19); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_480f1c: STEP(0x480f1c); /* and esi, 0x402d4 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x402d4);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480f22: STEP(0x480f22); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480f24: STEP(0x480f24); /* lea ebx, [rdx + rsi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_480f27: STEP(0x480f27); /* add ebx, 0xd44b896a */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0xd44b896a);
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480f2d: STEP(0x480f2d); /* movzx edx, byte ptr [rbp - 0xf8] */
READ(a, (UINT64_C(0xffffffffffffff08) + s->gpr[6]), 1);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_480f34: STEP(0x480f34); /* xor edx, 0x7c */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x7c);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480f37: STEP(0x480f37); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_480f3a: STEP(0x480f3a); /* and esi, 0x160 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x160);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480f40: STEP(0x480f40); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480f42: STEP(0x480f42); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480f44: STEP(0x480f44); /* add edx, 0x6e1a4eb0 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x6e1a4eb0);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480f4a: STEP(0x480f4a); /* xor edx, 0x2e18de2d */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x2e18de2d);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480f50: STEP(0x480f50); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_480f53: STEP(0x480f53); /* and esi, 0x80010404 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x80010404);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_480f59: STEP(0x480f59); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_480f5b: STEP(0x480f5b); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480f5d: STEP(0x480f5d); /* add edx, 0x6dd0ce02 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x6dd0ce02);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_480f63: STEP(0x480f63); /* mov eax, dword ptr [rdi + rax] */
READ(a, (UINT64_C(0x0) + s->gpr[5] + (s->gpr[0] * UINT64_C(0x1))), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_480f66: STEP(0x480f66); /* xor ebx, 0x7e79c9ec */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x7e79c9ec);
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480f6c: STEP(0x480f6c); /* lea rcx, [rcx + rbx*4] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[1] * UINT64_C(0x4)));
++s->steps;
kg_pc_480f70: STEP(0x480f70); /* movabs rsi, 0x9b93bff7c461f680 */
s->gpr[4] = UINT64_C(0x9b93bff7c461f680);
++s->steps;
kg_pc_480f7a: STEP(0x480f7a); /* lea r9, [rcx + rsi] */
s->gpr[9] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[4] * UINT64_C(0x1)));
++s->steps;
kg_pc_480f7e: STEP(0x480f7e); /* mov qword ptr [rbp - 0x990], r9 */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[9]);
++s->steps;
kg_pc_480f85: STEP(0x480f85); /* mov esi, dword ptr [rsi + rcx] */
READ(a, (UINT64_C(0x0) + s->gpr[4] + (s->gpr[2] * UINT64_C(0x1))), 4);
s->gpr[4] = (uint32_t)(a);
++s->steps;
kg_pc_480f88: STEP(0x480f88); /* mov ecx, esi */
s->gpr[2] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480f8a: STEP(0x480f8a); /* xor ecx, 0x948b3a */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x948b3a);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480f90: STEP(0x480f90); /* xor esi, 0x14000000 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x14000000);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480f96: STEP(0x480f96); /* shrd esi, ecx, 0x18 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
z = UINT64_C(0x18);
s->gpr[4] = (uint32_t)(shift_double(s, x, y, z, 32));
++s->steps;
kg_pc_480f9a: STEP(0x480f9a); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480f9c: STEP(0x480f9c); /* xor ecx, 0x3a */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x3a);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480f9f: STEP(0x480f9f); /* xor eax, 0x14948b00 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x14948b00);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480fa4: STEP(0x480fa4); /* shrd eax, ecx, 8 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
z = UINT64_C(0x8);
s->gpr[0] = (uint32_t)(shift_double(s, x, y, z, 32));
++s->steps;
kg_pc_480fa8: STEP(0x480fa8); /* xor eax, r11d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[11] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480fab: STEP(0x480fab); /* mov rcx, rbx */
s->gpr[2] = s->gpr[1];
++s->steps;
kg_pc_480fae: STEP(0x480fae); /* add rbx, rbx */
x = s->gpr[1]; y = s->gpr[1];
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480fb1: STEP(0x480fb1); /* movabs rdi, 0x10eb1ce0e */
s->gpr[5] = UINT64_C(0x10eb1ce0e);
++s->steps;
kg_pc_480fbb: STEP(0x480fbb); /* add rdi, 0x1d0b21e0 */
x = s->gpr[5]; y = UINT64_C(0x1d0b21e0);
s->gpr[5] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_480fc2: STEP(0x480fc2); /* and rdi, rbx */
x = s->gpr[5]; y = s->gpr[1];
s->gpr[5] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_480fc5: STEP(0x480fc5); /* movabs rbx, 0x50051126a218808 */
s->gpr[1] = UINT64_C(0x50051126a218808);
++s->steps;
kg_pc_480fcf: STEP(0x480fcf); /* xor rcx, rbx */
x = s->gpr[2]; y = s->gpr[1];
s->gpr[2] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_480fd2: STEP(0x480fd2); /* sub rcx, rdi */
x = s->gpr[2]; y = s->gpr[5];
s->gpr[2] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_480fd5: STEP(0x480fd5); /* xor edx, 0x2dd25e60 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x2dd25e60);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_480fdb: STEP(0x480fdb); /* lea rdi, [r9 + rdx*4] */
s->gpr[5] = (UINT64_C(0x0) + s->gpr[9] + (s->gpr[3] * UINT64_C(0x4)));
++s->steps;
kg_pc_480fdf: STEP(0x480fdf); /* lea rcx, [rdi + rcx*4] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[5] + (s->gpr[2] * UINT64_C(0x4)));
++s->steps;
kg_pc_480fe3: STEP(0x480fe3); /* movabs rbx, 0xebfebbb65779dfe0 */
s->gpr[1] = UINT64_C(0xebfebbb65779dfe0);
++s->steps;
kg_pc_480fed: STEP(0x480fed); /* lea rdi, [rcx + rbx] */
s->gpr[5] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[1] * UINT64_C(0x1)));
++s->steps;
kg_pc_480ff1: STEP(0x480ff1); /* mov qword ptr [rbp - 0x990], rdi */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[5]);
++s->steps;
kg_pc_480ff8: STEP(0x480ff8); /* mov r14d, dword ptr [rbx + rcx] */
READ(a, (UINT64_C(0x0) + s->gpr[1] + (s->gpr[2] * UINT64_C(0x1))), 4);
s->gpr[14] = (uint32_t)(a);
++s->steps;
kg_pc_480ffc: STEP(0x480ffc); /* mov ecx, r14d */
s->gpr[2] = (uint32_t)((s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_480fff: STEP(0x480fff); /* xor ecx, 0x3a */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x3a);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481002: STEP(0x481002); /* xor r14d, 0x14948b00 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0x14948b00);
s->gpr[14] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481009: STEP(0x481009); /* shrd r14d, ecx, 8 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
z = UINT64_C(0x8);
s->gpr[14] = (uint32_t)(shift_double(s, x, y, z, 32));
++s->steps;
kg_pc_48100e: STEP(0x48100e); /* xor eax, esi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481010: STEP(0x481010); /* xor r14d, r12d */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = (s->gpr[12] & UINT64_C(0xffffffff));
s->gpr[14] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481013: STEP(0x481013); /* mov rcx, rdx */
s->gpr[2] = s->gpr[3];
++s->steps;

break;
    case 4:
next_pc=bias+UINT64_C(0x481343);
switch(s->pc-bias){
case UINT64_C(0x481016):goto kg_pc_481016;
case UINT64_C(0x481019):goto kg_pc_481019;
case UINT64_C(0x481020):goto kg_pc_481020;
case UINT64_C(0x481023):goto kg_pc_481023;
case UINT64_C(0x48102d):goto kg_pc_48102d;
case UINT64_C(0x481030):goto kg_pc_481030;
case UINT64_C(0x481033):goto kg_pc_481033;
case UINT64_C(0x481037):goto kg_pc_481037;
case UINT64_C(0x481041):goto kg_pc_481041;
case UINT64_C(0x481044):goto kg_pc_481044;
case UINT64_C(0x48104e):goto kg_pc_48104e;
case UINT64_C(0x481054):goto kg_pc_481054;
case UINT64_C(0x481056):goto kg_pc_481056;
case UINT64_C(0x48105c):goto kg_pc_48105c;
case UINT64_C(0x48105f):goto kg_pc_48105f;
case UINT64_C(0x481066):goto kg_pc_481066;
case UINT64_C(0x481069):goto kg_pc_481069;
case UINT64_C(0x48106f):goto kg_pc_48106f;
case UINT64_C(0x481072):goto kg_pc_481072;
case UINT64_C(0x481075):goto kg_pc_481075;
case UINT64_C(0x481078):goto kg_pc_481078;
case UINT64_C(0x48107a):goto kg_pc_48107a;
case UINT64_C(0x48107e):goto kg_pc_48107e;
case UINT64_C(0x481082):goto kg_pc_481082;
case UINT64_C(0x481086):goto kg_pc_481086;
case UINT64_C(0x48108a):goto kg_pc_48108a;
case UINT64_C(0x48108e):goto kg_pc_48108e;
case UINT64_C(0x481090):goto kg_pc_481090;
case UINT64_C(0x481092):goto kg_pc_481092;
case UINT64_C(0x481095):goto kg_pc_481095;
case UINT64_C(0x48109b):goto kg_pc_48109b;
case UINT64_C(0x48109e):goto kg_pc_48109e;
case UINT64_C(0x4810a4):goto kg_pc_4810a4;
case UINT64_C(0x4810a7):goto kg_pc_4810a7;
case UINT64_C(0x4810aa):goto kg_pc_4810aa;
case UINT64_C(0x4810b0):goto kg_pc_4810b0;
case UINT64_C(0x4810b4):goto kg_pc_4810b4;
case UINT64_C(0x4810bb):goto kg_pc_4810bb;
case UINT64_C(0x4810be):goto kg_pc_4810be;
case UINT64_C(0x4810c2):goto kg_pc_4810c2;
case UINT64_C(0x4810c8):goto kg_pc_4810c8;
case UINT64_C(0x4810cc):goto kg_pc_4810cc;
case UINT64_C(0x4810ce):goto kg_pc_4810ce;
case UINT64_C(0x4810d2):goto kg_pc_4810d2;
case UINT64_C(0x4810d5):goto kg_pc_4810d5;
case UINT64_C(0x4810d9):goto kg_pc_4810d9;
case UINT64_C(0x4810e0):goto kg_pc_4810e0;
case UINT64_C(0x4810e3):goto kg_pc_4810e3;
case UINT64_C(0x4810e8):goto kg_pc_4810e8;
case UINT64_C(0x4810ef):goto kg_pc_4810ef;
case UINT64_C(0x4810f5):goto kg_pc_4810f5;
case UINT64_C(0x4810fa):goto kg_pc_4810fa;
case UINT64_C(0x4810fd):goto kg_pc_4810fd;
case UINT64_C(0x481101):goto kg_pc_481101;
case UINT64_C(0x481103):goto kg_pc_481103;
case UINT64_C(0x481108):goto kg_pc_481108;
case UINT64_C(0x48110f):goto kg_pc_48110f;
case UINT64_C(0x481111):goto kg_pc_481111;
case UINT64_C(0x481114):goto kg_pc_481114;
case UINT64_C(0x481117):goto kg_pc_481117;
case UINT64_C(0x48111d):goto kg_pc_48111d;
case UINT64_C(0x48111f):goto kg_pc_48111f;
case UINT64_C(0x481121):goto kg_pc_481121;
case UINT64_C(0x481127):goto kg_pc_481127;
case UINT64_C(0x48112e):goto kg_pc_48112e;
case UINT64_C(0x481131):goto kg_pc_481131;
case UINT64_C(0x481136):goto kg_pc_481136;
case UINT64_C(0x48113c):goto kg_pc_48113c;
case UINT64_C(0x48113f):goto kg_pc_48113f;
case UINT64_C(0x481145):goto kg_pc_481145;
case UINT64_C(0x481147):goto kg_pc_481147;
case UINT64_C(0x481149):goto kg_pc_481149;
case UINT64_C(0x48114e):goto kg_pc_48114e;
case UINT64_C(0x481150):goto kg_pc_481150;
case UINT64_C(0x481152):goto kg_pc_481152;
case UINT64_C(0x481158):goto kg_pc_481158;
case UINT64_C(0x48115a):goto kg_pc_48115a;
case UINT64_C(0x481161):goto kg_pc_481161;
case UINT64_C(0x481163):goto kg_pc_481163;
case UINT64_C(0x481166):goto kg_pc_481166;
case UINT64_C(0x481169):goto kg_pc_481169;
case UINT64_C(0x48116f):goto kg_pc_48116f;
case UINT64_C(0x481171):goto kg_pc_481171;
case UINT64_C(0x481173):goto kg_pc_481173;
case UINT64_C(0x481179):goto kg_pc_481179;
case UINT64_C(0x48117f):goto kg_pc_48117f;
case UINT64_C(0x481182):goto kg_pc_481182;
case UINT64_C(0x481188):goto kg_pc_481188;
case UINT64_C(0x48118a):goto kg_pc_48118a;
case UINT64_C(0x48118c):goto kg_pc_48118c;
case UINT64_C(0x481192):goto kg_pc_481192;
case UINT64_C(0x481198):goto kg_pc_481198;
case UINT64_C(0x48119f):goto kg_pc_48119f;
case UINT64_C(0x4811a1):goto kg_pc_4811a1;
case UINT64_C(0x4811a3):goto kg_pc_4811a3;
case UINT64_C(0x4811a9):goto kg_pc_4811a9;
case UINT64_C(0x4811af):goto kg_pc_4811af;
case UINT64_C(0x4811b6):goto kg_pc_4811b6;
case UINT64_C(0x4811b9):goto kg_pc_4811b9;
case UINT64_C(0x4811bb):goto kg_pc_4811bb;
case UINT64_C(0x4811bd):goto kg_pc_4811bd;
case UINT64_C(0x4811c3):goto kg_pc_4811c3;
case UINT64_C(0x4811c5):goto kg_pc_4811c5;
case UINT64_C(0x4811c7):goto kg_pc_4811c7;
case UINT64_C(0x4811ca):goto kg_pc_4811ca;
case UINT64_C(0x4811cf):goto kg_pc_4811cf;
case UINT64_C(0x4811d1):goto kg_pc_4811d1;
case UINT64_C(0x4811d3):goto kg_pc_4811d3;
case UINT64_C(0x4811d6):goto kg_pc_4811d6;
case UINT64_C(0x4811dc):goto kg_pc_4811dc;
case UINT64_C(0x4811de):goto kg_pc_4811de;
case UINT64_C(0x4811e0):goto kg_pc_4811e0;
case UINT64_C(0x4811e6):goto kg_pc_4811e6;
case UINT64_C(0x4811ec):goto kg_pc_4811ec;
case UINT64_C(0x4811ef):goto kg_pc_4811ef;
case UINT64_C(0x4811f5):goto kg_pc_4811f5;
case UINT64_C(0x4811f9):goto kg_pc_4811f9;
case UINT64_C(0x4811fd):goto kg_pc_4811fd;
case UINT64_C(0x481203):goto kg_pc_481203;
case UINT64_C(0x481209):goto kg_pc_481209;
case UINT64_C(0x48120c):goto kg_pc_48120c;
case UINT64_C(0x481212):goto kg_pc_481212;
case UINT64_C(0x481215):goto kg_pc_481215;
case UINT64_C(0x48121b):goto kg_pc_48121b;
case UINT64_C(0x48121d):goto kg_pc_48121d;
case UINT64_C(0x48121f):goto kg_pc_48121f;
case UINT64_C(0x481224):goto kg_pc_481224;
case UINT64_C(0x48122b):goto kg_pc_48122b;
case UINT64_C(0x48122e):goto kg_pc_48122e;
case UINT64_C(0x481234):goto kg_pc_481234;
case UINT64_C(0x481237):goto kg_pc_481237;
case UINT64_C(0x48123a):goto kg_pc_48123a;
case UINT64_C(0x481240):goto kg_pc_481240;
case UINT64_C(0x481242):goto kg_pc_481242;
case UINT64_C(0x481245):goto kg_pc_481245;
case UINT64_C(0x48124b):goto kg_pc_48124b;
case UINT64_C(0x481250):goto kg_pc_481250;
case UINT64_C(0x481257):goto kg_pc_481257;
case UINT64_C(0x48125a):goto kg_pc_48125a;
case UINT64_C(0x48125c):goto kg_pc_48125c;
case UINT64_C(0x481262):goto kg_pc_481262;
case UINT64_C(0x481268):goto kg_pc_481268;
case UINT64_C(0x48126a):goto kg_pc_48126a;
case UINT64_C(0x48126c):goto kg_pc_48126c;
case UINT64_C(0x481272):goto kg_pc_481272;
case UINT64_C(0x481274):goto kg_pc_481274;
case UINT64_C(0x48127a):goto kg_pc_48127a;
case UINT64_C(0x48127c):goto kg_pc_48127c;
case UINT64_C(0x481282):goto kg_pc_481282;
case UINT64_C(0x481285):goto kg_pc_481285;
case UINT64_C(0x48128a):goto kg_pc_48128a;
case UINT64_C(0x48128d):goto kg_pc_48128d;
case UINT64_C(0x481290):goto kg_pc_481290;
case UINT64_C(0x481295):goto kg_pc_481295;
case UINT64_C(0x48129a):goto kg_pc_48129a;
case UINT64_C(0x48129c):goto kg_pc_48129c;
case UINT64_C(0x48129e):goto kg_pc_48129e;
case UINT64_C(0x4812a1):goto kg_pc_4812a1;
case UINT64_C(0x4812a7):goto kg_pc_4812a7;
case UINT64_C(0x4812a9):goto kg_pc_4812a9;
case UINT64_C(0x4812b0):goto kg_pc_4812b0;
case UINT64_C(0x4812b2):goto kg_pc_4812b2;
case UINT64_C(0x4812b5):goto kg_pc_4812b5;
case UINT64_C(0x4812bb):goto kg_pc_4812bb;
case UINT64_C(0x4812bd):goto kg_pc_4812bd;
case UINT64_C(0x4812c1):goto kg_pc_4812c1;
case UINT64_C(0x4812c8):goto kg_pc_4812c8;
case UINT64_C(0x4812ce):goto kg_pc_4812ce;
case UINT64_C(0x4812d1):goto kg_pc_4812d1;
case UINT64_C(0x4812d7):goto kg_pc_4812d7;
case UINT64_C(0x4812d9):goto kg_pc_4812d9;
case UINT64_C(0x4812dd):goto kg_pc_4812dd;
case UINT64_C(0x4812e4):goto kg_pc_4812e4;
case UINT64_C(0x4812eb):goto kg_pc_4812eb;
case UINT64_C(0x4812ee):goto kg_pc_4812ee;
case UINT64_C(0x4812f1):goto kg_pc_4812f1;
case UINT64_C(0x4812f8):goto kg_pc_4812f8;
case UINT64_C(0x4812fa):goto kg_pc_4812fa;
case UINT64_C(0x481300):goto kg_pc_481300;
case UINT64_C(0x481306):goto kg_pc_481306;
case UINT64_C(0x481309):goto kg_pc_481309;
case UINT64_C(0x48130f):goto kg_pc_48130f;
case UINT64_C(0x481311):goto kg_pc_481311;
case UINT64_C(0x481313):goto kg_pc_481313;
case UINT64_C(0x481319):goto kg_pc_481319;
case UINT64_C(0x48131b):goto kg_pc_48131b;
case UINT64_C(0x48131d):goto kg_pc_48131d;
case UINT64_C(0x481323):goto kg_pc_481323;
case UINT64_C(0x481325):goto kg_pc_481325;
case UINT64_C(0x48132b):goto kg_pc_48132b;
case UINT64_C(0x48132e):goto kg_pc_48132e;
case UINT64_C(0x481334):goto kg_pc_481334;
case UINT64_C(0x481336):goto kg_pc_481336;
case UINT64_C(0x48133a):goto kg_pc_48133a;
case UINT64_C(0x481341):goto kg_pc_481341;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5243: [0x481016,0x481343), 195 instructions. */
kg_pc_481016: STEP(0x481016); /* add rdx, rdx */
x = s->gpr[3]; y = s->gpr[3];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_481019: STEP(0x481019); /* lea rsi, [r13 - 0x1624a076] */
s->gpr[4] = (UINT64_C(0xffffffffe9db5f8a) + s->gpr[13]);
++s->steps;
kg_pc_481020: STEP(0x481020); /* and rsi, rdx */
x = s->gpr[4]; y = s->gpr[3];
s->gpr[4] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_481023: STEP(0x481023); /* movabs rdx, 0x201e52000b12503a */
s->gpr[3] = UINT64_C(0x201e52000b12503a);
++s->steps;
kg_pc_48102d: STEP(0x48102d); /* xor rcx, rdx */
x = s->gpr[2]; y = s->gpr[3];
s->gpr[2] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_481030: STEP(0x481030); /* sub rcx, rsi */
x = s->gpr[2]; y = s->gpr[4];
s->gpr[2] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_481033: STEP(0x481033); /* lea r9, [rdi + rcx*4] */
s->gpr[9] = (UINT64_C(0x0) + s->gpr[5] + (s->gpr[2] * UINT64_C(0x4)));
++s->steps;
kg_pc_481037: STEP(0x481037); /* movabs rcx, 0x7f86b7ffd3b6bf18 */
s->gpr[2] = UINT64_C(0x7f86b7ffd3b6bf18);
++s->steps;
kg_pc_481041: STEP(0x481041); /* add r9, rcx */
x = s->gpr[9]; y = s->gpr[2];
s->gpr[9] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_481044: STEP(0x481044); /* cmp dword ptr [rbp - 0x388], 0xfa003c1e */
READ(a, (UINT64_C(0xfffffffffffffc78) + s->gpr[6]), 4);
x = a; y = UINT64_C(0xfa003c1e);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_48104e: STEP(0x48104e); /* mov edx, dword ptr [rbp - 0x2e8] */
READ(a, (UINT64_C(0xfffffffffffffd18) + s->gpr[6]), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_481054: STEP(0x481054); /* mov ecx, edx */
s->gpr[2] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481056: STEP(0x481056); /* mov ebx, dword ptr [rbp - 0x328] */
READ(a, (UINT64_C(0xfffffffffffffcd8) + s->gpr[6]), 4);
s->gpr[1] = (uint32_t)(a);
++s->steps;
kg_pc_48105c: STEP(0x48105c); /* cmove ecx, ebx */
s->gpr[2] = (uint32_t)((condition(s, COND_E) ? (s->gpr[1] & UINT64_C(0xffffffff)) : (s->gpr[2] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_48105f: STEP(0x48105f); /* mov rsi, qword ptr [rbp - 0x98] */
READ(a, (UINT64_C(0xffffffffffffff68) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_481066: STEP(0x481066); /* cmove ebx, esi */
s->gpr[1] = (uint32_t)((condition(s, COND_E) ? (s->gpr[4] & UINT64_C(0xffffffff)) : (s->gpr[1] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_481069: STEP(0x481069); /* mov edi, dword ptr [rbp - 0x270] */
READ(a, (UINT64_C(0xfffffffffffffd90) + s->gpr[6]), 4);
s->gpr[5] = (uint32_t)(a);
++s->steps;
kg_pc_48106f: STEP(0x48106f); /* cmove esi, edi */
s->gpr[4] = (uint32_t)((condition(s, COND_E) ? (s->gpr[5] & UINT64_C(0xffffffff)) : (s->gpr[4] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_481072: STEP(0x481072); /* mov r10, rsi */
s->gpr[10] = s->gpr[4];
++s->steps;
kg_pc_481075: STEP(0x481075); /* cmove edi, edx */
s->gpr[5] = (uint32_t)((condition(s, COND_E) ? (s->gpr[3] & UINT64_C(0xffffffff)) : (s->gpr[5] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_481078: STEP(0x481078); /* mov esi, eax */
s->gpr[4] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48107a: STEP(0x48107a); /* cmove esi, r8d */
s->gpr[4] = (uint32_t)((condition(s, COND_E) ? (s->gpr[8] & UINT64_C(0xffffffff)) : (s->gpr[4] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_48107e: STEP(0x48107e); /* cmove r8d, r15d */
s->gpr[8] = (uint32_t)((condition(s, COND_E) ? (s->gpr[15] & UINT64_C(0xffffffff)) : (s->gpr[8] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_481082: STEP(0x481082); /* cmove r15d, r14d */
s->gpr[15] = (uint32_t)((condition(s, COND_E) ? (s->gpr[14] & UINT64_C(0xffffffff)) : (s->gpr[15] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_481086: STEP(0x481086); /* cmove r14d, eax */
s->gpr[14] = (uint32_t)((condition(s, COND_E) ? (s->gpr[0] & UINT64_C(0xffffffff)) : (s->gpr[14] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_48108a: STEP(0x48108a); /* test byte ptr [rbp - 0x58], 2 */
READ(a, (UINT64_C(0xffffffffffffffa8) + s->gpr[6]), 1);
x = a; y = UINT64_C(0x2);
(void)operation(s, OP_AND, x, y, 8);
++s->steps;
kg_pc_48108e: STEP(0x48108e); /* mov edx, ebx */
s->gpr[3] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481090: STEP(0x481090); /* mov eax, edi */
s->gpr[0] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481092: STEP(0x481092); /* cmove edx, edi */
s->gpr[3] = (uint32_t)((condition(s, COND_E) ? (s->gpr[5] & UINT64_C(0xffffffff)) : (s->gpr[3] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_481095: STEP(0x481095); /* mov dword ptr [rbp - 0xf8], edx */
WRITE((UINT64_C(0xffffffffffffff08) + s->gpr[6]), 4, (s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48109b: STEP(0x48109b); /* cmove eax, ebx */
s->gpr[0] = (uint32_t)((condition(s, COND_E) ? (s->gpr[1] & UINT64_C(0xffffffff)) : (s->gpr[0] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_48109e: STEP(0x48109e); /* mov dword ptr [rbp - 0x270], eax */
WRITE((UINT64_C(0xfffffffffffffd90) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4810a4: STEP(0x4810a4); /* mov eax, r10d */
s->gpr[0] = (uint32_t)((s->gpr[10] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4810a7: STEP(0x4810a7); /* cmove eax, ecx */
s->gpr[0] = (uint32_t)((condition(s, COND_E) ? (s->gpr[2] & UINT64_C(0xffffffff)) : (s->gpr[0] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_4810aa: STEP(0x4810aa); /* mov dword ptr [rbp - 0x310], eax */
WRITE((UINT64_C(0xfffffffffffffcf0) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4810b0: STEP(0x4810b0); /* cmovne r10d, ecx */
s->gpr[10] = (uint32_t)((condition(s, COND_NE) ? (s->gpr[2] & UINT64_C(0xffffffff)) : (s->gpr[10] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_4810b4: STEP(0x4810b4); /* mov qword ptr [rbp - 0x98], r10 */
WRITE((UINT64_C(0xffffffffffffff68) + s->gpr[6]), 8, s->gpr[10]);
++s->steps;
kg_pc_4810bb: STEP(0x4810bb); /* mov eax, r14d */
s->gpr[0] = (uint32_t)((s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4810be: STEP(0x4810be); /* cmove eax, r8d */
s->gpr[0] = (uint32_t)((condition(s, COND_E) ? (s->gpr[8] & UINT64_C(0xffffffff)) : (s->gpr[0] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_4810c2: STEP(0x4810c2); /* mov dword ptr [rbp - 0xd0], eax */
WRITE((UINT64_C(0xffffffffffffff30) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4810c8: STEP(0x4810c8); /* cmovne r14d, r8d */
s->gpr[14] = (uint32_t)((condition(s, COND_NE) ? (s->gpr[8] & UINT64_C(0xffffffff)) : (s->gpr[14] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_4810cc: STEP(0x4810cc); /* mov eax, esi */
s->gpr[0] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4810ce: STEP(0x4810ce); /* cmove eax, r15d */
s->gpr[0] = (uint32_t)((condition(s, COND_E) ? (s->gpr[15] & UINT64_C(0xffffffff)) : (s->gpr[0] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_4810d2: STEP(0x4810d2); /* mov dword ptr [rbp - 0x78], eax */
WRITE((UINT64_C(0xffffffffffffff88) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4810d5: STEP(0x4810d5); /* cmove r15d, esi */
s->gpr[15] = (uint32_t)((condition(s, COND_E) ? (s->gpr[4] & UINT64_C(0xffffffff)) : (s->gpr[15] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_4810d9: STEP(0x4810d9); /* mov qword ptr [rbp - 0x990], r9 */
WRITE((UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8, s->gpr[9]);
++s->steps;
kg_pc_4810e0: STEP(0x4810e0); /* mov eax, r15d */
s->gpr[0] = (uint32_t)((s->gpr[15] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4810e3: STEP(0x4810e3); /* xor eax, 0x71beebdf */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x71beebdf);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4810e8: STEP(0x4810e8); /* imul r13d, eax, 0x63f3deb */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x63f3deb);
s->gpr[13] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_4810ef: STEP(0x4810ef); /* imul eax, eax, 0xc7e7bd6 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xc7e7bd6);
s->gpr[0] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_4810f5: STEP(0x4810f5); /* and eax, 0xfc13fbca */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xfc13fbca);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4810fa: STEP(0x4810fa); /* sub r13d, eax */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_4810fd: STEP(0x4810fd); /* mov rsi, qword ptr [rbp - 0x70] */
READ(a, (UINT64_C(0xffffffffffffff90) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_481101: STEP(0x481101); /* mov eax, esi */
s->gpr[0] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481103: STEP(0x481103); /* xor eax, 0x1929baec */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1929baec);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481108: STEP(0x481108); /* mov rcx, qword ptr [rbp - 0x118] */
READ(a, (UINT64_C(0xfffffffffffffee8) + s->gpr[6]), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_48110f: STEP(0x48110f); /* and eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481111: STEP(0x481111); /* mov r10, rcx */
s->gpr[10] = s->gpr[2];
++s->steps;
kg_pc_481114: STEP(0x481114); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481117: STEP(0x481117); /* and ecx, 0x8c3f14c8 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x8c3f14c8);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48111d: STEP(0x48111d); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_48111f: STEP(0x48111f); /* add ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481121: STEP(0x481121); /* add ecx, 0x461f8a64 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x461f8a64);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481127: STEP(0x481127); /* mov r9d, dword ptr [rbp - 0x268] */
READ(a, (UINT64_C(0xfffffffffffffd98) + s->gpr[6]), 4);
s->gpr[9] = (uint32_t)(a);
++s->steps;
kg_pc_48112e: STEP(0x48112e); /* mov eax, r9d */
s->gpr[0] = (uint32_t)((s->gpr[9] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481131: STEP(0x481131); /* xor eax, 0x1929baec */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1929baec);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481136: STEP(0x481136); /* and eax, dword ptr [rbp - 0x3c0] */
READ(b, (UINT64_C(0xfffffffffffffc40) + s->gpr[6]), 4);
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = b;
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48113c: STEP(0x48113c); /* lea edx, [rax + rax] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_48113f: STEP(0x48113f); /* and edx, 0x38d8caf8 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x38d8caf8);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481145: STEP(0x481145); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481147: STEP(0x481147); /* add eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481149: STEP(0x481149); /* add eax, 0x1c6c657c */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1c6c657c);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48114e: STEP(0x48114e); /* shr ecx, 1 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x1);
s->gpr[2] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_481150: STEP(0x481150); /* xor ecx, esi */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481152: STEP(0x481152); /* xor ecx, 0x3a267fde */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x3a267fde);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481158: STEP(0x481158); /* mov edx, ecx */
s->gpr[3] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48115a: STEP(0x48115a); /* mov rsi, qword ptr [rbp - 0x160] */
READ(a, (UINT64_C(0xfffffffffffffea0) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_481161: STEP(0x481161); /* and edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481163: STEP(0x481163); /* mov rbx, rsi */
s->gpr[1] = s->gpr[4];
++s->steps;
kg_pc_481166: STEP(0x481166); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_481169: STEP(0x481169); /* and esi, 0xef49f160 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xef49f160);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48116f: STEP(0x48116f); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481171: STEP(0x481171); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481173: STEP(0x481173); /* add edx, 0x77a4f8b0 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x77a4f8b0);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481179: STEP(0x481179); /* and ecx, dword ptr [rbp - 0xe0] */
READ(b, (UINT64_C(0xffffffffffffff20) + s->gpr[6]), 4);
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = b;
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48117f: STEP(0x48117f); /* lea esi, [rcx + rcx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_481182: STEP(0x481182); /* and esi, 0x628beca4 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x628beca4);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481188: STEP(0x481188); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_48118a: STEP(0x48118a); /* add esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48118c: STEP(0x48118c); /* add esi, 0x3145f652 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x3145f652);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481192: STEP(0x481192); /* xor edx, 0x77a4f8b0 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x77a4f8b0);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481198: STEP(0x481198); /* mov rcx, qword ptr [rbp - 0xa0] */
READ(a, (UINT64_C(0xffffffffffffff60) + s->gpr[6]), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_48119f: STEP(0x48119f); /* shr edx, cl */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_4811a1: STEP(0x4811a1); /* mov edi, edx */
s->gpr[5] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4811a3: STEP(0x4811a3); /* xor edi, 0xeff58ebf */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xeff58ebf);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4811a9: STEP(0x4811a9); /* xor esi, 0x3145f652 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x3145f652);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4811af: STEP(0x4811af); /* mov r8, qword ptr [rbp - 0x3e0] */
READ(a, (UINT64_C(0xfffffffffffffc20) + s->gpr[6]), 8);
s->gpr[8] = a;
++s->steps;
kg_pc_4811b6: STEP(0x4811b6); /* mov ecx, r8d */
s->gpr[2] = (uint32_t)((s->gpr[8] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4811b9: STEP(0x4811b9); /* shl esi, cl */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[4] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_4811bb: STEP(0x4811bb); /* mov ecx, esi */
s->gpr[2] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4811bd: STEP(0x4811bd); /* xor ecx, 0x5db1e7a5 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x5db1e7a5);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4811c3: STEP(0x4811c3); /* add ecx, edi */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4811c5: STEP(0x4811c5); /* shr eax, 1 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_4811c7: STEP(0x4811c7); /* xor eax, r9d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[9] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4811ca: STEP(0x4811ca); /* xor eax, 0x171f8852 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x171f8852);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4811cf: STEP(0x4811cf); /* mov edi, eax */
s->gpr[5] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4811d1: STEP(0x4811d1); /* and edi, ebx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4811d3: STEP(0x4811d3); /* lea ebx, [rdi + rdi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_4811d6: STEP(0x4811d6); /* and ebx, 0x6826bb40 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x6826bb40);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4811dc: STEP(0x4811dc); /* neg ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = 0;
s->gpr[1] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4811de: STEP(0x4811de); /* add edi, ebx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4811e0: STEP(0x4811e0); /* add edi, 0x34135da0 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x34135da0);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4811e6: STEP(0x4811e6); /* and esi, 0xddb1e7a5 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xddb1e7a5);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4811ec: STEP(0x4811ec); /* lea ecx, [rcx + rsi*2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[4] * UINT64_C(0x2))));
++s->steps;
kg_pc_4811ef: STEP(0x4811ef); /* and edx, 0xeff58ebf */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xeff58ebf);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4811f5: STEP(0x4811f5); /* lea r11d, [rcx + rdx*2] */
s->gpr[11] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_4811f9: STEP(0x4811f9); /* lea ecx, [r11 + r11] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[11] + (s->gpr[11] * UINT64_C(0x1))));
++s->steps;
kg_pc_4811fd: STEP(0x4811fd); /* add ecx, 0x64b11338 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x64b11338);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481203: STEP(0x481203); /* and ecx, 0x9c30abf0 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x9c30abf0);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481209: STEP(0x481209); /* sub r11d, ecx */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[11] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_48120c: STEP(0x48120c); /* and eax, dword ptr [rbp - 0x2f0] */
READ(b, (UINT64_C(0xfffffffffffffd10) + s->gpr[6]), 4);
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = b;
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481212: STEP(0x481212); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481215: STEP(0x481215); /* and ecx, 0x5d13ec38 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x5d13ec38);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48121b: STEP(0x48121b); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_48121d: STEP(0x48121d); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48121f: STEP(0x48121f); /* add eax, 0x2e89f61c */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x2e89f61c);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481224: STEP(0x481224); /* mov r9d, dword ptr [rbp - 0x288] */
READ(a, (UINT64_C(0xfffffffffffffd78) + s->gpr[6]), 4);
s->gpr[9] = (uint32_t)(a);
++s->steps;
kg_pc_48122b: STEP(0x48122b); /* mov ecx, r9d */
s->gpr[2] = (uint32_t)((s->gpr[9] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48122e: STEP(0x48122e); /* xor ecx, 0x1929baec */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x1929baec);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481234: STEP(0x481234); /* and ecx, r10d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481237: STEP(0x481237); /* lea edx, [rcx + rcx] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_48123a: STEP(0x48123a); /* and edx, 0xdce0f294 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xdce0f294);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481240: STEP(0x481240); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481242: STEP(0x481242); /* lea esi, [rcx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_481245: STEP(0x481245); /* add esi, 0x6e70794a */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x6e70794a);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48124b: STEP(0x48124b); /* xor eax, 0x2e89f61c */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x2e89f61c);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481250: STEP(0x481250); /* mov r12, qword ptr [rbp - 0x2d8] */
READ(a, (UINT64_C(0xfffffffffffffd28) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_481257: STEP(0x481257); /* mov ecx, r12d */
s->gpr[2] = (uint32_t)((s->gpr[12] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48125a: STEP(0x48125a); /* shl eax, cl */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[0] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_48125c: STEP(0x48125c); /* xor edi, 0x34135da0 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x34135da0);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481262: STEP(0x481262); /* mov ecx, dword ptr [rbp - 0x330] */
READ(a, (UINT64_C(0xfffffffffffffcd0) + s->gpr[6]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
kg_pc_481268: STEP(0x481268); /* shr edi, cl */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[5] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_48126a: STEP(0x48126a); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48126c: STEP(0x48126c); /* xor ecx, 0x7ff9dfde */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x7ff9dfde);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481272: STEP(0x481272); /* mov edx, edi */
s->gpr[3] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481274: STEP(0x481274); /* xor edx, 0x7e6ffeaf */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x7e6ffeaf);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48127a: STEP(0x48127a); /* add edx, ecx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48127c: STEP(0x48127c); /* and edi, 0xfe6ffeaf */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xfe6ffeaf);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481282: STEP(0x481282); /* lea ecx, [rdx + rdi*2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[5] * UINT64_C(0x2))));
++s->steps;
kg_pc_481285: STEP(0x481285); /* and eax, 0xfff9dfde */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xfff9dfde);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48128a: STEP(0x48128a); /* lea ebx, [rcx + rax*2] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_48128d: STEP(0x48128d); /* lea eax, [rbx + rbx] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[1] * UINT64_C(0x1))));
++s->steps;
kg_pc_481290: STEP(0x481290); /* add eax, 0x32c42e6 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x32c42e6);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481295: STEP(0x481295); /* and eax, 0xadc3525a */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xadc3525a);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48129a: STEP(0x48129a); /* sub ebx, eax */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_48129c: STEP(0x48129c); /* shr esi, 1 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x1);
s->gpr[4] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_48129e: STEP(0x48129e); /* xor esi, r9d */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[9] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4812a1: STEP(0x4812a1); /* xor esi, 0x2e118649 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x2e118649);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4812a7: STEP(0x4812a7); /* mov eax, esi */
s->gpr[0] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4812a9: STEP(0x4812a9); /* mov rdi, qword ptr [rbp - 0xe0] */
READ(a, (UINT64_C(0xffffffffffffff20) + s->gpr[6]), 8);
s->gpr[5] = a;
++s->steps;
kg_pc_4812b0: STEP(0x4812b0); /* and eax, edi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4812b2: STEP(0x4812b2); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_4812b5: STEP(0x4812b5); /* and ecx, 0x95523f2 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x95523f2);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4812bb: STEP(0x4812bb); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4812bd: STEP(0x4812bd); /* lea r10d, [rax + rcx] */
s->gpr[10] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_4812c1: STEP(0x4812c1); /* add r10d, 0x4aa91f9 */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x4aa91f9);
s->gpr[10] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4812c8: STEP(0x4812c8); /* and esi, dword ptr [rbp - 0x298] */
READ(b, (UINT64_C(0xfffffffffffffd68) + s->gpr[6]), 4);
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = b;
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4812ce: STEP(0x4812ce); /* lea ecx, [rsi + rsi] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_4812d1: STEP(0x4812d1); /* and ecx, 0xe3bb4b6c */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xe3bb4b6c);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4812d7: STEP(0x4812d7); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4812d9: STEP(0x4812d9); /* lea r9d, [rsi + rcx] */
s->gpr[9] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_4812dd: STEP(0x4812dd); /* add r9d, 0x71dda5b6 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x71dda5b6);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4812e4: STEP(0x4812e4); /* xor r10d, 0x4aa91f9 */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x4aa91f9);
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4812eb: STEP(0x4812eb); /* mov ecx, r8d */
s->gpr[2] = (uint32_t)((s->gpr[8] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4812ee: STEP(0x4812ee); /* shl r10d, cl */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[10] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_4812f1: STEP(0x4812f1); /* mov rax, qword ptr [rbp - 0x150] */
READ(a, (UINT64_C(0xfffffffffffffeb0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_4812f8: STEP(0x4812f8); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4812fa: STEP(0x4812fa); /* xor ecx, 0x1929baec */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x1929baec);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481300: STEP(0x481300); /* and ecx, dword ptr [rbp - 0x118] */
READ(b, (UINT64_C(0xfffffffffffffee8) + s->gpr[6]), 4);
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = b;
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481306: STEP(0x481306); /* lea edx, [rcx + rcx] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_481309: STEP(0x481309); /* and edx, 0xfd54521a */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xfd54521a);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48130f: STEP(0x48130f); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481311: STEP(0x481311); /* add ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481313: STEP(0x481313); /* add ecx, 0x7eaa290d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x7eaa290d);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481319: STEP(0x481319); /* shr ecx, 1 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x1);
s->gpr[2] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_48131b: STEP(0x48131b); /* xor ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48131d: STEP(0x48131d); /* xor ecx, 0x267cae6a */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x267cae6a);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481323: STEP(0x481323); /* mov edx, ecx */
s->gpr[3] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481325: STEP(0x481325); /* and edx, dword ptr [rbp - 0x160] */
READ(b, (UINT64_C(0xfffffffffffffea0) + s->gpr[6]), 4);
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = b;
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48132b: STEP(0x48132b); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_48132e: STEP(0x48132e); /* and esi, 0xe4cf66c8 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xe4cf66c8);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481334: STEP(0x481334); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481336: STEP(0x481336); /* lea r8d, [rdx + rsi] */
s->gpr[8] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_48133a: STEP(0x48133a); /* add r8d, 0x7267b364 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x7267b364);
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481341: STEP(0x481341); /* and ecx, edi */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;

break;
    case 5:
next_pc=bias+UINT64_C(0x48166a);
switch(s->pc-bias){
case UINT64_C(0x481343):goto kg_pc_481343;
case UINT64_C(0x481346):goto kg_pc_481346;
case UINT64_C(0x48134c):goto kg_pc_48134c;
case UINT64_C(0x48134e):goto kg_pc_48134e;
case UINT64_C(0x481350):goto kg_pc_481350;
case UINT64_C(0x481356):goto kg_pc_481356;
case UINT64_C(0x481359):goto kg_pc_481359;
case UINT64_C(0x48135e):goto kg_pc_48135e;
case UINT64_C(0x481365):goto kg_pc_481365;
case UINT64_C(0x48136c):goto kg_pc_48136c;
case UINT64_C(0x48136e):goto kg_pc_48136e;
case UINT64_C(0x481371):goto kg_pc_481371;
case UINT64_C(0x481374):goto kg_pc_481374;
case UINT64_C(0x48137a):goto kg_pc_48137a;
case UINT64_C(0x481380):goto kg_pc_481380;
case UINT64_C(0x481383):goto kg_pc_481383;
case UINT64_C(0x481385):goto kg_pc_481385;
case UINT64_C(0x48138c):goto kg_pc_48138c;
case UINT64_C(0x48138e):goto kg_pc_48138e;
case UINT64_C(0x481391):goto kg_pc_481391;
case UINT64_C(0x481393):goto kg_pc_481393;
case UINT64_C(0x481395):goto kg_pc_481395;
case UINT64_C(0x48139a):goto kg_pc_48139a;
case UINT64_C(0x48139d):goto kg_pc_48139d;
case UINT64_C(0x4813a3):goto kg_pc_4813a3;
case UINT64_C(0x4813a5):goto kg_pc_4813a5;
case UINT64_C(0x4813ac):goto kg_pc_4813ac;
case UINT64_C(0x4813b0):goto kg_pc_4813b0;
case UINT64_C(0x4813b7):goto kg_pc_4813b7;
case UINT64_C(0x4813bb):goto kg_pc_4813bb;
case UINT64_C(0x4813be):goto kg_pc_4813be;
case UINT64_C(0x4813c3):goto kg_pc_4813c3;
case UINT64_C(0x4813c8):goto kg_pc_4813c8;
case UINT64_C(0x4813ca):goto kg_pc_4813ca;
case UINT64_C(0x4813d0):goto kg_pc_4813d0;
case UINT64_C(0x4813d6):goto kg_pc_4813d6;
case UINT64_C(0x4813d8):goto kg_pc_4813d8;
case UINT64_C(0x4813df):goto kg_pc_4813df;
case UINT64_C(0x4813e3):goto kg_pc_4813e3;
case UINT64_C(0x4813e9):goto kg_pc_4813e9;
case UINT64_C(0x4813ec):goto kg_pc_4813ec;
case UINT64_C(0x4813ef):goto kg_pc_4813ef;
case UINT64_C(0x4813f5):goto kg_pc_4813f5;
case UINT64_C(0x4813fb):goto kg_pc_4813fb;
case UINT64_C(0x4813fd):goto kg_pc_4813fd;
case UINT64_C(0x481403):goto kg_pc_481403;
case UINT64_C(0x481409):goto kg_pc_481409;
case UINT64_C(0x48140f):goto kg_pc_48140f;
case UINT64_C(0x481415):goto kg_pc_481415;
case UINT64_C(0x481417):goto kg_pc_481417;
case UINT64_C(0x48141e):goto kg_pc_48141e;
case UINT64_C(0x481424):goto kg_pc_481424;
case UINT64_C(0x481427):goto kg_pc_481427;
case UINT64_C(0x481429):goto kg_pc_481429;
case UINT64_C(0x48142f):goto kg_pc_48142f;
case UINT64_C(0x481435):goto kg_pc_481435;
case UINT64_C(0x48143b):goto kg_pc_48143b;
case UINT64_C(0x481441):goto kg_pc_481441;
case UINT64_C(0x481443):goto kg_pc_481443;
case UINT64_C(0x481449):goto kg_pc_481449;
case UINT64_C(0x48144f):goto kg_pc_48144f;
case UINT64_C(0x481455):goto kg_pc_481455;
case UINT64_C(0x48145b):goto kg_pc_48145b;
case UINT64_C(0x481461):goto kg_pc_481461;
case UINT64_C(0x481463):goto kg_pc_481463;
case UINT64_C(0x48146a):goto kg_pc_48146a;
case UINT64_C(0x481470):goto kg_pc_481470;
case UINT64_C(0x481476):goto kg_pc_481476;
case UINT64_C(0x48147c):goto kg_pc_48147c;
case UINT64_C(0x48147f):goto kg_pc_48147f;
case UINT64_C(0x481485):goto kg_pc_481485;
case UINT64_C(0x481487):goto kg_pc_481487;
case UINT64_C(0x48148d):goto kg_pc_48148d;
case UINT64_C(0x481493):goto kg_pc_481493;
case UINT64_C(0x481499):goto kg_pc_481499;
case UINT64_C(0x48149f):goto kg_pc_48149f;
case UINT64_C(0x4814a5):goto kg_pc_4814a5;
case UINT64_C(0x4814a8):goto kg_pc_4814a8;
case UINT64_C(0x4814ae):goto kg_pc_4814ae;
case UINT64_C(0x4814b0):goto kg_pc_4814b0;
case UINT64_C(0x4814b7):goto kg_pc_4814b7;
case UINT64_C(0x4814b9):goto kg_pc_4814b9;
case UINT64_C(0x4814bf):goto kg_pc_4814bf;
case UINT64_C(0x4814c5):goto kg_pc_4814c5;
case UINT64_C(0x4814cb):goto kg_pc_4814cb;
case UINT64_C(0x4814d1):goto kg_pc_4814d1;
case UINT64_C(0x4814d7):goto kg_pc_4814d7;
case UINT64_C(0x4814dd):goto kg_pc_4814dd;
case UINT64_C(0x4814e3):goto kg_pc_4814e3;
case UINT64_C(0x4814e5):goto kg_pc_4814e5;
case UINT64_C(0x4814eb):goto kg_pc_4814eb;
case UINT64_C(0x4814f1):goto kg_pc_4814f1;
case UINT64_C(0x4814f7):goto kg_pc_4814f7;
case UINT64_C(0x4814fd):goto kg_pc_4814fd;
case UINT64_C(0x4814ff):goto kg_pc_4814ff;
case UINT64_C(0x481506):goto kg_pc_481506;
case UINT64_C(0x481509):goto kg_pc_481509;
case UINT64_C(0x48150b):goto kg_pc_48150b;
case UINT64_C(0x481510):goto kg_pc_481510;
case UINT64_C(0x481512):goto kg_pc_481512;
case UINT64_C(0x481514):goto kg_pc_481514;
case UINT64_C(0x481519):goto kg_pc_481519;
case UINT64_C(0x48151c):goto kg_pc_48151c;
case UINT64_C(0x481522):goto kg_pc_481522;
case UINT64_C(0x481526):goto kg_pc_481526;
case UINT64_C(0x48152c):goto kg_pc_48152c;
case UINT64_C(0x481532):goto kg_pc_481532;
case UINT64_C(0x481535):goto kg_pc_481535;
case UINT64_C(0x48153b):goto kg_pc_48153b;
case UINT64_C(0x481541):goto kg_pc_481541;
case UINT64_C(0x481546):goto kg_pc_481546;
case UINT64_C(0x48154c):goto kg_pc_48154c;
case UINT64_C(0x481552):goto kg_pc_481552;
case UINT64_C(0x481554):goto kg_pc_481554;
case UINT64_C(0x48155a):goto kg_pc_48155a;
case UINT64_C(0x48155c):goto kg_pc_48155c;
case UINT64_C(0x48155f):goto kg_pc_48155f;
case UINT64_C(0x481563):goto kg_pc_481563;
case UINT64_C(0x481566):goto kg_pc_481566;
case UINT64_C(0x481568):goto kg_pc_481568;
case UINT64_C(0x48156e):goto kg_pc_48156e;
case UINT64_C(0x481575):goto kg_pc_481575;
case UINT64_C(0x481578):goto kg_pc_481578;
case UINT64_C(0x48157f):goto kg_pc_48157f;
case UINT64_C(0x481586):goto kg_pc_481586;
case UINT64_C(0x48158d):goto kg_pc_48158d;
case UINT64_C(0x481590):goto kg_pc_481590;
case UINT64_C(0x481593):goto kg_pc_481593;
case UINT64_C(0x481596):goto kg_pc_481596;
case UINT64_C(0x481599):goto kg_pc_481599;
case UINT64_C(0x48159e):goto kg_pc_48159e;
case UINT64_C(0x4815a0):goto kg_pc_4815a0;
case UINT64_C(0x4815a5):goto kg_pc_4815a5;
case UINT64_C(0x4815a7):goto kg_pc_4815a7;
case UINT64_C(0x4815ad):goto kg_pc_4815ad;
case UINT64_C(0x4815b3):goto kg_pc_4815b3;
case UINT64_C(0x4815b8):goto kg_pc_4815b8;
case UINT64_C(0x4815bb):goto kg_pc_4815bb;
case UINT64_C(0x4815be):goto kg_pc_4815be;
case UINT64_C(0x4815c3):goto kg_pc_4815c3;
case UINT64_C(0x4815c8):goto kg_pc_4815c8;
case UINT64_C(0x4815ca):goto kg_pc_4815ca;
case UINT64_C(0x4815d0):goto kg_pc_4815d0;
case UINT64_C(0x4815d6):goto kg_pc_4815d6;
case UINT64_C(0x4815d8):goto kg_pc_4815d8;
case UINT64_C(0x4815db):goto kg_pc_4815db;
case UINT64_C(0x4815e2):goto kg_pc_4815e2;
case UINT64_C(0x4815e5):goto kg_pc_4815e5;
case UINT64_C(0x4815e8):goto kg_pc_4815e8;
case UINT64_C(0x4815ea):goto kg_pc_4815ea;
case UINT64_C(0x4815ed):goto kg_pc_4815ed;
case UINT64_C(0x4815ef):goto kg_pc_4815ef;
case UINT64_C(0x4815f5):goto kg_pc_4815f5;
case UINT64_C(0x4815fb):goto kg_pc_4815fb;
case UINT64_C(0x4815fd):goto kg_pc_4815fd;
case UINT64_C(0x4815ff):goto kg_pc_4815ff;
case UINT64_C(0x481601):goto kg_pc_481601;
case UINT64_C(0x481604):goto kg_pc_481604;
case UINT64_C(0x481607):goto kg_pc_481607;
case UINT64_C(0x48160c):goto kg_pc_48160c;
case UINT64_C(0x48160e):goto kg_pc_48160e;
case UINT64_C(0x481614):goto kg_pc_481614;
case UINT64_C(0x481617):goto kg_pc_481617;
case UINT64_C(0x48161a):goto kg_pc_48161a;
case UINT64_C(0x481620):goto kg_pc_481620;
case UINT64_C(0x481622):goto kg_pc_481622;
case UINT64_C(0x481628):goto kg_pc_481628;
case UINT64_C(0x48162a):goto kg_pc_48162a;
case UINT64_C(0x48162c):goto kg_pc_48162c;
case UINT64_C(0x48162f):goto kg_pc_48162f;
case UINT64_C(0x481631):goto kg_pc_481631;
case UINT64_C(0x481636):goto kg_pc_481636;
case UINT64_C(0x48163d):goto kg_pc_48163d;
case UINT64_C(0x481644):goto kg_pc_481644;
case UINT64_C(0x481647):goto kg_pc_481647;
case UINT64_C(0x48164e):goto kg_pc_48164e;
case UINT64_C(0x481652):goto kg_pc_481652;
case UINT64_C(0x481659):goto kg_pc_481659;
case UINT64_C(0x481661):goto kg_pc_481661;
case UINT64_C(0x481664):goto kg_pc_481664;
case UINT64_C(0x481667):goto kg_pc_481667;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5244: [0x481343,0x48166a), 181 instructions. */
kg_pc_481343: STEP(0x481343); /* lea edx, [rcx + rcx] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_481346: STEP(0x481346); /* and edx, 0x26bf2ee8 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x26bf2ee8);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48134c: STEP(0x48134c); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_48134e: STEP(0x48134e); /* add edx, ecx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481350: STEP(0x481350); /* add edx, 0x135f9774 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x135f9774);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481356: STEP(0x481356); /* mov eax, r10d */
s->gpr[0] = (uint32_t)((s->gpr[10] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481359: STEP(0x481359); /* xor eax, 0xefff3f79 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xefff3f79);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48135e: STEP(0x48135e); /* xor r9d, 0x71dda5b6 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x71dda5b6);
s->gpr[9] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481365: STEP(0x481365); /* mov rsi, qword ptr [rbp - 0xa0] */
READ(a, (UINT64_C(0xffffffffffffff60) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_48136c: STEP(0x48136c); /* mov ecx, esi */
s->gpr[2] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48136e: STEP(0x48136e); /* shr r9d, cl */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[9] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_481371: STEP(0x481371); /* mov edi, r9d */
s->gpr[5] = (uint32_t)((s->gpr[9] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481374: STEP(0x481374); /* xor edi, 0xf4ee6dbd */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xf4ee6dbd);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48137a: STEP(0x48137a); /* xor edx, 0x135f9774 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x135f9774);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481380: STEP(0x481380); /* mov ecx, r12d */
s->gpr[2] = (uint32_t)((s->gpr[12] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481383: STEP(0x481383); /* shl edx, cl */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[3] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_481385: STEP(0x481385); /* xor r8d, 0x7267b364 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x7267b364);
s->gpr[8] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48138c: STEP(0x48138c); /* mov ecx, esi */
s->gpr[2] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48138e: STEP(0x48138e); /* shr r8d, cl */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[8] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_481391: STEP(0x481391); /* add edi, eax */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481393: STEP(0x481393); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481395: STEP(0x481395); /* xor eax, 0xfb5f2fa6 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xfb5f2fa6);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48139a: STEP(0x48139a); /* mov esi, r8d */
s->gpr[4] = (uint32_t)((s->gpr[8] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48139d: STEP(0x48139d); /* xor esi, 0x7d7f66df */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x7d7f66df);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4813a3: STEP(0x4813a3); /* add esi, eax */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4813a5: STEP(0x4813a5); /* and r10d, 0xefff3f79 */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0xefff3f79);
s->gpr[10] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4813ac: STEP(0x4813ac); /* lea eax, [rdi + r10*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[10] * UINT64_C(0x2))));
++s->steps;
kg_pc_4813b0: STEP(0x4813b0); /* and r9d, 0xf4ee6dbd */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0xf4ee6dbd);
s->gpr[9] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4813b7: STEP(0x4813b7); /* lea ecx, [rax + r9*2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[9] * UINT64_C(0x2))));
++s->steps;
kg_pc_4813bb: STEP(0x4813bb); /* lea eax, [rcx + rcx] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_4813be: STEP(0x4813be); /* add eax, 0x1624a594 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1624a594);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4813c3: STEP(0x4813c3); /* and eax, 0x1b5fa9b0 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1b5fa9b0);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4813c8: STEP(0x4813c8); /* sub ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_4813ca: STEP(0x4813ca); /* add ebx, 0x5877caa0 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x5877caa0);
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4813d0: STEP(0x4813d0); /* add ecx, 0x28c227a2 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x28c227a2);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4813d6: STEP(0x4813d6); /* xor ecx, ebx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4813d8: STEP(0x4813d8); /* and r8d, 0xfd7f66df */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0xfd7f66df);
s->gpr[8] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4813df: STEP(0x4813df); /* lea eax, [rsi + r8*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[8] * UINT64_C(0x2))));
++s->steps;
kg_pc_4813e3: STEP(0x4813e3); /* and edx, 0xfb5f2fa6 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xfb5f2fa6);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4813e9: STEP(0x4813e9); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_4813ec: STEP(0x4813ec); /* lea edx, [rax + rax] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_4813ef: STEP(0x4813ef); /* add edx, 0xe42d2f6 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xe42d2f6);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4813f5: STEP(0x4813f5); /* and edx, 0xe4922d8c */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xe4922d8c);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4813fb: STEP(0x4813fb); /* sub eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_4813fd: STEP(0x4813fd); /* mov edx, dword ptr [rbp - 0x9b0] */
READ(a, (UINT64_C(0xfffffffffffff650) + s->gpr[6]), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_481403: STEP(0x481403); /* xor edx, dword ptr [rbp - 0x220] */
READ(b, (UINT64_C(0xfffffffffffffde0) + s->gpr[6]), 4);
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481409: STEP(0x481409); /* mov esi, dword ptr [rbp - 0x1a8] */
READ(a, (UINT64_C(0xfffffffffffffe58) + s->gpr[6]), 4);
s->gpr[4] = (uint32_t)(a);
++s->steps;
kg_pc_48140f: STEP(0x48140f); /* xor esi, dword ptr [rbp - 0x2a0] */
READ(b, (UINT64_C(0xfffffffffffffd60) + s->gpr[6]), 4);
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = b;
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481415: STEP(0x481415); /* xor esi, edx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481417: STEP(0x481417); /* mov rdx, qword ptr [rbp - 0xb0] */
READ(a, (UINT64_C(0xffffffffffffff50) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_48141e: STEP(0x48141e); /* xor edx, dword ptr [rbp - 0x1b8] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xfffffffffffffe48) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0xffffffffffffffa0) + s->gpr[6]);
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, (s->gpr[3] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x481427);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xfffffffffffffe48) + s->gpr[6]), 4);
x=(s->gpr[3] & UINT64_C(0xffffffff));y=b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481424: STEP(0x481424); /* xor edx, dword ptr [rbp - 0x60] */
READ(b, (UINT64_C(0xffffffffffffffa0) + s->gpr[6]), 4);
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481427: STEP(0x481427); /* xor edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481429: STEP(0x481429); /* mov esi, dword ptr [rbp - 0x240] */
READ(a, (UINT64_C(0xfffffffffffffdc0) + s->gpr[6]), 4);
s->gpr[4] = (uint32_t)(a);
++s->steps;
kg_pc_48142f: STEP(0x48142f); /* xor esi, dword ptr [rbp - 0x2e0] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xfffffffffffffd20) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0xfffffffffffffdb8) + s->gpr[6]);
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, (s->gpr[4] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x48143b);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xfffffffffffffd20) + s->gpr[6]), 4);
x=(s->gpr[4] & UINT64_C(0xffffffff));y=b;
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481435: STEP(0x481435); /* xor esi, dword ptr [rbp - 0x248] */
READ(b, (UINT64_C(0xfffffffffffffdb8) + s->gpr[6]), 4);
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = b;
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48143b: STEP(0x48143b); /* xor esi, dword ptr [rbp - 0x130] */
READ(b, (UINT64_C(0xfffffffffffffed0) + s->gpr[6]), 4);
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = b;
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481441: STEP(0x481441); /* xor esi, edx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481443: STEP(0x481443); /* mov edx, dword ptr [rbp - 0x290] */
READ(a, (UINT64_C(0xfffffffffffffd70) + s->gpr[6]), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_481449: STEP(0x481449); /* xor edx, dword ptr [rbp - 0x178] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xfffffffffffffe88) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0xfffffffffffffbf0) + s->gpr[6]);
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, (s->gpr[3] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x481455);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xfffffffffffffe88) + s->gpr[6]), 4);
x=(s->gpr[3] & UINT64_C(0xffffffff));y=b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48144f: STEP(0x48144f); /* xor edx, dword ptr [rbp - 0x410] */
READ(b, (UINT64_C(0xfffffffffffffbf0) + s->gpr[6]), 4);
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481455: STEP(0x481455); /* xor edx, dword ptr [rbp - 0x190] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xfffffffffffffe70) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0xfffffffffffffef8) + s->gpr[6]);
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, (s->gpr[3] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x481461);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xfffffffffffffe70) + s->gpr[6]), 4);
x=(s->gpr[3] & UINT64_C(0xffffffff));y=b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48145b: STEP(0x48145b); /* xor edx, dword ptr [rbp - 0x108] */
READ(b, (UINT64_C(0xfffffffffffffef8) + s->gpr[6]), 4);
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481461: STEP(0x481461); /* xor edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481463: STEP(0x481463); /* mov rsi, qword ptr [rbp - 0x90] */
READ(a, (UINT64_C(0xffffffffffffff70) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_48146a: STEP(0x48146a); /* xor esi, dword ptr [rbp - 0x440] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xfffffffffffffbc0) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0xfffffffffffffd48) + s->gpr[6]);
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, (s->gpr[4] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x481476);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xfffffffffffffbc0) + s->gpr[6]), 4);
x=(s->gpr[4] & UINT64_C(0xffffffff));y=b;
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481470: STEP(0x481470); /* xor esi, dword ptr [rbp - 0x2b8] */
READ(b, (UINT64_C(0xfffffffffffffd48) + s->gpr[6]), 4);
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = b;
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481476: STEP(0x481476); /* xor esi, dword ptr [rbp - 0x238] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xfffffffffffffdc8) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0xffffffffffffff98) + s->gpr[6]);
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, (s->gpr[4] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x48147f);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xfffffffffffffdc8) + s->gpr[6]), 4);
x=(s->gpr[4] & UINT64_C(0xffffffff));y=b;
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48147c: STEP(0x48147c); /* xor esi, dword ptr [rbp - 0x68] */
READ(b, (UINT64_C(0xffffffffffffff98) + s->gpr[6]), 4);
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = b;
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48147f: STEP(0x48147f); /* xor esi, dword ptr [rbp - 0x168] */
READ(b, (UINT64_C(0xfffffffffffffe98) + s->gpr[6]), 4);
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = b;
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481485: STEP(0x481485); /* xor esi, edx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481487: STEP(0x481487); /* mov edx, dword ptr [rbp - 0xc8] */
READ(a, (UINT64_C(0xffffffffffffff38) + s->gpr[6]), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_48148d: STEP(0x48148d); /* xor edx, dword ptr [rbp - 0x170] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xfffffffffffffe90) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0xfffffffffffffe00) + s->gpr[6]);
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, (s->gpr[3] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x481499);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xfffffffffffffe90) + s->gpr[6]), 4);
x=(s->gpr[3] & UINT64_C(0xffffffff));y=b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481493: STEP(0x481493); /* xor edx, dword ptr [rbp - 0x200] */
READ(b, (UINT64_C(0xfffffffffffffe00) + s->gpr[6]), 4);
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481499: STEP(0x481499); /* xor edx, dword ptr [rbp - 0x210] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xfffffffffffffdf0) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0xfffffffffffffea8) + s->gpr[6]);
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, (s->gpr[3] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x4814a5);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xfffffffffffffdf0) + s->gpr[6]), 4);
x=(s->gpr[3] & UINT64_C(0xffffffff));y=b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48149f: STEP(0x48149f); /* xor edx, dword ptr [rbp - 0x158] */
READ(b, (UINT64_C(0xfffffffffffffea8) + s->gpr[6]), 4);
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4814a5: STEP(0x4814a5); /* xor edx, dword ptr [rbp - 0x50] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xffffffffffffffb0) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0xfffffffffffffdd8) + s->gpr[6]);
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, (s->gpr[3] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x4814ae);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xffffffffffffffb0) + s->gpr[6]), 4);
x=(s->gpr[3] & UINT64_C(0xffffffff));y=b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4814a8: STEP(0x4814a8); /* xor edx, dword ptr [rbp - 0x228] */
READ(b, (UINT64_C(0xfffffffffffffdd8) + s->gpr[6]), 4);
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4814ae: STEP(0x4814ae); /* xor edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4814b0: STEP(0x4814b0); /* mov rsi, qword ptr [rbp - 0x230] */
READ(a, (UINT64_C(0xfffffffffffffdd0) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_4814b7: STEP(0x4814b7); /* mov edi, esi */
s->gpr[5] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4814b9: STEP(0x4814b9); /* xor edi, dword ptr [rbp - 0x260] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xfffffffffffffda0) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0xfffffffffffffe50) + s->gpr[6]);
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, (s->gpr[5] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x4814c5);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xfffffffffffffda0) + s->gpr[6]), 4);
x=(s->gpr[5] & UINT64_C(0xffffffff));y=b;
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4814bf: STEP(0x4814bf); /* xor edi, dword ptr [rbp - 0x1b0] */
READ(b, (UINT64_C(0xfffffffffffffe50) + s->gpr[6]), 4);
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = b;
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4814c5: STEP(0x4814c5); /* xor edi, dword ptr [rbp - 0x198] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xfffffffffffffe68) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0xfffffffffffffe78) + s->gpr[6]);
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, (s->gpr[5] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x4814d1);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xfffffffffffffe68) + s->gpr[6]), 4);
x=(s->gpr[5] & UINT64_C(0xffffffff));y=b;
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4814cb: STEP(0x4814cb); /* xor edi, dword ptr [rbp - 0x188] */
READ(b, (UINT64_C(0xfffffffffffffe78) + s->gpr[6]), 4);
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = b;
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4814d1: STEP(0x4814d1); /* xor edi, dword ptr [rbp - 0x258] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xfffffffffffffda8) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0xfffffffffffffde8) + s->gpr[6]);
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, (s->gpr[5] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x4814dd);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xfffffffffffffda8) + s->gpr[6]), 4);
x=(s->gpr[5] & UINT64_C(0xffffffff));y=b;
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4814d7: STEP(0x4814d7); /* xor edi, dword ptr [rbp - 0x218] */
READ(b, (UINT64_C(0xfffffffffffffde8) + s->gpr[6]), 4);
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = b;
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4814dd: STEP(0x4814dd); /* xor edi, dword ptr [rbp - 0x1a0] */
READ(b, (UINT64_C(0xfffffffffffffe60) + s->gpr[6]), 4);
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = b;
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4814e3: STEP(0x4814e3); /* xor edi, edx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4814e5: STEP(0x4814e5); /* mov esi, dword ptr [rbp - 0x180] */
READ(a, (UINT64_C(0xfffffffffffffe80) + s->gpr[6]), 4);
s->gpr[4] = (uint32_t)(a);
++s->steps;
kg_pc_4814eb: STEP(0x4814eb); /* xor esi, dword ptr [rbp - 0x300] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xfffffffffffffd00) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0xfffffffffffffd40) + s->gpr[6]);
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, (s->gpr[4] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x4814f7);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xfffffffffffffd00) + s->gpr[6]), 4);
x=(s->gpr[4] & UINT64_C(0xffffffff));y=b;
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4814f1: STEP(0x4814f1); /* xor esi, dword ptr [rbp - 0x2c0] */
READ(b, (UINT64_C(0xfffffffffffffd40) + s->gpr[6]), 4);
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = b;
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4814f7: STEP(0x4814f7); /* xor esi, dword ptr [rbp - 0x318] */
READ(b, (UINT64_C(0xfffffffffffffce8) + s->gpr[6]), 4);
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = b;
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4814fd: STEP(0x4814fd); /* xor esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4814ff: STEP(0x4814ff); /* add r11d, 0x70df94 */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = UINT64_C(0x70df94);
s->gpr[11] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481506: STEP(0x481506); /* xor esi, r11d */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[11] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481509: STEP(0x481509); /* xor esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48150b: STEP(0x48150b); /* add eax, 0xf96a8041 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xf96a8041);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481510: STEP(0x481510); /* xor esi, eax */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481512: STEP(0x481512); /* mov eax, esi */
s->gpr[0] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481514: STEP(0x481514); /* xor eax, 0x14d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x14d);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481519: STEP(0x481519); /* mov r10d, esi */
s->gpr[10] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48151c: STEP(0x48151c); /* xor esi, 0x40d83400 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x40d83400);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481522: STEP(0x481522); /* shrd esi, eax, 0xa */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
z = UINT64_C(0xa);
s->gpr[4] = (uint32_t)(shift_double(s, x, y, z, 32));
++s->steps;
kg_pc_481526: STEP(0x481526); /* xor esi, dword ptr [rbp - 0x568] */
READ(b, (UINT64_C(0xfffffffffffffa98) + s->gpr[6]), 4);
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = b;
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48152c: STEP(0x48152c); /* xor esi, 0x4f3ea162 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x4f3ea162);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481532: STEP(0x481532); /* rol esi, 0xa */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xa);
s->gpr[4] = (uint32_t)(operation(s, OP_ROL, x, y, 32));
++s->steps;
kg_pc_481535: STEP(0x481535); /* xor esi, 0xfa85893c */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xfa85893c);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48153b: STEP(0x48153b); /* imul eax, esi, 0x46990ae5 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x46990ae5);
s->gpr[0] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_481541: STEP(0x481541); /* xor eax, 0xcfebafbd */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xcfebafbd);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481546: STEP(0x481546); /* imul edx, esi, 0x8d3215ca */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x8d3215ca);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_48154c: STEP(0x48154c); /* and edx, 0x9fd75f7a */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x9fd75f7a);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481552: STEP(0x481552); /* add edx, eax */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481554: STEP(0x481554); /* mov ecx, dword ptr [rbp - 0xd0] */
READ(a, (UINT64_C(0xffffffffffffff30) + s->gpr[6]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
kg_pc_48155a: STEP(0x48155a); /* mov eax, ecx */
s->gpr[0] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48155c: STEP(0x48155c); /* xor eax, dword ptr [rbp - 0x78] */
READ(b, (UINT64_C(0xffffffffffffff88) + s->gpr[6]), 4);
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = b;
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48155f: STEP(0x48155f); /* mov r11, qword ptr [rbp - 0x40] */
READ(a, (UINT64_C(0xffffffffffffffc0) + s->gpr[6]), 8);
s->gpr[11] = a;
++s->steps;
kg_pc_481563: STEP(0x481563); /* mov ebx, r11d */
s->gpr[1] = (uint32_t)((s->gpr[11] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481566: STEP(0x481566); /* xor ebx, eax */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481568: STEP(0x481568); /* xor eax, dword ptr [rbp - 0xf8] */
READ(b, (UINT64_C(0xffffffffffffff08) + s->gpr[6]), 4);
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = b;
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48156e: STEP(0x48156e); /* add r13d, 0x7e09fde5 */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = UINT64_C(0x7e09fde5);
s->gpr[13] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481575: STEP(0x481575); /* xor r13d, eax */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481578: STEP(0x481578); /* xor r10d, dword ptr [rbp - 0x918] */
READ(b, (UINT64_C(0xfffffffffffff6e8) + s->gpr[6]), 4);
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = b;
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48157f: STEP(0x48157f); /* xor r10d, 0x15215cc4 */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x15215cc4);
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481586: STEP(0x481586); /* mov r12d, dword ptr [rbp - 0x3f8] */
READ(a, (UINT64_C(0xfffffffffffffc08) + s->gpr[6]), 4);
s->gpr[12] = (uint32_t)(a);
++s->steps;
kg_pc_48158d: STEP(0x48158d); /* xor r12d, r10d */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481590: STEP(0x481590); /* xor r12d, r14d */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481593: STEP(0x481593); /* xor r12d, ecx */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481596: STEP(0x481596); /* xor r12d, eax */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481599: STEP(0x481599); /* xor eax, 0x303a738c */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x303a738c);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48159e: STEP(0x48159e); /* add eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4815a0: STEP(0x4815a0); /* add eax, 0x30145043 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x30145043);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4815a5: STEP(0x4815a5); /* mov edx, eax */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4815a7: STEP(0x4815a7); /* xor edx, 0x3ffffbd5 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x3ffffbd5);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4815ad: STEP(0x4815ad); /* add edx, dword ptr [rbp - 0x9c8] */
READ(b, (UINT64_C(0xfffffffffffff638) + s->gpr[6]), 4);
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = b;
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4815b3: STEP(0x4815b3); /* and eax, 0x3ffffbd5 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x3ffffbd5);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4815b8: STEP(0x4815b8); /* lea ecx, [rdx + rax*2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_4815bb: STEP(0x4815bb); /* lea eax, [rcx + rcx] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_4815be: STEP(0x4815be); /* add eax, 0x88112858 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x88112858);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4815c3: STEP(0x4815c3); /* and eax, 0x905fe40a */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x905fe40a);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4815c8: STEP(0x4815c8); /* sub ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_4815ca: STEP(0x4815ca); /* add ecx, 0xc388631 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xc388631);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4815d0: STEP(0x4815d0); /* xor ecx, dword ptr [rbp - 0x398] */
READ(b, (UINT64_C(0xfffffffffffffc68) + s->gpr[6]), 4);
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = b;
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4815d6: STEP(0x4815d6); /* mov eax, ecx */
s->gpr[0] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4815d8: STEP(0x4815d8); /* mov rdx, rcx */
s->gpr[3] = s->gpr[2];
++s->steps;
kg_pc_4815db: STEP(0x4815db); /* mov qword ptr [rbp - 0x3f8], rcx */
WRITE((UINT64_C(0xfffffffffffffc08) + s->gpr[6]), 8, s->gpr[2]);
++s->steps;
kg_pc_4815e2: STEP(0x4815e2); /* shr eax, 0x18 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_4815e5: STEP(0x4815e5); /* lea esi, [rax + rax] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_4815e8: STEP(0x4815e8); /* mov edi, esi */
s->gpr[5] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4815ea: STEP(0x4815ea); /* xor edi, 0x40 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x40);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4815ed: STEP(0x4815ed); /* mov ecx, edi */
s->gpr[2] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4815ef: STEP(0x4815ef); /* and ecx, 0xf4 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xf4);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4815f5: STEP(0x4815f5); /* and esi, 0xa0 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xa0);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4815fb: STEP(0x4815fb); /* xor esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4815fd: STEP(0x4815fd); /* add esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4815ff: STEP(0x4815ff); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481601: STEP(0x481601); /* lea ecx, [rdi + rsi] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_481604: STEP(0x481604); /* add ecx, 0x54 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x54);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481607: STEP(0x481607); /* add eax, 0x97 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x97);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48160c: STEP(0x48160c); /* mov esi, eax */
s->gpr[4] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48160e: STEP(0x48160e); /* xor esi, 0x7dd6d3f9 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x7dd6d3f9);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481614: STEP(0x481614); /* and eax, 0xfffffff9 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffffff9);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481617: STEP(0x481617); /* lea eax, [rsi + rax*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_48161a: STEP(0x48161a); /* and ecx, 0x12e */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x12e);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481620: STEP(0x481620); /* mov esi, ecx */
s->gpr[4] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481622: STEP(0x481622); /* xor esi, 0xd2084005 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xd2084005);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481628: STEP(0x481628); /* add eax, esi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48162a: STEP(0x48162a); /* add ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48162c: STEP(0x48162c); /* xor ecx, 0xfffffff7 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffffff7);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48162f: STEP(0x48162f); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481631: STEP(0x481631); /* add eax, 0xb020ec07 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xb020ec07);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481636: STEP(0x481636); /* mov r9, qword ptr [rbp - 0x2a8] */
READ(a, (UINT64_C(0xfffffffffffffd58) + s->gpr[6]), 8);
s->gpr[9] = a;
++s->steps;
kg_pc_48163d: STEP(0x48163d); /* lea ecx, [r9 - 0x1e5b] */
s->gpr[2] = (uint32_t)((UINT64_C(0xffffffffffffe1a5) + s->gpr[9]));
++s->steps;
kg_pc_481644: STEP(0x481644); /* movsxd rcx, ecx */
s->gpr[2] = (((s->gpr[2] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_481647: STEP(0x481647); /* lea r8, [rip + 0x20e4d2] */
s->gpr[8] = (UINT64_C(0x20e4d2) + (bias + UINT64_C(0x48164e)));
++s->steps;
kg_pc_48164e: STEP(0x48164e); /* mov rcx, qword ptr [r8 + rcx*8] */
READ(a, (UINT64_C(0x0) + s->gpr[8] + (s->gpr[2] * UINT64_C(0x8))), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_481652: STEP(0x481652); /* mov qword ptr [rbp - 0x398], rcx */
WRITE((UINT64_C(0xfffffffffffffc68) + s->gpr[6]), 8, s->gpr[2]);
++s->steps;
kg_pc_481659: STEP(0x481659); /* movzx eax, byte ptr [rcx + rax - 0x346e5502] */
READ(a, (UINT64_C(0xffffffffcb91aafe) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_481661: STEP(0x481661); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481664: STEP(0x481664); /* xor cl, 0xb6 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xb6);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481667: STEP(0x481667); /* lea esi, [rcx + rcx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;

break;
    case 6:
next_pc=bias+UINT64_C(0x481969);
switch(s->pc-bias){
case UINT64_C(0x48166a):goto kg_pc_48166a;
case UINT64_C(0x48166e):goto kg_pc_48166e;
case UINT64_C(0x481671):goto kg_pc_481671;
case UINT64_C(0x481674):goto kg_pc_481674;
case UINT64_C(0x481676):goto kg_pc_481676;
case UINT64_C(0x481679):goto kg_pc_481679;
case UINT64_C(0x481680):goto kg_pc_481680;
case UINT64_C(0x481687):goto kg_pc_481687;
case UINT64_C(0x48168a):goto kg_pc_48168a;
case UINT64_C(0x48168d):goto kg_pc_48168d;
case UINT64_C(0x48168f):goto kg_pc_48168f;
case UINT64_C(0x481694):goto kg_pc_481694;
case UINT64_C(0x48169a):goto kg_pc_48169a;
case UINT64_C(0x4816a0):goto kg_pc_4816a0;
case UINT64_C(0x4816a5):goto kg_pc_4816a5;
case UINT64_C(0x4816a7):goto kg_pc_4816a7;
case UINT64_C(0x4816ad):goto kg_pc_4816ad;
case UINT64_C(0x4816b3):goto kg_pc_4816b3;
case UINT64_C(0x4816b9):goto kg_pc_4816b9;
case UINT64_C(0x4816bb):goto kg_pc_4816bb;
case UINT64_C(0x4816be):goto kg_pc_4816be;
case UINT64_C(0x4816c3):goto kg_pc_4816c3;
case UINT64_C(0x4816c9):goto kg_pc_4816c9;
case UINT64_C(0x4816cf):goto kg_pc_4816cf;
case UINT64_C(0x4816d4):goto kg_pc_4816d4;
case UINT64_C(0x4816d6):goto kg_pc_4816d6;
case UINT64_C(0x4816dc):goto kg_pc_4816dc;
case UINT64_C(0x4816de):goto kg_pc_4816de;
case UINT64_C(0x4816e1):goto kg_pc_4816e1;
case UINT64_C(0x4816e4):goto kg_pc_4816e4;
case UINT64_C(0x4816e9):goto kg_pc_4816e9;
case UINT64_C(0x4816ef):goto kg_pc_4816ef;
case UINT64_C(0x4816f5):goto kg_pc_4816f5;
case UINT64_C(0x4816fc):goto kg_pc_4816fc;
case UINT64_C(0x481702):goto kg_pc_481702;
case UINT64_C(0x481704):goto kg_pc_481704;
case UINT64_C(0x48170a):goto kg_pc_48170a;
case UINT64_C(0x48170f):goto kg_pc_48170f;
case UINT64_C(0x481711):goto kg_pc_481711;
case UINT64_C(0x481716):goto kg_pc_481716;
case UINT64_C(0x481718):goto kg_pc_481718;
case UINT64_C(0x48171e):goto kg_pc_48171e;
case UINT64_C(0x481721):goto kg_pc_481721;
case UINT64_C(0x481727):goto kg_pc_481727;
case UINT64_C(0x48172d):goto kg_pc_48172d;
case UINT64_C(0x481733):goto kg_pc_481733;
case UINT64_C(0x481735):goto kg_pc_481735;
case UINT64_C(0x48173b):goto kg_pc_48173b;
case UINT64_C(0x481741):goto kg_pc_481741;
case UINT64_C(0x481743):goto kg_pc_481743;
case UINT64_C(0x481748):goto kg_pc_481748;
case UINT64_C(0x48174b):goto kg_pc_48174b;
case UINT64_C(0x48174e):goto kg_pc_48174e;
case UINT64_C(0x481754):goto kg_pc_481754;
case UINT64_C(0x48175a):goto kg_pc_48175a;
case UINT64_C(0x48175c):goto kg_pc_48175c;
case UINT64_C(0x481761):goto kg_pc_481761;
case UINT64_C(0x481767):goto kg_pc_481767;
case UINT64_C(0x481769):goto kg_pc_481769;
case UINT64_C(0x48176b):goto kg_pc_48176b;
case UINT64_C(0x481771):goto kg_pc_481771;
case UINT64_C(0x481777):goto kg_pc_481777;
case UINT64_C(0x48177d):goto kg_pc_48177d;
case UINT64_C(0x481783):goto kg_pc_481783;
case UINT64_C(0x481785):goto kg_pc_481785;
case UINT64_C(0x48178b):goto kg_pc_48178b;
case UINT64_C(0x48178e):goto kg_pc_48178e;
case UINT64_C(0x481791):goto kg_pc_481791;
case UINT64_C(0x481794):goto kg_pc_481794;
case UINT64_C(0x48179b):goto kg_pc_48179b;
case UINT64_C(0x48179e):goto kg_pc_48179e;
case UINT64_C(0x4817a1):goto kg_pc_4817a1;
case UINT64_C(0x4817a4):goto kg_pc_4817a4;
case UINT64_C(0x4817a7):goto kg_pc_4817a7;
case UINT64_C(0x4817aa):goto kg_pc_4817aa;
case UINT64_C(0x4817ac):goto kg_pc_4817ac;
case UINT64_C(0x4817af):goto kg_pc_4817af;
case UINT64_C(0x4817b1):goto kg_pc_4817b1;
case UINT64_C(0x4817b4):goto kg_pc_4817b4;
case UINT64_C(0x4817b6):goto kg_pc_4817b6;
case UINT64_C(0x4817b8):goto kg_pc_4817b8;
case UINT64_C(0x4817ba):goto kg_pc_4817ba;
case UINT64_C(0x4817c0):goto kg_pc_4817c0;
case UINT64_C(0x4817c6):goto kg_pc_4817c6;
case UINT64_C(0x4817c9):goto kg_pc_4817c9;
case UINT64_C(0x4817cf):goto kg_pc_4817cf;
case UINT64_C(0x4817d1):goto kg_pc_4817d1;
case UINT64_C(0x4817d3):goto kg_pc_4817d3;
case UINT64_C(0x4817d9):goto kg_pc_4817d9;
case UINT64_C(0x4817e0):goto kg_pc_4817e0;
case UINT64_C(0x4817e7):goto kg_pc_4817e7;
case UINT64_C(0x4817ea):goto kg_pc_4817ea;
case UINT64_C(0x4817ee):goto kg_pc_4817ee;
case UINT64_C(0x4817f6):goto kg_pc_4817f6;
case UINT64_C(0x4817f9):goto kg_pc_4817f9;
case UINT64_C(0x481800):goto kg_pc_481800;
case UINT64_C(0x481807):goto kg_pc_481807;
case UINT64_C(0x48180a):goto kg_pc_48180a;
case UINT64_C(0x48180c):goto kg_pc_48180c;
case UINT64_C(0x48180f):goto kg_pc_48180f;
case UINT64_C(0x481812):goto kg_pc_481812;
case UINT64_C(0x481814):goto kg_pc_481814;
case UINT64_C(0x48181a):goto kg_pc_48181a;
case UINT64_C(0x48181d):goto kg_pc_48181d;
case UINT64_C(0x481820):goto kg_pc_481820;
case UINT64_C(0x481822):goto kg_pc_481822;
case UINT64_C(0x481824):goto kg_pc_481824;
case UINT64_C(0x48182a):goto kg_pc_48182a;
case UINT64_C(0x481830):goto kg_pc_481830;
case UINT64_C(0x481833):goto kg_pc_481833;
case UINT64_C(0x481839):goto kg_pc_481839;
case UINT64_C(0x48183b):goto kg_pc_48183b;
case UINT64_C(0x48183d):goto kg_pc_48183d;
case UINT64_C(0x481843):goto kg_pc_481843;
case UINT64_C(0x48184a):goto kg_pc_48184a;
case UINT64_C(0x481851):goto kg_pc_481851;
case UINT64_C(0x481854):goto kg_pc_481854;
case UINT64_C(0x48185b):goto kg_pc_48185b;
case UINT64_C(0x48185e):goto kg_pc_48185e;
case UINT64_C(0x481862):goto kg_pc_481862;
case UINT64_C(0x48186a):goto kg_pc_48186a;
case UINT64_C(0x48186d):goto kg_pc_48186d;
case UINT64_C(0x481874):goto kg_pc_481874;
case UINT64_C(0x48187b):goto kg_pc_48187b;
case UINT64_C(0x48187e):goto kg_pc_48187e;
case UINT64_C(0x481885):goto kg_pc_481885;
case UINT64_C(0x481889):goto kg_pc_481889;
case UINT64_C(0x48188c):goto kg_pc_48188c;
case UINT64_C(0x481893):goto kg_pc_481893;
case UINT64_C(0x481896):goto kg_pc_481896;
case UINT64_C(0x481899):goto kg_pc_481899;
case UINT64_C(0x48189c):goto kg_pc_48189c;
case UINT64_C(0x48189f):goto kg_pc_48189f;
case UINT64_C(0x4818a2):goto kg_pc_4818a2;
case UINT64_C(0x4818a5):goto kg_pc_4818a5;
case UINT64_C(0x4818a7):goto kg_pc_4818a7;
case UINT64_C(0x4818ad):goto kg_pc_4818ad;
case UINT64_C(0x4818af):goto kg_pc_4818af;
case UINT64_C(0x4818b2):goto kg_pc_4818b2;
case UINT64_C(0x4818b4):goto kg_pc_4818b4;
case UINT64_C(0x4818b6):goto kg_pc_4818b6;
case UINT64_C(0x4818b8):goto kg_pc_4818b8;
case UINT64_C(0x4818be):goto kg_pc_4818be;
case UINT64_C(0x4818c1):goto kg_pc_4818c1;
case UINT64_C(0x4818c4):goto kg_pc_4818c4;
case UINT64_C(0x4818ca):goto kg_pc_4818ca;
case UINT64_C(0x4818cc):goto kg_pc_4818cc;
case UINT64_C(0x4818ce):goto kg_pc_4818ce;
case UINT64_C(0x4818d4):goto kg_pc_4818d4;
case UINT64_C(0x4818db):goto kg_pc_4818db;
case UINT64_C(0x4818e4):goto kg_pc_4818e4;
case UINT64_C(0x4818e6):goto kg_pc_4818e6;
case UINT64_C(0x4818ea):goto kg_pc_4818ea;
case UINT64_C(0x4818ed):goto kg_pc_4818ed;
case UINT64_C(0x4818f1):goto kg_pc_4818f1;
case UINT64_C(0x4818f5):goto kg_pc_4818f5;
case UINT64_C(0x4818f8):goto kg_pc_4818f8;
case UINT64_C(0x4818fa):goto kg_pc_4818fa;
case UINT64_C(0x4818fe):goto kg_pc_4818fe;
case UINT64_C(0x481901):goto kg_pc_481901;
case UINT64_C(0x481904):goto kg_pc_481904;
case UINT64_C(0x481907):goto kg_pc_481907;
case UINT64_C(0x48190a):goto kg_pc_48190a;
case UINT64_C(0x48190e):goto kg_pc_48190e;
case UINT64_C(0x481911):goto kg_pc_481911;
case UINT64_C(0x481915):goto kg_pc_481915;
case UINT64_C(0x481918):goto kg_pc_481918;
case UINT64_C(0x48191c):goto kg_pc_48191c;
case UINT64_C(0x48191e):goto kg_pc_48191e;
case UINT64_C(0x481921):goto kg_pc_481921;
case UINT64_C(0x481924):goto kg_pc_481924;
case UINT64_C(0x481927):goto kg_pc_481927;
case UINT64_C(0x48192a):goto kg_pc_48192a;
case UINT64_C(0x48192d):goto kg_pc_48192d;
case UINT64_C(0x48192f):goto kg_pc_48192f;
case UINT64_C(0x481931):goto kg_pc_481931;
case UINT64_C(0x481938):goto kg_pc_481938;
case UINT64_C(0x48193f):goto kg_pc_48193f;
case UINT64_C(0x481942):goto kg_pc_481942;
case UINT64_C(0x481945):goto kg_pc_481945;
case UINT64_C(0x481948):goto kg_pc_481948;
case UINT64_C(0x48194b):goto kg_pc_48194b;
case UINT64_C(0x481952):goto kg_pc_481952;
case UINT64_C(0x481958):goto kg_pc_481958;
case UINT64_C(0x48195a):goto kg_pc_48195a;
case UINT64_C(0x48195e):goto kg_pc_48195e;
case UINT64_C(0x481967):goto kg_pc_481967;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5245: [0x48166a,0x481969), 187 instructions. */
kg_pc_48166a: STEP(0x48166a); /* and sil, 0xb4 */
x = (s->gpr[4] & UINT64_C(0xff)); y = UINT64_C(0xb4);
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48166e: STEP(0x48166e); /* sub cl, sil */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[4] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481671: STEP(0x481671); /* add cl, 0x5b */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x5b);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481674: STEP(0x481674); /* xor cl, al */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481676: STEP(0x481676); /* xor cl, 0xb1 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xb1);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481679: STEP(0x481679); /* mov rax, qword ptr [rbp - 0xe10] */
READ(a, (UINT64_C(0xfffffffffffff1f0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_481680: STEP(0x481680); /* mov rsi, qword ptr [rbp - 0x478] */
READ(a, (UINT64_C(0xfffffffffffffb88) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_481687: STEP(0x481687); /* mov byte ptr [rax + rsi], cl */
WRITE((UINT64_C(0x0) + s->gpr[0] + (s->gpr[4] * UINT64_C(0x1))), 1, (s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_48168a: STEP(0x48168a); /* mov rdi, r11 */
s->gpr[5] = s->gpr[11];
++s->steps;
kg_pc_48168d: STEP(0x48168d); /* mov eax, edi */
s->gpr[0] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48168f: STEP(0x48168f); /* xor eax, 0x25bab7ca */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x25bab7ca);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481694: STEP(0x481694); /* imul ecx, eax, 0xb8f98243 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xb8f98243);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_48169a: STEP(0x48169a); /* imul eax, eax, 0x71f30486 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x71f30486);
s->gpr[0] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_4816a0: STEP(0x4816a0); /* and eax, 0xffadb4e4 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xffadb4e4);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4816a5: STEP(0x4816a5); /* sub ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_4816a7: STEP(0x4816a7); /* add ecx, 0x7fd6da72 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x7fd6da72);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4816ad: STEP(0x4816ad); /* xor ecx, dword ptr [rbp - 0x310] */
READ(b, (UINT64_C(0xfffffffffffffcf0) + s->gpr[6]), 4);
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = b;
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4816b3: STEP(0x4816b3); /* mov eax, dword ptr [rbp - 0x270] */
READ(a, (UINT64_C(0xfffffffffffffd90) + s->gpr[6]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_4816b9: STEP(0x4816b9); /* xor ebx, eax */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4816bb: STEP(0x4816bb); /* xor eax, r15d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[15] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4816be: STEP(0x4816be); /* xor eax, 0x6b779546 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x6b779546);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4816c3: STEP(0x4816c3); /* imul esi, eax, 0xb8f98243 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xb8f98243);
s->gpr[4] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_4816c9: STEP(0x4816c9); /* imul eax, eax, 0x71f30486 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x71f30486);
s->gpr[0] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_4816cf: STEP(0x4816cf); /* and eax, 0xcebd0b32 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xcebd0b32);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4816d4: STEP(0x4816d4); /* sub esi, eax */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_4816d6: STEP(0x4816d6); /* add esi, 0x675e8599 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x675e8599);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4816dc: STEP(0x4816dc); /* xor esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4816de: STEP(0x4816de); /* xor r14d, edi */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[14] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4816e1: STEP(0x4816e1); /* mov eax, r14d */
s->gpr[0] = (uint32_t)((s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4816e4: STEP(0x4816e4); /* xor eax, 0x54045c15 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x54045c15);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4816e9: STEP(0x4816e9); /* imul ecx, eax, 0x908590e2 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x908590e2);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_4816ef: STEP(0x4816ef); /* and ecx, 0xfeeb6ed6 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xfeeb6ed6);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4816f5: STEP(0x4816f5); /* mov rdi, qword ptr [rbp - 0x98] */
READ(a, (UINT64_C(0xffffffffffffff68) + s->gpr[6]), 8);
s->gpr[5] = a;
++s->steps;
kg_pc_4816fc: STEP(0x4816fc); /* xor edi, 0x303a738c */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x303a738c);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481702: STEP(0x481702); /* add edi, ecx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481704: STEP(0x481704); /* imul eax, eax, 0x4842c871 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x4842c871);
s->gpr[0] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_48170a: STEP(0x48170a); /* xor eax, 0x7f75b76b */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x7f75b76b);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48170f: STEP(0x48170f); /* add eax, edi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481711: STEP(0x481711); /* add eax, 0x808a4895 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x808a4895);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481716: STEP(0x481716); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481718: STEP(0x481718); /* xor ecx, 0x59f6fbb8 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x59f6fbb8);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48171e: STEP(0x48171e); /* xor r13d, esi */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481721: STEP(0x481721); /* xor esi, 0x2412172 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x2412172);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481727: STEP(0x481727); /* imul edi, esi, 0x6f7a6f1e */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x6f7a6f1e);
s->gpr[5] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_48172d: STEP(0x48172d); /* and edi, 0xbefbef70 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xbefbef70);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481733: STEP(0x481733); /* add edi, ecx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481735: STEP(0x481735); /* imul ecx, esi, 0xb7bd378f */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xb7bd378f);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_48173b: STEP(0x48173b); /* xor ecx, 0xdf7df7b8 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xdf7df7b8);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481741: STEP(0x481741); /* add edi, ecx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481743: STEP(0x481743); /* and eax, 0xd9f6fbb8 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xd9f6fbb8);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481748: STEP(0x481748); /* lea eax, [rdi + rax*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_48174b: STEP(0x48174b); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_48174e: STEP(0x48174e); /* add ecx, 0x8d161920 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x8d161920);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481754: STEP(0x481754); /* and ecx, 0xf13cb90e */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xf13cb90e);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48175a: STEP(0x48175a); /* sub eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_48175c: STEP(0x48175c); /* add eax, 0x3f296917 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x3f296917);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481761: STEP(0x481761); /* xor eax, dword ptr [rbp - 0xf8] */
READ(b, (UINT64_C(0xffffffffffffff08) + s->gpr[6]), 4);
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = b;
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481767: STEP(0x481767); /* xor ebx, eax */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481769: STEP(0x481769); /* mov ecx, ebx */
s->gpr[2] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48176b: STEP(0x48176b); /* xor ecx, 0x77d7e658 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x77d7e658);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481771: STEP(0x481771); /* imul esi, ecx, 0x63f3deb */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x63f3deb);
s->gpr[4] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_481777: STEP(0x481777); /* imul ecx, ecx, 0xc7e7bd6 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xc7e7bd6);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_48177d: STEP(0x48177d); /* and ecx, 0x8c499656 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x8c499656);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481783: STEP(0x481783); /* sub esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_481785: STEP(0x481785); /* add esi, 0x4624cb2b */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x4624cb2b);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48178b: STEP(0x48178b); /* xor r13d, esi */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48178e: STEP(0x48178e); /* xor eax, r14d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481791: STEP(0x481791); /* xor eax, r13d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[13] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481794: STEP(0x481794); /* mov r14, qword ptr [rbp - 0x4d8] */
READ(a, (UINT64_C(0xfffffffffffffb28) + s->gpr[6]), 8);
s->gpr[14] = a;
++s->steps;
kg_pc_48179b: STEP(0x48179b); /* xor r14d, r10d */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[14] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48179e: STEP(0x48179e); /* xor r14d, eax */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[14] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4817a1: STEP(0x4817a1); /* mov ecx, r14d */
s->gpr[2] = (uint32_t)((s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4817a4: STEP(0x4817a4); /* shr ecx, 0x10 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[2] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_4817a7: STEP(0x4817a7); /* movzx ecx, cl */
s->gpr[2] = (uint32_t)((s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_4817aa: STEP(0x4817aa); /* mov esi, ecx */
s->gpr[4] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4817ac: STEP(0x4817ac); /* xor esi, 0x29 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x29);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4817af: STEP(0x4817af); /* mov edi, esi */
s->gpr[5] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4817b1: STEP(0x4817b1); /* and edi, 0x74 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x74);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4817b4: STEP(0x4817b4); /* add edi, edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4817b6: STEP(0x4817b6); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4817b8: STEP(0x4817b8); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4817ba: STEP(0x4817ba); /* add esi, 0x10e3be74 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x10e3be74);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4817c0: STEP(0x4817c0); /* xor esi, 0x6df62764 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x6df62764);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4817c6: STEP(0x4817c6); /* lea edi, [rsi + rsi] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_4817c9: STEP(0x4817c9); /* and edi, 0x7a2b3222 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x7a2b3222);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4817cf: STEP(0x4817cf); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4817d1: STEP(0x4817d1); /* add edi, esi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4817d3: STEP(0x4817d3); /* add edi, 0x3d5f9d11 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x3d5f9d11);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4817d9: STEP(0x4817d9); /* xor rdi, 0x404a04d0 */
x = s->gpr[5]; y = UINT64_C(0x404a04d0);
s->gpr[5] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_4817e0: STEP(0x4817e0); /* lea esi, [r9 - 0x1ddd] */
s->gpr[4] = (uint32_t)((UINT64_C(0xffffffffffffe223) + s->gpr[9]));
++s->steps;
kg_pc_4817e7: STEP(0x4817e7); /* movsxd rsi, esi */
s->gpr[4] = (((s->gpr[4] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4817ea: STEP(0x4817ea); /* mov r11, qword ptr [r8 + rsi*8] */
READ(a, (UINT64_C(0x0) + s->gpr[8] + (s->gpr[4] * UINT64_C(0x8))), 8);
s->gpr[11] = a;
++s->steps;
kg_pc_4817ee: STEP(0x4817ee); /* xor cl, byte ptr [r11 + rdi - 0x55ad0efe] */
READ(b, (UINT64_C(0xffffffffaa52f102) + s->gpr[11] + (s->gpr[5] * UINT64_C(0x1))), 1);
x = (s->gpr[2] & UINT64_C(0xff)); y = b;
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4817f6: STEP(0x4817f6); /* xor cl, 0x47 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x47);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4817f9: STEP(0x4817f9); /* mov rdi, qword ptr [rbp - 0xe10] */
READ(a, (UINT64_C(0xfffffffffffff1f0) + s->gpr[6]), 8);
s->gpr[5] = a;
++s->steps;
kg_pc_481800: STEP(0x481800); /* mov rsi, qword ptr [rbp - 0x4e0] */
READ(a, (UINT64_C(0xfffffffffffffb20) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_481807: STEP(0x481807); /* mov byte ptr [rdi + rsi], cl */
WRITE((UINT64_C(0x0) + s->gpr[5] + (s->gpr[4] * UINT64_C(0x1))), 1, (s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_48180a: STEP(0x48180a); /* mov ecx, edx */
s->gpr[2] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48180c: STEP(0x48180c); /* shr ecx, 0x10 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[2] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_48180f: STEP(0x48180f); /* movzx ecx, cl */
s->gpr[2] = (uint32_t)((s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_481812: STEP(0x481812); /* mov edi, ecx */
s->gpr[5] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481814: STEP(0x481814); /* xor edi, 0xf3 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xf3);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48181a: STEP(0x48181a); /* lea esi, [rdi + rdi] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_48181d: STEP(0x48181d); /* and esi, 0x7c */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x7c);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481820: STEP(0x481820); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481822: STEP(0x481822); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481824: STEP(0x481824); /* add esi, 0x361e593e */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x361e593e);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48182a: STEP(0x48182a); /* xor esi, 0x1e267b3a */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x1e267b3a);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481830: STEP(0x481830); /* lea edi, [rsi + rsi] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_481833: STEP(0x481833); /* and edi, 0x105011be */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x105011be);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481839: STEP(0x481839); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_48183b: STEP(0x48183b); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48183d: STEP(0x48183d); /* add esi, 0x48ed58df */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x48ed58df);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481843: STEP(0x481843); /* xor rsi, 0x60d57a3a */
x = s->gpr[4]; y = UINT64_C(0x60d57a3a);
s->gpr[4] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_48184a: STEP(0x48184a); /* lea edi, [r9 - 0x1ea9] */
s->gpr[5] = (uint32_t)((UINT64_C(0xffffffffffffe157) + s->gpr[9]));
++s->steps;
kg_pc_481851: STEP(0x481851); /* mov rdx, r9 */
s->gpr[3] = s->gpr[9];
++s->steps;
kg_pc_481854: STEP(0x481854); /* mov qword ptr [rbp - 0x2a8], r9 */
WRITE((UINT64_C(0xfffffffffffffd58) + s->gpr[6]), 8, s->gpr[9]);
++s->steps;
kg_pc_48185b: STEP(0x48185b); /* movsxd rdi, edi */
s->gpr[5] = (((s->gpr[5] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48185e: STEP(0x48185e); /* mov r9, qword ptr [r8 + rdi*8] */
READ(a, (UINT64_C(0x0) + s->gpr[8] + (s->gpr[5] * UINT64_C(0x8))), 8);
s->gpr[9] = a;
++s->steps;
kg_pc_481862: STEP(0x481862); /* xor cl, byte ptr [r9 + rsi - 0x56b53732] */
READ(b, (UINT64_C(0xffffffffa94ac8ce) + s->gpr[9] + (s->gpr[4] * UINT64_C(0x1))), 1);
x = (s->gpr[2] & UINT64_C(0xff)); y = b;
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48186a: STEP(0x48186a); /* xor cl, 0xbe */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xbe);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48186d: STEP(0x48186d); /* mov rsi, qword ptr [rbp - 0xe10] */
READ(a, (UINT64_C(0xfffffffffffff1f0) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_481874: STEP(0x481874); /* mov rdi, qword ptr [rbp - 0x460] */
READ(a, (UINT64_C(0xfffffffffffffba0) + s->gpr[6]), 8);
s->gpr[5] = a;
++s->steps;
kg_pc_48187b: STEP(0x48187b); /* mov byte ptr [rsi + rdi], cl */
WRITE((UINT64_C(0x0) + s->gpr[4] + (s->gpr[5] * UINT64_C(0x1))), 1, (s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_48187e: STEP(0x48187e); /* xor r10d, dword ptr [rbp - 0x420] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xfffffffffffffbe0) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0xffffffffffffff88) + s->gpr[6]);
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, (s->gpr[10] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x481889);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xfffffffffffffbe0) + s->gpr[6]), 4);
x=(s->gpr[10] & UINT64_C(0xffffffff));y=b;
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481885: STEP(0x481885); /* xor r10d, dword ptr [rbp - 0x78] */
READ(b, (UINT64_C(0xffffffffffffff88) + s->gpr[6]), 4);
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = b;
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481889: STEP(0x481889); /* xor r10d, ebx */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48188c: STEP(0x48188c); /* xor r15d, dword ptr [rbp - 0xd0] */
READ(b, (UINT64_C(0xffffffffffffff30) + s->gpr[6]), 4);
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = b;
s->gpr[15] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481893: STEP(0x481893); /* xor r15d, r13d */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = (s->gpr[13] & UINT64_C(0xffffffff));
s->gpr[15] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481896: STEP(0x481896); /* xor r10d, eax */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481899: STEP(0x481899); /* xor r10d, r15d */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = (s->gpr[15] & UINT64_C(0xffffffff));
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48189c: STEP(0x48189c); /* mov eax, r10d */
s->gpr[0] = (uint32_t)((s->gpr[10] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48189f: STEP(0x48189f); /* shr eax, 8 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_4818a2: STEP(0x4818a2); /* movzx eax, al */
s->gpr[0] = (uint32_t)((s->gpr[0] & UINT64_C(0xff)));
++s->steps;
kg_pc_4818a5: STEP(0x4818a5); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4818a7: STEP(0x4818a7); /* xor ecx, 0xc1 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xc1);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4818ad: STEP(0x4818ad); /* mov esi, ecx */
s->gpr[4] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4818af: STEP(0x4818af); /* and esi, 0x58 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x58);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4818b2: STEP(0x4818b2); /* add esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4818b4: STEP(0x4818b4); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4818b6: STEP(0x4818b6); /* add ecx, esi */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4818b8: STEP(0x4818b8); /* add ecx, 0x158 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x158);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4818be: STEP(0x4818be); /* xor ecx, 0x60 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x60);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4818c1: STEP(0x4818c1); /* lea esi, [rcx + rcx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_4818c4: STEP(0x4818c4); /* and esi, 0x334ea3d0 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x334ea3d0);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4818ca: STEP(0x4818ca); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4818cc: STEP(0x4818cc); /* add ecx, esi */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4818ce: STEP(0x4818ce); /* add ecx, 0x19a751e8 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x19a751e8);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4818d4: STEP(0x4818d4); /* xor rcx, 0x19a750c5 */
x = s->gpr[2]; y = UINT64_C(0x19a750c5);
s->gpr[2] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_4818db: STEP(0x4818db); /* movzx ecx, byte ptr [r11 + rcx - 0x55ad0efe] */
READ(a, (UINT64_C(0xffffffffaa52f102) + s->gpr[11] + (s->gpr[2] * UINT64_C(0x1))), 1);
s->gpr[2] = (uint32_t)(a);
++s->steps;
kg_pc_4818e4: STEP(0x4818e4); /* mov edi, ecx */
s->gpr[5] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4818e6: STEP(0x4818e6); /* xor dil, 0x98 */
x = (s->gpr[5] & UINT64_C(0xff)); y = UINT64_C(0x98);
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4818ea: STEP(0x4818ea); /* lea esi, [rdi + rdi] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_4818ed: STEP(0x4818ed); /* add sil, 0xb0 */
x = (s->gpr[4] & UINT64_C(0xff)); y = UINT64_C(0xb0);
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4818f1: STEP(0x4818f1); /* and sil, 0x88 */
x = (s->gpr[4] & UINT64_C(0xff)); y = UINT64_C(0x88);
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4818f5: STEP(0x4818f5); /* sub dil, sil */
x = (s->gpr[5] & UINT64_C(0xff)); y = (s->gpr[4] & UINT64_C(0xff));
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4818f8: STEP(0x4818f8); /* mov esi, ecx */
s->gpr[4] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4818fa: STEP(0x4818fa); /* xor sil, 0xcf */
x = (s->gpr[4] & UINT64_C(0xff)); y = UINT64_C(0xcf);
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4818fe: STEP(0x4818fe); /* lea ebx, [rsi + rsi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_481901: STEP(0x481901); /* add bl, 2 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x2);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481904: STEP(0x481904); /* and bl, 0xda */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0xda);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481907: STEP(0x481907); /* sub sil, bl */
x = (s->gpr[4] & UINT64_C(0xff)); y = (s->gpr[1] & UINT64_C(0xff));
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48190a: STEP(0x48190a); /* add sil, 0x6e */
x = (s->gpr[4] & UINT64_C(0xff)); y = UINT64_C(0x6e);
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48190e: STEP(0x48190e); /* xor sil, cl */
x = (s->gpr[4] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481911: STEP(0x481911); /* add dil, 0x9c */
x = (s->gpr[5] & UINT64_C(0xff)); y = UINT64_C(0x9c);
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481915: STEP(0x481915); /* xor sil, dil */
x = (s->gpr[4] & UINT64_C(0xff)); y = (s->gpr[5] & UINT64_C(0xff));
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481918: STEP(0x481918); /* xor sil, 0x19 */
x = (s->gpr[4] & UINT64_C(0xff)); y = UINT64_C(0x19);
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48191c: STEP(0x48191c); /* mov cl, 0x50 */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((UINT64_C(0x50)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48191e: STEP(0x48191e); /* lea edi, [rsi + rsi] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_481921: STEP(0x481921); /* sub cl, dil */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[5] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481924: STEP(0x481924); /* or cl, 0x71 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x71);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_OR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481927: STEP(0x481927); /* add cl, sil */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[4] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48192a: STEP(0x48192a); /* add cl, 0x9f */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x9f);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48192d: STEP(0x48192d); /* xor al, cl */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48192f: STEP(0x48192f); /* xor al, 0x19 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x19);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481931: STEP(0x481931); /* mov rcx, qword ptr [rbp - 0xe10] */
READ(a, (UINT64_C(0xfffffffffffff1f0) + s->gpr[6]), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_481938: STEP(0x481938); /* mov rsi, qword ptr [rbp - 0x418] */
READ(a, (UINT64_C(0xfffffffffffffbe8) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_48193f: STEP(0x48193f); /* mov byte ptr [rcx + rsi], al */
WRITE((UINT64_C(0x0) + s->gpr[2] + (s->gpr[4] * UINT64_C(0x1))), 1, (s->gpr[0] & UINT64_C(0xff)));
++s->steps;
kg_pc_481942: STEP(0x481942); /* xor r12d, r15d */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[15] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481945: STEP(0x481945); /* mov ecx, r12d */
s->gpr[2] = (uint32_t)((s->gpr[12] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481948: STEP(0x481948); /* shr ecx, 0x18 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[2] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_48194b: STEP(0x48194b); /* xor rcx, 0xd8 */
x = s->gpr[2]; y = UINT64_C(0xd8);
s->gpr[2] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_481952: STEP(0x481952); /* lea eax, [rdx - 0x1f2b] */
s->gpr[0] = (uint32_t)((UINT64_C(0xffffffffffffe0d5) + s->gpr[3]));
++s->steps;
kg_pc_481958: STEP(0x481958); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_48195a: STEP(0x48195a); /* mov r8, qword ptr [r8 + rax*8] */
READ(a, (UINT64_C(0x0) + s->gpr[8] + (s->gpr[0] * UINT64_C(0x8))), 8);
s->gpr[8] = a;
++s->steps;
kg_pc_48195e: STEP(0x48195e); /* movzx ebx, byte ptr [r8 + rcx - 0x3a80b032] */
READ(a, (UINT64_C(0xffffffffc57f4fce) + s->gpr[8] + (s->gpr[2] * UINT64_C(0x1))), 1);
s->gpr[1] = (uint32_t)(a);
++s->steps;
kg_pc_481967: STEP(0x481967); /* mov edi, ebx */
s->gpr[5] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;

break;
    case 7:
next_pc=bias+UINT64_C(0x481c53);
switch(s->pc-bias){
case UINT64_C(0x481969):goto kg_pc_481969;
case UINT64_C(0x48196d):goto kg_pc_48196d;
case UINT64_C(0x481971):goto kg_pc_481971;
case UINT64_C(0x481974):goto kg_pc_481974;
case UINT64_C(0x481977):goto kg_pc_481977;
case UINT64_C(0x48197a):goto kg_pc_48197a;
case UINT64_C(0x48197e):goto kg_pc_48197e;
case UINT64_C(0x481981):goto kg_pc_481981;
case UINT64_C(0x481985):goto kg_pc_481985;
case UINT64_C(0x48198c):goto kg_pc_48198c;
case UINT64_C(0x481993):goto kg_pc_481993;
case UINT64_C(0x481997):goto kg_pc_481997;
case UINT64_C(0x48199a):goto kg_pc_48199a;
case UINT64_C(0x48199d):goto kg_pc_48199d;
case UINT64_C(0x4819a0):goto kg_pc_4819a0;
case UINT64_C(0x4819a2):goto kg_pc_4819a2;
case UINT64_C(0x4819a8):goto kg_pc_4819a8;
case UINT64_C(0x4819aa):goto kg_pc_4819aa;
case UINT64_C(0x4819ad):goto kg_pc_4819ad;
case UINT64_C(0x4819af):goto kg_pc_4819af;
case UINT64_C(0x4819b1):goto kg_pc_4819b1;
case UINT64_C(0x4819b3):goto kg_pc_4819b3;
case UINT64_C(0x4819b9):goto kg_pc_4819b9;
case UINT64_C(0x4819bf):goto kg_pc_4819bf;
case UINT64_C(0x4819c2):goto kg_pc_4819c2;
case UINT64_C(0x4819c8):goto kg_pc_4819c8;
case UINT64_C(0x4819ca):goto kg_pc_4819ca;
case UINT64_C(0x4819cc):goto kg_pc_4819cc;
case UINT64_C(0x4819d2):goto kg_pc_4819d2;
case UINT64_C(0x4819d4):goto kg_pc_4819d4;
case UINT64_C(0x4819d6):goto kg_pc_4819d6;
case UINT64_C(0x4819dc):goto kg_pc_4819dc;
case UINT64_C(0x4819df):goto kg_pc_4819df;
case UINT64_C(0x4819e2):goto kg_pc_4819e2;
case UINT64_C(0x4819e4):goto kg_pc_4819e4;
case UINT64_C(0x4819e6):goto kg_pc_4819e6;
case UINT64_C(0x4819e8):goto kg_pc_4819e8;
case UINT64_C(0x4819ea):goto kg_pc_4819ea;
case UINT64_C(0x4819f0):goto kg_pc_4819f0;
case UINT64_C(0x4819f6):goto kg_pc_4819f6;
case UINT64_C(0x4819f9):goto kg_pc_4819f9;
case UINT64_C(0x4819fb):goto kg_pc_4819fb;
case UINT64_C(0x481a01):goto kg_pc_481a01;
case UINT64_C(0x481a07):goto kg_pc_481a07;
case UINT64_C(0x481a0a):goto kg_pc_481a0a;
case UINT64_C(0x481a10):goto kg_pc_481a10;
case UINT64_C(0x481a16):goto kg_pc_481a16;
case UINT64_C(0x481a18):goto kg_pc_481a18;
case UINT64_C(0x481a1a):goto kg_pc_481a1a;
case UINT64_C(0x481a1f):goto kg_pc_481a1f;
case UINT64_C(0x481a24):goto kg_pc_481a24;
case UINT64_C(0x481a29):goto kg_pc_481a29;
case UINT64_C(0x481a2b):goto kg_pc_481a2b;
case UINT64_C(0x481a30):goto kg_pc_481a30;
case UINT64_C(0x481a38):goto kg_pc_481a38;
case UINT64_C(0x481a3b):goto kg_pc_481a3b;
case UINT64_C(0x481a42):goto kg_pc_481a42;
case UINT64_C(0x481a49):goto kg_pc_481a49;
case UINT64_C(0x481a4c):goto kg_pc_481a4c;
case UINT64_C(0x481a50):goto kg_pc_481a50;
case UINT64_C(0x481a53):goto kg_pc_481a53;
case UINT64_C(0x481a55):goto kg_pc_481a55;
case UINT64_C(0x481a58):goto kg_pc_481a58;
case UINT64_C(0x481a5a):goto kg_pc_481a5a;
case UINT64_C(0x481a5c):goto kg_pc_481a5c;
case UINT64_C(0x481a5e):goto kg_pc_481a5e;
case UINT64_C(0x481a63):goto kg_pc_481a63;
case UINT64_C(0x481a68):goto kg_pc_481a68;
case UINT64_C(0x481a6b):goto kg_pc_481a6b;
case UINT64_C(0x481a71):goto kg_pc_481a71;
case UINT64_C(0x481a73):goto kg_pc_481a73;
case UINT64_C(0x481a75):goto kg_pc_481a75;
case UINT64_C(0x481a7a):goto kg_pc_481a7a;
case UINT64_C(0x481a80):goto kg_pc_481a80;
case UINT64_C(0x481a87):goto kg_pc_481a87;
case UINT64_C(0x481a8f):goto kg_pc_481a8f;
case UINT64_C(0x481a92):goto kg_pc_481a92;
case UINT64_C(0x481a95):goto kg_pc_481a95;
case UINT64_C(0x481a9c):goto kg_pc_481a9c;
case UINT64_C(0x481aa0):goto kg_pc_481aa0;
case UINT64_C(0x481aa3):goto kg_pc_481aa3;
case UINT64_C(0x481aa6):goto kg_pc_481aa6;
case UINT64_C(0x481aa8):goto kg_pc_481aa8;
case UINT64_C(0x481aab):goto kg_pc_481aab;
case UINT64_C(0x481ab2):goto kg_pc_481ab2;
case UINT64_C(0x481ab9):goto kg_pc_481ab9;
case UINT64_C(0x481abc):goto kg_pc_481abc;
case UINT64_C(0x481ac3):goto kg_pc_481ac3;
case UINT64_C(0x481ac6):goto kg_pc_481ac6;
case UINT64_C(0x481acb):goto kg_pc_481acb;
case UINT64_C(0x481acd):goto kg_pc_481acd;
case UINT64_C(0x481ad0):goto kg_pc_481ad0;
case UINT64_C(0x481ad2):goto kg_pc_481ad2;
case UINT64_C(0x481ad4):goto kg_pc_481ad4;
case UINT64_C(0x481ad6):goto kg_pc_481ad6;
case UINT64_C(0x481adb):goto kg_pc_481adb;
case UINT64_C(0x481ae0):goto kg_pc_481ae0;
case UINT64_C(0x481ae3):goto kg_pc_481ae3;
case UINT64_C(0x481ae9):goto kg_pc_481ae9;
case UINT64_C(0x481aeb):goto kg_pc_481aeb;
case UINT64_C(0x481aed):goto kg_pc_481aed;
case UINT64_C(0x481af2):goto kg_pc_481af2;
case UINT64_C(0x481af8):goto kg_pc_481af8;
case UINT64_C(0x481b00):goto kg_pc_481b00;
case UINT64_C(0x481b03):goto kg_pc_481b03;
case UINT64_C(0x481b06):goto kg_pc_481b06;
case UINT64_C(0x481b0d):goto kg_pc_481b0d;
case UINT64_C(0x481b11):goto kg_pc_481b11;
case UINT64_C(0x481b14):goto kg_pc_481b14;
case UINT64_C(0x481b17):goto kg_pc_481b17;
case UINT64_C(0x481b19):goto kg_pc_481b19;
case UINT64_C(0x481b1c):goto kg_pc_481b1c;
case UINT64_C(0x481b23):goto kg_pc_481b23;
case UINT64_C(0x481b2a):goto kg_pc_481b2a;
case UINT64_C(0x481b2d):goto kg_pc_481b2d;
case UINT64_C(0x481b30):goto kg_pc_481b30;
case UINT64_C(0x481b33):goto kg_pc_481b33;
case UINT64_C(0x481b36):goto kg_pc_481b36;
case UINT64_C(0x481b3b):goto kg_pc_481b3b;
case UINT64_C(0x481b3e):goto kg_pc_481b3e;
case UINT64_C(0x481b44):goto kg_pc_481b44;
case UINT64_C(0x481b46):goto kg_pc_481b46;
case UINT64_C(0x481b48):goto kg_pc_481b48;
case UINT64_C(0x481b4d):goto kg_pc_481b4d;
case UINT64_C(0x481b52):goto kg_pc_481b52;
case UINT64_C(0x481b55):goto kg_pc_481b55;
case UINT64_C(0x481b5b):goto kg_pc_481b5b;
case UINT64_C(0x481b5d):goto kg_pc_481b5d;
case UINT64_C(0x481b5f):goto kg_pc_481b5f;
case UINT64_C(0x481b64):goto kg_pc_481b64;
case UINT64_C(0x481b6a):goto kg_pc_481b6a;
case UINT64_C(0x481b73):goto kg_pc_481b73;
case UINT64_C(0x481b75):goto kg_pc_481b75;
case UINT64_C(0x481b78):goto kg_pc_481b78;
case UINT64_C(0x481b7b):goto kg_pc_481b7b;
case UINT64_C(0x481b7d):goto kg_pc_481b7d;
case UINT64_C(0x481b80):goto kg_pc_481b80;
case UINT64_C(0x481b82):goto kg_pc_481b82;
case UINT64_C(0x481b84):goto kg_pc_481b84;
case UINT64_C(0x481b86):goto kg_pc_481b86;
case UINT64_C(0x481b88):goto kg_pc_481b88;
case UINT64_C(0x481b8a):goto kg_pc_481b8a;
case UINT64_C(0x481b91):goto kg_pc_481b91;
case UINT64_C(0x481b98):goto kg_pc_481b98;
case UINT64_C(0x481b9b):goto kg_pc_481b9b;
case UINT64_C(0x481b9e):goto kg_pc_481b9e;
case UINT64_C(0x481ba3):goto kg_pc_481ba3;
case UINT64_C(0x481ba6):goto kg_pc_481ba6;
case UINT64_C(0x481ba9):goto kg_pc_481ba9;
case UINT64_C(0x481bab):goto kg_pc_481bab;
case UINT64_C(0x481bad):goto kg_pc_481bad;
case UINT64_C(0x481bb2):goto kg_pc_481bb2;
case UINT64_C(0x481bb7):goto kg_pc_481bb7;
case UINT64_C(0x481bba):goto kg_pc_481bba;
case UINT64_C(0x481bc0):goto kg_pc_481bc0;
case UINT64_C(0x481bc2):goto kg_pc_481bc2;
case UINT64_C(0x481bc4):goto kg_pc_481bc4;
case UINT64_C(0x481bc9):goto kg_pc_481bc9;
case UINT64_C(0x481bcf):goto kg_pc_481bcf;
case UINT64_C(0x481bd8):goto kg_pc_481bd8;
case UINT64_C(0x481bda):goto kg_pc_481bda;
case UINT64_C(0x481bdd):goto kg_pc_481bdd;
case UINT64_C(0x481be0):goto kg_pc_481be0;
case UINT64_C(0x481be3):goto kg_pc_481be3;
case UINT64_C(0x481be6):goto kg_pc_481be6;
case UINT64_C(0x481be8):goto kg_pc_481be8;
case UINT64_C(0x481beb):goto kg_pc_481beb;
case UINT64_C(0x481bed):goto kg_pc_481bed;
case UINT64_C(0x481bf0):goto kg_pc_481bf0;
case UINT64_C(0x481bf7):goto kg_pc_481bf7;
case UINT64_C(0x481bfe):goto kg_pc_481bfe;
case UINT64_C(0x481c01):goto kg_pc_481c01;
case UINT64_C(0x481c04):goto kg_pc_481c04;
case UINT64_C(0x481c07):goto kg_pc_481c07;
case UINT64_C(0x481c0a):goto kg_pc_481c0a;
case UINT64_C(0x481c0f):goto kg_pc_481c0f;
case UINT64_C(0x481c12):goto kg_pc_481c12;
case UINT64_C(0x481c18):goto kg_pc_481c18;
case UINT64_C(0x481c1a):goto kg_pc_481c1a;
case UINT64_C(0x481c1c):goto kg_pc_481c1c;
case UINT64_C(0x481c21):goto kg_pc_481c21;
case UINT64_C(0x481c26):goto kg_pc_481c26;
case UINT64_C(0x481c29):goto kg_pc_481c29;
case UINT64_C(0x481c2f):goto kg_pc_481c2f;
case UINT64_C(0x481c31):goto kg_pc_481c31;
case UINT64_C(0x481c33):goto kg_pc_481c33;
case UINT64_C(0x481c38):goto kg_pc_481c38;
case UINT64_C(0x481c3e):goto kg_pc_481c3e;
case UINT64_C(0x481c46):goto kg_pc_481c46;
case UINT64_C(0x481c49):goto kg_pc_481c49;
case UINT64_C(0x481c4c):goto kg_pc_481c4c;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5246: [0x481969,0x481c53), 191 instructions. */
kg_pc_481969: STEP(0x481969); /* shl dil, 4 */
x = (s->gpr[5] & UINT64_C(0xff)); y = UINT64_C(0x4);
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48196d: STEP(0x48196d); /* xor dil, 0xb0 */
x = (s->gpr[5] & UINT64_C(0xff)); y = UINT64_C(0xb0);
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481971: STEP(0x481971); /* lea ecx, [rdi + rdi] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_481974: STEP(0x481974); /* and cl, 0x20 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x20);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481977: STEP(0x481977); /* sub dil, cl */
x = (s->gpr[5] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48197a: STEP(0x48197a); /* add dil, 0x1f */
x = (s->gpr[5] & UINT64_C(0xff)); y = UINT64_C(0x1f);
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48197e: STEP(0x48197e); /* xor dil, bl */
x = (s->gpr[5] & UINT64_C(0xff)); y = (s->gpr[1] & UINT64_C(0xff));
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481981: STEP(0x481981); /* xor dil, 0x5f */
x = (s->gpr[5] & UINT64_C(0xff)); y = UINT64_C(0x5f);
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481985: STEP(0x481985); /* mov rcx, qword ptr [rbp - 0xe10] */
READ(a, (UINT64_C(0xfffffffffffff1f0) + s->gpr[6]), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_48198c: STEP(0x48198c); /* mov r15, qword ptr [rbp - 0x508] */
READ(a, (UINT64_C(0xfffffffffffffaf8) + s->gpr[6]), 8);
s->gpr[15] = a;
++s->steps;
kg_pc_481993: STEP(0x481993); /* mov byte ptr [rcx + r15], dil */
WRITE((UINT64_C(0x0) + s->gpr[2] + (s->gpr[15] * UINT64_C(0x1))), 1, (s->gpr[5] & UINT64_C(0xff)));
++s->steps;
kg_pc_481997: STEP(0x481997); /* mov ecx, r14d */
s->gpr[2] = (uint32_t)((s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48199a: STEP(0x48199a); /* shr ecx, 8 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[2] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_48199d: STEP(0x48199d); /* movzx ecx, cl */
s->gpr[2] = (uint32_t)((s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_4819a0: STEP(0x4819a0); /* mov esi, ecx */
s->gpr[4] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4819a2: STEP(0x4819a2); /* xor esi, 0xa1 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xa1);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4819a8: STEP(0x4819a8); /* mov edi, esi */
s->gpr[5] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4819aa: STEP(0x4819aa); /* and edi, 0x47 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x47);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4819ad: STEP(0x4819ad); /* add edi, edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4819af: STEP(0x4819af); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4819b1: STEP(0x4819b1); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4819b3: STEP(0x4819b3); /* add esi, 0x9c26e147 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x9c26e147);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4819b9: STEP(0x4819b9); /* xor esi, 0x7c32614f */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x7c32614f);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4819bf: STEP(0x4819bf); /* lea edi, [rsi + rsi] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_4819c2: STEP(0x4819c2); /* and edi, 0xc009771c */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xc009771c);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4819c8: STEP(0x4819c8); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4819ca: STEP(0x4819ca); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4819cc: STEP(0x4819cc); /* add esi, 0x6f25bb8e */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x6f25bb8e);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4819d2: STEP(0x4819d2); /* mov edi, esi */
s->gpr[5] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4819d4: STEP(0x4819d4); /* add esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4819d6: STEP(0x4819d6); /* xor esi, 0x1e6277e0 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x1e6277e0);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4819dc: STEP(0x4819dc); /* lea ebx, [rsi + rsi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_4819df: STEP(0x4819df); /* and ebx, 0x40 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x40);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4819e2: STEP(0x4819e2); /* mov eax, esi */
s->gpr[0] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4819e4: STEP(0x4819e4); /* sub eax, ebx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_4819e6: STEP(0x4819e6); /* neg ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = 0;
s->gpr[1] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_4819e8: STEP(0x4819e8); /* add esi, ebx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4819ea: STEP(0x4819ea); /* add esi, 0x1a0 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x1a0);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4819f0: STEP(0x4819f0); /* xor edi, 0x8f313bf0 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x8f313bf0);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4819f6: STEP(0x4819f6); /* add edi, 0x57 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x57);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4819f9: STEP(0x4819f9); /* mov ebx, edi */
s->gpr[1] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4819fb: STEP(0x4819fb); /* xor ebx, 0x7bfb344d */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x7bfb344d);
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481a01: STEP(0x481a01); /* and edi, 0xfbfb344d */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xfbfb344d);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481a07: STEP(0x481a07); /* lea edi, [rbx + rdi*2] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[5] * UINT64_C(0x2))));
++s->steps;
kg_pc_481a0a: STEP(0x481a0a); /* and esi, 0xae */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xae);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481a10: STEP(0x481a10); /* xor esi, 0xa49001ad */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xa49001ad);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481a16: STEP(0x481a16); /* add edi, esi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481a18: STEP(0x481a18); /* add eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481a1a: STEP(0x481a1a); /* add eax, 0x340 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x340);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481a1f: STEP(0x481a1f); /* and eax, 0x144 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x144);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481a24: STEP(0x481a24); /* xor eax, 0xfffffebf */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffffebf);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481a29: STEP(0x481a29); /* add eax, edi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481a2b: STEP(0x481a2b); /* add eax, 0xdf74caa7 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xdf74caa7);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481a30: STEP(0x481a30); /* xor cl, byte ptr [r11 + rax - 0x55ad0efe] */
READ(b, (UINT64_C(0xffffffffaa52f102) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x1))), 1);
x = (s->gpr[2] & UINT64_C(0xff)); y = b;
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481a38: STEP(0x481a38); /* xor cl, 0x3e */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x3e);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481a3b: STEP(0x481a3b); /* mov rax, qword ptr [rbp - 0xe10] */
READ(a, (UINT64_C(0xfffffffffffff1f0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_481a42: STEP(0x481a42); /* mov rsi, qword ptr [rbp - 0x450] */
READ(a, (UINT64_C(0xfffffffffffffbb0) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_481a49: STEP(0x481a49); /* mov byte ptr [rax + rsi], cl */
WRITE((UINT64_C(0x0) + s->gpr[0] + (s->gpr[4] * UINT64_C(0x1))), 1, (s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_481a4c: STEP(0x481a4c); /* movzx eax, r14b */
s->gpr[0] = (uint32_t)((s->gpr[14] & UINT64_C(0xff)));
++s->steps;
kg_pc_481a50: STEP(0x481a50); /* xor eax, 0x53 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x53);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481a53: STEP(0x481a53); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481a55: STEP(0x481a55); /* and ecx, 0x76 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x76);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481a58: STEP(0x481a58); /* add ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481a5a: STEP(0x481a5a); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481a5c: STEP(0x481a5c); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481a5e: STEP(0x481a5e); /* add eax, 0x4c6c6f76 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x4c6c6f76);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481a63: STEP(0x481a63); /* xor eax, 0xcfd6610 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xcfd6610);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481a68: STEP(0x481a68); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481a6b: STEP(0x481a6b); /* and ecx, 0x81220c86 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x81220c86);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481a71: STEP(0x481a71); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481a73: STEP(0x481a73); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481a75: STEP(0x481a75); /* add eax, 0x65b1c643 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x65b1c643);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481a7a: STEP(0x481a7a); /* xor rax, 0x2520cfdb */
x = s->gpr[0]; y = UINT64_C(0x2520cfdb);
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_481a80: STEP(0x481a80); /* mov rdi, qword ptr [rbp - 0x398] */
READ(a, (UINT64_C(0xfffffffffffffc68) + s->gpr[6]), 8);
s->gpr[5] = a;
++s->steps;
kg_pc_481a87: STEP(0x481a87); /* movzx eax, byte ptr [rdi + rax - 0x346e5502] */
READ(a, (UINT64_C(0xffffffffcb91aafe) + s->gpr[5] + (s->gpr[0] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_481a8f: STEP(0x481a8f); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481a92: STEP(0x481a92); /* xor cl, 0xb6 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xb6);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481a95: STEP(0x481a95); /* lea esi, [rax*4] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + (s->gpr[0] * UINT64_C(0x4))));
++s->steps;
kg_pc_481a9c: STEP(0x481a9c); /* and sil, 0x90 */
x = (s->gpr[4] & UINT64_C(0xff)); y = UINT64_C(0x90);
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481aa0: STEP(0x481aa0); /* sub cl, sil */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[4] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481aa3: STEP(0x481aa3); /* add cl, 0x49 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x49);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481aa6: STEP(0x481aa6); /* xor cl, al */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481aa8: STEP(0x481aa8); /* xor cl, 0xc2 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xc2);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481aab: STEP(0x481aab); /* mov rax, qword ptr [rbp - 0xe10] */
READ(a, (UINT64_C(0xfffffffffffff1f0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_481ab2: STEP(0x481ab2); /* mov rsi, qword ptr [rbp - 0x4e8] */
READ(a, (UINT64_C(0xfffffffffffffb18) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_481ab9: STEP(0x481ab9); /* mov byte ptr [rax + rsi], cl */
WRITE((UINT64_C(0x0) + s->gpr[0] + (s->gpr[4] * UINT64_C(0x1))), 1, (s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_481abc: STEP(0x481abc); /* mov rdx, qword ptr [rbp - 0x3f8] */
READ(a, (UINT64_C(0xfffffffffffffc08) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_481ac3: STEP(0x481ac3); /* movzx eax, dl */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xff)));
++s->steps;
kg_pc_481ac6: STEP(0x481ac6); /* xor eax, 0xa5 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xa5);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481acb: STEP(0x481acb); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481acd: STEP(0x481acd); /* and ecx, 0x46 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x46);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481ad0: STEP(0x481ad0); /* add ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481ad2: STEP(0x481ad2); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481ad4: STEP(0x481ad4); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481ad6: STEP(0x481ad6); /* add eax, 0xcfe4ce46 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xcfe4ce46);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481adb: STEP(0x481adb); /* xor eax, 0x46bc1c40 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x46bc1c40);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481ae0: STEP(0x481ae0); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481ae3: STEP(0x481ae3); /* and ecx, 0x30a7de */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x30a7de);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481ae9: STEP(0x481ae9); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481aeb: STEP(0x481aeb); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481aed: STEP(0x481aed); /* add eax, 0xa01f7bef */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xa01f7bef);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481af2: STEP(0x481af2); /* xor rax, 0x2947a978 */
x = s->gpr[0]; y = UINT64_C(0x2947a978);
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_481af8: STEP(0x481af8); /* movzx eax, byte ptr [rdi + rax - 0x346e5502] */
READ(a, (UINT64_C(0xffffffffcb91aafe) + s->gpr[5] + (s->gpr[0] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_481b00: STEP(0x481b00); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481b03: STEP(0x481b03); /* xor cl, 0xb6 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xb6);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481b06: STEP(0x481b06); /* lea esi, [rax*4] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + (s->gpr[0] * UINT64_C(0x4))));
++s->steps;
kg_pc_481b0d: STEP(0x481b0d); /* and sil, 0x90 */
x = (s->gpr[4] & UINT64_C(0xff)); y = UINT64_C(0x90);
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481b11: STEP(0x481b11); /* sub cl, sil */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[4] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481b14: STEP(0x481b14); /* add cl, 0x49 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x49);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481b17: STEP(0x481b17); /* xor cl, al */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481b19: STEP(0x481b19); /* xor cl, 0x8c */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x8c);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481b1c: STEP(0x481b1c); /* mov rax, qword ptr [rbp - 0xe10] */
READ(a, (UINT64_C(0xfffffffffffff1f0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_481b23: STEP(0x481b23); /* mov rsi, qword ptr [rbp - 0x468] */
READ(a, (UINT64_C(0xfffffffffffffb98) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_481b2a: STEP(0x481b2a); /* mov byte ptr [rax + rsi], cl */
WRITE((UINT64_C(0x0) + s->gpr[0] + (s->gpr[4] * UINT64_C(0x1))), 1, (s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_481b2d: STEP(0x481b2d); /* mov eax, r12d */
s->gpr[0] = (uint32_t)((s->gpr[12] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481b30: STEP(0x481b30); /* shr eax, 0x10 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_481b33: STEP(0x481b33); /* movzx eax, al */
s->gpr[0] = (uint32_t)((s->gpr[0] & UINT64_C(0xff)));
++s->steps;
kg_pc_481b36: STEP(0x481b36); /* xor eax, 0xb0 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xb0);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481b3b: STEP(0x481b3b); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481b3e: STEP(0x481b3e); /* and ecx, 0x122 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x122);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481b44: STEP(0x481b44); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481b46: STEP(0x481b46); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481b48: STEP(0x481b48); /* add eax, 0xb04cbe91 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xb04cbe91);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481b4d: STEP(0x481b4d); /* xor eax, 0x2cbab9 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x2cbab9);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481b52: STEP(0x481b52); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481b55: STEP(0x481b55); /* and ecx, 0x20c00d20 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x20c00d20);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481b5b: STEP(0x481b5b); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481b5d: STEP(0x481b5d); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481b5f: STEP(0x481b5f); /* add eax, 0x94ea9e90 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x94ea9e90);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481b64: STEP(0x481b64); /* xor rax, 0x248a9a00 */
x = s->gpr[0]; y = UINT64_C(0x248a9a00);
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_481b6a: STEP(0x481b6a); /* movzx ebx, byte ptr [r8 + rax - 0x3a80b032] */
READ(a, (UINT64_C(0xffffffffc57f4fce) + s->gpr[8] + (s->gpr[0] * UINT64_C(0x1))), 1);
s->gpr[1] = (uint32_t)(a);
++s->steps;
kg_pc_481b73: STEP(0x481b73); /* mov ecx, ebx */
s->gpr[2] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481b75: STEP(0x481b75); /* shl cl, 4 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x4);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481b78: STEP(0x481b78); /* xor cl, 0xb0 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xb0);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481b7b: STEP(0x481b7b); /* mov eax, ebx */
s->gpr[0] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481b7d: STEP(0x481b7d); /* shl al, 5 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x5);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481b80: STEP(0x481b80); /* and al, 0x80 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x80);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481b82: STEP(0x481b82); /* add al, cl */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481b84: STEP(0x481b84); /* add al, 0x43 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x43);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481b86: STEP(0x481b86); /* xor al, bl */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[1] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481b88: STEP(0x481b88); /* xor al, 0x10 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x10);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481b8a: STEP(0x481b8a); /* mov rcx, qword ptr [rbp - 0xe10] */
READ(a, (UINT64_C(0xfffffffffffff1f0) + s->gpr[6]), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_481b91: STEP(0x481b91); /* mov rsi, qword ptr [rbp - 0x470] */
READ(a, (UINT64_C(0xfffffffffffffb90) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_481b98: STEP(0x481b98); /* mov byte ptr [rcx + rsi], al */
WRITE((UINT64_C(0x0) + s->gpr[2] + (s->gpr[4] * UINT64_C(0x1))), 1, (s->gpr[0] & UINT64_C(0xff)));
++s->steps;
kg_pc_481b9b: STEP(0x481b9b); /* movzx eax, dh */
s->gpr[0] = (uint32_t)(((s->gpr[3] >> 8) & UINT64_C(0xff)));
++s->steps;
kg_pc_481b9e: STEP(0x481b9e); /* xor eax, 0xb7 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xb7);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481ba3: STEP(0x481ba3); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481ba6: STEP(0x481ba6); /* and ecx, 0x5e */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x5e);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481ba9: STEP(0x481ba9); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481bab: STEP(0x481bab); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481bad: STEP(0x481bad); /* add eax, 0x409c2f */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x409c2f);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481bb2: STEP(0x481bb2); /* xor eax, 0x172b */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x172b);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481bb7: STEP(0x481bb7); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481bba: STEP(0x481bba); /* and ecx, 0x11202 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x11202);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481bc0: STEP(0x481bc0); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481bc2: STEP(0x481bc2); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481bc4: STEP(0x481bc4); /* add eax, 0xe2ab901 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xe2ab901);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481bc9: STEP(0x481bc9); /* xor rax, 0xe6a32a9 */
x = s->gpr[0]; y = UINT64_C(0xe6a32a9);
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_481bcf: STEP(0x481bcf); /* movzx eax, byte ptr [r8 + rax - 0x3a80b032] */
READ(a, (UINT64_C(0xffffffffc57f4fce) + s->gpr[8] + (s->gpr[0] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_481bd8: STEP(0x481bd8); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481bda: STEP(0x481bda); /* shl cl, 4 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x4);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481bdd: STEP(0x481bdd); /* xor cl, 0xb0 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xb0);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481be0: STEP(0x481be0); /* lea edx, [rcx + rcx] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_481be3: STEP(0x481be3); /* and dl, 0x60 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x60);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481be6: STEP(0x481be6); /* sub cl, dl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481be8: STEP(0x481be8); /* add cl, 0x39 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x39);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481beb: STEP(0x481beb); /* xor cl, al */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481bed: STEP(0x481bed); /* xor cl, 0x88 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x88);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481bf0: STEP(0x481bf0); /* mov rax, qword ptr [rbp - 0xe10] */
READ(a, (UINT64_C(0xfffffffffffff1f0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_481bf7: STEP(0x481bf7); /* mov rdx, qword ptr [rbp - 0x488] */
READ(a, (UINT64_C(0xfffffffffffffb78) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_481bfe: STEP(0x481bfe); /* mov byte ptr [rax + rdx], cl */
WRITE((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x1))), 1, (s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_481c01: STEP(0x481c01); /* mov eax, r10d */
s->gpr[0] = (uint32_t)((s->gpr[10] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481c04: STEP(0x481c04); /* shr eax, 0x10 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_481c07: STEP(0x481c07); /* movzx eax, al */
s->gpr[0] = (uint32_t)((s->gpr[0] & UINT64_C(0xff)));
++s->steps;
kg_pc_481c0a: STEP(0x481c0a); /* xor eax, 0xd9 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xd9);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481c0f: STEP(0x481c0f); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481c12: STEP(0x481c12); /* and ecx, 0x142 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x142);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481c18: STEP(0x481c18); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481c1a: STEP(0x481c1a); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481c1c: STEP(0x481c1c); /* add eax, 0x7a1 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x7a1);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481c21: STEP(0x481c21); /* xor eax, 0x15d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x15d);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481c26: STEP(0x481c26); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481c29: STEP(0x481c29); /* and ecx, 0x8844ed58 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x8844ed58);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481c2f: STEP(0x481c2f); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481c31: STEP(0x481c31); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481c33: STEP(0x481c33); /* add eax, 0x442276ac */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x442276ac);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481c38: STEP(0x481c38); /* xor rax, 0x4422708e */
x = s->gpr[0]; y = UINT64_C(0x4422708e);
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_481c3e: STEP(0x481c3e); /* movzx eax, byte ptr [rdi + rax - 0x346e5502] */
READ(a, (UINT64_C(0xffffffffcb91aafe) + s->gpr[5] + (s->gpr[0] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_481c46: STEP(0x481c46); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481c49: STEP(0x481c49); /* xor cl, 0xb6 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xb6);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481c4c: STEP(0x481c4c); /* lea edx, [rax*4] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + (s->gpr[0] * UINT64_C(0x4))));
++s->steps;

break;
    case 8:
next_pc=bias+UINT64_C(0x481f04);
switch(s->pc-bias){
case UINT64_C(0x481c53):goto kg_pc_481c53;
case UINT64_C(0x481c56):goto kg_pc_481c56;
case UINT64_C(0x481c58):goto kg_pc_481c58;
case UINT64_C(0x481c5a):goto kg_pc_481c5a;
case UINT64_C(0x481c5d):goto kg_pc_481c5d;
case UINT64_C(0x481c64):goto kg_pc_481c64;
case UINT64_C(0x481c6b):goto kg_pc_481c6b;
case UINT64_C(0x481c6e):goto kg_pc_481c6e;
case UINT64_C(0x481c72):goto kg_pc_481c72;
case UINT64_C(0x481c77):goto kg_pc_481c77;
case UINT64_C(0x481c7a):goto kg_pc_481c7a;
case UINT64_C(0x481c7d):goto kg_pc_481c7d;
case UINT64_C(0x481c7f):goto kg_pc_481c7f;
case UINT64_C(0x481c81):goto kg_pc_481c81;
case UINT64_C(0x481c86):goto kg_pc_481c86;
case UINT64_C(0x481c8b):goto kg_pc_481c8b;
case UINT64_C(0x481c8e):goto kg_pc_481c8e;
case UINT64_C(0x481c94):goto kg_pc_481c94;
case UINT64_C(0x481c96):goto kg_pc_481c96;
case UINT64_C(0x481c98):goto kg_pc_481c98;
case UINT64_C(0x481c9d):goto kg_pc_481c9d;
case UINT64_C(0x481ca3):goto kg_pc_481ca3;
case UINT64_C(0x481cac):goto kg_pc_481cac;
case UINT64_C(0x481cae):goto kg_pc_481cae;
case UINT64_C(0x481cb1):goto kg_pc_481cb1;
case UINT64_C(0x481cb4):goto kg_pc_481cb4;
case UINT64_C(0x481cb6):goto kg_pc_481cb6;
case UINT64_C(0x481cb9):goto kg_pc_481cb9;
case UINT64_C(0x481cbc):goto kg_pc_481cbc;
case UINT64_C(0x481cbe):goto kg_pc_481cbe;
case UINT64_C(0x481cc0):goto kg_pc_481cc0;
case UINT64_C(0x481cc3):goto kg_pc_481cc3;
case UINT64_C(0x481cc6):goto kg_pc_481cc6;
case UINT64_C(0x481cca):goto kg_pc_481cca;
case UINT64_C(0x481cce):goto kg_pc_481cce;
case UINT64_C(0x481cd1):goto kg_pc_481cd1;
case UINT64_C(0x481cd4):goto kg_pc_481cd4;
case UINT64_C(0x481cd6):goto kg_pc_481cd6;
case UINT64_C(0x481cd9):goto kg_pc_481cd9;
case UINT64_C(0x481cdb):goto kg_pc_481cdb;
case UINT64_C(0x481cde):goto kg_pc_481cde;
case UINT64_C(0x481ce1):goto kg_pc_481ce1;
case UINT64_C(0x481ce3):goto kg_pc_481ce3;
case UINT64_C(0x481ce5):goto kg_pc_481ce5;
case UINT64_C(0x481ce7):goto kg_pc_481ce7;
case UINT64_C(0x481cea):goto kg_pc_481cea;
case UINT64_C(0x481cec):goto kg_pc_481cec;
case UINT64_C(0x481cef):goto kg_pc_481cef;
case UINT64_C(0x481cf3):goto kg_pc_481cf3;
case UINT64_C(0x481cf5):goto kg_pc_481cf5;
case UINT64_C(0x481cf8):goto kg_pc_481cf8;
case UINT64_C(0x481cfb):goto kg_pc_481cfb;
case UINT64_C(0x481cff):goto kg_pc_481cff;
case UINT64_C(0x481d06):goto kg_pc_481d06;
case UINT64_C(0x481d08):goto kg_pc_481d08;
case UINT64_C(0x481d0b):goto kg_pc_481d0b;
case UINT64_C(0x481d0d):goto kg_pc_481d0d;
case UINT64_C(0x481d10):goto kg_pc_481d10;
case UINT64_C(0x481d12):goto kg_pc_481d12;
case UINT64_C(0x481d14):goto kg_pc_481d14;
case UINT64_C(0x481d16):goto kg_pc_481d16;
case UINT64_C(0x481d19):goto kg_pc_481d19;
case UINT64_C(0x481d1b):goto kg_pc_481d1b;
case UINT64_C(0x481d1e):goto kg_pc_481d1e;
case UINT64_C(0x481d21):goto kg_pc_481d21;
case UINT64_C(0x481d23):goto kg_pc_481d23;
case UINT64_C(0x481d26):goto kg_pc_481d26;
case UINT64_C(0x481d29):goto kg_pc_481d29;
case UINT64_C(0x481d2c):goto kg_pc_481d2c;
case UINT64_C(0x481d2e):goto kg_pc_481d2e;
case UINT64_C(0x481d30):goto kg_pc_481d30;
case UINT64_C(0x481d33):goto kg_pc_481d33;
case UINT64_C(0x481d36):goto kg_pc_481d36;
case UINT64_C(0x481d38):goto kg_pc_481d38;
case UINT64_C(0x481d3b):goto kg_pc_481d3b;
case UINT64_C(0x481d42):goto kg_pc_481d42;
case UINT64_C(0x481d49):goto kg_pc_481d49;
case UINT64_C(0x481d4c):goto kg_pc_481d4c;
case UINT64_C(0x481d4f):goto kg_pc_481d4f;
case UINT64_C(0x481d52):goto kg_pc_481d52;
case UINT64_C(0x481d55):goto kg_pc_481d55;
case UINT64_C(0x481d57):goto kg_pc_481d57;
case UINT64_C(0x481d5a):goto kg_pc_481d5a;
case UINT64_C(0x481d5d):goto kg_pc_481d5d;
case UINT64_C(0x481d60):goto kg_pc_481d60;
case UINT64_C(0x481d66):goto kg_pc_481d66;
case UINT64_C(0x481d68):goto kg_pc_481d68;
case UINT64_C(0x481d6d):goto kg_pc_481d6d;
case UINT64_C(0x481d72):goto kg_pc_481d72;
case UINT64_C(0x481d75):goto kg_pc_481d75;
case UINT64_C(0x481d7b):goto kg_pc_481d7b;
case UINT64_C(0x481d7d):goto kg_pc_481d7d;
case UINT64_C(0x481d80):goto kg_pc_481d80;
case UINT64_C(0x481d86):goto kg_pc_481d86;
case UINT64_C(0x481d8d):goto kg_pc_481d8d;
case UINT64_C(0x481d95):goto kg_pc_481d95;
case UINT64_C(0x481d98):goto kg_pc_481d98;
case UINT64_C(0x481d9f):goto kg_pc_481d9f;
case UINT64_C(0x481da6):goto kg_pc_481da6;
case UINT64_C(0x481da9):goto kg_pc_481da9;
case UINT64_C(0x481dad):goto kg_pc_481dad;
case UINT64_C(0x481db1):goto kg_pc_481db1;
case UINT64_C(0x481db6):goto kg_pc_481db6;
case UINT64_C(0x481db9):goto kg_pc_481db9;
case UINT64_C(0x481dbc):goto kg_pc_481dbc;
case UINT64_C(0x481dbe):goto kg_pc_481dbe;
case UINT64_C(0x481dc0):goto kg_pc_481dc0;
case UINT64_C(0x481dc2):goto kg_pc_481dc2;
case UINT64_C(0x481dc4):goto kg_pc_481dc4;
case UINT64_C(0x481dc9):goto kg_pc_481dc9;
case UINT64_C(0x481dcc):goto kg_pc_481dcc;
case UINT64_C(0x481dd2):goto kg_pc_481dd2;
case UINT64_C(0x481dd5):goto kg_pc_481dd5;
case UINT64_C(0x481dd7):goto kg_pc_481dd7;
case UINT64_C(0x481ddd):goto kg_pc_481ddd;
case UINT64_C(0x481de0):goto kg_pc_481de0;
case UINT64_C(0x481de3):goto kg_pc_481de3;
case UINT64_C(0x481de6):goto kg_pc_481de6;
case UINT64_C(0x481deb):goto kg_pc_481deb;
case UINT64_C(0x481ded):goto kg_pc_481ded;
case UINT64_C(0x481df0):goto kg_pc_481df0;
case UINT64_C(0x481df5):goto kg_pc_481df5;
case UINT64_C(0x481df8):goto kg_pc_481df8;
case UINT64_C(0x481dfb):goto kg_pc_481dfb;
case UINT64_C(0x481dfd):goto kg_pc_481dfd;
case UINT64_C(0x481e02):goto kg_pc_481e02;
case UINT64_C(0x481e0a):goto kg_pc_481e0a;
case UINT64_C(0x481e11):goto kg_pc_481e11;
case UINT64_C(0x481e15):goto kg_pc_481e15;
case UINT64_C(0x481e1c):goto kg_pc_481e1c;
case UINT64_C(0x481e20):goto kg_pc_481e20;
case UINT64_C(0x481e23):goto kg_pc_481e23;
case UINT64_C(0x481e26):goto kg_pc_481e26;
case UINT64_C(0x481e2a):goto kg_pc_481e2a;
case UINT64_C(0x481e32):goto kg_pc_481e32;
case UINT64_C(0x481e35):goto kg_pc_481e35;
case UINT64_C(0x481e38):goto kg_pc_481e38;
case UINT64_C(0x481e3b):goto kg_pc_481e3b;
case UINT64_C(0x481e3e):goto kg_pc_481e3e;
case UINT64_C(0x481e40):goto kg_pc_481e40;
case UINT64_C(0x481e43):goto kg_pc_481e43;
case UINT64_C(0x481e45):goto kg_pc_481e45;
case UINT64_C(0x481e4c):goto kg_pc_481e4c;
case UINT64_C(0x481e4f):goto kg_pc_481e4f;
case UINT64_C(0x481e56):goto kg_pc_481e56;
case UINT64_C(0x481e59):goto kg_pc_481e59;
case UINT64_C(0x481e5d):goto kg_pc_481e5d;
case UINT64_C(0x481e62):goto kg_pc_481e62;
case UINT64_C(0x481e65):goto kg_pc_481e65;
case UINT64_C(0x481e68):goto kg_pc_481e68;
case UINT64_C(0x481e6a):goto kg_pc_481e6a;
case UINT64_C(0x481e6c):goto kg_pc_481e6c;
case UINT64_C(0x481e71):goto kg_pc_481e71;
case UINT64_C(0x481e76):goto kg_pc_481e76;
case UINT64_C(0x481e79):goto kg_pc_481e79;
case UINT64_C(0x481e7f):goto kg_pc_481e7f;
case UINT64_C(0x481e81):goto kg_pc_481e81;
case UINT64_C(0x481e83):goto kg_pc_481e83;
case UINT64_C(0x481e88):goto kg_pc_481e88;
case UINT64_C(0x481e8e):goto kg_pc_481e8e;
case UINT64_C(0x481e97):goto kg_pc_481e97;
case UINT64_C(0x481e9b):goto kg_pc_481e9b;
case UINT64_C(0x481e9e):goto kg_pc_481e9e;
case UINT64_C(0x481ea4):goto kg_pc_481ea4;
case UINT64_C(0x481ea6):goto kg_pc_481ea6;
case UINT64_C(0x481eaa):goto kg_pc_481eaa;
case UINT64_C(0x481eb1):goto kg_pc_481eb1;
case UINT64_C(0x481eb3):goto kg_pc_481eb3;
case UINT64_C(0x481eb6):goto kg_pc_481eb6;
case UINT64_C(0x481eb9):goto kg_pc_481eb9;
case UINT64_C(0x481ebb):goto kg_pc_481ebb;
case UINT64_C(0x481ebe):goto kg_pc_481ebe;
case UINT64_C(0x481ec1):goto kg_pc_481ec1;
case UINT64_C(0x481ec3):goto kg_pc_481ec3;
case UINT64_C(0x481ec6):goto kg_pc_481ec6;
case UINT64_C(0x481ecd):goto kg_pc_481ecd;
case UINT64_C(0x481ecf):goto kg_pc_481ecf;
case UINT64_C(0x481ed2):goto kg_pc_481ed2;
case UINT64_C(0x481ed9):goto kg_pc_481ed9;
case UINT64_C(0x481edc):goto kg_pc_481edc;
case UINT64_C(0x481edf):goto kg_pc_481edf;
case UINT64_C(0x481ee4):goto kg_pc_481ee4;
case UINT64_C(0x481ee6):goto kg_pc_481ee6;
case UINT64_C(0x481ee8):goto kg_pc_481ee8;
case UINT64_C(0x481eee):goto kg_pc_481eee;
case UINT64_C(0x481ef1):goto kg_pc_481ef1;
case UINT64_C(0x481ef4):goto kg_pc_481ef4;
case UINT64_C(0x481ef7):goto kg_pc_481ef7;
case UINT64_C(0x481efa):goto kg_pc_481efa;
case UINT64_C(0x481efd):goto kg_pc_481efd;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5247: [0x481c53,0x481f04), 190 instructions. */
kg_pc_481c53: STEP(0x481c53); /* xor dl, 0x93 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x93);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481c56: STEP(0x481c56); /* add dl, cl */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481c58: STEP(0x481c58); /* xor dl, al */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481c5a: STEP(0x481c5a); /* xor dl, 0x19 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x19);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481c5d: STEP(0x481c5d); /* mov rax, qword ptr [rbp - 0xe10] */
READ(a, (UINT64_C(0xfffffffffffff1f0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_481c64: STEP(0x481c64); /* mov rcx, qword ptr [rbp - 0x500] */
READ(a, (UINT64_C(0xfffffffffffffb00) + s->gpr[6]), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_481c6b: STEP(0x481c6b); /* mov byte ptr [rax + rcx], dl */
WRITE((UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1))), 1, (s->gpr[3] & UINT64_C(0xff)));
++s->steps;
kg_pc_481c6e: STEP(0x481c6e); /* movzx eax, r10b */
s->gpr[0] = (uint32_t)((s->gpr[10] & UINT64_C(0xff)));
++s->steps;
kg_pc_481c72: STEP(0x481c72); /* xor eax, 0xe0 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xe0);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481c77: STEP(0x481c77); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481c7a: STEP(0x481c7a); /* and ecx, 0xffffffd4 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffd4);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481c7d: STEP(0x481c7d); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481c7f: STEP(0x481c7f); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481c81: STEP(0x481c81); /* add eax, 0xe13c6fea */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xe13c6fea);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481c86: STEP(0x481c86); /* xor eax, 0x492c6e6f */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x492c6e6f);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481c8b: STEP(0x481c8b); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481c8e: STEP(0x481c8e); /* and ecx, 0x10002f44 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x10002f44);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481c94: STEP(0x481c94); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481c96: STEP(0x481c96); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481c98: STEP(0x481c98); /* add eax, 0x9f6797a2 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x9f6797a2);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481c9d: STEP(0x481c9d); /* xor rax, 0x377796b4 */
x = s->gpr[0]; y = UINT64_C(0x377796b4);
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_481ca3: STEP(0x481ca3); /* movzx eax, byte ptr [r8 + rax - 0x3a80b032] */
READ(a, (UINT64_C(0xffffffffc57f4fce) + s->gpr[8] + (s->gpr[0] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_481cac: STEP(0x481cac); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481cae: STEP(0x481cae); /* xor cl, 0xd4 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xd4);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cb1: STEP(0x481cb1); /* lea esi, [rcx + rcx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_481cb4: STEP(0x481cb4); /* mov dl, 0x32 */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((UINT64_C(0x32)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cb6: STEP(0x481cb6); /* sub dl, sil */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[4] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cb9: STEP(0x481cb9); /* or dl, 0x23 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x23);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_OR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cbc: STEP(0x481cbc); /* add dl, cl */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cbe: STEP(0x481cbe); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481cc0: STEP(0x481cc0); /* xor cl, 0xb1 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xb1);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cc3: STEP(0x481cc3); /* lea esi, [rcx + rcx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_481cc6: STEP(0x481cc6); /* add sil, 2 */
x = (s->gpr[4] & UINT64_C(0xff)); y = UINT64_C(0x2);
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cca: STEP(0x481cca); /* and sil, 0xae */
x = (s->gpr[4] & UINT64_C(0xff)); y = UINT64_C(0xae);
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cce: STEP(0x481cce); /* sub cl, sil */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[4] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cd1: STEP(0x481cd1); /* add dl, 0xd5 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0xd5);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cd4: STEP(0x481cd4); /* xor dl, al */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cd6: STEP(0x481cd6); /* add cl, 0x58 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x58);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cd9: STEP(0x481cd9); /* xor dl, cl */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cdb: STEP(0x481cdb); /* xor dl, 0x77 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x77);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cde: STEP(0x481cde); /* add dl, 0x65 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x65);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481ce1: STEP(0x481ce1); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481ce3: STEP(0x481ce3); /* xor al, 0x53 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x53);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481ce5: STEP(0x481ce5); /* add dl, dl */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481ce7: STEP(0x481ce7); /* and dl, 0xa6 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0xa6);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cea: STEP(0x481cea); /* add dl, al */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cec: STEP(0x481cec); /* lea esi, [rdx - 0x53] */
s->gpr[4] = (uint32_t)((UINT64_C(0xffffffffffffffad) + s->gpr[3]));
++s->steps;
kg_pc_481cef: STEP(0x481cef); /* shr sil, 4 */
x = (s->gpr[4] & UINT64_C(0xff)); y = UINT64_C(0x4);
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cf3: STEP(0x481cf3); /* mov ebx, edx */
s->gpr[1] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481cf5: STEP(0x481cf5); /* shl bl, 4 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x4);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cf8: STEP(0x481cf8); /* or sil, bl */
x = (s->gpr[4] & UINT64_C(0xff)); y = (s->gpr[1] & UINT64_C(0xff));
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_OR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cfb: STEP(0x481cfb); /* add sil, 0xd0 */
x = (s->gpr[4] & UINT64_C(0xff)); y = UINT64_C(0xd0);
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481cff: STEP(0x481cff); /* lea eax, [rsi*4] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + (s->gpr[4] * UINT64_C(0x4))));
++s->steps;
kg_pc_481d06: STEP(0x481d06); /* and al, 0xc */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xc);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d08: STEP(0x481d08); /* lea ecx, [rsi + rsi] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_481d0b: STEP(0x481d0b); /* sub cl, al */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d0d: STEP(0x481d0d); /* add cl, 7 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x7);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d10: STEP(0x481d10); /* mov eax, ecx */
s->gpr[0] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481d12: STEP(0x481d12); /* and al, 0xd2 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xd2);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d14: STEP(0x481d14); /* xor al, 0x87 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x87);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d16: STEP(0x481d16); /* add al, sil */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[4] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d19: STEP(0x481d19); /* add cl, cl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d1b: STEP(0x481d1b); /* and cl, 0xa4 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xa4);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d1e: STEP(0x481d1e); /* xor cl, 0xfb */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xfb);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d21: STEP(0x481d21); /* add al, cl */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d23: STEP(0x481d23); /* shl dl, 5 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x5);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d26: STEP(0x481d26); /* add dl, 0xa0 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0xa0);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d29: STEP(0x481d29); /* and dl, 0xc0 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0xc0);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d2c: STEP(0x481d2c); /* sub bl, dl */
x = (s->gpr[1] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d2e: STEP(0x481d2e); /* add al, 0xe5 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xe5);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d30: STEP(0x481d30); /* rol al, 4 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x4);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ROL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d33: STEP(0x481d33); /* add bl, 0x30 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x30);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d36: STEP(0x481d36); /* xor bl, al */
x = (s->gpr[1] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d38: STEP(0x481d38); /* xor bl, 0xbd */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0xbd);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d3b: STEP(0x481d3b); /* mov rax, qword ptr [rbp - 0xe10] */
READ(a, (UINT64_C(0xfffffffffffff1f0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_481d42: STEP(0x481d42); /* mov rcx, qword ptr [rbp - 0x480] */
READ(a, (UINT64_C(0xfffffffffffffb80) + s->gpr[6]), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_481d49: STEP(0x481d49); /* mov byte ptr [rax + rcx], bl */
WRITE((UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1))), 1, (s->gpr[1] & UINT64_C(0xff)));
++s->steps;
kg_pc_481d4c: STEP(0x481d4c); /* mov eax, r12d */
s->gpr[0] = (uint32_t)((s->gpr[12] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481d4f: STEP(0x481d4f); /* shr eax, 8 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_481d52: STEP(0x481d52); /* movzx edx, al */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xff)));
++s->steps;
kg_pc_481d55: STEP(0x481d55); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481d57: STEP(0x481d57); /* xor eax, 5 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x5);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481d5a: STEP(0x481d5a); /* mov ecx, r12d */
s->gpr[2] = (uint32_t)((s->gpr[12] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481d5d: STEP(0x481d5d); /* shr ecx, 7 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x7);
s->gpr[2] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_481d60: STEP(0x481d60); /* and ecx, 0x174 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x174);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481d66: STEP(0x481d66); /* sub eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_481d68: STEP(0x481d68); /* add eax, 0x6c3279ba */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x6c3279ba);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481d6d: STEP(0x481d6d); /* xor eax, 0x883b5d1c */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x883b5d1c);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481d72: STEP(0x481d72); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481d75: STEP(0x481d75); /* and ecx, 0x8105144 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x8105144);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481d7b: STEP(0x481d7b); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481d7d: STEP(0x481d7d); /* lea esi, [rax + rcx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_481d80: STEP(0x481d80); /* add esi, 0x86fe28a2 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x86fe28a2);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481d86: STEP(0x481d86); /* xor rsi, 0x62f70cf8 */
x = s->gpr[4]; y = UINT64_C(0x62f70cf8);
s->gpr[4] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_481d8d: STEP(0x481d8d); /* xor dl, byte ptr [r9 + rsi - 0x56b53732] */
READ(b, (UINT64_C(0xffffffffa94ac8ce) + s->gpr[9] + (s->gpr[4] * UINT64_C(0x1))), 1);
x = (s->gpr[3] & UINT64_C(0xff)); y = b;
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d95: STEP(0x481d95); /* xor dl, 0x42 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x42);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481d98: STEP(0x481d98); /* mov rax, qword ptr [rbp - 0xe10] */
READ(a, (UINT64_C(0xfffffffffffff1f0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_481d9f: STEP(0x481d9f); /* mov rcx, qword ptr [rbp - 0x528] */
READ(a, (UINT64_C(0xfffffffffffffad8) + s->gpr[6]), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_481da6: STEP(0x481da6); /* mov byte ptr [rax + rcx], dl */
WRITE((UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1))), 1, (s->gpr[3] & UINT64_C(0xff)));
++s->steps;
kg_pc_481da9: STEP(0x481da9); /* shr r14d, 0x18 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[14] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_481dad: STEP(0x481dad); /* lea eax, [r14 + r14] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[14] + (s->gpr[14] * UINT64_C(0x1))));
++s->steps;
kg_pc_481db1: STEP(0x481db1); /* xor eax, 0x15e */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x15e);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481db6: STEP(0x481db6); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481db9: STEP(0x481db9); /* and ecx, 0x50 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x50);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481dbc: STEP(0x481dbc); /* mov edx, eax */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481dbe: STEP(0x481dbe); /* sub edx, ecx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_481dc0: STEP(0x481dc0); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481dc2: STEP(0x481dc2); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481dc4: STEP(0x481dc4); /* add eax, 0xa8 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xa8);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481dc9: STEP(0x481dc9); /* mov ecx, r14d */
s->gpr[2] = (uint32_t)((s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481dcc: STEP(0x481dcc); /* xor ecx, 0xaf */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xaf);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481dd2: STEP(0x481dd2); /* add ecx, 0x39 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x39);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481dd5: STEP(0x481dd5); /* mov esi, ecx */
s->gpr[4] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481dd7: STEP(0x481dd7); /* xor esi, 0x3cd5dffc */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x3cd5dffc);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481ddd: STEP(0x481ddd); /* and ecx, 0xfffffffc */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffffffc);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481de0: STEP(0x481de0); /* lea ecx, [rsi + rcx*2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[2] * UINT64_C(0x2))));
++s->steps;
kg_pc_481de3: STEP(0x481de3); /* and eax, 0x72 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x72);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481de6: STEP(0x481de6); /* xor eax, 0x135e461 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x135e461);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481deb: STEP(0x481deb); /* add ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481ded: STEP(0x481ded); /* lea eax, [rdx + rdx] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_481df0: STEP(0x481df0); /* add eax, 0x150 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x150);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481df5: STEP(0x481df5); /* and eax, 0x64 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x64);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481df8: STEP(0x481df8); /* xor eax, 0xffffffbf */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffbf);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481dfb: STEP(0x481dfb); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481dfd: STEP(0x481dfd); /* add eax, 0xc1f43bc4 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xc1f43bc4);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481e02: STEP(0x481e02); /* xor r14b, byte ptr [r9 + rax - 0x56b53732] */
READ(b, (UINT64_C(0xffffffffa94ac8ce) + s->gpr[9] + (s->gpr[0] * UINT64_C(0x1))), 1);
x = (s->gpr[14] & UINT64_C(0xff)); y = b;
s->gpr[14] = (s->gpr[14] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481e0a: STEP(0x481e0a); /* mov rax, qword ptr [rbp - 0xe10] */
READ(a, (UINT64_C(0xfffffffffffff1f0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_481e11: STEP(0x481e11); /* xor r14b, 3 */
x = (s->gpr[14] & UINT64_C(0xff)); y = UINT64_C(0x3);
s->gpr[14] = (s->gpr[14] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481e15: STEP(0x481e15); /* mov rcx, qword ptr [rbp - 0x518] */
READ(a, (UINT64_C(0xfffffffffffffae8) + s->gpr[6]), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_481e1c: STEP(0x481e1c); /* mov byte ptr [rax + rcx], r14b */
WRITE((UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1))), 1, (s->gpr[14] & UINT64_C(0xff)));
++s->steps;
kg_pc_481e20: STEP(0x481e20); /* mov eax, r10d */
s->gpr[0] = (uint32_t)((s->gpr[10] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481e23: STEP(0x481e23); /* shr eax, 0x18 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x18);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_481e26: STEP(0x481e26); /* xor rax, 0x7f */
x = s->gpr[0]; y = UINT64_C(0x7f);
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_481e2a: STEP(0x481e2a); /* movzx eax, byte ptr [rdi + rax - 0x346e5502] */
READ(a, (UINT64_C(0xffffffffcb91aafe) + s->gpr[5] + (s->gpr[0] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_481e32: STEP(0x481e32); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481e35: STEP(0x481e35); /* xor cl, 0xb6 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xb6);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481e38: STEP(0x481e38); /* lea edx, [rcx + rcx] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_481e3b: STEP(0x481e3b); /* and dl, 4 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x4);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481e3e: STEP(0x481e3e); /* sub cl, dl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481e40: STEP(0x481e40); /* add cl, 3 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x3);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481e43: STEP(0x481e43); /* xor cl, al */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481e45: STEP(0x481e45); /* mov rax, qword ptr [rbp - 0xe10] */
READ(a, (UINT64_C(0xfffffffffffff1f0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_481e4c: STEP(0x481e4c); /* xor cl, 0xd7 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xd7);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481e4f: STEP(0x481e4f); /* mov rdx, qword ptr [rbp - 0x520] */
READ(a, (UINT64_C(0xfffffffffffffae0) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_481e56: STEP(0x481e56); /* mov byte ptr [rax + rdx], cl */
WRITE((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x1))), 1, (s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_481e59: STEP(0x481e59); /* movzx eax, r12b */
s->gpr[0] = (uint32_t)((s->gpr[12] & UINT64_C(0xff)));
++s->steps;
kg_pc_481e5d: STEP(0x481e5d); /* xor eax, 0x90 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x90);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481e62: STEP(0x481e62); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481e65: STEP(0x481e65); /* and ecx, 0xffffff90 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffff90);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481e68: STEP(0x481e68); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481e6a: STEP(0x481e6a); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481e6c: STEP(0x481e6c); /* add eax, 0xbd690c8 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xbd690c8);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481e71: STEP(0x481e71); /* xor eax, 0xb1d6308a */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xb1d6308a);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481e76: STEP(0x481e76); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_481e79: STEP(0x481e79); /* and ecx, 0x50014b86 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x50014b86);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481e7f: STEP(0x481e7f); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481e81: STEP(0x481e81); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481e83: STEP(0x481e83); /* add eax, 0xa9ece5c3 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xa9ece5c3);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481e88: STEP(0x481e88); /* xor rax, 0x13ec45c2 */
x = s->gpr[0]; y = UINT64_C(0x13ec45c2);
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_481e8e: STEP(0x481e8e); /* movzx eax, byte ptr [r8 + rax - 0x3a80b032] */
READ(a, (UINT64_C(0xffffffffc57f4fce) + s->gpr[8] + (s->gpr[0] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_481e97: STEP(0x481e97); /* lea ecx, [r15 + r15] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[15] + (s->gpr[15] * UINT64_C(0x1))));
++s->steps;
kg_pc_481e9b: STEP(0x481e9b); /* add ecx, 0x20 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x20);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481e9e: STEP(0x481e9e); /* and ecx, 0x31e6a1f6 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x31e6a1f6);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481ea4: STEP(0x481ea4); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_481ea6: STEP(0x481ea6); /* lea r13d, [r15 + rcx] */
s->gpr[13] = (uint32_t)((UINT64_C(0x0) + s->gpr[15] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_481eaa: STEP(0x481eaa); /* add r13d, 0x18f3510b */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = UINT64_C(0x18f3510b);
s->gpr[13] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481eb1: STEP(0x481eb1); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481eb3: STEP(0x481eb3); /* shl cl, 4 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x4);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481eb6: STEP(0x481eb6); /* xor cl, 0xe0 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xe0);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481eb9: STEP(0x481eb9); /* mov edx, eax */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481ebb: STEP(0x481ebb); /* shl dl, 5 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x5);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481ebe: STEP(0x481ebe); /* and dl, 0x20 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x20);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481ec1: STEP(0x481ec1); /* sub cl, dl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481ec3: STEP(0x481ec3); /* add cl, 0x18 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x18);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481ec6: STEP(0x481ec6); /* mov rdx, qword ptr [rbp - 0xe10] */
READ(a, (UINT64_C(0xfffffffffffff1f0) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_481ecd: STEP(0x481ecd); /* xor cl, al */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481ecf: STEP(0x481ecf); /* xor cl, 0x3e */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x3e);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481ed2: STEP(0x481ed2); /* mov rax, qword ptr [rbp - 0x448] */
READ(a, (UINT64_C(0xfffffffffffffbb8) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_481ed9: STEP(0x481ed9); /* mov byte ptr [rdx + rax], cl */
WRITE((UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x1))), 1, (s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_481edc: STEP(0x481edc); /* mov eax, r13d */
s->gpr[0] = (uint32_t)((s->gpr[13] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481edf: STEP(0x481edf); /* xor eax, 0x18f350fb */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x18f350fb);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481ee4: STEP(0x481ee4); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481ee6: STEP(0x481ee6); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481ee8: STEP(0x481ee8); /* cmp eax, dword ptr [rbp - 0x570] */
READ(b, (UINT64_C(0xfffffffffffffa90) + s->gpr[6]), 4);
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = b;
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_481eee: STEP(0x481eee); /* setae cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_AE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481ef1: STEP(0x481ef1); /* setb dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_481ef4: STEP(0x481ef4); /* lea eax, [rdx + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_481ef7: STEP(0x481ef7); /* lea eax, [rdx + rax*4] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x4))));
++s->steps;
kg_pc_481efa: STEP(0x481efa); /* lea ecx, [rcx + rcx*2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x2))));
++s->steps;
kg_pc_481efd: STEP(0x481efd); /* mov rsi, qword ptr [rbp - 0x2a8] */
READ(a, (UINT64_C(0xfffffffffffffd58) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;

break;
    case 9:
next_pc=bias+UINT64_C(0x481f27);
switch(s->pc-bias){
case UINT64_C(0x481f04):goto kg_pc_481f04;
case UINT64_C(0x481f06):goto kg_pc_481f06;
case UINT64_C(0x481f08):goto kg_pc_481f08;
case UINT64_C(0x481f0a):goto kg_pc_481f0a;
case UINT64_C(0x481f0d):goto kg_pc_481f0d;
case UINT64_C(0x481f14):goto kg_pc_481f14;
case UINT64_C(0x481f18):goto kg_pc_481f18;
case UINT64_C(0x481f1f):goto kg_pc_481f1f;
case UINT64_C(0x481f22):goto kg_pc_481f22;
case UINT64_C(0x481f25):goto kg_pc_481f25;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5248: [0x481f04,0x481f27), 10 instructions. */
kg_pc_481f04: STEP(0x481f04); /* add ecx, esi */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481f06: STEP(0x481f06); /* add ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481f08: STEP(0x481f08); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481f0a: STEP(0x481f0a); /* movsxd rax, edx */
s->gpr[0] = (((s->gpr[3] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_481f0d: STEP(0x481f0d); /* lea rbx, [rip - 0x47abc4] */
s->gpr[1] = (UINT64_C(0xffffffffffb8543c) + (bias + UINT64_C(0x481f14)));
++s->steps;
kg_pc_481f14: STEP(0x481f14); /* movsxd rax, dword ptr [rbx + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[1] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_481f18: STEP(0x481f18); /* lea rdx, [rip - 0x9ed7] */
s->gpr[3] = (UINT64_C(0xffffffffffff6129) + (bias + UINT64_C(0x481f1f)));
++s->steps;
kg_pc_481f1f: STEP(0x481f1f); /* add rax, rdx */
x = s->gpr[0]; y = s->gpr[3];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_481f22: STEP(0x481f22); /* movsxd rdx, ecx */
s->gpr[3] = (((s->gpr[2] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_481f25: STEP(0x481f25); /* jmp rax */
x = s->gpr[0];
next_pc = x;
++s->steps;

break;
    case 10:
next_pc=bias+UINT64_C(0x481fac);
switch(s->pc-bias){
case UINT64_C(0x481f2a):goto kg_pc_481f2a;
case UINT64_C(0x481f2e):goto kg_pc_481f2e;
case UINT64_C(0x481f34):goto kg_pc_481f34;
case UINT64_C(0x481f3b):goto kg_pc_481f3b;
case UINT64_C(0x481f41):goto kg_pc_481f41;
case UINT64_C(0x481f44):goto kg_pc_481f44;
case UINT64_C(0x481f46):goto kg_pc_481f46;
case UINT64_C(0x481f4c):goto kg_pc_481f4c;
case UINT64_C(0x481f51):goto kg_pc_481f51;
case UINT64_C(0x481f53):goto kg_pc_481f53;
case UINT64_C(0x481f56):goto kg_pc_481f56;
case UINT64_C(0x481f5c):goto kg_pc_481f5c;
case UINT64_C(0x481f5e):goto kg_pc_481f5e;
case UINT64_C(0x481f61):goto kg_pc_481f61;
case UINT64_C(0x481f67):goto kg_pc_481f67;
case UINT64_C(0x481f6d):goto kg_pc_481f6d;
case UINT64_C(0x481f70):goto kg_pc_481f70;
case UINT64_C(0x481f72):goto kg_pc_481f72;
case UINT64_C(0x481f78):goto kg_pc_481f78;
case UINT64_C(0x481f7e):goto kg_pc_481f7e;
case UINT64_C(0x481f81):goto kg_pc_481f81;
case UINT64_C(0x481f83):goto kg_pc_481f83;
case UINT64_C(0x481f86):goto kg_pc_481f86;
case UINT64_C(0x481f89):goto kg_pc_481f89;
case UINT64_C(0x481f8e):goto kg_pc_481f8e;
case UINT64_C(0x481f93):goto kg_pc_481f93;
case UINT64_C(0x481f95):goto kg_pc_481f95;
case UINT64_C(0x481f9f):goto kg_pc_481f9f;
case UINT64_C(0x481fa6):goto kg_pc_481fa6;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5249: [0x481f2a,0x481fac), 29 instructions. */
kg_pc_481f2a: STEP(0x481f2a); /* mov rsi, qword ptr [rbp - 0x40] */
READ(a, (UINT64_C(0xffffffffffffffc0) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_481f2e: STEP(0x481f2e); /* xor esi, 0xf49badf */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xf49badf);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481f34: STEP(0x481f34); /* mov rdi, qword ptr [rbp - 0x120] */
READ(a, (UINT64_C(0xfffffffffffffee0) + s->gpr[6]), 8);
s->gpr[5] = a;
++s->steps;
kg_pc_481f3b: STEP(0x481f3b); /* xor edi, 0x66e981c5 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x66e981c5);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481f41: STEP(0x481f41); /* lea eax, [rdi + rsi] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_481f44: STEP(0x481f44); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481f46: STEP(0x481f46); /* xor ecx, 0xdcbeabce */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xdcbeabce);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481f4c: STEP(0x481f4c); /* and eax, 0xdcbeabce */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xdcbeabce);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481f51: STEP(0x481f51); /* and edi, esi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481f53: STEP(0x481f53); /* lea esi, [rdi + rdi] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_481f56: STEP(0x481f56); /* and esi, 0x42f2f8ec */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x42f2f8ec);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481f5c: STEP(0x481f5c); /* sub edi, esi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_481f5e: STEP(0x481f5e); /* lea esi, [rdi + rdi] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_481f61: STEP(0x481f61); /* add esi, 0xc2f2f8ec */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xc2f2f8ec);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481f67: STEP(0x481f67); /* xor esi, 0x3d0d0712 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x3d0d0712);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481f6d: STEP(0x481f6d); /* add esi, 2 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x2);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481f70: STEP(0x481f70); /* mov edi, esi */
s->gpr[5] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481f72: STEP(0x481f72); /* xor edi, 0x5f7b5bbe */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x5f7b5bbe);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_481f78: STEP(0x481f78); /* and esi, 0xdf7b5bbe */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xdf7b5bbe);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481f7e: STEP(0x481f7e); /* lea eax, [rcx + rax*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_481f81: STEP(0x481f81); /* add eax, edi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481f83: STEP(0x481f83); /* lea esi, [rax + rsi*2] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[4] * UINT64_C(0x2))));
++s->steps;
kg_pc_481f86: STEP(0x481f86); /* lea eax, [rsi + rsi] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_481f89: STEP(0x481f89); /* add eax, 0x878bf0e8 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x878bf0e8);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_481f8e: STEP(0x481f8e); /* and eax, 0xd3407634 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xd3407634);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_481f93: STEP(0x481f93); /* sub esi, eax */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_481f95: STEP(0x481f95); /* cmp dword ptr [rbp - 0x530], 0x77659280 */
READ(a, (UINT64_C(0xfffffffffffffad0) + s->gpr[6]), 4);
x = a; y = UINT64_C(0x77659280);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_481f9f: STEP(0x481f9f); /* mov rax, qword ptr [rbp - 0x100] */
READ(a, (UINT64_C(0xffffffffffffff00) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_481fa6: STEP(0x481fa6); /* jne 0x477fb8 */
next_pc = bias + (condition(s, COND_NE) ? UINT64_C(0x477fb8) : UINT64_C(0x481fac));
++s->steps;

break;
    case 11:
next_pc=bias+UINT64_C(0x481fc9);
switch(s->pc-bias){
case UINT64_C(0x481fac):goto kg_pc_481fac;
case UINT64_C(0x481faf):goto kg_pc_481faf;
case UINT64_C(0x481fb6):goto kg_pc_481fb6;
case UINT64_C(0x481fbc):goto kg_pc_481fbc;
case UINT64_C(0x481fbe):goto kg_pc_481fbe;
case UINT64_C(0x481fc4):goto kg_pc_481fc4;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5250: [0x481fac,0x481fc9), 6 instructions. */
kg_pc_481fac: STEP(0x481fac); /* mov r8d, eax */
s->gpr[8] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481faf: STEP(0x481faf); /* mov r9d, dword ptr [rbp - 0x2d0] */
READ(a, (UINT64_C(0xfffffffffffffd30) + s->gpr[6]), 4);
s->gpr[9] = (uint32_t)(a);
++s->steps;
kg_pc_481fb6: STEP(0x481fb6); /* mov edi, dword ptr [rbp - 0x280] */
READ(a, (UINT64_C(0xfffffffffffffd80) + s->gpr[6]), 4);
s->gpr[5] = (uint32_t)(a);
++s->steps;
kg_pc_481fbc: STEP(0x481fbc); /* mov eax, edi */
s->gpr[0] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_481fbe: STEP(0x481fbe); /* mov edi, dword ptr [rbp - 0x5a0] */
READ(a, (UINT64_C(0xfffffffffffffa60) + s->gpr[6]), 4);
s->gpr[5] = (uint32_t)(a);
++s->steps;
kg_pc_481fc4: STEP(0x481fc4); /* jmp 0x477fcc */
x = (bias + UINT64_C(0x477fcc));
next_pc = x;
++s->steps;

break;
    case 12:
next_pc=bias+UINT64_C(0x481fe5);
switch(s->pc-bias){
case UINT64_C(0x481fca):goto kg_pc_481fca;
case UINT64_C(0x481fce):goto kg_pc_481fce;
case UINT64_C(0x481fd5):goto kg_pc_481fd5;
case UINT64_C(0x481fd9):goto kg_pc_481fd9;
case UINT64_C(0x481fe0):goto kg_pc_481fe0;
case UINT64_C(0x481fe3):goto kg_pc_481fe3;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5251: [0x481fca,0x481fe5), 6 instructions. */
kg_pc_481fca: STEP(0x481fca); /* lea r9d, [rdx + 7] */
s->gpr[9] = (uint32_t)((UINT64_C(0x7) + s->gpr[3]));
++s->steps;
kg_pc_481fce: STEP(0x481fce); /* mov rdi, qword ptr [rbp - 0x990] */
READ(a, (UINT64_C(0xfffffffffffff670) + s->gpr[6]), 8);
s->gpr[5] = a;
++s->steps;
kg_pc_481fd5: STEP(0x481fd5); /* movsxd rax, dword ptr [rbx + rdx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[1] + (s->gpr[3] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_481fd9: STEP(0x481fd9); /* lea rcx, [rip - 0x16] */
s->gpr[2] = (UINT64_C(0xffffffffffffffea) + (bias + UINT64_C(0x481fe0)));
++s->steps;
kg_pc_481fe0: STEP(0x481fe0); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_481fe3: STEP(0x481fe3); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 13:
next_pc=bias+UINT64_C(0x481ff7);
switch(s->pc-bias){
case UINT64_C(0x481fe7):goto kg_pc_481fe7;
case UINT64_C(0x481fea):goto kg_pc_481fea;
case UINT64_C(0x481fee):goto kg_pc_481fee;
case UINT64_C(0x481ff5):goto kg_pc_481ff5;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5252: [0x481fe7,0x481ff7), 4 instructions. */
kg_pc_481fe7: STEP(0x481fe7); /* mov r14, r9 */
s->gpr[14] = s->gpr[9];
++s->steps;
kg_pc_481fea: STEP(0x481fea); /* lea r15d, [r9 - 2] */
s->gpr[15] = (uint32_t)((UINT64_C(0xfffffffffffffffe) + s->gpr[9]));
++s->steps;
kg_pc_481fee: STEP(0x481fee); /* mov rbx, qword ptr [rbp - 0xf28] */
READ(a, (UINT64_C(0xfffffffffffff0d8) + s->gpr[6]), 8);
s->gpr[1] = a;
++s->steps;
kg_pc_481ff5: STEP(0x481ff5); /* call rbx */
x = s->gpr[1];
y = s->gpr[7] - 8;
WRITE(y, 8, bias + UINT64_C(0x481ff7));
s->gpr[7] = y;
next_pc = x;
++s->steps;

break;
    case 14:
next_pc=bias+UINT64_C(0x482000);
switch(s->pc-bias){
case UINT64_C(0x481ff7):goto kg_pc_481ff7;
case UINT64_C(0x481ffe):goto kg_pc_481ffe;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5253: [0x481ff7,0x482000), 2 instructions. */
kg_pc_481ff7: STEP(0x481ff7); /* mov rdi, qword ptr [rbp - 0x498] */
READ(a, (UINT64_C(0xfffffffffffffb68) + s->gpr[6]), 8);
s->gpr[5] = a;
++s->steps;
kg_pc_481ffe: STEP(0x481ffe); /* call rbx */
x = s->gpr[1];
y = s->gpr[7] - 8;
WRITE(y, 8, bias + UINT64_C(0x482000));
s->gpr[7] = y;
next_pc = x;
++s->steps;

break;
    case 15:
next_pc=bias+UINT64_C(0x48204b);
switch(s->pc-bias){
case UINT64_C(0x482000):goto kg_pc_482000;
case UINT64_C(0x482003):goto kg_pc_482003;
case UINT64_C(0x48200b):goto kg_pc_48200b;
case UINT64_C(0x482010):goto kg_pc_482010;
case UINT64_C(0x482014):goto kg_pc_482014;
case UINT64_C(0x48201c):goto kg_pc_48201c;
case UINT64_C(0x482020):goto kg_pc_482020;
case UINT64_C(0x482027):goto kg_pc_482027;
case UINT64_C(0x48202a):goto kg_pc_48202a;
case UINT64_C(0x482031):goto kg_pc_482031;
case UINT64_C(0x482034):goto kg_pc_482034;
case UINT64_C(0x482038):goto kg_pc_482038;
case UINT64_C(0x48203f):goto kg_pc_48203f;
case UINT64_C(0x482042):goto kg_pc_482042;
case UINT64_C(0x482049):goto kg_pc_482049;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5254: [0x482000,0x48204b), 15 instructions. */
kg_pc_482000: STEP(0x482000); /* xor r13d, r13d */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[13] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482003: STEP(0x482003); /* cmp qword ptr [rbp - 0x9f0], 0 */
READ(a, (UINT64_C(0xfffffffffffff610) + s->gpr[6]), 8);
x = a; y = UINT64_C(0x0);
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_48200b: STEP(0x48200b); /* mov eax, 0xffff587b */
s->gpr[0] = (uint32_t)(UINT64_C(0xffff587b));
++s->steps;
kg_pc_482010: STEP(0x482010); /* cmove r13d, eax */
s->gpr[13] = (uint32_t)((condition(s, COND_E) ? (s->gpr[0] & UINT64_C(0xffffffff)) : (s->gpr[13] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_482014: STEP(0x482014); /* cmp qword ptr [rbp - 0x9a0], 0 */
READ(a, (UINT64_C(0xfffffffffffff660) + s->gpr[6]), 8);
x = a; y = UINT64_C(0x0);
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_48201c: STEP(0x48201c); /* cmove r13d, eax */
s->gpr[13] = (uint32_t)((condition(s, COND_E) ? (s->gpr[0] & UINT64_C(0xffffffff)) : (s->gpr[13] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_482020: STEP(0x482020); /* mov r12, qword ptr [rbp - 0x710] */
READ(a, (UINT64_C(0xfffffffffffff8f0) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_482027: STEP(0x482027); /* movsxd rax, r14d */
s->gpr[0] = (((s->gpr[14] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48202a: STEP(0x48202a); /* lea rcx, [rip - 0x47ace1] */
s->gpr[2] = (UINT64_C(0xffffffffffb8531f) + (bias + UINT64_C(0x482031)));
++s->steps;
kg_pc_482031: STEP(0x482031); /* mov r14, rcx */
s->gpr[14] = s->gpr[2];
++s->steps;
kg_pc_482034: STEP(0x482034); /* movsxd rax, dword ptr [rcx + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482038: STEP(0x482038); /* lea rcx, [rip - 0x58] */
s->gpr[2] = (UINT64_C(0xffffffffffffffa8) + (bias + UINT64_C(0x48203f)));
++s->steps;
kg_pc_48203f: STEP(0x48203f); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482042: STEP(0x482042); /* mov rbx, qword ptr [rbp - 0x128] */
READ(a, (UINT64_C(0xfffffffffffffed8) + s->gpr[6]), 8);
s->gpr[1] = a;
++s->steps;
kg_pc_482049: STEP(0x482049); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 16:
next_pc=bias+UINT64_C(0x4820a1);
switch(s->pc-bias){
case UINT64_C(0x48204e):goto kg_pc_48204e;
case UINT64_C(0x482052):goto kg_pc_482052;
case UINT64_C(0x482059):goto kg_pc_482059;
case UINT64_C(0x48205b):goto kg_pc_48205b;
case UINT64_C(0x48205d):goto kg_pc_48205d;
case UINT64_C(0x482060):goto kg_pc_482060;
case UINT64_C(0x482063):goto kg_pc_482063;
case UINT64_C(0x482066):goto kg_pc_482066;
case UINT64_C(0x482069):goto kg_pc_482069;
case UINT64_C(0x48206e):goto kg_pc_48206e;
case UINT64_C(0x482074):goto kg_pc_482074;
case UINT64_C(0x482078):goto kg_pc_482078;
case UINT64_C(0x48207b):goto kg_pc_48207b;
case UINT64_C(0x48207e):goto kg_pc_48207e;
case UINT64_C(0x482081):goto kg_pc_482081;
case UINT64_C(0x482084):goto kg_pc_482084;
case UINT64_C(0x482087):goto kg_pc_482087;
case UINT64_C(0x48208a):goto kg_pc_48208a;
case UINT64_C(0x48208e):goto kg_pc_48208e;
case UINT64_C(0x482095):goto kg_pc_482095;
case UINT64_C(0x482098):goto kg_pc_482098;
case UINT64_C(0x48209f):goto kg_pc_48209f;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5255: [0x48204e,0x4820a1), 22 instructions. */
kg_pc_48204e: STEP(0x48204e); /* add r12, -0x10 */
x = s->gpr[12]; y = UINT64_C(0xfffffffffffffff0);
s->gpr[12] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482052: STEP(0x482052); /* mov qword ptr [rbp - 0x710], r12 */
WRITE((UINT64_C(0xfffffffffffff8f0) + s->gpr[6]), 8, s->gpr[12]);
++s->steps;
kg_pc_482059: STEP(0x482059); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48205b: STEP(0x48205b); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48205d: STEP(0x48205d); /* test r13d, r13d */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[13] & UINT64_C(0xffffffff));
(void)operation(s, OP_AND, x, y, 32);
++s->steps;
kg_pc_482060: STEP(0x482060); /* setne al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482063: STEP(0x482063); /* sete dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482066: STEP(0x482066); /* lea ecx, [rdx + rdx*4] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x4))));
++s->steps;
kg_pc_482069: STEP(0x482069); /* mov esi, 0xe982a16 */
s->gpr[4] = (uint32_t)(UINT64_C(0xe982a16));
++s->steps;
kg_pc_48206e: STEP(0x48206e); /* mov r13d, 0xe982a02 */
s->gpr[13] = (uint32_t)(UINT64_C(0xe982a02));
++s->steps;
kg_pc_482074: STEP(0x482074); /* cmove r13d, esi */
s->gpr[13] = (uint32_t)((condition(s, COND_E) ? (s->gpr[4] & UINT64_C(0xffffffff)) : (s->gpr[13] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_482078: STEP(0x482078); /* lea eax, [rax + rax*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_48207b: STEP(0x48207b); /* add eax, r15d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[15] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48207e: STEP(0x48207e); /* lea ecx, [rax + rcx*2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x2))));
++s->steps;
kg_pc_482081: STEP(0x482081); /* add edx, r15d */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[15] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482084: STEP(0x482084); /* movsxd rax, edx */
s->gpr[0] = (((s->gpr[3] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482087: STEP(0x482087); /* mov r11, r14 */
s->gpr[11] = s->gpr[14];
++s->steps;
kg_pc_48208a: STEP(0x48208a); /* movsxd rax, dword ptr [r14 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[14] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48208e: STEP(0x48208e); /* lea rdx, [rip - 0x47] */
s->gpr[3] = (UINT64_C(0xffffffffffffffb9) + (bias + UINT64_C(0x482095)));
++s->steps;
kg_pc_482095: STEP(0x482095); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482098: STEP(0x482098); /* mov r12, qword ptr [rbp - 0x110] */
READ(a, (UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_48209f: STEP(0x48209f); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 17:
next_pc=bias+UINT64_C(0x48213d);
switch(s->pc-bias){
case UINT64_C(0x4820a4):goto kg_pc_4820a4;
case UINT64_C(0x4820ab):goto kg_pc_4820ab;
case UINT64_C(0x4820b5):goto kg_pc_4820b5;
case UINT64_C(0x4820b9):goto kg_pc_4820b9;
case UINT64_C(0x4820bb):goto kg_pc_4820bb;
case UINT64_C(0x4820bf):goto kg_pc_4820bf;
case UINT64_C(0x4820c4):goto kg_pc_4820c4;
case UINT64_C(0x4820c9):goto kg_pc_4820c9;
case UINT64_C(0x4820cc):goto kg_pc_4820cc;
case UINT64_C(0x4820d2):goto kg_pc_4820d2;
case UINT64_C(0x4820d8):goto kg_pc_4820d8;
case UINT64_C(0x4820da):goto kg_pc_4820da;
case UINT64_C(0x4820e0):goto kg_pc_4820e0;
case UINT64_C(0x4820e6):goto kg_pc_4820e6;
case UINT64_C(0x4820e8):goto kg_pc_4820e8;
case UINT64_C(0x4820ed):goto kg_pc_4820ed;
case UINT64_C(0x4820f1):goto kg_pc_4820f1;
case UINT64_C(0x4820f4):goto kg_pc_4820f4;
case UINT64_C(0x4820fa):goto kg_pc_4820fa;
case UINT64_C(0x4820fc):goto kg_pc_4820fc;
case UINT64_C(0x482101):goto kg_pc_482101;
case UINT64_C(0x482104):goto kg_pc_482104;
case UINT64_C(0x482106):goto kg_pc_482106;
case UINT64_C(0x482108):goto kg_pc_482108;
case UINT64_C(0x48210b):goto kg_pc_48210b;
case UINT64_C(0x482111):goto kg_pc_482111;
case UINT64_C(0x482114):goto kg_pc_482114;
case UINT64_C(0x482118):goto kg_pc_482118;
case UINT64_C(0x48211f):goto kg_pc_48211f;
case UINT64_C(0x482121):goto kg_pc_482121;
case UINT64_C(0x482123):goto kg_pc_482123;
case UINT64_C(0x482126):goto kg_pc_482126;
case UINT64_C(0x482128):goto kg_pc_482128;
case UINT64_C(0x48212b):goto kg_pc_48212b;
case UINT64_C(0x48212f):goto kg_pc_48212f;
case UINT64_C(0x482136):goto kg_pc_482136;
case UINT64_C(0x482139):goto kg_pc_482139;
case UINT64_C(0x48213b):goto kg_pc_48213b;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5256: [0x4820a4,0x48213d), 38 instructions. */
kg_pc_4820a4: STEP(0x4820a4); /* mov r10, qword ptr [rbp - 0x840] */
READ(a, (UINT64_C(0xfffffffffffff7c0) + s->gpr[6]), 8);
s->gpr[10] = a;
++s->steps;
kg_pc_4820ab: STEP(0x4820ab); /* movabs rax, 0x6f79466dab33c914 */
s->gpr[0] = UINT64_C(0x6f79466dab33c914);
++s->steps;
kg_pc_4820b5: STEP(0x4820b5); /* mov edx, dword ptr [r10 + rax] */
READ(a, (UINT64_C(0x0) + s->gpr[10] + (s->gpr[0] * UINT64_C(0x1))), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_4820b9: STEP(0x4820b9); /* mov eax, dword ptr [rbx] */
READ(a, (UINT64_C(0x0) + s->gpr[1]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_4820bb: STEP(0x4820bb); /* mov rsi, qword ptr [r12] */
READ(a, (UINT64_C(0x0) + s->gpr[12]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_4820bf: STEP(0x4820bf); /* and eax, 0x125515c8 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x125515c8);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4820c4: STEP(0x4820c4); /* mov edi, 0x7fffffff */
s->gpr[5] = (uint32_t)(UINT64_C(0x7fffffff));
++s->steps;
kg_pc_4820c9: STEP(0x4820c9); /* and edi, dword ptr [rsi + rax] */
READ(b, (UINT64_C(0x0) + s->gpr[4] + (s->gpr[0] * UINT64_C(0x1))), 4);
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = b;
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4820cc: STEP(0x4820cc); /* lea eax, [rdx - 0x67c6ada5] */
s->gpr[0] = (uint32_t)((UINT64_C(0xffffffff9839525b) + s->gpr[3]));
++s->steps;
kg_pc_4820d2: STEP(0x4820d2); /* xor edi, 0x40e3c417 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x40e3c417);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4820d8: STEP(0x4820d8); /* mov esi, edi */
s->gpr[4] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4820da: STEP(0x4820da); /* sub esi, dword ptr [rbp - 0x608] */
READ(b, (UINT64_C(0xfffffffffffff9f8) + s->gpr[6]), 4);
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = b;
s->gpr[4] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_4820e0: STEP(0x4820e0); /* imul esi, esi, 0x2ad0c043 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x2ad0c043);
s->gpr[4] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_4820e6: STEP(0x4820e6); /* cmp eax, esi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_4820e8: STEP(0x4820e8); /* mov esi, 0xe97836a */
s->gpr[4] = (uint32_t)(UINT64_C(0xe97836a));
++s->steps;
kg_pc_4820ed: STEP(0x4820ed); /* cmove esi, r13d */
s->gpr[4] = (uint32_t)((condition(s, COND_E) ? (s->gpr[13] & UINT64_C(0xffffffff)) : (s->gpr[4] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_4820f1: STEP(0x4820f1); /* sub edi, dword ptr [rbp - 0x48] */
READ(b, (UINT64_C(0xffffffffffffffb8) + s->gpr[6]), 4);
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = b;
s->gpr[5] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_4820f4: STEP(0x4820f4); /* imul edi, edi, 0x2ad0c043 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x2ad0c043);
s->gpr[5] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_4820fa: STEP(0x4820fa); /* cmp eax, edi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_4820fc: STEP(0x4820fc); /* mov edi, 0xe9829f2 */
s->gpr[5] = (uint32_t)(UINT64_C(0xe9829f2));
++s->steps;
kg_pc_482101: STEP(0x482101); /* cmovbe edi, esi */
s->gpr[5] = (uint32_t)((condition(s, COND_BE) ? (s->gpr[4] & UINT64_C(0xffffffff)) : (s->gpr[5] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_482104: STEP(0x482104); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482106: STEP(0x482106); /* xor esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482108: STEP(0x482108); /* mov r13d, edi */
s->gpr[13] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48210b: STEP(0x48210b); /* cmp edi, 0xe982a16 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xe982a16);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_482111: STEP(0x482111); /* setne al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482114: STEP(0x482114); /* sete sil */
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482118: STEP(0x482118); /* lea edi, [rax*8] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + (s->gpr[0] * UINT64_C(0x8))));
++s->steps;
kg_pc_48211f: STEP(0x48211f); /* sub eax, edi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_482121: STEP(0x482121); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482123: STEP(0x482123); /* lea eax, [rax + rsi*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[4] * UINT64_C(0x2))));
++s->steps;
kg_pc_482126: STEP(0x482126); /* add esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482128: STEP(0x482128); /* movsxd rcx, esi */
s->gpr[2] = (((s->gpr[4] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48212b: STEP(0x48212b); /* movsxd rcx, dword ptr [r11 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48212f: STEP(0x48212f); /* lea rsi, [rip - 0x92] */
s->gpr[4] = (UINT64_C(0xffffffffffffff6e) + (bias + UINT64_C(0x482136)));
++s->steps;
kg_pc_482136: STEP(0x482136); /* add rsi, rcx */
x = s->gpr[4]; y = s->gpr[2];
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482139: STEP(0x482139); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48213b: STEP(0x48213b); /* jmp rsi */
x = s->gpr[4];
next_pc = x;
++s->steps;

break;
    case 18:
next_pc=bias+UINT64_C(0x482196);
switch(s->pc-bias){
case UINT64_C(0x48213f):goto kg_pc_48213f;
case UINT64_C(0x482141):goto kg_pc_482141;
case UINT64_C(0x482147):goto kg_pc_482147;
case UINT64_C(0x482151):goto kg_pc_482151;
case UINT64_C(0x482155):goto kg_pc_482155;
case UINT64_C(0x482159):goto kg_pc_482159;
case UINT64_C(0x482160):goto kg_pc_482160;
case UINT64_C(0x482162):goto kg_pc_482162;
case UINT64_C(0x482164):goto kg_pc_482164;
case UINT64_C(0x48216b):goto kg_pc_48216b;
case UINT64_C(0x48216e):goto kg_pc_48216e;
case UINT64_C(0x482172):goto kg_pc_482172;
case UINT64_C(0x482175):goto kg_pc_482175;
case UINT64_C(0x482178):goto kg_pc_482178;
case UINT64_C(0x48217b):goto kg_pc_48217b;
case UINT64_C(0x48217d):goto kg_pc_48217d;
case UINT64_C(0x48217f):goto kg_pc_48217f;
case UINT64_C(0x482181):goto kg_pc_482181;
case UINT64_C(0x482185):goto kg_pc_482185;
case UINT64_C(0x48218c):goto kg_pc_48218c;
case UINT64_C(0x48218f):goto kg_pc_48218f;
case UINT64_C(0x482194):goto kg_pc_482194;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5257: [0x48213f,0x482196), 22 instructions. */
kg_pc_48213f: STEP(0x48213f); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482141: STEP(0x482141); /* cmp edx, 0x67c6ada5 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x67c6ada5);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_482147: STEP(0x482147); /* movabs rsi, 0x100000000 */
s->gpr[4] = UINT64_C(0x100000000);
++s->steps;
kg_pc_482151: STEP(0x482151); /* cmovb rcx, rsi */
s->gpr[2] = (condition(s, COND_B) ? s->gpr[4] : s->gpr[2]);
++s->steps;
kg_pc_482155: STEP(0x482155); /* lea r14, [rdx + rcx] */
s->gpr[14] = (UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x1)));
++s->steps;
kg_pc_482159: STEP(0x482159); /* add r14, -0x42aafb59 */
x = s->gpr[14]; y = UINT64_C(0xffffffffbd5504a7);
s->gpr[14] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482160: STEP(0x482160); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482162: STEP(0x482162); /* xor esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482164: STEP(0x482164); /* cmp r14, 0x251bb24c */
x = s->gpr[14]; y = UINT64_C(0x251bb24c);
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_48216b: STEP(0x48216b); /* setne dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48216e: STEP(0x48216e); /* sete sil */
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482172: STEP(0x482172); /* lea edi, [rsi + rsi*4] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x4))));
++s->steps;
kg_pc_482175: STEP(0x482175); /* lea edi, [rsi + rdi*2] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[5] * UINT64_C(0x2))));
++s->steps;
kg_pc_482178: STEP(0x482178); /* lea edi, [rdi + rdx*2] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_48217b: STEP(0x48217b); /* add edi, eax */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48217d: STEP(0x48217d); /* add eax, esi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48217f: STEP(0x48217f); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_482181: STEP(0x482181); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482185: STEP(0x482185); /* lea rdx, [rip - 0x4d] */
s->gpr[3] = (UINT64_C(0xffffffffffffffb3) + (bias + UINT64_C(0x48218c)));
++s->steps;
kg_pc_48218c: STEP(0x48218c); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_48218f: STEP(0x48218f); /* mov eax, 0x16326527 */
s->gpr[0] = (uint32_t)(UINT64_C(0x16326527));
++s->steps;
kg_pc_482194: STEP(0x482194); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 19:
next_pc=bias+UINT64_C(0x4821e2);
switch(s->pc-bias){
case UINT64_C(0x482199):goto kg_pc_482199;
case UINT64_C(0x48219c):goto kg_pc_48219c;
case UINT64_C(0x4821a6):goto kg_pc_4821a6;
case UINT64_C(0x4821ad):goto kg_pc_4821ad;
case UINT64_C(0x4821b0):goto kg_pc_4821b0;
case UINT64_C(0x4821b3):goto kg_pc_4821b3;
case UINT64_C(0x4821b7):goto kg_pc_4821b7;
case UINT64_C(0x4821be):goto kg_pc_4821be;
case UINT64_C(0x4821c1):goto kg_pc_4821c1;
case UINT64_C(0x4821cb):goto kg_pc_4821cb;
case UINT64_C(0x4821ce):goto kg_pc_4821ce;
case UINT64_C(0x4821d0):goto kg_pc_4821d0;
case UINT64_C(0x4821d7):goto kg_pc_4821d7;
case UINT64_C(0x4821de):goto kg_pc_4821de;
case UINT64_C(0x4821e0):goto kg_pc_4821e0;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5258: [0x482199,0x4821e2), 15 instructions. */
kg_pc_482199: STEP(0x482199); /* mov r15, r11 */
s->gpr[15] = s->gpr[11];
++s->steps;
kg_pc_48219c: STEP(0x48219c); /* movabs r11, 0x9349b860979d76d3 */
s->gpr[11] = UINT64_C(0x9349b860979d76d3);
++s->steps;
kg_pc_4821a6: STEP(0x4821a6); /* add r11, qword ptr [rbp - 0x2d88] */
READ(b, (UINT64_C(0xffffffffffffd278) + s->gpr[6]), 8);
x = s->gpr[11]; y = b;
s->gpr[11] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4821ad: STEP(0x4821ad); /* movsxd rax, edi */
s->gpr[0] = (((s->gpr[5] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4821b0: STEP(0x4821b0); /* add edi, -8 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffffffffffffff8);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4821b3: STEP(0x4821b3); /* movsxd rsi, dword ptr [r15 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[15] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[4] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4821b7: STEP(0x4821b7); /* lea rax, [rip - 0x25] */
s->gpr[0] = (UINT64_C(0xffffffffffffffdb) + (bias + UINT64_C(0x4821be)));
++s->steps;
kg_pc_4821be: STEP(0x4821be); /* add rax, rsi */
x = s->gpr[0]; y = s->gpr[4];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4821c1: STEP(0x4821c1); /* movabs rsi, 0x6f79466dab33c84c */
s->gpr[4] = UINT64_C(0x6f79466dab33c84c);
++s->steps;
kg_pc_4821cb: STEP(0x4821cb); /* add r10, rsi */
x = s->gpr[10]; y = s->gpr[4];
s->gpr[10] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4821ce: STEP(0x4821ce); /* xor esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4821d0: STEP(0x4821d0); /* lea r9, [rip + 0xc] */
s->gpr[9] = (UINT64_C(0xc) + (bias + UINT64_C(0x4821d7)));
++s->steps;
kg_pc_4821d7: STEP(0x4821d7); /* lea r8, [rip + 0x60] */
s->gpr[8] = (UINT64_C(0x60) + (bias + UINT64_C(0x4821de)));
++s->steps;
kg_pc_4821de: STEP(0x4821de); /* mov ebx, edi */
s->gpr[1] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4821e0: STEP(0x4821e0); /* jmp rax */
x = s->gpr[0];
next_pc = x;
++s->steps;

break;
    case 20:
next_pc=bias+UINT64_C(0x48223c);
switch(s->pc-bias){
case UINT64_C(0x4821e3):goto kg_pc_4821e3;
case UINT64_C(0x4821e8):goto kg_pc_4821e8;
case UINT64_C(0x4821ea):goto kg_pc_4821ea;
case UINT64_C(0x4821f0):goto kg_pc_4821f0;
case UINT64_C(0x4821f3):goto kg_pc_4821f3;
case UINT64_C(0x4821f8):goto kg_pc_4821f8;
case UINT64_C(0x4821fa):goto kg_pc_4821fa;
case UINT64_C(0x482200):goto kg_pc_482200;
case UINT64_C(0x482202):goto kg_pc_482202;
case UINT64_C(0x482208):goto kg_pc_482208;
case UINT64_C(0x48220b):goto kg_pc_48220b;
case UINT64_C(0x48220d):goto kg_pc_48220d;
case UINT64_C(0x48220f):goto kg_pc_48220f;
case UINT64_C(0x482214):goto kg_pc_482214;
case UINT64_C(0x482216):goto kg_pc_482216;
case UINT64_C(0x482218):goto kg_pc_482218;
case UINT64_C(0x48221d):goto kg_pc_48221d;
case UINT64_C(0x482220):goto kg_pc_482220;
case UINT64_C(0x482223):goto kg_pc_482223;
case UINT64_C(0x482226):goto kg_pc_482226;
case UINT64_C(0x482229):goto kg_pc_482229;
case UINT64_C(0x48222b):goto kg_pc_48222b;
case UINT64_C(0x48222e):goto kg_pc_48222e;
case UINT64_C(0x482230):goto kg_pc_482230;
case UINT64_C(0x482233):goto kg_pc_482233;
case UINT64_C(0x482237):goto kg_pc_482237;
case UINT64_C(0x48223a):goto kg_pc_48223a;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5259: [0x4821e3,0x48223c), 27 instructions. */
kg_pc_4821e3: STEP(0x4821e3); /* movzx eax, byte ptr [r11 + rsi] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[4] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_4821e8: STEP(0x4821e8); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4821ea: STEP(0x4821ea); /* xor ecx, 0xf6fce7cc */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xf6fce7cc);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4821f0: STEP(0x4821f0); /* and eax, 0xffffffcc */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffcc);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4821f3: STEP(0x4821f3); /* movzx edx, byte ptr [r10 + rsi] */
READ(a, (UINT64_C(0x0) + s->gpr[10] + (s->gpr[4] * UINT64_C(0x1))), 1);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_4821f8: STEP(0x4821f8); /* mov edi, edx */
s->gpr[5] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4821fa: STEP(0x4821fa); /* xor edi, 0x80302046 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x80302046);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482200: STEP(0x482200); /* add edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482202: STEP(0x482202); /* and edx, 0x172 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x172);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_482208: STEP(0x482208); /* lea eax, [rcx + rax*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_48220b: STEP(0x48220b); /* add eax, edi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48220d: STEP(0x48220d); /* sub eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_48220f: STEP(0x48220f); /* add eax, 0x9f055d15 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x9f055d15);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482214: STEP(0x482214); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482216: STEP(0x482216); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482218: STEP(0x482218); /* cmp eax, 0x16326527 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x16326527);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_48221d: STEP(0x48221d); /* setne cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482220: STEP(0x482220); /* sete dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482223: STEP(0x482223); /* lea edi, [rdx + rdx*8] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x8))));
++s->steps;
kg_pc_482226: STEP(0x482226); /* lea ecx, [rcx + rcx*2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x2))));
++s->steps;
kg_pc_482229: STEP(0x482229); /* add ecx, ebx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48222b: STEP(0x48222b); /* lea edi, [rcx + rdi*2] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[5] * UINT64_C(0x2))));
++s->steps;
kg_pc_48222e: STEP(0x48222e); /* add edx, ebx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482230: STEP(0x482230); /* movsxd rcx, edx */
s->gpr[2] = (((s->gpr[3] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482233: STEP(0x482233); /* movsxd rcx, dword ptr [r15 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[15] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482237: STEP(0x482237); /* add rcx, r9 */
x = s->gpr[2]; y = s->gpr[9];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_48223a: STEP(0x48223a); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 21:
next_pc=bias+UINT64_C(0x48229f);
switch(s->pc-bias){
case UINT64_C(0x48223e):goto kg_pc_48223e;
case UINT64_C(0x482240):goto kg_pc_482240;
case UINT64_C(0x482247):goto kg_pc_482247;
case UINT64_C(0x48224a):goto kg_pc_48224a;
case UINT64_C(0x482251):goto kg_pc_482251;
case UINT64_C(0x482258):goto kg_pc_482258;
case UINT64_C(0x48225b):goto kg_pc_48225b;
case UINT64_C(0x48225d):goto kg_pc_48225d;
case UINT64_C(0x48225f):goto kg_pc_48225f;
case UINT64_C(0x482262):goto kg_pc_482262;
case UINT64_C(0x482265):goto kg_pc_482265;
case UINT64_C(0x482267):goto kg_pc_482267;
case UINT64_C(0x48226a):goto kg_pc_48226a;
case UINT64_C(0x48226d):goto kg_pc_48226d;
case UINT64_C(0x48226f):goto kg_pc_48226f;
case UINT64_C(0x482272):goto kg_pc_482272;
case UINT64_C(0x482275):goto kg_pc_482275;
case UINT64_C(0x482278):goto kg_pc_482278;
case UINT64_C(0x48227b):goto kg_pc_48227b;
case UINT64_C(0x48227d):goto kg_pc_48227d;
case UINT64_C(0x482280):goto kg_pc_482280;
case UINT64_C(0x482282):goto kg_pc_482282;
case UINT64_C(0x482284):goto kg_pc_482284;
case UINT64_C(0x482286):goto kg_pc_482286;
case UINT64_C(0x482288):goto kg_pc_482288;
case UINT64_C(0x48228b):goto kg_pc_48228b;
case UINT64_C(0x48228f):goto kg_pc_48228f;
case UINT64_C(0x482292):goto kg_pc_482292;
case UINT64_C(0x482296):goto kg_pc_482296;
case UINT64_C(0x48229b):goto kg_pc_48229b;
case UINT64_C(0x48229d):goto kg_pc_48229d;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5260: [0x48223e,0x48229f), 31 instructions. */
kg_pc_48223e: STEP(0x48223e); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482240: STEP(0x482240); /* cmp r14, 0x251bb24c */
x = s->gpr[14]; y = UINT64_C(0x251bb24c);
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_482247: STEP(0x482247); /* setb al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48224a: STEP(0x48224a); /* lea rbx, [rsi + 0x251bb24d] */
s->gpr[1] = (UINT64_C(0x251bb24d) + s->gpr[4]);
++s->steps;
kg_pc_482251: STEP(0x482251); /* cmp rbx, 0x251bb24c */
x = s->gpr[1]; y = UINT64_C(0x251bb24c);
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_482258: STEP(0x482258); /* setb dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48225b: STEP(0x48225b); /* xor dl, al */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48225d: STEP(0x48225d); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48225f: STEP(0x48225f); /* cmp rbx, r14 */
x = s->gpr[1]; y = s->gpr[14];
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_482262: STEP(0x482262); /* setb cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482265: STEP(0x482265); /* test dl, dl */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
(void)operation(s, OP_AND, x, y, 8);
++s->steps;
kg_pc_482267: STEP(0x482267); /* cmove eax, ecx */
s->gpr[0] = (uint32_t)((condition(s, COND_E) ? (s->gpr[2] & UINT64_C(0xffffffff)) : (s->gpr[0] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_48226a: STEP(0x48226a); /* movzx eax, al */
s->gpr[0] = (uint32_t)((s->gpr[0] & UINT64_C(0xff)));
++s->steps;
kg_pc_48226d: STEP(0x48226d); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48226f: STEP(0x48226f); /* xor cl, 1 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x1);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482272: STEP(0x482272); /* movzx ebx, cl */
s->gpr[1] = (uint32_t)((s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_482275: STEP(0x482275); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_482278: STEP(0x482278); /* lea ecx, [rcx + rcx*8] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x8))));
++s->steps;
kg_pc_48227b: STEP(0x48227b); /* mov edx, ebx */
s->gpr[3] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48227d: STEP(0x48227d); /* shl edx, 4 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x4);
s->gpr[3] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_482280: STEP(0x482280); /* sub ebx, edx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_482282: STEP(0x482282); /* sub ebx, ecx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_482284: STEP(0x482284); /* add ebx, edi */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482286: STEP(0x482286); /* add edi, eax */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482288: STEP(0x482288); /* movsxd rax, edi */
s->gpr[0] = (((s->gpr[5] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48228b: STEP(0x48228b); /* movsxd rcx, dword ptr [r15 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[15] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48228f: STEP(0x48228f); /* add rcx, r8 */
x = s->gpr[2]; y = s->gpr[8];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482292: STEP(0x482292); /* add rsi, 1 */
x = s->gpr[4]; y = UINT64_C(0x1);
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482296: STEP(0x482296); /* mov eax, 0x16326527 */
s->gpr[0] = (uint32_t)(UINT64_C(0x16326527));
++s->steps;
kg_pc_48229b: STEP(0x48229b); /* mov edi, ebx */
s->gpr[5] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48229d: STEP(0x48229d); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 22:
next_pc=bias+UINT64_C(0x4822c0);
switch(s->pc-bias){
case UINT64_C(0x4822a0):goto kg_pc_4822a0;
case UINT64_C(0x4822a3):goto kg_pc_4822a3;
case UINT64_C(0x4822a6):goto kg_pc_4822a6;
case UINT64_C(0x4822aa):goto kg_pc_4822aa;
case UINT64_C(0x4822b1):goto kg_pc_4822b1;
case UINT64_C(0x4822b4):goto kg_pc_4822b4;
case UINT64_C(0x4822bb):goto kg_pc_4822bb;
case UINT64_C(0x4822be):goto kg_pc_4822be;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5261: [0x4822a0,0x4822c0), 8 instructions. */
kg_pc_4822a0: STEP(0x4822a0); /* movsxd rcx, edi */
s->gpr[2] = (((s->gpr[5] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4822a3: STEP(0x4822a3); /* add edi, 0xe */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xe);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4822a6: STEP(0x4822a6); /* movsxd rcx, dword ptr [r15 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[15] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4822aa: STEP(0x4822aa); /* lea rdx, [rip - 0x11] */
s->gpr[3] = (UINT64_C(0xffffffffffffffef) + (bias + UINT64_C(0x4822b1)));
++s->steps;
kg_pc_4822b1: STEP(0x4822b1); /* add rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4822b4: STEP(0x4822b4); /* mov r12, qword ptr [rbp - 0x110] */
READ(a, (UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_4822bb: STEP(0x4822bb); /* mov r11, r15 */
s->gpr[11] = s->gpr[15];
++s->steps;
kg_pc_4822be: STEP(0x4822be); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 23:
next_pc=bias+UINT64_C(0x4822ec);
switch(s->pc-bias){
case UINT64_C(0x4822c2):goto kg_pc_4822c2;
case UINT64_C(0x4822c5):goto kg_pc_4822c5;
case UINT64_C(0x4822ca):goto kg_pc_4822ca;
case UINT64_C(0x4822cf):goto kg_pc_4822cf;
case UINT64_C(0x4822d5):goto kg_pc_4822d5;
case UINT64_C(0x4822d9):goto kg_pc_4822d9;
case UINT64_C(0x4822dc):goto kg_pc_4822dc;
case UINT64_C(0x4822e0):goto kg_pc_4822e0;
case UINT64_C(0x4822e7):goto kg_pc_4822e7;
case UINT64_C(0x4822ea):goto kg_pc_4822ea;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5262: [0x4822c2,0x4822ec), 10 instructions. */
kg_pc_4822c2: STEP(0x4822c2); /* lea ecx, [rdi - 0x14] */
s->gpr[2] = (uint32_t)((UINT64_C(0xffffffffffffffec) + s->gpr[5]));
++s->steps;
kg_pc_4822c5: STEP(0x4822c5); /* cmp eax, 0x16326527 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x16326527);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_4822ca: STEP(0x4822ca); /* mov eax, 0xe982a16 */
s->gpr[0] = (uint32_t)(UINT64_C(0xe982a16));
++s->steps;
kg_pc_4822cf: STEP(0x4822cf); /* mov r13d, 0xe97836a */
s->gpr[13] = (uint32_t)(UINT64_C(0xe97836a));
++s->steps;
kg_pc_4822d5: STEP(0x4822d5); /* cmove r13d, eax */
s->gpr[13] = (uint32_t)((condition(s, COND_E) ? (s->gpr[0] & UINT64_C(0xffffffff)) : (s->gpr[13] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_4822d9: STEP(0x4822d9); /* movsxd rax, edi */
s->gpr[0] = (((s->gpr[5] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4822dc: STEP(0x4822dc); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4822e0: STEP(0x4822e0); /* lea rdx, [rip - 0x25] */
s->gpr[3] = (UINT64_C(0xffffffffffffffdb) + (bias + UINT64_C(0x4822e7)));
++s->steps;
kg_pc_4822e7: STEP(0x4822e7); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4822ea: STEP(0x4822ea); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 24:
next_pc=bias+UINT64_C(0x482340);
switch(s->pc-bias){
case UINT64_C(0x4822ee):goto kg_pc_4822ee;
case UINT64_C(0x4822f5):goto kg_pc_4822f5;
case UINT64_C(0x4822ff):goto kg_pc_4822ff;
case UINT64_C(0x482302):goto kg_pc_482302;
case UINT64_C(0x48230c):goto kg_pc_48230c;
case UINT64_C(0x48230e):goto kg_pc_48230e;
case UINT64_C(0x482310):goto kg_pc_482310;
case UINT64_C(0x482313):goto kg_pc_482313;
case UINT64_C(0x482317):goto kg_pc_482317;
case UINT64_C(0x48231b):goto kg_pc_48231b;
case UINT64_C(0x48231e):goto kg_pc_48231e;
case UINT64_C(0x482322):goto kg_pc_482322;
case UINT64_C(0x482325):goto kg_pc_482325;
case UINT64_C(0x482328):goto kg_pc_482328;
case UINT64_C(0x48232a):goto kg_pc_48232a;
case UINT64_C(0x48232d):goto kg_pc_48232d;
case UINT64_C(0x482331):goto kg_pc_482331;
case UINT64_C(0x482338):goto kg_pc_482338;
case UINT64_C(0x48233b):goto kg_pc_48233b;
case UINT64_C(0x48233e):goto kg_pc_48233e;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5263: [0x4822ee,0x482340), 20 instructions. */
kg_pc_4822ee: STEP(0x4822ee); /* mov rax, qword ptr [rbp - 0x2d88] */
READ(a, (UINT64_C(0xffffffffffffd278) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_4822f5: STEP(0x4822f5); /* movabs rdx, 0x423e3288e1d0cf67 */
s->gpr[3] = UINT64_C(0x423e3288e1d0cf67);
++s->steps;
kg_pc_4822ff: STEP(0x4822ff); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482302: STEP(0x482302); /* movabs rbx, 0xaef47a284a335894 */
s->gpr[1] = UINT64_C(0xaef47a284a335894);
++s->steps;
kg_pc_48230c: STEP(0x48230c); /* xor edi, edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48230e: STEP(0x48230e); /* xor esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482310: STEP(0x482310); /* cmp rdx, rbx */
x = s->gpr[3]; y = s->gpr[1];
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_482313: STEP(0x482313); /* setne dil */
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482317: STEP(0x482317); /* sete sil */
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48231b: STEP(0x48231b); /* imul edx, esi, -0x5f */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffffffffffa1);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_48231e: STEP(0x48231e); /* lea r14d, [rdi + rdi*4] */
s->gpr[14] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x4))));
++s->steps;
kg_pc_482322: STEP(0x482322); /* add r14d, ecx */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[14] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482325: STEP(0x482325); /* add r14d, edx */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[14] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482328: STEP(0x482328); /* add esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48232a: STEP(0x48232a); /* movsxd rcx, esi */
s->gpr[2] = (((s->gpr[4] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48232d: STEP(0x48232d); /* movsxd rcx, dword ptr [r11 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482331: STEP(0x482331); /* lea rdx, [rip - 0x4a] */
s->gpr[3] = (UINT64_C(0xffffffffffffffb6) + (bias + UINT64_C(0x482338)));
++s->steps;
kg_pc_482338: STEP(0x482338); /* add rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_48233b: STEP(0x48233b); /* mov esi, r13d */
s->gpr[4] = (uint32_t)((s->gpr[13] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48233e: STEP(0x48233e); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 25:
next_pc=bias+UINT64_C(0x4823a7);
switch(s->pc-bias){
case UINT64_C(0x482341):goto kg_pc_482341;
case UINT64_C(0x482345):goto kg_pc_482345;
case UINT64_C(0x48234f):goto kg_pc_48234f;
case UINT64_C(0x482352):goto kg_pc_482352;
case UINT64_C(0x482359):goto kg_pc_482359;
case UINT64_C(0x482360):goto kg_pc_482360;
case UINT64_C(0x482362):goto kg_pc_482362;
case UINT64_C(0x48236c):goto kg_pc_48236c;
case UINT64_C(0x48236e):goto kg_pc_48236e;
case UINT64_C(0x482374):goto kg_pc_482374;
case UINT64_C(0x482376):goto kg_pc_482376;
case UINT64_C(0x48237c):goto kg_pc_48237c;
case UINT64_C(0x482383):goto kg_pc_482383;
case UINT64_C(0x48238a):goto kg_pc_48238a;
case UINT64_C(0x482391):goto kg_pc_482391;
case UINT64_C(0x482393):goto kg_pc_482393;
case UINT64_C(0x482395):goto kg_pc_482395;
case UINT64_C(0x48239b):goto kg_pc_48239b;
case UINT64_C(0x4823a1):goto kg_pc_4823a1;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5264: [0x482341,0x4823a7), 19 instructions. */
kg_pc_482341: STEP(0x482341); /* lea ebx, [r14 - 0x64] */
s->gpr[1] = (uint32_t)((UINT64_C(0xffffffffffffff9c) + s->gpr[14]));
++s->steps;
kg_pc_482345: STEP(0x482345); /* movabs rcx, 0x9349b860979d76d3 */
s->gpr[2] = UINT64_C(0x9349b860979d76d3);
++s->steps;
kg_pc_48234f: STEP(0x48234f); /* add rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482352: STEP(0x482352); /* lea ecx, [r14 - 0x20df] */
s->gpr[2] = (uint32_t)((UINT64_C(0xffffffffffffdf21) + s->gpr[14]));
++s->steps;
kg_pc_482359: STEP(0x482359); /* lea rdi, [rbp - 0x1f8] */
s->gpr[5] = (UINT64_C(0xfffffffffffffe08) + s->gpr[6]);
++s->steps;
kg_pc_482360: STEP(0x482360); /* mov edx, edi */
s->gpr[3] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_482362: STEP(0x482362); /* movabs rsi, 0xd7cf669026532472 */
s->gpr[4] = UINT64_C(0xd7cf669026532472);
++s->steps;
kg_pc_48236c: STEP(0x48236c); /* xor edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48236e: STEP(0x48236e); /* imul edx, edx, 0x20bd8b7f */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x20bd8b7f);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_482374: STEP(0x482374); /* xor ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482376: STEP(0x482376); /* mov dword ptr [rbp - 0x1e8], ecx */
WRITE((UINT64_C(0xfffffffffffffe18) + s->gpr[6]), 4, (s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48237c: STEP(0x48237c); /* mov qword ptr [rbp - 0x1f0], rax */
WRITE((UINT64_C(0xfffffffffffffe10) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_482383: STEP(0x482383); /* lea rax, [rip - 0x2e197f] */
s->gpr[0] = (UINT64_C(0xffffffffffd1e681) + (bias + UINT64_C(0x48238a)));
++s->steps;
kg_pc_48238a: STEP(0x48238a); /* lea rcx, [rip - 0x2e18f2] */
s->gpr[2] = (UINT64_C(0xffffffffffd1e70e) + (bias + UINT64_C(0x482391)));
++s->steps;
kg_pc_482391: STEP(0x482391); /* sub ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_482393: STEP(0x482393); /* sub ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_482395: STEP(0x482395); /* add ecx, 0x8fc */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x8fc);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48239b: STEP(0x48239b); /* mov dword ptr [rbp - 0x1f8], ecx */
WRITE((UINT64_C(0xfffffffffffffe08) + s->gpr[6]), 4, (s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4823a1: STEP(0x4823a1); /* call qword ptr [rbp - 0x458] */
READ(a, (UINT64_C(0xfffffffffffffba8) + s->gpr[6]), 8);
x = a;
y = s->gpr[7] - 8;
WRITE(y, 8, bias + UINT64_C(0x4823a7));
s->gpr[7] = y;
next_pc = x;
++s->steps;

break;
    case 26:
next_pc=bias+UINT64_C(0x4823c7);
switch(s->pc-bias){
case UINT64_C(0x4823a7):goto kg_pc_4823a7;
case UINT64_C(0x4823aa):goto kg_pc_4823aa;
case UINT64_C(0x4823b1):goto kg_pc_4823b1;
case UINT64_C(0x4823b4):goto kg_pc_4823b4;
case UINT64_C(0x4823b8):goto kg_pc_4823b8;
case UINT64_C(0x4823bf):goto kg_pc_4823bf;
case UINT64_C(0x4823c2):goto kg_pc_4823c2;
case UINT64_C(0x4823c5):goto kg_pc_4823c5;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5265: [0x4823a7,0x4823c7), 8 instructions. */
kg_pc_4823a7: STEP(0x4823a7); /* mov esi, r13d */
s->gpr[4] = (uint32_t)((s->gpr[13] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4823aa: STEP(0x4823aa); /* lea r11, [rip - 0x47b061] */
s->gpr[11] = (UINT64_C(0xffffffffffb84f9f) + (bias + UINT64_C(0x4823b1)));
++s->steps;
kg_pc_4823b1: STEP(0x4823b1); /* movsxd rax, r14d */
s->gpr[0] = (((s->gpr[14] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4823b4: STEP(0x4823b4); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4823b8: STEP(0x4823b8); /* lea rcx, [rip - 0x7e] */
s->gpr[2] = (UINT64_C(0xffffffffffffff82) + (bias + UINT64_C(0x4823bf)));
++s->steps;
kg_pc_4823bf: STEP(0x4823bf); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4823c2: STEP(0x4823c2); /* mov r14d, ebx */
s->gpr[14] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4823c5: STEP(0x4823c5); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 27:
next_pc=bias+UINT64_C(0x48240d);
switch(s->pc-bias){
case UINT64_C(0x4823c9):goto kg_pc_4823c9;
case UINT64_C(0x4823cf):goto kg_pc_4823cf;
case UINT64_C(0x4823d1):goto kg_pc_4823d1;
case UINT64_C(0x4823d3):goto kg_pc_4823d3;
case UINT64_C(0x4823d6):goto kg_pc_4823d6;
case UINT64_C(0x4823dc):goto kg_pc_4823dc;
case UINT64_C(0x4823df):goto kg_pc_4823df;
case UINT64_C(0x4823e2):goto kg_pc_4823e2;
case UINT64_C(0x4823e5):goto kg_pc_4823e5;
case UINT64_C(0x4823eb):goto kg_pc_4823eb;
case UINT64_C(0x4823ee):goto kg_pc_4823ee;
case UINT64_C(0x4823f0):goto kg_pc_4823f0;
case UINT64_C(0x4823f7):goto kg_pc_4823f7;
case UINT64_C(0x4823fa):goto kg_pc_4823fa;
case UINT64_C(0x4823fd):goto kg_pc_4823fd;
case UINT64_C(0x482401):goto kg_pc_482401;
case UINT64_C(0x482408):goto kg_pc_482408;
case UINT64_C(0x48240b):goto kg_pc_48240b;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5266: [0x4823c9,0x48240d), 18 instructions. */
kg_pc_4823c9: STEP(0x4823c9); /* mov dword ptr [rbp - 0x36f0], esi */
WRITE((UINT64_C(0xffffffffffffc910) + s->gpr[6]), 4, (s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4823cf: STEP(0x4823cf); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4823d1: STEP(0x4823d1); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4823d3: STEP(0x4823d3); /* mov r10d, esi */
s->gpr[10] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4823d6: STEP(0x4823d6); /* cmp esi, 0xe982a16 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xe982a16);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_4823dc: STEP(0x4823dc); /* setne al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4823df: STEP(0x4823df); /* sete dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4823e2: STEP(0x4823e2); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_4823e5: STEP(0x4823e5); /* imul ecx, eax, 0xffffe08b */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffe08b);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_4823eb: STEP(0x4823eb); /* add ecx, r14d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4823ee: STEP(0x4823ee); /* sub ecx, esi */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_4823f0: STEP(0x4823f0); /* mov r9d, dword ptr [rbp - 0x7e4] */
READ(a, (UINT64_C(0xfffffffffffff81c) + s->gpr[6]), 4);
s->gpr[9] = (uint32_t)(a);
++s->steps;
kg_pc_4823f7: STEP(0x4823f7); /* add edx, r14d */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4823fa: STEP(0x4823fa); /* movsxd rax, edx */
s->gpr[0] = (((s->gpr[3] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4823fd: STEP(0x4823fd); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482401: STEP(0x482401); /* lea rdx, [rip - 0x3f] */
s->gpr[3] = (UINT64_C(0xffffffffffffffc1) + (bias + UINT64_C(0x482408)));
++s->steps;
kg_pc_482408: STEP(0x482408); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_48240b: STEP(0x48240b); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 28:
next_pc=bias+UINT64_C(0x482454);
switch(s->pc-bias){
case UINT64_C(0x48240e):goto kg_pc_48240e;
case UINT64_C(0x482415):goto kg_pc_482415;
case UINT64_C(0x482418):goto kg_pc_482418;
case UINT64_C(0x48241b):goto kg_pc_48241b;
case UINT64_C(0x482423):goto kg_pc_482423;
case UINT64_C(0x482426):goto kg_pc_482426;
case UINT64_C(0x482428):goto kg_pc_482428;
case UINT64_C(0x48242b):goto kg_pc_48242b;
case UINT64_C(0x48242d):goto kg_pc_48242d;
case UINT64_C(0x482430):goto kg_pc_482430;
case UINT64_C(0x482433):goto kg_pc_482433;
case UINT64_C(0x482435):goto kg_pc_482435;
case UINT64_C(0x482438):goto kg_pc_482438;
case UINT64_C(0x48243b):goto kg_pc_48243b;
case UINT64_C(0x48243e):goto kg_pc_48243e;
case UINT64_C(0x482440):goto kg_pc_482440;
case UINT64_C(0x482442):goto kg_pc_482442;
case UINT64_C(0x482444):goto kg_pc_482444;
case UINT64_C(0x482448):goto kg_pc_482448;
case UINT64_C(0x48244f):goto kg_pc_48244f;
case UINT64_C(0x482452):goto kg_pc_482452;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5267: [0x48240e,0x482454), 21 instructions. */
kg_pc_48240e: STEP(0x48240e); /* mov r14, qword ptr [rbp - 0x13e0] */
READ(a, (UINT64_C(0xffffffffffffec20) + s->gpr[6]), 8);
s->gpr[14] = a;
++s->steps;
kg_pc_482415: STEP(0x482415); /* test r14, r14 */
x = s->gpr[14]; y = s->gpr[14];
(void)operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_482418: STEP(0x482418); /* sete al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48241b: STEP(0x48241b); /* cmp qword ptr [rbp - 0x1590], 0 */
READ(a, (UINT64_C(0xffffffffffffea70) + s->gpr[6]), 8);
x = a; y = UINT64_C(0x0);
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_482423: STEP(0x482423); /* sete dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482426: STEP(0x482426); /* or dl, al */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_OR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482428: STEP(0x482428); /* movzx eax, dl */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xff)));
++s->steps;
kg_pc_48242b: STEP(0x48242b); /* mov edx, eax */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48242d: STEP(0x48242d); /* xor dl, 1 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x1);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482430: STEP(0x482430); /* movzx edx, dl */
s->gpr[3] = (uint32_t)((s->gpr[3] & UINT64_C(0xff)));
++s->steps;
kg_pc_482433: STEP(0x482433); /* mov edi, eax */
s->gpr[5] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_482435: STEP(0x482435); /* shl edi, 4 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x4);
s->gpr[5] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_482438: STEP(0x482438); /* lea edx, [rdx + rdx*2] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_48243b: STEP(0x48243b); /* lea esi, [rcx + rdx*2] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_48243e: STEP(0x48243e); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482440: STEP(0x482440); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482442: STEP(0x482442); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_482444: STEP(0x482444); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482448: STEP(0x482448); /* lea rcx, [rip - 0x41] */
s->gpr[2] = (UINT64_C(0xffffffffffffffbf) + (bias + UINT64_C(0x48244f)));
++s->steps;
kg_pc_48244f: STEP(0x48244f); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482452: STEP(0x482452); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 29:
next_pc=bias+UINT64_C(0x482578);
switch(s->pc-bias){
case UINT64_C(0x48253b):goto kg_pc_48253b;
case UINT64_C(0x482542):goto kg_pc_482542;
case UINT64_C(0x482544):goto kg_pc_482544;
case UINT64_C(0x482547):goto kg_pc_482547;
case UINT64_C(0x48254a):goto kg_pc_48254a;
case UINT64_C(0x48254c):goto kg_pc_48254c;
case UINT64_C(0x48254f):goto kg_pc_48254f;
case UINT64_C(0x482552):goto kg_pc_482552;
case UINT64_C(0x482558):goto kg_pc_482558;
case UINT64_C(0x48255b):goto kg_pc_48255b;
case UINT64_C(0x48255d):goto kg_pc_48255d;
case UINT64_C(0x48255f):goto kg_pc_48255f;
case UINT64_C(0x482562):goto kg_pc_482562;
case UINT64_C(0x482566):goto kg_pc_482566;
case UINT64_C(0x48256d):goto kg_pc_48256d;
case UINT64_C(0x482570):goto kg_pc_482570;
case UINT64_C(0x482576):goto kg_pc_482576;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5268: [0x48253b,0x482578), 17 instructions. */
kg_pc_48253b: STEP(0x48253b); /* lea edi, [r9 - 0x8a9c5e8] */
s->gpr[5] = (uint32_t)((UINT64_C(0xfffffffff7563a18) + s->gpr[9]));
++s->steps;
kg_pc_482542: STEP(0x482542); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482544: STEP(0x482544); /* cmp edi, 0xa */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xa);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_482547: STEP(0x482547); /* setb al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48254a: STEP(0x48254a); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48254c: STEP(0x48254c); /* cmp edi, 9 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x9);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_48254f: STEP(0x48254f); /* seta dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_A)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482552: STEP(0x482552); /* imul ecx, edx, 0xffffe087 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffe087);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_482558: STEP(0x482558); /* lea ecx, [rcx + rax*2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_48255b: STEP(0x48255b); /* add ecx, esi */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48255d: STEP(0x48255d); /* add esi, edx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48255f: STEP(0x48255f); /* movsxd rax, esi */
s->gpr[0] = (((s->gpr[4] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482562: STEP(0x482562); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482566: STEP(0x482566); /* lea rdx, [rip - 0x32] */
s->gpr[3] = (UINT64_C(0xffffffffffffffce) + (bias + UINT64_C(0x48256d)));
++s->steps;
kg_pc_48256d: STEP(0x48256d); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482570: STEP(0x482570); /* mov r10d, 0xe97837b */
s->gpr[10] = (uint32_t)(UINT64_C(0xe97837b));
++s->steps;
kg_pc_482576: STEP(0x482576); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 30:
next_pc=bias+UINT64_C(0x482615);
switch(s->pc-bias){
case UINT64_C(0x48257a):goto kg_pc_48257a;
case UINT64_C(0x482581):goto kg_pc_482581;
case UINT64_C(0x482588):goto kg_pc_482588;
case UINT64_C(0x48258f):goto kg_pc_48258f;
case UINT64_C(0x482591):goto kg_pc_482591;
case UINT64_C(0x482595):goto kg_pc_482595;
case UINT64_C(0x48259b):goto kg_pc_48259b;
case UINT64_C(0x4825a0):goto kg_pc_4825a0;
case UINT64_C(0x4825a3):goto kg_pc_4825a3;
case UINT64_C(0x4825a9):goto kg_pc_4825a9;
case UINT64_C(0x4825af):goto kg_pc_4825af;
case UINT64_C(0x4825b5):goto kg_pc_4825b5;
case UINT64_C(0x4825bb):goto kg_pc_4825bb;
case UINT64_C(0x4825c1):goto kg_pc_4825c1;
case UINT64_C(0x4825c7):goto kg_pc_4825c7;
case UINT64_C(0x4825c9):goto kg_pc_4825c9;
case UINT64_C(0x4825cf):goto kg_pc_4825cf;
case UINT64_C(0x4825d1):goto kg_pc_4825d1;
case UINT64_C(0x4825d5):goto kg_pc_4825d5;
case UINT64_C(0x4825d8):goto kg_pc_4825d8;
case UINT64_C(0x4825df):goto kg_pc_4825df;
case UINT64_C(0x4825e6):goto kg_pc_4825e6;
case UINT64_C(0x4825ed):goto kg_pc_4825ed;
case UINT64_C(0x4825f4):goto kg_pc_4825f4;
case UINT64_C(0x4825fb):goto kg_pc_4825fb;
case UINT64_C(0x482602):goto kg_pc_482602;
case UINT64_C(0x482605):goto kg_pc_482605;
case UINT64_C(0x482609):goto kg_pc_482609;
case UINT64_C(0x482610):goto kg_pc_482610;
case UINT64_C(0x482613):goto kg_pc_482613;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5269: [0x48257a,0x482615), 30 instructions. */
kg_pc_48257a: STEP(0x48257a); /* lea r9d, [rcx - 0x9c] */
s->gpr[9] = (uint32_t)((UINT64_C(0xffffffffffffff64) + s->gpr[2]));
++s->steps;
kg_pc_482581: STEP(0x482581); /* mov r8, qword ptr [rbp - 0x1570] */
READ(a, (UINT64_C(0xffffffffffffea90) + s->gpr[6]), 8);
s->gpr[8] = a;
++s->steps;
kg_pc_482588: STEP(0x482588); /* mov rdx, qword ptr [rbp - 0x128] */
READ(a, (UINT64_C(0xfffffffffffffed8) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_48258f: STEP(0x48258f); /* mov edx, dword ptr [rdx] */
READ(a, (UINT64_C(0x0) + s->gpr[3]), 4);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_482591: STEP(0x482591); /* mov rsi, qword ptr [r12] */
READ(a, (UINT64_C(0x0) + s->gpr[12]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_482595: STEP(0x482595); /* and edx, 0x125515c8 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x125515c8);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48259b: STEP(0x48259b); /* mov ebx, 0x7fffffff */
s->gpr[1] = (uint32_t)(UINT64_C(0x7fffffff));
++s->steps;
kg_pc_4825a0: STEP(0x4825a0); /* and ebx, dword ptr [rsi + rdx] */
READ(b, (UINT64_C(0x0) + s->gpr[4] + (s->gpr[3] * UINT64_C(0x1))), 4);
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = b;
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4825a3: STEP(0x4825a3); /* xor ebx, 0x40e3c417 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x40e3c417);
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4825a9: STEP(0x4825a9); /* sub ebx, dword ptr [rbp - 0xb5c] */
READ(b, (UINT64_C(0xfffffffffffff4a4) + s->gpr[6]), 4);
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = b;
s->gpr[1] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_4825af: STEP(0x4825af); /* imul edx, ebx, 0x2ad0c043 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x2ad0c043);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_4825b5: STEP(0x4825b5); /* xor edx, 0x7ffc5fb6 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x7ffc5fb6);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4825bb: STEP(0x4825bb); /* imul esi, ebx, 0x55a18086 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x55a18086);
s->gpr[4] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_4825c1: STEP(0x4825c1); /* and esi, 0xfff8bf6c */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xfff8bf6c);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4825c7: STEP(0x4825c7); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4825c9: STEP(0x4825c9); /* add edx, 0xc5dfb7e0 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xc5dfb7e0);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4825cf: STEP(0x4825cf); /* mov esi, edi */
s->gpr[4] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4825d1: STEP(0x4825d1); /* shl rsi, 4 */
x = s->gpr[4]; y = UINT64_C(0x4);
s->gpr[4] = operation(s, OP_SHL, x, y, 64);
++s->steps;
kg_pc_4825d5: STEP(0x4825d5); /* add r14, rsi */
x = s->gpr[14]; y = s->gpr[4];
s->gpr[14] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4825d8: STEP(0x4825d8); /* mov rax, qword ptr [rbp - 0x840] */
READ(a, (UINT64_C(0xfffffffffffff7c0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_4825df: STEP(0x4825df); /* mov rdi, qword ptr [rbp - 0xdd0] */
READ(a, (UINT64_C(0xfffffffffffff230) + s->gpr[6]), 8);
s->gpr[5] = a;
++s->steps;
kg_pc_4825e6: STEP(0x4825e6); /* mov rsi, qword ptr [rbp - 0xba0] */
READ(a, (UINT64_C(0xfffffffffffff460) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_4825ed: STEP(0x4825ed); /* mov r13d, dword ptr [rbp - 0x1368] */
READ(a, (UINT64_C(0xffffffffffffec98) + s->gpr[6]), 4);
s->gpr[13] = (uint32_t)(a);
++s->steps;
kg_pc_4825f4: STEP(0x4825f4); /* lea rbx, [rip + 0x10ea] */
s->gpr[1] = (UINT64_C(0x10ea) + (bias + UINT64_C(0x4825fb)));
++s->steps;
kg_pc_4825fb: STEP(0x4825fb); /* mov qword ptr [rbp - 0x1710], rbx */
WRITE((UINT64_C(0xffffffffffffe8f0) + s->gpr[6]), 8, s->gpr[1]);
++s->steps;
kg_pc_482602: STEP(0x482602); /* movsxd rcx, ecx */
s->gpr[2] = (((s->gpr[2] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482605: STEP(0x482605); /* movsxd rcx, dword ptr [r11 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482609: STEP(0x482609); /* lea rbx, [rip - 0x96] */
s->gpr[1] = (UINT64_C(0xffffffffffffff6a) + (bias + UINT64_C(0x482610)));
++s->steps;
kg_pc_482610: STEP(0x482610); /* add rbx, rcx */
x = s->gpr[1]; y = s->gpr[2];
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482613: STEP(0x482613); /* jmp rbx */
x = s->gpr[1];
next_pc = x;
++s->steps;

break;
    case 31:
next_pc=bias+UINT64_C(0x482690);
switch(s->pc-bias){
case UINT64_C(0x482617):goto kg_pc_482617;
case UINT64_C(0x48261e):goto kg_pc_48261e;
case UINT64_C(0x482624):goto kg_pc_482624;
case UINT64_C(0x48262a):goto kg_pc_48262a;
case UINT64_C(0x48262c):goto kg_pc_48262c;
case UINT64_C(0x48262f):goto kg_pc_48262f;
case UINT64_C(0x482635):goto kg_pc_482635;
case UINT64_C(0x48263b):goto kg_pc_48263b;
case UINT64_C(0x48263d):goto kg_pc_48263d;
case UINT64_C(0x482643):goto kg_pc_482643;
case UINT64_C(0x482645):goto kg_pc_482645;
case UINT64_C(0x482647):goto kg_pc_482647;
case UINT64_C(0x48264d):goto kg_pc_48264d;
case UINT64_C(0x482651):goto kg_pc_482651;
case UINT64_C(0x482658):goto kg_pc_482658;
case UINT64_C(0x48265f):goto kg_pc_48265f;
case UINT64_C(0x482669):goto kg_pc_482669;
case UINT64_C(0x482670):goto kg_pc_482670;
case UINT64_C(0x482672):goto kg_pc_482672;
case UINT64_C(0x482676):goto kg_pc_482676;
case UINT64_C(0x48267d):goto kg_pc_48267d;
case UINT64_C(0x482680):goto kg_pc_482680;
case UINT64_C(0x482687):goto kg_pc_482687;
case UINT64_C(0x48268e):goto kg_pc_48268e;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5270: [0x482617,0x482690), 24 instructions. */
kg_pc_482617: STEP(0x482617); /* lea r14d, [rsi + 0x1bfc] */
s->gpr[14] = (uint32_t)((UINT64_C(0x1bfc) + s->gpr[4]));
++s->steps;
kg_pc_48261e: STEP(0x48261e); /* lea eax, [rsi + 0x1bf9] */
s->gpr[0] = (uint32_t)((UINT64_C(0x1bf9) + s->gpr[4]));
++s->steps;
kg_pc_482624: STEP(0x482624); /* mov ecx, dword ptr [rbp - 0x924] */
READ(a, (UINT64_C(0xfffffffffffff6dc) + s->gpr[6]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
kg_pc_48262a: STEP(0x48262a); /* mov edx, ecx */
s->gpr[3] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48262c: STEP(0x48262c); /* or edx, 1 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1);
s->gpr[3] = (uint32_t)(operation(s, OP_OR, x, y, 32));
++s->steps;
kg_pc_48262f: STEP(0x48262f); /* xor edx, 0x47675dde */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x47675dde);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482635: STEP(0x482635); /* or ecx, 0x476f5ddf */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x476f5ddf);
s->gpr[2] = (uint32_t)(operation(s, OP_OR, x, y, 32));
++s->steps;
kg_pc_48263b: STEP(0x48263b); /* mov esi, edx */
s->gpr[4] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48263d: STEP(0x48263d); /* and esi, 0x7ff7fffe */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x7ff7fffe);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_482643: STEP(0x482643); /* xor esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482645: STEP(0x482645); /* add esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482647: STEP(0x482647); /* xor esi, 0x71214443 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x71214443);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48264d: STEP(0x48264d); /* lea r8d, [rdx + rsi] */
s->gpr[8] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_482651: STEP(0x482651); /* add r8d, 0x47675de0 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x47675de0);
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482658: STEP(0x482658); /* mov rcx, qword ptr [rbp - 0x840] */
READ(a, (UINT64_C(0xfffffffffffff7c0) + s->gpr[6]), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_48265f: STEP(0x48265f); /* movabs rdx, 0x6f79466dab33cb24 */
s->gpr[3] = UINT64_C(0x6f79466dab33cb24);
++s->steps;
kg_pc_482669: STEP(0x482669); /* mov dword ptr [rcx + rdx], 0x19ab30bd */
WRITE((UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x1))), 4, UINT64_C(0x19ab30bd));
++s->steps;
kg_pc_482670: STEP(0x482670); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_482672: STEP(0x482672); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482676: STEP(0x482676); /* lea rcx, [rip - 0x66] */
s->gpr[2] = (UINT64_C(0xffffffffffffff9a) + (bias + UINT64_C(0x48267d)));
++s->steps;
kg_pc_48267d: STEP(0x48267d); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482680: STEP(0x482680); /* mov r12, qword ptr [rbp - 0x110] */
READ(a, (UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_482687: STEP(0x482687); /* mov rbx, qword ptr [rbp - 0x128] */
READ(a, (UINT64_C(0xfffffffffffffed8) + s->gpr[6]), 8);
s->gpr[1] = a;
++s->steps;
kg_pc_48268e: STEP(0x48268e); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 32:
next_pc=bias+UINT64_C(0x4826e1);
switch(s->pc-bias){
case UINT64_C(0x482693):goto kg_pc_482693;
case UINT64_C(0x48269d):goto kg_pc_48269d;
case UINT64_C(0x4826a5):goto kg_pc_4826a5;
case UINT64_C(0x4826af):goto kg_pc_4826af;
case UINT64_C(0x4826b1):goto kg_pc_4826b1;
case UINT64_C(0x4826b3):goto kg_pc_4826b3;
case UINT64_C(0x4826b6):goto kg_pc_4826b6;
case UINT64_C(0x4826b9):goto kg_pc_4826b9;
case UINT64_C(0x4826bd):goto kg_pc_4826bd;
case UINT64_C(0x4826c0):goto kg_pc_4826c0;
case UINT64_C(0x4826c3):goto kg_pc_4826c3;
case UINT64_C(0x4826c6):goto kg_pc_4826c6;
case UINT64_C(0x4826c8):goto kg_pc_4826c8;
case UINT64_C(0x4826cb):goto kg_pc_4826cb;
case UINT64_C(0x4826ce):goto kg_pc_4826ce;
case UINT64_C(0x4826d1):goto kg_pc_4826d1;
case UINT64_C(0x4826d5):goto kg_pc_4826d5;
case UINT64_C(0x4826dc):goto kg_pc_4826dc;
case UINT64_C(0x4826df):goto kg_pc_4826df;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5271: [0x482693,0x4826e1), 19 instructions. */
kg_pc_482693: STEP(0x482693); /* movabs rax, 0xdae2336e592c9ca5 */
s->gpr[0] = UINT64_C(0xdae2336e592c9ca5);
++s->steps;
kg_pc_48269d: STEP(0x48269d); /* imul rax, qword ptr [rbp - 0x3dc0] */
READ(b, (UINT64_C(0xffffffffffffc240) + s->gpr[6]), 8);
x = s->gpr[0]; y = b;
s->gpr[0] = operation(s, OP_IMUL, x, y, 64);
++s->steps;
kg_pc_4826a5: STEP(0x4826a5); /* movabs rcx, 0x488b7d6e625b5959 */
s->gpr[2] = UINT64_C(0x488b7d6e625b5959);
++s->steps;
kg_pc_4826af: STEP(0x4826af); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4826b1: STEP(0x4826b1); /* xor esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4826b3: STEP(0x4826b3); /* cmp rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_4826b6: STEP(0x4826b6); /* setne dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4826b9: STEP(0x4826b9); /* sete sil */
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4826bd: STEP(0x4826bd); /* lea eax, [rsi + rsi*4] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x4))));
++s->steps;
kg_pc_4826c0: STEP(0x4826c0); /* lea ecx, [rdx + rdx*2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_4826c3: STEP(0x4826c3); /* add ecx, r14d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4826c6: STEP(0x4826c6); /* add ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4826c8: STEP(0x4826c8); /* add esi, r14d */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4826cb: STEP(0x4826cb); /* mov r14, rcx */
s->gpr[14] = s->gpr[2];
++s->steps;
kg_pc_4826ce: STEP(0x4826ce); /* movsxd rax, esi */
s->gpr[0] = (((s->gpr[4] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4826d1: STEP(0x4826d1); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4826d5: STEP(0x4826d5); /* lea rcx, [rip - 0x49] */
s->gpr[2] = (UINT64_C(0xffffffffffffffb7) + (bias + UINT64_C(0x4826dc)));
++s->steps;
kg_pc_4826dc: STEP(0x4826dc); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4826df: STEP(0x4826df); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 33:
next_pc=bias+UINT64_C(0x482732);
switch(s->pc-bias){
case UINT64_C(0x482711):goto kg_pc_482711;
case UINT64_C(0x482718):goto kg_pc_482718;
case UINT64_C(0x48271b):goto kg_pc_48271b;
case UINT64_C(0x482722):goto kg_pc_482722;
case UINT64_C(0x482726):goto kg_pc_482726;
case UINT64_C(0x48272d):goto kg_pc_48272d;
case UINT64_C(0x482730):goto kg_pc_482730;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5272: [0x482711,0x482732), 7 instructions. */
kg_pc_482711: STEP(0x482711); /* mov r9d, dword ptr [rbp - 0x7e4] */
READ(a, (UINT64_C(0xfffffffffffff81c) + s->gpr[6]), 4);
s->gpr[9] = (uint32_t)(a);
++s->steps;
kg_pc_482718: STEP(0x482718); /* movsxd rax, r14d */
s->gpr[0] = (((s->gpr[14] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48271b: STEP(0x48271b); /* add r14d, 0xffffe502 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffe502);
s->gpr[14] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482722: STEP(0x482722); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482726: STEP(0x482726); /* lea rcx, [rip - 0x1c] */
s->gpr[2] = (UINT64_C(0xffffffffffffffe4) + (bias + UINT64_C(0x48272d)));
++s->steps;
kg_pc_48272d: STEP(0x48272d); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482730: STEP(0x482730); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 34:
next_pc=bias+UINT64_C(0x48288a);
switch(s->pc-bias){
case UINT64_C(0x482875):goto kg_pc_482875;
case UINT64_C(0x48287b):goto kg_pc_48287b;
case UINT64_C(0x48287e):goto kg_pc_48287e;
case UINT64_C(0x482883):goto kg_pc_482883;
case UINT64_C(0x482888):goto kg_pc_482888;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5273: [0x482875,0x48288a), 5 instructions. */
kg_pc_482875: STEP(0x482875); /* mov eax, dword ptr [rbp - 0xd00] */
READ(a, (UINT64_C(0xfffffffffffff300) + s->gpr[6]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_48287b: STEP(0x48287b); /* and eax, 0xfffffff8 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffffff8);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48287e: STEP(0x48287e); /* mov ecx, 0xe9829f2 */
s->gpr[2] = (uint32_t)(UINT64_C(0xe9829f2));
++s->steps;
kg_pc_482883: STEP(0x482883); /* cmp eax, 0x65c90048 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x65c90048);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_482888: STEP(0x482888); /* je 0x482890 */
next_pc = bias + (condition(s, COND_E) ? UINT64_C(0x482890) : UINT64_C(0x48288a));
++s->steps;

break;
    case 35:
next_pc=bias+UINT64_C(0x482890);
switch(s->pc-bias){
case UINT64_C(0x48288a):goto kg_pc_48288a;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5274: [0x48288a,0x482890), 1 instructions. */
kg_pc_48288a: STEP(0x48288a); /* mov ecx, dword ptr [rbp - 0x36c4] */
READ(a, (UINT64_C(0xffffffffffffc93c) + s->gpr[6]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;

break;
    case 36:
next_pc=bias+UINT64_C(0x4828e7);
switch(s->pc-bias){
case UINT64_C(0x482890):goto kg_pc_482890;
case UINT64_C(0x482894):goto kg_pc_482894;
case UINT64_C(0x48289a):goto kg_pc_48289a;
case UINT64_C(0x4828a1):goto kg_pc_4828a1;
case UINT64_C(0x4828a5):goto kg_pc_4828a5;
case UINT64_C(0x4828ac):goto kg_pc_4828ac;
case UINT64_C(0x4828b0):goto kg_pc_4828b0;
case UINT64_C(0x4828b7):goto kg_pc_4828b7;
case UINT64_C(0x4828bb):goto kg_pc_4828bb;
case UINT64_C(0x4828c0):goto kg_pc_4828c0;
case UINT64_C(0x4828c6):goto kg_pc_4828c6;
case UINT64_C(0x4828c9):goto kg_pc_4828c9;
case UINT64_C(0x4828d0):goto kg_pc_4828d0;
case UINT64_C(0x4828d4):goto kg_pc_4828d4;
case UINT64_C(0x4828d7):goto kg_pc_4828d7;
case UINT64_C(0x4828db):goto kg_pc_4828db;
case UINT64_C(0x4828e2):goto kg_pc_4828e2;
case UINT64_C(0x4828e5):goto kg_pc_4828e5;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5275: [0x482890,0x4828e7), 18 instructions. */
kg_pc_482890: STEP(0x482890); /* mov qword ptr [rbp - 0x40], rdx */
WRITE((UINT64_C(0xffffffffffffffc0) + s->gpr[6]), 8, s->gpr[3]);
++s->steps;
kg_pc_482894: STEP(0x482894); /* mov dword ptr [rbp - 0xb0], ecx */
WRITE((UINT64_C(0xffffffffffffff50) + s->gpr[6]), 4, (s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48289a: STEP(0x48289a); /* mov rax, qword ptr [rbp - 0x1030] */
READ(a, (UINT64_C(0xffffffffffffefd0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_4828a1: STEP(0x4828a1); /* mov qword ptr [rbp - 0x48], rax */
WRITE((UINT64_C(0xffffffffffffffb8) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_4828a5: STEP(0x4828a5); /* mov rax, qword ptr [rbp - 0x1df8] */
READ(a, (UINT64_C(0xffffffffffffe208) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_4828ac: STEP(0x4828ac); /* mov qword ptr [rbp - 0x50], rax */
WRITE((UINT64_C(0xffffffffffffffb0) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_4828b0: STEP(0x4828b0); /* mov rax, qword ptr [rbp - 0x40e8] */
READ(a, (UINT64_C(0xffffffffffffbf18) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_4828b7: STEP(0x4828b7); /* mov qword ptr [rbp - 0x58], rax */
WRITE((UINT64_C(0xffffffffffffffa8) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_4828bb: STEP(0x4828bb); /* mov eax, 0x9c44882e */
s->gpr[0] = (uint32_t)(UINT64_C(0x9c44882e));
++s->steps;
kg_pc_4828c0: STEP(0x4828c0); /* add eax, dword ptr [rbp - 0x19b4] */
READ(b, (UINT64_C(0xffffffffffffe64c) + s->gpr[6]), 4);
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = b;
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4828c6: STEP(0x4828c6); /* mov dword ptr [rbp - 0x60], eax */
WRITE((UINT64_C(0xffffffffffffffa0) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4828c9: STEP(0x4828c9); /* mov rax, qword ptr [rbp - 0x43c8] */
READ(a, (UINT64_C(0xffffffffffffbc38) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_4828d0: STEP(0x4828d0); /* mov qword ptr [rbp - 0x68], rax */
WRITE((UINT64_C(0xffffffffffffff98) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_4828d4: STEP(0x4828d4); /* movsxd rax, r8d */
s->gpr[0] = (((s->gpr[8] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4828d7: STEP(0x4828d7); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4828db: STEP(0x4828db); /* lea rcx, [rip - 0x6d] */
s->gpr[2] = (UINT64_C(0xffffffffffffff93) + (bias + UINT64_C(0x4828e2)));
++s->steps;
kg_pc_4828e2: STEP(0x4828e2); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4828e5: STEP(0x4828e5); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 37:
next_pc=bias+UINT64_C(0x482b4b);
switch(s->pc-bias){
case UINT64_C(0x482ae5):goto kg_pc_482ae5;
case UINT64_C(0x482aec):goto kg_pc_482aec;
case UINT64_C(0x482af3):goto kg_pc_482af3;
case UINT64_C(0x482af6):goto kg_pc_482af6;
case UINT64_C(0x482afc):goto kg_pc_482afc;
case UINT64_C(0x482b02):goto kg_pc_482b02;
case UINT64_C(0x482b09):goto kg_pc_482b09;
case UINT64_C(0x482b0d):goto kg_pc_482b0d;
case UINT64_C(0x482b14):goto kg_pc_482b14;
case UINT64_C(0x482b1b):goto kg_pc_482b1b;
case UINT64_C(0x482b1f):goto kg_pc_482b1f;
case UINT64_C(0x482b26):goto kg_pc_482b26;
case UINT64_C(0x482b2d):goto kg_pc_482b2d;
case UINT64_C(0x482b30):goto kg_pc_482b30;
case UINT64_C(0x482b34):goto kg_pc_482b34;
case UINT64_C(0x482b38):goto kg_pc_482b38;
case UINT64_C(0x482b3f):goto kg_pc_482b3f;
case UINT64_C(0x482b42):goto kg_pc_482b42;
case UINT64_C(0x482b49):goto kg_pc_482b49;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5276: [0x482ae5,0x482b4b), 19 instructions. */
kg_pc_482ae5: STEP(0x482ae5); /* mov r15d, dword ptr [rbp - 0xd00] */
READ(a, (UINT64_C(0xfffffffffffff300) + s->gpr[6]), 4);
s->gpr[15] = (uint32_t)(a);
++s->steps;
kg_pc_482aec: STEP(0x482aec); /* lea eax, [r15 + 0x14c51391] */
s->gpr[0] = (uint32_t)((UINT64_C(0x14c51391) + s->gpr[15]));
++s->steps;
kg_pc_482af3: STEP(0x482af3); /* mov dword ptr [rbp - 0x68], eax */
WRITE((UINT64_C(0xffffffffffffff98) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_482af6: STEP(0x482af6); /* mov eax, dword ptr [rbp - 0x36dc] */
READ(a, (UINT64_C(0xffffffffffffc924) + s->gpr[6]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_482afc: STEP(0x482afc); /* mov dword ptr [rbp - 0x150], eax */
WRITE((UINT64_C(0xfffffffffffffeb0) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_482b02: STEP(0x482b02); /* mov rax, qword ptr [rbp - 0x1e88] */
READ(a, (UINT64_C(0xffffffffffffe178) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_482b09: STEP(0x482b09); /* mov qword ptr [rbp - 0x70], rax */
WRITE((UINT64_C(0xffffffffffffff90) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_482b0d: STEP(0x482b0d); /* add r15d, 0xc1c53aff */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = UINT64_C(0xc1c53aff);
s->gpr[15] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482b14: STEP(0x482b14); /* mov rax, qword ptr [rbp - 0x1030] */
READ(a, (UINT64_C(0xffffffffffffefd0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_482b1b: STEP(0x482b1b); /* mov qword ptr [rbp - 0x78], rax */
WRITE((UINT64_C(0xffffffffffffff88) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_482b1f: STEP(0x482b1f); /* mov rax, qword ptr [rbp - 0x4718] */
READ(a, (UINT64_C(0xffffffffffffb8e8) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_482b26: STEP(0x482b26); /* mov qword ptr [rbp - 0x98], rax */
WRITE((UINT64_C(0xffffffffffffff68) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_482b2d: STEP(0x482b2d); /* movsxd rax, r12d */
s->gpr[0] = (((s->gpr[12] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482b30: STEP(0x482b30); /* add r12d, 5 */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x5);
s->gpr[12] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482b34: STEP(0x482b34); /* movsxd rcx, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482b38: STEP(0x482b38); /* lea rax, [rip - 0x5a] */
s->gpr[0] = (UINT64_C(0xffffffffffffffa6) + (bias + UINT64_C(0x482b3f)));
++s->steps;
kg_pc_482b3f: STEP(0x482b3f); /* add rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482b42: STEP(0x482b42); /* mov qword ptr [rbp - 0xa0], r15 */
WRITE((UINT64_C(0xffffffffffffff60) + s->gpr[6]), 8, s->gpr[15]);
++s->steps;
kg_pc_482b49: STEP(0x482b49); /* jmp rax */
x = s->gpr[0];
next_pc = x;
++s->steps;

break;
    case 38:
next_pc=bias+UINT64_C(0x482bfb);
switch(s->pc-bias){
case UINT64_C(0x482b50):goto kg_pc_482b50;
case UINT64_C(0x482b57):goto kg_pc_482b57;
case UINT64_C(0x482b5a):goto kg_pc_482b5a;
case UINT64_C(0x482b5e):goto kg_pc_482b5e;
case UINT64_C(0x482b68):goto kg_pc_482b68;
case UINT64_C(0x482b6b):goto kg_pc_482b6b;
case UINT64_C(0x482b6d):goto kg_pc_482b6d;
case UINT64_C(0x482b6f):goto kg_pc_482b6f;
case UINT64_C(0x482b73):goto kg_pc_482b73;
case UINT64_C(0x482b76):goto kg_pc_482b76;
case UINT64_C(0x482b79):goto kg_pc_482b79;
case UINT64_C(0x482b7c):goto kg_pc_482b7c;
case UINT64_C(0x482b7f):goto kg_pc_482b7f;
case UINT64_C(0x482b82):goto kg_pc_482b82;
case UINT64_C(0x482b84):goto kg_pc_482b84;
case UINT64_C(0x482b86):goto kg_pc_482b86;
case UINT64_C(0x482b8d):goto kg_pc_482b8d;
case UINT64_C(0x482b8f):goto kg_pc_482b8f;
case UINT64_C(0x482b92):goto kg_pc_482b92;
case UINT64_C(0x482b94):goto kg_pc_482b94;
case UINT64_C(0x482b97):goto kg_pc_482b97;
case UINT64_C(0x482b9a):goto kg_pc_482b9a;
case UINT64_C(0x482b9e):goto kg_pc_482b9e;
case UINT64_C(0x482ba5):goto kg_pc_482ba5;
case UINT64_C(0x482ba8):goto kg_pc_482ba8;
case UINT64_C(0x482bb0):goto kg_pc_482bb0;
case UINT64_C(0x482bb3):goto kg_pc_482bb3;
case UINT64_C(0x482bba):goto kg_pc_482bba;
case UINT64_C(0x482bbe):goto kg_pc_482bbe;
case UINT64_C(0x482bc5):goto kg_pc_482bc5;
case UINT64_C(0x482bc8):goto kg_pc_482bc8;
case UINT64_C(0x482bd0):goto kg_pc_482bd0;
case UINT64_C(0x482bd3):goto kg_pc_482bd3;
case UINT64_C(0x482bd7):goto kg_pc_482bd7;
case UINT64_C(0x482bde):goto kg_pc_482bde;
case UINT64_C(0x482be1):goto kg_pc_482be1;
case UINT64_C(0x482be8):goto kg_pc_482be8;
case UINT64_C(0x482beb):goto kg_pc_482beb;
case UINT64_C(0x482bef):goto kg_pc_482bef;
case UINT64_C(0x482bf6):goto kg_pc_482bf6;
case UINT64_C(0x482bf9):goto kg_pc_482bf9;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5277: [0x482b50,0x482bfb), 41 instructions. */
kg_pc_482b50: STEP(0x482b50); /* mov qword ptr [rbp - 0x90], rdi */
WRITE((UINT64_C(0xffffffffffffff70) + s->gpr[6]), 8, s->gpr[5]);
++s->steps;
kg_pc_482b57: STEP(0x482b57); /* mov r14, rbx */
s->gpr[14] = s->gpr[1];
++s->steps;
kg_pc_482b5a: STEP(0x482b5a); /* lea rax, [rbx + rdi] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[1] + (s->gpr[5] * UINT64_C(0x1)));
++s->steps;
kg_pc_482b5e: STEP(0x482b5e); /* movabs rcx, 0x92f5aabc863c7042 */
s->gpr[2] = UINT64_C(0x92f5aabc863c7042);
++s->steps;
kg_pc_482b68: STEP(0x482b68); /* add rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482b6b: STEP(0x482b6b); /* xor ebx, ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482b6d: STEP(0x482b6d); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482b6f: STEP(0x482b6f); /* mov qword ptr [rbp - 0x40], r9 */
WRITE((UINT64_C(0xffffffffffffffc0) + s->gpr[6]), 8, s->gpr[9]);
++s->steps;
kg_pc_482b73: STEP(0x482b73); /* cmp rax, r9 */
x = s->gpr[0]; y = s->gpr[9];
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_482b76: STEP(0x482b76); /* setbe bl */
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_BE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482b79: STEP(0x482b79); /* seta cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_A)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482b7c: STEP(0x482b7c); /* lea eax, [rcx + rcx*8] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x8))));
++s->steps;
kg_pc_482b7f: STEP(0x482b7f); /* lea eax, [rax + rax*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_482b82: STEP(0x482b82); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482b84: STEP(0x482b84); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482b86: STEP(0x482b86); /* lea edi, [rbx*8] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + (s->gpr[1] * UINT64_C(0x8))));
++s->steps;
kg_pc_482b8d: STEP(0x482b8d); /* sub ebx, edi */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_482b8f: STEP(0x482b8f); /* add ebx, r12d */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[12] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482b92: STEP(0x482b92); /* add ebx, eax */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482b94: STEP(0x482b94); /* add ecx, r12d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[12] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482b97: STEP(0x482b97); /* movsxd rax, ecx */
s->gpr[0] = (((s->gpr[2] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482b9a: STEP(0x482b9a); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482b9e: STEP(0x482b9e); /* lea rcx, [rip - 0x55] */
s->gpr[2] = (UINT64_C(0xffffffffffffffab) + (bias + UINT64_C(0x482ba5)));
++s->steps;
kg_pc_482ba5: STEP(0x482ba5); /* add rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482ba8: STEP(0x482ba8); /* lea ecx, [r12 - 0x1ab3] */
s->gpr[2] = (uint32_t)((UINT64_C(0xffffffffffffe54d) + s->gpr[12]));
++s->steps;
kg_pc_482bb0: STEP(0x482bb0); /* movsxd rcx, ecx */
s->gpr[2] = (((s->gpr[2] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482bb3: STEP(0x482bb3); /* lea rdi, [rip + 0x20cf66] */
s->gpr[5] = (UINT64_C(0x20cf66) + (bias + UINT64_C(0x482bba)));
++s->steps;
kg_pc_482bba: STEP(0x482bba); /* mov r13, qword ptr [rdi + rcx*8] */
READ(a, (UINT64_C(0x0) + s->gpr[5] + (s->gpr[2] * UINT64_C(0x8))), 8);
s->gpr[13] = a;
++s->steps;
kg_pc_482bbe: STEP(0x482bbe); /* mov rcx, 0xffffffffc7805532 */
s->gpr[2] = UINT64_C(0xffffffffc7805532);
++s->steps;
kg_pc_482bc5: STEP(0x482bc5); /* add r13, rcx */
x = s->gpr[13]; y = s->gpr[2];
s->gpr[13] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482bc8: STEP(0x482bc8); /* lea ecx, [r12 - 0x1917] */
s->gpr[2] = (uint32_t)((UINT64_C(0xffffffffffffe6e9) + s->gpr[12]));
++s->steps;
kg_pc_482bd0: STEP(0x482bd0); /* movsxd rcx, ecx */
s->gpr[2] = (((s->gpr[2] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482bd3: STEP(0x482bd3); /* mov r8, qword ptr [rdi + rcx*8] */
READ(a, (UINT64_C(0x0) + s->gpr[5] + (s->gpr[2] * UINT64_C(0x8))), 8);
s->gpr[8] = a;
++s->steps;
kg_pc_482bd7: STEP(0x482bd7); /* mov rcx, 0xffffffffce9ad896 */
s->gpr[2] = UINT64_C(0xffffffffce9ad896);
++s->steps;
kg_pc_482bde: STEP(0x482bde); /* add r8, rcx */
x = s->gpr[8]; y = s->gpr[2];
s->gpr[8] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482be1: STEP(0x482be1); /* add r12d, 0xffffe80b */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffe80b);
s->gpr[12] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482be8: STEP(0x482be8); /* movsxd rcx, r12d */
s->gpr[2] = (((s->gpr[12] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482beb: STEP(0x482beb); /* mov r10, qword ptr [rdi + rcx*8] */
READ(a, (UINT64_C(0x0) + s->gpr[5] + (s->gpr[2] * UINT64_C(0x8))), 8);
s->gpr[10] = a;
++s->steps;
kg_pc_482bef: STEP(0x482bef); /* mov rcx, 0xfffffffffbfe48f6 */
s->gpr[2] = UINT64_C(0xfffffffffbfe48f6);
++s->steps;
kg_pc_482bf6: STEP(0x482bf6); /* add r10, rcx */
x = s->gpr[10]; y = s->gpr[2];
s->gpr[10] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482bf9: STEP(0x482bf9); /* jmp rax */
x = s->gpr[0];
next_pc = x;
++s->steps;

break;
    case 39:
next_pc=bias+UINT64_C(0x482c40);
switch(s->pc-bias){
case UINT64_C(0x482bfc):goto kg_pc_482bfc;
case UINT64_C(0x482bfe):goto kg_pc_482bfe;
case UINT64_C(0x482c03):goto kg_pc_482c03;
case UINT64_C(0x482c05):goto kg_pc_482c05;
case UINT64_C(0x482c0b):goto kg_pc_482c0b;
case UINT64_C(0x482c11):goto kg_pc_482c11;
case UINT64_C(0x482c13):goto kg_pc_482c13;
case UINT64_C(0x482c19):goto kg_pc_482c19;
case UINT64_C(0x482c1b):goto kg_pc_482c1b;
case UINT64_C(0x482c1d):goto kg_pc_482c1d;
case UINT64_C(0x482c23):goto kg_pc_482c23;
case UINT64_C(0x482c27):goto kg_pc_482c27;
case UINT64_C(0x482c2a):goto kg_pc_482c2a;
case UINT64_C(0x482c2d):goto kg_pc_482c2d;
case UINT64_C(0x482c30):goto kg_pc_482c30;
case UINT64_C(0x482c34):goto kg_pc_482c34;
case UINT64_C(0x482c3b):goto kg_pc_482c3b;
case UINT64_C(0x482c3e):goto kg_pc_482c3e;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5278: [0x482bfc,0x482c40), 18 instructions. */
kg_pc_482bfc: STEP(0x482bfc); /* mov eax, esi */
s->gpr[0] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_482bfe: STEP(0x482bfe); /* xor eax, 0xf4d2a44f */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xf4d2a44f);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482c03: STEP(0x482c03); /* add esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482c05: STEP(0x482c05); /* and esi, 0xfd5d3aee */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xfd5d3aee);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_482c0b: STEP(0x482c0b); /* xor esi, 0x14583260 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x14583260);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482c11: STEP(0x482c11); /* add esi, eax */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482c13: STEP(0x482c13); /* add esi, 0x84e5952f */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x84e5952f);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482c19: STEP(0x482c19); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482c1b: STEP(0x482c1b); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482c1d: STEP(0x482c1d); /* cmp esi, 0x39432a6 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x39432a6);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_482c23: STEP(0x482c23); /* setne r12b */
s->gpr[12] = (s->gpr[12] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482c27: STEP(0x482c27); /* sete al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482c2a: STEP(0x482c2a); /* lea edi, [rbx + rax] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_482c2d: STEP(0x482c2d); /* movsxd rdi, edi */
s->gpr[5] = (((s->gpr[5] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482c30: STEP(0x482c30); /* movsxd rdi, dword ptr [r11 + rdi*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[5] * UINT64_C(0x4))), 4);
s->gpr[5] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482c34: STEP(0x482c34); /* lea rdx, [rip - 0x3f] */
s->gpr[3] = (UINT64_C(0xffffffffffffffc1) + (bias + UINT64_C(0x482c3b)));
++s->steps;
kg_pc_482c3b: STEP(0x482c3b); /* add rdi, rdx */
x = s->gpr[5]; y = s->gpr[3];
s->gpr[5] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482c3e: STEP(0x482c3e); /* jmp rdi */
x = s->gpr[5];
next_pc = x;
++s->steps;

break;
    case 40:
next_pc=bias+UINT64_C(0x482c9a);
switch(s->pc-bias){
case UINT64_C(0x482c42):goto kg_pc_482c42;
case UINT64_C(0x482c45):goto kg_pc_482c45;
case UINT64_C(0x482c4b):goto kg_pc_482c4b;
case UINT64_C(0x482c52):goto kg_pc_482c52;
case UINT64_C(0x482c54):goto kg_pc_482c54;
case UINT64_C(0x482c57):goto kg_pc_482c57;
case UINT64_C(0x482c5a):goto kg_pc_482c5a;
case UINT64_C(0x482c64):goto kg_pc_482c64;
case UINT64_C(0x482c67):goto kg_pc_482c67;
case UINT64_C(0x482c6b):goto kg_pc_482c6b;
case UINT64_C(0x482c6e):goto kg_pc_482c6e;
case UINT64_C(0x482c72):goto kg_pc_482c72;
case UINT64_C(0x482c76):goto kg_pc_482c76;
case UINT64_C(0x482c7d):goto kg_pc_482c7d;
case UINT64_C(0x482c80):goto kg_pc_482c80;
case UINT64_C(0x482c86):goto kg_pc_482c86;
case UINT64_C(0x482c90):goto kg_pc_482c90;
case UINT64_C(0x482c94):goto kg_pc_482c94;
case UINT64_C(0x482c98):goto kg_pc_482c98;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5279: [0x482c42,0x482c9a), 19 instructions. */
kg_pc_482c42: STEP(0x482c42); /* mov cl, r12b */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((s->gpr[12] & UINT64_C(0xff))) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482c45: STEP(0x482c45); /* mov dword ptr [rbp - 0xb0], esi */
WRITE((UINT64_C(0xffffffffffffff50) + s->gpr[6]), 4, (s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_482c4b: STEP(0x482c4b); /* imul r9d, eax, 0xffffe3f7 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffe3f7);
s->gpr[9] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_482c52: STEP(0x482c52); /* add ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482c54: STEP(0x482c54); /* sub r9d, ecx */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[9] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_482c57: STEP(0x482c57); /* add r9d, ebx */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482c5a: STEP(0x482c5a); /* movabs rax, 0x4f727f7c24811648 */
s->gpr[0] = UINT64_C(0x4f727f7c24811648);
++s->steps;
kg_pc_482c64: STEP(0x482c64); /* add r14, rax */
x = s->gpr[14]; y = s->gpr[0];
s->gpr[14] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482c67: STEP(0x482c67); /* mov qword ptr [rbp - 0x48], r14 */
WRITE((UINT64_C(0xffffffffffffffb8) + s->gpr[6]), 8, s->gpr[14]);
++s->steps;
kg_pc_482c6b: STEP(0x482c6b); /* movsxd rcx, r9d */
s->gpr[2] = (((s->gpr[9] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482c6e: STEP(0x482c6e); /* add r9d, -2 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffffffffffffffe);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482c72: STEP(0x482c72); /* movsxd rcx, dword ptr [r11 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482c76: STEP(0x482c76); /* lea rax, [rip - 0x3b] */
s->gpr[0] = (UINT64_C(0xffffffffffffffc5) + (bias + UINT64_C(0x482c7d)));
++s->steps;
kg_pc_482c7d: STEP(0x482c7d); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482c80: STEP(0x482c80); /* mov r12d, 0x5afff3ed */
s->gpr[12] = (uint32_t)(UINT64_C(0x5afff3ed));
++s->steps;
kg_pc_482c86: STEP(0x482c86); /* movabs rbx, 0xbc7cd4bf9e44a606 */
s->gpr[1] = UINT64_C(0xbc7cd4bf9e44a606);
++s->steps;
kg_pc_482c90: STEP(0x482c90); /* mov qword ptr [rbp - 0x50], r8 */
WRITE((UINT64_C(0xffffffffffffffb0) + s->gpr[6]), 8, s->gpr[8]);
++s->steps;
kg_pc_482c94: STEP(0x482c94); /* mov qword ptr [rbp - 0x58], r10 */
WRITE((UINT64_C(0xffffffffffffffa8) + s->gpr[6]), 8, s->gpr[10]);
++s->steps;
kg_pc_482c98: STEP(0x482c98); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 41:
next_pc=bias+UINT64_C(0x482e2c);
switch(s->pc-bias){
case UINT64_C(0x482ca0):goto kg_pc_482ca0;
case UINT64_C(0x482ca3):goto kg_pc_482ca3;
case UINT64_C(0x482cad):goto kg_pc_482cad;
case UINT64_C(0x482cb1):goto kg_pc_482cb1;
case UINT64_C(0x482cb4):goto kg_pc_482cb4;
case UINT64_C(0x482cbb):goto kg_pc_482cbb;
case UINT64_C(0x482cc0):goto kg_pc_482cc0;
case UINT64_C(0x482cca):goto kg_pc_482cca;
case UINT64_C(0x482cce):goto kg_pc_482cce;
case UINT64_C(0x482cd1):goto kg_pc_482cd1;
case UINT64_C(0x482cdb):goto kg_pc_482cdb;
case UINT64_C(0x482cde):goto kg_pc_482cde;
case UINT64_C(0x482ce2):goto kg_pc_482ce2;
case UINT64_C(0x482ce6):goto kg_pc_482ce6;
case UINT64_C(0x482ced):goto kg_pc_482ced;
case UINT64_C(0x482cf1):goto kg_pc_482cf1;
case UINT64_C(0x482cf5):goto kg_pc_482cf5;
case UINT64_C(0x482cfc):goto kg_pc_482cfc;
case UINT64_C(0x482cff):goto kg_pc_482cff;
case UINT64_C(0x482d02):goto kg_pc_482d02;
case UINT64_C(0x482d09):goto kg_pc_482d09;
case UINT64_C(0x482d0c):goto kg_pc_482d0c;
case UINT64_C(0x482d0f):goto kg_pc_482d0f;
case UINT64_C(0x482d16):goto kg_pc_482d16;
case UINT64_C(0x482d1b):goto kg_pc_482d1b;
case UINT64_C(0x482d1f):goto kg_pc_482d1f;
case UINT64_C(0x482d26):goto kg_pc_482d26;
case UINT64_C(0x482d2b):goto kg_pc_482d2b;
case UINT64_C(0x482d2e):goto kg_pc_482d2e;
case UINT64_C(0x482d35):goto kg_pc_482d35;
case UINT64_C(0x482d3c):goto kg_pc_482d3c;
case UINT64_C(0x482d43):goto kg_pc_482d43;
case UINT64_C(0x482d45):goto kg_pc_482d45;
case UINT64_C(0x482d48):goto kg_pc_482d48;
case UINT64_C(0x482d4a):goto kg_pc_482d4a;
case UINT64_C(0x482d51):goto kg_pc_482d51;
case UINT64_C(0x482d57):goto kg_pc_482d57;
case UINT64_C(0x482d5d):goto kg_pc_482d5d;
case UINT64_C(0x482d5f):goto kg_pc_482d5f;
case UINT64_C(0x482d62):goto kg_pc_482d62;
case UINT64_C(0x482d64):goto kg_pc_482d64;
case UINT64_C(0x482d67):goto kg_pc_482d67;
case UINT64_C(0x482d6b):goto kg_pc_482d6b;
case UINT64_C(0x482d72):goto kg_pc_482d72;
case UINT64_C(0x482d76):goto kg_pc_482d76;
case UINT64_C(0x482d7c):goto kg_pc_482d7c;
case UINT64_C(0x482d80):goto kg_pc_482d80;
case UINT64_C(0x482d83):goto kg_pc_482d83;
case UINT64_C(0x482d8a):goto kg_pc_482d8a;
case UINT64_C(0x482d8e):goto kg_pc_482d8e;
case UINT64_C(0x482d91):goto kg_pc_482d91;
case UINT64_C(0x482d98):goto kg_pc_482d98;
case UINT64_C(0x482d9b):goto kg_pc_482d9b;
case UINT64_C(0x482da5):goto kg_pc_482da5;
case UINT64_C(0x482da8):goto kg_pc_482da8;
case UINT64_C(0x482dab):goto kg_pc_482dab;
case UINT64_C(0x482daf):goto kg_pc_482daf;
case UINT64_C(0x482db3):goto kg_pc_482db3;
case UINT64_C(0x482db6):goto kg_pc_482db6;
case UINT64_C(0x482dbb):goto kg_pc_482dbb;
case UINT64_C(0x482dbf):goto kg_pc_482dbf;
case UINT64_C(0x482dc3):goto kg_pc_482dc3;
case UINT64_C(0x482dc6):goto kg_pc_482dc6;
case UINT64_C(0x482dc9):goto kg_pc_482dc9;
case UINT64_C(0x482dcc):goto kg_pc_482dcc;
case UINT64_C(0x482dd0):goto kg_pc_482dd0;
case UINT64_C(0x482dd5):goto kg_pc_482dd5;
case UINT64_C(0x482ddc):goto kg_pc_482ddc;
case UINT64_C(0x482de3):goto kg_pc_482de3;
case UINT64_C(0x482de6):goto kg_pc_482de6;
case UINT64_C(0x482de9):goto kg_pc_482de9;
case UINT64_C(0x482deb):goto kg_pc_482deb;
case UINT64_C(0x482df2):goto kg_pc_482df2;
case UINT64_C(0x482df5):goto kg_pc_482df5;
case UINT64_C(0x482df7):goto kg_pc_482df7;
case UINT64_C(0x482dfa):goto kg_pc_482dfa;
case UINT64_C(0x482dfe):goto kg_pc_482dfe;
case UINT64_C(0x482e02):goto kg_pc_482e02;
case UINT64_C(0x482e06):goto kg_pc_482e06;
case UINT64_C(0x482e0a):goto kg_pc_482e0a;
case UINT64_C(0x482e11):goto kg_pc_482e11;
case UINT64_C(0x482e14):goto kg_pc_482e14;
case UINT64_C(0x482e16):goto kg_pc_482e16;
case UINT64_C(0x482e19):goto kg_pc_482e19;
case UINT64_C(0x482e1d):goto kg_pc_482e1d;
case UINT64_C(0x482e24):goto kg_pc_482e24;
case UINT64_C(0x482e27):goto kg_pc_482e27;
case UINT64_C(0x482e2a):goto kg_pc_482e2a;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5280: [0x482ca0,0x482e2c), 88 instructions. */
kg_pc_482ca0: STEP(0x482ca0); /* xor r10d, r10d */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482ca3: STEP(0x482ca3); /* cmp dword ptr [rbp - 0xb0], 0x39432a6 */
READ(a, (UINT64_C(0xffffffffffffff50) + s->gpr[6]), 4);
x = a; y = UINT64_C(0x39432a6);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_482cad: STEP(0x482cad); /* setb r10b */
s->gpr[10] = (s->gpr[10] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482cb1: STEP(0x482cb1); /* mov edi, r12d */
s->gpr[5] = (uint32_t)((s->gpr[12] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_482cb4: STEP(0x482cb4); /* cmp r12d, 0x5afff3ed */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x5afff3ed);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_482cbb: STEP(0x482cbb); /* mov ecx, 0 */
s->gpr[2] = (uint32_t)(UINT64_C(0x0));
++s->steps;
kg_pc_482cc0: STEP(0x482cc0); /* movabs rax, 0x100000000 */
s->gpr[0] = UINT64_C(0x100000000);
++s->steps;
kg_pc_482cca: STEP(0x482cca); /* cmovb rcx, rax */
s->gpr[2] = (condition(s, COND_B) ? s->gpr[0] : s->gpr[2]);
++s->steps;
kg_pc_482cce: STEP(0x482cce); /* add rcx, rdi */
x = s->gpr[2]; y = s->gpr[5];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482cd1: STEP(0x482cd1); /* movabs rax, 0x43832b4006bb660d */
s->gpr[0] = UINT64_C(0x43832b4006bb660d);
++s->steps;
kg_pc_482cdb: STEP(0x482cdb); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482cde: STEP(0x482cde); /* mov rax, qword ptr [rbp - 0x48] */
READ(a, (UINT64_C(0xffffffffffffffb8) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_482ce2: STEP(0x482ce2); /* lea r14, [rax + rcx] */
s->gpr[14] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1)));
++s->steps;
kg_pc_482ce6: STEP(0x482ce6); /* mov rdi, qword ptr [rbp - 0x90] */
READ(a, (UINT64_C(0xffffffffffffff70) + s->gpr[6]), 8);
s->gpr[5] = a;
++s->steps;
kg_pc_482ced: STEP(0x482ced); /* lea r15, [rdi + r14] */
s->gpr[15] = (UINT64_C(0x0) + s->gpr[5] + (s->gpr[14] * UINT64_C(0x1)));
++s->steps;
kg_pc_482cf1: STEP(0x482cf1); /* add rcx, qword ptr [rbp - 0x40] */
READ(b, (UINT64_C(0xffffffffffffffc0) + s->gpr[6]), 8);
x = s->gpr[2]; y = b;
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482cf5: STEP(0x482cf5); /* mov rax, qword ptr [rbp - 0x128] */
READ(a, (UINT64_C(0xfffffffffffffed8) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_482cfc: STEP(0x482cfc); /* movsxd r11, dword ptr [rax] */
READ(a, (UINT64_C(0x0) + s->gpr[0]), 4);
s->gpr[11] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482cff: STEP(0x482cff); /* mov rax, r13 */
s->gpr[0] = s->gpr[13];
++s->steps;
kg_pc_482d02: STEP(0x482d02); /* mov rdx, qword ptr [rbp - 0x110] */
READ(a, (UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_482d09: STEP(0x482d09); /* mov r13, qword ptr [rdx] */
READ(a, (UINT64_C(0x0) + s->gpr[3]), 8);
s->gpr[13] = a;
++s->steps;
kg_pc_482d0c: STEP(0x482d0c); /* mov r8, r11 */
s->gpr[8] = s->gpr[11];
++s->steps;
kg_pc_482d0f: STEP(0x482d0f); /* and r8, 0xffffffffdb1cd9f8 */
x = s->gpr[8]; y = UINT64_C(0xffffffffdb1cd9f8);
s->gpr[8] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_482d16: STEP(0x482d16); /* xor r15d, dword ptr [r13 + r8] */
READ(b, (UINT64_C(0x0) + s->gpr[13] + (s->gpr[8] * UINT64_C(0x1))), 4);
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = b;
s->gpr[15] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482d1b: STEP(0x482d1b); /* lea rdx, [rcx + rbx] */
s->gpr[3] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[1] * UINT64_C(0x1)));
++s->steps;
kg_pc_482d1f: STEP(0x482d1f); /* and r11, 0xffffffffce7540c4 */
x = s->gpr[11]; y = UINT64_C(0xffffffffce7540c4);
s->gpr[11] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_482d26: STEP(0x482d26); /* xor edx, dword ptr [r13 + r11] */
READ(b, (UINT64_C(0x0) + s->gpr[13] + (s->gpr[11] * UINT64_C(0x1))), 4);
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482d2b: STEP(0x482d2b); /* mov r13, rax */
s->gpr[13] = s->gpr[0];
++s->steps;
kg_pc_482d2e: STEP(0x482d2e); /* lea r11, [rip - 0x47b9e5] */
s->gpr[11] = (UINT64_C(0xffffffffffb8461b) + (bias + UINT64_C(0x482d35)));
++s->steps;
kg_pc_482d35: STEP(0x482d35); /* and r15d, 0x7fffffff */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = UINT64_C(0x7fffffff);
s->gpr[15] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_482d3c: STEP(0x482d3c); /* imul eax, r15d, 0xa57ed9a7 */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = UINT64_C(0xa57ed9a7);
s->gpr[0] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_482d43: STEP(0x482d43); /* mov esi, eax */
s->gpr[4] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_482d45: STEP(0x482d45); /* shr esi, 0x10 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[4] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_482d48: STEP(0x482d48); /* xor esi, eax */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482d4a: STEP(0x482d4a); /* imul r8d, esi, 0xa57ed9a7 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xa57ed9a7);
s->gpr[8] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_482d51: STEP(0x482d51); /* and edx, 0x7fffffff */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x7fffffff);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_482d57: STEP(0x482d57); /* imul edx, edx, 0xa57ed9a7 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xa57ed9a7);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_482d5d: STEP(0x482d5d); /* mov esi, edx */
s->gpr[4] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_482d5f: STEP(0x482d5f); /* shr esi, 0x10 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[4] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_482d62: STEP(0x482d62); /* xor esi, edx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482d64: STEP(0x482d64); /* mov rdx, r8 */
s->gpr[3] = s->gpr[8];
++s->steps;
kg_pc_482d67: STEP(0x482d67); /* shr rdx, 0x18 */
x = s->gpr[3]; y = UINT64_C(0x18);
s->gpr[3] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_482d6b: STEP(0x482d6b); /* mov rax, qword ptr [rbp - 0xd48] */
READ(a, (UINT64_C(0xfffffffffffff2b8) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_482d72: STEP(0x482d72); /* movzx eax, byte ptr [rax + rdx] */
READ(a, (UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_482d76: STEP(0x482d76); /* imul esi, esi, 0xa57ed9a7 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xa57ed9a7);
s->gpr[4] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_482d7c: STEP(0x482d7c); /* xor al, byte ptr [rdi + r14] */
READ(b, (UINT64_C(0x0) + s->gpr[5] + (s->gpr[14] * UINT64_C(0x1))), 1);
x = (s->gpr[0] & UINT64_C(0xff)); y = b;
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482d80: STEP(0x482d80); /* mov rdi, rsi */
s->gpr[5] = s->gpr[4];
++s->steps;
kg_pc_482d83: STEP(0x482d83); /* mov rbx, qword ptr [rbp - 0xd40] */
READ(a, (UINT64_C(0xfffffffffffff2c0) + s->gpr[6]), 8);
s->gpr[1] = a;
++s->steps;
kg_pc_482d8a: STEP(0x482d8a); /* xor al, byte ptr [rdx + rbx + 2] */
READ(b, (UINT64_C(0x2) + s->gpr[3] + (s->gpr[1] * UINT64_C(0x1))), 1);
x = (s->gpr[0] & UINT64_C(0xff)); y = b;
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482d8e: STEP(0x482d8e); /* xor sil, r8b */
x = (s->gpr[4] & UINT64_C(0xff)); y = (s->gpr[8] & UINT64_C(0xff));
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482d91: STEP(0x482d91); /* mov rbx, qword ptr [rbp - 0xd50] */
READ(a, (UINT64_C(0xfffffffffffff2b0) + s->gpr[6]), 8);
s->gpr[1] = a;
++s->steps;
kg_pc_482d98: STEP(0x482d98); /* xor al, byte ptr [rbx + rdx] */
READ(b, (UINT64_C(0x0) + s->gpr[1] + (s->gpr[3] * UINT64_C(0x1))), 1);
x = (s->gpr[0] & UINT64_C(0xff)); y = b;
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482d9b: STEP(0x482d9b); /* movabs rbx, 0xbc7cd4bf9e44a606 */
s->gpr[1] = UINT64_C(0xbc7cd4bf9e44a606);
++s->steps;
kg_pc_482da5: STEP(0x482da5); /* imul edx, edx, -0x4b */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffffffffffb5);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_482da8: STEP(0x482da8); /* xor sil, dl */
x = (s->gpr[4] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482dab: STEP(0x482dab); /* shr rdi, 0x18 */
x = s->gpr[5]; y = UINT64_C(0x18);
s->gpr[5] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_482daf: STEP(0x482daf); /* mov rdx, qword ptr [rbp - 0x58] */
READ(a, (UINT64_C(0xffffffffffffffa8) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_482db3: STEP(0x482db3); /* xor al, byte ptr [rdx + rdi] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0x0) + s->gpr[3] + (s->gpr[5] * UINT64_C(0x1)));int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0x0) + s->gpr[13] + (s->gpr[5] * UINT64_C(0x1)));
if(middle_valid_&&!translate(regions,count,x,1,1)&&!translate(regions,count,y,1,1)&&wrapper_kg_ckc_integrity_word(x,y,1,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, (s->gpr[0] & UINT64_C(0xff)), pair_, 8)) & UINT64_C(0xff)) << 0);
s->steps+=2;s->pc=bias+UINT64_C(0x482dbb);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,1,1)&&!translate(regions,count,y,1,1)&&!wrapper_kg_ckc_integrity_word(x,y,1,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[5] * UINT64_C(0x1))), 1);
x=(s->gpr[0] & UINT64_C(0xff));y=b;
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482db6: STEP(0x482db6); /* xor al, byte ptr [r13 + rdi] */
READ(b, (UINT64_C(0x0) + s->gpr[13] + (s->gpr[5] * UINT64_C(0x1))), 1);
x = (s->gpr[0] & UINT64_C(0xff)); y = b;
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482dbb: STEP(0x482dbb); /* mov rdx, qword ptr [rbp - 0x50] */
READ(a, (UINT64_C(0xffffffffffffffb0) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_482dbf: STEP(0x482dbf); /* xor al, byte ptr [rdi + rdx + 6] */
READ(b, (UINT64_C(0x6) + s->gpr[5] + (s->gpr[3] * UINT64_C(0x1))), 1);
x = (s->gpr[0] & UINT64_C(0xff)); y = b;
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482dc3: STEP(0x482dc3); /* imul edx, edi, -0x61 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffffffffff9f);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_482dc6: STEP(0x482dc6); /* xor sil, dl */
x = (s->gpr[4] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482dc9: STEP(0x482dc9); /* xor sil, al */
x = (s->gpr[4] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482dcc: STEP(0x482dcc); /* mov byte ptr [rbx + rcx], sil */
WRITE((UINT64_C(0x0) + s->gpr[1] + (s->gpr[2] * UINT64_C(0x1))), 1, (s->gpr[4] & UINT64_C(0xff)));
++s->steps;
kg_pc_482dd0: STEP(0x482dd0); /* lea eax, [r12 + 1] */
s->gpr[0] = (uint32_t)((UINT64_C(0x1) + s->gpr[12]));
++s->steps;
kg_pc_482dd5: STEP(0x482dd5); /* add r12d, 0xa8943eba */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0xa8943eba);
s->gpr[12] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482ddc: STEP(0x482ddc); /* cmp r12d, 0x39432a6 */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x39432a6);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_482de3: STEP(0x482de3); /* setb cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482de6: STEP(0x482de6); /* xor cl, r10b */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[10] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482de9: STEP(0x482de9); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_482deb: STEP(0x482deb); /* cmp r12d, dword ptr [rbp - 0xb0] */
READ(b, (UINT64_C(0xffffffffffffff50) + s->gpr[6]), 4);
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = b;
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_482df2: STEP(0x482df2); /* setb dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482df5: STEP(0x482df5); /* test cl, cl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
(void)operation(s, OP_AND, x, y, 8);
++s->steps;
kg_pc_482df7: STEP(0x482df7); /* mov ecx, r9d */
s->gpr[2] = (uint32_t)((s->gpr[9] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_482dfa: STEP(0x482dfa); /* cmove r10d, edx */
s->gpr[10] = (uint32_t)((condition(s, COND_E) ? (s->gpr[3] & UINT64_C(0xffffffff)) : (s->gpr[10] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_482dfe: STEP(0x482dfe); /* movzx edx, r10b */
s->gpr[3] = (uint32_t)((s->gpr[10] & UINT64_C(0xff)));
++s->steps;
kg_pc_482e02: STEP(0x482e02); /* xor r10b, 1 */
x = (s->gpr[10] & UINT64_C(0xff)); y = UINT64_C(0x1);
s->gpr[10] = (s->gpr[10] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_482e06: STEP(0x482e06); /* movzx esi, r10b */
s->gpr[4] = (uint32_t)((s->gpr[10] & UINT64_C(0xff)));
++s->steps;
kg_pc_482e0a: STEP(0x482e0a); /* imul r9d, esi, 0xffffe3fb */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffe3fb);
s->gpr[9] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_482e11: STEP(0x482e11); /* add r9d, ecx */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482e14: STEP(0x482e14); /* add edx, ecx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482e16: STEP(0x482e16); /* movsxd rcx, edx */
s->gpr[2] = (((s->gpr[3] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482e19: STEP(0x482e19); /* movsxd rcx, dword ptr [r11 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482e1d: STEP(0x482e1d); /* lea rdx, [rip - 0x184] */
s->gpr[3] = (UINT64_C(0xfffffffffffffe7c) + (bias + UINT64_C(0x482e24)));
++s->steps;
kg_pc_482e24: STEP(0x482e24); /* add rcx, rdx */
x = s->gpr[2]; y = s->gpr[3];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482e27: STEP(0x482e27); /* mov r12d, eax */
s->gpr[12] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_482e2a: STEP(0x482e2a); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 42:
next_pc=bias+UINT64_C(0x482e4e);
switch(s->pc-bias){
case UINT64_C(0x482e2d):goto kg_pc_482e2d;
case UINT64_C(0x482e34):goto kg_pc_482e34;
case UINT64_C(0x482e37):goto kg_pc_482e37;
case UINT64_C(0x482e3b):goto kg_pc_482e3b;
case UINT64_C(0x482e42):goto kg_pc_482e42;
case UINT64_C(0x482e45):goto kg_pc_482e45;
case UINT64_C(0x482e4c):goto kg_pc_482e4c;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5281: [0x482e2d,0x482e4e), 7 instructions. */
kg_pc_482e2d: STEP(0x482e2d); /* add r9d, 0x1c04 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x1c04);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_482e34: STEP(0x482e34); /* movsxd rax, r9d */
s->gpr[0] = (((s->gpr[9] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482e37: STEP(0x482e37); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_482e3b: STEP(0x482e3b); /* lea rcx, [rip - 0x15] */
s->gpr[2] = (UINT64_C(0xffffffffffffffeb) + (bias + UINT64_C(0x482e42)));
++s->steps;
kg_pc_482e42: STEP(0x482e42); /* add rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_482e45: STEP(0x482e45); /* mov r15, qword ptr [rbp - 0xa0] */
READ(a, (UINT64_C(0xffffffffffffff60) + s->gpr[6]), 8);
s->gpr[15] = a;
++s->steps;
kg_pc_482e4c: STEP(0x482e4c); /* jmp rax */
x = s->gpr[0];
next_pc = x;
++s->steps;

break;
    case 43:
next_pc=bias+UINT64_C(0x48306e);
switch(s->pc-bias){
case UINT64_C(0x48305f):goto kg_pc_48305f;
case UINT64_C(0x483066):goto kg_pc_483066;
case UINT64_C(0x483068):goto kg_pc_483068;
case UINT64_C(0x48306b):goto kg_pc_48306b;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5282: [0x48305f,0x48306e), 4 instructions. */
kg_pc_48305f: STEP(0x48305f); /* mov rax, qword ptr [rbp - 0xb8] */
READ(a, (UINT64_C(0xffffffffffffff48) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_483066: STEP(0x483066); /* mov edi, eax */
s->gpr[5] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483068: STEP(0x483068); /* mov r8d, eax */
s->gpr[8] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48306b: STEP(0x48306b); /* jmp qword ptr [rbp - 0x60] */
READ(a, (UINT64_C(0xffffffffffffffa0) + s->gpr[6]), 8);
x = a;
next_pc = x;
++s->steps;

break;
    case 44:
next_pc=bias+UINT64_C(0x483264);
switch(s->pc-bias){
case UINT64_C(0x483222):goto kg_pc_483222;
case UINT64_C(0x483229):goto kg_pc_483229;
case UINT64_C(0x48322b):goto kg_pc_48322b;
case UINT64_C(0x48322d):goto kg_pc_48322d;
case UINT64_C(0x483230):goto kg_pc_483230;
case UINT64_C(0x483233):goto kg_pc_483233;
case UINT64_C(0x483236):goto kg_pc_483236;
case UINT64_C(0x48323c):goto kg_pc_48323c;
case UINT64_C(0x483242):goto kg_pc_483242;
case UINT64_C(0x483245):goto kg_pc_483245;
case UINT64_C(0x483247):goto kg_pc_483247;
case UINT64_C(0x48324b):goto kg_pc_48324b;
case UINT64_C(0x483251):goto kg_pc_483251;
case UINT64_C(0x483254):goto kg_pc_483254;
case UINT64_C(0x483258):goto kg_pc_483258;
case UINT64_C(0x48325f):goto kg_pc_48325f;
case UINT64_C(0x483262):goto kg_pc_483262;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5283: [0x483222,0x483264), 17 instructions. */
kg_pc_483222: STEP(0x483222); /* mov rax, qword ptr [rbp - 0x1db0] */
READ(a, (UINT64_C(0xffffffffffffe250) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_483229: STEP(0x483229); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48322b: STEP(0x48322b); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48322d: STEP(0x48322d); /* test rax, rax */
x = s->gpr[0]; y = s->gpr[0];
(void)operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_483230: STEP(0x483230); /* setne cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483233: STEP(0x483233); /* sete dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483236: STEP(0x483236); /* imul esi, edx, 0x1bf8 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1bf8);
s->gpr[4] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_48323c: STEP(0x48323c); /* imul ebx, ecx, 0x1bfa */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x1bfa);
s->gpr[1] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_483242: STEP(0x483242); /* add ebx, r8d */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483245: STEP(0x483245); /* add ebx, esi */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483247: STEP(0x483247); /* lea ecx, [r8 + rdx] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[8] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_48324b: STEP(0x48324b); /* add ecx, 0x1bf5 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x1bf5);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483251: STEP(0x483251); /* movsxd rcx, ecx */
s->gpr[2] = (((s->gpr[2] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483254: STEP(0x483254); /* movsxd rcx, dword ptr [r11 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483258: STEP(0x483258); /* lea rdx, [rip - 0x3d] */
s->gpr[3] = (UINT64_C(0xffffffffffffffc3) + (bias + UINT64_C(0x48325f)));
++s->steps;
kg_pc_48325f: STEP(0x48325f); /* add rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483262: STEP(0x483262); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 45:
next_pc=bias+UINT64_C(0x4832be);
switch(s->pc-bias){
case UINT64_C(0x483266):goto kg_pc_483266;
case UINT64_C(0x48326a):goto kg_pc_48326a;
case UINT64_C(0x483270):goto kg_pc_483270;
case UINT64_C(0x483277):goto kg_pc_483277;
case UINT64_C(0x483279):goto kg_pc_483279;
case UINT64_C(0x483283):goto kg_pc_483283;
case UINT64_C(0x483285):goto kg_pc_483285;
case UINT64_C(0x48328b):goto kg_pc_48328b;
case UINT64_C(0x483292):goto kg_pc_483292;
case UINT64_C(0x483299):goto kg_pc_483299;
case UINT64_C(0x4832a0):goto kg_pc_4832a0;
case UINT64_C(0x4832a2):goto kg_pc_4832a2;
case UINT64_C(0x4832a4):goto kg_pc_4832a4;
case UINT64_C(0x4832aa):goto kg_pc_4832aa;
case UINT64_C(0x4832b0):goto kg_pc_4832b0;
case UINT64_C(0x4832b2):goto kg_pc_4832b2;
case UINT64_C(0x4832b8):goto kg_pc_4832b8;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5284: [0x483266,0x4832be), 17 instructions. */
kg_pc_483266: STEP(0x483266); /* lea r14d, [rbx - 2] */
s->gpr[14] = (uint32_t)((UINT64_C(0xfffffffffffffffe) + s->gpr[1]));
++s->steps;
kg_pc_48326a: STEP(0x48326a); /* lea ecx, [rbx - 0x1c01] */
s->gpr[2] = (uint32_t)((UINT64_C(0xffffffffffffe3ff) + s->gpr[1]));
++s->steps;
kg_pc_483270: STEP(0x483270); /* lea rdi, [rbp - 0x1f8] */
s->gpr[5] = (UINT64_C(0xfffffffffffffe08) + s->gpr[6]);
++s->steps;
kg_pc_483277: STEP(0x483277); /* mov edx, edi */
s->gpr[3] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483279: STEP(0x483279); /* movabs rsi, 0xd7cf669026532472 */
s->gpr[4] = UINT64_C(0xd7cf669026532472);
++s->steps;
kg_pc_483283: STEP(0x483283); /* xor edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483285: STEP(0x483285); /* imul edx, edx, 0x20bd8b7f */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x20bd8b7f);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_48328b: STEP(0x48328b); /* mov qword ptr [rbp - 0x1f0], rax */
WRITE((UINT64_C(0xfffffffffffffe10) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_483292: STEP(0x483292); /* lea rax, [rip - 0x2e288e] */
s->gpr[0] = (UINT64_C(0xffffffffffd1d772) + (bias + UINT64_C(0x483299)));
++s->steps;
kg_pc_483299: STEP(0x483299); /* lea rsi, [rip - 0x2e2801] */
s->gpr[4] = (UINT64_C(0xffffffffffd1d7ff) + (bias + UINT64_C(0x4832a0)));
++s->steps;
kg_pc_4832a0: STEP(0x4832a0); /* sub esi, eax */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_4832a2: STEP(0x4832a2); /* sub esi, edx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_4832a4: STEP(0x4832a4); /* add esi, 0x8fc */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x8fc);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4832aa: STEP(0x4832aa); /* mov dword ptr [rbp - 0x1f8], esi */
WRITE((UINT64_C(0xfffffffffffffe08) + s->gpr[6]), 4, (s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4832b0: STEP(0x4832b0); /* xor ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4832b2: STEP(0x4832b2); /* mov dword ptr [rbp - 0x1e8], ecx */
WRITE((UINT64_C(0xfffffffffffffe18) + s->gpr[6]), 4, (s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4832b8: STEP(0x4832b8); /* call qword ptr [rbp - 0x458] */
READ(a, (UINT64_C(0xfffffffffffffba8) + s->gpr[6]), 8);
x = a;
y = s->gpr[7] - 8;
WRITE(y, 8, bias + UINT64_C(0x4832be));
s->gpr[7] = y;
next_pc = x;
++s->steps;

break;
    case 46:
next_pc=bias+UINT64_C(0x4832db);
switch(s->pc-bias){
case UINT64_C(0x4832be):goto kg_pc_4832be;
case UINT64_C(0x4832c5):goto kg_pc_4832c5;
case UINT64_C(0x4832c8):goto kg_pc_4832c8;
case UINT64_C(0x4832cc):goto kg_pc_4832cc;
case UINT64_C(0x4832d3):goto kg_pc_4832d3;
case UINT64_C(0x4832d6):goto kg_pc_4832d6;
case UINT64_C(0x4832d9):goto kg_pc_4832d9;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5285: [0x4832be,0x4832db), 7 instructions. */
kg_pc_4832be: STEP(0x4832be); /* lea r11, [rip - 0x47bf75] */
s->gpr[11] = (UINT64_C(0xffffffffffb8408b) + (bias + UINT64_C(0x4832c5)));
++s->steps;
kg_pc_4832c5: STEP(0x4832c5); /* movsxd rax, ebx */
s->gpr[0] = (((s->gpr[1] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4832c8: STEP(0x4832c8); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4832cc: STEP(0x4832cc); /* lea rcx, [rip - 0x6d] */
s->gpr[2] = (UINT64_C(0xffffffffffffff93) + (bias + UINT64_C(0x4832d3)));
++s->steps;
kg_pc_4832d3: STEP(0x4832d3); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4832d6: STEP(0x4832d6); /* mov ebx, r14d */
s->gpr[1] = (uint32_t)((s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4832d9: STEP(0x4832d9); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 47:
next_pc=bias+UINT64_C(0x4832fd);
switch(s->pc-bias){
case UINT64_C(0x4832dc):goto kg_pc_4832dc;
case UINT64_C(0x4832e3):goto kg_pc_4832e3;
case UINT64_C(0x4832e6):goto kg_pc_4832e6;
case UINT64_C(0x4832ea):goto kg_pc_4832ea;
case UINT64_C(0x4832f1):goto kg_pc_4832f1;
case UINT64_C(0x4832f4):goto kg_pc_4832f4;
case UINT64_C(0x4832fb):goto kg_pc_4832fb;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5286: [0x4832dc,0x4832fd), 7 instructions. */
kg_pc_4832dc: STEP(0x4832dc); /* mov r10d, dword ptr [rbp - 0x32c4] */
READ(a, (UINT64_C(0xffffffffffffcd3c) + s->gpr[6]), 4);
s->gpr[10] = (uint32_t)(a);
++s->steps;
kg_pc_4832e3: STEP(0x4832e3); /* movsxd rcx, ebx */
s->gpr[2] = (((s->gpr[1] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4832e6: STEP(0x4832e6); /* movsxd rcx, dword ptr [r11 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4832ea: STEP(0x4832ea); /* lea rdx, [rip - 0x15] */
s->gpr[3] = (UINT64_C(0xffffffffffffffeb) + (bias + UINT64_C(0x4832f1)));
++s->steps;
kg_pc_4832f1: STEP(0x4832f1); /* add rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4832f4: STEP(0x4832f4); /* mov rsi, qword ptr [rbp - 0xb8] */
READ(a, (UINT64_C(0xffffffffffffff48) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_4832fb: STEP(0x4832fb); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 48:
next_pc=bias+UINT64_C(0x48330c);
switch(s->pc-bias){
case UINT64_C(0x4832fe):goto kg_pc_4832fe;
case UINT64_C(0x483306):goto kg_pc_483306;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5287: [0x4832fe,0x48330c), 2 instructions. */
kg_pc_4832fe: STEP(0x4832fe); /* add qword ptr [rbp - 0x2c8], -0x10 */
READ(a, (UINT64_C(0xfffffffffffffd38) + s->gpr[6]), 8);
x = a; y = UINT64_C(0xfffffffffffffff0);
WRITE((UINT64_C(0xfffffffffffffd38) + s->gpr[6]), 8, operation(s, OP_ADD, x, y, 64));
++s->steps;
kg_pc_483306: STEP(0x483306); /* jmp qword ptr [rbp - 0x4580] */
READ(a, (UINT64_C(0xffffffffffffba80) + s->gpr[6]), 8);
x = a;
next_pc = x;
++s->steps;

break;
    case 49:
next_pc=bias+UINT64_C(0x48371e);
switch(s->pc-bias){
case UINT64_C(0x4836e5):goto kg_pc_4836e5;
case UINT64_C(0x4836ec):goto kg_pc_4836ec;
case UINT64_C(0x4836f3):goto kg_pc_4836f3;
case UINT64_C(0x4836fa):goto kg_pc_4836fa;
case UINT64_C(0x4836fe):goto kg_pc_4836fe;
case UINT64_C(0x483700):goto kg_pc_483700;
case UINT64_C(0x483707):goto kg_pc_483707;
case UINT64_C(0x48370b):goto kg_pc_48370b;
case UINT64_C(0x483712):goto kg_pc_483712;
case UINT64_C(0x483715):goto kg_pc_483715;
case UINT64_C(0x48371c):goto kg_pc_48371c;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5288: [0x4836e5,0x48371e), 11 instructions. */
kg_pc_4836e5: STEP(0x4836e5); /* lea ecx, [r15 + 0xff] */
s->gpr[2] = (uint32_t)((UINT64_C(0xff) + s->gpr[15]));
++s->steps;
kg_pc_4836ec: STEP(0x4836ec); /* lea eax, [r15 + 0x21e7] */
s->gpr[0] = (uint32_t)((UINT64_C(0x21e7) + s->gpr[15]));
++s->steps;
kg_pc_4836f3: STEP(0x4836f3); /* mov r9d, dword ptr [rbp - 0x7e4] */
READ(a, (UINT64_C(0xfffffffffffff81c) + s->gpr[6]), 4);
s->gpr[9] = (uint32_t)(a);
++s->steps;
kg_pc_4836fa: STEP(0x4836fa); /* add r9d, 1 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x1);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4836fe: STEP(0x4836fe); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_483700: STEP(0x483700); /* lea r11, [rip - 0x47c3b7] */
s->gpr[11] = (UINT64_C(0xffffffffffb83c49) + (bias + UINT64_C(0x483707)));
++s->steps;
kg_pc_483707: STEP(0x483707); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48370b: STEP(0x48370b); /* lea rdx, [rip - 0x2d] */
s->gpr[3] = (UINT64_C(0xffffffffffffffd3) + (bias + UINT64_C(0x483712)));
++s->steps;
kg_pc_483712: STEP(0x483712); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483715: STEP(0x483715); /* mov r12, qword ptr [rbp - 0x110] */
READ(a, (UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_48371c: STEP(0x48371c); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 50:
next_pc=bias+UINT64_C(0x483736);
switch(s->pc-bias){
case UINT64_C(0x483721):goto kg_pc_483721;
case UINT64_C(0x483727):goto kg_pc_483727;
case UINT64_C(0x48372a):goto kg_pc_48372a;
case UINT64_C(0x48372f):goto kg_pc_48372f;
case UINT64_C(0x483734):goto kg_pc_483734;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5289: [0x483721,0x483736), 5 instructions. */
kg_pc_483721: STEP(0x483721); /* mov eax, dword ptr [rbp - 0x1f90] */
READ(a, (UINT64_C(0xffffffffffffe070) + s->gpr[6]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_483727: STEP(0x483727); /* and eax, 0xfffffff8 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffffff8);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48372a: STEP(0x48372a); /* mov edi, 0xe9829f2 */
s->gpr[5] = (uint32_t)(UINT64_C(0xe9829f2));
++s->steps;
kg_pc_48372f: STEP(0x48372f); /* cmp eax, 0x65c90048 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x65c90048);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_483734: STEP(0x483734); /* je 0x48373c */
next_pc = bias + (condition(s, COND_E) ? UINT64_C(0x48373c) : UINT64_C(0x483736));
++s->steps;

break;
    case 51:
next_pc=bias+UINT64_C(0x48373c);
switch(s->pc-bias){
case UINT64_C(0x483736):goto kg_pc_483736;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5290: [0x483736,0x48373c), 1 instructions. */
kg_pc_483736: STEP(0x483736); /* mov edi, dword ptr [rbp - 0x3520] */
READ(a, (UINT64_C(0xffffffffffffcae0) + s->gpr[6]), 4);
s->gpr[5] = (uint32_t)(a);
++s->steps;

break;
    case 52:
next_pc=bias+UINT64_C(0x483788);
switch(s->pc-bias){
case UINT64_C(0x48373c):goto kg_pc_48373c;
case UINT64_C(0x48373e):goto kg_pc_48373e;
case UINT64_C(0x483740):goto kg_pc_483740;
case UINT64_C(0x483746):goto kg_pc_483746;
case UINT64_C(0x483749):goto kg_pc_483749;
case UINT64_C(0x48374c):goto kg_pc_48374c;
case UINT64_C(0x483752):goto kg_pc_483752;
case UINT64_C(0x483759):goto kg_pc_483759;
case UINT64_C(0x48375c):goto kg_pc_48375c;
case UINT64_C(0x48375f):goto kg_pc_48375f;
case UINT64_C(0x483763):goto kg_pc_483763;
case UINT64_C(0x483768):goto kg_pc_483768;
case UINT64_C(0x48376a):goto kg_pc_48376a;
case UINT64_C(0x483771):goto kg_pc_483771;
case UINT64_C(0x483775):goto kg_pc_483775;
case UINT64_C(0x48377c):goto kg_pc_48377c;
case UINT64_C(0x48377f):goto kg_pc_48377f;
case UINT64_C(0x483786):goto kg_pc_483786;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5291: [0x48373c,0x483788), 18 instructions. */
kg_pc_48373c: STEP(0x48373c); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48373e: STEP(0x48373e); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483740: STEP(0x483740); /* cmp edi, 0xe982a16 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xe982a16);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_483746: STEP(0x483746); /* setne al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483749: STEP(0x483749); /* sete cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48374c: STEP(0x48374c); /* imul edx, ecx, 0x21c1 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x21c1);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_483752: STEP(0x483752); /* imul r8d, eax, 0x21bb */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x21bb);
s->gpr[8] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_483759: STEP(0x483759); /* add r8d, r15d */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = (s->gpr[15] & UINT64_C(0xffffffff));
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48375c: STEP(0x48375c); /* add r8d, edx */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48375f: STEP(0x48375f); /* lea eax, [r15 + rcx] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[15] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_483763: STEP(0x483763); /* add eax, 0x21bd */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x21bd);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483768: STEP(0x483768); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_48376a: STEP(0x48376a); /* lea r11, [rip - 0x47c421] */
s->gpr[11] = (UINT64_C(0xffffffffffb83bdf) + (bias + UINT64_C(0x483771)));
++s->steps;
kg_pc_483771: STEP(0x483771); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483775: STEP(0x483775); /* lea rcx, [rip - 0x5b] */
s->gpr[2] = (UINT64_C(0xffffffffffffffa5) + (bias + UINT64_C(0x48377c)));
++s->steps;
kg_pc_48377c: STEP(0x48377c); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_48377f: STEP(0x48377f); /* mov r12, qword ptr [rbp - 0x110] */
READ(a, (UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_483786: STEP(0x483786); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 53:
next_pc=bias+UINT64_C(0x4837ed);
switch(s->pc-bias){
case UINT64_C(0x48378b):goto kg_pc_48378b;
case UINT64_C(0x483792):goto kg_pc_483792;
case UINT64_C(0x483799):goto kg_pc_483799;
case UINT64_C(0x48379c):goto kg_pc_48379c;
case UINT64_C(0x4837a0):goto kg_pc_4837a0;
case UINT64_C(0x4837a7):goto kg_pc_4837a7;
case UINT64_C(0x4837ab):goto kg_pc_4837ab;
case UINT64_C(0x4837ae):goto kg_pc_4837ae;
case UINT64_C(0x4837b2):goto kg_pc_4837b2;
case UINT64_C(0x4837b6):goto kg_pc_4837b6;
case UINT64_C(0x4837bd):goto kg_pc_4837bd;
case UINT64_C(0x4837c0):goto kg_pc_4837c0;
case UINT64_C(0x4837c3):goto kg_pc_4837c3;
case UINT64_C(0x4837ca):goto kg_pc_4837ca;
case UINT64_C(0x4837d4):goto kg_pc_4837d4;
case UINT64_C(0x4837d7):goto kg_pc_4837d7;
case UINT64_C(0x4837da):goto kg_pc_4837da;
case UINT64_C(0x4837e1):goto kg_pc_4837e1;
case UINT64_C(0x4837e4):goto kg_pc_4837e4;
case UINT64_C(0x4837eb):goto kg_pc_4837eb;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5292: [0x48378b,0x4837ed), 20 instructions. */
kg_pc_48378b: STEP(0x48378b); /* mov r14, qword ptr [rbp - 0x2530] */
READ(a, (UINT64_C(0xffffffffffffdad0) + s->gpr[6]), 8);
s->gpr[14] = a;
++s->steps;
kg_pc_483792: STEP(0x483792); /* mov rax, qword ptr [rbp - 0x128] */
READ(a, (UINT64_C(0xfffffffffffffed8) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_483799: STEP(0x483799); /* movsxd rcx, dword ptr [rax] */
READ(a, (UINT64_C(0x0) + s->gpr[0]), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48379c: STEP(0x48379c); /* mov rdx, qword ptr [r12] */
READ(a, (UINT64_C(0x0) + s->gpr[12]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_4837a0: STEP(0x4837a0); /* and rcx, 0xffffffffdb1cd9f8 */
x = s->gpr[2]; y = UINT64_C(0xffffffffdb1cd9f8);
s->gpr[2] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_4837a7: STEP(0x4837a7); /* mov r10d, dword ptr [rdx + rcx] */
READ(a, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x1))), 4);
s->gpr[10] = (uint32_t)(a);
++s->steps;
kg_pc_4837ab: STEP(0x4837ab); /* movsxd rdx, r8d */
s->gpr[3] = (((s->gpr[8] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4837ae: STEP(0x4837ae); /* add r8d, -8 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffffffffffffff8);
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4837b2: STEP(0x4837b2); /* movsxd rdx, dword ptr [r11 + rdx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[3] * UINT64_C(0x4))), 4);
s->gpr[3] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4837b6: STEP(0x4837b6); /* lea rdi, [rip - 0x32] */
s->gpr[5] = (UINT64_C(0xffffffffffffffce) + (bias + UINT64_C(0x4837bd)));
++s->steps;
kg_pc_4837bd: STEP(0x4837bd); /* add rdi, rdx */
x = s->gpr[5]; y = s->gpr[3];
s->gpr[5] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4837c0: STEP(0x4837c0); /* mov r15, r11 */
s->gpr[15] = s->gpr[11];
++s->steps;
kg_pc_4837c3: STEP(0x4837c3); /* mov r11, qword ptr [rbp - 0x840] */
READ(a, (UINT64_C(0xfffffffffffff7c0) + s->gpr[6]), 8);
s->gpr[11] = a;
++s->steps;
kg_pc_4837ca: STEP(0x4837ca); /* movabs rax, 0x6f79466dab33c918 */
s->gpr[0] = UINT64_C(0x6f79466dab33c918);
++s->steps;
kg_pc_4837d4: STEP(0x4837d4); /* add r11, rax */
x = s->gpr[11]; y = s->gpr[0];
s->gpr[11] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4837d7: STEP(0x4837d7); /* xor r13d, r13d */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[13] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4837da: STEP(0x4837da); /* lea r9, [rip + 0xf] */
s->gpr[9] = (UINT64_C(0xf) + (bias + UINT64_C(0x4837e1)));
++s->steps;
kg_pc_4837e1: STEP(0x4837e1); /* mov rsi, r8 */
s->gpr[4] = s->gpr[8];
++s->steps;
kg_pc_4837e4: STEP(0x4837e4); /* lea r8, [rip + 0xb5] */
s->gpr[8] = (UINT64_C(0xb5) + (bias + UINT64_C(0x4837eb)));
++s->steps;
kg_pc_4837eb: STEP(0x4837eb); /* jmp rdi */
x = s->gpr[5];
next_pc = x;
++s->steps;

break;
    case 54:
next_pc=bias+UINT64_C(0x48389f);
switch(s->pc-bias){
case UINT64_C(0x4837f0):goto kg_pc_4837f0;
case UINT64_C(0x4837f4):goto kg_pc_4837f4;
case UINT64_C(0x4837f7):goto kg_pc_4837f7;
case UINT64_C(0x4837fd):goto kg_pc_4837fd;
case UINT64_C(0x483803):goto kg_pc_483803;
case UINT64_C(0x483805):goto kg_pc_483805;
case UINT64_C(0x483808):goto kg_pc_483808;
case UINT64_C(0x48380a):goto kg_pc_48380a;
case UINT64_C(0x483810):goto kg_pc_483810;
case UINT64_C(0x483813):goto kg_pc_483813;
case UINT64_C(0x483817):goto kg_pc_483817;
case UINT64_C(0x48381e):goto kg_pc_48381e;
case UINT64_C(0x483822):goto kg_pc_483822;
case UINT64_C(0x483824):goto kg_pc_483824;
case UINT64_C(0x483828):goto kg_pc_483828;
case UINT64_C(0x48382f):goto kg_pc_48382f;
case UINT64_C(0x483832):goto kg_pc_483832;
case UINT64_C(0x483839):goto kg_pc_483839;
case UINT64_C(0x48383c):goto kg_pc_48383c;
case UINT64_C(0x48383f):goto kg_pc_48383f;
case UINT64_C(0x483841):goto kg_pc_483841;
case UINT64_C(0x483843):goto kg_pc_483843;
case UINT64_C(0x483845):goto kg_pc_483845;
case UINT64_C(0x483848):goto kg_pc_483848;
case UINT64_C(0x48384d):goto kg_pc_48384d;
case UINT64_C(0x48384f):goto kg_pc_48384f;
case UINT64_C(0x483855):goto kg_pc_483855;
case UINT64_C(0x483857):goto kg_pc_483857;
case UINT64_C(0x48385d):goto kg_pc_48385d;
case UINT64_C(0x48385f):goto kg_pc_48385f;
case UINT64_C(0x483862):goto kg_pc_483862;
case UINT64_C(0x483868):goto kg_pc_483868;
case UINT64_C(0x48386b):goto kg_pc_48386b;
case UINT64_C(0x483871):goto kg_pc_483871;
case UINT64_C(0x483873):goto kg_pc_483873;
case UINT64_C(0x483875):goto kg_pc_483875;
case UINT64_C(0x48387b):goto kg_pc_48387b;
case UINT64_C(0x48387e):goto kg_pc_48387e;
case UINT64_C(0x483881):goto kg_pc_483881;
case UINT64_C(0x483884):goto kg_pc_483884;
case UINT64_C(0x483887):goto kg_pc_483887;
case UINT64_C(0x48388a):goto kg_pc_48388a;
case UINT64_C(0x48388d):goto kg_pc_48388d;
case UINT64_C(0x48388f):goto kg_pc_48388f;
case UINT64_C(0x483891):goto kg_pc_483891;
case UINT64_C(0x483893):goto kg_pc_483893;
case UINT64_C(0x483896):goto kg_pc_483896;
case UINT64_C(0x48389a):goto kg_pc_48389a;
case UINT64_C(0x48389d):goto kg_pc_48389d;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5293: [0x4837f0,0x48389f), 49 instructions. */
kg_pc_4837f0: STEP(0x4837f0); /* lea rcx, [r14 + r13] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[14] + (s->gpr[13] * UINT64_C(0x1)));
++s->steps;
kg_pc_4837f4: STEP(0x4837f4); /* xor ecx, r10d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4837f7: STEP(0x4837f7); /* and ecx, 0x7fffffff */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x7fffffff);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4837fd: STEP(0x4837fd); /* imul ecx, ecx, 0xa57ed9a7 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xa57ed9a7);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_483803: STEP(0x483803); /* mov edi, ecx */
s->gpr[5] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483805: STEP(0x483805); /* shr edi, 0x10 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[5] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_483808: STEP(0x483808); /* xor edi, ecx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48380a: STEP(0x48380a); /* imul ecx, edi, 0xa57ed9a7 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xa57ed9a7);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_483810: STEP(0x483810); /* mov rdi, rcx */
s->gpr[5] = s->gpr[2];
++s->steps;
kg_pc_483813: STEP(0x483813); /* shr rdi, 0x18 */
x = s->gpr[5]; y = UINT64_C(0x18);
s->gpr[5] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_483817: STEP(0x483817); /* mov rax, qword ptr [rbp - 0xf20] */
READ(a, (UINT64_C(0xfffffffffffff0e0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_48381e: STEP(0x48381e); /* movzx ebx, byte ptr [rax + rdi] */
READ(a, (UINT64_C(0x0) + s->gpr[0] + (s->gpr[5] * UINT64_C(0x1))), 1);
s->gpr[1] = (uint32_t)(a);
++s->steps;
kg_pc_483822: STEP(0x483822); /* mov edx, edi */
s->gpr[3] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483824: STEP(0x483824); /* xor bl, byte ptr [r14 + r13] */
READ(b, (UINT64_C(0x0) + s->gpr[14] + (s->gpr[13] * UINT64_C(0x1))), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483828: STEP(0x483828); /* mov rax, qword ptr [rbp - 0xf18] */
READ(a, (UINT64_C(0xfffffffffffff0e8) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_48382f: STEP(0x48382f); /* xor bl, byte ptr [rax + rdi] */
READ(b, (UINT64_C(0x0) + s->gpr[0] + (s->gpr[5] * UINT64_C(0x1))), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483832: STEP(0x483832); /* mov rax, qword ptr [rbp - 0xf10] */
READ(a, (UINT64_C(0xfffffffffffff0f0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_483839: STEP(0x483839); /* xor bl, byte ptr [rax + rdi] */
READ(b, (UINT64_C(0x0) + s->gpr[0] + (s->gpr[5] * UINT64_C(0x1))), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48383c: STEP(0x48383c); /* shl edi, 4 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x4);
s->gpr[5] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_48383f: STEP(0x48383f); /* sub edx, edi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_483841: STEP(0x483841); /* xor dl, cl */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483843: STEP(0x483843); /* xor dl, bl */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[1] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483845: STEP(0x483845); /* movzx ecx, dl */
s->gpr[2] = (uint32_t)((s->gpr[3] & UINT64_C(0xff)));
++s->steps;
kg_pc_483848: STEP(0x483848); /* movzx edx, byte ptr [r11 + r13] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[13] * UINT64_C(0x1))), 1);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_48384d: STEP(0x48384d); /* mov edi, edx */
s->gpr[5] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48384f: STEP(0x48384f); /* xor edi, 0x9aa80e60 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x9aa80e60);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483855: STEP(0x483855); /* add edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483857: STEP(0x483857); /* and edx, 0x13e */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x13e);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48385d: STEP(0x48385d); /* sub edi, edx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_48385f: STEP(0x48385f); /* lea edx, [rdi + rcx*2] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[2] * UINT64_C(0x2))));
++s->steps;
kg_pc_483862: STEP(0x483862); /* xor ecx, 0x4df7dfff */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x4df7dfff);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483868: STEP(0x483868); /* lea ebx, [rcx + rdx] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_48386b: STEP(0x48386b); /* add ebx, 0x25f83bb7 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x25f83bb7);
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483871: STEP(0x483871); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483873: STEP(0x483873); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483875: STEP(0x483875); /* cmp ebx, 0xe982a16 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0xe982a16);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_48387b: STEP(0x48387b); /* setne cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48387e: STEP(0x48387e); /* sete dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483881: STEP(0x483881); /* lea edi, [rdx + rdx*2] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_483884: STEP(0x483884); /* lea eax, [rdx + rdi*4] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[5] * UINT64_C(0x4))));
++s->steps;
kg_pc_483887: STEP(0x483887); /* lea ecx, [rcx + rcx*4] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x4))));
++s->steps;
kg_pc_48388a: STEP(0x48388a); /* lea edi, [rcx + rcx*2] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x2))));
++s->steps;
kg_pc_48388d: STEP(0x48388d); /* add edi, esi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48388f: STEP(0x48388f); /* add edi, eax */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483891: STEP(0x483891); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483893: STEP(0x483893); /* movsxd rax, edx */
s->gpr[0] = (((s->gpr[3] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483896: STEP(0x483896); /* movsxd rax, dword ptr [r15 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[15] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48389a: STEP(0x48389a); /* add rax, r9 */
x = s->gpr[0]; y = s->gpr[9];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_48389d: STEP(0x48389d); /* jmp rax */
x = s->gpr[0];
next_pc = x;
++s->steps;

break;
    case 55:
next_pc=bias+UINT64_C(0x4838cf);
switch(s->pc-bias){
case UINT64_C(0x4838a0):goto kg_pc_4838a0;
case UINT64_C(0x4838a2):goto kg_pc_4838a2;
case UINT64_C(0x4838a4):goto kg_pc_4838a4;
case UINT64_C(0x4838a8):goto kg_pc_4838a8;
case UINT64_C(0x4838ab):goto kg_pc_4838ab;
case UINT64_C(0x4838ae):goto kg_pc_4838ae;
case UINT64_C(0x4838b1):goto kg_pc_4838b1;
case UINT64_C(0x4838b4):goto kg_pc_4838b4;
case UINT64_C(0x4838b6):goto kg_pc_4838b6;
case UINT64_C(0x4838b8):goto kg_pc_4838b8;
case UINT64_C(0x4838bb):goto kg_pc_4838bb;
case UINT64_C(0x4838bf):goto kg_pc_4838bf;
case UINT64_C(0x4838c2):goto kg_pc_4838c2;
case UINT64_C(0x4838c6):goto kg_pc_4838c6;
case UINT64_C(0x4838cb):goto kg_pc_4838cb;
case UINT64_C(0x4838cd):goto kg_pc_4838cd;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5294: [0x4838a0,0x4838cf), 16 instructions. */
kg_pc_4838a0: STEP(0x4838a0); /* xor ebx, ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4838a2: STEP(0x4838a2); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4838a4: STEP(0x4838a4); /* cmp r13, 7 */
x = s->gpr[13]; y = UINT64_C(0x7);
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_4838a8: STEP(0x4838a8); /* setne bl */
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4838ab: STEP(0x4838ab); /* sete cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4838ae: STEP(0x4838ae); /* imul ebx, ebx, -0xd */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffffffffffffff3);
s->gpr[1] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_4838b1: STEP(0x4838b1); /* lea esi, [rbx + rcx*2] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[2] * UINT64_C(0x2))));
++s->steps;
kg_pc_4838b4: STEP(0x4838b4); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4838b6: STEP(0x4838b6); /* add edi, ecx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4838b8: STEP(0x4838b8); /* movsxd rcx, edi */
s->gpr[2] = (((s->gpr[5] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4838bb: STEP(0x4838bb); /* movsxd rcx, dword ptr [r15 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[15] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4838bf: STEP(0x4838bf); /* add rcx, r8 */
x = s->gpr[2]; y = s->gpr[8];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4838c2: STEP(0x4838c2); /* add r13, 1 */
x = s->gpr[13]; y = UINT64_C(0x1);
s->gpr[13] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4838c6: STEP(0x4838c6); /* mov ebx, 0xe982a16 */
s->gpr[1] = (uint32_t)(UINT64_C(0xe982a16));
++s->steps;
kg_pc_4838cb: STEP(0x4838cb); /* mov edi, esi */
s->gpr[5] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4838cd: STEP(0x4838cd); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 56:
next_pc=bias+UINT64_C(0x4838fb);
switch(s->pc-bias){
case UINT64_C(0x4838d1):goto kg_pc_4838d1;
case UINT64_C(0x4838d5):goto kg_pc_4838d5;
case UINT64_C(0x4838db):goto kg_pc_4838db;
case UINT64_C(0x4838e0):goto kg_pc_4838e0;
case UINT64_C(0x4838e3):goto kg_pc_4838e3;
case UINT64_C(0x4838e6):goto kg_pc_4838e6;
case UINT64_C(0x4838e8):goto kg_pc_4838e8;
case UINT64_C(0x4838ec):goto kg_pc_4838ec;
case UINT64_C(0x4838f3):goto kg_pc_4838f3;
case UINT64_C(0x4838f6):goto kg_pc_4838f6;
case UINT64_C(0x4838f9):goto kg_pc_4838f9;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5295: [0x4838d1,0x4838fb), 11 instructions. */
kg_pc_4838d1: STEP(0x4838d1); /* lea r8d, [rdi - 0xd] */
s->gpr[8] = (uint32_t)((UINT64_C(0xfffffffffffffff3) + s->gpr[5]));
++s->steps;
kg_pc_4838d5: STEP(0x4838d5); /* cmp ebx, 0xe982a16 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0xe982a16);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_4838db: STEP(0x4838db); /* mov ecx, 0xe97836a */
s->gpr[2] = (uint32_t)(UINT64_C(0xe97836a));
++s->steps;
kg_pc_4838e0: STEP(0x4838e0); /* cmove ecx, ebx */
s->gpr[2] = (uint32_t)((condition(s, COND_E) ? (s->gpr[1] & UINT64_C(0xffffffff)) : (s->gpr[2] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_4838e3: STEP(0x4838e3); /* movsxd rax, edi */
s->gpr[0] = (((s->gpr[5] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4838e6: STEP(0x4838e6); /* mov edi, ecx */
s->gpr[5] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4838e8: STEP(0x4838e8); /* movsxd rax, dword ptr [r15 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[15] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4838ec: STEP(0x4838ec); /* lea rcx, [rip - 0x22] */
s->gpr[2] = (UINT64_C(0xffffffffffffffde) + (bias + UINT64_C(0x4838f3)));
++s->steps;
kg_pc_4838f3: STEP(0x4838f3); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4838f6: STEP(0x4838f6); /* mov r11, r15 */
s->gpr[11] = s->gpr[15];
++s->steps;
kg_pc_4838f9: STEP(0x4838f9); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 57:
next_pc=bias+UINT64_C(0x483937);
switch(s->pc-bias){
case UINT64_C(0x4838fd):goto kg_pc_4838fd;
case UINT64_C(0x483904):goto kg_pc_483904;
case UINT64_C(0x483906):goto kg_pc_483906;
case UINT64_C(0x483908):goto kg_pc_483908;
case UINT64_C(0x48390b):goto kg_pc_48390b;
case UINT64_C(0x48390e):goto kg_pc_48390e;
case UINT64_C(0x483911):goto kg_pc_483911;
case UINT64_C(0x483917):goto kg_pc_483917;
case UINT64_C(0x48391b):goto kg_pc_48391b;
case UINT64_C(0x48391e):goto kg_pc_48391e;
case UINT64_C(0x483921):goto kg_pc_483921;
case UINT64_C(0x483924):goto kg_pc_483924;
case UINT64_C(0x483927):goto kg_pc_483927;
case UINT64_C(0x48392b):goto kg_pc_48392b;
case UINT64_C(0x483932):goto kg_pc_483932;
case UINT64_C(0x483935):goto kg_pc_483935;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5296: [0x4838fd,0x483937), 16 instructions. */
kg_pc_4838fd: STEP(0x4838fd); /* mov rax, qword ptr [rbp - 0x2530] */
READ(a, (UINT64_C(0xffffffffffffdad0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_483904: STEP(0x483904); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483906: STEP(0x483906); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483908: STEP(0x483908); /* test rax, rax */
x = s->gpr[0]; y = s->gpr[0];
(void)operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_48390b: STEP(0x48390b); /* setne cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48390e: STEP(0x48390e); /* sete dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483911: STEP(0x483911); /* imul esi, edx, 0xfffffe64 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffffe64);
s->gpr[4] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_483917: STEP(0x483917); /* lea r15d, [rcx + rcx*4] */
s->gpr[15] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x4))));
++s->steps;
kg_pc_48391b: STEP(0x48391b); /* add r15d, r8d */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[15] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48391e: STEP(0x48391e); /* add r15d, esi */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[15] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483921: STEP(0x483921); /* add edx, r8d */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483924: STEP(0x483924); /* movsxd rcx, edx */
s->gpr[2] = (((s->gpr[3] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483927: STEP(0x483927); /* movsxd rcx, dword ptr [r11 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48392b: STEP(0x48392b); /* lea rdx, [rip - 0x35] */
s->gpr[3] = (UINT64_C(0xffffffffffffffcb) + (bias + UINT64_C(0x483932)));
++s->steps;
kg_pc_483932: STEP(0x483932); /* add rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483935: STEP(0x483935); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 58:
next_pc=bias+UINT64_C(0x483996);
switch(s->pc-bias){
case UINT64_C(0x483938):goto kg_pc_483938;
case UINT64_C(0x48393f):goto kg_pc_48393f;
case UINT64_C(0x483946):goto kg_pc_483946;
case UINT64_C(0x483948):goto kg_pc_483948;
case UINT64_C(0x48394f):goto kg_pc_48394f;
case UINT64_C(0x483951):goto kg_pc_483951;
case UINT64_C(0x48395b):goto kg_pc_48395b;
case UINT64_C(0x48395d):goto kg_pc_48395d;
case UINT64_C(0x483963):goto kg_pc_483963;
case UINT64_C(0x48396a):goto kg_pc_48396a;
case UINT64_C(0x483971):goto kg_pc_483971;
case UINT64_C(0x483978):goto kg_pc_483978;
case UINT64_C(0x48397a):goto kg_pc_48397a;
case UINT64_C(0x48397c):goto kg_pc_48397c;
case UINT64_C(0x483982):goto kg_pc_483982;
case UINT64_C(0x483988):goto kg_pc_483988;
case UINT64_C(0x48398a):goto kg_pc_48398a;
case UINT64_C(0x483990):goto kg_pc_483990;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5297: [0x483938,0x483996), 18 instructions. */
kg_pc_483938: STEP(0x483938); /* lea r14d, [r15 - 0x1a1] */
s->gpr[14] = (uint32_t)((UINT64_C(0xfffffffffffffe5f) + s->gpr[15]));
++s->steps;
kg_pc_48393f: STEP(0x48393f); /* lea ecx, [r15 - 0x21c7] */
s->gpr[2] = (uint32_t)((UINT64_C(0xffffffffffffde39) + s->gpr[15]));
++s->steps;
kg_pc_483946: STEP(0x483946); /* mov ebx, edi */
s->gpr[1] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483948: STEP(0x483948); /* lea rdi, [rbp - 0x1f8] */
s->gpr[5] = (UINT64_C(0xfffffffffffffe08) + s->gpr[6]);
++s->steps;
kg_pc_48394f: STEP(0x48394f); /* mov edx, edi */
s->gpr[3] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483951: STEP(0x483951); /* movabs rsi, 0xd7cf669026532472 */
s->gpr[4] = UINT64_C(0xd7cf669026532472);
++s->steps;
kg_pc_48395b: STEP(0x48395b); /* xor edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48395d: STEP(0x48395d); /* imul edx, edx, 0x20bd8b7f */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x20bd8b7f);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_483963: STEP(0x483963); /* mov qword ptr [rbp - 0x1f0], rax */
WRITE((UINT64_C(0xfffffffffffffe10) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_48396a: STEP(0x48396a); /* lea rax, [rip - 0x2e2f66] */
s->gpr[0] = (UINT64_C(0xffffffffffd1d09a) + (bias + UINT64_C(0x483971)));
++s->steps;
kg_pc_483971: STEP(0x483971); /* lea rsi, [rip - 0x2e2ed9] */
s->gpr[4] = (UINT64_C(0xffffffffffd1d127) + (bias + UINT64_C(0x483978)));
++s->steps;
kg_pc_483978: STEP(0x483978); /* sub esi, eax */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_48397a: STEP(0x48397a); /* sub esi, edx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_48397c: STEP(0x48397c); /* add esi, 0x8fc */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x8fc);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483982: STEP(0x483982); /* mov dword ptr [rbp - 0x1f8], esi */
WRITE((UINT64_C(0xfffffffffffffe08) + s->gpr[6]), 4, (s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483988: STEP(0x483988); /* xor ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48398a: STEP(0x48398a); /* mov dword ptr [rbp - 0x1e8], ecx */
WRITE((UINT64_C(0xfffffffffffffe18) + s->gpr[6]), 4, (s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483990: STEP(0x483990); /* call qword ptr [rbp - 0x458] */
READ(a, (UINT64_C(0xfffffffffffffba8) + s->gpr[6]), 8);
x = a;
y = s->gpr[7] - 8;
WRITE(y, 8, bias + UINT64_C(0x483996));
s->gpr[7] = y;
next_pc = x;
++s->steps;

break;
    case 59:
next_pc=bias+UINT64_C(0x4839b5);
switch(s->pc-bias){
case UINT64_C(0x483996):goto kg_pc_483996;
case UINT64_C(0x483998):goto kg_pc_483998;
case UINT64_C(0x48399f):goto kg_pc_48399f;
case UINT64_C(0x4839a2):goto kg_pc_4839a2;
case UINT64_C(0x4839a6):goto kg_pc_4839a6;
case UINT64_C(0x4839ad):goto kg_pc_4839ad;
case UINT64_C(0x4839b0):goto kg_pc_4839b0;
case UINT64_C(0x4839b3):goto kg_pc_4839b3;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5298: [0x483996,0x4839b5), 8 instructions. */
kg_pc_483996: STEP(0x483996); /* mov edi, ebx */
s->gpr[5] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483998: STEP(0x483998); /* lea r11, [rip - 0x47c64f] */
s->gpr[11] = (UINT64_C(0xffffffffffb839b1) + (bias + UINT64_C(0x48399f)));
++s->steps;
kg_pc_48399f: STEP(0x48399f); /* movsxd rax, r15d */
s->gpr[0] = (((s->gpr[15] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4839a2: STEP(0x4839a2); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4839a6: STEP(0x4839a6); /* lea rcx, [rip - 0x75] */
s->gpr[2] = (UINT64_C(0xffffffffffffff8b) + (bias + UINT64_C(0x4839ad)));
++s->steps;
kg_pc_4839ad: STEP(0x4839ad); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4839b0: STEP(0x4839b0); /* mov r15d, r14d */
s->gpr[15] = (uint32_t)((s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4839b3: STEP(0x4839b3); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 60:
next_pc=bias+UINT64_C(0x483a09);
switch(s->pc-bias){
case UINT64_C(0x4839b7):goto kg_pc_4839b7;
case UINT64_C(0x4839bb):goto kg_pc_4839bb;
case UINT64_C(0x4839c3):goto kg_pc_4839c3;
case UINT64_C(0x4839c9):goto kg_pc_4839c9;
case UINT64_C(0x4839cb):goto kg_pc_4839cb;
case UINT64_C(0x4839ce):goto kg_pc_4839ce;
case UINT64_C(0x4839d4):goto kg_pc_4839d4;
case UINT64_C(0x4839d9):goto kg_pc_4839d9;
case UINT64_C(0x4839db):goto kg_pc_4839db;
case UINT64_C(0x4839e1):goto kg_pc_4839e1;
case UINT64_C(0x4839e3):goto kg_pc_4839e3;
case UINT64_C(0x4839e5):goto kg_pc_4839e5;
case UINT64_C(0x4839eb):goto kg_pc_4839eb;
case UINT64_C(0x4839ef):goto kg_pc_4839ef;
case UINT64_C(0x4839f6):goto kg_pc_4839f6;
case UINT64_C(0x4839f9):goto kg_pc_4839f9;
case UINT64_C(0x4839fd):goto kg_pc_4839fd;
case UINT64_C(0x483a04):goto kg_pc_483a04;
case UINT64_C(0x483a07):goto kg_pc_483a07;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5299: [0x4839b7,0x483a09), 19 instructions. */
kg_pc_4839b7: STEP(0x4839b7); /* lea r14d, [r15 + 0xa] */
s->gpr[14] = (uint32_t)((UINT64_C(0xa) + s->gpr[15]));
++s->steps;
kg_pc_4839bb: STEP(0x4839bb); /* add qword ptr [rbp - 0x2c8], -0x10 */
READ(a, (UINT64_C(0xfffffffffffffd38) + s->gpr[6]), 8);
x = a; y = UINT64_C(0xfffffffffffffff0);
WRITE((UINT64_C(0xfffffffffffffd38) + s->gpr[6]), 8, operation(s, OP_ADD, x, y, 64));
++s->steps;
kg_pc_4839c3: STEP(0x4839c3); /* mov eax, dword ptr [rbp - 0x924] */
READ(a, (UINT64_C(0xfffffffffffff6dc) + s->gpr[6]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_4839c9: STEP(0x4839c9); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4839cb: STEP(0x4839cb); /* or ecx, 2 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x2);
s->gpr[2] = (uint32_t)(operation(s, OP_OR, x, y, 32));
++s->steps;
kg_pc_4839ce: STEP(0x4839ce); /* xor ecx, 0x47675ddd */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x47675ddd);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4839d4: STEP(0x4839d4); /* or eax, 0x4ff7dfdf */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x4ff7dfdf);
s->gpr[0] = (uint32_t)(operation(s, OP_OR, x, y, 32));
++s->steps;
kg_pc_4839d9: STEP(0x4839d9); /* mov edx, ecx */
s->gpr[3] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4839db: STEP(0x4839db); /* and edx, 0x776f7dfd */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x776f7dfd);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4839e1: STEP(0x4839e1); /* xor edx, eax */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4839e3: STEP(0x4839e3); /* add edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4839e5: STEP(0x4839e5); /* xor edx, 0x60104045 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x60104045);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4839eb: STEP(0x4839eb); /* lea r8d, [rcx + rdx] */
s->gpr[8] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_4839ef: STEP(0x4839ef); /* add r8d, 0x47675de0 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x47675de0);
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4839f6: STEP(0x4839f6); /* movsxd rax, r15d */
s->gpr[0] = (((s->gpr[15] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4839f9: STEP(0x4839f9); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4839fd: STEP(0x4839fd); /* lea rcx, [rip - 0x4d] */
s->gpr[2] = (UINT64_C(0xffffffffffffffb3) + (bias + UINT64_C(0x483a04)));
++s->steps;
kg_pc_483a04: STEP(0x483a04); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483a07: STEP(0x483a07); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 61:
next_pc=bias+UINT64_C(0x483a35);
switch(s->pc-bias){
case UINT64_C(0x483a0a):goto kg_pc_483a0a;
case UINT64_C(0x483a0d):goto kg_pc_483a0d;
case UINT64_C(0x483a14):goto kg_pc_483a14;
case UINT64_C(0x483a17):goto kg_pc_483a17;
case UINT64_C(0x483a1e):goto kg_pc_483a1e;
case UINT64_C(0x483a22):goto kg_pc_483a22;
case UINT64_C(0x483a29):goto kg_pc_483a29;
case UINT64_C(0x483a2c):goto kg_pc_483a2c;
case UINT64_C(0x483a33):goto kg_pc_483a33;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5300: [0x483a0a,0x483a35), 9 instructions. */
kg_pc_483a0a: STEP(0x483a0a); /* mov r10d, edi */
s->gpr[10] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483a0d: STEP(0x483a0d); /* mov r9d, dword ptr [rbp - 0x7e4] */
READ(a, (UINT64_C(0xfffffffffffff81c) + s->gpr[6]), 4);
s->gpr[9] = (uint32_t)(a);
++s->steps;
kg_pc_483a14: STEP(0x483a14); /* movsxd rax, r14d */
s->gpr[0] = (((s->gpr[14] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483a17: STEP(0x483a17); /* add r14d, 0xffffe0d8 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffe0d8);
s->gpr[14] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483a1e: STEP(0x483a1e); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483a22: STEP(0x483a22); /* lea rcx, [rip - 0x1f] */
s->gpr[2] = (UINT64_C(0xffffffffffffffe1) + (bias + UINT64_C(0x483a29)));
++s->steps;
kg_pc_483a29: STEP(0x483a29); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483a2c: STEP(0x483a2c); /* mov rbx, qword ptr [rbp - 0x128] */
READ(a, (UINT64_C(0xfffffffffffffed8) + s->gpr[6]), 8);
s->gpr[1] = a;
++s->steps;
kg_pc_483a33: STEP(0x483a33); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 62:
next_pc=bias+UINT64_C(0x483a8c);
switch(s->pc-bias){
case UINT64_C(0x483a37):goto kg_pc_483a37;
case UINT64_C(0x483a3e):goto kg_pc_483a3e;
case UINT64_C(0x483a48):goto kg_pc_483a48;
case UINT64_C(0x483a4c):goto kg_pc_483a4c;
case UINT64_C(0x483a51):goto kg_pc_483a51;
case UINT64_C(0x483a57):goto kg_pc_483a57;
case UINT64_C(0x483a5d):goto kg_pc_483a5d;
case UINT64_C(0x483a5f):goto kg_pc_483a5f;
case UINT64_C(0x483a65):goto kg_pc_483a65;
case UINT64_C(0x483a69):goto kg_pc_483a69;
case UINT64_C(0x483a6f):goto kg_pc_483a6f;
case UINT64_C(0x483a72):goto kg_pc_483a72;
case UINT64_C(0x483a75):goto kg_pc_483a75;
case UINT64_C(0x483a77):goto kg_pc_483a77;
case UINT64_C(0x483a79):goto kg_pc_483a79;
case UINT64_C(0x483a7d):goto kg_pc_483a7d;
case UINT64_C(0x483a7f):goto kg_pc_483a7f;
case UINT64_C(0x483a82):goto kg_pc_483a82;
case UINT64_C(0x483a87):goto kg_pc_483a87;
case UINT64_C(0x483a8a):goto kg_pc_483a8a;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5301: [0x483a37,0x483a8c), 20 instructions. */
kg_pc_483a37: STEP(0x483a37); /* mov r8, qword ptr [rbp - 0x840] */
READ(a, (UINT64_C(0xfffffffffffff7c0) + s->gpr[6]), 8);
s->gpr[8] = a;
++s->steps;
kg_pc_483a3e: STEP(0x483a3e); /* movabs rax, 0x6f79466dab33c928 */
s->gpr[0] = UINT64_C(0x6f79466dab33c928);
++s->steps;
kg_pc_483a48: STEP(0x483a48); /* mov eax, dword ptr [r8 + rax] */
READ(a, (UINT64_C(0x0) + s->gpr[8] + (s->gpr[0] * UINT64_C(0x1))), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_483a4c: STEP(0x483a4c); /* mov ecx, 0xeaa52d3b */
s->gpr[2] = (uint32_t)(UINT64_C(0xeaa52d3b));
++s->steps;
kg_pc_483a51: STEP(0x483a51); /* add ecx, dword ptr [rbp - 0x207c] */
READ(b, (UINT64_C(0xffffffffffffdf84) + s->gpr[6]), 4);
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = b;
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483a57: STEP(0x483a57); /* lea edx, [rax + 0x2b6e8127] */
s->gpr[3] = (uint32_t)((UINT64_C(0x2b6e8127) + s->gpr[0]));
++s->steps;
kg_pc_483a5d: STEP(0x483a5d); /* xor edi, edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483a5f: STEP(0x483a5f); /* cmp edx, 0x506e2d83 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x506e2d83);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_483a65: STEP(0x483a65); /* setb dil */
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483a69: STEP(0x483a69); /* cmp ecx, 0x506e2d83 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x506e2d83);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_483a6f: STEP(0x483a6f); /* setb bl */
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483a72: STEP(0x483a72); /* xor bl, dil */
x = (s->gpr[1] & UINT64_C(0xff)); y = (s->gpr[5] & UINT64_C(0xff));
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483a75: STEP(0x483a75); /* xor esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483a77: STEP(0x483a77); /* cmp edx, ecx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_483a79: STEP(0x483a79); /* seta sil */
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_A)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483a7d: STEP(0x483a7d); /* test bl, bl */
x = (s->gpr[1] & UINT64_C(0xff)); y = (s->gpr[1] & UINT64_C(0xff));
(void)operation(s, OP_AND, x, y, 8);
++s->steps;
kg_pc_483a7f: STEP(0x483a7f); /* cmovne esi, edi */
s->gpr[4] = (uint32_t)((condition(s, COND_NE) ? (s->gpr[5] & UINT64_C(0xffffffff)) : (s->gpr[4] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_483a82: STEP(0x483a82); /* mov edi, 0xe9829f2 */
s->gpr[5] = (uint32_t)(UINT64_C(0xe9829f2));
++s->steps;
kg_pc_483a87: STEP(0x483a87); /* test sil, sil */
x = (s->gpr[4] & UINT64_C(0xff)); y = (s->gpr[4] & UINT64_C(0xff));
(void)operation(s, OP_AND, x, y, 8);
++s->steps;
kg_pc_483a8a: STEP(0x483a8a); /* jne 0x483a92 */
next_pc = bias + (condition(s, COND_NE) ? UINT64_C(0x483a92) : UINT64_C(0x483a8c));
++s->steps;

break;
    case 63:
next_pc=bias+UINT64_C(0x483a92);
switch(s->pc-bias){
case UINT64_C(0x483a8c):goto kg_pc_483a8c;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5302: [0x483a8c,0x483a92), 1 instructions. */
kg_pc_483a8c: STEP(0x483a8c); /* mov edi, dword ptr [rbp - 0x3410] */
READ(a, (UINT64_C(0xffffffffffffcbf0) + s->gpr[6]), 4);
s->gpr[5] = (uint32_t)(a);
++s->steps;

break;
    case 64:
next_pc=bias+UINT64_C(0x483ad7);
switch(s->pc-bias){
case UINT64_C(0x483a92):goto kg_pc_483a92;
case UINT64_C(0x483a94):goto kg_pc_483a94;
case UINT64_C(0x483a96):goto kg_pc_483a96;
case UINT64_C(0x483a9c):goto kg_pc_483a9c;
case UINT64_C(0x483a9f):goto kg_pc_483a9f;
case UINT64_C(0x483aa2):goto kg_pc_483aa2;
case UINT64_C(0x483aa8):goto kg_pc_483aa8;
case UINT64_C(0x483aae):goto kg_pc_483aae;
case UINT64_C(0x483ab1):goto kg_pc_483ab1;
case UINT64_C(0x483ab3):goto kg_pc_483ab3;
case UINT64_C(0x483ab7):goto kg_pc_483ab7;
case UINT64_C(0x483abd):goto kg_pc_483abd;
case UINT64_C(0x483ac0):goto kg_pc_483ac0;
case UINT64_C(0x483ac7):goto kg_pc_483ac7;
case UINT64_C(0x483acb):goto kg_pc_483acb;
case UINT64_C(0x483ad2):goto kg_pc_483ad2;
case UINT64_C(0x483ad5):goto kg_pc_483ad5;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5303: [0x483a92,0x483ad7), 17 instructions. */
kg_pc_483a92: STEP(0x483a92); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483a94: STEP(0x483a94); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483a96: STEP(0x483a96); /* cmp edi, 0xe982a16 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xe982a16);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_483a9c: STEP(0x483a9c); /* setne cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483a9f: STEP(0x483a9f); /* sete dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483aa2: STEP(0x483aa2); /* imul esi, edx, 0x21c2 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x21c2);
s->gpr[4] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_483aa8: STEP(0x483aa8); /* imul ebx, ecx, 0x190 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x190);
s->gpr[1] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_483aae: STEP(0x483aae); /* add ebx, r15d */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[15] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483ab1: STEP(0x483ab1); /* add ebx, esi */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483ab3: STEP(0x483ab3); /* lea ecx, [r15 + rdx] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[15] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_483ab7: STEP(0x483ab7); /* add ecx, 0x21c4 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x21c4);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483abd: STEP(0x483abd); /* movsxd rcx, ecx */
s->gpr[2] = (((s->gpr[2] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483ac0: STEP(0x483ac0); /* lea r11, [rip - 0x47c777] */
s->gpr[11] = (UINT64_C(0xffffffffffb83889) + (bias + UINT64_C(0x483ac7)));
++s->steps;
kg_pc_483ac7: STEP(0x483ac7); /* movsxd rcx, dword ptr [r11 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483acb: STEP(0x483acb); /* lea rdx, [rip - 0x9b] */
s->gpr[3] = (UINT64_C(0xffffffffffffff65) + (bias + UINT64_C(0x483ad2)));
++s->steps;
kg_pc_483ad2: STEP(0x483ad2); /* add rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483ad5: STEP(0x483ad5); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 65:
next_pc=bias+UINT64_C(0x483b33);
switch(s->pc-bias){
case UINT64_C(0x483ad8):goto kg_pc_483ad8;
case UINT64_C(0x483ada):goto kg_pc_483ada;
case UINT64_C(0x483adf):goto kg_pc_483adf;
case UINT64_C(0x483ae9):goto kg_pc_483ae9;
case UINT64_C(0x483aed):goto kg_pc_483aed;
case UINT64_C(0x483af1):goto kg_pc_483af1;
case UINT64_C(0x483af8):goto kg_pc_483af8;
case UINT64_C(0x483aff):goto kg_pc_483aff;
case UINT64_C(0x483b01):goto kg_pc_483b01;
case UINT64_C(0x483b03):goto kg_pc_483b03;
case UINT64_C(0x483b06):goto kg_pc_483b06;
case UINT64_C(0x483b09):goto kg_pc_483b09;
case UINT64_C(0x483b0c):goto kg_pc_483b0c;
case UINT64_C(0x483b0f):goto kg_pc_483b0f;
case UINT64_C(0x483b12):goto kg_pc_483b12;
case UINT64_C(0x483b15):goto kg_pc_483b15;
case UINT64_C(0x483b17):goto kg_pc_483b17;
case UINT64_C(0x483b19):goto kg_pc_483b19;
case UINT64_C(0x483b1b):goto kg_pc_483b1b;
case UINT64_C(0x483b1e):goto kg_pc_483b1e;
case UINT64_C(0x483b22):goto kg_pc_483b22;
case UINT64_C(0x483b29):goto kg_pc_483b29;
case UINT64_C(0x483b2c):goto kg_pc_483b2c;
case UINT64_C(0x483b31):goto kg_pc_483b31;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5304: [0x483ad8,0x483b33), 24 instructions. */
kg_pc_483ad8: STEP(0x483ad8); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483ada: STEP(0x483ada); /* cmp eax, 0x24ffac5c */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x24ffac5c);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_483adf: STEP(0x483adf); /* movabs rdx, 0x100000000 */
s->gpr[3] = UINT64_C(0x100000000);
++s->steps;
kg_pc_483ae9: STEP(0x483ae9); /* cmovb rcx, rdx */
s->gpr[2] = (condition(s, COND_B) ? s->gpr[3] : s->gpr[2]);
++s->steps;
kg_pc_483aed: STEP(0x483aed); /* lea r12, [rax + rcx] */
s->gpr[12] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1)));
++s->steps;
kg_pc_483af1: STEP(0x483af1); /* add r12, 0x73a72039 */
x = s->gpr[12]; y = UINT64_C(0x73a72039);
s->gpr[12] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483af8: STEP(0x483af8); /* lea r13, [rdx - 0x6759336b] */
s->gpr[13] = (UINT64_C(0xffffffff98a6cc95) + s->gpr[3]);
++s->steps;
kg_pc_483aff: STEP(0x483aff); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483b01: STEP(0x483b01); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483b03: STEP(0x483b03); /* cmp r12, r13 */
x = s->gpr[12]; y = s->gpr[13];
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_483b06: STEP(0x483b06); /* setne al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483b09: STEP(0x483b09); /* sete dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483b0c: STEP(0x483b0c); /* lea esi, [rdx + rdx*2] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_483b0f: STEP(0x483b0f); /* lea esi, [rdx + rsi*4] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x4))));
++s->steps;
kg_pc_483b12: STEP(0x483b12); /* lea edi, [rax + rax*8] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x8))));
++s->steps;
kg_pc_483b15: STEP(0x483b15); /* add edi, esi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483b17: STEP(0x483b17); /* add edi, ebx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483b19: STEP(0x483b19); /* add ebx, edx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483b1b: STEP(0x483b1b); /* movsxd rax, ebx */
s->gpr[0] = (((s->gpr[1] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483b1e: STEP(0x483b1e); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483b22: STEP(0x483b22); /* lea rdx, [rip - 0x51] */
s->gpr[3] = (UINT64_C(0xffffffffffffffaf) + (bias + UINT64_C(0x483b29)));
++s->steps;
kg_pc_483b29: STEP(0x483b29); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483b2c: STEP(0x483b2c); /* mov eax, 0x57e510e1 */
s->gpr[0] = (uint32_t)(UINT64_C(0x57e510e1));
++s->steps;
kg_pc_483b31: STEP(0x483b31); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 66:
next_pc=bias+UINT64_C(0x483bac);
switch(s->pc-bias){
case UINT64_C(0x483b34):goto kg_pc_483b34;
case UINT64_C(0x483b3b):goto kg_pc_483b3b;
case UINT64_C(0x483b45):goto kg_pc_483b45;
case UINT64_C(0x483b49):goto kg_pc_483b49;
case UINT64_C(0x483b50):goto kg_pc_483b50;
case UINT64_C(0x483b53):goto kg_pc_483b53;
case UINT64_C(0x483b5a):goto kg_pc_483b5a;
case UINT64_C(0x483b5d):goto kg_pc_483b5d;
case UINT64_C(0x483b60):goto kg_pc_483b60;
case UINT64_C(0x483b66):goto kg_pc_483b66;
case UINT64_C(0x483b69):goto kg_pc_483b69;
case UINT64_C(0x483b6c):goto kg_pc_483b6c;
case UINT64_C(0x483b73):goto kg_pc_483b73;
case UINT64_C(0x483b76):goto kg_pc_483b76;
case UINT64_C(0x483b7c):goto kg_pc_483b7c;
case UINT64_C(0x483b7f):goto kg_pc_483b7f;
case UINT64_C(0x483b82):goto kg_pc_483b82;
case UINT64_C(0x483b86):goto kg_pc_483b86;
case UINT64_C(0x483b8d):goto kg_pc_483b8d;
case UINT64_C(0x483b90):goto kg_pc_483b90;
case UINT64_C(0x483b9a):goto kg_pc_483b9a;
case UINT64_C(0x483b9e):goto kg_pc_483b9e;
case UINT64_C(0x483ba1):goto kg_pc_483ba1;
case UINT64_C(0x483ba3):goto kg_pc_483ba3;
case UINT64_C(0x483baa):goto kg_pc_483baa;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5305: [0x483b34,0x483bac), 25 instructions. */
kg_pc_483b34: STEP(0x483b34); /* mov r10, qword ptr [rbp - 0x2358] */
READ(a, (UINT64_C(0xffffffffffffdca8) + s->gpr[6]), 8);
s->gpr[10] = a;
++s->steps;
kg_pc_483b3b: STEP(0x483b3b); /* movabs rax, 0x6f79466dab33c920 */
s->gpr[0] = UINT64_C(0x6f79466dab33c920);
++s->steps;
kg_pc_483b45: STEP(0x483b45); /* mov r14, qword ptr [r8 + rax] */
READ(a, (UINT64_C(0x0) + s->gpr[8] + (s->gpr[0] * UINT64_C(0x1))), 8);
s->gpr[14] = a;
++s->steps;
kg_pc_483b49: STEP(0x483b49); /* mov rax, qword ptr [rbp - 0x128] */
READ(a, (UINT64_C(0xfffffffffffffed8) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_483b50: STEP(0x483b50); /* movsxd rbx, dword ptr [rax] */
READ(a, (UINT64_C(0x0) + s->gpr[0]), 4);
s->gpr[1] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483b53: STEP(0x483b53); /* mov rax, qword ptr [rbp - 0x110] */
READ(a, (UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_483b5a: STEP(0x483b5a); /* mov rsi, qword ptr [rax] */
READ(a, (UINT64_C(0x0) + s->gpr[0]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_483b5d: STEP(0x483b5d); /* mov rax, rbx */
s->gpr[0] = s->gpr[1];
++s->steps;
kg_pc_483b60: STEP(0x483b60); /* and rax, 0xffffffffdb1cd9f8 */
x = s->gpr[0]; y = UINT64_C(0xffffffffdb1cd9f8);
s->gpr[0] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_483b66: STEP(0x483b66); /* mov eax, dword ptr [rsi + rax] */
READ(a, (UINT64_C(0x0) + s->gpr[4] + (s->gpr[0] * UINT64_C(0x1))), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_483b69: STEP(0x483b69); /* mov dword ptr [rbp - 0x40], eax */
WRITE((UINT64_C(0xffffffffffffffc0) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483b6c: STEP(0x483b6c); /* and rbx, 0xffffffffa45bf05c */
x = s->gpr[1]; y = UINT64_C(0xffffffffa45bf05c);
s->gpr[1] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_483b73: STEP(0x483b73); /* mov eax, dword ptr [rsi + rbx] */
READ(a, (UINT64_C(0x0) + s->gpr[4] + (s->gpr[1] * UINT64_C(0x1))), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_483b76: STEP(0x483b76); /* mov dword ptr [rbp - 0x90], eax */
WRITE((UINT64_C(0xffffffffffffff70) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483b7c: STEP(0x483b7c); /* movsxd rax, edi */
s->gpr[0] = (((s->gpr[5] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483b7f: STEP(0x483b7f); /* add edi, -2 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffffffffffffffe);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483b82: STEP(0x483b82); /* movsxd rsi, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[4] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483b86: STEP(0x483b86); /* lea rax, [rip - 0x59] */
s->gpr[0] = (UINT64_C(0xffffffffffffffa7) + (bias + UINT64_C(0x483b8d)));
++s->steps;
kg_pc_483b8d: STEP(0x483b8d); /* add rax, rsi */
x = s->gpr[0]; y = s->gpr[4];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483b90: STEP(0x483b90); /* movabs rcx, 0x98356922bcf1635a */
s->gpr[2] = UINT64_C(0x98356922bcf1635a);
++s->steps;
kg_pc_483b9a: STEP(0x483b9a); /* lea r15, [r14 + rcx] */
s->gpr[15] = (UINT64_C(0x0) + s->gpr[14] + (s->gpr[2] * UINT64_C(0x1)));
++s->steps;
kg_pc_483b9e: STEP(0x483b9e); /* xor r8d, r8d */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[8] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483ba1: STEP(0x483ba1); /* mov esi, edi */
s->gpr[4] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483ba3: STEP(0x483ba3); /* mov r9, qword ptr [rbp - 0x1a78] */
READ(a, (UINT64_C(0xffffffffffffe588) + s->gpr[6]), 8);
s->gpr[9] = a;
++s->steps;
kg_pc_483baa: STEP(0x483baa); /* jmp rax */
x = s->gpr[0];
next_pc = x;
++s->steps;

break;
    case 67:
next_pc=bias+UINT64_C(0x483cc0);
switch(s->pc-bias){
case UINT64_C(0x483bb0):goto kg_pc_483bb0;
case UINT64_C(0x483bb4):goto kg_pc_483bb4;
case UINT64_C(0x483bb7):goto kg_pc_483bb7;
case UINT64_C(0x483bbc):goto kg_pc_483bbc;
case UINT64_C(0x483bc2):goto kg_pc_483bc2;
case UINT64_C(0x483bc4):goto kg_pc_483bc4;
case UINT64_C(0x483bc7):goto kg_pc_483bc7;
case UINT64_C(0x483bc9):goto kg_pc_483bc9;
case UINT64_C(0x483bcf):goto kg_pc_483bcf;
case UINT64_C(0x483bd2):goto kg_pc_483bd2;
case UINT64_C(0x483bd6):goto kg_pc_483bd6;
case UINT64_C(0x483bdd):goto kg_pc_483bdd;
case UINT64_C(0x483be1):goto kg_pc_483be1;
case UINT64_C(0x483be3):goto kg_pc_483be3;
case UINT64_C(0x483be7):goto kg_pc_483be7;
case UINT64_C(0x483bee):goto kg_pc_483bee;
case UINT64_C(0x483bf1):goto kg_pc_483bf1;
case UINT64_C(0x483bf8):goto kg_pc_483bf8;
case UINT64_C(0x483bfb):goto kg_pc_483bfb;
case UINT64_C(0x483bfe):goto kg_pc_483bfe;
case UINT64_C(0x483c00):goto kg_pc_483c00;
case UINT64_C(0x483c03):goto kg_pc_483c03;
case UINT64_C(0x483c07):goto kg_pc_483c07;
case UINT64_C(0x483c0d):goto kg_pc_483c0d;
case UINT64_C(0x483c13):goto kg_pc_483c13;
case UINT64_C(0x483c19):goto kg_pc_483c19;
case UINT64_C(0x483c1b):goto kg_pc_483c1b;
case UINT64_C(0x483c1e):goto kg_pc_483c1e;
case UINT64_C(0x483c20):goto kg_pc_483c20;
case UINT64_C(0x483c27):goto kg_pc_483c27;
case UINT64_C(0x483c2a):goto kg_pc_483c2a;
case UINT64_C(0x483c2e):goto kg_pc_483c2e;
case UINT64_C(0x483c35):goto kg_pc_483c35;
case UINT64_C(0x483c39):goto kg_pc_483c39;
case UINT64_C(0x483c3d):goto kg_pc_483c3d;
case UINT64_C(0x483c44):goto kg_pc_483c44;
case UINT64_C(0x483c48):goto kg_pc_483c48;
case UINT64_C(0x483c4b):goto kg_pc_483c4b;
case UINT64_C(0x483c50):goto kg_pc_483c50;
case UINT64_C(0x483c53):goto kg_pc_483c53;
case UINT64_C(0x483c55):goto kg_pc_483c55;
case UINT64_C(0x483c58):goto kg_pc_483c58;
case UINT64_C(0x483c5c):goto kg_pc_483c5c;
case UINT64_C(0x483c5f):goto kg_pc_483c5f;
case UINT64_C(0x483c66):goto kg_pc_483c66;
case UINT64_C(0x483c68):goto kg_pc_483c68;
case UINT64_C(0x483c6e):goto kg_pc_483c6e;
case UINT64_C(0x483c71):goto kg_pc_483c71;
case UINT64_C(0x483c73):goto kg_pc_483c73;
case UINT64_C(0x483c76):goto kg_pc_483c76;
case UINT64_C(0x483c78):goto kg_pc_483c78;
case UINT64_C(0x483c7e):goto kg_pc_483c7e;
case UINT64_C(0x483c80):goto kg_pc_483c80;
case UINT64_C(0x483c86):goto kg_pc_483c86;
case UINT64_C(0x483c89):goto kg_pc_483c89;
case UINT64_C(0x483c8b):goto kg_pc_483c8b;
case UINT64_C(0x483c8d):goto kg_pc_483c8d;
case UINT64_C(0x483c92):goto kg_pc_483c92;
case UINT64_C(0x483c94):goto kg_pc_483c94;
case UINT64_C(0x483c96):goto kg_pc_483c96;
case UINT64_C(0x483c9b):goto kg_pc_483c9b;
case UINT64_C(0x483c9e):goto kg_pc_483c9e;
case UINT64_C(0x483ca1):goto kg_pc_483ca1;
case UINT64_C(0x483ca4):goto kg_pc_483ca4;
case UINT64_C(0x483ca7):goto kg_pc_483ca7;
case UINT64_C(0x483ca9):goto kg_pc_483ca9;
case UINT64_C(0x483cab):goto kg_pc_483cab;
case UINT64_C(0x483cad):goto kg_pc_483cad;
case UINT64_C(0x483cb0):goto kg_pc_483cb0;
case UINT64_C(0x483cb4):goto kg_pc_483cb4;
case UINT64_C(0x483cbb):goto kg_pc_483cbb;
case UINT64_C(0x483cbe):goto kg_pc_483cbe;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5306: [0x483bb0,0x483cc0), 72 instructions. */
kg_pc_483bb0: STEP(0x483bb0); /* lea rax, [r10 + r8] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[10] + (s->gpr[8] * UINT64_C(0x1)));
++s->steps;
kg_pc_483bb4: STEP(0x483bb4); /* xor eax, dword ptr [rbp - 0x40] */
READ(b, (UINT64_C(0xffffffffffffffc0) + s->gpr[6]), 4);
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = b;
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483bb7: STEP(0x483bb7); /* and eax, 0x7fffffff */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x7fffffff);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_483bbc: STEP(0x483bbc); /* imul eax, eax, 0xa57ed9a7 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xa57ed9a7);
s->gpr[0] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_483bc2: STEP(0x483bc2); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483bc4: STEP(0x483bc4); /* shr ecx, 0x10 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[2] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_483bc7: STEP(0x483bc7); /* xor ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483bc9: STEP(0x483bc9); /* imul edx, ecx, 0xa57ed9a7 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xa57ed9a7);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_483bcf: STEP(0x483bcf); /* mov rcx, rdx */
s->gpr[2] = s->gpr[3];
++s->steps;
kg_pc_483bd2: STEP(0x483bd2); /* shr rcx, 0x18 */
x = s->gpr[2]; y = UINT64_C(0x18);
s->gpr[2] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_483bd6: STEP(0x483bd6); /* mov rax, qword ptr [rbp - 0xf20] */
READ(a, (UINT64_C(0xfffffffffffff0e0) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_483bdd: STEP(0x483bdd); /* movzx eax, byte ptr [rax + rcx] */
READ(a, (UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_483be1: STEP(0x483be1); /* mov edi, ecx */
s->gpr[5] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483be3: STEP(0x483be3); /* xor al, byte ptr [r10 + r8] */
READ(b, (UINT64_C(0x0) + s->gpr[10] + (s->gpr[8] * UINT64_C(0x1))), 1);
x = (s->gpr[0] & UINT64_C(0xff)); y = b;
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483be7: STEP(0x483be7); /* mov rbx, qword ptr [rbp - 0xf18] */
READ(a, (UINT64_C(0xfffffffffffff0e8) + s->gpr[6]), 8);
s->gpr[1] = a;
++s->steps;
kg_pc_483bee: STEP(0x483bee); /* xor al, byte ptr [rbx + rcx] */
READ(b, (UINT64_C(0x0) + s->gpr[1] + (s->gpr[2] * UINT64_C(0x1))), 1);
x = (s->gpr[0] & UINT64_C(0xff)); y = b;
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483bf1: STEP(0x483bf1); /* mov rbx, qword ptr [rbp - 0xf10] */
READ(a, (UINT64_C(0xfffffffffffff0f0) + s->gpr[6]), 8);
s->gpr[1] = a;
++s->steps;
kg_pc_483bf8: STEP(0x483bf8); /* xor al, byte ptr [rbx + rcx] */
READ(b, (UINT64_C(0x0) + s->gpr[1] + (s->gpr[2] * UINT64_C(0x1))), 1);
x = (s->gpr[0] & UINT64_C(0xff)); y = b;
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483bfb: STEP(0x483bfb); /* shl ecx, 4 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x4);
s->gpr[2] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_483bfe: STEP(0x483bfe); /* sub edi, ecx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_483c00: STEP(0x483c00); /* xor dil, dl */
x = (s->gpr[5] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483c03: STEP(0x483c03); /* lea ecx, [r14 + r8] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[14] + (s->gpr[8] * UINT64_C(0x1))));
++s->steps;
kg_pc_483c07: STEP(0x483c07); /* xor ecx, dword ptr [rbp - 0x90] */
READ(b, (UINT64_C(0xffffffffffffff70) + s->gpr[6]), 4);
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = b;
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483c0d: STEP(0x483c0d); /* and ecx, 0x7fffffff */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x7fffffff);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_483c13: STEP(0x483c13); /* imul ecx, ecx, 0xa57ed9a7 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xa57ed9a7);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_483c19: STEP(0x483c19); /* mov edx, ecx */
s->gpr[3] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483c1b: STEP(0x483c1b); /* shr edx, 0x10 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_483c1e: STEP(0x483c1e); /* xor edx, ecx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483c20: STEP(0x483c20); /* imul r11d, edx, 0xa57ed9a7 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xa57ed9a7);
s->gpr[11] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_483c27: STEP(0x483c27); /* mov rdx, r11 */
s->gpr[3] = s->gpr[11];
++s->steps;
kg_pc_483c2a: STEP(0x483c2a); /* shr rdx, 0x18 */
x = s->gpr[3]; y = UINT64_C(0x18);
s->gpr[3] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_483c2e: STEP(0x483c2e); /* mov rcx, qword ptr [rbp - 0x1a70] */
READ(a, (UINT64_C(0xffffffffffffe590) + s->gpr[6]), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_483c35: STEP(0x483c35); /* movzx ebx, byte ptr [rcx + rdx] */
READ(a, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x1))), 1);
s->gpr[1] = (uint32_t)(a);
++s->steps;
kg_pc_483c39: STEP(0x483c39); /* xor bl, byte ptr [r15 + r8] */
READ(b, (UINT64_C(0x0) + s->gpr[15] + (s->gpr[8] * UINT64_C(0x1))), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483c3d: STEP(0x483c3d); /* mov rcx, qword ptr [rbp - 0x1a20] */
READ(a, (UINT64_C(0xffffffffffffe5e0) + s->gpr[6]), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_483c44: STEP(0x483c44); /* xor bl, byte ptr [rdx + rcx + 6] */
READ(b, (UINT64_C(0x6) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x1))), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483c48: STEP(0x483c48); /* imul ecx, edx, 0x2f */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x2f);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_483c4b: STEP(0x483c4b); /* xor bl, byte ptr [rdx + r9 + 3] */
READ(b, (UINT64_C(0x3) + s->gpr[3] + (s->gpr[9] * UINT64_C(0x1))), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483c50: STEP(0x483c50); /* shl edx, 6 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x6);
s->gpr[3] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_483c53: STEP(0x483c53); /* add dl, cl */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483c55: STEP(0x483c55); /* xor dil, al */
x = (s->gpr[5] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483c58: STEP(0x483c58); /* movzx eax, dil */
s->gpr[0] = (uint32_t)((s->gpr[5] & UINT64_C(0xff)));
++s->steps;
kg_pc_483c5c: STEP(0x483c5c); /* xor dl, r11b */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[11] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483c5f: STEP(0x483c5f); /* lea r11, [rip - 0x47c916] */
s->gpr[11] = (UINT64_C(0xffffffffffb836ea) + (bias + UINT64_C(0x483c66)));
++s->steps;
kg_pc_483c66: STEP(0x483c66); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483c68: STEP(0x483c68); /* xor ecx, 0xfd2ff7ea */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xfd2ff7ea);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483c6e: STEP(0x483c6e); /* and eax, 0xffffffea */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffea);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_483c71: STEP(0x483c71); /* xor dl, bl */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[1] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483c73: STEP(0x483c73); /* movzx edx, dl */
s->gpr[3] = (uint32_t)((s->gpr[3] & UINT64_C(0xff)));
++s->steps;
kg_pc_483c76: STEP(0x483c76); /* mov edi, edx */
s->gpr[5] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483c78: STEP(0x483c78); /* xor edi, 0x2048c844 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x2048c844);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483c7e: STEP(0x483c7e); /* add edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483c80: STEP(0x483c80); /* and edx, 0x176 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x176);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_483c86: STEP(0x483c86); /* lea eax, [rcx + rax*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_483c89: STEP(0x483c89); /* add eax, edi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483c8b: STEP(0x483c8b); /* sub eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_483c8d: STEP(0x483c8d); /* add eax, 0x3a6c50b3 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x3a6c50b3);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483c92: STEP(0x483c92); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483c94: STEP(0x483c94); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483c96: STEP(0x483c96); /* cmp eax, 0x57e510e1 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x57e510e1);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_483c9b: STEP(0x483c9b); /* setne cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483c9e: STEP(0x483c9e); /* sete dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483ca1: STEP(0x483ca1); /* lea ebx, [rdx + rdx*2] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_483ca4: STEP(0x483ca4); /* lea edi, [rcx + rcx*4] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x4))));
++s->steps;
kg_pc_483ca7: STEP(0x483ca7); /* add edi, esi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483ca9: STEP(0x483ca9); /* add edi, ebx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483cab: STEP(0x483cab); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483cad: STEP(0x483cad); /* movsxd rcx, edx */
s->gpr[2] = (((s->gpr[3] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483cb0: STEP(0x483cb0); /* movsxd rcx, dword ptr [r11 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483cb4: STEP(0x483cb4); /* lea rdx, [rip - 0x10b] */
s->gpr[3] = (UINT64_C(0xfffffffffffffef5) + (bias + UINT64_C(0x483cbb)));
++s->steps;
kg_pc_483cbb: STEP(0x483cbb); /* add rcx, rdx */
x = s->gpr[2]; y = s->gpr[3];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483cbe: STEP(0x483cbe); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 68:
next_pc=bias+UINT64_C(0x483d34);
switch(s->pc-bias){
case UINT64_C(0x483cc3):goto kg_pc_483cc3;
case UINT64_C(0x483cc5):goto kg_pc_483cc5;
case UINT64_C(0x483cc8):goto kg_pc_483cc8;
case UINT64_C(0x483ccb):goto kg_pc_483ccb;
case UINT64_C(0x483cd5):goto kg_pc_483cd5;
case UINT64_C(0x483cd9):goto kg_pc_483cd9;
case UINT64_C(0x483ce0):goto kg_pc_483ce0;
case UINT64_C(0x483ce3):goto kg_pc_483ce3;
case UINT64_C(0x483ce6):goto kg_pc_483ce6;
case UINT64_C(0x483ce8):goto kg_pc_483ce8;
case UINT64_C(0x483ceb):goto kg_pc_483ceb;
case UINT64_C(0x483cee):goto kg_pc_483cee;
case UINT64_C(0x483cf2):goto kg_pc_483cf2;
case UINT64_C(0x483cf4):goto kg_pc_483cf4;
case UINT64_C(0x483cf8):goto kg_pc_483cf8;
case UINT64_C(0x483cfc):goto kg_pc_483cfc;
case UINT64_C(0x483d03):goto kg_pc_483d03;
case UINT64_C(0x483d05):goto kg_pc_483d05;
case UINT64_C(0x483d08):goto kg_pc_483d08;
case UINT64_C(0x483d0b):goto kg_pc_483d0b;
case UINT64_C(0x483d0e):goto kg_pc_483d0e;
case UINT64_C(0x483d10):goto kg_pc_483d10;
case UINT64_C(0x483d12):goto kg_pc_483d12;
case UINT64_C(0x483d14):goto kg_pc_483d14;
case UINT64_C(0x483d16):goto kg_pc_483d16;
case UINT64_C(0x483d19):goto kg_pc_483d19;
case UINT64_C(0x483d1d):goto kg_pc_483d1d;
case UINT64_C(0x483d24):goto kg_pc_483d24;
case UINT64_C(0x483d27):goto kg_pc_483d27;
case UINT64_C(0x483d2b):goto kg_pc_483d2b;
case UINT64_C(0x483d30):goto kg_pc_483d30;
case UINT64_C(0x483d32):goto kg_pc_483d32;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5307: [0x483cc3,0x483d34), 32 instructions. */
kg_pc_483cc3: STEP(0x483cc3); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483cc5: STEP(0x483cc5); /* cmp r12, r13 */
x = s->gpr[12]; y = s->gpr[13];
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_483cc8: STEP(0x483cc8); /* setb al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483ccb: STEP(0x483ccb); /* movabs rcx, 0x100000000 */
s->gpr[2] = UINT64_C(0x100000000);
++s->steps;
kg_pc_483cd5: STEP(0x483cd5); /* lea rsi, [rcx + r8] */
s->gpr[4] = (UINT64_C(0x0) + s->gpr[2] + (s->gpr[8] * UINT64_C(0x1)));
++s->steps;
kg_pc_483cd9: STEP(0x483cd9); /* add rsi, -0x6759336a */
x = s->gpr[4]; y = UINT64_C(0xffffffff98a6cc96);
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483ce0: STEP(0x483ce0); /* cmp rsi, r13 */
x = s->gpr[4]; y = s->gpr[13];
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_483ce3: STEP(0x483ce3); /* setb cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483ce6: STEP(0x483ce6); /* xor cl, al */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483ce8: STEP(0x483ce8); /* xor r11d, r11d */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = (s->gpr[11] & UINT64_C(0xffffffff));
s->gpr[11] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483ceb: STEP(0x483ceb); /* cmp rsi, r12 */
x = s->gpr[4]; y = s->gpr[12];
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_483cee: STEP(0x483cee); /* setb r11b */
s->gpr[11] = (s->gpr[11] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483cf2: STEP(0x483cf2); /* test cl, cl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
(void)operation(s, OP_AND, x, y, 8);
++s->steps;
kg_pc_483cf4: STEP(0x483cf4); /* cmovne r11d, eax */
s->gpr[11] = (uint32_t)((condition(s, COND_NE) ? (s->gpr[0] & UINT64_C(0xffffffff)) : (s->gpr[11] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_483cf8: STEP(0x483cf8); /* movzx eax, r11b */
s->gpr[0] = (uint32_t)((s->gpr[11] & UINT64_C(0xff)));
++s->steps;
kg_pc_483cfc: STEP(0x483cfc); /* lea r11, [rip - 0x47c9b3] */
s->gpr[11] = (UINT64_C(0xffffffffffb8364d) + (bias + UINT64_C(0x483d03)));
++s->steps;
kg_pc_483d03: STEP(0x483d03); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483d05: STEP(0x483d05); /* xor cl, 1 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x1);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483d08: STEP(0x483d08); /* movzx esi, cl */
s->gpr[4] = (uint32_t)((s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_483d0b: STEP(0x483d0b); /* lea ecx, [rax + rax*2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_483d0e: STEP(0x483d0e); /* add esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483d10: STEP(0x483d10); /* sub esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_483d12: STEP(0x483d12); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483d14: STEP(0x483d14); /* add edi, eax */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483d16: STEP(0x483d16); /* movsxd rax, edi */
s->gpr[0] = (((s->gpr[5] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483d19: STEP(0x483d19); /* movsxd rcx, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483d1d: STEP(0x483d1d); /* lea rax, [rip - 0x61] */
s->gpr[0] = (UINT64_C(0xffffffffffffff9f) + (bias + UINT64_C(0x483d24)));
++s->steps;
kg_pc_483d24: STEP(0x483d24); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483d27: STEP(0x483d27); /* add r8, 1 */
x = s->gpr[8]; y = UINT64_C(0x1);
s->gpr[8] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483d2b: STEP(0x483d2b); /* mov eax, 0x57e510e1 */
s->gpr[0] = (uint32_t)(UINT64_C(0x57e510e1));
++s->steps;
kg_pc_483d30: STEP(0x483d30); /* mov edi, esi */
s->gpr[5] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483d32: STEP(0x483d32); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 69:
next_pc=bias+UINT64_C(0x483d4b);
switch(s->pc-bias){
case UINT64_C(0x483d35):goto kg_pc_483d35;
case UINT64_C(0x483d38):goto kg_pc_483d38;
case UINT64_C(0x483d3b):goto kg_pc_483d3b;
case UINT64_C(0x483d3f):goto kg_pc_483d3f;
case UINT64_C(0x483d46):goto kg_pc_483d46;
case UINT64_C(0x483d49):goto kg_pc_483d49;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5308: [0x483d35,0x483d4b), 6 instructions. */
kg_pc_483d35: STEP(0x483d35); /* movsxd rcx, edi */
s->gpr[2] = (((s->gpr[5] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483d38: STEP(0x483d38); /* add edi, 1 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x1);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483d3b: STEP(0x483d3b); /* movsxd rcx, dword ptr [r11 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483d3f: STEP(0x483d3f); /* lea rdx, [rip - 0x11] */
s->gpr[3] = (UINT64_C(0xffffffffffffffef) + (bias + UINT64_C(0x483d46)));
++s->steps;
kg_pc_483d46: STEP(0x483d46); /* add rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483d49: STEP(0x483d49); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 70:
next_pc=bias+UINT64_C(0x483d7a);
switch(s->pc-bias){
case UINT64_C(0x483d4d):goto kg_pc_483d4d;
case UINT64_C(0x483d53):goto kg_pc_483d53;
case UINT64_C(0x483d58):goto kg_pc_483d58;
case UINT64_C(0x483d5d):goto kg_pc_483d5d;
case UINT64_C(0x483d62):goto kg_pc_483d62;
case UINT64_C(0x483d65):goto kg_pc_483d65;
case UINT64_C(0x483d68):goto kg_pc_483d68;
case UINT64_C(0x483d6a):goto kg_pc_483d6a;
case UINT64_C(0x483d6e):goto kg_pc_483d6e;
case UINT64_C(0x483d75):goto kg_pc_483d75;
case UINT64_C(0x483d78):goto kg_pc_483d78;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5309: [0x483d4d,0x483d7a), 11 instructions. */
kg_pc_483d4d: STEP(0x483d4d); /* lea ebx, [rdi - 0x203f] */
s->gpr[1] = (uint32_t)((UINT64_C(0xffffffffffffdfc1) + s->gpr[5]));
++s->steps;
kg_pc_483d53: STEP(0x483d53); /* cmp eax, 0x57e510e1 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x57e510e1);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_483d58: STEP(0x483d58); /* mov eax, 0xe982a16 */
s->gpr[0] = (uint32_t)(UINT64_C(0xe982a16));
++s->steps;
kg_pc_483d5d: STEP(0x483d5d); /* mov ecx, 0xe97836a */
s->gpr[2] = (uint32_t)(UINT64_C(0xe97836a));
++s->steps;
kg_pc_483d62: STEP(0x483d62); /* cmove ecx, eax */
s->gpr[2] = (uint32_t)((condition(s, COND_E) ? (s->gpr[0] & UINT64_C(0xffffffff)) : (s->gpr[2] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_483d65: STEP(0x483d65); /* movsxd rax, edi */
s->gpr[0] = (((s->gpr[5] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483d68: STEP(0x483d68); /* mov edi, ecx */
s->gpr[5] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483d6a: STEP(0x483d6a); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483d6e: STEP(0x483d6e); /* lea rcx, [rip - 0x28] */
s->gpr[2] = (UINT64_C(0xffffffffffffffd8) + (bias + UINT64_C(0x483d75)));
++s->steps;
kg_pc_483d75: STEP(0x483d75); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483d78: STEP(0x483d78); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 71:
next_pc=bias+UINT64_C(0x483db7);
switch(s->pc-bias){
case UINT64_C(0x483d7d):goto kg_pc_483d7d;
case UINT64_C(0x483d84):goto kg_pc_483d84;
case UINT64_C(0x483d86):goto kg_pc_483d86;
case UINT64_C(0x483d88):goto kg_pc_483d88;
case UINT64_C(0x483d8b):goto kg_pc_483d8b;
case UINT64_C(0x483d8e):goto kg_pc_483d8e;
case UINT64_C(0x483d91):goto kg_pc_483d91;
case UINT64_C(0x483d94):goto kg_pc_483d94;
case UINT64_C(0x483d98):goto kg_pc_483d98;
case UINT64_C(0x483d9b):goto kg_pc_483d9b;
case UINT64_C(0x483d9d):goto kg_pc_483d9d;
case UINT64_C(0x483da0):goto kg_pc_483da0;
case UINT64_C(0x483da4):goto kg_pc_483da4;
case UINT64_C(0x483dab):goto kg_pc_483dab;
case UINT64_C(0x483dae):goto kg_pc_483dae;
case UINT64_C(0x483db5):goto kg_pc_483db5;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5310: [0x483d7d,0x483db7), 16 instructions. */
kg_pc_483d7d: STEP(0x483d7d); /* mov rax, qword ptr [rbp - 0x2358] */
READ(a, (UINT64_C(0xffffffffffffdca8) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_483d84: STEP(0x483d84); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483d86: STEP(0x483d86); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483d88: STEP(0x483d88); /* test rax, rax */
x = s->gpr[0]; y = s->gpr[0];
(void)operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_483d8b: STEP(0x483d8b); /* setne cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483d8e: STEP(0x483d8e); /* sete dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_483d91: STEP(0x483d91); /* lea esi, [rdx + rdx*2] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_483d94: STEP(0x483d94); /* lea r15d, [rbx + rcx*4] */
s->gpr[15] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[2] * UINT64_C(0x4))));
++s->steps;
kg_pc_483d98: STEP(0x483d98); /* sub r15d, esi */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[15] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_483d9b: STEP(0x483d9b); /* add edx, ebx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483d9d: STEP(0x483d9d); /* movsxd rcx, edx */
s->gpr[2] = (((s->gpr[3] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483da0: STEP(0x483da0); /* movsxd rcx, dword ptr [r11 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483da4: STEP(0x483da4); /* lea rdx, [rip - 0x2e] */
s->gpr[3] = (UINT64_C(0xffffffffffffffd2) + (bias + UINT64_C(0x483dab)));
++s->steps;
kg_pc_483dab: STEP(0x483dab); /* add rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483dae: STEP(0x483dae); /* mov r12, qword ptr [rbp - 0x110] */
READ(a, (UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_483db5: STEP(0x483db5); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 72:
next_pc=bias+UINT64_C(0x483e14);
switch(s->pc-bias){
case UINT64_C(0x483db9):goto kg_pc_483db9;
case UINT64_C(0x483dbd):goto kg_pc_483dbd;
case UINT64_C(0x483dc4):goto kg_pc_483dc4;
case UINT64_C(0x483dc6):goto kg_pc_483dc6;
case UINT64_C(0x483dcd):goto kg_pc_483dcd;
case UINT64_C(0x483dcf):goto kg_pc_483dcf;
case UINT64_C(0x483dd9):goto kg_pc_483dd9;
case UINT64_C(0x483ddb):goto kg_pc_483ddb;
case UINT64_C(0x483de1):goto kg_pc_483de1;
case UINT64_C(0x483de8):goto kg_pc_483de8;
case UINT64_C(0x483dea):goto kg_pc_483dea;
case UINT64_C(0x483df0):goto kg_pc_483df0;
case UINT64_C(0x483df7):goto kg_pc_483df7;
case UINT64_C(0x483dfe):goto kg_pc_483dfe;
case UINT64_C(0x483e00):goto kg_pc_483e00;
case UINT64_C(0x483e02):goto kg_pc_483e02;
case UINT64_C(0x483e08):goto kg_pc_483e08;
case UINT64_C(0x483e0e):goto kg_pc_483e0e;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5311: [0x483db9,0x483e14), 18 instructions. */
kg_pc_483db9: STEP(0x483db9); /* lea r14d, [r15 - 7] */
s->gpr[14] = (uint32_t)((UINT64_C(0xfffffffffffffff9) + s->gpr[15]));
++s->steps;
kg_pc_483dbd: STEP(0x483dbd); /* lea ecx, [r15 - 0x19b] */
s->gpr[2] = (uint32_t)((UINT64_C(0xfffffffffffffe65) + s->gpr[15]));
++s->steps;
kg_pc_483dc4: STEP(0x483dc4); /* mov ebx, edi */
s->gpr[1] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483dc6: STEP(0x483dc6); /* lea rdi, [rbp - 0x1f8] */
s->gpr[5] = (UINT64_C(0xfffffffffffffe08) + s->gpr[6]);
++s->steps;
kg_pc_483dcd: STEP(0x483dcd); /* mov edx, edi */
s->gpr[3] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483dcf: STEP(0x483dcf); /* movabs rsi, 0xd7cf669026532472 */
s->gpr[4] = UINT64_C(0xd7cf669026532472);
++s->steps;
kg_pc_483dd9: STEP(0x483dd9); /* xor edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483ddb: STEP(0x483ddb); /* imul edx, edx, 0x20bd8b7f */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x20bd8b7f);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_483de1: STEP(0x483de1); /* mov qword ptr [rbp - 0x1f0], rax */
WRITE((UINT64_C(0xfffffffffffffe10) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_483de8: STEP(0x483de8); /* xor ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483dea: STEP(0x483dea); /* mov dword ptr [rbp - 0x1e8], ecx */
WRITE((UINT64_C(0xfffffffffffffe18) + s->gpr[6]), 4, (s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483df0: STEP(0x483df0); /* lea rax, [rip - 0x2e33ec] */
s->gpr[0] = (UINT64_C(0xffffffffffd1cc14) + (bias + UINT64_C(0x483df7)));
++s->steps;
kg_pc_483df7: STEP(0x483df7); /* lea rcx, [rip - 0x2e335f] */
s->gpr[2] = (UINT64_C(0xffffffffffd1cca1) + (bias + UINT64_C(0x483dfe)));
++s->steps;
kg_pc_483dfe: STEP(0x483dfe); /* sub ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_483e00: STEP(0x483e00); /* sub ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_483e02: STEP(0x483e02); /* add ecx, 0x8fc */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x8fc);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483e08: STEP(0x483e08); /* mov dword ptr [rbp - 0x1f8], ecx */
WRITE((UINT64_C(0xfffffffffffffe08) + s->gpr[6]), 4, (s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483e0e: STEP(0x483e0e); /* call qword ptr [rbp - 0x458] */
READ(a, (UINT64_C(0xfffffffffffffba8) + s->gpr[6]), 8);
x = a;
y = s->gpr[7] - 8;
WRITE(y, 8, bias + UINT64_C(0x483e14));
s->gpr[7] = y;
next_pc = x;
++s->steps;

break;
    case 73:
next_pc=bias+UINT64_C(0x483e33);
switch(s->pc-bias){
case UINT64_C(0x483e14):goto kg_pc_483e14;
case UINT64_C(0x483e16):goto kg_pc_483e16;
case UINT64_C(0x483e1d):goto kg_pc_483e1d;
case UINT64_C(0x483e20):goto kg_pc_483e20;
case UINT64_C(0x483e24):goto kg_pc_483e24;
case UINT64_C(0x483e2b):goto kg_pc_483e2b;
case UINT64_C(0x483e2e):goto kg_pc_483e2e;
case UINT64_C(0x483e31):goto kg_pc_483e31;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5312: [0x483e14,0x483e33), 8 instructions. */
kg_pc_483e14: STEP(0x483e14); /* mov edi, ebx */
s->gpr[5] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483e16: STEP(0x483e16); /* lea r11, [rip - 0x47cacd] */
s->gpr[11] = (UINT64_C(0xffffffffffb83533) + (bias + UINT64_C(0x483e1d)));
++s->steps;
kg_pc_483e1d: STEP(0x483e1d); /* movsxd rax, r15d */
s->gpr[0] = (((s->gpr[15] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483e20: STEP(0x483e20); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483e24: STEP(0x483e24); /* lea rcx, [rip - 0x72] */
s->gpr[2] = (UINT64_C(0xffffffffffffff8e) + (bias + UINT64_C(0x483e2b)));
++s->steps;
kg_pc_483e2b: STEP(0x483e2b); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483e2e: STEP(0x483e2e); /* mov r15d, r14d */
s->gpr[15] = (uint32_t)((s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483e31: STEP(0x483e31); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 74:
next_pc=bias+UINT64_C(0x483e87);
switch(s->pc-bias){
case UINT64_C(0x483e35):goto kg_pc_483e35;
case UINT64_C(0x483e39):goto kg_pc_483e39;
case UINT64_C(0x483e41):goto kg_pc_483e41;
case UINT64_C(0x483e47):goto kg_pc_483e47;
case UINT64_C(0x483e49):goto kg_pc_483e49;
case UINT64_C(0x483e4c):goto kg_pc_483e4c;
case UINT64_C(0x483e52):goto kg_pc_483e52;
case UINT64_C(0x483e57):goto kg_pc_483e57;
case UINT64_C(0x483e59):goto kg_pc_483e59;
case UINT64_C(0x483e5f):goto kg_pc_483e5f;
case UINT64_C(0x483e61):goto kg_pc_483e61;
case UINT64_C(0x483e63):goto kg_pc_483e63;
case UINT64_C(0x483e69):goto kg_pc_483e69;
case UINT64_C(0x483e6d):goto kg_pc_483e6d;
case UINT64_C(0x483e74):goto kg_pc_483e74;
case UINT64_C(0x483e77):goto kg_pc_483e77;
case UINT64_C(0x483e7b):goto kg_pc_483e7b;
case UINT64_C(0x483e82):goto kg_pc_483e82;
case UINT64_C(0x483e85):goto kg_pc_483e85;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5313: [0x483e35,0x483e87), 19 instructions. */
kg_pc_483e35: STEP(0x483e35); /* lea r14d, [r15 + 5] */
s->gpr[14] = (uint32_t)((UINT64_C(0x5) + s->gpr[15]));
++s->steps;
kg_pc_483e39: STEP(0x483e39); /* add qword ptr [rbp - 0x2c8], -0x10 */
READ(a, (UINT64_C(0xfffffffffffffd38) + s->gpr[6]), 8);
x = a; y = UINT64_C(0xfffffffffffffff0);
WRITE((UINT64_C(0xfffffffffffffd38) + s->gpr[6]), 8, operation(s, OP_ADD, x, y, 64));
++s->steps;
kg_pc_483e41: STEP(0x483e41); /* mov eax, dword ptr [rbp - 0x924] */
READ(a, (UINT64_C(0xfffffffffffff6dc) + s->gpr[6]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_483e47: STEP(0x483e47); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483e49: STEP(0x483e49); /* or ecx, 4 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x4);
s->gpr[2] = (uint32_t)(operation(s, OP_OR, x, y, 32));
++s->steps;
kg_pc_483e4c: STEP(0x483e4c); /* xor ecx, 0x47675ddb */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x47675ddb);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483e52: STEP(0x483e52); /* or eax, 0x77e7ddff */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x77e7ddff);
s->gpr[0] = (uint32_t)(operation(s, OP_OR, x, y, 32));
++s->steps;
kg_pc_483e57: STEP(0x483e57); /* mov edx, ecx */
s->gpr[3] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483e59: STEP(0x483e59); /* and edx, 0x4f7f7fdb */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x4f7f7fdb);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_483e5f: STEP(0x483e5f); /* xor edx, eax */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483e61: STEP(0x483e61); /* add edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483e63: STEP(0x483e63); /* xor edx, 0x10304409 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x10304409);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_483e69: STEP(0x483e69); /* lea r8d, [rcx + rdx] */
s->gpr[8] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_483e6d: STEP(0x483e6d); /* add r8d, 0x47675de0 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x47675de0);
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483e74: STEP(0x483e74); /* movsxd rax, r15d */
s->gpr[0] = (((s->gpr[15] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483e77: STEP(0x483e77); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483e7b: STEP(0x483e7b); /* lea rcx, [rip - 0x4d] */
s->gpr[2] = (UINT64_C(0xffffffffffffffb3) + (bias + UINT64_C(0x483e82)));
++s->steps;
kg_pc_483e82: STEP(0x483e82); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483e85: STEP(0x483e85); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 75:
next_pc=bias+UINT64_C(0x483eb5);
switch(s->pc-bias){
case UINT64_C(0x483e8a):goto kg_pc_483e8a;
case UINT64_C(0x483e8d):goto kg_pc_483e8d;
case UINT64_C(0x483e94):goto kg_pc_483e94;
case UINT64_C(0x483e97):goto kg_pc_483e97;
case UINT64_C(0x483e9e):goto kg_pc_483e9e;
case UINT64_C(0x483ea2):goto kg_pc_483ea2;
case UINT64_C(0x483ea9):goto kg_pc_483ea9;
case UINT64_C(0x483eac):goto kg_pc_483eac;
case UINT64_C(0x483eb3):goto kg_pc_483eb3;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5314: [0x483e8a,0x483eb5), 9 instructions. */
kg_pc_483e8a: STEP(0x483e8a); /* mov r10d, edi */
s->gpr[10] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_483e8d: STEP(0x483e8d); /* mov r9d, dword ptr [rbp - 0x7e4] */
READ(a, (UINT64_C(0xfffffffffffff81c) + s->gpr[6]), 4);
s->gpr[9] = (uint32_t)(a);
++s->steps;
kg_pc_483e94: STEP(0x483e94); /* movsxd rax, r14d */
s->gpr[0] = (((s->gpr[14] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483e97: STEP(0x483e97); /* add r14d, 0xffffff6f */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffff6f);
s->gpr[14] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_483e9e: STEP(0x483e9e); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_483ea2: STEP(0x483ea2); /* lea rcx, [rip - 0x1f] */
s->gpr[2] = (UINT64_C(0xffffffffffffffe1) + (bias + UINT64_C(0x483ea9)));
++s->steps;
kg_pc_483ea9: STEP(0x483ea9); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_483eac: STEP(0x483eac); /* mov rbx, qword ptr [rbp - 0x128] */
READ(a, (UINT64_C(0xfffffffffffffed8) + s->gpr[6]), 8);
s->gpr[1] = a;
++s->steps;
kg_pc_483eb3: STEP(0x483eb3); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 76:
next_pc=bias+UINT64_C(0x48410d);
switch(s->pc-bias){
case UINT64_C(0x4840d4):goto kg_pc_4840d4;
case UINT64_C(0x4840db):goto kg_pc_4840db;
case UINT64_C(0x4840e2):goto kg_pc_4840e2;
case UINT64_C(0x4840e9):goto kg_pc_4840e9;
case UINT64_C(0x4840ed):goto kg_pc_4840ed;
case UINT64_C(0x4840ef):goto kg_pc_4840ef;
case UINT64_C(0x4840f6):goto kg_pc_4840f6;
case UINT64_C(0x4840fa):goto kg_pc_4840fa;
case UINT64_C(0x484101):goto kg_pc_484101;
case UINT64_C(0x484104):goto kg_pc_484104;
case UINT64_C(0x48410b):goto kg_pc_48410b;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5315: [0x4840d4,0x48410d), 11 instructions. */
kg_pc_4840d4: STEP(0x4840d4); /* lea edi, [r15 + 0x21de] */
s->gpr[5] = (uint32_t)((UINT64_C(0x21de) + s->gpr[15]));
++s->steps;
kg_pc_4840db: STEP(0x4840db); /* lea eax, [r15 + 0x21da] */
s->gpr[0] = (uint32_t)((UINT64_C(0x21da) + s->gpr[15]));
++s->steps;
kg_pc_4840e2: STEP(0x4840e2); /* mov r9d, dword ptr [rbp - 0x7e4] */
READ(a, (UINT64_C(0xfffffffffffff81c) + s->gpr[6]), 4);
s->gpr[9] = (uint32_t)(a);
++s->steps;
kg_pc_4840e9: STEP(0x4840e9); /* add r9d, 1 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x1);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4840ed: STEP(0x4840ed); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_4840ef: STEP(0x4840ef); /* lea r11, [rip - 0x47cda6] */
s->gpr[11] = (UINT64_C(0xffffffffffb8325a) + (bias + UINT64_C(0x4840f6)));
++s->steps;
kg_pc_4840f6: STEP(0x4840f6); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4840fa: STEP(0x4840fa); /* lea rcx, [rip - 0x2d] */
s->gpr[2] = (UINT64_C(0xffffffffffffffd3) + (bias + UINT64_C(0x484101)));
++s->steps;
kg_pc_484101: STEP(0x484101); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_484104: STEP(0x484104); /* mov r12, qword ptr [rbp - 0x110] */
READ(a, (UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_48410b: STEP(0x48410b); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 77:
next_pc=bias+UINT64_C(0x484183);
switch(s->pc-bias){
case UINT64_C(0x48414a):goto kg_pc_48414a;
case UINT64_C(0x484151):goto kg_pc_484151;
case UINT64_C(0x484158):goto kg_pc_484158;
case UINT64_C(0x48415f):goto kg_pc_48415f;
case UINT64_C(0x484163):goto kg_pc_484163;
case UINT64_C(0x484165):goto kg_pc_484165;
case UINT64_C(0x48416c):goto kg_pc_48416c;
case UINT64_C(0x484170):goto kg_pc_484170;
case UINT64_C(0x484177):goto kg_pc_484177;
case UINT64_C(0x48417a):goto kg_pc_48417a;
case UINT64_C(0x484181):goto kg_pc_484181;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5316: [0x48414a,0x484183), 11 instructions. */
kg_pc_48414a: STEP(0x48414a); /* lea edi, [r15 + 0x1fef] */
s->gpr[5] = (uint32_t)((UINT64_C(0x1fef) + s->gpr[15]));
++s->steps;
kg_pc_484151: STEP(0x484151); /* lea eax, [r15 + 0x21df] */
s->gpr[0] = (uint32_t)((UINT64_C(0x21df) + s->gpr[15]));
++s->steps;
kg_pc_484158: STEP(0x484158); /* mov r9d, dword ptr [rbp - 0x7e4] */
READ(a, (UINT64_C(0xfffffffffffff81c) + s->gpr[6]), 4);
s->gpr[9] = (uint32_t)(a);
++s->steps;
kg_pc_48415f: STEP(0x48415f); /* add r9d, 1 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x1);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_484163: STEP(0x484163); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_484165: STEP(0x484165); /* lea r11, [rip - 0x47ce1c] */
s->gpr[11] = (UINT64_C(0xffffffffffb831e4) + (bias + UINT64_C(0x48416c)));
++s->steps;
kg_pc_48416c: STEP(0x48416c); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484170: STEP(0x484170); /* lea rcx, [rip - 0x2d] */
s->gpr[2] = (UINT64_C(0xffffffffffffffd3) + (bias + UINT64_C(0x484177)));
++s->steps;
kg_pc_484177: STEP(0x484177); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_48417a: STEP(0x48417a); /* mov r12, qword ptr [rbp - 0x110] */
READ(a, (UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_484181: STEP(0x484181); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 78:
next_pc=bias+UINT64_C(0x4841be);
switch(s->pc-bias){
case UINT64_C(0x484185):goto kg_pc_484185;
case UINT64_C(0x48418c):goto kg_pc_48418c;
case UINT64_C(0x484193):goto kg_pc_484193;
case UINT64_C(0x48419a):goto kg_pc_48419a;
case UINT64_C(0x48419e):goto kg_pc_48419e;
case UINT64_C(0x4841a0):goto kg_pc_4841a0;
case UINT64_C(0x4841a7):goto kg_pc_4841a7;
case UINT64_C(0x4841ab):goto kg_pc_4841ab;
case UINT64_C(0x4841b2):goto kg_pc_4841b2;
case UINT64_C(0x4841b5):goto kg_pc_4841b5;
case UINT64_C(0x4841bc):goto kg_pc_4841bc;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5317: [0x484185,0x4841be), 11 instructions. */
kg_pc_484185: STEP(0x484185); /* lea edi, [r15 + 0x2057] */
s->gpr[5] = (uint32_t)((UINT64_C(0x2057) + s->gpr[15]));
++s->steps;
kg_pc_48418c: STEP(0x48418c); /* lea eax, [r15 + 0x21d8] */
s->gpr[0] = (uint32_t)((UINT64_C(0x21d8) + s->gpr[15]));
++s->steps;
kg_pc_484193: STEP(0x484193); /* mov r9d, dword ptr [rbp - 0x7e4] */
READ(a, (UINT64_C(0xfffffffffffff81c) + s->gpr[6]), 4);
s->gpr[9] = (uint32_t)(a);
++s->steps;
kg_pc_48419a: STEP(0x48419a); /* add r9d, 1 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x1);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48419e: STEP(0x48419e); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_4841a0: STEP(0x4841a0); /* lea r11, [rip - 0x47ce57] */
s->gpr[11] = (UINT64_C(0xffffffffffb831a9) + (bias + UINT64_C(0x4841a7)));
++s->steps;
kg_pc_4841a7: STEP(0x4841a7); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4841ab: STEP(0x4841ab); /* lea rcx, [rip - 0x2d] */
s->gpr[2] = (UINT64_C(0xffffffffffffffd3) + (bias + UINT64_C(0x4841b2)));
++s->steps;
kg_pc_4841b2: STEP(0x4841b2); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4841b5: STEP(0x4841b5); /* mov r12, qword ptr [rbp - 0x110] */
READ(a, (UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_4841bc: STEP(0x4841bc); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 79:
next_pc=bias+UINT64_C(0x4841fa);
switch(s->pc-bias){
case UINT64_C(0x4841c1):goto kg_pc_4841c1;
case UINT64_C(0x4841c8):goto kg_pc_4841c8;
case UINT64_C(0x4841cf):goto kg_pc_4841cf;
case UINT64_C(0x4841d6):goto kg_pc_4841d6;
case UINT64_C(0x4841da):goto kg_pc_4841da;
case UINT64_C(0x4841dc):goto kg_pc_4841dc;
case UINT64_C(0x4841e3):goto kg_pc_4841e3;
case UINT64_C(0x4841e7):goto kg_pc_4841e7;
case UINT64_C(0x4841ee):goto kg_pc_4841ee;
case UINT64_C(0x4841f1):goto kg_pc_4841f1;
case UINT64_C(0x4841f8):goto kg_pc_4841f8;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5318: [0x4841c1,0x4841fa), 11 instructions. */
kg_pc_4841c1: STEP(0x4841c1); /* lea edi, [r15 + 0x1fe2] */
s->gpr[5] = (uint32_t)((UINT64_C(0x1fe2) + s->gpr[15]));
++s->steps;
kg_pc_4841c8: STEP(0x4841c8); /* lea eax, [r15 + 0x21d5] */
s->gpr[0] = (uint32_t)((UINT64_C(0x21d5) + s->gpr[15]));
++s->steps;
kg_pc_4841cf: STEP(0x4841cf); /* mov r9d, dword ptr [rbp - 0x7e4] */
READ(a, (UINT64_C(0xfffffffffffff81c) + s->gpr[6]), 4);
s->gpr[9] = (uint32_t)(a);
++s->steps;
kg_pc_4841d6: STEP(0x4841d6); /* add r9d, 1 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x1);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4841da: STEP(0x4841da); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_4841dc: STEP(0x4841dc); /* lea r11, [rip - 0x47ce93] */
s->gpr[11] = (UINT64_C(0xffffffffffb8316d) + (bias + UINT64_C(0x4841e3)));
++s->steps;
kg_pc_4841e3: STEP(0x4841e3); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4841e7: STEP(0x4841e7); /* lea rcx, [rip - 0x2d] */
s->gpr[2] = (UINT64_C(0xffffffffffffffd3) + (bias + UINT64_C(0x4841ee)));
++s->steps;
kg_pc_4841ee: STEP(0x4841ee); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4841f1: STEP(0x4841f1); /* mov r12, qword ptr [rbp - 0x110] */
READ(a, (UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_4841f8: STEP(0x4841f8); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 80:
next_pc=bias+UINT64_C(0x484280);
switch(s->pc-bias){
case UINT64_C(0x484236):goto kg_pc_484236;
case UINT64_C(0x48423d):goto kg_pc_48423d;
case UINT64_C(0x484244):goto kg_pc_484244;
case UINT64_C(0x48424b):goto kg_pc_48424b;
case UINT64_C(0x484252):goto kg_pc_484252;
case UINT64_C(0x484259):goto kg_pc_484259;
case UINT64_C(0x48425b):goto kg_pc_48425b;
case UINT64_C(0x484262):goto kg_pc_484262;
case UINT64_C(0x484266):goto kg_pc_484266;
case UINT64_C(0x48426d):goto kg_pc_48426d;
case UINT64_C(0x484270):goto kg_pc_484270;
case UINT64_C(0x484277):goto kg_pc_484277;
case UINT64_C(0x48427e):goto kg_pc_48427e;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5319: [0x484236,0x484280), 13 instructions. */
kg_pc_484236: STEP(0x484236); /* lea r14d, [r15 + 0x101] */
s->gpr[14] = (uint32_t)((UINT64_C(0x101) + s->gpr[15]));
++s->steps;
kg_pc_48423d: STEP(0x48423d); /* lea eax, [r15 + 0x21d1] */
s->gpr[0] = (uint32_t)((UINT64_C(0x21d1) + s->gpr[15]));
++s->steps;
kg_pc_484244: STEP(0x484244); /* mov r9d, dword ptr [rbp - 0x7e4] */
READ(a, (UINT64_C(0xfffffffffffff81c) + s->gpr[6]), 4);
s->gpr[9] = (uint32_t)(a);
++s->steps;
kg_pc_48424b: STEP(0x48424b); /* mov r8d, dword ptr [rbp - 0x924] */
READ(a, (UINT64_C(0xfffffffffffff6dc) + s->gpr[6]), 4);
s->gpr[8] = (uint32_t)(a);
++s->steps;
kg_pc_484252: STEP(0x484252); /* mov r10d, dword ptr [rbp - 0xe3c] */
READ(a, (UINT64_C(0xfffffffffffff1c4) + s->gpr[6]), 4);
s->gpr[10] = (uint32_t)(a);
++s->steps;
kg_pc_484259: STEP(0x484259); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_48425b: STEP(0x48425b); /* lea r11, [rip - 0x47cf12] */
s->gpr[11] = (UINT64_C(0xffffffffffb830ee) + (bias + UINT64_C(0x484262)));
++s->steps;
kg_pc_484262: STEP(0x484262); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484266: STEP(0x484266); /* lea rdx, [rip - 0x37] */
s->gpr[3] = (UINT64_C(0xffffffffffffffc9) + (bias + UINT64_C(0x48426d)));
++s->steps;
kg_pc_48426d: STEP(0x48426d); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_484270: STEP(0x484270); /* mov r12, qword ptr [rbp - 0x110] */
READ(a, (UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_484277: STEP(0x484277); /* mov rbx, qword ptr [rbp - 0x128] */
READ(a, (UINT64_C(0xfffffffffffffed8) + s->gpr[6]), 8);
s->gpr[1] = a;
++s->steps;
kg_pc_48427e: STEP(0x48427e); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 81:
next_pc=bias+UINT64_C(0x4842e3);
switch(s->pc-bias){
case UINT64_C(0x484281):goto kg_pc_484281;
case UINT64_C(0x484285):goto kg_pc_484285;
case UINT64_C(0x48428b):goto kg_pc_48428b;
case UINT64_C(0x48428d):goto kg_pc_48428d;
case UINT64_C(0x484291):goto kg_pc_484291;
case UINT64_C(0x484297):goto kg_pc_484297;
case UINT64_C(0x48429c):goto kg_pc_48429c;
case UINT64_C(0x48429f):goto kg_pc_48429f;
case UINT64_C(0x4842a5):goto kg_pc_4842a5;
case UINT64_C(0x4842ab):goto kg_pc_4842ab;
case UINT64_C(0x4842b1):goto kg_pc_4842b1;
case UINT64_C(0x4842b3):goto kg_pc_4842b3;
case UINT64_C(0x4842b8):goto kg_pc_4842b8;
case UINT64_C(0x4842ba):goto kg_pc_4842ba;
case UINT64_C(0x4842c0):goto kg_pc_4842c0;
case UINT64_C(0x4842c5):goto kg_pc_4842c5;
case UINT64_C(0x4842c9):goto kg_pc_4842c9;
case UINT64_C(0x4842d0):goto kg_pc_4842d0;
case UINT64_C(0x4842d3):goto kg_pc_4842d3;
case UINT64_C(0x4842d7):goto kg_pc_4842d7;
case UINT64_C(0x4842de):goto kg_pc_4842de;
case UINT64_C(0x4842e1):goto kg_pc_4842e1;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5320: [0x484281,0x4842e3), 22 instructions. */
kg_pc_484281: STEP(0x484281); /* lea r15d, [r14 - 3] */
s->gpr[15] = (uint32_t)((UINT64_C(0xfffffffffffffffd) + s->gpr[14]));
++s->steps;
kg_pc_484285: STEP(0x484285); /* mov eax, dword ptr [rbp - 0x1368] */
READ(a, (UINT64_C(0xffffffffffffec98) + s->gpr[6]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_48428b: STEP(0x48428b); /* mov ecx, dword ptr [rbx] */
READ(a, (UINT64_C(0x0) + s->gpr[1]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
kg_pc_48428d: STEP(0x48428d); /* mov rdx, qword ptr [r12] */
READ(a, (UINT64_C(0x0) + s->gpr[12]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_484291: STEP(0x484291); /* and ecx, 0x125515c8 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x125515c8);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_484297: STEP(0x484297); /* mov esi, 0x7fffffff */
s->gpr[4] = (uint32_t)(UINT64_C(0x7fffffff));
++s->steps;
kg_pc_48429c: STEP(0x48429c); /* and esi, dword ptr [rdx + rcx] */
READ(b, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x1))), 4);
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = b;
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48429f: STEP(0x48429f); /* xor esi, 0x40e3c417 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x40e3c417);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4842a5: STEP(0x4842a5); /* sub esi, dword ptr [rbp - 0xb5c] */
READ(b, (UINT64_C(0xfffffffffffff4a4) + s->gpr[6]), 4);
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = b;
s->gpr[4] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_4842ab: STEP(0x4842ab); /* imul ecx, esi, 0x2ad0c043 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x2ad0c043);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_4842b1: STEP(0x4842b1); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4842b3: STEP(0x4842b3); /* add eax, 0x9c02bcd9 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x9c02bcd9);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4842b8: STEP(0x4842b8); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4842ba: STEP(0x4842ba); /* xor ecx, 0x6fffd7e7 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x6fffd7e7);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4842c0: STEP(0x4842c0); /* and eax, 0xefffd7e7 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xefffd7e7);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_4842c5: STEP(0x4842c5); /* lea r13d, [rcx + rax*2] */
s->gpr[13] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_4842c9: STEP(0x4842c9); /* add r13d, 0xf3fd6b40 */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = UINT64_C(0xf3fd6b40);
s->gpr[13] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4842d0: STEP(0x4842d0); /* movsxd rax, r14d */
s->gpr[0] = (((s->gpr[14] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4842d3: STEP(0x4842d3); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4842d7: STEP(0x4842d7); /* lea rcx, [rip - 0x5d] */
s->gpr[2] = (UINT64_C(0xffffffffffffffa3) + (bias + UINT64_C(0x4842de)));
++s->steps;
kg_pc_4842de: STEP(0x4842de); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4842e1: STEP(0x4842e1); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 82:
next_pc=bias+UINT64_C(0x4842fc);
switch(s->pc-bias){
case UINT64_C(0x4842e5):goto kg_pc_4842e5;
case UINT64_C(0x4842e8):goto kg_pc_4842e8;
case UINT64_C(0x4842ec):goto kg_pc_4842ec;
case UINT64_C(0x4842f0):goto kg_pc_4842f0;
case UINT64_C(0x4842f7):goto kg_pc_4842f7;
case UINT64_C(0x4842fa):goto kg_pc_4842fa;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5321: [0x4842e5,0x4842fc), 6 instructions. */
kg_pc_4842e5: STEP(0x4842e5); /* movsxd rax, r15d */
s->gpr[0] = (((s->gpr[15] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4842e8: STEP(0x4842e8); /* add r15d, 8 */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[15] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4842ec: STEP(0x4842ec); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4842f0: STEP(0x4842f0); /* lea rcx, [rip - 0x12] */
s->gpr[2] = (UINT64_C(0xffffffffffffffee) + (bias + UINT64_C(0x4842f7)));
++s->steps;
kg_pc_4842f7: STEP(0x4842f7); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4842fa: STEP(0x4842fa); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 83:
next_pc=bias+UINT64_C(0x4843f4);
switch(s->pc-bias){
case UINT64_C(0x4842fd):goto kg_pc_4842fd;
case UINT64_C(0x484307):goto kg_pc_484307;
case UINT64_C(0x48430b):goto kg_pc_48430b;
case UINT64_C(0x484315):goto kg_pc_484315;
case UINT64_C(0x48431c):goto kg_pc_48431c;
case UINT64_C(0x48431f):goto kg_pc_48431f;
case UINT64_C(0x484329):goto kg_pc_484329;
case UINT64_C(0x48432c):goto kg_pc_48432c;
case UINT64_C(0x484330):goto kg_pc_484330;
case UINT64_C(0x48433a):goto kg_pc_48433a;
case UINT64_C(0x484344):goto kg_pc_484344;
case UINT64_C(0x48434b):goto kg_pc_48434b;
case UINT64_C(0x484352):goto kg_pc_484352;
case UINT64_C(0x484355):goto kg_pc_484355;
case UINT64_C(0x484359):goto kg_pc_484359;
case UINT64_C(0x484363):goto kg_pc_484363;
case UINT64_C(0x48436a):goto kg_pc_48436a;
case UINT64_C(0x484371):goto kg_pc_484371;
case UINT64_C(0x484378):goto kg_pc_484378;
case UINT64_C(0x484382):goto kg_pc_484382;
case UINT64_C(0x484385):goto kg_pc_484385;
case UINT64_C(0x484389):goto kg_pc_484389;
case UINT64_C(0x484393):goto kg_pc_484393;
case UINT64_C(0x484396):goto kg_pc_484396;
case UINT64_C(0x48439a):goto kg_pc_48439a;
case UINT64_C(0x4843a4):goto kg_pc_4843a4;
case UINT64_C(0x4843a7):goto kg_pc_4843a7;
case UINT64_C(0x4843ab):goto kg_pc_4843ab;
case UINT64_C(0x4843b5):goto kg_pc_4843b5;
case UINT64_C(0x4843b8):goto kg_pc_4843b8;
case UINT64_C(0x4843bc):goto kg_pc_4843bc;
case UINT64_C(0x4843c6):goto kg_pc_4843c6;
case UINT64_C(0x4843c9):goto kg_pc_4843c9;
case UINT64_C(0x4843cd):goto kg_pc_4843cd;
case UINT64_C(0x4843d0):goto kg_pc_4843d0;
case UINT64_C(0x4843d4):goto kg_pc_4843d4;
case UINT64_C(0x4843db):goto kg_pc_4843db;
case UINT64_C(0x4843de):goto kg_pc_4843de;
case UINT64_C(0x4843e5):goto kg_pc_4843e5;
case UINT64_C(0x4843e8):goto kg_pc_4843e8;
case UINT64_C(0x4843f2):goto kg_pc_4843f2;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5322: [0x4842fd,0x4843f4), 41 instructions. */
kg_pc_4842fd: STEP(0x4842fd); /* movabs r12, 0xf3e8ac10815abf71 */
s->gpr[12] = UINT64_C(0xf3e8ac10815abf71);
++s->steps;
kg_pc_484307: STEP(0x484307); /* lea r13d, [r9 + 4] */
s->gpr[13] = (uint32_t)((UINT64_C(0x4) + s->gpr[9]));
++s->steps;
kg_pc_48430b: STEP(0x48430b); /* movabs rax, 0x6fbf7bfffff563af */
s->gpr[0] = UINT64_C(0x6fbf7bfffff563af);
++s->steps;
kg_pc_484315: STEP(0x484315); /* lea rdx, [rbp - 0x3048] */
s->gpr[3] = (UINT64_C(0xffffffffffffcfb8) + s->gpr[6]);
++s->steps;
kg_pc_48431c: STEP(0x48431c); /* xor rax, rdx */
x = s->gpr[0]; y = s->gpr[3];
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_48431f: STEP(0x48431f); /* movabs rsi, 0xefbf7bfffff563a8 */
s->gpr[4] = UINT64_C(0xefbf7bfffff563a8);
++s->steps;
kg_pc_484329: STEP(0x484329); /* and rsi, rdx */
x = s->gpr[4]; y = s->gpr[3];
s->gpr[4] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_48432c: STEP(0x48432c); /* lea rax, [rax + rsi*2] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[4] * UINT64_C(0x2)));
++s->steps;
kg_pc_484330: STEP(0x484330); /* movabs rdx, 0x9c57d7ef7eafdce0 */
s->gpr[3] = UINT64_C(0x9c57d7ef7eafdce0);
++s->steps;
kg_pc_48433a: STEP(0x48433a); /* movabs rsi, 0x49ce48a0c06c9d6d */
s->gpr[4] = UINT64_C(0x49ce48a0c06c9d6d);
++s->steps;
kg_pc_484344: STEP(0x484344); /* add rsi, qword ptr [rbp - 0xdd0] */
READ(b, (UINT64_C(0xfffffffffffff230) + s->gpr[6]), 8);
x = s->gpr[4]; y = b;
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_48434b: STEP(0x48434b); /* mov qword ptr [rbp - 0x90], rsi */
WRITE((UINT64_C(0xffffffffffffff70) + s->gpr[6]), 8, s->gpr[4]);
++s->steps;
kg_pc_484352: STEP(0x484352); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_484355: STEP(0x484355); /* mov qword ptr [rbp - 0x40], rdx */
WRITE((UINT64_C(0xffffffffffffffc0) + s->gpr[6]), 8, s->gpr[3]);
++s->steps;
kg_pc_484359: STEP(0x484359); /* movabs rax, 0x60bdcd18916eca6d */
s->gpr[0] = UINT64_C(0x60bdcd18916eca6d);
++s->steps;
kg_pc_484363: STEP(0x484363); /* add rax, qword ptr [rbp - 0x2f18] */
READ(b, (UINT64_C(0xffffffffffffd0e8) + s->gpr[6]), 8);
x = s->gpr[0]; y = b;
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_48436a: STEP(0x48436a); /* mov qword ptr [rbp - 0xb0], rax */
WRITE((UINT64_C(0xffffffffffffff50) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_484371: STEP(0x484371); /* mov rax, qword ptr [rbp - 0x50e8] */
READ(a, (UINT64_C(0xffffffffffffaf18) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_484378: STEP(0x484378); /* movabs rdx, 0xd1a71130df0b5d59 */
s->gpr[3] = UINT64_C(0xd1a71130df0b5d59);
++s->steps;
kg_pc_484382: STEP(0x484382); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_484385: STEP(0x484385); /* mov qword ptr [rbp - 0x48], rdx */
WRITE((UINT64_C(0xffffffffffffffb8) + s->gpr[6]), 8, s->gpr[3]);
++s->steps;
kg_pc_484389: STEP(0x484389); /* movabs rdx, 0x6f79466dab33c920 */
s->gpr[3] = UINT64_C(0x6f79466dab33c920);
++s->steps;
kg_pc_484393: STEP(0x484393); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_484396: STEP(0x484396); /* mov qword ptr [rbp - 0x50], rdx */
WRITE((UINT64_C(0xffffffffffffffb0) + s->gpr[6]), 8, s->gpr[3]);
++s->steps;
kg_pc_48439a: STEP(0x48439a); /* movabs rdx, 0xd1a71130df0b5dc6 */
s->gpr[3] = UINT64_C(0xd1a71130df0b5dc6);
++s->steps;
kg_pc_4843a4: STEP(0x4843a4); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4843a7: STEP(0x4843a7); /* mov qword ptr [rbp - 0x58], rdx */
WRITE((UINT64_C(0xffffffffffffffa8) + s->gpr[6]), 8, s->gpr[3]);
++s->steps;
kg_pc_4843ab: STEP(0x4843ab); /* movabs rdx, 0xd1a71130df0b5d91 */
s->gpr[3] = UINT64_C(0xd1a71130df0b5d91);
++s->steps;
kg_pc_4843b5: STEP(0x4843b5); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4843b8: STEP(0x4843b8); /* mov qword ptr [rbp - 0x60], rdx */
WRITE((UINT64_C(0xffffffffffffffa0) + s->gpr[6]), 8, s->gpr[3]);
++s->steps;
kg_pc_4843bc: STEP(0x4843bc); /* movabs rdx, 0xd1a71130df0b5f31 */
s->gpr[3] = UINT64_C(0xd1a71130df0b5f31);
++s->steps;
kg_pc_4843c6: STEP(0x4843c6); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4843c9: STEP(0x4843c9); /* mov qword ptr [rbp - 0x68], rdx */
WRITE((UINT64_C(0xffffffffffffff98) + s->gpr[6]), 8, s->gpr[3]);
++s->steps;
kg_pc_4843cd: STEP(0x4843cd); /* movsxd rax, r9d */
s->gpr[0] = (((s->gpr[9] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4843d0: STEP(0x4843d0); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4843d4: STEP(0x4843d4); /* lea rdx, [rip - 0xde] */
s->gpr[3] = (UINT64_C(0xffffffffffffff22) + (bias + UINT64_C(0x4843db)));
++s->steps;
kg_pc_4843db: STEP(0x4843db); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4843de: STEP(0x4843de); /* mov r9, qword ptr [rbp - 0x1ea0] */
READ(a, (UINT64_C(0xffffffffffffe160) + s->gpr[6]), 8);
s->gpr[9] = a;
++s->steps;
kg_pc_4843e5: STEP(0x4843e5); /* add r9, rdi */
x = s->gpr[9]; y = s->gpr[5];
s->gpr[9] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4843e8: STEP(0x4843e8); /* movabs r15, 0x36786f82353ccc07 */
s->gpr[15] = UINT64_C(0x36786f82353ccc07);
++s->steps;
kg_pc_4843f2: STEP(0x4843f2); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 84:
next_pc=bias+UINT64_C(0x484436);
switch(s->pc-bias){
case UINT64_C(0x4843f6):goto kg_pc_4843f6;
case UINT64_C(0x4843fd):goto kg_pc_4843fd;
case UINT64_C(0x484402):goto kg_pc_484402;
case UINT64_C(0x484409):goto kg_pc_484409;
case UINT64_C(0x484410):goto kg_pc_484410;
case UINT64_C(0x484417):goto kg_pc_484417;
case UINT64_C(0x48441e):goto kg_pc_48441e;
case UINT64_C(0x484420):goto kg_pc_484420;
case UINT64_C(0x484424):goto kg_pc_484424;
case UINT64_C(0x48442b):goto kg_pc_48442b;
case UINT64_C(0x48442e):goto kg_pc_48442e;
case UINT64_C(0x484434):goto kg_pc_484434;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5323: [0x4843f6,0x484436), 12 instructions. */
kg_pc_4843f6: STEP(0x4843f6); /* lea r9d, [rax + 0x154f] */
s->gpr[9] = (uint32_t)((UINT64_C(0x154f) + s->gpr[0]));
++s->steps;
kg_pc_4843fd: STEP(0x4843fd); /* add eax, 0x1f81 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1f81);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_484402: STEP(0x484402); /* mov r10, qword ptr [rbp - 0x1db8] */
READ(a, (UINT64_C(0xffffffffffffe248) + s->gpr[6]), 8);
s->gpr[10] = a;
++s->steps;
kg_pc_484409: STEP(0x484409); /* mov rsi, qword ptr [rbp - 0x1de0] */
READ(a, (UINT64_C(0xffffffffffffe220) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_484410: STEP(0x484410); /* lea rcx, [rip + 0x22] */
s->gpr[2] = (UINT64_C(0x22) + (bias + UINT64_C(0x484417)));
++s->steps;
kg_pc_484417: STEP(0x484417); /* mov qword ptr [rbp - 0xcd8], rcx */
WRITE((UINT64_C(0xfffffffffffff328) + s->gpr[6]), 8, s->gpr[2]);
++s->steps;
kg_pc_48441e: STEP(0x48441e); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_484420: STEP(0x484420); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484424: STEP(0x484424); /* lea rcx, [rip - 0x35] */
s->gpr[2] = (UINT64_C(0xffffffffffffffcb) + (bias + UINT64_C(0x48442b)));
++s->steps;
kg_pc_48442b: STEP(0x48442b); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_48442e: STEP(0x48442e); /* mov r15d, 0x24ffac6c */
s->gpr[15] = (uint32_t)(UINT64_C(0x24ffac6c));
++s->steps;
kg_pc_484434: STEP(0x484434); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 85:
next_pc=bias+UINT64_C(0x484481);
switch(s->pc-bias){
case UINT64_C(0x484439):goto kg_pc_484439;
case UINT64_C(0x484440):goto kg_pc_484440;
case UINT64_C(0x484447):goto kg_pc_484447;
case UINT64_C(0x48444c):goto kg_pc_48444c;
case UINT64_C(0x484453):goto kg_pc_484453;
case UINT64_C(0x48445a):goto kg_pc_48445a;
case UINT64_C(0x484461):goto kg_pc_484461;
case UINT64_C(0x484468):goto kg_pc_484468;
case UINT64_C(0x48446f):goto kg_pc_48446f;
case UINT64_C(0x484471):goto kg_pc_484471;
case UINT64_C(0x484475):goto kg_pc_484475;
case UINT64_C(0x48447c):goto kg_pc_48447c;
case UINT64_C(0x48447f):goto kg_pc_48447f;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5324: [0x484439,0x484481), 13 instructions. */
kg_pc_484439: STEP(0x484439); /* mov rax, qword ptr [rbp - 0xb8] */
READ(a, (UINT64_C(0xffffffffffffff48) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_484440: STEP(0x484440); /* lea r9d, [rax + 0x154f] */
s->gpr[9] = (uint32_t)((UINT64_C(0x154f) + s->gpr[0]));
++s->steps;
kg_pc_484447: STEP(0x484447); /* add eax, 0x179e */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x179e);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48444c: STEP(0x48444c); /* mov r10, qword ptr [rbp - 0x2e18] */
READ(a, (UINT64_C(0xffffffffffffd1e8) + s->gpr[6]), 8);
s->gpr[10] = a;
++s->steps;
kg_pc_484453: STEP(0x484453); /* mov r15d, dword ptr [rbp - 0x2020] */
READ(a, (UINT64_C(0xffffffffffffdfe0) + s->gpr[6]), 4);
s->gpr[15] = (uint32_t)(a);
++s->steps;
kg_pc_48445a: STEP(0x48445a); /* mov rsi, qword ptr [rbp - 0x1de0] */
READ(a, (UINT64_C(0xffffffffffffe220) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_484461: STEP(0x484461); /* lea rcx, [rip + 0x1c] */
s->gpr[2] = (UINT64_C(0x1c) + (bias + UINT64_C(0x484468)));
++s->steps;
kg_pc_484468: STEP(0x484468); /* mov qword ptr [rbp - 0xcd8], rcx */
WRITE((UINT64_C(0xfffffffffffff328) + s->gpr[6]), 8, s->gpr[2]);
++s->steps;
kg_pc_48446f: STEP(0x48446f); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_484471: STEP(0x484471); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484475: STEP(0x484475); /* lea rcx, [rip - 0x43] */
s->gpr[2] = (UINT64_C(0xffffffffffffffbd) + (bias + UINT64_C(0x48447c)));
++s->steps;
kg_pc_48447c: STEP(0x48447c); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_48447f: STEP(0x48447f); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 86:
next_pc=bias+UINT64_C(0x4844d7);
switch(s->pc-bias){
case UINT64_C(0x484484):goto kg_pc_484484;
case UINT64_C(0x48448b):goto kg_pc_48448b;
case UINT64_C(0x484491):goto kg_pc_484491;
case UINT64_C(0x48449b):goto kg_pc_48449b;
case UINT64_C(0x4844a2):goto kg_pc_4844a2;
case UINT64_C(0x4844a8):goto kg_pc_4844a8;
case UINT64_C(0x4844af):goto kg_pc_4844af;
case UINT64_C(0x4844b6):goto kg_pc_4844b6;
case UINT64_C(0x4844bd):goto kg_pc_4844bd;
case UINT64_C(0x4844c0):goto kg_pc_4844c0;
case UINT64_C(0x4844c4):goto kg_pc_4844c4;
case UINT64_C(0x4844cb):goto kg_pc_4844cb;
case UINT64_C(0x4844ce):goto kg_pc_4844ce;
case UINT64_C(0x4844d5):goto kg_pc_4844d5;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5325: [0x484484,0x4844d7), 14 instructions. */
kg_pc_484484: STEP(0x484484); /* mov rcx, qword ptr [rbp - 0xb8] */
READ(a, (UINT64_C(0xffffffffffffff48) + s->gpr[6]), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_48448b: STEP(0x48448b); /* lea ebx, [rcx + 0x92c] */
s->gpr[1] = (uint32_t)((UINT64_C(0x92c) + s->gpr[2]));
++s->steps;
kg_pc_484491: STEP(0x484491); /* movabs rax, 0x71d32c5f9580f4d8 */
s->gpr[0] = UINT64_C(0x71d32c5f9580f4d8);
++s->steps;
kg_pc_48449b: STEP(0x48449b); /* add rax, qword ptr [rbp - 0x4e38] */
READ(b, (UINT64_C(0xffffffffffffb1c8) + s->gpr[6]), 8);
x = s->gpr[0]; y = b;
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4844a2: STEP(0x4844a2); /* add ecx, 0x17a0 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x17a0);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4844a8: STEP(0x4844a8); /* mov r12, qword ptr [rbp - 0x3f28] */
READ(a, (UINT64_C(0xffffffffffffc0d8) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_4844af: STEP(0x4844af); /* lea rdx, [rip + 0x24] */
s->gpr[3] = (UINT64_C(0x24) + (bias + UINT64_C(0x4844b6)));
++s->steps;
kg_pc_4844b6: STEP(0x4844b6); /* mov qword ptr [rbp - 0x2d10], rdx */
WRITE((UINT64_C(0xffffffffffffd2f0) + s->gpr[6]), 8, s->gpr[3]);
++s->steps;
kg_pc_4844bd: STEP(0x4844bd); /* movsxd rcx, ecx */
s->gpr[2] = (((s->gpr[2] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4844c0: STEP(0x4844c0); /* movsxd rcx, dword ptr [r11 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4844c4: STEP(0x4844c4); /* lea rdx, [rip - 0x47] */
s->gpr[3] = (UINT64_C(0xffffffffffffffb9) + (bias + UINT64_C(0x4844cb)));
++s->steps;
kg_pc_4844cb: STEP(0x4844cb); /* add rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4844ce: STEP(0x4844ce); /* mov r14, qword ptr [rbp - 0x128] */
READ(a, (UINT64_C(0xfffffffffffffed8) + s->gpr[6]), 8);
s->gpr[14] = a;
++s->steps;
kg_pc_4844d5: STEP(0x4844d5); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 87:
next_pc=bias+UINT64_C(0x48451f);
switch(s->pc-bias){
case UINT64_C(0x4844da):goto kg_pc_4844da;
case UINT64_C(0x4844e1):goto kg_pc_4844e1;
case UINT64_C(0x4844e3):goto kg_pc_4844e3;
case UINT64_C(0x4844ea):goto kg_pc_4844ea;
case UINT64_C(0x4844ed):goto kg_pc_4844ed;
case UINT64_C(0x4844f4):goto kg_pc_4844f4;
case UINT64_C(0x4844fb):goto kg_pc_4844fb;
case UINT64_C(0x4844fe):goto kg_pc_4844fe;
case UINT64_C(0x484501):goto kg_pc_484501;
case UINT64_C(0x484506):goto kg_pc_484506;
case UINT64_C(0x484508):goto kg_pc_484508;
case UINT64_C(0x48450c):goto kg_pc_48450c;
case UINT64_C(0x484513):goto kg_pc_484513;
case UINT64_C(0x484516):goto kg_pc_484516;
case UINT64_C(0x48451d):goto kg_pc_48451d;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5326: [0x4844da,0x48451f), 15 instructions. */
kg_pc_4844da: STEP(0x4844da); /* mov dword ptr [rbp - 0x3278], r10d */
WRITE((UINT64_C(0xffffffffffffcd88) + s->gpr[6]), 4, (s->gpr[10] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4844e1: STEP(0x4844e1); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4844e3: STEP(0x4844e3); /* cmp r10d, 0xe982a16 */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0xe982a16);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_4844ea: STEP(0x4844ea); /* sete al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4844ed: STEP(0x4844ed); /* imul r9d, eax, 0x1547 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1547);
s->gpr[9] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_4844f4: STEP(0x4844f4); /* mov r8, qword ptr [rbp - 0xb8] */
READ(a, (UINT64_C(0xffffffffffffff48) + s->gpr[6]), 8);
s->gpr[8] = a;
++s->steps;
kg_pc_4844fb: STEP(0x4844fb); /* add r9d, r8d */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4844fe: STEP(0x4844fe); /* add eax, r8d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_484501: STEP(0x484501); /* add eax, 0xd04 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xd04);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_484506: STEP(0x484506); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_484508: STEP(0x484508); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48450c: STEP(0x48450c); /* lea rcx, [rip - 0x39] */
s->gpr[2] = (UINT64_C(0xffffffffffffffc7) + (bias + UINT64_C(0x484513)));
++s->steps;
kg_pc_484513: STEP(0x484513); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_484516: STEP(0x484516); /* mov r12, qword ptr [rbp - 0x3f0] */
READ(a, (UINT64_C(0xfffffffffffffc10) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_48451d: STEP(0x48451d); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 88:
next_pc=bias+UINT64_C(0x484559);
switch(s->pc-bias){
case UINT64_C(0x484520):goto kg_pc_484520;
case UINT64_C(0x484527):goto kg_pc_484527;
case UINT64_C(0x48452e):goto kg_pc_48452e;
case UINT64_C(0x484535):goto kg_pc_484535;
case UINT64_C(0x48453c):goto kg_pc_48453c;
case UINT64_C(0x48453f):goto kg_pc_48453f;
case UINT64_C(0x484543):goto kg_pc_484543;
case UINT64_C(0x484547):goto kg_pc_484547;
case UINT64_C(0x48454e):goto kg_pc_48454e;
case UINT64_C(0x484551):goto kg_pc_484551;
case UINT64_C(0x484557):goto kg_pc_484557;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5327: [0x484520,0x484559), 11 instructions. */
kg_pc_484520: STEP(0x484520); /* mov r10, qword ptr [rbp - 0x3f28] */
READ(a, (UINT64_C(0xffffffffffffc0d8) + s->gpr[6]), 8);
s->gpr[10] = a;
++s->steps;
kg_pc_484527: STEP(0x484527); /* mov rsi, qword ptr [rbp - 0x1de0] */
READ(a, (UINT64_C(0xffffffffffffe220) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_48452e: STEP(0x48452e); /* lea rax, [rip + 0x26] */
s->gpr[0] = (UINT64_C(0x26) + (bias + UINT64_C(0x484535)));
++s->steps;
kg_pc_484535: STEP(0x484535); /* mov qword ptr [rbp - 0xcd8], rax */
WRITE((UINT64_C(0xfffffffffffff328) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_48453c: STEP(0x48453c); /* movsxd rax, r9d */
s->gpr[0] = (((s->gpr[9] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48453f: STEP(0x48453f); /* add r9d, 8 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_484543: STEP(0x484543); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484547: STEP(0x484547); /* lea rcx, [rip - 0x2e] */
s->gpr[2] = (UINT64_C(0xffffffffffffffd2) + (bias + UINT64_C(0x48454e)));
++s->steps;
kg_pc_48454e: STEP(0x48454e); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_484551: STEP(0x484551); /* mov r15d, 0x24ffac70 */
s->gpr[15] = (uint32_t)(UINT64_C(0x24ffac70));
++s->steps;
kg_pc_484557: STEP(0x484557); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 89:
next_pc=bias+UINT64_C(0x48459f);
switch(s->pc-bias){
case UINT64_C(0x48455b):goto kg_pc_48455b;
case UINT64_C(0x484562):goto kg_pc_484562;
case UINT64_C(0x484569):goto kg_pc_484569;
case UINT64_C(0x48456e):goto kg_pc_48456e;
case UINT64_C(0x484575):goto kg_pc_484575;
case UINT64_C(0x48457c):goto kg_pc_48457c;
case UINT64_C(0x484583):goto kg_pc_484583;
case UINT64_C(0x48458a):goto kg_pc_48458a;
case UINT64_C(0x48458c):goto kg_pc_48458c;
case UINT64_C(0x484590):goto kg_pc_484590;
case UINT64_C(0x484597):goto kg_pc_484597;
case UINT64_C(0x48459a):goto kg_pc_48459a;
case UINT64_C(0x48459d):goto kg_pc_48459d;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5328: [0x48455b,0x48459f), 13 instructions. */
kg_pc_48455b: STEP(0x48455b); /* mov rax, qword ptr [rbp - 0xb8] */
READ(a, (UINT64_C(0xffffffffffffff48) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_484562: STEP(0x484562); /* lea r9d, [rax + 0x1554] */
s->gpr[9] = (uint32_t)((UINT64_C(0x1554) + s->gpr[0]));
++s->steps;
kg_pc_484569: STEP(0x484569); /* add eax, 0x179f */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x179f);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48456e: STEP(0x48456e); /* mov rdx, qword ptr [rbp - 0x3f30] */
READ(a, (UINT64_C(0xffffffffffffc0d0) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_484575: STEP(0x484575); /* mov r8, qword ptr [rbp - 0x1de0] */
READ(a, (UINT64_C(0xffffffffffffe220) + s->gpr[6]), 8);
s->gpr[8] = a;
++s->steps;
kg_pc_48457c: STEP(0x48457c); /* lea rcx, [rip + 0x1f] */
s->gpr[2] = (UINT64_C(0x1f) + (bias + UINT64_C(0x484583)));
++s->steps;
kg_pc_484583: STEP(0x484583); /* mov qword ptr [rbp - 0x1338], rcx */
WRITE((UINT64_C(0xffffffffffffecc8) + s->gpr[6]), 8, s->gpr[2]);
++s->steps;
kg_pc_48458a: STEP(0x48458a); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_48458c: STEP(0x48458c); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484590: STEP(0x484590); /* lea rcx, [rip - 0x3c] */
s->gpr[2] = (UINT64_C(0xffffffffffffffc4) + (bias + UINT64_C(0x484597)));
++s->steps;
kg_pc_484597: STEP(0x484597); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_48459a: STEP(0x48459a); /* mov rsi, r11 */
s->gpr[4] = s->gpr[11];
++s->steps;
kg_pc_48459d: STEP(0x48459d); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 90:
next_pc=bias+UINT64_C(0x4845e5);
switch(s->pc-bias){
case UINT64_C(0x4845a2):goto kg_pc_4845a2;
case UINT64_C(0x4845a8):goto kg_pc_4845a8;
case UINT64_C(0x4845ab):goto kg_pc_4845ab;
case UINT64_C(0x4845b1):goto kg_pc_4845b1;
case UINT64_C(0x4845b8):goto kg_pc_4845b8;
case UINT64_C(0x4845bf):goto kg_pc_4845bf;
case UINT64_C(0x4845c1):goto kg_pc_4845c1;
case UINT64_C(0x4845c5):goto kg_pc_4845c5;
case UINT64_C(0x4845cc):goto kg_pc_4845cc;
case UINT64_C(0x4845cf):goto kg_pc_4845cf;
case UINT64_C(0x4845d9):goto kg_pc_4845d9;
case UINT64_C(0x4845e0):goto kg_pc_4845e0;
case UINT64_C(0x4845e3):goto kg_pc_4845e3;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5329: [0x4845a2,0x4845e5), 13 instructions. */
kg_pc_4845a2: STEP(0x4845a2); /* lea ecx, [rsi + 0x2148] */
s->gpr[2] = (uint32_t)((UINT64_C(0x2148) + s->gpr[4]));
++s->steps;
kg_pc_4845a8: STEP(0x4845a8); /* mov r8, rsi */
s->gpr[8] = s->gpr[4];
++s->steps;
kg_pc_4845ab: STEP(0x4845ab); /* lea eax, [rsi + 0x284f] */
s->gpr[0] = (uint32_t)((UINT64_C(0x284f) + s->gpr[4]));
++s->steps;
kg_pc_4845b1: STEP(0x4845b1); /* mov r13, qword ptr [rbp - 0x4908] */
READ(a, (UINT64_C(0xffffffffffffb6f8) + s->gpr[6]), 8);
s->gpr[13] = a;
++s->steps;
kg_pc_4845b8: STEP(0x4845b8); /* mov r10, qword ptr [rbp - 0x3f30] */
READ(a, (UINT64_C(0xffffffffffffc0d0) + s->gpr[6]), 8);
s->gpr[10] = a;
++s->steps;
kg_pc_4845bf: STEP(0x4845bf); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_4845c1: STEP(0x4845c1); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4845c5: STEP(0x4845c5); /* lea rdx, [rip - 0x2a] */
s->gpr[3] = (UINT64_C(0xffffffffffffffd6) + (bias + UINT64_C(0x4845cc)));
++s->steps;
kg_pc_4845cc: STEP(0x4845cc); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4845cf: STEP(0x4845cf); /* movabs rsi, 0x22f7022fbd0d6d46 */
s->gpr[4] = UINT64_C(0x22f7022fbd0d6d46);
++s->steps;
kg_pc_4845d9: STEP(0x4845d9); /* lea r15, [rip + 0x4b9] */
s->gpr[15] = (UINT64_C(0x4b9) + (bias + UINT64_C(0x4845e0)));
++s->steps;
kg_pc_4845e0: STEP(0x4845e0); /* mov rbx, r11 */
s->gpr[1] = s->gpr[11];
++s->steps;
kg_pc_4845e3: STEP(0x4845e3); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 91:
next_pc=bias+UINT64_C(0x484625);
switch(s->pc-bias){
case UINT64_C(0x4845e6):goto kg_pc_4845e6;
case UINT64_C(0x4845f0):goto kg_pc_4845f0;
case UINT64_C(0x4845f3):goto kg_pc_4845f3;
case UINT64_C(0x4845f5):goto kg_pc_4845f5;
case UINT64_C(0x4845f7):goto kg_pc_4845f7;
case UINT64_C(0x4845fa):goto kg_pc_4845fa;
case UINT64_C(0x4845fd):goto kg_pc_4845fd;
case UINT64_C(0x484601):goto kg_pc_484601;
case UINT64_C(0x484603):goto kg_pc_484603;
case UINT64_C(0x484606):goto kg_pc_484606;
case UINT64_C(0x48460a):goto kg_pc_48460a;
case UINT64_C(0x48460d):goto kg_pc_48460d;
case UINT64_C(0x484610):goto kg_pc_484610;
case UINT64_C(0x484612):goto kg_pc_484612;
case UINT64_C(0x484615):goto kg_pc_484615;
case UINT64_C(0x484619):goto kg_pc_484619;
case UINT64_C(0x484620):goto kg_pc_484620;
case UINT64_C(0x484623):goto kg_pc_484623;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5330: [0x4845e6,0x484625), 18 instructions. */
kg_pc_4845e6: STEP(0x4845e6); /* movabs rax, 0x8539528206b6dd45 */
s->gpr[0] = UINT64_C(0x8539528206b6dd45);
++s->steps;
kg_pc_4845f0: STEP(0x4845f0); /* add rax, r13 */
x = s->gpr[0]; y = s->gpr[13];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4845f3: STEP(0x4845f3); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4845f5: STEP(0x4845f5); /* xor edi, edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4845f7: STEP(0x4845f7); /* cmp r10, rax */
x = s->gpr[10]; y = s->gpr[0];
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_4845fa: STEP(0x4845fa); /* setbe dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_BE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4845fd: STEP(0x4845fd); /* seta dil */
s->gpr[5] = (s->gpr[5] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_A)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_484601: STEP(0x484601); /* mov eax, edi */
s->gpr[0] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_484603: STEP(0x484603); /* shl eax, 4 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x4);
s->gpr[0] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_484606: STEP(0x484606); /* lea r11d, [rdx + rdx*2] */
s->gpr[11] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_48460a: STEP(0x48460a); /* add r11d, ecx */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[11] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48460d: STEP(0x48460d); /* add r11d, eax */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[11] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_484610: STEP(0x484610); /* add edi, ecx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_484612: STEP(0x484612); /* movsxd rax, edi */
s->gpr[0] = (((s->gpr[5] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484615: STEP(0x484615); /* movsxd rax, dword ptr [rbx + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[1] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484619: STEP(0x484619); /* lea rcx, [rip - 0x3a] */
s->gpr[2] = (UINT64_C(0xffffffffffffffc6) + (bias + UINT64_C(0x484620)));
++s->steps;
kg_pc_484620: STEP(0x484620); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_484623: STEP(0x484623); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 92:
next_pc=bias+UINT64_C(0x484677);
switch(s->pc-bias){
case UINT64_C(0x484628):goto kg_pc_484628;
case UINT64_C(0x48462a):goto kg_pc_48462a;
case UINT64_C(0x48462f):goto kg_pc_48462f;
case UINT64_C(0x484631):goto kg_pc_484631;
case UINT64_C(0x484637):goto kg_pc_484637;
case UINT64_C(0x48463d):goto kg_pc_48463d;
case UINT64_C(0x484641):goto kg_pc_484641;
case UINT64_C(0x484648):goto kg_pc_484648;
case UINT64_C(0x48464a):goto kg_pc_48464a;
case UINT64_C(0x48464c):goto kg_pc_48464c;
case UINT64_C(0x484653):goto kg_pc_484653;
case UINT64_C(0x484656):goto kg_pc_484656;
case UINT64_C(0x484659):goto kg_pc_484659;
case UINT64_C(0x48465d):goto kg_pc_48465d;
case UINT64_C(0x484660):goto kg_pc_484660;
case UINT64_C(0x484664):goto kg_pc_484664;
case UINT64_C(0x48466b):goto kg_pc_48466b;
case UINT64_C(0x48466e):goto kg_pc_48466e;
case UINT64_C(0x484675):goto kg_pc_484675;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5331: [0x484628,0x484677), 19 instructions. */
kg_pc_484628: STEP(0x484628); /* mov eax, esi */
s->gpr[0] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_48462a: STEP(0x48462a); /* xor eax, 0xe2f390ad */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xe2f390ad);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48462f: STEP(0x48462f); /* add esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_484631: STEP(0x484631); /* and esi, 0xbffdfbf6 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xbffdfbf6);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_484637: STEP(0x484637); /* xor esi, 0x3a18daa4 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x3a18daa4);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48463d: STEP(0x48463d); /* lea r14d, [rax + rsi] */
s->gpr[14] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_484641: STEP(0x484641); /* add r14d, 0xd0ab0449 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0xd0ab0449);
s->gpr[14] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_484648: STEP(0x484648); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48464a: STEP(0x48464a); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48464c: STEP(0x48464c); /* cmp r14d, 0x30aa0244 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0x30aa0244);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_484653: STEP(0x484653); /* setne dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_484656: STEP(0x484656); /* sete cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_484659: STEP(0x484659); /* lea edi, [r11 + rcx] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[11] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_48465d: STEP(0x48465d); /* movsxd rdi, edi */
s->gpr[5] = (((s->gpr[5] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484660: STEP(0x484660); /* movsxd rdi, dword ptr [rbx + rdi*4] */
READ(a, (UINT64_C(0x0) + s->gpr[1] + (s->gpr[5] * UINT64_C(0x4))), 4);
s->gpr[5] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484664: STEP(0x484664); /* lea rbx, [rip - 0x43] */
s->gpr[1] = (UINT64_C(0xffffffffffffffbd) + (bias + UINT64_C(0x48466b)));
++s->steps;
kg_pc_48466b: STEP(0x48466b); /* add rbx, rdi */
x = s->gpr[1]; y = s->gpr[5];
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_48466e: STEP(0x48466e); /* mov r12, qword ptr [rbp - 0x3f0] */
READ(a, (UINT64_C(0xfffffffffffffc10) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_484675: STEP(0x484675); /* jmp rbx */
x = s->gpr[1];
next_pc = x;
++s->steps;

break;
    case 93:
next_pc=bias+UINT64_C(0x4846b7);
switch(s->pc-bias){
case UINT64_C(0x48467a):goto kg_pc_48467a;
case UINT64_C(0x48467e):goto kg_pc_48467e;
case UINT64_C(0x484680):goto kg_pc_484680;
case UINT64_C(0x484682):goto kg_pc_484682;
case UINT64_C(0x484688):goto kg_pc_484688;
case UINT64_C(0x48468b):goto kg_pc_48468b;
case UINT64_C(0x484692):goto kg_pc_484692;
case UINT64_C(0x484694):goto kg_pc_484694;
case UINT64_C(0x48469b):goto kg_pc_48469b;
case UINT64_C(0x48469f):goto kg_pc_48469f;
case UINT64_C(0x4846a6):goto kg_pc_4846a6;
case UINT64_C(0x4846a9):goto kg_pc_4846a9;
case UINT64_C(0x4846ae):goto kg_pc_4846ae;
case UINT64_C(0x4846b5):goto kg_pc_4846b5;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5332: [0x48467a,0x4846b7), 14 instructions. */
kg_pc_48467a: STEP(0x48467a); /* mov qword ptr [rbp - 0x40], r15 */
WRITE((UINT64_C(0xffffffffffffffc0) + s->gpr[6]), 8, s->gpr[15]);
++s->steps;
kg_pc_48467e: STEP(0x48467e); /* mov al, dl */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((s->gpr[3] & UINT64_C(0xff))) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_484680: STEP(0x484680); /* add ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_484682: STEP(0x484682); /* imul eax, ecx, 0xffffdea8 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffdea8);
s->gpr[0] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_484688: STEP(0x484688); /* add r11d, eax */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[11] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48468b: STEP(0x48468b); /* lea eax, [r11 + 0x2157] */
s->gpr[0] = (uint32_t)((UINT64_C(0x2157) + s->gpr[11]));
++s->steps;
kg_pc_484692: STEP(0x484692); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_484694: STEP(0x484694); /* lea rcx, [rip - 0x47d34b] */
s->gpr[2] = (UINT64_C(0xffffffffffb82cb5) + (bias + UINT64_C(0x48469b)));
++s->steps;
kg_pc_48469b: STEP(0x48469b); /* movsxd rax, dword ptr [rcx + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48469f: STEP(0x48469f); /* lea rcx, [rip - 0x2c] */
s->gpr[2] = (UINT64_C(0xffffffffffffffd4) + (bias + UINT64_C(0x4846a6)));
++s->steps;
kg_pc_4846a6: STEP(0x4846a6); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4846a9: STEP(0x4846a9); /* mov edi, 0x60c83afd */
s->gpr[5] = (uint32_t)(UINT64_C(0x60c83afd));
++s->steps;
kg_pc_4846ae: STEP(0x4846ae); /* mov r9, qword ptr [rbp - 0xd40] */
READ(a, (UINT64_C(0xfffffffffffff2c0) + s->gpr[6]), 8);
s->gpr[9] = a;
++s->steps;
kg_pc_4846b5: STEP(0x4846b5); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 94:
next_pc=bias+UINT64_C(0x484813);
switch(s->pc-bias){
case UINT64_C(0x4846c0):goto kg_pc_4846c0;
case UINT64_C(0x4846c3):goto kg_pc_4846c3;
case UINT64_C(0x4846ca):goto kg_pc_4846ca;
case UINT64_C(0x4846ce):goto kg_pc_4846ce;
case UINT64_C(0x4846d4):goto kg_pc_4846d4;
case UINT64_C(0x4846d9):goto kg_pc_4846d9;
case UINT64_C(0x4846e3):goto kg_pc_4846e3;
case UINT64_C(0x4846e7):goto kg_pc_4846e7;
case UINT64_C(0x4846e9):goto kg_pc_4846e9;
case UINT64_C(0x4846ec):goto kg_pc_4846ec;
case UINT64_C(0x4846f0):goto kg_pc_4846f0;
case UINT64_C(0x4846f7):goto kg_pc_4846f7;
case UINT64_C(0x4846fe):goto kg_pc_4846fe;
case UINT64_C(0x484701):goto kg_pc_484701;
case UINT64_C(0x484708):goto kg_pc_484708;
case UINT64_C(0x48470b):goto kg_pc_48470b;
case UINT64_C(0x48470e):goto kg_pc_48470e;
case UINT64_C(0x484715):goto kg_pc_484715;
case UINT64_C(0x484718):goto kg_pc_484718;
case UINT64_C(0x48471e):goto kg_pc_48471e;
case UINT64_C(0x484724):goto kg_pc_484724;
case UINT64_C(0x484726):goto kg_pc_484726;
case UINT64_C(0x484729):goto kg_pc_484729;
case UINT64_C(0x48472b):goto kg_pc_48472b;
case UINT64_C(0x48472f):goto kg_pc_48472f;
case UINT64_C(0x484736):goto kg_pc_484736;
case UINT64_C(0x48473d):goto kg_pc_48473d;
case UINT64_C(0x484744):goto kg_pc_484744;
case UINT64_C(0x484747):goto kg_pc_484747;
case UINT64_C(0x48474a):goto kg_pc_48474a;
case UINT64_C(0x48474e):goto kg_pc_48474e;
case UINT64_C(0x484755):goto kg_pc_484755;
case UINT64_C(0x484759):goto kg_pc_484759;
case UINT64_C(0x48475c):goto kg_pc_48475c;
case UINT64_C(0x484762):goto kg_pc_484762;
case UINT64_C(0x484768):goto kg_pc_484768;
case UINT64_C(0x484770):goto kg_pc_484770;
case UINT64_C(0x484772):goto kg_pc_484772;
case UINT64_C(0x484775):goto kg_pc_484775;
case UINT64_C(0x48477a):goto kg_pc_48477a;
case UINT64_C(0x484781):goto kg_pc_484781;
case UINT64_C(0x484784):goto kg_pc_484784;
case UINT64_C(0x484786):goto kg_pc_484786;
case UINT64_C(0x484789):goto kg_pc_484789;
case UINT64_C(0x48478c):goto kg_pc_48478c;
case UINT64_C(0x484792):goto kg_pc_484792;
case UINT64_C(0x484794):goto kg_pc_484794;
case UINT64_C(0x484798):goto kg_pc_484798;
case UINT64_C(0x48479f):goto kg_pc_48479f;
case UINT64_C(0x4847a2):goto kg_pc_4847a2;
case UINT64_C(0x4847a9):goto kg_pc_4847a9;
case UINT64_C(0x4847ac):goto kg_pc_4847ac;
case UINT64_C(0x4847b3):goto kg_pc_4847b3;
case UINT64_C(0x4847b7):goto kg_pc_4847b7;
case UINT64_C(0x4847ba):goto kg_pc_4847ba;
case UINT64_C(0x4847bc):goto kg_pc_4847bc;
case UINT64_C(0x4847be):goto kg_pc_4847be;
case UINT64_C(0x4847c8):goto kg_pc_4847c8;
case UINT64_C(0x4847cc):goto kg_pc_4847cc;
case UINT64_C(0x4847d2):goto kg_pc_4847d2;
case UINT64_C(0x4847d7):goto kg_pc_4847d7;
case UINT64_C(0x4847da):goto kg_pc_4847da;
case UINT64_C(0x4847dd):goto kg_pc_4847dd;
case UINT64_C(0x4847df):goto kg_pc_4847df;
case UINT64_C(0x4847e2):goto kg_pc_4847e2;
case UINT64_C(0x4847e5):goto kg_pc_4847e5;
case UINT64_C(0x4847e7):goto kg_pc_4847e7;
case UINT64_C(0x4847eb):goto kg_pc_4847eb;
case UINT64_C(0x4847ef):goto kg_pc_4847ef;
case UINT64_C(0x4847f7):goto kg_pc_4847f7;
case UINT64_C(0x4847f9):goto kg_pc_4847f9;
case UINT64_C(0x484800):goto kg_pc_484800;
case UINT64_C(0x484804):goto kg_pc_484804;
case UINT64_C(0x48480b):goto kg_pc_48480b;
case UINT64_C(0x48480e):goto kg_pc_48480e;
case UINT64_C(0x484811):goto kg_pc_484811;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5333: [0x4846c0,0x484813), 76 instructions. */
kg_pc_4846c0: STEP(0x4846c0); /* xor r12d, r12d */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[12] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4846c3: STEP(0x4846c3); /* cmp r14d, 0x30aa0244 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0x30aa0244);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_4846ca: STEP(0x4846ca); /* setb r12b */
s->gpr[12] = (s->gpr[12] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4846ce: STEP(0x4846ce); /* cmp edi, 0x60c83afd */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x60c83afd);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_4846d4: STEP(0x4846d4); /* mov eax, 0 */
s->gpr[0] = (uint32_t)(UINT64_C(0x0));
++s->steps;
kg_pc_4846d9: STEP(0x4846d9); /* movabs rcx, 0x100000000 */
s->gpr[2] = UINT64_C(0x100000000);
++s->steps;
kg_pc_4846e3: STEP(0x4846e3); /* cmovb rax, rcx */
s->gpr[0] = (condition(s, COND_B) ? s->gpr[2] : s->gpr[0]);
++s->steps;
kg_pc_4846e7: STEP(0x4846e7); /* mov edx, edi */
s->gpr[3] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_4846e9: STEP(0x4846e9); /* add rax, rdx */
x = s->gpr[0]; y = s->gpr[3];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4846ec: STEP(0x4846ec); /* lea rdx, [r10 + rax] */
s->gpr[3] = (UINT64_C(0x0) + s->gpr[10] + (s->gpr[0] * UINT64_C(0x1)));
++s->steps;
kg_pc_4846f0: STEP(0x4846f0); /* add rdx, -0x60c83afd */
x = s->gpr[3]; y = UINT64_C(0xffffffff9f37c503);
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4846f7: STEP(0x4846f7); /* mov rcx, qword ptr [rbp - 0x128] */
READ(a, (UINT64_C(0xfffffffffffffed8) + s->gpr[6]), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_4846fe: STEP(0x4846fe); /* movsxd rcx, dword ptr [rcx] */
READ(a, (UINT64_C(0x0) + s->gpr[2]), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484701: STEP(0x484701); /* mov rsi, qword ptr [rbp - 0x110] */
READ(a, (UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_484708: STEP(0x484708); /* mov rbx, qword ptr [rsi] */
READ(a, (UINT64_C(0x0) + s->gpr[4]), 8);
s->gpr[1] = a;
++s->steps;
kg_pc_48470b: STEP(0x48470b); /* mov rsi, rcx */
s->gpr[4] = s->gpr[2];
++s->steps;
kg_pc_48470e: STEP(0x48470e); /* and rsi, 0xffffffffdb1cd9f8 */
x = s->gpr[4]; y = UINT64_C(0xffffffffdb1cd9f8);
s->gpr[4] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_484715: STEP(0x484715); /* xor edx, dword ptr [rbx + rsi] */
READ(b, (UINT64_C(0x0) + s->gpr[1] + (s->gpr[4] * UINT64_C(0x1))), 4);
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = b;
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_484718: STEP(0x484718); /* and edx, 0x7fffffff */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x7fffffff);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_48471e: STEP(0x48471e); /* imul edx, edx, 0xa57ed9a7 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xa57ed9a7);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_484724: STEP(0x484724); /* mov esi, edx */
s->gpr[4] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_484726: STEP(0x484726); /* shr esi, 0x10 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[4] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_484729: STEP(0x484729); /* xor esi, edx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48472b: STEP(0x48472b); /* lea r15, [rax + r13] */
s->gpr[15] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[13] * UINT64_C(0x1)));
++s->steps;
kg_pc_48472f: STEP(0x48472f); /* add r15, -0x60c83afd */
x = s->gpr[15]; y = UINT64_C(0xffffffff9f37c503);
s->gpr[15] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_484736: STEP(0x484736); /* imul r8d, esi, 0xa57ed9a7 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xa57ed9a7);
s->gpr[8] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_48473d: STEP(0x48473d); /* and rcx, 0xffffffff846a5610 */
x = s->gpr[2]; y = UINT64_C(0xffffffff846a5610);
s->gpr[2] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_484744: STEP(0x484744); /* mov ecx, dword ptr [rbx + rcx] */
READ(a, (UINT64_C(0x0) + s->gpr[1] + (s->gpr[2] * UINT64_C(0x1))), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
kg_pc_484747: STEP(0x484747); /* mov rsi, r8 */
s->gpr[4] = s->gpr[8];
++s->steps;
kg_pc_48474a: STEP(0x48474a); /* shr rsi, 0x18 */
x = s->gpr[4]; y = UINT64_C(0x18);
s->gpr[4] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_48474e: STEP(0x48474e); /* mov rbx, qword ptr [rbp - 0xd48] */
READ(a, (UINT64_C(0xfffffffffffff2b8) + s->gpr[6]), 8);
s->gpr[1] = a;
++s->steps;
kg_pc_484755: STEP(0x484755); /* movzx ebx, byte ptr [rbx + rsi] */
READ(a, (UINT64_C(0x0) + s->gpr[1] + (s->gpr[4] * UINT64_C(0x1))), 1);
s->gpr[1] = (uint32_t)(a);
++s->steps;
kg_pc_484759: STEP(0x484759); /* xor ecx, r15d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[15] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_48475c: STEP(0x48475c); /* and ecx, 0x7fffffff */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x7fffffff);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_484762: STEP(0x484762); /* imul ecx, ecx, 0xa57ed9a7 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xa57ed9a7);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_484768: STEP(0x484768); /* xor bl, byte ptr [r10 + rax - 0x60c83afd] */
READ(b, (UINT64_C(0xffffffff9f37c503) + s->gpr[10] + (s->gpr[0] * UINT64_C(0x1))), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_484770: STEP(0x484770); /* mov eax, ecx */
s->gpr[0] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_484772: STEP(0x484772); /* shr eax, 0x10 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_484775: STEP(0x484775); /* xor bl, byte ptr [rsi + r9 + 2] */
READ(b, (UINT64_C(0x2) + s->gpr[4] + (s->gpr[9] * UINT64_C(0x1))), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48477a: STEP(0x48477a); /* mov rdx, qword ptr [rbp - 0xd50] */
READ(a, (UINT64_C(0xfffffffffffff2b0) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_484781: STEP(0x484781); /* xor bl, byte ptr [rdx + rsi] */
READ(b, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x1))), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_484784: STEP(0x484784); /* xor eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_484786: STEP(0x484786); /* imul ecx, esi, -0x4b */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffffffffffb5);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_484789: STEP(0x484789); /* xor cl, r8b */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[8] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_48478c: STEP(0x48478c); /* imul eax, eax, 0xa57ed9a7 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xa57ed9a7);
s->gpr[0] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_484792: STEP(0x484792); /* xor cl, al */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_484794: STEP(0x484794); /* shr rax, 0x18 */
x = s->gpr[0]; y = UINT64_C(0x18);
s->gpr[0] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_484798: STEP(0x484798); /* mov rdx, qword ptr [rbp - 0x1a18] */
READ(a, (UINT64_C(0xffffffffffffe5e8) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_48479f: STEP(0x48479f); /* xor bl, byte ptr [rdx + rax] */
READ(b, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x1))), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4847a2: STEP(0x4847a2); /* mov rdx, qword ptr [rbp - 0x1d10] */
READ(a, (UINT64_C(0xffffffffffffe2f0) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_4847a9: STEP(0x4847a9); /* xor bl, byte ptr [rdx + rax] */
READ(b, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x1))), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4847ac: STEP(0x4847ac); /* mov rdx, qword ptr [rbp - 0x1a10] */
READ(a, (UINT64_C(0xffffffffffffe5f0) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_4847b3: STEP(0x4847b3); /* xor bl, byte ptr [rax + rdx + 3] */
READ(b, (UINT64_C(0x3) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x1))), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4847b7: STEP(0x4847b7); /* imul eax, eax, 0x69 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x69);
s->gpr[0] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_4847ba: STEP(0x4847ba); /* xor cl, al */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4847bc: STEP(0x4847bc); /* xor cl, bl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[1] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4847be: STEP(0x4847be); /* movabs rax, 0x8539528206b6dd45 */
s->gpr[0] = UINT64_C(0x8539528206b6dd45);
++s->steps;
kg_pc_4847c8: STEP(0x4847c8); /* mov byte ptr [rax + r15], cl */
WRITE((UINT64_C(0x0) + s->gpr[0] + (s->gpr[15] * UINT64_C(0x1))), 1, (s->gpr[2] & UINT64_C(0xff)));
++s->steps;
kg_pc_4847cc: STEP(0x4847cc); /* lea eax, [rdi - 0x301e38b8] */
s->gpr[0] = (uint32_t)((UINT64_C(0xffffffffcfe1c748) + s->gpr[5]));
++s->steps;
kg_pc_4847d2: STEP(0x4847d2); /* cmp eax, 0x30aa0244 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x30aa0244);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_4847d7: STEP(0x4847d7); /* setb cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4847da: STEP(0x4847da); /* xor cl, r12b */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[12] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4847dd: STEP(0x4847dd); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_4847df: STEP(0x4847df); /* cmp eax, r14d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_4847e2: STEP(0x4847e2); /* setb dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_B)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_4847e5: STEP(0x4847e5); /* test cl, cl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
(void)operation(s, OP_AND, x, y, 8);
++s->steps;
kg_pc_4847e7: STEP(0x4847e7); /* cmove r12d, edx */
s->gpr[12] = (uint32_t)((condition(s, COND_E) ? (s->gpr[3] & UINT64_C(0xffffffff)) : (s->gpr[12] & UINT64_C(0xffffffff))));
++s->steps;
kg_pc_4847eb: STEP(0x4847eb); /* movzx eax, r12b */
s->gpr[0] = (uint32_t)((s->gpr[12] & UINT64_C(0xff)));
++s->steps;
kg_pc_4847ef: STEP(0x4847ef); /* lea eax, [r11 + rax + 0x2155] */
s->gpr[0] = (uint32_t)((UINT64_C(0x2155) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_4847f7: STEP(0x4847f7); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_4847f9: STEP(0x4847f9); /* lea rcx, [rip - 0x47d4b0] */
s->gpr[2] = (UINT64_C(0xffffffffffb82b50) + (bias + UINT64_C(0x484800)));
++s->steps;
kg_pc_484800: STEP(0x484800); /* movsxd rax, dword ptr [rcx + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484804: STEP(0x484804); /* lea rcx, [rip - 0x14b] */
s->gpr[2] = (UINT64_C(0xfffffffffffffeb5) + (bias + UINT64_C(0x48480b)));
++s->steps;
kg_pc_48480b: STEP(0x48480b); /* add rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_48480e: STEP(0x48480e); /* add edi, 1 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x1);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_484811: STEP(0x484811); /* jmp rax */
x = s->gpr[0];
next_pc = x;
++s->steps;

break;
    case 95:
next_pc=bias+UINT64_C(0x484849);
switch(s->pc-bias){
case UINT64_C(0x484816):goto kg_pc_484816;
case UINT64_C(0x48481d):goto kg_pc_48481d;
case UINT64_C(0x484820):goto kg_pc_484820;
case UINT64_C(0x484827):goto kg_pc_484827;
case UINT64_C(0x48482b):goto kg_pc_48482b;
case UINT64_C(0x484832):goto kg_pc_484832;
case UINT64_C(0x484835):goto kg_pc_484835;
case UINT64_C(0x48483c):goto kg_pc_48483c;
case UINT64_C(0x484843):goto kg_pc_484843;
case UINT64_C(0x484847):goto kg_pc_484847;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5334: [0x484816,0x484849), 10 instructions. */
kg_pc_484816: STEP(0x484816); /* add r11d, 0x2154 */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = UINT64_C(0x2154);
s->gpr[11] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_48481d: STEP(0x48481d); /* movsxd rax, r11d */
s->gpr[0] = (((s->gpr[11] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484820: STEP(0x484820); /* lea rcx, [rip - 0x47d4d7] */
s->gpr[2] = (UINT64_C(0xffffffffffb82b29) + (bias + UINT64_C(0x484827)));
++s->steps;
kg_pc_484827: STEP(0x484827); /* movsxd rax, dword ptr [rcx + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_48482b: STEP(0x48482b); /* lea rcx, [rip - 0x1c] */
s->gpr[2] = (UINT64_C(0xffffffffffffffe4) + (bias + UINT64_C(0x484832)));
++s->steps;
kg_pc_484832: STEP(0x484832); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_484835: STEP(0x484835); /* mov r8, qword ptr [rbp - 0xb8] */
READ(a, (UINT64_C(0xffffffffffffff48) + s->gpr[6]), 8);
s->gpr[8] = a;
++s->steps;
kg_pc_48483c: STEP(0x48483c); /* mov r12, qword ptr [rbp - 0x3f0] */
READ(a, (UINT64_C(0xfffffffffffffc10) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_484843: STEP(0x484843); /* mov r15, qword ptr [rbp - 0x40] */
READ(a, (UINT64_C(0xffffffffffffffc0) + s->gpr[6]), 8);
s->gpr[15] = a;
++s->steps;
kg_pc_484847: STEP(0x484847); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 96:
next_pc=bias+UINT64_C(0x484a50);
switch(s->pc-bias){
case UINT64_C(0x484a43):goto kg_pc_484a43;
case UINT64_C(0x484a46):goto kg_pc_484a46;
case UINT64_C(0x484a4d):goto kg_pc_484a4d;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5335: [0x484a43,0x484a50), 3 instructions. */
kg_pc_484a43: STEP(0x484a43); /* mov r9d, r8d */
s->gpr[9] = (uint32_t)((s->gpr[8] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_484a46: STEP(0x484a46); /* lea r11, [rip - 0x47d6fd] */
s->gpr[11] = (UINT64_C(0xffffffffffb82903) + (bias + UINT64_C(0x484a4d)));
++s->steps;
kg_pc_484a4d: STEP(0x484a4d); /* jmp r15 */
x = s->gpr[15];
next_pc = x;
++s->steps;

break;
    case 97:
next_pc=bias+UINT64_C(0x484ac3);
switch(s->pc-bias){
case UINT64_C(0x484a99):goto kg_pc_484a99;
case UINT64_C(0x484aa0):goto kg_pc_484aa0;
case UINT64_C(0x484aa7):goto kg_pc_484aa7;
case UINT64_C(0x484aad):goto kg_pc_484aad;
case UINT64_C(0x484ab0):goto kg_pc_484ab0;
case UINT64_C(0x484ab4):goto kg_pc_484ab4;
case UINT64_C(0x484abb):goto kg_pc_484abb;
case UINT64_C(0x484abe):goto kg_pc_484abe;
case UINT64_C(0x484ac1):goto kg_pc_484ac1;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5336: [0x484a99,0x484ac3), 9 instructions. */
kg_pc_484a99: STEP(0x484a99); /* lea ebx, [r9 + 0xd0e] */
s->gpr[1] = (uint32_t)((UINT64_C(0xd0e) + s->gpr[9]));
++s->steps;
kg_pc_484aa0: STEP(0x484aa0); /* add r9d, 0xcff */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0xcff);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_484aa7: STEP(0x484aa7); /* mov eax, dword ptr [rbp - 0x3278] */
READ(a, (UINT64_C(0xffffffffffffcd88) + s->gpr[6]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_484aad: STEP(0x484aad); /* movsxd rcx, r9d */
s->gpr[2] = (((s->gpr[9] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484ab0: STEP(0x484ab0); /* movsxd rcx, dword ptr [r11 + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484ab4: STEP(0x484ab4); /* lea rdx, [rip - 0x22] */
s->gpr[3] = (UINT64_C(0xffffffffffffffde) + (bias + UINT64_C(0x484abb)));
++s->steps;
kg_pc_484abb: STEP(0x484abb); /* add rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_484abe: STEP(0x484abe); /* mov r10d, eax */
s->gpr[10] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_484ac1: STEP(0x484ac1); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    case 98:
next_pc=bias+UINT64_C(0x484af6);
switch(s->pc-bias){
case UINT64_C(0x484ac6):goto kg_pc_484ac6;
case UINT64_C(0x484ac9):goto kg_pc_484ac9;
case UINT64_C(0x484ad0):goto kg_pc_484ad0;
case UINT64_C(0x484ad2):goto kg_pc_484ad2;
case UINT64_C(0x484ad4):goto kg_pc_484ad4;
case UINT64_C(0x484ad7):goto kg_pc_484ad7;
case UINT64_C(0x484ada):goto kg_pc_484ada;
case UINT64_C(0x484add):goto kg_pc_484add;
case UINT64_C(0x484ae0):goto kg_pc_484ae0;
case UINT64_C(0x484ae3):goto kg_pc_484ae3;
case UINT64_C(0x484ae7):goto kg_pc_484ae7;
case UINT64_C(0x484aee):goto kg_pc_484aee;
case UINT64_C(0x484af1):goto kg_pc_484af1;
case UINT64_C(0x484af4):goto kg_pc_484af4;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5337: [0x484ac6,0x484af6), 14 instructions. */
kg_pc_484ac6: STEP(0x484ac6); /* mov rax, rbx */
s->gpr[0] = s->gpr[1];
++s->steps;
kg_pc_484ac9: STEP(0x484ac9); /* mov r8, qword ptr [rbp - 0x2e18] */
READ(a, (UINT64_C(0xffffffffffffd1e8) + s->gpr[6]), 8);
s->gpr[8] = a;
++s->steps;
kg_pc_484ad0: STEP(0x484ad0); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_484ad2: STEP(0x484ad2); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_484ad4: STEP(0x484ad4); /* test r8, r8 */
x = s->gpr[8]; y = s->gpr[8];
(void)operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_484ad7: STEP(0x484ad7); /* setne bl */
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_484ada: STEP(0x484ada); /* sete dl */
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_484add: STEP(0x484add); /* lea esi, [rdx + rax] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_484ae0: STEP(0x484ae0); /* movsxd rsi, esi */
s->gpr[4] = (((s->gpr[4] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484ae3: STEP(0x484ae3); /* movsxd rsi, dword ptr [r11 + rsi*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[4] * UINT64_C(0x4))), 4);
s->gpr[4] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484ae7: STEP(0x484ae7); /* lea rdi, [rip - 0x28] */
s->gpr[5] = (UINT64_C(0xffffffffffffffd8) + (bias + UINT64_C(0x484aee)));
++s->steps;
kg_pc_484aee: STEP(0x484aee); /* add rdi, rsi */
x = s->gpr[5]; y = s->gpr[4];
s->gpr[5] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_484af1: STEP(0x484af1); /* mov r14, r10 */
s->gpr[14] = s->gpr[10];
++s->steps;
kg_pc_484af4: STEP(0x484af4); /* jmp rdi */
x = s->gpr[5];
next_pc = x;
++s->steps;

break;
    case 99:
next_pc=bias+UINT64_C(0x484b57);
switch(s->pc-bias){
case UINT64_C(0x484af7):goto kg_pc_484af7;
case UINT64_C(0x484af9):goto kg_pc_484af9;
case UINT64_C(0x484aff):goto kg_pc_484aff;
case UINT64_C(0x484b02):goto kg_pc_484b02;
case UINT64_C(0x484b04):goto kg_pc_484b04;
case UINT64_C(0x484b0a):goto kg_pc_484b0a;
case UINT64_C(0x484b11):goto kg_pc_484b11;
case UINT64_C(0x484b13):goto kg_pc_484b13;
case UINT64_C(0x484b1d):goto kg_pc_484b1d;
case UINT64_C(0x484b1f):goto kg_pc_484b1f;
case UINT64_C(0x484b25):goto kg_pc_484b25;
case UINT64_C(0x484b2c):goto kg_pc_484b2c;
case UINT64_C(0x484b33):goto kg_pc_484b33;
case UINT64_C(0x484b35):goto kg_pc_484b35;
case UINT64_C(0x484b37):goto kg_pc_484b37;
case UINT64_C(0x484b3c):goto kg_pc_484b3c;
case UINT64_C(0x484b42):goto kg_pc_484b42;
case UINT64_C(0x484b44):goto kg_pc_484b44;
case UINT64_C(0x484b4a):goto kg_pc_484b4a;
case UINT64_C(0x484b51):goto kg_pc_484b51;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5338: [0x484af7,0x484b57), 20 instructions. */
kg_pc_484af7: STEP(0x484af7); /* mov cl, bl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((s->gpr[1] & UINT64_C(0xff))) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_484af9: STEP(0x484af9); /* imul edx, edx, 0xfffff2f2 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffff2f2);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_484aff: STEP(0x484aff); /* lea ebx, [rax + rcx*2] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x2))));
++s->steps;
kg_pc_484b02: STEP(0x484b02); /* add ebx, edx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_484b04: STEP(0x484b04); /* lea ecx, [rbx - 0xd17] */
s->gpr[2] = (uint32_t)((UINT64_C(0xfffffffffffff2e9) + s->gpr[1]));
++s->steps;
kg_pc_484b0a: STEP(0x484b0a); /* lea rdi, [rbp - 0x1f8] */
s->gpr[5] = (UINT64_C(0xfffffffffffffe08) + s->gpr[6]);
++s->steps;
kg_pc_484b11: STEP(0x484b11); /* mov edx, edi */
s->gpr[3] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_484b13: STEP(0x484b13); /* movabs rax, 0xd7cf669026532472 */
s->gpr[0] = UINT64_C(0xd7cf669026532472);
++s->steps;
kg_pc_484b1d: STEP(0x484b1d); /* xor edx, eax */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_484b1f: STEP(0x484b1f); /* imul edx, edx, 0x20bd8b7f */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x20bd8b7f);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_484b25: STEP(0x484b25); /* lea rsi, [rip - 0x2e4121] */
s->gpr[4] = (UINT64_C(0xffffffffffd1bedf) + (bias + UINT64_C(0x484b2c)));
++s->steps;
kg_pc_484b2c: STEP(0x484b2c); /* lea rax, [rip - 0x2e4094] */
s->gpr[0] = (UINT64_C(0xffffffffffd1bf6c) + (bias + UINT64_C(0x484b33)));
++s->steps;
kg_pc_484b33: STEP(0x484b33); /* sub eax, esi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_484b35: STEP(0x484b35); /* sub eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_484b37: STEP(0x484b37); /* add eax, 0x8fc */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x8fc);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_484b3c: STEP(0x484b3c); /* mov dword ptr [rbp - 0x1f8], eax */
WRITE((UINT64_C(0xfffffffffffffe08) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_484b42: STEP(0x484b42); /* xor ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_484b44: STEP(0x484b44); /* mov dword ptr [rbp - 0x1e8], ecx */
WRITE((UINT64_C(0xfffffffffffffe18) + s->gpr[6]), 4, (s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_484b4a: STEP(0x484b4a); /* mov qword ptr [rbp - 0x1f0], r8 */
WRITE((UINT64_C(0xfffffffffffffe10) + s->gpr[6]), 8, s->gpr[8]);
++s->steps;
kg_pc_484b51: STEP(0x484b51); /* call qword ptr [rbp - 0x458] */
READ(a, (UINT64_C(0xfffffffffffffba8) + s->gpr[6]), 8);
x = a;
y = s->gpr[7] - 8;
WRITE(y, 8, bias + UINT64_C(0x484b57));
s->gpr[7] = y;
next_pc = x;
++s->steps;

break;
    case 100:
next_pc=bias+UINT64_C(0x484b74);
switch(s->pc-bias){
case UINT64_C(0x484b57):goto kg_pc_484b57;
case UINT64_C(0x484b5a):goto kg_pc_484b5a;
case UINT64_C(0x484b61):goto kg_pc_484b61;
case UINT64_C(0x484b64):goto kg_pc_484b64;
case UINT64_C(0x484b68):goto kg_pc_484b68;
case UINT64_C(0x484b6f):goto kg_pc_484b6f;
case UINT64_C(0x484b72):goto kg_pc_484b72;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5339: [0x484b57,0x484b74), 7 instructions. */
kg_pc_484b57: STEP(0x484b57); /* mov r10, r14 */
s->gpr[10] = s->gpr[14];
++s->steps;
kg_pc_484b5a: STEP(0x484b5a); /* lea r11, [rip - 0x47d811] */
s->gpr[11] = (UINT64_C(0xffffffffffb827ef) + (bias + UINT64_C(0x484b61)));
++s->steps;
kg_pc_484b61: STEP(0x484b61); /* movsxd rax, ebx */
s->gpr[0] = (((s->gpr[1] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484b64: STEP(0x484b64); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_484b68: STEP(0x484b68); /* lea rcx, [rip - 0x78] */
s->gpr[2] = (UINT64_C(0xffffffffffffff88) + (bias + UINT64_C(0x484b6f)));
++s->steps;
kg_pc_484b6f: STEP(0x484b6f); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_484b72: STEP(0x484b72); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 101:
next_pc=bias+UINT64_C(0x484b9b);
switch(s->pc-bias){
case UINT64_C(0x484b76):goto kg_pc_484b76;
case UINT64_C(0x484b7d):goto kg_pc_484b7d;
case UINT64_C(0x484b84):goto kg_pc_484b84;
case UINT64_C(0x484b8b):goto kg_pc_484b8b;
case UINT64_C(0x484b92):goto kg_pc_484b92;
case UINT64_C(0x484b95):goto kg_pc_484b95;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5340: [0x484b76,0x484b9b), 6 instructions. */
kg_pc_484b76: STEP(0x484b76); /* mov r9, qword ptr [rbp - 0x2c8] */
READ(a, (UINT64_C(0xfffffffffffffd38) + s->gpr[6]), 8);
s->gpr[9] = a;
++s->steps;
kg_pc_484b7d: STEP(0x484b7d); /* lea rax, [r9 - 0xc0] */
s->gpr[0] = (UINT64_C(0xffffffffffffff40) + s->gpr[9]);
++s->steps;
kg_pc_484b84: STEP(0x484b84); /* mov qword ptr [rbp - 0x2c8], rax */
WRITE((UINT64_C(0xfffffffffffffd38) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_484b8b: STEP(0x484b8b); /* mov rdx, qword ptr [rbp - 0xb8] */
READ(a, (UINT64_C(0xffffffffffffff48) + s->gpr[6]), 8);
s->gpr[3] = a;
++s->steps;
kg_pc_484b92: STEP(0x484b92); /* mov r15d, edx */
s->gpr[15] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_484b95: STEP(0x484b95); /* jmp qword ptr [rbp - 0x24c0] */
READ(a, (UINT64_C(0xffffffffffffdb40) + s->gpr[6]), 8);
x = a;
next_pc = x;
++s->steps;

break;
    case 102:
next_pc=bias+UINT64_C(0x48771a);
switch(s->pc-bias){
case UINT64_C(0x4876be):goto kg_pc_4876be;
case UINT64_C(0x4876c8):goto kg_pc_4876c8;
case UINT64_C(0x4876cb):goto kg_pc_4876cb;
case UINT64_C(0x4876cf):goto kg_pc_4876cf;
case UINT64_C(0x4876d3):goto kg_pc_4876d3;
case UINT64_C(0x4876da):goto kg_pc_4876da;
case UINT64_C(0x4876dd):goto kg_pc_4876dd;
case UINT64_C(0x4876e4):goto kg_pc_4876e4;
case UINT64_C(0x4876eb):goto kg_pc_4876eb;
case UINT64_C(0x4876f2):goto kg_pc_4876f2;
case UINT64_C(0x4876f9):goto kg_pc_4876f9;
case UINT64_C(0x487700):goto kg_pc_487700;
case UINT64_C(0x487708):goto kg_pc_487708;
case UINT64_C(0x48770c):goto kg_pc_48770c;
case UINT64_C(0x487714):goto kg_pc_487714;
case UINT64_C(0x487718):goto kg_pc_487718;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 5341: [0x4876be,0x48771a), 16 instructions. */
kg_pc_4876be: STEP(0x4876be); /* movabs rsi, 0x9ce3f1aa6fd26c28 */
s->gpr[4] = UINT64_C(0x9ce3f1aa6fd26c28);
++s->steps;
kg_pc_4876c8: STEP(0x4876c8); /* movsxd rax, r14d */
s->gpr[0] = (((s->gpr[14] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4876cb: STEP(0x4876cb); /* add r14d, 7 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0x7);
s->gpr[14] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_4876cf: STEP(0x4876cf); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_4876d3: STEP(0x4876d3); /* lea rdx, [rip - 0x1c] */
s->gpr[3] = (UINT64_C(0xffffffffffffffe4) + (bias + UINT64_C(0x4876da)));
++s->steps;
kg_pc_4876da: STEP(0x4876da); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_4876dd: STEP(0x4876dd); /* lea rbx, [rip - 0x1cdc84] */
s->gpr[1] = (UINT64_C(0xffffffffffe3237c) + (bias + UINT64_C(0x4876e4)));
++s->steps;
kg_pc_4876e4: STEP(0x4876e4); /* lea rax, [rbp - 0x2d48] */
s->gpr[0] = (UINT64_C(0xffffffffffffd2b8) + s->gpr[6]);
++s->steps;
kg_pc_4876eb: STEP(0x4876eb); /* mov qword ptr [rbp - 0x90], rax */
WRITE((UINT64_C(0xffffffffffffff70) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_4876f2: STEP(0x4876f2); /* lea rax, [rip + 0x2a81e] */
s->gpr[0] = (UINT64_C(0x2a81e) + (bias + UINT64_C(0x4876f9)));
++s->steps;
kg_pc_4876f9: STEP(0x4876f9); /* mov qword ptr [rbp - 0xb0], rax */
WRITE((UINT64_C(0xffffffffffffff50) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_487700: STEP(0x487700); /* movdqa xmm4, xmmword ptr [rip - 0x484008] */
READ(x, (UINT64_C(0xffffffffffb7bff8) + (bias + UINT64_C(0x487708))), 8);
READ(y, (UINT64_C(0xffffffffffb7bff8) + (bias + UINT64_C(0x487708))) + UINT64_C(8), 8);
v0 = (kg_vec){x,y};
fs->xmm[4] = v0;
++s->steps;
kg_pc_487708: STEP(0x487708); /* pcmpeqd xmm3, xmm3 */
v0 = fs->xmm[3];
v1 = fs->xmm[3];
fs->xmm[3] = kg_simd(KG_SIMD_PCMPEQD,v0,v1,0,fs->xmm[0]);
++s->steps;
kg_pc_48770c: STEP(0x48770c); /* movdqa xmm0, xmmword ptr [rip - 0x485834] */
READ(x, (UINT64_C(0xffffffffffb7a7cc) + (bias + UINT64_C(0x487714))), 8);
READ(y, (UINT64_C(0xffffffffffb7a7cc) + (bias + UINT64_C(0x487714))) + UINT64_C(8), 8);
v0 = (kg_vec){x,y};
fs->xmm[0] = v0;
++s->steps;
kg_pc_487714: STEP(0x487714); /* pxor xmm2, xmm2 */
v0 = fs->xmm[2];
v1 = fs->xmm[2];
fs->xmm[2] = kg_simd(KG_SIMD_PXOR,v0,v1,0,fs->xmm[0]);
++s->steps;
kg_pc_487718: STEP(0x487718); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
    default:return WRAPPER_KG_PAYLOAD_INVALID;
    }
    NATIVE_DONE;
}
