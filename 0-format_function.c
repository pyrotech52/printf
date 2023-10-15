#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 * @format: counts the number of variable arguments
 * Return: chr_count
 */

int _printf(const char *format, ...);
{
	int chr_count = 0;
	va_list clist;

	if (format == NULL)
		return (-1);

	va_start(clist, format);

	while (*format)
	{
		if (*format != "%")
		{
			write(1, format, 1);
				chr_count++;
		}
		else
		{
			format++;

			if (*format == "\0")
				break;

			if (*format == "%")
			{
				write(1, format, 1);
				chr_count++;
			}
			else if (*format == "c")
			{
				char c = va_arg(clist, int);

				write(1, &c, 1);
				chr_count++;
			}
			else if (*format == "s")
			{
				char *str = va_arg(clist, char*);
				int str_len = 0;

				while (str[str_len] != "\0")
					str_len++;

				write(1, str, str_len);
				chr_count += str_len;
			}
		}
		format++;
	}
	va_end(clist);
	return (chr_count);
}
