#include "main.h"
/**
 * print_triangle - Prints # to console n of times
 *@size: input number
 *
 * Return: void
 */
void print_triangle(int size)
{
	int c;

	for (c = 0; c < size; c++)
	{
		_putchar('#');
	}
	_putchar('\n');
}
