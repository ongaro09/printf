#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...);

int format_specifier(const char **format, va_list args, int *char_count);

/**
 * _printf - Custom printf function.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    int char_count = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
   	 if (*format == '%')
   	 {
   		 format++;
   		 if (*format == '\0')
   		 {
   			 break;
   		 }
   		 char_count += format_specifier(&format, args, &char_count);
   	 }
   	 else
   	 {
   		 write(1, format, 1);
   		 char_count++;
   	 }
   	 format++;
    }

    va_end(args);
    return (char_count);
}
