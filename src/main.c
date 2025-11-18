#include "../include/main.h"
#include "../include/interractive.h"
#include "../include/calculator.h"

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
	char operator;
	int number1, number2;
	if (is_interractive){
		ask_for_number(&number1);
		EMPTY_STDIN;
		ask_for_operator(&operator);
		EMPTY_STDIN;
		ask_for_number(&number2);
	}
	int result;
	double sum;
	result = addition(number1, number2, &sum);
	if (result == OPERATION_SUCCESS)
		printf("(%d) %d + %d = %lf\n",
			result, number1, number2, sum);
	else
		puts("Addition failed!");
	return 0;
}
