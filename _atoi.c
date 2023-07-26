#include "shell.h"

/**
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
