#include "main.h"
#include <ctype.h>
#include <string.h>

/**
 * print_char - writes the char from args to stdout
 * @args: args to get next arg char
 * @flags: flags for format string
 * Return: 1
 */
int print_char(va_list *args, flag_t *flags)
{
char str = va_arg(*args, int);

(void) flags;

_write_buffer(str);
return (1);
}
/**
 * print_percent - writes % to stdout
 * @args: args
 * @flags: flags for format string
 * Return: 1
 */
int print_percent(va_list *args, flag_t *flags)
{
(void) args;
(void) flags;

_write_buffer('%');
return (1);
}
/**
 * print_string - writes string to stdout
 * @args: args
 * @flags: flags for format string
 * Return: number of printed characters
 */
int print_string(va_list *args, flag_t *flags)
{
char *s = va_arg(*args, char *);
int i = 0;
int precision = flags->precision;

if (s == NULL)
{
s = "(null)";
}
if (precision)
{
while (*s && i < precision)
{
_write_buffer(*s);
s++;
i++;
}
}
else
{
while (*s)
{
_write_buffer(*s);
s++;
i++;
}
}
return (i);
}
/**
 * print_ustring - prints a string
 * @args: args to get next arg char*
 * @flags: flags for format string
 * Return: number of printed chargcters
 */
int print_ustring(va_list *args, flag_t *flags)
{
unsigned char *str;
char *hex;
int i = 0, length = 0;

str = va_arg(*args, unsigned char *);

while (str[i])
{
if (str[i] < 32 || str[i] >= 127)
{
_write_buffer('\\');
_write_buffer('x');

flags->upperHex = 87;
hex = u_convert(str[i], 20, 16, flags);
if (!hex)
return (-1);
/*print last two digits in hex*/
_write_buffer(hex[18]);
_write_buffer(hex[19]);
free(hex);
length += 4;
}
else
{
_write_buffer(str[i]);
length++;
}
i++;
}
return (length);
}

/**
 * print_rotate - prints a string
 * @args: args to get next arg char*
 * @flags: flags for format string
 * Return: number of printed chargcters
 */
int print_rotate(va_list *args, flag_t *flags)
{
char *s = va_arg(*args, char *);
int len = strlen(s);
int i = 0;

(void) flags;
for (; i < len; i++)
{
if (isalpha(s[i]))
{
if (islower(s[i]))
_write_buffer((s[i] - 'a' + 13) % 26 + 'a');
else
_write_buffer((s[i] - 'A' + 13) % 26 + 'A');
}
else
{
_write_buffer(s[i]);
}
}
return (i);
}

/**
 * print_reverse - prints a string
 * @args: args to get next arg char*
 * @flags: flags for format string
 * Return: number of printed chargcters
 */
int print_reverse(va_list *args, flag_t *flags)
{
char *s = va_arg(*args, char *);
int len = strlen(s);
int i;

(void) flags;

for (i = len - 1; i >= 0; i--)
{
	_write_buffer(s[i]);
}
return (len);
}
