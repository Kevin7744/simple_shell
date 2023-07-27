#include "shell.h"

/**
* _help - Checks for requested error page.
*
* Return: always 1
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
* _helperror - Prints error message when help is unavailable.
*/
void _helperror(void)
{
	char *err_s1 = "\nError syntaxe : help [BUILT-IN]\n";
	char *err_s2 = "\n   Built-in command :\n\texit\n\tenv\n\tsetenv";
	char *err_s3 = "\n\tnsetenv\n\tcd\n\n";

	write(STDERR_FILENO, err_s1, 33);
	write(STDERR_FILENO, err_s2, 42);
	write(STDERR_FILENO, err_s3, 15);

}
