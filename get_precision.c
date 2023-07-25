#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @argz: List of arguments to be printed.
 * @arglist: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *argz, va_list arglist)
{
	int curr_i = *argz + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(arglist, int);
			break;
		}
		else
			break;
	}

	*argz = curr_i - 1;

	return (precision);
}
