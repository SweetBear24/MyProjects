/*Develop SelectSort*/
/*1). In the C language, develop a procedure for sorting an array using the direct selection method (SelectSort).
  2). Check the correctness of sorting by calculating the checksum and the number of runs in the array.
  3). Provide for the calculation of the actual number of transfers and comparisons (M and C), compare with the theoretical estimates obtained by the formulas M=3(n-1), C=(n2-n)\2.
  4). Investigate the direct selection method on arrays of decreasing, increasing and random numbers and confirm the independence of the method from the initial ordering of the array.*/

/*1). На языке Си разработать процедуру сортировки массива методом прямого выбора (SelectSort).
  2). Правильность сортировки проверить путем подсчета контрольной суммы и числа серий в массиве.
  3). Предусмотреть подсчет фактического количества пересылок и сравнений (М и С), сравнить с теоретическими оценками, полученными по формулам М=3(n-1), С=(n2-n)\2.
  4). Исследовать метод прямого выбора на массивах убывающих, возрастающих и случайных чисел и подтвердить независимость метода от исходной упорядоченности массива.*/

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>

int A[10], C=0, M=0, MT, CT;
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
void CheckSum(int N){
    int S = 0;
    for (int i=0; i < N; i++)
    {   
    	S = S + A[i]; 
    }
    printf("ChekSum: ");
	printf("%d ", S);
}  
void RunNumber(int N){
     int count = 1;
     for (int i=0; i < N; i++)
     {   
         if(A[i] >= A[i+1])
         {  
        	count = count + 1;
         }
     } 
	 printf("Seriya: ");
     printf("%d ", count);
}    
void SelectionSort(int N)
{ 
	int m, t, i, j;
	for (i = 0; i < N; i++) 
	{
        for (j = i, m = i; j < N; j++) 
		{
			C++;
            if (A[j] < A[m]) 
			{
                m = j;
            }
        }
        t = A[i];
        A[i] = A[m];
        A[m] = t;
        M=M+3; 
    }
    MT=3*(N-1);
    CT=(pow(N,2)-N)/2;
	printf("SelectionSort: ");
	for (int i = 0; i < N; i++) 
  	{
    	printf("%d ", A[i]);
  	}
}
int main()
{
	int N=10;
//Arr ->
	FillInc(N);
	printf("\n");
	CheckSum(N);
	printf("\n");
	SelectionSort(N);	
	printf("\n");
	CheckSum(N);
	printf("\n");
	RunNumber(N);
	printf("\n");
	printf("Actual estimates: C-%d, M-%d",C,M);
	printf("\n");	
	printf("Theoretical estimates:C-%d,M-%d",CT,MT);
	printf("\n\n");
//Arr <-
	FillDec(N);
	printf("\n");
	CheckSum(N);
	printf("\n");
	SelectionSort(N);
    printf("\n");    
	CheckSum(N);
	printf("\n");
	RunNumber(N);
	printf("\n");
	printf("Actual estimates: C-%d, M-%d",C,M);
	printf("\n");	
	printf("Theoretical estimates:C-%d,M-%d",CT,MT);
	printf("\n\n");
//Arr rand	
	FillRand(N);
	printf("\n");
	CheckSum(N);
	printf("\n");
	SelectionSort(N);
	printf("\n");
	CheckSum(N);
	printf("\n");
	RunNumber(N);
	printf("\n");
	printf("Actual estimates: C-%d, M-%d",C,M);
	printf("\n");	
	printf("Theoretical estimates:C-%d,M-%d",CT,MT);
	
}
