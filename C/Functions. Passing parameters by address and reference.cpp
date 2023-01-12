/*Write a function that calculates the perimeter and area of a triangle. The length of its sides is passed to the function.
The results are returned via pointer parameters. In the function, also provide for an error in the entered data.*/

/*Написать функцию, которая вычисляет периметр и площадь треугольника. В функцию передаётся длина его сторон. 
Результаты возвращаются через параметры-указатели. В функции также предусмотреть ошибку в введённых данных.*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
float P, S;
float Triangle(float &A, float &B, float &C){
	if((A + B > C) and (A + C > B) and (B + C > A)){
		P = A + B + C;
		float p = P/2;
		S =	sqrt(p * (p - A) * (p - B) * (p -C));
		return 1;
	}else{
		return 0;
	}               
}

 
int main(){                             
	float A, B ,C;
	printf(" Enter the size of sides: \n");  
  	printf(" A = "); 
	scanf(" %f", &A);
  	printf(" B = "); 
	scanf(" %f", &B);
  	printf(" C = "); 
	scanf(" %f", &C);
	Triangle(A, B, C);
	if (Triangle(A, B, C) != 0){	
		printf("\n P = %.3f, S = %.3f", P, S);
	} else{
		printf("\n Triangle error ");
	}	
}

