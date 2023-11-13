#include "function.h"
#include "../main.h"

/**
 * Find_Matching_Function_Index - Function to find the index of
 * the matching function in the 'functions' array.
 * Return: The index of the matching function in the 'functions' array.
 * ----------------------
 * Prototype:
 * int (*Determine_Print_Function(
 * const char *identifier,
 * int position))(va_list, char *, unsigned int)
 * ----------------------
 * @identifier: The argument identifier to match.
 * @position: Current position in the identifier string.
 * @index_1: Pointer to the first index used for iteration in 'functions'.
 * @index_2: Pointer to the second index used for character matching.
 * @functions: Array of structures mapping identifiers to functions.
 * ----------------------
 * By Youssef Hassane
 */

int Find_Matching_Function_Index(
	const char *identifier, int position,
	int *index_1, int *index_2,
	const print_t *functions)
{
	/* Save the initial position for potential resets */
	int initial_position = position;
	/* Iterate through the 'functions' array until */
	/* a match is found or the end is reached */
	while (functions[*index_1].argument_type)
	{
		/* Check if the current character in the identifier */
		/* matches the expected character in the function argument type */
		if (identifier[position] == functions[*index_1].argument_type[*index_2])
		{
			/* If there are more characters in the function argument type */
			/* move to the next character */
			if (functions[*index_1].argument_type[*index_2 + 1] != '\0')
			{
				position++, (*index_2)++;
			}
			/* If the end of the function argument type is reached, break the loop */
			else
			{
				break;
			}
		}
		/* If there is no match, reset the second index */
		/* move to the next function, and reset the position */
		else
		{
			*index_2 = 0;
			(*index_1)++;
			position = initial_position;
		}
	}
	/* Return the index of the matching function in the 'functions' array */
	return (*index_1);
}
