#include "../main.h"

/**
 * processCharacters - Process each character in the input string.
 *
 * @inputString: Input string to be processed.
 * @theBuffer: Buffer to store the result.
 * @numberOfBytesToPrint: Index for the buffer.
 *
 * Return: Updated number of characters printed.
 */
unsigned int processCharacters(const char *inputString,
		char *theBuffer,
		unsigned int numberOfBytesToPrint)
{
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	unsigned int inputIndex = 0, alphabetIndex, isFound;

	/* Process each character in the input string */
	while (inputString[inputIndex])
	{
		isFound = 0;
		alphabetIndex = 0;

		/* Search for the character in the alphabet */
		while (alphabet[alphabetIndex])
		{
			if (inputString[inputIndex] == alphabet[alphabetIndex])
			{
				isFound = 1;
				/* Apply ROT13 substitution and print the result */
				numberOfBytesToPrint = Combines_Buffer(theBuffer, rot13[alphabetIndex], numberOfBytesToPrint);
				break;
			}
			alphabetIndex++;
		}

		/* If the character is not in the alphabet, print it unchanged */
		if (!isFound)
			numberOfBytesToPrint = Combines_Buffer(theBuffer, inputString[inputIndex], numberOfBytesToPrint);

		inputIndex++;
	}

	return (numberOfBytesToPrint);
}

/**
 * Handling_Rot13_Specifier - Prints a string using the
 *							  ROT13 substitution cipher.
 *
 * @theArgs: The variable arguments list.
 * @theBuffer: Buffer to store the result.
 * @numberOfBytesToPrint: Index for the buffer.
 *
 * Return: Number of characters printed.
 */
int Handling_Rot13_Specifier(va_list theArgs,
		char *theBuffer,
		unsigned int numberOfBytesToPrint)
{
	char *inputString;
	char placeholder[] = "(nil)";

	inputString = va_arg(theArgs, char *);

	/* Handle the case when the string is NULL */
	if (inputString == NULL)
	{
		/* Print the placeholder string "(nill)" */
		numberOfBytesToPrint = processCharacters(placeholder,
				theBuffer, numberOfBytesToPrint);
		return (5);
	}

	/* Process each character in the input string */
	numberOfBytesToPrint = processCharacters(inputString,
			theBuffer, numberOfBytesToPrint);

	/* Return the total number of characters printed */
	return (numberOfBytesToPrint);
}
