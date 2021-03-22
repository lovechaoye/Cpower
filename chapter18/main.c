#include<stdio.h>
int static_num = 10;
typedef void (*Func)(int,int);
void add(int a,int b){
	printf("sum = %d\n",a+b);
}
void sub(int a,int b){
	printf("sub = %d\n",a -b );
}

void operate(int a,int b,Func f){
	f(a,b);
}
int main(void){
	int a = 10;
	static int inner_static =10;
	int b = 8;
	operate(a,b,add);
	operate(a,b,sub);

	return 0;
}
