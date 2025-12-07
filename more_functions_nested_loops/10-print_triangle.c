#include "main.h"
/**
 *print_triangle - create triangle with # on console
 *@size: number of times the '#' character should be printed
 *
 * Return: void
 */
void print_triangle(int size)
{
	int r, c;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}
	for (r = 0; r < size; r++)
	{
		for (c = 0; c < size - r - 1; c++)
			_putchar(' ');
		for (c = 0; c <= r; c++)
			_putchar('#');
		_putchar('\n');
	}
}
