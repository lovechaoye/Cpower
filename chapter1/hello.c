#include<stdio.h>
#include"a.h"
#include"b.h"
int main(void){
	char msg[] = "msgddddddddddddddddddddd";
	printf("%s\n",msg);
	#ifdef hello
	printf("hello,world\n");
	#endif
	return 0;
}
