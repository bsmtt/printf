
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct specifier_handler - matched conversion specifier of string.
 * @specifier: type of conversion specifier.
 * @handler: pointer to function to handle selected type.
 *
 */
typedef struct specifier_handler
{
char *specifier;
int (*handler)();
} specifier_handler;

/**
 * struct flag_t - matched conversion specifier of string.
 * @plus: flag
 * @space: flag
 * @hash: flag
 * @h: flag
 * @l: flag
 * @precision: flag
 * @width: flag
 * @zero: flag
 * @minus: flag
 * @reverse: flag
 * @rotate: flag
 * @upperHex: flag
 * @negative: flag
 */
typedef struct flag_t
{
int plus;
int space;
int hash;
int h;
int l;
int precision;
int width;
int zero;
int minus;
int reverse;
int rotate;
int upperHex;
int negative;
} flag_t;

int _printf(const char *format, ...);
int _putchar(char c);
int get_specifier_handler(const char *format, va_list *args, flag_t *flags);
void _write_buffer(char c);
int print_number(va_list *args, flag_t *flags);
int print_unsigned_number(va_list *args, flag_t *flags);
int print_string(va_list *args, flag_t *flags);
int print_char(va_list *args, flag_t *flags);
int print_percent(va_list *args, flag_t *flags);
int print_converted_int(char *str, flag_t *flags);
char *u_convert(unsigned long int n, int s, unsigned long int b, flag_t *f);
char *converter(long int n, int s, long int b, flag_t *flags);
int print_octal(va_list *args, flag_t *flags);
int print_hex(va_list *args, flag_t *flags);
int print_hex_upper(va_list *args, flag_t *flags);
int print_binary(va_list *args, flag_t *flags);
int print_ustring(va_list *args, flag_t *flags);
int print_pointer(va_list *args, flag_t *flags);
int set_flags(const char *c, flag_t *flags);
void reset_flags(flag_t *flag);
int printStartEnd(const char *str, int strat, int end);
int get_width(const char *c, flag_t *flags);
int get_str_length(char *str);
#endif
