#include "shell.h"

/**
* _prompt - Prompt the PWD env var, and $, to make our
* simple shell realistic
*
* Return: Anything, cause void function
*/
void _prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, _envget("PWD"), _strlen(_envget("PWD")));
		write(STDOUT_FILENO, "$ ", 2);
	}
}
