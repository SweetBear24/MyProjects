#pragma once
typedef enum{
    black  = 40, 
    red    = 41, 
    green  = 42, 
    blue   = 44,
    pink   = 45,
    grey   = 47,  
} bgcolor;
typedef enum{
	WHITE = 37, 
    BLACK = 30,
    RED   = 31,
    GREEN = 32,
    BLUE  = 34,
    CYAN  = 36, 
} fgcolor;
int mt_clrscr(void);
int mt_gotoXY(int x, int y); 
int mt_getscreensize(int *rows, int *cols);
int setfgcolor(fgcolor fg);
int setbgcolor(bgcolor bg);   
