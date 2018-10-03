#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
 void fun(int sig)
{
	printf("\nthe %d key is pressed ...\n",sig);
	//signal(SIGINT,SIG_DFL);
}
int main()
{
	
	signal(SIGINT,fun);
	pid_t pid;
	int count=0;
	while(1)
	{
		printf("the process id is %d :::=\n",pid);
		printf("sleep time is ...%d",count);
		count++;
		sleep(1);
	}
	return 0;
}
