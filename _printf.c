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
/* */
	va_list theArgs;

	/* int (*function)(va_list, char *, unsigned int); */

	va_start(theArgs, format);
/* */
	theBuffer = malloc(sizeof(char) * BUFFERSIZE);
/* */
	if (Input_Validation_Condition(format, index))
	{
		/* */
		return (FAIL);
	}
/* */
	if (!format[index])
	{
		/* */
		return (SUCCESS);
	}
/* */
	length = Format_Specifier_Processing_Loop(
	    format, theBuffer, &theIndexOfTheBuffer,
	    &length, theArgs);
/* */
	Display_The_Buffer(theBuffer, theIndexOfTheBuffer);
	/* */
	free(theBuffer);
	/* */
	va_end(theArgs);

	return (length);
}

