#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <stdio.h>

#define ARGC_COMMANDLINE 4

void help_commandline(char * argv[]);

enum Arguments_Commandline{
	FIRST_NUMBER = 1,
	OPERATOR = 2,
	SECOND_NUMBER = 3
};

#endif
