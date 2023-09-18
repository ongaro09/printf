#ifndef MY_PRINTF_H
#define MY_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format, ...);
int print_char(int *char_count, char c);
int print_string(int *char_count, const char *str);

#endif
