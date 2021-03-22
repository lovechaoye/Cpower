#include"strlen.h"
size_t stringLength(char * string){
	size_t length = 0;
	while(*(string++)){
		length++;
	}
	return length;
}
