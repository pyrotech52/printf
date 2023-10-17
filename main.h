#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define buff 1024

#define NEGATIVE 1
#define POSITIVE 2
#define ZERO 4
#define HASH 8
#define SPACE 16

#define _LONG 2
#define _SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

int print_c(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_s(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_percentage(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_d(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_base_2(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],int flags, int width, int precision, int size);
int print_base_8(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_base_10(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa_uppercase(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_noprintable(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_address(va_list types, char buffer[], int flags, int width, int precision, int size);
int get_flags(const char *format, int *x);
int get_width(const char *format, int *x, va_list list);
int get_precision(const char *format, int *x, va_list list);
int get_size(const char *format, int *x);
int print_inverse(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_rot13strings(va_list types, char buffer[], int flags, int width, int precision, int size);
int write_c(char c, char buffer[], int flags, int width, int precision, int size);
int number(int pluss, int ind, char buffer[], int flags, int width, int precision, int size);
int numx(int ind, char bff[], int flags, int width, int precision, int length, char padd, char extra_c);
int pointerx(char buffer[], int ind, int length, int width, int flags, char padd, char extra_c, int padd_start);
int unsignd(int minuss, int ind,
char buffer[], int flags, int width, int precision, int size);
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_number(long int num, int size);
long int convert_unsignd(unsigned long int num, int size);
#endif


