#include <stdio.h>
# include<pthread.h>


void* fib(void* no){
	int* temp = (void*)no;
	int n = *temp;

	int i,c=0;
  	int a=0;
   	int b=1;
   	printf("Fibonacci:\n");
	 while(c<=n){
      		 printf("%d ",c);
       		a=b;
       		b=c;
       		c=a+b;
   	}
	printf("\n");
}
void * prime(void* no){
	int* temp = (void*)no;
	int n = *temp;
	int i,j,fact;
	printf("Prime:\n");
	for(i=1; i<=n; i++){
        	fact=0;
        	for(j=1; j<=n; j++){
            		if(i%j==0)
                	fact++;
        	}
        	if(fact==2)
            		printf("%d " ,i);
    }
    printf("\n");
}

int main(){

	int n ;
	scanf("%d",&n);
	pthread_t f,p;
	pthread_create(&f,NULL,fib,(void*)&n);
	pthread_join(f,NULL);
	pthread_create(&p,NULL,prime,(void*)&n);
	pthread_join(p,NULL);

}
