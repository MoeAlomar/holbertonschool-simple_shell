#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/* environ declaration */
extern char **environ;

/* Shell functions */
char *read_line(void);
char **split_line(char *line);
int execute(char **args, char **env);
char *find_path(char *command, char **env);
void print_env(void);
void print_error(char *command);

/* String utils */
int _strlen(const char *s);
char *_strdup(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);

/* Memory management */
void free_args(char **args);

int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *dest, const char *src);
/* size_t _strlen(const char *s); */

#endif /* SHELL_H */
