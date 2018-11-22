// WAP to print "Hello World" using threads

#include<stdio.h>
#include<pthread.h>
void *f1()
{
	printf("Hello World\n");
}
int main()
{
	pthread_t p1;
	pthread_create(&p1,NULL,f1,NULL);
	pthread_join(p1,NULL);
	return 0;
}
