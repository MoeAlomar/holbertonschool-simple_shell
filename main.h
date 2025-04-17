#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

#define MAX_ARGS 100

ssize_t read_input(char **line, size_t *len);
void remove_newline(char *line);
void execute_command(char *line);
char *resolve_path(char *cmd);

#endif
