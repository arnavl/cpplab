#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void* find()
{
    int i,n;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }    
    
    int max=arr[0],min=arr[0];
    
    for(i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
        if(arr[i]<min)
        {
            min = arr[i];
        }
    }
    
    printf("Max = %d  Min = %d\n",max,min);
    
}

void main()
{

pthread_t thread;
pthread_create(&thread,NULL,find,NULL);
pthread_join(thread,NULL);
exit(0);

}
