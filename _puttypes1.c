#include "_puttypes.h"

/**
 * putUnsignedInt - prints Unsigned Int
 * @number: Unsigned Int
 * Return: lenght of number
 */
int putUnsignedInt(unsigned int number)
{
	if (number < 10)
		return (_putchar(number + '0'));
	else
		return (putUnsignedInt(number / 10) + putUnsignedInt(number % 10));
}

/**
 * putOctal - prints unsigned integer as octal
 * @number: unsigned integer
 * Return: lenght of octal
*/
int putOctal(unsigned int number)
{
	char digits[20];
	int len = 0, i = 0;

	if (number == 0)
		return (_putchar('0'));
	while (number > 0)
	{
		digits[i++] = '0' + (number & 7);
		number = number >> 3;
	}

	while (i > 0)
		len += _putchar(digits[--i]);

	return (len);
}

/**
 * putHexa - prints unsigned integer as Hexa
 * @number: unsigned integer
 * @isUpper: flag for %x or %X
 * Return: lenght of hexa
*/
int putHexa(unsigned int number, int isUpper)
{
	char digits[20];
	int len = 0, i = 0;
	int digit;

	if (number == 0)
		return (_putchar('0'));
	while (number > 0)
	{
		digit = number & 0xF;
		if (digit < 10)
			digits[i++] = '0' + digit;
		else
			digits[i++] = (isUpper ? 'A' : 'a') + (digit - 10);
		number = number >> 4;
	}

	while (i > 0)
		len += _putchar(digits[--i]);

	return (len);
}

/**
 * putPointer - prints pointer value as hexa
 * @pointer: address to be printed
 * Return: return lenght of address
 */
int putPointer(void *pointer)
{
	unsigned long int number = (unsigned long int) pointer;
	char digits[40];
	int len = 0, i = 0;
	int digit;

	if (pointer == NULL)
		return (_putstr("(nil)", 0));

	if (number == 0)
		return (_putchar('0'));
	while (number > 0)
	{
		digit = number & 0xF;
		if (digit < 10)
			digits[i++] = '0' + digit;
		else
			digits[i++] = 'a' + (digit - 10);
		number = number >> 4;
	}

	len += _putchar('0');
	len += _putchar('x');
	while (i > 0)
		len += _putchar(digits[--i]);

	return (len);
}

/**
 * putRot13 - prints strings ROT13
 * @str: string to be modified and printed
 * Return: lenght of strings
 */
int putRot13(char *str)
{
	int i, character, len = 0;

	if (str == NULL)
		return (_putstr("(nil)", 0));
	for (i = 0; str[i] != '\0'; i++)
	{
		character = (int) str[i];
		if (character >= 97 && character <= 122)
		{
			character += 13;
			character = (character > 122) ? 97 + (character - 123) : character;
			len += _putchar(character);
		} else if (character >= 65 && character <= 90)
		{
			character += 13;
			character = (character > 90) ? 65 + (character - 91) : character;
			len += _putchar(character);
		} else
			len += _putchar(character);
	}
	return (len);
}
