#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(void)
{
	uid_t uid;
	uid = getuid();
	fprintf(stderr,"uid = %d\n",uid);
	exit(EXIT_FAILURE);
}

