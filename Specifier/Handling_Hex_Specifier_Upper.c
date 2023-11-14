#include "../main.h"
#include "../Function/function.h"
#include "../Generate_Representation/Generate_Representation.h"

/**
 * Handling_Hex_Specifier_Upper - Prints the hexadecimal representation of a decimal.
 * @theArgs: The arguments list.
 * @theBuffer: Buffer pointer for storing the result.
 * @numberOfBytesToPrint: Index for the buffer pointer.
 * Return: Number of characters printed.
 */
int Handling_Hex_Specifier_Upper(va_list theArgs, char *theBuffer, unsigned int numberOfBytesToPrint)
{
	int  index, numNegative, count, theFirstNumber;
	long int input_int;
	char *theHex, *theBinary;

	/**Retrieve the integer argument from the variable arguments list */
	input_int = va_arg(theArgs, int);
	numNegative = 0;

	/**Handle the case when the input is zero */
	if (input_int == 0)
	{
		numberOfBytesToPrint = Combines_Buffer(theBuffer, '0', numberOfBytesToPrint);
		return (1);
	}

	/**Handle the case when the input is negative */
	if (input_int < 0)
	{
		input_int = (input_int * -1) - 1;
		numNegative = 1;
	}

	/**Allocate memory for binary and hexadecimal arrays */
	theBinary = malloc(sizeof(char) * (32 + 1));
	theBinary = Generate_Binary_Representation(theBinary, input_int, numNegative, 32);

	theHex = malloc(sizeof(char) * (8 + 1));
	theHex = Generate_Hex_Representation(theBinary, theHex, 1, 8);

	/**Loop through the hexadecimal array to print the non-zero digits */
	for (theFirstNumber = index = count = 0; theHex[index]; index++)
	{
		if (theHex[index] != '0' && theFirstNumber == 0)
			theFirstNumber = 1;

		/**Print the non-zero digits to the buffer */
		if (theFirstNumber)
		{
			numberOfBytesToPrint = Combines_Buffer(theBuffer, theHex[index], numberOfBytesToPrint);
			count++;
		}
	}

	/**Free allocated memory for binary and hexadecimal arrays */
	free(theBinary);
	free(theHex);

	/**Return the total count of characters printed */
	return (count);
}
