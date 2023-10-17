#include "main.h"
/**
 * handle_print - argument types
 * @fmt: dtring
 * @list: list
 * @ind: indeterminate number
 * @buffer: arrays
 * @flags: arrays
 * @width: dimension
 * @precision: decimals places
 * @size: sizes
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int x, ln = 0, _char = -1;
	fmt_t fmt_types[] = {
		{'c', print_c}, {'s', print_s}, {'%', print_percentage},
		{'i', print_d}, {'d', print_d}, {'b', print_base_2},
		{'u', print_unsigned}, {'o', print_base_8}, {'x', print_base_10},
		{'X', print_hexa_uppercase}, {'p', print_address}, {'S', print_noprintable},
		{'r', print_inverse}, {'R', print_rot13strings}, {'\0', NULL}
	};
	for (x = 0; fmt_types[x].fmt != '\0'; x++)
		if (fmt[*ind] == fmt_types[x].fmt)
			return (fmt_types[x].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[x].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		ln += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			ln += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		ln += write(1, &fmt[*ind], 1);
		return (ln);
	}
	return (_char);
}
