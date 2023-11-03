#include "shell_m_u.h"
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

	copy = malloc(sizeof(char) * (_strlen(paths) + 1));
	_strcpy(copy, paths);
	commandlength = _strlen(command);
	pathToken_shell = strtok(copy_ptr, ":");
	while (pathToken_shell != NULL)
	{
		directorylen = _strlen(pathToken_shell);
		wholefile_path = malloc(sizeof(char) * (directorylen + commandlength + 2));
		_strcpy(wholefile_path, pathToken_shell);
		_strcat(wholefile_path, "/");
		_strcat(wholefile_path, command);
		_strcat(wholefile_path, "\0");
		if (stat(wholefile_path, &file_status) == 0)
		{
			free(copy);
			return (wholefile_path);
		}
		else
		{
			free(copy);
			free(wholefile_path);
			pathToken_shell = strtok(NULL, ":");
		}
	}
	free(copy);
	if (stat(command, &file_status) == 0)
		return (command);
	return (NULL);
}
