#include "main.h"

/**
 * print_int - function that prints numbers.
 *
 * @d: the number that will be given.
 *
 * Return: the size of the whole number.
 */
int print_int(int d)
{
	int i = 0, char_count = 0;
	char buffer[20];

	if (d == 0)
	{
		char_count += putchar('0');
		i++;
	}

	if (d < 0)
	{
		char_count += putchar('-');
		d = -d;
	}

	if (d > 0)
	{
		while (d > 0)
		{
			buffer[i++] = (d % 10) + '0';
			d /= 10;
		}

		while (i > 0)
		{
			char_count += putchar(buffer[--i]);
		}
	}
	return (char_count);
}

/**
 * print_str - function that print string
 *
 * @ap: list of arguements
 *
 * Return: number of chars print on screen
 */
int print_str(va_list ap)
{
	int count = 0;
	char *str;
	char *null_str = "(null)";

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		while (*null_str)
		{
			putchar(*null_str);
			count++;
			null_str++;
		}
		return (count);
	}
	while (*str)
	{
		putchar(*str);
		count++;
		str++;
	}
	return (count);
}

