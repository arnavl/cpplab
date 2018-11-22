# include <stdio.h>
# include <pthread.h>

#define N_THREAD 5
long long int ans=1;
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
void *fact(void *no)
{
   int *x = (int*)no;
   int i = *x;
pthread_mutex_lock(&mutex1);
ans = ans * i;
pthread_mutex_unlock(&mutex1);
    
    pthread_exit(NULL);    
}
int main()
{
    int i,n,j;
    pthread_t tid[N_THREAD];
    printf("Enter Number:");
    scanf("%d",&n);    
	for(i=1;i<=n;){
		for(j=0;j<N_THREAD && i<=n;j++,i++){
			pthread_create(&tid[j],NULL,fact,(void*)&i);
			pthread_join(tid[j],NULL);
		}
	}
    printf("Factorial : %lld \n",ans);
    return 0;
}


