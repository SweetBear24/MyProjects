/* Write a function that resets the array elements between two minimum elements.
Pass the array to the function as a parameter, display the array before and after processing in the main function.*/

/*Написать функцию, обнуляющую элементы массива, находящиеся между двумя минимальными элементами.
Массив передать в функцию как параметр, вывести массив до и после обработки в функции main.*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void SerchMin(int *a,int n){
	int i,min1=100,min2=100,i1=0,i2=0;
	for (i=0;i<n;i++){
    	if(a[i]<min1){
    		min1 = a[i];
    		i1 = i;
		}	
	}
	for (i=0;i<n;i++){
    	if((a[i] < min2) && (a[i] > min1)){
    		min2 = a[i];
    		i2 = i;
		}
	}
	if (i1>i2){
		for(i=i2+1;i<i1;i++){
			a[i]=0;
		}
	}
	else{
        for(i=i1+1;i<i2;i++){
			a[i]=0;
		}		
	}
}
int main(){
	int *a,n,i;
	srand(time(NULL));
	scanf("%d",&n);
    a = new int[n];
  	printf("Befor: \n");
	for (i=0;i<n;i++){
    	a[i] = rand()%100+1;
    	printf("a[%d]=%d\n",i,a[i]);
	}
    SerchMin(a,n);
    printf("\n");
  	printf("After: \n");
    for (i=0;i<n;i++){
    	printf("a[%d]=%d\n",i,a[i]);
	}
	free(a);
	return 0;
}
