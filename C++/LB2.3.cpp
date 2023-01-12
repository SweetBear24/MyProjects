#include <stdio.h> 
#include <iostream>
#include <string>
 
using namespace std;

void dec(const int num, string &snum){
    if (num%2==0)
	 	snum+="0";
    else snum+="1";
    if ((num/2)!=0) 
		dec(num/2, snum);
    else return;
}
 
int main(){
    string snum;
    dec(57, snum);
	cout<<snum<<endl;
}
