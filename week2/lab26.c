#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t mutex;

void* prime()
{

pthread_mutex_lock(&mutex);
    int i,j,flag;
int n;
printf("Enter the value of n\n");
scanf("%d",&n);
    
        printf("Prime Numbers are:");
    
    for(i=2;i<n+1;i++)
    {
    flag =0;
        for(j=2;j<=i/2;j++)    
        {    
            if(i%j==0)    
            {    
                flag=1;    
                break;    
            }    
        }    
        if(flag==0)    
        printf("%d\n",i);   
    }
pthread_mutex_unlock(&mutex);
}

void main()
{
pthread_t thread;


pthread_create(&thread,NULL,prime,NULL);
pthread_join(thread,NULL);
exit(0);
}
