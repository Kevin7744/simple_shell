#include "shell.h"

/**
* _envprint - Print the env varaible
*
* Return: 0 (succes)
*/
int _envprint(void)
{
	int i;

	if (array_command[1] != NULL)
	{
		write(STDERR_FILENO, "Error syntaxe : env\n", 20);
		return (0);
	}

	for (i = 0; new_env[i]; i++)
	{
		if (new_env[i][0] != '\0')
		{
			write(STDOUT_FILENO, new_env[i], _strlen(new_env[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	return (0);
}
