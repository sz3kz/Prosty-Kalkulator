#include "../../include/interractive.h"

void ask_for_operator(char * operator, size_t size){
	printf(ASK_OPERATOR_PROMPT);
	fgets(operator, size, stdin);
}
