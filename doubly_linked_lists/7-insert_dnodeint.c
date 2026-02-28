#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to pointer of the first element of the list
 * @idx: index where the new node should be added (starting at 0)
 * @n: integer to store in the new node
 * Return: address of the new node, or NULL if failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *tmp;
	unsigned int i = 0;

	if (idx == 0)
		return (add_dnodeint(h, n));

	tmp = *h;
	while (tmp)
	{
		if (i == idx - 1)
		{
			if (!tmp->next)
				return (add_dnodeint_end(h, n));

			new = malloc(sizeof(dlistint_t));
			if (!new)
				return (NULL);

			new->n = n;
			new->next = tmp->next;
			new->prev = tmp;

			if (tmp->next)
				tmp->next->prev = new;

			tmp->next = new;
			return (new);
		}
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}
