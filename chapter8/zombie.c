#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(void)
{
	int stat_loc;
	pid_t p;
	p = fork();
	if(p == 0)
	{
		printf("I am son,pid = %d\n",getpid());
	}
	else
	{
		//wait(&stat_loc);
		while(1){
			printf("I am father,pid = %d\n",getpid());
			sleep(1);
		}
	}

	return 0;
}
