#include "main.h"
/**
 * print_square - create a square with # in console 
 *@size: number of times the '#' character should be printed
 *
 * Return: void
 */
void print_square(int size)
{
	int r, c;

	for (r = 0; r < size; r++)
	{
		for (c = 0; c < size; c++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
