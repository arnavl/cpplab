/*
Implement a linked list as a Parallel program (based on Pthreads)
with Mutex locks for the entire linked list Implementation should
support Search( ), Insert( ), and Delete( ) functions.
*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define MAXVAL 10
#define CALLS 20
pthread_mutex_t m;

struct node
{
	int value;
	struct node *next;
};

struct node *root=NULL;

struct node *create(int value)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->value=value;
	temp->next=NULL;
	return temp;	
}

void insert(int value)
{
	struct node *temp=create(value);
	temp->next=root;
	root=temp;
	printf("\tElement %d inserted.\n",value);
}

int search(int value)
{
	struct node *temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	temp=root;
	while(temp!=NULL)
	{
		if(temp->value == value)
		{
			printf("\tElement %d found!\n",value);
			return 1;
		}
		temp=temp->next;
	}
	printf("\tElement %d not found!\n",value);
	return 0;
}

void delete(int value)
{
	if(search(value)==0)
	{
		printf("\tElement %d can not be deleted.\n",value);
	}
	else
	{
		struct node *temp=NULL;
		temp=(struct node*)malloc(sizeof(struct node));
		struct node *prev=NULL;
		temp=(struct node*)malloc(sizeof(struct node));
		if(root->value==value)
		{
			root=root->next;
		}
		else
		{
			prev=root;
			temp=prev->next;
			while(temp->value!=value)
			{
				prev=temp;
				temp=temp->next;
			}
			prev->next=temp->next;
		}
		printf("\tElement %d deleted.\n",value);
	}
}

void choose(int choice, int value)
{
	//pthread_t calc;
	switch(choice)
	{
		case 0:
			// pthread_create(&calc,NULL,insert,NULL);
			insert(value);
			break;
		case 1:
			// pthread_create(&calc,NULL,delete,NULL);
			delete(value);
			break;
		case 2:
			// pthread_create(&calc,NULL,search,NULL);
			search(value);
			break;
		default:
			printf("\tInvalid selection\n");
	}
	//p_thread.join(calc,NULL);
}
void* thread()
{
	choose(rand() % 3,rand() % MAXVAL);
}
int main()
{
	int i=0;
	srand(time(0));
	for(i=0; i<CALLS;i++)
	{
		printf("%d:\n",i+1);
		pthread_mutex_lock(&m);
		pthread_t calc;
		pthread_create(&calc,NULL,&thread,NULL);
		pthread_join(calc,NULL);
		pthread_mutex_unlock(&m);
	}
	return 0;
}
