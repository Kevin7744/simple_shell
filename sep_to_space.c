#include "shell.h"

/**
* sep_to_space - Change \t and \r into a space
*
* Return: Anything, cause void function
*/
void sep_to_space(void)
{
	int i;

	for (i = 0; user_input[i]; i++)
	{
		if (user_input[i] == '\t' || user_input[i] == '\r' || user_input[i] == '\n')
			user_input[i] = ' ';
	}
}
