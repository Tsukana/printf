#include "main.h"

/**
 * _putchar - prints a character
 * @c: character
 * Return: if null return 0, else 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putstr - prints a character
 * @str: string to print
 * @reverse: flag to reverse string
 * Return: lenght of string
 */
int _putstr(char *str, int reverse)
{
	int len = 0;
	char *end = str;

	if (str == NULL)
	{
		reverse = 0;
		str = "(nil)";
	}
	if (!reverse)
	{
		while (*str != '\0')
		{
			len += _putchar(*str);
			str++;
		}
	} else
	{
		while (*end != '\0')
			end++;

		while (end > str)
			len += _putchar(*(--end));
	}
	return (len);
}

/**
 * _putint - prints a integer
 * @number: integer
 * Return: lenght of number
 */
int _putint(int number)
{
	if (number < 0)
		return (_putchar('-') + _putint(-1 * number));
	else if (number < 10)
		return (_putchar(number + '0'));
	else
		return (_putint(number / 10) + _putint(number % 10));
}

/**
 * putBinary - prints unsigned integer as binary
 * @number: unsigned integer
 * Return: lenght of binary
*/
int putBinary(unsigned int number)
{
	int len = 0;

	if (number > 1)
		len += putBinary(number >> 1);
	len += _putchar('0' + (number & 1));

	return (len);
}
