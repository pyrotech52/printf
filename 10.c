#include "main.h"
/**
 * write_c - writes a char
 * @c: paramter
 * @buffer: arrays
 * @flags:  signal to the function
 * @width: gets the dimesion
 * @precision: decimal places
 * @size: sizes
 * Return: char_count
 */
int write_c(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = 0;
	char p = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & ZERO)
		p = '0';

	buffer[x++] = c;
	buffer[x] = '\0';

	if (width > 1)
	{
		buffer[buff - 1] = '\0';
		for (x = 0; x < width - 1; x++)
			buffer[buff - x - 2] = p;

		if (flags & NEGATIVE)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[buff - x - 1], width - 1));
		else
			return (write(1, &buffer[buff - x - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
/**
 * number - prints integers
 * @is_negative: parameter
 * @ind: indeterminate number
 * @buffer: array
 * @flags:  signals
 * @width: get dimensions
 * @precision: decimals places
 * @size: sizes
 * Return: number
 */
int number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = buff - ind - 1;
	char p = ' ', y = 0;

	UNUSED(size);

	if ((flags & ZERO) && !(flags & NEGATIVE))
		p = '0';
	if (is_negative)
		y = '-';
	else if (flags & POSITIVE)
		y = '+';
	else if (flags & SPACE)
		y = ' ';

	return (numx(ind, buffer, flags, width, precision,
		x, p, y));
}

/**
 * numx - write a number
 * @ind: index
 * @buffer: array
 * @flags: signals for function
 * @width: gets the dimension
 * @prec: decimals
 * @l:length of character
 * @padd: Pading char
 * @extra_c: extra characters
 * Return: chr_counts
 */
int numx(int ind, char buffer[],
	int flags, int width, int prec,
	int l, char padd, char extra_c)
{
	int x, p_start = 1;

	if (prec == 0 && ind == buff - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == buff - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prec > 0 && prec < l)
		padd = ' ';
	while (prec > l)
		buffer[--ind] = '0', l++;
	if (extra_c != 0)
		l++;
	if (width > l)
	{
		for (x = 1; x < width - l + 1; x++)
			buffer[x] = padd;
		buffer[x] = '\0';
		if (flags & NEGATIVE && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], l) + write(1, &buffer[1], x - 1));
		}
		else if (!(flags & NEGATIVE) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], x - 1) + write(1, &buffer[ind], l));
		}
		else if (!(flags & NEGATIVE) && padd == '0')
		{
			if (extra_c)
				buffer[--p_start] = extra_c;
			return (write(1, &buffer[p_start], x - p_start) +
				write(1, &buffer[ind], l - (1 - p_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], l));
}

/**
 * unsignd - postive and negatice numbers
 * @is_negative: parameter
 * @ind: indeterminates
 * @buffer: arrays
 * @flags: signals for function
 * @width: gets the dimension
 * @precision: decimals
 * @size: sizesr
 * Return: 0
 */
int unsignd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int l = buff - ind - 1, x = 0;
	char p = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == buff - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < l)
		p = ' ';

	while (precision > l)
	{
		buffer[--ind] = '0';
		l++;
	}

	if ((flags & ZERO) && !(flags & NEGATIVE))
		p = '0';

	if (width > l)
	{
		for (x = 0; x < width - l; x++)
			buffer[x] = p;

		buffer[x] = '\0';

		if (flags & NEGATIVE)
{
			return (write(1, &buffer[ind], l) + write(1, &buffer[0], x));
		}
		else
		{
			return (write(1, &buffer[0], x) + write(1, &buffer[ind], l));
		}
	}

	return (write(1, &buffer[ind], l));
}

/**
 * pointerx - memory address
 * @buffer: arrays
 * @ind: indeterminste
 * @length: Length of number
 * @width: dimensions
 * @flags: parameter
 * @p: parameter
 * @z:  extra char
 * @p_start: start padd
 * Return: characters
 */
int pointerx(char buffer[], int ind, int length,
	int width, int flags, char p, char z, int p_start)
{
	int x;

	if (width > length)
	{
		for (x = 3; x < width - length + 3; x++)
			buffer[x] = p;
		buffer[x] = '\0';
		if (flags & NEGATIVE && p == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (z)
				buffer[--ind] = z;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], x - 3));
		}
		else if (!(flags & NEGATIVE) && p == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (z)
				buffer[--ind] = z;
			return (write(1, &buffer[3], x - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & NEGATIVE) && p == '0')
		{
			if (z)
				buffer[--p_start] = z;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[p_start], x - p_start) +
				write(1, &buffer[ind], length - (1 - p_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (z)
		buffer[--ind] = z;
	return (write(1, &buffer[ind], buff - ind - 1));
}
