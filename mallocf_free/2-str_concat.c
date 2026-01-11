#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings.
 * @s1: first string (can be NULL)
 * @s2: second string (can be NULL)
 *
 * Return: pointer to newly allocated concatenated string, or NULL if
 * allocation fails.
 */
char *str_concat(char *s1, char *s2)
{
	char *out;
	int len1, len2, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	len2 = 0;
	while (s2[len2] != '\0')
		len2++;

	out = malloc(sizeof(char) * (len1 + len2 + 1));
	if (out == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		out[i] = s1[i];
	for (j = 0; j < len2; j++)
		out[i + j] = s2[j];
	out[i + j] = '\0';

	return (out);
}
