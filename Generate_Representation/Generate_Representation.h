#include "../main.h"

char *Generate_Hex_Representation(
		char *bnr,
		char *hexadecimal,
		int isUppercase,
		int limit);

char *Generate_Binary_Representation(
	char *binaryRepresentation, long int theGivenNumber,
	int isNegative, int theLimitOfBinary);

int Handling_Octal_Specifier(va_list theArgs,
 char *theBuffer,
  unsigned int numberOfBytesToPrint);

