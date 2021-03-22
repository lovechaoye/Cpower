#include<stdio.h>
struct CHAR {
	unsigned ch : 7;
	unsigned font: 6;
	unsigned size: 19;
};

struct DISK_REGISTER_FORMAT{
	unsigned command:5;
	unsigned sector:5;
	unsigned track:9;
	unsigned error_code:8;
	unsigned head_loaded:1;
	unsigned write_protect:1;
	unsigned disk_spinning:1;
	unsigned error_occurred:1;
	unsigned ready:1;
};

#define DISK_REGISTER\
	((struct DISK_REGISTER_FORMAT*)0xc0200142)


int main(void){
	struct CHAR ch;
	ch.ch =10;
	ch.font = 20;
	ch.size = 1000;
	printf("ch = %#x\t,font = %#x\t,size = %#x\n",ch.ch,ch.font,ch.size);
	return 0;
}
