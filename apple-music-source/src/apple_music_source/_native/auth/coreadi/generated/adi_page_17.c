#include "../internal.h"
int adi_adi_page_17(unsigned block,uint64_t bias,wrapper_kg_native_state *fs,const wrapper_kg_payload_region *regions,size_t count,size_t max_steps){
NATIVE_LOCALS;
switch(block){
case 0:
next_pc=bias+UINT64_C(0x170612);
switch(s->pc-bias){
case UINT64_C(0x1702e4):goto pc_1702e4;
case UINT64_C(0x1702e9):goto pc_1702e9;
case UINT64_C(0x1702ee):goto pc_1702ee;
case UINT64_C(0x1702f3):goto pc_1702f3;
case UINT64_C(0x1702f7):goto pc_1702f7;
case UINT64_C(0x1702fa):goto pc_1702fa;
case UINT64_C(0x1702fd):goto pc_1702fd;
case UINT64_C(0x170307):goto pc_170307;
case UINT64_C(0x17030a):goto pc_17030a;
case UINT64_C(0x170310):goto pc_170310;
case UINT64_C(0x170316):goto pc_170316;
case UINT64_C(0x17031c):goto pc_17031c;
case UINT64_C(0x17031f):goto pc_17031f;
case UINT64_C(0x170322):goto pc_170322;
case UINT64_C(0x170325):goto pc_170325;
case UINT64_C(0x170329):goto pc_170329;
case UINT64_C(0x17032c):goto pc_17032c;
case UINT64_C(0x170331):goto pc_170331;
case UINT64_C(0x170333):goto pc_170333;
case UINT64_C(0x170335):goto pc_170335;
case UINT64_C(0x170337):goto pc_170337;
case UINT64_C(0x17033c):goto pc_17033c;
case UINT64_C(0x17033f):goto pc_17033f;
case UINT64_C(0x170342):goto pc_170342;
case UINT64_C(0x170347):goto pc_170347;
case UINT64_C(0x170351):goto pc_170351;
case UINT64_C(0x170354):goto pc_170354;
case UINT64_C(0x170359):goto pc_170359;
case UINT64_C(0x17035e):goto pc_17035e;
case UINT64_C(0x170362):goto pc_170362;
case UINT64_C(0x170365):goto pc_170365;
case UINT64_C(0x170368):goto pc_170368;
case UINT64_C(0x170372):goto pc_170372;
case UINT64_C(0x170375):goto pc_170375;
case UINT64_C(0x170378):goto pc_170378;
case UINT64_C(0x17037b):goto pc_17037b;
case UINT64_C(0x17037e):goto pc_17037e;
case UINT64_C(0x170381):goto pc_170381;
case UINT64_C(0x170385):goto pc_170385;
case UINT64_C(0x170388):goto pc_170388;
case UINT64_C(0x17038d):goto pc_17038d;
case UINT64_C(0x17038f):goto pc_17038f;
case UINT64_C(0x170391):goto pc_170391;
case UINT64_C(0x170393):goto pc_170393;
case UINT64_C(0x170398):goto pc_170398;
case UINT64_C(0x17039b):goto pc_17039b;
case UINT64_C(0x17039e):goto pc_17039e;
case UINT64_C(0x1703a3):goto pc_1703a3;
case UINT64_C(0x1703a8):goto pc_1703a8;
case UINT64_C(0x1703ad):goto pc_1703ad;
case UINT64_C(0x1703b1):goto pc_1703b1;
case UINT64_C(0x1703b4):goto pc_1703b4;
case UINT64_C(0x1703b7):goto pc_1703b7;
case UINT64_C(0x1703ba):goto pc_1703ba;
case UINT64_C(0x1703c4):goto pc_1703c4;
case UINT64_C(0x1703c7):goto pc_1703c7;
case UINT64_C(0x1703cb):goto pc_1703cb;
case UINT64_C(0x1703ce):goto pc_1703ce;
case UINT64_C(0x1703d3):goto pc_1703d3;
case UINT64_C(0x1703d5):goto pc_1703d5;
case UINT64_C(0x1703d7):goto pc_1703d7;
case UINT64_C(0x1703d9):goto pc_1703d9;
case UINT64_C(0x1703de):goto pc_1703de;
case UINT64_C(0x1703e1):goto pc_1703e1;
case UINT64_C(0x1703e4):goto pc_1703e4;
case UINT64_C(0x1703e9):goto pc_1703e9;
case UINT64_C(0x1703f3):goto pc_1703f3;
case UINT64_C(0x1703f6):goto pc_1703f6;
case UINT64_C(0x1703fb):goto pc_1703fb;
case UINT64_C(0x170400):goto pc_170400;
case UINT64_C(0x170404):goto pc_170404;
case UINT64_C(0x170407):goto pc_170407;
case UINT64_C(0x17040a):goto pc_17040a;
case UINT64_C(0x170414):goto pc_170414;
case UINT64_C(0x170418):goto pc_170418;
case UINT64_C(0x17041c):goto pc_17041c;
case UINT64_C(0x17041f):goto pc_17041f;
case UINT64_C(0x170424):goto pc_170424;
case UINT64_C(0x170426):goto pc_170426;
case UINT64_C(0x170428):goto pc_170428;
case UINT64_C(0x17042a):goto pc_17042a;
case UINT64_C(0x17042f):goto pc_17042f;
case UINT64_C(0x170432):goto pc_170432;
case UINT64_C(0x170435):goto pc_170435;
case UINT64_C(0x17043a):goto pc_17043a;
case UINT64_C(0x170444):goto pc_170444;
case UINT64_C(0x170447):goto pc_170447;
case UINT64_C(0x17044c):goto pc_17044c;
case UINT64_C(0x170451):goto pc_170451;
case UINT64_C(0x170455):goto pc_170455;
case UINT64_C(0x170458):goto pc_170458;
case UINT64_C(0x17045b):goto pc_17045b;
case UINT64_C(0x17045e):goto pc_17045e;
case UINT64_C(0x170461):goto pc_170461;
case UINT64_C(0x17046b):goto pc_17046b;
case UINT64_C(0x17046e):goto pc_17046e;
case UINT64_C(0x170471):goto pc_170471;
case UINT64_C(0x170473):goto pc_170473;
case UINT64_C(0x170476):goto pc_170476;
case UINT64_C(0x170478):goto pc_170478;
case UINT64_C(0x17047b):goto pc_17047b;
case UINT64_C(0x17047d):goto pc_17047d;
case UINT64_C(0x170480):goto pc_170480;
case UINT64_C(0x170483):goto pc_170483;
case UINT64_C(0x170487):goto pc_170487;
case UINT64_C(0x17048a):goto pc_17048a;
case UINT64_C(0x17048f):goto pc_17048f;
case UINT64_C(0x170491):goto pc_170491;
case UINT64_C(0x170493):goto pc_170493;
case UINT64_C(0x170495):goto pc_170495;
case UINT64_C(0x17049a):goto pc_17049a;
case UINT64_C(0x17049d):goto pc_17049d;
case UINT64_C(0x1704a0):goto pc_1704a0;
case UINT64_C(0x1704a5):goto pc_1704a5;
case UINT64_C(0x1704af):goto pc_1704af;
case UINT64_C(0x1704b2):goto pc_1704b2;
case UINT64_C(0x1704b7):goto pc_1704b7;
case UINT64_C(0x1704bc):goto pc_1704bc;
case UINT64_C(0x1704c0):goto pc_1704c0;
case UINT64_C(0x1704c3):goto pc_1704c3;
case UINT64_C(0x1704c6):goto pc_1704c6;
case UINT64_C(0x1704d0):goto pc_1704d0;
case UINT64_C(0x1704d4):goto pc_1704d4;
case UINT64_C(0x1704d8):goto pc_1704d8;
case UINT64_C(0x1704db):goto pc_1704db;
case UINT64_C(0x1704e0):goto pc_1704e0;
case UINT64_C(0x1704e2):goto pc_1704e2;
case UINT64_C(0x1704e4):goto pc_1704e4;
case UINT64_C(0x1704e6):goto pc_1704e6;
case UINT64_C(0x1704eb):goto pc_1704eb;
case UINT64_C(0x1704ee):goto pc_1704ee;
case UINT64_C(0x1704f1):goto pc_1704f1;
case UINT64_C(0x1704f6):goto pc_1704f6;
case UINT64_C(0x170500):goto pc_170500;
case UINT64_C(0x170503):goto pc_170503;
case UINT64_C(0x170508):goto pc_170508;
case UINT64_C(0x17050d):goto pc_17050d;
case UINT64_C(0x170511):goto pc_170511;
case UINT64_C(0x170514):goto pc_170514;
case UINT64_C(0x170517):goto pc_170517;
case UINT64_C(0x17051d):goto pc_17051d;
case UINT64_C(0x17051f):goto pc_17051f;
case UINT64_C(0x170522):goto pc_170522;
case UINT64_C(0x170524):goto pc_170524;
case UINT64_C(0x170527):goto pc_170527;
case UINT64_C(0x170531):goto pc_170531;
case UINT64_C(0x170534):goto pc_170534;
case UINT64_C(0x170537):goto pc_170537;
case UINT64_C(0x170539):goto pc_170539;
case UINT64_C(0x17053c):goto pc_17053c;
case UINT64_C(0x17053f):goto pc_17053f;
case UINT64_C(0x170543):goto pc_170543;
case UINT64_C(0x170546):goto pc_170546;
case UINT64_C(0x17054b):goto pc_17054b;
case UINT64_C(0x17054d):goto pc_17054d;
case UINT64_C(0x17054f):goto pc_17054f;
case UINT64_C(0x170551):goto pc_170551;
case UINT64_C(0x170556):goto pc_170556;
case UINT64_C(0x170559):goto pc_170559;
case UINT64_C(0x17055c):goto pc_17055c;
case UINT64_C(0x170561):goto pc_170561;
case UINT64_C(0x17056b):goto pc_17056b;
case UINT64_C(0x17056e):goto pc_17056e;
case UINT64_C(0x170573):goto pc_170573;
case UINT64_C(0x170578):goto pc_170578;
case UINT64_C(0x17057c):goto pc_17057c;
case UINT64_C(0x17057f):goto pc_17057f;
case UINT64_C(0x170582):goto pc_170582;
case UINT64_C(0x17058c):goto pc_17058c;
case UINT64_C(0x170590):goto pc_170590;
case UINT64_C(0x170594):goto pc_170594;
case UINT64_C(0x170597):goto pc_170597;
case UINT64_C(0x17059c):goto pc_17059c;
case UINT64_C(0x17059e):goto pc_17059e;
case UINT64_C(0x1705a0):goto pc_1705a0;
case UINT64_C(0x1705a2):goto pc_1705a2;
case UINT64_C(0x1705a7):goto pc_1705a7;
case UINT64_C(0x1705aa):goto pc_1705aa;
case UINT64_C(0x1705af):goto pc_1705af;
case UINT64_C(0x1705b9):goto pc_1705b9;
case UINT64_C(0x1705bc):goto pc_1705bc;
case UINT64_C(0x1705c1):goto pc_1705c1;
case UINT64_C(0x1705c6):goto pc_1705c6;
case UINT64_C(0x1705ca):goto pc_1705ca;
case UINT64_C(0x1705cd):goto pc_1705cd;
case UINT64_C(0x1705d0):goto pc_1705d0;
case UINT64_C(0x1705da):goto pc_1705da;
case UINT64_C(0x1705de):goto pc_1705de;
case UINT64_C(0x1705e2):goto pc_1705e2;
case UINT64_C(0x1705e5):goto pc_1705e5;
case UINT64_C(0x1705ea):goto pc_1705ea;
case UINT64_C(0x1705ec):goto pc_1705ec;
case UINT64_C(0x1705ee):goto pc_1705ee;
case UINT64_C(0x1705f0):goto pc_1705f0;
case UINT64_C(0x1705f5):goto pc_1705f5;
case UINT64_C(0x1705f8):goto pc_1705f8;
case UINT64_C(0x1705fb):goto pc_1705fb;
case UINT64_C(0x170600):goto pc_170600;
case UINT64_C(0x17060a):goto pc_17060a;
case UINT64_C(0x17060d):goto pc_17060d;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: b5b971cea0bbe828bdcfaf219fd91fc1e37cf8daee84001ef917d0b1c2b985ed
 * Path 1811: [0x1702e4,0x170612), 200 instructions. */
pc_1702e4: STEP(0x1702e4); /* add eax, 0x6f47f7fd */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x6f47f7fd);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_1702e9: STEP(0x1702e9); /* cmp eax, 0x2546f6ec */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x2546f6ec);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_1702ee: STEP(0x1702ee); /* mov ecx, 0 */
s->gpr[2] = (uint32_t)(UINT64_C(0x0));
++s->steps;
pc_1702f3: STEP(0x1702f3); /* cmovb rcx, r15 */
s->gpr[2] = (condition(s, COND_B) ? s->gpr[15] : s->gpr[2]);
++s->steps;
pc_1702f7: STEP(0x1702f7); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1702fa: STEP(0x1702fa); /* add rcx, rdi */
x = s->gpr[2]; y = s->gpr[5];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1702fd: STEP(0x1702fd); /* movabs rax, 0xbbd4e6301e8df7d7 */
s->gpr[0] = UINT64_C(0xbbd4e6301e8df7d7);
++s->steps;
pc_170307: STEP(0x170307); /* mov dl, byte ptr [rax + rcx] */
READ(a, (UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1))), 1);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17030a: STEP(0x17030a); /* add dl, byte ptr [rbp - 0x84] */
READ(b, (UINT64_C(0xffffffffffffff7c) + s->gpr[6]), 1);
x = (s->gpr[3] & UINT64_C(0xff)); y = b;
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170310: STEP(0x170310); /* add dl, byte ptr [rbp - 0x85] */
READ(b, (UINT64_C(0xffffffffffffff7b) + s->gpr[6]), 1);
x = (s->gpr[3] & UINT64_C(0xff)); y = b;
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170316: STEP(0x170316); /* sub dl, byte ptr [rbp - 0x8c] */
READ(b, (UINT64_C(0xffffffffffffff74) + s->gpr[6]), 1);
x = (s->gpr[3] & UINT64_C(0xff)); y = b;
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17031c: STEP(0x17031c); /* sub dl, byte ptr [rbp - 0x2a] */
READ(b, (UINT64_C(0xffffffffffffffd6) + s->gpr[6]), 1);
x = (s->gpr[3] & UINT64_C(0xff)); y = b;
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17031f: STEP(0x17031f); /* add dl, 0x45 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x45);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170322: STEP(0x170322); /* mov byte ptr [rax + rcx], dl */
WRITE((UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1))), 1, (s->gpr[3] & UINT64_C(0xff)));
++s->steps;
pc_170325: STEP(0x170325); /* mov ecx, dword ptr [r13] */
READ(a, (UINT64_C(0x0) + s->gpr[13]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
pc_170329: STEP(0x170329); /* add ecx, r10d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_17032c: STEP(0x17032c); /* mov eax, 0x14 */
s->gpr[0] = (uint32_t)(UINT64_C(0x14));
++s->steps;
pc_170331: STEP(0x170331); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170333: STEP(0x170333); /* div ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_170335: STEP(0x170335); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_170337: STEP(0x170337); /* xor eax, 0xffe5dfbe */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xffe5dfbe);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_17033c: STEP(0x17033c); /* and edx, 0x1e */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1e);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_17033f: STEP(0x17033f); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_170342: STEP(0x170342); /* add eax, 0x1fde26d0 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1fde26d0);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170347: STEP(0x170347); /* movabs rcx, 0x6d24b93e79080954 */
s->gpr[2] = UINT64_C(0x6d24b93e79080954);
++s->steps;
pc_170351: STEP(0x170351); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170354: STEP(0x170354); /* cmp eax, 0x1fc4068e */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1fc4068e);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_170359: STEP(0x170359); /* mov eax, 0 */
s->gpr[0] = (uint32_t)(UINT64_C(0x0));
++s->steps;
pc_17035e: STEP(0x17035e); /* cmovb rax, r15 */
s->gpr[0] = (condition(s, COND_B) ? s->gpr[15] : s->gpr[0]);
++s->steps;
pc_170362: STEP(0x170362); /* or rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_OR, x, y, 64);
++s->steps;
pc_170365: STEP(0x170365); /* add rax, rdi */
x = s->gpr[0]; y = s->gpr[5];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170368: STEP(0x170368); /* movabs rcx, 0x4eb02cf1ab08dee1 */
s->gpr[2] = UINT64_C(0x4eb02cf1ab08dee1);
++s->steps;
pc_170372: STEP(0x170372); /* mov dl, byte ptr [rcx + rax] */
READ(a, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x1))), 1);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170375: STEP(0x170375); /* add dl, byte ptr [rbp - 0x2e] */
READ(b, (UINT64_C(0xffffffffffffffd2) + s->gpr[6]), 1);
x = (s->gpr[3] & UINT64_C(0xff)); y = b;
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170378: STEP(0x170378); /* add dl, byte ptr [rbp - 0x2f] */
READ(b, (UINT64_C(0xffffffffffffffd1) + s->gpr[6]), 1);
x = (s->gpr[3] & UINT64_C(0xff)); y = b;
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17037b: STEP(0x17037b); /* add dl, 0x38 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x38);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17037e: STEP(0x17037e); /* mov byte ptr [rcx + rax], dl */
WRITE((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x1))), 1, (s->gpr[3] & UINT64_C(0xff)));
++s->steps;
pc_170381: STEP(0x170381); /* mov ecx, dword ptr [r13] */
READ(a, (UINT64_C(0x0) + s->gpr[13]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
pc_170385: STEP(0x170385); /* add ecx, r10d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170388: STEP(0x170388); /* mov eax, 0x15 */
s->gpr[0] = (uint32_t)(UINT64_C(0x15));
++s->steps;
pc_17038d: STEP(0x17038d); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_17038f: STEP(0x17038f); /* div ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_170391: STEP(0x170391); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_170393: STEP(0x170393); /* xor eax, 0x3c79dafb */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x3c79dafb);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170398: STEP(0x170398); /* and edx, 0x1b */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1b);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_17039b: STEP(0x17039b); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_17039e: STEP(0x17039e); /* add eax, 0xf7e7f778 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xf7e7f778);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_1703a3: STEP(0x1703a3); /* cmp eax, 0x3461d273 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x3461d273);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_1703a8: STEP(0x1703a8); /* mov ecx, 0 */
s->gpr[2] = (uint32_t)(UINT64_C(0x0));
++s->steps;
pc_1703ad: STEP(0x1703ad); /* cmovb rcx, r15 */
s->gpr[2] = (condition(s, COND_B) ? s->gpr[15] : s->gpr[2]);
++s->steps;
pc_1703b1: STEP(0x1703b1); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1703b4: STEP(0x1703b4); /* add rcx, rdi */
x = s->gpr[2]; y = s->gpr[5];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1703b7: STEP(0x1703b7); /* mov al, byte ptr [rbp - 0x36] */
READ(a, (UINT64_C(0xffffffffffffffca) + s->gpr[6]), 1);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1703ba: STEP(0x1703ba); /* movabs rdx, 0xbbd4e6300f731c50 */
s->gpr[3] = UINT64_C(0xbbd4e6300f731c50);
++s->steps;
pc_1703c4: STEP(0x1703c4); /* add byte ptr [rdx + rcx], al */
READ(a, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x1))), 1);
x = a; y = (s->gpr[0] & UINT64_C(0xff));
WRITE((UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x1))), 1, operation(s, OP_ADD, x, y, 8));
++s->steps;
pc_1703c7: STEP(0x1703c7); /* mov ecx, dword ptr [r13] */
READ(a, (UINT64_C(0x0) + s->gpr[13]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
pc_1703cb: STEP(0x1703cb); /* add ecx, r10d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_1703ce: STEP(0x1703ce); /* mov eax, 0x16 */
s->gpr[0] = (uint32_t)(UINT64_C(0x16));
++s->steps;
pc_1703d3: STEP(0x1703d3); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1703d5: STEP(0x1703d5); /* div ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_1703d7: STEP(0x1703d7); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_1703d9: STEP(0x1703d9); /* xor eax, 0x7eefed0f */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x7eefed0f);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1703de: STEP(0x1703de); /* and edx, 0xf */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xf);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_1703e1: STEP(0x1703e1); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_1703e4: STEP(0x1703e4); /* add eax, 0xbd7f4000 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xbd7f4000);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_1703e9: STEP(0x1703e9); /* movabs rcx, 0x16a6362a840b803d */
s->gpr[2] = UINT64_C(0x16a6362a840b803d);
++s->steps;
pc_1703f3: STEP(0x1703f3); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1703f6: STEP(0x1703f6); /* cmp eax, 0x3c6f2d0f */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x3c6f2d0f);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_1703fb: STEP(0x1703fb); /* mov eax, 0 */
s->gpr[0] = (uint32_t)(UINT64_C(0x0));
++s->steps;
pc_170400: STEP(0x170400); /* cmovb rax, r15 */
s->gpr[0] = (condition(s, COND_B) ? s->gpr[15] : s->gpr[0]);
++s->steps;
pc_170404: STEP(0x170404); /* or rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_OR, x, y, 64);
++s->steps;
pc_170407: STEP(0x170407); /* add rax, rdi */
x = s->gpr[0]; y = s->gpr[5];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_17040a: STEP(0x17040a); /* movabs rcx, 0xa52eb005835a4177 */
s->gpr[2] = UINT64_C(0xa52eb005835a4177);
++s->steps;
pc_170414: STEP(0x170414); /* add byte ptr [rcx + rax], 0x1f */
READ(a, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x1))), 1);
x = a; y = UINT64_C(0x1f);
WRITE((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x1))), 1, operation(s, OP_ADD, x, y, 8));
++s->steps;
pc_170418: STEP(0x170418); /* mov ecx, dword ptr [r13] */
READ(a, (UINT64_C(0x0) + s->gpr[13]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
pc_17041c: STEP(0x17041c); /* add ecx, r10d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_17041f: STEP(0x17041f); /* mov eax, 0x17 */
s->gpr[0] = (uint32_t)(UINT64_C(0x17));
++s->steps;
pc_170424: STEP(0x170424); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170426: STEP(0x170426); /* div ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_170428: STEP(0x170428); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_17042a: STEP(0x17042a); /* xor eax, 0x99fbbdef */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x99fbbdef);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_17042f: STEP(0x17042f); /* and edx, 0xf */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xf);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_170432: STEP(0x170432); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_170435: STEP(0x170435); /* add eax, 0x7f9def72 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x7f9def72);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_17043a: STEP(0x17043a); /* movabs rcx, 0x21ab96f282d76600 */
s->gpr[2] = UINT64_C(0x21ab96f282d76600);
++s->steps;
pc_170444: STEP(0x170444); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170447: STEP(0x170447); /* cmp eax, 0x1999ad61 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1999ad61);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_17044c: STEP(0x17044c); /* mov eax, 0 */
s->gpr[0] = (uint32_t)(UINT64_C(0x0));
++s->steps;
pc_170451: STEP(0x170451); /* cmovb rax, r15 */
s->gpr[0] = (condition(s, COND_B) ? s->gpr[15] : s->gpr[0]);
++s->steps;
pc_170455: STEP(0x170455); /* or rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_OR, x, y, 64);
++s->steps;
pc_170458: STEP(0x170458); /* add rax, rdi */
x = s->gpr[0]; y = s->gpr[5];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_17045b: STEP(0x17045b); /* mov cl, byte ptr [rbp - 0x35] */
READ(a, (UINT64_C(0xffffffffffffffcb) + s->gpr[6]), 1);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17045e: STEP(0x17045e); /* xor cl, 0xcb */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xcb);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170461: STEP(0x170461); /* movabs rdx, 0x9a294f3da763db62 */
s->gpr[3] = UINT64_C(0x9a294f3da763db62);
++s->steps;
pc_17046b: STEP(0x17046b); /* add cl, byte ptr [rdx + rax] */
READ(b, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x1))), 1);
x = (s->gpr[2] & UINT64_C(0xff)); y = b;
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17046e: STEP(0x17046e); /* add cl, 0xb2 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xb2);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170471: STEP(0x170471); /* mov ebx, ecx */
s->gpr[1] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
pc_170473: STEP(0x170473); /* xor bl, 0xfe */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0xfe);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170476: STEP(0x170476); /* add cl, cl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170478: STEP(0x170478); /* and cl, 0xfc */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xfc);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17047b: STEP(0x17047b); /* add cl, bl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[1] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17047d: STEP(0x17047d); /* add cl, 0x50 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x50);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170480: STEP(0x170480); /* mov byte ptr [rdx + rax], cl */
WRITE((UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x1))), 1, (s->gpr[2] & UINT64_C(0xff)));
++s->steps;
pc_170483: STEP(0x170483); /* mov ecx, dword ptr [r13] */
READ(a, (UINT64_C(0x0) + s->gpr[13]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
pc_170487: STEP(0x170487); /* add ecx, r10d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_17048a: STEP(0x17048a); /* mov eax, 0x18 */
s->gpr[0] = (uint32_t)(UINT64_C(0x18));
++s->steps;
pc_17048f: STEP(0x17048f); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170491: STEP(0x170491); /* div ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_170493: STEP(0x170493); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_170495: STEP(0x170495); /* xor eax, 0xbe577fdd */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xbe577fdd);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_17049a: STEP(0x17049a); /* and edx, 0x1d */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1d);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_17049d: STEP(0x17049d); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_1704a0: STEP(0x1704a0); /* add eax, 0x7bfbfb3c */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x7bfbfb3c);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_1704a5: STEP(0x1704a5); /* movabs rcx, 0x918fc0666af4593 */
s->gpr[2] = UINT64_C(0x918fc0666af4593);
++s->steps;
pc_1704af: STEP(0x1704af); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1704b2: STEP(0x1704b2); /* cmp eax, 0x3a537b19 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x3a537b19);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_1704b7: STEP(0x1704b7); /* mov eax, 0 */
s->gpr[0] = (uint32_t)(UINT64_C(0x0));
++s->steps;
pc_1704bc: STEP(0x1704bc); /* cmovb rax, r15 */
s->gpr[0] = (condition(s, COND_B) ? s->gpr[15] : s->gpr[0]);
++s->steps;
pc_1704c0: STEP(0x1704c0); /* or rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_OR, x, y, 64);
++s->steps;
pc_1704c3: STEP(0x1704c3); /* add rax, rdi */
x = s->gpr[0]; y = s->gpr[5];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1704c6: STEP(0x1704c6); /* movabs rcx, 0xb2bbea29a2d22e17 */
s->gpr[2] = UINT64_C(0xb2bbea29a2d22e17);
++s->steps;
pc_1704d0: STEP(0x1704d0); /* add byte ptr [rcx + rax], 0x71 */
READ(a, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x1))), 1);
x = a; y = UINT64_C(0x71);
WRITE((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x1))), 1, operation(s, OP_ADD, x, y, 8));
++s->steps;
pc_1704d4: STEP(0x1704d4); /* mov ecx, dword ptr [r13] */
READ(a, (UINT64_C(0x0) + s->gpr[13]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
pc_1704d8: STEP(0x1704d8); /* add ecx, r10d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_1704db: STEP(0x1704db); /* mov eax, 0x19 */
s->gpr[0] = (uint32_t)(UINT64_C(0x19));
++s->steps;
pc_1704e0: STEP(0x1704e0); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1704e2: STEP(0x1704e2); /* div ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_1704e4: STEP(0x1704e4); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_1704e6: STEP(0x1704e6); /* xor eax, 0x36e6f7f7 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x36e6f7f7);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1704eb: STEP(0x1704eb); /* and edx, 0x17 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x17);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_1704ee: STEP(0x1704ee); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_1704f1: STEP(0x1704f1); /* add eax, 0xffb9bf5b */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xffb9bf5b);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_1704f6: STEP(0x1704f6); /* movabs rcx, 0xe9c666aa21ca26 */
s->gpr[2] = UINT64_C(0xe9c666aa21ca26);
++s->steps;
pc_170500: STEP(0x170500); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170503: STEP(0x170503); /* cmp eax, 0x36a0b752 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x36a0b752);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_170508: STEP(0x170508); /* mov eax, 0 */
s->gpr[0] = (uint32_t)(UINT64_C(0x0));
++s->steps;
pc_17050d: STEP(0x17050d); /* cmovb rax, r15 */
s->gpr[0] = (condition(s, COND_B) ? s->gpr[15] : s->gpr[0]);
++s->steps;
pc_170511: STEP(0x170511); /* or rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_OR, x, y, 64);
++s->steps;
pc_170514: STEP(0x170514); /* add rax, rdi */
x = s->gpr[0]; y = s->gpr[5];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170517: STEP(0x170517); /* mov cl, byte ptr [rbp - 0x83] */
READ(a, (UINT64_C(0xffffffffffffff7d) + s->gpr[6]), 1);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17051d: STEP(0x17051d); /* mov edx, ecx */
s->gpr[3] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
pc_17051f: STEP(0x17051f); /* xor dl, 0x18 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x18);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170522: STEP(0x170522); /* add cl, cl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170524: STEP(0x170524); /* and cl, 0xfc */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xfc);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170527: STEP(0x170527); /* movabs rsi, 0xbaeb1fc963126d4b */
s->gpr[4] = UINT64_C(0xbaeb1fc963126d4b);
++s->steps;
pc_170531: STEP(0x170531); /* add dl, byte ptr [rsi + rax] */
READ(b, (UINT64_C(0x0) + s->gpr[4] + (s->gpr[0] * UINT64_C(0x1))), 1);
x = (s->gpr[3] & UINT64_C(0xff)); y = b;
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170534: STEP(0x170534); /* xor cl, 0xcc */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xcc);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170537: STEP(0x170537); /* add dl, cl */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170539: STEP(0x170539); /* add dl, 0x82 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x82);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17053c: STEP(0x17053c); /* mov byte ptr [rsi + rax], dl */
WRITE((UINT64_C(0x0) + s->gpr[4] + (s->gpr[0] * UINT64_C(0x1))), 1, (s->gpr[3] & UINT64_C(0xff)));
++s->steps;
pc_17053f: STEP(0x17053f); /* mov ecx, dword ptr [r13] */
READ(a, (UINT64_C(0x0) + s->gpr[13]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
pc_170543: STEP(0x170543); /* add ecx, r10d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170546: STEP(0x170546); /* mov eax, 0x1a */
s->gpr[0] = (uint32_t)(UINT64_C(0x1a));
++s->steps;
pc_17054b: STEP(0x17054b); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_17054d: STEP(0x17054d); /* div ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_17054f: STEP(0x17054f); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_170551: STEP(0x170551); /* xor eax, 0xfe1feefd */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xfe1feefd);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170556: STEP(0x170556); /* and edx, 0x1d */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1d);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_170559: STEP(0x170559); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_17055c: STEP(0x17055c); /* add eax, 0x19f59da7 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x19f59da7);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170561: STEP(0x170561); /* movabs rcx, 0x1f5a03b2de8acb9a */
s->gpr[2] = UINT64_C(0x1f5a03b2de8acb9a);
++s->steps;
pc_17056b: STEP(0x17056b); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_17056e: STEP(0x17056e); /* cmp eax, 0x18158ca4 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x18158ca4);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_170573: STEP(0x170573); /* mov eax, 0 */
s->gpr[0] = (uint32_t)(UINT64_C(0x0));
++s->steps;
pc_170578: STEP(0x170578); /* cmovb rax, r15 */
s->gpr[0] = (condition(s, COND_B) ? s->gpr[15] : s->gpr[0]);
++s->steps;
pc_17057c: STEP(0x17057c); /* or rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_OR, x, y, 64);
++s->steps;
pc_17057f: STEP(0x17057f); /* add rax, rdi */
x = s->gpr[0]; y = s->gpr[5];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170582: STEP(0x170582); /* movabs rcx, 0x9c7ae27d4d349685 */
s->gpr[2] = UINT64_C(0x9c7ae27d4d349685);
++s->steps;
pc_17058c: STEP(0x17058c); /* add byte ptr [rcx + rax], 0xfe */
READ(a, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x1))), 1);
x = a; y = UINT64_C(0xfe);
WRITE((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x1))), 1, operation(s, OP_ADD, x, y, 8));
++s->steps;
pc_170590: STEP(0x170590); /* mov ecx, dword ptr [r13] */
READ(a, (UINT64_C(0x0) + s->gpr[13]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
pc_170594: STEP(0x170594); /* add ecx, r10d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170597: STEP(0x170597); /* mov eax, 0x1b */
s->gpr[0] = (uint32_t)(UINT64_C(0x1b));
++s->steps;
pc_17059c: STEP(0x17059c); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_17059e: STEP(0x17059e); /* div ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_1705a0: STEP(0x1705a0); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_1705a2: STEP(0x1705a2); /* xor eax, 0xf585df7f */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xf585df7f);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1705a7: STEP(0x1705a7); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_1705aa: STEP(0x1705aa); /* add eax, 0x2bff6c97 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x2bff6c97);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_1705af: STEP(0x1705af); /* movabs rcx, 0xafdafd060305e03 */
s->gpr[2] = UINT64_C(0xafdafd060305e03);
++s->steps;
pc_1705b9: STEP(0x1705b9); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1705bc: STEP(0x1705bc); /* cmp eax, 0x21854c16 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x21854c16);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_1705c1: STEP(0x1705c1); /* mov eax, 0 */
s->gpr[0] = (uint32_t)(UINT64_C(0x0));
++s->steps;
pc_1705c6: STEP(0x1705c6); /* cmovb rax, r15 */
s->gpr[0] = (condition(s, COND_B) ? s->gpr[15] : s->gpr[0]);
++s->steps;
pc_1705ca: STEP(0x1705ca); /* or rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_OR, x, y, 64);
++s->steps;
pc_1705cd: STEP(0x1705cd); /* add rax, rdi */
x = s->gpr[0]; y = s->gpr[5];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1705d0: STEP(0x1705d0); /* movabs rcx, 0xb0d7365fc21f44aa */
s->gpr[2] = UINT64_C(0xb0d7365fc21f44aa);
++s->steps;
pc_1705da: STEP(0x1705da); /* add byte ptr [rcx + rax], 0x18 */
READ(a, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x1))), 1);
x = a; y = UINT64_C(0x18);
WRITE((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x1))), 1, operation(s, OP_ADD, x, y, 8));
++s->steps;
pc_1705de: STEP(0x1705de); /* mov ecx, dword ptr [r13] */
READ(a, (UINT64_C(0x0) + s->gpr[13]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
pc_1705e2: STEP(0x1705e2); /* add ecx, r10d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_1705e5: STEP(0x1705e5); /* mov eax, 0x1c */
s->gpr[0] = (uint32_t)(UINT64_C(0x1c));
++s->steps;
pc_1705ea: STEP(0x1705ea); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1705ec: STEP(0x1705ec); /* div ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_1705ee: STEP(0x1705ee); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_1705f0: STEP(0x1705f0); /* xor eax, 0x7ddfb797 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x7ddfb797);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1705f5: STEP(0x1705f5); /* and edx, 0x17 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x17);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_1705f8: STEP(0x1705f8); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_1705fb: STEP(0x1705fb); /* add eax, 0xd37eeffc */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xd37eeffc);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170600: STEP(0x170600); /* movabs rcx, 0x17e48198244c3058 */
s->gpr[2] = UINT64_C(0x17e48198244c3058);
++s->steps;
pc_17060a: STEP(0x17060a); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_17060d: STEP(0x17060d); /* cmp eax, 0x515ea793 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x515ea793);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;

break;
case 1:
next_pc=bias+UINT64_C(0x170781);
switch(s->pc-bias){
case UINT64_C(0x170612):goto pc_170612;
case UINT64_C(0x170617):goto pc_170617;
case UINT64_C(0x17061b):goto pc_17061b;
case UINT64_C(0x17061e):goto pc_17061e;
case UINT64_C(0x170621):goto pc_170621;
case UINT64_C(0x17062b):goto pc_17062b;
case UINT64_C(0x17062f):goto pc_17062f;
case UINT64_C(0x170634):goto pc_170634;
case UINT64_C(0x170638):goto pc_170638;
case UINT64_C(0x17063b):goto pc_17063b;
case UINT64_C(0x170640):goto pc_170640;
case UINT64_C(0x170642):goto pc_170642;
case UINT64_C(0x170644):goto pc_170644;
case UINT64_C(0x170646):goto pc_170646;
case UINT64_C(0x17064b):goto pc_17064b;
case UINT64_C(0x17064e):goto pc_17064e;
case UINT64_C(0x170651):goto pc_170651;
case UINT64_C(0x170656):goto pc_170656;
case UINT64_C(0x17065b):goto pc_17065b;
case UINT64_C(0x170660):goto pc_170660;
case UINT64_C(0x170664):goto pc_170664;
case UINT64_C(0x170667):goto pc_170667;
case UINT64_C(0x17066a):goto pc_17066a;
case UINT64_C(0x170674):goto pc_170674;
case UINT64_C(0x170677):goto pc_170677;
case UINT64_C(0x17067d):goto pc_17067d;
case UINT64_C(0x170683):goto pc_170683;
case UINT64_C(0x170686):goto pc_170686;
case UINT64_C(0x170689):goto pc_170689;
case UINT64_C(0x17068d):goto pc_17068d;
case UINT64_C(0x170690):goto pc_170690;
case UINT64_C(0x170695):goto pc_170695;
case UINT64_C(0x170697):goto pc_170697;
case UINT64_C(0x170699):goto pc_170699;
case UINT64_C(0x17069b):goto pc_17069b;
case UINT64_C(0x1706a0):goto pc_1706a0;
case UINT64_C(0x1706a3):goto pc_1706a3;
case UINT64_C(0x1706a6):goto pc_1706a6;
case UINT64_C(0x1706ab):goto pc_1706ab;
case UINT64_C(0x1706b0):goto pc_1706b0;
case UINT64_C(0x1706b5):goto pc_1706b5;
case UINT64_C(0x1706b9):goto pc_1706b9;
case UINT64_C(0x1706bc):goto pc_1706bc;
case UINT64_C(0x1706bf):goto pc_1706bf;
case UINT64_C(0x1706c9):goto pc_1706c9;
case UINT64_C(0x1706cc):goto pc_1706cc;
case UINT64_C(0x1706cf):goto pc_1706cf;
case UINT64_C(0x1706d2):goto pc_1706d2;
case UINT64_C(0x1706d5):goto pc_1706d5;
case UINT64_C(0x1706d8):goto pc_1706d8;
case UINT64_C(0x1706dc):goto pc_1706dc;
case UINT64_C(0x1706df):goto pc_1706df;
case UINT64_C(0x1706e4):goto pc_1706e4;
case UINT64_C(0x1706e6):goto pc_1706e6;
case UINT64_C(0x1706e8):goto pc_1706e8;
case UINT64_C(0x1706ea):goto pc_1706ea;
case UINT64_C(0x1706ef):goto pc_1706ef;
case UINT64_C(0x1706f2):goto pc_1706f2;
case UINT64_C(0x1706f5):goto pc_1706f5;
case UINT64_C(0x1706fa):goto pc_1706fa;
case UINT64_C(0x170704):goto pc_170704;
case UINT64_C(0x170707):goto pc_170707;
case UINT64_C(0x17070c):goto pc_17070c;
case UINT64_C(0x170710):goto pc_170710;
case UINT64_C(0x170713):goto pc_170713;
case UINT64_C(0x170716):goto pc_170716;
case UINT64_C(0x17071c):goto pc_17071c;
case UINT64_C(0x17071e):goto pc_17071e;
case UINT64_C(0x170721):goto pc_170721;
case UINT64_C(0x170723):goto pc_170723;
case UINT64_C(0x170725):goto pc_170725;
case UINT64_C(0x17072f):goto pc_17072f;
case UINT64_C(0x170733):goto pc_170733;
case UINT64_C(0x170735):goto pc_170735;
case UINT64_C(0x170737):goto pc_170737;
case UINT64_C(0x17073a):goto pc_17073a;
case UINT64_C(0x17073e):goto pc_17073e;
case UINT64_C(0x170749):goto pc_170749;
case UINT64_C(0x17074c):goto pc_17074c;
case UINT64_C(0x170750):goto pc_170750;
case UINT64_C(0x170757):goto pc_170757;
case UINT64_C(0x17075a):goto pc_17075a;
case UINT64_C(0x170764):goto pc_170764;
case UINT64_C(0x170768):goto pc_170768;
case UINT64_C(0x17076f):goto pc_17076f;
case UINT64_C(0x170772):goto pc_170772;
case UINT64_C(0x170775):goto pc_170775;
case UINT64_C(0x17077f):goto pc_17077f;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: b5b971cea0bbe828bdcfaf219fd91fc1e37cf8daee84001ef917d0b1c2b985ed
 * Path 1812: [0x170612,0x170781), 88 instructions. */
pc_170612: STEP(0x170612); /* mov eax, 0 */
s->gpr[0] = (uint32_t)(UINT64_C(0x0));
++s->steps;
pc_170617: STEP(0x170617); /* cmovb rax, r15 */
s->gpr[0] = (condition(s, COND_B) ? s->gpr[15] : s->gpr[0]);
++s->steps;
pc_17061b: STEP(0x17061b); /* or rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_OR, x, y, 64);
++s->steps;
pc_17061e: STEP(0x17061e); /* add rax, rdi */
x = s->gpr[0]; y = s->gpr[5];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170621: STEP(0x170621); /* movabs rcx, 0xa3f06497ce2a16d8 */
s->gpr[2] = UINT64_C(0xa3f06497ce2a16d8);
++s->steps;
pc_17062b: STEP(0x17062b); /* add byte ptr [rcx + rax], 0xd0 */
READ(a, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x1))), 1);
x = a; y = UINT64_C(0xd0);
WRITE((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x1))), 1, operation(s, OP_ADD, x, y, 8));
++s->steps;
pc_17062f: STEP(0x17062f); /* lea r14d, [r12 + 3] */
s->gpr[14] = (uint32_t)((UINT64_C(0x3) + s->gpr[12]));
++s->steps;
pc_170634: STEP(0x170634); /* mov esi, dword ptr [r13] */
READ(a, (UINT64_C(0x0) + s->gpr[13]), 4);
s->gpr[4] = (uint32_t)(a);
++s->steps;
pc_170638: STEP(0x170638); /* add esi, r10d */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_17063b: STEP(0x17063b); /* mov eax, 0x1d */
s->gpr[0] = (uint32_t)(UINT64_C(0x1d));
++s->steps;
pc_170640: STEP(0x170640); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170642: STEP(0x170642); /* div esi */
x = (s->gpr[4] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_170644: STEP(0x170644); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_170646: STEP(0x170646); /* xor eax, 0xeb6dff6d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xeb6dff6d);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_17064b: STEP(0x17064b); /* and edx, 0xd */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xd);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_17064e: STEP(0x17064e); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_170651: STEP(0x170651); /* add eax, 0x5fff3ff7 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x5fff3ff7);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170656: STEP(0x170656); /* cmp eax, 0x4b6d3f64 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x4b6d3f64);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_17065b: STEP(0x17065b); /* mov edx, 0 */
s->gpr[3] = (uint32_t)(UINT64_C(0x0));
++s->steps;
pc_170660: STEP(0x170660); /* cmovb rdx, r15 */
s->gpr[3] = (condition(s, COND_B) ? s->gpr[15] : s->gpr[3]);
++s->steps;
pc_170664: STEP(0x170664); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170667: STEP(0x170667); /* add rdx, rdi */
x = s->gpr[3]; y = s->gpr[5];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_17066a: STEP(0x17066a); /* movabs rax, 0xbbd4e62ff867af5f */
s->gpr[0] = UINT64_C(0xbbd4e62ff867af5f);
++s->steps;
pc_170674: STEP(0x170674); /* mov bl, byte ptr [rax + rdx] */
READ(a, (UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x1))), 1);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170677: STEP(0x170677); /* add bl, byte ptr [rbp - 0x8b] */
READ(b, (UINT64_C(0xffffffffffffff75) + s->gpr[6]), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17067d: STEP(0x17067d); /* add bl, byte ptr [rbp - 0x8a] */
READ(b, (UINT64_C(0xffffffffffffff76) + s->gpr[6]), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170683: STEP(0x170683); /* add bl, 0xbe */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0xbe);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170686: STEP(0x170686); /* mov byte ptr [rax + rdx], bl */
WRITE((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x1))), 1, (s->gpr[1] & UINT64_C(0xff)));
++s->steps;
pc_170689: STEP(0x170689); /* mov esi, dword ptr [r13] */
READ(a, (UINT64_C(0x0) + s->gpr[13]), 4);
s->gpr[4] = (uint32_t)(a);
++s->steps;
pc_17068d: STEP(0x17068d); /* add esi, r10d */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170690: STEP(0x170690); /* mov eax, 0x1e */
s->gpr[0] = (uint32_t)(UINT64_C(0x1e));
++s->steps;
pc_170695: STEP(0x170695); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170697: STEP(0x170697); /* div esi */
x = (s->gpr[4] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_170699: STEP(0x170699); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_17069b: STEP(0x17069b); /* xor eax, 0x9efdcede */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x9efdcede);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1706a0: STEP(0x1706a0); /* and edx, 0x1e */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1e);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_1706a3: STEP(0x1706a3); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_1706a6: STEP(0x1706a6); /* add eax, 0x790eb1be */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x790eb1be);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_1706ab: STEP(0x1706ab); /* cmp eax, 0x180c809c */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x180c809c);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_1706b0: STEP(0x1706b0); /* mov edx, 0 */
s->gpr[3] = (uint32_t)(UINT64_C(0x0));
++s->steps;
pc_1706b5: STEP(0x1706b5); /* cmovb rdx, r15 */
s->gpr[3] = (condition(s, COND_B) ? s->gpr[15] : s->gpr[3]);
++s->steps;
pc_1706b9: STEP(0x1706b9); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1706bc: STEP(0x1706bc); /* add rdx, rdi */
x = s->gpr[3]; y = s->gpr[5];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1706bf: STEP(0x1706bf); /* movabs rax, 0xbbd4e6302bc86e27 */
s->gpr[0] = UINT64_C(0xbbd4e6302bc86e27);
++s->steps;
pc_1706c9: STEP(0x1706c9); /* mov bl, byte ptr [rax + rdx] */
READ(a, (UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x1))), 1);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1706cc: STEP(0x1706cc); /* sub bl, byte ptr [rbp - 0x2c] */
READ(b, (UINT64_C(0xffffffffffffffd4) + s->gpr[6]), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1706cf: STEP(0x1706cf); /* sub bl, byte ptr [rbp - 0x29] */
READ(b, (UINT64_C(0xffffffffffffffd7) + s->gpr[6]), 1);
x = (s->gpr[1] & UINT64_C(0xff)); y = b;
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1706d2: STEP(0x1706d2); /* add bl, 0xc1 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0xc1);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1706d5: STEP(0x1706d5); /* mov byte ptr [rax + rdx], bl */
WRITE((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x1))), 1, (s->gpr[1] & UINT64_C(0xff)));
++s->steps;
pc_1706d8: STEP(0x1706d8); /* mov esi, dword ptr [r13] */
READ(a, (UINT64_C(0x0) + s->gpr[13]), 4);
s->gpr[4] = (uint32_t)(a);
++s->steps;
pc_1706dc: STEP(0x1706dc); /* add esi, r10d */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_1706df: STEP(0x1706df); /* mov eax, 0x1f */
s->gpr[0] = (uint32_t)(UINT64_C(0x1f));
++s->steps;
pc_1706e4: STEP(0x1706e4); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1706e6: STEP(0x1706e6); /* div esi */
x = (s->gpr[4] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_1706e8: STEP(0x1706e8); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_1706ea: STEP(0x1706ea); /* xor eax, 0x79edb7d7 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x79edb7d7);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1706ef: STEP(0x1706ef); /* and edx, 0x17 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x17);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_1706f2: STEP(0x1706f2); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_1706f5: STEP(0x1706f5); /* add eax, 0xbe3bdc2f */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xbe3bdc2f);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_1706fa: STEP(0x1706fa); /* movabs rdx, 0x857a74c30f6bcc4 */
s->gpr[3] = UINT64_C(0x857a74c30f6bcc4);
++s->steps;
pc_170704: STEP(0x170704); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170707: STEP(0x170707); /* cmp eax, 0x38299406 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x38299406);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_17070c: STEP(0x17070c); /* cmovb r8, r15 */
s->gpr[8] = (condition(s, COND_B) ? s->gpr[15] : s->gpr[8]);
++s->steps;
pc_170710: STEP(0x170710); /* or r8, rdx */
x = s->gpr[8]; y = s->gpr[3];
s->gpr[8] = operation(s, OP_OR, x, y, 64);
++s->steps;
pc_170713: STEP(0x170713); /* add r8, rdi */
x = s->gpr[8]; y = s->gpr[5];
s->gpr[8] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170716: STEP(0x170716); /* mov al, byte ptr [rbp - 0xe4] */
READ(a, (UINT64_C(0xffffffffffffff1c) + s->gpr[6]), 1);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((a) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17071c: STEP(0x17071c); /* mov edx, eax */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
pc_17071e: STEP(0x17071e); /* xor dl, 0x1d */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x1d);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170721: STEP(0x170721); /* add al, al */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170723: STEP(0x170723); /* and al, 0xf6 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xf6);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170725: STEP(0x170725); /* movabs rsi, 0xb37d3ee3dab49df9 */
s->gpr[4] = UINT64_C(0xb37d3ee3dab49df9);
++s->steps;
pc_17072f: STEP(0x17072f); /* add dl, byte ptr [rsi + r8] */
READ(b, (UINT64_C(0x0) + s->gpr[4] + (s->gpr[8] * UINT64_C(0x1))), 1);
x = (s->gpr[3] & UINT64_C(0xff)); y = b;
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170733: STEP(0x170733); /* xor al, 0xc4 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xc4);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170735: STEP(0x170735); /* add dl, al */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170737: STEP(0x170737); /* add dl, 0x85 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x85);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17073a: STEP(0x17073a); /* mov byte ptr [rsi + r8], dl */
WRITE((UINT64_C(0x0) + s->gpr[4] + (s->gpr[8] * UINT64_C(0x1))), 1, (s->gpr[3] & UINT64_C(0xff)));
++s->steps;
pc_17073e: STEP(0x17073e); /* mov qword ptr [rbp - 0x108], 0x542cae9 */
WRITE((UINT64_C(0xfffffffffffffef8) + s->gpr[6]), 8, UINT64_C(0x542cae9));
++s->steps;
pc_170749: STEP(0x170749); /* movsxd rax, r12d */
s->gpr[0] = (((s->gpr[12] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
pc_17074c: STEP(0x17074c); /* movsxd rax, dword ptr [r11 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
pc_170750: STEP(0x170750); /* lea rdx, [rip - 0xa9c] */
s->gpr[3] = (UINT64_C(0xfffffffffffff564) + (bias + UINT64_C(0x170757)));
++s->steps;
pc_170757: STEP(0x170757); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_17075a: STEP(0x17075a); /* movabs rsi, 0xbbd4e62fdf109952 */
s->gpr[4] = UINT64_C(0xbbd4e62fdf109952);
++s->steps;
pc_170764: STEP(0x170764); /* lea r8, [rbp - 0x80] */
s->gpr[8] = (UINT64_C(0xffffffffffffff80) + s->gpr[6]);
++s->steps;
pc_170768: STEP(0x170768); /* lea r9, [rip + 0x21] */
s->gpr[9] = (UINT64_C(0x21) + (bias + UINT64_C(0x17076f)));
++s->steps;
pc_17076f: STEP(0x17076f); /* mov r15, r11 */
s->gpr[15] = s->gpr[11];
++s->steps;
pc_170772: STEP(0x170772); /* mov r11, r13 */
s->gpr[11] = s->gpr[13];
++s->steps;
pc_170775: STEP(0x170775); /* movabs rcx, 0x100000000 */
s->gpr[2] = UINT64_C(0x100000000);
++s->steps;
pc_17077f: STEP(0x17077f); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
case 2:
next_pc=bias+UINT64_C(0x170825);
switch(s->pc-bias){
case UINT64_C(0x170790):goto pc_170790;
case UINT64_C(0x170797):goto pc_170797;
case UINT64_C(0x17079a):goto pc_17079a;
case UINT64_C(0x17079d):goto pc_17079d;
case UINT64_C(0x1707a3):goto pc_1707a3;
case UINT64_C(0x1707a5):goto pc_1707a5;
case UINT64_C(0x1707a7):goto pc_1707a7;
case UINT64_C(0x1707a9):goto pc_1707a9;
case UINT64_C(0x1707ae):goto pc_1707ae;
case UINT64_C(0x1707b4):goto pc_1707b4;
case UINT64_C(0x1707b7):goto pc_1707b7;
case UINT64_C(0x1707bc):goto pc_1707bc;
case UINT64_C(0x1707c1):goto pc_1707c1;
case UINT64_C(0x1707c6):goto pc_1707c6;
case UINT64_C(0x1707ca):goto pc_1707ca;
case UINT64_C(0x1707cd):goto pc_1707cd;
case UINT64_C(0x1707d4):goto pc_1707d4;
case UINT64_C(0x1707d8):goto pc_1707d8;
case UINT64_C(0x1707da):goto pc_1707da;
case UINT64_C(0x1707e2):goto pc_1707e2;
case UINT64_C(0x1707e4):goto pc_1707e4;
case UINT64_C(0x1707e7):goto pc_1707e7;
case UINT64_C(0x1707e9):goto pc_1707e9;
case UINT64_C(0x1707ec):goto pc_1707ec;
case UINT64_C(0x1707ef):goto pc_1707ef;
case UINT64_C(0x1707f3):goto pc_1707f3;
case UINT64_C(0x1707f5):goto pc_1707f5;
case UINT64_C(0x1707fc):goto pc_1707fc;
case UINT64_C(0x1707ff):goto pc_1707ff;
case UINT64_C(0x170802):goto pc_170802;
case UINT64_C(0x170809):goto pc_170809;
case UINT64_C(0x170814):goto pc_170814;
case UINT64_C(0x170817):goto pc_170817;
case UINT64_C(0x17081a):goto pc_17081a;
case UINT64_C(0x17081c):goto pc_17081c;
case UINT64_C(0x170820):goto pc_170820;
case UINT64_C(0x170823):goto pc_170823;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: b5b971cea0bbe828bdcfaf219fd91fc1e37cf8daee84001ef917d0b1c2b985ed
 * Path 1813: [0x170790,0x170825), 37 instructions. */
pc_170790: STEP(0x170790); /* mov rdi, qword ptr [rbp - 0x108] */
READ(a, (UINT64_C(0xfffffffffffffef8) + s->gpr[6]), 8);
s->gpr[5] = a;
++s->steps;
pc_170797: STEP(0x170797); /* mov ebx, dword ptr [r11] */
READ(a, (UINT64_C(0x0) + s->gpr[11]), 4);
s->gpr[1] = (uint32_t)(a);
++s->steps;
pc_17079a: STEP(0x17079a); /* add ebx, r10d */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_17079d: STEP(0x17079d); /* lea eax, [rdi - 0x542cae9] */
s->gpr[0] = (uint32_t)((UINT64_C(0xfffffffffabd3517) + s->gpr[5]));
++s->steps;
pc_1707a3: STEP(0x1707a3); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1707a5: STEP(0x1707a5); /* div ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_1707a7: STEP(0x1707a7); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_1707a9: STEP(0x1707a9); /* xor eax, 0xecccf5f5 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xecccf5f5);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1707ae: STEP(0x1707ae); /* and edx, 0xecccf5f5 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xecccf5f5);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_1707b4: STEP(0x1707b4); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_1707b7: STEP(0x1707b7); /* add eax, 0x77f75f7c */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x77f75f7c);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_1707bc: STEP(0x1707bc); /* cmp eax, 0x64c45571 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x64c45571);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_1707c1: STEP(0x1707c1); /* mov edx, 0 */
s->gpr[3] = (uint32_t)(UINT64_C(0x0));
++s->steps;
pc_1707c6: STEP(0x1707c6); /* cmovb rdx, rcx */
s->gpr[3] = (condition(s, COND_B) ? s->gpr[2] : s->gpr[3]);
++s->steps;
pc_1707ca: STEP(0x1707ca); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1707cd: STEP(0x1707cd); /* add rdx, qword ptr [rbp - 0xf0] */
READ(b, (UINT64_C(0xffffffffffffff10) + s->gpr[6]), 8);
x = s->gpr[3]; y = b;
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1707d4: STEP(0x1707d4); /* movzx eax, byte ptr [rsi + rdx] */
READ(a, (UINT64_C(0x0) + s->gpr[4] + (s->gpr[3] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
pc_1707d8: STEP(0x1707d8); /* add al, 0xb2 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xb2);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1707da: STEP(0x1707da); /* xor al, byte ptr [rdi + r8 - 0x542cae9] */
READ(b, (UINT64_C(0xfffffffffabd3517) + s->gpr[5] + (s->gpr[8] * UINT64_C(0x1))), 1);
x = (s->gpr[0] & UINT64_C(0xff)); y = b;
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1707e2: STEP(0x1707e2); /* xor al, 0x78 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x78);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1707e4: STEP(0x1707e4); /* lea ebx, [rax + rax] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
pc_1707e7: STEP(0x1707e7); /* sub bl, al */
x = (s->gpr[1] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1707e9: STEP(0x1707e9); /* add bl, 0x4e */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x4e);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1707ec: STEP(0x1707ec); /* mov byte ptr [rsi + rdx], bl */
WRITE((UINT64_C(0x0) + s->gpr[4] + (s->gpr[3] * UINT64_C(0x1))), 1, (s->gpr[1] & UINT64_C(0xff)));
++s->steps;
pc_1707ef: STEP(0x1707ef); /* add rdi, 1 */
x = s->gpr[5]; y = UINT64_C(0x1);
s->gpr[5] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1707f3: STEP(0x1707f3); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1707f5: STEP(0x1707f5); /* cmp rdi, 0x542cb29 */
x = s->gpr[5]; y = UINT64_C(0x542cb29);
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
pc_1707fc: STEP(0x1707fc); /* sete al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1707ff: STEP(0x1707ff); /* lea edx, [rax + rax] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
pc_170802: STEP(0x170802); /* mov qword ptr [rbp - 0x108], rdi */
WRITE((UINT64_C(0xfffffffffffffef8) + s->gpr[6]), 8, s->gpr[5]);
++s->steps;
pc_170809: STEP(0x170809); /* mov qword ptr [rbp - 0x110], 0x4d02558c */
WRITE((UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8, UINT64_C(0x4d02558c));
++s->steps;
pc_170814: STEP(0x170814); /* add eax, r14d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170817: STEP(0x170817); /* sub r14d, edx */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[14] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
pc_17081a: STEP(0x17081a); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
pc_17081c: STEP(0x17081c); /* movsxd rax, dword ptr [r15 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[15] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
pc_170820: STEP(0x170820); /* add rax, r9 */
x = s->gpr[0]; y = s->gpr[9];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170823: STEP(0x170823); /* jmp rax */
x = s->gpr[0];
next_pc = x;
++s->steps;

break;
case 3:
next_pc=bias+UINT64_C(0x1708f2);
switch(s->pc-bias){
case UINT64_C(0x170830):goto pc_170830;
case UINT64_C(0x170837):goto pc_170837;
case UINT64_C(0x17083d):goto pc_17083d;
case UINT64_C(0x170840):goto pc_170840;
case UINT64_C(0x170843):goto pc_170843;
case UINT64_C(0x170849):goto pc_170849;
case UINT64_C(0x17084b):goto pc_17084b;
case UINT64_C(0x17084d):goto pc_17084d;
case UINT64_C(0x17084f):goto pc_17084f;
case UINT64_C(0x170854):goto pc_170854;
case UINT64_C(0x17085a):goto pc_17085a;
case UINT64_C(0x17085d):goto pc_17085d;
case UINT64_C(0x170862):goto pc_170862;
case UINT64_C(0x170864):goto pc_170864;
case UINT64_C(0x170869):goto pc_170869;
case UINT64_C(0x170873):goto pc_170873;
case UINT64_C(0x170877):goto pc_170877;
case UINT64_C(0x17087a):goto pc_17087a;
case UINT64_C(0x170881):goto pc_170881;
case UINT64_C(0x17088b):goto pc_17088b;
case UINT64_C(0x170890):goto pc_170890;
case UINT64_C(0x170892):goto pc_170892;
case UINT64_C(0x170899):goto pc_170899;
case UINT64_C(0x1708a0):goto pc_1708a0;
case UINT64_C(0x1708a2):goto pc_1708a2;
case UINT64_C(0x1708a5):goto pc_1708a5;
case UINT64_C(0x1708a7):goto pc_1708a7;
case UINT64_C(0x1708a9):goto pc_1708a9;
case UINT64_C(0x1708ac):goto pc_1708ac;
case UINT64_C(0x1708ae):goto pc_1708ae;
case UINT64_C(0x1708b1):goto pc_1708b1;
case UINT64_C(0x1708b5):goto pc_1708b5;
case UINT64_C(0x1708b9):goto pc_1708b9;
case UINT64_C(0x1708bb):goto pc_1708bb;
case UINT64_C(0x1708c2):goto pc_1708c2;
case UINT64_C(0x1708c5):goto pc_1708c5;
case UINT64_C(0x1708c8):goto pc_1708c8;
case UINT64_C(0x1708cf):goto pc_1708cf;
case UINT64_C(0x1708da):goto pc_1708da;
case UINT64_C(0x1708dd):goto pc_1708dd;
case UINT64_C(0x1708e0):goto pc_1708e0;
case UINT64_C(0x1708e2):goto pc_1708e2;
case UINT64_C(0x1708e6):goto pc_1708e6;
case UINT64_C(0x1708ed):goto pc_1708ed;
case UINT64_C(0x1708f0):goto pc_1708f0;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: b5b971cea0bbe828bdcfaf219fd91fc1e37cf8daee84001ef917d0b1c2b985ed
 * Path 1814: [0x170830,0x1708f2), 45 instructions. */
pc_170830: STEP(0x170830); /* mov rsi, qword ptr [rbp - 0x110] */
READ(a, (UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
pc_170837: STEP(0x170837); /* mov r8d, 0xdb8d305a */
s->gpr[8] = (uint32_t)(UINT64_C(0xdb8d305a));
++s->steps;
pc_17083d: STEP(0x17083d); /* mov ebx, dword ptr [r11] */
READ(a, (UINT64_C(0x0) + s->gpr[11]), 4);
s->gpr[1] = (uint32_t)(a);
++s->steps;
pc_170840: STEP(0x170840); /* add ebx, r8d */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170843: STEP(0x170843); /* lea eax, [rsi - 0x4d02558c] */
s->gpr[0] = (uint32_t)((UINT64_C(0xffffffffb2fdaa74) + s->gpr[4]));
++s->steps;
pc_170849: STEP(0x170849); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_17084b: STEP(0x17084b); /* div ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_17084d: STEP(0x17084d); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_17084f: STEP(0x17084f); /* xor eax, 0xf76fde1c */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xf76fde1c);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170854: STEP(0x170854); /* and edx, 0xf76fde1c */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xf76fde1c);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_17085a: STEP(0x17085a); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_17085d: STEP(0x17085d); /* add eax, 0x38bbfbf0 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x38bbfbf0);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170862: STEP(0x170862); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170864: STEP(0x170864); /* cmp eax, 0x302bda0c */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x302bda0c);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_170869: STEP(0x170869); /* movabs rcx, 0x100000000 */
s->gpr[2] = UINT64_C(0x100000000);
++s->steps;
pc_170873: STEP(0x170873); /* cmovb rdx, rcx */
s->gpr[3] = (condition(s, COND_B) ? s->gpr[2] : s->gpr[3]);
++s->steps;
pc_170877: STEP(0x170877); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_17087a: STEP(0x17087a); /* add rdx, qword ptr [rbp - 0xf0] */
READ(b, (UINT64_C(0xffffffffffffff10) + s->gpr[6]), 8);
x = s->gpr[3]; y = b;
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170881: STEP(0x170881); /* movabs r9, 0xbbd4e63013a914b7 */
s->gpr[9] = UINT64_C(0xbbd4e63013a914b7);
++s->steps;
pc_17088b: STEP(0x17088b); /* movzx eax, byte ptr [r9 + rdx] */
READ(a, (UINT64_C(0x0) + s->gpr[9] + (s->gpr[3] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
pc_170890: STEP(0x170890); /* add al, 0xb2 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xb2);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170892: STEP(0x170892); /* lea rdi, [rbp - 0xd0] */
s->gpr[5] = (UINT64_C(0xffffffffffffff30) + s->gpr[6]);
++s->steps;
pc_170899: STEP(0x170899); /* xor al, byte ptr [rsi + rdi - 0x4d02558c] */
READ(b, (UINT64_C(0xffffffffb2fdaa74) + s->gpr[4] + (s->gpr[5] * UINT64_C(0x1))), 1);
x = (s->gpr[0] & UINT64_C(0xff)); y = b;
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1708a0: STEP(0x1708a0); /* mov ebx, eax */
s->gpr[1] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
pc_1708a2: STEP(0x1708a2); /* xor bl, 0x48 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x48);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1708a5: STEP(0x1708a5); /* xor al, 0xb7 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xb7);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1708a7: STEP(0x1708a7); /* add bl, bl */
x = (s->gpr[1] & UINT64_C(0xff)); y = (s->gpr[1] & UINT64_C(0xff));
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1708a9: STEP(0x1708a9); /* and bl, 0x9e */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x9e);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1708ac: STEP(0x1708ac); /* add bl, al */
x = (s->gpr[1] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1708ae: STEP(0x1708ae); /* add bl, 0x7f */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x7f);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1708b1: STEP(0x1708b1); /* mov byte ptr [r9 + rdx], bl */
WRITE((UINT64_C(0x0) + s->gpr[9] + (s->gpr[3] * UINT64_C(0x1))), 1, (s->gpr[1] & UINT64_C(0xff)));
++s->steps;
pc_1708b5: STEP(0x1708b5); /* add rsi, 1 */
x = s->gpr[4]; y = UINT64_C(0x1);
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1708b9: STEP(0x1708b9); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1708bb: STEP(0x1708bb); /* cmp rsi, 0x4d0255cc */
x = s->gpr[4]; y = UINT64_C(0x4d0255cc);
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
pc_1708c2: STEP(0x1708c2); /* sete al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_1708c5: STEP(0x1708c5); /* lea edx, [rax + rax*2] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
pc_1708c8: STEP(0x1708c8); /* mov qword ptr [rbp - 0x110], rsi */
WRITE((UINT64_C(0xfffffffffffffef0) + s->gpr[6]), 8, s->gpr[4]);
++s->steps;
pc_1708cf: STEP(0x1708cf); /* mov qword ptr [rbp - 0x118], 0x5bca7a77 */
WRITE((UINT64_C(0xfffffffffffffee8) + s->gpr[6]), 8, UINT64_C(0x5bca7a77));
++s->steps;
pc_1708da: STEP(0x1708da); /* add eax, r14d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_1708dd: STEP(0x1708dd); /* sub r14d, edx */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[14] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
pc_1708e0: STEP(0x1708e0); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
pc_1708e2: STEP(0x1708e2); /* movsxd rax, dword ptr [r15 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[15] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
pc_1708e6: STEP(0x1708e6); /* lea rdx, [rip - 0xbd] */
s->gpr[3] = (UINT64_C(0xffffffffffffff43) + (bias + UINT64_C(0x1708ed)));
++s->steps;
pc_1708ed: STEP(0x1708ed); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1708f0: STEP(0x1708f0); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
case 4:
next_pc=bias+UINT64_C(0x1709c3);
switch(s->pc-bias){
case UINT64_C(0x170900):goto pc_170900;
case UINT64_C(0x170907):goto pc_170907;
case UINT64_C(0x17090a):goto pc_17090a;
case UINT64_C(0x17090d):goto pc_17090d;
case UINT64_C(0x170913):goto pc_170913;
case UINT64_C(0x170915):goto pc_170915;
case UINT64_C(0x170917):goto pc_170917;
case UINT64_C(0x170919):goto pc_170919;
case UINT64_C(0x17091e):goto pc_17091e;
case UINT64_C(0x170924):goto pc_170924;
case UINT64_C(0x170927):goto pc_170927;
case UINT64_C(0x17092c):goto pc_17092c;
case UINT64_C(0x17092e):goto pc_17092e;
case UINT64_C(0x170933):goto pc_170933;
case UINT64_C(0x17093d):goto pc_17093d;
case UINT64_C(0x170941):goto pc_170941;
case UINT64_C(0x170944):goto pc_170944;
case UINT64_C(0x17094b):goto pc_17094b;
case UINT64_C(0x170955):goto pc_170955;
case UINT64_C(0x170959):goto pc_170959;
case UINT64_C(0x17095c):goto pc_17095c;
case UINT64_C(0x170963):goto pc_170963;
case UINT64_C(0x17096a):goto pc_17096a;
case UINT64_C(0x17096c):goto pc_17096c;
case UINT64_C(0x17096e):goto pc_17096e;
case UINT64_C(0x170971):goto pc_170971;
case UINT64_C(0x170973):goto pc_170973;
case UINT64_C(0x170975):goto pc_170975;
case UINT64_C(0x170977):goto pc_170977;
case UINT64_C(0x170979):goto pc_170979;
case UINT64_C(0x17097c):goto pc_17097c;
case UINT64_C(0x170980):goto pc_170980;
case UINT64_C(0x170982):goto pc_170982;
case UINT64_C(0x170989):goto pc_170989;
case UINT64_C(0x17098c):goto pc_17098c;
case UINT64_C(0x170994):goto pc_170994;
case UINT64_C(0x170997):goto pc_170997;
case UINT64_C(0x17099a):goto pc_17099a;
case UINT64_C(0x1709a1):goto pc_1709a1;
case UINT64_C(0x1709ab):goto pc_1709ab;
case UINT64_C(0x1709ae):goto pc_1709ae;
case UINT64_C(0x1709b0):goto pc_1709b0;
case UINT64_C(0x1709b4):goto pc_1709b4;
case UINT64_C(0x1709bb):goto pc_1709bb;
case UINT64_C(0x1709be):goto pc_1709be;
case UINT64_C(0x1709c1):goto pc_1709c1;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: b5b971cea0bbe828bdcfaf219fd91fc1e37cf8daee84001ef917d0b1c2b985ed
 * Path 1815: [0x170900,0x1709c3), 46 instructions. */
pc_170900: STEP(0x170900); /* mov rbx, qword ptr [rbp - 0x118] */
READ(a, (UINT64_C(0xfffffffffffffee8) + s->gpr[6]), 8);
s->gpr[1] = a;
++s->steps;
pc_170907: STEP(0x170907); /* mov esi, dword ptr [r11] */
READ(a, (UINT64_C(0x0) + s->gpr[11]), 4);
s->gpr[4] = (uint32_t)(a);
++s->steps;
pc_17090a: STEP(0x17090a); /* add esi, r8d */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_17090d: STEP(0x17090d); /* lea eax, [rbx - 0x5bca7a77] */
s->gpr[0] = (uint32_t)((UINT64_C(0xffffffffa4358589) + s->gpr[1]));
++s->steps;
pc_170913: STEP(0x170913); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170915: STEP(0x170915); /* div esi */
x = (s->gpr[4] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_170917: STEP(0x170917); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_170919: STEP(0x170919); /* xor eax, 0x63fbff97 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x63fbff97);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_17091e: STEP(0x17091e); /* and edx, 0xe3fbff97 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xe3fbff97);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_170924: STEP(0x170924); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_170927: STEP(0x170927); /* add eax, 0xfda7fd6c */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xfda7fd6c);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_17092c: STEP(0x17092c); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_17092e: STEP(0x17092e); /* cmp eax, 0x61a3fd03 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x61a3fd03);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_170933: STEP(0x170933); /* movabs rcx, 0x100000000 */
s->gpr[2] = UINT64_C(0x100000000);
++s->steps;
pc_17093d: STEP(0x17093d); /* cmovb rdx, rcx */
s->gpr[3] = (condition(s, COND_B) ? s->gpr[2] : s->gpr[3]);
++s->steps;
pc_170941: STEP(0x170941); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170944: STEP(0x170944); /* add rdx, qword ptr [rbp - 0xf0] */
READ(b, (UINT64_C(0xffffffffffffff10) + s->gpr[6]), 8);
x = s->gpr[3]; y = b;
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_17094b: STEP(0x17094b); /* movabs rsi, 0xbbd4e62fe230f1c0 */
s->gpr[4] = UINT64_C(0xbbd4e62fe230f1c0);
++s->steps;
pc_170955: STEP(0x170955); /* movzx ecx, byte ptr [rsi + rdx] */
READ(a, (UINT64_C(0x0) + s->gpr[4] + (s->gpr[3] * UINT64_C(0x1))), 1);
s->gpr[2] = (uint32_t)(a);
++s->steps;
pc_170959: STEP(0x170959); /* add cl, 0xb2 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xb2);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17095c: STEP(0x17095c); /* lea rax, [rbp - 0x290] */
s->gpr[0] = (UINT64_C(0xfffffffffffffd70) + s->gpr[6]);
++s->steps;
pc_170963: STEP(0x170963); /* xor cl, byte ptr [rbx + rax - 0x5bca7a77] */
READ(b, (UINT64_C(0xffffffffa4358589) + s->gpr[1] + (s->gpr[0] * UINT64_C(0x1))), 1);
x = (s->gpr[2] & UINT64_C(0xff)); y = b;
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17096a: STEP(0x17096a); /* mov eax, ecx */
s->gpr[0] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
pc_17096c: STEP(0x17096c); /* xor al, 0x68 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x68);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17096e: STEP(0x17096e); /* xor cl, 0x96 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x96);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170971: STEP(0x170971); /* add al, al */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170973: STEP(0x170973); /* and al, 0xdc */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xdc);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170975: STEP(0x170975); /* add al, cl */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170977: STEP(0x170977); /* add al, 0x60 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x60);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170979: STEP(0x170979); /* mov byte ptr [rsi + rdx], al */
WRITE((UINT64_C(0x0) + s->gpr[4] + (s->gpr[3] * UINT64_C(0x1))), 1, (s->gpr[0] & UINT64_C(0xff)));
++s->steps;
pc_17097c: STEP(0x17097c); /* add rbx, 1 */
x = s->gpr[1]; y = UINT64_C(0x1);
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170980: STEP(0x170980); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170982: STEP(0x170982); /* cmp rbx, 0x5bca7bbf */
x = s->gpr[1]; y = UINT64_C(0x5bca7bbf);
(void)operation(s, OP_SUB, x, y, 64);
++s->steps;
pc_170989: STEP(0x170989); /* sete al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_17098c: STEP(0x17098c); /* lea r13d, [rax*8] */
s->gpr[13] = (uint32_t)((UINT64_C(0x0) + (s->gpr[0] * UINT64_C(0x8))));
++s->steps;
pc_170994: STEP(0x170994); /* sub r13d, eax */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
pc_170997: STEP(0x170997); /* add r13d, r14d */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_17099a: STEP(0x17099a); /* mov qword ptr [rbp - 0x118], rbx */
WRITE((UINT64_C(0xfffffffffffffee8) + s->gpr[6]), 8, s->gpr[1]);
++s->steps;
pc_1709a1: STEP(0x1709a1); /* mov dword ptr [rbp - 0x130], 0x3306404b */
WRITE((UINT64_C(0xfffffffffffffed0) + s->gpr[6]), 4, UINT64_C(0x3306404b));
++s->steps;
pc_1709ab: STEP(0x1709ab); /* add eax, r14d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_1709ae: STEP(0x1709ae); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
pc_1709b0: STEP(0x1709b0); /* movsxd rax, dword ptr [r15 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[15] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
pc_1709b4: STEP(0x1709b4); /* lea rcx, [rip - 0xbb] */
s->gpr[2] = (UINT64_C(0xffffffffffffff45) + (bias + UINT64_C(0x1709bb)));
++s->steps;
pc_1709bb: STEP(0x1709bb); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_1709be: STEP(0x1709be); /* mov r14d, r13d */
s->gpr[14] = (uint32_t)((s->gpr[13] & UINT64_C(0xffffffff)));
++s->steps;
pc_1709c1: STEP(0x1709c1); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
case 5:
next_pc=bias+UINT64_C(0x170c4c);
switch(s->pc-bias){
case UINT64_C(0x1709d0):goto pc_1709d0;
case UINT64_C(0x1709d7):goto pc_1709d7;
case UINT64_C(0x1709da):goto pc_1709da;
case UINT64_C(0x1709e1):goto pc_1709e1;
case UINT64_C(0x1709e7):goto pc_1709e7;
case UINT64_C(0x1709e9):goto pc_1709e9;
case UINT64_C(0x1709eb):goto pc_1709eb;
case UINT64_C(0x1709ed):goto pc_1709ed;
case UINT64_C(0x1709f2):goto pc_1709f2;
case UINT64_C(0x1709f8):goto pc_1709f8;
case UINT64_C(0x1709fc):goto pc_1709fc;
case UINT64_C(0x1709ff):goto pc_1709ff;
case UINT64_C(0x170a02):goto pc_170a02;
case UINT64_C(0x170a07):goto pc_170a07;
case UINT64_C(0x170a0c):goto pc_170a0c;
case UINT64_C(0x170a12):goto pc_170a12;
case UINT64_C(0x170a15):goto pc_170a15;
case UINT64_C(0x170a1f):goto pc_170a1f;
case UINT64_C(0x170a23):goto pc_170a23;
case UINT64_C(0x170a26):goto pc_170a26;
case UINT64_C(0x170a2d):goto pc_170a2d;
case UINT64_C(0x170a37):goto pc_170a37;
case UINT64_C(0x170a3c):goto pc_170a3c;
case UINT64_C(0x170a41):goto pc_170a41;
case UINT64_C(0x170a43):goto pc_170a43;
case UINT64_C(0x170a45):goto pc_170a45;
case UINT64_C(0x170a47):goto pc_170a47;
case UINT64_C(0x170a4d):goto pc_170a4d;
case UINT64_C(0x170a4f):goto pc_170a4f;
case UINT64_C(0x170a52):goto pc_170a52;
case UINT64_C(0x170a56):goto pc_170a56;
case UINT64_C(0x170a5c):goto pc_170a5c;
case UINT64_C(0x170a5e):goto pc_170a5e;
case UINT64_C(0x170a60):goto pc_170a60;
case UINT64_C(0x170a62):goto pc_170a62;
case UINT64_C(0x170a67):goto pc_170a67;
case UINT64_C(0x170a69):goto pc_170a69;
case UINT64_C(0x170a6b):goto pc_170a6b;
case UINT64_C(0x170a6d):goto pc_170a6d;
case UINT64_C(0x170a72):goto pc_170a72;
case UINT64_C(0x170a78):goto pc_170a78;
case UINT64_C(0x170a7b):goto pc_170a7b;
case UINT64_C(0x170a80):goto pc_170a80;
case UINT64_C(0x170a85):goto pc_170a85;
case UINT64_C(0x170a8a):goto pc_170a8a;
case UINT64_C(0x170a8e):goto pc_170a8e;
case UINT64_C(0x170a91):goto pc_170a91;
case UINT64_C(0x170a98):goto pc_170a98;
case UINT64_C(0x170aa1):goto pc_170aa1;
case UINT64_C(0x170aa4):goto pc_170aa4;
case UINT64_C(0x170aa7):goto pc_170aa7;
case UINT64_C(0x170aa9):goto pc_170aa9;
case UINT64_C(0x170aab):goto pc_170aab;
case UINT64_C(0x170aad):goto pc_170aad;
case UINT64_C(0x170aaf):goto pc_170aaf;
case UINT64_C(0x170ab1):goto pc_170ab1;
case UINT64_C(0x170ab3):goto pc_170ab3;
case UINT64_C(0x170ab6):goto pc_170ab6;
case UINT64_C(0x170ab9):goto pc_170ab9;
case UINT64_C(0x170abb):goto pc_170abb;
case UINT64_C(0x170abe):goto pc_170abe;
case UINT64_C(0x170ac3):goto pc_170ac3;
case UINT64_C(0x170ac5):goto pc_170ac5;
case UINT64_C(0x170ac7):goto pc_170ac7;
case UINT64_C(0x170ac9):goto pc_170ac9;
case UINT64_C(0x170acf):goto pc_170acf;
case UINT64_C(0x170ad1):goto pc_170ad1;
case UINT64_C(0x170ad3):goto pc_170ad3;
case UINT64_C(0x170ad6):goto pc_170ad6;
case UINT64_C(0x170ad8):goto pc_170ad8;
case UINT64_C(0x170adb):goto pc_170adb;
case UINT64_C(0x170add):goto pc_170add;
case UINT64_C(0x170ae1):goto pc_170ae1;
case UINT64_C(0x170ae6):goto pc_170ae6;
case UINT64_C(0x170ae8):goto pc_170ae8;
case UINT64_C(0x170aea):goto pc_170aea;
case UINT64_C(0x170aec):goto pc_170aec;
case UINT64_C(0x170aef):goto pc_170aef;
case UINT64_C(0x170af4):goto pc_170af4;
case UINT64_C(0x170afa):goto pc_170afa;
case UINT64_C(0x170afd):goto pc_170afd;
case UINT64_C(0x170b02):goto pc_170b02;
case UINT64_C(0x170b05):goto pc_170b05;
case UINT64_C(0x170b0a):goto pc_170b0a;
case UINT64_C(0x170b0f):goto pc_170b0f;
case UINT64_C(0x170b13):goto pc_170b13;
case UINT64_C(0x170b16):goto pc_170b16;
case UINT64_C(0x170b1f):goto pc_170b1f;
case UINT64_C(0x170b21):goto pc_170b21;
case UINT64_C(0x170b24):goto pc_170b24;
case UINT64_C(0x170b26):goto pc_170b26;
case UINT64_C(0x170b29):goto pc_170b29;
case UINT64_C(0x170b2c):goto pc_170b2c;
case UINT64_C(0x170b2f):goto pc_170b2f;
case UINT64_C(0x170b32):goto pc_170b32;
case UINT64_C(0x170b35):goto pc_170b35;
case UINT64_C(0x170b39):goto pc_170b39;
case UINT64_C(0x170b3d):goto pc_170b3d;
case UINT64_C(0x170b3f):goto pc_170b3f;
case UINT64_C(0x170b42):goto pc_170b42;
case UINT64_C(0x170b45):goto pc_170b45;
case UINT64_C(0x170b4a):goto pc_170b4a;
case UINT64_C(0x170b4c):goto pc_170b4c;
case UINT64_C(0x170b4e):goto pc_170b4e;
case UINT64_C(0x170b50):goto pc_170b50;
case UINT64_C(0x170b55):goto pc_170b55;
case UINT64_C(0x170b57):goto pc_170b57;
case UINT64_C(0x170b59):goto pc_170b59;
case UINT64_C(0x170b5f):goto pc_170b5f;
case UINT64_C(0x170b61):goto pc_170b61;
case UINT64_C(0x170b67):goto pc_170b67;
case UINT64_C(0x170b6b):goto pc_170b6b;
case UINT64_C(0x170b6d):goto pc_170b6d;
case UINT64_C(0x170b6f):goto pc_170b6f;
case UINT64_C(0x170b71):goto pc_170b71;
case UINT64_C(0x170b73):goto pc_170b73;
case UINT64_C(0x170b78):goto pc_170b78;
case UINT64_C(0x170b7e):goto pc_170b7e;
case UINT64_C(0x170b81):goto pc_170b81;
case UINT64_C(0x170b86):goto pc_170b86;
case UINT64_C(0x170b8a):goto pc_170b8a;
case UINT64_C(0x170b8d):goto pc_170b8d;
case UINT64_C(0x170b90):goto pc_170b90;
case UINT64_C(0x170b94):goto pc_170b94;
case UINT64_C(0x170b99):goto pc_170b99;
case UINT64_C(0x170b9d):goto pc_170b9d;
case UINT64_C(0x170ba0):goto pc_170ba0;
case UINT64_C(0x170ba3):goto pc_170ba3;
case UINT64_C(0x170bac):goto pc_170bac;
case UINT64_C(0x170bae):goto pc_170bae;
case UINT64_C(0x170bb1):goto pc_170bb1;
case UINT64_C(0x170bb4):goto pc_170bb4;
case UINT64_C(0x170bb6):goto pc_170bb6;
case UINT64_C(0x170bb8):goto pc_170bb8;
case UINT64_C(0x170bbb):goto pc_170bbb;
case UINT64_C(0x170bbe):goto pc_170bbe;
case UINT64_C(0x170bc0):goto pc_170bc0;
case UINT64_C(0x170bc2):goto pc_170bc2;
case UINT64_C(0x170bc4):goto pc_170bc4;
case UINT64_C(0x170bc6):goto pc_170bc6;
case UINT64_C(0x170bc8):goto pc_170bc8;
case UINT64_C(0x170bcb):goto pc_170bcb;
case UINT64_C(0x170bcd):goto pc_170bcd;
case UINT64_C(0x170bd0):goto pc_170bd0;
case UINT64_C(0x170bd2):goto pc_170bd2;
case UINT64_C(0x170bd4):goto pc_170bd4;
case UINT64_C(0x170bd6):goto pc_170bd6;
case UINT64_C(0x170bd8):goto pc_170bd8;
case UINT64_C(0x170bdb):goto pc_170bdb;
case UINT64_C(0x170bdd):goto pc_170bdd;
case UINT64_C(0x170bdf):goto pc_170bdf;
case UINT64_C(0x170be2):goto pc_170be2;
case UINT64_C(0x170be4):goto pc_170be4;
case UINT64_C(0x170be6):goto pc_170be6;
case UINT64_C(0x170be9):goto pc_170be9;
case UINT64_C(0x170beb):goto pc_170beb;
case UINT64_C(0x170bed):goto pc_170bed;
case UINT64_C(0x170bf0):goto pc_170bf0;
case UINT64_C(0x170bf3):goto pc_170bf3;
case UINT64_C(0x170bf5):goto pc_170bf5;
case UINT64_C(0x170bf8):goto pc_170bf8;
case UINT64_C(0x170c02):goto pc_170c02;
case UINT64_C(0x170c06):goto pc_170c06;
case UINT64_C(0x170c0d):goto pc_170c0d;
case UINT64_C(0x170c11):goto pc_170c11;
case UINT64_C(0x170c13):goto pc_170c13;
case UINT64_C(0x170c1a):goto pc_170c1a;
case UINT64_C(0x170c1d):goto pc_170c1d;
case UINT64_C(0x170c20):goto pc_170c20;
case UINT64_C(0x170c27):goto pc_170c27;
case UINT64_C(0x170c2a):goto pc_170c2a;
case UINT64_C(0x170c2c):goto pc_170c2c;
case UINT64_C(0x170c30):goto pc_170c30;
case UINT64_C(0x170c37):goto pc_170c37;
case UINT64_C(0x170c3a):goto pc_170c3a;
case UINT64_C(0x170c44):goto pc_170c44;
case UINT64_C(0x170c47):goto pc_170c47;
case UINT64_C(0x170c4a):goto pc_170c4a;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: b5b971cea0bbe828bdcfaf219fd91fc1e37cf8daee84001ef917d0b1c2b985ed
 * Path 1816: [0x1709d0,0x170c4c), 178 instructions. */
pc_1709d0: STEP(0x1709d0); /* mov r10d, dword ptr [rbp - 0x130] */
READ(a, (UINT64_C(0xfffffffffffffed0) + s->gpr[6]), 4);
s->gpr[10] = (uint32_t)(a);
++s->steps;
pc_1709d7: STEP(0x1709d7); /* mov ecx, dword ptr [r11] */
READ(a, (UINT64_C(0x0) + s->gpr[11]), 4);
s->gpr[2] = (uint32_t)(a);
++s->steps;
pc_1709da: STEP(0x1709da); /* lea eax, [r10 - 0x3306404b] */
s->gpr[0] = (uint32_t)((UINT64_C(0xffffffffccf9bfb5) + s->gpr[10]));
++s->steps;
pc_1709e1: STEP(0x1709e1); /* lea edi, [rcx - 0x2472cfa6] */
s->gpr[5] = (uint32_t)((UINT64_C(0xffffffffdb8d305a) + s->gpr[2]));
++s->steps;
pc_1709e7: STEP(0x1709e7); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1709e9: STEP(0x1709e9); /* div edi */
x = (s->gpr[5] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_1709eb: STEP(0x1709eb); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_1709ed: STEP(0x1709ed); /* xor eax, 0x7ffffa36 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x7ffffa36);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1709f2: STEP(0x1709f2); /* and edx, 0xfffffa36 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffffa36);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_1709f8: STEP(0x1709f8); /* lea r8d, [rax + rdx*2] */
s->gpr[8] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_1709fc: STEP(0x1709fc); /* xor r15d, r15d */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = (s->gpr[15] & UINT64_C(0xffffffff));
s->gpr[15] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_1709ff: STEP(0x1709ff); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_170a02: STEP(0x170a02); /* add eax, 0xda43b000 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xda43b000);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170a07: STEP(0x170a07); /* cmp eax, 0x5a43aa36 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x5a43aa36);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_170a0c: STEP(0x170a0c); /* mov r12d, 0 */
s->gpr[12] = (uint32_t)(UINT64_C(0x0));
++s->steps;
pc_170a12: STEP(0x170a12); /* mov r14, r11 */
s->gpr[14] = s->gpr[11];
++s->steps;
pc_170a15: STEP(0x170a15); /* movabs r11, 0x100000000 */
s->gpr[11] = UINT64_C(0x100000000);
++s->steps;
pc_170a1f: STEP(0x170a1f); /* cmovb r12, r11 */
s->gpr[12] = (condition(s, COND_B) ? s->gpr[11] : s->gpr[12]);
++s->steps;
pc_170a23: STEP(0x170a23); /* add r12, rax */
x = s->gpr[12]; y = s->gpr[0];
s->gpr[12] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170a26: STEP(0x170a26); /* add r12, qword ptr [rbp - 0xf0] */
READ(b, (UINT64_C(0xffffffffffffff10) + s->gpr[6]), 8);
x = s->gpr[12]; y = b;
s->gpr[12] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170a2d: STEP(0x170a2d); /* movabs rax, 0xbbd4e62fe991448d */
s->gpr[0] = UINT64_C(0xbbd4e62fe991448d);
++s->steps;
pc_170a37: STEP(0x170a37); /* movzx ebx, byte ptr [rax + r12] */
READ(a, (UINT64_C(0x0) + s->gpr[0] + (s->gpr[12] * UINT64_C(0x1))), 1);
s->gpr[1] = (uint32_t)(a);
++s->steps;
pc_170a3c: STEP(0x170a3c); /* mov eax, 7 */
s->gpr[0] = (uint32_t)(UINT64_C(0x7));
++s->steps;
pc_170a41: STEP(0x170a41); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170a43: STEP(0x170a43); /* div edi */
x = (s->gpr[5] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_170a45: STEP(0x170a45); /* mov esi, edx */
s->gpr[4] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_170a47: STEP(0x170a47); /* xor esi, 0x3dfafbda */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x3dfafbda);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170a4d: STEP(0x170a4d); /* add edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170a4f: STEP(0x170a4f); /* and edx, 4 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x4);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_170a52: STEP(0x170a52); /* lea ecx, [rcx + r8] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[8] * UINT64_C(0x1))));
++s->steps;
pc_170a56: STEP(0x170a56); /* add ecx, 0xda43b000 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xda43b000);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170a5c: STEP(0x170a5c); /* mov eax, ecx */
s->gpr[0] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
pc_170a5e: STEP(0x170a5e); /* sub eax, esi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
pc_170a60: STEP(0x170a60); /* sub eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
pc_170a62: STEP(0x170a62); /* add eax, 0xbf4481fe */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xbf4481fe);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170a67: STEP(0x170a67); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170a69: STEP(0x170a69); /* div edi */
x = (s->gpr[5] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_170a6b: STEP(0x170a6b); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_170a6d: STEP(0x170a6d); /* xor eax, 0xdffafbdf */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xdffafbdf);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170a72: STEP(0x170a72); /* and edx, 0xdffafbdf */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xdffafbdf);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_170a78: STEP(0x170a78); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_170a7b: STEP(0x170a7b); /* add eax, 0x7b47cdf0 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x7b47cdf0);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170a80: STEP(0x170a80); /* cmp eax, 0x5b42c9cf */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x5b42c9cf);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_170a85: STEP(0x170a85); /* mov edx, 0 */
s->gpr[3] = (uint32_t)(UINT64_C(0x0));
++s->steps;
pc_170a8a: STEP(0x170a8a); /* cmovb rdx, r11 */
s->gpr[3] = (condition(s, COND_B) ? s->gpr[11] : s->gpr[3]);
++s->steps;
pc_170a8e: STEP(0x170a8e); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170a91: STEP(0x170a91); /* mov r8, qword ptr [rbp - 0x2a0] */
READ(a, (UINT64_C(0xfffffffffffffd60) + s->gpr[6]), 8);
s->gpr[8] = a;
++s->steps;
pc_170a98: STEP(0x170a98); /* movzx eax, byte ptr [r8 + rdx - 0x5b42c9cf] */
READ(a, (UINT64_C(0xffffffffa4bd3631) + s->gpr[8] + (s->gpr[3] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
pc_170aa1: STEP(0x170aa1); /* lea edx, [rax - 0x4e] */
s->gpr[3] = (uint32_t)((UINT64_C(0xffffffffffffffb2) + s->gpr[0]));
++s->steps;
pc_170aa4: STEP(0x170aa4); /* shr dl, 7 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x7);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170aa7: STEP(0x170aa7); /* add al, al */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170aa9: STEP(0x170aa9); /* add al, 0x64 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x64);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170aab: STEP(0x170aab); /* or dl, al */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_OR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170aad: STEP(0x170aad); /* add al, al */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170aaf: STEP(0x170aaf); /* and al, 0x70 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x70);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170ab1: STEP(0x170ab1); /* sub dl, al */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170ab3: STEP(0x170ab3); /* add bl, 0xb2 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0xb2);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170ab6: STEP(0x170ab6); /* add dl, 0x38 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x38);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170ab9: STEP(0x170ab9); /* xor bl, dl */
x = (s->gpr[1] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170abb: STEP(0x170abb); /* xor bl, 0x38 */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x38);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170abe: STEP(0x170abe); /* mov eax, 0x25 */
s->gpr[0] = (uint32_t)(UINT64_C(0x25));
++s->steps;
pc_170ac3: STEP(0x170ac3); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170ac5: STEP(0x170ac5); /* div edi */
x = (s->gpr[5] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_170ac7: STEP(0x170ac7); /* mov esi, edx */
s->gpr[4] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_170ac9: STEP(0x170ac9); /* xor esi, 0x7f62f6f3 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x7f62f6f3);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170acf: STEP(0x170acf); /* mov eax, ecx */
s->gpr[0] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
pc_170ad1: STEP(0x170ad1); /* sub eax, esi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
pc_170ad3: STEP(0x170ad3); /* lea esi, [rbx + rbx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[1] * UINT64_C(0x1))));
++s->steps;
pc_170ad6: STEP(0x170ad6); /* add edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170ad8: STEP(0x170ad8); /* and edx, 0x66 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x66);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_170adb: STEP(0x170adb); /* sub eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
pc_170add: STEP(0x170add); /* and sil, 0x34 */
x = (s->gpr[4] & UINT64_C(0xff)); y = UINT64_C(0x34);
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170ae1: STEP(0x170ae1); /* add eax, 0xac7d17 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xac7d17);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170ae6: STEP(0x170ae6); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170ae8: STEP(0x170ae8); /* div edi */
x = (s->gpr[5] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_170aea: STEP(0x170aea); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_170aec: STEP(0x170aec); /* sub bl, sil */
x = (s->gpr[1] & UINT64_C(0xff)); y = (s->gpr[4] & UINT64_C(0xff));
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170aef: STEP(0x170aef); /* xor eax, 0xe7f27fed */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xe7f27fed);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170af4: STEP(0x170af4); /* and edx, 0xe7f27fed */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xe7f27fed);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_170afa: STEP(0x170afa); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_170afd: STEP(0x170afd); /* add eax, 0x7a4fb800 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x7a4fb800);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170b02: STEP(0x170b02); /* add bl, 0x1a */
x = (s->gpr[1] & UINT64_C(0xff)); y = UINT64_C(0x1a);
s->gpr[1] = (s->gpr[1] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170b05: STEP(0x170b05); /* cmp eax, 0x624237ed */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x624237ed);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_170b0a: STEP(0x170b0a); /* mov edx, 0 */
s->gpr[3] = (uint32_t)(UINT64_C(0x0));
++s->steps;
pc_170b0f: STEP(0x170b0f); /* cmovb rdx, r11 */
s->gpr[3] = (condition(s, COND_B) ? s->gpr[11] : s->gpr[3]);
++s->steps;
pc_170b13: STEP(0x170b13); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170b16: STEP(0x170b16); /* movzx eax, byte ptr [r8 + rdx - 0x624237ed] */
READ(a, (UINT64_C(0xffffffff9dbdc813) + s->gpr[8] + (s->gpr[3] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
pc_170b1f: STEP(0x170b1f); /* mov edx, eax */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
pc_170b21: STEP(0x170b21); /* mov r9d, eax */
s->gpr[9] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
pc_170b24: STEP(0x170b24); /* add al, 0xb2 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xb2);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170b26: STEP(0x170b26); /* shr al, 2 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x2);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170b29: STEP(0x170b29); /* lea esi, [rax + rax] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
pc_170b2c: STEP(0x170b2c); /* sub al, sil */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[4] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170b2f: STEP(0x170b2f); /* shl dl, 6 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x6);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170b32: STEP(0x170b32); /* xor dl, 0x7d */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x7d);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170b35: STEP(0x170b35); /* shl r9b, 7 */
x = (s->gpr[9] & UINT64_C(0xff)); y = UINT64_C(0x7);
s->gpr[9] = (s->gpr[9] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170b39: STEP(0x170b39); /* or r9b, 3 */
x = (s->gpr[9] & UINT64_C(0xff)); y = UINT64_C(0x3);
s->gpr[9] = (s->gpr[9] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_OR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170b3d: STEP(0x170b3d); /* add al, 0x3f */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x3f);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170b3f: STEP(0x170b3f); /* add r9b, dl */
x = (s->gpr[9] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[9] = (s->gpr[9] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170b42: STEP(0x170b42); /* or r9b, al */
x = (s->gpr[9] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[9] = (s->gpr[9] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_OR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170b45: STEP(0x170b45); /* mov eax, 0xb1 */
s->gpr[0] = (uint32_t)(UINT64_C(0xb1));
++s->steps;
pc_170b4a: STEP(0x170b4a); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170b4c: STEP(0x170b4c); /* div edi */
x = (s->gpr[5] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_170b4e: STEP(0x170b4e); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_170b50: STEP(0x170b50); /* xor eax, 0xff137faf */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xff137faf);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170b55: STEP(0x170b55); /* sub ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
pc_170b57: STEP(0x170b57); /* add edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170b59: STEP(0x170b59); /* and edx, 0x15e */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x15e);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_170b5f: STEP(0x170b5f); /* sub ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
pc_170b61: STEP(0x170b61); /* add ecx, 0x805d05d3 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x805d05d3);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170b67: STEP(0x170b67); /* xor r9b, 0x3f */
x = (s->gpr[9] & UINT64_C(0xff)); y = UINT64_C(0x3f);
s->gpr[9] = (s->gpr[9] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170b6b: STEP(0x170b6b); /* mov eax, ecx */
s->gpr[0] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
pc_170b6d: STEP(0x170b6d); /* xor edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170b6f: STEP(0x170b6f); /* div edi */
x = (s->gpr[5] & UINT64_C(0xffffffff));
if(!divide(s, x, 32))return WRAPPER_KG_PAYLOAD_ARITH_FAULT;
++s->steps;
pc_170b71: STEP(0x170b71); /* mov eax, edx */
s->gpr[0] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_170b73: STEP(0x170b73); /* xor eax, 0x1a8effff */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1a8effff);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170b78: STEP(0x170b78); /* and edx, 0x1a8effff */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1a8effff);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_170b7e: STEP(0x170b7e); /* lea eax, [rax + rdx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
pc_170b81: STEP(0x170b81); /* add eax, 0xfffbdfb1 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xfffbdfb1);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170b86: STEP(0x170b86); /* lea ecx, [r9 + r9] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[9] + (s->gpr[9] * UINT64_C(0x1))));
++s->steps;
pc_170b8a: STEP(0x170b8a); /* and cl, 0xc8 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xc8);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170b8d: STEP(0x170b8d); /* sub r9b, cl */
x = (s->gpr[9] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[9] = (s->gpr[9] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170b90: STEP(0x170b90); /* add r9b, 0x64 */
x = (s->gpr[9] & UINT64_C(0xff)); y = UINT64_C(0x64);
s->gpr[9] = (s->gpr[9] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170b94: STEP(0x170b94); /* cmp eax, 0x1a8adfb0 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1a8adfb0);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_170b99: STEP(0x170b99); /* cmovb r15, r11 */
s->gpr[15] = (condition(s, COND_B) ? s->gpr[11] : s->gpr[15]);
++s->steps;
pc_170b9d: STEP(0x170b9d); /* mov r11, r14 */
s->gpr[11] = s->gpr[14];
++s->steps;
pc_170ba0: STEP(0x170ba0); /* add r15, rax */
x = s->gpr[15]; y = s->gpr[0];
s->gpr[15] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170ba3: STEP(0x170ba3); /* movzx eax, byte ptr [r8 + r15 - 0x1a8adfb0] */
READ(a, (UINT64_C(0xffffffffe5752050) + s->gpr[8] + (s->gpr[15] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
pc_170bac: STEP(0x170bac); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
pc_170bae: STEP(0x170bae); /* shl cl, 5 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x5);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHL, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bb1: STEP(0x170bb1); /* add cl, 0x40 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x40);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bb4: STEP(0x170bb4); /* add al, 0xb2 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xb2);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bb6: STEP(0x170bb6); /* mov edx, eax */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
pc_170bb8: STEP(0x170bb8); /* shr dl, 3 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x3);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bbb: STEP(0x170bbb); /* shr al, 2 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x2);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SHR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bbe: STEP(0x170bbe); /* and al, 8 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x8);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bc0: STEP(0x170bc0); /* sub dl, al */
x = (s->gpr[3] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bc2: STEP(0x170bc2); /* mov eax, ecx */
s->gpr[0] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
pc_170bc4: STEP(0x170bc4); /* xor al, 0xe7 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0xe7);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bc6: STEP(0x170bc6); /* add cl, cl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bc8: STEP(0x170bc8); /* or cl, 0x19 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x19);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_OR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bcb: STEP(0x170bcb); /* add cl, al */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bcd: STEP(0x170bcd); /* add dl, 4 */
x = (s->gpr[3] & UINT64_C(0xff)); y = UINT64_C(0x4);
s->gpr[3] = (s->gpr[3] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bd0: STEP(0x170bd0); /* or cl, dl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[3] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_OR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bd2: STEP(0x170bd2); /* mov eax, ecx */
s->gpr[0] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
pc_170bd4: STEP(0x170bd4); /* xor al, 4 */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x4);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bd6: STEP(0x170bd6); /* add cl, cl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bd8: STEP(0x170bd8); /* and cl, 0xb6 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xb6);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bdb: STEP(0x170bdb); /* sub al, cl */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_SUB, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bdd: STEP(0x170bdd); /* add al, 0x5b */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x5b);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bdf: STEP(0x170bdf); /* xor al, r9b */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[9] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170be2: STEP(0x170be2); /* xor al, bl */
x = (s->gpr[0] & UINT64_C(0xff)); y = (s->gpr[1] & UINT64_C(0xff));
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170be4: STEP(0x170be4); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
pc_170be6: STEP(0x170be6); /* xor cl, 6 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x6);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170be9: STEP(0x170be9); /* xor al, 0x4b */
x = (s->gpr[0] & UINT64_C(0xff)); y = UINT64_C(0x4b);
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170beb: STEP(0x170beb); /* add cl, cl */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[2] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bed: STEP(0x170bed); /* and cl, 0xdc */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xdc);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_AND, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bf0: STEP(0x170bf0); /* xor cl, 0x44 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0x44);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_XOR, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bf3: STEP(0x170bf3); /* add cl, al */
x = (s->gpr[2] & UINT64_C(0xff)); y = (s->gpr[0] & UINT64_C(0xff));
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bf5: STEP(0x170bf5); /* add cl, 0xe0 */
x = (s->gpr[2] & UINT64_C(0xff)); y = UINT64_C(0xe0);
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | (((operation(s, OP_ADD, x, y, 8)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170bf8: STEP(0x170bf8); /* movabs rax, 0xbbd4e62fe991448d */
s->gpr[0] = UINT64_C(0xbbd4e62fe991448d);
++s->steps;
pc_170c02: STEP(0x170c02); /* mov byte ptr [rax + r12], cl */
WRITE((UINT64_C(0x0) + s->gpr[0] + (s->gpr[12] * UINT64_C(0x1))), 1, (s->gpr[2] & UINT64_C(0xff)));
++s->steps;
pc_170c06: STEP(0x170c06); /* lea r12, [rip - 0x14b34d] */
s->gpr[12] = (UINT64_C(0xffffffffffeb4cb3) + (bias + UINT64_C(0x170c0d)));
++s->steps;
pc_170c0d: STEP(0x170c0d); /* add r10d, 1 */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x1);
s->gpr[10] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170c11: STEP(0x170c11); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170c13: STEP(0x170c13); /* cmp r10d, 0x3306414b */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x3306414b);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
pc_170c1a: STEP(0x170c1a); /* sete al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170c1d: STEP(0x170c1d); /* imul edx, eax, -0x1c */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffffffffffe4);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
pc_170c20: STEP(0x170c20); /* mov dword ptr [rbp - 0x130], r10d */
WRITE((UINT64_C(0xfffffffffffffed0) + s->gpr[6]), 4, (s->gpr[10] & UINT64_C(0xffffffff)));
++s->steps;
pc_170c27: STEP(0x170c27); /* add eax, r13d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[13] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170c2a: STEP(0x170c2a); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
pc_170c2c: STEP(0x170c2c); /* movsxd rax, dword ptr [r12 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[12] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
pc_170c30: STEP(0x170c30); /* lea rcx, [rip - 0x267] */
s->gpr[2] = (UINT64_C(0xfffffffffffffd99) + (bias + UINT64_C(0x170c37)));
++s->steps;
pc_170c37: STEP(0x170c37); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170c3a: STEP(0x170c3a); /* mov dword ptr [rbp - 0xd4], 0x7f3c7ec0 */
WRITE((UINT64_C(0xffffffffffffff2c) + s->gpr[6]), 4, UINT64_C(0x7f3c7ec0));
++s->steps;
pc_170c44: STEP(0x170c44); /* add edx, r13d */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[13] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
pc_170c47: STEP(0x170c47); /* mov r13d, edx */
s->gpr[13] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
pc_170c4a: STEP(0x170c4a); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
case 6:
next_pc=bias+UINT64_C(0x170c86);
switch(s->pc-bias){
case UINT64_C(0x170c4f):goto pc_170c4f;
case UINT64_C(0x170c56):goto pc_170c56;
case UINT64_C(0x170c59):goto pc_170c59;
case UINT64_C(0x170c5b):goto pc_170c5b;
case UINT64_C(0x170c5f):goto pc_170c5f;
case UINT64_C(0x170c66):goto pc_170c66;
case UINT64_C(0x170c69):goto pc_170c69;
case UINT64_C(0x170c70):goto pc_170c70;
case UINT64_C(0x170c76):goto pc_170c76;
case UINT64_C(0x170c7d):goto pc_170c7d;
case UINT64_C(0x170c84):goto pc_170c84;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: b5b971cea0bbe828bdcfaf219fd91fc1e37cf8daee84001ef917d0b1c2b985ed
 * Path 1817: [0x170c4f,0x170c86), 11 instructions. */
pc_170c4f: STEP(0x170c4f); /* mov qword ptr [rbp - 0x140], r11 */
WRITE((UINT64_C(0xfffffffffffffec0) + s->gpr[6]), 8, s->gpr[11]);
++s->steps;
pc_170c56: STEP(0x170c56); /* lea eax, [rdx + 0x14] */
s->gpr[0] = (uint32_t)((UINT64_C(0x14) + s->gpr[3]));
++s->steps;
pc_170c59: STEP(0x170c59); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
pc_170c5b: STEP(0x170c5b); /* movsxd rax, dword ptr [r12 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[12] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
pc_170c5f: STEP(0x170c5f); /* lea rcx, [rip - 0x17] */
s->gpr[2] = (UINT64_C(0xffffffffffffffe9) + (bias + UINT64_C(0x170c66)));
++s->steps;
pc_170c66: STEP(0x170c66); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170c69: STEP(0x170c69); /* lea r8, [rip - 0x49f0] */
s->gpr[8] = (UINT64_C(0xffffffffffffb610) + (bias + UINT64_C(0x170c70)));
++s->steps;
pc_170c70: STEP(0x170c70); /* mov r9d, 0xc7ce0c7d */
s->gpr[9] = (uint32_t)(UINT64_C(0xc7ce0c7d));
++s->steps;
pc_170c76: STEP(0x170c76); /* lea r10, [rip - 0x49d2] */
s->gpr[10] = (UINT64_C(0xffffffffffffb62e) + (bias + UINT64_C(0x170c7d)));
++s->steps;
pc_170c7d: STEP(0x170c7d); /* mov r15, qword ptr [rbp - 0x2c0] */
READ(a, (UINT64_C(0xfffffffffffffd40) + s->gpr[6]), 8);
s->gpr[15] = a;
++s->steps;
pc_170c84: STEP(0x170c84); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
case 7:
next_pc=bias+UINT64_C(0x170cfe);
switch(s->pc-bias){
case UINT64_C(0x170c88):goto pc_170c88;
case UINT64_C(0x170c8b):goto pc_170c8b;
case UINT64_C(0x170c8f):goto pc_170c8f;
case UINT64_C(0x170c92):goto pc_170c92;
case UINT64_C(0x170c96):goto pc_170c96;
case UINT64_C(0x170c99):goto pc_170c99;
case UINT64_C(0x170c9d):goto pc_170c9d;
case UINT64_C(0x170ca0):goto pc_170ca0;
case UINT64_C(0x170ca4):goto pc_170ca4;
case UINT64_C(0x170ca7):goto pc_170ca7;
case UINT64_C(0x170cab):goto pc_170cab;
case UINT64_C(0x170cae):goto pc_170cae;
case UINT64_C(0x170cb2):goto pc_170cb2;
case UINT64_C(0x170cb5):goto pc_170cb5;
case UINT64_C(0x170cb9):goto pc_170cb9;
case UINT64_C(0x170cbc):goto pc_170cbc;
case UINT64_C(0x170cc0):goto pc_170cc0;
case UINT64_C(0x170cc3):goto pc_170cc3;
case UINT64_C(0x170cc7):goto pc_170cc7;
case UINT64_C(0x170cca):goto pc_170cca;
case UINT64_C(0x170cce):goto pc_170cce;
case UINT64_C(0x170cd1):goto pc_170cd1;
case UINT64_C(0x170cd5):goto pc_170cd5;
case UINT64_C(0x170cd8):goto pc_170cd8;
case UINT64_C(0x170cdc):goto pc_170cdc;
case UINT64_C(0x170cdf):goto pc_170cdf;
case UINT64_C(0x170ce3):goto pc_170ce3;
case UINT64_C(0x170ce6):goto pc_170ce6;
case UINT64_C(0x170cea):goto pc_170cea;
case UINT64_C(0x170ced):goto pc_170ced;
case UINT64_C(0x170cf1):goto pc_170cf1;
case UINT64_C(0x170cf4):goto pc_170cf4;
case UINT64_C(0x170cf8):goto pc_170cf8;
case UINT64_C(0x170cfc):goto pc_170cfc;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: b5b971cea0bbe828bdcfaf219fd91fc1e37cf8daee84001ef917d0b1c2b985ed
 * Path 1818: [0x170c88,0x170cfe), 34 instructions. */
pc_170c88: STEP(0x170c88); /* mov rax, qword ptr [rbx] */
READ(a, (UINT64_C(0x0) + s->gpr[1]), 8);
s->gpr[0] = a;
++s->steps;
pc_170c8b: STEP(0x170c8b); /* add rbx, 8 */
x = s->gpr[1]; y = UINT64_C(0x8);
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170c8f: STEP(0x170c8f); /* mov qword ptr [rdx], rax */
WRITE((UINT64_C(0x0) + s->gpr[3]), 8, s->gpr[0]);
++s->steps;
pc_170c92: STEP(0x170c92); /* add rdx, 8 */
x = s->gpr[3]; y = UINT64_C(0x8);
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170c96: STEP(0x170c96); /* mov rax, qword ptr [rbx] */
READ(a, (UINT64_C(0x0) + s->gpr[1]), 8);
s->gpr[0] = a;
++s->steps;
pc_170c99: STEP(0x170c99); /* add rbx, 8 */
x = s->gpr[1]; y = UINT64_C(0x8);
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170c9d: STEP(0x170c9d); /* mov qword ptr [rdx], rax */
WRITE((UINT64_C(0x0) + s->gpr[3]), 8, s->gpr[0]);
++s->steps;
pc_170ca0: STEP(0x170ca0); /* add rdx, 8 */
x = s->gpr[3]; y = UINT64_C(0x8);
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170ca4: STEP(0x170ca4); /* mov rax, qword ptr [rbx] */
READ(a, (UINT64_C(0x0) + s->gpr[1]), 8);
s->gpr[0] = a;
++s->steps;
pc_170ca7: STEP(0x170ca7); /* add rbx, 8 */
x = s->gpr[1]; y = UINT64_C(0x8);
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170cab: STEP(0x170cab); /* mov qword ptr [rdx], rax */
WRITE((UINT64_C(0x0) + s->gpr[3]), 8, s->gpr[0]);
++s->steps;
pc_170cae: STEP(0x170cae); /* add rdx, 8 */
x = s->gpr[3]; y = UINT64_C(0x8);
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170cb2: STEP(0x170cb2); /* mov rax, qword ptr [rbx] */
READ(a, (UINT64_C(0x0) + s->gpr[1]), 8);
s->gpr[0] = a;
++s->steps;
pc_170cb5: STEP(0x170cb5); /* add rbx, 8 */
x = s->gpr[1]; y = UINT64_C(0x8);
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170cb9: STEP(0x170cb9); /* mov qword ptr [rdx], rax */
WRITE((UINT64_C(0x0) + s->gpr[3]), 8, s->gpr[0]);
++s->steps;
pc_170cbc: STEP(0x170cbc); /* add rdx, 8 */
x = s->gpr[3]; y = UINT64_C(0x8);
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170cc0: STEP(0x170cc0); /* mov rax, qword ptr [rbx] */
READ(a, (UINT64_C(0x0) + s->gpr[1]), 8);
s->gpr[0] = a;
++s->steps;
pc_170cc3: STEP(0x170cc3); /* add rbx, 8 */
x = s->gpr[1]; y = UINT64_C(0x8);
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170cc7: STEP(0x170cc7); /* mov qword ptr [rdx], rax */
WRITE((UINT64_C(0x0) + s->gpr[3]), 8, s->gpr[0]);
++s->steps;
pc_170cca: STEP(0x170cca); /* add rdx, 8 */
x = s->gpr[3]; y = UINT64_C(0x8);
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170cce: STEP(0x170cce); /* mov rax, qword ptr [rbx] */
READ(a, (UINT64_C(0x0) + s->gpr[1]), 8);
s->gpr[0] = a;
++s->steps;
pc_170cd1: STEP(0x170cd1); /* add rbx, 8 */
x = s->gpr[1]; y = UINT64_C(0x8);
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170cd5: STEP(0x170cd5); /* mov qword ptr [rdx], rax */
WRITE((UINT64_C(0x0) + s->gpr[3]), 8, s->gpr[0]);
++s->steps;
pc_170cd8: STEP(0x170cd8); /* add rdx, 8 */
x = s->gpr[3]; y = UINT64_C(0x8);
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170cdc: STEP(0x170cdc); /* mov rax, qword ptr [rbx] */
READ(a, (UINT64_C(0x0) + s->gpr[1]), 8);
s->gpr[0] = a;
++s->steps;
pc_170cdf: STEP(0x170cdf); /* add rbx, 8 */
x = s->gpr[1]; y = UINT64_C(0x8);
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170ce3: STEP(0x170ce3); /* mov qword ptr [rdx], rax */
WRITE((UINT64_C(0x0) + s->gpr[3]), 8, s->gpr[0]);
++s->steps;
pc_170ce6: STEP(0x170ce6); /* add rdx, 8 */
x = s->gpr[3]; y = UINT64_C(0x8);
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170cea: STEP(0x170cea); /* mov rax, qword ptr [rbx] */
READ(a, (UINT64_C(0x0) + s->gpr[1]), 8);
s->gpr[0] = a;
++s->steps;
pc_170ced: STEP(0x170ced); /* add rbx, 8 */
x = s->gpr[1]; y = UINT64_C(0x8);
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170cf1: STEP(0x170cf1); /* mov qword ptr [rdx], rax */
WRITE((UINT64_C(0x0) + s->gpr[3]), 8, s->gpr[0]);
++s->steps;
pc_170cf4: STEP(0x170cf4); /* add rdx, 8 */
x = s->gpr[3]; y = UINT64_C(0x8);
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170cf8: STEP(0x170cf8); /* add rdi, -1 */
x = s->gpr[5]; y = UINT64_C(0xffffffffffffffff);
s->gpr[5] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170cfc: STEP(0x170cfc); /* jne 0x170c88 */
next_pc = bias + (condition(s, COND_NE) ? UINT64_C(0x170c88) : UINT64_C(0x170cfe));
++s->steps;

break;
case 8:
next_pc=bias+UINT64_C(0x170d12);
switch(s->pc-bias){
case UINT64_C(0x170cfe):goto pc_170cfe;
case UINT64_C(0x170d02):goto pc_170d02;
case UINT64_C(0x170d09):goto pc_170d09;
case UINT64_C(0x170d0d):goto pc_170d0d;
case UINT64_C(0x170d10):goto pc_170d10;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: b5b971cea0bbe828bdcfaf219fd91fc1e37cf8daee84001ef917d0b1c2b985ed
 * Path 1819: [0x170cfe,0x170d12), 5 instructions. */
pc_170cfe: STEP(0x170cfe); /* and r8d, 7 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x7);
s->gpr[8] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
pc_170d02: STEP(0x170d02); /* lea rax, [rip - 0x168bed] */
s->gpr[0] = (UINT64_C(0xffffffffffe97413) + (bias + UINT64_C(0x170d09)));
++s->steps;
pc_170d09: STEP(0x170d09); /* movsxd rsi, dword ptr [rax + r8*4] */
READ(a, (UINT64_C(0x0) + s->gpr[0] + (s->gpr[8] * UINT64_C(0x4))), 4);
s->gpr[4] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
pc_170d0d: STEP(0x170d0d); /* add rsi, rax */
x = s->gpr[4]; y = s->gpr[0];
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170d10: STEP(0x170d10); /* jmp rsi */
x = s->gpr[4];
next_pc = x;
++s->steps;

break;
case 9:
next_pc=bias+UINT64_C(0x170d9f);
switch(s->pc-bias){
case UINT64_C(0x170d70):goto pc_170d70;
case UINT64_C(0x170d71):goto pc_170d71;
case UINT64_C(0x170d74):goto pc_170d74;
case UINT64_C(0x170d76):goto pc_170d76;
case UINT64_C(0x170d78):goto pc_170d78;
case UINT64_C(0x170d7b):goto pc_170d7b;
case UINT64_C(0x170d7f):goto pc_170d7f;
case UINT64_C(0x170d83):goto pc_170d83;
case UINT64_C(0x170d8a):goto pc_170d8a;
case UINT64_C(0x170d8e):goto pc_170d8e;
case UINT64_C(0x170d95):goto pc_170d95;
case UINT64_C(0x170d98):goto pc_170d98;
case UINT64_C(0x170d9d):goto pc_170d9d;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: b5b971cea0bbe828bdcfaf219fd91fc1e37cf8daee84001ef917d0b1c2b985ed
 * Path 1820: [0x170d70,0x170d9f), 13 instructions. */
pc_170d70: STEP(0x170d70); /* push rbp */
x = s->gpr[6]; y = s->gpr[7] - 8;
WRITE(y, 8, x);
s->gpr[7] = y;
++s->steps;
pc_170d71: STEP(0x170d71); /* mov rbp, rsp */
s->gpr[6] = s->gpr[7];
++s->steps;
pc_170d74: STEP(0x170d74); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170d76: STEP(0x170d76); /* xor esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170d78: STEP(0x170d78); /* test rdi, rdi */
x = s->gpr[5]; y = s->gpr[5];
(void)operation(s, OP_AND, x, y, 64);
++s->steps;
pc_170d7b: STEP(0x170d7b); /* setne r9b */
s->gpr[9] = (s->gpr[9] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_NE)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170d7f: STEP(0x170d7f); /* sete sil */
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_E)) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170d83: STEP(0x170d83); /* lea r8, [rip - 0x16486a] */
s->gpr[8] = (UINT64_C(0xffffffffffe9b796) + (bias + UINT64_C(0x170d8a)));
++s->steps;
pc_170d8a: STEP(0x170d8a); /* movsxd rax, dword ptr [r8 + rsi*4] */
READ(a, (UINT64_C(0x0) + s->gpr[8] + (s->gpr[4] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
pc_170d8e: STEP(0x170d8e); /* lea rdx, [rip - 0x25] */
s->gpr[3] = (UINT64_C(0xffffffffffffffdb) + (bias + UINT64_C(0x170d95)));
++s->steps;
pc_170d95: STEP(0x170d95); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170d98: STEP(0x170d98); /* mov eax, 0xffff5036 */
s->gpr[0] = (uint32_t)(UINT64_C(0xffff5036));
++s->steps;
pc_170d9d: STEP(0x170d9d); /* jmp rdx */
x = s->gpr[3];
next_pc = x;
++s->steps;

break;
case 10:
next_pc=bias+UINT64_C(0x170dd4);
switch(s->pc-bias){
case UINT64_C(0x170da0):goto pc_170da0;
case UINT64_C(0x170da3):goto pc_170da3;
case UINT64_C(0x170da9):goto pc_170da9;
case UINT64_C(0x170dac):goto pc_170dac;
case UINT64_C(0x170db6):goto pc_170db6;
case UINT64_C(0x170db9):goto pc_170db9;
case UINT64_C(0x170dc0):goto pc_170dc0;
case UINT64_C(0x170dc2):goto pc_170dc2;
case UINT64_C(0x170dc6):goto pc_170dc6;
case UINT64_C(0x170dcd):goto pc_170dcd;
case UINT64_C(0x170dd0):goto pc_170dd0;
case UINT64_C(0x170dd2):goto pc_170dd2;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: b5b971cea0bbe828bdcfaf219fd91fc1e37cf8daee84001ef917d0b1c2b985ed
 * Path 1821: [0x170da0,0x170dd4), 12 instructions. */
pc_170da0: STEP(0x170da0); /* mov cl, r9b */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((s->gpr[9] & UINT64_C(0xff))) & UINT64_C(0xff)) << 0);
++s->steps;
pc_170da3: STEP(0x170da3); /* imul eax, esi, 0x9f8ac37d */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x9f8ac37d);
s->gpr[0] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
pc_170da9: STEP(0x170da9); /* lea eax, [rax + rcx*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x2))));
++s->steps;
pc_170dac: STEP(0x170dac); /* movabs rcx, 0x2100000001 */
s->gpr[2] = UINT64_C(0x2100000001);
++s->steps;
pc_170db6: STEP(0x170db6); /* mov qword ptr [rdi], rcx */
WRITE((UINT64_C(0x0) + s->gpr[5]), 8, s->gpr[2]);
++s->steps;
pc_170db9: STEP(0x170db9); /* mov dword ptr [rdi + 8], 0 */
WRITE((UINT64_C(0x8) + s->gpr[5]), 4, UINT64_C(0x0));
++s->steps;
pc_170dc0: STEP(0x170dc0); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
pc_170dc2: STEP(0x170dc2); /* movsxd rax, dword ptr [r8 + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[8] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
pc_170dc6: STEP(0x170dc6); /* lea rcx, [rip - 0x2d] */
s->gpr[2] = (UINT64_C(0xffffffffffffffd3) + (bias + UINT64_C(0x170dcd)));
++s->steps;
pc_170dcd: STEP(0x170dcd); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
pc_170dd0: STEP(0x170dd0); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
pc_170dd2: STEP(0x170dd2); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
case 11:
next_pc=bias+UINT64_C(0x170dd7);
switch(s->pc-bias){
case UINT64_C(0x170dd5):goto pc_170dd5;
case UINT64_C(0x170dd6):goto pc_170dd6;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: b5b971cea0bbe828bdcfaf219fd91fc1e37cf8daee84001ef917d0b1c2b985ed
 * Path 1822: [0x170dd5,0x170dd7), 2 instructions. */
pc_170dd5: STEP(0x170dd5); /* pop rbp */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
s->gpr[6] = x;
++s->steps;
pc_170dd6: STEP(0x170dd6); /* ret  */
READ(x, s->gpr[7], 8);
s->gpr[7] += 8;
next_pc = x;
++s->steps;

break;
default:return WRAPPER_KG_PAYLOAD_INVALID;}
NATIVE_DONE;}
