#include "main.h"

/**
 * print_int - function that prints numbers.
 *
 * @d: list of arguements
 *
 * Return: numbers to print on screen
 */

int print_int(int d)
{
	int char_count = 0;

	if (d < 0)
	{
		char_count += putchar('-');
		d = -d;
	}
	else
	{
		char_count += len_num(d);
	}

	if (d == -2147483648)
	{
		char_count += 1;
		putchar('2');
		print_int(147483648);
		return (char_count);
	}
	else if (d < 0)
	{
		putchar('-');
		char_count++;
		d = -d;
	}

	if (d >= 10)
	{
		print_int(d / 10);
		print_int(d % 10);
	}
	else if (d < 10)
	{
		putchar(d + '0');
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

/**
 * print_char - function that print char
 *
 * @ap: list of arguements
 *
 * Return: number of chars print on screen
 */
int print_char(va_list ap)
{
	int c;

	c = va_arg(ap, int);
	putchar(c);
	return (1);
}

/**
 * print_mod - function that print %
 *
 * @ap: list of arguements
 *
 * Return: number of chars print on screen
 */
int print_mod(va_list ap)
{
	ap = ap;
	putchar('%');
	return (1);
}

/**
 * print_binary - function that prints the binary of number
 *
 * @ap: list of arguements
 *
 * Return: number of numbers print on screen
 */
int print_binary(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
	int binary[32], i = 0, count = 0, j = 0;

	while (num > 0)
	{
		binary[i] = num % 2;
		num /= 2;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		if (binary[j] == 0)
		{
			putchar('0');
			count++;
		}
		else
		{
			putchar('1');
			count++;
		}
	}
	return (count);
}
