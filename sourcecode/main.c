#include "shell.h"

/**
 * main - this is the main shell
 * @argc: the command line argument count
 * @argv: the command line argument vector
 * Return: 0 on success and -1 on failure
 */
int main(int argc, char **argv)
{
	run_shell(argv);

	return (0);
}
