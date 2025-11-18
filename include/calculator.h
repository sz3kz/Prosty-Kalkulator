#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <limits.h>

#define OPERATION_SUCCESS 0
#define OPERATION_FAILURE -1
#define OPERATION_COUNT 2


int addition(int number1, int number2, double * sum);
int subtraction(int number1, int number2, double * difference);

#endif
