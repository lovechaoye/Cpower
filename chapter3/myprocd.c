#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void)
{
	unsigned int i = 0;
	while(1){
		printf("%d\n",++i);
		sleep(2);
	}

	exit(EXIT_SUCCESS);
}
