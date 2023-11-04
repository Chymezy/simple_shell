#include "shell.h"


/**
 * _execute - function that executes commands
 * @command: the command
 * @argv: array that conntains the command and it's arguments
 * @paths: holds all the directories in the global enviroments
 * Return: nothinh
*/

void _execute(char *command, char **argv, char *paths)
{
	pid_t child_process;
	char *command_path;
	int status;
	
	command_path= getpath(command, paths);

	child_pid = fork();
	if(child_pid == -1)
	{
		perror("ERROR: process couldn't be created");
		exit(1);
	}
	if(execve(command_path, argv, NULL) == -1)
	{
		perror("ERROR: command couldn't be found");
		exit(0);

	}
	else
	{
		wait(&status)
	}


}

