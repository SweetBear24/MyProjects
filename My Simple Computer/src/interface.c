#include <signal.h>  
#include <stdio.h>    
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "LB2.h"
#include "mySimpleComputer.h"
#include "myBigChar.h"
#include "keys.h"
#include <stdlib.h>
#include <string.h>
#include "myCU.h"
#include <sys/time.h>
#include "mySignal.h"
int addr_accum = 0;
int instruction_counter = 0;
int accumulator; 
int big_char[18][2]= {
	{0x818181FF,0xFF818181}, // 0
	{0x12141810,0x10101010}, // 1
	{1010842624,8258050},    // 2
	{2120252928,8282238},    // 3
	{2120640000,6316158},    // 4
	{1040350720,4079680},    // 5
	{35789824,1974814},      // 6
	{811630080,396312},      // 7
	{1013332992,3958374},    // 8
	{2087074816,3956832},    // 9
	{2118269952,4342338},    // A
	{1044528640,4080194},    // B
	{37895168,3949058},      // C
	{1111637504,4080194},    // D
	{2114092544,8258050},    // E
	{33717760,131646},       // F
	{2115508224,1579134},    // +
	{2113929216,126},        // -
};      
void printCell(int address){
	int value, row, col, command=10, operand=10;
	char buf[6];  
	 
	if(sc_memoryGet(address, &value) < 0)return;
	if(sc_commandDecode((value & 0x3FFF), &command, &operand) < 0)return;
	
	row = address/10;
	col = address%10;
	
	snprintf(buf, 6, "%c%02X%02X", (value & 0x4000) ?'-':'+', command, operand);
	mt_gotoXY(2+row, 2+col*6);
	write(1, buf, 5);
	
	return;
}
int loadfile(){
  char filename[256];
  mt_gotoXY(30,1);
  write (1, "Enter filename for load: ", 26);
  fgets (filename, 256, stdin);
  filename[strlen (filename) - 1] = 0;
  sc_memoryLoad (filename);
  return 0;
} 
int savefile(){
  char filename[256];
  mt_gotoXY (30, 1);
  write (1, "Enter filename for save: ", 26);
  fgets (filename, 256, stdin);
  filename[strlen (filename) - 1] = 0;
  sc_memorySave (filename);
  return 0;
}

int main(){ 
	
	mt_clrscr(); 
	
	bc_box(1,1,62,12);	
	mt_gotoXY(1,29);
	char Memory[6] = "Memory";
	write(1, Memory, 6);
	
	bc_box(1,63,25,3);
	mt_gotoXY(1,70);
	char accumulator[12] = "accumulator";
	write(1, accumulator, 12); 	
	
	sc_memoryInit();
	sc_memorySet(10, 0x7FFFF); 
	sc_memorySet(0, 1);
	sc_memorySet(5, 4543);	
	sc_memorySet(50, 0777);
	for(int i=0; i<100; i++){
		printCell(i);
	}

	bc_box(4,63,25,3);   
	mt_gotoXY(4,67);  
	char instructionCounter[20] = "instructionCounter";
	write(1, instructionCounter, 20); 
	bc_box(7,63,25,3);
	mt_gotoXY(7,70);
	char Operation[9] = "Operation";
	write(1, Operation, 9); 
	bc_box(10,63,25,3);
	mt_gotoXY(10,73); 
	char Flags[9] = "Flags";
	write(1, Flags, 9);
	bc_box(13,47,41,10); 
	mt_gotoXY(13 ,50);
	char Key[9] = "Keys:";
	write(1, Key, 9); 
	mt_gotoXY(14,50);
	char Keydiscription[135] = {"l - load\E[15;49H s - save\E[16;49H r - run\E[17;49H s - step\E[18;49H i - reset\E[19;48H  F5 - accumulator\E[20;48H  F6 - instructionCounter"};
	write(1, Keydiscription, 135); 
	
	bc_box(13,1,46,10);
	bc_printbigchar(big_char[1], 14, 3, CYAN, black); 
	
	enum keys key;
	int number; 
	int step = 0; 
	int flag = 1;
	
	struct itimerval nval, oval;
	nval.it_interval.tv_sec = 1;
	nval.it_interval.tv_usec = 0;
	nval.it_value.tv_sec = 1;
	nval.it_value.tv_usec = 0;
	ms_setSignals ();
	  
	while(flag){		 
		setfgcolor(grey);
		setbgcolor(CYAN);
		printCell(step);

		rk_mytermsave();
		rk_mytermregime(0, 0, 1, 0, 1);
		rk_readkey(&key);
		rk_mytermrestore();
		setfgcolor(WHITE);
		setbgcolor(black);
		printCell(step);
			
		switch (key) {
		case KEY_DOWN:
			step=step+10;
			if(step>90) step=0;
			break;
		case KEY_UP:
			step=step-10;
			if(step<0) step=90;
			break;
		case KEY_LEFT:
			step=step-1;
			if(step<0) step=99;
			break;	
		case KEY_RIGHT:
			step=step+1;
			if(step>99) step=0;
			break;
		case KEY_ESC:
			flag = 0; 
			break;
		case KEY_ENTER:
			mt_gotoXY(30 ,1);
			scanf("%d", &number); 
			sc_memorySet(step, number);
			break;
		case KEY_L:
			loadfile();
			break;
		case KEY_S:
			savefile();
			break;
		case KEY_T:
			CU(); 
			break;		
		default:
			break;
		}	
	} 
	
	mt_gotoXY(30,1);	
	printf("\033[0m\n\n\n\n\n\n\n");
	return 0;
}
     

 
