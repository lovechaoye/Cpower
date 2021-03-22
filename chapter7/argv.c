#include<stdio.h>
#include<stdlib.h>
int main(int argc,char * argv[])
{	
	int count = 0;
	char * str;
	while((str = argv[count++]) != NULL){
		printf("%s\n",str);
	}	
	printf("count = %d,argc = %d\n",count-1,argc);
	exit(EXIT_SUCCESS);
}
