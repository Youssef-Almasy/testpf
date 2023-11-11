#ifndef MAIN_H
#define MAIN_H


int _putchar(char character);
int _printf(const char *format, ...);
static int Format_Specifier_Processing_Loop(const char *format, char *theBuffer,
							  unsigned int *theIndexOfTheBuffer,
							  unsigned int *length, va_list theArgs);
#endif
