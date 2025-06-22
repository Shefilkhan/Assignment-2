/*
  FILE          : math_library.c
  PROJECT		: SENG1070 – Assignment 2 – Errors and Testing
  PROGRAMMER	: Shefilkhan Pathan
  FIRST VERSION : 2025-06-16
  DESCRIPTION	: This source file provides definitions for arithmetic operations
  including add, subtract, multiply, and divide with error handling.
*/

#include "math_library.h"

/*
 FUNCTION		: subtract
 DESCRIPTION	: Returns the sum of two integers.
 PARAMETERS		: int a - fist operand & int b - second operand
 RETURNS		: int - result of a + b
*/
int add(int a, int b)
{
	return a + b;
}

/*
 FUNCTION		: subtract
 DESCRIPTION	: Returns the result of subtracting the second integer from the first.
 PARAMETERS		: int a - first operand & int b - second operand
 RETURNS		: int - result of a - b
*/
int subtract(int a, int b)
{
	return a - b;
}

/*
 FUNCTION		: multiply 
 DESCRIPTION	: Returns the product of two integers.
 PARAMETERS		: int a - first operand & int b - second operand
 RETURNS		: int - result of a * b
*/
int multiply(int a, int b)
{
	return a * b;
}

/*
 FUNCTION		: divide
 DESCRIPTION	: Returns the result of integer division. If the divisor is 0, returns 0 to avoid a runtime crash due to division by zero.
 PARAMETERS		: int a - numerator & int b - denominator
 RETURNS		: int - result of a / b, or 0 if b is 0
*/
int divide(int a, int b)
{
	if (b == 0) {
		
		return 0;
	}

	return a / b;
}