#include "main.h"
#include <stdlib.h>
/**
 * argstostr - concatenates all the arguments of your program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to new string, or NULL if ac == 0, av == NULL,
 * or malloc fails
 */
char *argstostr(int ac, char **av)
{
	int i, j;
	unsigned int total = 0, k = 0;
	char *s;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		if (av[i] == NULL)
			return (NULL);
		for (j = 0; av[i][j] != '\0'; j++)
			total++;
		total++; /* for '\n' */
	}

	s = (char *)malloc((total + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			s[k++] = av[i][j];
		s[k++] = '\n';
	}
	s[k] = '\0';

	return (s);
}
