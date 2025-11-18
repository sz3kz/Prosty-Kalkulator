#include "../../include/operation.h"

void print_available_operations(Operation ** available_operations, size_t count){
	printf("Available operations:\n");
	for (int i = 0; i < count; ++i)
		printf("\t%-*s(%c)\n",
				OPERATION_NAME_SIZE,
				available_operations[i]->name,
				available_operations[i]->symbol);
}
