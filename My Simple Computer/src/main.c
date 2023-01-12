#include<stdio.h>
#include<sys/ioctl.h>
#include<termios.h>
#include "mySimpleComputer.h"
int main(){
    int command = 1;
	int operand = 1;
	  
	sc_commandDecode(1234, &command, &operand);
	printf("%d %d",command, operand);
}
    
