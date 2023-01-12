#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "LB2.h"
#include "mySimpleComputer.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int bcprintA(char *str){
	write(1, "\E(0", 3);
	write(1, str, strlen(str));
	write(1, "\E(B", 3);     
	return 0; 
}
int bc_box(int x, int y, int wight, int height){
	char a[]= "q";
	char b[]= "x"; 
	char rl[]= "j";
	char rup[]= "k"; 
	char ll[]= "m"; 
	char lup[]= "l"; 
	
	
	int rows, cols; 
	mt_getscreensize(&rows, &cols);
	 
	if((x <= 0) || (y <= 0) || (x + height + 2 > rows) || (y + wight + 2 > cols)
	|| (wight <= 1) || (height <= 1 )){
		return -1;
	}
	mt_gotoXY(x, y);
	bcprintA(lup);
	mt_gotoXY(x, y + wight - 1);
	bcprintA(rup); 
	mt_gotoXY(x + height - 1, y + wight - 1);
	bcprintA(rl);
	mt_gotoXY(x + height - 1, y);
	bcprintA(ll);
	
	for(int i = 1; i < wight - 1; ++i){
		mt_gotoXY(x, y + i);
		bcprintA(a);
		
		mt_gotoXY(x + height - 1, y + i);
		bcprintA(a);
	}
	
	for(int i = 1; i < height - 1; ++i){
		mt_gotoXY(x + i, y);
		bcprintA(b);
		
		mt_gotoXY(x + i, y + wight - 1);
		bcprintA(b);
	 }
	return 0;
}
int bc_setbigcharpos(int *big, int x, int y, int value) {
  int shift, pos, temp;
  if (x < 0 || x > 8 || y < 0 || y > 8)
  return -1;
  
  if (x < 4) {
	 pos = 0;
  }
  else { 
	 pos = 1;
	 x -= 4;
  }
  shift = (x * 8) + y;
  if (value != 0){
	big[pos] |= (1 << shift);
  }else{
    big[pos] &= ~(1 << shift);; 
  }
  return 0; 
}  

int bc_getbigcharpos(int *big, int x, int y, int *value) {
  int shift, pos;
  int temp;

  if (x < 0 || x > 8 || y < 0 || y > 8)
  return -1;

  if (x < 4) {
	  pos = 0;
  }
  else { 
	 pos = 1;
	 x -= 4;
  }
  shift = (x * 8) + y;
  temp = big[pos] & (1 << shift);
  if (temp != 0)
    *value = 1;
  else
    *value = 0;
   
  return 0;
} 

int bc_printbigchar (int *big, int x, int y, int fg, int bg){
	int value = 0;
	
	setfgcolor (fg); setbgcolor (bg);

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
  		    mt_gotoXY (x+i, y+j);
			bc_getbigcharpos (big, i,j, &value);
			if (value)
   			  bcprintA ("a");
			else
	          bcprintA (" ");
		}
    }
	return 0;
}
int bc_bigcharwrite(int fd, int* buf, int count){
	int result;
	result = write(fd, buf, count*sizeof(int)*2);
	if(result != (count*sizeof(int)*2)){return -1;}
	return 0;
} 
int bc_bigcharread(int fd, int* buf, int need_count, int* count){
	*count = read (fd, buf, need_count*sizeof(int)*2); 
	*count = (*count/sizeof(int))/2;
 	printf("%d", *count);
	return 0;
}
/*int main(){
	int file;
	file = open("bigchar.txt", O_WRONLY|O_CREAT|O_TRUNC, 0600);
	if(file==-1)return (1);
	bc_bigcharwrite(file, (int *)big_char, 18);       
	close(file);
	file = open("bigchar.txt", O_RDONLY);
	int result_read;
	if(file==-1)return (1);
    mt_clrscr();
	bc_box(1,1,10,10);	bc_printbigchar(big_char[0], 1, 1, BLUE, def);
	bc_printbigchar(big_char[1], 1, 9, BLUE, def);
	for (int i = 0; i < 17; i++)
    {	
		bc_printbigchar(big_char[i], 9, 1, BLUE, def);
	}
	bc_bigcharread(file, (int *)big_char, 18, &result_read);
	close(file);
 	printf("\033[0m\n\n\n\n\n\n\n");
}*/
