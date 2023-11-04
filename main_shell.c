#include "shell.h"

/**
 * main - this is the main function
 * @argc: number of arguments that been passed to the main
 * @argv: represents the command and it's arguments
 * @env: represtns global enviroments
 * Return: returns intiger
*/

int main(int argc, char **argv, char **env)
{
	(void)argc;
	char **enviroment = NULL;
	ssize_t n = 0;
	char *buffer = NULL; size_t buffer_size;
	char *token = NULL; char *new_token = NULL;
	int count = 0;
	char *buffer_copy = NULL;
	int i = 0; int j;
	char *key = NULL; char *value = NULL;

	enviroment = env;
	for(i = 0; enviroment[i] != NULL; i++)
		{
			key = strtok(enviroment[i], "=");
			if(_strcmp(key, "PATH") == 0)
			{
				value = strtok(NULL, "=");
				break;
			}
		}

	while(1)
	{
		if (isatty(STDIN_FILENO))
		
			write(1, "$ ", 1);
		n = getline(&buffer, &buffer_size, stdin);
		buffer_copy = malloc(sizeof(char) * buffer_size);
		strcpy(buffer_copy, buffer);
		if (n == -1)
		{
			write(1, "\n", 1);
			break;
		}
		else
		{
			token = strtok(buffer, " \n");
			while(token != NULL)
			{
				count++;
				token = strtok(NULL, " \n");
			}
			count++;
			argv = malloc(sizeof(char *) * count);
			if (argv == NULL)
			{
				free(buffer);
				free(buffer_copy);
				return(-1);
			}
			new_token = strtok(buffer_copy, " \n");
			while(new_token != NULL)
			{
				argv[i] = malloc(sizeof(char) * (strlen(new_token) + 1));
				if(argv[i] == NULL)
				{
					for(j = 0; j < i; j++)
					{
						free(argv[j]);
					}
					free(argv);
					free(buffer);
					free(buffer_copy);
					return(-1);
				}
				strcpy(argv[i], new_token);
				new_token = strtok(NULL, " \n");
				i++;
			}
			argv[i] = NULL;
			_execute(argv[0], argv, value);
			for(i = 0; argv[i] != NULL; i++)
			{
				free(argv[i]);
			}
			free(argv);
			free(buffer);
			free(buffer_copy);
		}	
	}
	return(0);
}

