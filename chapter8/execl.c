#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define END ((char*)NULL)
int main(void)
{
	char* filepath = "/home/lc/study/c/chapter8/hello";
	printf("调用exec的进程\n");	
	if(execl(filepath,"./hello",END) == -1){
		perror("execl error");
		exit(EXIT_FAILURE);	
	}else{
		printf("原进程映像还存在");
	}

	exit(EXIT_SUCCESS);	
}
