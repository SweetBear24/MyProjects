int bcprintA(char *str);
int bc_box(int x, int y, int wight, int height);
int bc_setbigcharpos(int *big, int x, int y, int value);
int bc_getbigcharpos(int *big, int x, int y, int *value);
int bc_printbigchar (int *big, int x, int y, int fg, int bg);    
int bc_bigcharwrite(int fd, int* buf, int count);
int bc_bigcharread(int fd, int* buf, int need_count, int* count);
