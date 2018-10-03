#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* hike()
{
    int i,salary[5],total=0;
    float p;
    char name[10],sub[5][10],id[10],designation[10];
    printf("What is your name, Id,Designation/");
    scanf("%s%s%s",name,id,designation);
    
    for(i=0;i<5;i++)
    {
        printf("enter %dth year's salary",i+1);
        scanf("%d",&salary[i]);
    }
    
    for(i=1;i<5;i++)
    {
          printf("%dth hike : %f\n",i,(salary[i]-salary[i-1])*100/salary[i-1]);
    }
    
}

void main()
{
    pthread_t thread;
    pthread_create(&thread,NULL,hike,NULL);
    pthread_join(thread,NULL);
    exit(0);
}
