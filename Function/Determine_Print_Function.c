#include "../main.h"
#include "function.h"

/**
 * Determine_Print_Function - Selects the appropriate function
 * for the task based on the provided identifier and position.
 * Return: Pointer to a function that matches the given identifier.
 * ----------------------
 * Prototype:
 * int (*Determine_Print_Function(
 * const char *identifier,
 * int position))(va_list, char *, unsigned int)
 * ----------------------
 * @identifier: Argument identifier.
 * @position: Position for the argument identifier.

 * ----------------------
 * By Youssef Hassane
 */

int (*Determine_Print_Function(
	const char *identifier,
	int position))(va_list, char *, unsigned int)
{
	/* Initialize index variables for iteration */
	/* through functions and argument types */
	int index_1 = 0;
	int index_2 = 0;
	/* Array of structures mapping identifiers to corresponding functions */
	print_t functions[] = {
	    /* Handling Character Specifier */
	    {"c", Handling_Character_Specifier},
	    /* Handling String Specifier */
	    {"s", Handling_String_Specifier},
	    /* Handling Percent Sign Specifier */
	    {"%", Handling_Percent_Sign_Specifier},
	    /* Handling Integer that has the sign "i" Specifier */
	    {"i", Handling_Integer_Specifier},
	    /* Handling Integer that has the sign "d" Specifier */
	    {"d", Handling_Integer_Specifier},
	    /* Handling Hex that has the sign "x" Specifier */
	    {"x", Handling_Hex_Specifier},
	    /*Sentinel entry indicating the end of the array */
	    {NULL, NULL},
	};
	/* Find the index of the matching function in the 'functions' array */
	int matchingIndex = Find_Matching_Function_Index(
	    identifier, position,
	    &index_1, &index_2, functions);
	/* Return the pointer to the matching function */
	return (functions[matchingIndex].function_pointer);
}
