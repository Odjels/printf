
#include "main.h"

/**
 * get_size - Calculates the size in which to cast the argument
 * @format: Formatted string to print the arguments
 * @i: List of arguments.
 *
 * Return: size (s)
 */
int get_size(const char *format, int *i)
{
	int bab_c = *i + 1;
	int s = 0;


	if (format[bab_c] == 'l')
		s = S_LONG;
	else if (format[bab_c] == 'h')
		s = S_SHORT;

	if (s == 0)
		*i = bab_c - 1;
	else
		*i = bab_c;

	return (s);

}

