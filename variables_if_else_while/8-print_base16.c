#include <stdio.h>

/**
 * main - Prints the alpabet in lower and uppercase
 *
 * Return: Always 0
 */
int main(void)
{
	int num;
	char letter;

	for (num = 0; num <= 9; num++)
	{
		putchar(num + '0');
	}
	for (letter = 'a'; letter <= 'f'; letter++)
	{
		putchar(letter);
	}
	putchar('\n');

	return (0);
}
