#include "../main.h"
#include <stdio.h>

/**
 * print_prg - writes the character c to stdout
 * @a: input char
 * @buffer: buffer pointer
 * @i: index for buffer pointer
 * Return: On success 1.
 */

int print_prg(va_list a, char *buffer, unsigned int i)
{
	char percent = '%';

	(void)a;

	Combines_Buffer(buffer, percent, i);

	return (1);
}
