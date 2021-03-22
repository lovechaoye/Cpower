#include<stdio.h>
int main(void){
	int num = 0x12345678;
	char * pc = (char*)&num;
	int i = 0;
	for(; i < 4; i++){
		printf("%p: %02x \n",pc,*pc++);
	}
	return 0;
}
