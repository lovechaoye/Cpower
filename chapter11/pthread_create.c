#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


void* dosth(void * msg)
{
	while(1){
		printf("current pid = %ld,current tid =%lx\n",(unsigned long)getpid(),(unsigned long)pthread_self());
		sleep(1);
	}
	return NULL;
}

int main(void)
{
	pthread_t tid;
	int error;
	if( (error = pthread_create(&tid,NULL,dosth,NULL))){
		fprintf(stderr,"error msg :%s\n",strerror(error));
		exit(EXIT_FAILURE);
	}
	dosth(NULL);	
	return 0;
}
