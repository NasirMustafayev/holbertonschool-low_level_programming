#include "dog.h"
#include <stdlib.h>
/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 * Return: pointer to the new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	char *name_copy = NULL, *owner_copy = NULL;
	unsigned int i, name_len = 0, owner_len = 0;

	if (name == NULL || owner == NULL)
		return (NULL);

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);
	while (name[name_len])
		name_len++;
	while (owner[owner_len])
		owner_len++;
	name_copy = malloc(name_len + 1);
	owner_copy = malloc(owner_len + 1);

	if (!name_copy || !owner_copy)
	{
		free(name_copy);
		free(owner_copy);
		free(d);
		return (NULL);
	}
	for (i = 0; i <= name_len; i++)
		name_copy[i] = name[i];
	for (i = 0; i <= owner_len; i++)
		owner_copy[i] = owner[i];
	d->name = name_copy;
	d->age = age;
	d->owner = owner_copy;
	return (d);
}
