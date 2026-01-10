#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to find
 *
 * Return: pointer to the beginning of the located substring,
 *         or NULL if not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;

	if (needle[0] == '\0')
		return (haystack);

	for (i = 0; haystack[i]; i++)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j])
			j++;

		if (needle[j] == '\0')
			return (haystack + i);
	}

	return (0);
}
