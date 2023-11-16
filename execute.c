#include "shell.h"

/**
 * exec - executes input_string
 * @input_string: contains command and flags.
 * @state: instance of state struct
 * Return: 1 on sucess or 0 on failure
 */
int exec(state_t *state, char **input_string)
{

	if (input_string[0] == NULL)
	{
		return (-1);
	}
	return (fork_process(state, input_string));
}

/**
 * fork_process - creates a child process
 * @state: struct
 * @input_string: contains command and flags
 *
 * Return: 1 on success or ) on failure
 */
int fork_process(state_t *state, char **input_string)
{
	pid_t get_pid;
	char *command, *actual_command;
	int i, status;

	command = NULL;
	actual_command = NULL;
	status = 0;
	get_pid = fork();
	if (get_pid == 0)
	{
		command = input_string[0];
		if (_strcmp(command, "env") == 0)
			_env(state);
		if (_strcmp(command, "exit") == 0)
		{
			exit(0);
		}
		actual_command = get_location(state, command);
		if (actual_command == NULL)
		{
			printString(state->shell_name);
			printString(": 1: not found");
			printString("\n");
			return(-1);
		}
		if (execve(actual_command, input_string, NULL) == -1)
		{
			/*write(1, state->shell_name, _strlen(state->shell_name));
			write(1, ": 1: ", 5);
			write(1, command, _strlen(command));
			write(1, ": not found\n", 12);*/
			i = 0;
			while (input_string[i] != NULL)
			{
				free(input_string[i]);
				i++;
			}
			free(input_string);
			exit(127);
		}
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

/**
 * _getenv - custmize function for getenv()
 * @name: name of the enviroment
 * @state: struct the contain global enviroment
 * Return: value of the enviroment
*/

char *_getenv(char *name, state_t *state)
{
	char **env_copy = NULL;
	int i = 0;
	int count = 0;
	char *key = NULL, *value = NULL;

	count = 0;
	key = NULL;
	value = NULL;
	for (i = 0; state->env[i] != NULL; i++)
		count++;
	count++;
	env_copy = malloc(sizeof(char *) * count);
	for (i = 0; state->env[i] != NULL; i++)
	{
		env_copy[i] = malloc(sizeof(char) * (strlen(state->env[i]) + 1));
		_strcpy(env_copy[i], state->env[i]);

	}
	env_copy[i] = NULL;
	for (i = 0; env_copy[i] != NULL; i++)
	{
		key = strtok(env_copy[i], "=");
		if (_strcmp(key, name) == 0)
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
