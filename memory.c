#include "shell.h"

/**
 * bfree - frees a pointer and NULLs its address
 * @ptr: address of the pointer to free
 *
 * Return: returns 1 if freed and otherwise if 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
