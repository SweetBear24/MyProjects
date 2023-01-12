/*A two-dimensional dynamic array A of dimension m x n is specified. (m and n to enter from the keyboard).
Fill it with random numbers.
Create an array D of size m+1 by n+1, in which to write the elements of array A and the sums of the elements of the corresponding rows and columns of the original array A.
Place the sum of all elements of the original array into the D[m+1][n+1] element.*/

/*Задан двумерный динамический массив А  размерности   m x n. ( m и n вводить с клавиатуры). 
Заполнить его случайными числами. 
Создать массив D  размером m+1 на  n+1, в который записать элементы массива А и суммы элементов соответствующих строк и столбцов исходного массива А.  
В элемент D[m+1][n+1] поместить сумму всех элементов исходного массива.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int m, n, i, j, a, b, q, w, k;
	printf("Enter M: ");
	scanf("%d", &m);
	printf("\nEnter N: ");
	scanf("%d", &n);
	
	int **A;
	
	A = (int**)malloc(m*sizeof(int*));
	for (i = 0; i < n; i++) A[i] = (int*)malloc(n*sizeof(int));
	
	srand(time(0));
	
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++) A[i][j] = rand()% 100 - 50;
		
	int **D;
	
	D = (int**)malloc((m+1)*sizeof(int*));
	for (i = 0; i < n+1; i++) D[i] = (int*)malloc((n+1)*sizeof(int));
	
	for (i = 0; i < m+1; i++)
		for (j = 0; j < n+1; j++) D[i][j] = 0;
	
	for (i = 0; i < m+1; i++)
	{
		if (i == m)
		{
			for (a = 0; a < n+1; a++)
			{
				if (a == n)
				{
					for (q = 0; q < m; q++)
						for (w = 0; w < n; w++) D[m][n] += A[q][w];
				}
				else
				{
					for (b = 0; b < m; b++)
						D[i][a] += A[b][a];
				}
			}			
		}
		else
		{
			for (j = 0; j < n+1; j++)
			{
				if (j == n)
				{
					for (k = 0; k < n; k++)
						D[i][j] += A[i][k];
				}
				else D[i][j] = A[i][j];
			}
		}
	}
	
	printf("\nArray A:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%4d ", A[i][j]);
		}
		printf("\n");
	}
	
	printf("\nArray D:\n");
	for (i = 0; i < m+1; i++)
	{
		for (j = 0; j < n+1; j++)
		{
			printf("%4d ", D[i][j]);
		}
		printf("\n");
	}
	
return 0;
}
