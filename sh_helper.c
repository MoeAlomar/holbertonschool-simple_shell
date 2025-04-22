#include "shell.h"
/**
 * print_error - Prints an error message when a command is not found
 * @cmd: The command that was not found
 */
void print_error(char *cmd)
{
	/* Write the initial error message to stderr */
	write(STDERR_FILENO, "./hsh: 1: ", 10);

	/* Write the command that was not found */
	write(STDERR_FILENO, cmd, strlen(cmd));

	/* Write the "not found" part of the error message */
	write(STDERR_FILENO, ": not found\n", 12);
}
