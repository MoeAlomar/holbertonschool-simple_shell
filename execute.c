#include "shell.h"

/**
 * handle_command - Handles command execution:
 * Resolves the full path, checks access, and calls execute_command
 * @args: Array of arguments
 */
void handle_command(char **args)
{
	char *path_cmd = NULL;

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		if (access(args[0], X_OK) == 0)
			path_cmd = strdup(args[0]);
		else
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			last_status = 127;
			return;
		}
	}
	else
	{
		path_cmd = find_command_path(args[0]);
		if (!path_cmd)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			last_status = 127;
			return;
		}
	}

	execute_command(path_cmd, args);
	free(path_cmd);
}

/**
 * execute_command - Fork and run a command using execve
 * @path: Full path to the command
 * @args: Array of arguments
 */
void execute_command(char *path, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			last_status = WEXITSTATUS(status);
	}
}
