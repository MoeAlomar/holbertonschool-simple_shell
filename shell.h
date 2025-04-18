#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_ARGS 64
#define _GNU_SOURCE

extern char **environ;
extern int last_status;
extern char *line;

int main(void);
int only_spaces(char *s);
char *read_line(void);
void parse_arguments(char *line, char **args);
char *find_command_path(char *command);
void execute_command(char *command_path, char **args);
void handle_command(char **args);
char *get_env_value(const char *name);
char *_strdup(const char *str);
int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
int check_builtin(char **args);
void free_args_and_exit(void);
void print_env(void);
char *tokenize_input(char *line);

#endif
