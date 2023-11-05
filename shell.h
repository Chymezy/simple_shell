#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>

void _execute(char *command, char **argv, char *paths);
char *getpath(char *command, char *paths);
char *_strcat(char *string, char *add);
int _strcmp(char *first, char *second);
char *_strdup(const char *);
char *_strcpy(char *des, char *orig);
int _strlen(char *string);

#endif

