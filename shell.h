#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void _execute(char *command, char **argv, char *paths);
char *getpath(char *command, char, char *paths);
char *_strcat(char *string, char *add);
char *_strcmp(char *first, char *second);
char *_strdup(char *des, char *orig);
char *strcpy(char *des, char *orig);
int _strlen(char *string);

#endif

