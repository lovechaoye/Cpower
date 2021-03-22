#include<stdio.h>
#include<string.h>
int main(void){
	char *str1 = "mike";
	char *str2 = "mtmy";
	int ret = strcmp(str1,str2);
	printf("ret = %d\n",ret);
	return 0;
}
