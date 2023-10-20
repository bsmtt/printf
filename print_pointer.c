#include "main.h"
#include <string.h>

/**
 * print_pointer - print pointer address of input
 * @args: args to get next arg int
 * @flags: flags for format string
 * Return: number of characters printed
 */
int print_pointer(va_list *args, flag_t *flags)
{
unsigned long int_input;
int length = 2, i;
char *hex;
char *temp;
void *ptr = (va_arg(*args, void *));

if (ptr == NULL)
{
temp = "(nil)";

for (i = 0; temp[i]; i++)
_write_buffer(temp[i]);
return (5);
}
else
int_input = (unsigned long)ptr;

flags->upperHex = 87;
hex = u_convert(int_input, 20, 16, flags);
if (!hex)
return (-1);
_write_buffer('0');
_write_buffer('x');
length += (print_converted_int(hex, flags));
return (length);
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
int i = len - 1;

(void) flags;

for (; i >= 0; i--)
{
_write_buffer(s[i]);
}
return (len);
}
