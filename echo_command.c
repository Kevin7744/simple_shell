#include "shell.h"

/**
* prt_num - print number given
*
* @number: number to print
*
* Return: Anything, cause void function
*/
void prt_num(unsigned int number)
{
	if (number > 10)
		prt_num(number / 10);
	_putchar(number % 10 + '0');
}

/**
* dollar - Check if the command is "echo $$", then
* if it's the case, printf the pid
*
* Return: 1 succes, 0 not find
*/
int dollar(void)
{
	pid_t my_pid = getpid();

	if (_strcmp(array_command[1], "$$") == 0)
	{
		prt_num(my_pid);
		write(STDOUT_FILENO, "\n", 1);
		exit_var = 0;
		return (1);
	}
	return (0);
}

/**
* var - Check if the command is "echo $env_var", then
* if it's the case, printf the env_var value.
*
* Return: 1 succes, 0 not find
*/
int var(void)
{
	char *env;

	if (array_command[1][0] == '$')
	{
		env = _envget(*(array_command + 1) + 1);
		if (env != NULL && _strcmp(env, "?") != 0)
		{
			write(STDOUT_FILENO, env, _strlen(env));
			write(STDOUT_FILENO, "\n", 1);
			exit_var = 0;
			return (1);
		}
	}
	return (0);
}

/**
* xit_stat - Print the exit status of a command
*
* Return: 1 if it's work, 0 else
*/
int xit_stat(void)
{
	if (_strcmp(array_command[1], "$?") == 0)
	{
		prt_num(exit_var);
		write(STDOUT_FILENO, "\n", 1);
		exit_var = 0;
		return (1);
	}
	return (0);
}
