#include "main.h"

/**
 * print_c - prints character
 * @types: types
 * @buffer: arrays
 * @flags:  checks for acyive flags
 * @width: gets the dimesion
 * @precision: decimal places
 * @size: sizes
 * Return: nos
 */
int print_c(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (write_c(c, buffer, flags, width, precision, size));
}
/**
 * print_s - Prints a string
 * @types: types
 * @buffer: arrays
 * @flags:  checks for active flags
 * @width: get the dimension
 * @precision: decimal places
 * @size: sizes
 * Return: nos
 */
int print_s(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int l = 0, x;
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

	while (str[l] != '\0')
		l++;

	if (precision >= 0 && precision < l)
		l = precision;

	if (width > l)
	{
		if (flags & NEGATIVE)
		{
			write(1, &str[0], l);
			for (x = width - l; x > 0; x--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (x = width - l; x > 0; x--)
				write(1, " ", 1);
			write(1, &str[0], l);
			return (width);
		}
	}

	return (write(1, str, l));
}
/**
 * print_percentage - Prints a percent sign
 * @types: types
 * @buffer: array
 * @flags:  checks for  active flags
 * @width: get the dimensions.
 * @precision: decimal places
 * @size: sizes
 * Return: nos
 */
int print_percentage(va_list types, char buffer[],
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

/**
 * print_d - Print integers
 * @types: types
 * @buffer: arrays
 * @flags:  checks for active flags
 * @width: gets the dimension
 * @precision: decimal places
 * @size: sizes
 * Return: nos
 */
int print_d(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int x = buff - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int y;

	n = convert_number(n, size);

	if (n == 0)
		buffer[x--] = '0';

	buffer[buff - 1] = '\0';
	y = (unsigned long int)n;

	if (n < 0)
	{
		y = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (y > 0)
	{
		buffer[x--] = (y % 10) + '0';
		y /= 10;
	}

	x++;

	return (number(is_negative, x, buffer, flags, width, precision, size));
}

/**
 * print_base_2 - Prints an base 2 numbers
 * @types: types
 * @buffer: array
 * @flags:  checks active flags
 * @width: get the dimension
 * @precision: decimal places
 * @size: size
 * Return: nos
 */
int print_base_2(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int x, y, z, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(types, unsigned int);
	y = 2147483648;
	a[0] = x / y;
	for (z = 1; z < 32; z++)
	{
		y /= 2;
		a[x] = (x / y) % 2;
	}
	for (z = 0, sum = 0, count = 0; z < 32; z++)
	{
		sum += a[z];
		if (sum || z == 31)
		{
			char b = '0' + a[z];

			write(1, &b, 1);
			count++;
		}
	}
	return (count);
}
