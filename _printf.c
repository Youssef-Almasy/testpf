#include "main.h"
#include "Function/function.h"
#include "Function/Determine_Print_Function.c"
#include "Function/Input_Validation_Condition.c"
#include "Function/Format_Specifier_Processing_Loop.c"
#include "Function/Find_Matching_Function_Index.c"
#include "Buffer/Display_The_Buffer.c"
#include "Buffer/Combines_Buffer.c"
#include "Buffer/Write_Buffer_To_Stdout.c"
#include "Specifier/Handling_Character_Specifier.c"
#include "Specifier/Handling_String_Specifier.c"
#include "Specifier/Handling_Integer_Specifier.c"
#include "Specifier/Handling_Percent_Sign_Specifier.c"

/**
 * _printf - Custom implementation of the printf function.
 * Formats and prints data according to the provided format string.
 * Return: The number of characters printed (excluding null terminator).
 * ----------------------
 * Prototype:
 * int _printf(const char *format, ...);
 * ----------------------
 * @format: The format string containing format specifiers.
 * ----------------------
 * By Youssef Hassane
 */
int _printf(const char *format, ...)
{
	/* Index for iterating through the format string */
	unsigned int index = 0;
	/* Length of the formatted string */
	unsigned int length = 0;
	/* Index in the buffer where characters are stored for printing */
	unsigned int theIndexOfTheBuffer = 0;
	/* Dynamically allocated buffer to store formatted characters */
	char *theBuffer;
	/* Variable argument list */
	va_list theArgs;
	/* Start the variable argument processing */
	va_start(theArgs, format);
	/* Allocate memory for the buffer */
	theBuffer = malloc(sizeof(char) * BUFFERSIZE);
	/* Validate the input format */
	if (Input_Validation_Condition(format, index))
	{
		/* Return failure if input validation fails */
		return (FAIL);
	}
	/* Check for an empty format string */
	if (!format[index])
	{
		/* Return success if the format string is empty */
		return (SUCCESS);
	}
	/* Process the format string and store the result in the buffer */
	length = Format_Specifier_Processing_Loop(
	    format, theBuffer, &theIndexOfTheBuffer,
	    &length, theArgs);
	/* Display the content of the buffer */
	Display_The_Buffer(theBuffer, theIndexOfTheBuffer);
	/* Free the allocated memory for the buffer */
	free(theBuffer);
	/* End variable argument processing */
	va_end(theArgs);
	/* Return the number of characters printed */
	return (length);
}
