#include<stdio.h>
#define PRINT_STRING(S)  #S
#define PRINT_STRING2(S) "S" //这么加时不对的
int main(void){
	printf("%s\n",PRINT_STRING(2DDDDD));
	return 0;
}
