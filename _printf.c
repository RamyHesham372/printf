#include "main.h"
int print_str(va_list ap);

/**
 * _printf - function that produces output accroding
 *      to 3 specifiers c, s, %
 *
 * @format: char string which contain specifier
 *   and different chars
 *
 * Return: number of chars print on screen
 */
int _printf(const char *format, ...)
{
	int ch_count = 0;
	int str_count;
	va_list args_ptr;

	va_start(args_ptr, format);
	if (!(format))
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 's':
						str = print_str(args_ptr);
						ch_count += str;
						break;
				case 'c':
						putchar(va_arg(args_ptr, int));
						ch_count++;
						break;
				case '%':
						putchar('%');
						ch_count++;
						break;
				default:
						return (-1);
			}
		}
		else
		{
			putchar(*format);
			ch_count++;
		}
		format++;
	}
	va_end(args_ptr);
	return (ch_count);
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

	str = va_arg(ap, char *);
	if (!(str))
		fputs("(null)", stdout);
	while (*str)
	{
		putchar(*str);
		count++;
		str++;
	}
	return (count);
}
