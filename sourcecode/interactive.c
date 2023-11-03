#include "command.h"
#include <stddef.h>

int is_interactive(state_t *data)
{
  return (isatty(STDIN_FILENO) && data->fd <= 2);
}

void clean_shell_data(state_t *data)
{
  data->get_arg = NULL;
  data->argv = NULL;
}

ssize_t get_input(state_t *data)
{
  data->get_arg = NULL;
  size_t size = 0, return_value;

  return_value = getline(&data->get_arg, &size, stdin);
  return (return_value);
}
/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delimiter(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
