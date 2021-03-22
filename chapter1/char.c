#include<stdio.h>
#include<wchar.h>
int main(void){
	printf("%d\n",sizeof(char));
	printf("%d\n",sizeof('a'));
	printf("%d\n",sizeof(wchar_t));
	return 0;
}
