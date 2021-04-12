#include<stdio.h>
#include<stdlib.h>
#include<wait.h>
#include<unistd.h>
#include<sys/types.h>
/**
 *只有root用户才可以调用setuid()和seteuid()方法切换到其他用户，其他普通用户只能切换自己，所以必须具备root权限。当然主要是具备可执行文件的属主的身份，即effective uid，这个影响执行的权限。但是对于passwd这样子的方法，它还需要real id 也是 root 才可以随意修改任何用户的密码。
 如果root用户调用setuid(),则它会修改 real uid,effective uid,saved uid
 而调用seteuid ，它只是改变effective uid,对于具备 u+s 权限的可执行文件，执行的时候只是把文件的euid设置成文件属主的id而已，并没有改变readid
 *
 *
 * */
int main(int argc,char * argv[])
{
	if(argc != 4){
		fprintf(stderr,"Usage: %s who command param\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	int uid = atoi(argv[1]);
	printf("before real uid = %d,effective uid = %d\n",getuid(),geteuid());
	if(seteuid(uid) == -1){
		perror("setuid");
		exit(EXIT_FAILURE);
	}
	printf("after real uid = %d,effective uid = %d\n",getuid(),geteuid());
	char * command = argv[2];
	char * param = argv[3];
	pid_t pid;
	if((pid = fork()) == 0){
		execlp(command,command,param,(char*)NULL);	
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	wait(NULL);

	exit(EXIT_SUCCESS);
}
