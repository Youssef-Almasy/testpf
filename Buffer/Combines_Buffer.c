#include "../main.h"

/**
 * Combines_Buffer - combines characters in the buffer
 * @theBuffer: pointer to buffer
 * @character: character to combine
 * @numberOfBytesToPrint: index of the buffer pointer
 * Return: updated index of buffer pointer.
 */
unsigned int Combines_Buffer(
	char *theBuffer,
	char character,
	unsigned int numberOfBytesToPrint)
{
	if (numberOfBytesToPrint == BUFFERSIZE)
	{
		Display_The_Buffer(theBuffer, numberOfBytesToPrint);
		numberOfBytesToPrint = 0;
	}
	theBuffer[numberOfBytesToPrint] = character;
	numberOfBytesToPrint++;

	return (numberOfBytesToPrint);
}
