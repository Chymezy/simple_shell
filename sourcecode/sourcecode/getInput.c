#include "shell.h"

/**
 * read_line - Reads user input
 *
 * Return: user input pointer.
 */
char *read_line(void)
{
	char *input = NULL;
	size_t size;
	ssize_t r;

	r = 0;
	size = 0;
	r = getline(&input, &size, stdin);
	if (r == -1)
	{
		free(input);
		write(1, "\n", 1);
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
	char *token = NULL;
	char **tok_address = NULL;
	int counter = 0;
	int split_buffer = 64;

	tok_address = malloc(split_buffer * sizeof(char *));
	if (tok_address == NULL)
	{
		fprintf(stderr, "allocationn error in split_input");
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
