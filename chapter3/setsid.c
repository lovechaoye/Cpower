#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
int main(void)
{
	pid_t pid;
	pid_t p;
	int status;
	int i = 0;
	if ((pid = fork()) < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(pid == 0)
	{
		if((p = setsid()) == -1){
			perror("setsid");
			exit(EXIT_FAILURE);
		}	
		execl("./myprocd","httpd",NULL);
		perror("execl");
		exit(EXIT_FAILURE);
	}
	//wait(&status);
	exit(EXIT_SUCCESS);
}
