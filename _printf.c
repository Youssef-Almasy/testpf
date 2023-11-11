#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h> // Include the necessary header for snprintf

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;
	int num;
	char buffer[12];
	int len;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			// Handle '%' character
			switch (*(++ptr))
			{
			case 'c':
				// %c specifier
				num = va_arg(args, int);
				write(1, &num, 1);
				count++;
				break;
			case 'd':
			case 'i':
				// %d or %i specifier
				num = va_arg(args, int);
				// Convert integer to string and write to stdout
				// assuming a 32-bit integer
				 
				
				len = snprintf(buffer, sizeof(buffer), "%d", num);
				write(1, buffer, len);
				count += len;
				break;
			default:
				// Unsupported specifier, print as is
				write(1, "%", 1);
				count++;
				if (*ptr != '\0')
				{
					write(1, ptr, 1);
					count++;
				}
				break;
			}
		}
		else
		{
			// Handle regular characters
			write(1, ptr, 1);
			count++;
		}
	}

	va_end(args);

	return count;
}
