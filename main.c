#include "shell.h"

/**
* main - Entry point for shell
* @argc: Argument count (unused)
* @argv: Argument vector
* @env: Environment variables
*
* Return: Exit status
*/
int main(int argc, char **argv, char **env)
{
char *line = NULL;
char **args = NULL;
int status = 0;
(void)argc;
(void)argv;

signal(SIGCHLD, handle_signal);

while (1)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);

line = read_line();
if (!line)
{
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

if (_strcmp(args[0], "exit") == 0)
{
free(line);
free_args(args);
exit(status);
}
else if (_strcmp(args[0], "env") == 0)
{
print_env();
status = 0;
}
else if (_strcmp(args[0], "cd") == 0)
{
status = change_dir(args);
}
else
{
status = execute(args, env);
}

free(line);
free_args(args);
}

return (status);
}
