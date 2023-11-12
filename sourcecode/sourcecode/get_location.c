#include "shell.h"

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

	path = _getenv("PATH", state);
	/*path = _getenv(state, "PATH");*/
	if (path)
	{
        	path_copy = strdup(path);
        	command_length = strlen(command);
        	path_token = strtok(path_copy, ":");
		while(path_token != NULL)
		{
            		directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				/* return value of 0 means success implying that the file_path is valid*/
				/* free up allocated memory before returning your file_path */
				free(path_copy);
				return (file_path);
			}
			else
			{
				/* free up the file_path memory so we can check for another path*/
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		/* if we don't get any file_path that exists for the command, we return NULL but we need to free up memory for path_copy */
		free(path_copy);
		/* before we exit without luck, let's see if the command itself is a file_path that exists */
		if (stat(command, &buffer) == 0)
            		return (command);
		return (NULL);
	}
	return (NULL);
}
