/*Task 1. Create a dynamic two-dimensional array of NxN elements
  Fill with random integers.
  Create a one-dimensional array D.
  Rewrite the matrix elements into array D in the following order:
a) along the right diagonals, starting from the top right element
b) along the left diagonals, starting from the top left element
c) in a spiral, starting from the central element
d) in a spiral, starting from the top left element

Task 2. Create a two-dimensional dynamic array with an arbitrary number
elements in each period. Fill it out and print line by line.*/

/*Задание 1. Создать динамический двумерный массив размером NхN элементов
 Заполнить случайными целыми числами.
 Создать одномерный массив D.
 Переписать элементы матрицы в массив D в следующем порядке:
a) по правым диагоналям, начиная с правого верхнего элемента
b) по левым диагоналям, начиная с левого верхнего элемента
c) по спирали, начиная с центрального элемента
d) по спирали, начиная с левого верхнего элемента

Задание 2. Создать двумерный динамический массив с произвольным количеством
элементов в каждой сроке. Заполнить его и распечатать построчно. */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void print_arr(int* array,int size)
{
    for (int i = 0; i < size; i++) printf("%d ", array[i]);
}
int** dynamic_array_alloc(size_t N,size_t M)
{
    int** A = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        A[i] = (int*)malloc(M * sizeof(int));
    }
    return A;
}
void fill_rand(int** matrix, int width,int height)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            matrix[i][j] = rand() % 9;
        }
    }
}
void normal_print(int** matrix,int width,int height)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        puts("\n");
    }
}
int* right_diagonal(int** matrix,int size)
{
    int* array = (int*)malloc(size * size * sizeof(int));
    int i, j, m = 0;
    for (int k = size-1;k>=0;k--)
    {
        i = 0;
        j = k;
        while (j < size)
        {
            array[m] = matrix[i][j];
            i++;
            j++;
            m++;
        }
    }
    for (int k = 1; k < size; k++)
    {
        i = k;
        j = 0;
        while (i < size)
        {
             array[m] = matrix[i][j];
            i++;
            j++;
            m++;
        }
    }
    return array;
}
int * left_diagonal(int** matrix, int size)
{
    int* array = (int*)malloc(size * size * sizeof(int));
    int i, j, m = 0;
    for (int k = 0; k < size; k++)
    {
        i = 0;
        j = k;
        while (j >= 0)
        {
            array[m] = matrix[i][j];
            i++;
            j--;
            m++;
        }
    }
    for (int k = 1; k < size; k++)
    {
        i = k;
        j = size-1;
        while (i < size)
        {
            array[m] = matrix[i][j];
            i++;
            j--;
            m++;
        }
    }
    return array;
}
int * spiral_left(int** matrix, int size)
{
    int* array = (int*)malloc(size * size * sizeof(int));
    int row = size;
    int col = size;
    int row1 = 0, col1 = 0,k=0;
    while (row1 < size && col1 < size)
    {
        for (int i = col1; i < col; i++)
        {
            array[k] = matrix[row1][i];
            k++;
        }
        row1++;
        for (int i = row1; i < row; i++)
        {
            array[k] = matrix[i][col-1];
            k++;
        }
        col--;
        for (int i = col-1; i >= col1; i--)
        {
            array[k] = matrix[row-1][i];
            k++;
        }
        row--;
        for(int i = row-1;i >= row1;i--)
        {
            array[k] = matrix[i][col1];
            k++;
        }
        col1++;
    }
    return array;
}
int* spiral_center(int** matrix, int size)
{
    int* array = (int*)malloc(size * size * sizeof(int));
    int row = 0;
    int col = 0;
    int row1 = size, col1 = size, k = 0;
    while (row1 > 0 && col1 > 0)
    {
        for (int i = col1 - 1; i >= col; i--)
        {
            array[size * size - k - 1] = matrix[row1 - 1][i];
            k++;
        }
        row1--;
        for (int i = row1 - 1; i >= row; i--)
        {
            array[size * size - k - 1] = matrix[i][col];
            k++;
        }
        col++;
        for (int i = col; i < col1; i++)
        {
            array[size * size - k - 1] = matrix[row][i];
            k++;
        }
        row++;
        for (int i = row; i < row1; i++)
        {
            array[size * size - k - 1] = matrix[i][col1 - 1];
            k++;
        }
        col1--;
    }
    return array;
}
void dynamic_array_free(int** A, size_t N)
{
    for (int i = 0; i < N; i++) 
    {
        free(A[i]);
    }
    free(A);
}
int main()
{
 	srand(time(NULL));
    printf("\nlab part 1\n");
    int size = rand() % 6 + 4;
    int **matrix1 = dynamic_array_alloc(size,size);
    fill_rand(matrix1, size,size);
    normal_print(matrix1, size,size);
    printf("Print matrix starting from right diagonal\n");
    int* array1 = right_diagonal(matrix1, size);
    print_arr(array1, size*size);
    printf("\nPrint matrix starting from left diagonal\n");
    int *array2 = left_diagonal(matrix1, size);
    print_arr(array2, size * size);
    printf("\nPrint matrix starting from left element, across spiral\n");
    int* array3 = spiral_left(matrix1, size);
    print_arr(array3, size * size);
    printf("\nPrint matrix starting from center, across spiral\n");
    int* array4 = spiral_center(matrix1, size);
    print_arr(array4, size * size);
    printf("\n\nlab part 2\n");
    //printf("Print width and height: ");
    int width = rand()% 9+3, height = rand()%9+3;
    //scanf_s("%d", &width);
    //scanf_s("%d", &height);
    int** matrix2 = dynamic_array_alloc(width,height);
    fill_rand(matrix2, width,height);
    normal_print(matrix2, width,height);
    free(array1);
    free(array2);
    free(array3);
    free(array4);
    dynamic_array_free(matrix1, size);
    dynamic_array_free(matrix2, width);
}