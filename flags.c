#include "main.h"

/**
 * set_flags - get specifier handler from string
 * @c: formatted string
 * @flags: format flags to update
 * Return: void
 */
int set_flags(const char *c, flag_t *flags)
{
if (!*c)
return (0);
if (get_width(c, flags))
return (1);
switch (*c)
{
case '+':
flags->plus = 1;
break;
case ' ':
flags->space = 1;
break;
case '#':
flags->hash = 1;
break;
case 'h':
flags->h = 1;
break;
case 'l':
flags->l = 1;
break;
case '0':
flags->zero = 1;
break;
case '-':
flags->minus = 1;
break;
case 'r':
flags->reverse = 1;
break;
case 'R':
flags->rotate = 1;
break;
case '.':
flags->precision = 1;
break;
default:
return (0);
}
return (1);
}

/**
 * reset_flags - get specifier handler from string
 * @flags: format flags to update
 * Return: void
 */
void reset_flags(flag_t *flags)
{
flags->precision = 0;
flags->plus = 0;
flags->space = 0;
flags->hash = 0;
flags->h = 0;
flags->l = 0;
flags->width = 0;
flags->zero = 0;
flags->minus = 0;
flags->zero = 0;
flags->minus = 0;
flags->rotate = 0;
flags->upperHex = 0;
flags->negative = 0;
}

/**
 * get_width - get width handler from string
 * @c: formatted string
 * @flags: format flags to update
 * Return: void
 */
int get_width(const char *c, flag_t *flags)
{
int num = '0';
while (num <= '9')
{
if (num == *c)
{
flags->width = (flags->width) * 10 + (num - '0');
return (1);
}
num++;
}
return (0);
}
