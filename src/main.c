#include "../include/main.h"
#include "../include/interractive.h"
#include "../include/calculator.h"
#include "../include/operation.h"
#include "../include/commandline.h"

int main(int argc, char * argv[]){
	enum Mode mode = NONE;
	switch (argc){
		case ARGC_INTERRACTIVE:
			if (strcmp(argv[INTERRACTIVE_SWITCH], "-i") == 0){
				mode = INTERRACTIVE;
				break;
			}
			puts("Invalid switch!");
			print_help(argv);
			return -1;
		case ARGC_COMMANDLINE:
			mode = COMMANDLINE;
			break;
		default:
			puts("Invalid program invocation!");
			print_help(argv);
			return -1;
	}
	printf("mode = %d\n",mode);

	Operation * available_operations[OPERATION_COUNT];
	available_operations[0] = create_operation("addition", addition);
	available_operations[1] = create_operation("subtraction", subtraction);
	available_operations[2] = create_operation("multiplication", multiplication);
	available_operations[3] = create_operation("division", division);
	char operator[OPERATION_NAME_SIZE];
	int number1, number2;
	if (mode == INTERRACTIVE){
		ask_for_number(&number1);
		EMPTY_STDIN;
		ask_for_operator(operator, OPERATION_NAME_SIZE);
		//EMPTY_STDIN;
		ask_for_number(&number2);
	}
	else if (mode == COMMANDLINE){
		sscanf(argv[1], "%d", &number1);
		sscanf(argv[2], "%s", operator);
		sscanf(argv[3], "%d", &number2);
	}
	else {
		printf("Code Error: invalid mode value (%d)\n", mode);
		return -1;
	}
	printf("operator = \"%s\"\n",operator);
	int code;
	double result;
	for (int i = 0; i < OPERATION_COUNT; ++i){
		char * name = available_operations[i]->name;
		if(strncmp(operator, name, OPERATION_NAME_SIZE) != 0)
			continue;

		int (* pointer) (int,int,double*) = available_operations[i]->pointer;
		code = pointer(number1, number2, &result);
		if (code == OPERATION_FAILURE){
			printf("Operation failed!\n");
			continue;
		}
		printf("%d %d = %lf\n",
			number1, number2, result);
	}

	for (int i = 0; i < OPERATION_COUNT; ++i)
		destroy_operation(available_operations[i]);
	return 0;
}
