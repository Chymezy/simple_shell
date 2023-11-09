#include "shell.h"

/**
 * readline - Reads user input
 *
 * Return: user input pointer.
 */
char *read_line(void)
{
	char *input = NULL;
	size_t size;
	ssize_t r;

	r = getline(&input, &size, stdin);
	if (r == -1)
	{
		free(input);
		exit(0);
	}
	return (input);
}

/**
 * split_input - This splits input str into list of tokens.
 * @input: the string to be splitted
 *
 * Return: returns a pointer.
 */
char **split_input(char *input)
{
	char *token;
	char **tok_address;
	int counter;
	int split_buffer;

	split_buffer = 64;
	counter = 0;
	tok_address = malloc(split_buffer * sizeof(char *));
	if (tok_address == NULL)
	{
		fprintf(stderr, "allocation error in split_input\n");
		exit(1);
	}
	token = strtok(input, DEL);
	while (token != NULL)
	{
		if (token[0] == '#')
			break;
		tok_address[counter] = strdup(token);
		counter++;
		if (counter >= split_buffer)
		{
			split_buffer += split_buffer;
			tok_address = realloc(tok_address, split_buffer * sizeof(char *));
			if (tok_address == NULL)
			{
				fprintf(stderr, "reallocation error in split_input: tok_add\n");
				exit(1);
			}
		}
		token = strtok(NULL, DEL);
	}
	tok_address[counter] = NULL;
	return (tok_address);
}
