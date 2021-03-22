#include<stdio.h>
int main(){
	#if defined(SIZE)
		int array[SIZE];
		int i;
		for(i =0;i < SIZE;i++){
			printf("%d\t",array[i]);
		}
		putchar('\n');
	#else
		#error not define SIZE

	#endif
	return 0;
}
