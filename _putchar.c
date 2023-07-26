#include "shell.h"

/**
* _putchar - writes the character c to stdout
*
* @c: The character to print
*
* Return: On success 1.
*/
int _putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
