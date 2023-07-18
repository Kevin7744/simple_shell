#include "shell.h"

/**
 * _strcmp - Copare 2 sting
 *
 * @s1: String to compare
 * @s2: String to compare
 *
 * Return: Positive if s1 > s2, negative if s1 < s2, 0 if s1 == s2
 */
int _strcmp(const char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
