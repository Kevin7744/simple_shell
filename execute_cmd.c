#include "shell.h"

/**
* _execute - Test and execute a command
*
* Return: Anything, cause void function
*/
void _execute(void)
{
	int (*f)(void), a = 0, b = 0, c = 0;
	struct stat st;

	if (_strcmp(array_command[0], "echo") == 0)
	{
		a = dollar();
		c = xit_stat();
		if (c != 1)
			b = var();
		if (a == 1 || b == 1 || c == 1)
		{
			free_cmd();
			return;
		}
	}
	f = check_built_in(array_command[0]);
	if (f != NULL)
	{
		f();
		free_cmd();
		return;
	}
	else if (cmd_path(array_command[0]) != 1)
	{
		_exevc();
		free_cmd();
		return;
	}
	else if (stat(array_command[0], &st) == 0)
	{
		_exevc();
		free_cmd();
		return;
	}
	else
	{
		err_process();
		exit_var = 127;
		free_cmd();
	}
}

/**
* err_process - Print a error message to STDERR, that explain
* why it doesn't work
*
* Return: Anything, cause void function
*/
void err_process(void)
{
	int i;
	char count;

	for (i = 0; array_command[i]; i++)
		;
	i -= 1;
	while (i >= 0)
	{
		if (i == 0)
		{
			write(STDERR_FILENO, program_name, _strlen(program_name));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, _envget("SHLVL"), 1);
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, array_command[0], _strlen(array_command[0]));
			write(STDERR_FILENO, ": not found\n", 12);
		}
		else
		{
			count = i + 48;
			write(STDERR_FILENO, array_command[i], _strlen(array_command[i]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, &count, 1);
			write(STDERR_FILENO, ": ", 2);
		}
		i--;
	}
}
