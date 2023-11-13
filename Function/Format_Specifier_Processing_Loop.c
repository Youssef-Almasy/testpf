#include "../main.h"
#include "Process_Print_Function.c"

/**
 * Format_Specifier_Processing_Loop - Processes the format string,
 * identifying and handling format specifiers.
 * Return: The length of the formatted string.
 * ----------------------
 * Prototype: int Format_Specifier_Processing_Loop(
 * const char *format, char *theBuffer,
 * unsigned int *theIndexOfTheBuffer,
 * unsigned int *length, va_list theArgs)
 * ----------------------
 * @theStringToProcess: The format string to process.
 * @theBuffer: The buffer to store the formatted string.
 * @theIndexOfTheBuffer: Pointer to the index in the buffer.
 * @length: Pointer to the length of the formatted string.
 * @theArgs: Variable argument list.
 * ----------------------
 * This function iterates through the format string and processes
 * each character, identifying format specifiers and invoking
 * the appropriate processing function.
 * ----------------------
 * By Youssef Hassane
 */

int Format_Specifier_Processing_Loop(
	const char *theStringToProcess, char *theBuffer,
	unsigned int *theIndexOfTheBuffer,
	unsigned int *length, va_list theArgs)
{
	/* Index variable for iterating through the format string */
	unsigned int index = 0;
	/* Loop through the format string */
	for (; theStringToProcess && theStringToProcess[index]; index++)
	{	/* Check for the presence of a format specifier */
		if (theStringToProcess[index] == '%')
		{	/* Check if '%' is the last character in the format string */
			if (theStringToProcess[index + 1] == '\0')
			{	/* Display the buffer, free memory, and return failure */
				Display_The_Buffer(theBuffer, *theIndexOfTheBuffer);
				free(theBuffer);
				va_end(theArgs);
				exit(FAIL);
			}
			else
			{	/* Process the format specifier */
				Process_Print_Function(
				    theStringToProcess, theBuffer, theIndexOfTheBuffer,
				    length, theArgs, index);
			}
			/* Move to the next character after processing the format specifier */
			index++;
		}
		else
		{	/* Combine the character with the buffer and update length */
			Combines_Buffer(
			    theBuffer, theStringToProcess[index],
			    *theIndexOfTheBuffer),
			    (*length)++;
		}
		/* Adjust the index of the buffer if it exceeds the buffer size */
		*theIndexOfTheBuffer = *length;
		while (*theIndexOfTheBuffer > BUFFERSIZE)
		{
			*theIndexOfTheBuffer -= BUFFERSIZE;
		}
	}
	/* Return the length of the formatted string */
	return (*length);
}
