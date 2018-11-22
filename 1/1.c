// WAP to create 5 threads in C

#include<stdio.h>
#include<pthread.h>
void *t1()
{
	printf("1\n");
}
void *t2()
{
	printf("2\n");
}
void *t3()
{
	printf("3\n");
}
void *t4()
{
	printf("4\n");
}
void *t5()
{
	printf("5\n");
}
int main()
{
	pthread_t tid1,tid2,tid3,tid4,tid5;
	pthread_create(&tid1,NULL,t1,NULL);
	pthread_create(&tid2,NULL,t2,NULL);
	pthread_create(&tid3,NULL,t3,NULL);
	pthread_create(&tid4,NULL,t4,NULL);
	pthread_create(&tid5,NULL,t5,NULL);
	// printf("main\n");
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);
	pthread_join(tid4,NULL);
	pthread_join(tid5,NULL);
	return 0;
}
