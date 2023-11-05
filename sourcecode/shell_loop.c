#include "shell.h"

/**
 * run_shell - This the shell loop
 * Return: void
 */
void run_shell(char **argv)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive(argv);
	}
	else
	{
		non_interactive(argv);
	}
}

/**
 * interactive - This function handles interct. mode of shell
 * @argv: the argument vector;
 * Return: void
 */
void interactive(char **argv)
{
	char *prompt = "$ ";
	char *input;
	char **input_string;
	int status = exec(input_string);
	
	do
	{
		write(STDOUT_FILENO, sizeof(prompt), _strlen(prompt));
	
		input = read_line();
		input_string = split_input();
	
		free(input);
		free(input_string);
	} while (status == -1);
}
