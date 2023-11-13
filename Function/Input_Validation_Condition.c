#include "function.h"

/**
 * Input_Validation_Condition - Checks the input validation
 * condition for _printf function.
 * Return: 1 if the condition is true, 0 otherwise.
 * --------------------------
 * Prototype: int Input_Validation_Condition(
 * const char *theInputString, unsigned int index)
 * --------------------------
 * @theInputString: input string.
 * @index: current index in the theInputString string.
 * --------------------------
 * By Youssef Hassane
 */

int Input_Validation_Condition(const char *theInputString, unsigned int index)
{
	/* Check if theInputString is a null pointer */
	/* or if the current character is '%' and the next character is null */
	return (
	    !theInputString ||			 /* Null pointer check */
	    (theInputString[index] == '%' && /* '%' character check */
	     !theInputString[index + 1]));	 /* Next character is null check */
}
