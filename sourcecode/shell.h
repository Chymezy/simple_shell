#ifndef SHELL_H
#define SHELL_H

#define BUFFER_MAX 1024
#define DELIMER " \n\t"

/* FUNCTION PROTOTYPES */
void run_shell(char **argv);
void interactive(char **argv);
non_interactive(char **argv);
exec(char ** input_sting);
char *read_line(void);
split_input();
/* STRING FUNCTION PROTOTYPES */
char *_strstr(char *haystack, char *needle)a;
char *_strdup(char *);
#endif /* This a shell header*/
