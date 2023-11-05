#include "shell.h"

/**
 *
 *
 */
char *readline(void);
{
	char *input = NULL;
	size_t size;
	ssize_t r;

	r = getline(&input, &size, stdin);
	if(r == -1)
	{
		free(input);
		exit(0);
	}
	else
	{
		input = check_comment(input);
		return (input);
	}

}

/**
 * check_comment - This searches for comments input str.
 * @input: the string to search
 *
 * Return: returns a pointer.
 */
char *check_comment(char *input)
{
	char *comment_point;
	comment_point = _strstr(input, " #");
	
	if (comment_point)
	{
		*comment_point = '\0';
	}
	return (input);
}
