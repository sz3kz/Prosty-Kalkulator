#include "../../include/operation.h"

void destroy_operation(Operation * operation){
	free(operation);
}
