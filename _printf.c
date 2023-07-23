#include "main.h"

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
	int ch_count = 0, i = 0, str_count;
	va_list args_ptr;

	va_start(args_ptr, format);
	if (!(format) || (format[i] == '\0' && !format[i + 1]))
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 's':
				str_count = print_str(args_ptr);
				ch_count += str_count;
				break;
			case 'c':
				putchar(va_arg(args_ptr, int));
				ch_count++;
				break;
			case '%':
				putchar('%');
				ch_count++;
				break;
			case 'd':
			case 'i':
				ch_count += print_int(va_arg(args_ptr, int));
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
	}
		format++;
	va_end(args_ptr);
	return (ch_count);
}

