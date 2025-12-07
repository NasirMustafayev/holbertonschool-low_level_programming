#include "main.h"
/**
 * print_square - Prints # to console n of times
 *@size: input number
 *
 * Return: void
 */
void print_square(int size)
{
	int c;

	for (c = 0; c < size; c++)
	{
		_putchar('#');
	}
	_putchar('\n');
}
