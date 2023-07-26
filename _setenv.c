#include "shell.h"

/**
* _setenv - Set an env variable, create it if not exit, else
* change the value
*
* Return: 0 (succes), 1 else. If malloc issues, exit.
*/
int _setenv(void)
{
	int i;
	int length;

	if (array_command[1] == NULL || array_command[2] == NULL)
	{
		_setenverr();
		return (-1);
	}
	if (_envget(array_command[1]) != NULL)
		i = _setenv_real(array_command[1]);

	else
		i = _setenv_unreal();
	length = _strlen(array_command[1]) + _strlen(array_command[2]) + 2;
	new_env[i] = malloc(sizeof(char) * length);
	_envnew(i);
	return (0);
}
