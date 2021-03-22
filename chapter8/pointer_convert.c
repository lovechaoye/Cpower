#include<stdio.h>
int main(void){
	int num = 3;
	int *pi = &num;
	printf("Before:%p\n",pi);
	int tmp = (int)pi;
	pi = (int*)tmp;
	printf("After: %p\n",pi);
	return 0;
}
