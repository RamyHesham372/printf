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
	int ch_count = 0;

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
		ch_count += print_int(args_ptr);
		break;
	case 'b':
		ch_count += print_binary(args_ptr);
		break;
	default:
		return (-1);
	}
	return (ch_count);
}

