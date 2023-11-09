#include "shell.h"

/**
 * run_shell - This the shell loop
 * @argv: commandline vector
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
 * @argv: the argument vector;
 *
 * Return void
 */
void interactive(state_t *state)
{
	char *prompt = "$ ";
	char *input;
	char **input_string;
	int status = -1;
	int i;

	do {
		/*write(STDOUT_FILENO, sizeof(prompt), _strlen(prompt));*/
		printf("%s", prompt);
		_getenv(state, "PATH");
		printf("%s\n", state->shell_name);
		input = read_line();
		input_string = split_input(input);
		status = exec(state, input_string);
		free(input);
		i = 0;
		while (input_string[i] != NULL)
		{
			free(input_string[i]);
			i++;
		}
		free(input_string);
		if (status >= 0)
			exit(status);
	} while (status == -1);
}
/**
 * non_interactive - This function handles non-interct mode of shell
 * @argv: the argument vector
 *
 * returns void
 */
void non_interactive(state_t *state)
{
	(void)state;
	printf("Yet to be implemented\n");
}
