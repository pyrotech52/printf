#include "main.h"
void print_buffer(char buffer[], int *buffers);
/**
 * _printf - my custom printf
 * @format: parameter
 * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
int x, chr = 0, chr_count = 0;
int flags, width, precision, size, buffers = 0;
va_list clist;
char buffer[buff];
if (format == NULL)
return (-1);
va_start(clist, format);
for (x = 0; format && format[x] != '\0'; x++)
{
if (format[x] != '%')
{
buffer[buffers++] = format[x];
if (buffers == buff)
print_buffer(buffer, &buffers);
chr_count++;
}
else
{
print_buffer(buffer, &buffers);
flags = get_flags(format, &x);
width = get_width(format, &x, clist);
precision = get_precision(format, &x, clist);
size = get_size(format, &x);
++x;
chr = print_types(format, &x, clist, buffer, flags, width, precision, size);
if (chr == -1)
return (-1);
chr_count += chr;
}
}
print_buffer(buffer, &buffers);
va_end(clist);
return (chr_count);
}
/**
 *print_buffer - view buffer
 * @buffer: parameter
 * @buffers: parameter
*/
void print_buffer(char buffer[], int *buffers)
{
if (*buffers > 0)
write(1, &buffer[0], *buffers);
*buffers = 0;
}
