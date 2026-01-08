#include "stdio.h"
/**
 * main - prints the number of arguments passed to it
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	//prevent unused variable warning
	 (void)argv;
	 // Subtracting 1 to not count the program name
	 int actualargc = argc - 1;

	 printf("%d\n", actualargc);
	 return (0);
}