#include "main.h"

/**
 * flush_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters.
 * @buffer_index: Index to add the next character, represents the length.
 */
void flush_buffer(char buffer[], int *buffer_index);

/**
 * custom_printf - Custom printf function
 * @format: Format string.
 * Return: Number of printed characters.
 */
int custom_printf(const char *format, ...)
{
	int i, printed = 0, total_printed = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list args;
	char output_buffer[BUFF_SIZE];

	if (format == NULL)
	{
		/* Handle NULL format string gracefully. */
		fprintf(stderr, "Error: NULL format string\n");
		return (-1);
	}

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			output_buffer[buffer_index++] = format[i];
			if (buffer_index == BUFF_SIZE)
				flush_buffer(output_buffer, &buffer_index);
			printed++;
		}
		else
		{
			flush_buffer(output_buffer, &buffer_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, args, output_buffer,
								   flags, width, precision, size);
			if (printed == -1)
			{
				/* Handle printing error. */
				fprintf(stderr, "Error: Printing failed\n");
				va_end(args);
				return (-1);
			}
			total_printed += printed;
		}
	}

	flush_buffer(output_buffer, &buffer_index);

	va_end(args);

	return (total_printed);
}

/**
 * flush_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of characters.
 * @buffer_index: Index to add the next character, represents the length.
 */
void flush_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, buffer, *buffer_index);

	*buffer_index = 0;
}
