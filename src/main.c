#include "../include/main.h"
#include "../include/interractive.h"
#include "../include/calculator.h"
#include "../include/operation.h"

int main(int argc, char * argv[]){
	bool is_interractive = false;
	if (argc != INTERRACTIVE_MODE_ARGUMENT_COUNT){
		puts("Invalid program invocation!");
		print_help(argv);
		return -1;
	}
	if (argc == INTERRACTIVE_MODE_ARGUMENT_COUNT ){
		if (strcmp(argv[INTERRACTIVE_SWITCH], "-i") != 0){
			puts("Invalid switch!");
			print_help(argv);
			return -1;
		}
		is_interractive = true;
	}

	Operation * available_operations[OPERATION_COUNT];
	available_operations[0] = create_operation("addition", addition);
	available_operations[1] = create_operation("subtraction", subtraction);
	available_operations[2] = create_operation("multiplication", multiplication);
	available_operations[3] = create_operation("division", division);
	char operator[OPERATION_NAME_SIZE];
	int number1, number2;
	if (is_interractive){
		ask_for_number(&number1);
		EMPTY_STDIN;
		ask_for_operator(operator, OPERATION_NAME_SIZE);
		//EMPTY_STDIN;
		ask_for_number(&number2);
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
	return 0;
}
