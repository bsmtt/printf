#include "main.h"
/**
 * print_converted_int - print number in str
 * @str: text to print
 * @flags: flags
 * Return: number of characters printed
 */
int print_converted_int(char *str, flag_t *flags)
{
int i = 0, startPrintFlag = 0, length = 0;

(void) flags;
while (str[i])
{
if (str[i] != '0' || startPrintFlag == 1)
{
startPrintFlag = 1;
_write_buffer(str[i]);
length++;
}
i++;
}
if (startPrintFlag == 0)
{
_write_buffer('0');
length++;
}
free(str);
return (length);
}
/**
 * u_convert - convert integer to str.
 * @n: number to convert to str in string
 * @s: size of result string
 * @b: base number for convert
 * @flags: flags
 * Return: void
 */
char *u_convert(unsigned long int n, int s, unsigned long int b, flag_t *flags)
{
int i;
char *str = malloc(s * sizeof(char));
if (!str)
return (str);
for (i = 0; i < s; i++)
str[i] = '0';
str[s] = '\0';

/*convert to str in string*/
for (i = s - 1; n > 0; i--)
{
if ((n % b) > 9 && b == 16)
str[i] = (n % b) + flags->upperHex;
else
str[i] = (n % b) + '0';

n /= b;
}
if (flags->plus)
str[i] = '+', i++;
else if (flags->space)
str[i] = ' ', i++;
return (str);
}

/**
 * converter - convert integer to str.
 * @n: number to convert to str in string
 * @s: size of result string
 * @b: base number for convert
 * @flags: flags
 * Return: void
 */
char *converter(long int n, int s, long int b, flag_t *flags)
{
int i;
char *str = malloc(s * sizeof(char));
if (!str)
return (str);
for (i = 0; i < s; i++)
str[i] = '0';
str[s] = '\0';

if (flags->negative && n == LONG_MIN)
n = LONG_MAX;
else if (flags->negative)
n = -n;
/*convert to str in string*/
for (i = s - 1; n > 0; i--)
{
if (flags->upperHex && (n % b) > 9 && b == 16)
str[i] = (n % b) + 55;
else if (!flags->upperHex && (n % b) > 9 && b == 16)
str[i] = (n % b) + 87;
else if (i == s - 1 && b == 10 && n == LONG_MAX && flags->negative == 1)
str[i] = '8';
else
str[i] = (n % b) + '0';

n /= b;
}
if (flags->negative && b == 10)
str[i] = '-', i++;
else if (flags->plus)
str[i] = '+', i++;
else if (flags->space)
str[i] = ' ', i++;
return (str);
}
/**
 * get_str_length - print number in str
 * @str: text to get length
 * Return: str length
 */
int get_str_length(char *str)
{
int i = 0;
while (str[i])
i++;
return (i);
}
