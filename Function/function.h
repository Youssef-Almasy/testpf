#ifndef FUNCTION_H
#define FUNCTION_H

#include "../main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void Process_Print_Function(
	const char *format, char *theBuffer,
	unsigned int *theIndexOfTheBuffer,
	unsigned int *length, va_list theArgs, unsigned int index);

int Format_Specifier_Processing_Loop(
	const char *theStringToProcess, char *theBuffer,
	unsigned int *theIndexOfTheBuffer,
	unsigned int *length, va_list theArgs);

int (*Determine_Print_Function(
	const char *identifier,
	int position))(va_list, char *, unsigned int);

int Input_Validation_Condition(const char *theInputString, unsigned int index);

int Find_Matching_Function_Index(
	const char *identifier, int position,
	int *index_1, int *index_2,
	const print_t *functions);


#endif
