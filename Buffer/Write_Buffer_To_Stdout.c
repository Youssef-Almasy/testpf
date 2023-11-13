#include "Buffer.h"

/**
 * Write_Buffer_To_Stdout - Writes the contents of the buffer to the
 * standard output.
 * Return: On success, the number of bytes written is returned. On error, -1 is
 * returned, and errno is set appropriately.
 * --------------------------
 * @theBuffer: Pointer to the buffer containing the characters to write.
 * @numberOfBytesToPrint: Number of bytes to write from the buffer.
 * --------------------------
 * Prototype: ssize_t Write_Buffer_To_Stdout(char *theBuffer,
 * size_t numberOfBytesToPrint)
 * --------------------------
 * This function writes the specified number of bytes from the buffer to the
 * standard output (file descriptor 1). It utilizes the POSIX write function.
 * --------------------------
 * By Youssef Hassane
 */

ssize_t Write_Buffer_To_Stdout(char *theBuffer, size_t numberOfBytesToPrint)
{
	/* Use the POSIX write function to write the buffer to standard output */
	return (write(1, theBuffer, numberOfBytesToPrint));
}
