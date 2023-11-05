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

	for(i = 0; string[i] != '\0'; i++)
	{
		;
	}
	for(j = 0; add[j] != '\0'; i++)
	{
		string[i] = add[j];
		i++;

	}
	string[i] = '\0';
	return(string);
}
