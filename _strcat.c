#include "shell.h"

/**
 * _strcat - Concatanate 2 string
 *
 * @s1: First string
 * @s2: second string
 *
 * Return: The new string
 */

char *_strcat(char *s1, char *s2)
{
	/*     i : Index for s1, j : Index for s2     */

	int i = 0, j = 0, size = _strlen(s1) + _strlen(s2);
	char *concatenated_string = NULL;

	concatenated_string = malloc(size + 1);

	while (i < _strlen(s1))
		concatenated_string[i + j] = s1[i], i++;
	while (j < _strlen(s2))
		concatenated_string[i + j] = s2[j], j++;

	concatenated_string[i + j] = '\0';
	return (concatenated_string);
}

