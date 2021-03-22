#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
	extern char** environ;
	puts("************** argv start *********************");
	int i;
	char * s;
	for(i = 0;i < argc ; i++)
	{
		printf("%s\n",argv[i]);
	}
	puts("************** argv end ********************");
	putchar('\n');
	puts("************** env start *********************");
	i = 0;
	while((s = *(environ + i++)) != NULL)
	{
		printf("%s\n",s);
	}
	puts("************** env end *********************");
	sleep(30);
	exit(EXIT_SUCCESS);
}
