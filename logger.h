/*
  FILE          : logger.h
  PROJECT       : SENG1070 - Assignment 2
  PROGRAMMER    : Shefilkhan Pathan
  FIRST VERSION : 2025-06-20
  DESCRIPTION   : This header file declares the logging interface used to manage logging operations within the application. 
   It allows initialization of a log file,formatted logging of messages with levels, and proper cleanup on shutdown.
 */

#ifndef LOGGER_H
#define LOGGER_H

 /*
   FUNCTION      : initLogger
   DESCRIPTION   : Initializes the logging system by opening the specified log file. This should be called once at the beginning of the program.
   PARAMETERS    : const char* filename - Name of the file to write log messages to
   RETURNS       : void - No return value
  */
void initLogger(const char* filename);

/*
  FUNCTION      : logMessage
  DESCRIPTION   : Logs a formatted message to the log file with a specified severity level.Supports variable arguments similar to printf.
  PARAMETERS    : const char* level  - Logging level string (e.g., "INFO", "ERROR")
                  const char* format - printf-style format string
                  ...                - Additional arguments to format
  RETURNS       : void - No return value
 */
void logMessage(const char* level, const char* format, ...);

/*
  FUNCTION      : closeLogger
  DESCRIPTION   : Closes the log file and performs necessary cleanup operations.
  RETURNS       : void - No return value
 */
void closeLogger(void);

#endif // LOGGER_H
#pragma once
