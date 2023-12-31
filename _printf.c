#include "main.h"

/**
 * _printf - function that produces output according
 *      to 3 specifiers c, s, %
 *
 * @format: char string which contain specifier
 *   and different chars
 *
 * Return: number of chars print on screen
 */
int _printf(const char *format, ...)
{
	int ch_count = 0, i = 0;
	va_list args_ptr;

	va_start(args_ptr, format);
	if (!(format) || (format[i] == '\0' && !format[i + 1]))
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ch_count += handle_specifiers(args_ptr, format);
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
