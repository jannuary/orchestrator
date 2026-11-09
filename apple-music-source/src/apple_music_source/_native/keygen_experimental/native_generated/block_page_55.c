#include "../spc_native_internal.h"
int wrapper_kg_native_page_55(unsigned block,uint64_t bias,wrapper_kg_native_state *fs,const wrapper_kg_payload_region *regions,size_t count,size_t max_steps) {
    NATIVE_LOCALS;
    switch(block) {
    case 0:
next_pc=bias+UINT64_C(0x555940);
switch(s->pc-bias){
case UINT64_C(0x555520):goto kg_pc_555520;
case UINT64_C(0x555527):goto kg_pc_555527;
case UINT64_C(0x55552d):goto kg_pc_55552d;
case UINT64_C(0x555537):goto kg_pc_555537;
case UINT64_C(0x55553b):goto kg_pc_55553b;
case UINT64_C(0x55553e):goto kg_pc_55553e;
case UINT64_C(0x555541):goto kg_pc_555541;
case UINT64_C(0x555548):goto kg_pc_555548;
case UINT64_C(0x555550):goto kg_pc_555550;
case UINT64_C(0x55555a):goto kg_pc_55555a;
case UINT64_C(0x55555d):goto kg_pc_55555d;
case UINT64_C(0x555560):goto kg_pc_555560;
case UINT64_C(0x55556a):goto kg_pc_55556a;
case UINT64_C(0x55556e):goto kg_pc_55556e;
case UINT64_C(0x555578):goto kg_pc_555578;
case UINT64_C(0x55557c):goto kg_pc_55557c;
case UINT64_C(0x555586):goto kg_pc_555586;
case UINT64_C(0x555589):goto kg_pc_555589;
case UINT64_C(0x55558c):goto kg_pc_55558c;
case UINT64_C(0x555596):goto kg_pc_555596;
case UINT64_C(0x555599):goto kg_pc_555599;
case UINT64_C(0x5555a3):goto kg_pc_5555a3;
case UINT64_C(0x5555a6):goto kg_pc_5555a6;
case UINT64_C(0x5555a9):goto kg_pc_5555a9;
case UINT64_C(0x5555ad):goto kg_pc_5555ad;
case UINT64_C(0x5555b4):goto kg_pc_5555b4;
case UINT64_C(0x5555b7):goto kg_pc_5555b7;
case UINT64_C(0x5555c1):goto kg_pc_5555c1;
case UINT64_C(0x5555c4):goto kg_pc_5555c4;
case UINT64_C(0x5555ce):goto kg_pc_5555ce;
case UINT64_C(0x5555d1):goto kg_pc_5555d1;
case UINT64_C(0x5555d5):goto kg_pc_5555d5;
case UINT64_C(0x5555df):goto kg_pc_5555df;
case UINT64_C(0x5555e2):goto kg_pc_5555e2;
case UINT64_C(0x5555e6):goto kg_pc_5555e6;
case UINT64_C(0x5555e9):goto kg_pc_5555e9;
case UINT64_C(0x5555f3):goto kg_pc_5555f3;
case UINT64_C(0x5555f6):goto kg_pc_5555f6;
case UINT64_C(0x5555f9):goto kg_pc_5555f9;
case UINT64_C(0x555603):goto kg_pc_555603;
case UINT64_C(0x55560a):goto kg_pc_55560a;
case UINT64_C(0x55560d):goto kg_pc_55560d;
case UINT64_C(0x555610):goto kg_pc_555610;
case UINT64_C(0x555613):goto kg_pc_555613;
case UINT64_C(0x55561d):goto kg_pc_55561d;
case UINT64_C(0x555620):goto kg_pc_555620;
case UINT64_C(0x555623):goto kg_pc_555623;
case UINT64_C(0x555627):goto kg_pc_555627;
case UINT64_C(0x555631):goto kg_pc_555631;
case UINT64_C(0x555634):goto kg_pc_555634;
case UINT64_C(0x555638):goto kg_pc_555638;
case UINT64_C(0x555642):goto kg_pc_555642;
case UINT64_C(0x555645):goto kg_pc_555645;
case UINT64_C(0x555648):goto kg_pc_555648;
case UINT64_C(0x55564b):goto kg_pc_55564b;
case UINT64_C(0x555655):goto kg_pc_555655;
case UINT64_C(0x555658):goto kg_pc_555658;
case UINT64_C(0x55565b):goto kg_pc_55565b;
case UINT64_C(0x55565f):goto kg_pc_55565f;
case UINT64_C(0x555669):goto kg_pc_555669;
case UINT64_C(0x55566c):goto kg_pc_55566c;
case UINT64_C(0x555670):goto kg_pc_555670;
case UINT64_C(0x55567a):goto kg_pc_55567a;
case UINT64_C(0x55567d):goto kg_pc_55567d;
case UINT64_C(0x555680):goto kg_pc_555680;
case UINT64_C(0x55568a):goto kg_pc_55568a;
case UINT64_C(0x55568d):goto kg_pc_55568d;
case UINT64_C(0x555690):goto kg_pc_555690;
case UINT64_C(0x555693):goto kg_pc_555693;
case UINT64_C(0x555696):goto kg_pc_555696;
case UINT64_C(0x5556a0):goto kg_pc_5556a0;
case UINT64_C(0x5556a3):goto kg_pc_5556a3;
case UINT64_C(0x5556a6):goto kg_pc_5556a6;
case UINT64_C(0x5556ac):goto kg_pc_5556ac;
case UINT64_C(0x5556b2):goto kg_pc_5556b2;
case UINT64_C(0x5556b8):goto kg_pc_5556b8;
case UINT64_C(0x5556ba):goto kg_pc_5556ba;
case UINT64_C(0x5556bc):goto kg_pc_5556bc;
case UINT64_C(0x5556c2):goto kg_pc_5556c2;
case UINT64_C(0x5556c8):goto kg_pc_5556c8;
case UINT64_C(0x5556cc):goto kg_pc_5556cc;
case UINT64_C(0x5556d0):goto kg_pc_5556d0;
case UINT64_C(0x5556d7):goto kg_pc_5556d7;
case UINT64_C(0x5556e1):goto kg_pc_5556e1;
case UINT64_C(0x5556e5):goto kg_pc_5556e5;
case UINT64_C(0x5556ef):goto kg_pc_5556ef;
case UINT64_C(0x5556f2):goto kg_pc_5556f2;
case UINT64_C(0x5556f5):goto kg_pc_5556f5;
case UINT64_C(0x5556f8):goto kg_pc_5556f8;
case UINT64_C(0x555702):goto kg_pc_555702;
case UINT64_C(0x555705):goto kg_pc_555705;
case UINT64_C(0x55570f):goto kg_pc_55570f;
case UINT64_C(0x555712):goto kg_pc_555712;
case UINT64_C(0x555715):goto kg_pc_555715;
case UINT64_C(0x555718):goto kg_pc_555718;
case UINT64_C(0x55571f):goto kg_pc_55571f;
case UINT64_C(0x555722):goto kg_pc_555722;
case UINT64_C(0x55572c):goto kg_pc_55572c;
case UINT64_C(0x55572f):goto kg_pc_55572f;
case UINT64_C(0x555732):goto kg_pc_555732;
case UINT64_C(0x555736):goto kg_pc_555736;
case UINT64_C(0x555740):goto kg_pc_555740;
case UINT64_C(0x555743):goto kg_pc_555743;
case UINT64_C(0x555746):goto kg_pc_555746;
case UINT64_C(0x555749):goto kg_pc_555749;
case UINT64_C(0x55574d):goto kg_pc_55574d;
case UINT64_C(0x555757):goto kg_pc_555757;
case UINT64_C(0x55575a):goto kg_pc_55575a;
case UINT64_C(0x55575d):goto kg_pc_55575d;
case UINT64_C(0x555761):goto kg_pc_555761;
case UINT64_C(0x555768):goto kg_pc_555768;
case UINT64_C(0x55576f):goto kg_pc_55576f;
case UINT64_C(0x555773):goto kg_pc_555773;
case UINT64_C(0x555779):goto kg_pc_555779;
case UINT64_C(0x55577c):goto kg_pc_55577c;
case UINT64_C(0x55577f):goto kg_pc_55577f;
case UINT64_C(0x555789):goto kg_pc_555789;
case UINT64_C(0x55578d):goto kg_pc_55578d;
case UINT64_C(0x555790):goto kg_pc_555790;
case UINT64_C(0x555794):goto kg_pc_555794;
case UINT64_C(0x55579e):goto kg_pc_55579e;
case UINT64_C(0x5557a1):goto kg_pc_5557a1;
case UINT64_C(0x5557a4):goto kg_pc_5557a4;
case UINT64_C(0x5557a8):goto kg_pc_5557a8;
case UINT64_C(0x5557b2):goto kg_pc_5557b2;
case UINT64_C(0x5557b5):goto kg_pc_5557b5;
case UINT64_C(0x5557bc):goto kg_pc_5557bc;
case UINT64_C(0x5557bf):goto kg_pc_5557bf;
case UINT64_C(0x5557c9):goto kg_pc_5557c9;
case UINT64_C(0x5557cd):goto kg_pc_5557cd;
case UINT64_C(0x5557d0):goto kg_pc_5557d0;
case UINT64_C(0x5557d4):goto kg_pc_5557d4;
case UINT64_C(0x5557de):goto kg_pc_5557de;
case UINT64_C(0x5557e1):goto kg_pc_5557e1;
case UINT64_C(0x5557e4):goto kg_pc_5557e4;
case UINT64_C(0x5557e8):goto kg_pc_5557e8;
case UINT64_C(0x5557f2):goto kg_pc_5557f2;
case UINT64_C(0x5557f5):goto kg_pc_5557f5;
case UINT64_C(0x5557f8):goto kg_pc_5557f8;
case UINT64_C(0x5557fb):goto kg_pc_5557fb;
case UINT64_C(0x555805):goto kg_pc_555805;
case UINT64_C(0x555808):goto kg_pc_555808;
case UINT64_C(0x55580c):goto kg_pc_55580c;
case UINT64_C(0x555813):goto kg_pc_555813;
case UINT64_C(0x55581a):goto kg_pc_55581a;
case UINT64_C(0x555820):goto kg_pc_555820;
case UINT64_C(0x555823):goto kg_pc_555823;
case UINT64_C(0x55582a):goto kg_pc_55582a;
case UINT64_C(0x555830):goto kg_pc_555830;
case UINT64_C(0x555833):goto kg_pc_555833;
case UINT64_C(0x555837):goto kg_pc_555837;
case UINT64_C(0x555841):goto kg_pc_555841;
case UINT64_C(0x555845):goto kg_pc_555845;
case UINT64_C(0x55584f):goto kg_pc_55584f;
case UINT64_C(0x555852):goto kg_pc_555852;
case UINT64_C(0x555855):goto kg_pc_555855;
case UINT64_C(0x55585c):goto kg_pc_55585c;
case UINT64_C(0x55585f):goto kg_pc_55585f;
case UINT64_C(0x555869):goto kg_pc_555869;
case UINT64_C(0x55586c):goto kg_pc_55586c;
case UINT64_C(0x555876):goto kg_pc_555876;
case UINT64_C(0x555879):goto kg_pc_555879;
case UINT64_C(0x55587c):goto kg_pc_55587c;
case UINT64_C(0x55587f):goto kg_pc_55587f;
case UINT64_C(0x555885):goto kg_pc_555885;
case UINT64_C(0x555888):goto kg_pc_555888;
case UINT64_C(0x555892):goto kg_pc_555892;
case UINT64_C(0x555895):goto kg_pc_555895;
case UINT64_C(0x555898):goto kg_pc_555898;
case UINT64_C(0x55589b):goto kg_pc_55589b;
case UINT64_C(0x55589f):goto kg_pc_55589f;
case UINT64_C(0x5558a9):goto kg_pc_5558a9;
case UINT64_C(0x5558ad):goto kg_pc_5558ad;
case UINT64_C(0x5558b0):goto kg_pc_5558b0;
case UINT64_C(0x5558b4):goto kg_pc_5558b4;
case UINT64_C(0x5558be):goto kg_pc_5558be;
case UINT64_C(0x5558c1):goto kg_pc_5558c1;
case UINT64_C(0x5558c4):goto kg_pc_5558c4;
case UINT64_C(0x5558c8):goto kg_pc_5558c8;
case UINT64_C(0x5558cd):goto kg_pc_5558cd;
case UINT64_C(0x5558d1):goto kg_pc_5558d1;
case UINT64_C(0x5558d6):goto kg_pc_5558d6;
case UINT64_C(0x5558dc):goto kg_pc_5558dc;
case UINT64_C(0x5558df):goto kg_pc_5558df;
case UINT64_C(0x5558e9):goto kg_pc_5558e9;
case UINT64_C(0x5558ed):goto kg_pc_5558ed;
case UINT64_C(0x5558f0):goto kg_pc_5558f0;
case UINT64_C(0x5558f3):goto kg_pc_5558f3;
case UINT64_C(0x5558f7):goto kg_pc_5558f7;
case UINT64_C(0x555901):goto kg_pc_555901;
case UINT64_C(0x555904):goto kg_pc_555904;
case UINT64_C(0x555908):goto kg_pc_555908;
case UINT64_C(0x55590b):goto kg_pc_55590b;
case UINT64_C(0x555915):goto kg_pc_555915;
case UINT64_C(0x555918):goto kg_pc_555918;
case UINT64_C(0x55591b):goto kg_pc_55591b;
case UINT64_C(0x555925):goto kg_pc_555925;
case UINT64_C(0x555929):goto kg_pc_555929;
case UINT64_C(0x55592c):goto kg_pc_55592c;
case UINT64_C(0x555930):goto kg_pc_555930;
case UINT64_C(0x55593a):goto kg_pc_55593a;
case UINT64_C(0x55593d):goto kg_pc_55593d;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 6356: [0x555520,0x555940), 202 instructions. */
kg_pc_555520: STEP(0x555520); /* cmp r9d, 0xf9500a3 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0xf9500a3);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_555527: STEP(0x555527); /* mov r11d, 0 */
s->gpr[11] = (uint32_t)(UINT64_C(0x0));
++s->steps;
kg_pc_55552d: STEP(0x55552d); /* movabs rax, 0x100000000 */
s->gpr[0] = UINT64_C(0x100000000);
++s->steps;
kg_pc_555537: STEP(0x555537); /* cmovb r11, rax */
s->gpr[11] = (condition(s, COND_B) ? s->gpr[0] : s->gpr[11]);
++s->steps;
kg_pc_55553b: STEP(0x55553b); /* mov eax, r9d */
s->gpr[0] = (uint32_t)((s->gpr[9] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55553e: STEP(0x55553e); /* add r11, rax */
x = s->gpr[11]; y = s->gpr[0];
s->gpr[11] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_555541: STEP(0x555541); /* mov rax, qword ptr [rbp - 0x3c0] */
READ(a, (UINT64_C(0xfffffffffffffc40) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_555548: STEP(0x555548); /* mov rcx, qword ptr [rax + r11*8 - 0x7ca80518] */
READ(a, (UINT64_C(0xffffffff8357fae8) + s->gpr[0] + (s->gpr[11] * UINT64_C(0x8))), 8);
s->gpr[2] = a;
++s->steps;
kg_pc_555550: STEP(0x555550); /* movabs rax, 0xefefefefefefefef */
s->gpr[0] = UINT64_C(0xefefefefefefefef);
++s->steps;
kg_pc_55555a: STEP(0x55555a); /* xor rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_55555d: STEP(0x55555d); /* mov rax, rcx */
s->gpr[0] = s->gpr[2];
++s->steps;
kg_pc_555560: STEP(0x555560); /* movabs rdx, 0xdd3f253fe531afcf */
s->gpr[3] = UINT64_C(0xdd3f253fe531afcf);
++s->steps;
kg_pc_55556a: STEP(0x55556a); /* imul rax, rdx */
x = s->gpr[0]; y = s->gpr[3];
s->gpr[0] = operation(s, OP_IMUL, x, y, 64);
++s->steps;
kg_pc_55556e: STEP(0x55556e); /* movabs rdx, 0xba7e4a7fca635f9e */
s->gpr[3] = UINT64_C(0xba7e4a7fca635f9e);
++s->steps;
kg_pc_555578: STEP(0x555578); /* imul rcx, rdx */
x = s->gpr[2]; y = s->gpr[3];
s->gpr[2] = operation(s, OP_IMUL, x, y, 64);
++s->steps;
kg_pc_55557c: STEP(0x55557c); /* movabs rdx, 0x73adca874133691c */
s->gpr[3] = UINT64_C(0x73adca874133691c);
++s->steps;
kg_pc_555586: STEP(0x555586); /* and rcx, rdx */
x = s->gpr[2]; y = s->gpr[3];
s->gpr[2] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_555589: STEP(0x555589); /* sub rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_55558c: STEP(0x55558c); /* movabs rcx, 0x39d6e543a099b48e */
s->gpr[2] = UINT64_C(0x39d6e543a099b48e);
++s->steps;
kg_pc_555596: STEP(0x555596); /* add rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_555599: STEP(0x555599); /* movabs rcx, 0x92f2e4665f31c52 */
s->gpr[2] = UINT64_C(0x92f2e4665f31c52);
++s->steps;
kg_pc_5555a3: STEP(0x5555a3); /* xor rbx, rcx */
x = s->gpr[1]; y = s->gpr[2];
s->gpr[1] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_5555a6: STEP(0x5555a6); /* xor rbx, rax */
x = s->gpr[1]; y = s->gpr[0];
s->gpr[1] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_5555a9: STEP(0x5555a9); /* lea rcx, [rbx + r11] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[1] + (s->gpr[11] * UINT64_C(0x1)));
++s->steps;
kg_pc_5555ad: STEP(0x5555ad); /* add rcx, -0xf9500a3 */
x = s->gpr[2]; y = UINT64_C(0xfffffffff06aff5d);
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_5555b4: STEP(0x5555b4); /* mov rdx, rcx */
s->gpr[3] = s->gpr[2];
++s->steps;
kg_pc_5555b7: STEP(0x5555b7); /* movabs rsi, 0x9dfcf7efdbd285be */
s->gpr[4] = UINT64_C(0x9dfcf7efdbd285be);
++s->steps;
kg_pc_5555c1: STEP(0x5555c1); /* xor rdx, rsi */
x = s->gpr[3]; y = s->gpr[4];
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_5555c4: STEP(0x5555c4); /* movabs rsi, 0x1dfcf7efdbd285be */
s->gpr[4] = UINT64_C(0x1dfcf7efdbd285be);
++s->steps;
kg_pc_5555ce: STEP(0x5555ce); /* and rcx, rsi */
x = s->gpr[2]; y = s->gpr[4];
s->gpr[2] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_5555d1: STEP(0x5555d1); /* lea rcx, [rdx + rcx*2] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x2)));
++s->steps;
kg_pc_5555d5: STEP(0x5555d5); /* movabs rdx, 0x62030810242d7a42 */
s->gpr[3] = UINT64_C(0x62030810242d7a42);
++s->steps;
kg_pc_5555df: STEP(0x5555df); /* add rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_5555e2: STEP(0x5555e2); /* shr rdx, 0x20 */
x = s->gpr[3]; y = UINT64_C(0x20);
s->gpr[3] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_5555e6: STEP(0x5555e6); /* mov rbx, rdx */
s->gpr[1] = s->gpr[3];
++s->steps;
kg_pc_5555e9: STEP(0x5555e9); /* movabs rsi, 0x569c01202837 */
s->gpr[4] = UINT64_C(0x569c01202837);
++s->steps;
kg_pc_5555f3: STEP(0x5555f3); /* xor rbx, rsi */
x = s->gpr[1]; y = s->gpr[4];
s->gpr[1] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_5555f6: STEP(0x5555f6); /* add rdx, rdx */
x = s->gpr[3]; y = s->gpr[3];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_5555f9: STEP(0x5555f9); /* movabs rsi, 0x1894fbcf6 */
s->gpr[4] = UINT64_C(0x1894fbcf6);
++s->steps;
kg_pc_555603: STEP(0x555603); /* lea rdi, [rsi + 0x746ff29a] */
s->gpr[5] = (UINT64_C(0x746ff29a) + s->gpr[4]);
++s->steps;
kg_pc_55560a: STEP(0x55560a); /* and rdi, rdx */
x = s->gpr[5]; y = s->gpr[3];
s->gpr[5] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_55560d: STEP(0x55560d); /* add rbx, rcx */
x = s->gpr[1]; y = s->gpr[2];
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_555610: STEP(0x555610); /* sub rbx, rdi */
x = s->gpr[1]; y = s->gpr[5];
s->gpr[1] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_555613: STEP(0x555613); /* movabs rcx, 0x6202b174230d520b */
s->gpr[2] = UINT64_C(0x6202b174230d520b);
++s->steps;
kg_pc_55561d: STEP(0x55561d); /* add rcx, rbx */
x = s->gpr[2]; y = s->gpr[1];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_555620: STEP(0x555620); /* mov rdi, rcx */
s->gpr[5] = s->gpr[2];
++s->steps;
kg_pc_555623: STEP(0x555623); /* shr rdi, 0x10 */
x = s->gpr[5]; y = UINT64_C(0x10);
s->gpr[5] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_555627: STEP(0x555627); /* movabs rdx, 0xa11178ca030808a6 */
s->gpr[3] = UINT64_C(0xa11178ca030808a6);
++s->steps;
kg_pc_555631: STEP(0x555631); /* xor rdi, rdx */
x = s->gpr[5]; y = s->gpr[3];
s->gpr[5] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_555634: STEP(0x555634); /* shr rcx, 0xf */
x = s->gpr[2]; y = UINT64_C(0xf);
s->gpr[2] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_555638: STEP(0x555638); /* movabs rdx, 0x10e6bf9efeeb2 */
s->gpr[3] = UINT64_C(0x10e6bf9efeeb2);
++s->steps;
kg_pc_555642: STEP(0x555642); /* and rcx, rdx */
x = s->gpr[2]; y = s->gpr[3];
s->gpr[2] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_555645: STEP(0x555645); /* add rdi, rbx */
x = s->gpr[5]; y = s->gpr[1];
s->gpr[5] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_555648: STEP(0x555648); /* sub rdi, rcx */
x = s->gpr[5]; y = s->gpr[2];
s->gpr[5] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_55564b: STEP(0x55564b); /* movabs rcx, 0xc0f138aa20054965 */
s->gpr[2] = UINT64_C(0xc0f138aa20054965);
++s->steps;
kg_pc_555655: STEP(0x555655); /* add rcx, rdi */
x = s->gpr[2]; y = s->gpr[5];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_555658: STEP(0x555658); /* mov rdx, rcx */
s->gpr[3] = s->gpr[2];
++s->steps;
kg_pc_55565b: STEP(0x55565b); /* shr rdx, 8 */
x = s->gpr[3]; y = UINT64_C(0x8);
s->gpr[3] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_55565f: STEP(0x55565f); /* movabs rsi, 0x6ef33913f3ebeedd */
s->gpr[4] = UINT64_C(0x6ef33913f3ebeedd);
++s->steps;
kg_pc_555669: STEP(0x555669); /* xor rdx, rsi */
x = s->gpr[3]; y = s->gpr[4];
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_55566c: STEP(0x55566c); /* shr rcx, 7 */
x = s->gpr[2]; y = UINT64_C(0x7);
s->gpr[2] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_555670: STEP(0x555670); /* movabs rsi, 0x1e67227e7d7ddba */
s->gpr[4] = UINT64_C(0x1e67227e7d7ddba);
++s->steps;
kg_pc_55567a: STEP(0x55567a); /* and rcx, rsi */
x = s->gpr[2]; y = s->gpr[4];
s->gpr[2] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_55567d: STEP(0x55567d); /* add rcx, rdx */
x = s->gpr[2]; y = s->gpr[3];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_555680: STEP(0x555680); /* movabs rdx, 0xd3fffffffed6f1fb */
s->gpr[3] = UINT64_C(0xd3fffffffed6f1fb);
++s->steps;
kg_pc_55568a: STEP(0x55568a); /* add rcx, rdx */
x = s->gpr[2]; y = s->gpr[3];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_55568d: STEP(0x55568d); /* add rdi, rcx */
x = s->gpr[5]; y = s->gpr[2];
s->gpr[5] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_555690: STEP(0x555690); /* add rcx, rcx */
x = s->gpr[2]; y = s->gpr[2];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_555693: STEP(0x555693); /* sub rdi, rcx */
x = s->gpr[5]; y = s->gpr[2];
s->gpr[5] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_555696: STEP(0x555696); /* movabs rcx, 0x66635a9e8ab9165 */
s->gpr[2] = UINT64_C(0x66635a9e8ab9165);
++s->steps;
kg_pc_5556a0: STEP(0x5556a0); /* add rdi, rcx */
x = s->gpr[5]; y = s->gpr[2];
s->gpr[5] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_5556a3: STEP(0x5556a3); /* lea edx, [rdi + rdi] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_5556a6: STEP(0x5556a6); /* add edx, 0x543931b0 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x543931b0);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5556ac: STEP(0x5556ac); /* and edx, 0xfdc6d542 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xfdc6d542);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_5556b2: STEP(0x5556b2); /* lea ecx, [rdi + 0x2a1c98d8] */
s->gpr[2] = (uint32_t)((UINT64_C(0x2a1c98d8) + s->gpr[5]));
++s->steps;
kg_pc_5556b8: STEP(0x5556b8); /* mov ebx, ecx */
s->gpr[1] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_5556ba: STEP(0x5556ba); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_5556bc: STEP(0x5556bc); /* xor ebx, 0x777faffe */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x777faffe);
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_5556c2: STEP(0x5556c2); /* and ecx, 0xf77faffe */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xf77faffe);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_5556c8: STEP(0x5556c8); /* lea r12d, [rbx + rcx*2] */
s->gpr[12] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[2] * UINT64_C(0x2))));
++s->steps;
kg_pc_5556cc: STEP(0x5556cc); /* lea r8d, [rdi + rdx] */
s->gpr[8] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_5556d0: STEP(0x5556d0); /* add r8d, 0xa9000379 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0xa9000379);
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5556d7: STEP(0x5556d7); /* movabs rdx, 0x49a30d5cd9d757c */
s->gpr[3] = UINT64_C(0x49a30d5cd9d757c);
++s->steps;
kg_pc_5556e1: STEP(0x5556e1); /* lea rdx, [rdx + rdi*2] */
s->gpr[3] = (UINT64_C(0x0) + s->gpr[3] + (s->gpr[5] * UINT64_C(0x2)));
++s->steps;
kg_pc_5556e5: STEP(0x5556e5); /* movabs rsi, 0x4d5375f69472eeee */
s->gpr[4] = UINT64_C(0x4d5375f69472eeee);
++s->steps;
kg_pc_5556ef: STEP(0x5556ef); /* and rdx, rsi */
x = s->gpr[3]; y = s->gpr[4];
s->gpr[3] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_5556f2: STEP(0x5556f2); /* sub rdi, rdx */
x = s->gpr[5]; y = s->gpr[3];
s->gpr[5] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_5556f5: STEP(0x5556f5); /* mov rdx, rax */
s->gpr[3] = s->gpr[0];
++s->steps;
kg_pc_5556f8: STEP(0x5556f8); /* movabs rsi, 0xa8f6d36631083235 */
s->gpr[4] = UINT64_C(0xa8f6d36631083235);
++s->steps;
kg_pc_555702: STEP(0x555702); /* add rdi, rsi */
x = s->gpr[5]; y = s->gpr[4];
s->gpr[5] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_555705: STEP(0x555705); /* movabs rsi, 0x1f7f5fb8eaa0c3f9 */
s->gpr[4] = UINT64_C(0x1f7f5fb8eaa0c3f9);
++s->steps;
kg_pc_55570f: STEP(0x55570f); /* xor rdx, rsi */
x = s->gpr[3]; y = s->gpr[4];
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_555712: STEP(0x555712); /* xor rdx, rdi */
x = s->gpr[3]; y = s->gpr[5];
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_555715: STEP(0x555715); /* add rdx, r11 */
x = s->gpr[3]; y = s->gpr[11];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_555718: STEP(0x555718); /* add rdx, -0xf9500a3 */
x = s->gpr[3]; y = UINT64_C(0xfffffffff06aff5d);
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_55571f: STEP(0x55571f); /* mov rsi, rdx */
s->gpr[4] = s->gpr[3];
++s->steps;
kg_pc_555722: STEP(0x555722); /* movabs rbx, 0xfdf7efedcfbffdae */
s->gpr[1] = UINT64_C(0xfdf7efedcfbffdae);
++s->steps;
kg_pc_55572c: STEP(0x55572c); /* xor rsi, rbx */
x = s->gpr[4]; y = s->gpr[1];
s->gpr[4] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_55572f: STEP(0x55572f); /* and rdx, rbx */
x = s->gpr[3]; y = s->gpr[1];
s->gpr[3] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_555732: STEP(0x555732); /* lea r14, [rsi + rdx*2] */
s->gpr[14] = (UINT64_C(0x0) + s->gpr[4] + (s->gpr[3] * UINT64_C(0x2)));
++s->steps;
kg_pc_555736: STEP(0x555736); /* movabs rdx, 0x208101230400252 */
s->gpr[3] = UINT64_C(0x208101230400252);
++s->steps;
kg_pc_555740: STEP(0x555740); /* add rdx, r14 */
x = s->gpr[3]; y = s->gpr[14];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_555743: STEP(0x555743); /* xor r8d, r13d */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = (s->gpr[13] & UINT64_C(0xffffffff));
s->gpr[8] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_555746: STEP(0x555746); /* mov rsi, rdx */
s->gpr[4] = s->gpr[3];
++s->steps;
kg_pc_555749: STEP(0x555749); /* shr rsi, 0x20 */
x = s->gpr[4]; y = UINT64_C(0x20);
s->gpr[4] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_55574d: STEP(0x55574d); /* movabs rbx, 0x340d220b81000810 */
s->gpr[1] = UINT64_C(0x340d220b81000810);
++s->steps;
kg_pc_555757: STEP(0x555757); /* xor rsi, rbx */
x = s->gpr[4]; y = s->gpr[1];
s->gpr[4] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_55575a: STEP(0x55575a); /* add rsi, r14 */
x = s->gpr[4]; y = s->gpr[14];
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_55575d: STEP(0x55575d); /* lea r14d, [r12 + r12] */
s->gpr[14] = (uint32_t)((UINT64_C(0x0) + s->gpr[12] + (s->gpr[12] * UINT64_C(0x1))));
++s->steps;
kg_pc_555761: STEP(0x555761); /* add r14d, 0x4db2c1ea */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0x4db2c1ea);
s->gpr[14] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_555768: STEP(0x555768); /* and r14d, 0x70e80236 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0x70e80236);
s->gpr[14] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55576f: STEP(0x55576f); /* shr rdx, 0x1f */
x = s->gpr[3]; y = UINT64_C(0x1f);
s->gpr[3] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_555773: STEP(0x555773); /* and edx, 0xfdffefde */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xfdffefde);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_555779: STEP(0x555779); /* sub r12d, r14d */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55577c: STEP(0x55577c); /* sub rsi, rdx */
x = s->gpr[4]; y = s->gpr[3];
s->gpr[4] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_55577f: STEP(0x55577f); /* movabs rdx, 0xcdfaee06af3ffa42 */
s->gpr[3] = UINT64_C(0xcdfaee06af3ffa42);
++s->steps;
kg_pc_555789: STEP(0x555789); /* lea r14, [rsi + rdx] */
s->gpr[14] = (UINT64_C(0x0) + s->gpr[4] + (s->gpr[3] * UINT64_C(0x1)));
++s->steps;
kg_pc_55578d: STEP(0x55578d); /* mov rdx, r14 */
s->gpr[3] = s->gpr[14];
++s->steps;
kg_pc_555790: STEP(0x555790); /* shr rdx, 0x10 */
x = s->gpr[3]; y = UINT64_C(0x10);
s->gpr[3] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_555794: STEP(0x555794); /* movabs rbx, 0x444d922020803000 */
s->gpr[1] = UINT64_C(0x444d922020803000);
++s->steps;
kg_pc_55579e: STEP(0x55579e); /* xor rdx, rbx */
x = s->gpr[3]; y = s->gpr[1];
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_5557a1: STEP(0x5557a1); /* add rdx, rsi */
x = s->gpr[3]; y = s->gpr[4];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_5557a4: STEP(0x5557a4); /* shr r14, 0xf */
x = s->gpr[14]; y = UINT64_C(0xf);
s->gpr[14] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_5557a8: STEP(0x5557a8); /* movabs rsi, 0xdbbfbeff9ffe */
s->gpr[4] = UINT64_C(0xdbbfbeff9ffe);
++s->steps;
kg_pc_5557b2: STEP(0x5557b2); /* and r14, rsi */
x = s->gpr[14]; y = s->gpr[4];
s->gpr[14] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_5557b5: STEP(0x5557b5); /* add r12d, 0x1f4d6210 */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x1f4d6210);
s->gpr[12] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5557bc: STEP(0x5557bc); /* sub rdx, r14 */
x = s->gpr[3]; y = s->gpr[14];
s->gpr[3] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_5557bf: STEP(0x5557bf); /* movabs rsi, 0x89ad5be68ebfca42 */
s->gpr[4] = UINT64_C(0x89ad5be68ebfca42);
++s->steps;
kg_pc_5557c9: STEP(0x5557c9); /* lea r14, [rdx + rsi] */
s->gpr[14] = (UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x1)));
++s->steps;
kg_pc_5557cd: STEP(0x5557cd); /* mov rsi, r14 */
s->gpr[4] = s->gpr[14];
++s->steps;
kg_pc_5557d0: STEP(0x5557d0); /* shr rsi, 8 */
x = s->gpr[4]; y = UINT64_C(0x8);
s->gpr[4] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_5557d4: STEP(0x5557d4); /* movabs rbx, 0x90a9902084640000 */
s->gpr[1] = UINT64_C(0x90a9902084640000);
++s->steps;
kg_pc_5557de: STEP(0x5557de); /* xor rsi, rbx */
x = s->gpr[4]; y = s->gpr[1];
s->gpr[4] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_5557e1: STEP(0x5557e1); /* add rsi, rdx */
x = s->gpr[4]; y = s->gpr[3];
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_5557e4: STEP(0x5557e4); /* shr r14, 7 */
x = s->gpr[14]; y = UINT64_C(0x7);
s->gpr[14] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_5557e8: STEP(0x5557e8); /* movabs rdx, 0xacdfbef737fffe */
s->gpr[3] = UINT64_C(0xacdfbef737fffe);
++s->steps;
kg_pc_5557f2: STEP(0x5557f2); /* and r14, rdx */
x = s->gpr[14]; y = s->gpr[3];
s->gpr[14] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_5557f5: STEP(0x5557f5); /* xor r12d, r10d */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_5557f8: STEP(0x5557f8); /* sub rsi, r14 */
x = s->gpr[4]; y = s->gpr[14];
s->gpr[4] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_5557fb: STEP(0x5557fb); /* movabs rdx, 0x46a33e7a3885a058 */
s->gpr[3] = UINT64_C(0x46a33e7a3885a058);
++s->steps;
kg_pc_555805: STEP(0x555805); /* add rsi, rdx */
x = s->gpr[4]; y = s->gpr[3];
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_555808: STEP(0x555808); /* lea r10d, [rsi + rsi] */
s->gpr[10] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55580c: STEP(0x55580c); /* add r10d, 0x23ac53d4 */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x23ac53d4);
s->gpr[10] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_555813: STEP(0x555813); /* and r10d, 0x7c0a52bc */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x7c0a52bc);
s->gpr[10] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55581a: STEP(0x55581a); /* lea edx, [rsi - 0x2e29d616] */
s->gpr[3] = (uint32_t)((UINT64_C(0xffffffffd1d629ea) + s->gpr[4]));
++s->steps;
kg_pc_555820: STEP(0x555820); /* mov r14d, edx */
s->gpr[14] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_555823: STEP(0x555823); /* xor r14d, 0xf78ffe9b */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0xf78ffe9b);
s->gpr[14] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55582a: STEP(0x55582a); /* and edx, 0xf78ffe9b */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xf78ffe9b);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_555830: STEP(0x555830); /* neg r10d */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = 0;
s->gpr[10] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_555833: STEP(0x555833); /* lea r14d, [r14 + rdx*2] */
s->gpr[14] = (uint32_t)((UINT64_C(0x0) + s->gpr[14] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_555837: STEP(0x555837); /* movabs rdx, 0x6e5ed3451d1097a0 */
s->gpr[3] = UINT64_C(0x6e5ed3451d1097a0);
++s->steps;
kg_pc_555841: STEP(0x555841); /* lea rdx, [rdx + rsi*2] */
s->gpr[3] = (UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x2)));
++s->steps;
kg_pc_555845: STEP(0x555845); /* movabs rbx, 0xd2948161f77f2bb2 */
s->gpr[1] = UINT64_C(0xd2948161f77f2bb2);
++s->steps;
kg_pc_55584f: STEP(0x55584f); /* and rdx, rbx */
x = s->gpr[3]; y = s->gpr[1];
s->gpr[3] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_555852: STEP(0x555852); /* add r10d, esi */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[10] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_555855: STEP(0x555855); /* add r10d, 0xfdb5348 */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0xfdb5348);
s->gpr[10] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55585c: STEP(0x55585c); /* sub rsi, rdx */
x = s->gpr[4]; y = s->gpr[3];
s->gpr[4] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_55585f: STEP(0x55585f); /* movabs rdx, 0xa079aa538a47e1a9 */
s->gpr[3] = UINT64_C(0xa079aa538a47e1a9);
++s->steps;
kg_pc_555869: STEP(0x555869); /* add rsi, rdx */
x = s->gpr[4]; y = s->gpr[3];
s->gpr[4] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_55586c: STEP(0x55586c); /* movabs rdx, 0x509ca5f35b262157 */
s->gpr[3] = UINT64_C(0x509ca5f35b262157);
++s->steps;
kg_pc_555876: STEP(0x555876); /* xor rax, rdx */
x = s->gpr[0]; y = s->gpr[3];
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_555879: STEP(0x555879); /* xor rax, rsi */
x = s->gpr[0]; y = s->gpr[4];
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_55587c: STEP(0x55587c); /* add rax, r11 */
x = s->gpr[0]; y = s->gpr[11];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_55587f: STEP(0x55587f); /* add rax, -0xf9500a3 */
x = s->gpr[0]; y = UINT64_C(0xfffffffff06aff5d);
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_555885: STEP(0x555885); /* mov rdx, rax */
s->gpr[3] = s->gpr[0];
++s->steps;
kg_pc_555888: STEP(0x555888); /* movabs rbx, 0xfb2538b7fcfdefdc */
s->gpr[1] = UINT64_C(0xfb2538b7fcfdefdc);
++s->steps;
kg_pc_555892: STEP(0x555892); /* xor rdx, rbx */
x = s->gpr[3]; y = s->gpr[1];
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_555895: STEP(0x555895); /* and rax, rbx */
x = s->gpr[0]; y = s->gpr[1];
s->gpr[0] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_555898: STEP(0x555898); /* xor r10d, r8d */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55589b: STEP(0x55589b); /* lea rax, [rdx + rax*2] */
s->gpr[0] = (UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x2)));
++s->steps;
kg_pc_55589f: STEP(0x55589f); /* movabs rdx, 0x4dac74803021024 */
s->gpr[3] = UINT64_C(0x4dac74803021024);
++s->steps;
kg_pc_5558a9: STEP(0x5558a9); /* lea rbx, [rax + rdx] */
s->gpr[1] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[3] * UINT64_C(0x1)));
++s->steps;
kg_pc_5558ad: STEP(0x5558ad); /* mov rdx, rbx */
s->gpr[3] = s->gpr[1];
++s->steps;
kg_pc_5558b0: STEP(0x5558b0); /* shr rdx, 0x20 */
x = s->gpr[3]; y = UINT64_C(0x20);
s->gpr[3] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_5558b4: STEP(0x5558b4); /* movabs rcx, 0x11010810c400081c */
s->gpr[2] = UINT64_C(0x11010810c400081c);
++s->steps;
kg_pc_5558be: STEP(0x5558be); /* xor rdx, rcx */
x = s->gpr[3]; y = s->gpr[2];
s->gpr[3] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_5558c1: STEP(0x5558c1); /* add rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_5558c4: STEP(0x5558c4); /* lea eax, [r14 + r14] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[14] + (s->gpr[14] * UINT64_C(0x1))));
++s->steps;
kg_pc_5558c8: STEP(0x5558c8); /* add eax, 0x4d9224b0 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x4d9224b0);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5558cd: STEP(0x5558cd); /* shr rbx, 0x1f */
x = s->gpr[1]; y = UINT64_C(0x1f);
s->gpr[1] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_5558d1: STEP(0x5558d1); /* and eax, 0x7b997876 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x7b997876);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_5558d6: STEP(0x5558d6); /* and ebx, 0x77ffefc6 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x77ffefc6);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_5558dc: STEP(0x5558dc); /* sub rdx, rbx */
x = s->gpr[3]; y = s->gpr[1];
s->gpr[3] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_5558df: STEP(0x5558df); /* movabs rcx, 0xf3d9bf373f020808 */
s->gpr[2] = UINT64_C(0xf3d9bf373f020808);
++s->steps;
kg_pc_5558e9: STEP(0x5558e9); /* lea rbx, [rdx + rcx] */
s->gpr[1] = (UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x1)));
++s->steps;
kg_pc_5558ed: STEP(0x5558ed); /* sub r14d, eax */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[14] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_5558f0: STEP(0x5558f0); /* mov rax, rbx */
s->gpr[0] = s->gpr[1];
++s->steps;
kg_pc_5558f3: STEP(0x5558f3); /* shr rax, 0x10 */
x = s->gpr[0]; y = UINT64_C(0x10);
s->gpr[0] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_5558f7: STEP(0x5558f7); /* movabs rcx, 0x900c01198021010a */
s->gpr[2] = UINT64_C(0x900c01198021010a);
++s->steps;
kg_pc_555901: STEP(0x555901); /* xor rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_555904: STEP(0x555904); /* shr rbx, 0xf */
x = s->gpr[1]; y = UINT64_C(0xf);
s->gpr[1] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_555908: STEP(0x555908); /* add rax, rdx */
x = s->gpr[0]; y = s->gpr[3];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_55590b: STEP(0x55590b); /* movabs rcx, 0x1fdccffbdfdea */
s->gpr[2] = UINT64_C(0x1fdccffbdfdea);
++s->steps;
kg_pc_555915: STEP(0x555915); /* and rbx, rcx */
x = s->gpr[1]; y = s->gpr[2];
s->gpr[1] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_555918: STEP(0x555918); /* sub rax, rbx */
x = s->gpr[0]; y = s->gpr[1];
s->gpr[0] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_55591b: STEP(0x55591b); /* movabs rcx, 0x63cdbe1dbee106fe */
s->gpr[2] = UINT64_C(0x63cdbe1dbee106fe);
++s->steps;
kg_pc_555925: STEP(0x555925); /* lea rdx, [rax + rcx] */
s->gpr[3] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[2] * UINT64_C(0x1)));
++s->steps;
kg_pc_555929: STEP(0x555929); /* mov rbx, rdx */
s->gpr[1] = s->gpr[3];
++s->steps;
kg_pc_55592c: STEP(0x55592c); /* shr rbx, 8 */
x = s->gpr[1]; y = UINT64_C(0x8);
s->gpr[1] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_555930: STEP(0x555930); /* movabs rcx, 0x824012c809028400 */
s->gpr[2] = UINT64_C(0x824012c809028400);
++s->steps;
kg_pc_55593a: STEP(0x55593a); /* xor rbx, rcx */
x = s->gpr[1]; y = s->gpr[2];
s->gpr[1] = operation(s, OP_XOR, x, y, 64);
++s->steps;
kg_pc_55593d: STEP(0x55593d); /* add rbx, rax */
x = s->gpr[1]; y = s->gpr[0];
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;

break;
    case 1:
next_pc=bias+UINT64_C(0x555a4f);
switch(s->pc-bias){
case UINT64_C(0x555940):goto kg_pc_555940;
case UINT64_C(0x555944):goto kg_pc_555944;
case UINT64_C(0x55594b):goto kg_pc_55594b;
case UINT64_C(0x555955):goto kg_pc_555955;
case UINT64_C(0x555958):goto kg_pc_555958;
case UINT64_C(0x55595b):goto kg_pc_55595b;
case UINT64_C(0x555965):goto kg_pc_555965;
case UINT64_C(0x555968):goto kg_pc_555968;
case UINT64_C(0x55596b):goto kg_pc_55596b;
case UINT64_C(0x55596e):goto kg_pc_55596e;
case UINT64_C(0x555973):goto kg_pc_555973;
case UINT64_C(0x555978):goto kg_pc_555978;
case UINT64_C(0x55597a):goto kg_pc_55597a;
case UINT64_C(0x55597e):goto kg_pc_55597e;
case UINT64_C(0x555985):goto kg_pc_555985;
case UINT64_C(0x555988):goto kg_pc_555988;
case UINT64_C(0x55598e):goto kg_pc_55598e;
case UINT64_C(0x555990):goto kg_pc_555990;
case UINT64_C(0x555996):goto kg_pc_555996;
case UINT64_C(0x55599b):goto kg_pc_55599b;
case UINT64_C(0x55599f):goto kg_pc_55599f;
case UINT64_C(0x5559a3):goto kg_pc_5559a3;
case UINT64_C(0x5559a8):goto kg_pc_5559a8;
case UINT64_C(0x5559ad):goto kg_pc_5559ad;
case UINT64_C(0x5559b4):goto kg_pc_5559b4;
case UINT64_C(0x5559b7):goto kg_pc_5559b7;
case UINT64_C(0x5559be):goto kg_pc_5559be;
case UINT64_C(0x5559c2):goto kg_pc_5559c2;
case UINT64_C(0x5559c5):goto kg_pc_5559c5;
case UINT64_C(0x5559cf):goto kg_pc_5559cf;
case UINT64_C(0x5559d3):goto kg_pc_5559d3;
case UINT64_C(0x5559dd):goto kg_pc_5559dd;
case UINT64_C(0x5559e0):goto kg_pc_5559e0;
case UINT64_C(0x5559e3):goto kg_pc_5559e3;
case UINT64_C(0x5559ea):goto kg_pc_5559ea;
case UINT64_C(0x5559f4):goto kg_pc_5559f4;
case UINT64_C(0x5559f7):goto kg_pc_5559f7;
case UINT64_C(0x5559fe):goto kg_pc_5559fe;
case UINT64_C(0x555a00):goto kg_pc_555a00;
case UINT64_C(0x555a07):goto kg_pc_555a07;
case UINT64_C(0x555a0a):goto kg_pc_555a0a;
case UINT64_C(0x555a0e):goto kg_pc_555a0e;
case UINT64_C(0x555a10):goto kg_pc_555a10;
case UINT64_C(0x555a13):goto kg_pc_555a13;
case UINT64_C(0x555a16):goto kg_pc_555a16;
case UINT64_C(0x555a18):goto kg_pc_555a18;
case UINT64_C(0x555a1c):goto kg_pc_555a1c;
case UINT64_C(0x555a1f):goto kg_pc_555a1f;
case UINT64_C(0x555a22):goto kg_pc_555a22;
case UINT64_C(0x555a25):goto kg_pc_555a25;
case UINT64_C(0x555a28):goto kg_pc_555a28;
case UINT64_C(0x555a2b):goto kg_pc_555a2b;
case UINT64_C(0x555a2e):goto kg_pc_555a2e;
case UINT64_C(0x555a35):goto kg_pc_555a35;
case UINT64_C(0x555a39):goto kg_pc_555a39;
case UINT64_C(0x555a40):goto kg_pc_555a40;
case UINT64_C(0x555a43):goto kg_pc_555a43;
case UINT64_C(0x555a46):goto kg_pc_555a46;
case UINT64_C(0x555a4d):goto kg_pc_555a4d;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 6357: [0x555940,0x555a4f), 59 instructions. */
kg_pc_555940: STEP(0x555940); /* shr rdx, 7 */
x = s->gpr[3]; y = UINT64_C(0x7);
s->gpr[3] = operation(s, OP_SHR, x, y, 64);
++s->steps;
kg_pc_555944: STEP(0x555944); /* add r14d, 0xa495ce93 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0xa495ce93);
s->gpr[14] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55594b: STEP(0x55594b); /* movabs rax, 0x17fda6fedfaf7fe */
s->gpr[0] = UINT64_C(0x17fda6fedfaf7fe);
++s->steps;
kg_pc_555955: STEP(0x555955); /* and rdx, rax */
x = s->gpr[3]; y = s->gpr[0];
s->gpr[3] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_555958: STEP(0x555958); /* sub rbx, rdx */
x = s->gpr[1]; y = s->gpr[3];
s->gpr[1] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_55595b: STEP(0x55595b); /* movabs rax, 0xf02b32330d6b2967 */
s->gpr[0] = UINT64_C(0xf02b32330d6b2967);
++s->steps;
kg_pc_555965: STEP(0x555965); /* add rbx, rax */
x = s->gpr[1]; y = s->gpr[0];
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_555968: STEP(0x555968); /* xor r14d, r12d */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = (s->gpr[12] & UINT64_C(0xffffffff));
s->gpr[14] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55596b: STEP(0x55596b); /* lea eax, [rbx + rbx] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[1] * UINT64_C(0x1))));
++s->steps;
kg_pc_55596e: STEP(0x55596e); /* add eax, 0x50e6b32e */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x50e6b32e);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_555973: STEP(0x555973); /* and eax, 0x66ae764a */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x66ae764a);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_555978: STEP(0x555978); /* neg eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = 0;
s->gpr[0] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55597a: STEP(0x55597a); /* lea r13d, [rbx + rax] */
s->gpr[13] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55597e: STEP(0x55597e); /* add r13d, 0xdbca94bc */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = UINT64_C(0xdbca94bc);
s->gpr[13] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_555985: STEP(0x555985); /* xor r13d, r10d */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_555988: STEP(0x555988); /* lea eax, [rbx - 0x578ca669] */
s->gpr[0] = (uint32_t)((UINT64_C(0xffffffffa8735997) + s->gpr[1]));
++s->steps;
kg_pc_55598e: STEP(0x55598e); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_555990: STEP(0x555990); /* xor ecx, 0xff6fafbf */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xff6fafbf);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_555996: STEP(0x555996); /* and eax, 0xff6fafbf */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xff6fafbf);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55599b: STEP(0x55599b); /* lea r10d, [rcx + rax*2] */
s->gpr[10] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_55599f: STEP(0x55599f); /* lea eax, [r10 + r10] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[10] + (s->gpr[10] * UINT64_C(0x1))));
++s->steps;
kg_pc_5559a3: STEP(0x5559a3); /* add eax, 0x1dd2c268 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1dd2c268);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5559a8: STEP(0x5559a8); /* and eax, 0x13988106 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x13988106);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_5559ad: STEP(0x5559ad); /* xor r13d, 0x73b178da */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = UINT64_C(0x73b178da);
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_5559b4: STEP(0x5559b4); /* sub r10d, eax */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[10] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_5559b7: STEP(0x5559b7); /* add r10d, 0x68b5a1b7 */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x68b5a1b7);
s->gpr[10] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5559be: STEP(0x5559be); /* lea r8d, [r9 + 1] */
s->gpr[8] = (uint32_t)((UINT64_C(0x1) + s->gpr[9]));
++s->steps;
kg_pc_5559c2: STEP(0x5559c2); /* xor r10d, r14d */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_5559c5: STEP(0x5559c5); /* movabs rax, 0x6c62aaf2ca4af6fa */
s->gpr[0] = UINT64_C(0x6c62aaf2ca4af6fa);
++s->steps;
kg_pc_5559cf: STEP(0x5559cf); /* lea rcx, [rax + rbx*2] */
s->gpr[2] = (UINT64_C(0x0) + s->gpr[0] + (s->gpr[1] * UINT64_C(0x2)));
++s->steps;
kg_pc_5559d3: STEP(0x5559d3); /* movabs rdx, 0x61f3960b8ad551b8 */
s->gpr[3] = UINT64_C(0x61f3960b8ad551b8);
++s->steps;
kg_pc_5559dd: STEP(0x5559dd); /* and rcx, rdx */
x = s->gpr[2]; y = s->gpr[3];
s->gpr[2] = operation(s, OP_AND, x, y, 64);
++s->steps;
kg_pc_5559e0: STEP(0x5559e0); /* sub rbx, rcx */
x = s->gpr[1]; y = s->gpr[2];
s->gpr[1] = operation(s, OP_SUB, x, y, 64);
++s->steps;
kg_pc_5559e3: STEP(0x5559e3); /* xor r10d, 0xc74fda3 */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0xc74fda3);
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_5559ea: STEP(0x5559ea); /* movabs rax, 0xa72b207f2a902459 */
s->gpr[0] = UINT64_C(0xa72b207f2a902459);
++s->steps;
kg_pc_5559f4: STEP(0x5559f4); /* add rbx, rax */
x = s->gpr[1]; y = s->gpr[0];
s->gpr[1] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_5559f7: STEP(0x5559f7); /* add r9d, 0xf06aff5e */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0xf06aff5e);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5559fe: STEP(0x5559fe); /* xor ecx, ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_555a00: STEP(0x555a00); /* cmp r9d, dword ptr [rbp - 0x128] */
READ(b, (UINT64_C(0xfffffffffffffed8) + s->gpr[6]), 4);
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = b;
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_555a07: STEP(0x555a07); /* setae cl */
s->gpr[2] = (s->gpr[2] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_AE)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_555a0a: STEP(0x555a0a); /* mov rax, qword ptr [rbp - 0x68] */
READ(a, (UINT64_C(0xffffffffffffff98) + s->gpr[6]), 8);
s->gpr[0] = a;
++s->steps;
kg_pc_555a0e: STEP(0x555a0e); /* mov edx, eax */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_555a10: STEP(0x555a10); /* adc edx, 0 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x0);
s->gpr[3] = (uint32_t)(operation(s, OP_ADC, x, y, 32));
++s->steps;
kg_pc_555a13: STEP(0x555a13); /* shl ecx, 2 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x2);
s->gpr[2] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_555a16: STEP(0x555a16); /* sub eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_555a18: STEP(0x555a18); /* mov qword ptr [rbp - 0x68], rax */
WRITE((UINT64_C(0xffffffffffffff98) + s->gpr[6]), 8, s->gpr[0]);
++s->steps;
kg_pc_555a1c: STEP(0x555a1c); /* xor r15d, edi */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[15] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_555a1f: STEP(0x555a1f); /* xor r15d, esi */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[15] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_555a22: STEP(0x555a22); /* mov r14d, r15d */
s->gpr[14] = (uint32_t)((s->gpr[15] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_555a25: STEP(0x555a25); /* xor r14d, ebx */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[14] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_555a28: STEP(0x555a28); /* mov r15d, r14d */
s->gpr[15] = (uint32_t)((s->gpr[14] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_555a2b: STEP(0x555a2b); /* movsxd rcx, edx */
s->gpr[2] = (((s->gpr[3] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_555a2e: STEP(0x555a2e); /* lea rdx, [rip - 0x540f25] */
s->gpr[3] = (UINT64_C(0xffffffffffabf0db) + (bias + UINT64_C(0x555a35)));
++s->steps;
kg_pc_555a35: STEP(0x555a35); /* movsxd rcx, dword ptr [rdx + rcx*4] */
READ(a, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x4))), 4);
s->gpr[2] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_555a39: STEP(0x555a39); /* lea rax, [rip - 0x520] */
s->gpr[0] = (UINT64_C(0xfffffffffffffae0) + (bias + UINT64_C(0x555a40)));
++s->steps;
kg_pc_555a40: STEP(0x555a40); /* add rcx, rax */
x = s->gpr[2]; y = s->gpr[0];
s->gpr[2] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_555a43: STEP(0x555a43); /* mov r9d, r8d */
s->gpr[9] = (uint32_t)((s->gpr[8] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_555a46: STEP(0x555a46); /* xor r15d, 0x74ec4a72 */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = UINT64_C(0x74ec4a72);
s->gpr[15] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_555a4d: STEP(0x555a4d); /* jmp rcx */
x = s->gpr[2];
next_pc = x;
++s->steps;

break;
    case 2:
next_pc=bias+UINT64_C(0x55695c);
switch(s->pc-bias){
case UINT64_C(0x556660):goto kg_pc_556660;
case UINT64_C(0x556663):goto kg_pc_556663;
case UINT64_C(0x55666a):goto kg_pc_55666a;
case UINT64_C(0x55666e):goto kg_pc_55666e;
case UINT64_C(0x556671):goto kg_pc_556671;
case UINT64_C(0x556675):goto kg_pc_556675;
case UINT64_C(0x55667f):goto kg_pc_55667f;
case UINT64_C(0x556683):goto kg_pc_556683;
case UINT64_C(0x556689):goto kg_pc_556689;
case UINT64_C(0x55668d):goto kg_pc_55668d;
case UINT64_C(0x55668f):goto kg_pc_55668f;
case UINT64_C(0x556695):goto kg_pc_556695;
case UINT64_C(0x556698):goto kg_pc_556698;
case UINT64_C(0x55669b):goto kg_pc_55669b;
case UINT64_C(0x5566a1):goto kg_pc_5566a1;
case UINT64_C(0x5566a7):goto kg_pc_5566a7;
case UINT64_C(0x5566ad):goto kg_pc_5566ad;
case UINT64_C(0x5566b3):goto kg_pc_5566b3;
case UINT64_C(0x5566b5):goto kg_pc_5566b5;
case UINT64_C(0x5566ba):goto kg_pc_5566ba;
case UINT64_C(0x5566bc):goto kg_pc_5566bc;
case UINT64_C(0x5566c2):goto kg_pc_5566c2;
case UINT64_C(0x5566c5):goto kg_pc_5566c5;
case UINT64_C(0x5566cb):goto kg_pc_5566cb;
case UINT64_C(0x5566cd):goto kg_pc_5566cd;
case UINT64_C(0x5566d3):goto kg_pc_5566d3;
case UINT64_C(0x5566d9):goto kg_pc_5566d9;
case UINT64_C(0x5566dc):goto kg_pc_5566dc;
case UINT64_C(0x5566df):goto kg_pc_5566df;
case UINT64_C(0x5566e5):goto kg_pc_5566e5;
case UINT64_C(0x5566e7):goto kg_pc_5566e7;
case UINT64_C(0x5566ea):goto kg_pc_5566ea;
case UINT64_C(0x5566f0):goto kg_pc_5566f0;
case UINT64_C(0x5566f2):goto kg_pc_5566f2;
case UINT64_C(0x5566f5):goto kg_pc_5566f5;
case UINT64_C(0x5566fb):goto kg_pc_5566fb;
case UINT64_C(0x5566fd):goto kg_pc_5566fd;
case UINT64_C(0x556703):goto kg_pc_556703;
case UINT64_C(0x556705):goto kg_pc_556705;
case UINT64_C(0x556708):goto kg_pc_556708;
case UINT64_C(0x55670e):goto kg_pc_55670e;
case UINT64_C(0x556710):goto kg_pc_556710;
case UINT64_C(0x556713):goto kg_pc_556713;
case UINT64_C(0x556719):goto kg_pc_556719;
case UINT64_C(0x55671c):goto kg_pc_55671c;
case UINT64_C(0x556722):goto kg_pc_556722;
case UINT64_C(0x556724):goto kg_pc_556724;
case UINT64_C(0x55672a):goto kg_pc_55672a;
case UINT64_C(0x55672d):goto kg_pc_55672d;
case UINT64_C(0x556733):goto kg_pc_556733;
case UINT64_C(0x556736):goto kg_pc_556736;
case UINT64_C(0x55673c):goto kg_pc_55673c;
case UINT64_C(0x55673e):goto kg_pc_55673e;
case UINT64_C(0x556742):goto kg_pc_556742;
case UINT64_C(0x556749):goto kg_pc_556749;
case UINT64_C(0x55674c):goto kg_pc_55674c;
case UINT64_C(0x556752):goto kg_pc_556752;
case UINT64_C(0x556758):goto kg_pc_556758;
case UINT64_C(0x55675a):goto kg_pc_55675a;
case UINT64_C(0x55675c):goto kg_pc_55675c;
case UINT64_C(0x556762):goto kg_pc_556762;
case UINT64_C(0x556765):goto kg_pc_556765;
case UINT64_C(0x556768):goto kg_pc_556768;
case UINT64_C(0x55676e):goto kg_pc_55676e;
case UINT64_C(0x556774):goto kg_pc_556774;
case UINT64_C(0x556776):goto kg_pc_556776;
case UINT64_C(0x55677c):goto kg_pc_55677c;
case UINT64_C(0x55677e):goto kg_pc_55677e;
case UINT64_C(0x556780):goto kg_pc_556780;
case UINT64_C(0x556786):goto kg_pc_556786;
case UINT64_C(0x556789):goto kg_pc_556789;
case UINT64_C(0x55678f):goto kg_pc_55678f;
case UINT64_C(0x556791):goto kg_pc_556791;
case UINT64_C(0x556797):goto kg_pc_556797;
case UINT64_C(0x55679d):goto kg_pc_55679d;
case UINT64_C(0x5567a0):goto kg_pc_5567a0;
case UINT64_C(0x5567a3):goto kg_pc_5567a3;
case UINT64_C(0x5567a9):goto kg_pc_5567a9;
case UINT64_C(0x5567ab):goto kg_pc_5567ab;
case UINT64_C(0x5567ae):goto kg_pc_5567ae;
case UINT64_C(0x5567b4):goto kg_pc_5567b4;
case UINT64_C(0x5567b6):goto kg_pc_5567b6;
case UINT64_C(0x5567b9):goto kg_pc_5567b9;
case UINT64_C(0x5567bf):goto kg_pc_5567bf;
case UINT64_C(0x5567c1):goto kg_pc_5567c1;
case UINT64_C(0x5567c7):goto kg_pc_5567c7;
case UINT64_C(0x5567c9):goto kg_pc_5567c9;
case UINT64_C(0x5567cc):goto kg_pc_5567cc;
case UINT64_C(0x5567d2):goto kg_pc_5567d2;
case UINT64_C(0x5567d4):goto kg_pc_5567d4;
case UINT64_C(0x5567d7):goto kg_pc_5567d7;
case UINT64_C(0x5567dd):goto kg_pc_5567dd;
case UINT64_C(0x5567e1):goto kg_pc_5567e1;
case UINT64_C(0x5567e8):goto kg_pc_5567e8;
case UINT64_C(0x5567ea):goto kg_pc_5567ea;
case UINT64_C(0x5567f0):goto kg_pc_5567f0;
case UINT64_C(0x5567f3):goto kg_pc_5567f3;
case UINT64_C(0x5567f9):goto kg_pc_5567f9;
case UINT64_C(0x5567fc):goto kg_pc_5567fc;
case UINT64_C(0x556802):goto kg_pc_556802;
case UINT64_C(0x556804):goto kg_pc_556804;
case UINT64_C(0x556808):goto kg_pc_556808;
case UINT64_C(0x55680f):goto kg_pc_55680f;
case UINT64_C(0x556813):goto kg_pc_556813;
case UINT64_C(0x556819):goto kg_pc_556819;
case UINT64_C(0x55681f):goto kg_pc_55681f;
case UINT64_C(0x556822):goto kg_pc_556822;
case UINT64_C(0x556824):goto kg_pc_556824;
case UINT64_C(0x55682a):goto kg_pc_55682a;
case UINT64_C(0x55682c):goto kg_pc_55682c;
case UINT64_C(0x556830):goto kg_pc_556830;
case UINT64_C(0x556836):goto kg_pc_556836;
case UINT64_C(0x55683c):goto kg_pc_55683c;
case UINT64_C(0x55683f):goto kg_pc_55683f;
case UINT64_C(0x556846):goto kg_pc_556846;
case UINT64_C(0x556849):goto kg_pc_556849;
case UINT64_C(0x55684e):goto kg_pc_55684e;
case UINT64_C(0x556851):goto kg_pc_556851;
case UINT64_C(0x556856):goto kg_pc_556856;
case UINT64_C(0x556858):goto kg_pc_556858;
case UINT64_C(0x55685e):goto kg_pc_55685e;
case UINT64_C(0x556863):goto kg_pc_556863;
case UINT64_C(0x556866):goto kg_pc_556866;
case UINT64_C(0x556869):goto kg_pc_556869;
case UINT64_C(0x55686e):goto kg_pc_55686e;
case UINT64_C(0x556870):goto kg_pc_556870;
case UINT64_C(0x556873):goto kg_pc_556873;
case UINT64_C(0x556879):goto kg_pc_556879;
case UINT64_C(0x55687b):goto kg_pc_55687b;
case UINT64_C(0x55687e):goto kg_pc_55687e;
case UINT64_C(0x556883):goto kg_pc_556883;
case UINT64_C(0x556885):goto kg_pc_556885;
case UINT64_C(0x55688b):goto kg_pc_55688b;
case UINT64_C(0x55688d):goto kg_pc_55688d;
case UINT64_C(0x556890):goto kg_pc_556890;
case UINT64_C(0x556896):goto kg_pc_556896;
case UINT64_C(0x556898):goto kg_pc_556898;
case UINT64_C(0x55689b):goto kg_pc_55689b;
case UINT64_C(0x5568a0):goto kg_pc_5568a0;
case UINT64_C(0x5568a3):goto kg_pc_5568a3;
case UINT64_C(0x5568a9):goto kg_pc_5568a9;
case UINT64_C(0x5568ac):goto kg_pc_5568ac;
case UINT64_C(0x5568b2):goto kg_pc_5568b2;
case UINT64_C(0x5568b4):goto kg_pc_5568b4;
case UINT64_C(0x5568b7):goto kg_pc_5568b7;
case UINT64_C(0x5568bd):goto kg_pc_5568bd;
case UINT64_C(0x5568c0):goto kg_pc_5568c0;
case UINT64_C(0x5568c5):goto kg_pc_5568c5;
case UINT64_C(0x5568c7):goto kg_pc_5568c7;
case UINT64_C(0x5568cb):goto kg_pc_5568cb;
case UINT64_C(0x5568d2):goto kg_pc_5568d2;
case UINT64_C(0x5568d5):goto kg_pc_5568d5;
case UINT64_C(0x5568da):goto kg_pc_5568da;
case UINT64_C(0x5568df):goto kg_pc_5568df;
case UINT64_C(0x5568e2):goto kg_pc_5568e2;
case UINT64_C(0x5568e5):goto kg_pc_5568e5;
case UINT64_C(0x5568ec):goto kg_pc_5568ec;
case UINT64_C(0x5568ef):goto kg_pc_5568ef;
case UINT64_C(0x5568f2):goto kg_pc_5568f2;
case UINT64_C(0x5568f7):goto kg_pc_5568f7;
case UINT64_C(0x5568fc):goto kg_pc_5568fc;
case UINT64_C(0x5568fe):goto kg_pc_5568fe;
case UINT64_C(0x556901):goto kg_pc_556901;
case UINT64_C(0x556905):goto kg_pc_556905;
case UINT64_C(0x55690c):goto kg_pc_55690c;
case UINT64_C(0x556910):goto kg_pc_556910;
case UINT64_C(0x556916):goto kg_pc_556916;
case UINT64_C(0x556919):goto kg_pc_556919;
case UINT64_C(0x55691b):goto kg_pc_55691b;
case UINT64_C(0x55691e):goto kg_pc_55691e;
case UINT64_C(0x556925):goto kg_pc_556925;
case UINT64_C(0x556927):goto kg_pc_556927;
case UINT64_C(0x55692b):goto kg_pc_55692b;
case UINT64_C(0x55692e):goto kg_pc_55692e;
case UINT64_C(0x556931):goto kg_pc_556931;
case UINT64_C(0x556935):goto kg_pc_556935;
case UINT64_C(0x556938):goto kg_pc_556938;
case UINT64_C(0x55693b):goto kg_pc_55693b;
case UINT64_C(0x55693e):goto kg_pc_55693e;
case UINT64_C(0x556942):goto kg_pc_556942;
case UINT64_C(0x556945):goto kg_pc_556945;
case UINT64_C(0x55694c):goto kg_pc_55694c;
case UINT64_C(0x556950):goto kg_pc_556950;
case UINT64_C(0x556957):goto kg_pc_556957;
case UINT64_C(0x55695a):goto kg_pc_55695a;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 6358: [0x556660,0x55695c), 185 instructions. */
kg_pc_556660: STEP(0x556660); /* mov r10d, r12d */
s->gpr[10] = (uint32_t)((s->gpr[12] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_556663: STEP(0x556663); /* lea r14d, [r11 - 0x32592bb8] */
s->gpr[14] = (uint32_t)((UINT64_C(0xffffffffcda6d448) + s->gpr[11]));
++s->steps;
kg_pc_55666a: STEP(0x55666a); /* cmp r14d, 0x10 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_55666e: STEP(0x55666e); /* mov r15d, r12d */
s->gpr[15] = (uint32_t)((s->gpr[12] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_556671: STEP(0x556671); /* adc r15d, 0 */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = UINT64_C(0x0);
s->gpr[15] = (uint32_t)(operation(s, OP_ADC, x, y, 32));
++s->steps;
kg_pc_556675: STEP(0x556675); /* movabs rax, 0x100000000 */
s->gpr[0] = UINT64_C(0x100000000);
++s->steps;
kg_pc_55667f: STEP(0x55667f); /* lea edx, [rax + r11] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[11] * UINT64_C(0x1))));
++s->steps;
kg_pc_556683: STEP(0x556683); /* add edx, 0xcda6d447 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xcda6d447);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_556689: STEP(0x556689); /* movzx edx, byte ptr [rbx + rdx] */
READ(a, (UINT64_C(0x0) + s->gpr[1] + (s->gpr[3] * UINT64_C(0x1))), 1);
s->gpr[3] = (uint32_t)(a);
++s->steps;
kg_pc_55668d: STEP(0x55668d); /* mov esi, edx */
s->gpr[4] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55668f: STEP(0x55668f); /* xor esi, 0x61b3fee3 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x61b3fee3);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_556695: STEP(0x556695); /* and edx, 0xffffffe3 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffe3);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_556698: STEP(0x556698); /* lea edx, [rsi + rdx*2] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_55669b: STEP(0x55669b); /* imul eax, edx, 0x1d578b67 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1d578b67);
s->gpr[0] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_5566a1: STEP(0x5566a1); /* imul edx, edx, 0x3aaf16ce */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x3aaf16ce);
s->gpr[3] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_5566a7: STEP(0x5566a7); /* add edx, 0x3e146356 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x3e146356);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5566ad: STEP(0x5566ad); /* and edx, 0x6fa65b84 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x6fa65b84);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_5566b3: STEP(0x5566b3); /* sub eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_5566b5: STEP(0x5566b5); /* add eax, 0xd6dd5f6d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xd6dd5f6d);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5566ba: STEP(0x5566ba); /* xor ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_5566bc: STEP(0x5566bc); /* xor ecx, 0x33f9bae1 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x33f9bae1);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_5566c2: STEP(0x5566c2); /* add ecx, r11d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[11] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5566c5: STEP(0x5566c5); /* add ecx, 0xcda6d447 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xcda6d447);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5566cb: STEP(0x5566cb); /* mov edx, ecx */
s->gpr[3] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_5566cd: STEP(0x5566cd); /* xor edx, 0x7fdf39ff */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x7fdf39ff);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_5566d3: STEP(0x5566d3); /* and ecx, 0xffdf39ff */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xffdf39ff);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_5566d9: STEP(0x5566d9); /* lea edi, [rdx + rcx*2] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x2))));
++s->steps;
kg_pc_5566dc: STEP(0x5566dc); /* lea ecx, [rdx + rcx*2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[2] * UINT64_C(0x2))));
++s->steps;
kg_pc_5566df: STEP(0x5566df); /* add ecx, 0x8020c601 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x8020c601);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5566e5: STEP(0x5566e5); /* mov edx, ecx */
s->gpr[3] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_5566e7: STEP(0x5566e7); /* shr edx, 0x10 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_5566ea: STEP(0x5566ea); /* xor edx, 0x8064b840 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x8064b840);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_5566f0: STEP(0x5566f0); /* add edx, edi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5566f2: STEP(0x5566f2); /* shr ecx, 0xf */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xf);
s->gpr[2] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_5566f5: STEP(0x5566f5); /* and ecx, 0x8f7e */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x8f7e);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_5566fb: STEP(0x5566fb); /* sub edx, ecx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_5566fd: STEP(0x5566fd); /* lea ebx, [rdx - 0x43f23f] */
s->gpr[1] = (uint32_t)((UINT64_C(0xffffffffffbc0dc1) + s->gpr[3]));
++s->steps;
kg_pc_556703: STEP(0x556703); /* mov ecx, ebx */
s->gpr[2] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_556705: STEP(0x556705); /* shr ecx, 8 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[2] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_556708: STEP(0x556708); /* xor ecx, 0x13dfe7bb */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x13dfe7bb);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55670e: STEP(0x55670e); /* add ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_556710: STEP(0x556710); /* shr ebx, 7 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x7);
s->gpr[1] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_556713: STEP(0x556713); /* and ebx, 0x1bfcf76 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x1bfcf76);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_556719: STEP(0x556719); /* lea edi, [rbx + rcx] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_55671c: STEP(0x55671c); /* add edi, 0x76190c2d */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x76190c2d);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_556722: STEP(0x556722); /* add ecx, ebx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_556724: STEP(0x556724); /* add ecx, 0xebdc2606 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xebdc2606);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55672a: STEP(0x55672a); /* xor ecx, r9d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[9] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55672d: STEP(0x55672d); /* xor ecx, 0x8f669fa */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x8f669fa);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_556733: STEP(0x556733); /* lea edx, [rcx + rcx] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_556736: STEP(0x556736); /* and edx, 0x3f3c0b50 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x3f3c0b50);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55673c: STEP(0x55673c); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55673e: STEP(0x55673e); /* lea r9d, [rcx + rdx] */
s->gpr[9] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_556742: STEP(0x556742); /* add r9d, 0x1f9e05a8 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x1f9e05a8);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_556749: STEP(0x556749); /* lea ebx, [rdi + rdi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55674c: STEP(0x55674c); /* add ebx, 0x5685562 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x5685562);
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_556752: STEP(0x556752); /* and ebx, 0xe0c3c78 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0xe0c3c78);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_556758: STEP(0x556758); /* mov ecx, edi */
s->gpr[2] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55675a: STEP(0x55675a); /* sub ecx, ebx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55675c: STEP(0x55675c); /* add ecx, 0x29ba48ed */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x29ba48ed);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_556762: STEP(0x556762); /* xor ecx, r13d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[13] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_556765: STEP(0x556765); /* lea ebx, [rdi + rdi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_556768: STEP(0x556768); /* add ebx, 0x9f4a7712 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x9f4a7712);
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55676e: STEP(0x55676e); /* and ebx, 0x90d009e0 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x90d009e0);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_556774: STEP(0x556774); /* sub edi, ebx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_556776: STEP(0x556776); /* add edi, 0x180d4079 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x180d4079);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55677c: STEP(0x55677c); /* mov esi, eax */
s->gpr[4] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55677e: STEP(0x55677e); /* xor esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_556780: STEP(0x556780); /* xor esi, 0x7fbb2932 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x7fbb2932);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_556786: STEP(0x556786); /* add esi, r11d */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[11] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_556789: STEP(0x556789); /* add esi, 0xcda6d447 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xcda6d447);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55678f: STEP(0x55678f); /* mov ebx, esi */
s->gpr[1] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_556791: STEP(0x556791); /* xor ebx, 0x2bbbf8fb */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x2bbbf8fb);
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_556797: STEP(0x556797); /* and esi, 0x2bbbf8fb */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x2bbbf8fb);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55679d: STEP(0x55679d); /* lea edx, [rbx + rsi*2] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[4] * UINT64_C(0x2))));
++s->steps;
kg_pc_5567a0: STEP(0x5567a0); /* lea esi, [rbx + rsi*2] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[4] * UINT64_C(0x2))));
++s->steps;
kg_pc_5567a3: STEP(0x5567a3); /* add esi, 0xd4440705 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xd4440705);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5567a9: STEP(0x5567a9); /* mov ebx, esi */
s->gpr[1] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_5567ab: STEP(0x5567ab); /* shr ebx, 0x10 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[1] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_5567ae: STEP(0x5567ae); /* xor ebx, 0x90057202 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x90057202);
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_5567b4: STEP(0x5567b4); /* add ebx, edx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5567b6: STEP(0x5567b6); /* shr esi, 0xf */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xf);
s->gpr[4] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_5567b9: STEP(0x5567b9); /* and esi, 0x11bfa */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x11bfa);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_5567bf: STEP(0x5567bf); /* sub ebx, esi */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_5567c1: STEP(0x5567c1); /* lea edx, [rbx + 0x443e9503] */
s->gpr[3] = (uint32_t)((UINT64_C(0x443e9503) + s->gpr[1]));
++s->steps;
kg_pc_5567c7: STEP(0x5567c7); /* mov esi, edx */
s->gpr[4] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_5567c9: STEP(0x5567c9); /* shr esi, 8 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[4] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_5567cc: STEP(0x5567cc); /* xor esi, 0x5e9fff7e */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x5e9fff7e);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_5567d2: STEP(0x5567d2); /* add esi, ebx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5567d4: STEP(0x5567d4); /* shr edx, 7 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x7);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_5567d7: STEP(0x5567d7); /* and edx, 0x13ffefc */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x13ffefc);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_5567dd: STEP(0x5567dd); /* lea r12d, [rdx + rsi] */
s->gpr[12] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_5567e1: STEP(0x5567e1); /* add r12d, 0x5f54dcb8 */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x5f54dcb8);
s->gpr[12] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5567e8: STEP(0x5567e8); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5567ea: STEP(0x5567ea); /* add edx, 0xe59e9585 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xe59e9585);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5567f0: STEP(0x5567f0); /* xor edx, r9d */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[9] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_5567f3: STEP(0x5567f3); /* xor edx, 0x1f9e05a8 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1f9e05a8);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_5567f9: STEP(0x5567f9); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_5567fc: STEP(0x5567fc); /* and esi, 0x92c23f98 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x92c23f98);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_556802: STEP(0x556802); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_556804: STEP(0x556804); /* lea r9d, [rdx + rsi] */
s->gpr[9] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_556808: STEP(0x556808); /* add r9d, 0x49611fcc */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x49611fcc);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55680f: STEP(0x55680f); /* lea esi, [r12 + r12] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[12] + (s->gpr[12] * UINT64_C(0x1))));
++s->steps;
kg_pc_556813: STEP(0x556813); /* add esi, 0x6675934a */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x6675934a);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_556819: STEP(0x556819); /* and esi, 0xf50e760e */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xf50e760e);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55681f: STEP(0x55681f); /* mov edx, r12d */
s->gpr[3] = (uint32_t)((s->gpr[12] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_556822: STEP(0x556822); /* sub edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_556824: STEP(0x556824); /* add edx, 0xadc204ac */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xadc204ac);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55682a: STEP(0x55682a); /* xor edx, ecx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55682c: STEP(0x55682c); /* lea ecx, [r12 + r12] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[12] + (s->gpr[12] * UINT64_C(0x1))));
++s->steps;
kg_pc_556830: STEP(0x556830); /* add ecx, 0x4057b4fa */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x4057b4fa);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_556836: STEP(0x556836); /* and ecx, 0x5030a8ba */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x5030a8ba);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55683c: STEP(0x55683c); /* sub r12d, ecx */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55683f: STEP(0x55683f); /* add r12d, 0x8442eda */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x8442eda);
s->gpr[12] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_556846: STEP(0x556846); /* xor eax, r12d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[12] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_556849: STEP(0x556849); /* xor eax, 0x1fcb799f */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1fcb799f);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55684e: STEP(0x55684e); /* add eax, r11d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[11] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_556851: STEP(0x556851); /* add eax, 0xcda6d447 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xcda6d447);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_556856: STEP(0x556856); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_556858: STEP(0x556858); /* xor ecx, 0xaed53dfa */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xaed53dfa);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55685e: STEP(0x55685e); /* and eax, 0x2ed53dfa */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x2ed53dfa);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_556863: STEP(0x556863); /* lea esi, [rcx + rax*2] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_556866: STEP(0x556866); /* lea eax, [rcx + rax*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_556869: STEP(0x556869); /* add eax, 0x512ac206 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x512ac206);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55686e: STEP(0x55686e); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_556870: STEP(0x556870); /* shr ecx, 0x10 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[2] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_556873: STEP(0x556873); /* xor ecx, 0x20a000b8 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x20a000b8);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_556879: STEP(0x556879); /* add ecx, esi */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55687b: STEP(0x55687b); /* shr eax, 0xf */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xf);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55687e: STEP(0x55687e); /* and eax, 0x1fe8e */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1fe8e);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_556883: STEP(0x556883); /* sub ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_556885: STEP(0x556885); /* lea eax, [rcx + 0x308ac14e] */
s->gpr[0] = (uint32_t)((UINT64_C(0x308ac14e) + s->gpr[2]));
++s->steps;
kg_pc_55688b: STEP(0x55688b); /* mov esi, eax */
s->gpr[4] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55688d: STEP(0x55688d); /* shr esi, 8 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[4] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_556890: STEP(0x556890); /* xor esi, 0xe0db0faf */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xe0db0faf);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_556896: STEP(0x556896); /* add esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_556898: STEP(0x556898); /* shr eax, 7 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x7);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55689b: STEP(0x55689b); /* and eax, 0x1b61f5e */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1b61f5e);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_5568a0: STEP(0x5568a0); /* lea ecx, [rax + rsi] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_5568a3: STEP(0x5568a3); /* add ecx, 0xf957554b */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xf957554b);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5568a9: STEP(0x5568a9); /* lea ebx, [rax + rsi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_5568ac: STEP(0x5568ac); /* add ebx, 0x4fafb19f */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x4fafb19f);
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5568b2: STEP(0x5568b2); /* add esi, eax */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5568b4: STEP(0x5568b4); /* xor ebx, r9d */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[9] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_5568b7: STEP(0x5568b7); /* xor ebx, 0x49611fcc */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x49611fcc);
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_5568bd: STEP(0x5568bd); /* lea eax, [rbx + rbx] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[1] * UINT64_C(0x1))));
++s->steps;
kg_pc_5568c0: STEP(0x5568c0); /* and eax, 0x11ecd3f4 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x11ecd3f4);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_5568c5: STEP(0x5568c5); /* neg eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = 0;
s->gpr[0] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_5568c7: STEP(0x5568c7); /* lea r9d, [rbx + rax] */
s->gpr[9] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_5568cb: STEP(0x5568cb); /* add r9d, 0x8f669fa */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x8f669fa);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5568d2: STEP(0x5568d2); /* lea eax, [rsi + rsi] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_5568d5: STEP(0x5568d5); /* add eax, 0xf94184ee */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xf94184ee);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5568da: STEP(0x5568da); /* and eax, 0x27d7293a */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x27d7293a);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_5568df: STEP(0x5568df); /* mov r13d, ecx */
s->gpr[13] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_5568e2: STEP(0x5568e2); /* sub r13d, eax */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_5568e5: STEP(0x5568e5); /* add r13d, 0x173501c9 */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = UINT64_C(0x173501c9);
s->gpr[13] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5568ec: STEP(0x5568ec); /* xor r13d, edx */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_5568ef: STEP(0x5568ef); /* lea eax, [rsi + rsi] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_5568f2: STEP(0x5568f2); /* add eax, 0xf323a69e */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xf323a69e);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_5568f7: STEP(0x5568f7); /* and eax, 0x8552e46 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x8552e46);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_5568fc: STEP(0x5568fc); /* sub ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_5568fe: STEP(0x5568fe); /* xor edi, r8d */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_556901: STEP(0x556901); /* mov rbx, qword ptr [rbp - 0x38] */
READ(a, (UINT64_C(0xffffffffffffffc8) + s->gpr[6]), 8);
s->gpr[1] = a;
++s->steps;
kg_pc_556905: STEP(0x556905); /* xor r13d, 0x6e6ab1a6 */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = UINT64_C(0x6e6ab1a6);
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55690c: STEP(0x55690c); /* add r11, 1 */
x = s->gpr[11]; y = UINT64_C(0x1);
s->gpr[11] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_556910: STEP(0x556910); /* add ecx, 0xb4651527 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xb4651527);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_556916: STEP(0x556916); /* xor edi, r12d */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[12] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_556919: STEP(0x556919); /* xor edi, ecx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55691b: STEP(0x55691b); /* mov r8d, edi */
s->gpr[8] = (uint32_t)((s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55691e: STEP(0x55691e); /* xor r8d, 0x645ac78e */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x645ac78e);
s->gpr[8] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_556925: STEP(0x556925); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_556927: STEP(0x556927); /* cmp r14d, 0xf */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0xf);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_55692b: STEP(0x55692b); /* seta al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_A)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_55692e: STEP(0x55692e); /* mov r12d, eax */
s->gpr[12] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_556931: STEP(0x556931); /* shl r12d, 5 */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x5);
s->gpr[12] = (uint32_t)(operation(s, OP_SHL, x, y, 32));
++s->steps;
kg_pc_556935: STEP(0x556935); /* sub r12d, eax */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_556938: STEP(0x556938); /* sub r12d, eax */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55693b: STEP(0x55693b); /* add r12d, r10d */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55693e: STEP(0x55693e); /* add r15d, 0x1f */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = UINT64_C(0x1f);
s->gpr[15] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_556942: STEP(0x556942); /* movsxd rax, r15d */
s->gpr[0] = (((s->gpr[15] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_556945: STEP(0x556945); /* lea rdx, [rip - 0x541e3c] */
s->gpr[3] = (UINT64_C(0xffffffffffabe1c4) + (bias + UINT64_C(0x55694c)));
++s->steps;
kg_pc_55694c: STEP(0x55694c); /* movsxd rax, dword ptr [rdx + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_556950: STEP(0x556950); /* lea rdx, [rip - 0x2f7] */
s->gpr[3] = (UINT64_C(0xfffffffffffffd09) + (bias + UINT64_C(0x556957)));
++s->steps;
kg_pc_556957: STEP(0x556957); /* add rax, rdx */
x = s->gpr[0]; y = s->gpr[3];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_55695a: STEP(0x55695a); /* jmp rax */
x = s->gpr[0];
next_pc = x;
++s->steps;

break;
    case 3:
next_pc=bias+UINT64_C(0x55ac82);
switch(s->pc-bias){
case UINT64_C(0x55a960):goto kg_pc_55a960;
case UINT64_C(0x55a963):goto kg_pc_55a963;
case UINT64_C(0x55a969):goto kg_pc_55a969;
case UINT64_C(0x55a96c):goto kg_pc_55a96c;
case UINT64_C(0x55a970):goto kg_pc_55a970;
case UINT64_C(0x55a978):goto kg_pc_55a978;
case UINT64_C(0x55a97b):goto kg_pc_55a97b;
case UINT64_C(0x55a97e):goto kg_pc_55a97e;
case UINT64_C(0x55a981):goto kg_pc_55a981;
case UINT64_C(0x55a984):goto kg_pc_55a984;
case UINT64_C(0x55a98e):goto kg_pc_55a98e;
case UINT64_C(0x55a991):goto kg_pc_55a991;
case UINT64_C(0x55a996):goto kg_pc_55a996;
case UINT64_C(0x55a999):goto kg_pc_55a999;
case UINT64_C(0x55a99d):goto kg_pc_55a99d;
case UINT64_C(0x55a99f):goto kg_pc_55a99f;
case UINT64_C(0x55a9a5):goto kg_pc_55a9a5;
case UINT64_C(0x55a9a8):goto kg_pc_55a9a8;
case UINT64_C(0x55a9ab):goto kg_pc_55a9ab;
case UINT64_C(0x55a9b2):goto kg_pc_55a9b2;
case UINT64_C(0x55a9b8):goto kg_pc_55a9b8;
case UINT64_C(0x55a9bd):goto kg_pc_55a9bd;
case UINT64_C(0x55a9c2):goto kg_pc_55a9c2;
case UINT64_C(0x55a9c5):goto kg_pc_55a9c5;
case UINT64_C(0x55a9cc):goto kg_pc_55a9cc;
case UINT64_C(0x55a9cf):goto kg_pc_55a9cf;
case UINT64_C(0x55a9d6):goto kg_pc_55a9d6;
case UINT64_C(0x55a9da):goto kg_pc_55a9da;
case UINT64_C(0x55a9df):goto kg_pc_55a9df;
case UINT64_C(0x55a9e2):goto kg_pc_55a9e2;
case UINT64_C(0x55a9e4):goto kg_pc_55a9e4;
case UINT64_C(0x55a9ea):goto kg_pc_55a9ea;
case UINT64_C(0x55a9ef):goto kg_pc_55a9ef;
case UINT64_C(0x55a9f2):goto kg_pc_55a9f2;
case UINT64_C(0x55a9f5):goto kg_pc_55a9f5;
case UINT64_C(0x55a9fa):goto kg_pc_55a9fa;
case UINT64_C(0x55a9fd):goto kg_pc_55a9fd;
case UINT64_C(0x55a9ff):goto kg_pc_55a9ff;
case UINT64_C(0x55aa01):goto kg_pc_55aa01;
case UINT64_C(0x55aa03):goto kg_pc_55aa03;
case UINT64_C(0x55aa09):goto kg_pc_55aa09;
case UINT64_C(0x55aa0b):goto kg_pc_55aa0b;
case UINT64_C(0x55aa0e):goto kg_pc_55aa0e;
case UINT64_C(0x55aa14):goto kg_pc_55aa14;
case UINT64_C(0x55aa17):goto kg_pc_55aa17;
case UINT64_C(0x55aa1d):goto kg_pc_55aa1d;
case UINT64_C(0x55aa1f):goto kg_pc_55aa1f;
case UINT64_C(0x55aa22):goto kg_pc_55aa22;
case UINT64_C(0x55aa27):goto kg_pc_55aa27;
case UINT64_C(0x55aa2a):goto kg_pc_55aa2a;
case UINT64_C(0x55aa30):goto kg_pc_55aa30;
case UINT64_C(0x55aa32):goto kg_pc_55aa32;
case UINT64_C(0x55aa35):goto kg_pc_55aa35;
case UINT64_C(0x55aa3b):goto kg_pc_55aa3b;
case UINT64_C(0x55aa42):goto kg_pc_55aa42;
case UINT64_C(0x55aa48):goto kg_pc_55aa48;
case UINT64_C(0x55aa4a):goto kg_pc_55aa4a;
case UINT64_C(0x55aa50):goto kg_pc_55aa50;
case UINT64_C(0x55aa56):goto kg_pc_55aa56;
case UINT64_C(0x55aa5c):goto kg_pc_55aa5c;
case UINT64_C(0x55aa5f):goto kg_pc_55aa5f;
case UINT64_C(0x55aa65):goto kg_pc_55aa65;
case UINT64_C(0x55aa67):goto kg_pc_55aa67;
case UINT64_C(0x55aa69):goto kg_pc_55aa69;
case UINT64_C(0x55aa6f):goto kg_pc_55aa6f;
case UINT64_C(0x55aa75):goto kg_pc_55aa75;
case UINT64_C(0x55aa78):goto kg_pc_55aa78;
case UINT64_C(0x55aa7e):goto kg_pc_55aa7e;
case UINT64_C(0x55aa80):goto kg_pc_55aa80;
case UINT64_C(0x55aa85):goto kg_pc_55aa85;
case UINT64_C(0x55aa88):goto kg_pc_55aa88;
case UINT64_C(0x55aa8e):goto kg_pc_55aa8e;
case UINT64_C(0x55aa92):goto kg_pc_55aa92;
case UINT64_C(0x55aa99):goto kg_pc_55aa99;
case UINT64_C(0x55aa9f):goto kg_pc_55aa9f;
case UINT64_C(0x55aaa1):goto kg_pc_55aaa1;
case UINT64_C(0x55aaa3):goto kg_pc_55aaa3;
case UINT64_C(0x55aaa9):goto kg_pc_55aaa9;
case UINT64_C(0x55aaac):goto kg_pc_55aaac;
case UINT64_C(0x55aab2):goto kg_pc_55aab2;
case UINT64_C(0x55aab5):goto kg_pc_55aab5;
case UINT64_C(0x55aabb):goto kg_pc_55aabb;
case UINT64_C(0x55aabd):goto kg_pc_55aabd;
case UINT64_C(0x55aabf):goto kg_pc_55aabf;
case UINT64_C(0x55aac5):goto kg_pc_55aac5;
case UINT64_C(0x55aacb):goto kg_pc_55aacb;
case UINT64_C(0x55aad1):goto kg_pc_55aad1;
case UINT64_C(0x55aad4):goto kg_pc_55aad4;
case UINT64_C(0x55aad7):goto kg_pc_55aad7;
case UINT64_C(0x55aadd):goto kg_pc_55aadd;
case UINT64_C(0x55aadf):goto kg_pc_55aadf;
case UINT64_C(0x55aae5):goto kg_pc_55aae5;
case UINT64_C(0x55aae7):goto kg_pc_55aae7;
case UINT64_C(0x55aaed):goto kg_pc_55aaed;
case UINT64_C(0x55aaf0):goto kg_pc_55aaf0;
case UINT64_C(0x55aaf6):goto kg_pc_55aaf6;
case UINT64_C(0x55aaf8):goto kg_pc_55aaf8;
case UINT64_C(0x55aafa):goto kg_pc_55aafa;
case UINT64_C(0x55ab00):goto kg_pc_55ab00;
case UINT64_C(0x55ab06):goto kg_pc_55ab06;
case UINT64_C(0x55ab08):goto kg_pc_55ab08;
case UINT64_C(0x55ab0c):goto kg_pc_55ab0c;
case UINT64_C(0x55ab13):goto kg_pc_55ab13;
case UINT64_C(0x55ab16):goto kg_pc_55ab16;
case UINT64_C(0x55ab1c):goto kg_pc_55ab1c;
case UINT64_C(0x55ab22):goto kg_pc_55ab22;
case UINT64_C(0x55ab25):goto kg_pc_55ab25;
case UINT64_C(0x55ab2b):goto kg_pc_55ab2b;
case UINT64_C(0x55ab31):goto kg_pc_55ab31;
case UINT64_C(0x55ab33):goto kg_pc_55ab33;
case UINT64_C(0x55ab35):goto kg_pc_55ab35;
case UINT64_C(0x55ab3b):goto kg_pc_55ab3b;
case UINT64_C(0x55ab3e):goto kg_pc_55ab3e;
case UINT64_C(0x55ab44):goto kg_pc_55ab44;
case UINT64_C(0x55ab46):goto kg_pc_55ab46;
case UINT64_C(0x55ab48):goto kg_pc_55ab48;
case UINT64_C(0x55ab4e):goto kg_pc_55ab4e;
case UINT64_C(0x55ab51):goto kg_pc_55ab51;
case UINT64_C(0x55ab56):goto kg_pc_55ab56;
case UINT64_C(0x55ab5c):goto kg_pc_55ab5c;
case UINT64_C(0x55ab62):goto kg_pc_55ab62;
case UINT64_C(0x55ab68):goto kg_pc_55ab68;
case UINT64_C(0x55ab6b):goto kg_pc_55ab6b;
case UINT64_C(0x55ab70):goto kg_pc_55ab70;
case UINT64_C(0x55ab72):goto kg_pc_55ab72;
case UINT64_C(0x55ab74):goto kg_pc_55ab74;
case UINT64_C(0x55ab79):goto kg_pc_55ab79;
case UINT64_C(0x55ab7e):goto kg_pc_55ab7e;
case UINT64_C(0x55ab81):goto kg_pc_55ab81;
case UINT64_C(0x55ab87):goto kg_pc_55ab87;
case UINT64_C(0x55ab89):goto kg_pc_55ab89;
case UINT64_C(0x55ab8b):goto kg_pc_55ab8b;
case UINT64_C(0x55ab90):goto kg_pc_55ab90;
case UINT64_C(0x55ab96):goto kg_pc_55ab96;
case UINT64_C(0x55ab99):goto kg_pc_55ab99;
case UINT64_C(0x55ab9c):goto kg_pc_55ab9c;
case UINT64_C(0x55ab9e):goto kg_pc_55ab9e;
case UINT64_C(0x55aba3):goto kg_pc_55aba3;
case UINT64_C(0x55aba6):goto kg_pc_55aba6;
case UINT64_C(0x55abad):goto kg_pc_55abad;
case UINT64_C(0x55abb0):goto kg_pc_55abb0;
case UINT64_C(0x55abb5):goto kg_pc_55abb5;
case UINT64_C(0x55abb7):goto kg_pc_55abb7;
case UINT64_C(0x55abbd):goto kg_pc_55abbd;
case UINT64_C(0x55abc2):goto kg_pc_55abc2;
case UINT64_C(0x55abc5):goto kg_pc_55abc5;
case UINT64_C(0x55abc8):goto kg_pc_55abc8;
case UINT64_C(0x55abcd):goto kg_pc_55abcd;
case UINT64_C(0x55abcf):goto kg_pc_55abcf;
case UINT64_C(0x55abd2):goto kg_pc_55abd2;
case UINT64_C(0x55abd8):goto kg_pc_55abd8;
case UINT64_C(0x55abda):goto kg_pc_55abda;
case UINT64_C(0x55abdd):goto kg_pc_55abdd;
case UINT64_C(0x55abe2):goto kg_pc_55abe2;
case UINT64_C(0x55abe4):goto kg_pc_55abe4;
case UINT64_C(0x55abea):goto kg_pc_55abea;
case UINT64_C(0x55abec):goto kg_pc_55abec;
case UINT64_C(0x55abef):goto kg_pc_55abef;
case UINT64_C(0x55abf4):goto kg_pc_55abf4;
case UINT64_C(0x55abf6):goto kg_pc_55abf6;
case UINT64_C(0x55abf9):goto kg_pc_55abf9;
case UINT64_C(0x55abff):goto kg_pc_55abff;
case UINT64_C(0x55ac03):goto kg_pc_55ac03;
case UINT64_C(0x55ac0a):goto kg_pc_55ac0a;
case UINT64_C(0x55ac0d):goto kg_pc_55ac0d;
case UINT64_C(0x55ac13):goto kg_pc_55ac13;
case UINT64_C(0x55ac15):goto kg_pc_55ac15;
case UINT64_C(0x55ac1c):goto kg_pc_55ac1c;
case UINT64_C(0x55ac22):goto kg_pc_55ac22;
case UINT64_C(0x55ac25):goto kg_pc_55ac25;
case UINT64_C(0x55ac2b):goto kg_pc_55ac2b;
case UINT64_C(0x55ac2d):goto kg_pc_55ac2d;
case UINT64_C(0x55ac33):goto kg_pc_55ac33;
case UINT64_C(0x55ac39):goto kg_pc_55ac39;
case UINT64_C(0x55ac3f):goto kg_pc_55ac3f;
case UINT64_C(0x55ac42):goto kg_pc_55ac42;
case UINT64_C(0x55ac48):goto kg_pc_55ac48;
case UINT64_C(0x55ac4a):goto kg_pc_55ac4a;
case UINT64_C(0x55ac4c):goto kg_pc_55ac4c;
case UINT64_C(0x55ac52):goto kg_pc_55ac52;
case UINT64_C(0x55ac58):goto kg_pc_55ac58;
case UINT64_C(0x55ac5b):goto kg_pc_55ac5b;
case UINT64_C(0x55ac61):goto kg_pc_55ac61;
case UINT64_C(0x55ac63):goto kg_pc_55ac63;
case UINT64_C(0x55ac65):goto kg_pc_55ac65;
case UINT64_C(0x55ac6b):goto kg_pc_55ac6b;
case UINT64_C(0x55ac6d):goto kg_pc_55ac6d;
case UINT64_C(0x55ac70):goto kg_pc_55ac70;
case UINT64_C(0x55ac76):goto kg_pc_55ac76;
case UINT64_C(0x55ac7c):goto kg_pc_55ac7c;
case UINT64_C(0x55ac7f):goto kg_pc_55ac7f;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 6359: [0x55a960,0x55ac82), 191 instructions. */
kg_pc_55a960: STEP(0x55a960); /* mov dword ptr [rbp - 0x50], ebx */
WRITE((UINT64_C(0xffffffffffffffb0) + s->gpr[6]), 4, (s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55a963: STEP(0x55a963); /* mov dword ptr [rbp - 0xc0], edi */
WRITE((UINT64_C(0xffffffffffffff40) + s->gpr[6]), 4, (s->gpr[5] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55a969: STEP(0x55a969); /* mov eax, r8d */
s->gpr[0] = (uint32_t)((s->gpr[8] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55a96c: STEP(0x55a96c); /* mov dword ptr [rbp - 0x60], r8d */
WRITE((UINT64_C(0xffffffffffffffa0) + s->gpr[6]), 4, (s->gpr[8] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55a970: STEP(0x55a970); /* lea ecx, [r12 - 0x61d2d3b5] */
s->gpr[2] = (uint32_t)((UINT64_C(0xffffffff9e2d2c4b) + s->gpr[12]));
++s->steps;
kg_pc_55a978: STEP(0x55a978); /* mov dword ptr [rbp - 0x58], ecx */
WRITE((UINT64_C(0xffffffffffffffa8) + s->gpr[6]), 4, (s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55a97b: STEP(0x55a97b); /* cmp ecx, 0x10 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_55a97e: STEP(0x55a97e); /* adc eax, 0 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x0);
s->gpr[0] = (uint32_t)(operation(s, OP_ADC, x, y, 32));
++s->steps;
kg_pc_55a981: STEP(0x55a981); /* mov dword ptr [rbp - 0x68], eax */
WRITE((UINT64_C(0xffffffffffffff98) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55a984: STEP(0x55a984); /* movabs rax, 0x100000000 */
s->gpr[0] = UINT64_C(0x100000000);
++s->steps;
kg_pc_55a98e: STEP(0x55a98e); /* add eax, r12d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[12] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55a991: STEP(0x55a991); /* add eax, 0x9e2d2c4a */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x9e2d2c4a);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55a996: STEP(0x55a996); /* mov rdx, r12 */
s->gpr[3] = s->gpr[12];
++s->steps;
kg_pc_55a999: STEP(0x55a999); /* movzx eax, byte ptr [rsi + rax] */
READ(a, (UINT64_C(0x0) + s->gpr[4] + (s->gpr[0] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_55a99d: STEP(0x55a99d); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55a99f: STEP(0x55a99f); /* xor ecx, 0x8fff0eb9 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x8fff0eb9);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55a9a5: STEP(0x55a9a5); /* and eax, 0xffffffb9 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xffffffb9);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55a9a8: STEP(0x55a9a8); /* lea eax, [rcx + rax*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_55a9ab: STEP(0x55a9ab); /* imul r12d, eax, 0x1d578b67 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1d578b67);
s->gpr[12] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_55a9b2: STEP(0x55a9b2); /* imul eax, eax, 0x3aaf16ce */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x3aaf16ce);
s->gpr[0] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_55a9b8: STEP(0x55a9b8); /* add eax, 0x3b074122 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x3b074122);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55a9bd: STEP(0x55a9bd); /* and eax, 0x541dbd2c */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x541dbd2c);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55a9c2: STEP(0x55a9c2); /* sub r12d, eax */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55a9c5: STEP(0x55a9c5); /* add r12d, 0xc7927f27 */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0xc7927f27);
s->gpr[12] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55a9cc: STEP(0x55a9cc); /* xor r9d, r12d */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = (s->gpr[12] & UINT64_C(0xffffffff));
s->gpr[9] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55a9cf: STEP(0x55a9cf); /* xor r9d, 0x64db7356 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x64db7356);
s->gpr[9] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55a9d6: STEP(0x55a9d6); /* lea eax, [r9 + rdx] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[9] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55a9da: STEP(0x55a9da); /* add eax, 0x9e2d2c4a */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x9e2d2c4a);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55a9df: STEP(0x55a9df); /* mov r8, rdx */
s->gpr[8] = s->gpr[3];
++s->steps;
kg_pc_55a9e2: STEP(0x55a9e2); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55a9e4: STEP(0x55a9e4); /* xor ecx, 0xfef6fdcf */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xfef6fdcf);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55a9ea: STEP(0x55a9ea); /* and eax, 0xfef6fdcf */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xfef6fdcf);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55a9ef: STEP(0x55a9ef); /* lea ebx, [rcx + rax*2] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_55a9f2: STEP(0x55a9f2); /* lea eax, [rcx + rax*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_55a9f5: STEP(0x55a9f5); /* add eax, 0x1090231 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1090231);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55a9fa: STEP(0x55a9fa); /* shr eax, 0x10 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55a9fd: STEP(0x55a9fd); /* add ebx, eax */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55a9ff: STEP(0x55a9ff); /* add eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aa01: STEP(0x55aa01); /* sub ebx, eax */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55aa03: STEP(0x55aa03); /* lea esi, [rbx + 0x1090231] */
s->gpr[4] = (uint32_t)((UINT64_C(0x1090231) + s->gpr[1]));
++s->steps;
kg_pc_55aa09: STEP(0x55aa09); /* mov edx, esi */
s->gpr[3] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55aa0b: STEP(0x55aa0b); /* shr edx, 8 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55aa0e: STEP(0x55aa0e); /* xor edx, 0x9fedf09f */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x9fedf09f);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55aa14: STEP(0x55aa14); /* shr esi, 7 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x7);
s->gpr[4] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55aa17: STEP(0x55aa17); /* and esi, 0x1dbe13e */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x1dbe13e);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55aa1d: STEP(0x55aa1d); /* add edx, ebx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aa1f: STEP(0x55aa1f); /* lea eax, [rsi + rdx] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55aa22: STEP(0x55aa22); /* add eax, 0xc0430001 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xc0430001);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aa27: STEP(0x55aa27); /* lea ecx, [rsi + rdx] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55aa2a: STEP(0x55aa2a); /* add ecx, 0x611b1192 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x611b1192);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aa30: STEP(0x55aa30); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aa32: STEP(0x55aa32); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55aa35: STEP(0x55aa35); /* add esi, 0x80860002 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x80860002);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aa3b: STEP(0x55aa3b); /* lea ebx, [rax*4 - 0x7c9fb9bc] */
s->gpr[1] = (uint32_t)((UINT64_C(0xffffffff83604644) + (s->gpr[0] * UINT64_C(0x4))));
++s->steps;
kg_pc_55aa42: STEP(0x55aa42); /* and ebx, 0xac8dd8a0 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0xac8dd8a0);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55aa48: STEP(0x55aa48); /* sub esi, ebx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55aa4a: STEP(0x55aa4a); /* add esi, 0x97f70f73 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x97f70f73);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aa50: STEP(0x55aa50); /* and esi, 0xedd9d4fe */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xedd9d4fe);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55aa56: STEP(0x55aa56); /* xor esi, 0x65191038 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x65191038);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55aa5c: STEP(0x55aa5c); /* lea ebx, [rsi + rsi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55aa5f: STEP(0x55aa5f); /* and ebx, 0x81a0e8 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x81a0e8);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55aa65: STEP(0x55aa65); /* neg ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = 0;
s->gpr[1] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55aa67: STEP(0x55aa67); /* add esi, ebx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[1] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aa69: STEP(0x55aa69); /* add esi, 0x62d175 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x62d175);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aa6f: STEP(0x55aa6f); /* xor esi, 0x264174 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x264174);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55aa75: STEP(0x55aa75); /* lea ebx, [rsi + rsi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55aa78: STEP(0x55aa78); /* and ebx, 0xc2f4e30 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0xc2f4e30);
s->gpr[1] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55aa7e: STEP(0x55aa7e); /* neg ebx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = 0;
s->gpr[1] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55aa80: STEP(0x55aa80); /* mov edi, 0x9b9244d2 */
s->gpr[5] = (uint32_t)(UINT64_C(0x9b9244d2));
++s->steps;
kg_pc_55aa85: STEP(0x55aa85); /* lea edi, [rdi + rdx*2] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_55aa88: STEP(0x55aa88); /* add edi, 0x80860002 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x80860002);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aa8e: STEP(0x55aa8e); /* lea r9d, [rsi + rbx] */
s->gpr[9] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[1] * UINT64_C(0x1))));
++s->steps;
kg_pc_55aa92: STEP(0x55aa92); /* add r9d, 0x617a718 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x617a718);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aa99: STEP(0x55aa99); /* and edi, 0x885236a2 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x885236a2);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55aa9f: STEP(0x55aa9f); /* mov ebx, eax */
s->gpr[1] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55aaa1: STEP(0x55aaa1); /* sub ebx, edi */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55aaa3: STEP(0x55aaa3); /* add ebx, 0x91f23dba */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x91f23dba);
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aaa9: STEP(0x55aaa9); /* lea edi, [rbx + rbx] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[1] + (s->gpr[1] * UINT64_C(0x1))));
++s->steps;
kg_pc_55aaac: STEP(0x55aaac); /* xor edi, 0x885236a2 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x885236a2);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55aab2: STEP(0x55aab2); /* lea esi, [rdi + rdi] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55aab5: STEP(0x55aab5); /* and esi, 0xb0c69cc8 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xb0c69cc8);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55aabb: STEP(0x55aabb); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55aabd: STEP(0x55aabd); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aabf: STEP(0x55aabf); /* add esi, 0x58634e64 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x58634e64);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aac5: STEP(0x55aac5); /* and esi, 0xedd9d4fe */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xedd9d4fe);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55aacb: STEP(0x55aacb); /* xor esi, 0xc419c03e */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xc419c03e);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55aad1: STEP(0x55aad1); /* xor ecx, r9d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[9] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55aad4: STEP(0x55aad4); /* lea edi, [rsi + rsi] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55aad7: STEP(0x55aad7); /* and edi, 0x81a160 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x81a160);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55aadd: STEP(0x55aadd); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55aadf: STEP(0x55aadf); /* xor ecx, 0x270ae371 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x270ae371);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55aae5: STEP(0x55aae5); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aae7: STEP(0x55aae7); /* add esi, 0x62f9b1 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x62f9b1);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aaed: STEP(0x55aaed); /* lea edi, [rcx + rcx] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_55aaf0: STEP(0x55aaf0); /* and edi, 0x6b529ac4 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x6b529ac4);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55aaf6: STEP(0x55aaf6); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55aaf8: STEP(0x55aaf8); /* add edx, edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aafa: STEP(0x55aafa); /* add edx, 0xf5fa6684 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xf5fa6684);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ab00: STEP(0x55ab00); /* and edx, 0x4b3b210a */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x4b3b210a);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ab06: STEP(0x55ab06); /* sub eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55ab08: STEP(0x55ab08); /* lea r13d, [rcx + rdi] */
s->gpr[13] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ab0c: STEP(0x55ab0c); /* add r13d, 0x35a94d62 */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = UINT64_C(0x35a94d62);
s->gpr[13] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ab13: STEP(0x55ab13); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ab16: STEP(0x55ab16); /* add ecx, 0x40af878c */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x40af878c);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ab1c: STEP(0x55ab1c); /* xor ecx, 0x4b3b210a */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x4b3b210a);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ab22: STEP(0x55ab22); /* lea edx, [rcx + rcx] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ab25: STEP(0x55ab25); /* xor esi, 0x22f4f3 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x22f4f3);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ab2b: STEP(0x55ab2b); /* and edx, 0x36891494 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x36891494);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ab31: STEP(0x55ab31); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55ab33: STEP(0x55ab33); /* add edx, ecx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ab35: STEP(0x55ab35); /* add edx, 0x1b448a4a */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1b448a4a);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ab3b: STEP(0x55ab3b); /* lea edi, [rsi + rsi] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ab3e: STEP(0x55ab3e); /* and edi, 0x11fe7a64 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x11fe7a64);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ab44: STEP(0x55ab44); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55ab46: STEP(0x55ab46); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55ab48: STEP(0x55ab48); /* add ecx, 0x2057c3c6 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x2057c3c6);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ab4e: STEP(0x55ab4e); /* lea eax, [rsi + rdi] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ab51: STEP(0x55ab51); /* add eax, 0x88ff3d33 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x88ff3d33);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ab56: STEP(0x55ab56); /* mov dword ptr [rbp - 0xa8], eax */
WRITE((UINT64_C(0xffffffffffffff58) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55ab5c: STEP(0x55ab5c); /* and edx, 0xedd9d4fe */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xedd9d4fe);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ab62: STEP(0x55ab62); /* xor edx, 0x241950de */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x241950de);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ab68: STEP(0x55ab68); /* lea eax, [rdx + rdx] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ab6b: STEP(0x55ab6b); /* and eax, 0x5901a124 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x5901a124);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ab70: STEP(0x55ab70); /* neg eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = 0;
s->gpr[0] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55ab72: STEP(0x55ab72); /* add eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ab74: STEP(0x55ab74); /* add eax, 0x2e82f292 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x2e82f292);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ab79: STEP(0x55ab79); /* xor eax, 0xabb3216 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xabb3216);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ab7e: STEP(0x55ab7e); /* lea edx, [rax + rax] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ab81: STEP(0x55ab81); /* and edx, 0x84198914 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x84198914);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ab87: STEP(0x55ab87); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55ab89: STEP(0x55ab89); /* add eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ab8b: STEP(0x55ab8b); /* add eax, 0x420ccc8b */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x420ccc8b);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ab90: STEP(0x55ab90); /* mov dword ptr [rbp - 0xc8], eax */
WRITE((UINT64_C(0xffffffffffffff38) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55ab96: STEP(0x55ab96); /* mov eax, r12d */
s->gpr[0] = (uint32_t)((s->gpr[12] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55ab99: STEP(0x55ab99); /* xor r13d, r10d */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[10] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ab9c: STEP(0x55ab9c); /* xor eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ab9e: STEP(0x55ab9e); /* xor eax, 0xf934e13 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xf934e13);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55aba3: STEP(0x55aba3); /* mov r9, r8 */
s->gpr[9] = s->gpr[8];
++s->steps;
kg_pc_55aba6: STEP(0x55aba6); /* mov qword ptr [rbp - 0xa0], r8 */
WRITE((UINT64_C(0xffffffffffffff60) + s->gpr[6]), 8, s->gpr[8]);
++s->steps;
kg_pc_55abad: STEP(0x55abad); /* add eax, r8d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55abb0: STEP(0x55abb0); /* add eax, 0x9e2d2c4a */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x9e2d2c4a);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55abb5: STEP(0x55abb5); /* mov edx, eax */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55abb7: STEP(0x55abb7); /* xor edx, 0x6ad9bf9f */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x6ad9bf9f);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55abbd: STEP(0x55abbd); /* and eax, 0xead9bf9f */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xead9bf9f);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55abc2: STEP(0x55abc2); /* lea esi, [rdx + rax*2] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_55abc5: STEP(0x55abc5); /* lea eax, [rdx + rax*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_55abc8: STEP(0x55abc8); /* add eax, 0x95264061 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x95264061);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55abcd: STEP(0x55abcd); /* mov edx, eax */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55abcf: STEP(0x55abcf); /* shr edx, 0x10 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55abd2: STEP(0x55abd2); /* xor edx, 0x42441c00 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x42441c00);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55abd8: STEP(0x55abd8); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55abda: STEP(0x55abda); /* shr eax, 0xf */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xf);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55abdd: STEP(0x55abdd); /* and eax, 0x1c7fe */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1c7fe);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55abe2: STEP(0x55abe2); /* sub edx, eax */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55abe4: STEP(0x55abe4); /* lea esi, [rdx + 0x52e22461] */
s->gpr[4] = (uint32_t)((UINT64_C(0x52e22461) + s->gpr[3]));
++s->steps;
kg_pc_55abea: STEP(0x55abea); /* mov eax, esi */
s->gpr[0] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55abec: STEP(0x55abec); /* shr eax, 8 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55abef: STEP(0x55abef); /* xor eax, 0x9f7f9e59 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x9f7f9e59);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55abf4: STEP(0x55abf4); /* add eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55abf6: STEP(0x55abf6); /* shr esi, 7 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x7);
s->gpr[4] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55abf9: STEP(0x55abf9); /* and esi, 0xff3cb2 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xff3cb2);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55abff: STEP(0x55abff); /* lea r15d, [rsi + rax] */
s->gpr[15] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ac03: STEP(0x55ac03); /* add r15d, 0xfb956fbd */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = UINT64_C(0xfb956fbd);
s->gpr[15] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ac0a: STEP(0x55ac0a); /* lea edx, [rsi + rax] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ac0d: STEP(0x55ac0d); /* add edx, 0xb3628608 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xb3628608);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ac13: STEP(0x55ac13); /* add eax, esi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ac15: STEP(0x55ac15); /* lea esi, [rax*4 - 0x3275e7e0] */
s->gpr[4] = (uint32_t)((UINT64_C(0xffffffffcd8a1820) + (s->gpr[0] * UINT64_C(0x4))));
++s->steps;
kg_pc_55ac1c: STEP(0x55ac1c); /* and esi, 0x8922f460 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x8922f460);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ac22: STEP(0x55ac22); /* lea edi, [rax + rax] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ac25: STEP(0x55ac25); /* add edi, 0xf72adf7a */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xf72adf7a);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ac2b: STEP(0x55ac2b); /* sub edi, esi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55ac2d: STEP(0x55ac2d); /* add edi, 0xb42ba6c6 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xb42ba6c6);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ac33: STEP(0x55ac33); /* and edi, 0xedd9d4fe */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xedd9d4fe);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ac39: STEP(0x55ac39); /* xor edi, 0x4519d43a */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x4519d43a);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ac3f: STEP(0x55ac3f); /* lea esi, [rdi + rdi] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ac42: STEP(0x55ac42); /* and esi, 0xba0a030 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xba0a030);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ac48: STEP(0x55ac48); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55ac4a: STEP(0x55ac4a); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ac4c: STEP(0x55ac4c); /* add esi, 0x15d47819 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x15d47819);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ac52: STEP(0x55ac52); /* xor esi, 0x5d07813 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x5d07813);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ac58: STEP(0x55ac58); /* lea edi, [rsi + rsi] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ac5b: STEP(0x55ac5b); /* and edi, 0xfae5864c */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xfae5864c);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ac61: STEP(0x55ac61); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55ac63: STEP(0x55ac63); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ac65: STEP(0x55ac65); /* add esi, 0x7d72c327 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x7d72c327);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ac6b: STEP(0x55ac6b); /* xor edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ac6d: STEP(0x55ac6d); /* lea esi, [rax + rax] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ac70: STEP(0x55ac70); /* add esi, 0xa72dc0 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xa72dc0);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ac76: STEP(0x55ac76); /* and esi, 0x264dd5c2 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x264dd5c2);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ac7c: STEP(0x55ac7c); /* mov r11d, r15d */
s->gpr[11] = (uint32_t)((s->gpr[15] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55ac7f: STEP(0x55ac7f); /* sub r11d, esi */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[11] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;

break;
    case 4:
next_pc=bias+UINT64_C(0x55afa2);
switch(s->pc-bias){
case UINT64_C(0x55ac82):goto kg_pc_55ac82;
case UINT64_C(0x55ac89):goto kg_pc_55ac89;
case UINT64_C(0x55ac8d):goto kg_pc_55ac8d;
case UINT64_C(0x55ac93):goto kg_pc_55ac93;
case UINT64_C(0x55ac96):goto kg_pc_55ac96;
case UINT64_C(0x55ac9c):goto kg_pc_55ac9c;
case UINT64_C(0x55ac9e):goto kg_pc_55ac9e;
case UINT64_C(0x55aca0):goto kg_pc_55aca0;
case UINT64_C(0x55aca6):goto kg_pc_55aca6;
case UINT64_C(0x55acac):goto kg_pc_55acac;
case UINT64_C(0x55acb2):goto kg_pc_55acb2;
case UINT64_C(0x55acb5):goto kg_pc_55acb5;
case UINT64_C(0x55acbb):goto kg_pc_55acbb;
case UINT64_C(0x55acbd):goto kg_pc_55acbd;
case UINT64_C(0x55acc1):goto kg_pc_55acc1;
case UINT64_C(0x55acc8):goto kg_pc_55acc8;
case UINT64_C(0x55acca):goto kg_pc_55acca;
case UINT64_C(0x55accf):goto kg_pc_55accf;
case UINT64_C(0x55acd4):goto kg_pc_55acd4;
case UINT64_C(0x55acd7):goto kg_pc_55acd7;
case UINT64_C(0x55acde):goto kg_pc_55acde;
case UINT64_C(0x55ace2):goto kg_pc_55ace2;
case UINT64_C(0x55ace7):goto kg_pc_55ace7;
case UINT64_C(0x55acea):goto kg_pc_55acea;
case UINT64_C(0x55acf0):goto kg_pc_55acf0;
case UINT64_C(0x55acf2):goto kg_pc_55acf2;
case UINT64_C(0x55acf4):goto kg_pc_55acf4;
case UINT64_C(0x55acf9):goto kg_pc_55acf9;
case UINT64_C(0x55acfe):goto kg_pc_55acfe;
case UINT64_C(0x55ad03):goto kg_pc_55ad03;
case UINT64_C(0x55ad06):goto kg_pc_55ad06;
case UINT64_C(0x55ad0c):goto kg_pc_55ad0c;
case UINT64_C(0x55ad0e):goto kg_pc_55ad0e;
case UINT64_C(0x55ad12):goto kg_pc_55ad12;
case UINT64_C(0x55ad19):goto kg_pc_55ad19;
case UINT64_C(0x55ad1f):goto kg_pc_55ad1f;
case UINT64_C(0x55ad22):goto kg_pc_55ad22;
case UINT64_C(0x55ad28):goto kg_pc_55ad28;
case UINT64_C(0x55ad2a):goto kg_pc_55ad2a;
case UINT64_C(0x55ad2d):goto kg_pc_55ad2d;
case UINT64_C(0x55ad32):goto kg_pc_55ad32;
case UINT64_C(0x55ad35):goto kg_pc_55ad35;
case UINT64_C(0x55ad3c):goto kg_pc_55ad3c;
case UINT64_C(0x55ad40):goto kg_pc_55ad40;
case UINT64_C(0x55ad46):goto kg_pc_55ad46;
case UINT64_C(0x55ad48):goto kg_pc_55ad48;
case UINT64_C(0x55ad4e):goto kg_pc_55ad4e;
case UINT64_C(0x55ad54):goto kg_pc_55ad54;
case UINT64_C(0x55ad57):goto kg_pc_55ad57;
case UINT64_C(0x55ad5a):goto kg_pc_55ad5a;
case UINT64_C(0x55ad60):goto kg_pc_55ad60;
case UINT64_C(0x55ad67):goto kg_pc_55ad67;
case UINT64_C(0x55ad6b):goto kg_pc_55ad6b;
case UINT64_C(0x55ad71):goto kg_pc_55ad71;
case UINT64_C(0x55ad73):goto kg_pc_55ad73;
case UINT64_C(0x55ad77):goto kg_pc_55ad77;
case UINT64_C(0x55ad7e):goto kg_pc_55ad7e;
case UINT64_C(0x55ad80):goto kg_pc_55ad80;
case UINT64_C(0x55ad83):goto kg_pc_55ad83;
case UINT64_C(0x55ad89):goto kg_pc_55ad89;
case UINT64_C(0x55ad8b):goto kg_pc_55ad8b;
case UINT64_C(0x55ad8e):goto kg_pc_55ad8e;
case UINT64_C(0x55ad91):goto kg_pc_55ad91;
case UINT64_C(0x55ad94):goto kg_pc_55ad94;
case UINT64_C(0x55ad9a):goto kg_pc_55ad9a;
case UINT64_C(0x55ad9c):goto kg_pc_55ad9c;
case UINT64_C(0x55ada2):goto kg_pc_55ada2;
case UINT64_C(0x55ada4):goto kg_pc_55ada4;
case UINT64_C(0x55ada7):goto kg_pc_55ada7;
case UINT64_C(0x55adad):goto kg_pc_55adad;
case UINT64_C(0x55adaf):goto kg_pc_55adaf;
case UINT64_C(0x55adb2):goto kg_pc_55adb2;
case UINT64_C(0x55adb8):goto kg_pc_55adb8;
case UINT64_C(0x55adbc):goto kg_pc_55adbc;
case UINT64_C(0x55adc3):goto kg_pc_55adc3;
case UINT64_C(0x55adc7):goto kg_pc_55adc7;
case UINT64_C(0x55adcd):goto kg_pc_55adcd;
case UINT64_C(0x55add3):goto kg_pc_55add3;
case UINT64_C(0x55add6):goto kg_pc_55add6;
case UINT64_C(0x55addd):goto kg_pc_55addd;
case UINT64_C(0x55ade1):goto kg_pc_55ade1;
case UINT64_C(0x55ade7):goto kg_pc_55ade7;
case UINT64_C(0x55adea):goto kg_pc_55adea;
case UINT64_C(0x55adf0):goto kg_pc_55adf0;
case UINT64_C(0x55adf2):goto kg_pc_55adf2;
case UINT64_C(0x55adf4):goto kg_pc_55adf4;
case UINT64_C(0x55adfa):goto kg_pc_55adfa;
case UINT64_C(0x55adfd):goto kg_pc_55adfd;
case UINT64_C(0x55ae04):goto kg_pc_55ae04;
case UINT64_C(0x55ae0c):goto kg_pc_55ae0c;
case UINT64_C(0x55ae12):goto kg_pc_55ae12;
case UINT64_C(0x55ae15):goto kg_pc_55ae15;
case UINT64_C(0x55ae17):goto kg_pc_55ae17;
case UINT64_C(0x55ae19):goto kg_pc_55ae19;
case UINT64_C(0x55ae1f):goto kg_pc_55ae1f;
case UINT64_C(0x55ae25):goto kg_pc_55ae25;
case UINT64_C(0x55ae29):goto kg_pc_55ae29;
case UINT64_C(0x55ae30):goto kg_pc_55ae30;
case UINT64_C(0x55ae33):goto kg_pc_55ae33;
case UINT64_C(0x55ae36):goto kg_pc_55ae36;
case UINT64_C(0x55ae3c):goto kg_pc_55ae3c;
case UINT64_C(0x55ae42):goto kg_pc_55ae42;
case UINT64_C(0x55ae48):goto kg_pc_55ae48;
case UINT64_C(0x55ae4b):goto kg_pc_55ae4b;
case UINT64_C(0x55ae50):goto kg_pc_55ae50;
case UINT64_C(0x55ae52):goto kg_pc_55ae52;
case UINT64_C(0x55ae54):goto kg_pc_55ae54;
case UINT64_C(0x55ae59):goto kg_pc_55ae59;
case UINT64_C(0x55ae5f):goto kg_pc_55ae5f;
case UINT64_C(0x55ae65):goto kg_pc_55ae65;
case UINT64_C(0x55ae68):goto kg_pc_55ae68;
case UINT64_C(0x55ae6e):goto kg_pc_55ae6e;
case UINT64_C(0x55ae70):goto kg_pc_55ae70;
case UINT64_C(0x55ae72):goto kg_pc_55ae72;
case UINT64_C(0x55ae78):goto kg_pc_55ae78;
case UINT64_C(0x55ae7b):goto kg_pc_55ae7b;
case UINT64_C(0x55ae80):goto kg_pc_55ae80;
case UINT64_C(0x55ae83):goto kg_pc_55ae83;
case UINT64_C(0x55ae89):goto kg_pc_55ae89;
case UINT64_C(0x55ae8b):goto kg_pc_55ae8b;
case UINT64_C(0x55ae8d):goto kg_pc_55ae8d;
case UINT64_C(0x55ae92):goto kg_pc_55ae92;
case UINT64_C(0x55ae98):goto kg_pc_55ae98;
case UINT64_C(0x55ae9b):goto kg_pc_55ae9b;
case UINT64_C(0x55ae9e):goto kg_pc_55ae9e;
case UINT64_C(0x55aea4):goto kg_pc_55aea4;
case UINT64_C(0x55aea7):goto kg_pc_55aea7;
case UINT64_C(0x55aead):goto kg_pc_55aead;
case UINT64_C(0x55aeaf):goto kg_pc_55aeaf;
case UINT64_C(0x55aeb1):goto kg_pc_55aeb1;
case UINT64_C(0x55aeb7):goto kg_pc_55aeb7;
case UINT64_C(0x55aeb9):goto kg_pc_55aeb9;
case UINT64_C(0x55aebc):goto kg_pc_55aebc;
case UINT64_C(0x55aec2):goto kg_pc_55aec2;
case UINT64_C(0x55aec4):goto kg_pc_55aec4;
case UINT64_C(0x55aec6):goto kg_pc_55aec6;
case UINT64_C(0x55aecd):goto kg_pc_55aecd;
case UINT64_C(0x55aed0):goto kg_pc_55aed0;
case UINT64_C(0x55aed4):goto kg_pc_55aed4;
case UINT64_C(0x55aeda):goto kg_pc_55aeda;
case UINT64_C(0x55aee1):goto kg_pc_55aee1;
case UINT64_C(0x55aee5):goto kg_pc_55aee5;
case UINT64_C(0x55aee8):goto kg_pc_55aee8;
case UINT64_C(0x55aef0):goto kg_pc_55aef0;
case UINT64_C(0x55aef2):goto kg_pc_55aef2;
case UINT64_C(0x55aef7):goto kg_pc_55aef7;
case UINT64_C(0x55aef9):goto kg_pc_55aef9;
case UINT64_C(0x55af00):goto kg_pc_55af00;
case UINT64_C(0x55af06):goto kg_pc_55af06;
case UINT64_C(0x55af08):goto kg_pc_55af08;
case UINT64_C(0x55af0c):goto kg_pc_55af0c;
case UINT64_C(0x55af10):goto kg_pc_55af10;
case UINT64_C(0x55af14):goto kg_pc_55af14;
case UINT64_C(0x55af1b):goto kg_pc_55af1b;
case UINT64_C(0x55af1f):goto kg_pc_55af1f;
case UINT64_C(0x55af24):goto kg_pc_55af24;
case UINT64_C(0x55af27):goto kg_pc_55af27;
case UINT64_C(0x55af2d):goto kg_pc_55af2d;
case UINT64_C(0x55af2f):goto kg_pc_55af2f;
case UINT64_C(0x55af31):goto kg_pc_55af31;
case UINT64_C(0x55af37):goto kg_pc_55af37;
case UINT64_C(0x55af3b):goto kg_pc_55af3b;
case UINT64_C(0x55af40):goto kg_pc_55af40;
case UINT64_C(0x55af44):goto kg_pc_55af44;
case UINT64_C(0x55af4a):goto kg_pc_55af4a;
case UINT64_C(0x55af50):goto kg_pc_55af50;
case UINT64_C(0x55af54):goto kg_pc_55af54;
case UINT64_C(0x55af57):goto kg_pc_55af57;
case UINT64_C(0x55af5d):goto kg_pc_55af5d;
case UINT64_C(0x55af5f):goto kg_pc_55af5f;
case UINT64_C(0x55af61):goto kg_pc_55af61;
case UINT64_C(0x55af67):goto kg_pc_55af67;
case UINT64_C(0x55af6d):goto kg_pc_55af6d;
case UINT64_C(0x55af73):goto kg_pc_55af73;
case UINT64_C(0x55af76):goto kg_pc_55af76;
case UINT64_C(0x55af7c):goto kg_pc_55af7c;
case UINT64_C(0x55af7f):goto kg_pc_55af7f;
case UINT64_C(0x55af85):goto kg_pc_55af85;
case UINT64_C(0x55af87):goto kg_pc_55af87;
case UINT64_C(0x55af89):goto kg_pc_55af89;
case UINT64_C(0x55af8f):goto kg_pc_55af8f;
case UINT64_C(0x55af93):goto kg_pc_55af93;
case UINT64_C(0x55af95):goto kg_pc_55af95;
case UINT64_C(0x55af98):goto kg_pc_55af98;
case UINT64_C(0x55af9a):goto kg_pc_55af9a;
case UINT64_C(0x55af9d):goto kg_pc_55af9d;
case UINT64_C(0x55afa0):goto kg_pc_55afa0;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 6360: [0x55ac82,0x55afa2), 187 instructions. */
kg_pc_55ac82: STEP(0x55ac82); /* add r11d, 0x77e51204 */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = UINT64_C(0x77e51204);
s->gpr[11] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ac89: STEP(0x55ac89); /* lea esi, [r11 + r11] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[11] + (s->gpr[11] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ac8d: STEP(0x55ac8d); /* xor esi, 0x264dd5c2 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x264dd5c2);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ac93: STEP(0x55ac93); /* lea edi, [rsi + rsi] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ac96: STEP(0x55ac96); /* and edi, 0xc9bd6e30 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xc9bd6e30);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ac9c: STEP(0x55ac9c); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55ac9e: STEP(0x55ac9e); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aca0: STEP(0x55aca0); /* add esi, 0x64deb719 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x64deb719);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aca6: STEP(0x55aca6); /* and esi, 0xedd9d4fe */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xedd9d4fe);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55acac: STEP(0x55acac); /* xor esi, 0xa058d460 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xa058d460);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55acb2: STEP(0x55acb2); /* lea edi, [rsi + rsi] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55acb5: STEP(0x55acb5); /* and edi, 0x41b1a01c */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x41b1a01c);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55acbb: STEP(0x55acbb); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55acbd: STEP(0x55acbd); /* lea r8d, [rsi + rdi] */
s->gpr[8] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55acc1: STEP(0x55acc1); /* add r8d, 0xb0fed10e */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0xb0fed10e);
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55acc8: STEP(0x55acc8); /* add eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55acca: STEP(0x55acca); /* add eax, 0x1a894f70 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1a894f70);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55accf: STEP(0x55accf); /* and eax, 0xe697c4d8 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xe697c4d8);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55acd4: STEP(0x55acd4); /* sub r15d, eax */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[15] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55acd7: STEP(0x55acd7); /* add r15d, 0x84fb1a67 */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = UINT64_C(0x84fb1a67);
s->gpr[15] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55acde: STEP(0x55acde); /* lea eax, [r15 + r15] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[15] + (s->gpr[15] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ace2: STEP(0x55ace2); /* xor eax, 0xe697c4d8 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xe697c4d8);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ace7: STEP(0x55ace7); /* lea edi, [rax + rax] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55acea: STEP(0x55acea); /* and edi, 0x45588588 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x45588588);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55acf0: STEP(0x55acf0); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55acf2: STEP(0x55acf2); /* add eax, edi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55acf4: STEP(0x55acf4); /* add eax, 0x22ac42c5 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x22ac42c5);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55acf9: STEP(0x55acf9); /* and eax, 0xedd9d4fe */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xedd9d4fe);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55acfe: STEP(0x55acfe); /* xor eax, 0xc4988024 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xc4988024);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ad03: STEP(0x55ad03); /* lea edi, [rax + rax] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ad06: STEP(0x55ad06); /* and edi, 0x8b31a960 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x8b31a960);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ad0c: STEP(0x55ad0c); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55ad0e: STEP(0x55ad0e); /* lea r14d, [rax + rdi] */
s->gpr[14] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ad12: STEP(0x55ad12); /* add r14d, 0xc7b8fcb0 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0xc7b8fcb0);
s->gpr[14] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ad19: STEP(0x55ad19); /* xor edx, 0x6cfe4727 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x6cfe4727);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ad1f: STEP(0x55ad1f); /* lea edi, [rdx + rdx] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ad22: STEP(0x55ad22); /* and edi, 0xdc56d51a */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xdc56d51a);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ad28: STEP(0x55ad28); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55ad2a: STEP(0x55ad2a); /* lea eax, [rdx + rdi] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ad2d: STEP(0x55ad2d); /* add eax, 0x6e2b6a8d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x6e2b6a8d);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ad32: STEP(0x55ad32); /* xor r12d, r15d */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[15] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ad35: STEP(0x55ad35); /* xor r12d, 0x59453cfa */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x59453cfa);
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ad3c: STEP(0x55ad3c); /* lea edx, [r12 + r9] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[12] + (s->gpr[9] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ad40: STEP(0x55ad40); /* add edx, 0x9e2d2c4a */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x9e2d2c4a);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ad46: STEP(0x55ad46); /* mov edi, edx */
s->gpr[5] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55ad48: STEP(0x55ad48); /* xor edi, 0xd7def336 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xd7def336);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ad4e: STEP(0x55ad4e); /* and edx, 0xd7def336 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xd7def336);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ad54: STEP(0x55ad54); /* lea esi, [rdi + rdx*2] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_55ad57: STEP(0x55ad57); /* lea edx, [rdi + rdx*2] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[3] * UINT64_C(0x2))));
++s->steps;
kg_pc_55ad5a: STEP(0x55ad5a); /* add edx, 0x28210cca */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x28210cca);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ad60: STEP(0x55ad60); /* xor r8d, 0x247c9906 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x247c9906);
s->gpr[8] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ad67: STEP(0x55ad67); /* lea edi, [r8 + r8] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[8] + (s->gpr[8] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ad6b: STEP(0x55ad6b); /* and edi, 0x7e5c59c4 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x7e5c59c4);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ad71: STEP(0x55ad71); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55ad73: STEP(0x55ad73); /* lea r12d, [r8 + rdi] */
s->gpr[12] = (uint32_t)((UINT64_C(0x0) + s->gpr[8] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ad77: STEP(0x55ad77); /* add r12d, 0x3f2e2ce2 */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x3f2e2ce2);
s->gpr[12] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ad7e: STEP(0x55ad7e); /* mov edi, edx */
s->gpr[5] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55ad80: STEP(0x55ad80); /* shr edi, 0x10 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[5] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55ad83: STEP(0x55ad83); /* xor edi, 0xeb501090 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xeb501090);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ad89: STEP(0x55ad89); /* add edi, esi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ad8b: STEP(0x55ad8b); /* xor eax, r13d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[13] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ad8e: STEP(0x55ad8e); /* mov r8d, eax */
s->gpr[8] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55ad91: STEP(0x55ad91); /* shr edx, 0xf */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xf);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55ad94: STEP(0x55ad94); /* and edx, 0x1dede */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1dede);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ad9a: STEP(0x55ad9a); /* sub edi, edx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55ad9c: STEP(0x55ad9c); /* lea edx, [rdi + 0x3cd0fc3a] */
s->gpr[3] = (uint32_t)((UINT64_C(0x3cd0fc3a) + s->gpr[5]));
++s->steps;
kg_pc_55ada2: STEP(0x55ada2); /* mov esi, edx */
s->gpr[4] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55ada4: STEP(0x55ada4); /* shr esi, 8 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[4] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55ada7: STEP(0x55ada7); /* xor esi, 0xeebbe9ea */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xeebbe9ea);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55adad: STEP(0x55adad); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55adaf: STEP(0x55adaf); /* shr edx, 7 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x7);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55adb2: STEP(0x55adb2); /* and edx, 0x177d3d4 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x177d3d4);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55adb8: STEP(0x55adb8); /* lea r10d, [rdx + rsi] */
s->gpr[10] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55adbc: STEP(0x55adbc); /* add r10d, 0x6cb4640c */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x6cb4640c);
s->gpr[10] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55adc3: STEP(0x55adc3); /* lea edx, [r10 + r10] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[10] + (s->gpr[10] * UINT64_C(0x1))));
++s->steps;
kg_pc_55adc7: STEP(0x55adc7); /* add edx, 0xc2c15c88 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xc2c15c88);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55adcd: STEP(0x55adcd); /* and edx, 0xcc63a32c */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xcc63a32c);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55add3: STEP(0x55add3); /* sub r10d, edx */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[10] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55add6: STEP(0x55add6); /* add r10d, 0x47927fda */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x47927fda);
s->gpr[10] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55addd: STEP(0x55addd); /* lea edx, [r10 + r10] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[10] + (s->gpr[10] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ade1: STEP(0x55ade1); /* xor edx, 0xcc63a32c */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xcc63a32c);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ade7: STEP(0x55ade7); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55adea: STEP(0x55adea); /* and esi, 0xada46354 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xada46354);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55adf0: STEP(0x55adf0); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55adf2: STEP(0x55adf2); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55adf4: STEP(0x55adf4); /* add edx, 0x56d231aa */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x56d231aa);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55adfa: STEP(0x55adfa); /* mov r13d, r10d */
s->gpr[13] = (uint32_t)((s->gpr[10] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55adfd: STEP(0x55adfd); /* xor r13d, 0x6631d196 */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = UINT64_C(0x6631d196);
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ae04: STEP(0x55ae04); /* lea esi, [r13 + r13 + 0x59e221b0] */
s->gpr[4] = (uint32_t)((UINT64_C(0x59e221b0) + s->gpr[13] + (s->gpr[13] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ae0c: STEP(0x55ae0c); /* and esi, 0x515ad28a */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x515ad28a);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ae12: STEP(0x55ae12); /* mov edi, r13d */
s->gpr[5] = (uint32_t)((s->gpr[13] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55ae15: STEP(0x55ae15); /* sub edi, esi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55ae17: STEP(0x55ae17); /* add edi, edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ae19: STEP(0x55ae19); /* add edi, 0xab3cf43a */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xab3cf43a);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ae1f: STEP(0x55ae1f); /* xor edi, 0x515ad28a */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x515ad28a);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ae25: STEP(0x55ae25); /* lea r9d, [rdi + rdi] */
s->gpr[9] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ae29: STEP(0x55ae29); /* and r9d, 0x5df1e04 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x5df1e04);
s->gpr[9] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ae30: STEP(0x55ae30); /* neg r9d */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = 0;
s->gpr[9] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55ae33: STEP(0x55ae33); /* add edi, r9d */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[9] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ae36: STEP(0x55ae36); /* add edi, 0x2ef8f02 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x2ef8f02);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ae3c: STEP(0x55ae3c); /* and edx, 0xedd9d4fe */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xedd9d4fe);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ae42: STEP(0x55ae42); /* xor edx, 0x20118414 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x20118414);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ae48: STEP(0x55ae48); /* lea eax, [rdx + rdx] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ae4b: STEP(0x55ae4b); /* and eax, 0x5b232934 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x5b232934);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ae50: STEP(0x55ae50); /* neg eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = 0;
s->gpr[0] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55ae52: STEP(0x55ae52); /* add eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ae54: STEP(0x55ae54); /* add eax, 0x3db3b69a */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x3db3b69a);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ae59: STEP(0x55ae59); /* and edi, 0xedd9d4fe */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xedd9d4fe);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ae5f: STEP(0x55ae5f); /* xor edi, 0xc459009c */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xc459009c);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ae65: STEP(0x55ae65); /* lea edx, [rdi + rdi] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ae68: STEP(0x55ae68); /* and edx, 0x8a92a98c */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x8a92a98c);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ae6e: STEP(0x55ae6e); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55ae70: STEP(0x55ae70); /* add edx, edi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ae72: STEP(0x55ae72); /* add edx, 0xd74f56c6 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xd74f56c6);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ae78: STEP(0x55ae78); /* xor ebx, dword ptr [rbp - 0x50] */
READ(b, (UINT64_C(0xffffffffffffffb0) + s->gpr[6]), 4);
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = b;
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ae7b: STEP(0x55ae7b); /* xor eax, 0xdf29e1f */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xdf29e1f);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ae80: STEP(0x55ae80); /* lea edi, [rax + rax] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55ae83: STEP(0x55ae83); /* and edi, 0x9e8980f2 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x9e8980f2);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55ae89: STEP(0x55ae89); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55ae8b: STEP(0x55ae8b); /* add eax, edi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ae8d: STEP(0x55ae8d); /* add eax, 0x4f44c079 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x4f44c079);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55ae92: STEP(0x55ae92); /* xor ebx, dword ptr [rbp - 0xa8] */
READ(b, (UINT64_C(0xffffffffffffff58) + s->gpr[6]), 4);
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = b;
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ae98: STEP(0x55ae98); /* xor ebx, r11d */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[11] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ae9b: STEP(0x55ae9b); /* xor ebx, r12d */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[12] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55ae9e: STEP(0x55ae9e); /* xor edx, 0x17dfd0d0 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x17dfd0d0);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55aea4: STEP(0x55aea4); /* lea edi, [rdx + rdx] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55aea7: STEP(0x55aea7); /* and edi, 0x1ef30bf8 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x1ef30bf8);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55aead: STEP(0x55aead); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55aeaf: STEP(0x55aeaf); /* add edx, edi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aeb1: STEP(0x55aeb1); /* add edx, 0xf7985fc */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xf7985fc);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aeb7: STEP(0x55aeb7); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55aeb9: STEP(0x55aeb9); /* add esi, r13d */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[13] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aebc: STEP(0x55aebc); /* add esi, 0xd59e7a1d */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xd59e7a1d);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55aec2: STEP(0x55aec2); /* xor ebx, esi */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55aec4: STEP(0x55aec4); /* xor ebx, edx */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55aec6: STEP(0x55aec6); /* xor r14d, 0x23b87c51 */
x = (s->gpr[14] & UINT64_C(0xffffffff)); y = UINT64_C(0x23b87c51);
s->gpr[14] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55aecd: STEP(0x55aecd); /* xor r10d, r8d */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55aed0: STEP(0x55aed0); /* lea edx, [r14 + r14] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[14] + (s->gpr[14] * UINT64_C(0x1))));
++s->steps;
kg_pc_55aed4: STEP(0x55aed4); /* and edx, 0x4325bf3e */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x4325bf3e);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55aeda: STEP(0x55aeda); /* mov r12, qword ptr [rbp - 0xa0] */
READ(a, (UINT64_C(0xffffffffffffff60) + s->gpr[6]), 8);
s->gpr[12] = a;
++s->steps;
kg_pc_55aee1: STEP(0x55aee1); /* add r12, 1 */
x = s->gpr[12]; y = UINT64_C(0x1);
s->gpr[12] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_55aee5: STEP(0x55aee5); /* xor r10d, eax */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55aee8: STEP(0x55aee8); /* lea eax, [r13 + r13 - 0x4c3bbca0] */
s->gpr[0] = (uint32_t)((UINT64_C(0xffffffffb3c44360) + s->gpr[13] + (s->gpr[13] * UINT64_C(0x1))));
++s->steps;
kg_pc_55aef0: STEP(0x55aef0); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55aef2: STEP(0x55aef2); /* and eax, 0x9dab5b80 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x9dab5b80);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55aef7: STEP(0x55aef7); /* neg eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = 0;
s->gpr[0] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55aef9: STEP(0x55aef9); /* xor r10d, 0x26778a3b */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x26778a3b);
s->gpr[10] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55af00: STEP(0x55af00); /* xor ebx, 0x1f108f38 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x1f108f38);
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55af06: STEP(0x55af06); /* xor esi, esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55af08: STEP(0x55af08); /* cmp dword ptr [rbp - 0x58], 0xf */
READ(a, (UINT64_C(0xffffffffffffffa8) + s->gpr[6]), 4);
x = a; y = UINT64_C(0xf);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_55af0c: STEP(0x55af0c); /* seta sil */
s->gpr[4] = (s->gpr[4] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_A)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_55af10: STEP(0x55af10); /* lea r9d, [rax + r13] */
s->gpr[9] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[13] * UINT64_C(0x1))));
++s->steps;
kg_pc_55af14: STEP(0x55af14); /* add r9d, 0xa8b7cf70 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0xa8b7cf70);
s->gpr[9] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55af1b: STEP(0x55af1b); /* lea eax, [r9 + r9] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[9] + (s->gpr[9] * UINT64_C(0x1))));
++s->steps;
kg_pc_55af1f: STEP(0x55af1f); /* xor eax, 0x9dab5b80 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x9dab5b80);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55af24: STEP(0x55af24); /* lea edi, [rax + rax] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55af27: STEP(0x55af27); /* and edi, 0xde2ba580 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xde2ba580);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55af2d: STEP(0x55af2d); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55af2f: STEP(0x55af2f); /* add edi, eax */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55af31: STEP(0x55af31); /* add edi, 0x6f15d2c1 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x6f15d2c1);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55af37: STEP(0x55af37); /* lea eax, [r14 + rdx] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[14] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55af3b: STEP(0x55af3b); /* add eax, 0x2192df9f */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x2192df9f);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55af40: STEP(0x55af40); /* imul r8d, esi, 0x27 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x27);
s->gpr[8] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_55af44: STEP(0x55af44); /* and edi, 0xedd9d4fe */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xedd9d4fe);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55af4a: STEP(0x55af4a); /* xor edi, 0x4c5800cc */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x4c5800cc);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55af50: STEP(0x55af50); /* add r8d, dword ptr [rbp - 0x60] */
READ(b, (UINT64_C(0xffffffffffffffa0) + s->gpr[6]), 4);
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = b;
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55af54: STEP(0x55af54); /* lea edx, [rdi + rdi] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55af57: STEP(0x55af57); /* and edx, 0x383a12c */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x383a12c);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55af5d: STEP(0x55af5d); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55af5f: STEP(0x55af5f); /* add edx, edi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55af61: STEP(0x55af61); /* add edx, 0x1c3d897 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1c3d897);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55af67: STEP(0x55af67); /* xor ecx, dword ptr [rbp - 0xc0] */
{ extern int wrapper_kg_ckc_integrity_word(uint64_t,uint64_t,unsigned,uint64_t *);
wrapper_kg_payload_state *original_=s;wrapper_kg_payload_state candidate_=*s;
uint64_t pair_,first_=(UINT64_C(0xffffffffffffff40) + s->gpr[6]);int middle_valid_=1;s=&candidate_;
x=first_; y=(UINT64_C(0xffffffffffffff38) + s->gpr[6]);
if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){
if(max_steps-s->steps<2){s=original_;return WRAPPER_KG_PAYLOAD_LIMIT;}
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, (s->gpr[2] & UINT64_C(0xffffffff)), pair_, 32));
s->steps+=2;s->pc=bias+UINT64_C(0x55af73);*original_=*s;s=original_;return WRAPPER_KG_PAYLOAD_OK;}
s=original_;if(middle_valid_&&!translate(regions,count,x,4,1)&&!translate(regions,count,y,4,1)&&!wrapper_kg_ckc_integrity_word(x,y,4,&pair_)){s->fault_address=y;s->fault_size=(unsigned)((y-x)&UINT64_C(0xffff));return WRAPPER_KG_PAYLOAD_READ_FAULT;}}
READ(b, (UINT64_C(0xffffffffffffff40) + s->gpr[6]), 4);
x=(s->gpr[2] & UINT64_C(0xffffffff));y=b;
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55af6d: STEP(0x55af6d); /* xor ecx, dword ptr [rbp - 0xc8] */
READ(b, (UINT64_C(0xffffffffffffff38) + s->gpr[6]), 4);
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = b;
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55af73: STEP(0x55af73); /* xor ecx, r15d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[15] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55af76: STEP(0x55af76); /* xor edx, 0xa30b9b */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xa30b9b);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55af7c: STEP(0x55af7c); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55af7f: STEP(0x55af7f); /* and esi, 0x59980a90 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x59980a90);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55af85: STEP(0x55af85); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55af87: STEP(0x55af87); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55af89: STEP(0x55af89); /* add edx, 0x2ccc0548 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x2ccc0548);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55af8f: STEP(0x55af8f); /* mov rsi, qword ptr [rbp - 0x38] */
READ(a, (UINT64_C(0xffffffffffffffc8) + s->gpr[6]), 8);
s->gpr[4] = a;
++s->steps;
kg_pc_55af93: STEP(0x55af93); /* xor ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55af95: STEP(0x55af95); /* xor ecx, r9d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[9] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55af98: STEP(0x55af98); /* xor ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55af9a: STEP(0x55af9a); /* mov eax, dword ptr [rbp - 0x68] */
READ(a, (UINT64_C(0xffffffffffffff98) + s->gpr[6]), 4);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_55af9d: STEP(0x55af9d); /* add eax, 0x23 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x23);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55afa0: STEP(0x55afa0); /* mov edi, ecx */
s->gpr[5] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;

break;
    case 5:
next_pc=bias+UINT64_C(0x55afc1);
switch(s->pc-bias){
case UINT64_C(0x55afa2):goto kg_pc_55afa2;
case UINT64_C(0x55afa4):goto kg_pc_55afa4;
case UINT64_C(0x55afab):goto kg_pc_55afab;
case UINT64_C(0x55afaf):goto kg_pc_55afaf;
case UINT64_C(0x55afb6):goto kg_pc_55afb6;
case UINT64_C(0x55afb9):goto kg_pc_55afb9;
case UINT64_C(0x55afbf):goto kg_pc_55afbf;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 6361: [0x55afa2,0x55afc1), 7 instructions. */
kg_pc_55afa2: STEP(0x55afa2); /* cdqe  */
s->gpr[0] = ((s->gpr[0] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000);
++s->steps;
kg_pc_55afa4: STEP(0x55afa4); /* lea rcx, [rip - 0x54649b] */
s->gpr[2] = (UINT64_C(0xffffffffffab9b65) + (bias + UINT64_C(0x55afab)));
++s->steps;
kg_pc_55afab: STEP(0x55afab); /* movsxd rax, dword ptr [rcx + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_55afaf: STEP(0x55afaf); /* lea rcx, [rip - 0x656] */
s->gpr[2] = (UINT64_C(0xfffffffffffff9aa) + (bias + UINT64_C(0x55afb6)));
++s->steps;
kg_pc_55afb6: STEP(0x55afb6); /* add rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_55afb9: STEP(0x55afb9); /* xor edi, 0x7e089a64 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x7e089a64);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55afbf: STEP(0x55afbf); /* jmp rax */
x = s->gpr[0];
next_pc = x;
++s->steps;

break;
    case 6:
next_pc=bias+UINT64_C(0x55e4f2);
switch(s->pc-bias){
case UINT64_C(0x55e1d0):goto kg_pc_55e1d0;
case UINT64_C(0x55e1d3):goto kg_pc_55e1d3;
case UINT64_C(0x55e1d9):goto kg_pc_55e1d9;
case UINT64_C(0x55e1e0):goto kg_pc_55e1e0;
case UINT64_C(0x55e1e6):goto kg_pc_55e1e6;
case UINT64_C(0x55e1e9):goto kg_pc_55e1e9;
case UINT64_C(0x55e1ed):goto kg_pc_55e1ed;
case UINT64_C(0x55e1f7):goto kg_pc_55e1f7;
case UINT64_C(0x55e1fa):goto kg_pc_55e1fa;
case UINT64_C(0x55e1ff):goto kg_pc_55e1ff;
case UINT64_C(0x55e203):goto kg_pc_55e203;
case UINT64_C(0x55e205):goto kg_pc_55e205;
case UINT64_C(0x55e20b):goto kg_pc_55e20b;
case UINT64_C(0x55e20e):goto kg_pc_55e20e;
case UINT64_C(0x55e214):goto kg_pc_55e214;
case UINT64_C(0x55e21a):goto kg_pc_55e21a;
case UINT64_C(0x55e21f):goto kg_pc_55e21f;
case UINT64_C(0x55e224):goto kg_pc_55e224;
case UINT64_C(0x55e226):goto kg_pc_55e226;
case UINT64_C(0x55e22c):goto kg_pc_55e22c;
case UINT64_C(0x55e22e):goto kg_pc_55e22e;
case UINT64_C(0x55e234):goto kg_pc_55e234;
case UINT64_C(0x55e238):goto kg_pc_55e238;
case UINT64_C(0x55e23d):goto kg_pc_55e23d;
case UINT64_C(0x55e23f):goto kg_pc_55e23f;
case UINT64_C(0x55e245):goto kg_pc_55e245;
case UINT64_C(0x55e24a):goto kg_pc_55e24a;
case UINT64_C(0x55e24d):goto kg_pc_55e24d;
case UINT64_C(0x55e250):goto kg_pc_55e250;
case UINT64_C(0x55e255):goto kg_pc_55e255;
case UINT64_C(0x55e257):goto kg_pc_55e257;
case UINT64_C(0x55e25a):goto kg_pc_55e25a;
case UINT64_C(0x55e260):goto kg_pc_55e260;
case UINT64_C(0x55e262):goto kg_pc_55e262;
case UINT64_C(0x55e265):goto kg_pc_55e265;
case UINT64_C(0x55e26a):goto kg_pc_55e26a;
case UINT64_C(0x55e26c):goto kg_pc_55e26c;
case UINT64_C(0x55e272):goto kg_pc_55e272;
case UINT64_C(0x55e274):goto kg_pc_55e274;
case UINT64_C(0x55e277):goto kg_pc_55e277;
case UINT64_C(0x55e27d):goto kg_pc_55e27d;
case UINT64_C(0x55e27f):goto kg_pc_55e27f;
case UINT64_C(0x55e282):goto kg_pc_55e282;
case UINT64_C(0x55e287):goto kg_pc_55e287;
case UINT64_C(0x55e28a):goto kg_pc_55e28a;
case UINT64_C(0x55e290):goto kg_pc_55e290;
case UINT64_C(0x55e292):goto kg_pc_55e292;
case UINT64_C(0x55e295):goto kg_pc_55e295;
case UINT64_C(0x55e29a):goto kg_pc_55e29a;
case UINT64_C(0x55e29f):goto kg_pc_55e29f;
case UINT64_C(0x55e2a1):goto kg_pc_55e2a1;
case UINT64_C(0x55e2a7):goto kg_pc_55e2a7;
case UINT64_C(0x55e2a9):goto kg_pc_55e2a9;
case UINT64_C(0x55e2ac):goto kg_pc_55e2ac;
case UINT64_C(0x55e2b2):goto kg_pc_55e2b2;
case UINT64_C(0x55e2b8):goto kg_pc_55e2b8;
case UINT64_C(0x55e2bb):goto kg_pc_55e2bb;
case UINT64_C(0x55e2c1):goto kg_pc_55e2c1;
case UINT64_C(0x55e2c3):goto kg_pc_55e2c3;
case UINT64_C(0x55e2c6):goto kg_pc_55e2c6;
case UINT64_C(0x55e2cd):goto kg_pc_55e2cd;
case UINT64_C(0x55e2d1):goto kg_pc_55e2d1;
case UINT64_C(0x55e2d8):goto kg_pc_55e2d8;
case UINT64_C(0x55e2dc):goto kg_pc_55e2dc;
case UINT64_C(0x55e2e2):goto kg_pc_55e2e2;
case UINT64_C(0x55e2e8):goto kg_pc_55e2e8;
case UINT64_C(0x55e2ea):goto kg_pc_55e2ea;
case UINT64_C(0x55e2f1):goto kg_pc_55e2f1;
case UINT64_C(0x55e2f5):goto kg_pc_55e2f5;
case UINT64_C(0x55e2fc):goto kg_pc_55e2fc;
case UINT64_C(0x55e2ff):goto kg_pc_55e2ff;
case UINT64_C(0x55e302):goto kg_pc_55e302;
case UINT64_C(0x55e305):goto kg_pc_55e305;
case UINT64_C(0x55e309):goto kg_pc_55e309;
case UINT64_C(0x55e30f):goto kg_pc_55e30f;
case UINT64_C(0x55e315):goto kg_pc_55e315;
case UINT64_C(0x55e318):goto kg_pc_55e318;
case UINT64_C(0x55e31e):goto kg_pc_55e31e;
case UINT64_C(0x55e324):goto kg_pc_55e324;
case UINT64_C(0x55e328):goto kg_pc_55e328;
case UINT64_C(0x55e32d):goto kg_pc_55e32d;
case UINT64_C(0x55e332):goto kg_pc_55e332;
case UINT64_C(0x55e334):goto kg_pc_55e334;
case UINT64_C(0x55e336):goto kg_pc_55e336;
case UINT64_C(0x55e33a):goto kg_pc_55e33a;
case UINT64_C(0x55e341):goto kg_pc_55e341;
case UINT64_C(0x55e344):goto kg_pc_55e344;
case UINT64_C(0x55e347):goto kg_pc_55e347;
case UINT64_C(0x55e349):goto kg_pc_55e349;
case UINT64_C(0x55e34c):goto kg_pc_55e34c;
case UINT64_C(0x55e34f):goto kg_pc_55e34f;
case UINT64_C(0x55e352):goto kg_pc_55e352;
case UINT64_C(0x55e357):goto kg_pc_55e357;
case UINT64_C(0x55e35a):goto kg_pc_55e35a;
case UINT64_C(0x55e361):goto kg_pc_55e361;
case UINT64_C(0x55e366):goto kg_pc_55e366;
case UINT64_C(0x55e369):goto kg_pc_55e369;
case UINT64_C(0x55e36f):goto kg_pc_55e36f;
case UINT64_C(0x55e373):goto kg_pc_55e373;
case UINT64_C(0x55e37a):goto kg_pc_55e37a;
case UINT64_C(0x55e37c):goto kg_pc_55e37c;
case UINT64_C(0x55e383):goto kg_pc_55e383;
case UINT64_C(0x55e387):goto kg_pc_55e387;
case UINT64_C(0x55e38d):goto kg_pc_55e38d;
case UINT64_C(0x55e38f):goto kg_pc_55e38f;
case UINT64_C(0x55e393):goto kg_pc_55e393;
case UINT64_C(0x55e39a):goto kg_pc_55e39a;
case UINT64_C(0x55e3a0):goto kg_pc_55e3a0;
case UINT64_C(0x55e3a6):goto kg_pc_55e3a6;
case UINT64_C(0x55e3a9):goto kg_pc_55e3a9;
case UINT64_C(0x55e3b0):goto kg_pc_55e3b0;
case UINT64_C(0x55e3b3):goto kg_pc_55e3b3;
case UINT64_C(0x55e3b9):goto kg_pc_55e3b9;
case UINT64_C(0x55e3bb):goto kg_pc_55e3bb;
case UINT64_C(0x55e3be):goto kg_pc_55e3be;
case UINT64_C(0x55e3c4):goto kg_pc_55e3c4;
case UINT64_C(0x55e3c6):goto kg_pc_55e3c6;
case UINT64_C(0x55e3ca):goto kg_pc_55e3ca;
case UINT64_C(0x55e3d0):goto kg_pc_55e3d0;
case UINT64_C(0x55e3d3):goto kg_pc_55e3d3;
case UINT64_C(0x55e3d5):goto kg_pc_55e3d5;
case UINT64_C(0x55e3db):goto kg_pc_55e3db;
case UINT64_C(0x55e3dd):goto kg_pc_55e3dd;
case UINT64_C(0x55e3e3):goto kg_pc_55e3e3;
case UINT64_C(0x55e3e6):goto kg_pc_55e3e6;
case UINT64_C(0x55e3ed):goto kg_pc_55e3ed;
case UINT64_C(0x55e3ef):goto kg_pc_55e3ef;
case UINT64_C(0x55e3f2):goto kg_pc_55e3f2;
case UINT64_C(0x55e3f8):goto kg_pc_55e3f8;
case UINT64_C(0x55e3fa):goto kg_pc_55e3fa;
case UINT64_C(0x55e3fd):goto kg_pc_55e3fd;
case UINT64_C(0x55e402):goto kg_pc_55e402;
case UINT64_C(0x55e404):goto kg_pc_55e404;
case UINT64_C(0x55e409):goto kg_pc_55e409;
case UINT64_C(0x55e40c):goto kg_pc_55e40c;
case UINT64_C(0x55e412):goto kg_pc_55e412;
case UINT64_C(0x55e419):goto kg_pc_55e419;
case UINT64_C(0x55e41f):goto kg_pc_55e41f;
case UINT64_C(0x55e421):goto kg_pc_55e421;
case UINT64_C(0x55e425):goto kg_pc_55e425;
case UINT64_C(0x55e42b):goto kg_pc_55e42b;
case UINT64_C(0x55e42d):goto kg_pc_55e42d;
case UINT64_C(0x55e432):goto kg_pc_55e432;
case UINT64_C(0x55e435):goto kg_pc_55e435;
case UINT64_C(0x55e438):goto kg_pc_55e438;
case UINT64_C(0x55e43f):goto kg_pc_55e43f;
case UINT64_C(0x55e441):goto kg_pc_55e441;
case UINT64_C(0x55e444):goto kg_pc_55e444;
case UINT64_C(0x55e446):goto kg_pc_55e446;
case UINT64_C(0x55e449):goto kg_pc_55e449;
case UINT64_C(0x55e44e):goto kg_pc_55e44e;
case UINT64_C(0x55e453):goto kg_pc_55e453;
case UINT64_C(0x55e456):goto kg_pc_55e456;
case UINT64_C(0x55e45c):goto kg_pc_55e45c;
case UINT64_C(0x55e45e):goto kg_pc_55e45e;
case UINT64_C(0x55e464):goto kg_pc_55e464;
case UINT64_C(0x55e467):goto kg_pc_55e467;
case UINT64_C(0x55e46d):goto kg_pc_55e46d;
case UINT64_C(0x55e473):goto kg_pc_55e473;
case UINT64_C(0x55e476):goto kg_pc_55e476;
case UINT64_C(0x55e47a):goto kg_pc_55e47a;
case UINT64_C(0x55e481):goto kg_pc_55e481;
case UINT64_C(0x55e483):goto kg_pc_55e483;
case UINT64_C(0x55e486):goto kg_pc_55e486;
case UINT64_C(0x55e48c):goto kg_pc_55e48c;
case UINT64_C(0x55e492):goto kg_pc_55e492;
case UINT64_C(0x55e494):goto kg_pc_55e494;
case UINT64_C(0x55e49a):goto kg_pc_55e49a;
case UINT64_C(0x55e49c):goto kg_pc_55e49c;
case UINT64_C(0x55e4a0):goto kg_pc_55e4a0;
case UINT64_C(0x55e4a7):goto kg_pc_55e4a7;
case UINT64_C(0x55e4aa):goto kg_pc_55e4aa;
case UINT64_C(0x55e4b1):goto kg_pc_55e4b1;
case UINT64_C(0x55e4b5):goto kg_pc_55e4b5;
case UINT64_C(0x55e4b8):goto kg_pc_55e4b8;
case UINT64_C(0x55e4bb):goto kg_pc_55e4bb;
case UINT64_C(0x55e4c1):goto kg_pc_55e4c1;
case UINT64_C(0x55e4c7):goto kg_pc_55e4c7;
case UINT64_C(0x55e4cd):goto kg_pc_55e4cd;
case UINT64_C(0x55e4d0):goto kg_pc_55e4d0;
case UINT64_C(0x55e4d2):goto kg_pc_55e4d2;
case UINT64_C(0x55e4d5):goto kg_pc_55e4d5;
case UINT64_C(0x55e4db):goto kg_pc_55e4db;
case UINT64_C(0x55e4de):goto kg_pc_55e4de;
case UINT64_C(0x55e4e0):goto kg_pc_55e4e0;
case UINT64_C(0x55e4e3):goto kg_pc_55e4e3;
case UINT64_C(0x55e4e6):goto kg_pc_55e4e6;
case UINT64_C(0x55e4e9):goto kg_pc_55e4e9;
case UINT64_C(0x55e4ee):goto kg_pc_55e4ee;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 6362: [0x55e1d0,0x55e4f2), 189 instructions. */
kg_pc_55e1d0: STEP(0x55e1d0); /* mov r10d, ebx */
s->gpr[10] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e1d3: STEP(0x55e1d3); /* mov dword ptr [rbp - 0x128], ebx */
WRITE((UINT64_C(0xfffffffffffffed8) + s->gpr[6]), 4, (s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e1d9: STEP(0x55e1d9); /* lea eax, [r14 - 0x23546c62] */
s->gpr[0] = (uint32_t)((UINT64_C(0xffffffffdcab939e) + s->gpr[14]));
++s->steps;
kg_pc_55e1e0: STEP(0x55e1e0); /* mov dword ptr [rbp - 0xb0], eax */
WRITE((UINT64_C(0xffffffffffffff50) + s->gpr[6]), 4, (s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e1e6: STEP(0x55e1e6); /* cmp eax, 0x10 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_55e1e9: STEP(0x55e1e9); /* adc r10d, 0 */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x0);
s->gpr[10] = (uint32_t)(operation(s, OP_ADC, x, y, 32));
++s->steps;
kg_pc_55e1ed: STEP(0x55e1ed); /* movabs rax, 0x100000000 */
s->gpr[0] = UINT64_C(0x100000000);
++s->steps;
kg_pc_55e1f7: STEP(0x55e1f7); /* add eax, r14d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e1fa: STEP(0x55e1fa); /* add eax, 0xdcab939d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xdcab939d);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e1ff: STEP(0x55e1ff); /* movzx eax, byte ptr [rdi + rax] */
READ(a, (UINT64_C(0x0) + s->gpr[5] + (s->gpr[0] * UINT64_C(0x1))), 1);
s->gpr[0] = (uint32_t)(a);
++s->steps;
kg_pc_55e203: STEP(0x55e203); /* mov ecx, eax */
s->gpr[2] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e205: STEP(0x55e205); /* xor ecx, 0x6bd7beff */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x6bd7beff);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e20b: STEP(0x55e20b); /* lea eax, [rcx + rax*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_55e20e: STEP(0x55e20e); /* imul ecx, eax, 0x1d578b67 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x1d578b67);
s->gpr[2] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_55e214: STEP(0x55e214); /* imul eax, eax, 0x3aaf16ce */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x3aaf16ce);
s->gpr[0] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_55e21a: STEP(0x55e21a); /* add eax, 0x57a964ce */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x57a964ce);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e21f: STEP(0x55e21f); /* and eax, 0x9240bfb6 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x9240bfb6);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e224: STEP(0x55e224); /* sub ecx, eax */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55e226: STEP(0x55e226); /* add ecx, 0xf4f51242 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xf4f51242);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e22c: STEP(0x55e22c); /* xor esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e22e: STEP(0x55e22e); /* xor esi, 0x6f7c621c */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x6f7c621c);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e234: STEP(0x55e234); /* lea eax, [rsi + r14] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[14] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e238: STEP(0x55e238); /* add eax, 0xdcab939d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xdcab939d);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e23d: STEP(0x55e23d); /* mov edx, eax */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e23f: STEP(0x55e23f); /* xor edx, 0x7b7f7ebc */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x7b7f7ebc);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e245: STEP(0x55e245); /* and eax, 0xfb7f7ebc */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xfb7f7ebc);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e24a: STEP(0x55e24a); /* lea esi, [rdx + rax*2] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_55e24d: STEP(0x55e24d); /* lea eax, [rdx + rax*2] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[0] * UINT64_C(0x2))));
++s->steps;
kg_pc_55e250: STEP(0x55e250); /* add eax, 0x84808144 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x84808144);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e255: STEP(0x55e255); /* mov edx, eax */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e257: STEP(0x55e257); /* shr edx, 0x10 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e25a: STEP(0x55e25a); /* xor edx, 0xc5203000 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xc5203000);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e260: STEP(0x55e260); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e262: STEP(0x55e262); /* shr eax, 0xf */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xf);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e265: STEP(0x55e265); /* and eax, 0x19ffe */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x19ffe);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e26a: STEP(0x55e26a); /* sub edx, eax */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55e26c: STEP(0x55e26c); /* lea eax, [rdx - 0x409faebc] */
s->gpr[0] = (uint32_t)((UINT64_C(0xffffffffbf605144) + s->gpr[3]));
++s->steps;
kg_pc_55e272: STEP(0x55e272); /* mov esi, eax */
s->gpr[4] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e274: STEP(0x55e274); /* shr esi, 8 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[4] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e277: STEP(0x55e277); /* xor esi, 0x7e3a7b7e */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x7e3a7b7e);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e27d: STEP(0x55e27d); /* add esi, edx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e27f: STEP(0x55e27f); /* shr eax, 7 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x7);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e282: STEP(0x55e282); /* and eax, 0x74f6fc */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x74f6fc);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e287: STEP(0x55e287); /* lea ebx, [rax + rsi] */
s->gpr[1] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e28a: STEP(0x55e28a); /* add ebx, 0xc56ca660 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0xc56ca660);
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e290: STEP(0x55e290); /* add esi, eax */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e292: STEP(0x55e292); /* lea eax, [rsi + rsi] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e295: STEP(0x55e295); /* add eax, 0xc24bab8c */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xc24bab8c);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e29a: STEP(0x55e29a); /* and eax, 0x294711b8 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x294711b8);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e29f: STEP(0x55e29f); /* sub ebx, eax */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55e2a1: STEP(0x55e2a1); /* add ebx, 0x905cb842 */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = UINT64_C(0x905cb842);
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e2a7: STEP(0x55e2a7); /* mov edx, ebx */
s->gpr[3] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e2a9: STEP(0x55e2a9); /* shr edx, 2 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x2);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e2ac: STEP(0x55e2ac); /* and edx, 0xcf57a2f */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xcf57a2f);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e2b2: STEP(0x55e2b2); /* xor edx, 0xcc1300d */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xcc1300d);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e2b8: STEP(0x55e2b8); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e2bb: STEP(0x55e2bb); /* and esi, 0x196ad00c */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x196ad00c);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e2c1: STEP(0x55e2c1); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e2c3: STEP(0x55e2c3); /* mov r11d, ebx */
s->gpr[11] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e2c6: STEP(0x55e2c6); /* xor r11d, 0x14a388dc */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = UINT64_C(0x14a388dc);
s->gpr[11] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e2cd: STEP(0x55e2cd); /* lea r8d, [rdx + rsi] */
s->gpr[8] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e2d1: STEP(0x55e2d1); /* add r8d, 0x1dbd69d6 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x1dbd69d6);
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e2d8: STEP(0x55e2d8); /* lea edx, [r11 + r11] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[11] + (s->gpr[11] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e2dc: STEP(0x55e2dc); /* add edx, 0x19e221b0 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x19e221b0);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e2e2: STEP(0x55e2e2); /* and edx, 0x296478e2 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x296478e2);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e2e8: STEP(0x55e2e8); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e2ea: STEP(0x55e2ea); /* xor r8d, 0x5fcaf94 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x5fcaf94);
s->gpr[8] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e2f1: STEP(0x55e2f1); /* lea r12d, [r11 + rdx] */
s->gpr[12] = (uint32_t)((UINT64_C(0x0) + s->gpr[11] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e2f5: STEP(0x55e2f5); /* add r12d, 0xc1a34d49 */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0xc1a34d49);
s->gpr[12] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e2fc: STEP(0x55e2fc); /* xor r15d, r12d */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = (s->gpr[12] & UINT64_C(0xffffffff));
s->gpr[15] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e2ff: STEP(0x55e2ff); /* mov edx, r12d */
s->gpr[3] = (uint32_t)((s->gpr[12] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e302: STEP(0x55e302); /* shr edx, 2 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x2);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e305: STEP(0x55e305); /* lea edi, [r8 + r8] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[8] + (s->gpr[8] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e309: STEP(0x55e309); /* and edx, 0xcf57a2f */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xcf57a2f);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e30f: STEP(0x55e30f); /* xor edx, 0xcd43208 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xcd43208);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e315: STEP(0x55e315); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e318: STEP(0x55e318); /* and edi, 0x62546876 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x62546876);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e31e: STEP(0x55e31e); /* and esi, 0x48b40c */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x48b40c);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e324: STEP(0x55e324); /* lea eax, [r11 + r11] */
s->gpr[0] = (uint32_t)((UINT64_C(0x0) + s->gpr[11] + (s->gpr[11] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e328: STEP(0x55e328); /* add eax, 0x33c44360 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x33c44360);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e32d: STEP(0x55e32d); /* and eax, 0x37507280 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x37507280);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e332: STEP(0x55e332); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e334: STEP(0x55e334); /* neg eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = 0;
s->gpr[0] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e336: STEP(0x55e336); /* lea r12d, [r11 + rax] */
s->gpr[12] = (uint32_t)((UINT64_C(0x0) + s->gpr[11] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e33a: STEP(0x55e33a); /* add r12d, 0x758a5af0 */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x758a5af0);
s->gpr[12] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e341: STEP(0x55e341); /* mov r11d, ecx */
s->gpr[11] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e344: STEP(0x55e344); /* xor r11d, r12d */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = (s->gpr[12] & UINT64_C(0xffffffff));
s->gpr[11] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e347: STEP(0x55e347); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e349: STEP(0x55e349); /* xor r9d, r12d */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = (s->gpr[12] & UINT64_C(0xffffffff));
s->gpr[9] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e34c: STEP(0x55e34c); /* mov eax, r12d */
s->gpr[0] = (uint32_t)((s->gpr[12] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e34f: STEP(0x55e34f); /* shr eax, 2 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x2);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e352: STEP(0x55e352); /* and eax, 0xcf57a2f */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xcf57a2f);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e357: STEP(0x55e357); /* add r8d, edi */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e35a: STEP(0x55e35a); /* add r8d, 0x312a343b */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x312a343b);
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e361: STEP(0x55e361); /* xor eax, 0x4847a2d */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x4847a2d);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e366: STEP(0x55e366); /* lea edi, [rax + rax] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e369: STEP(0x55e369); /* and edi, 0x8c8c454 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x8c8c454);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e36f: STEP(0x55e36f); /* lea r12d, [rdx + rsi] */
s->gpr[12] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e373: STEP(0x55e373); /* add r12d, 0x265b46 */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x265b46);
s->gpr[12] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e37a: STEP(0x55e37a); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e37c: STEP(0x55e37c); /* xor r11d, 0x5288669b */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = UINT64_C(0x5288669b);
s->gpr[11] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e383: STEP(0x55e383); /* lea esi, [r11 + r14] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[11] + (s->gpr[14] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e387: STEP(0x55e387); /* add esi, 0xdcab939d */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xdcab939d);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e38d: STEP(0x55e38d); /* mov edx, esi */
s->gpr[3] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e38f: STEP(0x55e38f); /* lea r11d, [rax + rdi] */
s->gpr[11] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e393: STEP(0x55e393); /* add r11d, 0x666ee6fa */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = UINT64_C(0x666ee6fa);
s->gpr[11] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e39a: STEP(0x55e39a); /* xor edx, 0x957f2dbd */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x957f2dbd);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e3a0: STEP(0x55e3a0); /* and esi, 0x157f2dbd */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x157f2dbd);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e3a6: STEP(0x55e3a6); /* lea edi, [rdx + rsi*2] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x2))));
++s->steps;
kg_pc_55e3a9: STEP(0x55e3a9); /* xor r12d, 0x6c302 */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x6c302);
s->gpr[12] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e3b0: STEP(0x55e3b0); /* lea edx, [rdx + rsi*2] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[4] * UINT64_C(0x2))));
++s->steps;
kg_pc_55e3b3: STEP(0x55e3b3); /* add edx, 0x6a80d243 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x6a80d243);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e3b9: STEP(0x55e3b9); /* mov esi, edx */
s->gpr[4] = (uint32_t)((s->gpr[3] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e3bb: STEP(0x55e3bb); /* shr esi, 0x10 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[4] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e3be: STEP(0x55e3be); /* xor esi, 0xf0049200 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xf0049200);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e3c4: STEP(0x55e3c4); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e3c6: STEP(0x55e3c6); /* lea edi, [r12 + r12] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[12] + (s->gpr[12] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e3ca: STEP(0x55e3ca); /* and edi, 0x20901474 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x20901474);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e3d0: STEP(0x55e3d0); /* shr edx, 0xf */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xf);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e3d3: STEP(0x55e3d3); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e3d5: STEP(0x55e3d5); /* and edx, 0xdbfe */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xdbfe);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e3db: STEP(0x55e3db); /* sub esi, edx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55e3dd: STEP(0x55e3dd); /* lea eax, [rsi + 0x7a7c4043] */
s->gpr[0] = (uint32_t)((UINT64_C(0x7a7c4043) + s->gpr[4]));
++s->steps;
kg_pc_55e3e3: STEP(0x55e3e3); /* add r12d, edi */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[12] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e3e6: STEP(0x55e3e6); /* add r12d, 0x10480a3a */
x = (s->gpr[12] & UINT64_C(0xffffffff)); y = UINT64_C(0x10480a3a);
s->gpr[12] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e3ed: STEP(0x55e3ed); /* mov edx, eax */
s->gpr[3] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e3ef: STEP(0x55e3ef); /* shr edx, 8 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e3f2: STEP(0x55e3f2); /* xor edx, 0xef73ff7f */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xef73ff7f);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e3f8: STEP(0x55e3f8); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e3fa: STEP(0x55e3fa); /* shr eax, 7 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x7);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e3fd: STEP(0x55e3fd); /* and eax, 0xe7fefe */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xe7fefe);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e402: STEP(0x55e402); /* add eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e404: STEP(0x55e404); /* add eax, 0x84187aa1 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x84187aa1);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e409: STEP(0x55e409); /* lea edx, [rax + rax] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e40c: STEP(0x55e40c); /* add edx, 0xddf8c46 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xddf8c46);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e412: STEP(0x55e412); /* xor r11d, 0x260e67f3 */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = UINT64_C(0x260e67f3);
s->gpr[11] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e419: STEP(0x55e419); /* and edx, 0xad4f7984 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xad4f7984);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e41f: STEP(0x55e41f); /* sub eax, edx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55e421: STEP(0x55e421); /* lea edx, [r11 + r11] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[11] + (s->gpr[11] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e425: STEP(0x55e425); /* and edx, 0xc0459daa */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xc0459daa);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e42b: STEP(0x55e42b); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e42d: STEP(0x55e42d); /* add eax, 0x5d9782e5 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x5d9782e5);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e432: STEP(0x55e432); /* xor ebx, r13d */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[13] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e435: STEP(0x55e435); /* add r11d, edx */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[11] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e438: STEP(0x55e438); /* add r11d, 0x6022ced5 */
x = (s->gpr[11] & UINT64_C(0xffffffff)); y = UINT64_C(0x6022ced5);
s->gpr[11] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e43f: STEP(0x55e43f); /* mov esi, eax */
s->gpr[4] = (uint32_t)((s->gpr[0] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e441: STEP(0x55e441); /* xor ebx, r8d */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e444: STEP(0x55e444); /* xor ebx, eax */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e446: STEP(0x55e446); /* shr eax, 2 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x2);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e449: STEP(0x55e449); /* and eax, 0xcf57a2f */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xcf57a2f);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e44e: STEP(0x55e44e); /* xor eax, 0xc044201 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xc044201);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e453: STEP(0x55e453); /* lea edi, [rax + rax] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e456: STEP(0x55e456); /* and edi, 0x96a8054 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x96a8054);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e45c: STEP(0x55e45c); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e45e: STEP(0x55e45e); /* xor esi, 0x56a7bcc2 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x56a7bcc2);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e464: STEP(0x55e464); /* lea edx, [rsi + rsi] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e467: STEP(0x55e467); /* add edx, 0x59e221b0 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x59e221b0);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e46d: STEP(0x55e46d); /* and edx, 0x71739b48 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x71739b48);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e473: STEP(0x55e473); /* mov r13d, r15d */
s->gpr[13] = (uint32_t)((s->gpr[15] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e476: STEP(0x55e476); /* lea r15d, [rax + rdi] */
s->gpr[15] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e47a: STEP(0x55e47a); /* add r15d, 0xc7bdc5aa */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = UINT64_C(0xc7bdc5aa);
s->gpr[15] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e481: STEP(0x55e481); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e483: STEP(0x55e483); /* lea edi, [rsi + rsi] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e486: STEP(0x55e486); /* add edi, 0xb3c44360 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xb3c44360);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e48c: STEP(0x55e48c); /* and edi, 0x8844dd52 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x8844dd52);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e492: STEP(0x55e492); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e494: STEP(0x55e494); /* add edx, 0xe5aade7c */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xe5aade7c);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e49a: STEP(0x55e49a); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e49c: STEP(0x55e49c); /* lea r8d, [rsi + rdi] */
s->gpr[8] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e4a0: STEP(0x55e4a0); /* add r8d, 0x9e049059 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0x9e049059);
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e4a7: STEP(0x55e4a7); /* xor r13d, r12d */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[12] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e4aa: STEP(0x55e4aa); /* xor r15d, 0x44b8e5aa */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = UINT64_C(0x44b8e5aa);
s->gpr[15] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e4b1: STEP(0x55e4b1); /* lea edi, [r15 + r15] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[15] + (s->gpr[15] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e4b5: STEP(0x55e4b5); /* xor r13d, edx */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e4b8: STEP(0x55e4b8); /* shr edx, 2 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x2);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e4bb: STEP(0x55e4bb); /* and edi, 0xae1c9060 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xae1c9060);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e4c1: STEP(0x55e4c1); /* and edx, 0xcf57a2f */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xcf57a2f);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e4c7: STEP(0x55e4c7); /* xor edx, 0x8d05208 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x8d05208);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e4cd: STEP(0x55e4cd); /* xor r9d, r11d */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = (s->gpr[11] & UINT64_C(0xffffffff));
s->gpr[9] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e4d0: STEP(0x55e4d0); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e4d2: STEP(0x55e4d2); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e4d5: STEP(0x55e4d5); /* and esi, 0x8ea5004 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x8ea5004);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e4db: STEP(0x55e4db); /* xor ecx, r8d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e4de: STEP(0x55e4de); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e4e0: STEP(0x55e4e0); /* xor r9d, r8d */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[9] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e4e3: STEP(0x55e4e3); /* mov eax, r8d */
s->gpr[0] = (uint32_t)((s->gpr[8] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e4e6: STEP(0x55e4e6); /* shr eax, 2 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x2);
s->gpr[0] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e4e9: STEP(0x55e4e9); /* and eax, 0xcf57a2f */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0xcf57a2f);
s->gpr[0] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e4ee: STEP(0x55e4ee); /* lea r8d, [r15 + rdi] */
s->gpr[8] = (uint32_t)((UINT64_C(0x0) + s->gpr[15] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;

break;
    case 7:
next_pc=bias+UINT64_C(0x55e723);
switch(s->pc-bias){
case UINT64_C(0x55e4f2):goto kg_pc_55e4f2;
case UINT64_C(0x55e4f9):goto kg_pc_55e4f9;
case UINT64_C(0x55e4fc):goto kg_pc_55e4fc;
case UINT64_C(0x55e501):goto kg_pc_55e501;
case UINT64_C(0x55e504):goto kg_pc_55e504;
case UINT64_C(0x55e50a):goto kg_pc_55e50a;
case UINT64_C(0x55e50c):goto kg_pc_55e50c;
case UINT64_C(0x55e512):goto kg_pc_55e512;
case UINT64_C(0x55e514):goto kg_pc_55e514;
case UINT64_C(0x55e51a):goto kg_pc_55e51a;
case UINT64_C(0x55e51d):goto kg_pc_55e51d;
case UINT64_C(0x55e523):goto kg_pc_55e523;
case UINT64_C(0x55e525):goto kg_pc_55e525;
case UINT64_C(0x55e527):goto kg_pc_55e527;
case UINT64_C(0x55e52c):goto kg_pc_55e52c;
case UINT64_C(0x55e532):goto kg_pc_55e532;
case UINT64_C(0x55e538):goto kg_pc_55e538;
case UINT64_C(0x55e53b):goto kg_pc_55e53b;
case UINT64_C(0x55e541):goto kg_pc_55e541;
case UINT64_C(0x55e544):goto kg_pc_55e544;
case UINT64_C(0x55e54a):goto kg_pc_55e54a;
case UINT64_C(0x55e54c):goto kg_pc_55e54c;
case UINT64_C(0x55e54f):goto kg_pc_55e54f;
case UINT64_C(0x55e555):goto kg_pc_55e555;
case UINT64_C(0x55e557):goto kg_pc_55e557;
case UINT64_C(0x55e55a):goto kg_pc_55e55a;
case UINT64_C(0x55e560):goto kg_pc_55e560;
case UINT64_C(0x55e563):goto kg_pc_55e563;
case UINT64_C(0x55e565):goto kg_pc_55e565;
case UINT64_C(0x55e56b):goto kg_pc_55e56b;
case UINT64_C(0x55e56d):goto kg_pc_55e56d;
case UINT64_C(0x55e573):goto kg_pc_55e573;
case UINT64_C(0x55e575):goto kg_pc_55e575;
case UINT64_C(0x55e57b):goto kg_pc_55e57b;
case UINT64_C(0x55e57d):goto kg_pc_55e57d;
case UINT64_C(0x55e580):goto kg_pc_55e580;
case UINT64_C(0x55e586):goto kg_pc_55e586;
case UINT64_C(0x55e589):goto kg_pc_55e589;
case UINT64_C(0x55e58b):goto kg_pc_55e58b;
case UINT64_C(0x55e591):goto kg_pc_55e591;
case UINT64_C(0x55e594):goto kg_pc_55e594;
case UINT64_C(0x55e59a):goto kg_pc_55e59a;
case UINT64_C(0x55e59c):goto kg_pc_55e59c;
case UINT64_C(0x55e5a1):goto kg_pc_55e5a1;
case UINT64_C(0x55e5a4):goto kg_pc_55e5a4;
case UINT64_C(0x55e5aa):goto kg_pc_55e5aa;
case UINT64_C(0x55e5b0):goto kg_pc_55e5b0;
case UINT64_C(0x55e5b2):goto kg_pc_55e5b2;
case UINT64_C(0x55e5b5):goto kg_pc_55e5b5;
case UINT64_C(0x55e5bb):goto kg_pc_55e5bb;
case UINT64_C(0x55e5bd):goto kg_pc_55e5bd;
case UINT64_C(0x55e5c3):goto kg_pc_55e5c3;
case UINT64_C(0x55e5c5):goto kg_pc_55e5c5;
case UINT64_C(0x55e5ca):goto kg_pc_55e5ca;
case UINT64_C(0x55e5cc):goto kg_pc_55e5cc;
case UINT64_C(0x55e5cf):goto kg_pc_55e5cf;
case UINT64_C(0x55e5d1):goto kg_pc_55e5d1;
case UINT64_C(0x55e5d4):goto kg_pc_55e5d4;
case UINT64_C(0x55e5da):goto kg_pc_55e5da;
case UINT64_C(0x55e5e0):goto kg_pc_55e5e0;
case UINT64_C(0x55e5e3):goto kg_pc_55e5e3;
case UINT64_C(0x55e5e9):goto kg_pc_55e5e9;
case UINT64_C(0x55e5eb):goto kg_pc_55e5eb;
case UINT64_C(0x55e5ed):goto kg_pc_55e5ed;
case UINT64_C(0x55e5f3):goto kg_pc_55e5f3;
case UINT64_C(0x55e5f9):goto kg_pc_55e5f9;
case UINT64_C(0x55e5ff):goto kg_pc_55e5ff;
case UINT64_C(0x55e602):goto kg_pc_55e602;
case UINT64_C(0x55e605):goto kg_pc_55e605;
case UINT64_C(0x55e608):goto kg_pc_55e608;
case UINT64_C(0x55e60e):goto kg_pc_55e60e;
case UINT64_C(0x55e614):goto kg_pc_55e614;
case UINT64_C(0x55e61a):goto kg_pc_55e61a;
case UINT64_C(0x55e61c):goto kg_pc_55e61c;
case UINT64_C(0x55e61e):goto kg_pc_55e61e;
case UINT64_C(0x55e624):goto kg_pc_55e624;
case UINT64_C(0x55e627):goto kg_pc_55e627;
case UINT64_C(0x55e629):goto kg_pc_55e629;
case UINT64_C(0x55e62c):goto kg_pc_55e62c;
case UINT64_C(0x55e632):goto kg_pc_55e632;
case UINT64_C(0x55e638):goto kg_pc_55e638;
case UINT64_C(0x55e63a):goto kg_pc_55e63a;
case UINT64_C(0x55e640):goto kg_pc_55e640;
case UINT64_C(0x55e643):goto kg_pc_55e643;
case UINT64_C(0x55e649):goto kg_pc_55e649;
case UINT64_C(0x55e64b):goto kg_pc_55e64b;
case UINT64_C(0x55e64d):goto kg_pc_55e64d;
case UINT64_C(0x55e653):goto kg_pc_55e653;
case UINT64_C(0x55e656):goto kg_pc_55e656;
case UINT64_C(0x55e65c):goto kg_pc_55e65c;
case UINT64_C(0x55e662):goto kg_pc_55e662;
case UINT64_C(0x55e664):goto kg_pc_55e664;
case UINT64_C(0x55e66a):goto kg_pc_55e66a;
case UINT64_C(0x55e66c):goto kg_pc_55e66c;
case UINT64_C(0x55e672):goto kg_pc_55e672;
case UINT64_C(0x55e675):goto kg_pc_55e675;
case UINT64_C(0x55e67b):goto kg_pc_55e67b;
case UINT64_C(0x55e67d):goto kg_pc_55e67d;
case UINT64_C(0x55e67f):goto kg_pc_55e67f;
case UINT64_C(0x55e681):goto kg_pc_55e681;
case UINT64_C(0x55e684):goto kg_pc_55e684;
case UINT64_C(0x55e68a):goto kg_pc_55e68a;
case UINT64_C(0x55e68c):goto kg_pc_55e68c;
case UINT64_C(0x55e692):goto kg_pc_55e692;
case UINT64_C(0x55e698):goto kg_pc_55e698;
case UINT64_C(0x55e69b):goto kg_pc_55e69b;
case UINT64_C(0x55e6a1):goto kg_pc_55e6a1;
case UINT64_C(0x55e6a3):goto kg_pc_55e6a3;
case UINT64_C(0x55e6a5):goto kg_pc_55e6a5;
case UINT64_C(0x55e6ab):goto kg_pc_55e6ab;
case UINT64_C(0x55e6b1):goto kg_pc_55e6b1;
case UINT64_C(0x55e6b4):goto kg_pc_55e6b4;
case UINT64_C(0x55e6ba):goto kg_pc_55e6ba;
case UINT64_C(0x55e6bc):goto kg_pc_55e6bc;
case UINT64_C(0x55e6be):goto kg_pc_55e6be;
case UINT64_C(0x55e6c4):goto kg_pc_55e6c4;
case UINT64_C(0x55e6c8):goto kg_pc_55e6c8;
case UINT64_C(0x55e6cb):goto kg_pc_55e6cb;
case UINT64_C(0x55e6ce):goto kg_pc_55e6ce;
case UINT64_C(0x55e6d1):goto kg_pc_55e6d1;
case UINT64_C(0x55e6d8):goto kg_pc_55e6d8;
case UINT64_C(0x55e6db):goto kg_pc_55e6db;
case UINT64_C(0x55e6de):goto kg_pc_55e6de;
case UINT64_C(0x55e6e5):goto kg_pc_55e6e5;
case UINT64_C(0x55e6ec):goto kg_pc_55e6ec;
case UINT64_C(0x55e6f0):goto kg_pc_55e6f0;
case UINT64_C(0x55e6f2):goto kg_pc_55e6f2;
case UINT64_C(0x55e6f9):goto kg_pc_55e6f9;
case UINT64_C(0x55e6fc):goto kg_pc_55e6fc;
case UINT64_C(0x55e6ff):goto kg_pc_55e6ff;
case UINT64_C(0x55e705):goto kg_pc_55e705;
case UINT64_C(0x55e709):goto kg_pc_55e709;
case UINT64_C(0x55e70c):goto kg_pc_55e70c;
case UINT64_C(0x55e713):goto kg_pc_55e713;
case UINT64_C(0x55e717):goto kg_pc_55e717;
case UINT64_C(0x55e71e):goto kg_pc_55e71e;
case UINT64_C(0x55e721):goto kg_pc_55e721;
default:return WRAPPER_KG_PAYLOAD_INVALID;} 
/* Generated by generate_payload.py; no executable bytes.
 * ELF SHA256: 1c8e1b64f7e966c2f78ba2582a1ec30a0aff8ad7ef8221117853f34d9b7faa3b
 * Path 6363: [0x55e4f2,0x55e723), 137 instructions. */
kg_pc_55e4f2: STEP(0x55e4f2); /* add r8d, 0xd70e4d30 */
x = (s->gpr[8] & UINT64_C(0xffffffff)); y = UINT64_C(0xd70e4d30);
s->gpr[8] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e4f9: STEP(0x55e4f9); /* mov r15d, r13d */
s->gpr[15] = (uint32_t)((s->gpr[13] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e4fc: STEP(0x55e4fc); /* xor eax, 0x402e */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x402e);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e501: STEP(0x55e501); /* lea edi, [rax + rax] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e504: STEP(0x55e504); /* and edi, 0x842d05e */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x842d05e);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e50a: STEP(0x55e50a); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e50c: STEP(0x55e50c); /* add edx, 0x74752842 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x74752842);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e512: STEP(0x55e512); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e514: STEP(0x55e514); /* xor ecx, 0xd023172 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xd023172);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e51a: STEP(0x55e51a); /* add ecx, r14d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[14] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e51d: STEP(0x55e51d); /* add ecx, 0xdcab939d */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xdcab939d);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e523: STEP(0x55e523); /* mov esi, ecx */
s->gpr[4] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e525: STEP(0x55e525); /* add eax, edi */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e527: STEP(0x55e527); /* add eax, 0x142969af */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x142969af);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e52c: STEP(0x55e52c); /* xor esi, 0xffb5f9fd */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xffb5f9fd);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e532: STEP(0x55e532); /* and ecx, 0xffb5f9fd */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xffb5f9fd);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e538: STEP(0x55e538); /* lea edi, [rsi + rcx*2] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[2] * UINT64_C(0x2))));
++s->steps;
kg_pc_55e53b: STEP(0x55e53b); /* xor edx, 0x30810843 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x30810843);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e541: STEP(0x55e541); /* lea ecx, [rsi + rcx*2] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[2] * UINT64_C(0x2))));
++s->steps;
kg_pc_55e544: STEP(0x55e544); /* add ecx, 0x4a0603 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x4a0603);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e54a: STEP(0x55e54a); /* mov esi, ecx */
s->gpr[4] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e54c: STEP(0x55e54c); /* shr esi, 0x10 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x10);
s->gpr[4] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e54f: STEP(0x55e54f); /* xor esi, 0x41fa02d */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x41fa02d);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e555: STEP(0x55e555); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e557: STEP(0x55e557); /* lea edi, [rdx + rdx] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e55a: STEP(0x55e55a); /* and edi, 0x14a6241c */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x14a6241c);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e560: STEP(0x55e560); /* shr ecx, 0xf */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xf);
s->gpr[2] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e563: STEP(0x55e563); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e565: STEP(0x55e565); /* and ecx, 0xbfa4 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xbfa4);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e56b: STEP(0x55e56b); /* sub esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55e56d: STEP(0x55e56d); /* lea ecx, [rsi - 0x3d59a2a] */
s->gpr[2] = (uint32_t)((UINT64_C(0xfffffffffc2a65d6) + s->gpr[4]));
++s->steps;
kg_pc_55e573: STEP(0x55e573); /* add edx, edi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e575: STEP(0x55e575); /* add edx, 0xa53130e */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xa53130e);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e57b: STEP(0x55e57b); /* mov edi, ecx */
s->gpr[5] = (uint32_t)((s->gpr[2] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e57d: STEP(0x55e57d); /* shr edi, 8 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x8);
s->gpr[5] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e580: STEP(0x55e580); /* xor edi, 0xe5fffb7a */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xe5fffb7a);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e586: STEP(0x55e586); /* shr ecx, 7 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x7);
s->gpr[2] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e589: STEP(0x55e589); /* add edi, esi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e58b: STEP(0x55e58b); /* and ecx, 0x1fff6f4 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x1fff6f4);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e591: STEP(0x55e591); /* lea esi, [rcx + rdi] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e594: STEP(0x55e594); /* add esi, 0x1c4f82a5 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x1c4f82a5);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e59a: STEP(0x55e59a); /* add edi, ecx */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e59c: STEP(0x55e59c); /* xor eax, 0x52969ab */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x52969ab);
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e5a1: STEP(0x55e5a1); /* lea ecx, [rdi + rdi] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e5a4: STEP(0x55e5a4); /* add ecx, 0x4c54d4b8 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x4c54d4b8);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e5aa: STEP(0x55e5aa); /* and ecx, 0x1835266e */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x1835266e);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e5b0: STEP(0x55e5b0); /* sub esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_SUB, x, y, 32));
++s->steps;
kg_pc_55e5b2: STEP(0x55e5b2); /* lea ecx, [rax + rax] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[0] + (s->gpr[0] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e5b5: STEP(0x55e5b5); /* and ecx, 0x51d3b494 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x51d3b494);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e5bb: STEP(0x55e5bb); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e5bd: STEP(0x55e5bd); /* add esi, 0x5f57aee */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x5f57aee);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e5c3: STEP(0x55e5c3); /* add eax, ecx */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e5c5: STEP(0x55e5c5); /* add eax, 0x28e9de4a */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x28e9de4a);
s->gpr[0] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e5ca: STEP(0x55e5ca); /* mov ecx, esi */
s->gpr[2] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e5cc: STEP(0x55e5cc); /* xor ebx, r8d */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[8] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e5cf: STEP(0x55e5cf); /* xor ebx, esi */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e5d1: STEP(0x55e5d1); /* shr esi, 2 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x2);
s->gpr[4] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e5d4: STEP(0x55e5d4); /* and esi, 0xcf57a2f */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xcf57a2f);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e5da: STEP(0x55e5da); /* xor esi, 0x8742a07 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x8742a07);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e5e0: STEP(0x55e5e0); /* lea edi, [rsi + rsi] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e5e3: STEP(0x55e5e3); /* and edi, 0x18221442 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x18221442);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e5e9: STEP(0x55e5e9); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e5eb: STEP(0x55e5eb); /* add esi, edi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e5ed: STEP(0x55e5ed); /* add esi, 0x1c138be1 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x1c138be1);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e5f3: STEP(0x55e5f3); /* xor esi, 0x843388e9 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x843388e9);
s->gpr[4] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e5f9: STEP(0x55e5f9); /* xor ecx, 0xc1a9337 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xc1a9337);
s->gpr[2] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e5ff: STEP(0x55e5ff); /* lea edi, [rsi + rsi] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[4] + (s->gpr[4] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e602: STEP(0x55e602); /* xor r15d, edx */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[15] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e605: STEP(0x55e605); /* lea edx, [rcx + rcx] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e608: STEP(0x55e608); /* add edx, 0x19e221b0 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x19e221b0);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e60e: STEP(0x55e60e); /* and edx, 0x10e23362 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x10e23362);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e614: STEP(0x55e614); /* and edi, 0x99cd1d28 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x99cd1d28);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e61a: STEP(0x55e61a); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e61c: STEP(0x55e61c); /* add edx, ecx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e61e: STEP(0x55e61e); /* add edx, 0xb5622a89 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xb5622a89);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e624: STEP(0x55e624); /* xor r15d, edx */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[15] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e627: STEP(0x55e627); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e629: STEP(0x55e629); /* shr edx, 2 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x2);
s->gpr[3] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e62c: STEP(0x55e62c); /* and edx, 0xcf57a2f */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xcf57a2f);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e632: STEP(0x55e632); /* xor edx, 0x844a29 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x844a29);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e638: STEP(0x55e638); /* add edi, esi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e63a: STEP(0x55e63a); /* add edi, 0xcce68e94 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xcce68e94);
s->gpr[5] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e640: STEP(0x55e640); /* lea esi, [rdx + rdx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e643: STEP(0x55e643); /* and esi, 0xc8a01a */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0xc8a01a);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e649: STEP(0x55e649); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e64b: STEP(0x55e64b); /* add edx, esi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e64d: STEP(0x55e64d); /* add edx, 0x16cd5cd */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x16cd5cd);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e653: STEP(0x55e653); /* lea esi, [rcx + rcx] */
s->gpr[4] = (uint32_t)((UINT64_C(0x0) + s->gpr[2] + (s->gpr[2] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e656: STEP(0x55e656); /* add esi, 0x33c44360 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x33c44360);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e65c: STEP(0x55e65c); /* and esi, 0x4cb87b8e */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x4cb87b8e);
s->gpr[4] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e662: STEP(0x55e662); /* neg esi */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = 0;
s->gpr[4] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e664: STEP(0x55e664); /* xor edx, 0x6cd589 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x6cd589);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e66a: STEP(0x55e66a); /* add esi, ecx */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e66c: STEP(0x55e66c); /* add esi, 0x803e5f77 */
x = (s->gpr[4] & UINT64_C(0xffffffff)); y = UINT64_C(0x803e5f77);
s->gpr[4] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e672: STEP(0x55e672); /* lea ecx, [rdx + rdx] */
s->gpr[2] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e675: STEP(0x55e675); /* and ecx, 0xcb9fe44a */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0xcb9fe44a);
s->gpr[2] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e67b: STEP(0x55e67b); /* neg ecx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = 0;
s->gpr[2] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e67d: STEP(0x55e67d); /* xor ebx, edi */
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[1] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e67f: STEP(0x55e67f); /* mov edi, esi */
s->gpr[5] = (uint32_t)((s->gpr[4] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e681: STEP(0x55e681); /* shr edi, 2 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x2);
s->gpr[5] = (uint32_t)(operation(s, OP_SHR, x, y, 32));
++s->steps;
kg_pc_55e684: STEP(0x55e684); /* and edi, 0xcf57a2f */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0xcf57a2f);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e68a: STEP(0x55e68a); /* add ecx, edx */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e68c: STEP(0x55e68c); /* add ecx, 0x65cff225 */
x = (s->gpr[2] & UINT64_C(0xffffffff)); y = UINT64_C(0x65cff225);
s->gpr[2] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e692: STEP(0x55e692); /* xor edi, 0x484782a */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x484782a);
s->gpr[5] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e698: STEP(0x55e698); /* lea edx, [rdi + rdi] */
s->gpr[3] = (uint32_t)((UINT64_C(0x0) + s->gpr[5] + (s->gpr[5] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e69b: STEP(0x55e69b); /* and edx, 0x1008e41c */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x1008e41c);
s->gpr[3] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e6a1: STEP(0x55e6a1); /* neg edx */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = 0;
s->gpr[3] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e6a3: STEP(0x55e6a3); /* add edx, edi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e6a5: STEP(0x55e6a5); /* add edx, 0xcb0ef69e */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xcb0ef69e);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e6ab: STEP(0x55e6ab); /* xor edx, 0x4b1fe55e */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0x4b1fe55e);
s->gpr[3] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e6b1: STEP(0x55e6b1); /* lea edi, [rdx + rdx] */
s->gpr[5] = (uint32_t)((UINT64_C(0x0) + s->gpr[3] + (s->gpr[3] * UINT64_C(0x1))));
++s->steps;
kg_pc_55e6b4: STEP(0x55e6b4); /* and edi, 0x93be42d0 */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = UINT64_C(0x93be42d0);
s->gpr[5] = (uint32_t)(operation(s, OP_AND, x, y, 32));
++s->steps;
kg_pc_55e6ba: STEP(0x55e6ba); /* neg edi */
x = (s->gpr[5] & UINT64_C(0xffffffff)); y = 0;
s->gpr[5] = (uint32_t)(operation(s, OP_NEG, x, y, 32));
++s->steps;
kg_pc_55e6bc: STEP(0x55e6bc); /* add edx, edi */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = (s->gpr[5] & UINT64_C(0xffffffff));
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e6be: STEP(0x55e6be); /* add edx, 0xc9df2168 */
x = (s->gpr[3] & UINT64_C(0xffffffff)); y = UINT64_C(0xc9df2168);
s->gpr[3] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e6c4: STEP(0x55e6c4); /* mov rdi, qword ptr [rbp - 0x38] */
READ(a, (UINT64_C(0xffffffffffffffc8) + s->gpr[6]), 8);
s->gpr[5] = a;
++s->steps;
kg_pc_55e6c8: STEP(0x55e6c8); /* xor r9d, eax */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[9] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e6cb: STEP(0x55e6cb); /* xor r15d, ecx */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = (s->gpr[2] & UINT64_C(0xffffffff));
s->gpr[15] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e6ce: STEP(0x55e6ce); /* mov r13d, ebx */
s->gpr[13] = (uint32_t)((s->gpr[1] & UINT64_C(0xffffffff)));
++s->steps;
kg_pc_55e6d1: STEP(0x55e6d1); /* xor r13d, 0x6f8cc5fd */
x = (s->gpr[13] & UINT64_C(0xffffffff)); y = UINT64_C(0x6f8cc5fd);
s->gpr[13] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e6d8: STEP(0x55e6d8); /* xor r9d, esi */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = (s->gpr[4] & UINT64_C(0xffffffff));
s->gpr[9] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e6db: STEP(0x55e6db); /* xor r9d, edx */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = (s->gpr[3] & UINT64_C(0xffffffff));
s->gpr[9] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e6de: STEP(0x55e6de); /* xor r15d, 0x12eeab54 */
x = (s->gpr[15] & UINT64_C(0xffffffff)); y = UINT64_C(0x12eeab54);
s->gpr[15] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e6e5: STEP(0x55e6e5); /* xor r9d, 0x25c69136 */
x = (s->gpr[9] & UINT64_C(0xffffffff)); y = UINT64_C(0x25c69136);
s->gpr[9] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e6ec: STEP(0x55e6ec); /* add r14, 1 */
x = s->gpr[14]; y = UINT64_C(0x1);
s->gpr[14] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_55e6f0: STEP(0x55e6f0); /* xor eax, eax */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = (s->gpr[0] & UINT64_C(0xffffffff));
s->gpr[0] = (uint32_t)(operation(s, OP_XOR, x, y, 32));
++s->steps;
kg_pc_55e6f2: STEP(0x55e6f2); /* cmp dword ptr [rbp - 0xb0], 0xf */
READ(a, (UINT64_C(0xffffffffffffff50) + s->gpr[6]), 4);
x = a; y = UINT64_C(0xf);
(void)operation(s, OP_SUB, x, y, 32);
++s->steps;
kg_pc_55e6f9: STEP(0x55e6f9); /* seta al */
s->gpr[0] = (s->gpr[0] & UINT64_C(0xffffffffffffff00)) | ((((uint64_t)condition(s, COND_A)) & UINT64_C(0xff)) << 0);
++s->steps;
kg_pc_55e6fc: STEP(0x55e6fc); /* imul ebx, eax, 0x35 */
x = (s->gpr[0] & UINT64_C(0xffffffff)); y = UINT64_C(0x35);
s->gpr[1] = (uint32_t)(operation(s, OP_IMUL, x, y, 32));
++s->steps;
kg_pc_55e6ff: STEP(0x55e6ff); /* add ebx, dword ptr [rbp - 0x128] */
READ(b, (UINT64_C(0xfffffffffffffed8) + s->gpr[6]), 4);
x = (s->gpr[1] & UINT64_C(0xffffffff)); y = b;
s->gpr[1] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e705: STEP(0x55e705); /* add r10d, 0x2f */
x = (s->gpr[10] & UINT64_C(0xffffffff)); y = UINT64_C(0x2f);
s->gpr[10] = (uint32_t)(operation(s, OP_ADD, x, y, 32));
++s->steps;
kg_pc_55e709: STEP(0x55e709); /* movsxd rax, r10d */
s->gpr[0] = (((s->gpr[10] & UINT64_C(0xffffffff)) ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_55e70c: STEP(0x55e70c); /* lea rcx, [rip - 0x549c03] */
s->gpr[2] = (UINT64_C(0xffffffffffab63fd) + (bias + UINT64_C(0x55e713)));
++s->steps;
kg_pc_55e713: STEP(0x55e713); /* movsxd rax, dword ptr [rcx + rax*4] */
READ(a, (UINT64_C(0x0) + s->gpr[2] + (s->gpr[0] * UINT64_C(0x4))), 4);
s->gpr[0] = ((a ^ UINT64_C(0x80000000)) - UINT64_C(0x80000000));
++s->steps;
kg_pc_55e717: STEP(0x55e717); /* lea rcx, [rip - 0x54e] */
s->gpr[2] = (UINT64_C(0xfffffffffffffab2) + (bias + UINT64_C(0x55e71e)));
++s->steps;
kg_pc_55e71e: STEP(0x55e71e); /* add rax, rcx */
x = s->gpr[0]; y = s->gpr[2];
s->gpr[0] = operation(s, OP_ADD, x, y, 64);
++s->steps;
kg_pc_55e721: STEP(0x55e721); /* jmp rax */
x = s->gpr[0];
next_pc = x;
++s->steps;

break;
    default:return WRAPPER_KG_PAYLOAD_INVALID;
    }
    NATIVE_DONE;
}
