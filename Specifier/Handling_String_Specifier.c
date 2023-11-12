#include "../main.h"

/**
 * Handling_String_Specifier - Handles string specifiers.
 * Return: On success, returns the number of characters processed.
 * ----------------------
 * prototype: int Handling_String_Specifier(
 * va_list theArgs, char *theBuffer,
 * unsigned int numberOfBytesToPrint)
 * ----------------------
 * @theArgs: Variable argument list.
 * @theBuffer: Buffer to store the result.
 * @numberOfBytesToPrint: Number of bytes to print.
 * ----------------------
 * This function extracts a character from the
 * variable argument list, updates the buffer,
 * and increments the index accordingly.
 * ----------------------
 * By Youssef Hassane
 */

int Handling_String_Specifier(
	va_list theArgs,
	char *theBuffer,
	unsigned int numberOfBytesToPrint)
{
	/* Declare variables and initialize */
	char *theString;
	unsigned int index;
	char anArrayOfNull[] = "(null)";
	int lengthOfAnArrayOfNull = 6;

	/* Extract string argument from variable arguments */
	theString = va_arg(theArgs, char *);

	/* Check if the string is NULL */
	if (theString == ((void *)0))
	{
		/* If NULL, concatenate "(null)" to the result buffer */
		for (index = 0; anArrayOfNull[index]; index++)
		{
			numberOfBytesToPrint = Combines_Buffer(
				theBuffer,
				anArrayOfNull[index],
				numberOfBytesToPrint);
		}
		/* Return the length of the array anArrayOfNull */
		return (lengthOfAnArrayOfNull);
	}
	/* If the string is not NULL, */
	/* concatenate each character to the result buffer */
	for (index = 0; theString[index]; index++)
	{
		numberOfBytesToPrint = Combines_Buffer(
			theBuffer,
			theString[index],
			numberOfBytesToPrint);
	}
	/* Return the number of characters processed */
	return (index);
}
