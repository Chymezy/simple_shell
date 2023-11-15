#include "shell.h"

/**
 * _env - builtin env()
 * @state: struct conation global enviroment
 * Return: pointer to strings
*/
int _env(state_t *state)
{
	int i;

	for (i = 0; state->env[i] != NULL; i++)
	{
		write(1, state->env[i], strlen(state->env[i]));
		write(1, "\n", 1);
	}
	return (0);

}
/**
 *_exit_t - exit shell
 *Return: void
*/
void _exit_t(void)
{

	exit(0);
}
