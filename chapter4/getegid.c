#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(void)
{
	gid_t gid;
	gid = getegid();
	fprintf(stderr,"egid = %d\n",gid);
	exit(EXIT_SUCCESS);
}

