#include<stdio.h>
void add(int size , double* restrict arr1 , const double* restrict arr2);
int main(void){
	double vector1[] ={1.1,2.2,3.3,4.4};
//	double vector2[] ={1.1,2.2,3.3,4.4};
	double* vector2 = vector1;
	add(4,vector1,vector2);
	return 0;
}
void add(int size , double*  restrict arr1 , const double* restrict arr2){
	int i = 0;
	for(;i < size; i++){
		arr1[i] += arr2[i];
	}
}
