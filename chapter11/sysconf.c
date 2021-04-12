#include<stdio.h>
#include<unistd.h>
int main(void)
{
	long ret;
	if((ret = sysconf(_SC_THREADS)) == -1 ){
		perror("_SC_THREADS not supported\n");
		return -1;
	}
	printf("支持\n");
	return 0;
}
