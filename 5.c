/*
Program to computes the total of the values of the matrix 
using thread and mutex lock on global variable total
*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define ROW 10
#define COL 10
#define MAX_NUM 100


int arr[ROW][COL];
long long int sum=0;
pthread_mutex_t m;
int i;
void *add()
{
	int j;
	pthread_mutex_lock(&m);
	int id=i;
	pthread_mutex_unlock(&m);
	long long int row_sum=0;
	for(j=0;j<COL;j++)
	{
		row_sum+=arr[id][j];
	}
	pthread_mutex_lock(&m);
	sum+=row_sum;
	pthread_mutex_unlock(&m);
}

int main()
{
	int j;
	srand(time(0));
	for(i=0; i<ROW; i++)
		for(j=0; j<COL; j++)
			arr[i][j]=rand()%MAX_NUM;
			// printf((j==COL-1)?"%d\n":"%d ", arr[i][j]=rand()%MAX_NUM);
	pthread_mutex_init(&m,NULL);
	pthread_t t[ROW];
	for(i=0; i<ROW; i++)
		pthread_create(&t[i],NULL,add,NULL);
	for(i=0; i<ROW; i++)
		pthread_join(t[i],NULL);
	printf("Sum: %lld\n", sum);
	return 0;
}
