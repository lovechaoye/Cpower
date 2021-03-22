#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define END ((char*)NULL)
int main(int argc ,char * arv[])
{
	pid_t p;
	int status;
	char * argv[] = {"arg1",END};
	char * envp[] = {"lichao=god",END};
	fflush(NULL);
	if((p = fork()) < 0){
		perror("fork error");
		exit(EXIT_FAILURE);
	}else if(p == 0){
		execle("/home/lc/study/c/chapter8/print_argv_env","arg1","arg2",END,envp);
	}else{
		while(1){
			sleep(10);
		}	
		//wait(&status);	
	}
	
	exit(EXIT_SUCCESS);
}
