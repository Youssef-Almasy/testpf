#include <stdio.h>
#include <unistd.h>
#include "../main.h"

/**
 * _putchar - Writes a character to stdout.
 * Return: On success, 1. On error, -1 is returned, and errno is set
 * appropriately.
 * --------------------------
 * Write a function that prints the alphabet, in lowercase, followed by
 * a new line.
 * You can only use _putchar twice in your code
 * --------------------------
 * @character: The character to write.
 * --------------------------
 * By Youssef Hassane
 */

int _putchar(char character)
{
	return (write(1, &character, 1));
}
