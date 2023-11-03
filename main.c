#include "command.h"

int main(int ac, char **av)
{
<<<<<<< HEAD
    state_t data[] = { DATA_INIT };
    (void)ac; (void)av;
    
    shell_loop(data, av);
    
    return (0);
=======
	(void)argc;
	char **enviroment = NULL;
	/*char prompt = "$ ";*/
	ssize_t n = 0;
	char *buffer = NULL;
	size_t buffer_size;
	char *token = NULL;
	char *new_token = NULL;
	int count = 0;
	char *buffer_copy = NULL;
	int i = 0;
	int j;
	char *key = NULL;
	char *value = NULL;

	while(1)
	{
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
		if (isatty(STDIN_FILENO))
		
			write(1, "$ ", 1);
		n = getline(&buffer, &buffer_size, stdin);
		buffer_copy = malloc(sizeof(char) * buffer_size);
		strcpy(buffer_copy, buffer);
		if (n == -1)
		{
			write(1, "\n", 1);
			/*free(buffer);
			free(buffer_copy);
			return (-1);*/
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
>>>>>>> 40142db55b204238a1602246e4729334d39fc750
}

