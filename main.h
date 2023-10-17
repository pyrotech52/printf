#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#define buff 1024
#define minus 1
#define UNUSED(x) (void)(x)
int _printf(const char *format, ...);
void print__buffer(char buffer[], int *buffers);
int get_flags(const char *format, int *x);
int get_width(const char *format, int *x, va_list clist);
int get_precision(const char *format, int *x, va_list clist);
int get_size(const char *format, int *x);
int print_c(va_list types, char buffer[], int width, int precision, int size, int flags);
int print_s(va_list types, char buffer[], int width, int precision, int size, int flags);
int print_percent(va_list types, char buffer[], int width, int precision, int size    , int flags);
int print_d(va_list types, char buffer[], int width, int precision, int size, int flags);
int print_binary(va_list types, char buffer[], int width, int precision, int size, int flags);
int chr_count(char x, char buffer[], int width, int precision, int size, int flags);
int numbers(int y, int  x, char buffer[], int  width, int size, int precisions, int flags);
#endif
