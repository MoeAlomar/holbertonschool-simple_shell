#include "shell.h"

/**
* execute - Executes a command using execve
* @args: Arguments passed (command + args)
* @env: Environment variables
* Return: status code
*/
int execute(char **args, char **env)
{
pid_t pid;
int status;
char *full_path;

full_path = find_path(args[0], env);
if (!full_path)
{
print_error(args[0]);
return (127);
}

pid = fork();
if (pid == -1)
{
perror("fork");
free(full_path);
return (1);
}
else if (pid == 0)
{
execve(full_path, args, env);
perror(args[0]);
exit(EXIT_FAILURE);
}
else
{
waitpid(pid, &status, 0);
free(full_path);
}

return (WEXITSTATUS(status));
}
