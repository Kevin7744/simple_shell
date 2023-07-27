#include "shell.h"

/**
* usr_input - Put a '\0' at the end of the input
* and check if there is any comment
*
* Return: Anything, cause void function
*/
void usr_input(void)
{
	int i = 0;

	for (i = 0; user_input[i]; i++)
		;
	if (user_input[i - 1] == '\n')
		user_input[i - 1] = '\0';
	sep_to_space();
	for (i = 0; user_input[i]; i++)
	{
		if (user_input[i] == '#' && user_input[i - 1] == ' ')
		{
			user_input[i] = '\0';
		}
	}
}
