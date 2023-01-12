/*Write a function that calculates the sum of the elements of each row for a two-dimensional array with a variable length of strings 
(the length of strings is random in the range from 2 to 10).
The length of each string is stored in element 0 of the corresponding string.
Form an array using random numbers and display it in the main program.*/

/*Написать функцию, которая вычисляет для двумерного массива с переменной длинной строк (длина строк случайна в диапазоне от 2 до 10) сумму элементов каждой строки.
Длина каждой строки хранится в 0 элементе соответствующей строки. 
Массив сформировать с помощью случайных чисел, и вывести на экран в главной программе.*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
int random(int n,int raznitsa){
	return rand()%n  + raznitsa;
}
void Rand(int *arr,int celements,int nelements,int raznitsa){
	int i;
	for (i = 0;i<celements;i++)
	{
		arr[i] = random(nelements,raznitsa);
	}
}
void PrintMas(int *arr,int celements){
	int i;
	for (i=0;i<celements;i++)
	{
		printf("%d  ",arr[i]);
	}
}
void d_array_print(int **A, int N, int M){
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%*d", 5, A[i][j]);
        }
        printf("\n");
    }
}

int ** d_array(int N, int*dlina){
    int **A = (int **)malloc(N*sizeof(int *));
    for (int i = 0; i < N; i++) {
        A[i] = (int *)malloc((dlina[i]+1)*sizeof(int)); 
    }
    return A;
}

void d_array_free(int **A, int N){
    for(int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);
}
void d_array(int N){
	int i,j,sum;
	int *dlina = (int*)malloc(N*sizeof(int*));
    Rand(dlina,N,7,2);
	int **arr = d_array(N,dlina);
	for (i = 0;i < N-1;i++) 
	{
		arr[i][0] = dlina[i];
	} 
	for (i = 0; i<N;i++){
		for (j = 1;j<dlina[i]+1;j++){
			arr[i][j]= random(9,0);
		}
	}
	printf("\n");

	for (i = 0; i<N-1;i++){
		for (j = 0;j<dlina[i]+1;j++){
			printf("%d  ",arr[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i<N-1;i++){
		sum = 0;
		for (j = 0;j<dlina[i]+1;j++){          
			sum+=arr[i][j];
		}		
		printf("Arr[%d]:= %d\n",i, sum);
	}
	free(dlina);
	d_array_free(arr, N+1);
}
int main()
{
	int N=0;
	srand(time(NULL));
	scanf("%d",&N);
	d_array(N+1);
	return 0;
}
