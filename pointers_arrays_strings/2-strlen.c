#include "main.h"
/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
    int length = 0;

    while (s[length] != '\0')
    {
        length++;
    }
    return (length);
}
