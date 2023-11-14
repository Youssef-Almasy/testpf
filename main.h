#ifndef MAIN_H
#define MAIN_H

#define FAIL -1
#define SUCCESS 0
#define SUCCESS_1 1
#define BUFFERSIZE 1024
#define theNull ((void *)0)

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format, ...);

int Format_Specifier_Processing_Loop(
	const char *format, char *theBuffer,
	unsigned int *theIndexOfTheBuffer,
	unsigned int *length, va_list theArgs);

void Process_Print_Function(
	const char *format, char *theBuffer,
	unsigned int *theIndexOfTheBuffer,
	unsigned int *length, va_list theArgs, unsigned int index);

int Display_The_Buffer(char *theBuffer, unsigned int numberOfBytesToPrint);
int Handling_Character_Specifier(
	va_list theArgs,
	char *theBuffer,
	unsigned int theIndexOfTheBuffer);

int Input_Validation_Condition(const char *theInputString, unsigned int index);

/**
 * struct print - struct for printer functions
 * @argument_type: identifier
 * @function_pointer: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
	const char *argument_type;
	int (*function_pointer)(va_list, char *, unsigned int);
} print_t;

unsigned int Combines_Buffer(
	char *theBuffer,
	char character,
	unsigned int numberOfBytesToPrint);
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int);
int ev_print_func(const char *s, int index);

int Handling_Hex_Specifier_Lower(
	va_list theArgs,
	char *theBuffer,
	unsigned int numberOfBytesToPrint);

int Handling_String_Specifier(
	va_list theArgs,
	char *theBuffer,
	unsigned int numberOfBytesToPrint);

int Handling_Integer_Specifier(
	va_list theArgs,
	char *theBuffer,
	unsigned int numberOfBytesToPrint);

int Handle_Integer_Sign(
	int theInputOfInteger,
	char *theBuffer,
	unsigned int *numberOfBytesToPrint);

void Append_Digits_To_Buffer(
	unsigned int value,
	unsigned int *numberOfBytesToPrint,
	char *theBuffer,
	unsigned int *index);

int Handling_Percent_Sign_Specifier(va_list a, char *buffer, unsigned int i);

int Find_Matching_Function_Index(
	const char *identifier, int position,
	int *index_1, int *index_2,
	const print_t *functions);

#endif
