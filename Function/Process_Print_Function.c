#include "../main.h"
#include "function.h"

void Process_Print_Function(
	const char *format, char *theBuffer,
	unsigned int *theIndexOfTheBuffer,
	unsigned int *length, va_list theArgs, unsigned int index)
{
	int (*function)(va_list, char *, unsigned int) =
	get_print_func(format, index + 1);

	if (function == NULL)
	{
		if (format[index + 1] == ' ' && !format[index + 2])
			return;
		Combines_Buffer(theBuffer, format[index], *theIndexOfTheBuffer);
		(*length)++;
		index--;
	}
	else
	{
		(*length) += function(theArgs, theBuffer, *theIndexOfTheBuffer);
		index += ev_print_func(format, index + 1);
	}
}
