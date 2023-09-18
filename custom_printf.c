#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

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
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				char_count++;
			}
			else if
				(*format == 's')
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
					}
				}
			else if (*format == '%')
			{
				write(1, "%", 1);
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
	return (char_count);
}
