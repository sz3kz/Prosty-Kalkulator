#include "../../include/interractive.h"

void newline2null(char * operator, size_t size){
	int i;
	for (i = 0; i < size && operator[i] != '\n' && operator[i] != '\0'; ++i);
	if(operator[i] == '\n')
		operator[i] = '\0';
}
