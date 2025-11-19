#include "../../include/operation.h"

Operation * create_operation(char const * name, char symbol,int (* address) (int,int,int*)){
	Operation * operation = malloc(sizeof(Operation));
	strncpy(operation->name, name, OPERATION_NAME_SIZE);
	operation->symbol = symbol;
	operation->address = address;
	return operation;
}
