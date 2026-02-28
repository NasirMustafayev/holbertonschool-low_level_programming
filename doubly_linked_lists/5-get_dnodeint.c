#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the head of the list
 * @idx: index of the node to return (starting at 0)
 * Return: pointer to the nth node, or NULL if not found
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int idx)
{
	unsigned int i = 0;

	while (head)
	{
		if (i == idx)
			return (head);
		i++;
		head = head->next;
	}
	return (NULL);
}
