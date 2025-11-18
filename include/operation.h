#ifndef OPERATION_H
#define OPERATION_H

#define OPERATION_NAME_SIZE 32

typedef struct Operation{
	char name[OPERATION_NAME_SIZE];
	int (* pointer) (int, int, double*);
} Operation;

#endif
