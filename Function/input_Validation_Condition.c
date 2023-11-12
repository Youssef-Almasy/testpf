#include "function.h"

/**
 * input_Validation_Condition - Checks the input validation
 * condition for _printf function.
 * Return: 1 if the condition is true, 0 otherwise.
 * --------------------------
 * Prototype: int input_Validation_Condition(
 * const char *theInputString, unsigned int index)
 * --------------------------
 * @theInputString: input string.
 * @index: current index in the theInputString string.
 * --------------------------
 * By Youssef Hassane
 */

int input_Validation_Condition(const char *theInputString, unsigned int index)
{
	return (
	    !theInputString ||
	    (theInputString[index] == '%' &&
	     !theInputString[index + 1])
	);
}
