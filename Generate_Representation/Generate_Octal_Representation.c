#include "../main.h"
#include "../Function/function.h"
#include "../Generate_Representation/Generate_Representation.h"

/**
 * Generate_Octal_Representation - Generate octal representation of a given number.
 * Return: Octal Representation string.
 * -----------------------------------
 * @binaryArray: Binary array to be converted.
 * @octalRepresentation: Array to store the resulting octal representation.
 * -----------------------------------
 * By Ahmed Abdelhamid 
 */
char *Generate_Octal_Representation(char *binaryArray, char *octalRepresentation)
{
    int binaryValue, binaryIndex;
    int powerOfTwo, octalIndex, limit;

    /** Ensure the octal array is null-terminated */
    octalRepresentation[11] = '\0';

    /** Iterate through the binary array in reverse to convert to octal */
    binaryIndex = 31;
    octalIndex = 10;

    while (binaryIndex >= 0)
    {
        /** Determine the limit for the inner loop based on the position in the array */
        switch (binaryIndex)
        {
        case 0:
        case 1:
            limit = 2;
            break;
        default:
            limit = 4;
        }
        /** Perform binary to decimal conversion for each group of bits */
        binaryValue = 0;
        powerOfTwo = 1;

        while (powerOfTwo <= limit)
        {
            binaryValue = ((binaryArray[binaryIndex] - '0') * powerOfTwo) + binaryValue;
            powerOfTwo *= 2;
            binaryIndex--;
        }

        /** Adjust the index to write the result into the octal array */
        binaryIndex++;

        /** Convert the decimal value to its octal character, then move to previous index */
        octalRepresentation[octalIndex] = binaryValue + '0';
        octalIndex--;
    }

    /** Return the resulting octal array */
    return octalRepresentation;
}
