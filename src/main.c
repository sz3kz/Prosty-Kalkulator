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
	char operator[OPERATION_NAME_SIZE];
	int number1, number2;
	if (is_interractive){
		ask_for_number(&number1);
		EMPTY_STDIN;
		ask_for_operator(operator, OPERATION_NAME_SIZE);
		//EMPTY_STDIN;
		ask_for_number(&number2);
	}
	printf("operation: \"%s\"\n", operator);

	int (* operations[OPERATION_COUNT]) (int, int, double *) = {
		addition,
		subtraction,
		multiplication,
		division};
	int code;
	double result;
	for (int i = 0; i < OPERATION_COUNT; ++i){
		int (* operation) (int,int,double*) = operations[i];
		code = operation(number1, number2, &result);
		if (code == OPERATION_FAILURE){
			printf("Operation failed!\n");
			continue;
		}
		printf("%d %d = %lf\n",
			number1, number2, result);
	}
	return 0;
}
