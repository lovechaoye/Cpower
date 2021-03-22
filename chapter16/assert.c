#include<stdio.h>
#include<assert.h>
int main(void)
{
	int i = 1001;
	puts("input an integer");
	scanf("%d",&i);
	assert(i > 0);
	#if defined(NUM) &&  NUM > 0
		printf("%d:bigger than 0\n",NUM);
	#else
		printf("%d <= 0\n",NUM);
	#endif

	return 0;
}
