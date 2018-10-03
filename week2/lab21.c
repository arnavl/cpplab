#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void* sum(int n)
{
    int i,sum=0;
    
    for(i=1;i<n+1;i++)
    {
        sum+= i;
    }
    
    printf("SUM = %d\n",sum);
    
}

void main()
{
int n;
printf("Enter the value of n\n");
scanf("%d",&n);

pthread_t thread;
pthread_create(&thread,NULL,sum,n);
pthread_join(thread,NULL);
exit(0);

}
