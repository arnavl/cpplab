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
