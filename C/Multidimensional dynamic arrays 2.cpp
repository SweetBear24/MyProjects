/*Create a two-dimensional array with a variable string length, in which to write the multiplication table of the following form:
   1
   2   4
   3   6   9
   4   8  12 16
   5  10 15 20 25
   6  12 18 24 30 36
   7  14 21 28 35 42 49
   8  16 24 32 40 48 56 64
   9  18 27 36 45 54 63 72 81
*/
/*Создать двумерный массив с переменной длиной строки, в который записать таблицу умножения следующего вида:
   1
   2   4
   3   6   9
   4   8  12 16
   5  10 15 20 25
   6  12 18 24 30 36
   7  14 21 28 35 42 49
   8  16 24 32 40 48 56 64
   9  18 27 36 45 54 63 72 81
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int **array_alloc(size_t N)
{
    int **A = (int **)malloc(N*sizeof(int *));
    for(int i = 0; i < N; i++) {
        A[i] = (int *)malloc((i+1)*sizeof(int));
    }
    return A;
}

void array_free(int **A, size_t N)
{
    for(int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);
}
int main()
{
	int N=0;
	printf("Enter nuber of table mul: ");
	scanf("%d",&N);
	int **array = array_alloc(N);
	for (int i = 1; i <= N;i++)
	{
		for (int j = 1; j <= i; j++){
			array[i-1][j-1]= i*j;
			printf("%d  ",array[i-1][j-1]);
		}
		printf("\n");
	}
	array_free(array,N);
	return 0;
}
