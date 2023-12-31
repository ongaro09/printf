#include <stdio.h>

/**
 * itoa - Converts an integer to a null-terminated string.
 * @num: The integer to convert.
 *
 * Return: A pointer to the resulting string.
 */

char *itoa(int num)
{
	int i, j;
	static char buf[12];

	int length = 0;
	int is_negative = 0;

	if (num == -2147483648)
	{
		return ("-2147483648");
	}
	else if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	i = length;
	do {
		buf[length++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	if (is_negative)
	{
		buf[length++] = '-';
	}

	for (j = i; j < length / 2; j++)
	{
		char temp = buf[j];

		buf[j] = buf[length - j - 1];
		buf[length - j - 1] = temp;
	}
	buf[length] = '\0';
	return (buf);
}
