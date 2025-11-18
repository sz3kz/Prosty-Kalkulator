#ifndef OPERATION_H
#define OPERATION_H

#include <string.h>
#include <stdlib.h>

#define OPERATION_NAME_SIZE 32

typedef struct Operation{
	char name[OPERATION_NAME_SIZE];
	char symbol;
	int (* pointer) (int, int, double*);
} Operation;


Operation * create_operation(char const * name, char symbol,int (* pointer) (int,int,double*));
void destroy_operation(Operation * operation);
#endif
