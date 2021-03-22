#include<stdio.h>
int main(int argc ,char* argv[]){

	char*** addr = &argv;
	char** env = *(addr + 1);
	char* s;
	int i = 0;
	while((s = (*(env + i))) != NULL){
		printf("%s\n",s);
		i++;
	} 
	return 0;
}
