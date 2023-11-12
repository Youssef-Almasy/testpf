#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

ssize_t _putchar(char *theBuffer, size_t numberOfBytesToPrint);

void Process_Print_Function(
	const char *format, char *theBuffer,
	unsigned int *theIndexOfTheBuffer,
	unsigned int *length, va_list theArgs, unsigned int index);

int ev_print_func(const char *s, int index);

int Format_Specifier_Processing_Loop(
	const char *format, char *theBuffer,
	unsigned int *theIndexOfTheBuffer,
	unsigned int *length, va_list theArgs);

int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int);

int input_Validation_Condition(const char *theInputString, unsigned int index);

#endif
