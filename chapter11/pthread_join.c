#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
int ret = 10;
void* dosth(void* arg) 
{
	const char * restrict msg = (const char *)arg;
	printf("my pid = %ld ,tid = %lx,msg = %s\n",(unsigned long)getpid(),(unsigned long)pthread_self(),msg);
	sleep(10);
	pthread_exit(&ret);
}

int main(void)
{
	pthread_t tid;
	int err;
	if((err = pthread_create(&tid,NULL,dosth,"hello,myson"))){
		printf("pthread_create failed : %s\n",strerror(err));
		exit(EXIT_FAILURE);
	}
	int * retval;
	pthread_join(tid,(void**)&retval);

	printf("my pid = %ld,tid = %lx,ret = %d\n",(unsigned long)getpid(),(unsigned long)pthread_self(),*retval);

	return 0;
}
