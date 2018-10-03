#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void* fact(int n)
{
    int i,f=1;
    
    for(i=n;i>=1;i--)
    {
        f *= i;
    }
    
    printf("Factorial = %d\n",f);
    
}

void main()
{
int n;
printf("Enter the value of n\n");
scanf("%d",&n);

pthread_t thread;
pthread_create(&thread,NULL,fact,n);
pthread_join(thread,NULL);
exit(0);

}
