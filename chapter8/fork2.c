#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define END ((char*)NULL)
int main(int argc ,char * arv[])
{
	pid_t p;
	char * argv[] = {"arg1",END};
	char * envp[] = {"lichao=god",END};
	if((p = fork()) < 0){
		perror("fork error");
		exit(EXIT_FAILURE);
	}else if(p == 0){
		execvp("date",argv);
	}else{
	
		
	}
	
	exit(EXIT_SUCCESS);
}
