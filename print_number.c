#include "main.h"
/**
 * print_number - print number from args in num
 * @args: args to get next arg long int
 * @flags: flags
 * Return: number of characters printed
 */
int print_number(va_list *args, flag_t *flags)
{
char *num;
int n1;
long int n2;
short int n3;

if (flags->l)
{
n2 = va_arg(*args, long int);
if (n2 < 0)
flags->negative = 1;
num = converter(n2, 25, 10, flags);
}
else if (flags->h)
{
n3 = va_arg(*args, int);
if (n3 < 0)
flags->negative = 1;
num = converter(n3, 25, 10, flags);
}
else
{
n1 = va_arg(*args, int);
if (n1 < 0)
flags->negative = 1;
num = converter(n1, 25, 10, flags);
}
if (!num)
return (-1);
return (print_converted_int(num, flags));
}
