#include "main.h"

/**
 * print_unsigned - positive numbers
 * @types: type
 * @buffer: array
 * @flags:  signal for functions
 * @width: get the dimension
 * @precision: decimal places
 * @size: sizes
 * Return: chr_count
 */
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int x = buff - 2;
	unsigned long int y = va_arg(types, unsigned long int);

	y = convert_unsignd(y, size);

	if (y == 0)
		buffer[x--] = '0';

	buffer[buff - 1] = '\0';

	while (y > 0)
	{
		buffer[x--] = (y % 10) + '0';
		y /= 10;
	}

	x++;

	return (unsignd(0, x, buffer, flags, width, precision, size));
}

/**
 * print_base_8 - Prints base 8 numbers
 * @types: types
 * @buffer: aarray
 * @flags:  signal for funstions
 * @width: gets the dimesion
 * @precision: decimal places
 * @size: sizes
 * Return: chr_count
 */
int print_base_8(va_list types, char buffer[], int flags, int width, int precision, int size)
{

	int x = buff - 2;
	unsigned long int y = va_arg(types, unsigned long int);
	unsigned long int init_num = y;

	UNUSED(width);

	y = convert_unsignd(y, size);

	if (y == 0)
		buffer[x--] = '0';

	buffer[buff - 1] = '\0';

	while (y > 0)
	{
		buffer[x--] = (y % 8) + '0';
		y /= 8;
	}

	if (flags & HASH && init_num != 0)
		buffer[x--] = '0';

	x++;

	return (unsignd(0, x, buffer, flags, width, precision, size));
}

/**
 * print_base_10 - prints base 10 numbers
 * @types: types
 * @buffer: arrays
 * @flags:  signal gor functions
 * @width: gets the dimension
 * @precision: decimals places
 * @size: sizes
 * Return: chr_counts
 */
int print_base_10(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_uppercase - Prints CAPS
 * @types: types
 * @buffer: array
 * @flags:  signal for functions
 * @width: gets the dimensions
 * @precision: decimal places
 * @size: sizes
 * Return: chr_counts
 */
int print_hexa_uppercase(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
/**
 * print_hexa - Prints base 10 numbers in lower or upper cases
 * @types: arrays
 * @map_to: arrays
 * @buffer: arrays
 * @flags:  signal for funstions
 * @flag_ch: signal for funcstions
 * @width: gets the dimension
 * @precision: decimal places
 * @size: sizes
 * Return: chr_counts
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size)
{
	int x = buff - 2;
	unsigned long int y = va_arg(types, unsigned long int);
	unsigned long int init_num = y;

	UNUSED(width);

	y = convert_unsignd(y, size);

	if (y == 0)
		buffer[x--] = '0';

	buffer[buff - 1] = '\0';

	while (y > 0)
	{
		buffer[x--] = map_to[y % 16];
		y /= 16;
	}

	if (flags & HASH && init_num != 0)
	{
		buffer[x--] = flag_ch;
		buffer[x--] = '0';
	}

	x++;

	return (unsignd(0, x, buffer, flags, width, precision, size));
}

