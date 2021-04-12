#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(void)
{
	printf("real uid = %d\n",getuid());
	printf("effective uid = %d\n",geteuid());
	getchar();
	if( seteuid(1000) == -1){
		perror("seteuid");
		return -1;
	}
	printf("real uid = %d\n",getuid());
	printf("effective uid = %d\n",geteuid());
	getchar();
	if( seteuid(0) == -1){
		perror("setuid");
		return -1;
	}
	printf("real uid = %d\n",getuid());
	printf("effective uid = %d\n",geteuid());

	return 0;
}
