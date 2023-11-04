#include "shell.h"

/**
 * _strcpy - it copies the contect of one string to another
 * @des : where we want to copy into
 * @orig: the string we copy from
 * Return: pointer to the des
*/

char *_strcpy( char *des, char *orig)
{
	int i =0;

	for(i = 0; orig[i] != '\0'; i++)
	{
		des[i] = orig[i];
	}
	des[i] = '\0';
	return(des);

}
