/*
  FILE          : main.c
  PROJECT       : SENG1070 – Assignment 2 – Errors and Testing
  PROGRAMMER    : Shefilkhan Pathan
  FIRST VERSION : 2025-06-15
  DESCRIPTION   : This file contains the main menu interface that allows the user to select and run different math operations
  (add, subtract, multiply, divide) and testing. All actions are logged to a file using the custom logger module.

  CITATION:
    TITLE       : Input validation using scanf_s and clearing stdin
    AUTHOR      : Microsoft Developer Network (MSDN)
    DATE        : 2024-06-01
    AVAILABILITY: https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logger.h"
#include "test_harness.h"

#define MAX_NAME_LEN 50

/*
  FUNCTION      : viewLogFile
  DESCRIPTION   : Opens and displays the contents of the specified log file.
  PARAMETERS    : const char* filename - Name of the file to open and read
  RETURNS       : void

  CITATION:
    TITLE       : Read a file character by character in C
    AUTHOR      : C Library Reference + TutorialsPoint
    DATE        : 2024-06-01
    AVAILABILITY: https://www.geeksforgeeks.org/c-program-read-contents-file/
 */
void viewLogFile(const char* filename)
{
    FILE* fp = fopen(filename, "r");

    if (!fp)
    {
        printf("Could not open log file: %s\n", filename);
        return;
    }

    printf("\n--- %s ---\n", filename);

    char c;
    while ((c = fgetc(fp)) != EOF)
    {
        putchar(c);
    }

    fclose(fp);
}

/*
  FUNCTION      : main
  DESCRIPTION   : Entry point of the program. Handles user interaction, test execution, and logging activities.
  PARAMETERS    : None
  RETURNS       : int - Exit code (0 if successful)
 */
int main(void)
{
    int choice;
    int testIndex;

    // Initialize the main log to track program startup
    initLogger("program.log");
    logMessage("INFO", "Program started");
    closeLogger();

    // Initialize test-specific log for capturing test results
    initLogger("test.log");

    while (1)
    {
        // Print main menu directly inside main
        printf("\n==== MAIN MENU ====\n");
        printf("1. Run all tests\n");
        printf("2. Run test by number\n");
        printf("3. View logs\n");
        printf("4. Exit\n");
        printf("Choose: ");

        // Validate user input using scanf_s and clear buffer if invalid
        if (scanf_s("%d", &choice) != 1)
        {
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice)
        {
        case 1:
            logMessage("INFO", "Running all tests");
            runAllTests();
            break;

        case 2:
        {
            int total = getTotalTests();
            printf("Select a test to run:\n");

            for (int i = 0; i < total; ++i)
            {
                printf("  %d. %s\n", i + 1, getTestName(i));
            }

            printf("Enter test number: ");
            if (scanf_s("%d", &testIndex) != 1 || testIndex < 1 || testIndex > total)
            {
                printf("Invalid selection.\n");
                while (getchar() != '\n');
                break;
            }

            logMessage("INFO", "Running test %d: %s", testIndex, getTestName(testIndex - 1));
            runTestByIndex(testIndex - 1);
            break;
        }

        case 3:
            viewLogFile("program.log");
            viewLogFile("test.log");
            break;

        case 4:
            logMessage("INFO", "Program exited");
            closeLogger();
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
