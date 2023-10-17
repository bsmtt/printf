#include "main.h"
/**
 * print_hex - print number from args in hex
 * @args: args to get next arg long int
 * @flags: flags
 * Return: number of characters printed
 */
int print_hex(va_list *args, flag_t *flags)
{
char *hex;
unsigned int n1;
unsigned long int n2;
unsigned short int n3;

flags->upperHex = 87;
if (flags->l)
{
n2 = va_arg(*args, unsigned long int);
hex = u_convert(n2, 20, 16, flags);
}
else if (flags->h)
{
n3 = va_arg(*args, unsigned int);
hex = u_convert(n3, 20, 16, flags);
}
else
{
n1 = va_arg(*args, unsigned int);
hex = u_convert(n1, 20, 16, flags);
}
if (!hex)
return (-1);
if (flags->hash && n1 != 0)
{
_write_buffer('0');
_write_buffer('x');
}
return (print_converted_int(hex, flags));
}
/**
 * print_hex_upper - print number from args in hex
 * @args: args to get next arg long int
 * @flags: flags
 * Return: number of characters printed
 */
int print_hex_upper(va_list *args, flag_t *flags)
{
char *hex;
unsigned int n1;
unsigned long int n2;
unsigned short int n3;

flags->upperHex = 55;
if (flags->l)
{
n2 = va_arg(*args, unsigned long int);
hex = u_convert(n2, 20, 16, flags);
}
else if (flags->h)
{
n3 = va_arg(*args, unsigned int);
hex = u_convert(n3, 20, 16, flags);
}
else
{
n1 = va_arg(*args, unsigned int);
hex = u_convert(n1, 20, 16, flags);
}
if (!hex)
return (-1);

if (flags->hash && n1 != 0)
{
_write_buffer('0');
_write_buffer('X');
}

return (print_converted_int(hex, flags));
}
