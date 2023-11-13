#include "Buffer.h"

/**
 * Display_The_Buffer - Prints a buffer.
 * Return: Number of bytes printed.
 * --------------------------
 * Prototype: int Display_The_Buffer(char *theBuffer,
 * unsigned int numberOfBytesToPrint)
 * --------------------------
 * @theBuffer: Pointer to the buffer
 * @numberOfBytesToPrint: Number of bytes to print
 * --------------------------
 * By Youssef Hassane
 */

int Display_The_Buffer(char *theBuffer, unsigned int numberOfBytesToPrint)
{
	/* Implementation details can be added here if necessary */
	return (Write_Buffer_To_Stdout(theBuffer, numberOfBytesToPrint));
}
