#include<stdio.h>
#define INTNAME(a) int var_ ## a

int main(void){
	INTNAME(1) = 3;
	INTNAME(2) = 4;

	return 0;
}
