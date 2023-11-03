#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h> 

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 10

typedef struct shell_state 
{
  char *get_arg;
  char **argv;
  char *program_name;
  int num_args;
  int fd;
  int status;
} state_t;

#define DATA_INIT { NULL, NULL, NULL, 0, 0, 0}

/* interactive.c prototypes */
int is_interactive(state_t *data);
void clean_shell_data(state_t *data);
int shell_loop(state_t *data, char **av);
ssize_t get_input(state_t *data);
void set_data(state_t *data, char **av);
char **split_string(char *input, char *delimiters);
int is_delimiter(char c, char *delim);

#endif

