#include "main.h"

/**
 * is_printable - checks if a character can be printed or not
 * @c: parameter
 * Return: 1 if yes else 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - combined the header code
 * @buffer: array
 * @x: parameter
 * @ascii_code: ascii codes
 * Return: 1
 */
int append_hexa_code(char ascii_code, char buffer[], int x)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[x++] = '\\';
	buffer[x++] = 'x';

	buffer[x++] = map_to[ascii_code / 16];
	buffer[x] = map_to[ascii_code % 16];

	return (1);
}

/**
 * is_digit - verifies if a values is an ints or not
 * @c: parameter
 * Return: 1 if yes else 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_number - converts number
 * @x: parameter
 * @size: sizes
 * Return: value
 */
long int convert_number(long int x, int size)
{
	if (size == _LONG)
		return (x);
	else if (size == _SHORT)
		return ((short)x);

	return ((int)x);
}

/**
 * convert_unsignd - unsigned numbers
 * @x: parameter
 * @size: size
 * Return: value
 */
long int convert_unsignd(unsigned long int x, int size)
{
	if (size == _LONG)
		return (x);
	else if (size == _SHORT)
		return ((unsigned short)x);

	return ((unsigned int)x);
}
