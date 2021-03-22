// environ 环境变量，全局环境变量
//
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	extern char ** environ;
	int count = 0;
	char * str;
	while((str = *(environ + count++)) != NULL){
		printf("%s\n",str);
	}
	printf("********** sum = %d *************\n",count - 1);
	exit(EXIT_SUCCESS);
}
