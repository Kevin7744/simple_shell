#include "shell.h"

/**
 * _envcpy - Copy the env given.
 *
 * @env: Env of the parent process
 *
 * Return: Anything, cause void function
 */
void _envcpy(char **env)
{
	int i, length;

	for (length = 0; env[length]; length++)
		;

	new_env = malloc(sizeof(char *) * (length + 2));
	if (!new_env)
		return;

	for (i = 0; env[i]; i++)
	{
		new_env[i] = _strdup(env[i]);
		if (!new_env[i])
		{
			for ( ; i >= 0; i--)
				free(new_env[i]);
			free(new_env);
			return;
		}
	}
	new_env[i] = NULL;
}
