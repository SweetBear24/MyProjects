/*Create a two-dimensional dynamic array of int type, fill it with random numbers,
display. The size of each one-dimensional array is arbitrary (the matrix is not
must be rectangular). Store the number of matrix rows in a separate
variable in main.*/

/*Создать двумерный динамический массив типа int, заполнить его случайными числами,
вывести на экран. Размер каждого одномерного массива – произвольный (матрица не
обязана быть прямоугольной). Количество строк матрицы хранить в отдельной
переменной в main.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
int c;
int** genRandArray(int size, int maxValue){
	int size1 = 0;
 	int **matrix = new int* [size];   // создаем 
  	for (int i = 0; i < size; i++) { 
	  	size1=rand()%10;        // двумерный
    	matrix[i] = new int [size1+1]; // массив 
		matrix[i][0]= size1;
	} 		
	for (int i = 0; i < size; i++) {  
		for (int j = 1; j < matrix[i][0]+1; j++) {  
 		   matrix[i][j] = rand()%maxValue;
		}
	}
	return matrix;
}
void print(int **matrix){
	printf("%d \n", c);
	for (int i = 0; i < c; i++) {
		printf("%d: ", matrix[i][0]);
		for (int j = 1; j < matrix[i][0]+1; j++){
			printf("%d ", matrix[i][j]);
        }
    	printf("\n");
	}
}

int main(){
	srand(time(NULL));	
	int size = rand()%10;
	c=size;
	int maxValue = 100;
	int **matrix = genRandArray(size, maxValue);
	print(matrix);
	system("pause");
  	for (int i = 0; i < size; i++) {
    	delete [] matrix[i];  // удаляем массив
  	}
}


