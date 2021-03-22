# 
#include<stdio.h>
#
int main(void){
	#ifdef DEBUG
		printf("debug\n");
	#else
		printf("release\n");

	#endif

	return 0;
}
