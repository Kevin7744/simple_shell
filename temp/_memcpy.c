#include "shell.h"

/**
 * _memcpy - copies memory area.
 *
 * @dest: Destination sting
 * @src: Source string to copies into dest
 *
 * Return: Dest string.
 */
char *_memcpy(char *dest, char *src)
{
	unsigned int i;

	for (i = 0; src[i]; i++)
	{
		*(dest + i) = *(src + i);
	}
	dest[i] = '\0';
	return (dest);
}
