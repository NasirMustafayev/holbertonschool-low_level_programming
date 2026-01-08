#include "stdio.h"
#include "stdlib.h"
/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 if successful, 1 if error
 */

int main(int argc, char *argv[])
{
	int calc;

	if (argc == 3)
	{
	calc = atoi(argv[1]) * atoi(argv[2]);
	printf("%d\n", calc);
	return (0);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
}
