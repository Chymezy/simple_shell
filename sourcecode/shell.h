#ifndef SHELL_H
#define SHELL_H

#define BUFFER_MAX 1024

/* FUNCTION PROTOTYPES */
void run_shell(char **argv);
void interactive(char **argv);
non_interactive(char **argv);
exec(char ** input_sting);
read_line();
split_input();
char *check_comment(char *input);

/* STRING FUNCTION PROTOTYPES */
char *_strstr(char *, char *);
#endif /* This a shell header*/
