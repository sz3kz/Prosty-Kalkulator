#include "../../include/calculator.h"

int division(int number1, int number2, int * quotient){
	if (number2 == 0)
		return CALCULATION_FAILURE;

	*quotient = number1 / number2;
	return CALCULATION_SUCCESS;
}
