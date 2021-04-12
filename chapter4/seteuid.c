#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc,char* argv[])
{
	if(argc != 2 )
	{
		fprintf(stderr,"Usage : %s num\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	uid_t uid;
	uid = atoi(argv[1]);
	if ( seteuid(uid) == -1 )
	{
		perror("seteuid");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
