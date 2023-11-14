#include "../main.h"
#include "../Function/function.h"
/**
 * Hex_arr_fill - Convert a binary array to a hexadecimal array.
 *
 * @bnr: Binary array to be converted.
 * @hexadecimal: Array to store the resulting hexadecimal representation.
 * @isUppercase: Flag indicating whether to use uppercase letters.
 * @limit: Size of the hexadecimal array.
 *
 * Return: Hexadecimal array.
 */
char *Hex_arr_fill(char *bnr, char *hexadecimal, int isUppercase, int limit)
{
	// Ensure the hexadecimal array is null-terminated
	hexadecimal[limit] = '\0';

	// Determine the ASCII value for the letter 'A'
	// or 'a' based on the isUppercase flag
	int letterOffset = (isUppercase) ? 55 : 87;

	// Iterate through the binary array in reverse to convert to hexadecimal
	int i = (limit * 4) - 1;

	while (i >= 0)
	{
		int decimalValue = 0;

		// Perform binary to decimal conversion for each group of four bits
		int j = 1;

		while (j <= 8)
		{
			decimalValue = ((bnr[i] - '0') * j) + decimalValue;
			j *= 2;
			i--;
		}

		// Adjust the index to write the result into the hexadecimal array
		i++;

		// Convert the decimal value to its corresponding hexadecimal character
		switch (decimalValue)
		{
		case 0 ... 9:
			hexadecimal[i / 4] = decimalValue + '0';
			break;
		default:
			hexadecimal[i / 4] = decimalValue + letterOffset;
		}
	}

	// Return the resulting hexadecimal array
	return (hexadecimal);
}
