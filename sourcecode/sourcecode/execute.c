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
			perror(state->shell_name);
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
		/*while (!WIFEXITED(status) && !WIFSIGNALED(status))
		{
			waitpid(get_pid, &status, WUNTRACED);
		};*/
		wait(&status);
	}
	return (-1);
}
char *_getenv(state_t *state, char *enviroment)
{
	char **env_copy;
	int i;
	int count;
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
		if(strcmp(key, enviroment) == 0)
		{
			value = strtok(NULL, "=");
			break;
		}
	}
	/*for (i = 0; env_copy[i] != NULL; i++)
	{
		free(env_copy[i]);
	}*/
	return (value);
}
