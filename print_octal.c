#include "main.h"
/**
 * print_octal - print number from args in octal
 * @args: args to get next arg long int
 * @flags: flags
 * Return: number of characters printed
 */
int print_octal(va_list *args, flag_t *flags)
{
char *octal;
unsigned int n1;
unsigned long int n2;
unsigned short int n3;

if (flags->l)
{
n2 = va_arg(*args, unsigned long int);
octal = u_convert(n2, 23, 8, flags);
}
else if (flags->h)
{
n3 = va_arg(*args, unsigned int);
octal = u_convert(n3, 23, 8, flags);
}
else
{
n1 = va_arg(*args, unsigned int);
octal = u_convert(n1, 23, 8, flags);
}
if (!octal)
return (-1);
return (print_converted_int(octal, flags));
}

/**
 * print_binary - print number from args in binary
 * @args: args to get next arg long int
 * @flags: flags
 * Return: number of characters printed
 */
int print_binary(va_list *args, flag_t *flags)
{
unsigned long int n, i, flag = 0;
char *binary;

n = va_arg(*args, long int);
binary = u_convert(n, 32, 2, flags);
if (!binary)
return (-1);
return (print_converted_int(binary, flags));
}
