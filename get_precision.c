#include "main.h"

/**
 * get_precision - Calculates the precision on  printing
 * @format: Formatted string to print the arguments
 * @i: List of arguments
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int bab_c = *i + 1;
	int precision = -1;

	if (format[bab_c] != '.')
		return (precision);

	precision = 0;

	for (bab_c += 1; format[bab_c] != '\0'; bab_c++)
	{
		if (is_digit(format[bab_c]))
		{
			precision *= 10;
			precision += format[bab_c] - '0';
		}
		else if (format[bab_c] == '*')
		{
			bab_c++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (precision);
}


