#ifndef _SHELL_H_
#define _SHELL_H_

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define WRITE_BUF_SIZE 1024

/*void _execute(char *command, char **argv, char *paths);
char *getpath(char *command, char *paths);
char *_strcat(char *string, char *add);
int _strcmp(char *first, char *second);
char *_strdup(char *des, char *orig);
char *_strcpy(char *des, char *orig);
int _strlen(char *string); */
int print(const char *data, int fd);

#endif

