#include "shell.h"

/**
* _setenv_real - Get the env variable index, then malloc a
* new place and free the old one
*
* @name: Name of the env var
*
* Return: i, the index of the existing var env.
*/
int _setenv_real(char *name)
{
	int i, j;

	for (i = 0; new_env[i]; i++)
	{
		for (j = 0; new_env[i][j] != '='; j++)
		{
			if (new_env[i][j] != name[j])
				break;
		}
		if (new_env[i][j] == '=')
			break;
	}
	free(new_env[i]);
	return (i);
}

/**
* _setenv_unreal - Malloc a new place at the end of all
* env variable 2D array.
*
* Return: The index of the new var
*/
int _setenv_unreal(void)
{
	int i;

	for (i = 0; new_env[i]; i++)
		;
	new_env = _realloc_ptr(new_env, sizeof(char *) * (i + 2));
	if (!new_env)
		_exit_();
	new_env[i + 1] = NULL;
	return (i);
}

/**
* _envnew - init a new env variable
*
* @i: Index of the new_env var
*
* Return: Anything, cause void fucntion
*/
void _envnew(int i)
{
	int j, k;

	for (j = 0; array_command[1][j]; j++)
		new_env[i][j] = array_command[1][j];
	new_env[i][j] = '=';
	for (k = 0, j++; array_command[2][k]; j++, k++)
		new_env[i][j] = array_command[2][k];
	new_env[i][j] = '\0';
}

/**
* _setenverr - Printf the correct syntaxe of setenv
*
* Return: Anything, cause void function.
*/
void _setenverr(void)
{
	write(STDERR_FILENO, "Error syntaxe : setenv var value\n", 33);
}
