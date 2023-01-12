/*Create a one-dimensional dynamic array of type int, fill it with random numbers, display it on the screen. 
The size of an array must be stored in the first element of the array.*/

/*Создать одномерный динамический массив типа int, заполнить его случайными числами,
вывести на экран. Размер массива необходимо хранить в первом элементе массива.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
int* genRandArray(int size, int maxValue){
	int *mas = new int[size + 1];
	mas[0] = size; 
	for(int i=1; i<=size; i++){ 
		mas[i] = rand()%maxValue;
	}
	return mas;
}
void print(int *arr){
	printf("%d: ", arr[0]);
	for(int i=1; i<=arr[0]; i++){ 
		printf("%d ", arr[i]);
	}
}

int main(){
	srand(time(NULL));
	int size = rand()%10;
	int maxValue = 100;
	int *arr = genRandArray(size, maxValue);
	print(arr);
}

