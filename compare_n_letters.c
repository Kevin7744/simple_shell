#include "shell.h"

/**
 * compare_n_letters - compares n characters of the input strings.
 *
 * @str1: the first input string.
 * @str2: the second input string.
 * @n: Number of characters to be compared.
 *
 * Return: 1 if similar, 0 otherwise.
 */

int compare_n_letters(char *str1, char *str2, int n)
{
	int i = 0;

	while (i < n)
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}
