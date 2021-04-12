#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int ret = system("type cd");
	if(ret != 0){
		perror("system");
		exit(EXIT_FAILURE);
	}
	return 0;
}
