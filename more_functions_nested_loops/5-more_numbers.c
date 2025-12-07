#include "main.h"
/**
 * more_numbers - prints numbers from 0 to 14, 10 times
 *
 * Return: void
 */
void more_numbers(void)
{
	int num, digit;

	for (num = 0; num < 10; num++)
	{
		for (digit = 0; digit <= 14; digit++)
		{
			if (digit >= 10)
				_putchar((digit / 10) + '0');
			_putchar((digit % 10) + '0');
		}
		_putchar('\n');
	}
}
