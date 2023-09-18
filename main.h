#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <unistd.h>

int _printf(const char *format, ...);
char *itoa(int num);
void print_char(int *char_count, char c);
void print_string(int *char_count, char *str);
void print_int(int *char_count, int num);
int write_char(int c);
int write_string(const char *str);
int write_integer(int num);
int format_specifier(const char **format, va_list args, int *char_count);

#endif
