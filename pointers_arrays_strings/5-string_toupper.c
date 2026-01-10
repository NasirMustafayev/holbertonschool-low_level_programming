#include "main.h"

/**
 * string_toupper - changes lowercase to uppercase
 * @s: string
 *
 * Return: pointer to s
 */
char *string_toupper(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}

	return (s);
}
