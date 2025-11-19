#include "../../include/calculator.h"

int addition(int number1, int number2, int * sum){

	/* Integer Overflow */
	if (number1 > 0)
		if (INT_MAX - number1 < number2)
			return CALCULATION_FAILURE;

	/* Integer Underflow */
	if (number1 < 0)
		if (INT_MIN - number1 > number2)
			return CALCULATION_FAILURE;

	*sum = number1 + number2;
	return CALCULATION_SUCCESS;
}
