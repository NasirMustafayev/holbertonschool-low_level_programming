#include "main.h"
/**
 * _isdigit - checks for digit character
 * @c: the character to check
 *
 * Return: 1 if c is digit, 0 otherwise
 */
int _isdigit(int c)
{
	int digit = c - '0';
	if (digit >= 0 && digit <= 9)
		return (1);
	else
		return (0);
}
