#include "hash_tables.h"

/**
 * update_value - updates the value of an existing node
 * @tmp: the node to update
 * @value: the new value
 * Return: 1 on success, 0 on failure
 */
static int update_value(hash_node_t *tmp, const char *value)
{
	free(tmp->value);
	tmp->value = strdup(value);
	if (!tmp->value)
		return (0);
	return (1);
}

/**
 * create_node - creates a new hash node
 * @key: the key
 * @value: the value
 * Return: pointer to new node, or NULL on failure
 */
static hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *new;

	new = malloc(sizeof(hash_node_t));
	if (!new)
		return (NULL);
	new->key = strdup(key);
	if (!new->key)
	{
		free(new);
		return (NULL);
	}
	new->value = strdup(value);
	if (!new->value)
	{
		free(new->key);
		free(new);
		return (NULL);
	}
	return (new);
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table
 * @key: the key (cannot be empty)
 * @value: the value associated with the key
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new, *tmp;
	unsigned long int idx;

	if (!ht || !key || key[0] == '\0' || !value)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[idx];
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
			return (update_value(tmp, value));
		tmp = tmp->next;
	}
	new = create_node(key, value);
	if (!new)
		return (0);
	new->next = ht->array[idx];
	ht->array[idx] = new;
	return (1);
}
