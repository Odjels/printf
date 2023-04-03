
#include "main.h"

/**
 * get_size - Calculates the size in which to cast the argument
 * @format: Formatted string to print the arguments
 * @t: List of arguments.
 *
 * Return: size (m)
 */
int get_size(const char *format, int *t)
{
	int bab_c = *t + 1;
	int m = 0;


	if (format[bab_c] == 'l')
		m = S_LONG;
	else if (format[bab_c] == 'h')
		m = S_SHORT;

	if (m == 0)
		*t = bab_c - 1;
	else
		*t = bab_c;

	return (m);

}
