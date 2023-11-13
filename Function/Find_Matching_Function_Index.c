#include "function.h"
#include "../main.h"

/* Function to find the index of the matching function */
int Find_Matching_Function_Index(
	const char *identifier, int position,
	int *index_1, int *index_2,
	const print_t *functions)
{
	/* */
	int initial_position = position;
	/* */
	while (functions[*index_1].argument_type)
	{
		/* */
		if (identifier[position] == functions[*index_1].argument_type[*index_2])
		{
			/* */
			if (functions[*index_1].argument_type[*index_2 + 1] != '\0')
			{
				position++, (*index_2)++;
			}
			/* */
			else
			{
				break;
			}
		}
		else
		{
			/* */
			*index_2 = 0;
			/* */
			(*index_1)++;
			/* */
			position = initial_position;
		}
	}
	/* */
	return (*index_1);
}
