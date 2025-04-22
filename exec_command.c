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
	/* Find the full path of the command */
	full_path = find_path(args[0], env);
	if (!full_path)
{
		print_error(args[0]);
		return (127);
}
	/* Create a new process using fork */
	pid = fork();
	if (pid == -1)
{
	perror("fork");
	free(full_path);
	return (1);
}
	/* Child process: Replace the child process image with the command */
	else if (pid == 0)
{
	execve(full_path, args, env);
	perror(args[0]);
	exit(EXIT_FAILURE);
}
	/* Parent process: Wait for child process to finish */
	else
{
	waitpid(pid, &status, 0);
	free(full_path);
}
	/* Return the exit status of the child */
	return (WEXITSTATUS(status));
}
