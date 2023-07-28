#include "shell.h"

/**
 * _perror - Modified version of perror.
 *
 * @function_name: Name of calling function.
 */

void _perror(char *function_name)
{
	char *error_string = NULL, *temp_string = NULL;


	temp_string = _strcat(program_name, ": ");
	error_string = _strcat(temp_string, _envget("SHLVL"));
	free(temp_string);
	temp_string = error_string;
	error_string = _strcat(temp_string, ": ");
	free(temp_string);
	temp_string = error_string;
	error_string = _strcat(temp_string, function_name);
	free(temp_string);
	perror(error_string);
	free(error_string);
}
