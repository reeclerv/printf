#include "main.h"

void print_buffer(char buffer[], int *bufferIndex);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, bufferIndex = 0;
	va_list arglist;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(arglist, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[bufferIndex++] = format[i];
			if (bufferIndex == BUFF_SIZE)
				print_buffer(buffer, &bufferIndex);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &bufferIndex);
			flags = get_flags(format, &param);
			width = get_width(format, &argz, arglist);
			precision = get_precision(format, &argz, arglist);
			size = get_size(format, &arglist);
			++i;
			printed = handle_print(format, &argz, arglist, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &bufferIndex);

	va_end(arglist);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @bufferIndex: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *bufferIndex)
{
	if (*bufferIndex > 0)
		write(1, &buffer[0], *bufferIndex);

	*bufferIndex = 0;
}
