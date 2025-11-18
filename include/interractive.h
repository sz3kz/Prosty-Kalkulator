#ifndef INTERRACTIVE_H
#define INTERRACTIVE_H

#include <stdio.h>

#define ASK_NUMBER_PROMPT "Number: "
#define ASK_OPERATOR_PROMPT "Operator: "
#define ARGC_INTERRACTIVE 2
#define EMPTY_STDIN while( getchar() != '\n' && getchar() != EOF)

enum Arguments_Interractive{
	INTERRACTIVE_SWITCH = 1
};

void help_interractive(char * argv[]);
void ask_for_number(int * number_ptr);
void ask_for_operator(char * operator, size_t size);
void newline2null(char * operator, size_t size);

#endif
