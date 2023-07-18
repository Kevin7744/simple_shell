#include "shell.h"

/**
* _help - Check the help, refer to help function
*
* Return: 1 succes
*/
int _help(void)
{
	if (array_command[2] == NULL)
	{
		if (_strcmp(array_command[1], "exit") == 0)
			_helpexit();
		else if (_strcmp(array_command[1], "env") == 0)
			_helpenv();
		else if (_strcmp(array_command[1], "setenv") == 0)
			_helpsetenv();
		else if (_strcmp(array_command[1], "unsetenv") == 0)
			_helpunsetenv();
		else
			_helperror();
	}
	else
		_helperror();
	return (1);
}

/**
* _helperror - Print the error
*
* Return: Anything, cause void function
*/
void _helperror(void)
{
		write(STDERR_FILENO, "\nError syntaxe : help [BUILT-IN]\n", 33);
		write(STDERR_FILENO, "\n   Built-in command :\n\texit\n\tenv\n\tsetenv", 42);
		write(STDERR_FILENO, "\n\tnsetenv\n\tcd\n\n", 15);

}
