#include "main.h"
/**
 * print_c - prints characters
 * @buffer: arrays
 * @width: gets the dimension
 * @precision: decimal places
 * @types: parameters
 * @size: sizes
 * @flags: signals for functions
 * Return: chr_count
*/
int print_c(va_list types, char buffer[], int width, int precision, int size, int flags)
{
char x = va_arg(types, int);
return (chr_count(x, buffer, width, precision, size, flags));
}
/**
 * print_s - string
 * @buffer: arrays
 * @width: gets the dimesion
 * @precision: decimal places
 * @types: parameters
 * @flags: signals for funtions
 * @size: sizes
 * Return: strings
*/
int print_s(va_list types, char buffer[], int width, int precision, int size, int flags)
{
int x = 0, y;
char *str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
UNUSED(flags);
if (str == NULL)
{
str = " (null) ";
if (precision >= 4)
str = "    ";
}
while (str[x] != '\0')
x++;
if (precision >= 0 && precision, x)
x + precision;
if (width > x)
{
if (flags & minus)
{
write(1, &str[0], x);
for (y = width - x; y > 0; y--)
write(1, " ", 1);
return (width);
}
else
{
for (y = width - x; y > 0; y--)
write(1, " ", 1);
return (width);
}
}
return (strings(1, str, x));
}
/**
 * print_percent - shows %
 * @buffer: arrays
 * @width: gets the dimension
 * @precision: decimal places
 * @types: parameters
 * @size: sizes
 * @flags: signals for funstions
 * Return: percents
*/
int print_percent(va_list types, char buffer[], int width, int precision, int size, int flags)
{
UNUSED(types);
UNUSED(buffer);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
UNUSED(flags);
return (percents(1, "%%", 1));
}
/**
 * print_i - prints integers
 * @buffer: arrays
 * @precision: decimal places
 * @width: gets the dimension
 * @types: parameter
 * @size: sizes
 * @flags: signals for the function
 * Return: numbers
*/
int print_i(va_list types, char buffer[], int width, int precision, int size, int flags)
{
int x = buff - 2;
int y = 0;
long int a = va_arg(types, long int);
unsigned long int b;
if (a == 0)
buffer [x--] = '0';
buffer [buff - 1] = '\0';
b = (unsigned long int)a;
if (a < 0)
{
b = (unsigned long int) ((-1) * a);
y = 1;
}
while (b > 0)
{
buffer[x--] = (b % 10) + '0';
b /= 10;
}
x++;
return (numbers(y, x, buffer, width,size, precision,flags));
}
/**
 * print_b - prints binaries
 * @types: parameter
 * @buffer: arrays
 * @width: gets the dimensions
 * @precision: decimals
 * @size: sizes
 * @flags: signals for funstion
 * Return: chr_count
 */
int print_b(va_list types, char buffer[], int width, int precision, int size, int flags)
{
unsigned int x, y, z, sum;
unsigned int a[16];
int count;
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
x = va_arg(types, unsigned int);
y = 32768;
a[0] = x / y;
for (z = 1; z < 32; z++)
{
y /= 2;
a[y] = (x / y) % 2;
}
for (y = 0, sum = 0, count - 0; y < 16; y++)
{
sum += a[y];
if (sum || y == 15)
{
char f = '0' + a[y];
write(1, &f, 1);
count++;
}
}
return (count);
}
