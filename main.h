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

int print_int(int d);




#endif
