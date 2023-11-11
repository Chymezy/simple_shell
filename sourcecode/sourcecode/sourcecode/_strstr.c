#include "shell.h"


/**
 * _strstr - a function tosearch for somthing in the string
 *@haystack: the string to search on it
 *@needle: what we want to search for
 *Return: either NULL or what we searched for
*/

char *_strstr(char *haystack, char *needle)
{
	int i, j;

	for (i = 0; haystack[i] != '\0'; i++)
	{
		for (j = 0; needle[j] != '\0'; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (!needle[j])
			return (&haystack[i]);
	}
	return (NULL);
}
