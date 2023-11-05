#include "shell.h"

/**
 * _strcat - concatination
 * @string: the string we want to add ino
 * @add: what we want to add to the string
 * Return: pointer to the new string
*/
char *_strcat(char *string, char *add)
{
	int i, j;

	for (i = 0; string[i] != '\0'; i++)
	{
		;
	}
	for (j = 0; add[j] != '\0'; i++)
	{
		string[i] = add[j];
		i++;

	}
	string[i] = '\0';
	return (string);
}
/**
 * _strlen - calculate number of characters in a string
 * @string: pointer to string
 * Return: number of characters
 */
int _strlen(char *string)
{
	int i = 0;

	if (string == NULL)
	{
		return (0);
	}

	for (i = 0; string[i] != '\0' ; i++)
	{
		;
	}
	return (i);
}
/**
 * _strcpy - it copies the contect of one string to another
 * @des : where we want to copy into
 * @orig: the string we copy from
 * Return: pointer to the des
 */
char *_strcpy(char *des, char *orig)
{
	int i = 0;

	for (i = 0; orig[i] != '\0'; i++)
	{
		des[i] = orig[i];
	}
	des[i] = '\0';
	return (des);
}
/**
 * _strcmp - compare between two strings
 * @first: the first string
 * @second: the second string
 * Return: 0 if they are equal, or less oer more
 */
int _strcmp(char *first, char *second)
{
	while (*first && *second)
	{
		if (*first != *second)
		{
			return (*first - *second);
		}
		first++;
		second++;
	}
	if (*first == *second)
	{
		return (0);
	}
	else
		return (*first < *second ? -1 : 1);
}
/**
 * starts_with - checks if find starts with str
 * @str: string to search
 * @find: the substring to find
 *
 * Return: address of next char of str or NULL
 */
char *starts_with(const char *str, const char *find)
{
	while (*find)
		if (*find++ != *str++)
			return (NULL);
	return ((char *)str);
}
