#include<stdio.h>
#include"base64.h"
#include<stdlib.h>
#include<string.h>

int main(int argc,char * argv[])
{
	if(argc != 2)
	{
		fprintf(stderr,"Usage : %s string\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	const char *msg = argv[1];
	int oldsz = strlen(msg);
	int newsz = ENCODESIZE(oldsz) + 1;
	char* new = (char*)malloc(newsz);
	if(new == NULL){
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	memset(new , 0 ,newsz);
	printf("****************encode*********************\n");
	encode(msg,oldsz,new,newsz);
	printf("base64 encode (%s) -> (%s)\n",msg,new);
	free(new);
	exit(EXIT_SUCCESS);
}
