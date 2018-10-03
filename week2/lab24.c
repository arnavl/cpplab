#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* per()
{
    int i,id,marks[5],total=0;
    float p;
    char name[10],sub[5][10];
    printf("What is your name/");
    scanf("%s",name);
    
    for(i=0;i<5;i++)
    {
        printf("enter %dth subject and its marks",i+1);
        scanf("%s%d",sub[i],&marks[i]);
    }
    
    for(i=0;i<5;i++)
    {
        total += marks[i];
    }
    printf("Hello %s!\nYour Percentage is %0.2f\n",name,total*1.0/5);
    
}

void main()
{
    pthread_t thread;
    pthread_create(&thread,NULL,per,NULL);
    pthread_join(thread,NULL);
    exit(0);
}
