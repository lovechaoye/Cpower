#include<stdio.h>
typedef union _Conversion{
	float fNum;
	unsigned int uiNum;
} Conversion;

typedef union _Conversion2{
	float *fNum;
	unsigned int * uiNum;
} Conversion2;
int isPositive(float number);
int isPositive2(float number);
int isPositive3(float number);
int main(void){
	
	return 0;
}

int isPositive(float number){
	Conversion conversion = { .fNum = number};
	return conversion.uiNum & 0x80000000 == 0 ;
}

int isPositive2(float number){
	Conversion2 conversion;
	conversion.fNum = &number;
	return (conversion.uiNum & 0x80000000) == 0;
}

int isPositive3(float number){
	unsigned int *ptrValue = (unsigned int *)&number;
	return (*ptrValue & 0x80000000) == 0;
}
