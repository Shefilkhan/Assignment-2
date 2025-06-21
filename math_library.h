/*
  FILE          : math_library.h
  PROJECT       : SENG1070 – Assignment 2 – Errors and Testing
  PROGRAMMER    : Shefilkhan Pathan
  FIRST VERSION : 2025-06-16
  DESCRIPTION   : This header file contains the function declarations for basic
                  arithmetic operations: add, subtract, multiply, and divide.
*/

#ifndef MATH_LIBRARY_H
#define MATH_LIBRARY_H

/*
 Function: add
 Purpose: Adds two integers a and b
 Parameter: int a & int b
 Return Type: int
*/

int add(int a, int b);

/*
 Function: subtract
 Purpose: subtracts b from a
 Parameter: int a & int b
 Return Type: int
*/

int subtract(int a, int b);

/*
 Function: multiply
 Purpose: multiplies two integers a and b
 Parameter: int a & int b
 Return Type: int
*/

int multiply(int a, int b);

/*
 Function: divide
 Purpose: divides a by b, logging an error if b is zero
 Parameter: int a & int b
 Return Type: int
*/

int divide(int a, int b);

#endif
