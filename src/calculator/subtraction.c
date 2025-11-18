#include "../../include/calculator.h"

int subtraction(int number1, int number2, double * difference){

	/* Integer Overflow */
	if (number1 < 0)
		if (INT_MAX + number1 < number2)
			return OPERATION_FAILURE;

	/* Integer Underflow */
	if (number1 > 0)
		if (INT_MIN + number1 > number2)
			return OPERATION_FAILURE;

	*difference = number1 - number2;
	return OPERATION_SUCCESS;
}
