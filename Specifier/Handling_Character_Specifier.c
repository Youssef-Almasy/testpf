#include "../main.h"

/**
 * Handling_Character_Specifier - Handles the character
 * specifier in the printf-like function.
 * Return: 1 to indicate that the character
 * specifier has been successfully handled
 * ----------------------
 * prototype: int Handling_Character_Specifier(
 * va_list theArgs,
 * char *theBuffer,
 * unsigned int theIndexOfTheBuffer)
 * ----------------------
 * @theArgs: the arguments passed to the printf-like function.
 * @theBuffer: The buffer to which the character specifier result will be added
 * @theIndexOfTheBuffer: The current index in the buffer where
 * the character specifier result should be placed.
 * ----------------------
 * This function extracts a character from the
 * variable argument list, updates the buffer,
 * and increments the index accordingly.
 * ----------------------
 * By Youssef Hassane
 */

int Handling_Character_Specifier(
	va_list theArgs,
	char *theBuffer,
	unsigned int theIndexOfTheBuffer)
{
	char theCharacterToBePrinted = va_arg(theArgs, int);
	/* Check if theArgs is pointing to an integer (character) */
	if (theCharacterToBePrinted == 0)
	{
		/* Handle the error condition */
		return (-1);
	}
	/* Update the buffer */
	Combines_Buffer(theBuffer, theCharacterToBePrinted, theIndexOfTheBuffer);

	return (1);
}
