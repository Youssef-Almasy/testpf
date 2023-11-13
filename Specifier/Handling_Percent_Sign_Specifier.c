#include "../main.h"
#include <stdio.h>

/**
 * Handling_Percent_Sign_Specifier - Handles the '%' character specifier
 * Return: Number of characters displayed in the buffer (always 1 for '%')
 * ----------------------
 * prototype: int Handling_Percent_Sign_Specifier(
 * va_list theArgs,
 * char *theBuffer,
 * unsigned int numberOfBytesToPrint)
 * ----------------------
 * @theArgs: Variable argument list (not used for '%' specifier)
 * @theBuffer: Character buffer to store the '%' character
 * @numberOfBytesToPrint: Maximum number of
 * bytes available in the buffer for printing
 * ----------------------
 * By Youssef Hassane
 */

int Handling_Percent_Sign_Specifier(
	va_list theArgs,
	char *theBuffer,
	unsigned int numberOfBytesToPrint)
{
	/* Variable to hold the '%' character */
	char thePercentSign = '%';
	/* Unused argument to maintain function prototype compatibility */
	(void)theArgs;
	/* Append the '%' character to the buffer */
	Combines_Buffer(theBuffer, thePercentSign, numberOfBytesToPrint);
	/* Return the number of characters displayed */
	/* in the buffer (always 1 for '%') */
	return (SUCCESS_1);
}
