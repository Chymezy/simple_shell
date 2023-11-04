#include "shell.h"

/**
 * _strdup - function used to duplicate strings
 * @des: vjchg
 * @orig: jh,vghv
 * Return: pointer to des  
*/

char *_strdup(char *des, char *orig)
{
	int i = 0;

	des = malloc(sizeof(char) * (_strlen(orig) + 1));
	for(i = 0; orig[i] != NULL; i++)
	{
		des[i] = orig[i];
	}
	des[i] = '\0';
	return(des);
}
