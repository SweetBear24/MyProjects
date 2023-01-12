#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int M, C, T, N;
void FillInc(int *Q){
	for (int i=0; i<N; i++) Q[i]=i;
}

void FillDec(int *Q){
	for (int i=0; i<N; i++) Q[i]=N-i;
}

void FillRand(int *Q){
	for (int i=0; i<N; i++) Q[i]=rand()%100;
}

void CheckSum(int *Q){
	int s=0;
	for (int i=0; i<N; i++) s+=Q[i];
	printf ("%d\n", s);
}

void PrintMas(int *Q){
	for (int i=0; i<N; i++) printf ("%d ", Q[i]);
	printf("\n");
}

void RunNumber(int *Q){
	int r=1;
	for (int i=0; i<N-1; i++) {
		if (Q[i+1]<Q[i]) r+=1;
	}
	printf ("%d\n", r);
}

void SelectSort(int *Q){
  int min, t; 
  M=0; C=0;
  for (int i=0; i<N-1; i++) 
  {
    min=i; 
    for (int j=i+1; j<N; j++) 
    {
    	C++;
    	if (Q[j]<Q[min]) 
        min=j;
    }
    if (Q[i]!=Q[min]) {
	    t=Q[i];
	    Q[i]=Q[min];
	    Q[min]=t;
	    M+=3;
	}
  }
}
void BubbleSort (int *Q){
	M=0; C=0; int t;
	for (int i=0; i<N; i++){
		for (int j=N-1; j>i; j--){
			C++;
			if (Q[j]<Q[j-1]){
				t=Q[j];
				Q[j]=Q[j-1];
				Q[j-1]=t;
				M+=3;
			}
		}
	}
}
int main (){
	srand(time(NULL));
	
	printf ("N       M+C theoretical        M+C dec         M+C rand       M+C inc\n");
	N = 100;
	int S[N];
	FillDec(S);
	BubbleSort(S);
	T=4*(N*N-N)/2;
	printf ("%3d", N);
	printf("     %6d                 %6d", T, M+C);
	FillRand(S);
	BubbleSort(S);
	printf ("          %6d", M+C);
	FillInc(S);
	BubbleSort(S);
	printf ("         %6d\n", M+C);
	int S1[N];	FillDec(S1);
	BubbleSort(S1);
	T=2*(N*N-N);
	printf ("%3d", N);
	printf("     %6d                 %6d", T, M+C);
	FillRand(S1);
	BubbleSort(S1);
	printf ("          %6d", M+C);
	FillInc(S1);
	BubbleSort(S1);
	printf ("         %6d\n", M+C);
	
	N = 300;
	int S2[N];
	FillDec(S2);
	BubbleSort(S2);
	T=2*(N*N-N);
	printf ("%3d", N);
	printf("     %6d                 %6d", T, M+C);
	FillRand(S2);
	BubbleSort(S2);
	printf ("          %6d", M+C);
	FillInc(S2);
	BubbleSort(S2);
	printf ("         %6d\n", M+C);
	
	N = 400;
	int S3[N];
	FillDec(S3);
	BubbleSort(S3);
	T=2*(N*N-N);
	printf ("%3d", N);
	printf("     %6d                 %6d", T, M+C);
	FillRand(S3);
	BubbleSort(S3);
	printf ("          %6d", M+C);
	FillInc(S3);
	BubbleSort(S3);
	printf ("         %6d\n", M+C);
	
	N = 500;
	int S4[N];
	FillDec(S4);
	BubbleSort(S4);
	T=2*(N*N-N);
	printf ("%d", N);
	printf("     %6d                 %6d", T, M+C);
	FillRand(S4);
	BubbleSort(S4);
	printf ("          %6d", M+C);
	FillInc(S4);
	BubbleSort(S4);
	printf ("         %6d\n", M+C);
	
	system ("PAUSE");
	
	return 0;
}
