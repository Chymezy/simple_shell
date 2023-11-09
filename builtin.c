#include "shell.h"

/**
 * _cd - is changes directory
 * @argv: argument vector
 * Return: 1 on success or 0 otherwise
 */
int _cd(char **argv)
{
	(void)argv;
	printf("yet to be developed from cd");
	return (1);
}
/**
 * _env - retrieves environment variables
 * @argv: argument vector
 * Return: 1 on success or 0 otherwise
 */ 
int _env(char **argv)
{
	(void)argv;
	printf("yet to be developed from env");
	return (2);
}
/**
 * _exit - builtin exit function
 * @argv: arugment vector
 * Return: exit status
 */
int _exit(char **argv)
{
	(void)argv;
	printf("Yet to be developed from exit");
	return (3);
}
/**
 * _help - Help or man page
 * @argv: command line vector
 * Return: something
 */
int _help(char **argv)
{
	(void)argv;
	printf("Yet to be devloped from help");
	return (4);
}
