#include "shell.h"

/**
 * main - this is the main shell
 * @argc: the command line argument count
 * @argv: the command line argument vector
 * Return: 0 on success and -1 on failure
 */
int main(int argc, char **argv, char **env)
{
	state_t state[] = { STATE_INIT };

	state->env = env;
	state->shell_name = argv[0];
	(void)argc;
	run_shell(state);

	return (0);
}
