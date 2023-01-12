#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "LB2.h"
int mt_clrscr(void){ 
   // printf("\E[0;0f");    
    write(1, "\033[H\033[2J", 7);
    return 0;
}
int mt_gotoXY(int x, int y){ 
	char buf [100];
	int size;
	
	size = snprintf (buf, 99, "\033[%d;%dH", x,y);
	
    write(1, buf, size);
    return 0;
}   
int mt_getscreensize(int *rows, int *cols){ 
    struct winsize ws;    
    if(!ioctl(1, TIOCGWINSZ, &ws)){
        *rows = ws.ws_row; 
        *cols = ws.ws_col;
    }else{
        fprintf(stderr,"Ошибка получения размера экранa.\n");
    }
    return 0;
}
int setfgcolor(fgcolor fg){ 
    char buf [100];
	int size;

	size = snprintf (buf, 99, "\033[%dm", fg);
	
    write(1, buf, size);                   
    return 0;
}   
int setbgcolor(bgcolor bg){ 
    char buf [100];
	int size;

	size = snprintf (buf, 99, "\033[%dm", bg);
	
    write(1, buf, size);                   
    return 0;

    return 0;
}   
