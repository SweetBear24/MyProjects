#include"mySimpleComputer.h"
#include<stdlib.h>
#include<stdio.h>

int memory[100];
int ops_num;
int correct_ops[];
unsigned char registerFlagov;

int int_cmp(const void* a, const void* b)
{
    if (*(int*)a < *(int*)b)
        return -1;
    else
        if (*(int*)a > *(int*)b)
            return 1;
        else
            return 0;
}

int sc_memoryInit() {
    for (int i = 0; i < 100; i++) memory[i] = 0;
    return 0;
}

int sc_memorySet(int address, int value) {
    if (address >= 100 || address <= -1) {
		return -1;
    }
    memory[address] = value;
    return 0;
}

int sc_memoryGet(int address, int* value) {
    if (address >= 100 || address <= -1) return -1;
    *value = memory[address];
    return 0;
}

int sc_memorySave(const char* filename) {
    FILE* fd = fopen(filename, "wb");
    fwrite(memory, sizeof(*memory) * 100, 1, fd);
    fclose(fd);
    return 0;
}

int sc_memoryLoad(const char* filename) {
    FILE* fd = fopen(filename, "rb");
    fread(memory, sizeof(*memory) * 100, 1, fd);
    fclose(fd);
    return 0;
}

int sc_regInit() {
    registerFlagov = 0;
    return 0;
}

int sc_regSet(int reg, int value) {
    if ((reg >= 0) && (reg <= 4)) {
        if (value == 1)
            SetBit(registerFlagov, reg);
        else if (value == 0)
            ClearBit(registerFlagov, reg);
        else
            return 0;
    }
    else return -1;
    return 0;
}

int sc_regGet(int reg, int* value) {
    if ((reg >= 0) && (reg <= 4)) *value = CheckBit(registerFlagov, reg);
    else return -1;
    return 0;
}

int sc_commandEncode(int command, int operand, int* value) {
    void* command_ptr;

    command_ptr = bsearch(&command, correct_ops, ops_num, sizeof(int), int_cmp);
    if (command_ptr != NULL) {
        *value = (command << 7) | operand;
        return 0;
    }
    else return -1;
}

int sc_commandDecode(int value, int* command, int* operand) {
	
	*command = 0;
    *operand = 0; 
	int bit = 0;
	int k = 0;
	for(int i=0; i<=6; i++){
		bit = (value >>(i))&0x1;
		if(bit == 1){
			*operand = *operand|(1<<(k));
		}
		k++;
	}
	k = 0;
	for(int i=7; i<=13; i++){
		bit = (value >>(i))&0x1;
		if(bit == 1){
			*command = *command|(1<<(k));
		}
		k++;
	}
	return 0;
}
