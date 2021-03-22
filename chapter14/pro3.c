#include<stdio.h>
#define PRINT(a,b) printf(#a,#b)

int main(void){
	PRINT(%s\n,a+b);
	return 0;
}
