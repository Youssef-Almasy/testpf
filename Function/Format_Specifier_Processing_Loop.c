#include "../main.h"
#include "Process_Print_Function.c"

int Format_Specifier_Processing_Loop(
	const char *format, char *theBuffer,
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
				Display_The_Buffer(theBuffer, *theIndexOfTheBuffer);
				free(theBuffer);
				va_end(theArgs);
				return (FAIL);
			}
			else
			{
				Process_Print_Function(
				    format, theBuffer, theIndexOfTheBuffer,
				    length, theArgs, index);
			}
			index++;
		}
		else
		{
			Combines_Buffer(
			    theBuffer, format[index],
			    *theIndexOfTheBuffer),
			    (*length)++;
		}
		for (
			  *theIndexOfTheBuffer = *length;
			  *theIndexOfTheBuffer > BUFFERSIZE;
			  *theIndexOfTheBuffer -= BUFFERSIZE)
			;
	}

	return (*length);
}
