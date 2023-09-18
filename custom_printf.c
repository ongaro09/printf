#include <unistd.h>
#include <stdarg.h>
#include "main.h"

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
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				char_count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);
				if (str)
				{
					int len = 0;
					while (str[len] != '\0')
					{
						len++;
					}
					write(1, str, len);
					char_count += len;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				char_count++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				char *num_str = itoa(num);
				int length = 0;
				while (num_str[length] != '\0')
				{
					length++;
				}
				write(1, num_str, length);
				char_count += length;
			}
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				char_count += 2;
			}
		}
		else
		{
			write(1, format, 1);
			char_count++;
		}
		format++;
	}

	va_end(args);
	return char_count;
}
