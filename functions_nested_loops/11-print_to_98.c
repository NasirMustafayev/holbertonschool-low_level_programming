#include <stdio.h>
#include "main.h"
/**
 * print_to_98 - counting to 98 in normal and reverse
 * @n: input
 */
void print_to_98(int n)
{
	int c;

	if (n < 98)
	{
		for (c = 0; c <= 98; c++)
		{
			(c == 98) ? printf("%i ", c) : printf("%i, ", c);
		}
	}
	else
	{
		for (c = n ; c >= 98; c--)
		{
			(c == 98) ? printf("%i ", c) : printf("%i, ", c);
		}
	}
	printf("\n");
}
