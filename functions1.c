#include "main.h"

/**
 * handle_specifiers - function that
 * handles specifiers.
 *
 * @args_ptr: list of arguements
 * @format: the character
 *
 * Return: the counter
 */
int handle_specifiers(va_list args_ptr, const char *format)
{
	int ch_count = 0, num;

	if (*format == ' ' || *format == '\0')
		return (-1);
	switch (*format)
	{
	case 's':
		ch_count += print_str(args_ptr);
		break;
	case 'c':
		ch_count += print_char(args_ptr);
		break;
	case '%':
		ch_count += print_mod(args_ptr);
		break;
	case 'd':
	case 'i':
		num = va_arg(args_ptr, int);
		if (num < 0)
			ch_count++;
		ch_count += len_num(num);
		print_int(num);
		break;
	case 'b':
		ch_count += print_binary(args_ptr);
		break;
	case 'r':
		ch_count += print_reverse(args_ptr);
		break;
	case 'R':
		ch_count += print_rot(args_ptr);
		break;
	default:
		ch_count += putchar('%');
		ch_count += putchar(*format);
		break;
	}
	return (ch_count);
}

/**
 * print_reverse - function that reverse string
 *
 * @ap: pointer to arguements
 *
 * Return: the counter
 */
int print_reverse(va_list ap)
{
	int count = 0, len, i;
	char *str_null = "(llun)", *str;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		while (*str_null)
		{
			putchar(*str_null);
			count++;
			str_null++;
		}
		return (count);
	}

	for (len = 0; str[len] != '\0'; len++)
		;
	for (i = len - 1; i >= 0; i--)
	{
		putchar(str[i]);
		count++;
	}
	return (count);
}

/**
 * print_rot - function that use rot13
 *
 * @ap: pointer to arguements
 *
 * Return: the counter
 */
int print_rot(va_list ap)
{
	int i, e, count = 0;
	char *null_str = "(avyy)";
	char *str;
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

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
	else
	{
		for (i = 0; *(str + i) != '\0'; i++)
		{
			for (e = 0; e < 52; e++)
			{
				if (str[i] == alphabet[e])
				{
					putchar(rot[e]);
					count++;
					break;
				}
			}
			if (e == 52)
			{
				putchar(*(str + i));
				count++;
			}
		}
	}
	return (count);
}

/**
 * len_num - function that prints numbers.
 *
 * @num: int number.
 *
 * Return: number.
 */

int len_num(int num)
{
	if (num == 0)
	{
		return (0);
	}
	else
	{
		return (1 + len_num(num / 10));
	}
}

