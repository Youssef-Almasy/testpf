#include "function.h"

/**
 * Process_Print_Function - Processes the format specifier and invokes
 * the appropriate printing function.
 * Return: void
 * --------------------------
 * Prototype: void Process_Print_Function(
 * const char *theStringToProcess, char *theBuffer,
 * unsigned int *theIndexOfTheBuffer,
 * unsigned int *length, va_list theArgs, unsigned int index)
 * --------------------------
 * @theStringToProcess: The format string to process.
 * @theBuffer: The buffer to store the formatted string.
 * @theIndexOfTheBuffer: Pointer to the index in the buffer.
 * @length: Pointer to the length of the formatted string.
 * @theArgs: Variable argument list.
 * @index: Current index in the format string.
 * --------------------------
 * By Youssef Hassane
 */

void Process_Print_Function(
	const char *theStringToProcess, char *theBuffer,
	unsigned int *theIndexOfTheBuffer,
	unsigned int *length, va_list theArgs, unsigned int index)
{
	/* Determine the printing function for the format specifier */
	int (*function)(va_list, char *, unsigned int) =
	    Determine_Print_Function(theStringToProcess, index + 1);

	/* Check if the determined function is NULL */
	if (function == NULL)
	{
		/* Check for a space after '%' with no following character */
		if (theStringToProcess[index + 1] == ' ' && !theStringToProcess[index + 2])
		{
			return; /* Ignore the space and return */
		}

		/* Combine the character with the buffer and update length */
		Combines_Buffer(theBuffer, theStringToProcess[index], *theIndexOfTheBuffer);
		(*length)++;
		index--; /* Adjust the index to reprocess the character */
	}
	else
	{
		/* Invoke the determined printing function and update the length */
		(*length) += function(theArgs, theBuffer, *theIndexOfTheBuffer);
	}
}
