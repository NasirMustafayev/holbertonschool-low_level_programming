#include "main.h"
/**
 * print_line : Prints _ to console n of times
 *@n: input number
 *
 * Return: void
 */
void print_line(int n)
{
	int c;

	for (c = 0; c < n; c++)
	{
		_putchar('_');
	}
	_putchar('\n');
}
