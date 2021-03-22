#include<stdio.h>
int main(){
	int a = 10;
	int b =a + 10;
	printf("hello,world\n");
	int i =0;
	for(i = 0; i< 10 ;i++){
		printf("%s:%d ,%s : line : %d\n","msg",i,__FUNCTION__, __LINE__);
	}
	return 0;
}
