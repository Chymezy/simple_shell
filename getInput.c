#include "shell.h"

/**
 * read_line - Reads user input
 *
 * Return: user input pointer.
 */
char *read_line(void)
{
	char *input = NULL;
	size_t size;
	ssize_t r;

	r = 0;
	size = 0;
	r = getline(&input, &size, stdin);
	if (r == -1)
	{
		free(input);
		write(1, "\n", 1);
		exit(0);
	}
	return (input);
}

/**
 * split_input - This splits input str into list of tokens.
 * @input: the string to be splitted
 *
 * Return: returns a pointer.
 */
char **split_input(char *input)
{
	char *token = NULL;
	char **tok_address = NULL;
	int counter = 0;
	int split_buffer = 64;

	tok_address = malloc(split_buffer * sizeof(char *));
	if (tok_address == NULL)
	{
		errorPrint("allocationn error in split_input");
		errorPrint("\n");
		exit(1);
	}
	token = strtok(input, DEL);
	while (token != NULL)
	{
		if (token[0] == '#')
			break;
		tok_address[counter] = _strdup(token);
		counter++;
		if (counter >= split_buffer)
		{
			split_buffer += split_buffer;
			tok_address = realloc(tok_address, split_buffer * sizeof(char *));
			if (tok_address == NULL)
			{
				errorPrint("reallocation error in split_input: tok_add");
				errorPrint("\n");
				exit(1);
			}
		}
		token = strtok(NULL, DEL);
	}
	tok_address[counter] = NULL;
	return (tok_address);
}
/**
 * _memcpy - Copy memory area
 * @target: Destination pointer to the target array where the content is to be
 * copied
 * @source: Source pointer to the source of data to be copied
 * @size: Number of bytes to copy
 *
 * Return: This function returns a pointer to the destination, which is target.
 */
void *_memcpy(void *target, const void *source, size_t size)
{
	const char *s;
	char *t;	

	if (target == NULL || source == NULL)
		return (NULL);

	t = (char *)target;
	s = (const char *)source;

	if (t <= s || t >= (s + size))
	{
		while (size--)
		{
			*t++ = *s++;
		}
	}
	else
	{
		t += size - 1;
		s += size - 1;
		while (size--)
		{
			*t-- = *s--;
		}
	}

	return (target);
}
/**
 * _realloc - Reallocate memory block
 * @ptr: Pointer to the memory block
 * @size: New size for the memory block
 *
 * Reallocates a memory block pointed to by ptr.
 *
 * Return: Pointer to the reallocated memory block, or NULL on failure.
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	else if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		new_ptr = malloc(size);
		if (new_ptr == NULL)
		{
			perror("malloc");
			return (NULL);
		}
		_memcpy(new_ptr, ptr, size);
		free(ptr);
		return (new_ptr);
	}
}


