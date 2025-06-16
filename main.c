/*
  FILE          : main.c
  PROJECT       : SENG1005 – Assignment 2 – Errors and Testing
  PROGRAMMER    : Shefilkhan Pathan
  FIRST VERSION : 2025-06-15
  DESCRIPTION   : This file contains the main menu interface that allows the user to select and run different math operations
  (add, subtract, multiply, divide) and testing. All actions are logged to a file using the custom logger module.
*/
#include<stdio.h>

int main(void)
{
	int Choice; 

	do {
		printf("\nMain Menu\n");
		printf("1. Run individual test cases\n");
		printf("2. Run all tests in the harness\n");
		printf("3. View log files\n");
		printf("4. Exit\n");
		printf("Please Enter you choice:");
		scanf_s("%d", &Choice);

		switch (Choice) {
		case 1:
			printf("Run individual test cases (function not implemented yet)\n");
			break;

		case 2:
			printf("Run all tests in the harness (function not implemented yet)\n");
			break;

		case 3:
			printf("View log files (function not implemented yet)\n");
			break;

		case 4:
			printf("Exit\n");
			break;

		default:
			printf("Invalid Choice\n");

		}
	} while (Choice != 4);

	return 0;
}