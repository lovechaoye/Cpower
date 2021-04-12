#include<stdio.h>
#include<pthread.h>
#include<string.h>
int main(void)
{

	pthread_t tid = (pthread_t)29197;
	int err;
	if ((err = pthread_join(tid,NULL))){
		fprintf(stderr,"%s",strerror(err));
	}
	return 0;
}
