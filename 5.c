#include "main.h"

/**
 * get_precision - gets the decimals [laces of a float
 * @format: formatted string
 * @x: parameters
 * @list: lists
 * Return: precision
 */
int get_precision(const char *format, int *x, va_list list)
{
	int j = *x + 1;
	int precision = -1;

	if (format[j] != '.')
		return (precision);

	precision = 0;

	for (j += 1; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
		{
			precision *= 10;
			precision += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*x = j - 1;

	return (precision);
}
