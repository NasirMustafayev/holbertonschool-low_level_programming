#include "main.h"
/**
 * _strcpy - copies the string pointed to by src
 * @dest: pointer to the destination array
 * @src: pointer to the source string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *original_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}

