#ifndef BUFFER_H
#define BUFFER_H

#include "../main.h"
#include <unistd.h>

int Display_The_Buffer(char *theBuffer, unsigned int numberOfBytesToPrint);

unsigned int Combines_Buffer(
	char *theBuffer,
	char character,
	unsigned int numberOfBytesToPrint);

ssize_t Write_Buffer_To_Stdout(char *theBuffer, size_t numberOfBytesToPrint);

#endif
