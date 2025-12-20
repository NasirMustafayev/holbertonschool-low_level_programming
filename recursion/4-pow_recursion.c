#include "main.h"
/**
 * _pow_recursion - function that returns the value of x
 * raised to the power of y
 * @x: base number
 * @y: exponent number
 * Return: result of x raised to the power of y
 */
int _pow_recursion(int x, int y)
{
	int result;

	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	result = x * _pow_recursion(x, y - 1);
	return (result);
}
