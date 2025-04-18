#include "shell.h"

/**
* main - Entry point for shell
* @argc: Argument count (unused)
* @argv: Argument vector
* @env: Environment variables
*
* Return: Always 0
*/
int main(int argc, char **argv, char **env)
{
char *line = NULL;
char **args = NULL;
int status = 1;
(void)argc;
(void)argv;

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
break;
}
else if (_strcmp(args[0], "env") == 0)
{
print_env();
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
