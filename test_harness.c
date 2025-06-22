/*
  FILE          : test_harness.c
  PROJECT       : SENG1005 – C Programming
  PROGRAMMER    : Shefilkhan Pathan
  FIRST VERSION : 2025-06-21
  DESCRIPTION   : Implements the test harness functions used to run predefined arithmetic test cases, evaluate results, and log test details to the logging system.
  REFERENCE     : https://stackoverflow.com/questions/7795296/comparing-function-pointers-in-c
                  https://stackoverflow.com/a/14452824 
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "logger.h"
#include "math_library.h"
#include "test_harness.h"

 /*
   STRUCT        : TestCase
   DESCRIPTION   : A structure representing a test case, including operands, expected result, operation function, and test name.
  */
typedef struct {
    const char* name;
    int a;
    int b;
    int expected;
    int (*func)(int, int);
} TestCase;

/*
  FUNCTION      : toLowerStr
  DESCRIPTION   : Converts a source string to lowercase and stores it in the destination buffer.
  PARAMETERS    :char* dest       - destination buffer for the lowercase string
                 const char* src  - source string to convert
  RETURNS       : void
 */
void toLowerStr(char* dest, const char* src)
{
    int i;
    for (i = 0; src[i]; ++i)
    {
        dest[i] = tolower((unsigned char)src[i]);
    }
    dest[i] = '\0';
}

// Define an array of test cases
static TestCase tests[] = {
    {"add", 5, 3, 8, add},
    {"subtract", 10, 5, 5, subtract},
    {"multiply", 4, 6, 24, multiply},
    {"divide", 20, 4, 5, divide},
    {"divide-by-zero", 10, 0, 0, divide},  //expect safe handling of division by zero
    {"add-boundary", 2147483647, 0, 2147483647, add} //test int boundary value
};

//Track the number of test cases
static int totalTests = sizeof(tests) / sizeof(tests[0]);

/*
  FUNCTION      : executeTest
  DESCRIPTION   : Runs a single test case, prints the result to the console, and logs detailed info.
  PARAMETERS    : const TestCase* t - pointer to the test case to execute
  RETURNS       : void
 */
void executeTest(const TestCase* t)
{
    int actual = t->func(t->a, t->b);
    int passed = (actual == t->expected);

    // determine the symbol for the operator
    char op = '?';
    if (t->func == add) op = '+';
    else if (t->func == subtract) op = '-';
    else if (t->func == multiply) op = '*';
    else if (t->func == divide) op = '/';

    // Display test result
    printf("%d %c %d = %d → %s\n", t->a, op, t->b, actual, passed ? "PASS" : "FAIL");

    // Log test details
    logMessage("INFO", "Test Name: %s", t->name);
    logMessage("INFO", "Input: (%d, %d)", t->a, t->b);
    logMessage("INFO", "Expected: %d, Actual: %d", t->expected, actual);
    logMessage(passed ? "INFO" : "ERROR", "Result: %s", passed ? "PASS" : "FAIL");
}

/*
  FUNCTION      : runAllTests
  DESCRIPTION   : Executes all defined test cases sequentially.
  PARAMETERS    : None
  RETURNS       : void
 */
void runAllTests(void)
{
    for (int i = 0; i < totalTests; ++i)
    {
        executeTest(&tests[i]);
    }
}

/*
  FUNCTION      : runTestByIndex
  DESCRIPTION   : Executes a specific test case by index.
  PARAMETERS    : int index - index of the test to run
  RETURNS       : void
 */
void runTestByIndex(int index)
{
    if (index < 0 || index >= totalTests)
    {
        printf("Invalid test selection.\n");
        logMessage("WARNING", "Invalid test index: %d", index);
        return;
    }

    executeTest(&tests[index]);
}

/*
  FUNCTION      : getTotalTests
  DESCRIPTION   : Returns the number of test cases defined.
  PARAMETERS    : None
  RETURNS       : int - number of test cases
 */
int getTotalTests(void)
{
    return totalTests;
}

/*
  FUNCTION      : getTestName
  DESCRIPTION   : Returns the name of a test case given its index.
  PARAMETERS    : int index - index of the test
  RETURNS       : const char* - test name or NULL if index is invalid
 */
const char* getTestName(int index)
{
    if (index < 0 || index >= totalTests)
    {
        return NULL;
    }

    return tests[index].name;
}
