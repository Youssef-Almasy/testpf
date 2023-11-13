#include "../main.h"
#include "function.h"

/**
 * determinePrintFunction - selects the appropriate function for the task.
 * @identifier: argument identifier
 * @position: position for argument identifier
 * Return: pointer to a function.
 */

int (*Determine_Print_Function(
	const char *identifier,
	int position))(va_list, char *, unsigned int)
{
	int index_1 = 0;
	int index_2 = 0;

	print_t functions[] = {
	    {"c", Handling_Character_Specifier},
	    {"s", Handling_String_Specifier},
	    {"%", Handling_Percent_Sign_Specifier},
	    {"i", Handling_Integer_Specifier},
	    {"d", Handling_Integer_Specifier},
	    {NULL, NULL},
	};

	int matchingIndex = Find_Matching_Function_Index(
		identifier, position,
		&index_1, &index_2, functions);

	return (functions[matchingIndex].function_pointer);
}
