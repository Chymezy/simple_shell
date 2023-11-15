#include "shell.h"

/**
 * _strdup - duplicates a string
 * @src: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(char *src)
{
	size_t length;
	char *dest;

	if (src == NULL)
	{
		errno = EINVAL;
		return (NULL);
	}
	length = _strlen(src);
	dest = (char *)malloc(length + 1);

	if (dest == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	_strcpy(dest, src);
	return (dest);
}
/**
 * printString - Prints strings to stdout
 * @str: The string to print
 * returns void
 */
void printString(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	write(STDOUT_FILENO, str, len);
}
/**
 * errorPrint - Prints strings to stdout
 * @str: The string to print
 * returns void
 */
void errorPrint(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	write(STDERR_FILENO, str, len);
}
