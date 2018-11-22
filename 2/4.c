#include <stdio.h>
#include<pthread.h>

struct student
{
    char name[50];
    int roll;
    int marks[5];
};

void* func(void* arr){
	int* x = (int*)arr;
	int sum = 0;
	int i=0;
	for(i=0;i<5;i++){
		sum += *(x+i);
	}
	printf("Ans : %f\n",(sum/5.0));
	  pthread_exit(NULL);
}

int main()
{
	struct student s;
	printf("Enter name,roll number and marks in 5 subjects\n");
	pthread_t tid;
	scanf("%s",&s.name);
	scanf("%d",&s.roll);
	int i=0;
	for(i=0;i<5;i++){
		scanf("%d",&s.marks[i]);
	}
	pthread_create(&tid,NULL,func,(void*)&s.marks);
	pthread_join(tid,NULL);
	return 0;

}
