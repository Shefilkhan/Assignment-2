/*
  FILE          : logger.c
  PROJECT       : SENG1070 - C Programming
  PROGRAMMER    : Shefilkhan Pathan
  FIRST VERSION : 2025-06-20
  DESCRIPTION   : This file contains the implementation of a simple logging system.
    It allows for initialization, timestamped message logging with levels, and safe closure of the log file.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include "logger.h"

 //Static file pointer to manage logging file state internally
static FILE* logFile = NULL;

/*
  FUNCTION      : initLogger
  DESCRIPTION   : Initializes the logging system by opening the specified log file in append mode.
  PARAMETERS    : const char* filename - Name of the file where logs will be written
  RETURNS       : void
 */
void initLogger(const char* filename)
{
    logFile = fopen(filename, "a");

    if (logFile == NULL)
    {
        fprintf(stderr, "ERROR: Could not open log file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
}

/*
  FUNCTION      : logMessage
  DESCRIPTION   : Logs a formatted message with the current timestamp and log level (e.g., INFO, ERROR).
  PARAMETERS    : const char* level  - String representing the log level
                  const char* format - Format string (like printf)
                  ...                - Variable arguments corresponding to the format string
  RETURNS       : void
  REFERENCE     : https://en.cppreference.com/w/c/io/vfprintf 
                : https://en.cppreference.com/w/c/chrono/strftime 
 */
void logMessage(const char* level, const char* format, ...)
{
    if (logFile == NULL)
    {
        fprintf(stderr, "ERROR: Logger not initialized.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm* timeInfo = localtime(&now);

    // Buffer to store formatted time
    char timeStr[20];
    strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", timeInfo);

    // Write timestamp and level to the log file
    fprintf(logFile, "[%s] [%s] ", timeStr, level);

    // Write the formatted message
    va_list args;
    va_start(args, format);
    vfprintf(logFile, format, args);
    va_end(args);

    fprintf(logFile, "\n");

    fflush(logFile); // Ensure data is written immediately
}

/*
  FUNCTION      : closeLogger
  DESCRIPTION   : Closes the log file safely if it is open.
  PARAMETERS    : None
  RETURNS       : void
 */
void closeLogger(void)
{
    if (logFile != NULL)
    {
        fclose(logFile);
        logFile = NULL;
    }
}
