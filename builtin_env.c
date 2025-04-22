#include "shell.h"

/**
 * print_env - Prints the environment variables.
 * Retrun: it returns nothing as a void function
 *
 */
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
}
}
