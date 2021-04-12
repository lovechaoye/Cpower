#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc,char * argv[])
{
		if(argc != 2 ){
				fprintf(stdout,"Usage: %s file\n",argv[0]);
				return 1;
		}
		FILE * fp;
		if( (fp = fopen(argv[1],"r")) == NULL)
		{
				perror("fopen");
				return 1;
		}
		char buff[1024];
		while(fgets(buff,1024,fp) != NULL){
				printf("%s",buff);
		}
		if (feof(fp))
				puts("EOF indicator set");
		if (ferror(fp))
				puts("ERROR indicator set");
		if(fclose(fp)){
			perror("fclose");
		}
		return 0;
}
