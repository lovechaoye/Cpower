#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(void)
{
	pid_t p;
	p = fork();
	if(p < 0){
		perror("fork failed");
		exit(EXIT_FAILURE);
	}else if(p == 0){ //子进程
		printf("son 执行\n");
		while(1);
	}else{ //父进程执行
		printf("father 执行\n");
	}
	sleep(10);
	exit(EXIT_SUCCESS);
}
