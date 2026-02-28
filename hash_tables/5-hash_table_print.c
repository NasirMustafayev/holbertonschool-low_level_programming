#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: the hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *tmp;
	unsigned long int i;
	int first = 1;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		while (tmp)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", tmp->key, tmp->value);
			first = 0;
			tmp = tmp->next;
		}
	}
	printf("}\n");
}
