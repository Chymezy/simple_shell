#include "shell.h"

/**
 * readline - Reads user input
 *
 * Return: user input pointer.
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
/**
 *
 */
char **split_input(char *input)
{
	char *token;
	char **tok_address;
	int counter;
	char *input_cpy;

	input _cpy = _strdup(input); /* Rember to free _strdup) */
	token = strtok(input,
}
