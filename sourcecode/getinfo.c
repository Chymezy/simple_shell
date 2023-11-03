#include "command.h"

void set_data(state_t *data, char **av)
{
    int i;

    data->program_name = av[0];

    if (data->get_arg != NULL)
    {
        data->argv = split_string(data->get_arg, " \t");
        if(data->argv == 0)
        {
            data->argv = malloc(sizeof(char *) * 2);
            if (data->argv != NULL)
            {
                data->argv[0] = strdup(data->get_arg);
                data->argv[1] = NULL;
            }
        }
        for (i = 0; data->argv && data->argv[i]; i++)
        {
            ;
        }
        data->num_args = i;
    }
    printf("I'm in set_data function\n");
    printf("argv: %s", data->argv[0]);
    printf("word count: %d", data->num_args);

}
