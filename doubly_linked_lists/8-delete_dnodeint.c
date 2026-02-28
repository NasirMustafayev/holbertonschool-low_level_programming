#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at a given index of a list
 * @head: pointer to pointer of the first element of the list
 * @index: index of the node to delete (starting at 0)
 * Return: 1 if succeeded, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);

	tmp = *head;

	while (tmp)
	{
		if (i == index)
		{
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			else
				*head = tmp->next;

			if (tmp->next)
				tmp->next->prev = tmp->prev;

			free(tmp);
			return (1);
		}
		i++;
		tmp = tmp->next;
	}
	return (-1);
}
