#include "shell.h"

/**
 * main - Entry point for shell
 * @argc: Argument count (unused)
 * @argv: Argument vector
 * @env: Environment variables
 *
 * Return: last exit status of executed command or exit code on `exit`
 */
int main(int argc, char **argv, char **env)
{
    char *line = NULL;
    char **args = NULL;
    int status = 0; /* store last command exit status */

    (void)argc;
    (void)argv;

    while (1)
    {
        /* display prompt if interactive */
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "$ ", 2);

        line = read_line();
        if (!line)
        {
            /* handle EOF */
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            break;
        }

        args = split_line(line);
        if (!args || !args[0])
        {
            free(line);
            free_args(args);
            continue;
        }

        /* built-in: exit */
        if (_strcmp(args[0], "exit") == 0)
        {
            int exit_code = status;

            /* if user provided an exit code, use it */
            if (args[1])
                exit_code = atoi(args[1]);

            free(line);
            free_args(args);
            exit(exit_code);
        }
        /* built-in: env */
        else if (_strcmp(args[0], "env") == 0)
        {
            print_env();
            status = 0;
        }
        else
        {
            /* execute external command and save its exit status */
            status = execute_args(args, env);
        }

        free(line);
        free_args(args);
    }

    return (status);
}
