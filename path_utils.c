#include "shell.h"
#include <sys/stat.h>
#include <string.h>

/**
 * get_path_from_env - Extracts the PATH variable from the environment.
 * @env: The environment variables.
 *
 * Return: The full value of the PATH variable if found, otherwise NULL.
 */
char *get_path_from_env(char **env)
{
	char *path = NULL;
	int i;

	for (i = 0; env[i]; i++)
	{
	if (strncmp(env[i], "PATH=", 5) == 0)
	{
	path = strdup(env[i] + 5); /* Skip "PATH=" part */
	break;
	}
	}

	return (path);
}

/**
 * find_full_path - Finds the full path of a command from the PATH variable.
 * @command: The command to find the path for.
 * @path: The PATH variable.
 *
 * Return: The full path of the command if found, otherwise NULL.
 */
char *find_full_path(char *command, char *path)
{
	char *token, *full_path;
	struct stat st;

	if (command[0] == '/' || command[0] == '.')
	{
	if (stat(command, &st) == 0)
	return (strdup(command));
	return (NULL);
	}

	token = strtok(path, ":");
	while (token)
	{
	full_path = malloc(strlen(token) + strlen(command) + 2);
	if (!full_path)
	return (NULL);

	strcpy(full_path, token);
	strcat(full_path, "/");
	strcat(full_path, command);

	if (stat(full_path, &st) == 0)
	return (full_path);

	free(full_path);
	token = strtok(NULL, ":");
	}

	return (NULL);
}

/**
 * find_path - Finds the full path of a command.
 * @command: The command to find the path for.
 * @env: The environment variables.
 *
 * Return: The full path of the command if found, otherwise NULL.
 */
char *find_path(char *command, char **env)
{
	char *path, *full_path;

	path = get_path_from_env(env); /* Get the PATH from environment */
	if (!path)
	return (NULL);

	full_path = find_full_path(command, path); /* Find the command in PATH */
	free(path);

	return (full_path);
}
