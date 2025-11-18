#include "../../include/operation.h"

Operation * create_operation(char const * name, char symbol,int (* pointer) (int,int,double*)){
	Operation * operation = malloc(sizeof(Operation));
	strncpy(operation->name, name, OPERATION_NAME_SIZE);
	operation->symbol = symbol;
	operation->pointer = pointer;
	return operation;
}
