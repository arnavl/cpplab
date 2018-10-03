#include<stdio.h>
#include<pthread.h>
int num;
int a;
void* factorial()
{
int fac=1;
for(a=1;a<=num;a++) 
{
fac=fac*a;
printf("Factorial of Given Number is = %d",fac);
}
}
int main()
{
pthread_t t;
printf(" Enter Number To Find Its Factorial: ");
scanf("%d",&num);
pthread_create (&t,NULL,factorial,(void*)&num);
//return 0;
}
