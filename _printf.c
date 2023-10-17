#include "main.h"

void print_buffer(char buffer[], int *index_buffer);

/**
 * _printf - my custom printf
 * @format: formatted str
 * Return: chars
 */
int _printf(const char *format, ...)
{
	int x, p = 0, p_c = 0;
	int flags, width, precision, size, index_buffer = 0;
	va_list list;
	char buffer[buff];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[index_buffer++] = format[x];
			if (index_buffer == buff)
				print_buffer(buffer, &index_buffer);
			p_c++;
		}
		else
		{
			print_buffer(buffer, &index_buffer);
			flags = get_flags(format, &x);
			width = get_width(format, &x, list);
			precision = get_precision(format, &x, list);
			size = get_size(format, &x);
			++x;
			p = handle_print(format, &x, list, buffer,
				flags, width, precision, size);
			if (p == -1)
				return (-1);
			p_c += p;
		}
	}

	print_buffer(buffer, &index_buffer);

	va_end(list);

	return (p_c);
}

/**
 * print_buffer - shows the buffer
 * @buffer: array
 * @index_buffer:index
 */
void print_buffer(char buffer[], int *index_buffer)
{
	if (*index_buffer > 0)
		write(1, &buffer[0], *index_buffer);

	*index_buffer = 0;
}
