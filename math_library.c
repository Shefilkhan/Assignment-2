/*
  FILE          : math_library.c
  PROJECT		: SENG1005 – Assignment 2 – Errors and Testing
  PROGRAMMER	: Shefilkhan Pathan
  FIRST VERSION : 2025-06-16
  DESCRIPTION	: This source file provides definitions for arithmetic operations
  including add, subtract, multiply, and divide with error handling.
*/

#include "math_library.h"

int add(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

int divide(int a, int b, int* error)
{
	if (b == 0) {
		*error = 1;
		return 0;
	}

	error = 0;
	return a / b;
}