#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	char str[] = "Hello, World!";
	int len, len2;

	len = _printf("%ld", LONG_MIN);
	len2 = printf("%ld", LONG_MIN);
	_printf("%s\n", str);
	_printf("%!\n");
	_printf("%K\n");
	_printf("%r\n", str);
	printf("Reversed string: %r\n", str);
	_printf("Reversed string: %r\n", str);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%ld + %ld = %ld\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));
	len2 = printf("%ld + %ld = %ld\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%li", LONG_MIN);
	len2 = printf("%li", LONG_MIN);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%li + %li = %li\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));
	len2 = printf("%li + %li = %li\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%hu", USHRT_MAX);
	len2 = printf("%hu", USHRT_MAX);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%hu - %hu = %hu\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	len2 = printf("%hu - %hu = %hu\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%h\n");
	len2 = printf("%h\n");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%l\n");
	len2 = printf("%l\n");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
