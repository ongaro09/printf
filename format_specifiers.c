#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int write_char(int c);
int write_string(const char *str);
int write_integer(int num);

/**
 * write_char - Write a character.
 * @c: The character to write.
 *
 * Return: The number of characters written (1).
 */
int write_char(int c)
{
    char ch = c;

    write(1, &ch, 1);
    return (1);
}

/**
 * write_string - Write a string.
 * @str: The string to write.
 *
 * Return: The number of characters written.
 */
int write_string(const char *str)
{
    int len = 0;

    while (str[len] != '\0')
    {
   	 len++;
    }
    write(1, str, len);
    return (len);
}

/**
 * write_integer - Write an integer.
 * @num: The integer to write.
 *
 * Return: The number of characters written.
 */
int write_integer(int num)
{
    char *num_str = itoa(num);
    int length = 0;

    while (num_str[length] != '\0')
    {
   	 length++;
    }
    write(1, num_str, length);
    return (length);
}

/**
 * format_specifier - Process a format specifier.
 * @format: A pointer to the format specifier.
 * @args: The va_list of arguments.
 * @char_count: A pointer to the character count.
 *
 * Return: The number of characters written.
 */
int format_specifier(const char **format, va_list args, int *char_count)
{
    if (**format == 'c')
    {
   	 char c = va_arg(args, int);

   	 return (write_char(c));
    }
    else if (**format == 's')
    {
   	 char *str = va_arg(args, char *);

   	 return (write_string(str));
    }
    else if (**format == '%')
    {
   	 return (write_char('%'));
    }
    else if (**format == 'd' || **format == 'i')
    {
   	 int num = va_arg(args, int);

   	 return (write_integer(num));
    }
    else
    {
   	 write(1, "%", 1);
   	 write(1, *format, 1);
   	 *char_count += 2;
   	 return (2);
    }
}
