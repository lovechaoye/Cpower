#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"singleLinkedList.h"
#include"Employee.h"
int main(int argc,char* argv[]){
	LinkedList linkedList;

	Employee *samuel = (Employee*)malloc(sizeof(Employee));
	strcpy(samuel->name,"Samuel");
	samuel->age = 32;

	
	Employee *sally = (Employee*)malloc(sizeof(Employee));
	strcpy(sally->name,"Susan");
	sally->age = 28;
	

	Employee *susan = (Employee*)malloc(sizeof(Employee));
	strcpy(susan->name,"Susan");
	susan->age = 45;

	initializeList(&linkedList);

	addHead(&linkedList, samuel);
	addHead(&linkedList, sally);
	addHead(&linkedList, susan);
	return 0;
}
