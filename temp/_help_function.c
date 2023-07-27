#include "shell.h"


/**
* _helpexit - Print the help page
*
* Return: Anything, cause void function
*/
void _helpexit(void)
{
	write(STDOUT_FILENO, "\nEXIT BUILT-IN\n", 15);
	write(STDOUT_FILENO, "\n\tExit the shell programm, free all the malloc", 46);
	write(STDOUT_FILENO, " var\n\t Can exit with a code status.\n", 36);
	write(STDOUT_FILENO, "\n\tSynthaxes :\n\t exit\n\t\texit without exit", 40);
	write(STDOUT_FILENO, " code\n\t exit 98\n\t\texit with the code 98", 39);
	write(STDOUT_FILENO, "\n\n", 2);
}

/**
* _helpenv - Print the help page
*
* Return: Anything, cause void function
*/
void _helpenv(void)
{
	write(STDOUT_FILENO, "\nENV BUILT-IN\n", 14);
	write(STDOUT_FILENO, "\n\tPrint all the environement variable\n", 38);
	write(STDOUT_FILENO, "\n\tSyntaxe :\n\t env\n\n", 19);
}

/**
* _helpsetenv - Print the help page
*
* Return: Anything, cause void function
*/
void _helpsetenv(void)
{
	write(STDOUT_FILENO, "\nSETENV BUILT-IN\n", 17);
	write(STDOUT_FILENO, "\n\tSet a new environement variable\n", 34);
	write(STDOUT_FILENO, "\n\t If the varaible exist, just replace the ", 43);
	write(STDOUT_FILENO, "value\n\tSyntaxe :\n\t setenv VAR VALUE\n\n", 37);
}

/**
* _helpunsetenv - Print the help page
*
* Return: Anything, cause void function
*/
void _helpunsetenv(void)
{
	write(STDOUT_FILENO, "\nUNSETENV BUILT-IN\n", 19);
	write(STDOUT_FILENO, "\n\tUnset a new environement variable\n", 36);
	write(STDOUT_FILENO, "\n\tSyntaxe :\n\t unsetenv VAR\n\n", 28);
}
