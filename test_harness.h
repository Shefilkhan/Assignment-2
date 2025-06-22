/*
  FILE          : test_harness.h
  PROJECT       : SENG1070 – C Programming
  PROGRAMMER    : shefilkhan Pathan
  FIRST VERSION : 2025-06-21
  DESCRIPTION   : This header file provides function declarations for the test harness system.
   It supports executing all tests, running specific tests by index, retrieving total number of tests, and obtaining test names.
 */

#ifndef TEST_HARNESS_H
#define TEST_HARNESS_H

 /*
   FUNCTION      : runAllTests
   DESCRIPTION   : Executes all registered test cases sequentially.
   PARAMETERS    : None
   RETURNS       : void
  */
void runAllTests(void);

/*
  FUNCTION      : runTestByIndex
  DESCRIPTION   : Executes a single test case based on its index.
  PARAMETERS    : int index - The zero-based index of the test case to run
  RETURNS       : void
 */
void runTestByIndex(int index);

/*
  FUNCTION      : getTotalTests
  DESCRIPTION   : Returns the total number of registered test cases.
  PARAMETERS    : None
  RETURNS       : int - Number of available test cases
 */
int getTotalTests(void);

/*
  FUNCTION      : getTestName
  DESCRIPTION   : Returns the name/description of the test at the given index.
  PARAMETERS    : int index - The index of the test case
  RETURNS       : const char* - Name of the test case
 */
const char* getTestName(int index);

#endif 
#pragma once
