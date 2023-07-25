#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @param: take a parameter.
 * 
 * Return: Flags:
 */
int get_flags(const char *format, int *param)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flags = 0;
	const char F_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int F_ARRY[] = {F_NEG, F_POS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *param + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == F_CHAR[j])
			{
				flags |= F_ARRY[j];
				break;
			}

		if (F_CHAR[j] == 0)
			break;
	}

	*param = curr_i - 1;

	return (flags);
}
