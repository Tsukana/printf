#include "main.h"

/**
 * handle_specifier - execute put function according to specifier
 * @specifier: specifies which put function to use
 * @len: increment the argument lenght into the initial output
 * @argv: get argument from _printf
 * Return: void
 */

void handle_specifier(char specifier, int *len, va_list argv)
{
	if (specifier == 'c')
		(*len) += _putchar(va_arg(argv, int));
	else if (specifier == 's')
		(*len) += _putstr(va_arg(argv, char *), 0);
	else if (specifier == 'd' || specifier == 'i')
		(*len) += _putint(va_arg(argv, int));
	else if (specifier == 'b')
		(*len) += putBinary(va_arg(argv, unsigned int));
	else if (specifier == 'u')
		(*len) += putUnsignedInt(va_arg(argv, unsigned int));
	else if (specifier == 'o')
		(*len) += putOctal(va_arg(argv, unsigned int));
	else if (specifier == 'x')
		(*len) += putHexa(va_arg(argv, unsigned int), 0);
	else if (specifier == 'X')
		(*len) += putHexa(va_arg(argv, unsigned int), 1);
	else if (specifier == 'p')
		(*len) += putPointer(va_arg(argv, void *));
	else if (specifier == 'R')
		(*len) += putRot13(va_arg(argv, char *));
	else if (specifier == 'r')
		(*len) += _putstr(va_arg(argv, char *), 1);
	else if (specifier == 'S')
		(*len) += convertSpecialChar(va_arg(argv, char *));
	else
		(*len) += _putchar(specifier);
}
