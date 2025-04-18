#include "shell.h"

void print_error(char *cmd)
{
    write(STDERR_FILENO, "./hsh: 1: ", 10);
    write(STDERR_FILENO, cmd, _strlen(cmd));
    write(STDERR_FILENO, ": not found\n", 12);
}
