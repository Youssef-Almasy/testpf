#include "main.h"
#include "variables.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	unsigned int index = 0;
	unsigned int length = 0;
	/* theIndexOfTheBuffer is used as an index to keep track of */
	/* the current position in the buffer (theBuff) where */
	/* characters are being stored for eventual printing. */
	unsigned int theIndexOfTheBuffer = 0;
	/* theBuff is a dynamically allocated buffer that is used to store the */
	/* characters that are being formatted and will be printed eventually. */
	char *theBuffer;

	va_list theArgs;

	int (*function)(va_list, char *, unsigned int);

	va_start(theArgs, format);

	theBuffer = malloc(sizeof(char) * BUFFERSIZE);

	if (inputValidationCondition(format, index))
	{
		return (FAIL);
	}

	if (!format[index])
	{
		return (SUCCESS);
	}

	length = Format_Specifier_Processing_Loop(format, theBuffer, &theIndexOfTheBuffer, &length, theArgs);

	print_buf(theBuffer, theIndexOfTheBuffer), free(theBuffer), va_end(theArgs);
	return (length);
}
