#include "shell.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 *
 * @ptr: Value to reallocate
 * @new_size: New size of memory
 *
 * Return: NULL if probleme, the new pointer to the new allocated
 * memory
 */
void *_realloc(void *ptr, unsigned int new_size)
{
	void *newArray;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	newArray = malloc(new_size);
	if (newArray == NULL)
		return (NULL);

	_memcpy(newArray, ptr);
	free(ptr);

	return (newArray);
}

/**
 * _realloc_ptr - reallocates a memory block using malloc and free
 *
 * @ptr: Value to reallocate
 * @new_size: New size of memory
 *
 * Return: NULL if probleme, the new pointer to the new allocated
 * memory
 */
char **_realloc_ptr(char **ptr, unsigned int new_size)
{
	char **newArray;
	int i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	newArray = malloc(new_size);
	if (newArray == NULL)
		return (NULL);

	for (i = 0; ptr[i]; i++)
		newArray[i] = ptr[i];
	free(ptr);

	return (newArray);
}
