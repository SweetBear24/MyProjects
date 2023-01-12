#include<stdio.h>
#include<time.h>
#include <math.h>
#include <stdlib.h>
int const N = 10;
int main()
{
	float A[N],sumA = 0,h,I1,a=0.2,b=10,f,x = 0.2, count=0;
	int i = 0;
	
	h=(b-a)/N;
	//printf("%f",h);
	
	while(x < b)
	{
		f = (sqrt(pow((2+x),3)))/pow(x,2);                                       
		x = x + h;
		A[i] = f;	
		i++;
	}
	
	for( i = 1; i <= N-1; i++)
	{	 
		sumA = sumA + A[i];
		printf("%f ",sumA);
	}
	
	I1 = h*(A[0]/2 + sumA + A[N]/2);
	printf("%f",I1);

}

