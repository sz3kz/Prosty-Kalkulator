#ifndef INTERRACTIVE_H
#define INTERRACTIVE_H

#include <stdio.h>

#define HELP_INTERRACTIVE "Usage: %s -i\n", argv[PROGRAM_NAME]

#define INTERRACTIVE_MODE_ARGUMENT_COUNT 2

enum Interractive_Mode_Arguments{
	PROGRAM_NAME,
	INTERRACTIVE_SWITCH
};

void print_help(char * argv[]);

#endif
