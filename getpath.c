#include "shell.h"
/**
 * getpath - to get the whole path of the command
 * @command: the command we need to get the path of it
 * @paths: equal to the value of PATH
 * Return: pointer to the wgole path of the command
*/
char *getpath(char *command, char *paths)
{
	int commandlength = 0, directorylen = 0;
	char *pathToken_shell = NULL, *wholefile_path = NULL;
	char *copy;
	struct stat file_status;

	copy = malloc(sizeof(char) * (strlen(paths) + 1));
	strcpy(copy, paths);
	commandlength = strlen(command);
	pathToken_shell = strtok(copy, ":");
	while (pathToken_shell != NULL)
	{
		directorylen = _strlen(pathToken_shell);
		wholefile_path = malloc(sizeof(char) * (directorylen + commandlength + 2));
		strcpy(wholefile_path, pathToken_shell);
		strcat(wholefile_path, "/");
		strcat(wholefile_path, command);
		strcat(wholefile_path, "\0");
		if (stat(wholefile_path, &file_status) == 0)
		{
			//free(copy);
			return (wholefile_path);
		}
		else
		{
			//free(wholefile_path);
			pathToken_shell = strtok(NULL, ":");
		}
	}
	//free(copy);
	if (stat(command, &file_status) == 0)
		return (command);
	return (NULL);
}
