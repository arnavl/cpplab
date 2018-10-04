#include <stdio.h>
#include <pthread.h>

//sum of first n numbers


int sum = 0;
void *add(void *data)
{
  int dat = (int)data;
  printf("%d\n",dat );
  sum += dat;

  pthread_exit(NULL);
}

int main()
{

  int n = 25;
  pthread_t id[n];

  for(int i = 0;i <= n ; i++ )
  {
    int rc = pthread_create(&id[i],NULL,add,(void*)i);
    pthread_join(id[i],NULL);

    printf("sum is %d\n",sum);
  }

}
