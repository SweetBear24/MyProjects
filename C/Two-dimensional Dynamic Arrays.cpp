/*A two-dimensional dynamic array B of dimension m x n is specified. (n=5, m enter from the keyboard). Fill it with random numbers.
To obtain a new dynamic matrix C[m-1][n-1] by removing from B the row and column that contain the maximum element of the original matrix.*/

/*Задан двумерный динамический массив B размерности m x n. (n=5, m вводить с клавиатуры). Заполнить её случайными числами.
Получить новую динамическую матрицу С[m-1][n-1] путем удаления из В строки и столбца, в которых содержится максимальный элемент исходной матрицы.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int m, n = 5, i, j, row_max = 0, column_max = 0, k = 0, l = 0;
	printf("Enter M: ");
	scanf("%d", &m);
	
	int **B;
	
	B = (int**)malloc(m*sizeof(int*));
	for (i = 0; i < n; i++) B[i] = (int*)malloc(n*sizeof(int));
	
	srand(time(0));
	
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) B[i][j] = rand()% 100 - 50;
		
	int **C;
	
	C = (int**)malloc((m-1)*sizeof(int*));
	for (i = 0; i < n-1; i++) C[i] = (int*)malloc((n-1)*sizeof(int));
	
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (B[row_max][column_max] < B[i][j])
			{
				row_max = i;
				column_max = j;
			}
		}
	}
	printf("\nArray B:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%4d ", B[i][j]);
		}
		printf("\n");
	}
	
	printf("\nrow_max = %d, column_max = %d\n", row_max, column_max);
	
	for (i = 0; ((i < m-1) && (l < m)); i++)
	{
		if (i == row_max) l++;
		for (j = 0; ((j < n-1) && (k < n)); j++)
		{
			if (j == column_max) k++;
			C[i][j] = B[l][k];
			k++;
		}
		l++;
		k = 0;
	}
	
	
	
	printf("\nArray C:\n");
	for (i = 0; i < m-1; i++)
	{
		for (j = 0; j < n-1; j++)
		{
			printf("%4d ", C[i][j]);
		}
		printf("\n");
	}
	
return 0;
}
