#ifndef PUT_TYPE
#define PUT_TYPE

#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);
int _putstr(char *str, int reverse);
int _putint(int number);
int putBinary(unsigned int number);
int putUnsignedInt(unsigned int number);
int putOctal(unsigned int number);
int putHexa(unsigned int number, int isUpper);
int putPointer(void *pointer);
int putRot13(char *str);
int convertSpecialChar(char *str);

#endif
