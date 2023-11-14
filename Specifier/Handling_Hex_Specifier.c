#include "../main.h"
#include "../Function/function.h"
/**
 * Handling_Hex_Specifier - Print a number in theHex format starting with zero.
 * @theArgs: Input string
 * @theBuffer: Buffer pointer
 * @numberOfBytesToPrint: Index for theBufferfer pointer
 * Return: Number of characters printed
 */
int Handling_Hex_Specifier(va_list theArgs, char *theBuffer, unsigned int numberOfBytesToPrint)
{
	int input_int, index, numNegative, count = 0, theFirstNumber = 0;
	char *theHex, *binary;

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

	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, input_int, numNegative, 32);

	theHex = malloc(sizeof(char) * (8 + 1));
	theHex = Hex_arr_fill(binary, theHex, 0, 8);
	index = 0;
	while (theHex[index])
	{
		theFirstNumber = (theHex[index] != '0' && !theFirstNumber) ?
			1 : theFirstNumber;

		numberOfBytesToPrint += (theFirstNumber) ?
			Combines_Buffer(theBuffer, theHex[index], numberOfBytesToPrint) : 0;
		count += (theFirstNumber) ? 1 : 0;

		index++;
	}
	count += 2;
	free(binary);
	free(theHex);
	return (count);
}
