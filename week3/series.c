/*#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *fun(void *ptr)
{
	int *n=(int *)ptr;
	int n1=*n;
	int i;
	for(i=1;i<=n1;i++)
	{
		
		printf("%d",i*i);
		if(i!=n1)
		{
			printf("+");
		}

	}
}
int main()
{
	pthread_t id;
	int n;
	scanf("%d",&n);
	pthread_create(&id,NULL,fun,(void *)&n);
	pthread_join(id,NULL);
	return 0;
}*/
/*
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define m 3
#define n 3
#define p 3
int a[m][n],b[n][p],c[m][p];
void * fun(void *ptr)
{
	int sum=0,i,j,k;
	for(i=0;i<m;i++)
	{
		for(j=0;j<p;j++)
		{
			sum=0;
			for(k=0;k<n;k++)
			{
				sum+=a[i][k]*b[k][j];
			}
			c[i][j]=sum;
		}
	}
}
int main()
{
	pthread_t id;
	printf("enter values in first matrix...\n");
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	printf("enter values in second matrix...\n");
	for(i=0;i<n;i++)
	{
		for( j=0;j<p;j++)
			scanf("%d",&b[i][j]);
	}	
	pthread_create(&id,NULL,fun,NULL);
	pthread_join(id,NULL);
	printf("resultant matrix is..\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<p;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void * fun(void *ptr)
{
	char *str=(char *)ptr;
	printf("%s",str);
	FILE *fp;
	fp=fopen(str,"r");
	if(fp==NULL)
	{
		perror("Error: galat hai ye");
		exit(1);
	}
	printf("successfully opened...\n");
	fclose(fp);
}
int main(int argc,char *argv[])
{
	pthread_t id;
	pthread_create(&id,NULL,fun,(void *)argv[1]);
	pthread_join(id,NULL);
	return 0;
}
