#pragma once
#define REGP 1
#define REG0 2
#define REGM 4
#define REGT 8
#define REGE 16

#define SetBit(A, B) (A = ((A) | (1 << (B))))
#define ClearBit(A, B) (A = ((A) & ~(1 << (B))))
#define CheckBit(A, B) (((A) >> B) & 1)

int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int* value);
int sc_memorySave(const char* filename);
int sc_memoryLoad(const char* filename);
int sc_regInit();
int sc_regSet(int register, int value);
int sc_regGet(int register, int* value);
int sc_commandEncode(int command, int operand, int* value);
int sc_commandDecode(int value, int* command, int* operand);
