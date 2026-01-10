#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: string
 *
 * Return: pointer to s
 */
char *cap_string(char *s)
{
	int i = 0;
	int sep[] = { ' ', '\t', '\n', ',', ';', '.', '!', '?', '"',
			  '(', ')', '{', '}' };
	int j;

	if (s[0] >= 'a' && s[0] <= 'z')
		s[0] -= 32;

	while (s[i])
	{
		for (j = 0; j < 13; j++)
		{
			if (s[i] == sep[j] &&
			    s[i + 1] >= 'a' && s[i + 1] <= 'z')
				s[i + 1] -= 32;
		}
		i++;
	}

	return (s);
}
