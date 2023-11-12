#include "../main.h"

/**
 * Handling_Integer_Specifier - Handles the conversion and
 * formatting of integer specifiers
 * Return: Number of characters displayed in the buffer
 * ----------------------
 * prototype: int Handling_Integer_Specifier(
 * va_list theArgs,
 * char *theBuffer,
 * unsigned int numberOfBytesToPrint)
 * ----------------------
 * @theArgs: Variable argument list
 * containing the integer to be formatted
 * @theBuffer: Character buffer to store
 * the formatted integer as a string
 * @numberOfBytesToPrint: Maximum number of
 * bytes available in the buffer for printing
 * ----------------------
 * By Youssef Hassane
 */
int Handling_Integer_Specifier(
	va_list theArgs,
	char *theBuffer,
	unsigned int numberOfBytesToPrint)
{
	/* Extract integer from variable arguments */
	int theInputOfInteger = va_arg(theArgs, int);
	/* Temporary variable for the processed integer */
	unsigned int temporaryVariableOfTheIntegerThatProcessed;
	/* Index for tracking position in the buffer */
	unsigned int index = 0;
	/* Variable to check if the integer is negative */
	int isNegative;
	/* Check and handle the sign of the integer */
	isNegative = Handle_Integer_Sign(
	    theInputOfInteger,
	    theBuffer,
	    &numberOfBytesToPrint);
	/* Determine the absolute value of the integer */
	temporaryVariableOfTheIntegerThatProcessed =
	    (isNegative) ? theInputOfInteger * -1 : theInputOfInteger;
	/* Append digits to the buffer */
	Append_Digits_To_Buffer(
	    temporaryVariableOfTheIntegerThatProcessed,
	    &numberOfBytesToPrint,
	    theBuffer,
	    &index);
	/* Return the total number of characters in the buffer */
	return (index + isNegative);
}

/**
 * Handle_Integer_Sign - Handles the sign of the
 * integer and updates the buffer
 * Return: 1 if the integer is negative, 0 otherwise
 * ----------------------
 * prototype: int Handle_Integer_Sign(
 * int theInputOfInteger,
 * char *theBuffer,
 * unsigned int *numberOfBytesToPrint)
 * ----------------------
 * @theInputOfInteger: Integer value to check the sign of
 * @theBuffer: Character buffer to store the formatted integer as a string
 * @numberOfBytesToPrint: Maximum number of bytes
 * available in the buffer for printing
 * ----------------------
 * By Youssef Hassane
 */
int Handle_Integer_Sign(
	int theInputOfInteger,
	char *theBuffer,
	unsigned int *numberOfBytesToPrint)
{
	/* Variable to check if the integer is negative */
	int isNegative = 0;
	/* Check if the integer is negative and update the buffer accordingly */
	if (theInputOfInteger < 0)
	{
		*numberOfBytesToPrint =
		    Combines_Buffer(theBuffer, '-', *numberOfBytesToPrint);
		isNegative = 1;
	}
	/* Return 1 if the integer is negative, 0 otherwise */
	return (isNegative);
}

/**
 * AppendDigitsToBuffer - Appends digits of an integer to the buffer
 * ----------------------
 * prototype: void AppendDigitsToBuffer(
 * unsigned int value,
 * unsigned int *numberOfBytesToPrint,
 * char *theBuffer,
 * unsigned int *index)
 * ----------------------
 * @value: The integer to be appended
 * @theBuffer: Character buffer to store
 * the formatted integer as a string
 * @numberOfBytesToPrint: Maximum number of
 * bytes available in the buffer for printing
 * @index: Index of the character in the buffer
 * ----------------------
 * By Youssef Hassane
 */
void Append_Digits_To_Buffer(
	unsigned int value,
	unsigned int *numberOfBytesToPrint,
	char *theBuffer,
	unsigned int *index)
{
	/* Variable for determining place value of digits */
	unsigned int theDivisor = 1;
	/* Find the divisor to determine the place value of the leftmost digit */
	while (value / theDivisor >= 10)
	{
		theDivisor *= 10;
	}
	/* Append each digit to the buffer */
	while (theDivisor > 0)
	{
		*numberOfBytesToPrint = Combines_Buffer(
		    theBuffer,
		    ((value / theDivisor) % 10) + '0',
		    *numberOfBytesToPrint);
		theDivisor /= 10;
		(*index)++;
	}
}
