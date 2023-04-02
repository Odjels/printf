#include "main.h"

/**
 * print_char - Prints a char
 * @types: List all the arguments
 * @buffer: Buffer arrays to handle print
 * @flags:  Calculates the active flags
 * @width: Width
 * @precision:  specification
 * @size: Size specifiers
 * Return: Numbers of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char a = va_arg(types, int);

	return (handle_write_char(a, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: List all the arguments
 * @buffer: Buffer arrays to handle print
 * @flags:  Calculates the active flags
 * @width:  width.
 * @precision: specification
 * @size: Size specifiers
 * Return: Numbers of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int leng = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[leng] != '\0')
		leng++;

	if (precision >= 0 && precision < leng)
		leng = precision;

	if (width > leng)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], leng);
			for (i = width - leng; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - leng; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], leng);
			return (width);
		}
	}

	return (write(1, str, leng));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: List all the arguments
 * @buffer: Buffer arrays to handle print
 * @flags:  Calculates the active flags
 * @width: get widths.
 * @precision: Precision specifications
 * @size: Size specifiers
 * Return: Numbers of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: List all the arguments
 * @buffer: Buffer arrays to handle print
 * @flags:  Calculates the active flags
 * @width: get widths.
 * @precision:  specification
 * @size: Size specifiers
 * Return: Numbers of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int c = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[c--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[c--] = (num % 10) + '0';
		num /= 10;
	}

	c++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints the unsigned number
 * @types: List all the  arguments
 * @buffer: Buffer arrays to handle print
 * @flags:  Calculates the active flags
 * @width: get width.
 * @precise: specification
 * @size: Size specifiers
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	(int flags, int width, int precision, int size)
{
	unsigned int n, m, b, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (b = 1; b < 32; b++)
	{
		m /= 2;
		a[b] = (n / m) % 2;
	}
	for (b = 0, sum = 0, count = 0; b < 32; b++)
	{
		sum += a[b];
		if (sum || b == 31)
		{
			char z = '0' + a[b];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}


