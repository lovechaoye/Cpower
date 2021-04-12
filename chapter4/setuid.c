#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
/**
 * setuid会同时设置real id,effective id, saved id
 */
int main(int argc,char* argv[])
{
	if(argc != 2 )
	{
		fprintf(stderr,"Usage : %s num\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	uid_t uid;
	uid = atoi(argv[1]);
	if ( setuid(uid) == -1 )
	{
		perror("setuid");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
