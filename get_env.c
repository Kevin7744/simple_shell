#include "shell.h"

/**
 * _envget - Get the value of an env variable
 *
 * @env: Env variable's name
 *
 * Return: The pointer to the value of the env varaible asked, NULL else
 */
char *_envget(const char *env)
{
	int i, j;

	for (i = 0; new_env[i]; i++)
	{
		for (j = 0; new_env[i][j] != '='; j++)
		{
			if (new_env[i][j] != env[j])
				break;
		}
		if (new_env[i][j] == '=')
			break;
	}
	if (new_env[i] == NULL)
		return (NULL);
	for (j = 0; new_env[i][j] != '='; j++)
		;
	j++;
	return ((*(new_env + i) + j));
}
