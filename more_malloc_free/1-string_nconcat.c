#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: max bytes to copy from s2
 *
 * Return: pointer to new string or NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i = 0, j = 0, len1 = 0, len2 = 0;
	char *s;

	if (s1)
		while (s1[len1])
			len1++;
	if (s2)
		while (s2[len2])
			len2++;

	if (n < len2)
		len2 = n;

	s = malloc(len1 + len2 + 1);
	if (s == NULL)
		return (NULL);

	while (i < len1)
	{
		s[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';

	return (s);
}
