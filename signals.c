#include "shell.h"

/**
* handl_sigs - Catch a Ctrl - C
*
* @i: Useless parameter
*
* Return: Anything, cause void function
*/
void handl_sigs(__attribute__((unused)) int i)
{
	write(STDOUT_FILENO, "\n", 1);
	_prompt();
}
