#include <stdio.h>
#include<pthread.h>
#define n 4
 

#define n_thread 4
 
int arr1[n][n];
int arr2[n][n];
int res[n][n];
int step_i = 0;
 
void* multi(void* arg)
{
    int core = step_i++;
 
    int i=0,j=0,k=0;
    for (i = core * n / 4; i < (core + 1) * n / 4; i++) 
        for (j = 0; j < n; j++) 
            for (k = 0; k < n; k++) 
                res[i][j] += arr1[i][k] * arr2[k][j];
}
 

int main()
{
    int i=0,j=0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            arr1[i][j] = rand() % 10;
            arr2[i][j] = rand() % 10;
        }
    }
 

   printf("Matrix A\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) 
            printf("%d ",arr1[i][j]);
        printf("\n");
    }

      printf("Matrix B\n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) 
            printf("%d ",arr2[i][j]);
        printf("\n");
    }
 
  
    pthread_t threads[n_thread];
 
   
    for (i = 0; i < n_thread; i++) {
        int* p;
        pthread_create(&threads[i], NULL, multi, (void*)(p));
    }
 
    for (i = 0; i < n_thread; i++) 
        pthread_join(threads[i], NULL);    
 

       printf("Matrix result\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) 
            printf("%d ",res[i][j]);
        printf("\n");
    }
    return 0;
}

