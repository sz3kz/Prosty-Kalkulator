#include "../../include/calculator.h"

int multiplication(int number1, int number2, int * product){
	int temp_product = number1 * number2;
	/* An honest attempt at catching an overflow / underflow */
	if (number1 != 0 && temp_product/ number1 != number2)
		return CALCULATION_FAILURE;
	*product = temp_product;
	return CALCULATION_SUCCESS;
}
