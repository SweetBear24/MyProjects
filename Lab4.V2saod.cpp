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

void ShakerSort (int *Q){
	int t, L = 0, R = N, k = N;
	M = 0, C = 0;
	
	do{
		for(int i = R; i > L+1;i--){
			C++;
			if(Q[i]<Q[i-1]){
				t = Q[i];
				Q[i] = Q[i-1];
				Q[i-1] = t;
				k = i;
				M+=3;
			}
		}
		L = k;
		for(int i = L; i < R-1; i++){
			C++;
			if(Q[i]>Q[i+1]){
				t = Q[i];
				Q[i] = Q[i+1];
				Q[i+1] = t;
				k = i;
				M+=3;
			}
		}
		R = k;
	}while(L<R);

	T = M+C;
}

int main (){
	srand(time(NULL));
	int *B;
	N=100;
	B = new int[N];
	printf ("     |          BubbleSort            |            ShakerSort           |\n");
	printf ("n       M+C dec   M+C rand   M+C inc      M+C dec   M+C rand   M+C inc\n");
	for (N=100; N!=600; N+=100){
		B = new int[N];
		printf ("%3d",N);
		FillDec(B);
		BubbleSort(B);
		printf ("     %6d", M+C);
		FillRand(B);
		BubbleSort(B);
		printf ("     %6d", M+C);
		FillInc(B);
		BubbleSort(B);
		printf ("    %6d", M+C);
		
		FillDec(B);
		ShakerSort(B);
		printf ("       %6d", M+C);
		FillRand(B);
		ShakerSort(B);
		printf ("     %6d", M+C);
		FillInc(B); 
		ShakerSort(B);
		printf ("   %6d\n", M+C);
		
		delete B;
	}	
		

	system ("PAUSE");
	
	return 0;
}
