#include "shell.h"

/**
<<<<<<< HEAD
 * interactive - returns true if shell is in interactive mode
 * @info: param - it is the struct address
 *
 * Return: 1 if interactive mode and 0 if otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if the character is delimeter
 * @c: param - character to check
 * @delim: param - is the delimeter string
 * Return: 1 if true and 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: param - character to input
 * Return: 1 if c is alphabetic and 0 if otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: param - is the string to be converted
 * Return: 0 if no numbers are in the string and converted number if otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

=======
 * _atoi - Convert the first number of a str to an interger.
 *
 * @s: String inputed.
 *
 * Return: 0 if there are no number, the interger based on the number.
 */
int _atoi(char *s)
{
	int counter = 0, sign = 1;
	unsigned int num = 0;

	while ((s[counter] > '9' || s[counter] < '0') && s[counter] != '\0')
	{
		if (s[counter] == '-')
		{
			sign *= -1;
		}
		counter++;
	}
	while (s[counter] <= '9' && s[counter] >= '0')
	{
		num = num * 10 + (s[counter] - '0');
		counter++;
	}
	return (num * sign);
}
>>>>>>> 1ff7b7d9550ce6ec363dbd58a267d2a8d3d92874
