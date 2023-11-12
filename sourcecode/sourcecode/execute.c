#include "shell.h"

/**
 * exec - executes input_string
 * @input_string: contains command and flags.
 * @state: instance of state struct
 * Return: 1 on sucess or 0 on failure
 */
int exec(state_t *state, char **input_string)
{
	/*int i;
	char *builtin_t[];
	int (*builtin_t[])(char **);

	builtin_t = {"cd", "env", "help", "exit"};
	int (*builtin_t[])(char **) = {&_cd, &_env, &_help, &_exit};*/

	if (input_string[0] == NULL)
	{
		return (-1);
	}
	/*for (; i < sizeof(builtin_t) / sizeof(char *); i++)
	{
		if (strcmp(input_string[0], builtin_t[i]) == 0)
			return ((*builtin_t[i](input_string)));
	}*/
	return (fork_process(state, input_string));
}
/**
 * fork_process - creates a child process
 * @input_string: contains command and flags
 *
 * Return: 1 on success or ) on failure
 */
int fork_process(state_t *state, char **input_string)
{
	pid_t get_pid;
	char *command, *actual_command;
	int status;

	command = NULL;
	actual_command = NULL;
	status = 0;
	get_pid = fork();
	if (get_pid == 0)
	{
		command = input_string[0];
		actual_command = get_location(state, command);
		if (execve(actual_command, input_string, NULL) == -1)
		{
			write(2, state->shell_name, strlen(state->shell_name));
			write(2, ": 1: ", 5);
			write(2, command, strlen(command));
			write(2, ": not found\n", 12);
			exit(127);
		}
		/*exit(1);*/
	}
	else if (get_pid < 0)
	{
		printf("%s", state->shell_name);
		perror("error forking");
	}
	else
	{
		wait(&status);
	}
	return (-1);
}
char *_getenv(char *name, state_t *state)
{
	char **env_copy;
	int i = 0;
	int count = 0;
	char *key, *value;

	count = 0;
	key = NULL;
	value = NULL;
	for (i = 0; state->env[i] != NULL; i++)
		count++;
	count++;
	env_copy = malloc(sizeof(char *) * count);
	for (i = 0; state->env[i] != NULL; i++)
	{
		env_copy[i] = state->env[i];
	}
	env_copy[i] = NULL;
	for(i = 0; env_copy[i] != NULL; i++)
	{
		key = strtok(env_copy[i], "=");
		if(strcmp(key, name) == 0)
		{
			value = strtok(NULL, "=");
			break;
		}
	}
	for (i = 0; env_copy[i] != NULL; i++)
	{
		free(env_copy[i]);
	}
	free(env_copy);
	return (value);
}
