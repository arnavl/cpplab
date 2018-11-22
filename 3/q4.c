# include<stdio.h>
# include<pthread.h>


int TotalSum=0;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
void *thread_sum(void *no)
{
   int *x = (int*)no;
   int i = *x;
    
   
        pthread_mutex_lock(&mutex1);
        TotalSum = TotalSum + i*i;
        pthread_mutex_unlock(&mutex1);
    
    pthread_exit(NULL);    
}
int main()
{
    int i,n,j;
    pthread_t tid[5];
    printf("Enter n:\n");
    scanf("%d",&n);    
	for(i=0;i<=n;i++){
		for(j=0;j<5 && i<=n;j++,i++){
			pthread_create(&tid[j],NULL,thread_sum,(void*)&i);
			pthread_join(tid[j],NULL);
		}
		i--;
	}
    printf("Final Sum is : %d \n",TotalSum);
    return 0;
}

