#include "main.h"
/**
 * sqrt_helper - helper function to find the square root
 * @n: number to find square root of
 * @guess: current guess
 * Return: square root of n or -1 if not found
 */
int sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	if (guess * guess > n)
		return (-1);
	return (sqrt_helper(n, guess + 1));
}
/**
 * _sqrt_recursion - function that returns the square root of a number
 * @n: number to find square root of
 * Return: square root of n or -1 if not found
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqrt_helper(n, 0));
}
