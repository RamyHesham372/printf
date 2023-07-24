#include "main.h"

/**
 * print_int - function that prints numbers.
 *
 * @ap: list of arguements
 *
 * Return: number of chars print on screen
 */
int print_int(va_list ap)
{
	int i = 0, char_count = 0;
	char buffer[20];
	int d;

	d = va_arg(ap, int); /* get the int value of the argument */

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

	c = va_arg(ap, int); /* get the int value of the char argument */
	putchar(c);			 /* print it as a char */
	return (1);			 /* return 1 because only one char is printed */
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
	ap = ap;	  /* unused parameter */
	putchar('%'); /* print % as it is */
	return (1);	  /* return 1 because only one char is printed */
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
