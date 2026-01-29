#include <stdio.h>
#include "function_pointers.h"
/**
 * array_iterator - executes a function on each element of an array
 * @array: pointer to the array of integers
 * @size: number of elements in the array
 * @action: pointer to the function to be executed on each element
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	int i;

	if (array == NULL || action == NULL)
		return;
	else
	{
		for (i = 0; i < size; i++)
		{
			action(array[i]);
		}
	}
}
