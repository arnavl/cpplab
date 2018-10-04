//-lpthread -lrt
#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h>

sem_t sem;

void* thread(void* arg) 
{ 
	while(1)
	{
		sem_wait(&sem); 
		printf("\nEntered critical section\n"); 
  
		sleep(2); 
	  
		printf("\nExiting critical section\n"); 
		sem_post(&sem); 
	}    
} 

int main() 
{ 
	sem_init(&sem,0,1); 
	pthread_t t[10];
	int i=0;
	for(i=0;i<10;i++)
	{
		pthread_create(&t[i],NULL,thread,NULL); 
		sleep(2);
	}
	for(i=0;i<10;i++)
	{
		pthread_join(t[i],NULL);        
	}    
	sem_destroy(&sem); 
	return 0; 
}
