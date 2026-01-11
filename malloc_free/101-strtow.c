#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts words in a string
 * @str: input string
 *
 * Return: number of words
 */
static int count_words(char *str)
{
	int i = 0, in_word = 0, count = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

/**
 * make_word - allocates and copies one word starting at index *i
 * @str: input string
 * @i: pointer to current index (will be advanced past the word)
 *
 * Return: allocated word, or NULL on failure
 */
static char *make_word(char *str, int *i)
{
	int start, len = 0, j;
	char *w;

	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n')
		(*i)++;

	start = *i;
	while (str[*i] != '\0' && str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\n')
	{
		(*i)++;
		len++;
	}

	w = (char *)malloc((len + 1) * sizeof(char));
	if (w == NULL)
		return (NULL);

	for (j = 0; j < len; j++)
		w[j] = str[start + j];
	w[len] = '\0';

	return (w);
}

/**
 * free_all - frees an array of words partially filled
 * @words: array of words
 * @n: number of allocated words
 */
static void free_all(char **words, int n)
{
	int i;

	for (i = 0; i < n; i++)
		free(words[i]);
	free(words);
}

/**
 * strtow - splits a string into words
 * @str: input string
 *
 * Return: pointer to array of words (NULL-terminated), or NULL
 */
char **strtow(char *str)
{
	char **words;
	int wc, i = 0, w = 0;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	wc = count_words(str);
	if (wc == 0)
		return (NULL);

	words = (char **)malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	while (w < wc)
	{
		words[w] = make_word(str, &i);
		if (words[w] == NULL)
		{
			free_all(words, w);
			return (NULL);
		}
		w++;
	}
	words[w] = NULL;

	return (words);
}
