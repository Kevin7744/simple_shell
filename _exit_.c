#include "shell.h"

/**
 * _exit_ - Exit the shell system
 *
 * Return: 0 (succes)
 */
int _exit_(void)
{
	int error_status;
	int i;
	char *error_string = NULL;

	if (array_command[1] == NULL)
	{
		free_all();
		exit(exit_var);
		return (0);
	}
	else
	{
		for (i = 0; array_command[1][i]; i++)
		{
			if (array_command[1][i] < '0' || array_command[1][i] > '9')
			{
				errno = EINVAL;
				perror(error_string);
				return (0);
			}
		}
	}
	error_status = _atoi(array_command[1]);
	free_all();
	exit(error_status);
	return (0);
}
