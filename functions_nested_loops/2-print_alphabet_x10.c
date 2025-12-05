#include "main.h"
/**
 * print_alphabet_x10 - Prints the alpabet in lowercase 10x
 *
 * Return: Always 0
 */
void print_alphabet_x10(void)
{
	int num;
	char letter;

	for (num = 1; num <= 10; num++)
	{
		for(letter ='a'; letter <= 'z'; letter++)
		{
			_putchar(letter);
		}
		_putchar('\n');
	}
}
