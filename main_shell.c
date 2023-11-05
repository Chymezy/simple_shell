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
	char *buffer = NULL;
	size_t buffer_size;
	char *token = NULL; char *new_token = NULL;
	int count = 0;
	char *buffer_copy = NULL;
	int i = 0; int j;
	char *key = NULL; char *value = NULL;

	enviroment = env;
	for(i = 0; enviroment[i] != NULL; i++)
		{
			key = strtok(enviroment[i], "=");
			if(strcmp(key, "PATH") == 0)
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
		printf("this is the buffer : %s", buffer);
		buffer_copy = malloc(sizeof(char) * buffer_size);
		_strcpy(buffer_copy, buffer);
		printf("this is buffer_copy: %s", buffer_copy);
		if (n == -1)
		{
			write(1, "\n", 1);
			break;
		}
		token = strtok(buffer, " \n\t");
		printf("this is command token :%s\n", token);
		while(token != NULL)
		{
			count++;
			token = strtok(NULL, " \n\t");
			printf("this is arguments tokens :%s\n", token);
		}
		count++;
		argv = malloc(sizeof(char *) * count);
		if (argv == NULL)
		{
			free(buffer);
			printf(" buffer after free is now : %s", buffer);
			free(buffer_copy);
			perror("ERROR: memory can't be allocated");
			return(-1);
		}
		new_token = strtok(buffer_copy, " \n\t");
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
				perror("ERROR: memory can't be allocated");
				return(-1);
					
			}
			_strcpy(argv[i], new_token);
			printf("this is argv[i] after strcpy: %s\n", argv[i]);

			new_token = strtok(NULL, " \n\t");
			i++;
		}
		argv[i] = NULL;
		for(i= 0; argv[i] != NULL; i++)
		{
			printf(" this is argv before execution %s\n", argv[i]);
		}
		execve(argv[0], argv, NULL);
		/*for(i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
		free(buffer);
		free(buffer_copy);*/
	}
	for(i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
		printf("this argv[i] after free %s\n", argv[i]);
	}
	free(argv);
	printf(" this is argv after free : %p\n", argv);
	free(buffer);
	printf(" this is buffer after free %s\n", buffer);
	free(buffer_copy);
	printf("this is buffer_copy after free %s\n", buffer_copy);
	return(0);
}
