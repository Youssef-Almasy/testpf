#include "../main.h"
#include "function.h"

void Process_Print_Function(
	const char *theStringToProcess, char *theBuffer,
	unsigned int *theIndexOfTheBuffer,
	unsigned int *length, va_list theArgs, unsigned int index)
{
	int (*function)(va_list, char *, unsigned int) =
	Determine_Print_Function(theStringToProcess, index + 1);

	if (function == NULL)
	{
		if (theStringToProcess[index + 1] == ' ' && !theStringToProcess[index + 2])
			return;
		Combines_Buffer(theBuffer, theStringToProcess[index], *theIndexOfTheBuffer);
		(*length)++;
		index--;
	}
	else
	{
		(*length) += function(theArgs, theBuffer, *theIndexOfTheBuffer);
	}
}
