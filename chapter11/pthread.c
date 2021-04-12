#include<stdio.h>
#include<unistd.h>
int main(void)
{
	#ifdef _POSIX_THREADS
		printf("支持\n");
	#endif

	return 0;
}
