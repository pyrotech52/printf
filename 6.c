#include "main.h"

/**
 * get_size - gets the size of the arg
 * @format: formatted string
 * @x: parameter
 * Return: size
 */
int get_size(const char *format, int *x)
{
	int j = *x + 1;
	int size = 0;

	if (format[j] == 'l')
		size = _LONG;
	else if (format[j] == 'h')
		size = _SHORT;

	if (size == 0)
		*x = j - 1;
	else
		*x = j;

	return (size);
}
