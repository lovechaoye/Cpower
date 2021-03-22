#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char * argv[])
{	
	int errno;
	int opt;
	while((opt = getopt(argc,argv,"n:")) != -1)
	{
		switch(opt){
			case 'n':
				printf("%s\n",optarg);
				errno = atoi(optarg);		
				fprintf(stderr,"%s\n",strerror(errno));
				break;
			default:
				fprintf(stderr,"usage:%s [ -n no]\n",argv[0]);
				exit(EXIT_FAILURE);
		}	
	
	}
	exit(EXIT_SUCCESS);
}
