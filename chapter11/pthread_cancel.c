#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


void clean1(void * arg)
{
	printf("\nclean : %s,my pid = %ld,tid = %#lx",(char*)arg,(unsigned long)getpid(),(unsigned long)pthread_self());
}

void* dosth(void* arg)
{
	pthread_cleanup_push(clean1,"1");
	pthread_cleanup_push(clean1,"2");
	pthread_cleanup_push(clean1,"3");
	while(1)
	{
		//printf("my pid = %ld,tid = %#lx\n",(unsigned long)getpid(),(unsigned long)pthread_self());
	//	sleep(10);
	//	break;
	}
	puts("end");
	pthread_cleanup_pop(1);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(1);
	pthread_exit((void*)2);	
}

int numbs(int num){
	int i = 1;
	while( num /10 ){
		i++;
		num /= 10;
	}
	return i;
}

int main(void)
{
		
	printf("main pid = %ld,tid = %#lx\n",(unsigned long)getpid(),(unsigned long)pthread_self());
	pthread_t tid;
	int err;
	if((err = pthread_create(&tid,NULL,dosth,NULL))){
		fprintf(stderr,"pthread_create error:%s\n",strerror(err));
		exit(EXIT_FAILURE);
	}
	int i = 2;
	while(i){
		printf("\r倒计时%5d",i);
		fflush(stdout);
		sleep(1);
		i--;
	}
	printf("\n");
	if((err = pthread_cancel(tid))){
		fprintf(stderr,"pthread_cancel error:%s\n",strerror(err));
		exit(EXIT_FAILURE);
	}
	return 0;
}
