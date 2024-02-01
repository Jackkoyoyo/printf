#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int print_out(const char *format, va_list ap);
int _putchar(int c);
int print_string(const char *str);

#endif /*_MAIN_H_*/
