#include "shell.h"

/**
 * cmd_path - Search if a command is in the PATH
 *
 * @command: Command to search
 *
 * Return: Anything, cause void function
 */
int cmd_path(char *command)
{
		int length;
		int i, j;
		char *command_to_test, *free_use;
		struct stat st;
		path *tmp = path_head;

		while (tmp != NULL)
		{
			length = _strlen(tmp->current_dir) + _strlen(command) + 1;
			command_to_test = _strdup(tmp->current_dir);
			command_to_test = _realloc(command_to_test, length);
			for (j = 0, i = _strlen(command_to_test); command[j]; j++, i++)
				command_to_test[i] = command[j];
			command_to_test[i] = '\0';
			if (!stat(command_to_test, &st))
			{
				free_use = array_command[0];
				array_command[0] = command_to_test;
				free(free_use);
				return (0);
			}
			free(command_to_test);
			tmp = tmp->next;
		}
		return (1);
	}
