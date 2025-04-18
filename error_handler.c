#include "shell.h"

/**
* print_error - prints error message when command is not found
* @cmd: the command that failed
*/
void print_error(char *cmd)
{
write(STDERR_FILENO, "./hsh: ", 7);
write(STDERR_FILENO, cmd, _strlen(cmd));
write(STDERR_FILENO, ": command not found\n", 20);
}
