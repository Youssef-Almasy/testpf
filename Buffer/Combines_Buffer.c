#include "Buffer.h"
/**
 * Handling_String_Specifier - Appends a character to the buffer and displays
 * the buffer if it reaches its maximum size.
 * Return: Updated number of bytes to print after appending the character.
 * ----------------------
 * prototype: unsigned int Combines_Buffer(
 * char *theBuffer,
 * char character,
 * unsigned int numberOfBytesToPrint)
 * ----------------------
 * @theBuffer: Buffer to store the result.
 * @character: Character to be appended to the buffer.
 * @numberOfBytesToPrint: Current number of bytes to print in the buffer.
 * ----------------------
 * This function appends the specified character to the buffer and checks if
 * the buffer has reached its maximum size (BUFFERSIZE). If the buffer is full,
 * it displays the content of the buffer and resets the count. Otherwise, it
 * simply appends the character to the buffer and increments the count.
 * ----------------------
 * By Youssef Hassane
 */

unsigned int Combines_Buffer(
	char *theBuffer,
	char character,
	unsigned int numberOfBytesToPrint)
{
	/* Check if the buffer is full */
	/* BUFFERSIZE = 1024*/
	if (numberOfBytesToPrint == BUFFERSIZE)
	{
		/* Display the buffer content and reset the count */
		Display_The_Buffer(theBuffer, numberOfBytesToPrint);
		numberOfBytesToPrint = 0;
	}
	/* Append the character to the buffer and increment the count */
	theBuffer[numberOfBytesToPrint] = character;
	numberOfBytesToPrint++;
	/* Return the updated number of bytes to print after appending the character*/
	return (numberOfBytesToPrint);
}
