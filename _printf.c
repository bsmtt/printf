#include "main.h"

/**
 * _printf - print strings to console.
 * @format: string with format to be printed.
 * Return: length of printed string.
 */
int _printf(const char *const format, ...)
{
int length = 0, i = 0, startIndex, newLength, startSpecifier;
const char *c;
flag_t flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
va_list args;

va_start(args, format);
c = format;
if (!c || (c[0] == '%' && !c[1]))
return (-1);
while (c[i])
{
if (c[i] == '%')
startSpecifier = 1, i++;
if (startSpecifier == 1)
{
reset_flags(&flags);
while (set_flags(c + i, &flags))
i++;
if(!c[i] || c[i] == '\n')
{
_write_buffer('%'), length++;
goto endprint;
}
startIndex = i;
newLength = get_specifier_handler(c + i, &args, &flags);
if (newLength == -1)
goto endprint;
if (newLength == -2)
newLength = printStartEnd(c, startIndex, i);
length += newLength;
startSpecifier = 0;
}
else
{
_write_buffer(c[i]), length++;
}
i++;
}
endprint:
va_end(args);
_write_buffer(0);
return (length);
}
/**
 * get_specifier_handler - get specifier handler from string
 * @format: formatted string
 * @args: args to get next arg
 * @flags: flags
 * Return: number of printed chars
 */
int get_specifier_handler(const char *format, va_list *args, flag_t *flags)
{
int i = 0;

specifier_handler specifiers[] = {
{"s", print_string}, {"c", print_char},
{"%", print_percent}, {"d", print_number},
{"i", print_number}, {"u", print_unsigned_number},
{"x", print_hex}, {"X", print_hex_upper},
{"o", print_octal}, {"b", print_binary},
{"S", print_ustring}, {"p", print_pointer}};
while (i < 12)
{
if (specifiers[i].specifier[0] == *format)
{
return (specifiers[i].handler(args, flags));
}
i++;
}
return (-2);
}
/**
 * printStartEnd - print strings to console.
 * @str: str to print.
 * @start: start char.
 * @end: end char.
 * Return: length of printed string.
 */
int printStartEnd(const char *str, int start, int end)
{
int i = 0;

while (start <= end)
{
_write_buffer(str[start]);
i++, start++;
}
return (i);
}
