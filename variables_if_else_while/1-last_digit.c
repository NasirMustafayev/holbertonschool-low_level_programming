#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Prints the last digit of random number
 *
 * Return: Always 0
 */
int main(void)
{
	int n;
	int lastdig;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	lastdig = n % 10;

	if (lastdig > 5)
		printf("Last digit of %i is %i and is greater than 5\n", n, lastdig);
	else if (lastdig == 0)
		printf("Last digit of %i is 0 and is 0\n", n);
	else
		printf("Last digit of %i is %i and is less than 6 and not 0\n", n, lastdig);

	return (0);
}
