#include "shell.h"

/**
 * run_shell - This the shell loop
 * @state: commandline vector
 * Return: void
 */
void run_shell(state_t *state)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive(state);
	}
	else
	{
		non_interactive(state);
	}
}

/**
 * interactive - This function handles interct. mode of shell
 * @state: the argument vector;
 *
 * Return void
 */
void interactive(state_t *state)
{
	char *prompt = "$ ";
	char *input = NULL;
	char **input_string = NULL;
	int status = -1;
	int i = 0;

	while (1)
	{
		printString(prompt);
		if (input != NULL)
			free(input);
		input = read_line();
		input_string = split_input(input);
		status = exec(state, input_string);
		i = 0;
		while (input_string[i] != NULL)
		{
			free(input_string[i]);
			i++;
		}
		free(input_string);
		if (status >= 0)
			exit(status);
	}
}
/**
 * non_interactive - This function handles non-interct mode of shell
 * @state: the argument vector
 *
 * returns void
 */
void non_interactive(state_t *state)
{
	char *input = NULL;
	char **input_string = NULL;
	int status;
	int i = 0;

	input = read_line();
	input_string = split_input(input);
	status = exec(state, input_string);
	free(input);
	while (input_string[i] != NULL)
	{
		free(input_string[i]);
		i++;
	}
	free(input_string);
	if (status >= 0)
		exit(status);
}
