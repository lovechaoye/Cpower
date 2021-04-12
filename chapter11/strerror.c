#include<stdio.h>
#include<string.h>
int main(void)
{
	int i ;
	for(i = 0; i< 256; i++){
		fprintf(stderr,"errno %d : %s\n",i,strerror(i));
	
	}


	return 0;
}
