#include "../main.h"
#include "../Function/function.h"
#include "../Fill_Arr/Fill_Arr.h"
/**
 * Handling_Hex_Specifier_Lower - Print a number in theHex format starting with zero.
 * @theArgs: Input string
 * @theBuffer: Buffer pointer
 * @numberOfBytesToPrint: Index for theBufferfer pointer
 * Return: Number of characters printed
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
	theBinary = fill_theBinary_array(theBinary, input_int, numNegative, 32);

	theHex = malloc(sizeof(char) * (8 + 1));
	theHex = Hex_arr_fill(theBinary, theHex, 0, 8);
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
