//matrix multiplication


#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define m 3
#define n 3
#define p 3
int a[m][n],b[n][p],c[m][p];
void * fun(void *ptr)
{

int main()
{
	pthread_t id;
	printf("enter values in first matrix...\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	printf("enter values in second matrix...\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<p;j++)
			scanf("%d",&b[i][j]);
	}


	pthread_create(&id,NULL,fun,NULL);
	pthread_join(id,NULL);
	printf("resultant matrix is..\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<p;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
