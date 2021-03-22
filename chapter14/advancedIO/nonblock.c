#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<fcntl.h>


static char buff[500000];

void set_fl(int fd,int flag);
void clear_fl(int fd,int flag);

int main(void)
{
	int ntowrite,nwrite;

	char * ptr;

	ntowrite = read(STDIN_FILENO,buff,sizeof(buff));

	fprintf(stderr,"read %d bytes\n",ntowrite);

	set_fl(STDOUT_FILENO,O_NONBLOCK);

	ptr = buff;
	while(ntowrite > 0 )
	{
		errno = 0;
		nwrite = write(STDOUT_FILENO,ptr,ntowrite);
		fprintf(stderr,"nwrite = %d,errno = %d\n",nwrite,errno);
		if( nwrite > 0 )
		{
			ptr += nwrite;
			ntowrite -= nwrite;	
		}
	
	}
	clear_fl(STDOUT_FILENO,O_NONBLOCK);

	exit(EXIT_SUCCESS);
}

void set_fl(int fd,int flag)
{
	int  old;
	if((old = fcntl(fd,F_GETFL)) == -1)
	{
		perror("fcntl set failed");
		exit(EXIT_FAILURE);
	}
	old |= flag;	
	if(fcntl(fd,F_SETFL,old)){
		perror("fcnt set faliled");
		exit(EXIT_FAILURE);
	}

}


void clear_fl(int fd,int flag)
{
	int  old;
	if((old = fcntl(fd,F_GETFL)) == -1)
	{
		perror("fcntl get failed");
		exit(EXIT_FAILURE);
	}
	old &= ~flag;	
	if(fcntl(fd,F_SETFL,old)){
		perror("fcnt set faliled");
		exit(EXIT_FAILURE);
	}

}
