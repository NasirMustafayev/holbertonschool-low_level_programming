#include "main.h"
#include <stdlib.h>

static int is_sep(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int word_count(char *str)
{
	int i = 0, count = 0;

	while (str[i] != '\0')
	{
		while (str[i] != '\0' && is_sep(str[i]))
			i++;
		if (str[i] == '\0')
			break;
		count++;
		while (str[i] != '\0' && !is_sep(str[i]))
			i++;
	}
	return (count);
}

static void free_words(char **words, int filled)
{
	int i;

	for (i = 0; i < filled; i++)
		free(words[i]);
	free(words);
}

/**
 * strtow - splits a string into words
 * @str: input string
 *
 * Return: pointer to an array of strings (words), terminated by NULL,
 *         or NULL if str is NULL/empty, no words, or malloc fails
 */
char **strtow(char *str)
{
	char **words;
	int wc, i = 0, w = 0, start, len, j;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	wc = word_count(str);
	if (wc == 0)
		return (NULL);

	words = (char **)malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	while (str[i] != '\0' && w < wc)
	{
		while (str[i] != '\0' && is_sep(str[i]))
			i++;
		if (str[i] == '\0')
			break;

		start = i;
		len = 0;
		while (str[i] != '\0' && !is_sep(str[i]))
		{
			i++;
			len++;
		}

		words[w] = (char *)malloc((len + 1) * sizeof(char));
		if (words[w] == NULL)
		{
			free_words(words, w);
			return (NULL);
		}

		for (j = 0; j < len; j++)
			words[w][j] = str[start + j];
		words[w][len] = '\0';
		w++;
	}

	words[w] = NULL;
	return (words);
}
