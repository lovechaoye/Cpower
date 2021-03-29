#include "base64.h"
const char MAP[] ={
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
	'0','1','2','3','4','5','6','7','8','9','0','+','/'
};
const char PAM[] ={
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0x3f,0,0,0,0x40,0x3e,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0,0,0,0,0,0,0,0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9,0xa,0xb,0xc,0xd,0xe,0xf,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0,0,0,0,0,0,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,0x30,0x31,0x32,0x33,0,0,0,0,0
};

int encode(const char * msg,int msgsz,char * new,int newsz)
{	
	int i ;
	int j ;
	const int sum = msgsz*8;
	for(i = 0,j = 0; i< sum;i += 6,j++)
	{
		int startbyte = BITPOSITION(i);	
		int endbyte = BITPOSITION(i + 6);
		int start = i - startbyte * 8;
		int end = i + 6 - endbyte * 8;
		char num,high,low,mask;
		high = 0xff >> start;
		low = 0xff << (8 - end);
		if(startbyte == endbyte){
			mask = high & low;
			num = (msg[startbyte] & mask) >> (8 - end);
		}else{
			num = ((msg[startbyte] & high) << end) | ((msg[endbyte] & low) >> (8 - end)); 
		}
		new[j] = MAP[0x3f & num]; 
	}
	return 0;

}
int decode(const char * cypher,int cyphersz,char * plain,int plainsz){
	char * tmp = (char *)cypher;
	int i,j,k;
	for(i = 6,j = i - 2,k = 0; k < plainsz;k++){
		char high = MASK(i,0) & (PAM[0x7f & (*tmp)]);
		char low = MASK(6,j) &(PAM[0x7f & (*(++tmp))]);
		char val = (high << (8 - i)) | (low >> j);
		if( (val & 0x80)){
			return 1;	
		}
		plain[k] = val;
		tmp = j == 0 ? ++tmp:tmp;
		i = j == 0 ? 6 : j;
		j = i - 2;
	}
	return 0;
}
