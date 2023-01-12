//Develop ShakerSort
/*1). In the C language, develop a ShakerSort procedure for sorting an array of integers in ascending order.
  2). Provide for the calculation of the actual number of transfers and comparisons (Mf and Sf), compare with the theoretical estimates of M and C.
  3). Compare the running time of bubble sort and shaker sort on arrays of decreasing, increasing and random numbers (by the sum of M+C).*/

/*1). На языке Си разработать процедуру шейкерной (ShakerSort) сортировки массива целых чисел по возрастанию.
  2). Предусмотреть подсчет фактического количества пересылок и сравнений (Мф и Сф), сравнить с теоретическими оценками М и С.
  3). Сравнить время работы пузырьковой и шейкерной сортировок на массивах убывающих, возрастающих и случайных чисел (по сумме М+С).*/
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>

int A[500], C=0, M=0, MT=0, CT=0, T=0;

void FillInc(int N){
  int count = 1;
  printf("Arr up: ");
  for(int i=0; i<N; i++)
  {
    A[i]=i;
    printf("%d ",A[i]); 
  } 
}
void FillDec(int N){
  int count = 1;
  printf("Arr down: ");
  for(int i=N-1; i>=0; i--)
  {
    A[i]=i;
    printf("%d ",A[i]);    
  } 
}
void FillRand(int N){
     printf("Arr rand: ");
     for (int i=0; i < N; i++)
     {   
         A[i] = rand()%10;
         printf("%d ", A[i]);
     }
} 
void shekerSort(int N)
{
	int left = 0, right = N - 1; 
	int flag = 1; 
	int M=0,C=0;
	
	while ((left < right) && flag > 0)
	{
    	flag = 0;
	   	for (int i = left; i<right; i++)  
		{ 
	   		C++;	
	    	if (A[i]>A[i + 1])
			{        
	       		int t = A[i];
	        	A[i] = A[i + 1];
	       		A[i + 1] = t;
	       		M+=3;
	        	flag = 1;      
	      	}
	    }
	    right--; 
	    for (int i = right; i>left; i--) 
	    {	
	    	C++;
	    	if (A[i - 1]>A[i]) 
			{           
				int t = A[i];
	        	A[i] = A[i - 1];
	        	A[i - 1] = t;
				M=M+3;
				flag = 1;   
		  	}
		}
		left++;
	}
  	printf("ShekerSort: ");
	for (int i = 0; i<N; i++)
	{
  		printf("%d ", A[i]); 
  	}
  	printf("\n\n");
 	T = M + C;
	printf("Actual estimates      N=%d:  C-%d,  M-%d,  T=C+M  = %d", N,C,M,T);
}
int main()
{
//Arr rand
	int N = 100;
	FillRand(N);
  	printf("\n");
	shekerSort(N);
//Arr down
	printf("\n\n");	
	FillDec(N);
 	printf("\n");
	shekerSort(N);
//Arr down	
-	printf("\n\n");
	FillInc(N);
	printf("\n");
	shekerSort(N);
	return 0;
}
 
