/*Develop BubbleSort*/
/*1). In the C language, develop a procedure for bubble sorting (BubbleSort) an array of integers in ascending order.
  2). Provide for the calculation of the actual number of transfers and comparisons (Mf and Sf), compare with the theoretical estimates of M and C.
  3). Estimate the complexity of bubble sort on arrays of decreasing, increasing and random numbers (by the sum of M + C). Create a table like:*/
  
/*1). На языке Си разработать процедуру пузырьковой сортировки (BubbleSort) массива целых чисел по возрастанию.
  2). Предусмотреть подсчет фактического количества пересылок и сравнений (Мф и Сф), сравнить с теоретическими оценками М и С.
  3). Оценить трудоемкость пузырьковой сортировки на массивах убывающих, возрастающих и случайных чисел (по сумме М+С). Составить таблицу вида:*/
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>

int A[500], TT=0, MT=0, CT=0, T=0, TTArrup=0, TTArrdown=0, TTArrrand=0, TU=0, TD=0, TR=0 ;

void FillInc(int N){
//printf("Arr up: ");
  for(int i=0; i<N; i++)
  {
    A[i]=i;
//  printf("%d ",A[i]); 
  } 
}
void FillDec(int N){
  int count = 1;
//printf("Arr down: ");
  for(int i=N-1; i>=0; i--)
  {
    A[i]=i;
//  printf("%d ",A[i]);
    
  } 

}
void FillRand(int N){
//    printf("Arr rand: ");
     for (int i=0; i < N; i++)
     {   
         A[i] = rand()%10;
//       printf("%d ", A[i]);
     }
}
void BubbleSort (int N){
	int M=0, C=0, t;
	for (int i=0; i<N; i++){
		for (int j=N-1; j>i; j--){
			C++;
			if (A[j]<A[j-1]){
				t=A[j];
				A[j]=A[j-1];
				A[j-1]=t;
				M+=3;
			}
		}
	}
	TU = M + C;
	TD = M + C;
	TR = M + C;
}
int main()
{ 
	srand(time(NULL));

	printf ("N    Theor M+C:  AR     AD      AU    Actual M+C:    AR       AD      AU\n");
	for (int N=100; N!=600; N+=100){
		printf ("%d", N);	
		FillRand (N);
		BubbleSort(N);
		MT= (3*CT)/2;
		CT= (pow(N,2)-N)/2;
		TTArrrand= MT+CT;
		printf ("	      %6d", TTArrrand);
	
		FillDec(N);
		BubbleSort (N);
		CT= (pow(N,2)-N)/2;
		MT= 3*CT;
		TTArrdown= MT+CT;
		printf (" %6d", TTArrdown);

		FillInc(N);
    	BubbleSort(N);
		MT= 0;
		CT= (pow(N,2)-N)/2;
		TTArrup= MT+CT;
		printf ("  %6d", TTArrup);
		
		FillRand (N);
		BubbleSort(N);
		printf ("               %6d", TR);
		
		FillDec(N);
		BubbleSort (N);
		printf ("   %6d", TD);
		
		FillInc(N);
    	BubbleSort(N);
		printf ("  %6d\n", TU);
	}
}

