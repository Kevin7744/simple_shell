#include "shell.h"

/**
* err_tst - default error
* @str: message error
* Return: -1
*/

int err_tst(char *str)
{
	errno = EINVAL;
	perror(str);
	return (-1);
}


/**
* _fread - verif lecture du fichier
* @buf: buffer
* @count: taille maximal
* @filename: nom du fichier
* Return: le poids totals du fichier
*/

size_t _fread(void *buf, size_t count, FILE *filename)
{
	size_t bytes = 0;
	ssize_t readvalue;
	char *p = buf;

	for (; count; p += readvalue, bytes += readvalue, count -= readvalue)
	{
		readvalue = read(fileno(filename), p, count);
		if (readvalue == -1)
		{
			if (errno != EINTR && errno != EAGAIN)
				break;
		}
		else if (readvalue == 0)
			break;
	}

	return (bytes);
}

/**
* f_get_c - Verifie la possibilité de lire le fichier
* @filename: nom  du fichier a tester
* Return: EOF en cas d'erreur de lecture sinon le caractère lu
*/

int f_get_c(FILE *filename)
{
	unsigned char ch;

	return ((_fread(&ch, 1, filename) == 1) ? (int)ch : EOF);
}

/**
* _getlines - Verifie le nombre de caractère sur une ligne spécifique
* @stream: nom  du fichier a de travaille
* @size: taille minimal d'ube ligne
* @lineptr: stock les différente ligne du fichier en mêmoir
* Return: EOF en cas d'erreur de lecture sinon le caractère lu
*/

ssize_t _getlines(char **lineptr, size_t *size, FILE *stream)
{
	int c = 0;
	char *new_ptr = NULL, *cur_pos = NULL;
	size_t count = 0;

	if (lineptr == NULL || size == NULL || stream == NULL)
		return (err_tst("_getline()"));
	if (*lineptr == NULL)
	{
		*size = SPACE_SIZE, *lineptr = (char *)malloc(*size);
		if (*lineptr == NULL)
			return (err_tst("malloc()"));
	}

	for (cur_pos = *lineptr; c != '\n';)
	{
		c = f_get_c(stream);
		if (c == EOF)
			return (-1);
		if (++count > *size)
		{
			*size = (*size) * 2, new_ptr = (char *)_realloc(*lineptr, *size);
			if (new_ptr == NULL)
				return (err_tst("realloc()"));
		}
	}

	*cur_pos = '\0';
	return ((ssize_t)count);
}
