#include "shell.h"

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
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
	/*write(STDOUT_FILENO, "\n", 1);*/
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
	/*write(STDOUT_FILENO, "\n", 1);*/
}
