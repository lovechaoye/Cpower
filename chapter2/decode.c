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
	const char *cypher = argv[1];
	int cyphersz = strlen(cypher);
	int plainsz = DECODESIZE(cyphersz) + 1;
	char * plain = (char *)malloc(plainsz);
	if(plain == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	memset(plain,0,plainsz);
	printf("****************decode*********************\n");
	decode(cypher,cyphersz,plain,plainsz);
	printf("base64 decode (%s) -> (%s)\n",cypher,plain);
	free(plain);
	exit(EXIT_SUCCESS);
}
