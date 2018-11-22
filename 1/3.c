/*
WAP that computes the square roots of the integers from 0 to 99 in a separate thread
and returns an array of doubles containing the *   results.
In the meantime the main thread should display a short message to the user
and then display the results of the computation
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#define N 100
double* arr;
void *root()
{
	arr = (double*)malloc(sizeof(double)*N);	
	int i;
	for(i=0;i<N;i++)
	{
		arr[i]=(double)sqrt(i);
	}
	return (void*)arr;
}

int main()
{
	pthread_t calc;
	double *roots;
	void *rootX;
	pthread_create(&calc,NULL,root,NULL);
	printf("Computing Square roots of numbers from 0 to %d...\n",N);
	pthread_join(calc,&rootX);
	roots=(double*)rootX;
	int i;
	for(i=0;i<N;i++)
	{
		printf("Square root of %d is %lf\n",i,(double)roots[i]);
	}
	return 0;
}
