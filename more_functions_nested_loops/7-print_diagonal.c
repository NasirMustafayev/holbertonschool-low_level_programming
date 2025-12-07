#include "main.h"
/**
 * print_diagonal - Prints \(reverseslash) to console n of times
 *@n: input number
 *
 * Return: void
 */
void print_diagonal(int n)
{
	int c;

	for (c = 0; c < n; c++)
	{
		_putchar('\\');
	}
	_putchar('\n');
}
