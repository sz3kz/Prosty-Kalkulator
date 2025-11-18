#include "../../include/calculator.h"

int division(int number1, int number2, double * quotient){
	if (number2 == 0)
		return OPERATION_FAILURE;

	*quotient = number1 / number2;
	return OPERATION_SUCCESS;
}
