#include "../include/main.h"
#include "../include/interractive.h"
#include "../include/calculator.h"
#include "../include/operation.h"
#include "../include/commandline.h"

int main(int argc, char * argv[]){

	/* Register available mathematical operations */
	Operation * operations[OPERATION_COUNT];
	operations[0] = create_operation("addition", '+', addition);
	operations[1] = create_operation("subtraction", '-', subtraction);
	operations[2] = create_operation("multiplication", '*', multiplication);
	operations[3] = create_operation("division", '/',division);

	/* Detect value input mode */
	enum Mode mode = NONE;
	switch (argc){

		/* Interractive: ./PROG -i */
		case ARGC_INTERRACTIVE:
			if (strcmp(argv[INTERRACTIVE_SWITCH], "-i") == 0){
				mode = INTERRACTIVE;
				break;
			}
			puts("Invalid program invocation format.");
			help_interractive(argv);
			help_commandline(argv);
			print_available_operations(operations, OPERATION_COUNT);
			return -1;

		/* Commandline: ./PROG <operation> <first_number> <second_number> */
		case ARGC_COMMANDLINE:
			mode = COMMANDLINE;
			break;

		default:
			puts("Invalid program invocation format.");
			help_interractive(argv);
			help_commandline(argv);
			print_available_operations(operations, OPERATION_COUNT);
			return -1;
	}

	char inputted_operation[OPERATION_NAME_SIZE];
	int first_operand, second_operand;

	/* Get values based on input mode */
	switch (mode){

		case INTERRACTIVE:
			ask_for_operator(inputted_operation, OPERATION_NAME_SIZE);
			//EMPTY_STDIN;
			ask_for_number(&first_operand);
			//EMPTY_STDIN;
			ask_for_number(&second_operand);
			break;

		case COMMANDLINE:
			sscanf(argv[OPERATOR], "%s", inputted_operation);
			sscanf(argv[FIRST_NUMBER], "%d", &first_operand);
			sscanf(argv[SECOND_NUMBER], "%d", &second_operand);
			break;

		default:
			printf("Invalid mode value: %d\n", mode);
			return -1;
	}

	bool attempted_computation = false;
	int error_code;
	int computation_result;
	char * operation_name;
	char operation_symbol;
	int (* operation_address) (int,int,int*);

	/* Iterate through operations and execute the one inputted */
	for (int i = 0; i < OPERATION_COUNT; ++i){

		operation_name = operations[i]->name;
		operation_symbol = operations[i]->symbol;
		operation_address = operations[i]->pointer;

		/* Check if current operation is one of interest */
		if(strncmp(inputted_operation, operation_name, OPERATION_NAME_SIZE) != 0)
			continue;
		attempted_computation = true;

		/* Execute it */
		error_code = operation_address(first_operand, second_operand, &computation_result);

		/* Check if computation succeeded */
		if (error_code == OPERATION_FAILURE){
			printf("Operation failure: %d %c %d => ERROR\n",
					first_operand, operation_symbol, second_operand);
			return -1;
		}

		/* Output calculation in a human-friendly format */
		printf("%d %c %d = %d\n",
			first_operand, operation_symbol, second_operand, computation_result);
	}

	/* Output error message if inputted operation did not match any registered */
	if (! attempted_computation)
		printf("Unknown operation: \"%s\"\n", inputted_operation);

	/* Deregister mathematical operations */
	for (int i = 0; i < OPERATION_COUNT; ++i)
		destroy_operation(operations[i]);
	return 0;
}
