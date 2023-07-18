#include "shell.h"

/**
 * _pathinit - Initialise a linked list of the PATH contain
 *
 * Return: nothing, void function
 */
void _pathinit(void)
{
	char *path_value;
	int i = 0, j, k, length;
	char *value_to_fill;
	int checkpoint = 0;

	path_head = NULL;
	path_value = _envget("PATH");

	if (path_value != NULL)
	{
		for (i = 0; path_value[i]; i++)
		{
			if (path_value[i] == ':' || path_value[i] == '\0')
			{
				length = i - checkpoint + 2;
				value_to_fill = malloc(sizeof(char) * length);
				if (!value_to_fill)
					return;
				for (j = checkpoint, k = 0; j < i; j++, k++)
					value_to_fill[k] = path_value[j];
				if (value_to_fill[k - 1] != '/')
				{
					value_to_fill[k] = '/';
					value_to_fill[k + 1] = '\0';
				}
				else
					value_to_fill[k] = '\0';
				add_node_end(&path_head, value_to_fill);
				i++;
				checkpoint = i;
			}
		}
	}
}
