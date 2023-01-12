#ifndef MY_ALU_H
#define MY_ALU_H

#include "mySimpleComputer.h"
#include <stdlib.h>
#include <string.h>

int ALU (int command, int operand);
char *invert (char *str);
int to_dec (char *str, int numeral_system);
#endif