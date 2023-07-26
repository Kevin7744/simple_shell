#include "shell.h"

/**
 * check_built_in - Check if a command inputed is a built in command
 *
 * @command: Commad inputed
 *
 * Return: Pointer to function, to execute the command, NULL else
 */
int (*check_built_in(const char *command))(void)
{
	int i;

	built_in p[] = {{"env", _envprint},
				{"exit", _exit_},
				{"setenv", _setenv},
				{"unsetenv", _unsetenv},
				{"help", _help},
				{NULL, NULL}};

	for (i = 0; p[i].command; i++)
	{
		if (_strcmp(command, p[i].command) == 0)
			return (p[i].f);
	}
	return (NULL);
}
