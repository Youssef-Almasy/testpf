#include "main.h"

/**
 * Handling_Integer_Specifier - prints an integer
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int Handling_Integer_Specifier(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input;
	unsigned int int_in, int_temp, i, div, isneg;

	int_input = va_arg(arguments, int);
	isneg = 0;
	if (int_input < 0)
	{
		int_in = int_input * -1;
		ibuf = handl_buf(buf, '-', ibuf);
		isneg = 1;
	}
	else
	{
		int_in = int_input;
	}

	int_temp = int_in;
	div = 1;

	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}

	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handl_buf(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i + isneg);
}

#include "main.h"

/**
 * Handling_Integer_Specifier - Prints an integer.
 * @arguments: Input string.
 * @buf: Buffer pointer.
 * @ibuf: Index for buffer pointer.
 * Return: Number of characters printed.
 */
int Handling_Integer_Specifier(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input = va_arg(arguments, int);
	unsigned int int_in = (unsigned int)int_input;
	unsigned int div = 1;

	if (int_input < 0)
	{
		ibuf = handl_buf(buf, '-', ibuf);
		int_input *= -1;
	}

	// Find the divisor for the largest place value
	while (int_in / div >= 10)
	{
		div *= 10;
	}

	// Extract each digit and add it to the buffer
	while (div > 0)
	{
		unsigned int digit = int_in / div;
		ibuf = handl_buf(buf, digit + '0', ibuf);
		int_in %= div;
		div /= 10;
	}

	return ibuf;
}
