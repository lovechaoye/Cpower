#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
typedef int (*fptrOperation)(const char*,const char*);
char* stringToLower(const char* string);
int compare(const char* s1,const char* s2);
int compareIgnoreCase(const char* s1,const char* s2);
void sort(char * array[],int size,fptrOperation operation);
void displayNames(char* names[],int size);

int main(int argc ,char* argv[]){
	char* names[] = {"Bob","Ted","Carol","Alice","alice" };
	sort(names,5,compare);
	displayNames(names,5);
	sort(names,5,compareIgnoreCase);
	displayNames(names,5);
	return 0;
}


char* stringToLower(const char* string){
	char *tmp = (char*)malloc(strlen(string) + 1);
	char *start = tmp;
	while(*string != 0 ){
		*tmp++ = tolower(*string++);
	}
	*tmp = 0;
	return start;
}

int compare(const char* s1,const char* s2){
	return strcmp(s1,s2);	
}

int compareIgnoreCase(const char* s1,const char* s2){
	char *t1 = stringToLower(s1);
	char *t2 = stringToLower(s2);
	int result = strcmp(t1,t2);
	free(t1);
	free(t2);
	return result;
}


void displayNames(char* names[],int size){
	for(int i=0; i < size; i++){
		printf("%s   ",names[i]);
	}
	printf("\n");
}

#if 0

void sort(char * array[],int size,fptrOperation operation){
	int maxIndex;
	int i;
	int j;
	char *tmp;
	for(i = 0;i < size;i++){
		max = maxIndex;
		for(j = 0;j < size - i -1; j++){
			if(operation(tmp,array[j]) < 0){
				max = j;	
			}
		}
		tmp = array[j - 1];
		array[j -1] = array[max];
		array[max] = tmp;
	}

}
#else
void sort(char * array[],int size,fptrOperation operation){
	int swap = 1;
	while(swap){
		swap = 0;
		for(int i=0;i< size -1;i++){
			if(operation(array[i],array[i+1]) > 0){
				swap =1;
				char * tmp = array[i];
				array[i] =array[i +1];
				array[i+1] = tmp;
			}
		}
	}
}

#endif
