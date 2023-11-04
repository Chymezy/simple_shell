#include "shell.h"

/**
 * _strcmp - compare between two strings
 * @first: the first string
 * @second: the second string
 * Return: 0 if they are equal, or less oer more
*/

int _strcmp(char *first, char *second)
{
	while(*first == *second)
	{
		if(*first == '\0')
		{
			return(0);
		}
		first++;
		second++;
	}
	return(*first - *second);
}
