#include <unistd.h>
#include "main.h"

/**
 * print_char - Print a character.
 * @c: The character to print.
 *
 * Return: The number of characters printed (1).
 */
int print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - Print a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int print_string(const char *str)
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
 * print_int - Print an integer.
 * @num: The integer to print.
 *
 * Return: The number of characters printed.
 */
int print_int(int num)
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
