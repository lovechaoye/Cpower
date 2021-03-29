#include<stdio.h>
#include"base64.h"
#include<stdlib.h>
#include<string.h>
const char MAP[] ={
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
		    '0','1','2','3','4','5','6','7','8','9','0','+','/'
			};
int main(int argc,char * argv[])
{
		int i;
		size_t size = sizeof(MAP);
		char * array = (char*)malloc(128);
		memset(array,0,128);	
		for(i = 0 ; i < size; i++){
			array[MAP[i]] = i;	
			
		}
		int count =0;
		for(i = 0; i < 128; i++){
			printf("%#x,",array[i]);
			if(array[i] != 0)
				count++;
				
		}
		printf("\n count = %d",count);
		exit(EXIT_SUCCESS);
}
