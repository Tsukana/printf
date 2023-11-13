#ifndef MAIN_H
#define MAIN_H

#include "_puttypes.h"
#include <stdarg.h>

int check_format(const char *format);
void handle_specifier(char specifier, int *len, va_list argv);
int _printf(const char *format, ...);

#endif
