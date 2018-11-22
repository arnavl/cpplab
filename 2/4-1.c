#include <stdio.h>
#include<pthread.h>

#define N 5
float ans[N];
struct student
{
    char name[50];
    int roll;
    int marks[5];
}s[N];

void* func(void* arr){
	int* x = (int*)arr;
	int sum = 0;
	int i=0;
	for(i=0;i<5;i++){
		sum += *(x+i);
		
	}
	  //printf("Ans : %f\n",(sum/5.0));
	  //pthread_exit(NULL);
	 return (void*)(sum/5.0);
}

int main()
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("Enter name,roll number and marks in 5 subjects\n");
		scanf("%s",&s[i].name);
		scanf("%d",&s[i].roll);
		int j;
		for(j=0;j<5;j++)
			scanf("%d",&s[i].marks[j]);
	}
	pthread_t tid[N];
	for(i=0;i<N;i++)
	{
		pthread_create(&tid[i],NULL,func,(void*)&s[i].marks[0]);
	}
	for(i=0;i<N;i++)
	{
		void* v;
		pthread_join(tid[i],(void*)v);
		printf("for student no %d, avg : %f\n",i,(float)(*v));
	}
	return 0;

}
