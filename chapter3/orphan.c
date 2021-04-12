#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	if( (pid = fork() ) < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(pid == 0){ // children
		while(1){
			printf("sleep\n");
			sleep(10);
		}
	}else{
		printf("father dead\n");
		exit(EXIT_SUCCESS);
	}
}
