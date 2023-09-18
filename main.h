#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
char *itoa(int num);
int print_char(char c);
int print_string(const char *str);
int print_int(int num);
int write_char(int c);
int write_string(const char *str);
int write_integer(int num);
int format_specifier(const char **format, va_list args, int *char_count);

#endif
