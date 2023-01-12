//Develop ShellSort

/*1)Develop a procedure for sorting an array of integers using the ShellSort method.
  2) Provide for the calculation of the actual number of transfers and comparisons (Mf and Sf), compare with the theoretical estimates of M and C.
  3) Explore the Shell method for n=100. 200, …500 on arrays of random numbers and compare with the direct inclusion method. 
  Determine the complexity and number of K-sorts using the Knuth formula.*/

/*1)Разработать процедуру сортировки массива целых чисел методом Шелла (ShellSort).
  2)Предусмотреть подсчет фактического количества пересылок и сравнений (Мф и Сф), сравнить с теоретическими оценками М и С.
  3)Исследовать метод Шелла для n=100. 200, …500 на массивах случайных чисел и сравнить с методом прямого включения.
  Определить трудоемкость и количество  К-сортировок по формуле Кнута.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int M, C, T, A[500], N, Interval;

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
void SelectSort(int N){
  int min, t; 
  M=0; C=0;
  for (int i=0; i<N-1; i++) 
  {
    min=i; 
    for (int j=i+1; j<N; j++) 
    {
    	C++;
    	if (A[j]<A[min]) 
        min=j;
    }
    if (A[i]!=A[min]) {
	    t=A[i];
	    A[i]=A[min];
	    A[min]=t;
	    M+=3;
	}
  }
}
int Interval_Knut (int N){
	int Interval = 1;
	while (Interval <= N/3)
	{
		Interval = Interval*2+1;
	}
	return Interval;
}
void ShellSort (int N){
	
	M=0, C=0;
	int k=0;
	int t=0, j=0;
	int Interval = Interval_Knut(N);
	for (int s=Interval; s>0; s = (s-1)/2){
		C++;
		for (int i=s; i<N; i++){
			C++;
			t = A[i];
			j = i-s;
			M++;
			for (j; j>0 && t<A[i]; j-=s) {
				C++;
				M++;
				A[j+k]=A[j];
			}
			M++;
			A[j+k]=t;
		}
		k++;
	}
	printf ("	%6d", Interval);
}
int main()
{ 
	srand(time(NULL));
	printf ("N     Number of K-sort    Insert Sort     Shell Sort\n");
	for (int N=100; N!=600; N+=100){
		printf ("%d", N);				
		FillRand (N);
		ShellSort (N);
		printf ("             %6d", M+C);
		SelectSort(N);
		printf ("           %6d\n", M+C);
	}
}
