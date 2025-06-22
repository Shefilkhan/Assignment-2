# Makefile for SENG1070 Assignment 2 - Error Logging and Test Harness

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
LDFLAGS =
OBJ = main.o logger.o test_harness.o math_library.o
TARGET = test_program

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

main.o: main.c logger.h test_harness.h math_library.h
	$(CC) $(CFLAGS) -c main.c

logger.o: logger.c logger.h
	$(CC) $(CFLAGS) -c logger.c

test_harness.o: test_harness.c test_harness.h logger.h math_library.h
	$(CC) $(CFLAGS) -c test_harness.c

math_library.o: math_library.c math_library.h logger.h
	$(CC) $(CFLAGS) -c math_library.c

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o *.log
