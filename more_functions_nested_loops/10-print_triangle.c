#include "main.h"
/**
 * print_triangle - Prints # to console n of times
 *@size: input number
 *
 * Return: void
 */
void print_triangle(int size)
{
	int r, c;

	for (r = 0; r < size; r++)
	{
		for (c = 0; c < size - r - 1; c++)
			_putchar(' ');
		for (c = 0; c <= r; c++)
			_putchar('#');
		_putchar('\n');
	}
}
