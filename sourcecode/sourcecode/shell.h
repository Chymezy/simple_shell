#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define BUFFER_MAX 1024
#define DEL " \n\t"

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
char *_getenv(char *name, state_t *state);
char *get_location(state_t *state, char *command);
/* EXECUTION FUNCTIONS */
int exec(state_t *state, char **input_string);
int fork_process(state_t *state, char **input_string);
/* DATA CLEANING FUNCTIONS */
char *read_line(void);
char **split_input(char *input);
/* STRING FUNCTION PROTOTYPES */
/*void errorPrint(const char *str);*/
/**void printString(const char *str);*/
int _env(state_t *state);
void _exit_t(void);
#endif /* This a shell header*/
