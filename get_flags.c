#include "main.h"

/**
 * get_flags - Calculates actual flags
 * @format: Formatted string in which to print the arguments
 * @i: parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int k, bab_c;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (bab_c = *i + 1; format[bab_c] != '\0'; bab_c++)
	{
		for (k = 0; FLAGS_CH[j] != '\0'; k++)
			if (format[bab_c] == FLAGS_CH[k])
			{
				flags |= FLAGS_ARR[k];
				break;
			}

		if (FLAGS_CH[k] == 0)
			break;
	}

	*i = bab_c - 1;

	return (flags);
}

