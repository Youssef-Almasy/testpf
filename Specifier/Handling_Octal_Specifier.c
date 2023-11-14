#include "../main.h"
#include "../Function/function.h"
#include "../Generate_Representation/Generate_Representation.h"

/**
 * Handling_Octal_Specifier - prints decimal number in octal
 * @theArgs: input number
 * @theBuffer: buffer pointer
 * @numberOfBytesToPrint: index for buffer pointer
 * Return: number of chars printed.
 */
int Handling_Octal_Specifier(va_list theArgs, char *theBuffer, unsigned int numberOfBytesToPrint)
{
    int index, numNegative, count, first_digit;
    long int input_int;
    char *octal, *binary;

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
    binary = malloc(sizeof(char) * (32 + 1));
    binary = Generate_Binary_Representation(binary, input_int, numNegative, 32);
    octal = malloc(sizeof(char) * (11 + 1));
    octal = fill_oct_array(binary, octal);
    for (first_digit = index = count = 0; octal[index]; i++)
    {
        if (octal[index] != '0' && first_digit == 0)
            first_digit = 1;
        if (first_digit)
        {
            numberOfBytesToPrint = Combines_Buffer(theBuffer, octal[index], numberOfBytesToPrint);
            count++;
        }
    }
    free(binary);
    free(octal);
    return (count);
}