#include "main.h"

/**
 * get_width - getys the dimension
 * @format: formatted string
 * @x: parameter
 * @list: list of arguments.
 * Return: width.
 */
int get_width(const char *format, int *x, va_list list)
{
	int j;
	int width = 0;

	for (j = *x + 1; format[j] != '\0'; j++)
	{
		if (is_digit(format[j]))
		{
			width *= 10;
			width += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*x = j - 1;

	return (width);
}
