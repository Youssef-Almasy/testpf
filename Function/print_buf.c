#include "main.h"

/**
 * printBuffer - Prints a buffer.
 * @buffer: Pointer to the buffer
 * @numBytes: Number of bytes to print
 * Return: Number of bytes printed.
 */

int printBuffer(char *buffer, unsigned int numBytes)
{
	return (write(1, buffer, numBytes));
}
