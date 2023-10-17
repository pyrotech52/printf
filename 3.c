#include "main.h"
/**
 * print_address - points memory addrress
 * @types: types
 * @buffer: array
 * @flags:  signal for functions
 * @width: gets the dimension
 * @precision: decimal [places
 * @size: sizes
 * Return:chtr_counts
 */
int print_address(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char x = 0, p = ' ';
	int y = buff - 2, l = 2, p_d = 1;
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[buff - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[y--] = map_to[num_address % 16];
		num_address /= 16;
		l++;
	}

	if ((flags & ZERO) && !(flags & NEGATIVE))
		p = '0';
	if (flags & POSITIVE)
		x = '+', l++;
	else if (flags & SPACE)
		x = ' ', l++;

	y++;

	return (pointerx(buffer, y, l, width, flags, p, x, p_d));
}

/**
 * print_noprintable - prints non printable characters in ascii
 * @types: types
 * @buffer: array
 * @flags:  signal of functions
 * @width: gets the dimension
 * @precision: decimals places
 * @size: sizes
 * Return: chr_counts
 */
int print_noprintable(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int x = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[x] != '\0')
	{
		if (is_printable(str[x]))
			buffer[x + offset] = str[x];
		else
			offset += append_hexa_code(str[x], buffer, x + offset);

		x++;
	}

	buffer[x + offset] = '\0';

	return (write(1, buffer, x + offset));
}

/**
 * print_inverse - Prints backward strings
 * @types: types
 * @buffer: array
 * @flags:  signal for functions
 * @width: gets the dimension
 * @precision: decimals places
 * @size: size
 * Return: Numbers of characterss printed
 */

int print_inverse(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char *str;
	int x, y = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (x = 0; str[x]; x++)
		;

	for (x = x - 1; x >= 0; x--)
	{
		char z = str[x];

		write(1, &z, 1);
		y++;
	}
	return (y);
}
/**
 * print_rot13strings -  rot13 strings
 * @types: types
 * @buffer: arrays
 * @flags:  signals for function
 * @width: get dimension
 * @precision: decimal places
 * @size: sizes
 * Return: Numbers of charaters printed
 */
int print_rot13strings(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int a, b;
	int y = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (a = 0; str[a]; a++)
	{
		for (b = 0; in[b]; b++)
		{
			if (in[b] == str[a])
			{
				x = out[b];
				write(1, &x, 1);
				y++;
				break;
			}
		}
		if (!in[b])
		{
			x = str[a];
			write(1, &x, 1);
			y++;
		}
	}
	return (y);
}
