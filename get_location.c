#include "shell.h"

/**
 * get_location - search for files
 * @state: strcture
 * @command: the command we searched for
 * Return: pointer
*/

char *get_location(state_t *state, char *command)
{
	char *path = NULL;
	char *path_copy = NULL;
	char *path_token = NULL;
	char *file_path = NULL;
	int command_length = 0;
	int directory_length = 0;
	struct stat buffer;

	(void)state;
	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		command_length = strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}
