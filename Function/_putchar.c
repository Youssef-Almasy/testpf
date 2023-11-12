#include "../main.h"
#include <unistd.h>
#include "function.h"

/**
 * _putchar - Writes a character to stdout.
 * Return: On success, 1. On error, -1 is returned, and errno is set
 * appropriately.
 * --------------------------
 * Write a function that prints the alphabet, in lowercase, followed by
 * a new line.
 * You can only use _putchar twice in your code
 * --------------------------
 * @theBuffer: Pointer to the buffer.
 * @numberOfBytesToPrint: Number of bytes to write.
 * --------------------------
 * Prototype: int _putchar(char character, unsigned int *length)
 * --------------------------
 * By Youssef Hassane
 */

ssize_t _putchar(char *theBuffer, size_t numberOfBytesToPrint)
{
    return write(1, theBuffer, numberOfBytesToPrint);
}
