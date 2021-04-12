#include<stdio.h>
#include<pthread.h>
int main(void)
{
	pthread_t thread;
	printf("%ld\n",thread = pthread_self());


	return 0;
}
