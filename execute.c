#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * find_command_path - Searches for a command in the PATH environment variable
 * @command: The command to search for
 *
 * Return: A pointer to a string containing the full path if found, otherwise NULL
 */
char *find_command_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy, *token;
	char full_path[1024];

	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(full_path));
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * execute_command - Forks and executes the command using execve
 * @path: Full path to the command
 * @args: Array of arguments
 *
 * Return: Nothing
 */
void execute_command(char *path, char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
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
	}
}

/**
 * handle_command - Handles command input, resolves path and executes
 * @args: Array of arguments passed to the shell
 *
 * Return: Nothing
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
			return;
		}
	}
	else
	{
		path_cmd = find_command_path(args[0]);
		if (!path_cmd)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
			return;
		}
	}

	execute_command(path_cmd, args);
	free(path_cmd);
}
