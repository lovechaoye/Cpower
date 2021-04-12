#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int main(void)
{
	int a = 10;
	puts("begin");
	pthread_exit(&a);
	puts("end");

	return 0;
}
