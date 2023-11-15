#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define BUFFER_MAX 1024
#define DEL " \n\t"
#define STDIN 0
#define STDOUT 1

/**
 * struct shellstate - contains copy of env and prog name.
 * @env: the environment
 * @shell_name: the program name
 */
typedef struct shellstate
{
	char **env;
	char *shell_name;
} state_t;

#define STATE_INIT { NULL, NULL }

/* FUNCTION PROTOTYPES */
void run_shell(state_t *state);
void interactive(state_t *state);
void non_interactive(state_t *state);
/*void signal_interrupt(int signnum);*/
char *_getenv(char *name, state_t *state);
char *get_location(state_t *state, char *command);
/* EXECUTION FUNCTIONS */
int exec(state_t *state, char **input_string);
int fork_process(state_t *state, char **input_string);
/* DATA CLEANING FUNCTIONS */
char *read_line(void);
char **split_input(char *input);
/* PRINTING FUNCTION PROTOTYPES */
void errorPrint(const char *str);
void printString(const char *str);
char *_strdup(char *src);
int _strlen(char *string);
char *_strcpy(char *des, char *orig);
int _strcmp(char *first, char *second);
char *starts_with(const char *str, const char *find);
char *_strcat(char *string, char *add);
/* STRING FUNCTIONS */
int _env(state_t *state);
void _exit_t(void);
#endif /* This a shell header*/
