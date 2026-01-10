#include "main.h"

/**
 * reverse_array - reverses an array of integers
 * @a: array
 * @n: number of elements
 */
void reverse_array(int *a, int n)
{
	int i = 0, tmp;

	while (i < n / 2)
	{
		tmp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = tmp;
		i++;
	}
}
