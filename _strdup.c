#include "shell.h"

/**
 * _strdup - Duplicate a str into an new str
 *
 * @str: String to copie
 *
 * Return: NULL if probleme, pointer to the new string else (success)
 */
char *_strdup(char *str)
{
	char *duplicateStr;
	unsigned int lengthOfStr, i;

	if (str == NULL)
		return (NULL);
	lengthOfStr = _strlen(str);
	duplicateStr = (char *)malloc(sizeof(char) * lengthOfStr + 1);
	if (duplicateStr == NULL)
		return (NULL);
	for (i = 0; i < lengthOfStr; i++)
		*(duplicateStr + i) = *(str + i);
	duplicateStr[i] = '\0';
	return (duplicateStr);
}
