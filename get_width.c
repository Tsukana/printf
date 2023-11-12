#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: Pointer to the index in the format string.
 * @list: List of arguments.
 *
 * Return: Width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			/* Accumulate digits to form the width. */
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			/* Handle '*' specifier to get width from arguments. */
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
		{
			/* Break on encountering non-digit or non-'*' character. */
			break;
		}
	}

	*i = curr_i - 1;

	return (width);
}
