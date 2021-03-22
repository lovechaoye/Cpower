#include<stdio.h>

typedef struct struct_person{
	char* firstName;
	char* lastName;
	char* title;
	short age;
} Person;

int main(int argc,char* argv[]){
	printf("%d\n",sizeof(Person));
	return 0;
}
