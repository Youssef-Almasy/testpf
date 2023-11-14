#include "../main.h"
#include "../Function/function.h"
#include "../Generate_Representation/Generate_Representation.h"
/**
 * Handling_Hex_Specifier_Lower - Print a number in hexadecimal format, starting with zero.
 * -----------------------------------
 * @theArgs: Input string
 * @theBuffer: Buffer pointer
 * @numberOfBytesToPrint: Index for theBufferfer pointer
 * 
 * Return: Number of characters printed
 * -----------------------------------
 * By: Ahmed Abdelhamid
 */
int Handling_Hex_Specifier_Lower(va_list theArgs, char *theBuffer, unsigned int numberOfBytesToPrint)
{
	int input_int, index, numNegative, count = 0, theFirstNumber = 0;
	char *theHex, *theBinary;

	input_int = va_arg(theArgs, int);
	numNegative = 0;
	if (input_int == 0)
	{
		numberOfBytesToPrint = Combines_Buffer(theBuffer, '0', numberOfBytesToPrint);
		return (1);
	}

	if (input_int < 0)
	{
		input_int = (input_int * -1) - 1;
		numNegative = 1;
	}

	numberOfBytesToPrint = Combines_Buffer(theBuffer, '0', numberOfBytesToPrint);
	numberOfBytesToPrint = Combines_Buffer(theBuffer, 'x', numberOfBytesToPrint);

	theBinary = malloc(sizeof(char) * (32 + 1));
	theBinary = Generate_Binary_Representation(theBinary, input_int, numNegative, 32);

	theHex = malloc(sizeof(char) * (8 + 1));
	theHex = Generate_Hex_Representation(theBinary, theHex, 0, 8);
	index = 0;
	while (theHex[index])
	{
		theFirstNumber = (theHex[index] != '0' && !theFirstNumber) ? 1 : theFirstNumber;

		numberOfBytesToPrint += (theFirstNumber) ? Combines_Buffer(theBuffer, theHex[index], numberOfBytesToPrint) : 0;
		count += (theFirstNumber) ? 1 : 0;

		index++;
	}
	count += 2;
	free(theBinary);
	free(theHex);
	return (count);
}
