#include<stdio.h>
#include<string.h>
#define SIZE 100
char* format(char*,size_t,const char*,size_t,size_t);
int main(void){
	char buffer[SIZE];
	printf("%s\n",format(buffer,SIZE,"Axle",25,45));	
	return 0;
}

char* format(char* buffer,size_t size,
				const char*  name,size_t quantity,size_t weight){
		snprintf(buffer,size,"Item: %s  Quantity: %u Weight: %u",
						name,quantity,weight);			
		return buffer;
}
