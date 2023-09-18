#include <unistd.h>



char *itoa(int num);

/**
 * print_char - Print a character.
 * @char_count: A pointer to the character count.
 * @c: The character to print.
 */
void print_char(int *char_count, char c)
{
	write(1, &c, 1);
	(*char_count)++;
}

/**
 * print_string - Print a string.
 * @char_count: A pointer to the character count.
 * @str: The string to print.
 */
void print_string(int *char_count, char *str)
{
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	write(1, str, len);
	(*char_count) += len;
}

/**
 * print_int - Print an integer.
 * @char_count: A pointer to the character count.
 * @num: The integer to print.
 */
void print_int(int *char_count, int num)
{
	char *num_str = itoa(num);
	int length = 0;
	while (num_str[length] != '\0')
	{
		length++;
	}

	write(1, num_str, length);
	(*char_count) += length;
}
