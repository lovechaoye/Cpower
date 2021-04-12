#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void)
{
	pid_t pid;
	if((pid = fork()) < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(pid > 0){
		while(1){
			sleep(10);
		}
	}

	exit(EXIT_SUCCESS);
}
