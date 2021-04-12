// 如果main函数返回了，进程就结束了，进程结束了，所有线程也都结束了。怎么解决这个问题呢
// 1.main线程调用pthread_join。等，2.main线程调用pthread_exit（）推出.
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


void* run(void *arg)
{
	pthread_detach(pthread_self());
	printf("my pid = %ld, tid = %lx\n",(unsigned long)getpid(),(unsigned long)pthread_self());
	//while(1)
	//{
	//	printf("rest\n");
	//	sleep(10);
	//}
	sleep(20);
	return (void*)0;
}

int main(void)
{
	pthread_t tid;
	
	int err;
	if((err = pthread_create(&tid,NULL,run,"hello"))){
		printf("%s\n",strerror(err));
		exit(EXIT_FAILURE);
	}
	sleep(10);
	pthread_detach(pthread_self());
	//sleep(10);
	//pthread_exit(NULL);
	err = pthread_join(tid,NULL);
	if(err){
		fprintf(stderr,"%s\n",strerror(err));
	}
	return 0;
}
