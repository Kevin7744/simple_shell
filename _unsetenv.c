#include "shell.h"

/**
* _unsetenv - Erased a env var, in fact just replace it by '\0'
* which is not printed when env
*
* Return: 0 (succes), -1 if any issues
*/
int _unsetenv(void)
{
	int i, j;

	if (array_command[1] == NULL)
	{
		write(STDERR_FILENO, "Error syntaxe : unsetenv VAR_NAME\n", 34);
		return (-1);
	}
	for (i = 0; new_env[i]; i++)
	{
		for (j = 0; new_env[i][j] != '='; j++)
		{
			if (new_env[i][j] != array_command[1][j])
				break;
		}
		if (new_env[i][j] == '=')
			break;
	}
	if (new_env[i] == NULL)
	{
		write(STDERR_FILENO, "var not found\n", 14);
		return (-1);
	}
	new_env[i][0] = '\0';
	return (0);
}
