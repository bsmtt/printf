#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	long int l = UINT_MAX;

	l += 1024;
	 _printf("%b", l);

	return (0);
}
