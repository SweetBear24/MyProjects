#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int random(int n)
{
	return rand()%n;
}
void FillRand(int *array,int countelements,int numelements)
{
	int i;
	for (i = 0;i<countelements;i++)
	{
		array[i] = random(numelements);
	}
}
void PrintMas(int *array,int countelements)
{
	int i;
	for (i=0;i<countelements;i++)
	{
		printf("%d  ",array[i]);
	}
}
void dynamic_array_print(int **A, size_t N, size_t M)
{
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%*d", 5, A[i][j]);
        }
        printf("\n");
    }
}
int ** dynamic_array_alloc(size_t N, size_t M)
{
    int **A = (int **)malloc(N*sizeof(int *));
    for(int i = 0; i < N; i++) {
        A[i] = (int *)malloc(M*sizeof(int));
    }
    return A;
}

void dynamic_array_free(int **A, size_t N)
{
    for(int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);
}
int main()
{
	int i,m=0,k=0,j,ostat=0,fullnum=0,k1=0;
	printf("Enter m - number of array size:\n");
	scanf("%d",&m);
	int *arr =  (int *)malloc(m*sizeof(int));
	FillRand(arr,m,20);
	printf("Generated array of %d elements:\n",m);
	PrintMas(arr,m);
	printf("\n");
	printf("Enter k - number of matrix width size:\n");
	scanf("%d",&k);
	if (k>m)
	{
		printf("You print valid number, ERROR\n");
		return 1;
	}
	ostat = (int)(m / k);
	int strokasize = ostat;
	if (m%k !=0 )
	{
		strokasize += 1;
	}
	int **dunarr = dynamic_array_alloc(strokasize, k);
	for(i = 0;i < strokasize;i++)
	    for(j = 0;j<k;j++)
	    {
	    	if(k1<m)
	    	{
	    	    dunarr[i][j] = arr[k1];
	    	    k1++;
	        }
	        else
	        {
	        	dunarr[i][j] = 0;
			}
		}
	dynamic_array_print(dunarr,strokasize,k);
	dynamic_array_free(dunarr,strokasize);
	free(arr);
	return 0;
}
