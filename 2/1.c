#include <stdio.h>
#include <pthread.h>

void * thread_sum(void *);
int sum=0;
pthread_mutex_t mVar=PTHREAD_MUTEX_INITIALIZER;

int main()
{
    int n,i;
    pthread_t tid;
    printf("Enter n:");
    scanf("%d",&n);    
    pthread_create(&tid,NULL,thread_sum,(void *)&n);
    for(i=1;i<=n;i=i+2)
    {
        pthread_mutex_lock(&mVar);
        sum=sum + i;
        pthread_mutex_unlock(&mVar);
    }
    
    pthread_join(tid,NULL);
    
    printf("Sum: %d \n",sum);
    return 0;
}

void *thread_sum(void *no)
{
    int *n,i;
    n=(int*)no;
    
    for(i=2;i<=*n;i=i+2)
    {
        pthread_mutex_lock(&mVar);
        sum=sum + i;
        pthread_mutex_unlock(&mVar);
    }
    pthread_exit(NULL);    
}
