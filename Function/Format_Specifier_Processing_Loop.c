#include "../main.h"
#include "../variables.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

static int Format_Specifier_Processing_Loop(const char *format, char *theBuffer,
							  unsigned int *theIndexOfTheBuffer,
							  unsigned int *length, va_list theArgs)
{
	unsigned int index;

	for (index = 0; format && format[index]; index++)
	{
		if (format[index] == '%')
		{
			if (format[index + 1] == '\0')
			{
				print_buf(theBuffer, *theIndexOfTheBuffer), free(theBuffer), va_end(theArgs);
				return (FAIL);
			}
			else
			{
				int (*function)(va_list, char *, unsigned int) = get_print_func(format, index + 1);
				if (function == NULL)
				{
					if (format[index + 1] == ' ' && !format[index + 2])
						return (FAIL);
					handl_buf(theBuffer, format[index], *theIndexOfTheBuffer), (*length)++, index--;
				}
				else
				{
					(*length) += function(theArgs, theBuffer, *theIndexOfTheBuffer);
					index += ev_print_func(format, index + 1);
				}
			}
			index++;
		}
		else
			handl_buf(theBuffer, format[index], *theIndexOfTheBuffer), (*length)++;
		for (*theIndexOfTheBuffer = *length; *theIndexOfTheBuffer > 1024; *theIndexOfTheBuffer -= 1024)
			;
	}

	return *length;
}