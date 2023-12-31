#ifndef _MAIN_H_
#define _MAIN_H_


#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

/*prototypes*/
int _printf(const char *format, ...);
int print_str(va_list ap);
int print_char(va_list ap);
int print_mod(va_list ap);
int print_int(int d);
int print_binary(va_list ap);
int handle_specifiers(va_list args_ptr, const char *format);
int len_num(int num);
int print_reverse(va_list ap);
int print_rot(va_list ap);

#endif

