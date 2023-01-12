/*Write a function that determines the probability that among n children there will be m girls or m boys. Provide input data control.*/

/*Написать функцию, определяющую вероятность того, что среди n детей будет m девочек или m мальчиков. Предусмотреть контроль входных данных.*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
float pd, pm;
int probability(int n, int m){
	float p = 0.45;
	float q = 1 - p;
	
	int nf = 1;
	for (int i = 1; i <= n; i++){
		nf = nf * i;	
	}
	
	int mf = 1;
	for (int i = 1; i <= m; i++){
		mf = mf * i;
	}

	int nmf = 1;
	for (int i = 1; i <= n-m; i++){
		nmf = nmf * i;
	}
	float c = nf / (mf * nmf);

	pd = (c * pow(p, m) * pow(q, n - m))*100;
	pm = (c *pow(q, m) * pow(p, n - m))*100;          
}

 
int main(){                             
	int n, m;
	float c;
	printf(" How many kids?: "); 
	scanf(" %d", &n);
  	printf(" How many of boys or girls?: ");
	scanf(" %d", &m);
	probability(n, m);
	printf(" Boys = %f, Girls = %f ", pm, pd);
	
	return 0;
 }

