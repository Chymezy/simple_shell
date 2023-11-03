#include "command.h"

int shell_loop(state_t *data, char **av)
{
	(void)av;

	int return_value = 0;
	char *prompt = "$ ";
	//size_t size = 0;

	while (return_value != -1)
    {
		fflush(stdin);
		clean_shell_data(data);

		if (is_interactive(data))
        {
			printf("%s", prompt);

			// Use getline to get input and check for success.
			return_value = get_input(data);

			if (return_value == -1) {
				// Handle getline error or end of input.
				printf("Exiting shell...\n");
				free(data->get_arg);
				return(-1);
			}

			set_data(data, av);
		}
		free(data->get_arg);
	}

	// Free cmd->get_arg when you're done with it.
	free(data->get_arg);

	return (return_value);
}

