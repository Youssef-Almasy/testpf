#include "../main.h"
#include "Generate_Representation.h"

/**
 * Generate_Binary_Representation - Generate binary representation
 * of a given number.
 * Return: Binary representation string.
 * ----------------------
 * prototype: char *Generate_Binary_Representation(
 * char *binaryRepresentation, long int theGivenNumber,
 * int isNegative, int theLimitOfBinary)
 * ----------------------
 * @binaryRepresentation: The binary representation string to be generated.
 * @theGivenNumber: The given number to be represented in binary.
 * @isNegative: Flag indicating if the number is negative.
 * @theLimitOfBinary: The limit of binary digits.
 * ----------------------
 * By Youssef Hassane
 */

char *Generate_Binary_Representation(
	char *binaryRepresentation, long int theGivenNumber,
	int isNegative, int theLimitOfBinary)
{
	/* Initialize index for binary representation */
	int index = 0;
	/* Initialize binary representation with zeros */
	while (index < theLimitOfBinary)
	{
		binaryRepresentation[index] = '0';
		index++;
	}
	/* Add null terminator to the binary representation string */
	binaryRepresentation[theLimitOfBinary] = '\0';
	/* Generate binary representation of the given number */
	index = theLimitOfBinary - 1;
	while (theGivenNumber > 0)
	{
		binaryRepresentation[index] = (theGivenNumber % 2) + '0';
		theGivenNumber /= 2;
		index--;

		/* Break if index goes below 0 */
		if (index < 0)
		{
			break;
		}
	}
	/* Invert bits if the number is negative */
	if (isNegative)
	{
		index = 0;
		while (binaryRepresentation[index])
		{
			binaryRepresentation[index] = (
				binaryRepresentation[index] == '0') ? '1' : '0';
			index++;
		}
	}
	/* Return the generated binary representation string */
	return (binaryRepresentation);
}
