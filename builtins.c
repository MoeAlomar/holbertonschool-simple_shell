#include "shell.h"

/**
 * check_builtin - Checks if the command is a built-in and executes it
 * @args: Parsed arguments from user input
 *
 * Return: 0
 */

int check_builtin(char **args)
{
    if (_strncmp(args[0], "exit", 4) == 0 && args[1] == NULL)
    {
        free_args_and_exit();
        return (1);
    }

    if (_strncmp(args[0], "env", 3) == 0 && args[1] == NULL)
    {
        print_env();
        return (1);
    }

    return (0);
}

/**
 * free_args_and_exit - Frees memory and exits shell
 */
void free_args_and_exit(void)
{
	if (line)
		free(line);
	exit(last_status);

}

/**
 * print_env - Prints the current environment
 */
void print_env(void)
{
    int i = 0;

    while (environ[i])
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}
