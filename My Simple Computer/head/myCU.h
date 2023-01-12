#ifndef MY_CU_H
#define MY_CU_H
//#include "myALU.h"
#include "myreadkey.h"
#include "mySimpleComputer.h"
#include "string.h"
#include "LB2.h" 


int READ (int operand);
int WRITE (int operand);
int LOAD (int operand);
int STORE (int operand);
int JUMP (int operand);
int JNEG (int operand);
int JZ (int operand);
int HALT ();
int JNS (int operand);
int CU ();
int JC (int operand);
int JNC (int operand);
int JP (int operand);
int JNP (int operand);
#endif
