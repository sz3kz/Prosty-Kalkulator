#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <limits.h>

#define OPERATION_SUCCESS 0
#define OPERATION_FAILURE -1
#define OPERATION_COUNT 4

int addition(int number1, int number2, int * sum);
int subtraction(int number1, int number2, int * difference);
int multiplication(int number1, int number2, int * product);
int division(int number1, int number2, int * quotient);

#endif
